#include "mk_lib_crypto_mac_hmac_sha2_512_test.hpp"
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
#include "mk_lib_crypto_mac_hmac_sha2_512.h"
#include "mk_sl_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<int mac_len = mk_lib_crypto_hash_block_sha2_512_digest_len, int msg_len, int key_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mac_hmac_sha2_512_test_compute_from_str_lit(mk_lang_types_pchar_t const(&msg)[msg_len], mk_lang_types_pchar_t const(&key)[key_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, msg_len - 1> m mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (key_len - 1) / 2> k mk_lang_constexpr_init;
	mk_lib_crypto_mac_hmac_sha2_512_t hmac mk_lang_constexpr_init;
	mk_lib_crypto_hash_block_sha2_512_digest_t digest mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mac_len> ret mk_lang_constexpr_init;

	mk_lang_static_assert(msg_len >= 1);
	mk_lang_static_assert(key_len >= 1);
	mk_lang_static_assert((key_len - 1) % 2 == 0);

	m = mk_lib_cpp_constexpr_str_lit_to_u8s(msg);
	k = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(key);
	mk_lib_crypto_mac_hmac_sha2_512_init(&hmac, k.data(), k.size());
	mk_lib_crypto_mac_hmac_sha2_512_append(&hmac, m.data(), m.size());
	mk_lib_crypto_mac_hmac_sha2_512_finish(&hmac, &digest);
	for(i = 0; i != mac_len; ++i){ ret[i] = digest.m_uint8s[i]; }
	return ret;
}

#endif


mk_lang_extern_c void mk_lib_crypto_mac_hmac_sha2_512_test(void) mk_lang_noexcept
{
	#define msg_1 "Sample message for keylen=blocklen"
	#define msg_2 "Sample message for keylen<blocklen"
	#define msg_3 "Sample message for keylen=blocklen"
	#define msg_4 "Sample message for keylen<blocklen, with truncated tag"

	#define key_1 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f"
	#define key_2 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f"
	#define key_3 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f404142434445464748494a4b4c4d4e4f505152535455565758595a5b5c5d5e5f606162636465666768696a6b6c6d6e6f707172737475767778797a7b7c7d7e7f808182838485868788898a8b8c8d8e8f909192939495969798999a9b9c9d9e9fa0a1a2a3a4a5a6a7a8a9aaabacadaeafb0b1b2b3b4b5b6b7b8b9babbbcbdbebfc0c1c2c3c4c5c6c7"
	#define key_4 "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f30"

	#define mac_1 "fc25e240658ca785b7a811a8d3f7b4ca48cfa26a8a366bf2cd1f836b05fcb024bd36853081811d6cea4216ebad79da1cfcb95ea4586b8a0ce356596a55fb1347"
	#define mac_2 "fd44c18bda0bb0a6ce0e82b031bf2818f6539bd56ec00bdc10a8a2d730b3634de2545d639b0f2cf710d0692c72a1896f1f211c2b922d1a96c392e07e7ea9fedc"
	#define mac_3 "d93ec8d2de1ad2a9957cb9b83f14e76ad6b5e0cce285079a127d3b14bccb7aa7286d4ac0d4ce64215f2bc9e6870b33d97438be4aaa20cda5c5a912b48b8e27f3"
	#define mac_4 "00f3e9a77bb0f06de15f160603e42b5028758808596664c03e1ab8fb2b076778"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_key_computed_1 = mk_lib_crypto_mac_hmac_sha2_512_test_compute_from_str_lit(msg_1, key_1);
	mk_lang_constexpr_static auto const s_key_computed_2 = mk_lib_crypto_mac_hmac_sha2_512_test_compute_from_str_lit(msg_2, key_2);
	mk_lang_constexpr_static auto const s_key_computed_3 = mk_lib_crypto_mac_hmac_sha2_512_test_compute_from_str_lit(msg_3, key_3);
	mk_lang_constexpr_static auto const s_key_computed_4 = mk_lib_crypto_mac_hmac_sha2_512_test_compute_from_str_lit<32>(msg_4, key_4);

	mk_lang_constexpr_static auto const s_key_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(mac_1);
	mk_lang_constexpr_static auto const s_key_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(mac_2);
	mk_lang_constexpr_static auto const s_key_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(mac_3);
	mk_lang_constexpr_static auto const s_key_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(mac_4);

	mk_lang_static_assert(s_key_computed_1 == s_key_precomputed_1);
	mk_lang_static_assert(s_key_computed_2 == s_key_precomputed_2);
	mk_lang_static_assert(s_key_computed_3 == s_key_precomputed_3);
	mk_lang_static_assert(s_key_computed_4 == s_key_precomputed_4);

	#endif

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((void)(0))

	static char const* const s_msgs[] =
	{
		msg_1,
		msg_2,
		msg_3,
		msg_4,
	};

	static int const s_msg_lens[] =
	{
		((int)(sizeof(msg_1) / sizeof(msg_1[0]) - 1)),
		((int)(sizeof(msg_2) / sizeof(msg_2[0]) - 1)),
		((int)(sizeof(msg_3) / sizeof(msg_3[0]) - 1)),
		((int)(sizeof(msg_4) / sizeof(msg_4[0]) - 1)),
	};

	static char const* const s_keys[] =
	{
		key_1,
		key_2,
		key_3,
		key_4,
	};

	static int const s_key_lens[] =
	{
		((int)(sizeof(key_1) / sizeof(key_1[0]) - 1)) / 2,
		((int)(sizeof(key_2) / sizeof(key_2[0]) - 1)) / 2,
		((int)(sizeof(key_3) / sizeof(key_3[0]) - 1)) / 2,
		((int)(sizeof(key_4) / sizeof(key_4[0]) - 1)) / 2,
	};

	static char const* const s_macs[] =
	{
		mac_1,
		mac_2,
		mac_3,
		mac_4,
	};

	static int const s_mac_lens[] =
	{
		((int)(sizeof(mac_1) / sizeof(mac_1[0]) - 1)) / 2,
		((int)(sizeof(mac_2) / sizeof(mac_2[0]) - 1)) / 2,
		((int)(sizeof(mac_3) / sizeof(mac_3[0]) - 1)) / 2,
		((int)(sizeof(mac_4) / sizeof(mac_4[0]) - 1)) / 2,
	};

	int n;
	int i;
	int m;
	mk_sl_cui_uint8_t key[200];
	int j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_sl_cui_uint8_t msg[64];
	mk_lib_crypto_mac_hmac_sha2_512_t hmac;
	mk_lib_crypto_hash_block_sha2_512_digest_t digest;
	mk_sl_cui_uint8_t u8;

	mk_lang_static_assert(sizeof(s_msgs) / sizeof(s_msgs[0]) == sizeof(s_msg_lens) / sizeof(s_msg_lens[0]));
	mk_lang_static_assert(sizeof(s_msgs) / sizeof(s_msgs[0]) == sizeof(s_keys) / sizeof(s_keys[0]));
	mk_lang_static_assert(sizeof(s_msgs) / sizeof(s_msgs[0]) == sizeof(s_key_lens) / sizeof(s_key_lens[0]));
	mk_lang_static_assert(sizeof(s_msgs) / sizeof(s_msgs[0]) == sizeof(s_macs) / sizeof(s_macs[0]));

	n = ((int)(sizeof(s_msgs) / sizeof(s_msgs[0])));
	for(i = 0; i != n; ++i)
	{
		m = s_key_lens[i];
		mk_lang_assert(((int)(sizeof(key) / sizeof(key[0]))) >= m);
		for(j = 0; j != m; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&key[j], &byte);
		}
		m = s_msg_lens[i];
		mk_lang_assert(((int)(sizeof(msg) / sizeof(msg[0]))) >= m);
		for(j = 0; j != m; ++j)
		{
			mk_sl_cui_uint8_from_bi_pchar(&msg[j], &s_msgs[i][j]);
		}
		mk_lib_crypto_mac_hmac_sha2_512_init(&hmac, &key[0], s_key_lens[i]);
		mk_lib_crypto_mac_hmac_sha2_512_append(&hmac, &msg[0], s_msg_lens[i]);
		mk_lib_crypto_mac_hmac_sha2_512_finish(&hmac, &digest);
		m = s_mac_lens[i];
		for(j = 0; j != m; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_macs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_macs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
			test(mk_sl_cui_uint8_eq(&digest.m_uint8s[j], &u8));
		}
	}

	#undef test

	#undef msg_1
	#undef msg_2
	#undef msg_3
	#undef msg_4

	#undef key_1
	#undef key_2
	#undef key_3
	#undef key_4

	#undef mac_1
	#undef mac_2
	#undef mac_3
	#undef mac_4
}
