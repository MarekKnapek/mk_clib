#include "mk_lang_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_cfb_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_init(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(cfb);
	mk_lang_assert(iv);

	cfb->m_iv = *iv;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_schedule_encrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output) mk_lang_noexcept
{
#if(mk_lib_crypto_mode_cfb_inl_defd_msg_len_m == mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m)
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_encrypt(schedule, &cfb->m_iv, &cfb->m_iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor2(&cfb->m_iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i]);
	}
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ output->m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i]; }
#else
	mk_lib_crypto_mode_cfb_inl_defd_msg_t msg mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	msg = *input;
	iv = cfb->m_iv;
	mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_encrypt(schedule, &iv, &iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor2(&msg.m_data.m_uint8s[i], &iv.m_data.m_uint8s[i]);
	}
	for(i = 0; i != ((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v)); ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v - mk_lib_crypto_mode_cfb_inl_defd_msg_len_v) + i] = msg.m_data.m_uint8s[i]; }
	*output = msg;
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_schedule_decrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output) mk_lang_noexcept
{
#if(mk_lib_crypto_mode_cfb_inl_defd_msg_len_m == mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m)
	mk_lib_crypto_mode_cfb_inl_defd_msg_t msg mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	msg = *input;
	mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_encrypt(schedule, &cfb->m_iv, &cfb->m_iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor3(&cfb->m_iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i], &output->m_data.m_uint8s[i]);
	}
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[i] = msg.m_data.m_uint8s[i]; }
#else
	mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	iv = cfb->m_iv;
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v - mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v - mk_lib_crypto_mode_cfb_inl_defd_msg_len_v) + i] = input->m_data.m_uint8s[i]; }
	mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_encrypt(schedule, &iv, &iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor3(&iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i], &output->m_data.m_uint8s[i]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_expand_enc(mk_lib_crypto_mode_cfb_inl_defd_key_pct const key, mk_lib_crypto_mode_cfb_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_mode_cfb_inl_defd_alg_expand_enc(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_expand_dec(mk_lib_crypto_mode_cfb_inl_defd_key_pct const key, mk_lib_crypto_mode_cfb_inl_defd_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lib_crypto_mode_cfb_inl_defd_alg_expand_enc(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_encrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_key_pct const key, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output) mk_lang_noexcept
{
#if(mk_lib_crypto_mode_cfb_inl_defd_msg_len_m == mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m)
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_mode_cfb_inl_defd_alg_encrypt(key, &cfb->m_iv, &cfb->m_iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor2(&cfb->m_iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i]);
	}
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ output->m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i]; }
#else
	mk_lib_crypto_mode_cfb_inl_defd_msg_t msg mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	msg = *input;
	iv = cfb->m_iv;
	mk_lib_crypto_mode_cfb_inl_defd_alg_encrypt(key, &iv, &iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor2(&msg.m_data.m_uint8s[i], &iv.m_data.m_uint8s[i]);
	}
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v - mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v - mk_lib_crypto_mode_cfb_inl_defd_msg_len_v) + i] = msg.m_data.m_uint8s[i]; }
	*output = msg;
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_decrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_key_pct const key, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output) mk_lang_noexcept
{
#if(mk_lib_crypto_mode_cfb_inl_defd_msg_len_m == mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m)
	mk_lib_crypto_mode_cfb_inl_defd_msg_t msg mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	msg = *input;
	mk_lib_crypto_mode_cfb_inl_defd_alg_encrypt(key, &cfb->m_iv, &cfb->m_iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor3(&cfb->m_iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i], &output->m_data.m_uint8s[i]);
	}
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[i] = msg.m_data.m_uint8s[i]; }
#else
	mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	iv = cfb->m_iv;
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v - mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v - mk_lib_crypto_mode_cfb_inl_defd_msg_len_v) + i] = input->m_data.m_uint8s[i]; }
	mk_lib_crypto_mode_cfb_inl_defd_alg_encrypt(key, &iv, &iv);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i)
	{
		mk_sl_cui_uint8_xor3(&iv.m_data.m_uint8s[i], &input->m_data.m_uint8s[i], &output->m_data.m_uint8s[i]);
	}
#endif
}


#include "mk_lib_crypto_mode_cfb_inl_defu.h"


#undef mk_lib_crypto_mode_cfb_t_name
#undef mk_lib_crypto_mode_cfb_t_sbits
#undef mk_lib_crypto_mode_cfb_t_alg
