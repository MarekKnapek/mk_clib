#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint128.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_cui_uint_more.h"
#include "mk_sl_uint_convert.h"


#include "mk_lib_crypto_mode_xts_inl_defd.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_xts_inl_defd_prrw_tweak_encrypt(mk_lib_crypto_mode_xts_inl_defd_alg_pt const alg) mk_lang_noexcept
{
	mk_lang_assert(alg);

	mk_lib_crypto_mode_xts_inl_defd_base_schedule_encrypt(&alg->m_schedule.m_sec.m_data.m_base, &alg->m_iv.m_data.m_base, &alg->m_iv.m_data.m_base, 1);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_xts_inl_defd_prrw_tweak_advance(mk_lib_crypto_mode_xts_inl_defd_alg_pt const alg) mk_lang_noexcept
{
#if mk_lib_crypto_mode_xts_inl_defd_msg_len_d == 16
	mk_sl_cui_uint8_t u8 mk_lang_constexpr_init;
	mk_sl_cui_uint128_t u128 mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;

	mk_lang_assert(alg);

	mk_sl_cui_uint8_shr3(&alg->m_iv.m_data.m_base.m_data.m_uint8s[mk_lib_crypto_mode_xts_inl_defd_iv_len_v - 1], mk_lang_charbit - 1, &u8);
	mk_sl_uint_convert_128_8_le_to_big(&u128, &alg->m_iv.m_data.m_base.m_data.m_uint8s[0]);
	mk_sl_cui_uint128_shl2(&u128, 1);
	mk_sl_uint_convert_128_8_le_to_sml(&u128, &alg->m_iv.m_data.m_base.m_data.m_uint8s[0]);
	if(!mk_sl_cui_uint8_is_zero(&u8))
	{
		tsi = 0x87; mk_sl_cui_uint8_from_bi_sint(&u8, &tsi);
		mk_sl_cui_uint8_xor2(&alg->m_iv.m_data.m_base.m_data.m_uint8s[0], &u8);
	}
#else
#error xxxxxxxxxx
#endif
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_xts_inl_defd_rw_set_key_enc(mk_lib_crypto_mode_xts_inl_defd_alg_pt const alg, mk_lib_crypto_mode_xts_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(alg);
	mk_lang_assert(key);

	mk_lib_crypto_mode_xts_inl_defd_base_expand_enc(&key->m_pri.m_data.m_base, &alg->m_schedule.m_pri.m_data.m_base);
	mk_lib_crypto_mode_xts_inl_defd_base_expand_enc(&key->m_sec.m_data.m_base, &alg->m_schedule.m_sec.m_data.m_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_xts_inl_defd_rw_set_key_dec(mk_lib_crypto_mode_xts_inl_defd_alg_pt const alg, mk_lib_crypto_mode_xts_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(alg);
	mk_lang_assert(key);

	mk_lib_crypto_mode_xts_inl_defd_base_expand_dec(&key->m_pri.m_data.m_base, &alg->m_schedule.m_pri.m_data.m_base);
	mk_lib_crypto_mode_xts_inl_defd_base_expand_dec(&key->m_sec.m_data.m_base, &alg->m_schedule.m_sec.m_data.m_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_xts_inl_defd_rw_set_iv(mk_lib_crypto_mode_xts_inl_defd_alg_pt const alg, mk_lib_crypto_mode_xts_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(alg);
	mk_lang_assert(iv);

	alg->m_iv = *iv;
	mk_lib_crypto_mode_xts_inl_defd_prrw_tweak_encrypt(alg);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_xts_inl_defd_rw_encrypt(mk_lib_crypto_mode_xts_inl_defd_alg_pt const alg, mk_lib_crypto_mode_xts_inl_defd_msg_pct const inputs, mk_lib_crypto_mode_xts_inl_defd_msg_pt const outputs, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_inl_defd_base_msg_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(alg);
	mk_lang_assert(inputs || count == 0);
	mk_lang_assert(outputs || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_mode_xts_inl_defd_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_mode_xts_inl_defd_xor_3(&alg->m_iv.m_data.m_base.m_data.m_uint8s[0], &inputs[i].m_data.m_base.m_data.m_uint8s[0], &tmp.m_data.m_uint8s[0]);
		mk_lib_crypto_mode_xts_inl_defd_base_schedule_encrypt(&alg->m_schedule.m_pri.m_data.m_base, &tmp, &tmp, 1);
		mk_lib_crypto_mode_xts_inl_defd_xor_3(&alg->m_iv.m_data.m_base.m_data.m_uint8s[0], &tmp.m_data.m_uint8s[0], &outputs[i].m_data.m_base.m_data.m_uint8s[0]);
		mk_lib_crypto_mode_xts_inl_defd_prrw_tweak_advance(alg);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_xts_inl_defd_rw_decrypt(mk_lib_crypto_mode_xts_inl_defd_alg_pt const alg, mk_lib_crypto_mode_xts_inl_defd_msg_pct const inputs, mk_lib_crypto_mode_xts_inl_defd_msg_pt const outputs, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_mode_xts_inl_defd_base_msg_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(alg);
	mk_lang_assert(inputs || count == 0);
	mk_lang_assert(outputs || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_mode_xts_inl_defd_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_mode_xts_inl_defd_xor_3(&alg->m_iv.m_data.m_base.m_data.m_uint8s[0], &inputs[i].m_data.m_base.m_data.m_uint8s[0], &tmp.m_data.m_uint8s[0]);
		mk_lib_crypto_mode_xts_inl_defd_base_schedule_decrypt(&alg->m_schedule.m_pri.m_data.m_base, &tmp, &tmp, 1);
		mk_lib_crypto_mode_xts_inl_defd_xor_3(&alg->m_iv.m_data.m_base.m_data.m_uint8s[0], &tmp.m_data.m_uint8s[0], &outputs[i].m_data.m_base.m_data.m_uint8s[0]);
		mk_lib_crypto_mode_xts_inl_defd_prrw_tweak_advance(alg);
	}
}


#include "mk_lib_crypto_mode_xts_inl_defu.h"
