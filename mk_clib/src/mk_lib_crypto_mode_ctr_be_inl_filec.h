#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
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


#define mk_lang_bui_name mk_lib_crypto_mode_ctr_be_inl_defd_prefix
#define mk_lang_bui_type mk_lang_bi_ulllong_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_ulllong_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name mk_lib_crypto_mode_ctr_be_inl_defd_prefix
#define mk_sl_cui_base_type mk_lang_bi_ulllong_t
#define mk_sl_cui_base_name mk_lang_concat(mk_lang_bui_, mk_lib_crypto_mode_ctr_be_inl_defd_prefix)
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(mk_lib_crypto_mode_ctr_be_inl_defd_msg_len_m * mk_lang_charbit, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn ulllong
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#define ctr_t mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_lib_crypto_mode_ctr_be_inl_defd_prefix), _t)
#define ctr_pt mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_lib_crypto_mode_ctr_be_inl_defd_prefix), _pt)
#define ctr_from_uchars mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_lib_crypto_mode_ctr_be_inl_defd_prefix), _from_buis_uchar_be)
#define ctr_inc mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_lib_crypto_mode_ctr_be_inl_defd_prefix), _inc1)
#define ctr_to_uchars mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_lib_crypto_mode_ctr_be_inl_defd_prefix), _to_buis_uchar_be)


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

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_schedule_crypt(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(ctr_be);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	iv = ctr_be->m_iv;
	mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv);
	mk_lib_crypto_mode_ctr_be_inl_defd_alg_schedule_encrypt(schedule, &iv, &iv);
	for(i = 0; i != mk_lib_crypto_mode_ctr_be_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor3(&iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i], &output->m_data.m_uint8s[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_crypt(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_key_pct const key, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(ctr_be);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	iv = ctr_be->m_iv;
	mk_lib_crypto_mode_ctr_be_inl_defd_increment(&ctr_be->m_iv);
	mk_lib_crypto_mode_ctr_be_inl_defd_alg_encrypt(key, &iv, &iv);
	for(i = 0; i != mk_lib_crypto_mode_ctr_be_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor3(&iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i], &output->m_data.m_uint8s[i]);
	}
}


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_init(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(ctr_be);
	mk_lang_assert(iv);

	ctr_be->m_iv = *iv;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_schedule_encrypt(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_schedule_crypt(ctr_be, schedule, input, output);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_ctr_be_inl_defd_schedule_decrypt(mk_lib_crypto_mode_ctr_be_inl_defd_pt const ctr_be, mk_lib_crypto_mode_ctr_be_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pct const input, mk_lib_crypto_mode_ctr_be_inl_defd_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_be_inl_defd_schedule_crypt(ctr_be, schedule, input, output);
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


#undef ctr_t
#undef ctr_from_uchars
#undef ctr_inc
#undef ctr_to_uchars


#include "mk_lib_crypto_mode_ctr_be_inl_defu.h"


#undef mk_lib_crypto_mode_ctr_be_t_name
#undef mk_lib_crypto_mode_ctr_be_t_alg
