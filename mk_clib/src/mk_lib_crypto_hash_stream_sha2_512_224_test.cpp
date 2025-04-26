#ifndef mk_include_guard_mk_lib_crypto_hash_stream_sha2_512_224_test_cpp
#define mk_include_guard_mk_lib_crypto_hash_stream_sha2_512_224_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_hash_stream_sha2_512_224_test.hpp"

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
#include "mk_lib_crypto_hash_stream_sha2_512_224.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_hash_stream_sha2_512_224_test_compute_from_str_lit(mk_lang_types_pchar_t const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, str_lit_len - 1> msg mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha2_512_224_t sha2_512_224 mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha2_512_224_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_hash_stream_sha2_512_224_digest_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);

	msg = mk_lib_cpp_constexpr_array_u8_from_pchar_lit(str_lit);
	mk_lib_crypto_hash_stream_sha2_512_224_init(&sha2_512_224);
	mk_lib_crypto_hash_stream_sha2_512_224_append_u8s(&sha2_512_224, msg.data(), msg.size());
	mk_lib_crypto_hash_stream_sha2_512_224_finish(&sha2_512_224, &digest);
	ret = mk_lib_cpp_constexpr_array_u8_from_u8s(digest.m_data.m_uint8s);
	return ret;
}

#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_crypto_hash_stream_sha2_512_224_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define message_1 ""
	#define message_2 "a"
	#define message_3 "abc"
	#define message_4 "message digest"
	#define message_5 "abcdefghijklmnopqrstuvwxyz"
	#define message_6 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	#define message_7 "12345678901234567890123456789012345678901234567890123456789012345678901234567890"
	#define message_8 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

	#define digest_1 "6ed0dd02806fa89e25de060c19d3ac86cabb87d6a0ddd05c333b84f4"
	#define digest_2 "d5cdb9ccc769a5121d4175f2bfdd13d6310e0d3d361ea75d82108327"
	#define digest_3 "4634270f707b6a54daae7530460842e20e37ed265ceee9a43e8924aa"
	#define digest_4 "ad1a4db188fe57064f4f24609d2a83cd0afb9b398eb2fcaeaae2c564"
	#define digest_5 "ff83148aa07ec30655c1b40aff86141c0215fe2a54f767d3f38743d8"
	#define digest_6 "a8b4b9174b99ffc67d6f49be9981587b96441051e16e6dd036b140d3"
	#define digest_7 "ae988faaa47e401a45f704d1272d99702458fea2ddc6582827556dd2"
	#define digest_8 "16f5c6a04ec0bd1e6656e42c95b78e61a8d4f074007cd818cc3a42f2"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_digest_computed_1 = mk_lib_crypto_hash_stream_sha2_512_224_test_compute_from_str_lit(message_1);
	mk_lang_constexpr_static auto const s_digest_computed_2 = mk_lib_crypto_hash_stream_sha2_512_224_test_compute_from_str_lit(message_2);
	mk_lang_constexpr_static auto const s_digest_computed_3 = mk_lib_crypto_hash_stream_sha2_512_224_test_compute_from_str_lit(message_3);
	mk_lang_constexpr_static auto const s_digest_computed_4 = mk_lib_crypto_hash_stream_sha2_512_224_test_compute_from_str_lit(message_4);
	mk_lang_constexpr_static auto const s_digest_computed_5 = mk_lib_crypto_hash_stream_sha2_512_224_test_compute_from_str_lit(message_5);
	mk_lang_constexpr_static auto const s_digest_computed_6 = mk_lib_crypto_hash_stream_sha2_512_224_test_compute_from_str_lit(message_6);
	mk_lang_constexpr_static auto const s_digest_computed_7 = mk_lib_crypto_hash_stream_sha2_512_224_test_compute_from_str_lit(message_7);
	mk_lang_constexpr_static auto const s_digest_computed_8 = mk_lib_crypto_hash_stream_sha2_512_224_test_compute_from_str_lit(message_8);

	mk_lang_constexpr_static auto const s_digest_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_1);
	mk_lang_constexpr_static auto const s_digest_precomputed_2 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_2);
	mk_lang_constexpr_static auto const s_digest_precomputed_3 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_3);
	mk_lang_constexpr_static auto const s_digest_precomputed_4 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_4);
	mk_lang_constexpr_static auto const s_digest_precomputed_5 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_5);
	mk_lang_constexpr_static auto const s_digest_precomputed_6 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_6);
	mk_lang_constexpr_static auto const s_digest_precomputed_7 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_7);
	mk_lang_constexpr_static auto const s_digest_precomputed_8 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(digest_8);

	mk_lang_static_assert(s_digest_computed_1 == s_digest_precomputed_1);
	mk_lang_static_assert(s_digest_computed_2 == s_digest_precomputed_2);
	mk_lang_static_assert(s_digest_computed_3 == s_digest_precomputed_3);
	mk_lang_static_assert(s_digest_computed_4 == s_digest_precomputed_4);
	mk_lang_static_assert(s_digest_computed_5 == s_digest_precomputed_5);
	mk_lang_static_assert(s_digest_computed_6 == s_digest_precomputed_6);
	mk_lang_static_assert(s_digest_computed_7 == s_digest_precomputed_7);
	mk_lang_static_assert(s_digest_computed_8 == s_digest_precomputed_8);

	#endif

	mk_lang_types_pchar_pct const messages[] =
	{
		message_1,
		message_2,
		message_3,
		message_4,
		message_5,
		message_6,
		message_7,
		message_8,
	};

	mk_lang_types_sint_t const message_lens[] =
	{
		mk_lang_countstr(message_1),
		mk_lang_countstr(message_2),
		mk_lang_countstr(message_3),
		mk_lang_countstr(message_4),
		mk_lang_countstr(message_5),
		mk_lang_countstr(message_6),
		mk_lang_countstr(message_7),
		mk_lang_countstr(message_8),
	};

	mk_lang_types_pchar_pct const digests[] =
	{
		digest_1,
		digest_2,
		digest_3,
		digest_4,
		digest_5,
		digest_6,
		digest_7,
		digest_8,
	};

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha2_512_224_t sha2_512_224 mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha2_512_224_digest_t digest mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(digests));
	mk_lang_static_assert(mk_lang_countof(messages) == mk_lang_countof(message_lens));

	n = mk_lang_countof(messages);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(message_lens[i] >= 0);
		mk_lib_crypto_hash_stream_sha2_512_224_init(&sha2_512_224);
		mk_lib_crypto_hash_stream_sha2_512_224_append_u8s(&sha2_512_224, ((mk_sl_cui_uint8_pct)(messages[i])), ((mk_lang_types_usize_t)(message_lens[i])));
		mk_lib_crypto_hash_stream_sha2_512_224_finish(&sha2_512_224, &digest);
		for(j = 0; j != mk_lib_crypto_hash_stream_sha2_512_224_digest_len_v; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &digests[i][j * 2], 2); mk_lang_assert(len == 2);
			mk_lang_test(mk_sl_cui_uint8_eq(&digest.m_data.m_uint8s[j], &ta));
		}
	}

	#undef message_1
	#undef message_2
	#undef message_3
	#undef message_4
	#undef message_5
	#undef message_6
	#undef message_7
	#undef message_8

	#undef digest_1
	#undef digest_2
	#undef digest_3
	#undef digest_4
	#undef digest_5
	#undef digest_6
	#undef digest_7
	#undef digest_8
}


#include "mk_lang_warning_msvc_pop.h"


#endif
