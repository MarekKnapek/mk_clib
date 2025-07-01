#ifndef mk_include_guard_mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_h
#define mk_include_guard_mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_h


#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


#define mk_sl_cui_t_name mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_integer_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((32 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_integer_single_from_u8s_be(mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_integer_single_pt const a, mk_lang_static_param(mk_sl_cui_uint8_ct, b, mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_integer_single_size_bytes_v)) mk_lang_noexcept;


struct mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_s
{
	mk_lang_types_uchar_t m_ucs[64];
};
typedef struct mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_s mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_t;
mk_lang_typedef(mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature);
enum mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_len_e{ mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_len_v = 64 }; typedef enum mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_len_e mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_len_t;


union mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_data_u
{
	mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_integer_single_t m_integer;
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_data_u mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_data_t;
struct mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_s
{
	mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_data_t m_data;
};
typedef struct mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_s mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_t;
mk_lang_typedef(mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub);


#if mk_lang_jumbo_have
#include "mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub.c"
#endif
#endif
