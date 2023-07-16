#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_cfb_inl_defd.h"


mk_lib_crypto_mode_cfb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_init(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_alg_msg_pct const msg) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lib_crypto_mode_cfb_inl_defd_s_bits >= 1 && mk_lib_crypto_mode_cfb_inl_defd_s_bits <= mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m * mk_lang_charbit);
	mk_lang_static_assert(mk_lib_crypto_mode_cfb_inl_defd_s_bits % mk_lang_charbit == 0);

	mk_lang_assert(cfb);
	mk_lang_assert(msg);

	cfb->m_iv = *msg;
}

mk_lib_crypto_mode_cfb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_encrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_key_pct const key, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	iv = cfb->m_iv;
	mk_lib_crypto_mode_cfb_inl_defd_alg_encrypt(key, &iv, &iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor3(&iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i], &output->m_data.m_uint8s[i]);
	}
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m - mk_lib_crypto_mode_cfb_inl_defd_msg_len_m; ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m - mk_lib_crypto_mode_cfb_inl_defd_msg_len_m) + i] = output->m_data.m_uint8s[i]; }
}

mk_lib_crypto_mode_cfb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_decrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_key_pct const key, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	iv = cfb->m_iv;
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m - mk_lib_crypto_mode_cfb_inl_defd_msg_len_m; ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m - mk_lib_crypto_mode_cfb_inl_defd_msg_len_m) + i] = input->m_data.m_uint8s[i]; }
	mk_lib_crypto_mode_cfb_inl_defd_alg_encrypt(key, &iv, &iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor3(&iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i], &output->m_data.m_uint8s[i]);
	}
}


#include "mk_lib_crypto_mode_cfb_inl_defu.h"


#undef mk_lib_crypto_mode_cfb_t_name
#undef mk_lib_crypto_mode_cfb_t_alg
#undef mk_lib_crypto_mode_cfb_t_constexpr
#undef mk_lib_crypto_mode_cfb_t_s_bits
