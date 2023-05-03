#include "mk_sl_mallocator_win_heap.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"

#if defined __cplusplus
#include <cstdlib> /* std::malloc std::free */
#define mk_sl_mallocator_win_heap_m std::malloc
#define mk_sl_mallocator_win_heap_f std::free
#else
#include <stdlib.h> /* malloc free */
#define mk_sl_mallocator_win_heap_m malloc
#define mk_sl_mallocator_win_heap_f free
#endif


#if defined mk_sl_mallocator_win_heap_want_statistics && mk_sl_mallocator_win_heap_want_statistics == 1
#define mk_sl_mallocator_win_heap_want_statistics_impl 1
#elif defined mk_sl_mallocator_win_heap_want_statistics && mk_sl_mallocator_win_heap_want_statistics == 0
#define mk_sl_mallocator_win_heap_want_statistics_impl 0
#else
#if defined NDEBUG
#define mk_sl_mallocator_win_heap_want_statistics_impl 0
#else
#define mk_sl_mallocator_win_heap_want_statistics_impl 1
#endif
#endif

#if mk_sl_mallocator_win_heap_want_statistics_impl
static mk_lang_size_t g_mk_sl_mallocator_win_heap_allocated;
#endif


mk_lang_jumbo void* mk_sl_mallocator_win_heap_allocate(mk_lang_size_t const bytes_count) mk_lang_noexcept
{
	void* ptr;

	mk_lang_assert(bytes_count != 0);

	ptr = mk_sl_mallocator_win_heap_m(bytes_count);
	#if mk_sl_mallocator_win_heap_want_statistics_impl
	if(ptr)
	{
		g_mk_sl_mallocator_win_heap_allocated += bytes_count;
	}
	#endif
	return ptr;
}

mk_lang_jumbo void mk_sl_mallocator_win_heap_deallocate(void const* const ptr, mk_lang_size_t const bytes_count) mk_lang_noexcept
{
	#if mk_sl_mallocator_win_heap_want_statistics_impl
	g_mk_sl_mallocator_win_heap_allocated -= bytes_count;
	#else
	((void)(bytes_count));
	#endif
	mk_sl_mallocator_win_heap_f(ptr);
}


#undef mk_sl_mallocator_win_heap_m
#undef mk_sl_mallocator_win_heap_f
