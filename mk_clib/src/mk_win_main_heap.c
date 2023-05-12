#include "mk_win_main_heap.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_exception.h"
#include "mk_lang_exception_out_of_memory.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_kernel_heap.h"


#if defined mk_win_main_heap_want_statistics && mk_win_main_heap_want_statistics == 1
#define mk_win_main_heap_want_statistics_impl 1
#elif defined mk_win_main_heap_want_statistics && mk_win_main_heap_want_statistics == 0
#define mk_win_main_heap_want_statistics_impl 0
#else
#if defined NDEBUG
#define mk_win_main_heap_want_statistics_impl 0
#else
#define mk_win_main_heap_want_statistics_impl 1
#endif
#endif


typedef mk_win_base_size_t mk_win_main_heap_counts_t; /* todo at least 64bit? */
typedef mk_win_base_size_t mk_win_main_heap_countl_t; /* todo at least 128bit? */


static mk_win_base_handle_t g_mk_win_main_heap;
#if mk_win_main_heap_want_statistics_impl
static mk_win_main_heap_counts_t g_mk_win_main_heap_allocated_blocks;
static mk_win_main_heap_counts_t g_mk_win_main_heap_deallocated_blocks;
static mk_win_main_heap_countl_t g_mk_win_main_heap_allocated_bytes;
static mk_win_main_heap_countl_t g_mk_win_main_heap_deallocated_bytes;
#endif 


static mk_lang_inline void mk_win_main_heap_statistics_allocated(mk_win_base_size_t const size_bytes) mk_lang_noexcept;
static mk_lang_inline void mk_win_main_heap_statistics_deallocated(mk_win_base_size_t const size_bytes) mk_lang_noexcept;
static mk_lang_inline void mk_win_main_heap_statistics_reallocated(mk_win_base_size_t const old_size_bytes, mk_win_base_size_t const new_size_bytes) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_counts_t mk_win_main_heap_statistics_get_allocated_blocks(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_counts_t mk_win_main_heap_statistics_get_deallocated_blocks(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_countl_t mk_win_main_heap_statistics_get_allocated_bytes(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_countl_t mk_win_main_heap_statistics_get_deallocated_bytes(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_counts_t mk_win_main_heap_statistics_get_live_blocks(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_countl_t mk_win_main_heap_statistics_get_live_bytes(void) mk_lang_noexcept;


mk_lang_jumbo void mk_win_main_heap_create(void) mk_lang_noexcept
{
	mk_lang_assert(!g_mk_win_main_heap);

	g_mk_win_main_heap = mk_win_kernel_heap_create(mk_win_kernel_heap_create_flags_e_none, 0, 0);
	mk_lang_assert(g_mk_win_main_heap);
}

mk_lang_jumbo void mk_win_main_heap_destroy(void) mk_lang_noexcept
{
	mk_win_base_bool_t destroyed;

	mk_lang_assert(g_mk_win_main_heap);

	mk_lang_assert(mk_win_main_heap_statistics_get_live_blocks() == 0);
	mk_lang_assert(mk_win_main_heap_statistics_get_live_bytes() == 0);
	destroyed = mk_win_kernel_heap_destroy(g_mk_win_main_heap); mk_lang_assert(destroyed != 0);
}

mk_lang_jumbo void mk_win_main_heap_allocate(mk_lang_exception_t* const ex, mk_win_base_size_t const size_bytes, mk_win_base_void_lpt* const mem) mk_lang_noexcept
{
	mk_win_base_void_lpt m;

	mk_lang_assert(g_mk_win_main_heap);
	mk_lang_assert(ex);
	mk_lang_assert(size_bytes != 0);
	mk_lang_assert(mem);

	m = mk_win_kernel_heap_allocate(g_mk_win_main_heap, mk_win_kernel_heap_allocate_flags_e_none, size_bytes);
	if(!m)
	{
		mk_lang_exception_out_of_memory_make(ex, size_bytes);
		return;
	}
	mk_win_main_heap_statistics_allocated(size_bytes);
	*mem = m;
}

mk_lang_jumbo void mk_win_main_heap_deallocate(mk_win_base_void_lpct const mem, mk_win_base_size_t const size_bytes) mk_lang_noexcept
{
	mk_win_base_bool_t deallocated;

	mk_lang_assert(g_mk_win_main_heap);
	mk_lang_assert(size_bytes != 0 || !mem);

	if(mem)
	{
		deallocated = mk_win_kernel_heap_deallocate(g_mk_win_main_heap, mk_win_kernel_heap_deallocate_flags_e_none, mem); mk_lang_assert(deallocated != 0);
		mk_win_main_heap_statistics_deallocated(size_bytes);
	}
}

mk_lang_jumbo void mk_win_main_heap_reallocate(mk_lang_exception_t* const ex, mk_win_base_void_lpct const old_mem, mk_win_base_size_t const old_size_bytes, mk_win_base_size_t const new_size_bytes, mk_win_base_void_lpt* const new_mem) mk_lang_noexcept
{
	mk_win_base_void_lpt m;

	mk_lang_assert(g_mk_win_main_heap);
	mk_lang_assert(ex);
	mk_lang_assert(old_mem);
	mk_lang_assert(old_size_bytes != 0);
	mk_lang_assert(new_size_bytes != 0);
	mk_lang_assert(new_mem);

	m = mk_win_kernel_heap_reallocate(g_mk_win_main_heap, mk_win_kernel_heap_reallocate_flags_e_none, old_mem, new_size_bytes);
	if(!m)
	{
		mk_lang_exception_out_of_memory_make(ex, new_size_bytes);
		return;
	}
	*new_mem = m;
	mk_win_main_heap_statistics_reallocated(old_size_bytes, new_size_bytes);
}


static mk_lang_inline void mk_win_main_heap_statistics_allocated(mk_win_base_size_t const size_bytes) mk_lang_noexcept
{
#if mk_win_main_heap_want_statistics_impl
	g_mk_win_main_heap_allocated_blocks += 1;
	g_mk_win_main_heap_allocated_bytes += size_bytes;
#else
	((void)(size_bytes));
#endif
}

static mk_lang_inline void mk_win_main_heap_statistics_deallocated(mk_win_base_size_t const size_bytes) mk_lang_noexcept
{
#if mk_win_main_heap_want_statistics_impl
	g_mk_win_main_heap_deallocated_blocks += 1;
	g_mk_win_main_heap_deallocated_bytes += size_bytes;
#else
	((void)(size_bytes));
#endif
}

static mk_lang_inline void mk_win_main_heap_statistics_reallocated(mk_win_base_size_t const old_size_bytes, mk_win_base_size_t const new_size_bytes) mk_lang_noexcept
{
	mk_win_main_heap_statistics_allocated(new_size_bytes);
	mk_win_main_heap_statistics_deallocated(old_size_bytes);
}

mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_counts_t mk_win_main_heap_statistics_get_allocated_blocks(void) mk_lang_noexcept
{
#if mk_win_main_heap_want_statistics_impl
	return g_mk_win_main_heap_allocated_blocks;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_counts_t mk_win_main_heap_statistics_get_deallocated_blocks(void) mk_lang_noexcept
{
#if mk_win_main_heap_want_statistics_impl
	return g_mk_win_main_heap_deallocated_blocks;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_countl_t mk_win_main_heap_statistics_get_allocated_bytes(void) mk_lang_noexcept
{
#if mk_win_main_heap_want_statistics_impl
	return g_mk_win_main_heap_allocated_bytes;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_countl_t mk_win_main_heap_statistics_get_deallocated_bytes(void) mk_lang_noexcept
{
#if mk_win_main_heap_want_statistics_impl
	return g_mk_win_main_heap_deallocated_bytes;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_counts_t mk_win_main_heap_statistics_get_live_blocks(void) mk_lang_noexcept
{
	return mk_win_main_heap_statistics_get_allocated_blocks() - mk_win_main_heap_statistics_get_deallocated_blocks();
}

mk_lang_nodiscard static mk_lang_inline mk_win_main_heap_countl_t mk_win_main_heap_statistics_get_live_bytes(void) mk_lang_noexcept
{
	return mk_win_main_heap_statistics_get_allocated_bytes() - mk_win_main_heap_statistics_get_deallocated_bytes();
}
