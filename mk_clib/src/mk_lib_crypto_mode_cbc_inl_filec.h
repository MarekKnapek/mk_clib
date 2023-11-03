#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_cbc_inl_defd.h"


#define mk_lib_crypto_mode_base_t_name mk_lib_crypto_mode_cbc_inl_defd_prefix
#define mk_lib_crypto_mode_base_t_len mk_lib_crypto_mode_cbc_inl_defd_msg_len_m
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"
#define mk_lib_crypto_mode_base_xor3 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_base_, mk_lib_crypto_mode_cbc_inl_defd_prefix), _xor3)
#define mk_lib_crypto_mode_base_xor2 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_base_, mk_lib_crypto_mode_cbc_inl_defd_prefix), _xor2)


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_init(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(cbc);
	mk_lang_assert(iv);

	cbc->m_iv = *iv;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_schedule_encrypt(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_cbc_inl_defd_msg_pct const input, mk_lib_crypto_mode_cbc_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;

	mk_lang_assert(cbc);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_mode_base_xor2(&cbc->m_iv.m_data.m_uint8s[0], &input[iblock].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_cbc_inl_defd_alg_schedule_encrypt(schedule, &cbc->m_iv, &cbc->m_iv, 1);
		output[iblock] = cbc->m_iv;
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_schedule_decrypt(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_cbc_inl_defd_msg_pct const input, mk_lib_crypto_mode_cbc_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_alignas(32) mk_lib_crypto_mode_cbc_inl_defd_alg_msg_t msg[9] mk_lang_constexpr_init;

	mk_lang_assert(cbc);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != (nblocks / 8) * 8; iblock += 8)
	{
		mk_lib_crypto_mode_cbc_inl_defd_alg_schedule_decrypt(schedule, &input[iblock], &msg[0], 8);
		msg[8] = input[iblock + 7];
		mk_lib_crypto_mode_base_xor3(&msg[7].m_data.m_uint8s[0], &input[iblock + 6].m_data.m_uint8s[0], &output[iblock + 7].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[6].m_data.m_uint8s[0], &input[iblock + 5].m_data.m_uint8s[0], &output[iblock + 6].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[5].m_data.m_uint8s[0], &input[iblock + 4].m_data.m_uint8s[0], &output[iblock + 5].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[4].m_data.m_uint8s[0], &input[iblock + 3].m_data.m_uint8s[0], &output[iblock + 4].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[3].m_data.m_uint8s[0], &input[iblock + 2].m_data.m_uint8s[0], &output[iblock + 3].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[2].m_data.m_uint8s[0], &input[iblock + 1].m_data.m_uint8s[0], &output[iblock + 2].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[1].m_data.m_uint8s[0], &input[iblock + 0].m_data.m_uint8s[0], &output[iblock + 1].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[0].m_data.m_uint8s[0], &cbc->m_iv.m_data.m_uint8s[0], &output[iblock + 0].m_data.m_uint8s[0]);
		cbc->m_iv = msg[8];
	}
	for(; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_mode_cbc_inl_defd_alg_schedule_decrypt(schedule, &input[iblock], &msg[0], 1);
		mk_lib_crypto_mode_base_xor2(&msg[0].m_data.m_uint8s[0], &cbc->m_iv.m_data.m_uint8s[0]);
		cbc->m_iv = input[iblock];
		output[iblock] = msg[0];
	}
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
	mk_lang_assert(cbc);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_mode_base_xor2(&cbc->m_iv.m_data.m_uint8s[0], &input->m_data.m_uint8s[0]);
	mk_lib_crypto_mode_cbc_inl_defd_alg_encrypt(key, &cbc->m_iv, &cbc->m_iv);
	*output = cbc->m_iv;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cbc_inl_defd_decrypt(mk_lib_crypto_mode_cbc_inl_defd_pt const cbc, mk_lib_crypto_mode_cbc_inl_defd_key_pct const key, mk_lib_crypto_mode_cbc_inl_defd_msg_pct const input, mk_lib_crypto_mode_cbc_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_cbc_inl_defd_alg_msg_t msg mk_lang_constexpr_init;

	mk_lang_assert(cbc);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_mode_cbc_inl_defd_alg_decrypt(key, input, &msg);
	mk_lib_crypto_mode_base_xor2(&msg.m_data.m_uint8s[0], &cbc->m_iv.m_data.m_uint8s[0]);
	cbc->m_iv = *input;
	*output = msg;
}


#undef mk_lib_crypto_mode_base_xor3
#undef mk_lib_crypto_mode_base_xor2


#include "mk_lib_crypto_mode_cbc_inl_defu.h"


#undef mk_lib_crypto_mode_cbc_t_name
#undef mk_lib_crypto_mode_cbc_t_alg
