#include "mk_lib_crypto_mode_ecb_aes_256_test.hpp"
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
#include "mk_lib_crypto_mode_ecb_aes_256.h"
#include "mk_sl_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mode_ecb_aes_256_test_encrypt_from_str_lit(char const(&key_lit)[key_lit_len], char const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_mode_ecb_aes_256_key_len_v> key_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (msg_lit_len - 1) / 2> msg_bytes mk_lang_constexpr_init;
	mk_lib_crypto_mode_ecb_aes_256_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_mode_ecb_aes_256_msg_t msg mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_mode_ecb_aes_256_t mode mk_lang_constexpr_init;
	mk_lang_types_usize_t j mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (msg_lit_len - 1) / 2> out_bytes mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_mode_ecb_aes_256_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_lit_len >= mk_lib_crypto_mode_ecb_aes_256_msg_len_v * 2 + 1 && ((msg_lit_len - 1) / 2) % mk_lib_crypto_mode_ecb_aes_256_msg_len_v == 0);

	key_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(key_lit);
	msg_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_lit);
	mk_lib_crypto_mode_ecb_aes_256_init(&mode);
	for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_key_len_v; ++i){ key.m_data.m_uint8s[i] = key_bytes[i]; }
	for(j = 0; j != ((msg_lit_len - 1) / 2) / mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++j)
	{
		for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = msg_bytes[j * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + i]; }
		mk_lib_crypto_mode_ecb_aes_256_encrypt(&mode, &key, &msg, &msg);
		for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++i){ out_bytes[j * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + i] = msg.m_data.m_uint8s[i]; }
	}
	return out_bytes;
}

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_bytes_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mode_ecb_aes_256_test_decrypt_from_str_lit(char const(&key_lit)[key_lit_len], mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, msg_bytes_len> const& msg_bytes) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_mode_ecb_aes_256_key_len_v> key_bytes mk_lang_constexpr_init;
	mk_lib_crypto_mode_ecb_aes_256_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_mode_ecb_aes_256_msg_t msg mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_mode_ecb_aes_256_t mode mk_lang_constexpr_init;
	mk_lang_types_usize_t j mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, msg_bytes_len> out_bytes mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_mode_ecb_aes_256_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_bytes_len >= mk_lib_crypto_mode_ecb_aes_256_msg_len_v && msg_bytes_len % mk_lib_crypto_mode_ecb_aes_256_msg_len_v == 0);

	key_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(key_lit);
	mk_lib_crypto_mode_ecb_aes_256_init(&mode);
	for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_key_len_v; ++i){ key.m_data.m_uint8s[i] = key_bytes[i]; }
	for(j = 0; j != msg_bytes_len / mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++j)
	{
		for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++i){ msg.m_data.m_uint8s[i] = msg_bytes[j * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + i]; }
		mk_lib_crypto_mode_ecb_aes_256_decrypt(&mode, &key, &msg, &msg);
		for(i = 0; i != mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++i){ out_bytes[j * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + i] = msg.m_data.m_uint8s[i]; }
	}
	return out_bytes;
}

#endif


mk_lang_extern_c void mk_lib_crypto_mode_ecb_aes_256_test(void) mk_lang_noexcept
{
	#define key_1 "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4"

	#define msg_1 "6bc1bee22e409f96e93d7e117393172a""ae2d8a571e03ac9c9eb76fac45af8e51""30c81c46a35ce411e5fbc1191a0a52ef""f69f2445df4f9b17ad2b417be66c3710"

	#define out_1 "f3eed1bdb5d2a03c064b5a7e3db181f8""591ccb10d410ed26dc5ba74a31362870""b6ed21b99ca6f4f9f153e7b1beafed1d""23304b7a39f9f3ff067d8d8f9e24ecc7"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_out_computed_1 = mk_lib_crypto_mode_ecb_aes_256_test_encrypt_from_str_lit(key_1, msg_1);

	mk_lang_constexpr_static auto const s_msg_computed_1 = mk_lib_crypto_mode_ecb_aes_256_test_decrypt_from_str_lit(key_1, s_out_computed_1);

	mk_lang_constexpr_static auto const s_out_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_1);

	mk_lang_constexpr_static auto const s_msg_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_1);

	mk_lang_static_assert(s_out_computed_1 == s_out_precomputed_1);

	mk_lang_static_assert(s_msg_computed_1 == s_msg_precomputed_1);

	#endif

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((void)(0))

	static char const* const s_keys[] =
	{
		key_1,
	};

	static char const* const s_msgs[] =
	{
		msg_1,
	};

	static int const s_msg_lens[] =
	{
		((int)(sizeof(msg_1) / sizeof(msg_1[0]))),
	};

	static char const* const s_outs[] =
	{
		out_1,
	};

	int n;
	int i;
	int msg_len;
	int k;
	int j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lib_crypto_mode_ecb_aes_256_key_t key;
	mk_lib_crypto_mode_ecb_aes_256_msg_t msg;
	mk_lib_crypto_mode_ecb_aes_256_t mode;
	mk_sl_cui_uint8_t u8;

	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_msgs) / sizeof(s_msgs[0]));
	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_msg_lens) / sizeof(s_msg_lens[0]));
	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_outs) / sizeof(s_outs[0]));

	mk_lang_cpuid_init();
	n = ((int)(sizeof(s_keys) / sizeof(s_keys[0])));
	for(i = 0; i != n; ++i)
	{
		msg_len = s_msg_lens[i];
		mk_lang_assert(msg_len >= mk_lib_crypto_mode_ecb_aes_256_msg_len_v * 2 + 1 && ((msg_len - 1) / 2) % mk_lib_crypto_mode_ecb_aes_256_msg_len_v == 0);
		msg_len = (msg_len - 1) / 2;
		for(j = 0; j != mk_lib_crypto_mode_ecb_aes_256_key_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&key.m_data.m_uint8s[j], &byte);
		}
		mk_lib_crypto_mode_ecb_aes_256_init(&mode);
		for(k = 0; k != msg_len / mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++k)
		{
			for(j = 0; j != mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(k * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + j) * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(k * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + j) * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&msg.m_data.m_uint8s[j], &byte);
			}
			mk_lib_crypto_mode_ecb_aes_256_encrypt(&mode, &key, &msg, &msg);
			for(j = 0; j != mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(k * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + j) * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(k * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + j) * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &u8));
			}
		}
		mk_lib_crypto_mode_ecb_aes_256_init(&mode);
		for(k = 0; k != msg_len / mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++k)
		{
			for(j = 0; j != mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(k * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + j) * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(k * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + j) * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&msg.m_data.m_uint8s[j], &byte);
			}
			mk_lib_crypto_mode_ecb_aes_256_decrypt(&mode, &key, &msg, &msg);
			for(j = 0; j != mk_lib_crypto_mode_ecb_aes_256_msg_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(k * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + j) * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(k * mk_lib_crypto_mode_ecb_aes_256_msg_len_v + j) * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
				test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &u8));
			}
		}
	}

	#undef test

	#undef key_1

	#undef msg_1

	#undef out_1
}
