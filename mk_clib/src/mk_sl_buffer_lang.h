#ifndef mk_include_guard_mk_sl_buffer_lang
#define mk_include_guard_mk_sl_buffer_lang


#define mk_sl_buffer_t_name lang
#define mk_sl_buffer_t_mallocator mk_sl_mallocator_lang
#include "mk_sl_buffer_inl_fileh.h"


#if mk_lang_jumbo_want == 1
#include "mk_sl_buffer_lang.c"
#endif
#endif
