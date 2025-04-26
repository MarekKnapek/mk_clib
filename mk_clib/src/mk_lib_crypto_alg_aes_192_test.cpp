#ifndef mk_include_guard_mk_lib_crypto_alg_aes_192_test_cpp
#define mk_include_guard_mk_lib_crypto_alg_aes_192_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_alg_aes_192_test.hpp"

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
#include "mk_lib_crypto_alg_aes_192.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(mk_lang_types_pchar_t const(&key_lit)[key_lit_len], mk_lang_types_pchar_t const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_msg_t msg mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_alg_aes_192_msg_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_192_key_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);
	mk_lang_static_assert(msg_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_192_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);

	mk_lib_cpp_constexpr_array_u8_from_hex_lit(key.m_data.m_uint8s, key_lit);
	mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg.m_data.m_uint8s, msg_lit);
	mk_lib_crypto_alg_aes_192_encrypt(&key, &msg, &msg);
	ret = mk_lib_cpp_constexpr_array_u8_from_u8s(msg.m_data.m_uint8s);
	return ret;
}

template<mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(mk_lang_types_pchar_t const(&key_lit)[key_lit_len], mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, msg_len> const& msg_in) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_192_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_msg_t msg mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, mk_lib_crypto_alg_aes_192_msg_len_v> ret mk_lang_constexpr_init;

	mk_lang_static_assert(key_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_192_key_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);
	mk_lang_static_assert(msg_len == mk_lib_crypto_alg_aes_192_msg_len_v);

	mk_lib_cpp_constexpr_array_u8_from_hex_lit(key.m_data.m_uint8s, key_lit);
	mk_sl_cui_uint8_memcpy_fn(&msg.m_data.m_uint8s[0], msg_in.cdata(), msg_in.size());
	mk_lib_crypto_alg_aes_192_decrypt(&key, &msg, &msg);
	ret = mk_lib_cpp_constexpr_array_u8_from_u8s(msg.m_data.m_uint8s);
	return ret;
}

#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_crypto_alg_aes_192_test(mk_lang_types_void_t) mk_lang_noexcept
{
	#define key_1 "000102030405060708090a0b0c0d0e0f1011121314151617"
	#define key_2 "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b"
	#define key_3 "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b"
	#define key_4 "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b"
	#define key_5 "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b"

	#define msg_1 "00112233445566778899aabbccddeeff"
	#define msg_2 "6bc1bee22e409f96e93d7e117393172a"
	#define msg_3 "ae2d8a571e03ac9c9eb76fac45af8e51"
	#define msg_4 "30c81c46a35ce411e5fbc1191a0a52ef"
	#define msg_5 "f69f2445df4f9b17ad2b417be66c3710"

	#define out_1 "dda97ca4864cdfe06eaf70a0ec0d7191"
	#define out_2 "bd334f1d6e45f25ff712a214571fa5cc"
	#define out_3 "974104846d0ad3ad7734ecb3ecee4eef"
	#define out_4 "ef7afd2270e2e60adce0ba2face6444e"
	#define out_5 "9a4b41ba738d6c72fb16691603c18e0e"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_out_computed_1 = mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(key_1, msg_1);
	mk_lang_constexpr_static auto const s_out_computed_2 = mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(key_2, msg_2);
	mk_lang_constexpr_static auto const s_out_computed_3 = mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(key_3, msg_3);
	mk_lang_constexpr_static auto const s_out_computed_4 = mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(key_4, msg_4);
	mk_lang_constexpr_static auto const s_out_computed_5 = mk_lib_crypto_alg_aes_192_test_encrypt_from_str_lit(key_5, msg_5);

	mk_lang_constexpr_static auto const s_msg_computed_1 = mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(key_1, s_out_computed_1);
	mk_lang_constexpr_static auto const s_msg_computed_2 = mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(key_2, s_out_computed_2);
	mk_lang_constexpr_static auto const s_msg_computed_3 = mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(key_3, s_out_computed_3);
	mk_lang_constexpr_static auto const s_msg_computed_4 = mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(key_4, s_out_computed_4);
	mk_lang_constexpr_static auto const s_msg_computed_5 = mk_lib_crypto_alg_aes_192_test_decrypt_from_str_lit(key_5, s_out_computed_5);

	mk_lang_constexpr_static auto const s_out_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_1);
	mk_lang_constexpr_static auto const s_out_precomputed_2 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_2);
	mk_lang_constexpr_static auto const s_out_precomputed_3 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_3);
	mk_lang_constexpr_static auto const s_out_precomputed_4 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_4);
	mk_lang_constexpr_static auto const s_out_precomputed_5 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_5);

	mk_lang_constexpr_static auto const s_msg_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_1);
	mk_lang_constexpr_static auto const s_msg_precomputed_2 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_2);
	mk_lang_constexpr_static auto const s_msg_precomputed_3 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_3);
	mk_lang_constexpr_static auto const s_msg_precomputed_4 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_4);
	mk_lang_constexpr_static auto const s_msg_precomputed_5 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_5);

	mk_lang_static_assert(s_out_computed_1 == s_out_precomputed_1);
	mk_lang_static_assert(s_out_computed_2 == s_out_precomputed_2);
	mk_lang_static_assert(s_out_computed_3 == s_out_precomputed_3);
	mk_lang_static_assert(s_out_computed_4 == s_out_precomputed_4);
	mk_lang_static_assert(s_out_computed_5 == s_out_precomputed_5);

	mk_lang_static_assert(s_msg_computed_1 == s_msg_precomputed_1);
	mk_lang_static_assert(s_msg_computed_2 == s_msg_precomputed_2);
	mk_lang_static_assert(s_msg_computed_3 == s_msg_precomputed_3);
	mk_lang_static_assert(s_msg_computed_4 == s_msg_precomputed_4);
	mk_lang_static_assert(s_msg_computed_5 == s_msg_precomputed_5);

	#endif

	mk_lang_types_pchar_pct const keys[] =
	{
		key_1,
		key_2,
		key_3,
		key_4,
		key_5,
	};

	mk_lang_types_sint_t const key_lens[] =
	{
		mk_lang_countstr(key_1),
		mk_lang_countstr(key_2),
		mk_lang_countstr(key_3),
		mk_lang_countstr(key_4),
		mk_lang_countstr(key_5),
	};

	mk_lang_types_pchar_pct const msgs[] =
	{
		msg_1,
		msg_2,
		msg_3,
		msg_4,
		msg_5,
	};

	mk_lang_types_sint_t const msg_lens[] =
	{
		mk_lang_countstr(msg_1),
		mk_lang_countstr(msg_2),
		mk_lang_countstr(msg_3),
		mk_lang_countstr(msg_4),
		mk_lang_countstr(msg_5),
	};

	mk_lang_types_pchar_pct const outs[] =
	{
		out_1,
		out_2,
		out_3,
		out_4,
		out_5,
	};

	mk_lang_types_sint_t const out_lens[] =
	{
		mk_lang_countstr(out_1),
		mk_lang_countstr(out_2),
		mk_lang_countstr(out_3),
		mk_lang_countstr(out_4),
		mk_lang_countstr(out_5),
	};

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_192_msg_t msg mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_sl_cui_uint8_t ta mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(keys) == mk_lang_countof(key_lens));
	mk_lang_static_assert(mk_lang_countof(keys) == mk_lang_countof(msgs));
	mk_lang_static_assert(mk_lang_countof(keys) == mk_lang_countof(msg_lens));
	mk_lang_static_assert(mk_lang_countof(keys) == mk_lang_countof(outs));
	mk_lang_static_assert(mk_lang_countof(keys) == mk_lang_countof(out_lens));

	n = mk_lang_countof(keys);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(key_lens[i] == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_192_key_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
		mk_lang_assert(msg_lens[i] == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_192_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
		mk_lang_assert(out_lens[i] == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_192_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
		len = mk_sl_cui_uint8_from_str_hex_many_n(&key.m_data.m_uint8s[0], mk_lib_crypto_alg_aes_192_key_len_v, &keys[i][0], key_lens[i]); mk_lang_assert(len == key_lens[i]);
		len = mk_sl_cui_uint8_from_str_hex_many_n(&msg.m_data.m_uint8s[0], mk_lib_crypto_alg_aes_192_msg_len_v, &msgs[i][0], msg_lens[i]); mk_lang_assert(len == msg_lens[i]);
		mk_lib_crypto_alg_aes_192_encrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_aes_192_msg_len_v; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &outs[i][j * mk_sl_cui_uint8_strlen_hex_v], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
			mk_lang_test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &ta));
		}
		mk_lib_crypto_alg_aes_192_decrypt(&key, &msg, &msg);
		for(j = 0; j != mk_lib_crypto_alg_aes_192_msg_len_v; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_n(&ta, &msgs[i][j * mk_sl_cui_uint8_strlen_hex_v], mk_sl_cui_uint8_strlen_hex_v); mk_lang_assert(len == mk_sl_cui_uint8_strlen_hex_v);
			mk_lang_test(mk_sl_cui_uint8_eq(&msg.m_data.m_uint8s[j], &ta));
		}
	}

	#undef key_1
	#undef key_2
	#undef key_3
	#undef key_4
	#undef key_5

	#undef msg_1
	#undef msg_2
	#undef msg_3
	#undef msg_4
	#undef msg_5

	#undef out_1
	#undef out_2
	#undef out_3
	#undef out_4
	#undef out_5
}


#include "mk_lang_warning_msvc_pop.h"


#endif
