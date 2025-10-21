include(`mk_lib_crypto_mode_stream.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_mode_stream_any1_c
#define mk_include_guard_mk_lib_crypto_mode_stream_any1_c
#include "mk_lib_crypto_mode_stream_any1.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"

#include "mk_lib_crypto_mode_stream.h"


mk_lang_forward(mk_sl_cui_uint8);


union mk_lib_crypto_mode_stream_any1_data_u
{
define(`mk_lib_crypto_mode_stream_any1_c_mm_data', `dnl
	mk_lib_crypto_mode_stream_$1_$2_t m_$1_$2;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_c_mm_data', mk_lib_crypto_mode_stream_mm_list())dnl
};
typedef union mk_lib_crypto_mode_stream_any1_data_u mk_lib_crypto_mode_stream_any1_data_t;
struct mk_lib_crypto_mode_stream_any1_s
{
	mk_lib_crypto_mode_stream_any1_data_t m_data;
};
typedef struct mk_lib_crypto_mode_stream_any1_s mk_lib_crypto_mode_stream_any1_t;
mk_lang_typedef(mk_lib_crypto_mode_stream_any1);


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any1_pr_iv_len_v(mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);

	len = 0;
	switch(id)
	{
define(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_msg_len_v', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: len = mk_lib_crypto_mode_stream_$1_$2_iv_len_v; break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_msg_len_v', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any1_pr_key_len_v(mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);

	len = 0;
	switch(id)
	{
define(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_msg_len_v', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: len = mk_lib_crypto_mode_stream_$1_$2_key_len_v; break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_msg_len_v', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any1_pr_msg_len_v(mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);

	len = 0;
	switch(id)
	{
define(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_msg_len_v', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: len = mk_lib_crypto_mode_stream_$1_$2_msg_len_v; break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_msg_len_v', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return len;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptr_rw_set_iv(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_lib_crypto_mode_stream_civ_any1_ptr_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(ptr);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lang_assert(iv);

	switch(id)
	{
define(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_rw_set_iv', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: mk_lib_crypto_mode_stream_$1_$2_rw_set_iv(ptr->m_data.m_$1_$2, iv->m_data.m_$1_$2); break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_rw_set_iv', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptr_rw_set_key_enc(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept
{
	mk_lang_assert(ptr);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lang_assert(key);

	switch(id)
	{
define(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_rw_set_key_enc', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: mk_lib_crypto_mode_stream_$1_$2_rw_set_key_enc(ptr->m_data.m_$1_$2, key->m_data.m_$1_$2); break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_rw_set_key_enc', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptr_rw_set_key_dec(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept
{
	mk_lang_assert(ptr);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lang_assert(key);

	switch(id)
	{
define(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_rw_set_key_dec', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: mk_lib_crypto_mode_stream_$1_$2_rw_set_key_dec(ptr->m_data.m_$1_$2, key->m_data.m_$1_$2); break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_rw_set_key_dec', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptr_rw_encrypt(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(ptr);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lang_assert(input_buf || input_len == 0);
	mk_lang_assert(input_len >= 0);
	mk_lang_assert(input_len <= mk_lang_limits_usize_max - (mk_lib_crypto_mode_stream_any1_pr_msg_len_v(id) - 1));
	mk_lang_assert(output_buf || output_len == 0);
	mk_lang_assert(output_len >= input_len + (mk_lib_crypto_mode_stream_any1_pr_msg_len_v(id) - 1));
	mk_lang_assert(output_used);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	switch(id)
	{
define(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_rw_encrypt', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: mk_lib_crypto_mode_stream_$1_$2_rw_encrypt(ptr->m_data.m_$1_$2, input_buf, input_len, output_buf, output_len, output_used); break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_rw_encrypt', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptr_rw_decrypt(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(ptr);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lang_assert(input_buf || input_len == 0);
	mk_lang_assert(input_len >= 0);
	mk_lang_assert(input_len <= mk_lang_limits_usize_max - (mk_lib_crypto_mode_stream_any1_pr_msg_len_v(id) - 1));
	mk_lang_assert(output_buf || output_len == 0);
	mk_lang_assert(output_len >= input_len + (mk_lib_crypto_mode_stream_any1_pr_msg_len_v(id) - 1));
	mk_lang_assert(output_used);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	switch(id)
	{
define(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_rw_decrypt', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: mk_lib_crypto_mode_stream_$1_$2_rw_decrypt(ptr->m_data.m_$1_$2, input_buf, input_len, output_buf, output_len, output_used); break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_c_mm_fnc_rw_decrypt', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_construct(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(any1);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);

	any1->m_id.m_data.m_id = id;
	any1->m_ptr.m_data.m_void = mk_lang_null;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_set_iv(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_civ_any1_ptr_pct const iv) mk_lang_noexcept
{
	mk_lang_assert(any1);
	mk_lang_assert(any1->m_id.m_data.m_id >= 0);
	mk_lang_assert(any1->m_id.m_data.m_id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lang_assert(iv);

	mk_lib_crypto_mode_stream_any1_ptr_rw_set_iv(&any1->m_ptr, any1->m_id.m_data.m_id, iv);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_set_key_enc(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept
{
	mk_lang_assert(any1);
	mk_lang_assert(any1->m_id.m_data.m_id >= 0);
	mk_lang_assert(any1->m_id.m_data.m_id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lang_assert(key);

	mk_lib_crypto_mode_stream_any1_ptr_rw_set_key_enc(&any1->m_ptr, any1->m_id.m_data.m_id, key);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_set_key_dec(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept
{
	mk_lang_assert(any1);
	mk_lang_assert(any1->m_id.m_data.m_id >= 0);
	mk_lang_assert(any1->m_id.m_data.m_id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lang_assert(key);

	mk_lib_crypto_mode_stream_any1_ptr_rw_set_key_dec(&any1->m_ptr, any1->m_id.m_data.m_id, key);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_encrypt(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(any1);
	mk_lang_assert(any1->m_id.m_data.m_id >= 0);
	mk_lang_assert(any1->m_id.m_data.m_id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lang_assert(input_buf || input_len == 0);
	mk_lang_assert(input_len >= 0);
	mk_lang_assert(input_len <= mk_lang_limits_usize_max - (mk_lib_crypto_mode_stream_any1_pr_msg_len_v(any1->m_id.m_data.m_id) - 1));
	mk_lang_assert(output_buf || output_len == 0);
	mk_lang_assert(output_len >= input_len + (mk_lib_crypto_mode_stream_any1_pr_msg_len_v(any1->m_id.m_data.m_id) - 1));
	mk_lang_assert(output_used);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	mk_lib_crypto_mode_stream_any1_ptr_rw_encrypt(&any1->m_ptr, any1->m_id.m_data.m_id, input_buf, input_len, output_buf, output_len, output_used);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_decrypt(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(any1);
	mk_lang_assert(any1->m_id.m_data.m_id >= 0);
	mk_lang_assert(any1->m_id.m_data.m_id < mk_lib_crypto_mode_stream_any1_id_e_dummy_end);
	mk_lang_assert(input_buf || input_len == 0);
	mk_lang_assert(input_len >= 0);
	mk_lang_assert(input_len <= mk_lang_limits_usize_max - (mk_lib_crypto_mode_stream_any1_pr_msg_len_v(any1->m_id.m_data.m_id) - 1));
	mk_lang_assert(output_buf || output_len == 0);
	mk_lang_assert(output_len >= input_len + (mk_lib_crypto_mode_stream_any1_pr_msg_len_v(any1->m_id.m_data.m_id) - 1));
	mk_lang_assert(output_used);
	#include "mk_lang_warning_msvc_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	mk_lib_crypto_mode_stream_any1_ptr_rw_decrypt(&any1->m_ptr, any1->m_id.m_data.m_id, input_buf, input_len, output_buf, output_len, output_used);
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any1_iv_len_v(mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any1_pr_iv_len_v(id);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any1_key_len_v(mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any1_pr_key_len_v(id);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any1_msg_len_v(mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any1_pr_msg_len_v(id);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptr_rw_set_iv(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_lib_crypto_mode_stream_civ_any1_ptr_pct const iv) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptr_rw_set_iv(ptr, id, iv);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptr_rw_set_key_enc(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptr_rw_set_key_enc(ptr, id, key);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptr_rw_set_key_dec(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptr_rw_set_key_dec(ptr, id, key);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptr_rw_encrypt(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptr_rw_encrypt(ptr, id, input_buf, input_len, output_buf, output_len, output_used);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptr_rw_decrypt(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptr_rw_decrypt(ptr, id, input_buf, input_len, output_buf, output_len, output_used);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_construct(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_construct(any1, id);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_set_iv(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_civ_any1_ptr_pct const iv) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_set_iv(any1, iv);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_set_key_enc(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_set_key_enc(any1, key);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_set_key_dec(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_set_key_dec(any1, key);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_encrypt(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_encrypt(any1, input_buf, input_len, output_buf, output_len, output_used);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_decrypt(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_pr_ptrid_rw_decrypt(any1, input_buf, input_len, output_buf, output_len, output_used);
}


#endif
