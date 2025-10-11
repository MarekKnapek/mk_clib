#ifndef mk_include_guard_mk_lib_crypto_alg_aes_portable_192_c
#define mk_include_guard_mk_lib_crypto_alg_aes_portable_192_c
#include "mk_lib_crypto_alg_aes_portable_192.h"

/* NIST FIPS PUB 197 */

#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_aes_portable_base.h"
#include "mk_lib_crypto_bitops_bulk.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_crypto_alg_aes_portable_192_word_bits_d 32
#define mk_lib_crypto_alg_aes_portable_192_word_bytes_d (mk_lib_crypto_alg_aes_portable_192_word_bits_d / mk_lang_charbit)
#define mk_lib_crypto_alg_aes_portable_192_key_words_d (mk_lib_crypto_alg_aes_portable_192_key_len_d / mk_lib_crypto_alg_aes_portable_192_word_bytes_d)
#define mk_lib_crypto_alg_aes_portable_192_msg_words_d (mk_lib_crypto_alg_aes_portable_192_msg_len_d / mk_lib_crypto_alg_aes_portable_192_word_bytes_d)
enum mk_lib_crypto_alg_aes_portable_192_key_words_e{ mk_lib_crypto_alg_aes_portable_192_key_words_v = mk_lib_crypto_alg_aes_portable_192_key_words_d }; typedef enum mk_lib_crypto_alg_aes_portable_192_key_words_e mk_lib_crypto_alg_aes_portable_192_key_words_t;
enum mk_lib_crypto_alg_aes_portable_192_word_bytes_e{ mk_lib_crypto_alg_aes_portable_192_word_bytes_v = mk_lib_crypto_alg_aes_portable_192_word_bytes_d }; typedef enum mk_lib_crypto_alg_aes_portable_192_word_bytes_e mk_lib_crypto_alg_aes_portable_192_word_bytes_t;


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_sub_bytes_enc(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0]);
	mk_lib_crypto_alg_aes_portable_base_sub_bytes_enc(&msg, &msg);
	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_sub_bytes_dec(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0]);
	mk_lib_crypto_alg_aes_portable_base_sub_bytes_dec(&msg, &msg);
	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_shift_rows_enc(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0]);
	mk_lib_crypto_alg_aes_portable_base_shift_rows_enc(&msg, &msg);
	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_shift_rows_dec(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0]);
	mk_lib_crypto_alg_aes_portable_base_shift_rows_dec(&msg, &msg);
	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_mix_columns_enc(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0]);
	mk_lib_crypto_alg_aes_portable_base_mix_columns_enc(&msg, &msg);
	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_mix_columns_dec(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0]);
	mk_lib_crypto_alg_aes_portable_base_mix_columns_dec(&msg, &msg);
	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_add_key2(mk_lib_crypto_alg_aes_portable_192_msg_pt const a, mk_lang_static_param(mk_sl_cui_uint8_ct, b, mk_lib_crypto_alg_aes_portable_192_msg_len_v)) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t aa mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_portable_base_msg_t bb mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&aa.m_data.m_uint8s[0], &a->m_data.m_uint8s[0]);
	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&bb.m_data.m_uint8s[0], &b[0]);
	mk_lib_crypto_alg_aes_portable_base_add_key2(&aa, &bb);
	mk_lib_crypto_bitops_bulk_uint8_16_memcpy(&a->m_data.m_uint8s[0], &aa.m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_expand(mk_lib_crypto_alg_aes_portable_192_key_pct const key, mk_lib_crypto_alg_aes_portable_192_schedule_pt const schedule) mk_lang_noexcept
{
	mk_sl_cui_uint8_t r_con mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t idx_prev mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_portable_base_word_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t idx_curr mk_lang_constexpr_init;
	mk_lang_types_sint_t idx_old mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_sl_cui_uint8_set_one(&r_con);
	mk_lib_crypto_bitops_bulk_uint8_24_memcpy(&schedule->m_data.m_uint8s[0], &key->m_data.m_uint8s[0]);
	for(i = 1 * mk_lib_crypto_alg_aes_portable_192_key_words_v; i != (mk_lib_crypto_alg_aes_portable_192_nr + 1) * mk_lib_crypto_alg_aes_portable_base_msg_words_v; ++i)
	{
		idx_prev = (i - 1) * mk_lib_crypto_alg_aes_portable_192_word_bytes_v;
		mk_lib_crypto_bitops_bulk_uint8_4_memcpy(&tmp.m_data.m_uint8s[0], &schedule->m_data.m_uint8s[idx_prev]);
		if(i % mk_lib_crypto_alg_aes_portable_192_key_words_v == 0)
		{
			mk_lib_crypto_alg_aes_portable_base_rot_word(&tmp, &tmp);
			mk_lib_crypto_alg_aes_portable_base_sub_word(&tmp, &tmp);
			mk_lib_crypto_alg_aes_portable_base_xor_word(&tmp, &r_con, &tmp, &r_con);
		}
		idx_curr = i * mk_lib_crypto_alg_aes_portable_192_word_bytes_v;
		idx_old = (i - mk_lib_crypto_alg_aes_portable_192_key_words_v) * mk_lib_crypto_alg_aes_portable_192_word_bytes_v;
		mk_lib_crypto_bitops_bulk_uint8_4_xor3(&tmp.m_data.m_uint8s[0], &schedule->m_data.m_uint8s[idx_old], &schedule->m_data.m_uint8s[idx_curr]);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_schedule_encrypt(mk_lib_crypto_alg_aes_portable_192_schedule_pct const schedule, mk_lib_crypto_alg_aes_portable_192_msg_pct const input, mk_lib_crypto_alg_aes_portable_192_msg_pt const output, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_portable_192_msg_t state mk_lang_constexpr_init;
	mk_lang_types_sint_t ir mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(count >= 0 && count <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_portable_192_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		state = input[i];
		mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_uint8s[0 * mk_lib_crypto_alg_aes_portable_192_msg_len_v]);
		for(ir = 0; ir != mk_lib_crypto_alg_aes_portable_192_nr - 1; ++ir)
		{
			mk_lib_crypto_alg_aes_portable_192_sub_bytes_enc(&state, &state);
			mk_lib_crypto_alg_aes_portable_192_shift_rows_enc(&state, &state);
			mk_lib_crypto_alg_aes_portable_192_mix_columns_enc(&state, &state);
			mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_uint8s[(ir + 1) * mk_lib_crypto_alg_aes_portable_192_msg_len_v]);
		}
		mk_lib_crypto_alg_aes_portable_192_sub_bytes_enc(&state, &state);
		mk_lib_crypto_alg_aes_portable_192_shift_rows_enc(&state, &state);
		mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_uint8s[mk_lib_crypto_alg_aes_portable_192_nr * mk_lib_crypto_alg_aes_portable_192_msg_len_v]);
		output[i] = state;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_schedule_decrypt(mk_lib_crypto_alg_aes_portable_192_schedule_pct const schedule, mk_lib_crypto_alg_aes_portable_192_msg_pct const input, mk_lib_crypto_alg_aes_portable_192_msg_pt const output, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_portable_192_msg_t state mk_lang_constexpr_init;
	mk_lang_types_sint_t ir mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(count >= 0 && count <= mk_lang_limits_usize_max / mk_lib_crypto_alg_aes_portable_192_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		state = input[i];
		mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_uint8s[mk_lib_crypto_alg_aes_portable_192_nr * mk_lib_crypto_alg_aes_portable_192_msg_len_v]);
		for(ir = 0; ir != mk_lib_crypto_alg_aes_portable_192_nr - 1; ++ir)
		{
			mk_lib_crypto_alg_aes_portable_192_shift_rows_dec(&state, &state);
			mk_lib_crypto_alg_aes_portable_192_sub_bytes_dec(&state, &state);
			mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_uint8s[((mk_lib_crypto_alg_aes_portable_192_nr - 1) - ir) * mk_lib_crypto_alg_aes_portable_192_msg_len_v]);
			mk_lib_crypto_alg_aes_portable_192_mix_columns_dec(&state, &state);
		}
		mk_lib_crypto_alg_aes_portable_192_shift_rows_dec(&state, &state);
		mk_lib_crypto_alg_aes_portable_192_sub_bytes_dec(&state, &state);
		mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_uint8s[0 * mk_lib_crypto_alg_aes_portable_192_msg_len_v]);
		output[i] = state;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_expand_enc(mk_lib_crypto_alg_aes_portable_192_key_pct const key, mk_lib_crypto_alg_aes_portable_192_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_lib_crypto_alg_aes_portable_192_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_expand_dec(mk_lib_crypto_alg_aes_portable_192_key_pct const key, mk_lib_crypto_alg_aes_portable_192_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_lib_crypto_alg_aes_portable_192_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_encrypt(mk_lib_crypto_alg_aes_portable_192_key_pct const key, mk_lib_crypto_alg_aes_portable_192_msg_pct const input, mk_lib_crypto_alg_aes_portable_192_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_192_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_aes_portable_192_expand_enc(key, &schedule);
	mk_lib_crypto_alg_aes_portable_192_schedule_encrypt(&schedule, input, output, 1);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_decrypt(mk_lib_crypto_alg_aes_portable_192_key_pct const key, mk_lib_crypto_alg_aes_portable_192_msg_pct const input, mk_lib_crypto_alg_aes_portable_192_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_192_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_aes_portable_192_expand_dec(key, &schedule);
	mk_lib_crypto_alg_aes_portable_192_schedule_decrypt(&schedule, input, output, 1);
}


#endif
