#ifndef mk_include_guard_mk_lib_iip_key_enc_elgamal_cryptopp_c
#define mk_include_guard_mk_lib_iip_key_enc_elgamal_cryptopp_c
#include "mk_lib_iip_key_enc_elgamal_cryptopp.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_iip_random.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((mk_lib_iip_key_enc_elgamal_cryptopp_pri_len_d * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((mk_lib_iip_key_enc_elgamal_cryptopp_pub_len_d * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (2 * ((mk_lib_iip_key_enc_elgamal_cryptopp_pri_len_d * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_size_bytes_d (2 * mk_lib_iip_key_enc_elgamal_cryptopp_pri_len_d)
#define mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_size_bits_d ((2 * mk_lib_iip_key_enc_elgamal_cryptopp_pri_len_d) * mk_lang_charbit)

#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (2 * ((mk_lib_iip_key_enc_elgamal_cryptopp_pub_len_d * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_size_bytes_d (2 * mk_lib_iip_key_enc_elgamal_cryptopp_pub_len_d)
#define mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_size_bits_d ((2 * mk_lib_iip_key_enc_elgamal_cryptopp_pub_len_d) * mk_lang_charbit)


#include "mk_lang_warning_msvc_push_c4820.h"
union mk_lib_iip_key_enc_elgamal_cryptopp_int_sml_data_u
{
	mk_lang_types_uchar_t m_uchars[20];
	mk_lang_types_uint_t m_align;
};
typedef union mk_lib_iip_key_enc_elgamal_cryptopp_int_sml_data_u mk_lib_iip_key_enc_elgamal_cryptopp_int_sml_data_t;
struct mk_lib_iip_key_enc_elgamal_cryptopp_int_sml_s
{
	mk_lang_alignas(32) mk_lib_iip_key_enc_elgamal_cryptopp_int_sml_data_t m_data;
};
typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_int_sml_s mk_lib_iip_key_enc_elgamal_cryptopp_int_sml_t;
#include "mk_lang_warning_msvc_pop.h"

union mk_lib_iip_key_enc_elgamal_cryptopp_int_big_data_u
{
	mk_lang_types_uchar_t m_uchars[128];
	mk_lang_types_uint_t m_align;
};
typedef union mk_lib_iip_key_enc_elgamal_cryptopp_int_big_data_u mk_lib_iip_key_enc_elgamal_cryptopp_int_big_data_t;
struct mk_lib_iip_key_enc_elgamal_cryptopp_int_big_s
{
	mk_lang_alignas(64) mk_lib_iip_key_enc_elgamal_cryptopp_int_big_data_t m_data;
};
typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_int_big_s mk_lib_iip_key_enc_elgamal_cryptopp_int_big_t;


mk_lang_constexpr_static_inline mk_lib_iip_key_enc_elgamal_cryptopp_int_sml_t const mk_lib_iip_key_enc_elgamal_cryptopp_k_q =
{{{
	0xa5, 0xdf, 0xc2, 0x8f, 0xef, 0x4c, 0xa1, 0xe2, 0x86, 0x74, 0x4c, 0xd8, 0xee, 0xd9, 0xd2, 0x9d, 0x68, 0x40, 0x46, 0xb7,
}}};

mk_lang_constexpr_static_inline mk_lib_iip_key_enc_elgamal_cryptopp_int_big_t const mk_lib_iip_key_enc_elgamal_cryptopp_k_g =
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

mk_lang_constexpr_static_inline mk_lib_iip_key_enc_elgamal_cryptopp_int_big_t const mk_lib_iip_key_enc_elgamal_cryptopp_k_p =
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


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_load_q(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_buis_uchar_be(x, &mk_lib_iip_key_enc_elgamal_cryptopp_k_q.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt const x, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m_pri_single;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be_storage_t storage mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(u8s);

	mk_sl_cui_uint8_to_bi_uchar_many(u8s, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_buis_uchar_be(x, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pct const x, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m_pri_single;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be_storage_data_t m_data mk_lang_constexpr_init;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be_storage_t storage;

	mk_lang_assert(x);
	mk_lang_assert(u8s);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_buis_uchar_be(x, &storage.m_data.m_uchars[0]);
	mk_sl_cui_uint8_from_bi_uchar_many(u8s, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt const x) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m_pri_single;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random_storage_t;

	mk_lang_types_sint_t err;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random_storage_t storage;

	mk_lang_assert(x);

	err = mk_lib_iip_random_generate_uchars(&storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_buis_uchar_le(x, &storage.m_data.m_uchars[0]); /* todo ne instead of le */
	return 0;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_size_bytes_v)))];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m_pri_single;
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t m_pri_double;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double_storage_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lang_string_memclr_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v], ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)));
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_pct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_size_bytes_v)))];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m_pri_single;
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t m_pri_double;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single_storage_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v)))];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m_pri_single;
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t m_pub_single;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single_storage_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lang_string_memclr_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v], ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)));
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_gcd(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const b, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prt const c) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t ta mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t tb mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t tc mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt pa mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt pb mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt pc mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt qa mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt qb mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt qc mk_lang_constexpr_init;

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
	while(!mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_zero(pb))
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod3_wrap(pa, pb, pc);
		qa = pa; qb = pb; qc = pc;
		pa = qb; pb = qc; pc = qa;
	}
	*c = *pa;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_negative(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pct const x) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t ta mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_shr3(x, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bits_v - 1, &ta);
	ret = !mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_zero(&ta);
	return ret;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_flip_sign_1(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_not1(x);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_inc1(x);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mul3_signed(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const b, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prt const c) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t ta mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t tb mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t tc mk_lang_constexpr_init;
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
	ba = mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_negative(&ta);
	bb = mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_negative(&tb);
	if(ba){ mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_flip_sign_1(&ta); }
	if(bb){ mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_flip_sign_1(&tb); }
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mul3_wrap_lo(&ta, &tb, &tc);
	if((ba && !bb) || (!ba && bb)){ mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_flip_sign_1(&tc); }
	*c = tc;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_add2_wrap_cid_cod(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const m, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prt const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const b) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t mm mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t aa mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t bb mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(a != b);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double(m, &mm);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double(a, &aa);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double(b, &bb);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_add2_wrap_cid_cod(&aa, &bb);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_mod2_wrap(&aa, &mm);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single(&aa, a);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_mul3_wrap_lo(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const m, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const b, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prt const c) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t mm mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t aa mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t bb mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t cc mk_lang_constexpr_init;

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

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double(m, &mm);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double(a, &aa);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double(b, &bb);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_mul3_wrap_lo(&aa, &bb, &cc);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_mod2_wrap(&cc, &mm);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single(&cc, c);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_mul2_wrap_lo(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const m, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prt const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const b) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t mm mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t aa mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_t bb mk_lang_constexpr_init;

	mk_lang_assert(m);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(m != a);
	mk_lang_assert(m != b);
	mk_lang_assert(a != b);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double(m, &mm);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double(a, &aa);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pri_double(b, &bb);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_mul2_wrap_lo(&aa, &bb);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_mod2_wrap(&aa, &mm);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_double_to_pri_single(&aa, a);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_inv(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pct const modulus, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt const res_out) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t mz mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t y mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t x mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t one mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t aa mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t mm mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t q mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t t mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(modulus);
	mk_lang_assert(res_out);
	mk_lang_assert((mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_gcd(a, modulus, &aa), mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_one(&aa)));

	mz = *modulus;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_set_zero(&y);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_set_one(&x);
	if(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_one(&mz))
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_set_zero(res_out);
	}
	else
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_set_one(&one);
		aa = *a;
		mm = *modulus;
		while(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_gt(&aa, &one))
		{
			mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_div3_wrap(&aa, &mm, &q);
			mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod3_wrap(&aa, &mm, &ta);
			aa = mm;
			mm = ta;
			t = y;
			mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mul3_signed(&q, &y, &ta);
			mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_sub3_wrap_cid_cod(&x, &ta, &y);
			x = t;
		}
		if(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_negative(&x))
		{
			mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_add2_wrap_cid_cod(&x, &mz);
		}
		*res_out = x;
	}
}


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_pct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_size_bytes_v)))];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t m_pub_single;
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t m_pub_double;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double_storage_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lang_string_memclr_uc_fn(&storage.m_data.m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v], ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_size_bytes_v)) - ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v)));
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_pct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_size_bytes_v)))];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t m_pub_single;
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t m_pub_double;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single_storage_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v)) <= ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_pct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)))];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t m_pub_single;
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m_pri_single;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single_storage_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v)) >= ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_load_g(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_from_buis_uchar_be(x, &mk_lib_iip_key_enc_elgamal_cryptopp_k_g.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_load_p(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_from_buis_uchar_be(x, &mk_lib_iip_key_enc_elgamal_cryptopp_k_p.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_mul3_wrap_lo(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const m, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const b, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prt const c) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t mm mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t aa mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t bb mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t cc mk_lang_constexpr_init;

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

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double(m, &mm);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double(a, &aa);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double(b, &bb);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_mul3_wrap_lo(&aa, &bb, &cc);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_mod2_wrap(&cc, &mm);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single(&cc, c);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_to_pri_single(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const m, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prt const b) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t mm mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(m);
	mk_lang_assert(b);
	mk_lang_assert(m != b);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single(m, &mm);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod3_wrap(a, &mm, &ta);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single(&ta, b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_pow_a(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const base, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const exponent, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const modulus, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prt const result) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t d_base mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t d_modulus mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t d_result mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t s_exponent mk_lang_constexpr_init;

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

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double(base, &d_base);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double(modulus, &d_modulus);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_set_one(&d_result);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_assign(&s_exponent, exponent);
	while(!mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_is_zero(&s_exponent))
	{
		if(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_has_lsb(&s_exponent))
		{
			mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_mul2_wrap_lo(&d_result, &d_base);
			mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_mod2_wrap(&d_result, &d_modulus);
		}
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_shr2(&s_exponent, 1);
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_mul2_wrap_lo(&d_base, &d_base);
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_mod2_wrap(&d_base, &d_modulus);
	}
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single(&d_result, result);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_pow_c(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const base, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const exponent, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const modulus, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prt const result) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t exp mk_lang_constexpr_init;

	mk_lang_assert(base);
	mk_lang_assert(exponent);
	mk_lang_assert(modulus);
	mk_lang_assert(result);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single(exponent, &exp);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_pow_a(base, &exp, modulus, result);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_pow_b(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const base, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const exponent, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_prct const modulus_a, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prct const modulus_b, mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_prt const result) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t d_base mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t d_modulus_a mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_t d_result mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t s_exponent mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t s_result mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t s_modulus_b mk_lang_constexpr_init;

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

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double(base, &d_base);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pub_double(modulus_a, &d_modulus_a);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_set_one(&d_result);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_assign(&s_exponent, exponent);
	while(!mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_zero(&s_exponent))
	{
		if(mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_has_lsb(&s_exponent))
		{
			mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_mul2_wrap_lo(&d_result, &d_base);
			mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_mod2_wrap(&d_result, &d_modulus_a);
		}
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_shr2(&s_exponent, 1);
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_mul2_wrap_lo(&d_base, &d_base);
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_mod2_wrap(&d_base, &d_modulus_a);
	}
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_double_to_pub_single(&d_result, &s_result);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single(modulus_b, &s_modulus_b);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod2_wrap(&s_result, &s_modulus_b);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_pri_single(&s_result, result);
}


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_sign_digest_has_k(mk_lib_iip_key_enc_elgamal_cryptopp_pri_prct const pri, mk_lib_iip_key_enc_elgamal_cryptopp_pri_prct const k, mk_lib_iip_key_enc_elgamal_cryptopp_digest_pct const digest, mk_lib_iip_key_enc_elgamal_cryptopp_signature_pt const signature, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t q mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t g mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t p mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t r mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t ki mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t s mk_lang_constexpr_init;

	mk_lang_assert(pri);
	mk_lang_assert(k);
	mk_lang_assert(digest);
	mk_lang_assert(signature);
	mk_lang_assert(success);
	mk_lang_assert(pri != k);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be(&m, &digest->m_data.m_uint8s[0]);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_load_q(&q);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_load_g(&g);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_load_p(&p);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_pow_b(&g, &k->m_integer, &p, &q, &r);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_inv(&k->m_integer, &q, &ki);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_mul3_wrap_lo(&q, &pri->m_integer, &r, &s);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_add2_wrap_cid_cod(&q, &s, &m);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_mul2_wrap_lo(&q, &s, &ki);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be(&r, &signature->m_data.m_uint8s[0 * mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v]);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_u8s_be(&s, &signature->m_data.m_uint8s[1 * mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v]);
	*success =
		!mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_zero(&r) &&
		!mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_zero(&s);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_get_public(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri, mk_lib_iip_key_enc_elgamal_cryptopp_pub_pt const pub) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t generator mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t prime mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t priv mk_lang_constexpr_init;

	mk_lang_assert(pri);
	mk_lang_assert(pub);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_load_g(&generator);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_load_p(&prime);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_pub_single(&pri->m_integer, &priv);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_pow_a(&generator, &priv, &prime, &pub->m_integer);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_good_k(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const k) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t q mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t gcd mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_assert(k);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_load_q(&q);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_gcd(&k->m_integer, &q, &gcd);
	gud = mk_lang_true;
	gud = gud & !mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_zero(&k->m_integer);
	gud = gud & mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_lt(&k->m_integer, &q);
	gud = gud & mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_one(&gcd);
	return gud;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_generate_k(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pt const k) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(k);

	do
	{
		err = mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random(&k->m_integer); mk_lang_check_rereturn(err);
	}while(!mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_good_k(k));
	return 0;
}


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_prst_hash_data(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_enc_elgamal_cryptopp_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_crypto_hash_stream_sha1_t sha1_hasher mk_lang_constexpr_init;
	mk_lib_crypto_hash_stream_sha1_digest_t sha1_digest mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);

	mk_lib_crypto_hash_stream_sha1_init(&sha1_hasher);
	mk_lib_crypto_hash_stream_sha1_append_u8s(&sha1_hasher, data_buf, ((mk_lang_types_usize_t)(data_len)));
	mk_lib_crypto_hash_stream_sha1_finish(&sha1_hasher, &sha1_digest);
	mk_sl_cui_uint8_memcpy_fn(&digest->m_data.m_uint8s[0], &sha1_digest.m_data.m_uint8s[0], mk_lib_crypto_hash_stream_sha1_digest_len_v);
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_generate_random(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pt const pri) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(pri);

	err = mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_generate_random(&pri->m_integer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t q mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(pri);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_load_q(&q);
	ret =
		!mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_is_zero(&pri->m_integer) &&
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_lt(&pri->m_integer, &q);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid_2(mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pri_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid_2_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m_integer;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid_2_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid_2_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid_2_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid_2_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid_2_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid_2_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid_2_storage_t storage mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_pri_t pri mk_lang_constexpr_init;

	mk_lang_assert(u8s);

	mk_sl_cui_uint8_to_bi_uchar_many(u8s, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_buis_uchar_be(&pri.m_integer, &storage.m_data.m_uchars[0]);
	return mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid(&pri);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_construct_from_u8s(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pt const pri, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pri_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_construct_from_u8s_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m_integer;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_construct_from_u8s_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_construct_from_u8s_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_construct_from_u8s_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_construct_from_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_construct_from_u8s_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_construct_from_u8s_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_construct_from_u8s_storage_t storage mk_lang_constexpr_init;

	mk_lang_assert(pri);

	mk_sl_cui_uint8_to_bi_uchar_many(u8s, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_buis_uchar_be(&pri->m_integer, &storage.m_data.m_uchars[0]);
	mk_lang_check_return(mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid(pri));
	return 0;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_destroy(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pt const pri) mk_lang_noexcept
{
	mk_lang_assert(pri);

	((mk_lang_types_void_t)(pri));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pri_to_u8s(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pri_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pri_to_u8s_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t m_integer;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pri_to_u8s_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pri_to_u8s_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pri_to_u8s_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pri_to_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pri_to_u8s_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pri_to_u8s_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pri_to_u8s_storage_t storage mk_lang_constexpr_init;

	mk_lang_assert(pri);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_to_buis_uchar_be(&pri->m_integer, &storage.m_data.m_uchars[0]);
	mk_sl_cui_uint8_from_bi_uchar_many(u8s, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pub_to_u8s(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pub_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pub_to_u8s_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t m_integer;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pub_to_u8s_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pub_to_u8s_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pub_to_u8s_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pub_to_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pub_to_u8s_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pub_to_u8s_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_pub_t pub mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pub_to_u8s_storage_t storage mk_lang_constexpr_init;

	mk_lang_assert(pri);

	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_get_public(pri, &pub);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_buis_uchar_be(&pub.m_integer, &storage.m_data.m_uchars[0]);
	mk_sl_cui_uint8_from_bi_uchar_many(u8s, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_sign_digest(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri, mk_lib_iip_key_enc_elgamal_cryptopp_digest_pct const digest, mk_lib_iip_key_enc_elgamal_cryptopp_signature_pt const signature) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_key_enc_elgamal_cryptopp_pri_t k;
	mk_lang_types_bool_t success;

	mk_lang_assert(pri);
	mk_lang_assert(digest);
	mk_lang_assert(signature);

	do
	{
		err = mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_generate_k(&k); mk_lang_check_rereturn(err);
		mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_sign_digest_has_k(pri, &k, digest, signature, &success);
	}while(!success);
	return 0;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_validate_signature(mk_lib_iip_key_enc_elgamal_cryptopp_pub_pct const pub, mk_lib_iip_key_enc_elgamal_cryptopp_digest_pct const digest, mk_lib_iip_key_enc_elgamal_cryptopp_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t r mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t s mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t zero mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t q mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t w mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t h mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t u1 mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t u2 mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t p mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t g mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t ta mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t tb mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t tc mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_t v mk_lang_constexpr_init;

	mk_lang_assert(pub);
	mk_lang_assert(digest);
	mk_lang_assert(signature);
	mk_lang_assert(is_valid);

	gud = mk_lang_true;
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be(&r, &signature->m_data.m_uint8s[0 * mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v]);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be(&s, &signature->m_data.m_uint8s[1 * mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_size_bytes_v]);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_set_zero(&zero);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_load_q(&q);
	gud = gud & mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_gt(&r, &zero);
	gud = gud & mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_lt(&r, &q);
	gud = gud & mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_gt(&s, &zero);
	gud = gud & mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_lt(&s, &q);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_inv(&s, &q, &w);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_from_u8s_be(&h, &digest->m_data.m_uint8s[0]);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_mul3_wrap_lo(&q, &h, &w, &u1);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_mod_mul3_wrap_lo(&q, &r, &w, &u2);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_load_p(&p);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_load_g(&g);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_pow_c(&g, &u1, &p, &ta);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_pow_c(&pub->m_integer, &u2, &p, &tb);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_mul3_wrap_lo(&p, &ta, &tb, &tc);
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_mod_to_pri_single(&tc, &q, &v);
	gud = gud & mk_lib_iip_key_enc_elgamal_cryptopp_integer_pri_single_eq(&r, &v);
	*is_valid = gud;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_validate_signature(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri, mk_lib_iip_key_enc_elgamal_cryptopp_digest_pct const digest, mk_lib_iip_key_enc_elgamal_cryptopp_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_pub_t pub mk_lang_constexpr_init;

	mk_lang_assert(pri);
	mk_lang_assert(digest);
	mk_lang_assert(signature);
	mk_lang_assert(is_valid);

	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_get_public(pri, &pub);
	mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_validate_signature(&pub, digest, signature, is_valid);
}


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_construct_from_u8s(mk_lib_iip_key_enc_elgamal_cryptopp_pub_pt const pub, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pub_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_construct_from_u8s_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t m_integer;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_construct_from_u8s_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_construct_from_u8s_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_construct_from_u8s_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_construct_from_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_construct_from_u8s_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_construct_from_u8s_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_construct_from_u8s_storage_t storage mk_lang_constexpr_init;

	mk_lang_assert(pub);

	mk_sl_cui_uint8_to_bi_uchar_many(u8s, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_from_buis_uchar_be(&pub->m_integer, &storage.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_destroy(mk_lib_iip_key_enc_elgamal_cryptopp_pub_pt const pub) mk_lang_noexcept
{
	mk_lang_assert(pub);

	((mk_lang_types_void_t)(pub));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_export_to_u8s(mk_lib_iip_key_enc_elgamal_cryptopp_pub_pct const pub, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pub_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_export_pub_to_u8s_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_t m_integer;
	};
	typedef union mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_export_pub_to_u8s_storage_data_u mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_export_pub_to_u8s_storage_data_t;
	struct mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_export_pub_to_u8s_storage_s
	{
		mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_export_pub_to_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_export_pub_to_u8s_storage_s mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_export_pub_to_u8s_storage_t;

	mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_export_pub_to_u8s_storage_t storage mk_lang_constexpr_init;

	mk_lang_assert(pub);

	mk_lib_iip_key_enc_elgamal_cryptopp_integer_pub_single_to_buis_uchar_be(&pub->m_integer, &storage.m_data.m_uchars[0]);
	mk_sl_cui_uint8_from_bi_uchar_many(u8s, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_st_hash_data(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_enc_elgamal_cryptopp_digest_pt const digest) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_prst_hash_data(data_buf, data_len, digest);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_rw_is_valid(mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pri_len_v), mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lang_assert(is_valid);

	*is_valid = mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_is_valid_2(u8s);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_rw_generate_random(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pt const pri) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_generate_random(pri);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_rw_construct_from_u8s(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pt const pri, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pri_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_construct_from_u8s(pri, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_rw_destroy(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pt const pri) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_destroy(pri);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_rw_export_pri_to_u8s(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pri_len_v)) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pri_to_u8s(pri, u8s);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_rw_export_pub_to_u8s(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pub_len_v)) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_export_pub_to_u8s(pri, u8s);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_rw_get_public(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri, mk_lib_iip_key_enc_elgamal_cryptopp_pub_pt const pub) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_get_public(pri, pub);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_rw_sign_digest(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri, mk_lib_iip_key_enc_elgamal_cryptopp_digest_pct const digest, mk_lib_iip_key_enc_elgamal_cryptopp_signature_pt const signature) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_sign_digest(pri, digest, signature);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pri_rw_validate_signature(mk_lib_iip_key_enc_elgamal_cryptopp_pri_pct const pri, mk_lib_iip_key_enc_elgamal_cryptopp_digest_pct const digest, mk_lib_iip_key_enc_elgamal_cryptopp_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_pri_prrw_validate_signature(pri, digest, signature, is_valid);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pub_rw_construct_from_u8s(mk_lib_iip_key_enc_elgamal_cryptopp_pub_pt const pub, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pub_len_v)) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_construct_from_u8s(pub, u8s);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pub_rw_destroy(mk_lib_iip_key_enc_elgamal_cryptopp_pub_pt const pub) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_destroy(pub);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pub_rw_export_to_u8s(mk_lib_iip_key_enc_elgamal_cryptopp_pub_pct const pub, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_cryptopp_pub_len_v)) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_export_to_u8s(pub, u8s);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_cryptopp_pub_rw_validate_signature(mk_lib_iip_key_enc_elgamal_cryptopp_pub_pct const pub, mk_lib_iip_key_enc_elgamal_cryptopp_digest_pct const digest, mk_lib_iip_key_enc_elgamal_cryptopp_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_cryptopp_pub_prrw_validate_signature(pub, digest, signature, is_valid);
	return 0;
}


#endif
