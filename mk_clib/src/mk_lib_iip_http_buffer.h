#ifndef mk_include_guard_mk_lib_iip_http_buffer_h
#define mk_include_guard_mk_lib_iip_http_buffer_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_sl_cui_uint8.h"


#define mk_sl_dynamic_ring_t_name mk_lib_iip_http_buffer
#define mk_sl_dynamic_ring_t_element_type mk_sl_cui_uint8_t
#define mk_sl_dynamic_ring_t_mallocatorg mk_lib_iip_cp_mallocator_global
#include "mk_sl_dynamic_ring_inl_fileh.h"
#include "mk_sl_dynamic_ring_inl_fileu.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_buffer_rw_fancy_string(mk_lib_iip_http_buffer_pt const buffer) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_http_buffer.c"
#endif
#endif
