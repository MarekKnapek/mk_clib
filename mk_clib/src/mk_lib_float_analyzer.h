#ifndef mk_include_guard_mk_lib_float_analyzer
#define mk_include_guard_mk_lib_float_analyzer


#include "mk_lang_jumbo.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"

#define mk_lib_flt_analyzer_t_name mk_lib_float_analyzer
#define mk_lib_flt_analyzer_t_flt_bits 32
#define mk_lib_flt_analyzer_t_flt_frac 23
#define mk_lib_flt_analyzer_t_uint mk_sl_cui_uint32
#define mk_lib_flt_analyzer_t_lent mk_lang_types_uchar
#define mk_lib_flt_analyzer_t_expuint mk_sl_cui_uint8
#define mk_lib_flt_analyzer_t_mtsuint mk_sl_cui_uint32
#define mk_lib_flt_analyzer_t_mtslent mk_lang_types_uchar
#include "mk_lib_flt_analyzer_inl_fileh.h"


#if mk_lang_jumbo_want == 1
#include "mk_lib_float_analyzer.c"
#endif
#endif
