#include "mk_lib_flt_analyzer_double.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_types.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#undef mk_lib_flt_analyzer_t_name
#undef mk_lib_flt_analyzer_t_flt_bits
#undef mk_lib_flt_analyzer_t_flt_frac
#undef mk_lib_flt_analyzer_t_uint
#undef mk_lib_flt_analyzer_t_lent
#undef mk_lib_flt_analyzer_t_expuint
#undef mk_lib_flt_analyzer_t_mtsuint
#undef mk_lib_flt_analyzer_t_mtslent
#define mk_lib_flt_analyzer_t_name mk_lib_flt_analyzer_double
#define mk_lib_flt_analyzer_t_flt_bits 64
#define mk_lib_flt_analyzer_t_flt_frac 52
#define mk_lib_flt_analyzer_t_uint mk_sl_cui_uint64
#define mk_lib_flt_analyzer_t_lent mk_sl_cui_uint8
#define mk_lib_flt_analyzer_t_expuint mk_sl_cui_uint16
#define mk_lib_flt_analyzer_t_mtsuint mk_sl_cui_uint64
#define mk_lib_flt_analyzer_t_mtslent mk_sl_cui_uint16
#include "mk_lib_flt_analyzer_inl_filec.h"
