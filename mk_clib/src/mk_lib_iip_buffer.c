#ifndef mk_include_guard_mk_lib_iip_buffer_c
#define mk_include_guard_mk_lib_iip_buffer_c
#include "mk_lib_iip_buffer.h"

#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_sl_cui_uint8.h"


#define mk_sl_dynamic_ring_t_name mk_lib_iip_buffer
#define mk_sl_dynamic_ring_t_element_type mk_sl_cui_uint8_t
#define mk_sl_dynamic_ring_t_mallocatorg mk_lib_iip_cp_mallocator_global
#include "mk_sl_dynamic_ring_inl_filec.h"
#include "mk_sl_dynamic_ring_inl_fileu.h"


#endif
