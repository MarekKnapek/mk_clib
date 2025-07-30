#ifndef mk_include_guard_mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_c
#define mk_include_guard_mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_c
#include "mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_static_param.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


#define mk_sl_cui_t_name mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((64 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_from_u8s_be(mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_pt const a, mk_lang_static_param(mk_sl_cui_uint8_ct, b, mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_size_bytes_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_from_u8s_be_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_size_bytes_v];
		mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_t m_pri_single;
	};
	typedef union mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_from_u8s_be_data_u mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_from_u8s_be_data_t;
	struct mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_from_u8s_be_s
	{
		mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_from_u8s_be_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_from_u8s_be_s mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_from_u8s_be_t;

	mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_from_u8s_be_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint8_to_bi_uchar_many(&b[0], &storage.m_data.m_uchars[0], mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_size_bytes_v);
	mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_from_buis_uchar_be(a, &storage.m_data.m_uchars[0]);
}


 #endif
