#ifndef mk_include_guard_mk_lib_iip_key_enc_elgamal_h
#define mk_include_guard_mk_lib_iip_key_enc_elgamal_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_bytes.h"
#include "mk_sl_cui_uint8.h"


#define mk_lib_iip_key_enc_elgamal_priv_len_d (2 * 1024 / 8) /* 256 */
#define mk_lib_iip_key_enc_elgamal_publ_len_d (2 * 1024 / 8) /* 256 */

enum mk_lib_iip_key_enc_elgamal_priv_len_e{ mk_lib_iip_key_enc_elgamal_priv_len_v = mk_lib_iip_key_enc_elgamal_priv_len_d }; typedef enum mk_lib_iip_key_enc_elgamal_priv_len_e mk_lib_iip_key_enc_elgamal_priv_len_t;
enum mk_lib_iip_key_enc_elgamal_publ_len_e{ mk_lib_iip_key_enc_elgamal_publ_len_v = mk_lib_iip_key_enc_elgamal_publ_len_d }; typedef enum mk_lib_iip_key_enc_elgamal_publ_len_e mk_lib_iip_key_enc_elgamal_publ_len_t;


union mk_lib_iip_key_enc_elgamal_priv_data_u
{
	mk_lib_iip_cp_bytes_256_t m_bytes;
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_key_enc_elgamal_priv_data_u mk_lib_iip_key_enc_elgamal_priv_data_t;
struct mk_lib_iip_key_enc_elgamal_priv_s
{
	mk_lib_iip_key_enc_elgamal_priv_data_t m_data;
};
typedef struct mk_lib_iip_key_enc_elgamal_priv_s mk_lib_iip_key_enc_elgamal_priv_t;
mk_lang_typedef(mk_lib_iip_key_enc_elgamal_priv);

union mk_lib_iip_key_enc_elgamal_publ_data_u
{
	mk_lib_iip_cp_bytes_256_t m_bytes;
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_key_enc_elgamal_publ_data_u mk_lib_iip_key_enc_elgamal_publ_data_t;
struct mk_lib_iip_key_enc_elgamal_publ_s
{
	mk_lib_iip_key_enc_elgamal_publ_data_t m_data;
};
typedef struct mk_lib_iip_key_enc_elgamal_publ_s mk_lib_iip_key_enc_elgamal_publ_t;
mk_lang_typedef(mk_lib_iip_key_enc_elgamal_publ);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_is_valid(mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_priv_len_v), mk_lang_types_bool_pt const is_valid) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_construct_random(mk_lib_iip_key_enc_elgamal_priv_pt const pri) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_construct_from_u8s(mk_lib_iip_key_enc_elgamal_priv_pt const pri, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_priv_len_v)) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_destroy(mk_lib_iip_key_enc_elgamal_priv_pt const pri) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_export_pri_to_u8s(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_priv_len_v)) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_export_pub_to_u8s(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_publ_len_v)) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_construct_public(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_lib_iip_key_enc_elgamal_publ_pt const pub) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_decrypt(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pct const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const data_out_act) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_encrypt(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pct const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_act) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_rw_construct_from_pri(mk_lib_iip_key_enc_elgamal_publ_pt const pub, mk_lib_iip_key_enc_elgamal_priv_pct const pri) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_rw_construct_from_u8s(mk_lib_iip_key_enc_elgamal_publ_pt const pub, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_publ_len_v)) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_rw_destroy(mk_lib_iip_key_enc_elgamal_publ_pt const pub) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_rw_export_to_u8s(mk_lib_iip_key_enc_elgamal_publ_pct const pub, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_publ_len_v)) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_rw_encrypt(mk_lib_iip_key_enc_elgamal_publ_pct const pub, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pct const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_act) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_key_enc_elgamal.c"
#endif
#endif
