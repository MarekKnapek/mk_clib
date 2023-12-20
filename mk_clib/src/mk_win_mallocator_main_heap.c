#include "mk_win_mallocator_main_heap.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_exception.h"
#include "mk_lang_exception_out_of_memory.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_main_heap.h"


#if defined mk_win_mallocator_main_heap_statistics && mk_win_mallocator_main_heap_statistics == 1
#define mk_win_mallocator_main_heap_statistics_impl 1
#elif defined mk_win_mallocator_main_heap_statistics && mk_win_mallocator_main_heap_statistics == 0
#define mk_win_mallocator_main_heap_statistics_impl 0
#else
#if defined NDEBUG
#define mk_win_mallocator_main_heap_statistics_impl 0
#else
#define mk_win_mallocator_main_heap_statistics_impl 1
#endif
#endif


typedef mk_lang_types_usize_t mk_win_mallocator_main_heap_counts_t; /* todo at least 64bit? */
typedef mk_lang_types_usize_t mk_win_mallocator_main_heap_countl_t; /* todo at least 128bit? */


#if mk_win_mallocator_main_heap_statistics_impl
static mk_win_mallocator_main_heap_counts_t g_mk_win_mallocator_main_heap_allocated_blocks;
static mk_win_mallocator_main_heap_counts_t g_mk_win_mallocator_main_heap_deallocated_blocks;
static mk_win_mallocator_main_heap_countl_t g_mk_win_mallocator_main_heap_allocated_bytes;
static mk_win_mallocator_main_heap_countl_t g_mk_win_mallocator_main_heap_deallocated_bytes;
#endif


static mk_lang_inline mk_lang_types_void_t mk_win_mallocator_main_heap_statistics_allocated(mk_lang_types_usize_t const size_bytes) mk_lang_noexcept;
static mk_lang_inline mk_lang_types_void_t mk_win_mallocator_main_heap_statistics_deallocated(mk_lang_types_usize_t const size_bytes) mk_lang_noexcept;
static mk_lang_inline mk_lang_types_void_t mk_win_mallocator_main_heap_statistics_reallocated(mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_counts_t mk_win_mallocator_main_heap_statistics_get_allocated_blocks(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_counts_t mk_win_mallocator_main_heap_statistics_get_deallocated_blocks(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_countl_t mk_win_mallocator_main_heap_statistics_get_allocated_bytes(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_countl_t mk_win_mallocator_main_heap_statistics_get_deallocated_bytes(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_counts_t mk_win_mallocator_main_heap_statistics_get_live_blocks(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_countl_t mk_win_mallocator_main_heap_statistics_get_live_bytes(mk_lang_types_void_t) mk_lang_noexcept;


mk_lang_jumbo mk_lang_types_void_t mk_win_mallocator_main_heap_init(mk_lang_types_void_t) mk_lang_noexcept
{
}

mk_lang_jumbo mk_lang_types_void_t mk_win_mallocator_main_heap_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_assert(mk_win_mallocator_main_heap_statistics_get_live_blocks() == 0);
	mk_lang_assert(mk_win_mallocator_main_heap_statistics_get_live_bytes() == 0);
}

mk_lang_jumbo mk_lang_types_void_t mk_win_mallocator_main_heap_allocate(mk_lang_exception_pt const ex, mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept
{
	mk_win_base_void_lpt m;

	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(size_bytes != 0);
	mk_lang_assert(mem);

	m = mk_win_main_heap_allocate(mk_win_kernel_heap_allocate_flags_e_none, ((mk_win_base_usize_t)(size_bytes)));
	if(!mk_lang_check_to_bool(m)){ mk_lang_unlikely mk_lang_exception_out_of_memory_make(ex, size_bytes); return; } mk_lang_assert(m);
	mk_win_mallocator_main_heap_statistics_allocated(size_bytes);
	*mem = ((mk_lang_types_void_pt)(m));
}

mk_lang_jumbo mk_lang_types_void_t mk_win_mallocator_main_heap_deallocate(mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
	mk_win_base_bool_t deallocated;

	mk_lang_assert((mem && size_bytes != 0) || (!mem && size_bytes == 0));

	if(mem)
	{
		deallocated = mk_win_main_heap_deallocate(mk_win_kernel_heap_deallocate_flags_e_none, ((mk_win_base_void_lpct)(mem))); mk_lang_assert(deallocated != 0);
		mk_win_mallocator_main_heap_statistics_deallocated(size_bytes);
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_win_mallocator_main_heap_reallocate(mk_lang_exception_pt const ex, mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_pt* const new_mem) mk_lang_noexcept
{
	mk_win_base_void_lpt m;

	mk_lang_assert(ex);
	mk_lang_assert(!mk_lang_exception_is(ex));
	mk_lang_assert(old_mem);
	mk_lang_assert(old_size_bytes != 0);
	mk_lang_assert(new_size_bytes != 0);
	mk_lang_assert(new_mem);

	m = mk_win_main_heap_reallocate(mk_win_kernel_heap_reallocate_flags_e_none, ((mk_win_base_void_lpct)(old_mem)), ((mk_win_base_usize_t)(new_size_bytes)));
	if(!mk_lang_check_to_bool(m)){ mk_lang_unlikely mk_lang_exception_out_of_memory_make(ex, new_size_bytes); return; } mk_lang_assert(m);
	mk_win_mallocator_main_heap_statistics_reallocated(old_size_bytes, new_size_bytes);
	*new_mem = ((mk_lang_types_void_pt)(m));
}


static mk_lang_inline mk_lang_types_void_t mk_win_mallocator_main_heap_statistics_allocated(mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
#if mk_win_mallocator_main_heap_statistics_impl
	g_mk_win_mallocator_main_heap_allocated_blocks += 1;
	g_mk_win_mallocator_main_heap_allocated_bytes += size_bytes;
#else
	((mk_lang_types_void_t)(size_bytes));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_win_mallocator_main_heap_statistics_deallocated(mk_lang_types_usize_t const size_bytes) mk_lang_noexcept
{
#if mk_win_mallocator_main_heap_statistics_impl
	g_mk_win_mallocator_main_heap_deallocated_blocks += 1;
	g_mk_win_mallocator_main_heap_deallocated_bytes += size_bytes;
#else
	((mk_lang_types_void_t)(size_bytes));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_win_mallocator_main_heap_statistics_reallocated(mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes) mk_lang_noexcept
{
	mk_win_mallocator_main_heap_statistics_allocated(new_size_bytes);
	mk_win_mallocator_main_heap_statistics_deallocated(old_size_bytes);
}

mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_counts_t mk_win_mallocator_main_heap_statistics_get_allocated_blocks(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_win_mallocator_main_heap_statistics_impl
	return g_mk_win_mallocator_main_heap_allocated_blocks;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_counts_t mk_win_mallocator_main_heap_statistics_get_deallocated_blocks(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_win_mallocator_main_heap_statistics_impl
	return g_mk_win_mallocator_main_heap_deallocated_blocks;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_countl_t mk_win_mallocator_main_heap_statistics_get_allocated_bytes(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_win_mallocator_main_heap_statistics_impl
	return g_mk_win_mallocator_main_heap_allocated_bytes;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_countl_t mk_win_mallocator_main_heap_statistics_get_deallocated_bytes(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_win_mallocator_main_heap_statistics_impl
	return g_mk_win_mallocator_main_heap_deallocated_bytes;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_counts_t mk_win_mallocator_main_heap_statistics_get_live_blocks(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_win_mallocator_main_heap_statistics_get_allocated_blocks() - mk_win_mallocator_main_heap_statistics_get_deallocated_blocks();
}

mk_lang_nodiscard static mk_lang_inline mk_win_mallocator_main_heap_countl_t mk_win_mallocator_main_heap_statistics_get_live_bytes(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_win_mallocator_main_heap_statistics_get_allocated_bytes() - mk_win_mallocator_main_heap_statistics_get_deallocated_bytes();
}
