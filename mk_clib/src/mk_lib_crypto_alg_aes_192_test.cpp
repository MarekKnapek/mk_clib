#include "mk_lib_crypto_alg_aes_192_test.hpp"
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
#include "mk_lib_crypto_alg_aes_192.h"
#include "mk_sl_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(char const(&key_lit)[key_lit_len], char const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_msg_t msg mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_alg_aes_192_msg_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_alg_aes_192_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_lit_len == mk_lib_crypto_alg_aes_192_msg_len_v * 2 + 1);

	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(key.m_data.m_uint8s, key_lit);
	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(msg.m_data.m_uint8s, msg_lit);
	mk_lib_crypto_alg_aes_192_encrypt(&key, &msg, &msg);
	for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i){ ret[i] = msg.m_data.m_uint8s[i]; }
	return ret;
}

template<mk_lang_types_usize_t key_lit_len, typename msg_t>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(char const(&key_lit)[key_lit_len], msg_t const& m) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_key_t key mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_msg_t msg mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_alg_aes_192_msg_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_alg_aes_192_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_t::s_size == mk_lib_crypto_alg_aes_192_msg_len_v);

	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(key.m_data.m_uint8s, key_lit);
	for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = m[i]; }
	mk_lib_crypto_alg_aes_192_decrypt(&key, &msg, &msg);
	for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i){ ret[i] = msg.m_data.m_uint8s[i]; }
	return ret;
}

#endif


mk_lang_extern_c void mk_lib_crypto_alg_aes_192_test(void) mk_lang_noexcept
{
	#define key_1 "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b"
	#define key_2 "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b"
	#define key_3 "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b"
	#define key_4 "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b"

	#define msg_1 "6bc1bee22e409f96e93d7e117393172a"
	#define msg_2 "ae2d8a571e03ac9c9eb76fac45af8e51"
	#define msg_3 "30c81c46a35ce411e5fbc1191a0a52ef"
	#define msg_4 "f69f2445df4f9b17ad2b417be66c3710"

	#define out_1 "bd334f1d6e45f25ff712a214571fa5cc"
	#define out_2 "974104846d0ad3ad7734ecb3ecee4eef"
	#define out_3 "ef7afd2270e2e60adce0ba2face6444e"
	#define out_4 "9a4b41ba738d6c72fb16691603c18e0e"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_out_computed_1 = mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(key_1, msg_1);
	mk_lang_constexpr_static auto const s_out_computed_2 = mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(key_2, msg_2);
	mk_lang_constexpr_static auto const s_out_computed_3 = mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(key_3, msg_3);
	mk_lang_constexpr_static auto const s_out_computed_4 = mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(key_4, msg_4);

	mk_lang_constexpr_static auto const s_msg_computed_1 = mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(key_1, s_out_computed_1);
	mk_lang_constexpr_static auto const s_msg_computed_2 = mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(key_2, s_out_computed_2);
	mk_lang_constexpr_static auto const s_msg_computed_3 = mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(key_3, s_out_computed_3);
	mk_lang_constexpr_static auto const s_msg_computed_4 = mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(key_4, s_out_computed_4);

	mk_lang_constexpr_static auto const s_out_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_1);
	mk_lang_constexpr_static auto const s_out_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_2);
	mk_lang_constexpr_static auto const s_out_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_3);
	mk_lang_constexpr_static auto const s_out_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_4);

	mk_lang_constexpr_static auto const s_msg_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_1);
	mk_lang_constexpr_static auto const s_msg_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_2);
	mk_lang_constexpr_static auto const s_msg_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_3);
	mk_lang_constexpr_static auto const s_msg_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_4);

	mk_lang_static_assert(s_out_computed_1 == s_out_precomputed_1);
	mk_lang_static_assert(s_out_computed_2 == s_out_precomputed_2);
	mk_lang_static_assert(s_out_computed_3 == s_out_precomputed_3);
	mk_lang_static_assert(s_out_computed_4 == s_out_precomputed_4);

	mk_lang_static_assert(s_msg_computed_1 == s_msg_precomputed_1);
	mk_lang_static_assert(s_msg_computed_2 == s_msg_precomputed_2);
	mk_lang_static_assert(s_msg_computed_3 == s_msg_precomputed_3);
	mk_lang_static_assert(s_msg_computed_4 == s_msg_precomputed_4);

	#endif

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((void)(0))

	static char const* const s_keys[] =
	{
		key_1,
		key_2,
		key_3,
		key_4,
	};

	static char const* const s_msgs[] =
	{
		msg_1,
		msg_2,
		msg_3,
		msg_4,
	};

	static char const* const s_outs[] =
	{
		out_1,
		out_2,
		out_3,
		out_4,
	};

	int n;
	int i;
	int j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lib_crypto_alg_aes_192_key_t key;
	mk_lib_crypto_alg_aes_192_msg_t msg;
	mk_sl_cui_uint8_t u8;

	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_msgs) / sizeof(s_msgs[0]));
	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_outs) / sizeof(s_outs[0]));

	mk_lang_cpuid_init();
	n = ((int)(sizeof(s_keys) / sizeof(s_keys[0])));
	for(i = 0; i != n; ++i)
	{
		for(j = 0; j != mk_lib_crypto_alg_aes_192_key_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&key.m_data.m_uint8s[j], &byte);
		}
		for(j = 0; j != mk_lib_crypto_alg_aes_192_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&msg.m_data.m_uint8s[j], &byte);
		}
		mk_lib_crypto_alg_aes_192_encrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_aes_192_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
			test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &u8));
		}
		mk_lib_crypto_alg_aes_192_decrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_aes_192_msg_len_v; ++j)
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

	#undef msg_1
	#undef msg_2
	#undef msg_3
	#undef msg_4

	#undef out_1
	#undef out_2
	#undef out_3
	#undef out_4
}
