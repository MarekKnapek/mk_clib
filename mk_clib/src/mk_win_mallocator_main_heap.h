#ifndef mk_include_guard_mk_win_mallocator_main_heap
#define mk_include_guard_mk_win_mallocator_main_heap


#include "mk_lang_exception.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo mk_lang_types_void_t mk_win_mallocator_main_heap_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_mallocator_main_heap_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_mallocator_main_heap_allocate(mk_lang_exception_pt const ex, mk_lang_types_usize_t const size_bytes, mk_lang_types_void_ppt const mem) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_mallocator_main_heap_deallocate(mk_lang_types_void_pct const mem, mk_lang_types_usize_t const size_bytes) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_mallocator_main_heap_reallocate(mk_lang_exception_pt const ex, mk_lang_types_void_pct const old_mem, mk_lang_types_usize_t const old_size_bytes, mk_lang_types_usize_t const new_size_bytes, mk_lang_types_void_ppt const new_mem) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_mallocator_main_heap.c"
#endif
#endif
