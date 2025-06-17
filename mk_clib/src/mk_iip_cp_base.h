#ifndef mk_include_guard_mk_iip_cp_base_h
#define mk_include_guard_mk_iip_cp_base_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_lib_iip_integer.h"


union mk_iip_cp_base_dsa_key_pri_data_u
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t m_val;
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_iip_cp_base_dsa_key_pri_data_u mk_iip_cp_base_dsa_key_pri_data_t;

struct mk_iip_cp_base_dsa_key_pri_s
{
	mk_iip_cp_base_dsa_key_pri_data_t m_data;
};
typedef struct mk_iip_cp_base_dsa_key_pri_s mk_iip_cp_base_dsa_key_pri_t;
typedef mk_iip_cp_base_dsa_key_pri_t const mk_iip_cp_base_dsa_key_pri_ct;
typedef mk_iip_cp_base_dsa_key_pri_t* mk_iip_cp_base_dsa_key_pri_pt;
typedef mk_iip_cp_base_dsa_key_pri_t const* mk_iip_cp_base_dsa_key_pri_pct;

union mk_iip_cp_base_dsa_key_pub_data_u
{
	mk_lib_iip_integer_dsa_sha1_pub_single_t m_val;
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_iip_cp_base_dsa_key_pub_data_u mk_iip_cp_base_dsa_key_pub_data_t;

struct mk_iip_cp_base_dsa_key_pub_s
{
	mk_iip_cp_base_dsa_key_pub_data_t m_data;
};
typedef struct mk_iip_cp_base_dsa_key_pub_s mk_iip_cp_base_dsa_key_pub_t;
typedef mk_iip_cp_base_dsa_key_pub_t const mk_iip_cp_base_dsa_key_pub_ct;
typedef mk_iip_cp_base_dsa_key_pub_t* mk_iip_cp_base_dsa_key_pub_pt;
typedef mk_iip_cp_base_dsa_key_pub_t const* mk_iip_cp_base_dsa_key_pub_pct;

struct mk_iip_cp_base_dsa_signature_rs_s
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t m_r;
	mk_lib_iip_integer_dsa_sha1_pri_single_t m_s;
};
typedef struct mk_iip_cp_base_dsa_signature_rs_s mk_iip_cp_base_dsa_signature_rs_t;

union mk_iip_cp_base_dsa_signature_data_u
{
	mk_iip_cp_base_dsa_signature_rs_t m_rs;
	mk_sl_cui_uint8_t m_uint8s[40];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_iip_cp_base_dsa_signature_data_u mk_iip_cp_base_dsa_signature_data_t;

struct mk_iip_cp_base_dsa_signature_s
{
	mk_iip_cp_base_dsa_signature_data_t m_data;
};
typedef struct mk_iip_cp_base_dsa_signature_s mk_iip_cp_base_dsa_signature_t;
typedef mk_iip_cp_base_dsa_signature_t const mk_iip_cp_base_dsa_signature_ct;
typedef mk_iip_cp_base_dsa_signature_t* mk_iip_cp_base_dsa_signature_pt;
typedef mk_iip_cp_base_dsa_signature_t const* mk_iip_cp_base_dsa_signature_pct;

enum mk_iip_cp_base_dsa_signature_len_e { mk_iip_cp_base_dsa_signature_len_v = 2 * mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v }; typedef enum mk_iip_cp_base_dsa_signature_len_e mk_iip_cp_base_dsa_signature_len_t;


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_base_dsa_key_pri_generate_public(mk_iip_cp_base_dsa_key_pri_pct const pri, mk_iip_cp_base_dsa_key_pub_pt const pub) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_base_dsa_generate_k(mk_lib_iip_integer_dsa_sha1_pri_single_pct const dsa_q, mk_lib_iip_integer_dsa_sha1_pri_single_pt const outk) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_base_dsa_sign_k_has_y(mk_iip_cp_base_dsa_key_pri_pct const pri, mk_lib_iip_integer_dsa_sha1_pri_single_pct const k, mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_iip_cp_base_dsa_signature_pt const signature) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_iip_cp_base_dsa_sign_k_has_n(mk_iip_cp_base_dsa_key_pri_pct const pri, mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_iip_cp_base_dsa_signature_pt const signature) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_base.c"
#endif
#endif
