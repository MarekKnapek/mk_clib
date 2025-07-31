#ifndef mk_include_guard_mk_lib_iip_key_enc_elgamal_pub_c
#define mk_include_guard_mk_lib_iip_key_enc_elgamal_pub_c
#include "mk_lib_iip_key_enc_elgamal_pub.h"

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


#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_pub_integer_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((256 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_pub_integer_double
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (2 * ((256 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


union mk_lib_iip_key_enc_elgamal_pub_uchars_data_u
{
	mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v];
	mk_lib_iip_key_enc_elgamal_pub_integer_single_t m_align;
};
typedef union mk_lib_iip_key_enc_elgamal_pub_uchars_data_u mk_lib_iip_key_enc_elgamal_pub_uchars_data_t;
struct mk_lib_iip_key_enc_elgamal_pub_uchars_s
{
	mk_lang_alignas(64) mk_lib_iip_key_enc_elgamal_pub_uchars_data_t m_data;
};
typedef struct mk_lib_iip_key_enc_elgamal_pub_uchars_s mk_lib_iip_key_enc_elgamal_pub_uchars_t;


mk_lang_constexpr_static_inline mk_lib_iip_key_enc_elgamal_pub_uchars_t const mk_lib_iip_key_enc_elgamal_pub_k_p =
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


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s(mk_lib_iip_key_enc_elgamal_pub_integer_single_pct const a, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_pub_integer_single_t m_integer;
	};
	typedef union mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_storage_data_u mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_storage_s
	{
		mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_storage_s mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_storage_t;

	mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_storage_t storage;

	mk_lang_assert(a);
	mk_lang_assert(u8s);

	mk_lib_iip_key_enc_elgamal_pub_integer_single_to_buis_uchar_be(a, &storage.m_data.m_uchars[0]);
	mk_sl_cui_uint8_from_bi_uchar_many(&u8s[0], &storage.m_data.m_uchars[0], mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double(mk_lib_iip_key_enc_elgamal_pub_integer_single_pct const a, mk_lib_iip_key_enc_elgamal_pub_integer_double_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_double_size_bytes_v)))];
		mk_lib_iip_key_enc_elgamal_pub_integer_single_t m_pub_single;
		mk_lib_iip_key_enc_elgamal_pub_integer_double_t m_pub_double;
	};
	typedef union mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double_data_u mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double_data_t;
	struct mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double_s
	{
		mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double_s mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double_t;

	mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_double_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_enc_elgamal_pub_integer_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lang_string_memclr_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v], ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_double_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)));
	mk_lib_iip_key_enc_elgamal_pub_integer_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single(mk_lib_iip_key_enc_elgamal_pub_integer_double_pct const a, mk_lib_iip_key_enc_elgamal_pub_integer_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_double_size_bytes_v)))];
		mk_lib_iip_key_enc_elgamal_pub_integer_single_t m_pub_single;
		mk_lib_iip_key_enc_elgamal_pub_integer_double_t m_pub_double;
	};
	typedef union mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single_data_u mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single_data_t;
	struct mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single_s
	{
		mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single_s mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single_t;

	mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_double_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_enc_elgamal_pub_integer_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_key_enc_elgamal_pub_integer_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_load_g(mk_lib_iip_key_enc_elgamal_pub_integer_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_enc_elgamal_pub_integer_single_set_two(x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_load_p(mk_lib_iip_key_enc_elgamal_pub_integer_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_enc_elgamal_pub_integer_single_from_buis_uchar_be(x, &mk_lib_iip_key_enc_elgamal_pub_k_p.m_data.m_uchars[0]);
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be(mk_lib_iip_key_enc_elgamal_pub_integer_single_pt const a, mk_lang_static_param(mk_sl_cui_uint8_ct, b, mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_pub_integer_single_t m_pri_single;
	};
	typedef union mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be_data_u mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be_data_t;
	struct mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be_s
	{
		mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be_s mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be_t;

	mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_uint8_to_bi_uchar_many(&b[0], &storage.m_data.m_uchars[0], mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v);
	mk_lib_iip_key_enc_elgamal_pub_integer_single_from_buis_uchar_be(a, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be(mk_lib_iip_key_enc_elgamal_pub_integer_single_pct const a, mk_lang_static_param(mk_sl_cui_uint8_t, b, mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_pub_integer_single_t m_pri_single;
	};
	typedef union mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be_data_u mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be_data_t;
	struct mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be_s
	{
		mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be_s mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be_t;

	mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be_t storage mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_enc_elgamal_pub_integer_single_to_buis_uchar_be(a, &storage.m_data.m_uchars[0]);
	mk_sl_cui_uint8_from_bi_uchar_many(&b[0], &storage.m_data.m_uchars[0], mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pub_integer_single_mod_pow(mk_lib_iip_key_enc_elgamal_pub_integer_single_prct const base, mk_lib_iip_key_enc_elgamal_pub_integer_single_prct const exponent, mk_lib_iip_key_enc_elgamal_pub_integer_single_prct const modulus, mk_lib_iip_key_enc_elgamal_pub_integer_single_prt const result) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_pub_integer_double_t dbase mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_pub_integer_double_t dmodulus mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_pub_integer_double_t dresult mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_pub_integer_single_t sexponent mk_lang_constexpr_init;

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

	mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double(base, &dbase);
	mk_lib_iip_key_enc_elgamal_pub_integer_single_to_pub_double(modulus, &dmodulus);
	mk_lib_iip_key_enc_elgamal_pub_integer_double_set_one(&dresult);
	mk_lib_iip_key_enc_elgamal_pub_integer_single_assign(&sexponent, exponent);
	while(!mk_lib_iip_key_enc_elgamal_pub_integer_single_is_zero(&sexponent))
	{
		if(mk_lib_iip_key_enc_elgamal_pub_integer_single_has_lsb(&sexponent))
		{
			mk_lib_iip_key_enc_elgamal_pub_integer_double_mul2_wrap_lo(&dresult, &dbase);
			mk_lib_iip_key_enc_elgamal_pub_integer_double_mod2_wrap(&dresult, &dmodulus);
		}
		mk_lib_iip_key_enc_elgamal_pub_integer_single_shr2(&sexponent, 1);
		mk_lib_iip_key_enc_elgamal_pub_integer_double_mul2_wrap_lo(&dbase, &dbase);
		mk_lib_iip_key_enc_elgamal_pub_integer_double_mod2_wrap(&dbase, &dmodulus);
	}
	mk_lib_iip_key_enc_elgamal_pub_integer_double_to_pub_single(&dresult, result);
}


#endif
