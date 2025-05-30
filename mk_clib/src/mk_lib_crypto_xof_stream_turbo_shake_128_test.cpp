#ifndef mk_include_guard_mk_lib_crypto_xof_stream_turbo_shake_128_test_cpp
#define mk_include_guard_mk_lib_crypto_xof_stream_turbo_shake_128_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_xof_stream_turbo_shake_128_test.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr_array_u8.hpp"
#include "mk_lib_crypto_xof_stream_turbo_shake_128.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t digest_len, mk_lang_types_usize_t hex_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_xof_stream_turbo_shake_128_test_compute_from_hex_lit(mk_lang_types_pchar_t const(&hex_lit)[hex_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (hex_lit_len - 1) / 2> msg mk_lang_constexpr_init;
	mk_lib_crypto_xof_stream_turbo_shake_128_t turbo_shake_128 mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, digest_len> ret mk_lang_constexpr_init;

	mk_lang_static_assert(digest_len >= 1);
	mk_lang_static_assert(hex_lit_len >= 1);
	mk_lang_static_assert((hex_lit_len - 1) % 2 == 0);

	msg = mk_lib_cpp_constexpr_array_u8_from_hex_lit(hex_lit);
	mk_lib_crypto_xof_stream_turbo_shake_128_init(&turbo_shake_128);
	mk_lib_crypto_xof_stream_turbo_shake_128_append_u8s(&turbo_shake_128, msg.data(), msg.size());
	mk_lib_crypto_xof_stream_turbo_shake_128_finish(&turbo_shake_128);
	mk_lib_crypto_xof_stream_turbo_shake_128_squeeze_u8s(&turbo_shake_128, ret.data(), ret.size());
	return ret;
}

#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_crypto_xof_stream_turbo_shake_128_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define message_1 ""
	#define message_2 ""
	#define message_3 "00"
	#define message_4 "000102030405060708090a0b0c0d0e0f10"
	#define message_5 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7c8c9cacbcccdcecfd0d1d2d3d4d5d6d7d8d9dadbdcdddedfe0e1e2e3e4e5e6e7e8e9eaebecedeeeff0f1f2f3f4f5f6f7f8f9fa000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425"

	#define digest_1 "1e415f1c5983aff2169217277d17bb538cd945a397ddec541f1ce41af2c1b74c"
	#define digest_2 "1e415f1c5983aff2169217277d17bb538cd945a397ddec541f1ce41af2c1b74c3e8ccae2a4dae56c84a04c2385c03c15e8193bdf58737363321691c05462c8df"
	#define digest_3 "55cedd6f60af7bb29a4042ae832ef3f58db7299f893ebb9247247d856958daa9"
	#define digest_4 "9c97d036a3bac819db70ede0ca554ec6e4c2a1a4ffbfd9ec269ca6a111161233"
	#define digest_5 "96c77c279e0126f7fc07c9b07f5cdae1e0be60bdbe10620040e75d7223a624d2"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_digest_computed_1 = mk_lib_crypto_xof_stream_turbo_shake_128_test_compute_from_hex_lit<32>(message_1);
	mk_lang_constexpr_static auto const s_digest_computed_2 = mk_lib_crypto_xof_stream_turbo_shake_128_test_compute_from_hex_lit<64>(message_2);
	mk_lang_constexpr_static auto const s_digest_computed_3 = mk_lib_crypto_xof_stream_turbo_shake_128_test_compute_from_hex_lit<32>(message_3);
	mk_lang_constexpr_static auto const s_digest_computed_4 = mk_lib_crypto_xof_stream_turbo_shake_128_test_compute_from_hex_lit<32>(message_4);
	mk_lang_constexpr_static auto const s_digest_computed_5 = mk_lib_crypto_xof_stream_turbo_shake_128_test_compute_from_hex_lit<32>(message_5);

	mk_lang_constexpr_static auto const s_digest_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_1);
	mk_lang_constexpr_static auto const s_digest_precomputed_2 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_2);
	mk_lang_constexpr_static auto const s_digest_precomputed_3 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_3);
	mk_lang_constexpr_static auto const s_digest_precomputed_4 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_4);
	mk_lang_constexpr_static auto const s_digest_precomputed_5 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_5);

	mk_lang_static_assert(s_digest_computed_1 == s_digest_precomputed_1);
	mk_lang_static_assert(s_digest_computed_2 == s_digest_precomputed_2);
	mk_lang_static_assert(s_digest_computed_3 == s_digest_precomputed_3);
	mk_lang_static_assert(s_digest_computed_4 == s_digest_precomputed_4);
	mk_lang_static_assert(s_digest_computed_5 == s_digest_precomputed_5);

	#endif

	mk_lang_types_pchar_pct const messages[] =
	{
		message_1,
		message_2,
		message_3,
		message_4,
		message_5,
	};

	mk_lang_types_sint_t const message_lens[] =
	{
		mk_lang_countstr(message_1),
		mk_lang_countstr(message_2),
		mk_lang_countstr(message_3),
		mk_lang_countstr(message_4),
		mk_lang_countstr(message_5),
	};

	mk_lang_types_pchar_pct const digests[] =
	{
		digest_1,
		digest_2,
		digest_3,
		digest_4,
		digest_5,
	};

	mk_lang_types_sint_t const digest_lens[] =
	{
		mk_lang_countstr(digest_1),
		mk_lang_countstr(digest_2),
		mk_lang_countstr(digest_3),
		mk_lang_countstr(digest_4),
		mk_lang_countstr(digest_5),
	};

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_crypto_xof_stream_turbo_shake_128_t turbo_shake_128 mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_cui_uint8_t msg_bin[64] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t digest[64] mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(message_lens));
	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(digests));
	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(digest_lens));

	n = mk_lang_countof(messages);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(message_lens[i] >= 0);
		mk_lang_assert(message_lens[i] % 2 == 0);
		mk_lang_assert(digest_lens[i] >= 0);
		mk_lang_assert(digest_lens[i] % 2 == 0);
		mk_lang_assert(digest_lens[i] / 2 <= mk_lang_countof(digest));
		mk_lib_crypto_xof_stream_turbo_shake_128_init(&turbo_shake_128);
		m = (message_lens[i] / 2) / mk_lang_countof(msg_bin);
		for(j = 0; j != m; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_many_n(&msg_bin[0], mk_lang_countof(msg_bin), &messages[i][j * mk_lang_countof(msg_bin) * mk_sl_cui_uint8_strlen_hex_v], mk_lang_countof(msg_bin) * mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_lang_countof(msg_bin) * mk_sl_cui_uint8_strlen_hex_v);
			mk_lib_crypto_xof_stream_turbo_shake_128_append_u8s(&turbo_shake_128, &msg_bin[0], mk_lang_countof(msg_bin));
		}
		m = (message_lens[i] / 2) - m * mk_lang_countof(msg_bin);
		len = mk_sl_cui_uint8_from_str_hex_many_n(&msg_bin[0], m, &messages[i][j * mk_lang_countof(msg_bin) * mk_sl_cui_uint8_strlen_hex_v], m * mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == m * mk_sl_cui_uint8_strlen_hex_v);
		mk_lib_crypto_xof_stream_turbo_shake_128_append_u8s(&turbo_shake_128, &msg_bin[0], ((mk_lang_types_usize_t)(m)));
		mk_lib_crypto_xof_stream_turbo_shake_128_finish(&turbo_shake_128);
		mk_lib_crypto_xof_stream_turbo_shake_128_squeeze_u8s(&turbo_shake_128, &digest[0], ((mk_lang_types_usize_t)(digest_lens[i] / 2)));
		for(j = 0; j != digest_lens[i] / 2; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &digests[i][j * 2], 2); mk_lang_assert(len == 2);
			mk_lang_test(mk_sl_cui_uint8_eq(&digest[j], &ta));
		}
	}

	#undef message_1
	#undef message_2
	#undef message_3
	#undef message_4
	#undef message_5

	#undef digest_1
	#undef digest_2
	#undef digest_3
	#undef digest_4
	#undef digest_5
}


#include "mk_lang_warning_msvc_pop.h"


#endif
