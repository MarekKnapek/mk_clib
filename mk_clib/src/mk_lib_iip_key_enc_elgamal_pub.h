#ifndef mk_include_guard_mk_lib_iip_key_enc_elgamal_pub_h
#define mk_include_guard_mk_lib_iip_key_enc_elgamal_pub_h


#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_pub_integer_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((256 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_pub_integer_double
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (2 * ((256 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s(mk_lib_iip_key_enc_elgamal_pub_integer_single_pct const a, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double(mk_lib_iip_key_enc_elgamal_pub_integer_single_pct const a, mk_lib_iip_key_enc_elgamal_pub_integer_double_pt const b) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single(mk_lib_iip_key_enc_elgamal_pub_integer_double_pct const a, mk_lib_iip_key_enc_elgamal_pub_integer_single_pt const b) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_load_g(mk_lib_iip_key_enc_elgamal_pub_integer_single_pt const x) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_load_p(mk_lib_iip_key_enc_elgamal_pub_integer_single_pt const x) mk_lang_noexcept;

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be(mk_lib_iip_key_enc_elgamal_pub_integer_single_pt const a, mk_lang_static_param(mk_sl_cui_uint8_ct, b, mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_mod_pow(mk_lib_iip_key_enc_elgamal_pub_integer_single_prct const base, mk_lib_iip_key_enc_elgamal_pub_integer_single_prct const exponent, mk_lib_iip_key_enc_elgamal_pub_integer_single_prct const modulus, mk_lib_iip_key_enc_elgamal_pub_integer_single_prt const result) mk_lang_noexcept;


union mk_lib_iip_key_enc_elgamal_pub_data_u
{
	mk_lib_iip_key_enc_elgamal_pub_integer_single_t m_integer;
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_key_enc_elgamal_pub_data_u mk_lib_iip_key_enc_elgamal_pub_data_t;
struct mk_lib_iip_key_enc_elgamal_pub_s
{
	mk_lib_iip_key_enc_elgamal_pub_data_t m_data;
};
typedef struct mk_lib_iip_key_enc_elgamal_pub_s mk_lib_iip_key_enc_elgamal_pub_t;
mk_lang_typedef(mk_lib_iip_key_enc_elgamal_pub);


#if mk_lang_jumbo_have
#include "mk_lib_iip_key_enc_elgamal_pub.c"
#endif
#endif
