#include "mk_lang_assert.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_cbc_inl_defd.h"


mk_lib_crypto_mode_cbc_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_init(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_alg_msg_pct const data) mk_lang_noexcept
{
	mk_lang_assert(cbc);
	mk_lang_assert(data);

	cbc->m_iv = *data;
}

mk_lib_crypto_mode_cbc_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_encrypt(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_key_pct const key, mk_lib_crypto_mode_cbc_inl_defd_msg_pct const input, mk_lib_crypto_mode_cbc_inl_defd_msg_pt const output) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(cbc);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(i = 0; i != mk_lib_crypto_mode_cbc_inl_defd_msg_len_v; ++i)
	{
		cbc->m_iv.m_data.m_uchars[i] ^= input->m_data.m_uchars[i];
	}
	mk_lib_crypto_mode_cbc_inl_defd_alg_encrypt(key, &cbc->m_iv, &cbc->m_iv);
	*output = cbc->m_iv;
}

mk_lib_crypto_mode_cbc_inl_defd_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_decrypt(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_key_pct const key, mk_lib_crypto_mode_cbc_inl_defd_msg_pct const input, mk_lib_crypto_mode_cbc_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_cbc_inl_defd_alg_msg_t msg mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cbc);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_mode_cbc_inl_defd_alg_decrypt(key, input, &msg);
	for(i = 0; i != mk_lib_crypto_mode_cbc_inl_defd_msg_len_v; ++i)
	{
		msg.m_data.m_uchars[i] ^= cbc->m_iv.m_data.m_uchars[i];
	}
	cbc->m_iv = *input;
	*output = msg;
}


#include "mk_lib_crypto_mode_cbc_inl_defu.h"


#undef mk_lib_crypto_mode_cbc_t_name
#undef mk_lib_crypto_mode_cbc_t_alg
#undef mk_lib_crypto_mode_cbc_t_constexpr
