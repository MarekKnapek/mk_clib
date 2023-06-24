#include "mk_lib_crypto_hash_stream_blake2b_384_test.hpp"
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
#include "mk_lib_crypto_hash_stream_blake2b_384.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t str_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_hash_stream_blake2b_384_test_compute_from_str_lit(char const(&str_lit)[str_lit_len]) mk_lang_noexcept
{
	mk_lang_constexpr_static mk_lang_types_usize_t const s_len = str_lit_len - 1;

	mk_lib_crypto_hash_stream_blake2b_384_t blake2b_384 mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t uch mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_blake2b_384_digest_t digest mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_hash_block_blake2b_384_digest_len> ret mk_lang_constexpr_init;

	mk_lang_static_assert(str_lit_len >= 1);

	mk_lib_crypto_hash_stream_blake2b_384_init(& blake2b_384);
	for(i = 0; i  != s_len; ++i){ uch = ((mk_lang_types_uchar_t)(str_lit[i])); mk_lib_crypto_hash_stream_blake2b_384_append(& blake2b_384, &uch, 1); }
	mk_lib_crypto_hash_stream_blake2b_384_finish(& blake2b_384, &digest);
	for(i = 0; i != mk_lib_crypto_hash_block_blake2b_384_digest_len; ++i){ mk_sl_cui_uint8_to_bi_uchar(&digest.m_uint8s[i], &ret[i]); }
	return ret;
}

#endif


mk_lang_extern_c void mk_lib_crypto_hash_stream_blake2b_384_test(void) mk_lang_noexcept
{
	#define message_1 ""
	#define message_2 "a"
	#define message_3 "abc"
	#define message_4 "message digest"
	#define message_5 "abcdefghijklmnopqrstuvwxyz"
	#define message_6 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
	#define message_7 "12345678901234567890123456789012345678901234567890123456789012345678901234567890"
	#define message_8 "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

	#define digest_1 "b32811423377f52d7862286ee1a72ee540524380fda1724a6f25d7978c6fd3244a6caf0498812673c5e05ef583825100"
	#define digest_2 "7d40de16ff771d4595bf70cbda0c4ea0a066a6046fa73d34471cd4d93d827d7c94c29399c50de86983af1ec61d5dcef0"
	#define digest_3 "6f56a82c8e7ef526dfe182eb5212f7db9df1317e57815dbda46083fc30f54ee6c66ba83be64b302d7cba6ce15bb556f4"
	#define digest_4 "44c3965bd8f02ed299ad52ffb5bba7c448df242073c5520dc091a0cc55d024cdd51569c339d0bf2b6cd746708683a0ef"
	#define digest_5 "5cad60ce23b9dc62eabdd149a16307ef916e0637506fa10cf8c688430da6c978a0cb7857fd138977bd281e8cfd5bfd1f"
	#define digest_6 "b4975ee19a4f559e3d3497df0db1e5c6b79988b7d7e85c1f064ceaa72a418c484e4418b775c77af8d2651872547c8e9f"
	#define digest_7 "1ce12d72189f06f1b95c16f4bf7e0685519bc1065eae2efd015a31db13bd123ea8f8bf83a8682ad29e3828a0a0af299c"
	#define digest_8 "7ad1025cf65da196577fc64beaede793b7b31618755c43b9122036b8341077dd92f3bc9bd6cc3167b428b13f0428ef01"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_digest_computed_1 = mk_lib_crypto_hash_stream_blake2b_384_test_compute_from_str_lit(message_1);
	mk_lang_constexpr_static auto const s_digest_computed_2 = mk_lib_crypto_hash_stream_blake2b_384_test_compute_from_str_lit(message_2);
	mk_lang_constexpr_static auto const s_digest_computed_3 = mk_lib_crypto_hash_stream_blake2b_384_test_compute_from_str_lit(message_3);
	mk_lang_constexpr_static auto const s_digest_computed_4 = mk_lib_crypto_hash_stream_blake2b_384_test_compute_from_str_lit(message_4);
	mk_lang_constexpr_static auto const s_digest_computed_5 = mk_lib_crypto_hash_stream_blake2b_384_test_compute_from_str_lit(message_5);
	mk_lang_constexpr_static auto const s_digest_computed_6 = mk_lib_crypto_hash_stream_blake2b_384_test_compute_from_str_lit(message_6);
	mk_lang_constexpr_static auto const s_digest_computed_7 = mk_lib_crypto_hash_stream_blake2b_384_test_compute_from_str_lit(message_7);
	mk_lang_constexpr_static auto const s_digest_computed_8 = mk_lib_crypto_hash_stream_blake2b_384_test_compute_from_str_lit(message_8);

	mk_lang_constexpr_static auto const s_digest_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_1);
	mk_lang_constexpr_static auto const s_digest_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_2);
	mk_lang_constexpr_static auto const s_digest_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_3);
	mk_lang_constexpr_static auto const s_digest_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_4);
	mk_lang_constexpr_static auto const s_digest_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_5);
	mk_lang_constexpr_static auto const s_digest_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_6);
	mk_lang_constexpr_static auto const s_digest_precomputed_7 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_7);
	mk_lang_constexpr_static auto const s_digest_precomputed_8 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(digest_8);

	mk_lang_static_assert(s_digest_computed_1 == s_digest_precomputed_1);
	mk_lang_static_assert(s_digest_computed_2 == s_digest_precomputed_2);
	mk_lang_static_assert(s_digest_computed_3 == s_digest_precomputed_3);
	mk_lang_static_assert(s_digest_computed_4 == s_digest_precomputed_4);
	mk_lang_static_assert(s_digest_computed_5 == s_digest_precomputed_5);
	mk_lang_static_assert(s_digest_computed_6 == s_digest_precomputed_6);
	mk_lang_static_assert(s_digest_computed_7 == s_digest_precomputed_7);
	mk_lang_static_assert(s_digest_computed_8 == s_digest_precomputed_8);

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
	};

	int n;
	int i;
	mk_lib_crypto_hash_stream_blake2b_384_t  blake2b_384;
	mk_lib_crypto_hash_block_blake2b_384_digest_t digest;
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
		mk_lib_crypto_hash_stream_blake2b_384_init(& blake2b_384);
		mk_lib_crypto_hash_stream_blake2b_384_append(& blake2b_384, ((mk_lang_types_uchar_pct)(s_messages[i])), s_message_lens[i]);
		mk_lib_crypto_hash_stream_blake2b_384_finish(& blake2b_384, &digest);
		for(j = 0; j != mk_lib_crypto_hash_block_blake2b_384_digest_len; ++j)
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
