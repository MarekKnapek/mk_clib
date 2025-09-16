#ifndef mk_include_guard_mk_lib_float_analyzer_b64_h
#define mk_include_guard_mk_lib_float_analyzer_b64_h


#include "mk_lang_jumbo.h"


#define mk_lib_float_analyzer_t_name mk_lib_float_analyzer_b64
#define mk_lib_float_analyzer_t_bits_all 64
#define mk_lib_float_analyzer_t_bits_exponent 11
#define mk_lib_float_analyzer_t_bits_mantissa 52
#include "mk_lib_float_analyzer_inl_fileh.h"
#include "mk_lib_float_analyzer_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_float_analyzer_b64.c"
#endif
#endif
