#include "mk_lib_crypto_alg_aes_portable_192.h"


/* NIST FIPS PUB 197 */


#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_aes_192.h"
#include "mk_lib_crypto_alg_aes_portable_base.h"
#include "mk_sl_uint8.h"

#define mk_lang_memcpy_t_name mk_lib_crypto_alg_aes_portable_192_memcpy_u8
#define mk_lang_memcpy_t_type mk_sl_cui_uint8_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"


#define mk_lib_crypto_alg_aes_portable_192_word_bits 32
#define mk_lib_crypto_alg_aes_portable_192_word_bytes (mk_lib_crypto_alg_aes_portable_192_word_bits  / mk_lang_charbit)
#define mk_lib_crypto_alg_aes_portable_192_key_words (mk_lib_crypto_alg_aes_portable_192_key_len_m / mk_lib_crypto_alg_aes_portable_192_word_bytes)
#define mk_lib_crypto_alg_aes_portable_192_msg_words (mk_lib_crypto_alg_aes_portable_192_msg_len_m / mk_lib_crypto_alg_aes_portable_192_word_bytes)


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_sub_bytes_enc(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
	mk_lib_crypto_alg_aes_portable_base_sub_bytes_enc(&msg, &msg);
	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_sub_bytes_dec(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
	mk_lib_crypto_alg_aes_portable_base_sub_bytes_dec(&msg, &msg);
	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_shift_rows_enc(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
	mk_lib_crypto_alg_aes_portable_base_shift_rows_enc(&msg, &msg);
	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_shift_rows_dec(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
	mk_lib_crypto_alg_aes_portable_base_shift_rows_dec(&msg, &msg);
	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_mix_columns_enc(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
	mk_lib_crypto_alg_aes_portable_base_mix_columns_enc(&msg, &msg);
	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_mix_columns_dec(mk_lib_crypto_alg_aes_portable_192_msg_pct const a, mk_lib_crypto_alg_aes_portable_192_msg_pt const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t msg mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&msg.m_data.m_uint8s[0], &a->m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
	mk_lib_crypto_alg_aes_portable_base_mix_columns_dec(&msg, &msg);
	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&b->m_data.m_uint8s[0], &msg.m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_add_key2(mk_lib_crypto_alg_aes_portable_192_msg_pt const a, mk_lib_crypto_alg_aes_portable_192_msg_pct const b) mk_lang_noexcept
{
	mk_lib_crypto_alg_aes_portable_base_msg_t aa mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_portable_base_msg_t bb mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_base_msg_len_v)) == ((mk_lang_types_sint_t)(mk_lib_crypto_alg_aes_portable_192_msg_len_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&aa.m_data.m_uint8s[0], &a->m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&bb.m_data.m_uint8s[0], &b->m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
	mk_lib_crypto_alg_aes_portable_base_add_key2(&aa, &bb);
	mk_lib_crypto_alg_aes_portable_192_memcpy_u8_fn(&a->m_data.m_uint8s[0], &aa.m_data.m_uint8s[0], mk_lib_crypto_alg_aes_portable_192_msg_len_v);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_expand(mk_lib_crypto_alg_aes_portable_192_key_pct const key, mk_lib_crypto_alg_aes_portable_192_schedule_pt const schedule) mk_lang_noexcept
{
	#define get_outer(x) ((x) / mk_lib_crypto_alg_aes_portable_base_msg_len_v)
	#define get_inner(x) ((x) % mk_lib_crypto_alg_aes_portable_base_msg_len_v)

	mk_sl_cui_uint8_t rcon mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t idx_prev mk_lang_constexpr_init;
	mk_lang_types_sint_t j mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_portable_base_word_t tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t idx_curr mk_lang_constexpr_init;
	mk_lang_types_sint_t idx_oldd mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_sl_cui_uint8_set_one(&rcon);
	for(i = 0; i != mk_lib_crypto_alg_aes_portable_192_key_len_v; ++i)
	{
		schedule->m_data.m_msgs[get_outer(i)].m_data.m_uint8s[get_inner(i)] = key->m_data.m_uint8s[i];
	}
	for(i = mk_lib_crypto_alg_aes_portable_192_key_words; i != (mk_lib_crypto_alg_aes_portable_192_nr + 1) * mk_lib_crypto_alg_aes_portable_base_msg_words; ++i)
	{
		idx_prev = (i - 1) * mk_lib_crypto_alg_aes_portable_192_word_bytes;
		for(j = 0; j != mk_lib_crypto_alg_aes_portable_192_word_bytes; ++j)
		{
			tmp.m_data.m_uint8s[j] = schedule->m_data.m_msgs[get_outer(idx_prev + j)].m_data.m_uint8s[get_inner(idx_prev + j)];
		}
		if(i % mk_lib_crypto_alg_aes_portable_192_key_words == 0)
		{
			mk_lib_crypto_alg_aes_portable_base_rot_word(&tmp, &tmp);
			mk_lib_crypto_alg_aes_portable_base_sub_word(&tmp, &tmp);
			mk_lib_crypto_alg_aes_portable_base_xor_word(&tmp, &rcon, &tmp, &rcon);
		}
		idx_curr = i * mk_lib_crypto_alg_aes_portable_192_word_bytes;
		idx_oldd = (i - mk_lib_crypto_alg_aes_portable_192_key_words) * mk_lib_crypto_alg_aes_portable_192_word_bytes;
		for(j = 0; j != mk_lib_crypto_alg_aes_portable_192_word_bytes; ++j)
		{
			mk_sl_cui_uint8_xor3(&tmp.m_data.m_uint8s[j], &schedule->m_data.m_msgs[get_outer(idx_oldd + j)].m_data.m_uint8s[get_inner(idx_oldd + j)], &schedule->m_data.m_msgs[get_outer(idx_curr + j)].m_data.m_uint8s[get_inner(idx_curr + j)]);
		}
	}

	#undef get_outer
	#undef get_inner
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_schedule_encrypt(mk_lib_crypto_alg_aes_portable_192_schedule_pct const schedule, mk_lib_crypto_alg_aes_portable_192_msg_pct const input, mk_lib_crypto_alg_aes_portable_192_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_portable_192_msg_t state mk_lang_constexpr_init;
	mk_lang_types_sint_t ir mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		state = input[iblock];
		mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_msgs[0]);
		for(ir = 0; ir != mk_lib_crypto_alg_aes_portable_192_nr - 1; ++ir)
		{
			mk_lib_crypto_alg_aes_portable_192_sub_bytes_enc(&state, &state);
			mk_lib_crypto_alg_aes_portable_192_shift_rows_enc(&state, &state);
			mk_lib_crypto_alg_aes_portable_192_mix_columns_enc(&state, &state);
			mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_msgs[ir + 1]);
		}
		mk_lib_crypto_alg_aes_portable_192_sub_bytes_enc(&state, &state);
		mk_lib_crypto_alg_aes_portable_192_shift_rows_enc(&state, &state);
		mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_msgs[mk_lib_crypto_alg_aes_portable_192_nr]);
		output[iblock] = state;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_aes_portable_192_schedule_decrypt(mk_lib_crypto_alg_aes_portable_192_schedule_pct const schedule, mk_lib_crypto_alg_aes_portable_192_msg_pct const input, mk_lib_crypto_alg_aes_portable_192_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t iblock mk_lang_constexpr_init;
	mk_lib_crypto_alg_aes_portable_192_msg_t state mk_lang_constexpr_init;
	mk_lang_types_sint_t ir mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	for(iblock = 0; iblock != nblocks; ++iblock)
	{
		state = input[iblock];
		mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_msgs[mk_lib_crypto_alg_aes_portable_192_nr]);
		for(ir = 0; ir != mk_lib_crypto_alg_aes_portable_192_nr - 1; ++ir)
		{
			mk_lib_crypto_alg_aes_portable_192_shift_rows_dec(&state, &state);
			mk_lib_crypto_alg_aes_portable_192_sub_bytes_dec(&state, &state);
			mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_msgs[(mk_lib_crypto_alg_aes_portable_192_nr - 1) - ir]);
			mk_lib_crypto_alg_aes_portable_192_mix_columns_dec(&state, &state);
		}
		mk_lib_crypto_alg_aes_portable_192_shift_rows_dec(&state, &state);
		mk_lib_crypto_alg_aes_portable_192_sub_bytes_dec(&state, &state);
		mk_lib_crypto_alg_aes_portable_192_add_key2(&state, &schedule->m_data.m_msgs[0]);
		output[iblock] = state;
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
