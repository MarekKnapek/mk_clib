#ifndef mk_include_guard_mk_lib_iip_base32_encoder_h
#define mk_include_guard_mk_lib_iip_base32_encoder_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_base32_encoder_fn(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_base32_encoder.c"
#endif
#endif
