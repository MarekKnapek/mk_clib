#ifndef mk_include_guard_mk_lib_double_analyzer
#define mk_include_guard_mk_lib_double_analyzer


#include "mk_lang_jumbo.h"
#include "mk_lang_types.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint64.h"

#define mk_lib_flt_analyzer_t_name mk_lib_double_analyzer
#define mk_lib_flt_analyzer_t_flt_bits 64
#define mk_lib_flt_analyzer_t_flt_frac 52
#define mk_lib_flt_analyzer_t_uint mk_sl_cui_uint64
#define mk_lib_flt_analyzer_t_lent mk_lang_types_uchar
#define mk_lib_flt_analyzer_t_expuint mk_sl_cui_uint16
#define mk_lib_flt_analyzer_t_mtsuint mk_sl_cui_uint64
#define mk_lib_flt_analyzer_t_mtslent mk_lang_types_ushort
#include "mk_lib_flt_analyzer_inl_fileh.h"


#if mk_lang_jumbo_want == 1
#include "mk_lib_double_analyzer.c"
#endif
#endif
