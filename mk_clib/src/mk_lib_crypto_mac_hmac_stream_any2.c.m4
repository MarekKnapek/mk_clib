include(`mk_lib_crypto_hash.m')dnl
include(`mk_mm_nl.m')dnl
include(`mk_mm_tab.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_stream_any2_c
#define mk_include_guard_mk_lib_crypto_mac_hmac_stream_any2_c
#include "mk_lib_crypto_mac_hmac_stream_any2.h"

#include "mk_lang_assert.h"
#include "mk_lang_inline.h"


mk_lang_forward(mk_sl_cui_uint8);


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_prrw_construct(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_lib_crypto_mac_hmac_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(any2);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end);

	any2->m_data.m_id.m_data.m_id = id;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_prrw_init(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_usize_t const key_len) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end);
	mk_lang_assert(key_buf || key_len == 0);
	mk_lang_assert(key_len >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	switch(any2->m_data.m_id.m_data.m_id)
	{
mk_lib_crypto_hash_mm_for_all(`mk_mm_tab()mk_mm_tab()case mk_lib_crypto_mac_hmac_stream_any1_id_e_$1: mk_lib_crypto_mac_hmac_$1_init(&any2->m_data.m_$1.m_$1.m_$1, key_buf, key_len); break;mk_mm_nl()')dnl
		case mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_prrw_append(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_usize_t const data_len) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	switch(any2->m_data.m_id.m_data.m_id)
	{
mk_lib_crypto_hash_mm_for_all(`mk_mm_tab()mk_mm_tab()case mk_lib_crypto_mac_hmac_stream_any1_id_e_$1: mk_lib_crypto_mac_hmac_$1_append(&any2->m_data.m_$1.m_$1.m_$1, data_buf, data_len); break;mk_mm_nl()')dnl
		case mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_prrw_finish(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_lib_crypto_mac_hmac_stream_any2_digest_pt const digest) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end);
	mk_lang_assert(digest);
	#include "mk_lang_warning_msvc_pop.h"

	switch(any2->m_data.m_id.m_data.m_id)
	{
mk_lib_crypto_hash_mm_for_all(`mk_mm_tab()mk_mm_tab()case mk_lib_crypto_mac_hmac_stream_any1_id_e_$1: mk_lib_crypto_mac_hmac_$1_finish(&any2->m_data.m_$1.m_$1.m_$1, &digest->m_data.m_$1); break;mk_mm_nl()')dnl
		case mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_rw_construct(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_lib_crypto_mac_hmac_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lib_crypto_mac_hmac_stream_any2_prrw_construct(any2, id);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_rw_init(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_usize_t const key_len) mk_lang_noexcept
{
	mk_lib_crypto_mac_hmac_stream_any2_prrw_init(any2, key_buf, key_len);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_rw_append(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_usize_t const data_len) mk_lang_noexcept
{
	mk_lib_crypto_mac_hmac_stream_any2_prrw_append(any2, data_buf, data_len);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_rw_finish(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_lib_crypto_mac_hmac_stream_any2_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_mac_hmac_stream_any2_prrw_finish(any2, digest);
}


#endif
