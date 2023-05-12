#include "mk_sl_mallocator_win_main_heap.h"

#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_win_main_heap.h"


mk_lang_jumbo void mk_sl_mallocator_win_main_heap_allocate(mk_lang_exception_t* const ex, mk_lang_size_t const size_bytes, void** const mem) mk_lang_noexcept
{
	mk_win_main_heap_allocate(ex, size_bytes, mem);
}

mk_lang_jumbo void mk_sl_mallocator_win_main_heap_deallocate(void const* const mem, mk_lang_size_t const size_bytes) mk_lang_noexcept
{
	mk_win_main_heap_deallocate(mem, size_bytes);
}

mk_lang_jumbo void mk_sl_mallocator_win_main_heap_reallocate(mk_lang_exception_t* const ex, void const* const old_mem, mk_lang_size_t const old_size_bytes, mk_lang_size_t const new_size_bytes, void** const new_mem) mk_lang_noexcept
{
	mk_win_main_heap_reallocate(ex, old_mem, old_size_bytes, new_size_bytes, new_mem);
}
