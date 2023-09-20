#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_cfb_inl_defd.h"


#define mk_lib_crypto_mode_base_t_name mk_lib_crypto_mode_cfb_inl_defd_prefix
#define mk_lib_crypto_mode_base_t_len mk_lib_crypto_mode_cfb_inl_defd_msg_len_m
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"
#define mk_lib_crypto_mode_base_xor3 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_base_, mk_lib_crypto_mode_cfb_inl_defd_prefix), _xor3)
#define mk_lib_crypto_mode_base_xor2 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_base_, mk_lib_crypto_mode_cfb_inl_defd_prefix), _xor2)


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_init(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lib_crypto_mode_cfb_inl_defd_sbits >= 1 && mk_lib_crypto_mode_cfb_inl_defd_sbits <= mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m * mk_lang_charbit);
	mk_lang_static_assert(mk_lib_crypto_mode_cfb_inl_defd_sbits % mk_lang_charbit == 0);

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
	mk_lib_crypto_mode_base_xor2(&cfb->m_iv.m_data.m_uint8s[0], &input->m_data.m_uint8s[0]);
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
	mk_lib_crypto_mode_base_xor2(&msg.m_data.m_uint8s[0], &iv.m_data.m_uint8s[0]);
	for(i = 0; i != ((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v)); ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v))) + i] = msg.m_data.m_uint8s[i]; }
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
	mk_lib_crypto_mode_base_xor3(&cfb->m_iv.m_data.m_uint8s[0], &input->m_data.m_uint8s[0], &output->m_data.m_uint8s[0]);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[i] = msg.m_data.m_uint8s[i]; }
#else
	mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	iv = cfb->m_iv;
	for(i = 0; i != ((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v)); ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v))) + i] = input->m_data.m_uint8s[i]; }
	mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_encrypt(schedule, &iv, &iv);
	mk_lib_crypto_mode_base_xor3(&iv.m_data.m_uint8s[0], &input->m_data.m_uint8s[0], &output->m_data.m_uint8s[0]);
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
	mk_lib_crypto_mode_base_xor2(&cfb->m_iv.m_data.m_uint8s[0], &input->m_data.m_uint8s[0]);
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
	mk_lib_crypto_mode_base_xor2(&msg.m_data.m_uint8s[0], &iv.m_data.m_uint8s[0]);
	for(i = 0; i != ((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v)); ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v))) + i] = msg.m_data.m_uint8s[i]; }
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
	mk_lib_crypto_mode_base_xor3(&cfb->m_iv.m_data.m_uint8s[0], &input->m_data.m_uint8s[0], &output->m_data.m_uint8s[0]);
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[i] = msg.m_data.m_uint8s[i]; }
#else
	mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	iv = cfb->m_iv;
	for(i = 0; i != ((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v)); ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
	for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v))) + i] = input->m_data.m_uint8s[i]; }
	mk_lib_crypto_mode_cfb_inl_defd_alg_encrypt(key, &iv, &iv);
	mk_lib_crypto_mode_base_xor3(&iv.m_data.m_uint8s[0], &input->m_data.m_uint8s[0], &output->m_data.m_uint8s[0]);
#endif
}


#undef mk_lib_crypto_mode_base_xor3
#undef mk_lib_crypto_mode_base_xor2


#include "mk_lib_crypto_mode_cfb_inl_defu.h"


#undef mk_lib_crypto_mode_cfb_t_name
#undef mk_lib_crypto_mode_cfb_t_sbits
#undef mk_lib_crypto_mode_cfb_t_alg
