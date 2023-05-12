#include "mk_sl_mallocator_lang.h"

#include "mk_lang_assert.h"
#include "mk_lang_exception_out_of_memory.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


#if defined __cplusplus
#include <cstdlib> /* std::malloc std::free std::realloc */
#define mk_sl_mallocator_lang_m(x) std::malloc((x))
#define mk_sl_mallocator_lang_f(x, s) std::free((x))
#define mk_sl_mallocator_lang_r(x, s) std::realloc((x), (s))
#else
#include <stdlib.h> /* malloc free realloc free_sized */
#define mk_sl_mallocator_lang_m(x) malloc((x))
#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 202299l /* todo c23 */
#define mk_sl_mallocator_lang_f(x, s) free_sized((x), (s))
#else
#define mk_sl_mallocator_lang_f(x, s) free((x))
#endif
#define mk_sl_mallocator_lang_r(x, s) realloc((x), (s))
#endif


#if defined mk_sl_mallocator_lang_want_statistics && mk_sl_mallocator_lang_want_statistics == 1
#define mk_sl_mallocator_lang_want_statistics_impl 1
#elif defined mk_sl_mallocator_lang_want_statistics && mk_sl_mallocator_lang_want_statistics == 0
#define mk_sl_mallocator_lang_want_statistics_impl 0
#else
#if defined NDEBUG
#define mk_sl_mallocator_lang_want_statistics_impl 0
#else
#define mk_sl_mallocator_lang_want_statistics_impl 1
#endif
#endif


typedef mk_lang_size_t mk_sl_mallocator_lang_counts_t; /* todo at least 64bit? */
typedef mk_lang_size_t mk_sl_mallocator_lang_countl_t; /* todo at least 128bit? */


#if mk_sl_mallocator_lang_want_statistics_impl
static mk_sl_mallocator_lang_counts_t g_mk_sl_mallocator_lang_allocated_blocks;
static mk_sl_mallocator_lang_counts_t g_mk_sl_mallocator_lang_deallocated_blocks;
static mk_sl_mallocator_lang_countl_t g_mk_sl_mallocator_lang_allocated_bytes;
static mk_sl_mallocator_lang_countl_t g_mk_sl_mallocator_lang_deallocated_bytes;
#endif


static mk_lang_inline void mk_sl_mallocator_lang_statistics_allocated(mk_lang_size_t const size_bytes) mk_lang_noexcept;
static mk_lang_inline void mk_sl_mallocator_lang_statistics_deallocated(mk_lang_size_t const size_bytes) mk_lang_noexcept;
static mk_lang_inline void mk_sl_mallocator_lang_statistics_reallocated(mk_lang_size_t const old_size_bytes, mk_lang_size_t const new_size_bytes) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_counts_t mk_sl_mallocator_lang_statistics_get_allocated_blocks(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_counts_t mk_sl_mallocator_lang_statistics_get_deallocated_blocks(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_countl_t mk_sl_mallocator_lang_statistics_get_allocated_bytes(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_countl_t mk_sl_mallocator_lang_statistics_get_deallocated_bytes(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_counts_t mk_sl_mallocator_lang_statistics_get_live_blocks(void) mk_lang_noexcept;
mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_countl_t mk_sl_mallocator_lang_statistics_get_live_bytes(void) mk_lang_noexcept;


mk_lang_jumbo void mk_sl_mallocator_lang_init(void) mk_lang_noexcept
{
}

mk_lang_jumbo void mk_sl_mallocator_lang_deinit(void) mk_lang_noexcept
{
	mk_lang_assert(mk_sl_mallocator_lang_statistics_get_live_blocks() == 0);
	mk_lang_assert(mk_sl_mallocator_lang_statistics_get_live_bytes() == 0);
}

mk_lang_jumbo void mk_sl_mallocator_lang_allocate(mk_lang_exception_t* const ex, mk_lang_size_t const size_bytes, void** const mem) mk_lang_noexcept
{
	void* m;

	mk_lang_assert(ex);
	mk_lang_assert(size_bytes != 0);
	mk_lang_assert(mem);

	m = mk_sl_mallocator_lang_m(size_bytes);
	if(!m)
	{
		mk_lang_exception_out_of_memory_make(ex, size_bytes);
		return;
	}
	mk_sl_mallocator_lang_statistics_allocated(size_bytes);
	*mem = m;
}

mk_lang_jumbo void mk_sl_mallocator_lang_deallocate(void const* const mem, mk_lang_size_t const size_bytes) mk_lang_noexcept
{
	mk_lang_assert(size_bytes != 0 || !mem);

	if(mem)
	{
		mk_sl_mallocator_lang_f(((void*)(mem)), size_bytes);
		mk_sl_mallocator_lang_statistics_deallocated(size_bytes);
	}
}

mk_lang_jumbo void mk_sl_mallocator_lang_reallocate(mk_lang_exception_t* const ex, void const* const old_mem, mk_lang_size_t const old_size_bytes, mk_lang_size_t const new_size_bytes, void** const new_mem) mk_lang_noexcept
{
	void* m;

	mk_lang_assert(ex);
	mk_lang_assert(old_mem);
	mk_lang_assert(old_size_bytes != 0);
	mk_lang_assert(new_size_bytes != 0);
	mk_lang_assert(new_mem);

	m = mk_sl_mallocator_lang_r(((void*)(old_mem)), new_size_bytes);
	if(!m)
	{
		mk_lang_exception_out_of_memory_make(ex, new_size_bytes);
		return;
	}
	*new_mem = m;
	mk_sl_mallocator_lang_statistics_reallocated(old_size_bytes, new_size_bytes);
}


static mk_lang_inline void mk_sl_mallocator_lang_statistics_allocated(mk_lang_size_t const size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_lang_want_statistics_impl
	g_mk_sl_mallocator_lang_allocated_blocks += 1;
	g_mk_sl_mallocator_lang_allocated_bytes += size_bytes;
#else
	((void)(size_bytes));
#endif
}

static mk_lang_inline void mk_sl_mallocator_lang_statistics_deallocated(mk_lang_size_t const size_bytes) mk_lang_noexcept
{
#if mk_sl_mallocator_lang_want_statistics_impl
	g_mk_sl_mallocator_lang_deallocated_blocks += 1;
	g_mk_sl_mallocator_lang_deallocated_bytes += size_bytes;
#else
	((void)(size_bytes));
#endif
}

static mk_lang_inline void mk_sl_mallocator_lang_statistics_reallocated(mk_lang_size_t const old_size_bytes, mk_lang_size_t const new_size_bytes) mk_lang_noexcept
{
	mk_sl_mallocator_lang_statistics_allocated(new_size_bytes);
	mk_sl_mallocator_lang_statistics_deallocated(old_size_bytes);
}

mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_counts_t mk_sl_mallocator_lang_statistics_get_allocated_blocks(void) mk_lang_noexcept
{
#if mk_sl_mallocator_lang_want_statistics_impl
	return g_mk_sl_mallocator_lang_allocated_blocks;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_counts_t mk_sl_mallocator_lang_statistics_get_deallocated_blocks(void) mk_lang_noexcept
{
#if mk_sl_mallocator_lang_want_statistics_impl
	return g_mk_sl_mallocator_lang_deallocated_blocks;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_countl_t mk_sl_mallocator_lang_statistics_get_allocated_bytes(void) mk_lang_noexcept
{
#if mk_sl_mallocator_lang_want_statistics_impl
	return g_mk_sl_mallocator_lang_allocated_bytes;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_countl_t mk_sl_mallocator_lang_statistics_get_deallocated_bytes(void) mk_lang_noexcept
{
#if mk_sl_mallocator_lang_want_statistics_impl
	return g_mk_sl_mallocator_lang_deallocated_bytes;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_counts_t mk_sl_mallocator_lang_statistics_get_live_blocks(void) mk_lang_noexcept
{
	return mk_sl_mallocator_lang_statistics_get_allocated_blocks() - mk_sl_mallocator_lang_statistics_get_deallocated_blocks();
}

mk_lang_nodiscard static mk_lang_inline mk_sl_mallocator_lang_countl_t mk_sl_mallocator_lang_statistics_get_live_bytes(void) mk_lang_noexcept
{
	return mk_sl_mallocator_lang_statistics_get_allocated_bytes() - mk_sl_mallocator_lang_statistics_get_deallocated_bytes();
}


#undef mk_sl_mallocator_lang_m
#undef mk_sl_mallocator_lang_f
#undef mk_sl_mallocator_lang_r
