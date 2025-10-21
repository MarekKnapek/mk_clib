include(`mk_lib_crypto_mode_stream.m')dnl
#ifndef mk_include_guard_mk_lib_crypto_mode_stream_any1_h
#define mk_include_guard_mk_lib_crypto_mode_stream_any1_h

#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


define(`mk_lib_crypto_mode_stream_any1_h_mm_forwards', `dnl
mk_lang_forward(mk_lib_crypto_mode_stream_$1_$2);
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_h_mm_forwards', mk_lib_crypto_mode_stream_mm_list())dnl

define(`mk_lib_crypto_mode_stream_any1_h_mm_iv_forwards', `dnl
mk_lang_forward(mk_lib_crypto_mode_stream_$1_$2_iv);
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_h_mm_iv_forwards', mk_lib_crypto_mode_stream_mm_list())dnl

define(`mk_lib_crypto_mode_stream_any1_h_mm_key_forwards', `dnl
mk_lang_forward(mk_lib_crypto_mode_stream_$1_$2_key);
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_h_mm_key_forwards', mk_lib_crypto_mode_stream_mm_list())dnl


enum mk_lib_crypto_mode_stream_any1_id_e
{
define(`mk_lib_crypto_mode_stream_any1_h_mm_enum', `dnl
	mk_lib_crypto_mode_stream_any1_id_e_$1_$2,
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_h_mm_enum', mk_lib_crypto_mode_stream_mm_list())dnl
	mk_lib_crypto_mode_stream_any1_id_e_dummy_end
};
typedef enum mk_lib_crypto_mode_stream_any1_id_e mk_lib_crypto_mode_stream_any1_id_t;

union mk_lib_crypto_mode_stream_any1_bigid_data_u
{
	mk_lib_crypto_mode_stream_any1_id_t m_id;
	mk_lang_types_void_pt m_align;
};
typedef union mk_lib_crypto_mode_stream_any1_bigid_data_u mk_lib_crypto_mode_stream_any1_bigid_data_t;
struct mk_lib_crypto_mode_stream_any1_bigid_s
{
	mk_lib_crypto_mode_stream_any1_bigid_data_t m_data;
};
typedef struct mk_lib_crypto_mode_stream_any1_bigid_s mk_lib_crypto_mode_stream_any1_bigid_t;


union mk_lib_crypto_mode_stream_civ_any1_ptr_data_u
{
	mk_lang_types_void_pct m_void;
define(`mk_lib_crypto_mode_stream_any1_h_mm_iv_member_data', `dnl
	mk_lib_crypto_mode_stream_$1_$2_iv_pct m_$1_$2;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_h_mm_iv_member_data', mk_lib_crypto_mode_stream_mm_list())dnl
};
typedef union mk_lib_crypto_mode_stream_civ_any1_ptr_data_u mk_lib_crypto_mode_stream_civ_any1_ptr_data_t;
struct mk_lib_crypto_mode_stream_civ_any1_ptr_s
{
	mk_lib_crypto_mode_stream_civ_any1_ptr_data_t m_data;
};
typedef struct mk_lib_crypto_mode_stream_civ_any1_ptr_s mk_lib_crypto_mode_stream_civ_any1_ptr_t;
mk_lang_typedef(mk_lib_crypto_mode_stream_civ_any1_ptr);

union mk_lib_crypto_mode_stream_ckey_any1_ptr_data_u
{
	mk_lang_types_void_pct m_void;
define(`mk_lib_crypto_mode_stream_any1_h_mm_key_member_data', `dnl
	mk_lib_crypto_mode_stream_$1_$2_key_pct m_$1_$2;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_h_mm_key_member_data', mk_lib_crypto_mode_stream_mm_list())dnl
};
typedef union mk_lib_crypto_mode_stream_ckey_any1_ptr_data_u mk_lib_crypto_mode_stream_ckey_any1_ptr_data_t;
struct mk_lib_crypto_mode_stream_ckey_any1_ptr_s
{
	mk_lib_crypto_mode_stream_ckey_any1_ptr_data_t m_data;
};
typedef struct mk_lib_crypto_mode_stream_ckey_any1_ptr_s mk_lib_crypto_mode_stream_ckey_any1_ptr_t;
mk_lang_typedef(mk_lib_crypto_mode_stream_ckey_any1_ptr);

union mk_lib_crypto_mode_stream_any1_ptr_data_u
{
	mk_lang_types_void_pt m_void;
define(`mk_lib_crypto_mode_stream_any1_h_mm_member_data', `dnl
	mk_lib_crypto_mode_stream_$1_$2_pt m_$1_$2;
')`'dnl
mk_lib_crypto_mode_stream_mm_recurse(`mk_lib_crypto_mode_stream_any1_h_mm_member_data', mk_lib_crypto_mode_stream_mm_list())dnl
};
typedef union mk_lib_crypto_mode_stream_any1_ptr_data_u mk_lib_crypto_mode_stream_any1_ptr_data_t;
struct mk_lib_crypto_mode_stream_any1_ptr_s
{
	mk_lib_crypto_mode_stream_any1_ptr_data_t m_data;
};
typedef struct mk_lib_crypto_mode_stream_any1_ptr_s mk_lib_crypto_mode_stream_any1_ptr_t;
mk_lang_typedef(mk_lib_crypto_mode_stream_any1_ptr);


struct mk_lib_crypto_mode_stream_any1_ptrid_s
{
	mk_lib_crypto_mode_stream_any1_bigid_t m_id;
	mk_lib_crypto_mode_stream_any1_ptr_t m_ptr;
};
typedef struct mk_lib_crypto_mode_stream_any1_ptrid_s mk_lib_crypto_mode_stream_any1_ptrid_t;
mk_lang_typedef(mk_lib_crypto_mode_stream_any1_ptrid);


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any1_iv_len_v(mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any1_key_len_v(mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_crypto_mode_stream_any1_msg_len_v(mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptr_rw_set_iv(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_lib_crypto_mode_stream_civ_any1_ptr_pct const iv) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptr_rw_set_key_enc(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptr_rw_set_key_dec(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptr_rw_encrypt(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptr_rw_decrypt(mk_lib_crypto_mode_stream_any1_ptr_pt const ptr, mk_lib_crypto_mode_stream_any1_id_t const id, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_construct(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_any1_id_t const id) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_set_iv(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_civ_any1_ptr_pct const iv) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_set_key_enc(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_set_key_dec(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_lib_crypto_mode_stream_ckey_any1_ptr_pct const key) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_encrypt(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_crypto_mode_stream_any1_ptrid_rw_decrypt(mk_lib_crypto_mode_stream_any1_ptrid_pt const any1, mk_sl_cui_uint8_pct const input_buf, mk_lang_types_usize_t const input_len, mk_sl_cui_uint8_pt const output_buf, mk_lang_types_usize_t const output_len, mk_lang_types_usize_pt const output_used) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_crypto_mode_stream_any1.c"
#endif
#endif
