#ifndef include_guard_mk_sl_mallocator_win_heap
#define include_guard_mk_sl_mallocator_win_heap


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_win_base.h"


mk_lang_jumbo mk_win_base_handle_t mk_sl_mallocator_win_heap_allocate(mk_lang_size_t const bytes_count) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_mallocator_win_heap_deallocate(void const* const ptr) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_mallocator_win_heap.c"
#endif
#endif
