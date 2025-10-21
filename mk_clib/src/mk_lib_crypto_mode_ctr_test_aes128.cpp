#ifndef mk_include_guard_mk_lib_crypto_mode_ctr_test_aes128_cpp
#define mk_include_guard_mk_lib_crypto_mode_ctr_test_aes128_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_lib_crypto_mode_ctr_test_aes128.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr_array_u8.hpp"
#include "mk_sl_cui_uint8.h"
#include "mk_lib_crypto_mode_ctr.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

template<mk_lang_types_usize_t iv_lit_len, mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mode_ctr_test_aes128_aes_128_encrypt_from_str_lit(mk_lang_types_pchar_t const(&iv_lit)[iv_lit_len], mk_lang_types_pchar_t const(&key_lit)[key_lit_len], mk_lang_types_pchar_t const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_aes_128_iv_t iv mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_alg_t alg mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_msg_t msgs[(msg_lit_len - 1) / (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))] mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (msg_lit_len - 1) / 2> ret mk_lang_constexpr_init;

	mk_lang_static_assert(iv_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_iv_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);
	mk_lang_static_assert(key_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_key_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);
	mk_lang_static_assert(msg_lit_len >= 1);
	mk_lang_static_assert((msg_lit_len - 1) % (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))) == 0);

	mk_lang_assert(iv_lit);
	mk_lang_assert(key_lit);
	mk_lang_assert(msg_lit);

	mk_lib_cpp_constexpr_array_u8_from_hex_lit(iv.m_data.m_base.m_data.m_uint8s, iv_lit);
	mk_lib_cpp_constexpr_array_u8_from_hex_lit(key.m_data.m_base.m_data.m_uint8s, key_lit);
	mk_lib_crypto_mode_ctr_aes_128_rw_set_iv(&alg, &iv);
	mk_lib_crypto_mode_ctr_aes_128_rw_set_key_enc(&alg, &key);
	n = mk_lang_countof(msgs);
	for(i = 0; i != n; ++i)
	{
		len = mk_sl_cui_uint8_from_str_hex_many_n(&msgs[i].m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_msg_len_v, &msg_lit[i * (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))], ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))); mk_lang_assert(len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
	}
	mk_lib_crypto_mode_ctr_aes_128_rw_encrypt(&alg, &msgs[0], &msgs[0], ((mk_lang_types_usize_t)(n)));
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_memcpy_fn(ret.data() + i * mk_lib_crypto_mode_ctr_aes_128_msg_len_v, &msgs[i].m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_msg_len_v);
	}
	return ret;
}

template<mk_lang_types_usize_t iv_lit_len, mk_lang_types_usize_t key_lit_len, mk_lang_types_usize_t msg_lit_len>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_lib_crypto_mode_ctr_test_aes128_aes_128_decrypt_from_str_lit(mk_lang_types_pchar_t const(&iv_lit)[iv_lit_len], mk_lang_types_pchar_t const(&key_lit)[key_lit_len], mk_lang_types_pchar_t const(&msg_lit)[msg_lit_len]) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_aes_128_iv_t iv mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_alg_t alg mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_msg_t msgs[(msg_lit_len - 1) / (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))] mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_sl_cui_uint8_t, (msg_lit_len - 1) / 2> ret mk_lang_constexpr_init;

	mk_lang_static_assert(iv_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_iv_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);
	mk_lang_static_assert(key_lit_len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_key_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)) + 1);
	mk_lang_static_assert(msg_lit_len >= 1);
	mk_lang_static_assert((msg_lit_len - 1) % (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))) == 0);

	mk_lang_assert(iv_lit);
	mk_lang_assert(key_lit);
	mk_lang_assert(msg_lit);

	mk_lib_cpp_constexpr_array_u8_from_hex_lit(iv.m_data.m_base.m_data.m_uint8s, iv_lit);
	mk_lib_cpp_constexpr_array_u8_from_hex_lit(key.m_data.m_base.m_data.m_uint8s, key_lit);
	mk_lib_crypto_mode_ctr_aes_128_rw_set_iv(&alg, &iv);
	mk_lib_crypto_mode_ctr_aes_128_rw_set_key_dec(&alg, &key);
	n = mk_lang_countof(msgs);
	for(i = 0; i != n; ++i)
	{
		len = mk_sl_cui_uint8_from_str_hex_many_n(&msgs[i].m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_msg_len_v, &msg_lit[i * (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))], ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))); mk_lang_assert(len == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
	}
	mk_lib_crypto_mode_ctr_aes_128_rw_decrypt(&alg, &msgs[0], &msgs[0], ((mk_lang_types_usize_t)(n)));
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_memcpy_fn(ret.data() + i * mk_lib_crypto_mode_ctr_aes_128_msg_len_v, &msgs[i].m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_msg_len_v);
	}
	return ret;
}

#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_lib_crypto_mode_ctr_test_aes128(mk_lang_types_void_t) mk_lang_noexcept
{
	#define iv_1 "f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff"

	#define key_1 "2b7e151628aed2a6abf7158809cf4f3c"

	#define msg_1 "6bc1bee22e409f96e93d7e117393172a""ae2d8a571e03ac9c9eb76fac45af8e51""30c81c46a35ce411e5fbc1191a0a52ef""f69f2445df4f9b17ad2b417be66c3710"

	#define out_1 "874d6191b620e3261bef6864990db6ce""9806f66b7970fdff8617187bb9fffdff""5ae4df3edbd5d35e5b4f09020db03eab""1e031dda2fbe03d1792170a0f3009cee"

	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static auto const s_out_computed_1 = mk_lib_crypto_mode_ctr_test_aes128_aes_128_encrypt_from_str_lit(iv_1, key_1, msg_1);
	mk_lang_constexpr_static auto const s_msg_computed_1 = mk_lib_crypto_mode_ctr_test_aes128_aes_128_decrypt_from_str_lit(iv_1, key_1, out_1);
	mk_lang_constexpr_static auto const s_out_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(out_1);
	mk_lang_constexpr_static auto const s_msg_precomputed_1 = mk_lib_cpp_constexpr_array_u8_from_hex_lit(msg_1);
	mk_lang_static_assert(s_out_computed_1 == s_out_precomputed_1);
	mk_lang_static_assert(s_msg_computed_1 == s_msg_precomputed_1);

	#endif

	mk_lang_types_pchar_pct const ivs[] =
	{
		iv_1,
	};

	mk_lang_types_sint_t const ivs_lens[] =
	{
		mk_lang_countstr(iv_1),
	};

	mk_lang_types_pchar_pct const keys[] =
	{
		key_1,
	};

	mk_lang_types_sint_t const keys_lens[] =
	{
		mk_lang_countstr(key_1),
	};

	mk_lang_types_pchar_pct const msgs[] =
	{
		msg_1,
	};

	mk_lang_types_sint_t const msgs_lens[] =
	{
		mk_lang_countstr(msg_1),
	};

	mk_lang_types_pchar_pct const outs[] =
	{
		out_1,
	};

	mk_lang_types_sint_t const outs_lens[] =
	{
		mk_lang_countstr(out_1),
	};

	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_iv_t iv mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_key_t key mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_alg_t alg mk_lang_constexpr_init;
	mk_lang_types_sint_t m mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_msg_t msg[9] mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_aes_128_msg_t out mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(ivs_lens));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(keys));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(keys_lens));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(msgs));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(msgs_lens));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(keys));
	mk_lang_static_assert(mk_lang_countof(ivs) == mk_lang_countof(outs_lens));

	n = mk_lang_countof(ivs);
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(ivs_lens[i] == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_iv_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
		mk_lang_assert(keys_lens[i] == ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_key_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
		mk_lang_assert(msgs_lens[i] % (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))) == 0);
		mk_lang_assert(outs_lens[i] % (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))) == 0);
		mk_lang_assert(msgs_lens[i] == outs_lens[i]);
		mk_lang_assert(mk_lang_countof(msg) >= msgs_lens[i] / (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))));
		len = mk_sl_cui_uint8_from_str_hex_many_n(&iv.m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_iv_len_v, &ivs[i][0], ivs_lens[i]); mk_lang_assert(len == ivs_lens[i]);
		len = mk_sl_cui_uint8_from_str_hex_many_n(&key.m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_key_len_v, &keys[i][0], keys_lens[i]); mk_lang_assert(len == keys_lens[i]);
		mk_lib_crypto_mode_ctr_aes_128_rw_set_iv(&alg, &iv);
		mk_lib_crypto_mode_ctr_aes_128_rw_set_key_enc(&alg, &key);
		m = msgs_lens[i] / (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)));
		for(j = 0; j != m; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_many_n(&msg[j].m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_msg_len_v, &msgs[i][j * (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))], ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))); mk_lang_assert(len == (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))));
		}
		mk_lib_crypto_mode_ctr_aes_128_rw_encrypt(&alg, &msg[0], &msg[0], ((mk_lang_types_usize_t)(m)));
		for(j = 0; j != m; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_many_n(&out.m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_msg_len_v, &outs[i][j * (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))], ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))); mk_lang_assert(len == (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))));
			mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&msg[j].m_data.m_base.m_data.m_uint8s[0], &out.m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_msg_len_v) == 0);
		}
		mk_lib_crypto_mode_ctr_aes_128_rw_set_iv(&alg, &iv);
		mk_lib_crypto_mode_ctr_aes_128_rw_set_key_dec(&alg, &key);
		mk_lib_crypto_mode_ctr_aes_128_rw_decrypt(&alg, &msg[0], &msg[0], ((mk_lang_types_usize_t)(m)));
		for(j = 0; j != m; ++j)
		{
			len = mk_sl_cui_uint8_from_str_hex_many_n(&out.m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_msg_len_v, &msgs[i][j * (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v)))], ((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))); mk_lang_assert(len == (((mk_lang_types_sint_t)(mk_lib_crypto_mode_ctr_aes_128_msg_len_v)) * ((mk_lang_types_sint_t)(mk_sl_cui_uint8_strlen_hex_v))));
			mk_lang_test(mk_sl_cui_uint8_memcmp_fn(&msg[j].m_data.m_base.m_data.m_uint8s[0], &out.m_data.m_base.m_data.m_uint8s[0], mk_lib_crypto_mode_ctr_aes_128_msg_len_v) == 0);
		}
	}

	#undef iv_1

	#undef key_1

	#undef msg_1

	#undef out_1
}


#include "mk_lang_warning_msvc_pop.h"


#endif
