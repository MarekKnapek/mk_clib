#include "mk_lib_crypto_hash_stream_tiger_160_test.hpp"
#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_hash_stream_tiger_160.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_hash_stream_tiger_160_test_compute_from_str_lit(char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_lang_types_usize_t const s_len = str_lit_len - 1;

	mk_lib_crypto_hash_stream_tiger_160_t tiger_160 mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t uch mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_tiger_160_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_hash_block_tiger_160_digest_len> ret mk_lang_constexpr_init;

	static_assert(str_lit_len >= 1);

	mk_lib_crypto_hash_stream_tiger_160_init(&tiger_160);
	for(i = 0; i  != s_len; ++i)
	{
		uch = ((mk_lang_types_uchar_t)(str_lit[i]));
		mk_lib_crypto_hash_stream_tiger_160_append(&tiger_160, &uch, 1);
	}
	mk_lib_crypto_hash_stream_tiger_160_finish(&tiger_160, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_tiger_160_digest_len; ++i)
	{
		mk_sl_cui_uint8_to_bi_uchar(&digest.m_uint8s[i], &ret[i]);
	}
	return ret;
}

#endif


mk_lang_extern_c void mk_lib_crypto_hash_stream_tiger_160_test(void) mk_lang_noexcept
{
	#define message_1 ""
	#define message_2 "abc"
	#define message_3 "Tiger"
	#define message_4 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-"
	#define message_5 "ABCDEFGHIJKLMNOPQRSTUVWXYZ=abcdefghijklmnopqrstuvwxyz+0123456789"
	#define message_6 "Tiger - A Fast New Hash Function, by Ross Anderson and Eli Biham"
	#define message_7 "Tiger - A Fast New Hash Function, by Ross Anderson and Eli Biham, proceedings of Fast Software Encryption 3, Cambridge."
	#define message_8 "Tiger - A Fast New Hash Function, by Ross Anderson and Eli Biham, proceedings of Fast Software Encryption 3, Cambridge, 1996."
	#define message_9 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-"

	#define digest_1 "3293ac630c13f0245f92bbb1766e16167a4e5849"
	#define digest_2 "2aab1484e8c158f2bfb8c5ff41b57a525129131c"
	#define digest_3 "dd00230799f5009fec6debc838bb6a27df2b9d6f"
	#define digest_4 "f71c8583902afb879edfe610f82c0d4786a3a534"
	#define digest_5 "48ceeb6308b87d46e95d656112cdf18d97915f97"
	#define digest_6 "8a866829040a410c729ad23f5ada711603b3cdd3"
	#define digest_7 "ce55a6afd591f5ebac547ff84f89227f9331dab0"
	#define digest_8 "631abdd103eb9a3d245b6dfd4d77b257fc743950"
	#define digest_9 "c54034e5b43eb8005848a7e0ae6aac76e4ff590a"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_digest_computed_1 = mk_lib_crypto_hash_stream_tiger_160_test_compute_from_str_lit(message_1);
	mk_lang_constexpr_static auto const s_digest_computed_2 = mk_lib_crypto_hash_stream_tiger_160_test_compute_from_str_lit(message_2);
	mk_lang_constexpr_static auto const s_digest_computed_3 = mk_lib_crypto_hash_stream_tiger_160_test_compute_from_str_lit(message_3);
	mk_lang_constexpr_static auto const s_digest_computed_4 = mk_lib_crypto_hash_stream_tiger_160_test_compute_from_str_lit(message_4);
	mk_lang_constexpr_static auto const s_digest_computed_5 = mk_lib_crypto_hash_stream_tiger_160_test_compute_from_str_lit(message_5);
	mk_lang_constexpr_static auto const s_digest_computed_6 = mk_lib_crypto_hash_stream_tiger_160_test_compute_from_str_lit(message_6);
	mk_lang_constexpr_static auto const s_digest_computed_7 = mk_lib_crypto_hash_stream_tiger_160_test_compute_from_str_lit(message_7);
	mk_lang_constexpr_static auto const s_digest_computed_8 = mk_lib_crypto_hash_stream_tiger_160_test_compute_from_str_lit(message_8);
	mk_lang_constexpr_static auto const s_digest_computed_9 = mk_lib_crypto_hash_stream_tiger_160_test_compute_from_str_lit(message_9);

	mk_lang_constexpr_static auto const s_digest_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_1);
	mk_lang_constexpr_static auto const s_digest_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_2);
	mk_lang_constexpr_static auto const s_digest_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_3);
	mk_lang_constexpr_static auto const s_digest_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_4);
	mk_lang_constexpr_static auto const s_digest_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_5);
	mk_lang_constexpr_static auto const s_digest_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_6);
	mk_lang_constexpr_static auto const s_digest_precomputed_7 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_7);
	mk_lang_constexpr_static auto const s_digest_precomputed_8 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_8);
	mk_lang_constexpr_static auto const s_digest_precomputed_9 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_9);

	static_assert(s_digest_computed_1 == s_digest_precomputed_1);
	static_assert(s_digest_computed_2 == s_digest_precomputed_2);
	static_assert(s_digest_computed_3 == s_digest_precomputed_3);
	static_assert(s_digest_computed_4 == s_digest_precomputed_4);
	static_assert(s_digest_computed_5 == s_digest_precomputed_5);
	static_assert(s_digest_computed_6 == s_digest_precomputed_6);
	static_assert(s_digest_computed_7 == s_digest_precomputed_7);
	static_assert(s_digest_computed_8 == s_digest_precomputed_8);
	static_assert(s_digest_computed_9 == s_digest_precomputed_9);

	#endif

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_assert(0); mk_lang_crash(); } ((void)(0))

	static char const* const s_messages[] =
	{
		message_1,
		message_2,
		message_3,
		message_4,
		message_5,
		message_6,
		message_7,
		message_8,
		message_9,
	};

	static int const s_message_lens[] =
	{
		((int)(sizeof(message_1) / sizeof(message_1[0]) - 1)),
		((int)(sizeof(message_2) / sizeof(message_2[0]) - 1)),
		((int)(sizeof(message_3) / sizeof(message_3[0]) - 1)),
		((int)(sizeof(message_4) / sizeof(message_4[0]) - 1)),
		((int)(sizeof(message_5) / sizeof(message_5[0]) - 1)),
		((int)(sizeof(message_6) / sizeof(message_6[0]) - 1)),
		((int)(sizeof(message_7) / sizeof(message_7[0]) - 1)),
		((int)(sizeof(message_8) / sizeof(message_8[0]) - 1)),
		((int)(sizeof(message_9) / sizeof(message_9[0]) - 1)),
	};

	static char const* const s_digests[] =
	{
		digest_1,
		digest_2,
		digest_3,
		digest_4,
		digest_5,
		digest_6,
		digest_7,
		digest_8,
		digest_9,
	};

	int n;
	int i;
	mk_lib_crypto_hash_stream_tiger_160_t tiger_160;
	mk_lib_crypto_hash_block_tiger_160_digest_t digest;
	int j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lang_types_uchar_t ta;

	mk_lang_static_assert(sizeof(s_messages) / sizeof(s_messages[0]) == sizeof(s_digests) / sizeof(s_digests[0]));
	mk_lang_static_assert(sizeof(s_messages) / sizeof(s_messages[0]) == sizeof(s_message_lens) / sizeof(s_message_lens[0]));

	n = ((int)(sizeof(s_messages) / sizeof(s_messages[0])));
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(s_message_lens[i] >= 0);
		mk_lib_crypto_hash_stream_tiger_160_init(&tiger_160);
		mk_lib_crypto_hash_stream_tiger_160_append(&tiger_160, ((mk_lang_types_uchar_pct)(s_messages[i])), s_message_lens[i]);
		mk_lib_crypto_hash_stream_tiger_160_finish(&tiger_160, &digest);
		for(j = 0; j != mk_lib_crypto_hash_block_tiger_160_digest_len; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_digests[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_digests[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_to_bi_uchar(&digest.m_uint8s[j], &ta);
			test(ta == byte);
		}
	}

	#undef test

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
