#ifndef mk_include_guard_win_main_heap
#define mk_include_guard_win_main_heap


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_jumbo void mk_win_main_heap_create(void) mk_lang_noexcept;
mk_lang_jumbo void mk_win_main_heap_destroy(void) mk_lang_noexcept;
mk_lang_jumbo void mk_win_main_heap_allocate(mk_lang_exception_t* const ex, mk_win_base_size_t const size_bytes, mk_win_base_void_lpt* const mem) mk_lang_noexcept;
mk_lang_jumbo void mk_win_main_heap_deallocate(mk_win_base_void_lpct const mem, mk_win_base_size_t const size_bytes) mk_lang_noexcept;
mk_lang_jumbo void mk_win_main_heap_reallocate(mk_lang_exception_t* const ex, mk_win_base_void_lpct const old_mem, mk_win_base_size_t const old_size_bytes, mk_win_base_size_t const new_size_bytes, mk_win_base_void_lpt* const new_mem) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_main_heap.c"
#endif
#endif
