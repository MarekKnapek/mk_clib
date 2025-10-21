include(`mk_lib_crypto_mode_stream.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_mode_stream_any3_c
#define mk_include_guard_mk_lib_crypto_mode_stream_any3_c
#include "mk_lib_crypto_mode_stream_any3.h"

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_mode_stream_any1.h"
#include "mk_lib_crypto_mode_stream_any2.h"
#include "mk_sl_mallocator.h"


mk_lang_forward(mk_sl_cui_uint8);


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prst_get_max_iv_len(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t r;

	r = mk_lib_crypto_mode_stream_any2_iv_len_v;
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prst_get_max_key_len(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t r;

	r = mk_lib_crypto_mode_stream_any2_key_len_v;
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prst_get_max_msg_len(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t r;

	r = mk_lib_crypto_mode_stream_any2_msg_len_v;
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prst_get_obj_len(mk_lib_crypto_mode_stream_any3_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t len;

	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any3_id_e_dummy_end);

	mk_lang_clobber(&len);
	switch(id)
	{
define(`mk_lib_crypto_mode_stream_any3_h_mm_case_construct_type_a', `dnl
		case mk_lib_crypto_mode_stream_any3_id_e_$1_$2: len = ((mk_lang_types_sint_t)(sizeof(mk_lib_crypto_mode_stream_any2_$1_$2_t))); break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any3_h_mm_case_construct_type_a', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any3_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return len;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prrw_construct_void(mk_lib_crypto_mode_stream_any3_pt const any3) mk_lang_noexcept
{
	mk_lang_assert(any3);

	any3->m_data.m_id = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prrw_construct_type(mk_lib_crypto_mode_stream_any3_pt const any3, mk_lib_crypto_mode_stream_any3_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;

	mk_lang_assert(any3);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any3_id_e_dummy_end);
	mk_lang_assert(mk_lib_crypto_mode_stream_any3_max_iv_len_guess_v == mk_lib_crypto_mode_stream_any3_prst_get_max_iv_len());
	mk_lang_assert(mk_lib_crypto_mode_stream_any3_max_key_len_guess_v == mk_lib_crypto_mode_stream_any3_prst_get_max_key_len());
	mk_lang_assert(mk_lib_crypto_mode_stream_any3_max_msg_len_guess_v == mk_lib_crypto_mode_stream_any3_prst_get_max_msg_len());

	len = mk_lib_crypto_mode_stream_any3_prst_get_obj_len(id); mk_lang_assert(len >= 1);
	err = mk_sl_mallocator_allocate(((mk_lang_types_usize_t)(len)), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
	switch(id)
	{
define(`mk_lib_crypto_mode_stream_any3_h_mm_case_construct_type', `dnl
		case mk_lib_crypto_mode_stream_any3_id_e_$1_$2: any3->m_data.m_$1_$2 = ((mk_lib_crypto_mode_stream_any2_$1_$2_pt)(mem)); any3->m_data.m_$1_$2->m_id.m_data.m_id = ((mk_lib_crypto_mode_stream_any1_id_t)(id)); break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any3_h_mm_case_construct_type', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any3_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	};
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prrw_destroy(mk_lib_crypto_mode_stream_any3_pt const any3) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any3_id_t id;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(any3);

	if(any3->m_data.m_id)
	{
		id = ((mk_lib_crypto_mode_stream_any3_id_t)(any3->m_data.m_id->m_data.m_id));
		len = mk_lib_crypto_mode_stream_any3_prst_get_obj_len(id); mk_lang_assert(len >= 1);
		err = mk_sl_mallocator_deallocate(any3->m_data.m_id, ((mk_lang_types_usize_t)(len))); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prrw_reconstruct_void(mk_lib_crypto_mode_stream_any3_pt const any3) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(any3);

	err = mk_lib_crypto_mode_stream_any3_prrw_destroy(any3); mk_lang_check_rereturn(err);
	err = mk_lib_crypto_mode_stream_any3_prrw_construct_void(any3); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prrw_reconstruct_type(mk_lib_crypto_mode_stream_any3_pt const any3, mk_lib_crypto_mode_stream_any3_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(any3);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mode_stream_any3_id_e_dummy_end);

	err = mk_lib_crypto_mode_stream_any3_prrw_destroy(any3); mk_lang_check_rereturn(err);
	err = mk_lib_crypto_mode_stream_any3_prrw_construct_type(any3, id); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prro_get_iv_len(mk_lib_crypto_mode_stream_any3_pct const any3) mk_lang_noexcept
{
	mk_lang_types_sint_t r;

	mk_lang_assert(any3);
	mk_lang_assert(any3->m_data.m_id);

	r = mk_lib_crypto_mode_stream_any1_iv_len_v(any3->m_data.m_id->m_data.m_id);
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prro_get_key_len(mk_lib_crypto_mode_stream_any3_pct const any3) mk_lang_noexcept
{
	mk_lang_types_sint_t r;

	mk_lang_assert(any3);
	mk_lang_assert(any3->m_data.m_id);

	r = mk_lib_crypto_mode_stream_any1_key_len_v(any3->m_data.m_id->m_data.m_id);
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_prro_get_msg_len(mk_lib_crypto_mode_stream_any3_pct const any3) mk_lang_noexcept
{
	mk_lang_types_sint_t r;

	mk_lang_assert(any3);
	mk_lang_assert(any3->m_data.m_id);

	r = mk_lib_crypto_mode_stream_any1_msg_len_v(any3->m_data.m_id->m_data.m_id);
	return r;
}

static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any3_prrw_set_iv(mk_lib_crypto_mode_stream_any3_pt const any3, mk_sl_cui_uint8_pct const iv_buf, mk_lang_types_sint_t const iv_len) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_ptr_t ptr;
	mk_lib_crypto_mode_stream_civ_any1_ptr_t iv;

	mk_lang_assert(any3);
	mk_lang_assert(any3->m_data.m_id);
	mk_lang_assert(iv_buf || iv_len == 0);
	mk_lang_assert(iv_len >= 0);
	mk_lang_assert(iv_len == mk_lib_crypto_mode_stream_any3_prro_get_iv_len(any3));

	switch(any3->m_data.m_id->m_data.m_id)
	{
define(`mk_lib_crypto_mode_stream_any3_h_mm_case_set_iv', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: ptr.m_data.m_$1_$2 = &any3->m_data.m_$1_$2->m_$1_$2; mk_lang_assert(((mk_lang_types_uintptr_t)(iv_buf)) % mk_lang_alignof(mk_lib_crypto_mode_stream_$1_$2_iv_t) == 0); iv.m_data.m_$1_$2 = ((mk_lib_crypto_mode_stream_$1_$2_iv_pct)(iv_buf)); break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any3_h_mm_case_set_iv', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	};
	mk_lib_crypto_mode_stream_any1_ptr_rw_set_iv(&ptr, any3->m_data.m_id->m_data.m_id, &iv);
}

static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any3_prrw_set_key_enc(mk_lib_crypto_mode_stream_any3_pt const any3, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_sint_t const key_len) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_ptr_t ptr;
	mk_lib_crypto_mode_stream_ckey_any1_ptr_t key;

	mk_lang_assert(any3);
	mk_lang_assert(any3->m_data.m_id);
	mk_lang_assert(key_buf || key_len == 0);
	mk_lang_assert(key_len >= 0);
	mk_lang_assert(key_len == mk_lib_crypto_mode_stream_any3_prro_get_key_len(any3));

	switch(any3->m_data.m_id->m_data.m_id)
	{
define(`mk_lib_crypto_mode_stream_any3_h_mm_case_set_key_enc', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: ptr.m_data.m_$1_$2 = &any3->m_data.m_$1_$2->m_$1_$2; mk_lang_assert(((mk_lang_types_uintptr_t)(key_buf)) % mk_lang_alignof(mk_lib_crypto_mode_stream_$1_$2_key_t) == 0); key.m_data.m_$1_$2 = ((mk_lib_crypto_mode_stream_$1_$2_key_pct)(key_buf)); break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any3_h_mm_case_set_key_enc', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	};
	mk_lib_crypto_mode_stream_any1_ptr_rw_set_key_enc(&ptr, any3->m_data.m_id->m_data.m_id, &key);
}

static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any3_prrw_set_key_dec(mk_lib_crypto_mode_stream_any3_pt const any3, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_sint_t const key_len) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_ptr_t ptr;
	mk_lib_crypto_mode_stream_ckey_any1_ptr_t key;

	mk_lang_assert(any3);
	mk_lang_assert(any3->m_data.m_id);
	mk_lang_assert(key_buf || key_len == 0);
	mk_lang_assert(key_len >= 0);
	mk_lang_assert(key_len == mk_lib_crypto_mode_stream_any3_prro_get_key_len(any3));

	switch(any3->m_data.m_id->m_data.m_id)
	{
define(`mk_lib_crypto_mode_stream_any3_h_mm_case_set_key_dec', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: ptr.m_data.m_$1_$2 = &any3->m_data.m_$1_$2->m_$1_$2; mk_lang_assert(((mk_lang_types_uintptr_t)(key_buf)) % mk_lang_alignof(mk_lib_crypto_mode_stream_$1_$2_key_t) == 0); key.m_data.m_$1_$2 = ((mk_lib_crypto_mode_stream_$1_$2_key_pct)(key_buf)); break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any3_h_mm_case_set_key_dec', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	};
	mk_lib_crypto_mode_stream_any1_ptr_rw_set_key_dec(&ptr, any3->m_data.m_id->m_data.m_id, &key);
}

static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any3_prrw_encrypt(mk_lib_crypto_mode_stream_any3_pt const any3, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_ptr_t ptr;

	mk_lang_assert(any3);
	mk_lang_assert(any3->m_data.m_id);

	switch(any3->m_data.m_id->m_data.m_id)
	{
define(`mk_lib_crypto_mode_stream_any3_h_mm_case_set_iv', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: ptr.m_data.m_$1_$2 = &any3->m_data.m_$1_$2->m_$1_$2; break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any3_h_mm_case_set_iv', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	};
	mk_lib_crypto_mode_stream_any1_ptr_rw_encrypt(&ptr, any3->m_data.m_id->m_data.m_id, input_buf, input_len, output_buf, output_len, output_used);
}

static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mode_stream_any3_prrw_decrypt(mk_lib_crypto_mode_stream_any3_pt const any3, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any1_ptr_t ptr;

	mk_lang_assert(any3);
	mk_lang_assert(any3->m_data.m_id);

	switch(any3->m_data.m_id->m_data.m_id)
	{
define(`mk_lib_crypto_mode_stream_any3_h_mm_case_set_iv', `dnl
		case mk_lib_crypto_mode_stream_any1_id_e_$1_$2: ptr.m_data.m_$1_$2 = &any3->m_data.m_$1_$2->m_$1_$2; break;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any3_h_mm_case_set_iv', mk_lib_crypto_mode_stream_mm_list())dnl
		case mk_lib_crypto_mode_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	};
	mk_lib_crypto_mode_stream_any1_ptr_rw_decrypt(&ptr, any3->m_data.m_id->m_data.m_id, input_buf, input_len, output_buf, output_len, output_used);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_st_get_max_iv_len(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prst_get_max_iv_len();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_st_get_max_key_len(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prst_get_max_key_len();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_st_get_max_msg_len(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prst_get_max_msg_len();
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_rw_construct_void(mk_lib_crypto_mode_stream_any3_pt const any3) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prrw_construct_void(any3);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_rw_construct_type(mk_lib_crypto_mode_stream_any3_pt const any3, mk_lib_crypto_mode_stream_any3_id_t const id) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prrw_construct_type(any3, id);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_rw_destroy(mk_lib_crypto_mode_stream_any3_pt const any3) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prrw_destroy(any3);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_rw_reconstruct_void(mk_lib_crypto_mode_stream_any3_pt const any3) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prrw_reconstruct_void(any3);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_rw_reconstruct_type(mk_lib_crypto_mode_stream_any3_pt const any3, mk_lib_crypto_mode_stream_any3_id_t const id) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prrw_reconstruct_type(any3, id);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_ro_get_iv_len(mk_lib_crypto_mode_stream_any3_pct const any3) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prro_get_iv_len(any3);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_ro_get_key_len(mk_lib_crypto_mode_stream_any3_pct const any3) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prro_get_key_len(any3);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any3_ro_get_msg_len(mk_lib_crypto_mode_stream_any3_pct const any3) mk_lang_noexcept
{
	return mk_lib_crypto_mode_stream_any3_prro_get_msg_len(any3);
}


mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any3_rw_set_iv(mk_lib_crypto_mode_stream_any3_pt const any3, mk_sl_cui_uint8_pct const iv_buf, mk_lang_types_sint_t const iv_len) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any3_prrw_set_iv(any3, iv_buf, iv_len);
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any3_rw_set_key_enc(mk_lib_crypto_mode_stream_any3_pt const any3, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_sint_t const key_len) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any3_prrw_set_key_enc(any3, key_buf, key_len);
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any3_rw_set_key_dec(mk_lib_crypto_mode_stream_any3_pt const any3, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_sint_t const key_len) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any3_prrw_set_key_dec(any3, key_buf, key_len);
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any3_rw_encrypt(mk_lib_crypto_mode_stream_any3_pt const any3, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any3_prrw_encrypt(any3, input_buf, input_len, output_buf, output_len, output_used);
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any3_rw_decrypt(mk_lib_crypto_mode_stream_any3_pt const any3, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept
{
	mk_lib_crypto_mode_stream_any3_prrw_decrypt(any3, input_buf, input_len, output_buf, output_len, output_used);
}


#endif
