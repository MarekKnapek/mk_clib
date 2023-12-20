#ifndef mk_include_guard_mk_win_main_heap
#define mk_include_guard_mk_win_main_heap


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_kernel_heap.h"


mk_lang_jumbo mk_lang_types_void_t mk_win_main_heap_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_main_heap_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_main_heap_allocate(mk_win_kernel_heap_allocate_flags_t const flags, mk_win_base_usize_t const size_bytes) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_main_heap_deallocate(mk_win_kernel_heap_deallocate_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_main_heap_reallocate(mk_win_kernel_heap_reallocate_flags_t const flags, mk_win_base_void_lpct const mem, mk_win_base_usize_t const size_bytes) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_usize_t mk_win_main_heap_size(mk_win_kernel_heap_size_flags_t const flags, mk_win_base_void_lpct const mem) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_main_heap.c"
#endif
#endif
