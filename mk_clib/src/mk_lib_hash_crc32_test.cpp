#ifndef mk_include_guard_mk_lib_hash_crc32_test_cpp
#define mk_include_guard_mk_lib_hash_crc32_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_hash_crc32_test.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr_array_u8.hpp"
#include "mk_lib_hash_crc32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t str_lit_hex_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_hash_crc32_test_compute_from_str_lit_hex(mk_lang_types_pchar_t const(&str_lit_hex_buf)[str_lit_hex_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (str_lit_hex_len - 1) / 2> msg mk_lang_constexpr_init;
	mk_lib_hash_crc32_t crc32 mk_lang_constexpr_init;
	mk_lib_hash_crc32_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_hash_crc32_digest_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_hex_len >= 1);
	mk_lang_static_assert((str_lit_hex_len - 1) % 2 == 0);

	msg = mk_lib_cpp_constexpr_array_u8_from_hex_lit(str_lit_hex_buf);
	mk_lib_hash_crc32_init(&crc32);
	mk_lib_hash_crc32_append(&crc32, msg.data(), msg.size());
	mk_lib_hash_crc32_finish(&crc32, &digest);
	ret = mk_lib_cpp_constexpr_array_u8_from_u8s(digest.m_data.m_uint8s);
	return ret;
}

template<mk_lang_types_usize_t str_lit_buf_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_hash_crc32_test_compute_from_str_lit_buf(mk_lang_types_pchar_t const(&str_lit_buf_buf)[str_lit_buf_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, str_lit_buf_len - 1> msg mk_lang_constexpr_init;
	mk_lib_hash_crc32_t crc32 mk_lang_constexpr_init;
	mk_lib_hash_crc32_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_hash_crc32_digest_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_buf_len >= 1);

	msg = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(str_lit_buf_buf);
	mk_lib_hash_crc32_init(&crc32);
	mk_lib_hash_crc32_append(&crc32, msg.data(), msg.size());
	mk_lib_hash_crc32_finish(&crc32, &digest);
	ret = mk_lib_cpp_constexpr_array_u8_from_u8s(digest.m_data.m_uint8s);
	return ret;
}

#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_hash_crc32_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define message_01 ""
	#define message_02 "00"
	#define message_03 "ff"
	#define message_04 "81"
	#define message_05 "8001"
	#define message_06 "800001"
	#define message_07 "80000001"
	#define message_08 "8000000001"
	#define message_09 "800000000001"
	#define message_10 "80000000000001"
	#define message_11 "8000000000000001"
	#define message_12 "800000000000000001"
	#define message_13 "7e"
	#define message_14 "7ffe"
	#define message_15 "7ffffe"
	#define message_16 "7ffffffe"
	#define message_17 "7ffffffffe"
	#define message_18 "7ffffffffffe"
	#define message_19 "7ffffffffffffe"
	#define message_20 "7ffffffffffffffe"
	#define message_21 "7ffffffffffffffffe"
	#define message_22 "The quick brown fox jumps over the lazy dog"

	#define digest_01 "00000000"
	#define digest_02 "8def02d2"
	#define digest_03 "000000ff"
	#define digest_04 "3b5cbd48"
	#define digest_05 "22ba5d0d"
	#define digest_06 "04f27369"
	#define digest_07 "b1591abb"
	#define digest_08 "1977c300"
	#define digest_09 "ed8575d8"
	#define digest_10 "1a057d62"
	#define digest_11 "256a1e41"
	#define digest_12 "77245bf7"
	#define digest_13 "b6b3bf65"
	#define digest_14 "dda87bb3"
	#define digest_15 "16d4cd69"
	#define digest_16 "5279a165"
	#define digest_17 "76901c14"
	#define digest_18 "4ec96e28"
	#define digest_19 "89035000"
	#define digest_20 "506a7805"
	#define digest_21 "492872fa"
	#define digest_22 "39a34f41"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_digest_computed_01 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_01);
	mk_lang_constexpr_static auto const s_digest_computed_02 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_02);
	mk_lang_constexpr_static auto const s_digest_computed_03 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_03);
	mk_lang_constexpr_static auto const s_digest_computed_04 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_04);
	mk_lang_constexpr_static auto const s_digest_computed_05 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_05);
	mk_lang_constexpr_static auto const s_digest_computed_06 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_06);
	mk_lang_constexpr_static auto const s_digest_computed_07 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_07);
	mk_lang_constexpr_static auto const s_digest_computed_08 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_08);
	mk_lang_constexpr_static auto const s_digest_computed_09 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_09);
	mk_lang_constexpr_static auto const s_digest_computed_10 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_10);
	mk_lang_constexpr_static auto const s_digest_computed_11 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_11);
	mk_lang_constexpr_static auto const s_digest_computed_12 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_12);
	mk_lang_constexpr_static auto const s_digest_computed_13 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_13);
	mk_lang_constexpr_static auto const s_digest_computed_14 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_14);
	mk_lang_constexpr_static auto const s_digest_computed_15 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_15);
	mk_lang_constexpr_static auto const s_digest_computed_16 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_16);
	mk_lang_constexpr_static auto const s_digest_computed_17 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_17);
	mk_lang_constexpr_static auto const s_digest_computed_18 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_18);
	mk_lang_constexpr_static auto const s_digest_computed_19 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_19);
	mk_lang_constexpr_static auto const s_digest_computed_20 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_20);
	mk_lang_constexpr_static auto const s_digest_computed_21 = mk_lib_hash_crc32_test_compute_from_str_lit_hex(message_21);
	mk_lang_constexpr_static auto const s_digest_computed_22 = mk_lib_hash_crc32_test_compute_from_str_lit_buf(message_22);

	mk_lang_constexpr_static auto const s_digest_precomputed_01 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_01);
	mk_lang_constexpr_static auto const s_digest_precomputed_02 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_02);
	mk_lang_constexpr_static auto const s_digest_precomputed_03 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_03);
	mk_lang_constexpr_static auto const s_digest_precomputed_04 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_04);
	mk_lang_constexpr_static auto const s_digest_precomputed_05 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_05);
	mk_lang_constexpr_static auto const s_digest_precomputed_06 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_06);
	mk_lang_constexpr_static auto const s_digest_precomputed_07 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_07);
	mk_lang_constexpr_static auto const s_digest_precomputed_08 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_08);
	mk_lang_constexpr_static auto const s_digest_precomputed_09 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_09);
	mk_lang_constexpr_static auto const s_digest_precomputed_10 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_10);
	mk_lang_constexpr_static auto const s_digest_precomputed_11 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_11);
	mk_lang_constexpr_static auto const s_digest_precomputed_12 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_12);
	mk_lang_constexpr_static auto const s_digest_precomputed_13 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_13);
	mk_lang_constexpr_static auto const s_digest_precomputed_14 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_14);
	mk_lang_constexpr_static auto const s_digest_precomputed_15 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_15);
	mk_lang_constexpr_static auto const s_digest_precomputed_16 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_16);
	mk_lang_constexpr_static auto const s_digest_precomputed_17 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_17);
	mk_lang_constexpr_static auto const s_digest_precomputed_18 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_18);
	mk_lang_constexpr_static auto const s_digest_precomputed_19 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_19);
	mk_lang_constexpr_static auto const s_digest_precomputed_20 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_20);
	mk_lang_constexpr_static auto const s_digest_precomputed_21 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_21);
	mk_lang_constexpr_static auto const s_digest_precomputed_22 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_22);

	mk_lang_static_assert(s_digest_computed_01 == s_digest_precomputed_01);
	mk_lang_static_assert(s_digest_computed_02 == s_digest_precomputed_02);
	mk_lang_static_assert(s_digest_computed_03 == s_digest_precomputed_03);
	mk_lang_static_assert(s_digest_computed_04 == s_digest_precomputed_04);
	mk_lang_static_assert(s_digest_computed_05 == s_digest_precomputed_05);
	mk_lang_static_assert(s_digest_computed_06 == s_digest_precomputed_06);
	mk_lang_static_assert(s_digest_computed_07 == s_digest_precomputed_07);
	mk_lang_static_assert(s_digest_computed_08 == s_digest_precomputed_08);
	mk_lang_static_assert(s_digest_computed_09 == s_digest_precomputed_09);
	mk_lang_static_assert(s_digest_computed_10 == s_digest_precomputed_10);
	mk_lang_static_assert(s_digest_computed_11 == s_digest_precomputed_11);
	mk_lang_static_assert(s_digest_computed_12 == s_digest_precomputed_12);
	mk_lang_static_assert(s_digest_computed_13 == s_digest_precomputed_13);
	mk_lang_static_assert(s_digest_computed_14 == s_digest_precomputed_14);
	mk_lang_static_assert(s_digest_computed_15 == s_digest_precomputed_15);
	mk_lang_static_assert(s_digest_computed_16 == s_digest_precomputed_16);
	mk_lang_static_assert(s_digest_computed_17 == s_digest_precomputed_17);
	mk_lang_static_assert(s_digest_computed_18 == s_digest_precomputed_18);
	mk_lang_static_assert(s_digest_computed_19 == s_digest_precomputed_19);
	mk_lang_static_assert(s_digest_computed_20 == s_digest_precomputed_20);
	mk_lang_static_assert(s_digest_computed_21 == s_digest_precomputed_21);
	mk_lang_static_assert(s_digest_computed_22 == s_digest_precomputed_22);

	#endif

	mk_lang_types_pchar_pct const messages[] =
	{
		message_01,
		message_02,
		message_03,
		message_04,
		message_05,
		message_06,
		message_07,
		message_08,
		message_09,
		message_10,
		message_11,
		message_12,
		message_13,
		message_14,
		message_15,
		message_16,
		message_17,
		message_18,
		message_19,
		message_20,
		message_21,
	};

	mk_lang_types_sint_t const message_lens[] =
	{
		mk_lang_countstr(message_01),
		mk_lang_countstr(message_02),
		mk_lang_countstr(message_03),
		mk_lang_countstr(message_04),
		mk_lang_countstr(message_05),
		mk_lang_countstr(message_06),
		mk_lang_countstr(message_07),
		mk_lang_countstr(message_08),
		mk_lang_countstr(message_09),
		mk_lang_countstr(message_10),
		mk_lang_countstr(message_11),
		mk_lang_countstr(message_12),
		mk_lang_countstr(message_13),
		mk_lang_countstr(message_14),
		mk_lang_countstr(message_15),
		mk_lang_countstr(message_16),
		mk_lang_countstr(message_17),
		mk_lang_countstr(message_18),
		mk_lang_countstr(message_19),
		mk_lang_countstr(message_20),
		mk_lang_countstr(message_21),
	};

	mk_lang_types_pchar_pct const digests[] =
	{
		digest_01,
		digest_02,
		digest_03,
		digest_04,
		digest_05,
		digest_06,
		digest_07,
		digest_08,
		digest_09,
		digest_10,
		digest_11,
		digest_12,
		digest_13,
		digest_14,
		digest_15,
		digest_16,
		digest_17,
		digest_18,
		digest_19,
		digest_20,
		digest_21,
	};

	mk_lang_types_pchar_pct const messages_2[] =
	{
		message_22,
	};

	mk_lang_types_sint_t const message_lens_2[] =
	{
		mk_lang_countstr(message_22),
	};

	mk_lang_types_pchar_pct const digests_2[] =
	{
		digest_22,
	};

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint8_t buf[64] mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lib_hash_crc32_t crc32 mk_lang_constexpr_init;
	mk_lib_hash_crc32_digest_t digest mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(message_lens));
	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(digests));
	mk_lang_static_assert(mk_lang_countof(messages_2) == mk_lang_countof(message_lens_2));
	mk_lang_static_assert(mk_lang_countof(messages_2) == mk_lang_countof(digests_2));

	n = mk_lang_countof(messages);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(message_lens[i] >= 0);
		mk_lang_assert(message_lens[i] % 2 == 0);
		mk_lang_assert(mk_lang_countof(buf) >= message_lens[i] / 2);
		len = mk_sl_cui_uint8_from_str_hex_many_n(&buf[0], message_lens[i] / 2, &messages[i][0], message_lens[i]); mk_lang_assert(len == message_lens[i]);
		mk_lib_hash_crc32_init(&crc32);
		mk_lib_hash_crc32_append(&crc32, &buf[0], ((mk_lang_types_usize_t)(message_lens[i] / 2)));
		mk_lib_hash_crc32_finish(&crc32, &digest);
		for(j = 0; j != mk_lib_hash_crc32_digest_len_v; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &digests[i][j * 2], 2); mk_lang_assert(len == 2);
			mk_lang_test(mk_sl_cui_uint8_eq(&digest.m_data.m_uint8s[j], &ta));
		}
	}
	n = mk_lang_countof(messages_2);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(message_lens_2[i] >= 0);
		mk_lang_assert(mk_lang_countof(buf) >= message_lens_2[i]);
		mk_sl_cui_uint8_from_bi_pchar_many(&buf[0], &messages_2[i][0], ((mk_lang_types_usize_t)(message_lens_2[i])));
		mk_lib_hash_crc32_init(&crc32);
		mk_lib_hash_crc32_append(&crc32, &buf[0], ((mk_lang_types_usize_t)(message_lens_2[i])));
		mk_lib_hash_crc32_finish(&crc32, &digest);
		for(j = 0; j != mk_lib_hash_crc32_digest_len_v; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &digests_2[i][j * 2], 2); mk_lang_assert(len == 2);
			mk_lang_test(mk_sl_cui_uint8_eq(&digest.m_data.m_uint8s[j], &ta));
		}
	}

	#undef message_01
	#undef message_02
	#undef message_03
	#undef message_04
	#undef message_05
	#undef message_06
	#undef message_07
	#undef message_08
	#undef message_09
	#undef message_10
	#undef message_11
	#undef message_12
	#undef message_13
	#undef message_14
	#undef message_15
	#undef message_16
	#undef message_17
	#undef message_18
	#undef message_19
	#undef message_20
	#undef message_21
	#undef message_22

	#undef digest_01
	#undef digest_02
	#undef digest_03
	#undef digest_04
	#undef digest_05
	#undef digest_06
	#undef digest_07
	#undef digest_08
	#undef digest_09
	#undef digest_10
	#undef digest_11
	#undef digest_12
	#undef digest_13
	#undef digest_14
	#undef digest_15
	#undef digest_16
	#undef digest_17
	#undef digest_18
	#undef digest_19
	#undef digest_20
	#undef digest_21
	#undef digest_22
}


#include "mk_lang_warning_msvc_pop.h"


#endif
