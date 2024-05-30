#include "mk_lib_crypto_alg_tdes3.h"


/* NIST FIPS PUB 46-3 */


#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_des_base.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"

#define mk_lang_memcpy_t_name mk_lib_crypto_alg_tdes3_memcpy_u8
#define mk_lang_memcpy_t_type mk_sl_cui_uint8_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lang_memcpy_t_name mk_lib_crypto_alg_tdes3_memcpy_u64
#define mk_lang_memcpy_t_type mk_sl_cui_uint64_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_tdes3_expand(mk_lib_crypto_alg_tdes3_key_pct const key, mk_lib_crypto_alg_tdes3_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	#if mk_lang_constexpr_is_constant_evaluated
	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lib_crypto_alg_des_base_key_t base_key mk_lang_constexpr_init;
		mk_lib_crypto_alg_des_base_schedule_t base_schedule mk_lang_constexpr_init;

		mk_lib_crypto_alg_tdes3_memcpy_u8_fn(&base_key.m_data.m_uint8s[0], &key->m_data.m_uint8s[0 * mk_lib_crypto_alg_des_base_key_len_v], mk_lib_crypto_alg_des_base_key_len_v);
		mk_lib_crypto_alg_des_base_expand_enc(&base_key, &base_schedule);
		mk_lib_crypto_alg_tdes3_memcpy_u64_fn(&schedule->m_data.m_uint64s[0 * mk_lib_crypto_alg_des_base_nr], &base_schedule.m_data.m_uint64s[0], mk_lib_crypto_alg_des_base_nr);
		mk_lib_crypto_alg_tdes3_memcpy_u8_fn(&base_key.m_data.m_uint8s[0], &key->m_data.m_uint8s[1 * mk_lib_crypto_alg_des_base_key_len_v], mk_lib_crypto_alg_des_base_key_len_v);
		mk_lib_crypto_alg_des_base_expand_dec(&base_key, &base_schedule);
		mk_lib_crypto_alg_tdes3_memcpy_u64_fn(&schedule->m_data.m_uint64s[1 * mk_lib_crypto_alg_des_base_nr], &base_schedule.m_data.m_uint64s[0], mk_lib_crypto_alg_des_base_nr);
		mk_lib_crypto_alg_tdes3_memcpy_u8_fn(&base_key.m_data.m_uint8s[0], &key->m_data.m_uint8s[2 * mk_lib_crypto_alg_des_base_key_len_v], mk_lib_crypto_alg_des_base_key_len_v);
		mk_lib_crypto_alg_des_base_expand_enc(&base_key, &base_schedule);
		mk_lib_crypto_alg_tdes3_memcpy_u64_fn(&schedule->m_data.m_uint64s[2 * mk_lib_crypto_alg_des_base_nr], &base_schedule.m_data.m_uint64s[0], mk_lib_crypto_alg_des_base_nr);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_des_base_expand_enc(((mk_lib_crypto_alg_des_base_key_pct)(&key->m_data.m_uint8s[0 * mk_lib_crypto_alg_des_base_key_len_v])), ((mk_lib_crypto_alg_des_base_schedule_pt)(&schedule->m_data.m_uint64s[0 * mk_lib_crypto_alg_tdes3_nr])));
		mk_lib_crypto_alg_des_base_expand_dec(((mk_lib_crypto_alg_des_base_key_pct)(&key->m_data.m_uint8s[1 * mk_lib_crypto_alg_des_base_key_len_v])), ((mk_lib_crypto_alg_des_base_schedule_pt)(&schedule->m_data.m_uint64s[1 * mk_lib_crypto_alg_tdes3_nr])));
		mk_lib_crypto_alg_des_base_expand_enc(((mk_lib_crypto_alg_des_base_key_pct)(&key->m_data.m_uint8s[2 * mk_lib_crypto_alg_des_base_key_len_v])), ((mk_lib_crypto_alg_des_base_schedule_pt)(&schedule->m_data.m_uint64s[2 * mk_lib_crypto_alg_tdes3_nr])));
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_tdes3_schedule_crypt_one(mk_lib_crypto_alg_tdes3_schedule_pct const schedule, mk_lib_crypto_alg_tdes3_msg_pct const input, mk_lib_crypto_alg_tdes3_msg_pt const output) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);

	#if mk_lang_constexpr_is_constant_evaluated
	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lib_crypto_alg_des_base_msg_t base_msg mk_lang_constexpr_init;
		mk_lib_crypto_alg_des_base_schedule_t base_schedule mk_lang_constexpr_init;

		mk_lib_crypto_alg_tdes3_memcpy_u8_fn(&base_msg.m_data.m_uint8s[0], &input->m_data.m_uint8s[0], mk_lib_crypto_alg_des_base_msg_len_v);
		mk_lib_crypto_alg_tdes3_memcpy_u64_fn(&base_schedule.m_data.m_uint64s[0], &schedule->m_data.m_uint64s[0 * mk_lib_crypto_alg_des_base_nr], mk_lib_crypto_alg_des_base_nr);
		mk_lib_crypto_alg_des_base_schedule_encrypt(&base_schedule, &base_msg, &base_msg, 1);
		mk_lib_crypto_alg_tdes3_memcpy_u64_fn(&base_schedule.m_data.m_uint64s[0], &schedule->m_data.m_uint64s[1 * mk_lib_crypto_alg_des_base_nr], mk_lib_crypto_alg_des_base_nr);
		mk_lib_crypto_alg_des_base_schedule_decrypt(&base_schedule, &base_msg, &base_msg, 1);
		mk_lib_crypto_alg_tdes3_memcpy_u64_fn(&base_schedule.m_data.m_uint64s[0], &schedule->m_data.m_uint64s[2 * mk_lib_crypto_alg_des_base_nr], mk_lib_crypto_alg_des_base_nr);
		mk_lib_crypto_alg_des_base_schedule_encrypt(&base_schedule, &base_msg, &base_msg, 1);
		mk_lib_crypto_alg_tdes3_memcpy_u8_fn(&output->m_data.m_uint8s[0], &base_msg.m_data.m_uint8s[0], mk_lib_crypto_alg_des_base_msg_len_v);
	}
	else
	#endif
	{
		mk_lib_crypto_alg_des_base_schedule_encrypt(((mk_lib_crypto_alg_des_base_schedule_pct)(&schedule->m_data.m_uint64s[0 * mk_lib_crypto_alg_des_base_nr])), ((mk_lib_crypto_alg_des_base_msg_pct)(input)), ((mk_lib_crypto_alg_des_base_msg_pt)(output)), 1);
		mk_lib_crypto_alg_des_base_schedule_decrypt(((mk_lib_crypto_alg_des_base_schedule_pct)(&schedule->m_data.m_uint64s[1 * mk_lib_crypto_alg_des_base_nr])), ((mk_lib_crypto_alg_des_base_msg_pct)(output)), ((mk_lib_crypto_alg_des_base_msg_pt)(output)), 1);
		mk_lib_crypto_alg_des_base_schedule_encrypt(((mk_lib_crypto_alg_des_base_schedule_pct)(&schedule->m_data.m_uint64s[2 * mk_lib_crypto_alg_des_base_nr])), ((mk_lib_crypto_alg_des_base_msg_pct)(output)), ((mk_lib_crypto_alg_des_base_msg_pt)(output)), 1);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_tdes3_schedule_crypt_all(mk_lib_crypto_alg_tdes3_schedule_pct const schedule, mk_lib_crypto_alg_tdes3_msg_pct const input, mk_lib_crypto_alg_tdes3_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_tdes3_msg_len_m);

	n = nblocks;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_alg_tdes3_schedule_crypt_one(schedule, &input[i], &output[i]);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_tdes3_schedule_encrypt(mk_lib_crypto_alg_tdes3_schedule_pct const schedule, mk_lib_crypto_alg_tdes3_msg_pct const input, mk_lib_crypto_alg_tdes3_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_tdes3_msg_len_m);

	mk_lib_crypto_alg_tdes3_schedule_crypt_all(schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_tdes3_schedule_decrypt(mk_lib_crypto_alg_tdes3_schedule_pct const schedule, mk_lib_crypto_alg_tdes3_msg_pct const input, mk_lib_crypto_alg_tdes3_msg_pt const output, mk_lang_types_usize_t const nblocks) mk_lang_noexcept
{
	mk_lang_assert(schedule);
	mk_lang_assert(input);
	mk_lang_assert(output);
	mk_lang_assert(nblocks <= mk_lang_limits_usize_max / mk_lib_crypto_alg_tdes3_msg_len_m);

	mk_lib_crypto_alg_tdes3_schedule_crypt_all(schedule, input, output, nblocks);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_tdes3_expand_enc(mk_lib_crypto_alg_tdes3_key_pct const key, mk_lib_crypto_alg_tdes3_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_lib_crypto_alg_tdes3_expand(key, schedule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_tdes3_expand_dec(mk_lib_crypto_alg_tdes3_key_pct const key, mk_lib_crypto_alg_tdes3_schedule_pt const schedule) mk_lang_noexcept
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(schedule);

	mk_lib_crypto_alg_tdes3_expand(key, schedule);
	for(i = 0; i != 3 * mk_lib_crypto_alg_tdes3_nr / 2; ++i)
	{
		ta = schedule->m_data.m_uint64s[i];
		schedule->m_data.m_uint64s[i] = schedule->m_data.m_uint64s[(3 * mk_lib_crypto_alg_tdes3_nr - 1) - i];
		schedule->m_data.m_uint64s[(3 * mk_lib_crypto_alg_tdes3_nr - 1) - i] = ta;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_tdes3_encrypt(mk_lib_crypto_alg_tdes3_key_pct const key, mk_lib_crypto_alg_tdes3_msg_pct const input, mk_lib_crypto_alg_tdes3_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_tdes3_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_tdes3_expand_enc(key, &schedule);
	mk_lib_crypto_alg_tdes3_schedule_encrypt(&schedule, input, output, 1);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_tdes3_decrypt(mk_lib_crypto_alg_tdes3_key_pct const key, mk_lib_crypto_alg_tdes3_msg_pct const input, mk_lib_crypto_alg_tdes3_msg_pt const output) mk_lang_noexcept
{
	mk_lib_crypto_alg_tdes3_schedule_t schedule mk_lang_constexpr_init;

	mk_lang_assert(key);
	mk_lang_assert(input);
	mk_lang_assert(output);

	mk_lib_crypto_alg_tdes3_expand_dec(key, &schedule);
	mk_lib_crypto_alg_tdes3_schedule_decrypt(&schedule, input, output, 1);
}
