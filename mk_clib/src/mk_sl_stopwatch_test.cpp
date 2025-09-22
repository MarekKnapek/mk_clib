#ifndef mk_include_guard_mk_sl_stopwatch_test_cpp
#define mk_include_guard_mk_sl_stopwatch_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_sl_stopwatch_test.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr_array_u8.hpp"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_stopwatch.h"
#include "mk_sl_uint_more.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_sl_stopwatch_test_duration_nanos_to_text_hlp(mk_lang_types_pchar_t const(&str_lit_buf)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t duration mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_pchar_t, mk_sl_stopwatch_duration_text_max_len> txt mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1 + 1);

	len = mk_sl_stopwatch_duration_from_str_dec_n(&duration, &str_lit_buf[0], str_lit_len - 1); mk_lang_assert(len == str_lit_len - 1);
	len = mk_sl_stopwatch_duration_to_text(&duration, txt.data(), ((mk_lang_types_sint_t)(txt.size()))); mk_lang_assert(len >= 1); mk_lang_assert(len <= ((mk_lang_types_sint_t)(txt.size())));
	return len;
}

template<mk_lang_types_usize_t hlp, mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_sl_stopwatch_test_duration_nanos_to_text_impl(mk_lang_types_pchar_t const(&str_lit_buf)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t duration mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_pchar_t, mk_sl_stopwatch_duration_text_max_len> txt mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, hlp> ret mk_lang_constexpr_init;

	mk_lang_static_assert(hlp >= 1);
	mk_lang_static_assert(hlp <= mk_sl_stopwatch_duration_text_max_len);
	mk_lang_static_assert(str_lit_len >= 1 + 1);

	len = mk_sl_stopwatch_duration_from_str_dec_n(&duration, &str_lit_buf[0], str_lit_len - 1); mk_lang_assert(len == str_lit_len - 1);
	len = mk_sl_stopwatch_duration_to_text(&duration, txt.data(), ((mk_lang_types_sint_t)(txt.size()))); mk_lang_assert(len >= 1); mk_lang_assert(len <= ((mk_lang_types_sint_t)(txt.size())));
	mk_sl_cui_uint8_from_bi_pchar_many(ret.data(), txt.data(), ret.size());
	return ret;
}

#define mk_sl_stopwatch_test_duration_nanos_to_text(str_lit) mk_sl_stopwatch_test_duration_nanos_to_text_impl<mk_sl_stopwatch_test_duration_nanos_to_text_hlp(str_lit)>(str_lit)

#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_sl_stopwatch_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define nanos_01 "0"
	#define nanos_02 "1"
	#define nanos_03 "100"
	#define nanos_04 "101"
	#define nanos_05 "900"

	#define nanos_06 "9999"
	#define nanos_07 "1000"
	#define nanos_08 "1001"
	#define nanos_09 "1100"
	#define nanos_10 "1101"
	#define nanos_11 "999000"
	#define nanos_12 "999009"
	#define nanos_13 "999900"
	#define nanos_14 "999999"

	#define nanos_15 "1000000"
	#define nanos_16 "1000001"
	#define nanos_17 "999000000"
	#define nanos_18 "999999000"
	#define nanos_19 "999999999"

	#define nanos_20 "1000000000"
	#define nanos_21 "1000000001"
	#define nanos_22 "1100000000"
	#define nanos_23 "1100000001"
	#define nanos_24 "1100010000"
	#define nanos_25 "59000000001"
	#define nanos_26 "59100000000"
	#define nanos_27 "59999999999"

	#define nanos_28 "60000000000"
	#define nanos_29 "60000000001"
	#define nanos_35 "60999999999"
	#define nanos_30 "61000000000"
	#define nanos_31 "61000000001"
	#define nanos_32 "61000010000"
	#define nanos_33 "91000000001"
	#define nanos_34 "91010000000"
	#define nanos_36 "3599999999999"

	#define nanos_37 "3600000000000"
	#define nanos_38 "3660000000000"

	#define nanos_39 "86400000000000"
	#define nanos_40 "90000000000000"
	#define nanos_41 "9223372036854775807"

	#define text_01 "0 ns"
	#define text_02 "1 ns"
	#define text_03 "100 ns"
	#define text_04 "101 ns"
	#define text_05 "900 ns"

	#define text_06 "9.999 us"
	#define text_07 "1.0 us"
	#define text_08 "1.001 us"
	#define text_09 "1.1 us"
	#define text_10 "1.101 us"
	#define text_11 "999.0 us"
	#define text_12 "999.009 us"
	#define text_13 "999.9 us"
	#define text_14 "999.999 us"

	#define text_15 "1.0 ms"
	#define text_16 "1.000001 ms"
	#define text_17 "999.0 ms"
	#define text_18 "999.999 ms"
	#define text_19 "999.999999 ms"

	#define text_20 "1.0 s"
	#define text_21 "1.000000001 s"
	#define text_22 "1.1 s"
	#define text_23 "1.100000001 s"
	#define text_24 "1.10001 s"
	#define text_25 "59.000000001 s"
	#define text_26 "59.1 s"
	#define text_27 "59.999999999 s"

	#define text_28 "1:00.0 m"
	#define text_29 "1:00.000000001 m"
	#define text_35 "1:00.999999999 m"
	#define text_30 "1:01.0 m"
	#define text_31 "1:01.000000001 m"
	#define text_32 "1:01.00001 m"
	#define text_33 "1:31.000000001 m"
	#define text_34 "1:31.01 m"
	#define text_36 "59:59.999999999 m"

	#define text_37 "1:00:00.0 h"
	#define text_38 "1:01:00.0 h"

	#define text_39 "1+00:00:00.0 d"
	#define text_40 "1+01:00:00.0 d"
	#define text_41 "106751+23:47:16.854775807 d"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_text_computed_01 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_01);
	mk_lang_constexpr_static auto const s_text_computed_02 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_02);
	mk_lang_constexpr_static auto const s_text_computed_03 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_03);
	mk_lang_constexpr_static auto const s_text_computed_04 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_04);
	mk_lang_constexpr_static auto const s_text_computed_05 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_05);
	mk_lang_constexpr_static auto const s_text_computed_06 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_06);
	mk_lang_constexpr_static auto const s_text_computed_07 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_07);
	mk_lang_constexpr_static auto const s_text_computed_08 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_08);
	mk_lang_constexpr_static auto const s_text_computed_09 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_09);
	mk_lang_constexpr_static auto const s_text_computed_10 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_10);
	mk_lang_constexpr_static auto const s_text_computed_11 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_11);
	mk_lang_constexpr_static auto const s_text_computed_12 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_12);
	mk_lang_constexpr_static auto const s_text_computed_13 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_13);
	mk_lang_constexpr_static auto const s_text_computed_14 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_14);
	mk_lang_constexpr_static auto const s_text_computed_15 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_15);
	mk_lang_constexpr_static auto const s_text_computed_16 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_16);
	mk_lang_constexpr_static auto const s_text_computed_17 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_17);
	mk_lang_constexpr_static auto const s_text_computed_18 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_18);
	mk_lang_constexpr_static auto const s_text_computed_19 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_19);
	mk_lang_constexpr_static auto const s_text_computed_20 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_20);
	mk_lang_constexpr_static auto const s_text_computed_21 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_21);
	mk_lang_constexpr_static auto const s_text_computed_22 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_22);
	mk_lang_constexpr_static auto const s_text_computed_23 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_23);
	mk_lang_constexpr_static auto const s_text_computed_24 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_24);
	mk_lang_constexpr_static auto const s_text_computed_25 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_25);
	mk_lang_constexpr_static auto const s_text_computed_26 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_26);
	mk_lang_constexpr_static auto const s_text_computed_27 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_27);
	mk_lang_constexpr_static auto const s_text_computed_28 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_28);
	mk_lang_constexpr_static auto const s_text_computed_29 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_29);
	mk_lang_constexpr_static auto const s_text_computed_30 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_30);
	mk_lang_constexpr_static auto const s_text_computed_31 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_31);
	mk_lang_constexpr_static auto const s_text_computed_32 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_32);
	mk_lang_constexpr_static auto const s_text_computed_33 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_33);
	mk_lang_constexpr_static auto const s_text_computed_34 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_34);
	mk_lang_constexpr_static auto const s_text_computed_35 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_35);
	mk_lang_constexpr_static auto const s_text_computed_36 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_36);
	mk_lang_constexpr_static auto const s_text_computed_37 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_37);
	mk_lang_constexpr_static auto const s_text_computed_38 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_38);
	mk_lang_constexpr_static auto const s_text_computed_39 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_39);
	mk_lang_constexpr_static auto const s_text_computed_40 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_40);
	mk_lang_constexpr_static auto const s_text_computed_41 = mk_sl_stopwatch_test_duration_nanos_to_text(nanos_41);

	mk_lang_constexpr_static auto const s_text_precomputed_01 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_01);
	mk_lang_constexpr_static auto const s_text_precomputed_02 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_02);
	mk_lang_constexpr_static auto const s_text_precomputed_03 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_03);
	mk_lang_constexpr_static auto const s_text_precomputed_04 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_04);
	mk_lang_constexpr_static auto const s_text_precomputed_05 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_05);
	mk_lang_constexpr_static auto const s_text_precomputed_06 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_06);
	mk_lang_constexpr_static auto const s_text_precomputed_07 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_07);
	mk_lang_constexpr_static auto const s_text_precomputed_08 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_08);
	mk_lang_constexpr_static auto const s_text_precomputed_09 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_09);
	mk_lang_constexpr_static auto const s_text_precomputed_10 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_10);
	mk_lang_constexpr_static auto const s_text_precomputed_11 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_11);
	mk_lang_constexpr_static auto const s_text_precomputed_12 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_12);
	mk_lang_constexpr_static auto const s_text_precomputed_13 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_13);
	mk_lang_constexpr_static auto const s_text_precomputed_14 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_14);
	mk_lang_constexpr_static auto const s_text_precomputed_15 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_15);
	mk_lang_constexpr_static auto const s_text_precomputed_16 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_16);
	mk_lang_constexpr_static auto const s_text_precomputed_17 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_17);
	mk_lang_constexpr_static auto const s_text_precomputed_18 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_18);
	mk_lang_constexpr_static auto const s_text_precomputed_19 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_19);
	mk_lang_constexpr_static auto const s_text_precomputed_20 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_20);
	mk_lang_constexpr_static auto const s_text_precomputed_21 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_21);
	mk_lang_constexpr_static auto const s_text_precomputed_22 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_22);
	mk_lang_constexpr_static auto const s_text_precomputed_23 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_23);
	mk_lang_constexpr_static auto const s_text_precomputed_24 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_24);
	mk_lang_constexpr_static auto const s_text_precomputed_25 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_25);
	mk_lang_constexpr_static auto const s_text_precomputed_26 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_26);
	mk_lang_constexpr_static auto const s_text_precomputed_27 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_27);
	mk_lang_constexpr_static auto const s_text_precomputed_28 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_28);
	mk_lang_constexpr_static auto const s_text_precomputed_29 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_29);
	mk_lang_constexpr_static auto const s_text_precomputed_30 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_30);
	mk_lang_constexpr_static auto const s_text_precomputed_31 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_31);
	mk_lang_constexpr_static auto const s_text_precomputed_32 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_32);
	mk_lang_constexpr_static auto const s_text_precomputed_33 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_33);
	mk_lang_constexpr_static auto const s_text_precomputed_34 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_34);
	mk_lang_constexpr_static auto const s_text_precomputed_35 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_35);
	mk_lang_constexpr_static auto const s_text_precomputed_36 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_36);
	mk_lang_constexpr_static auto const s_text_precomputed_37 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_37);
	mk_lang_constexpr_static auto const s_text_precomputed_38 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_38);
	mk_lang_constexpr_static auto const s_text_precomputed_39 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_39);
	mk_lang_constexpr_static auto const s_text_precomputed_40 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_40);
	mk_lang_constexpr_static auto const s_text_precomputed_41 = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(text_41);

	mk_lang_static_assert(s_text_computed_01 == s_text_precomputed_01);
	mk_lang_static_assert(s_text_computed_02 == s_text_precomputed_02);
	mk_lang_static_assert(s_text_computed_03 == s_text_precomputed_03);
	mk_lang_static_assert(s_text_computed_04 == s_text_precomputed_04);
	mk_lang_static_assert(s_text_computed_05 == s_text_precomputed_05);
	mk_lang_static_assert(s_text_computed_06 == s_text_precomputed_06);
	mk_lang_static_assert(s_text_computed_07 == s_text_precomputed_07);
	mk_lang_static_assert(s_text_computed_08 == s_text_precomputed_08);
	mk_lang_static_assert(s_text_computed_09 == s_text_precomputed_09);
	mk_lang_static_assert(s_text_computed_10 == s_text_precomputed_10);
	mk_lang_static_assert(s_text_computed_11 == s_text_precomputed_11);
	mk_lang_static_assert(s_text_computed_12 == s_text_precomputed_12);
	mk_lang_static_assert(s_text_computed_13 == s_text_precomputed_13);
	mk_lang_static_assert(s_text_computed_14 == s_text_precomputed_14);
	mk_lang_static_assert(s_text_computed_15 == s_text_precomputed_15);
	mk_lang_static_assert(s_text_computed_16 == s_text_precomputed_16);
	mk_lang_static_assert(s_text_computed_17 == s_text_precomputed_17);
	mk_lang_static_assert(s_text_computed_18 == s_text_precomputed_18);
	mk_lang_static_assert(s_text_computed_19 == s_text_precomputed_19);
	mk_lang_static_assert(s_text_computed_20 == s_text_precomputed_20);
	mk_lang_static_assert(s_text_computed_21 == s_text_precomputed_21);
	mk_lang_static_assert(s_text_computed_22 == s_text_precomputed_22);
	mk_lang_static_assert(s_text_computed_23 == s_text_precomputed_23);
	mk_lang_static_assert(s_text_computed_24 == s_text_precomputed_24);
	mk_lang_static_assert(s_text_computed_25 == s_text_precomputed_25);
	mk_lang_static_assert(s_text_computed_26 == s_text_precomputed_26);
	mk_lang_static_assert(s_text_computed_27 == s_text_precomputed_27);
	mk_lang_static_assert(s_text_computed_28 == s_text_precomputed_28);
	mk_lang_static_assert(s_text_computed_29 == s_text_precomputed_29);
	mk_lang_static_assert(s_text_computed_30 == s_text_precomputed_30);
	mk_lang_static_assert(s_text_computed_31 == s_text_precomputed_31);
	mk_lang_static_assert(s_text_computed_32 == s_text_precomputed_32);
	mk_lang_static_assert(s_text_computed_33 == s_text_precomputed_33);
	mk_lang_static_assert(s_text_computed_34 == s_text_precomputed_34);
	mk_lang_static_assert(s_text_computed_35 == s_text_precomputed_35);
	mk_lang_static_assert(s_text_computed_36 == s_text_precomputed_36);
	mk_lang_static_assert(s_text_computed_37 == s_text_precomputed_37);
	mk_lang_static_assert(s_text_computed_38 == s_text_precomputed_38);
	mk_lang_static_assert(s_text_computed_39 == s_text_precomputed_39);
	mk_lang_static_assert(s_text_computed_40 == s_text_precomputed_40);
	mk_lang_static_assert(s_text_computed_41 == s_text_precomputed_41);

	#endif

	mk_lang_types_pchar_pct const nanos_bufs[] =
	{
		nanos_01,
		nanos_02,
		nanos_03,
		nanos_04,
		nanos_05,
		nanos_06,
		nanos_07,
		nanos_08,
		nanos_09,
		nanos_10,
		nanos_11,
		nanos_12,
		nanos_13,
		nanos_14,
		nanos_15,
		nanos_16,
		nanos_17,
		nanos_18,
		nanos_19,
		nanos_20,
		nanos_21,
		nanos_22,
		nanos_23,
		nanos_24,
		nanos_25,
		nanos_26,
		nanos_27,
		nanos_28,
		nanos_29,
		nanos_30,
		nanos_31,
		nanos_32,
		nanos_33,
		nanos_34,
		nanos_35,
		nanos_36,
		nanos_37,
		nanos_38,
		nanos_39,
		nanos_40,
		nanos_41,
	};

	mk_lang_types_sint_t const nanos_lens[] =
	{
		mk_lang_countstr(nanos_01),
		mk_lang_countstr(nanos_02),
		mk_lang_countstr(nanos_03),
		mk_lang_countstr(nanos_04),
		mk_lang_countstr(nanos_05),
		mk_lang_countstr(nanos_06),
		mk_lang_countstr(nanos_07),
		mk_lang_countstr(nanos_08),
		mk_lang_countstr(nanos_09),
		mk_lang_countstr(nanos_10),
		mk_lang_countstr(nanos_11),
		mk_lang_countstr(nanos_12),
		mk_lang_countstr(nanos_13),
		mk_lang_countstr(nanos_14),
		mk_lang_countstr(nanos_15),
		mk_lang_countstr(nanos_16),
		mk_lang_countstr(nanos_17),
		mk_lang_countstr(nanos_18),
		mk_lang_countstr(nanos_19),
		mk_lang_countstr(nanos_20),
		mk_lang_countstr(nanos_21),
		mk_lang_countstr(nanos_22),
		mk_lang_countstr(nanos_23),
		mk_lang_countstr(nanos_24),
		mk_lang_countstr(nanos_25),
		mk_lang_countstr(nanos_26),
		mk_lang_countstr(nanos_27),
		mk_lang_countstr(nanos_28),
		mk_lang_countstr(nanos_29),
		mk_lang_countstr(nanos_30),
		mk_lang_countstr(nanos_31),
		mk_lang_countstr(nanos_32),
		mk_lang_countstr(nanos_33),
		mk_lang_countstr(nanos_34),
		mk_lang_countstr(nanos_35),
		mk_lang_countstr(nanos_36),
		mk_lang_countstr(nanos_37),
		mk_lang_countstr(nanos_38),
		mk_lang_countstr(nanos_39),
		mk_lang_countstr(nanos_40),
		mk_lang_countstr(nanos_41),
	};

	mk_lang_types_pchar_pct const texts_bufs[] =
	{
		text_01,
		text_02,
		text_03,
		text_04,
		text_05,
		text_06,
		text_07,
		text_08,
		text_09,
		text_10,
		text_11,
		text_12,
		text_13,
		text_14,
		text_15,
		text_16,
		text_17,
		text_18,
		text_19,
		text_20,
		text_21,
		text_22,
		text_23,
		text_24,
		text_25,
		text_26,
		text_27,
		text_28,
		text_29,
		text_30,
		text_31,
		text_32,
		text_33,
		text_34,
		text_35,
		text_36,
		text_37,
		text_38,
		text_39,
		text_40,
		text_41,
	};

	mk_lang_types_sint_t const texts_lens[] =
	{
		mk_lang_countstr(text_01),
		mk_lang_countstr(text_02),
		mk_lang_countstr(text_03),
		mk_lang_countstr(text_04),
		mk_lang_countstr(text_05),
		mk_lang_countstr(text_06),
		mk_lang_countstr(text_07),
		mk_lang_countstr(text_08),
		mk_lang_countstr(text_09),
		mk_lang_countstr(text_10),
		mk_lang_countstr(text_11),
		mk_lang_countstr(text_12),
		mk_lang_countstr(text_13),
		mk_lang_countstr(text_14),
		mk_lang_countstr(text_15),
		mk_lang_countstr(text_16),
		mk_lang_countstr(text_17),
		mk_lang_countstr(text_18),
		mk_lang_countstr(text_19),
		mk_lang_countstr(text_20),
		mk_lang_countstr(text_21),
		mk_lang_countstr(text_22),
		mk_lang_countstr(text_23),
		mk_lang_countstr(text_24),
		mk_lang_countstr(text_25),
		mk_lang_countstr(text_26),
		mk_lang_countstr(text_27),
		mk_lang_countstr(text_28),
		mk_lang_countstr(text_29),
		mk_lang_countstr(text_30),
		mk_lang_countstr(text_31),
		mk_lang_countstr(text_32),
		mk_lang_countstr(text_33),
		mk_lang_countstr(text_34),
		mk_lang_countstr(text_35),
		mk_lang_countstr(text_36),
		mk_lang_countstr(text_37),
		mk_lang_countstr(text_38),
		mk_lang_countstr(text_39),
		mk_lang_countstr(text_40),
		mk_lang_countstr(text_41),
	};

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t duration mk_lang_constexpr_init;
	mk_lang_types_pchar_t txt[mk_sl_stopwatch_duration_text_max_len] mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(nanos_bufs) == mk_lang_countof(nanos_lens));
	mk_lang_static_assert(mk_lang_countof(nanos_bufs) == mk_lang_countof(texts_bufs));
	mk_lang_static_assert(mk_lang_countof(nanos_bufs) == mk_lang_countof(texts_lens));

	n = mk_lang_countof(nanos_bufs);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(nanos_lens[i] >= 1);
		len = mk_sl_stopwatch_duration_from_str_dec_n(&duration, &nanos_bufs[i][0], nanos_lens[i]); mk_lang_assert(len == nanos_lens[i]);
		len = mk_sl_stopwatch_duration_to_text(&duration, &txt[0], mk_lang_countof(txt)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(txt));
		mk_lang_test(len == texts_lens[i]);
		mk_lang_test(mk_lang_string_memcmp_pc_fn(&txt[0], &texts_bufs[i][0], ((mk_lang_types_usize_t)(len))) == 0);
	}

	#undef nanos_01
	#undef nanos_02
	#undef nanos_03
	#undef nanos_04
	#undef nanos_05
	#undef nanos_06
	#undef nanos_07
	#undef nanos_08
	#undef nanos_09
	#undef nanos_10
	#undef nanos_11
	#undef nanos_12
	#undef nanos_13
	#undef nanos_14
	#undef nanos_15
	#undef nanos_16
	#undef nanos_17
	#undef nanos_18
	#undef nanos_19
	#undef nanos_20
	#undef nanos_21
	#undef nanos_22
	#undef nanos_23
	#undef nanos_24
	#undef nanos_25
	#undef nanos_26
	#undef nanos_27
	#undef nanos_28
	#undef nanos_29
	#undef nanos_35
	#undef nanos_30
	#undef nanos_31
	#undef nanos_32
	#undef nanos_33
	#undef nanos_34
	#undef nanos_36
	#undef nanos_37
	#undef nanos_38
	#undef nanos_39
	#undef nanos_40
	#undef nanos_41

	#undef text_01
	#undef text_02
	#undef text_03
	#undef text_04
	#undef text_05
	#undef text_06
	#undef text_07
	#undef text_08
	#undef text_09
	#undef text_10
	#undef text_11
	#undef text_12
	#undef text_13
	#undef text_14
	#undef text_15
	#undef text_16
	#undef text_17
	#undef text_18
	#undef text_19
	#undef text_20
	#undef text_21
	#undef text_22
	#undef text_23
	#undef text_24
	#undef text_25
	#undef text_26
	#undef text_27
	#undef text_28
	#undef text_29
	#undef text_35
	#undef text_30
	#undef text_31
	#undef text_32
	#undef text_33
	#undef text_34
	#undef text_36
	#undef text_37
	#undef text_38
	#undef text_39
	#undef text_40
	#undef text_41
}


#include "mk_lang_warning_msvc_pop.h"


#endif
