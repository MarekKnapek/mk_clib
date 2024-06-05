#ifndef mk_include_guard_mk_sl_uint
#define mk_include_guard_mk_sl_uint


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_uint128.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_16_to_8_le(mk_sl_cui_uint16_pct const u16, mk_lang_static_param(mk_sl_cui_uint8_t, u8, 2)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_16_to_8_be(mk_sl_cui_uint16_pct const u16, mk_lang_static_param(mk_sl_cui_uint8_t, u8, 2)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_32_to_8_le(mk_sl_cui_uint32_pct const u32, mk_lang_static_param(mk_sl_cui_uint8_t, u8, 4)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_32_to_8_be(mk_sl_cui_uint32_pct const u32, mk_lang_static_param(mk_sl_cui_uint8_t, u8, 4)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_64_to_8_le(mk_sl_cui_uint64_pct const u64, mk_lang_static_param(mk_sl_cui_uint8_t, u8, 8)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_64_to_8_be(mk_sl_cui_uint64_pct const u64, mk_lang_static_param(mk_sl_cui_uint8_t, u8, 8)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_128_to_8_le(mk_sl_cui_uint128_pct const u128, mk_lang_static_param(mk_sl_cui_uint8_t, u8, 16)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_128_to_8_be(mk_sl_cui_uint128_pct const u128, mk_lang_static_param(mk_sl_cui_uint8_t, u8, 16)) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_16_from_8_le(mk_sl_cui_uint16_pt const u16, mk_lang_static_param(mk_sl_cui_uint8_ct, u8, 2)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_16_from_8_be(mk_sl_cui_uint16_pt const u16, mk_lang_static_param(mk_sl_cui_uint8_ct, u8, 2)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_32_from_8_le(mk_sl_cui_uint32_pt const u32, mk_lang_static_param(mk_sl_cui_uint8_ct, u8, 4)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_32_from_8_be(mk_sl_cui_uint32_pt const u32, mk_lang_static_param(mk_sl_cui_uint8_ct, u8, 4)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_64_from_8_le(mk_sl_cui_uint64_pt const u64, mk_lang_static_param(mk_sl_cui_uint8_ct, u8, 8)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_64_from_8_be(mk_sl_cui_uint64_pt const u64, mk_lang_static_param(mk_sl_cui_uint8_ct, u8, 8)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_128_from_8_le(mk_sl_cui_uint128_pt const u128, mk_lang_static_param(mk_sl_cui_uint8_ct, u8, 16)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_128_from_8_be(mk_sl_cui_uint128_pt const u128, mk_lang_static_param(mk_sl_cui_uint8_ct, u8, 16)) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_64_to_32_le(mk_sl_cui_uint64_pct const u64, mk_lang_static_param(mk_sl_cui_uint32_t, u32, 2)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_64_from_32_le(mk_sl_cui_uint64_pt const u64, mk_lang_static_param(mk_sl_cui_uint32_ct, u32, 2)) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_128_to_64_le(mk_sl_cui_uint128_pct const u128, mk_lang_static_param(mk_sl_cui_uint64_t, u64, 2)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_uint_128_from_64_le(mk_sl_cui_uint128_pt const u128, mk_lang_static_param(mk_sl_cui_uint64_ct, u64, 2)) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_sl_uint.c"
#endif
#endif
