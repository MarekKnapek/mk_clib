#ifndef mk_include_guard_mk_sl_fxp_128_h
#define mk_include_guard_mk_sl_fxp_128_h


#include "mk_lang_jumbo.h"
#include "mk_sl_cui_uint128.h"


#define mk_sl_fxp_t_name mk_sl_fxp_128_64_64
#define mk_sl_fxp_t_base_type_name mk_sl_cui_uint128
#define mk_sl_fxp_t_bits_before 64
#define mk_sl_fxp_t_bits_after 64
#include "mk_sl_fxp_inl_fileh.h"
#include "mk_sl_fxp_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_sl_fxp_128.c"
#endif
#endif
