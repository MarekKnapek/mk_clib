#include "mk_lang_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_cbc_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_init(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(cbc);
	mk_lang_assert(iv);

	cbc->m_iv = *iv;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_schedule_encrypt(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_cbc_inl_defd_msg_pct const input, mk_lib_crypto_mode_cbc_inl_defd_msg_pt const output) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(cbc);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(i = 0; i != mk_lib_crypto_mode_cbc_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor2(&cbc->m_iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i]);
	}
	mk_lib_crypto_mode_cbc_inl_defd_alg_schedule_encrypt(schedule, &cbc->m_iv, &cbc->m_iv);
	*output = cbc->m_iv;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_schedule_decrypt(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_cbc_inl_defd_msg_pct const input, mk_lib_crypto_mode_cbc_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_cbc_inl_defd_alg_msg_t msg mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cbc);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_mode_cbc_inl_defd_alg_schedule_decrypt(schedule, input, &msg);
	for(i = 0; i != mk_lib_crypto_mode_cbc_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor2(&msg.m_data.m_uint8s[i], &cbc->m_iv.m_data.m_uint8s[i]);
	}
	cbc->m_iv = *input;
	*output = msg;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_expand_enc(mk_lib_crypto_mode_cbc_inl_defd_key_pct const key, mk_lib_crypto_mode_cbc_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_mode_cbc_inl_defd_alg_expand_enc(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_expand_dec(mk_lib_crypto_mode_cbc_inl_defd_key_pct const key, mk_lib_crypto_mode_cbc_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_mode_cbc_inl_defd_alg_expand_dec(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_encrypt(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_key_pct const key, mk_lib_crypto_mode_cbc_inl_defd_msg_pct const input, mk_lib_crypto_mode_cbc_inl_defd_msg_pt const output) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(cbc);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(i = 0; i != mk_lib_crypto_mode_cbc_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor2(&cbc->m_iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i]);
	}
	mk_lib_crypto_mode_cbc_inl_defd_alg_encrypt(key, &cbc->m_iv, &cbc->m_iv);
	*output = cbc->m_iv;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_decrypt(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_key_pct const key, mk_lib_crypto_mode_cbc_inl_defd_msg_pct const input, mk_lib_crypto_mode_cbc_inl_defd_msg_pt const output) mk_lang_noexcept
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
		mk_sl_cui_uint8_xor2(&msg.m_data.m_uint8s[i], &cbc->m_iv.m_data.m_uint8s[i]);
	}
	cbc->m_iv = *input;
	*output = msg;
}


#include "mk_lib_crypto_mode_cbc_inl_defu.h"


#undef mk_lib_crypto_mode_cbc_t_name
#undef mk_lib_crypto_mode_cbc_t_alg
#undef mk_lib_crypto_mode_cbc_t_constexpr
