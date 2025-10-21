#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


#include "mk_lib_crypto_mode_ecb_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_ecb_inl_defd_rw_set_iv(mk_lib_crypto_mode_ecb_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ecb_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(alg);
	mk_lang_assert(iv || !iv);

	((mk_lang_types_void_t)(alg));
	((mk_lang_types_void_t)(iv));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_ecb_inl_defd_rw_set_key_enc(mk_lib_crypto_mode_ecb_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ecb_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(alg);
	mk_lang_assert(key);

	mk_lib_crypto_mode_ecb_inl_defd_base_expand_enc(&key->m_data.m_base, &alg->m_schedule.m_data.m_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_ecb_inl_defd_rw_set_key_dec(mk_lib_crypto_mode_ecb_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ecb_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(alg);
	mk_lang_assert(key);

	mk_lib_crypto_mode_ecb_inl_defd_base_expand_dec(&key->m_data.m_base, &alg->m_schedule.m_data.m_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_ecb_inl_defd_rw_encrypt(mk_lib_crypto_mode_ecb_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ecb_inl_defd_msg_pct const inputs, mk_lib_crypto_mode_ecb_inl_defd_msg_pt const outputs, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(alg);
	mk_lang_assert(inputs || count == 0);
	mk_lang_assert(outputs || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_mode_ecb_inl_defd_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_mode_ecb_inl_defd_base_msg_pct ins mk_lang_constexpr_init;
		mk_lib_crypto_mode_ecb_inl_defd_base_msg_pt outs mk_lang_constexpr_init;

		mk_lang_static_assert(sizeof(mk_lib_crypto_mode_ecb_inl_defd_base_msg_t) == sizeof(mk_lib_crypto_mode_ecb_inl_defd_msg_t));
		mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_mode_ecb_inl_defd_base_msg_t) == mk_lang_alignof(mk_lib_crypto_mode_ecb_inl_defd_msg_t));

		ins = ((mk_lib_crypto_mode_ecb_inl_defd_base_msg_pct)(inputs));
		outs = ((mk_lib_crypto_mode_ecb_inl_defd_base_msg_pt)(outputs));
		mk_lib_crypto_mode_ecb_inl_defd_base_schedule_encrypt(&alg->m_schedule.m_data.m_base, ins, outs, count);
	}
	else
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;

		n = count;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_mode_ecb_inl_defd_base_schedule_encrypt(&alg->m_schedule.m_data.m_base, &inputs[i].m_data.m_base, &outputs[i].m_data.m_base, 1);
		}
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_ecb_inl_defd_rw_decrypt(mk_lib_crypto_mode_ecb_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ecb_inl_defd_msg_pct const inputs, mk_lib_crypto_mode_ecb_inl_defd_msg_pt const outputs, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(alg);
	mk_lang_assert(inputs || count == 0);
	mk_lang_assert(outputs || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_mode_ecb_inl_defd_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_mode_ecb_inl_defd_base_msg_pct ins mk_lang_constexpr_init;
		mk_lib_crypto_mode_ecb_inl_defd_base_msg_pt outs mk_lang_constexpr_init;

		mk_lang_static_assert(sizeof(mk_lib_crypto_mode_ecb_inl_defd_base_msg_t) == sizeof(mk_lib_crypto_mode_ecb_inl_defd_msg_t));
		mk_lang_static_assert(mk_lang_alignof(mk_lib_crypto_mode_ecb_inl_defd_base_msg_t) == mk_lang_alignof(mk_lib_crypto_mode_ecb_inl_defd_msg_t));

		ins = ((mk_lib_crypto_mode_ecb_inl_defd_base_msg_pct)(inputs));
		outs = ((mk_lib_crypto_mode_ecb_inl_defd_base_msg_pt)(outputs));
		mk_lib_crypto_mode_ecb_inl_defd_base_schedule_decrypt(&alg->m_schedule.m_data.m_base, ins, outs, count);
	}
	else
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;

		n = count;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_mode_ecb_inl_defd_base_schedule_decrypt(&alg->m_schedule.m_data.m_base, &inputs[i].m_data.m_base, &outputs[i].m_data.m_base, 1);
		}
	}
}


#include "mk_lib_crypto_mode_ecb_inl_defu.h"
