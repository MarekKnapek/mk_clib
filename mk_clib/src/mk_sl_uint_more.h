#ifndef mk_include_guard_mk_sl_uint_more_h
#define mk_include_guard_mk_sl_uint_more_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_xor2_many(mk_sl_cui_uint8_pt const a,mk_sl_cui_uint8_pct const b, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_xor3_many_1(mk_sl_cui_uint8_pct const a,mk_sl_cui_uint8_pct const b, mk_lang_types_usize_t const count, mk_sl_cui_uint8_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_xor3_many_n(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pct const b, mk_lang_types_usize_t const count, mk_sl_cui_uint8_pt const c) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_from_bi_uchar_many(mk_sl_cui_uint8_pt const a, mk_lang_types_uchar_pct const b, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_from_bi_pchar_many(mk_sl_cui_uint8_pt const a, mk_lang_types_pchar_pct const b, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_to_bi_pchar_many(mk_sl_cui_uint8_pct const a, mk_lang_types_pchar_pt const b, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_to_bi_uchar_many(mk_sl_cui_uint8_pct const a, mk_lang_types_uchar_pt const b, mk_lang_types_usize_t const count) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_uint8_eq_pchar_many(mk_sl_cui_uint8_pct const a, mk_lang_types_pchar_pct const b, mk_lang_types_usize_t const count) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_uint_more.c"
#endif
#endif
