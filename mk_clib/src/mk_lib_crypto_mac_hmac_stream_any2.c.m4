include(`mk_lib_crypto_hash.m')dnl
include(`mk_mm_nl.m')dnl
include(`mk_mm_tab.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_stream_any2_c
#define mk_include_guard_mk_lib_crypto_mac_hmac_stream_any2_c
#include "mk_lib_crypto_mac_hmac_stream_any2.h"

#include "mk_lang_assert.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


union mk_lib_crypto_mac_hmac_stream_any2_digest_data_u
{
mk_lib_crypto_hash_mm_for_all(`mk_mm_tab()mk_lib_crypto_hash_block_$1_digest_t m_$1;mk_mm_nl()')dnl
};
typedef union mk_lib_crypto_mac_hmac_stream_any2_digest_data_u mk_lib_crypto_mac_hmac_stream_any2_digest_data_t;
struct mk_lib_crypto_mac_hmac_stream_any2_digest_s
{
	mk_lib_crypto_mac_hmac_stream_any2_digest_data_t m_data;
};
typedef struct mk_lib_crypto_mac_hmac_stream_any2_digest_s mk_lib_crypto_mac_hmac_stream_any2_digest_t;
mk_lang_typedef(mk_lib_crypto_mac_hmac_stream_any2_digest);


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_prrw_construct(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_lib_crypto_mac_hmac_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(any2);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end);

	any2->m_data.m_id.m_data.m_id = id;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_crypto_mac_hmac_stream_any2_prro_get_tag_len(mk_lib_crypto_mac_hmac_stream_any2_pct const any2) mk_lang_noexcept
{
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end);

	mk_lang_clobber(&r);
	switch(any2->m_data.m_id.m_data.m_id)
	{
mk_lib_crypto_hash_mm_for_all(`mk_mm_tab()mk_mm_tab()case mk_lib_crypto_mac_hmac_stream_any1_id_e_$1: r = mk_lib_crypto_hash_block_$1_digest_len_v; break;mk_mm_nl()')dnl
		case mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return r;
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

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_prrw_finish(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_sl_cui_uint8_pt const digest_buf, mk_lang_types_usize_t const digest_len, mk_lang_types_usize_pt const digest_out) mk_lang_noexcept
{
	mk_lib_crypto_mac_hmac_stream_any2_digest_t digest mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end);
	mk_lang_assert(digest_buf || digest_len == 0);
	mk_lang_assert(digest_len >= 0);
	mk_lang_assert(digest_out);
	#include "mk_lang_warning_msvc_pop.h"

	switch(any2->m_data.m_id.m_data.m_id)
	{
mk_lib_crypto_hash_mm_for_all(`mk_mm_tab()mk_mm_tab()case mk_lib_crypto_mac_hmac_stream_any1_id_e_$1: if(digest_len >= mk_lib_crypto_hash_block_$1_digest_len_v){ mk_lib_crypto_mac_hmac_$1_finish(&any2->m_data.m_$1.m_$1.m_$1, &digest.m_data.m_$1); mk_sl_cui_uint8_memcpy_fn(digest_buf, &digest.m_data.m_$1.m_data.m_uint8s[0], mk_lib_crypto_hash_block_$1_digest_len_v); *digest_out = mk_lib_crypto_hash_block_$1_digest_len_v; }else{ *digest_out = 0; } break;mk_mm_nl()')dnl
		case mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_rw_construct(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_lib_crypto_mac_hmac_stream_any1_id_t const id) mk_lang_noexcept
{
	mk_lib_crypto_mac_hmac_stream_any2_prrw_construct(any2, id);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mac_hmac_stream_any2_ro_get_tag_len(mk_lib_crypto_mac_hmac_stream_any2_pct const any2) mk_lang_noexcept
{
	return mk_lib_crypto_mac_hmac_stream_any2_prro_get_tag_len(any2);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_rw_init(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_usize_t const key_len) mk_lang_noexcept
{
	mk_lib_crypto_mac_hmac_stream_any2_prrw_init(any2, key_buf, key_len);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_rw_append(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_usize_t const data_len) mk_lang_noexcept
{
	mk_lib_crypto_mac_hmac_stream_any2_prrw_append(any2, data_buf, data_len);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any2_rw_finish(mk_lib_crypto_mac_hmac_stream_any2_pt const any2, mk_sl_cui_uint8_pt const digest_buf, mk_lang_types_usize_t const digest_len, mk_lang_types_usize_pt const digest_out) mk_lang_noexcept
{
	mk_lib_crypto_mac_hmac_stream_any2_prrw_finish(any2, digest_buf, digest_len, digest_out);
}


#endif
