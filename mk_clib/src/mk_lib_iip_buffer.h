#ifndef mk_include_guard_mk_lib_iip_buffer_h
#define mk_include_guard_mk_lib_iip_buffer_h


#include "mk_lang_jumbo.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_sl_cui_uint8.h"


#define mk_sl_dynamic_ring_t_name mk_lib_iip_buffer
#define mk_sl_dynamic_ring_t_element_type mk_sl_cui_uint8_t
#define mk_sl_dynamic_ring_t_mallocatorg mk_lib_iip_cp_mallocator_global
#include "mk_sl_dynamic_ring_inl_fileh.h"
#include "mk_sl_dynamic_ring_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_iip_buffer.c"
#endif
#endif
