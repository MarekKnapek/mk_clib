#ifndef mk_include_guard_mk_lib_iip_key_enc_elgamal_pri_h
#define mk_include_guard_mk_lib_iip_key_enc_elgamal_pri_h


#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_lib_iip_key_enc_elgamal_pub);
mk_lang_forward(mk_lib_iip_key_enc_elgamal_pub_integer_single);


#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_pri_integer_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((256 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_pri_integer_double
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (2 * ((256 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single(mk_lib_iip_key_enc_elgamal_pri_integer_single_pct const a, mk_lib_iip_key_enc_elgamal_pub_integer_single_pt const b) mk_lang_noexcept;


union mk_lib_iip_key_enc_elgamal_pri_data_u
{
	mk_lib_iip_key_enc_elgamal_pri_integer_single_t m_integer;
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_key_enc_elgamal_pri_data_u mk_lib_iip_key_enc_elgamal_pri_data_t;
struct mk_lib_iip_key_enc_elgamal_pri_s
{
	mk_lib_iip_key_enc_elgamal_pri_data_t m_data;
};
typedef struct mk_lib_iip_key_enc_elgamal_pri_s mk_lib_iip_key_enc_elgamal_pri_t;
mk_lang_typedef(mk_lib_iip_key_enc_elgamal_pri);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_pri_generate_random(mk_lib_iip_key_enc_elgamal_pri_pt const pri) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pri_compute_public(mk_lib_iip_key_enc_elgamal_pri_pct const pri, mk_lib_iip_key_enc_elgamal_pub_pt const pub) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_key_enc_elgamal_pri.c"
#endif
#endif
