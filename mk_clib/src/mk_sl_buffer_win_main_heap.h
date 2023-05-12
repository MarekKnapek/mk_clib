#ifndef include_guard_mk_sl_buffer_win_main_heap
#define include_guard_mk_sl_buffer_win_main_heap


#define mk_sl_buffer_t_name win_main_heap
#define mk_sl_buffer_t_mallocator mk_sl_mallocator_win_main_heap
#include "mk_sl_buffer_inl_fileh.h"


#if mk_lang_jumbo_want == 1
#include "mk_sl_buffer_win_main_heap.c"
#endif
#endif
