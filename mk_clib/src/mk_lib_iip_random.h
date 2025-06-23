#ifndef mk_include_guard_mk_lib_iip_random_h
#define mk_include_guard_mk_lib_iip_random_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint32);
mk_lang_forward(mk_sl_cui_uint8);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_random_generate_u32_any(mk_sl_cui_uint32_pt const u32) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_random_generate_u32_non_zero(mk_sl_cui_uint32_pt const u32) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_random_generate_u8s(mk_sl_cui_uint8_pt const u8s, mk_lang_types_sint_t const count) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_random_generate_uchars(mk_lang_types_uchar_pt const ucs, mk_lang_types_sint_t const count) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_random.c"
#endif
#endif
