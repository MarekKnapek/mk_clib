#include "mk_lib_crypto_alg_aes_256_test.hpp"
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
#include "mk_lib_crypto_alg_aes_256.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_aes_256_test_encrypt_from_str_lit(char const(&key_lit)[key_lit_len], char const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_alg_aes_256_key_len_v> key_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_alg_aes_256_msg_len_v> msg_bytes mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_msg_t msg mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_alg_aes_256_msg_len_v> out_bytes mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_alg_aes_256_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_lit_len == mk_lib_crypto_alg_aes_256_msg_len_v * 2 + 1);

	key_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(key_lit);
	msg_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(msg_lit);
	for(i = 0; i != mk_lib_crypto_alg_aes_256_key_len_v; ++i){ key.m_data.m_uchars[i] = key_bytes[i]; }
	for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ msg.m_data.m_uchars[i] = msg_bytes[i]; }
	mk_lib_crypto_alg_aes_256_encrypt(&key, &msg, &msg);
	for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ out_bytes[i] = msg.m_data.m_uchars[i]; }
	return out_bytes;
}

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_bytes_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_aes_256_test_decrypt_from_str_lit(char const(&key_lit)[key_lit_len], mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, msg_bytes_len> const& msg_bytes) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_alg_aes_256_key_len_v> key_bytes mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_256_msg_t msg mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_alg_aes_256_msg_len_v> out_bytes mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_alg_aes_256_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_bytes_len == mk_lib_crypto_alg_aes_256_msg_len_v);

	key_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(key_lit);
	for(i = 0; i != mk_lib_crypto_alg_aes_256_key_len_v; ++i){ key.m_data.m_uchars[i] = key_bytes[i]; }
	for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ msg.m_data.m_uchars[i] = msg_bytes[i]; }
	mk_lib_crypto_alg_aes_256_decrypt(&key, &msg, &msg);
	for(i = 0; i != mk_lib_crypto_alg_aes_256_msg_len_v; ++i){ out_bytes[i] = msg.m_data.m_uchars[i]; }
	return out_bytes;
}

#endif


mk_lang_extern_c void mk_lib_crypto_alg_aes_256_test(void) mk_lang_noexcept
{
	#define key_1 "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4"
	#define key_2 "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4"
	#define key_3 "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4"
	#define key_4 "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4"

	#define msg_1 "6bc1bee22e409f96e93d7e117393172a"
	#define msg_2 "ae2d8a571e03ac9c9eb76fac45af8e51"
	#define msg_3 "30c81c46a35ce411e5fbc1191a0a52ef"
	#define msg_4 "f69f2445df4f9b17ad2b417be66c3710"

	#define out_1 "f3eed1bdb5d2a03c064b5a7e3db181f8"
	#define out_2 "591ccb10d410ed26dc5ba74a31362870"
	#define out_3 "b6ed21b99ca6f4f9f153e7b1beafed1d"
	#define out_4 "23304b7a39f9f3ff067d8d8f9e24ecc7"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_out_computed_1 = mk_lib_crypto_alg_aes_256_test_encrypt_from_str_lit(key_1, msg_1);
	mk_lang_constexpr_static auto const s_out_computed_2 = mk_lib_crypto_alg_aes_256_test_encrypt_from_str_lit(key_2, msg_2);
	mk_lang_constexpr_static auto const s_out_computed_3 = mk_lib_crypto_alg_aes_256_test_encrypt_from_str_lit(key_3, msg_3);
	mk_lang_constexpr_static auto const s_out_computed_4 = mk_lib_crypto_alg_aes_256_test_encrypt_from_str_lit(key_4, msg_4);

	mk_lang_constexpr_static auto const s_msg_computed_1 = mk_lib_crypto_alg_aes_256_test_decrypt_from_str_lit(key_1, s_out_computed_1);
	mk_lang_constexpr_static auto const s_msg_computed_2 = mk_lib_crypto_alg_aes_256_test_decrypt_from_str_lit(key_2, s_out_computed_2);
	mk_lang_constexpr_static auto const s_msg_computed_3 = mk_lib_crypto_alg_aes_256_test_decrypt_from_str_lit(key_3, s_out_computed_3);
	mk_lang_constexpr_static auto const s_msg_computed_4 = mk_lib_crypto_alg_aes_256_test_decrypt_from_str_lit(key_4, s_out_computed_4);

	mk_lang_constexpr_static auto const s_out_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(out_1);
	mk_lang_constexpr_static auto const s_out_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(out_2);
	mk_lang_constexpr_static auto const s_out_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(out_3);
	mk_lang_constexpr_static auto const s_out_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(out_4);

	mk_lang_constexpr_static auto const s_msg_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(msg_1);
	mk_lang_constexpr_static auto const s_msg_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(msg_2);
	mk_lang_constexpr_static auto const s_msg_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(msg_3);
	mk_lang_constexpr_static auto const s_msg_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(msg_4);

	mk_lang_static_assert(s_out_computed_1 == s_out_precomputed_1);
	mk_lang_static_assert(s_out_computed_2 == s_out_precomputed_2);
	mk_lang_static_assert(s_out_computed_3 == s_out_precomputed_3);
	mk_lang_static_assert(s_out_computed_4 == s_out_precomputed_4);

	mk_lang_static_assert(s_msg_computed_1 == s_msg_precomputed_1);
	mk_lang_static_assert(s_msg_computed_2 == s_msg_precomputed_2);
	mk_lang_static_assert(s_msg_computed_3 == s_msg_precomputed_3);
	mk_lang_static_assert(s_msg_computed_4 == s_msg_precomputed_4);

	#endif

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_assert(0); mk_lang_crash(); } ((void)(0))

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
	mk_lib_crypto_alg_aes_256_key_t key;
	mk_lib_crypto_alg_aes_256_msg_t msg;

	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_msgs) / sizeof(s_msgs[0]));
	mk_lang_static_assert(sizeof(s_keys) / sizeof(s_keys[0]) == sizeof(s_outs) / sizeof(s_outs[0]));

	mk_lang_cpuid_init();
	n = ((int)(sizeof(s_keys) / sizeof(s_keys[0])));
	for(i = 0; i != n; ++i)
	{
		for(j = 0; j != mk_lib_crypto_alg_aes_256_key_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			key.m_data.m_uchars[j] = byte;
		}
		for(j = 0; j != mk_lib_crypto_alg_aes_256_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			msg.m_data.m_uchars[j] = byte;
		}
		mk_lib_crypto_alg_aes_256_encrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_aes_256_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			test(msg.m_data.m_uchars[j] == byte);
		}
		mk_lib_crypto_alg_aes_256_decrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_aes_256_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			test(msg.m_data.m_uchars[j] == byte);
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
