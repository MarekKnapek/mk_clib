#ifndef mk_include_guard_mk_lib_flt_analyzer_quad
#define mk_include_guard_mk_lib_flt_analyzer_quad


#include "mk_lang_jumbo.h"
#include "mk_lang_types.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint8.h"

#define mk_lib_flt_analyzer_t_name mk_lib_flt_analyzer_quad
#define mk_lib_flt_analyzer_t_flt_bits 128
#define mk_lib_flt_analyzer_t_flt_frac 112
#define mk_lib_flt_analyzer_t_uint mk_sl_cui_uint128
#define mk_lib_flt_analyzer_t_lent mk_sl_cui_uint8
#define mk_lib_flt_analyzer_t_expuint mk_sl_cui_uint16
#define mk_lib_flt_analyzer_t_mtsuint mk_sl_cui_uint128
#define mk_lib_flt_analyzer_t_mtslent mk_sl_cui_uint16
#include "mk_lib_flt_analyzer_inl_fileh.h"


#if mk_lang_jumbo_want == 1
#include "mk_lib_flt_analyzer_quad.c"
#endif
#endif
