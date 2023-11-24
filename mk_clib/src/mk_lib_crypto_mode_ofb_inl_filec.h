#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_ofb_inl_defd.h"


#define mk_lib_crypto_mode_base_t_name mk_lang_concat(mk_lib_crypto_mode_ofb_inl_defd_prefix, _mode_base)
#define mk_lib_crypto_mode_base_t_len mk_lib_crypto_mode_ofb_inl_defd_msg_len_m
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"
#define mk_lib_crypto_mode_base_xor3 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_ofb_inl_defd_prefix, _mode_base), _xor3)
#define mk_lib_crypto_mode_base_xor2 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_ofb_inl_defd_prefix, _mode_base), _xor2)


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_schedule_crypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	mk_lang_assert(ofb);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_mode_ofb_inl_defd_alg_schedule_encrypt(schedule, &ofb->m_iv, &ofb->m_iv, 1);
		mk_lib_crypto_mode_base_xor3(&ofb->m_iv.m_data.m_uint8s[0], &input[iblock].m_data.m_uint8s[0], &output[iblock].m_data.m_uint8s[0]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_crypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_key_pct const key, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lang_assert(ofb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_mode_ofb_inl_defd_alg_encrypt(key, &ofb->m_iv, &ofb->m_iv);
	mk_lib_crypto_mode_base_xor3(&ofb->m_iv.m_data.m_uint8s[0], &input->m_data.m_uint8s[0], &output->m_data.m_uint8s[0]);
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_init(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(ofb);
	mk_lang_assert(iv);

	ofb->m_iv = *iv;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_schedule_encrypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_mode_ofb_inl_defd_schedule_crypt(ofb, schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_schedule_decrypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_mode_ofb_inl_defd_schedule_crypt(ofb, schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_expand_enc(mk_lib_crypto_mode_ofb_inl_defd_key_pct const key, mk_lib_crypto_mode_ofb_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_mode_ofb_inl_defd_alg_expand_enc(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_expand_dec(mk_lib_crypto_mode_ofb_inl_defd_key_pct const key, mk_lib_crypto_mode_ofb_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_mode_ofb_inl_defd_alg_expand_enc(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_encrypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_key_pct const key, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ofb_inl_defd_crypt(ofb, key, input, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ofb_inl_defd_decrypt(mk_lib_crypto_mode_ofb_inl_defd_pt const ofb, mk_lib_crypto_mode_ofb_inl_defd_key_pct const key, mk_lib_crypto_mode_ofb_inl_defd_msg_pct const input, mk_lib_crypto_mode_ofb_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ofb_inl_defd_crypt(ofb, key, input, output);
}


#undef mk_lib_crypto_mode_base_xor3
#undef mk_lib_crypto_mode_base_xor2


#include "mk_lib_crypto_mode_ofb_inl_defu.h"


#undef mk_lib_crypto_mode_ofb_t_name
#undef mk_lib_crypto_mode_ofb_t_alg
