include(`mk_lib_crypto_hash.m')dnl
include(`mk_mm_nl.m')dnl
include(`mk_mm_tab.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_stream_any1_h
#define mk_include_guard_mk_lib_crypto_mac_hmac_stream_any1_h

#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


mk_lib_crypto_hash_mm_for_all(`mk_lang_forward(mk_lib_crypto_mac_hmac_$1);mk_mm_nl()'`')dnl

mk_lib_crypto_hash_mm_for_all(`mk_lang_forward(mk_lib_crypto_hash_block_$1_digest); typedef mk_lib_crypto_hash_block_$1_digest_t mk_lib_crypto_mac_hmac_$1_digest_t; typedef mk_lib_crypto_mac_hmac_$1_digest_t* mk_lib_crypto_mac_hmac_$1_digest_pt;mk_mm_nl()'`')dnl


enum mk_lib_crypto_mac_hmac_stream_any1_id_e
{
mk_lib_crypto_hash_mm_for_all(`mk_mm_tab()`'mk_lib_crypto_mac_hmac_stream_any1_id_e_$1,mk_mm_nl()')dnl
	mk_lib_crypto_mac_hmac_stream_any1_id_e_dummy_end
};
typedef enum mk_lib_crypto_mac_hmac_stream_any1_id_e mk_lib_crypto_mac_hmac_stream_any1_id_t;


union mk_lib_crypto_mac_hmac_stream_any1_bigid_data_u
{
	mk_lib_crypto_mac_hmac_stream_any1_id_t m_id;
	mk_lang_types_void_pt m_align;
};
typedef union mk_lib_crypto_mac_hmac_stream_any1_bigid_data_u mk_lib_crypto_mac_hmac_stream_any1_bigid_data_t;
struct mk_lib_crypto_mac_hmac_stream_any1_bigid_s
{
	mk_lib_crypto_mac_hmac_stream_any1_bigid_data_t m_data;
};
typedef struct mk_lib_crypto_mac_hmac_stream_any1_bigid_s mk_lib_crypto_mac_hmac_stream_any1_bigid_t;


union mk_lib_crypto_mac_hmac_stream_any1_digest_ptr_data_u
{
	mk_lang_types_void_pt m_void;
mk_lib_crypto_hash_mm_for_all(`mk_mm_tab()`'mk_lib_crypto_mac_hmac_$1_digest_pt m_$1;`'mk_mm_nl()')dnl
};
typedef union mk_lib_crypto_mac_hmac_stream_any1_digest_ptr_data_u mk_lib_crypto_mac_hmac_stream_any1_digest_ptr_data_t;
struct mk_lib_crypto_mac_hmac_stream_any1_digest_ptr_s
{
	mk_lib_crypto_mac_hmac_stream_any1_digest_ptr_data_t m_data;
};
typedef struct mk_lib_crypto_mac_hmac_stream_any1_digest_ptr_s mk_lib_crypto_mac_hmac_stream_any1_digest_ptr_t;
mk_lang_typedef(mk_lib_crypto_mac_hmac_stream_any1_digest_ptr);

union mk_lib_crypto_mac_hmac_stream_any1_ptr_data_u
{
	mk_lang_types_void_pt m_void;
mk_lib_crypto_hash_mm_for_all(`mk_mm_tab()`'mk_lib_crypto_mac_hmac_$1_pt m_$1;`'mk_mm_nl()')dnl
};
typedef union mk_lib_crypto_mac_hmac_stream_any1_ptr_data_u mk_lib_crypto_mac_hmac_stream_any1_ptr_data_t;
struct mk_lib_crypto_mac_hmac_stream_any1_ptr_s
{
	mk_lib_crypto_mac_hmac_stream_any1_ptr_data_t m_data;
};
typedef struct mk_lib_crypto_mac_hmac_stream_any1_ptr_s mk_lib_crypto_mac_hmac_stream_any1_ptr_t;
mk_lang_typedef(mk_lib_crypto_mac_hmac_stream_any1_ptr);


struct mk_lib_crypto_mac_hmac_stream_any1_ptrid_s
{
	mk_lib_crypto_mac_hmac_stream_any1_bigid_t m_id;
	mk_lib_crypto_mac_hmac_stream_any1_ptr_t m_ptr;
};
typedef struct mk_lib_crypto_mac_hmac_stream_any1_ptrid_s mk_lib_crypto_mac_hmac_stream_any1_ptrid_t;
mk_lang_typedef(mk_lib_crypto_mac_hmac_stream_any1_ptrid);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any1_ptr_rw_init(mk_lib_crypto_mac_hmac_stream_any1_ptr_pt const hmac, mk_lib_crypto_mac_hmac_stream_any1_id_t const id, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_usize_t const key_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any1_ptr_rw_append(mk_lib_crypto_mac_hmac_stream_any1_ptr_pt const hmac, mk_lib_crypto_mac_hmac_stream_any1_id_t const id, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_usize_t const data_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any1_ptr_rw_finish(mk_lib_crypto_mac_hmac_stream_any1_ptr_pt const hmac, mk_lib_crypto_mac_hmac_stream_any1_id_t const id, mk_lib_crypto_mac_hmac_stream_any1_digest_ptr_pt const digest) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any1_ptrid_rw_init(mk_lib_crypto_mac_hmac_stream_any1_ptrid_pt const any1, mk_sl_cui_uint8_pct const key_buf, mk_lang_types_usize_t const key_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any1_ptrid_rw_append(mk_lib_crypto_mac_hmac_stream_any1_ptrid_pt const any1, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_usize_t const data_len) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mac_hmac_stream_any1_ptrid_rw_finish(mk_lib_crypto_mac_hmac_stream_any1_ptrid_pt const any1, mk_lib_crypto_mac_hmac_stream_any1_digest_ptr_pt const digest) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_mac_hmac_stream_any1.c"
#endif
#endif
