#include "mk_lib_float_analyzer.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"

#undef mk_lib_flt_analyzer_t_name
#undef mk_lib_flt_analyzer_t_flt_bits
#undef mk_lib_flt_analyzer_t_flt_frac
#undef mk_lib_flt_analyzer_t_uint
#undef mk_lib_flt_analyzer_t_lent
#undef mk_lib_flt_analyzer_t_expuint
#undef mk_lib_flt_analyzer_t_mtsuint
#undef mk_lib_flt_analyzer_t_mtslent
#define mk_lib_flt_analyzer_t_name mk_lib_float_analyzer
#define mk_lib_flt_analyzer_t_flt_bits 32
#define mk_lib_flt_analyzer_t_flt_frac 23
#define mk_lib_flt_analyzer_t_uint mk_sl_cui_uint32
#define mk_lib_flt_analyzer_t_lent mk_lang_types_uchar
#define mk_lib_flt_analyzer_t_expuint mk_sl_cui_uint8
#define mk_lib_flt_analyzer_t_mtsuint mk_sl_cui_uint32
#define mk_lib_flt_analyzer_t_mtslent mk_lang_types_uchar
#include "mk_lib_flt_analyzer_inl_filec.h"
