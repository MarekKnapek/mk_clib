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

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_prrw_crypt_do_constexpr(mk_lib_crypto_mode_ctr_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ctr_inl_defd_msg_pct const inputs, mk_lib_crypto_mode_ctr_inl_defd_msg_pt const outputs, mk_lang_types_usize_t const count) mk_lang_noexcept
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

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		n = count;
		for(i = 0; i != n; ++i)
		{
			mk_lib_crypto_mode_ctr_inl_defd_base_schedule_encrypt(&alg->m_schedule.m_data.m_base, &alg->m_iv.m_data.m_base, &tmp, 1);
			mk_lib_crypto_mode_ctr_inl_defd_xor_3(&tmp.m_data.m_uint8s[0], &inputs[i].m_data.m_base.m_data.m_uint8s[0], &outputs[i].m_data.m_base.m_data.m_uint8s[0]);
			mk_lib_crypto_mode_ctr_inl_defd_prrw_increment(&alg->m_iv);
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_prrw_crypt_no_constexpr(mk_lib_crypto_mode_ctr_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ctr_inl_defd_msg_pct const inputs, mk_lib_crypto_mode_ctr_inl_defd_msg_pt const outputs, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lib_crypto_mode_ctr_inl_defd_msg_pct ins mk_lang_constexpr_init;
	mk_lib_crypto_mode_ctr_inl_defd_msg_pt outs mk_lang_constexpr_init;
	mk_lang_types_usize_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(alg);
	mk_lang_assert(inputs || count == 0);
	mk_lang_assert(outputs || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_mode_ctr_inl_defd_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		ins = inputs;
		outs = outputs;
		rem = count;
		n = rem / 64; if(n !=0){ mk_lib_crypto_mode_ctr_inl_defd_rw_crypt_n64(((mk_lib_crypto_mode_ctr_inl_defd_n64_alg_pt)(alg)), ((mk_lib_crypto_mode_ctr_inl_defd_n64_msg_pct)(ins)), ((mk_lib_crypto_mode_ctr_inl_defd_n64_msg_pt)(outs)), n * 64); ins += n * 64; outs += n * 64; rem -= n * 64; }
		n = rem / 32; if(n !=0){ mk_lib_crypto_mode_ctr_inl_defd_rw_crypt_n32(((mk_lib_crypto_mode_ctr_inl_defd_n32_alg_pt)(alg)), ((mk_lib_crypto_mode_ctr_inl_defd_n32_msg_pct)(ins)), ((mk_lib_crypto_mode_ctr_inl_defd_n32_msg_pt)(outs)), n * 32); ins += n * 32; outs += n * 32; rem -= n * 32; }
		n = rem / 16; if(n !=0){ mk_lib_crypto_mode_ctr_inl_defd_rw_crypt_n16(((mk_lib_crypto_mode_ctr_inl_defd_n16_alg_pt)(alg)), ((mk_lib_crypto_mode_ctr_inl_defd_n16_msg_pct)(ins)), ((mk_lib_crypto_mode_ctr_inl_defd_n16_msg_pt)(outs)), n * 16); ins += n * 16; outs += n * 16; rem -= n * 16; }
		n = rem / 8 ; if(n !=0){ mk_lib_crypto_mode_ctr_inl_defd_rw_crypt_n8 (((mk_lib_crypto_mode_ctr_inl_defd_n8_alg_pt )(alg)), ((mk_lib_crypto_mode_ctr_inl_defd_n8_msg_pct )(ins)), ((mk_lib_crypto_mode_ctr_inl_defd_n8_msg_pt )(outs)), n * 8 ); ins += n * 8 ; outs += n * 8 ; rem -= n * 8 ; }
		n = rem / 4 ; if(n !=0){ mk_lib_crypto_mode_ctr_inl_defd_rw_crypt_n4 (((mk_lib_crypto_mode_ctr_inl_defd_n4_alg_pt )(alg)), ((mk_lib_crypto_mode_ctr_inl_defd_n4_msg_pct )(ins)), ((mk_lib_crypto_mode_ctr_inl_defd_n4_msg_pt )(outs)), n * 4 ); ins += n * 4 ; outs += n * 4 ; rem -= n * 4 ; }
		n = rem / 2 ; if(n !=0){ mk_lib_crypto_mode_ctr_inl_defd_rw_crypt_n2 (((mk_lib_crypto_mode_ctr_inl_defd_n2_alg_pt )(alg)), ((mk_lib_crypto_mode_ctr_inl_defd_n2_msg_pct )(ins)), ((mk_lib_crypto_mode_ctr_inl_defd_n2_msg_pt )(outs)), n * 2 ); ins += n * 2 ; outs += n * 2 ; rem -= n * 2 ; }
		n = rem / 1 ; if(n !=0){ mk_lib_crypto_mode_ctr_inl_defd_rw_crypt_n1 (((mk_lib_crypto_mode_ctr_inl_defd_n1_alg_pt )(alg)), ((mk_lib_crypto_mode_ctr_inl_defd_n1_msg_pct )(ins)), ((mk_lib_crypto_mode_ctr_inl_defd_n1_msg_pt )(outs)), n * 1 ); ins += n * 1 ; outs += n * 1 ; rem -= n * 1 ; }
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_ctr_inl_defd_prrw_crypt(mk_lib_crypto_mode_ctr_inl_defd_alg_pt const alg, mk_lib_crypto_mode_ctr_inl_defd_msg_pct const inputs, mk_lib_crypto_mode_ctr_inl_defd_msg_pt const outputs, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(alg);
	mk_lang_assert(inputs || count == 0);
	mk_lang_assert(outputs || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_lang_limits_usize_max / mk_lib_crypto_mode_ctr_inl_defd_msg_len_v);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lib_crypto_mode_ctr_inl_defd_prrw_crypt_no_constexpr(alg, inputs, outputs, count);
	}
	else
	{
		mk_lib_crypto_mode_ctr_inl_defd_prrw_crypt_do_constexpr(alg, inputs, outputs, count);
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
