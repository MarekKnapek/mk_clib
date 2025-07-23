#ifndef mk_include_guard_mk_lib_iip_key_sgn_dsa_sha1_pub_c
#define mk_include_guard_mk_lib_iip_key_sgn_dsa_sha1_pub_c
#include "mk_lib_iip_key_sgn_dsa_sha1_pub.h"

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
#include "mk_lib_iip_key_sgn_dsa_sha1_pri.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


#define mk_sl_cui_t_name mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((128 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (2 * ((128 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


union mk_lib_iip_key_sgn_dsa_sha1_pub_uchars_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v];
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t m_align;
};
typedef union mk_lib_iip_key_sgn_dsa_sha1_pub_uchars_data_u mk_lib_iip_key_sgn_dsa_sha1_pub_uchars_data_t;
struct mk_lib_iip_key_sgn_dsa_sha1_pub_uchars_s
{
	mk_lang_alignas(64) mk_lib_iip_key_sgn_dsa_sha1_pub_uchars_data_t m_data;
};
typedef struct mk_lib_iip_key_sgn_dsa_sha1_pub_uchars_s mk_lib_iip_key_sgn_dsa_sha1_pub_uchars_t;


mk_lang_constexpr_static_inline mk_lib_iip_key_sgn_dsa_sha1_pub_uchars_t const mk_lib_iip_key_sgn_dsa_sha1_pub_k_g =
{{{
	0x0c, 0x1f, 0x4d, 0x27, 0xd4, 0x00, 0x93, 0xb4, 0x29, 0xe9, 0x62, 0xd7, 0x22, 0x38, 0x24, 0xe0,
	0xbb, 0xc4, 0x7e, 0x7c, 0x83, 0x2a, 0x39, 0x23, 0x6f, 0xc6, 0x83, 0xaf, 0x84, 0x88, 0x95, 0x81,
	0x07, 0x5f, 0xf9, 0x08, 0x2e, 0xd3, 0x23, 0x53, 0xd4, 0x37, 0x4d, 0x73, 0x01, 0xcd, 0xa1, 0xd2,
	0x3c, 0x43, 0x1f, 0x46, 0x98, 0x59, 0x9d, 0xda, 0x02, 0x45, 0x18, 0x24, 0xff, 0x36, 0x97, 0x52,
	0x59, 0x36, 0x47, 0xcc, 0x3d, 0xdc, 0x19, 0x7d, 0xe9, 0x85, 0xe4, 0x3d, 0x13, 0x6c, 0xdc, 0xfc,
	0x6b, 0xd5, 0x40, 0x9c, 0xd2, 0xf4, 0x50, 0x82, 0x11, 0x42, 0xa5, 0xe6, 0xf8, 0xeb, 0x1c, 0x3a,
	0xb5, 0xd0, 0x48, 0x4b, 0x81, 0x29, 0xfc, 0xf1, 0x7b, 0xce, 0x4f, 0x7f, 0x33, 0x32, 0x1c, 0x3c,
	0xb3, 0xdb, 0xb1, 0x4a, 0x90, 0x5e, 0x7b, 0x2b, 0x3e, 0x93, 0xbe, 0x47, 0x08, 0xcb, 0xcc, 0x82,
}}};

mk_lang_constexpr_static_inline mk_lib_iip_key_sgn_dsa_sha1_pub_uchars_t const mk_lib_iip_key_sgn_dsa_sha1_pub_k_p =
{{{
	0x9c, 0x05, 0xb2, 0xaa, 0x96, 0x0d, 0x9b, 0x97, 0xb8, 0x93, 0x19, 0x63, 0xc9, 0xcc, 0x9e, 0x8c,
	0x30, 0x26, 0xe9, 0xb8, 0xed, 0x92, 0xfa, 0xd0, 0xa6, 0x9c, 0xc8, 0x86, 0xd5, 0xbf, 0x80, 0x15,
	0xfc, 0xad, 0xae, 0x31, 0xa0, 0xad, 0x18, 0xfa, 0xb3, 0xf0, 0x1b, 0x00, 0xa3, 0x58, 0xde, 0x23,
	0x76, 0x55, 0xc4, 0x96, 0x4a, 0xfa, 0xa2, 0xb3, 0x37, 0xe9, 0x6a, 0xd3, 0x16, 0xb9, 0xfb, 0x1c,
	0xc5, 0x64, 0xb5, 0xae, 0xc5, 0xb6, 0x9a, 0x9f, 0xf6, 0xc3, 0xe4, 0x54, 0x87, 0x07, 0xfe, 0xf8,
	0x50, 0x3d, 0x91, 0xdd, 0x86, 0x02, 0xe8, 0x67, 0xe6, 0xd3, 0x5d, 0x22, 0x35, 0xc1, 0x86, 0x9c,
	0xe2, 0x47, 0x9c, 0x3b, 0x9d, 0x54, 0x01, 0xde, 0x04, 0xe0, 0x72, 0x7f, 0xb3, 0x3d, 0x65, 0x11,
	0x28, 0x5d, 0x4c, 0xf2, 0x95, 0x38, 0xd9, 0xe3, 0xb6, 0x05, 0x1f, 0x5b, 0x22, 0xcc, 0x1c, 0x93,
}}};


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_u8s(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_pct const a, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_u8s_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v];
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t m_integer;
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_u8s_storage_data_u mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_u8s_storage_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_u8s_storage_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_u8s_storage_s mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_u8s_storage_t;

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_u8s_storage_t storage;

	mk_lang_assert(a);
	mk_lang_assert(u8s);

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_buis_uchar_be(a, &storage.m_data.m_uchars[0]);
	mk_sl_cui_uint8_from_bi_uchar_many(&u8s[0], &storage.m_data.m_uchars[0], mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_load_g(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_from_buis_uchar_be(x, &mk_lib_iip_key_sgn_dsa_sha1_pub_k_g.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_load_p(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_from_buis_uchar_be(x, &mk_lib_iip_key_sgn_dsa_sha1_pub_k_p.m_data.m_uchars[0]);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_pct const a, mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_size_bytes_v)))];
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t m_pub_single;
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_t m_pub_double;
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double_data_u mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double_s mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double_t;

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lang_string_memclr_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v], ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)));
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_pct const a, mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_size_bytes_v)))];
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t m_pub_single;
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_t m_pub_double;
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single_data_u mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single_s mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single_t;

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pri_single(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_pct const a, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pri_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)))];
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t m_pub_single;
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t m_pri_single;
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pri_single_data_u mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pri_single_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pri_single_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pri_single_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pri_single_s mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pri_single_t;

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pri_single_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_size_bytes_v)) >= ((mk_lang_types_sint_t)(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_mod_pow_a(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_prct const base, mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_prct const exponent, mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_prct const modulus, mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_prt const result) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_t dbase mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_t dmodulus mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_t dresult mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t sexponent mk_lang_constexpr_init;

	mk_lang_assert(base);
	mk_lang_assert(exponent);
	mk_lang_assert(modulus);
	mk_lang_assert(result);
	mk_lang_assert(base != exponent);
	mk_lang_assert(base != modulus);
	mk_lang_assert(base != result);
	mk_lang_assert(exponent != modulus);
	mk_lang_assert(exponent != result);
	mk_lang_assert(modulus != result);

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double(base, &dbase);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double(modulus, &dmodulus);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_set_one(&dresult);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_assign(&sexponent, exponent);
	while(!mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_is_zero(&sexponent))
	{
		if(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_has_lsb(&sexponent))
		{
			mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_mul2_wrap_lo(&dresult, &dbase);
			mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_mod2_wrap(&dresult, &dmodulus);
		}
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_shr2(&sexponent, 1);
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_mul2_wrap_lo(&dbase, &dbase);
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_mod2_wrap(&dbase, &dmodulus);
	}
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single(&dresult, result);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_mod_pow_b(mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_prct const base, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const exponent, mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_prct const modulus_a, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prct const modulus_b, mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_prt const result) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_t dbase mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_t dmodulusa mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_t dresult mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_t sexponent mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t sresult mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_t smodulusb mk_lang_constexpr_init;

	mk_lang_assert(base);
	mk_lang_assert(exponent);
	mk_lang_assert(modulus_a);
	mk_lang_assert(modulus_b);
	mk_lang_assert(result);
	/*mk_lang_assert(base != exponent);*/
	mk_lang_assert(base != modulus_a);
	/*mk_lang_assert(base != modulus_b);*/
	/*mk_lang_assert(base != result);*/
	/*mk_lang_assert(exponent != modulus_a);*/
	mk_lang_assert(exponent != modulus_b);
	mk_lang_assert(exponent != result);
	/*mk_lang_assert(modulus_a != modulus_b);*/
	/*mk_lang_assert(modulus_a != result);*/
	mk_lang_assert(modulus_b != result);

	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double(base, &dbase);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pub_double(modulus_a, &dmodulusa);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_set_one(&dresult);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_assign(&sexponent, exponent);
	while(!mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_is_zero(&sexponent))
	{
		if(mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_has_lsb(&sexponent))
		{
			mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_mul2_wrap_lo(&dresult, &dbase);
			mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_mod2_wrap(&dresult, &dmodulusa);
		}
		mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_shr2(&sexponent, 1);
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_mul2_wrap_lo(&dbase, &dbase);
		mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_mod2_wrap(&dbase, &dmodulusa);
	}
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_double_to_pub_single(&dresult, &sresult);
	mk_lib_iip_key_sgn_dsa_sha1_pri_integer_single_to_pub_single(modulus_b, &smodulusb);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_mod2_wrap(&sresult, &smodulusb);
	mk_lib_iip_key_sgn_dsa_sha1_pub_integer_single_to_pri_single(&sresult, result);
}


#endif
