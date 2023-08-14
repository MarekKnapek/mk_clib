#include "mk_lib_crypto_alg_serpent_test.hpp"
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
#include "mk_lib_crypto_alg_serpent.h"
#include "mk_sl_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_serpent_test_encrypt_from_str_lit(char const(&key_lit)[key_lit_len], char const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_msg_t msg mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_alg_serpent_msg_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_alg_serpent_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_lit_len == mk_lib_crypto_alg_serpent_msg_len_v * 2 + 1);

	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(key.m_data.m_uint8s, key_lit);
	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(msg.m_data.m_uint8s, msg_lit);
	mk_lib_crypto_alg_serpent_encrypt(&key, &msg, &msg);
	for(i = 0; i != mk_lib_crypto_alg_serpent_msg_len_v; ++i){ ret[i] = msg.m_data.m_uint8s[i]; }
	return ret;
}

template<mk_lang_types_usize_t key_lit_len, typename msg_t>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_serpent_test_decrypt_from_str_lit(char const(&key_lit)[key_lit_len], msg_t const& m) mk_lang_noexcept
{
	mk_lib_crypto_alg_serpent_key_t key mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_alg_serpent_msg_t msg mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_alg_serpent_msg_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_alg_serpent_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_t::s_size == mk_lib_crypto_alg_serpent_msg_len_v);

	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(key.m_data.m_uint8s, key_lit);
	for(i = 0; i != mk_lib_crypto_alg_serpent_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = m[i]; }
	mk_lib_crypto_alg_serpent_decrypt(&key, &msg, &msg);
	for(i = 0; i != mk_lib_crypto_alg_serpent_msg_len_v; ++i){ ret[i] = msg.m_data.m_uint8s[i]; }
	return ret;
}

#endif


mk_lang_extern_c void mk_lib_crypto_alg_serpent_test(void) mk_lang_noexcept
{
	#define key_1 "8000000000000000000000000000000000000000000000000000000000000000"
	#define key_2 "4000000000000000000000000000000000000000000000000000000000000000"
	#define key_3 "2000000000000000000000000000000000000000000000000000000000000000"
	#define key_4 "1000000000000000000000000000000000000000000000000000000000000000"
	#define key_5 "0000000000000000000000000000000000000000000000000000000000000001"
	#define key_6 "0000000000000000000000000000000000000000000000000000000000000002"
	#define key_7 "0000000000000000000000000000000000000000000000000000000000000004"
	#define key_8 "0000000000000000000000000000000000000000000000000000000000000008"
	#define key_9 "e7b7645b6f7d1cfb5facb96ae1f113d8c21222f752e10a4351c5870682c93465"

	#define msg_1 "00000000000000000000000000000000"
	#define msg_2 "00000000000000000000000000000000"
	#define msg_3 "00000000000000000000000000000000"
	#define msg_4 "00000000000000000000000000000000"
	#define msg_5 "00000000000000000000000000000000"
	#define msg_6 "00000000000000000000000000000000"
	#define msg_7 "00000000000000000000000000000000"
	#define msg_8 "00000000000000000000000000000000"
	#define msg_9 "f102498db057bee83828509c70f3f291"

	#define out_1 "a223aa1288463c0e2be38ebd825616c0"
	#define out_2 "eae1d405570174df7df2f9966d509159"
	#define out_3 "65f37684471e921dc8a30f45b43c4499"
	#define out_4 "0ee036d0bc32b89c1cef987f5229e4a9"
	#define out_5 "9858fd31c9c6b54ac0c99cc52324ed34"
	#define out_6 "a6726ce53bd62bc873f6c0463a5841fc"
	#define out_7 "f6899d57f734afd6473278dbde8fb99d"
	#define out_8 "869a570998988f68819ccf301eb015df"
	#define out_9 "6c0c59bc2d5dcfd9e5ce18f3c4059f03"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_out_computed_1 = mk_lib_crypto_alg_serpent_test_encrypt_from_str_lit(key_1, msg_1);
	mk_lang_constexpr_static auto const s_out_computed_2 = mk_lib_crypto_alg_serpent_test_encrypt_from_str_lit(key_2, msg_2);
	mk_lang_constexpr_static auto const s_out_computed_3 = mk_lib_crypto_alg_serpent_test_encrypt_from_str_lit(key_3, msg_3);
	mk_lang_constexpr_static auto const s_out_computed_4 = mk_lib_crypto_alg_serpent_test_encrypt_from_str_lit(key_4, msg_4);
	mk_lang_constexpr_static auto const s_out_computed_5 = mk_lib_crypto_alg_serpent_test_encrypt_from_str_lit(key_5, msg_5);
	mk_lang_constexpr_static auto const s_out_computed_6 = mk_lib_crypto_alg_serpent_test_encrypt_from_str_lit(key_6, msg_6);
	mk_lang_constexpr_static auto const s_out_computed_7 = mk_lib_crypto_alg_serpent_test_encrypt_from_str_lit(key_7, msg_7);
	mk_lang_constexpr_static auto const s_out_computed_8 = mk_lib_crypto_alg_serpent_test_encrypt_from_str_lit(key_8, msg_8);
	mk_lang_constexpr_static auto const s_out_computed_9 = mk_lib_crypto_alg_serpent_test_encrypt_from_str_lit(key_9, msg_9);

	mk_lang_constexpr_static auto const s_msg_computed_1 = mk_lib_crypto_alg_serpent_test_decrypt_from_str_lit(key_1, s_out_computed_1);
	mk_lang_constexpr_static auto const s_msg_computed_2 = mk_lib_crypto_alg_serpent_test_decrypt_from_str_lit(key_2, s_out_computed_2);
	mk_lang_constexpr_static auto const s_msg_computed_3 = mk_lib_crypto_alg_serpent_test_decrypt_from_str_lit(key_3, s_out_computed_3);
	mk_lang_constexpr_static auto const s_msg_computed_4 = mk_lib_crypto_alg_serpent_test_decrypt_from_str_lit(key_4, s_out_computed_4);
	mk_lang_constexpr_static auto const s_msg_computed_5 = mk_lib_crypto_alg_serpent_test_decrypt_from_str_lit(key_5, s_out_computed_5);
	mk_lang_constexpr_static auto const s_msg_computed_6 = mk_lib_crypto_alg_serpent_test_decrypt_from_str_lit(key_6, s_out_computed_6);
	mk_lang_constexpr_static auto const s_msg_computed_7 = mk_lib_crypto_alg_serpent_test_decrypt_from_str_lit(key_7, s_out_computed_7);
	mk_lang_constexpr_static auto const s_msg_computed_8 = mk_lib_crypto_alg_serpent_test_decrypt_from_str_lit(key_8, s_out_computed_8);
	mk_lang_constexpr_static auto const s_msg_computed_9 = mk_lib_crypto_alg_serpent_test_decrypt_from_str_lit(key_9, s_out_computed_9);

	mk_lang_constexpr_static auto const s_out_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_1);
	mk_lang_constexpr_static auto const s_out_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_2);
	mk_lang_constexpr_static auto const s_out_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_3);
	mk_lang_constexpr_static auto const s_out_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_4);
	mk_lang_constexpr_static auto const s_out_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_5);
	mk_lang_constexpr_static auto const s_out_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_6);
	mk_lang_constexpr_static auto const s_out_precomputed_7 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_7);
	mk_lang_constexpr_static auto const s_out_precomputed_8 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_8);
	mk_lang_constexpr_static auto const s_out_precomputed_9 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_9);

	mk_lang_constexpr_static auto const s_msg_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_1);
	mk_lang_constexpr_static auto const s_msg_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_2);
	mk_lang_constexpr_static auto const s_msg_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_3);
	mk_lang_constexpr_static auto const s_msg_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_4);
	mk_lang_constexpr_static auto const s_msg_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_5);
	mk_lang_constexpr_static auto const s_msg_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_6);
	mk_lang_constexpr_static auto const s_msg_precomputed_7 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_7);
	mk_lang_constexpr_static auto const s_msg_precomputed_8 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_8);
	mk_lang_constexpr_static auto const s_msg_precomputed_9 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_9);

	mk_lang_static_assert(s_out_computed_1 == s_out_precomputed_1);
	mk_lang_static_assert(s_out_computed_2 == s_out_precomputed_2);
	mk_lang_static_assert(s_out_computed_3 == s_out_precomputed_3);
	mk_lang_static_assert(s_out_computed_4 == s_out_precomputed_4);
	mk_lang_static_assert(s_out_computed_5 == s_out_precomputed_5);
	mk_lang_static_assert(s_out_computed_6 == s_out_precomputed_6);
	mk_lang_static_assert(s_out_computed_7 == s_out_precomputed_7);
	mk_lang_static_assert(s_out_computed_8 == s_out_precomputed_8);
	mk_lang_static_assert(s_out_computed_9 == s_out_precomputed_9);

	mk_lang_static_assert(s_msg_computed_1 == s_msg_precomputed_1);
	mk_lang_static_assert(s_msg_computed_2 == s_msg_precomputed_2);
	mk_lang_static_assert(s_msg_computed_3 == s_msg_precomputed_3);
	mk_lang_static_assert(s_msg_computed_4 == s_msg_precomputed_4);
	mk_lang_static_assert(s_msg_computed_5 == s_msg_precomputed_5);
	mk_lang_static_assert(s_msg_computed_6 == s_msg_precomputed_6);
	mk_lang_static_assert(s_msg_computed_7 == s_msg_precomputed_7);
	mk_lang_static_assert(s_msg_computed_8 == s_msg_precomputed_8);
	mk_lang_static_assert(s_msg_computed_9 == s_msg_precomputed_9);

	#endif

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((void)(0))

	static char const* const s_keys[] =
	{
		key_1,
		key_2,
		key_3,
		key_4,
		key_5,
		key_6,
		key_7,
		key_8,
		key_9,
	};

	static char const* const s_msgs[] =
	{
		msg_1,
		msg_2,
		msg_3,
		msg_4,
		msg_5,
		msg_6,
		msg_7,
		msg_8,
		msg_9,
	};

	static char const* const s_outs[] =
	{
		out_1,
		out_2,
		out_3,
		out_4,
		out_5,
		out_6,
		out_7,
		out_8,
		out_9,
	};

	int n;
	int i;
	int j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lib_crypto_alg_serpent_key_t key;
	mk_lib_crypto_alg_serpent_msg_t msg;
	mk_sl_cui_uint8_t u8;

	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_msgs) / sizeof(s_msgs[0]));
	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_outs) / sizeof(s_outs[0]));

	mk_lang_cpuid_init();
	n = ((int)(sizeof(s_keys) / sizeof(s_keys[0])));
	for(i = 0; i != n; ++i)
	{
		for(j = 0; j != mk_lib_crypto_alg_serpent_key_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&key.m_data.m_uint8s[j], &byte);
		}
		for(j = 0; j != mk_lib_crypto_alg_serpent_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&msg.m_data.m_uint8s[j], &byte);
		}
		mk_lib_crypto_alg_serpent_encrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_serpent_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
			test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &u8));
		}
		mk_lib_crypto_alg_serpent_decrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_serpent_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
			test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &u8));
		}
	}

	#undef test

	#undef key_1
	#undef key_2
	#undef key_3
	#undef key_4
	#undef key_5
	#undef key_6
	#undef key_7
	#undef key_8
	#undef key_9

	#undef msg_1
	#undef msg_2
	#undef msg_3
	#undef msg_4
	#undef msg_5
	#undef msg_6
	#undef msg_7
	#undef msg_8
	#undef msg_9

	#undef out_1
	#undef out_2
	#undef out_3
	#undef out_4
	#undef out_5
	#undef out_6
	#undef out_7
	#undef out_8
	#undef out_9
}
