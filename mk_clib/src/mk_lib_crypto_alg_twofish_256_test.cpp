#include "mk_lib_crypto_alg_twofish_256_test.hpp"
#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_alg_twofish_256.h"
#include "mk_sl_uint8.h"

#define mk_lang_memcpy_t_name mk_lib_crypto_alg_twofish_256_test_memcpyu8
#define mk_lang_memcpy_t_type mk_sl_cui_uint8_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline auto mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(mk_lang_types_pchar_t const(&key_lit)[key_lit_len], mk_lang_types_pchar_t const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_256_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_alg_twofish_256_msg_t msg mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_alg_twofish_256_msg_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_alg_twofish_256_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_lit_len == mk_lib_crypto_alg_twofish_256_msg_len_v * 2 + 1);

	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(key.m_data.m_uint8s, key_lit);
	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(msg.m_data.m_uint8s, msg_lit);
	mk_lib_crypto_alg_twofish_256_encrypt(&key, &msg, &msg);
	mk_lib_crypto_alg_twofish_256_test_memcpyu8_fn(&ret[0], &msg.m_data.m_uint8s[0], mk_lib_crypto_alg_twofish_256_msg_len_v);
	return ret;
}

template<mk_lang_types_usize_t key_lit_len, typename msg_t>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(mk_lang_types_pchar_t const(&key_lit)[key_lit_len], msg_t const& m) mk_lang_noexcept
{
	mk_lib_crypto_alg_twofish_256_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_alg_twofish_256_msg_t msg mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_alg_twofish_256_msg_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == mk_lib_crypto_alg_twofish_256_key_len_v * 2 + 1);
	mk_lang_static_assert(msg_t::s_size == mk_lib_crypto_alg_twofish_256_msg_len_v);

	mk_lib_cpp_constexpr_hex_str_lit_to_u8s_arr(key.m_data.m_uint8s, key_lit);
	mk_lib_crypto_alg_twofish_256_test_memcpyu8_fn(&msg.m_data.m_uint8s[0], &m[0], mk_lib_crypto_alg_twofish_256_msg_len_v);
	mk_lib_crypto_alg_twofish_256_decrypt(&key, &msg, &msg);
	mk_lib_crypto_alg_twofish_256_test_memcpyu8_fn(&ret[0], &msg.m_data.m_uint8s[0], mk_lib_crypto_alg_twofish_256_msg_len_v);
	return ret;
}

#endif


mk_lang_extern_c mk_lang_types_void_t mk_lib_crypto_alg_twofish_256_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define key_0 "0000000000000000000000000000000000000000000000000000000000000000"
	#define key_1 "0000000000000000000000000000000000000000000000000000000000000000"
	#define key_2 "57ff739d4dc92c1bd7fc01700cc8216f00000000000000000000000000000000"
	#define key_3 "d43bb7556ea32e46f2a282b7d45b4e0d57ff739d4dc92c1bd7fc01700cc8216f"
	#define key_4 "90afe91bb288544f2c32dc239b2635e6d43bb7556ea32e46f2a282b7d45b4e0d"
	#define key_5 "6cb4561c40bf0a9705931cb6d408e7fa90afe91bb288544f2c32dc239b2635e6"
	#define key_6 "3059d6d61753b958d92f4781c8640e586cb4561c40bf0a9705931cb6d408e7fa"
	#define key_7 "e69465770505d7f80ef68ca38ab3a3d63059d6d61753b958d92f4781c8640e58"
	#define key_8 "5ab67a5f8539a4a5fd9f0373ba463466e69465770505d7f80ef68ca38ab3a3d6"
	#define key_9 "dc096bcd99fc72f79936d4c748e75af75ab67a5f8539a4a5fd9f0373ba463466"

	#define msg_0 "00000000000000000000000000000000"
	#define msg_1 "57ff739d4dc92c1bd7fc01700cc8216f"
	#define msg_2 "d43bb7556ea32e46f2a282b7d45b4e0d"
	#define msg_3 "90afe91bb288544f2c32dc239b2635e6"
	#define msg_4 "6cb4561c40bf0a9705931cb6d408e7fa"
	#define msg_5 "3059d6d61753b958d92f4781c8640e58"
	#define msg_6 "e69465770505d7f80ef68ca38ab3a3d6"
	#define msg_7 "5ab67a5f8539a4a5fd9f0373ba463466"
	#define msg_8 "dc096bcd99fc72f79936d4c748e75af7"
	#define msg_9 "c5a3e7cee0f1b7260528a68fb4ea05f2"

	#define out_0 "57ff739d4dc92c1bd7fc01700cc8216f"
	#define out_1 "d43bb7556ea32e46f2a282b7d45b4e0d"
	#define out_2 "90afe91bb288544f2c32dc239b2635e6"
	#define out_3 "6cb4561c40bf0a9705931cb6d408e7fa"
	#define out_4 "3059d6d61753b958d92f4781c8640e58"
	#define out_5 "e69465770505d7f80ef68ca38ab3a3d6"
	#define out_6 "5ab67a5f8539a4a5fd9f0373ba463466"
	#define out_7 "dc096bcd99fc72f79936d4c748e75af7"
	#define out_8 "c5a3e7cee0f1b7260528a68fb4ea05f2"
	#define out_9 "43d5cec327b24ab90ad34a79d0469151"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_out_computed_0 = mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(key_0, msg_0);
	mk_lang_constexpr_static auto const s_out_computed_1 = mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(key_1, msg_1);
	mk_lang_constexpr_static auto const s_out_computed_2 = mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(key_2, msg_2);
	mk_lang_constexpr_static auto const s_out_computed_3 = mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(key_3, msg_3);
	mk_lang_constexpr_static auto const s_out_computed_4 = mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(key_4, msg_4);
	mk_lang_constexpr_static auto const s_out_computed_5 = mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(key_5, msg_5);
	mk_lang_constexpr_static auto const s_out_computed_6 = mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(key_6, msg_6);
	mk_lang_constexpr_static auto const s_out_computed_7 = mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(key_7, msg_7);
	mk_lang_constexpr_static auto const s_out_computed_8 = mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(key_8, msg_8);
	mk_lang_constexpr_static auto const s_out_computed_9 = mk_lib_crypto_alg_twofish_256_test_encrypt_from_str_lit(key_9, msg_9);

	mk_lang_constexpr_static auto const s_msg_computed_0 = mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(key_0, s_out_computed_0);
	mk_lang_constexpr_static auto const s_msg_computed_1 = mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(key_1, s_out_computed_1);
	mk_lang_constexpr_static auto const s_msg_computed_2 = mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(key_2, s_out_computed_2);
	mk_lang_constexpr_static auto const s_msg_computed_3 = mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(key_3, s_out_computed_3);
	mk_lang_constexpr_static auto const s_msg_computed_4 = mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(key_4, s_out_computed_4);
	mk_lang_constexpr_static auto const s_msg_computed_5 = mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(key_5, s_out_computed_5);
	mk_lang_constexpr_static auto const s_msg_computed_6 = mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(key_6, s_out_computed_6);
	mk_lang_constexpr_static auto const s_msg_computed_7 = mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(key_7, s_out_computed_7);
	mk_lang_constexpr_static auto const s_msg_computed_8 = mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(key_8, s_out_computed_8);
	mk_lang_constexpr_static auto const s_msg_computed_9 = mk_lib_crypto_alg_twofish_256_test_decrypt_from_str_lit(key_9, s_out_computed_9);

	mk_lang_constexpr_static auto const s_out_precomputed_0 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_0);
	mk_lang_constexpr_static auto const s_out_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_1);
	mk_lang_constexpr_static auto const s_out_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_2);
	mk_lang_constexpr_static auto const s_out_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_3);
	mk_lang_constexpr_static auto const s_out_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_4);
	mk_lang_constexpr_static auto const s_out_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_5);
	mk_lang_constexpr_static auto const s_out_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_6);
	mk_lang_constexpr_static auto const s_out_precomputed_7 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_7);
	mk_lang_constexpr_static auto const s_out_precomputed_8 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_8);
	mk_lang_constexpr_static auto const s_out_precomputed_9 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(out_9);

	mk_lang_constexpr_static auto const s_msg_precomputed_0 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_0);
	mk_lang_constexpr_static auto const s_msg_precomputed_1 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_1);
	mk_lang_constexpr_static auto const s_msg_precomputed_2 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_2);
	mk_lang_constexpr_static auto const s_msg_precomputed_3 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_3);
	mk_lang_constexpr_static auto const s_msg_precomputed_4 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_4);
	mk_lang_constexpr_static auto const s_msg_precomputed_5 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_5);
	mk_lang_constexpr_static auto const s_msg_precomputed_6 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_6);
	mk_lang_constexpr_static auto const s_msg_precomputed_7 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_7);
	mk_lang_constexpr_static auto const s_msg_precomputed_8 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_8);
	mk_lang_constexpr_static auto const s_msg_precomputed_9 = mk_lib_cpp_constexpr_hex_str_lit_to_u8s(msg_9);

	mk_lang_static_assert(s_out_computed_0 == s_out_precomputed_0);
	mk_lang_static_assert(s_out_computed_1 == s_out_precomputed_1);
	mk_lang_static_assert(s_out_computed_2 == s_out_precomputed_2);
	mk_lang_static_assert(s_out_computed_3 == s_out_precomputed_3);
	mk_lang_static_assert(s_out_computed_4 == s_out_precomputed_4);
	mk_lang_static_assert(s_out_computed_5 == s_out_precomputed_5);
	mk_lang_static_assert(s_out_computed_6 == s_out_precomputed_6);
	mk_lang_static_assert(s_out_computed_7 == s_out_precomputed_7);
	mk_lang_static_assert(s_out_computed_8 == s_out_precomputed_8);
	mk_lang_static_assert(s_out_computed_9 == s_out_precomputed_9);

	mk_lang_static_assert(s_msg_computed_0 == s_msg_precomputed_0);
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

	static char const* const s_keys[] =
	{
		key_0,
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
		msg_0,
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
		out_0,
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

	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t j;
	mk_lang_types_uchar_t hi;
	mk_lang_types_uchar_t lo;
	mk_lang_types_uchar_t byte;
	mk_lib_crypto_alg_twofish_256_key_t key;
	mk_lib_crypto_alg_twofish_256_msg_t msg;
	mk_sl_cui_uint8_t u8;

	mk_lang_static_assert(mk_lang_countof(s_keys) == mk_lang_countof(s_msgs));
	mk_lang_static_assert(mk_lang_countof(s_keys) == mk_lang_countof(s_outs));

	mk_lang_cpuid_init();
	n = mk_lang_countof(s_keys);
	for(i = 0; i != n; ++i)
	{
		for(j = 0; j != mk_lib_crypto_alg_twofish_256_key_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_keys[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&key.m_data.m_uint8s[j], &byte);
		}
		for(j = 0; j != mk_lib_crypto_alg_twofish_256_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&msg.m_data.m_uint8s[j], &byte);
		}
		mk_lib_crypto_alg_twofish_256_encrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_twofish_256_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_outs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
			mk_lang_test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &u8));
		}
		mk_lib_crypto_alg_twofish_256_decrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_twofish_256_msg_len_v; ++j)
		{
			hi = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 0]); mk_lang_assert(hi >= 0x0 && hi <= 0xf);
			lo = mk_lib_cpp_constexpr_char_to_nibble(s_msgs[i][j * 2 + 1]); mk_lang_assert(lo >= 0x0 && lo <= 0xf);
			byte = ((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(hi << 4)) | ((mk_lang_types_uchar_t)(lo << 0))));
			mk_sl_cui_uint8_from_bi_uchar(&u8, &byte);
			mk_lang_test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &u8));
		}
	}

	#undef key_0
	#undef key_1
	#undef key_2
	#undef key_3
	#undef key_4
	#undef key_5
	#undef key_6
	#undef key_7
	#undef key_8
	#undef key_9

	#undef msg_0
	#undef msg_1
	#undef msg_2
	#undef msg_3
	#undef msg_4
	#undef msg_5
	#undef msg_6
	#undef msg_7
	#undef msg_8
	#undef msg_9

	#undef out_0
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
