#ifndef mk_include_guard_sl_mallocator_win_process_heap
#define mk_include_guard_sl_mallocator_win_process_heap


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


mk_lang_jumbo void* mk_sl_mallocator_win_process_heap_allocate(mk_lang_size_t const bytes_count) mk_lang_noexcept;
mk_lang_jumbo void mk_sl_mallocator_win_process_heap_deallocate(void const* const ptr) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_mallocator_win_process_heap.c"
#endif
#endif
