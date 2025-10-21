#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_cui_uint_more.h"
#include "mk_sl_uint_more.h"


#include "mk_lib_crypto_mode_ctr_inl_defd.h"


#if mk_lib_crypto_mode_ctr_inl_defd_base_msg_len_d == 16
#include "mk_sl_cui_uint128.h"
#define mk_lib_crypto_mode_ctr_inl_defd_base_counter mk_sl_cui_uint128
#else
#error xxxxxxxxxx
#endif
#define mk_sl_cui_t_name mk_lib_crypto_mode_ctr_inl_defd_counter
#define mk_sl_cui_t_base_type_name mk_lib_crypto_mode_ctr_inl_defd_base_counter
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d (mk_lib_crypto_mode_ctr_inl_defd_base_msg_len_d * mk_lang_charbit)
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_rw_set_iv(mk_lib_crypto_mode_ctr_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ctr_inl_defd_iv_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(alg);
	mk_lang_assert(iv);

	alg->m_iv = *iv;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_prrw_set_key(mk_lib_crypto_mode_ctr_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ctr_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(alg);
	mk_lang_assert(key);

	mk_lib_crypto_mode_ctr_inl_defd_base_expand_enc(&key->m_data.m_base, &alg->m_schedule.m_data.m_base);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_rw_set_key_enc(mk_lib_crypto_mode_ctr_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ctr_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_inl_defd_prrw_set_key(alg, key);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_rw_set_key_dec(mk_lib_crypto_mode_ctr_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ctr_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_inl_defd_prrw_set_key(alg, key);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_counter_from_uint8s_be(mk_lib_crypto_mode_ctr_inl_defd_counter_pt const counter, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_crypto_mode_ctr_inl_defd_base_msg_len_d)) mk_lang_noexcept
{
	union mk_lib_crypto_mode_ctr_inl_defd_counter_from_uint8s_be_converter_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_crypto_mode_ctr_inl_defd_base_msg_len_d];
		mk_lib_crypto_mode_ctr_inl_defd_counter_t m_align;
	};
	typedef union mk_lib_crypto_mode_ctr_inl_defd_counter_from_uint8s_be_converter_data_u mk_lib_crypto_mode_ctr_inl_defd_counter_from_uint8s_be_converter_data_t;
	struct mk_lib_crypto_mode_ctr_inl_defd_counter_from_uint8s_be_converter_s
	{
		mk_lib_crypto_mode_ctr_inl_defd_counter_from_uint8s_be_converter_data_t m_data;
	};
	typedef struct mk_lib_crypto_mode_ctr_inl_defd_counter_from_uint8s_be_converter_s mk_lib_crypto_mode_ctr_inl_defd_counter_from_uint8s_be_converter_t;

	mk_lib_crypto_mode_ctr_inl_defd_counter_from_uint8s_be_converter_t converter mk_lang_constexpr_init;

	mk_lang_assert(counter);
	mk_lang_assert(u8s);

	mk_sl_cui_uint8_to_bi_uchar_many(&u8s[0], &converter.m_data.m_uchars[0], mk_lib_crypto_mode_ctr_inl_defd_base_msg_len_d);
	mk_lib_crypto_mode_ctr_inl_defd_counter_from_buis_uchar_be(counter, &converter.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_counter_to_uint8s_be(mk_lib_crypto_mode_ctr_inl_defd_counter_pct const counter, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_crypto_mode_ctr_inl_defd_base_msg_len_d)) mk_lang_noexcept
{
	union mk_lib_crypto_mode_ctr_inl_defd_counter_to_uint8s_be_converter_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_crypto_mode_ctr_inl_defd_base_msg_len_d];
		mk_lib_crypto_mode_ctr_inl_defd_counter_t m_align;
	};
	typedef union mk_lib_crypto_mode_ctr_inl_defd_counter_to_uint8s_be_converter_data_u mk_lib_crypto_mode_ctr_inl_defd_counter_to_uint8s_be_converter_data_t;
	struct mk_lib_crypto_mode_ctr_inl_defd_counter_to_uint8s_be_converter_s
	{
		mk_lib_crypto_mode_ctr_inl_defd_counter_to_uint8s_be_converter_data_t m_data;
	};
	typedef struct mk_lib_crypto_mode_ctr_inl_defd_counter_to_uint8s_be_converter_s mk_lib_crypto_mode_ctr_inl_defd_counter_to_uint8s_be_converter_t;

	mk_lib_crypto_mode_ctr_inl_defd_counter_to_uint8s_be_converter_t converter mk_lang_constexpr_init;

	mk_lang_assert(counter);
	mk_lang_assert(u8s);

	mk_lib_crypto_mode_ctr_inl_defd_counter_to_buis_uchar_be(counter, &converter.m_data.m_uchars[0]);
	mk_sl_cui_uint8_from_bi_uchar_many(&u8s[0], &converter.m_data.m_uchars[0], mk_lib_crypto_mode_ctr_inl_defd_base_msg_len_d);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_prrw_increment(mk_lib_crypto_mode_ctr_inl_defd_iv_pt const ctr) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_inl_defd_counter_t counter mk_lang_constexpr_init;

	mk_lang_assert(ctr);

	mk_lib_crypto_mode_ctr_inl_defd_counter_from_uint8s_be(&counter, &ctr->m_data.m_base.m_data.m_uint8s[0]);
	mk_lib_crypto_mode_ctr_inl_defd_counter_inc1(&counter);
	mk_lib_crypto_mode_ctr_inl_defd_counter_to_uint8s_be(&counter, &ctr->m_data.m_base.m_data.m_uint8s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_prrw_crypt(mk_lib_crypto_mode_ctr_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ctr_inl_defd_msg_pct const inputs, mk_lib_crypto_mode_ctr_inl_defd_msg_pt const outputs, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_inl_defd_base_msg_t tmp mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(alg);
	mk_lang_assert(inputs || count == 0);
	mk_lang_assert(outputs || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_mode_ctr_inl_defd_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		mk_lib_crypto_mode_ctr_inl_defd_base_schedule_encrypt(&alg->m_schedule.m_data.m_base, &alg->m_iv.m_data.m_base, &tmp, 1);
		mk_lib_crypto_mode_ctr_inl_defd_xor_3(&tmp.m_data.m_uint8s[0], &inputs[i].m_data.m_base.m_data.m_uint8s[0], &outputs[i].m_data.m_base.m_data.m_uint8s[0]);
		mk_lib_crypto_mode_ctr_inl_defd_prrw_increment(&alg->m_iv);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_rw_encrypt(mk_lib_crypto_mode_ctr_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ctr_inl_defd_msg_pct const inputs, mk_lib_crypto_mode_ctr_inl_defd_msg_pt const outputs, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_inl_defd_prrw_crypt(alg, inputs, outputs, count);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_rw_decrypt(mk_lib_crypto_mode_ctr_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ctr_inl_defd_msg_pct const inputs, mk_lib_crypto_mode_ctr_inl_defd_msg_pt const outputs, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_inl_defd_prrw_crypt(alg, inputs, outputs, count);
}


#include "mk_lib_crypto_mode_ctr_inl_defu.h"
