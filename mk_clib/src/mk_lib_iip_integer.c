#ifndef mk_include_guard_mk_lib_iip_integer_c
#define mk_include_guard_mk_lib_iip_integer_c
#include "mk_lib_iip_integer.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


#define mk_sl_cui_t_name mk_lib_iip_integer_elgamal_single
#define mk_sl_cui_t_base mk_lang_bui_uint
#define mk_sl_cui_t_count (((256 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d) * 1)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_integer_elgamal_double
#define mk_sl_cui_t_base mk_lang_bui_uint
#define mk_sl_cui_t_count (((256 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d) * 2)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_integer_dsa_sha1_pri_single
#define mk_sl_cui_t_base mk_lang_bui_uint
#define mk_sl_cui_t_count (((20 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d) * 1)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_integer_dsa_sha1_pri_double
#define mk_sl_cui_t_base mk_lang_bui_uint
#define mk_sl_cui_t_count (((20 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d) * 2)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_integer_dsa_sha1_pub_single
#define mk_sl_cui_t_base mk_lang_bui_uint
#define mk_sl_cui_t_count (((128 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d) * 1)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_integer_dsa_sha1_pub_double
#define mk_sl_cui_t_base mk_lang_bui_uint
#define mk_sl_cui_t_count (((128 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d) * 2)
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


union mk_lib_iip_integer_elgamal_uchars_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_elgamal_single_size_bytes_v];
	mk_lib_iip_integer_elgamal_single_t m_align;
};
typedef union mk_lib_iip_integer_elgamal_uchars_data_u mk_lib_iip_integer_elgamal_uchars_data_t;
struct mk_lib_iip_integer_elgamal_uchars_s
{
	mk_lang_alignas(64) mk_lib_iip_integer_elgamal_uchars_data_t m_data;
};
typedef struct mk_lib_iip_integer_elgamal_uchars_s mk_lib_iip_integer_elgamal_uchars_t;

#include "mk_lang_warning_msvc_push_c4820.h"
union mk_lib_iip_integer_dsa_sha1_pri_uchars_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v];
	mk_lib_iip_integer_dsa_sha1_pri_single_t m_align;
};
typedef union mk_lib_iip_integer_dsa_sha1_pri_uchars_data_u mk_lib_iip_integer_dsa_sha1_pri_uchars_data_t;
struct mk_lib_iip_integer_dsa_sha1_pri_uchars_s
{
	mk_lang_alignas(32) mk_lib_iip_integer_dsa_sha1_pri_uchars_data_t m_data;
};
typedef struct mk_lib_iip_integer_dsa_sha1_pri_uchars_s mk_lib_iip_integer_dsa_sha1_pri_uchars_t;
#include "mk_lang_warning_msvc_pop.h"

union mk_lib_iip_integer_dsa_sha1_pub_uchars_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pub_single_size_bytes_v];
	mk_lib_iip_integer_dsa_sha1_pub_single_t m_align;
};
typedef union mk_lib_iip_integer_dsa_sha1_pub_uchars_data_u mk_lib_iip_integer_dsa_sha1_pub_uchars_data_t;
struct mk_lib_iip_integer_dsa_sha1_pub_uchars_s
{
	mk_lang_alignas(64) mk_lib_iip_integer_dsa_sha1_pub_uchars_data_t m_data;
};
typedef struct mk_lib_iip_integer_dsa_sha1_pub_uchars_s mk_lib_iip_integer_dsa_sha1_pub_uchars_t;


mk_lang_constexpr_static_inline mk_lib_iip_integer_elgamal_uchars_t const mk_lib_iip_integer_k_elgamal_p =
{{{
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc9, 0x0f, 0xda, 0xa2, 0x21, 0x68, 0xc2, 0x34,
	0xc4, 0xc6, 0x62, 0x8b, 0x80, 0xdc, 0x1c, 0xd1, 0x29, 0x02, 0x4e, 0x08, 0x8a, 0x67, 0xcc, 0x74,
	0x02, 0x0b, 0xbe, 0xa6, 0x3b, 0x13, 0x9b, 0x22, 0x51, 0x4a, 0x08, 0x79, 0x8e, 0x34, 0x04, 0xdd,
	0xef, 0x95, 0x19, 0xb3, 0xcd, 0x3a, 0x43, 0x1b, 0x30, 0x2b, 0x0a, 0x6d, 0xf2, 0x5f, 0x14, 0x37,
	0x4f, 0xe1, 0x35, 0x6d, 0x6d, 0x51, 0xc2, 0x45, 0xe4, 0x85, 0xb5, 0x76, 0x62, 0x5e, 0x7e, 0xc6,
	0xf4, 0x4c, 0x42, 0xe9, 0xa6, 0x37, 0xed, 0x6b, 0x0b, 0xff, 0x5c, 0xb6, 0xf4, 0x06, 0xb7, 0xed,
	0xee, 0x38, 0x6b, 0xfb, 0x5a, 0x89, 0x9f, 0xa5, 0xae, 0x9f, 0x24, 0x11, 0x7c, 0x4b, 0x1f, 0xe6,
	0x49, 0x28, 0x66, 0x51, 0xec, 0xe4, 0x5b, 0x3d, 0xc2, 0x00, 0x7c, 0xb8, 0xa1, 0x63, 0xbf, 0x05,
	0x98, 0xda, 0x48, 0x36, 0x1c, 0x55, 0xd3, 0x9a, 0x69, 0x16, 0x3f, 0xa8, 0xfd, 0x24, 0xcf, 0x5f,
	0x83, 0x65, 0x5d, 0x23, 0xdc, 0xa3, 0xad, 0x96, 0x1c, 0x62, 0xf3, 0x56, 0x20, 0x85, 0x52, 0xbb,
	0x9e, 0xd5, 0x29, 0x07, 0x70, 0x96, 0x96, 0x6d, 0x67, 0x0c, 0x35, 0x4e, 0x4a, 0xbc, 0x98, 0x04,
	0xf1, 0x74, 0x6c, 0x08, 0xca, 0x18, 0x21, 0x7c, 0x32, 0x90, 0x5e, 0x46, 0x2e, 0x36, 0xce, 0x3b,
	0xe3, 0x9e, 0x77, 0x2c, 0x18, 0x0e, 0x86, 0x03, 0x9b, 0x27, 0x83, 0xa2, 0xec, 0x07, 0xa2, 0x8f,
	0xb5, 0xc5, 0x5d, 0xf0, 0x6f, 0x4c, 0x52, 0xc9, 0xde, 0x2b, 0xcb, 0xf6, 0x95, 0x58, 0x17, 0x18,
	0x39, 0x95, 0x49, 0x7c, 0xea, 0x95, 0x6a, 0xe5, 0x15, 0xd2, 0x26, 0x18, 0x98, 0xfa, 0x05, 0x10,
	0x15, 0x72, 0x8e, 0x5a, 0x8a, 0xac, 0xaa, 0x68, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
}}};

mk_lang_constexpr_static_inline mk_lib_iip_integer_dsa_sha1_pri_uchars_t const mk_lib_iip_integer_k_dsa_sha1_pri_q =
{{{
	0xa5, 0xdf, 0xc2, 0x8f, 0xef, 0x4c, 0xa1, 0xe2, 0x86, 0x74, 0x4c, 0xd8, 0xee, 0xd9, 0xd2, 0x9d, 0x68, 0x40, 0x46, 0xb7,
}}};

mk_lang_constexpr_static_inline mk_lib_iip_integer_dsa_sha1_pub_uchars_t const mk_lib_iip_integer_k_dsa_sha1_pub_g =
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

mk_lang_constexpr_static_inline mk_lib_iip_integer_dsa_sha1_pub_uchars_t const mk_lib_iip_integer_k_dsa_sha1_pub_p =
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


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_elgamal_single_load_p(mk_lib_iip_integer_elgamal_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_integer_elgamal_single_from_buis_uchar_be(x, &mk_lib_iip_integer_k_elgamal_p.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_elgamal_single_to_double(mk_lib_iip_integer_elgamal_single_pct const a, mk_lib_iip_integer_elgamal_double_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_integer_elgamal_single_to_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_elgamal_double_size_bytes_v];
		mk_lib_iip_integer_elgamal_single_t m_single;
		mk_lib_iip_integer_elgamal_double_t m_double;
	};
	typedef union mk_lib_iip_integer_elgamal_single_to_double_data_u mk_lib_iip_integer_elgamal_single_to_double_data_t;
	struct mk_lib_iip_integer_elgamal_single_to_double_s
	{
		mk_lib_iip_integer_elgamal_single_to_double_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_elgamal_single_to_double_s mk_lib_iip_integer_elgamal_single_to_double_t;

	mk_lang_types_uchar_t zero mk_lang_constexpr_init;
	mk_lib_iip_integer_elgamal_single_to_double_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_integer_elgamal_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	zero = 0; mk_lang_string_memset_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_integer_elgamal_single_size_bytes_v], &zero, ((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_double_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_single_size_bytes_v)));
	mk_lib_iip_integer_elgamal_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_elgamal_double_to_single(mk_lib_iip_integer_elgamal_double_pct const a, mk_lib_iip_integer_elgamal_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_integer_elgamal_double_to_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_elgamal_double_size_bytes_v];
		mk_lib_iip_integer_elgamal_double_t m_double;
		mk_lib_iip_integer_elgamal_single_t m_single;
	};
	typedef union mk_lib_iip_integer_elgamal_double_to_single_data_u mk_lib_iip_integer_elgamal_double_to_single_data_t;
	struct mk_lib_iip_integer_elgamal_double_to_single_s
	{
		mk_lib_iip_integer_elgamal_double_to_single_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_elgamal_double_to_single_s mk_lib_iip_integer_elgamal_double_to_single_t;

	mk_lib_iip_integer_elgamal_double_to_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_integer_elgamal_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_integer_elgamal_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_elgamal_single_mod_pow(mk_lib_iip_integer_elgamal_single_prct const base, mk_lib_iip_integer_elgamal_single_prct const exponent, mk_lib_iip_integer_elgamal_single_prct const modulus, mk_lib_iip_integer_elgamal_single_prt const result) mk_lang_noexcept
{
	mk_lib_iip_integer_elgamal_double_t dbase mk_lang_constexpr_init;
	mk_lib_iip_integer_elgamal_double_t dmodulus mk_lang_constexpr_init;
	mk_lib_iip_integer_elgamal_double_t dresult mk_lang_constexpr_init;
	mk_lib_iip_integer_elgamal_single_t sexponent mk_lang_constexpr_init;

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

	mk_lib_iip_integer_elgamal_single_to_double(base, &dbase);
	mk_lib_iip_integer_elgamal_single_to_double(modulus, &dmodulus);
	mk_lib_iip_integer_elgamal_double_set_one(&dresult);
	mk_lib_iip_integer_elgamal_single_assign(&sexponent, exponent);
	while(!mk_lib_iip_integer_elgamal_single_is_zero(&sexponent))
	{
		if(mk_lib_iip_integer_elgamal_single_has_lsb(&sexponent))
		{
			mk_lib_iip_integer_elgamal_double_mul2_wrap_lo(&dresult, &dbase);
			mk_lib_iip_integer_elgamal_double_mod2_wrap(&dresult, &dmodulus);
		}
		mk_lib_iip_integer_elgamal_single_shr2(&sexponent, 1);
		mk_lib_iip_integer_elgamal_double_mul2_wrap_lo(&dbase, &dbase);
		mk_lib_iip_integer_elgamal_double_mod2_wrap(&dbase, &dmodulus);
	}
	mk_lib_iip_integer_elgamal_double_to_single(&dresult, result);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_elgamal_double_load_p(mk_lib_iip_integer_elgamal_double_pt const x) mk_lang_noexcept
{
	mk_lib_iip_integer_elgamal_single_t elgamal_single mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_lib_iip_integer_elgamal_single_load_p(&elgamal_single);
	mk_lib_iip_integer_elgamal_single_to_double(&elgamal_single, x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_load_q(mk_lib_iip_integer_dsa_sha1_pri_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_integer_dsa_sha1_pri_single_from_buis_uchar_be(x, &mk_lib_iip_integer_k_dsa_sha1_pri_q.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be(mk_lib_iip_integer_dsa_sha1_pri_single_pt const x, mk_sl_cui_uint8_pct const u8s) mk_lang_noexcept
{
	union mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v];
		mk_lib_iip_integer_dsa_sha1_pri_single_t m_dsa_sha1_pri_cui_single;
	};
	typedef union mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be_data_u mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be_data_t;
	struct mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be_s
	{
		mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be_s mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be_t;

	mk_lib_iip_integer_dsa_sha1_pri_single_from_u8s_be_t storage mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(u8s);

	mk_sl_cui_uint8_to_bi_uchar_many(&u8s[0], &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
	mk_lib_iip_integer_dsa_sha1_pri_single_from_buis_uchar_be(x, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_to_double(mk_lib_iip_integer_dsa_sha1_pri_single_pct const a, mk_lib_iip_integer_dsa_sha1_pri_double_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_integer_dsa_sha1_pri_single_to_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pri_double_size_bytes_v];
		mk_lib_iip_integer_dsa_sha1_pri_single_t m_single;
		mk_lib_iip_integer_dsa_sha1_pri_double_t m_double;
	};
	typedef union mk_lib_iip_integer_dsa_sha1_pri_single_to_double_data_u mk_lib_iip_integer_dsa_sha1_pri_single_to_double_data_t;
	struct mk_lib_iip_integer_dsa_sha1_pri_single_to_double_s
	{
		mk_lib_iip_integer_dsa_sha1_pri_single_to_double_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_dsa_sha1_pri_single_to_double_s mk_lib_iip_integer_dsa_sha1_pri_single_to_double_t;

	mk_lang_types_uchar_t zero mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_to_double_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_integer_dsa_sha1_pri_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	zero = 0; mk_lang_string_memset_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v], &zero, ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_double_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v)));
	mk_lib_iip_integer_dsa_sha1_pri_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_double(mk_lib_iip_integer_dsa_sha1_pri_single_pct const a, mk_lib_iip_integer_dsa_sha1_pub_double_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pub_double_size_bytes_v];
		mk_lib_iip_integer_dsa_sha1_pri_single_t m_pri_single;
		mk_lib_iip_integer_dsa_sha1_pub_double_t m_pub_double;
	};
	typedef union mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_double_data_u mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_double_data_t;
	struct mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_double_s
	{
		mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_double_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_double_s mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_double_t;

	mk_lang_types_uchar_t zero mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_double_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_integer_dsa_sha1_pri_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	zero = 0; mk_lang_string_memset_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v], &zero, ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pub_double_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v)));
	mk_lib_iip_integer_dsa_sha1_pub_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_mod_mul3_wrap_lo(mk_lib_iip_integer_dsa_sha1_pri_single_prct const m, mk_lib_iip_integer_dsa_sha1_pri_single_prct const a, mk_lib_iip_integer_dsa_sha1_pri_single_prct const b, mk_lib_iip_integer_dsa_sha1_pri_single_prt const c) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_double_t mm mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_double_t aa mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_double_t bb mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_double_t cc mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(m != c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	mk_lib_iip_integer_dsa_sha1_pri_single_to_double(m, &mm);
	mk_lib_iip_integer_dsa_sha1_pri_single_to_double(a, &aa);
	mk_lib_iip_integer_dsa_sha1_pri_single_to_double(b, &bb);
	mk_lib_iip_integer_dsa_sha1_pri_double_mul3_wrap_lo(&aa, &bb, &cc);
	mk_lib_iip_integer_dsa_sha1_pri_double_mod2_wrap(&cc, &mm);
	mk_lib_iip_integer_dsa_sha1_pri_double_to_single(&cc, c);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_mod_add2_wrap_cid_cod(mk_lib_iip_integer_dsa_sha1_pri_single_prct const m, mk_lib_iip_integer_dsa_sha1_pri_single_prt const a, mk_lib_iip_integer_dsa_sha1_pri_single_prct const b) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_double_t mm mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_double_t aa mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_double_t bb mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(a != b);

	mk_lib_iip_integer_dsa_sha1_pri_single_to_double(m, &mm);
	mk_lib_iip_integer_dsa_sha1_pri_single_to_double(a, &aa);
	mk_lib_iip_integer_dsa_sha1_pri_single_to_double(b, &bb);
	mk_lib_iip_integer_dsa_sha1_pri_double_add2_wrap_cid_cod(&aa, &bb);
	mk_lib_iip_integer_dsa_sha1_pri_double_mod2_wrap(&aa, &mm);
	mk_lib_iip_integer_dsa_sha1_pri_double_to_single(&aa, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_mod_mul2_wrap_lo(mk_lib_iip_integer_dsa_sha1_pri_single_prct const m, mk_lib_iip_integer_dsa_sha1_pri_single_prt const a, mk_lib_iip_integer_dsa_sha1_pri_single_prct const b) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_double_t mm mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_double_t aa mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_double_t bb mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(a != b);

	mk_lib_iip_integer_dsa_sha1_pri_single_to_double(m, &mm);
	mk_lib_iip_integer_dsa_sha1_pri_single_to_double(a, &aa);
	mk_lib_iip_integer_dsa_sha1_pri_single_to_double(b, &bb);
	mk_lib_iip_integer_dsa_sha1_pri_double_mul2_wrap_lo(&aa, &bb);
	mk_lib_iip_integer_dsa_sha1_pri_double_mod2_wrap(&aa, &mm);
	mk_lib_iip_integer_dsa_sha1_pri_double_to_single(&aa, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_double_to_single(mk_lib_iip_integer_dsa_sha1_pri_double_pct const a, mk_lib_iip_integer_dsa_sha1_pri_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_integer_dsa_sha1_pri_double_to_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pri_double_size_bytes_v];
		mk_lib_iip_integer_dsa_sha1_pri_double_t m_double;
		mk_lib_iip_integer_dsa_sha1_pri_single_t m_single;
	};
	typedef union mk_lib_iip_integer_dsa_sha1_pri_double_to_single_data_u mk_lib_iip_integer_dsa_sha1_pri_double_to_single_data_t;
	struct mk_lib_iip_integer_dsa_sha1_pri_double_to_single_s
	{
		mk_lib_iip_integer_dsa_sha1_pri_double_to_single_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_dsa_sha1_pri_double_to_single_s mk_lib_iip_integer_dsa_sha1_pri_double_to_single_t;

	mk_lib_iip_integer_dsa_sha1_pri_double_to_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_integer_dsa_sha1_pri_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_integer_dsa_sha1_pri_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single(mk_lib_iip_integer_dsa_sha1_pri_single_pct const a, mk_lib_iip_integer_dsa_sha1_pub_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pub_single_size_bytes_v];
		mk_lib_iip_integer_dsa_sha1_pri_single_t m_pri_single;
		mk_lib_iip_integer_dsa_sha1_pub_single_t m_pub_single;
	};
	typedef union mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single_data_u mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single_data_t;
	struct mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single_s
	{
		mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single_s mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single_t;

	mk_lang_types_uchar_t zero mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_integer_dsa_sha1_pri_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	zero = 0; mk_lang_string_memset_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v], &zero, ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pub_single_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_size_bytes_v)));
	mk_lib_iip_integer_dsa_sha1_pub_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_integer_dsa_sha1_pri_single_is_negative(mk_lib_iip_integer_dsa_sha1_pri_single_pct const x) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_lib_iip_integer_dsa_sha1_pri_single_shr3(x, mk_lib_iip_integer_dsa_sha1_pri_single_size_bits_v - 1, &ta);
	ret = !mk_lib_iip_integer_dsa_sha1_pri_single_is_zero(&ta);
	return ret;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_flip_sign_1(mk_lib_iip_integer_dsa_sha1_pri_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_integer_dsa_sha1_pri_single_not1(x);
	mk_lib_iip_integer_dsa_sha1_pri_single_inc1(x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_gcd(mk_lib_iip_integer_dsa_sha1_pri_single_prct const a, mk_lib_iip_integer_dsa_sha1_pri_single_prct const b, mk_lib_iip_integer_dsa_sha1_pri_single_prt const c) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t ta mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t tb mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t tc mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_pt pa mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_pt pb mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_pt pc mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_pt qa mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_pt qb mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_pt qc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	ta = *a;
	tb = *b;
	pa = &ta;
	pb = &tb;
	pc = &tc;
	while(!mk_lib_iip_integer_dsa_sha1_pri_single_is_zero(pb))
	{
		mk_lib_iip_integer_dsa_sha1_pri_single_mod3_wrap(pa, pb, pc);
		qa = pa;
		qb = pb;
		qc = pc;
		pa = qb;
		pb = qc;
		pc = qa;
	}
	*c = *pa;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_mul3_signed(mk_lib_iip_integer_dsa_sha1_pri_single_prct const a, mk_lib_iip_integer_dsa_sha1_pri_single_prct const b, mk_lib_iip_integer_dsa_sha1_pri_single_prt const c) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t ta mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t tb mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t tc mk_lang_constexpr_init;
	mk_lang_types_bool_t ba mk_lang_constexpr_init;
	mk_lang_types_bool_t bb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(a != b);
	mk_lang_assert(a != c);
	mk_lang_assert(b != c);

	ta = *a;
	tb = *b;
	ba = mk_lib_iip_integer_dsa_sha1_pri_single_is_negative(&ta);
	bb = mk_lib_iip_integer_dsa_sha1_pri_single_is_negative(&tb);
	if(ba){ mk_lib_iip_integer_dsa_sha1_pri_single_flip_sign_1(&ta); }
	if(bb){ mk_lib_iip_integer_dsa_sha1_pri_single_flip_sign_1(&tb); }
	mk_lib_iip_integer_dsa_sha1_pri_single_mul3_wrap_lo(&ta, &tb, &tc);
	if((ba && !bb) || (!ba && bb)){ mk_lib_iip_integer_dsa_sha1_pri_single_flip_sign_1(&tc); }
	*c = tc;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_single_mod_inv(mk_lib_iip_integer_dsa_sha1_pri_single_pct const a, mk_lib_iip_integer_dsa_sha1_pri_single_pct const modulus, mk_lib_iip_integer_dsa_sha1_pri_single_pt const res_out) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t mz mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t y mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t x mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t one mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t aa mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t mm mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t q mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t t mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(modulus);
	mk_lang_assert(res_out);
	mk_lang_assert((mk_lib_iip_integer_dsa_sha1_pri_single_gcd(a, modulus, &aa), mk_lib_iip_integer_dsa_sha1_pri_single_is_one(&aa)));

	mz = *modulus;
	mk_lib_iip_integer_dsa_sha1_pri_single_set_zero(&y);
	mk_lib_iip_integer_dsa_sha1_pri_single_set_one(&x);
	if(mk_lib_iip_integer_dsa_sha1_pri_single_is_one(&mz))
	{
		mk_lib_iip_integer_dsa_sha1_pri_single_set_zero(res_out);
	}
	else
	{
		mk_lib_iip_integer_dsa_sha1_pri_single_set_one(&one);
		aa = *a;
		mm = *modulus;
		while(mk_lib_iip_integer_dsa_sha1_pri_single_gt(&aa, &one))
		{
			mk_lib_iip_integer_dsa_sha1_pri_single_div3_wrap(&aa, &mm, &q);
			mk_lib_iip_integer_dsa_sha1_pri_single_mod3_wrap(&aa, &mm, &ta);
			aa = mm;
			mm = ta;
			t = y;
			mk_lib_iip_integer_dsa_sha1_pri_single_mul3_signed(&q, &y, &ta);
			mk_lib_iip_integer_dsa_sha1_pri_single_sub3_wrap_cid_cod(&x, &ta, &y);
			x = t;
		}
		if(mk_lib_iip_integer_dsa_sha1_pri_single_is_negative(&x))
		{
			mk_lib_iip_integer_dsa_sha1_pri_single_add2_wrap_cid_cod(&x, &mz);
		}
		*res_out = x;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pri_double_load_q(mk_lib_iip_integer_dsa_sha1_pri_double_pt const x) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pri_single_t dsa_sha1_pri_single mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_lib_iip_integer_dsa_sha1_pri_single_load_q(&dsa_sha1_pri_single);
	mk_lib_iip_integer_dsa_sha1_pri_single_to_double(&dsa_sha1_pri_single, x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pub_single_load_g(mk_lib_iip_integer_dsa_sha1_pub_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_integer_dsa_sha1_pub_single_from_buis_uchar_be(x, &mk_lib_iip_integer_k_dsa_sha1_pub_g.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pub_single_load_p(mk_lib_iip_integer_dsa_sha1_pub_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_integer_dsa_sha1_pub_single_from_buis_uchar_be(x, &mk_lib_iip_integer_k_dsa_sha1_pub_p.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pub_single_to_double(mk_lib_iip_integer_dsa_sha1_pub_single_pct const a, mk_lib_iip_integer_dsa_sha1_pub_double_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_integer_dsa_sha1_pub_single_to_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pub_double_size_bytes_v];
		mk_lib_iip_integer_dsa_sha1_pub_single_t m_single;
		mk_lib_iip_integer_dsa_sha1_pub_double_t m_double;
	};
	typedef union mk_lib_iip_integer_dsa_sha1_pub_single_to_double_data_u mk_lib_iip_integer_dsa_sha1_pub_single_to_double_data_t;
	struct mk_lib_iip_integer_dsa_sha1_pub_single_to_double_s
	{
		mk_lib_iip_integer_dsa_sha1_pub_single_to_double_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_dsa_sha1_pub_single_to_double_s mk_lib_iip_integer_dsa_sha1_pub_single_to_double_t;

	mk_lang_types_uchar_t zero mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_single_to_double_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_integer_dsa_sha1_pub_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	zero = 0; mk_lang_string_memset_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_integer_dsa_sha1_pub_single_size_bytes_v], &zero, ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pub_double_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pub_single_size_bytes_v)));
	mk_lib_iip_integer_dsa_sha1_pub_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pub_single_to_pri_single(mk_lib_iip_integer_dsa_sha1_pub_single_pct const a, mk_lib_iip_integer_dsa_sha1_pri_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_integer_dsa_sha1_pub_single_to_pri_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pub_single_size_bytes_v];
		mk_lib_iip_integer_dsa_sha1_pub_single_t m_pub_single;
		mk_lib_iip_integer_dsa_sha1_pri_single_t m_pri_single;
	};
	typedef union mk_lib_iip_integer_dsa_sha1_pub_single_to_pri_single_data_u mk_lib_iip_integer_dsa_sha1_pub_single_to_pri_single_data_t;
	struct mk_lib_iip_integer_dsa_sha1_pub_single_to_pri_single_s
	{
		mk_lib_iip_integer_dsa_sha1_pub_single_to_pri_single_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_dsa_sha1_pub_single_to_pri_single_s mk_lib_iip_integer_dsa_sha1_pub_single_to_pri_single_t;

	mk_lib_iip_integer_dsa_sha1_pub_single_to_pri_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_integer_dsa_sha1_pub_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_integer_dsa_sha1_pri_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pub_double_to_single(mk_lib_iip_integer_dsa_sha1_pub_double_pct const a, mk_lib_iip_integer_dsa_sha1_pub_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_integer_dsa_sha1_pub_double_to_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pub_double_size_bytes_v];
		mk_lib_iip_integer_dsa_sha1_pub_double_t m_double;
		mk_lib_iip_integer_dsa_sha1_pub_single_t m_single;
	};
	typedef union mk_lib_iip_integer_dsa_sha1_pub_double_to_single_data_u mk_lib_iip_integer_dsa_sha1_pub_double_to_single_data_t;
	struct mk_lib_iip_integer_dsa_sha1_pub_double_to_single_s
	{
		mk_lib_iip_integer_dsa_sha1_pub_double_to_single_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_dsa_sha1_pub_double_to_single_s mk_lib_iip_integer_dsa_sha1_pub_double_to_single_t;

	mk_lib_iip_integer_dsa_sha1_pub_double_to_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_integer_dsa_sha1_pub_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_integer_dsa_sha1_pub_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pub_double_to_pri_single(mk_lib_iip_integer_dsa_sha1_pub_double_pct const a, mk_lib_iip_integer_dsa_sha1_pri_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_integer_dsa_sha1_pub_double_to_pri_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_integer_dsa_sha1_pub_double_size_bytes_v];
		mk_lib_iip_integer_dsa_sha1_pub_double_t m_pub_double;
		mk_lib_iip_integer_dsa_sha1_pri_single_t m_pri_single;
	};
	typedef union mk_lib_iip_integer_dsa_sha1_pub_double_to_pri_single_data_u mk_lib_iip_integer_dsa_sha1_pub_double_to_pri_single_data_t;
	struct mk_lib_iip_integer_dsa_sha1_pub_double_to_pri_single_s
	{
		mk_lib_iip_integer_dsa_sha1_pub_double_to_pri_single_data_t m_data;
	};
	typedef struct mk_lib_iip_integer_dsa_sha1_pub_double_to_pri_single_s mk_lib_iip_integer_dsa_sha1_pub_double_to_pri_single_t;

	mk_lib_iip_integer_dsa_sha1_pub_double_to_pri_single_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_integer_dsa_sha1_pub_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_integer_dsa_sha1_pri_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pub_single_mod_pow_a(mk_lib_iip_integer_dsa_sha1_pub_single_prct const base, mk_lib_iip_integer_dsa_sha1_pub_single_prct const exponent, mk_lib_iip_integer_dsa_sha1_pub_single_prct const modulus, mk_lib_iip_integer_dsa_sha1_pub_single_prt const result) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pub_double_t dbase mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_double_t dmodulus mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_double_t dresult mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_single_t sexponent mk_lang_constexpr_init;

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

	mk_lib_iip_integer_dsa_sha1_pub_single_to_double(base, &dbase);
	mk_lib_iip_integer_dsa_sha1_pub_single_to_double(modulus, &dmodulus);
	mk_lib_iip_integer_dsa_sha1_pub_double_set_one(&dresult);
	mk_lib_iip_integer_dsa_sha1_pub_single_assign(&sexponent, exponent);
	while(!mk_lib_iip_integer_dsa_sha1_pub_single_is_zero(&sexponent))
	{
		if(mk_lib_iip_integer_dsa_sha1_pub_single_has_lsb(&sexponent))
		{
			mk_lib_iip_integer_dsa_sha1_pub_double_mul2_wrap_lo(&dresult, &dbase);
			mk_lib_iip_integer_dsa_sha1_pub_double_mod2_wrap(&dresult, &dmodulus);
		}
		mk_lib_iip_integer_dsa_sha1_pub_single_shr2(&sexponent, 1);
		mk_lib_iip_integer_dsa_sha1_pub_double_mul2_wrap_lo(&dbase, &dbase);
		mk_lib_iip_integer_dsa_sha1_pub_double_mod2_wrap(&dbase, &dmodulus);
	}
	mk_lib_iip_integer_dsa_sha1_pub_double_to_single(&dresult, result);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pub_single_mod_pow_b(mk_lib_iip_integer_dsa_sha1_pub_single_prct const base, mk_lib_iip_integer_dsa_sha1_pri_single_prct const exponent, mk_lib_iip_integer_dsa_sha1_pub_single_prct const modulus_a, mk_lib_iip_integer_dsa_sha1_pri_single_prct const modulus_b, mk_lib_iip_integer_dsa_sha1_pri_single_prt const result) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pub_double_t dbase mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_double_t dmodulusa mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_double_t dresult mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pri_single_t sexponent mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_single_t sresult mk_lang_constexpr_init;
	mk_lib_iip_integer_dsa_sha1_pub_single_t smodulusb mk_lang_constexpr_init;

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

	mk_lib_iip_integer_dsa_sha1_pub_single_to_double(base, &dbase);
	mk_lib_iip_integer_dsa_sha1_pub_single_to_double(modulus_a, &dmodulusa);
	mk_lib_iip_integer_dsa_sha1_pub_double_set_one(&dresult);
	mk_lib_iip_integer_dsa_sha1_pri_single_assign(&sexponent, exponent);
	while(!mk_lib_iip_integer_dsa_sha1_pri_single_is_zero(&sexponent))
	{
		if(mk_lib_iip_integer_dsa_sha1_pri_single_has_lsb(&sexponent))
		{
			mk_lib_iip_integer_dsa_sha1_pub_double_mul2_wrap_lo(&dresult, &dbase);
			mk_lib_iip_integer_dsa_sha1_pub_double_mod2_wrap(&dresult, &dmodulusa);
		}
		mk_lib_iip_integer_dsa_sha1_pri_single_shr2(&sexponent, 1);
		mk_lib_iip_integer_dsa_sha1_pub_double_mul2_wrap_lo(&dbase, &dbase);
		mk_lib_iip_integer_dsa_sha1_pub_double_mod2_wrap(&dbase, &dmodulusa);
	}
	mk_lib_iip_integer_dsa_sha1_pub_double_to_single(&dresult, &sresult);
	mk_lib_iip_integer_dsa_sha1_pri_single_to_pub_single(modulus_b, &smodulusb);
	mk_lib_iip_integer_dsa_sha1_pub_single_mod2_wrap(&sresult, &smodulusb);
	mk_lib_iip_integer_dsa_sha1_pub_single_to_pri_single(&sresult, result);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pub_double_load_g(mk_lib_iip_integer_dsa_sha1_pub_double_pt const x) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pub_single_t dsa_sha1_pub_single mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_lib_iip_integer_dsa_sha1_pub_single_load_g(&dsa_sha1_pub_single);
	mk_lib_iip_integer_dsa_sha1_pub_single_to_double(&dsa_sha1_pub_single, x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_integer_dsa_sha1_pub_double_load_p(mk_lib_iip_integer_dsa_sha1_pub_double_pt const x) mk_lang_noexcept
{
	mk_lib_iip_integer_dsa_sha1_pub_single_t dsa_sha1_pub_single mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_lib_iip_integer_dsa_sha1_pub_single_load_p(&dsa_sha1_pub_single);
	mk_lib_iip_integer_dsa_sha1_pub_single_to_double(&dsa_sha1_pub_single, x);
}


#endif
