#ifndef mk_include_guard_mk_sl_uint
#define mk_include_guard_mk_sl_uint


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_32_to_8_le(mk_sl_cui_uint32_pct const u32, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_32_to_8_be(mk_sl_cui_uint32_pct const u32, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_64_to_8_le(mk_sl_cui_uint64_pct const u64, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_64_to_8_be(mk_sl_cui_uint64_pct const u64, mk_sl_cui_uint8_pt const u8) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_32_from_8_le(mk_sl_cui_uint32_pt const u32, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_32_from_8_be(mk_sl_cui_uint32_pt const u32, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_64_from_8_le(mk_sl_cui_uint64_pt const u64, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo void mk_sl_uint_64_from_8_be(mk_sl_cui_uint64_pt const u64, mk_sl_cui_uint8_pct const u8) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_uint.c"
#endif
#endif
