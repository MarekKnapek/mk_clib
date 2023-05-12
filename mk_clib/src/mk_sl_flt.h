#ifndef include_guard_mk_sl_flt
#define include_guard_mk_sl_flt


#include "mk_lang_jumbo.h"


#define mk_sl_flt_b32_bits 32
#define mk_sl_flt_b32_fraction_bits 23

#define mk_sl_flt_b64_bits 64
#define mk_sl_flt_b64_fraction_bits 52


#define mk_sl_flt_name float
#define mk_sl_flt_bits mk_sl_flt_b32_bits
#define mk_sl_flt_fraction_bits mk_sl_flt_b32_fraction_bits
#include "mk_sl_flt_inl_fileh.h"
#undef mk_sl_flt_name
#undef mk_sl_flt_bits
#undef mk_sl_flt_fraction_bits

#define mk_sl_flt_name double
#define mk_sl_flt_bits mk_sl_flt_b64_bits
#define mk_sl_flt_fraction_bits mk_sl_flt_b64_fraction_bits
#include "mk_sl_flt_inl_fileh.h"
#undef mk_sl_flt_name
#undef mk_sl_flt_bits
#undef mk_sl_flt_fraction_bits


#if mk_lang_jumbo_want == 1
#include "mk_sl_flt.c"
#endif
#endif
