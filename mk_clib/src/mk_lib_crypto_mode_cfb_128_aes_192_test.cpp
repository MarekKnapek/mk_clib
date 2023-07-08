#include "mk_lib_crypto_mode_cfb_128_aes_192_test.hpp"
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
#include "mk_lib_crypto_mode_cfb_128_aes_192.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t iv_lit_len, mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mode_cfb_128_aes_192_test_encrypt_from_str_lit(char const(&iv_lit)[iv_lit_len], char const(&key_lit)[key_lit_len], char const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_alg_aes_192_msg_len_v> iv_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_mode_cfb_128_aes_192_key_len_v> key_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, (msg_lit_len - 1) / 2> msg_bytes mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_msg_t iv mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_128_aes_192_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_128_aes_192_msg_t msg mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_128_aes_192_t mode mk_lang_constexpr_init;
	mk_lang_types_usize_t j mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, (msg_lit_len - 1) / 2> out_bytes mk_lang_constexpr_init;

	mk_lang_static_assert(iv_lit_len == mk_lib_crypto_alg_aes_192_msg_len_v * 2 + 1);
	mk_lang_static_assert(key_lit_len == mk_lib_crypto_mode_cfb_128_aes_192_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_lit_len >= mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v * 2 + 1 && ((msg_lit_len - 1) / 2) % mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v == 0);

	iv_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(iv_lit);
	key_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(key_lit);
	msg_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(msg_lit);
	for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i){ iv.m_data.m_uchars[i] = iv_bytes[i]; }
	mk_lib_crypto_mode_cfb_128_aes_192_init(&mode, &iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_key_len_v; ++i){ key.m_data.m_uchars[i] = key_bytes[i]; }
	for(j = 0; j != ((msg_lit_len - 1) / 2) / mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++j)
	{
		for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ msg.m_data.m_uchars[i] = msg_bytes[j * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + i]; }
		mk_lib_crypto_mode_cfb_128_aes_192_encrypt(&mode, &key, &msg, &msg);
		for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ out_bytes[j * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + i] = msg.m_data.m_uchars[i]; }
	}
	return out_bytes;
}

template<mk_lang_types_usize_t iv_lit_len, mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_bytes_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mode_cfb_128_aes_192_test_decrypt_from_str_lit(char const(&iv_lit)[iv_lit_len], char const(&key_lit)[key_lit_len], mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, msg_bytes_len> const& msg_bytes) mk_lang_noexcept
{
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_alg_aes_192_msg_len_v> iv_bytes mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, mk_lib_crypto_mode_cfb_128_aes_192_key_len_v> key_bytes mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_msg_t iv mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_128_aes_192_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_128_aes_192_msg_t msg mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_128_aes_192_t mode mk_lang_constexpr_init;
	mk_lang_types_usize_t j mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_uchar_t, msg_bytes_len> out_bytes mk_lang_constexpr_init;

	mk_lang_static_assert(iv_lit_len == mk_lib_crypto_alg_aes_192_msg_len_v * 2 + 1);
	mk_lang_static_assert(key_lit_len == mk_lib_crypto_mode_cfb_128_aes_192_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_bytes_len >= mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v && msg_bytes_len % mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v == 0);

	iv_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(iv_lit);
	key_bytes = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(key_lit);
	for(i = 0; i != mk_lib_crypto_alg_aes_192_msg_len_v; ++i){ iv.m_data.m_uchars[i] = iv_bytes[i]; }
	mk_lib_crypto_mode_cfb_128_aes_192_init(&mode, &iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_key_len_v; ++i){ key.m_data.m_uchars[i] = key_bytes[i]; }
	for(j = 0; j != msg_bytes_len / mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++j)
	{
		for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ msg.m_data.m_uchars[i] = msg_bytes[j * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + i]; }
		mk_lib_crypto_mode_cfb_128_aes_192_decrypt(&mode, &key, &msg, &msg);
		for(i = 0; i != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++i){ out_bytes[j * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + i] = msg.m_data.m_uchars[i]; }
	}
	return out_bytes;
}

#endif


mk_lang_extern_c void mk_lib_crypto_mode_cfb_128_aes_192_test(void) mk_lang_noexcept
{
	#define iv_1 "000102030405060708090a0b0c0d0e0f"

	#define key_1 "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b"

	#define msg_1 "6bc1bee22e409f96e93d7e117393172a""ae2d8a571e03ac9c9eb76fac45af8e51""30c81c46a35ce411e5fbc1191a0a52ef""f69f2445df4f9b17ad2b417be66c3710"

	#define out_1 "cdc80d6fddf18cab34c25909c99a4174""67ce7f7f81173621961a2b70171d3d7a""2e1e8a1dd59b88b1c8e60fed1efac4c9""c05f9f9ca9834fa042ae8fba584b09ff"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_out_computed_1 = mk_lib_crypto_mode_cfb_128_aes_192_test_encrypt_from_str_lit(iv_1, key_1, msg_1);

	mk_lang_constexpr_static auto const s_msg_computed_1 = mk_lib_crypto_mode_cfb_128_aes_192_test_decrypt_from_str_lit(iv_1, key_1, s_out_computed_1);

	mk_lang_constexpr_static auto const s_out_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(out_1);

	mk_lang_constexpr_static auto const s_msg_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_bytes(msg_1);

	mk_lang_static_assert(s_out_computed_1 == s_out_precomputed_1);

	mk_lang_static_assert(s_msg_computed_1 == s_msg_precomputed_1);

	#endif

	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_assert(0); mk_lang_crash(); } ((void)(0))

	static char const* const s_ivs[] =
	{
		iv_1,
	};

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
	mk_lib_crypto_alg_aes_192_msg_t iv;
	mk_lib_crypto_mode_cfb_128_aes_192_key_t key;
	mk_lib_crypto_mode_cfb_128_aes_192_msg_t msg;
	mk_lib_crypto_mode_cfb_128_aes_192_t mode;

	mk_lang_static_assert(sizeof(s_ivs) / sizeof(s_ivs[0]) == sizeof(s_keys) / sizeof(s_keys[0]));
	mk_lang_static_assert(sizeof(s_ivs) / sizeof(s_ivs[0]) == sizeof(s_msgs) / sizeof(s_msgs[0]));
	mk_lang_static_assert(sizeof(s_ivs) / sizeof(s_ivs[0]) == sizeof(s_msg_lens) / sizeof(s_msg_lens[0]));
	mk_lang_static_assert(sizeof(s_ivs) / sizeof(s_ivs[0]) == sizeof(s_outs) / sizeof(s_outs[0]));

	mk_lang_cpuid_init();
	n = ((int)(sizeof(s_ivs) / sizeof(s_ivs[0])));
	for(i = 0; i != n; ++i)
	{
		msg_len = s_msg_lens[i];
		mk_lang_assert(msg_len >= mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v * 2 + 1 && ((msg_len - 1) / 2) % mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v == 0);
		msg_len = (msg_len - 1) / 2;
		for(j = 0; j != mk_lib_crypto_alg_aes_192_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_ivs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_ivs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			iv.m_data.m_uchars[j] = byte;
		}
		for(j = 0; j != mk_lib_crypto_mode_cfb_128_aes_192_key_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			key.m_data.m_uchars[j] = byte;
		}
		mk_lib_crypto_mode_cfb_128_aes_192_init(&mode, &iv);
		for(k = 0; k != msg_len / mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++k)
		{
			for(j = 0; j != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(k * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + j) * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(k * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + j) * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				msg.m_data.m_uchars[j] = byte;
			}
			mk_lib_crypto_mode_cfb_128_aes_192_encrypt(&mode, &key, &msg, &msg);
			for(j = 0; j != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(k * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + j) * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(k * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + j) * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				test(msg.m_data.m_uchars[j] == byte);
			}
		}
		mk_lib_crypto_mode_cfb_128_aes_192_init(&mode, &iv);
		for(k = 0; k != msg_len / mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++k)
		{
			for(j = 0; j != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(k * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + j) * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][(k * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + j) * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				msg.m_data.m_uchars[j] = byte;
			}
			mk_lib_crypto_mode_cfb_128_aes_192_decrypt(&mode, &key, &msg, &msg);
			for(j = 0; j != mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v; ++j)
			{
				hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(k * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + j) * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
				lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][(k * mk_lib_crypto_mode_cfb_128_aes_192_msg_len_v + j) * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
				byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
				test(msg.m_data.m_uchars[j] == byte);
			}
		}
	}

	#undef test

	#undef iv_1

	#undef key_1

	#undef msg_1

	#undef out_1
}
