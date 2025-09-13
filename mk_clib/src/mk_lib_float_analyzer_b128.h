#ifndef mk_include_guard_mk_lib_float_analyzer_b128_h
#define mk_include_guard_mk_lib_float_analyzer_b128_h


#include "mk_lang_jumbo.h"


#define mk_lib_float_analyzer_t_name mk_lib_float_analyzer_b128
#define mk_lib_float_analyzer_t_bits_all 128
#define mk_lib_float_analyzer_t_bits_exponent 15
#define mk_lib_float_analyzer_t_bits_mantissa 112
#include "mk_lib_float_analyzer_inl_fileh.h"
#include "mk_lib_float_analyzer_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_float_analyzer_b128.c"
#endif
#endif
