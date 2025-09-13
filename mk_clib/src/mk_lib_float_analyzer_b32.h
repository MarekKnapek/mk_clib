#ifndef mk_include_guard_mk_lib_float_analyzer_b32_h
#define mk_include_guard_mk_lib_float_analyzer_b32_h


#include "mk_lang_jumbo.h"


#define mk_lib_float_analyzer_t_name mk_lib_float_analyzer_b32
#define mk_lib_float_analyzer_t_bits_all 32
#define mk_lib_float_analyzer_t_bits_exponent 8
#define mk_lib_float_analyzer_t_bits_mantissa 23
#include "mk_lib_float_analyzer_inl_fileh.h"
#include "mk_lib_float_analyzer_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_float_analyzer_b32.c"
#endif
#endif
