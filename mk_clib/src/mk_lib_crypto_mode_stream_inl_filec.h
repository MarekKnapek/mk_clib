#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


#include "mk_lib_crypto_mode_stream_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_inl_defd_rw_set_iv(mk_lib_crypto_mode_stream_inl_defd_pt const stream, mk_lib_crypto_mode_stream_inl_defd_iv_pct const iv) mk_lang_noexcept
{
#if mk_lib_crypto_mode_stream_inl_defd_base_iv_len_d != 0
	mk_lang_assert(stream);
	mk_lang_assert(iv);

	mk_lib_crypto_mode_stream_inl_defd_base_rw_set_iv(&stream->m_base_alg, &iv->m_data.m_base);
	stream->m_idx = 0;
#else
	mk_lang_assert(stream);
	mk_lang_assert(iv || !iv);

	((mk_lang_types_void_t)(iv));
	stream->m_idx = 0;
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_inl_defd_rw_set_key_enc(mk_lib_crypto_mode_stream_inl_defd_pt const stream, mk_lib_crypto_mode_stream_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(stream);
	mk_lang_assert(key);

	mk_lib_crypto_mode_stream_inl_defd_base_rw_set_key_enc(&stream->m_base_alg, &key->m_data.m_base);
	stream->m_idx = 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_inl_defd_rw_set_key_dec(mk_lib_crypto_mode_stream_inl_defd_pt const stream, mk_lib_crypto_mode_stream_inl_defd_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(stream);
	mk_lang_assert(key);

	mk_lib_crypto_mode_stream_inl_defd_base_rw_set_key_dec(&stream->m_base_alg, &key->m_data.m_base);
	stream->m_idx = 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_inl_defd_rw_encrypt(mk_lib_crypto_mode_stream_inl_defd_pt const stream, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t in_rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t out_rem mk_lang_constexpr_init;
	mk_lang_types_usize_t free_space mk_lang_constexpr_init;
	mk_lang_types_usize_t to_copy mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(stream);
	mk_lang_assert(input_buf || input_len == 0);
	mk_lang_assert(input_len >= 0);
	mk_lang_assert(input_len <= mk_lang_limits_usize_max - (mk_lib_crypto_mode_stream_inl_defd_msg_len_v - 1));
	mk_lang_assert(output_buf || output_len == 0);
	mk_lang_assert(output_len >= input_len + (mk_lib_crypto_mode_stream_inl_defd_msg_len_v - 1));
	mk_lang_assert(output_used);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	in_ptr = input_buf;
	in_rem = input_len;
	out_ptr = output_buf;
	out_rem = output_len;
	while(in_rem != 0)
	{
		if
		(
			(stream->m_idx == 0) &&
			(((mk_lang_types_uintptr_t)(in_ptr)) % mk_lib_crypto_mode_stream_inl_defd_msg_len_v == 0) &&
			(((mk_lang_types_uintptr_t)(out_ptr)) % mk_lib_crypto_mode_stream_inl_defd_msg_len_v == 0) &&
			(in_rem >= mk_lib_crypto_mode_stream_inl_defd_msg_len_v) &&
			(out_rem >= mk_lib_crypto_mode_stream_inl_defd_msg_len_v) &&
			(mk_lang_true)
		)
		{
			mk_lib_crypto_mode_stream_inl_defd_base_msg_pct in_base mk_lang_constexpr_init;
			mk_lib_crypto_mode_stream_inl_defd_base_msg_pt out_base mk_lang_constexpr_init;
			mk_lang_types_usize_t cnt_base mk_lang_constexpr_init;

			in_base = ((mk_lib_crypto_mode_stream_inl_defd_base_msg_pct)(in_ptr));
			out_base = ((mk_lib_crypto_mode_stream_inl_defd_base_msg_pt)(out_ptr));
			cnt_base = in_rem / mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
			mk_lib_crypto_mode_stream_inl_defd_base_rw_encrypt(&stream->m_base_alg, in_base, out_base, cnt_base);
			in_ptr += cnt_base * mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
			out_ptr += cnt_base * mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
			in_rem -= cnt_base * mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
			out_rem -= cnt_base * mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
		}
		free_space = ((mk_lang_types_usize_t)(mk_lib_crypto_mode_stream_inl_defd_msg_len_v - stream->m_idx));
		to_copy = mk_lang_min(free_space, in_rem);
		mk_sl_cui_uint8_memcpy_fn(&stream->m_msg.m_data.m_base.m_data.m_uint8s[stream->m_idx], in_ptr, to_copy); stream->m_idx += ((mk_lang_types_sint_t)(to_copy));
		in_ptr += to_copy;
		in_rem -= to_copy;
		if(stream->m_idx == mk_lib_crypto_mode_stream_inl_defd_msg_len_v)
		{
			stream->m_idx = 0;
			mk_lib_crypto_mode_stream_inl_defd_base_rw_encrypt(&stream->m_base_alg, &stream->m_msg.m_data.m_base, &stream->m_msg.m_data.m_base, 1);
			mk_sl_cui_uint8_memcpy_fn(out_ptr, &stream->m_msg.m_data.m_uint8s[0], mk_lib_crypto_mode_stream_inl_defd_msg_len_v);
			out_ptr += mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
			out_rem -= mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
		}
	}
	to_copy = output_len - out_rem;
	*output_used = to_copy;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_inl_defd_rw_decrypt(mk_lib_crypto_mode_stream_inl_defd_pt const stream, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct in_ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t in_rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt out_ptr mk_lang_constexpr_init;
	mk_lang_types_usize_t out_rem mk_lang_constexpr_init;
	mk_lang_types_usize_t free_space mk_lang_constexpr_init;
	mk_lang_types_usize_t to_copy mk_lang_constexpr_init;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(stream);
	mk_lang_assert(input_buf || input_len == 0);
	mk_lang_assert(input_len >= 0);
	mk_lang_assert(input_len <= mk_lang_limits_usize_max - (mk_lib_crypto_mode_stream_inl_defd_msg_len_v - 1));
	mk_lang_assert(output_buf || output_len == 0);
	mk_lang_assert(output_len >= input_len + (mk_lib_crypto_mode_stream_inl_defd_msg_len_v - 1));
	mk_lang_assert(output_used);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	in_ptr = input_buf;
	in_rem = input_len;
	out_ptr = output_buf;
	out_rem = output_len;
	while(in_rem != 0)
	{
		if
		(
			(stream->m_idx == 0) &&
			(((mk_lang_types_uintptr_t)(in_ptr)) % mk_lib_crypto_mode_stream_inl_defd_msg_len_v == 0) &&
			(((mk_lang_types_uintptr_t)(out_ptr)) % mk_lib_crypto_mode_stream_inl_defd_msg_len_v == 0) &&
			(in_rem >= mk_lib_crypto_mode_stream_inl_defd_msg_len_v) &&
			(out_rem >= mk_lib_crypto_mode_stream_inl_defd_msg_len_v) &&
			(mk_lang_true)
		)
		{
			mk_lib_crypto_mode_stream_inl_defd_base_msg_pct in_base mk_lang_constexpr_init;
			mk_lib_crypto_mode_stream_inl_defd_base_msg_pt out_base mk_lang_constexpr_init;
			mk_lang_types_usize_t cnt_base mk_lang_constexpr_init;

			in_base = ((mk_lib_crypto_mode_stream_inl_defd_base_msg_pct)(in_ptr));
			out_base = ((mk_lib_crypto_mode_stream_inl_defd_base_msg_pt)(out_ptr));
			cnt_base = in_rem / mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
			mk_lib_crypto_mode_stream_inl_defd_base_rw_decrypt(&stream->m_base_alg, in_base, out_base, cnt_base);
			in_ptr += cnt_base * mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
			out_ptr += cnt_base * mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
			in_rem -= cnt_base * mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
			out_rem -= cnt_base * mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
		}
		free_space = ((mk_lang_types_usize_t)(mk_lib_crypto_mode_stream_inl_defd_msg_len_v - stream->m_idx));
		to_copy = mk_lang_min(free_space, in_rem);
		mk_sl_cui_uint8_memcpy_fn(&stream->m_msg.m_data.m_base.m_data.m_uint8s[stream->m_idx], in_ptr, to_copy); stream->m_idx += ((mk_lang_types_sint_t)(to_copy));
		in_ptr += to_copy;
		in_rem -= to_copy;
		if(stream->m_idx == mk_lib_crypto_mode_stream_inl_defd_msg_len_v)
		{
			stream->m_idx = 0;
			mk_lib_crypto_mode_stream_inl_defd_base_rw_decrypt(&stream->m_base_alg, &stream->m_msg.m_data.m_base, &stream->m_msg.m_data.m_base, 1);
			mk_sl_cui_uint8_memcpy_fn(out_ptr, &stream->m_msg.m_data.m_uint8s[0], mk_lib_crypto_mode_stream_inl_defd_msg_len_v);
			out_ptr += mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
			out_rem -= mk_lib_crypto_mode_stream_inl_defd_msg_len_v;
		}
	}
	to_copy = output_len - out_rem;
	*output_used = to_copy;
}


#include "mk_lib_crypto_mode_stream_inl_defu.h"
