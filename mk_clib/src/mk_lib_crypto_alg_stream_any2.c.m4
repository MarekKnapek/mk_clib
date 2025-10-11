include(`mk_lib_crypto_alg_stream.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_alg_stream_any2_c
#define mk_include_guard_mk_lib_crypto_alg_stream_any2_c
#include "mk_lib_crypto_alg_stream_any2.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_alg_stream_any1.h"


mk_lang_forward(mk_sl_cui_uint8);


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_prrw_construct(mk_lib_crypto_alg_stream_any2_pt const any2, mk_lib_crypto_alg_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(any2);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_alg_stream_any1_id_e_dummy_end);

	switch(id)
	{
define(`mk_lib_crypto_alg_stream_any2_c_mm_fnc_construct', `dnl
		case mk_lib_crypto_alg_stream_any1_id_e_$1: any2->m_data.m_$1.m_id.m_data.m_id = id; break;
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_c_mm_fnc_construct', mk_lib_crypto_alg_stream_mm_half())dnl
		case mk_lib_crypto_alg_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_stream_any2_prro_get_msg_len(mk_lib_crypto_alg_stream_any2_pct const any2) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_alg_stream_any1_id_e_dummy_end);

	len = mk_lib_crypto_alg_stream_any1_msg_len_v(any2->m_data.m_id.m_data.m_id);
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_alg_stream_any2_prro_get_key_len(mk_lib_crypto_alg_stream_any2_pct const any2) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_alg_stream_any1_id_e_dummy_end);

	len = mk_lib_crypto_alg_stream_any1_key_len_v(any2->m_data.m_id.m_data.m_id);
	return len;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_prrw_construct_encrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_lib_crypto_alg_stream_any2_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_alg_stream_any1_id_e_dummy_end);

	switch(any2->m_data.m_id.m_data.m_id)
	{
define(`mk_lib_crypto_alg_stream_any2_c_mm_fnc_construct_encrypt', `dnl
		case mk_lib_crypto_alg_stream_any1_id_e_$1: mk_lib_crypto_alg_stream_$1_rw_construct_encrypt(&any2->m_data.m_$1.m_$1, &key->m_data.m_$1.m_$1); break;
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_c_mm_fnc_construct_encrypt', mk_lib_crypto_alg_stream_mm_half())dnl
		case mk_lib_crypto_alg_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_prrw_construct_decrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_lib_crypto_alg_stream_any2_key_pct const key) mk_lang_noexcept
{
	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_alg_stream_any1_id_e_dummy_end);

	switch(any2->m_data.m_id.m_data.m_id)
	{
define(`mk_lib_crypto_alg_stream_any2_c_mm_fnc_construct_decrypt', `dnl
		case mk_lib_crypto_alg_stream_any1_id_e_$1: mk_lib_crypto_alg_stream_$1_rw_construct_decrypt(&any2->m_data.m_$1.m_$1, &key->m_data.m_$1.m_$1); break;
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_c_mm_fnc_construct_decrypt', mk_lib_crypto_alg_stream_mm_half())dnl
		case mk_lib_crypto_alg_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_prrw_encrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_alg_stream_any1_id_e_dummy_end);
	mk_lang_assert(input_buf || input_len == 0);
	mk_lang_assert(input_len >= 0);
	mk_lang_assert(input_len <= mk_lang_limits_usize_max - (mk_lib_crypto_alg_stream_any1_msg_len_v(any2->m_data.m_id.m_data.m_id) - 1));
	mk_lang_assert(output_buf || output_len == 0);
	mk_lang_assert(output_len >= input_len + (mk_lib_crypto_alg_stream_any1_msg_len_v(any2->m_data.m_id.m_data.m_id) - 1));
	mk_lang_assert(output_used);
	#include "mk_lang_warning_msvc_pop.h"

	switch(any2->m_data.m_id.m_data.m_id)
	{
define(`mk_lib_crypto_alg_stream_any2_c_mm_fnc_encrypt', `dnl
		case mk_lib_crypto_alg_stream_any1_id_e_$1: mk_lib_crypto_alg_stream_$1_rw_encrypt(&any2->m_data.m_$1.m_$1, input_buf, input_len, output_buf, output_len, output_used); break;
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_c_mm_fnc_encrypt', mk_lib_crypto_alg_stream_mm_half())dnl
		case mk_lib_crypto_alg_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_prrw_decrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_alg_stream_any1_id_e_dummy_end);
	mk_lang_assert(input_buf || input_len == 0);
	mk_lang_assert(input_len >= 0);
	mk_lang_assert(input_len <= mk_lang_limits_usize_max - (mk_lib_crypto_alg_stream_any1_msg_len_v(any2->m_data.m_id.m_data.m_id) - 1));
	mk_lang_assert(output_buf || output_len == 0);
	mk_lang_assert(output_len >= input_len + (mk_lib_crypto_alg_stream_any1_msg_len_v(any2->m_data.m_id.m_data.m_id) - 1));
	mk_lang_assert(output_used);
	#include "mk_lang_warning_msvc_pop.h"

	switch(any2->m_data.m_id.m_data.m_id)
	{
define(`mk_lib_crypto_alg_stream_any2_c_mm_fnc_encrypt', `dnl
		case mk_lib_crypto_alg_stream_any1_id_e_$1: mk_lib_crypto_alg_stream_$1_rw_encrypt(&any2->m_data.m_$1.m_$1, input_buf, input_len, output_buf, output_len, output_used); break;
')`'dnl
mk_lib_crypto_alg_stream_mm_recurse(`mk_lib_crypto_alg_stream_any2_c_mm_fnc_encrypt', mk_lib_crypto_alg_stream_mm_half())dnl
		case mk_lib_crypto_alg_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_rw_construct(mk_lib_crypto_alg_stream_any2_pt const any2, mk_lib_crypto_alg_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lib_crypto_alg_stream_any2_prrw_construct(any2, id);
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_alg_stream_any2_ro_get_msg_len(mk_lib_crypto_alg_stream_any2_pct const any2) mk_lang_noexcept
{
	return mk_lib_crypto_alg_stream_any2_prro_get_msg_len(any2);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_alg_stream_any2_ro_get_key_len(mk_lib_crypto_alg_stream_any2_pct const any2) mk_lang_noexcept
{
	return mk_lib_crypto_alg_stream_any2_prro_get_key_len(any2);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_rw_construct_encrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_lib_crypto_alg_stream_any2_key_pct const key) mk_lang_noexcept
{
	mk_lib_crypto_alg_stream_any2_prrw_construct_encrypt(any2, key);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_rw_construct_decrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_lib_crypto_alg_stream_any2_key_pct const key) mk_lang_noexcept
{
	mk_lib_crypto_alg_stream_any2_prrw_construct_decrypt(any2, key);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_rw_encrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_lib_crypto_alg_stream_any2_prrw_encrypt(any2, input_buf, input_len, output_buf, output_len, output_used);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_alg_stream_any2_rw_decrypt(mk_lib_crypto_alg_stream_any2_pt const any2, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_lib_crypto_alg_stream_any2_prrw_decrypt(any2, input_buf, input_len, output_buf, output_len, output_used);
}


#endif
