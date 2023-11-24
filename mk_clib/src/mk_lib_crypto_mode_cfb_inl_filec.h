#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


/* NIST SP 800-38A */


#include "mk_lib_crypto_mode_cfb_inl_defd.h"


#define mk_lib_crypto_mode_base_t_name mk_lang_concat(mk_lib_crypto_mode_cfb_inl_defd_prefix, _mode_base)
#define mk_lib_crypto_mode_base_t_len mk_lib_crypto_mode_cfb_inl_defd_msg_len_m
#include "mk_lib_crypto_mode_base_inl_fileh.h"
#include "mk_lib_crypto_mode_base_inl_filec.h"
#define mk_lib_crypto_mode_base_xor3 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_cfb_inl_defd_prefix, _mode_base), _xor3)
#define mk_lib_crypto_mode_base_xor2 mk_lang_concat(mk_lang_concat(mk_lib_crypto_mode_cfb_inl_defd_prefix, _mode_base), _xor2)


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_init(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lib_crypto_mode_cfb_inl_defd_sbits >= 1 && mk_lib_crypto_mode_cfb_inl_defd_sbits <= mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m * mk_lang_charbit);
	mk_lang_static_assert(mk_lib_crypto_mode_cfb_inl_defd_sbits % mk_lang_charbit == 0);

	mk_lang_assert(cfb);
	mk_lang_assert(iv);

	cfb->m_iv = *iv;
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_schedule_encrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
#if(mk_lib_crypto_mode_cfb_inl_defd_msg_len_m == mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m)
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_encrypt(schedule, &cfb->m_iv, &cfb->m_iv, 1);
		mk_lib_crypto_mode_base_xor2(&cfb->m_iv.m_data.m_uint8s[0], &input[iblock].m_data.m_uint8s[0]);
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ output[iblock].m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i]; }
	}
#else
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_inl_defd_msg_t msg mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		msg = input[iblock];
		iv = cfb->m_iv;
		mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_encrypt(schedule, &iv, &iv, 1);
		mk_lib_crypto_mode_base_xor2(&msg.m_data.m_uint8s[0], &iv.m_data.m_uint8s[0]);
		for(i = 0; i != ((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v)); ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v))) + i] = msg.m_data.m_uint8s[i]; }
		output[iblock] = msg;
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_cfb_inl_defd_schedule_decrypt(mk_lib_crypto_mode_cfb_inl_defd_pt const cfb, mk_lib_crypto_mode_cfb_inl_defd_schedule_pct const schedule, mk_lib_crypto_mode_cfb_inl_defd_msg_pct const input, mk_lib_crypto_mode_cfb_inl_defd_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
#if(mk_lib_crypto_mode_cfb_inl_defd_msg_len_m == mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_m)
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lang_alignas(64) mk_lib_crypto_mode_cfb_inl_defd_iv_t msg[16 + 1] mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != (nblocks / 16) * 16; iblock += 16)
	{
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[ 0].m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[ 1].m_data.m_uint8s[i] = input[iblock +  0].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[ 2].m_data.m_uint8s[i] = input[iblock +  1].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[ 3].m_data.m_uint8s[i] = input[iblock +  2].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[ 4].m_data.m_uint8s[i] = input[iblock +  3].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[ 5].m_data.m_uint8s[i] = input[iblock +  4].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[ 6].m_data.m_uint8s[i] = input[iblock +  5].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[ 7].m_data.m_uint8s[i] = input[iblock +  6].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[ 8].m_data.m_uint8s[i] = input[iblock +  7].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[ 9].m_data.m_uint8s[i] = input[iblock +  8].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[10].m_data.m_uint8s[i] = input[iblock +  9].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[11].m_data.m_uint8s[i] = input[iblock + 10].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[12].m_data.m_uint8s[i] = input[iblock + 11].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[13].m_data.m_uint8s[i] = input[iblock + 12].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[14].m_data.m_uint8s[i] = input[iblock + 13].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[15].m_data.m_uint8s[i] = input[iblock + 14].m_data.m_uint8s[i]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[16].m_data.m_uint8s[i] = input[iblock + 15].m_data.m_uint8s[i]; }
		mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_encrypt(schedule, &msg[0], &msg[0], 16);
		mk_lib_crypto_mode_base_xor3(&msg[ 0].m_data.m_uint8s[0], &input[iblock +  0].m_data.m_uint8s[0], &output[iblock +  0].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[ 1].m_data.m_uint8s[0], &input[iblock +  1].m_data.m_uint8s[0], &output[iblock +  1].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[ 2].m_data.m_uint8s[0], &input[iblock +  2].m_data.m_uint8s[0], &output[iblock +  2].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[ 3].m_data.m_uint8s[0], &input[iblock +  3].m_data.m_uint8s[0], &output[iblock +  3].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[ 4].m_data.m_uint8s[0], &input[iblock +  4].m_data.m_uint8s[0], &output[iblock +  4].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[ 5].m_data.m_uint8s[0], &input[iblock +  5].m_data.m_uint8s[0], &output[iblock +  5].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[ 6].m_data.m_uint8s[0], &input[iblock +  6].m_data.m_uint8s[0], &output[iblock +  6].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[ 7].m_data.m_uint8s[0], &input[iblock +  7].m_data.m_uint8s[0], &output[iblock +  7].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[ 8].m_data.m_uint8s[0], &input[iblock +  8].m_data.m_uint8s[0], &output[iblock +  8].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[ 9].m_data.m_uint8s[0], &input[iblock +  9].m_data.m_uint8s[0], &output[iblock +  9].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[10].m_data.m_uint8s[0], &input[iblock + 10].m_data.m_uint8s[0], &output[iblock + 10].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[11].m_data.m_uint8s[0], &input[iblock + 11].m_data.m_uint8s[0], &output[iblock + 11].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[12].m_data.m_uint8s[0], &input[iblock + 12].m_data.m_uint8s[0], &output[iblock + 12].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[13].m_data.m_uint8s[0], &input[iblock + 13].m_data.m_uint8s[0], &output[iblock + 13].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[14].m_data.m_uint8s[0], &input[iblock + 14].m_data.m_uint8s[0], &output[iblock + 14].m_data.m_uint8s[0]);
		mk_lib_crypto_mode_base_xor3(&msg[15].m_data.m_uint8s[0], &input[iblock + 15].m_data.m_uint8s[0], &output[iblock + 15].m_data.m_uint8s[0]);
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[i] = msg[16].m_data.m_uint8s[i]; }
	}
	for(; iblock != nblocks; ++iblock)
	{
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ msg[0].m_data.m_uint8s[i] = input[iblock].m_data.m_uint8s[i]; }
		mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_encrypt(schedule, &cfb->m_iv, &cfb->m_iv, 1);
		mk_lib_crypto_mode_base_xor3(&cfb->m_iv.m_data.m_uint8s[0], &input[iblock].m_data.m_uint8s[0], &output[iblock].m_data.m_uint8s[0]);
		cfb->m_iv = msg[0];
	}
#else
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lib_crypto_mode_cfb_inl_defd_alg_msg_t iv mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(cfb);
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		iv = cfb->m_iv;
		for(i = 0; i != ((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v)); ++i){ cfb->m_iv.m_data.m_uint8s[i] = cfb->m_iv.m_data.m_uint8s[i + mk_lib_crypto_mode_cfb_inl_defd_msg_len_v]; }
		for(i = 0; i != mk_lib_crypto_mode_cfb_inl_defd_msg_len_v; ++i){ cfb->m_iv.m_data.m_uint8s[(((int)(mk_lib_crypto_mode_cfb_inl_defd_alg_msg_len_v)) - ((int)(mk_lib_crypto_mode_cfb_inl_defd_msg_len_v))) + i] = input[iblock].m_data.m_uint8s[i]; }
		mk_lib_crypto_mode_cfb_inl_defd_alg_schedule_encrypt(schedule, &iv, &iv, 1);
		mk_lib_crypto_mode_base_xor3(&iv.m_data.m_uint8s[0], &input[iblock].m_data.m_uint8s[0], &output[iblock].m_data.m_uint8s[0]);
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
