#include "mk_lang_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_ofb_inl_defd.h"


mk_lib_crypto_mode_ofb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_crypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_key_pct const key, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(ofb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_mode_ofb_inl_defd_alg_encrypt(key, &ofb->m_iv, &ofb->m_iv);
	for(i = 0; i != mk_lib_crypto_mode_ofb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor3(&ofb->m_iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i], &output->m_data.m_uint8s[i]);
	}
}


mk_lib_crypto_mode_ofb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_init(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_alg_msg_pct const data) mk_lang_noexcept
{
	mk_lang_assert(ofb);
	mk_lang_assert(data);

	ofb->m_iv = *data;
}

mk_lib_crypto_mode_ofb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_encrypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_key_pct const key, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ofb_inl_defd_crypt(ofb, key, input, output);
}

mk_lib_crypto_mode_ofb_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_decrypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_key_pct const key, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ofb_inl_defd_crypt(ofb, key, input, output);
}


#include "mk_lib_crypto_mode_ofb_inl_defu.h"


#undef mk_lib_crypto_mode_ofb_t_name
#undef mk_lib_crypto_mode_ofb_t_alg
#undef mk_lib_crypto_mode_ofb_t_constexpr
