#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_endian.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_ctr_be_inl_defd.h"


#define mk_lib_crypto_mode_base_t_name mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _mode_base)
#define mk_lib_crypto_mode_base_t_len mk_lib_crypto_mode_ctr_be_inl_defd_msg_len_m
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"
#define mk_lib_crypto_mode_base_xor3 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _mode_base), _xor3)
#define mk_lib_crypto_mode_base_xor2 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _mode_base), _xor2)


#define mk_lang_bui_t_name mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _uint_primitive)
#define mk_lang_bui_t_base ulllong
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_t_base_sizebits_d (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
#define mk_sl_cui_t_name mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _uint_proper)
#define mk_sl_cui_t_base mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _uint_primitive)
#define mk_sl_cui_t_count mk_lang_div_roundup(mk_lib_crypto_mode_ctr_be_inl_defd_msg_len_m * mk_lang_charbit, mk_sl_cui_t_base_sizebits_d) /* todo different msg len */
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#define ctr_t mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _uint_proper), _t)
#define ctr_pt mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _uint_proper), _pt)
#define ctr_from_uchars mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _uint_proper), _from_buis_uchar_be)
#define ctr_inc mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _uint_proper), _inc1)
#define ctr_to_uchars mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_ctr_be_inl_defd_prefix, _uint_proper), _to_buis_uchar_be)


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_increment(mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const iv) mk_lang_noexcept
{
	union ctr_uu
	{
		mk_lang_types_uchar_t m_uchars[sizeof(ctr_t)];
		ctr_t m_iv;
		mk_lib_crypto_mode_ctr_be_inl_defd_t m_msg;
	};
	typedef union ctr_uu ctr_tt;

	int i mk_lang_constexpr_init;
	ctr_tt ctrr mk_lang_constexpr_init;
	ctr_t num mk_lang_constexpr_init;

	mk_lang_assert(iv);

	#if !mk_lang_constexpr_is_constant_evaluated
	if(1)
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#endif
	{
		ctr_from_uchars(&num, ((mk_lang_types_uchar_pct)(iv)));
		ctr_inc(&num);
		ctr_to_uchars(&num, ((mk_lang_types_uchar_pt)(iv)));
	}
	else
	{
		for(i = 0; i != mk_lib_crypto_mode_ctr_be_inl_defd_msg_len_v; ++i){ mk_sl_cui_uint8_to_bi_uchar(&iv->m_data.m_uint8s[i], &ctrr.m_uchars[i]); }
		ctr_from_uchars(&num, &ctrr.m_uchars[0]);
		ctr_inc(&num);
		ctr_to_uchars(&num, &ctrr.m_uchars[0]);
		for(i = 0; i != mk_lib_crypto_mode_ctr_be_inl_defd_msg_len_v; ++i){ mk_sl_cui_uint8_from_bi_uchar(&iv->m_data.m_uint8s[i], &ctrr.m_uchars[i]); }
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_schedule_crypt(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_alignas(32) mk_lib_crypto_mode_ctr_be_inl_defd_msg_t iv[8] mk_lang_constexpr_init;

	mk_lang_assert(ctr_be);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != (nblocks / 8) * 8; iblock += 8)
	{
		iv[0] = ctr_be->m_iv;
		mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv); iv[1] = ctr_be->m_iv;
		mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv); iv[2] = ctr_be->m_iv;
		mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv); iv[3] = ctr_be->m_iv;
		mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv); iv[4] = ctr_be->m_iv;
		mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv); iv[5] = ctr_be->m_iv;
		mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv); iv[6] = ctr_be->m_iv;
		mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv); iv[7] = ctr_be->m_iv;
		mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv);
		mk_lib_crypto_mode_ctr_be_inl_defd_alg_schedule_encrypt(schedule, &iv[0], &iv[0], 8);
		mk_lib_crypto_mode_base_xor3(&iv[0].m_data.m_uint8s[0], &input[iblock + 0].m_data.m_uint8s[0], &output[iblock + 0].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&iv[1].m_data.m_uint8s[0], &input[iblock + 1].m_data.m_uint8s[0], &output[iblock + 1].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&iv[2].m_data.m_uint8s[0], &input[iblock + 2].m_data.m_uint8s[0], &output[iblock + 2].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&iv[3].m_data.m_uint8s[0], &input[iblock + 3].m_data.m_uint8s[0], &output[iblock + 3].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&iv[4].m_data.m_uint8s[0], &input[iblock + 4].m_data.m_uint8s[0], &output[iblock + 4].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&iv[5].m_data.m_uint8s[0], &input[iblock + 5].m_data.m_uint8s[0], &output[iblock + 5].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&iv[6].m_data.m_uint8s[0], &input[iblock + 6].m_data.m_uint8s[0], &output[iblock + 6].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&iv[7].m_data.m_uint8s[0], &input[iblock + 7].m_data.m_uint8s[0], &output[iblock + 7].m_data.m_uint8s[0]);
	}
	for(; iblock != nblocks; ++iblock)
	{
		iv[0] = ctr_be->m_iv;
		mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv);
		mk_lib_crypto_mode_ctr_be_inl_defd_alg_schedule_encrypt(schedule, &iv[0], &iv[0], 1);
		mk_lib_crypto_mode_base_xor3(&iv[0].m_data.m_uint8s[0], &input[iblock].m_data.m_uint8s[0], &output[iblock].m_data.m_uint8s[0]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_crypt(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_key_pct const key, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_msg_t iv mk_lang_constexpr_init;

	mk_lang_assert(ctr_be);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	iv = ctr_be->m_iv;
	mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv);
	mk_lib_crypto_mode_ctr_be_inl_defd_alg_encrypt(key, &iv, &iv);
	mk_lib_crypto_mode_base_xor3(&iv.m_data.m_uint8s[0], &input->m_data.m_uint8s[0], &output->m_data.m_uint8s[0]);
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_init(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(ctr_be);
	mk_lang_assert(iv);

	ctr_be->m_iv = *iv;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_schedule_encrypt(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_schedule_crypt(ctr_be, schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_schedule_decrypt(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_schedule_crypt(ctr_be, schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_expand_enc(mk_lib_crypto_mode_ctr_be_inl_defd_key_pct const key, mk_lib_crypto_mode_ctr_be_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_alg_expand_enc(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_expand_dec(mk_lib_crypto_mode_ctr_be_inl_defd_key_pct const key, mk_lib_crypto_mode_ctr_be_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_alg_expand_enc(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_encrypt(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_key_pct const key, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_crypt(ctr_be, key, input, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_decrypt(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_key_pct const key, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_crypt(ctr_be, key, input, output);
}


#undef mk_lib_crypto_mode_base_xor3
#undef mk_lib_crypto_mode_base_xor2

#undef ctr_t
#undef ctr_from_uchars
#undef ctr_inc
#undef ctr_to_uchars


#include "mk_lib_crypto_mode_ctr_be_inl_defu.h"


#undef mk_lib_crypto_mode_ctr_be_t_name
#undef mk_lib_crypto_mode_ctr_be_t_alg
