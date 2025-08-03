#ifndef mk_include_guard_mk_lib_iip_key_sgn_dsa_sha1_windows_c
#define mk_include_guard_mk_lib_iip_key_sgn_dsa_sha1_windows_c
#include "mk_lib_iip_key_sgn_dsa_sha1_windows.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"
#include "mk_win_base.h"
#include "mk_win_dll_bcrypt.h"


#define mk_sl_cui_t_name mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((mk_lib_iip_key_sgn_dsa_sha1_windows_pri_len_d * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#include "mk_lang_warning_msvc_push_c4820.h"
union mk_lib_iip_key_sgn_dsa_sha1_windows_int_sml_data_u
{
	mk_lang_types_uchar_t m_uchars[20];
	mk_lang_types_uint_t m_align;
};
typedef union mk_lib_iip_key_sgn_dsa_sha1_windows_int_sml_data_u mk_lib_iip_key_sgn_dsa_sha1_windows_int_sml_data_t;
struct mk_lib_iip_key_sgn_dsa_sha1_windows_int_sml_s
{
	mk_lang_alignas(32) mk_lib_iip_key_sgn_dsa_sha1_windows_int_sml_data_t m_data;
};
typedef struct mk_lib_iip_key_sgn_dsa_sha1_windows_int_sml_s mk_lib_iip_key_sgn_dsa_sha1_windows_int_sml_t;
#include "mk_lang_warning_msvc_pop.h"

union mk_lib_iip_key_sgn_dsa_sha1_windows_int_big_data_u
{
	mk_lang_types_uchar_t m_uchars[128];
	mk_lang_types_uint_t m_align;
};
typedef union mk_lib_iip_key_sgn_dsa_sha1_windows_int_big_data_u mk_lib_iip_key_sgn_dsa_sha1_windows_int_big_data_t;
struct mk_lib_iip_key_sgn_dsa_sha1_windows_int_big_s
{
	mk_lang_alignas(64) mk_lib_iip_key_sgn_dsa_sha1_windows_int_big_data_t m_data;
};
typedef struct mk_lib_iip_key_sgn_dsa_sha1_windows_int_big_s mk_lib_iip_key_sgn_dsa_sha1_windows_int_big_t;


mk_lang_constexpr_static_inline mk_lib_iip_key_sgn_dsa_sha1_windows_int_sml_t const mk_lib_iip_key_sgn_dsa_sha1_windows_k_q =
{{{
	0xa5, 0xdf, 0xc2, 0x8f, 0xef, 0x4c, 0xa1, 0xe2, 0x86, 0x74, 0x4c, 0xd8, 0xee, 0xd9, 0xd2, 0x9d, 0x68, 0x40, 0x46, 0xb7,
}}};

mk_lang_constexpr_static_inline mk_lib_iip_key_sgn_dsa_sha1_windows_int_big_t const mk_lib_iip_key_sgn_dsa_sha1_windows_k_g =
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

mk_lang_constexpr_static_inline mk_lib_iip_key_sgn_dsa_sha1_windows_int_big_t const mk_lib_iip_key_sgn_dsa_sha1_windows_k_p =
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


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_prst_hash_data(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_dsa_sha1_windows_digest_pt const digest) mk_lang_noexcept
{
	mk_win_base_ntstatus_t st;
	mk_win_dll_bcrypt_provider_t sha1_provider;
	mk_win_dll_bcrypt_hash_t sha1_hasher;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);

	st = mk_win_dll_bcrypt_open_algorithm_provider(&sha1_provider, mk_win_dll_bcrypt_k_algorithm_sha1, mk_win_base_null, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_create_hash(sha1_provider, &sha1_hasher, mk_win_base_null, 0, mk_win_base_null, 0, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_hash_data(sha1_hasher, data_buf, ((mk_lang_types_ulong_t)(data_len)), mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_finish_hash(sha1_hasher, &digest->m_data.m_uint8s[0], mk_lang_countof(digest->m_data.m_uint8s), mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_destroy_hash(sha1_hasher); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_close_algorithm_provider(sha1_provider, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	return 0;
}


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_load_q(mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_buis_uchar_be(x, &mk_lib_iip_key_sgn_dsa_sha1_windows_k_q.m_data.m_uchars[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_u8s_be(mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_pt const x, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_size_bytes_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_u8s_be_storage_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_size_bytes_v];
		mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_t m_pri_single;
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_u8s_be_storage_data_u mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_u8s_be_storage_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_u8s_be_storage_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_u8s_be_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_u8s_be_storage_s mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_u8s_be_storage_t;

	mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_u8s_be_storage_t storage mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(u8s);

	mk_sl_cui_uint8_to_bi_uchar_many(u8s, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars));
	mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_buis_uchar_be(x, &storage.m_data.m_uchars[0]);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_is_valid(mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pri_len_v)) mk_lang_noexcept
{
	mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_t q mk_lang_constexpr_init;
	mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_t pri mk_lang_constexpr_init;
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(u8s);

	mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_load_q(&q);
	mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_from_u8s_be(&pri, u8s);
	ret =
		!mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_is_zero(&pri) &&
		mk_lib_iip_key_sgn_dsa_sha1_windows_integer_pri_single_lt(&pri, &q);
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_generate_random_2(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pt const pri) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_generate_random_storage_data_u
	{
		mk_win_dll_bcrypt_dsa_parameter_header_t m_header;
		mk_sl_cui_uint8_t m_uint8s[sizeof(mk_win_dll_bcrypt_dsa_parameter_header_t) + 2 * 128];
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_generate_random_storage_data_u mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_generate_random_storage_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_generate_random_storage_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_generate_random_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_generate_random_storage_s mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_generate_random_storage_t;

	mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_generate_random_storage_t storage;
	mk_sl_cui_uint8_pt stor_q;
	mk_sl_cui_uint8_pt stor_p;
	mk_sl_cui_uint8_pt stor_g;
	mk_win_base_ntstatus_t st;
	mk_win_dll_bcrypt_provider_t dsa_provider;
	mk_win_dll_bcrypt_key_t dsa_keys;

	mk_lang_assert(pri);

	stor_q = ((mk_sl_cui_uint8_pt)(&storage.m_data.m_header.m_q[0]));
	stor_p = &storage.m_data.m_uint8s[sizeof(storage.m_data.m_header)];
	stor_g = stor_p + 128;

	storage.m_data.m_header.m_structure_size = sizeof(storage);
	storage.m_data.m_header.m_magic = mk_win_dll_bcrypt_dsa_parameter_header_k_magic;
	storage.m_data.m_header.m_key_len = 128;
	storage.m_data.m_header.m_count[0] = 0xff;
	storage.m_data.m_header.m_count[1] = 0xff;
	storage.m_data.m_header.m_count[2] = 0xff;
	storage.m_data.m_header.m_count[3] = 0xff;
	mk_lang_string_memclr_uc_fn(&storage.m_data.m_header.m_seed[0], mk_lang_countof(storage.m_data.m_header.m_seed));
	mk_sl_cui_uint8_from_bi_uchar_many(stor_q, &mk_lib_iip_key_sgn_dsa_sha1_windows_k_q.m_data.m_uchars[0], mk_lang_countof(mk_lib_iip_key_sgn_dsa_sha1_windows_k_q.m_data.m_uchars));
	mk_sl_cui_uint8_from_bi_uchar_many(stor_p, &mk_lib_iip_key_sgn_dsa_sha1_windows_k_p.m_data.m_uchars[0], mk_lang_countof(mk_lib_iip_key_sgn_dsa_sha1_windows_k_p.m_data.m_uchars));
	mk_sl_cui_uint8_from_bi_uchar_many(stor_g, &mk_lib_iip_key_sgn_dsa_sha1_windows_k_g.m_data.m_uchars[0], mk_lang_countof(mk_lib_iip_key_sgn_dsa_sha1_windows_k_g.m_data.m_uchars));

	st = mk_win_dll_bcrypt_open_algorithm_provider(&dsa_provider, mk_win_dll_bcrypt_k_algorithm_dsa, mk_win_base_null, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_generate_key_pair(dsa_provider, &dsa_keys, 1024, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_set_property(mk_win_dll_bcrypt_handle_from(dsa_keys.m_handle), mk_win_dll_bcrypt_k_dsa_parameters, &storage, sizeof(storage), mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_finalize_key_pair(dsa_keys, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_close_algorithm_provider(dsa_provider, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	pri->m_key_handle = dsa_keys;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_export_pri_to_u8s(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pri_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_u
	{
		mk_win_dll_bcrypt_blob_key_dsa_v1_t m_header;
		mk_sl_cui_uint8_t m_uint8s[sizeof(mk_win_dll_bcrypt_blob_key_dsa_v1_t) + 3 * 128 + 20];
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_u mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_s mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_t;

	mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_t storage;
	mk_sl_cui_uint8_pct stor_p;
	mk_sl_cui_uint8_pct stor_g;
	mk_sl_cui_uint8_pct stor_pub;
	mk_sl_cui_uint8_pct stor_pri;
	mk_win_base_ntstatus_t st;
	mk_lang_types_ulong_t actual_len;

	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	stor_p = &storage.m_data.m_uint8s[sizeof(storage.m_data.m_header)];
	stor_g = stor_p + 128;
	stor_pub = stor_g + 128;
	stor_pri = stor_pub + 128;

	st = mk_win_dll_bcrypt_export_key(pri->m_key_handle, mk_win_dll_bcrypt_key_get_null(), mk_win_dll_bcrypt_k_blob_type_dsa_private, &storage, sizeof(storage), &actual_len, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0); mk_lang_check_return(actual_len == sizeof(storage));
	mk_sl_cui_uint8_memcpy_fn(u8s, stor_pri, 20);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_is_good(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pt const pri, mk_lang_types_bool_pt const is_good) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_t u8s[mk_lib_iip_key_sgn_dsa_sha1_windows_pri_len_v];
	mk_lang_types_bool_t gud;

	mk_lang_assert(pri);
	mk_lang_assert(is_good);

	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_export_pri_to_u8s(pri, &u8s[0]); mk_lang_check_rereturn(err);
	gud = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_is_valid(u8s);
	*is_good = gud;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_generate_random(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pt const pri) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;

	mk_lang_assert(pri);

	do
	{
		err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_generate_random_2(pri); mk_lang_check_rereturn(err);
		err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_is_good(pri, &gud); mk_lang_check_rereturn(err);
	}while(!gud);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_construct_from_u8s(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pt const pri, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pri_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_data_u
	{
		mk_win_dll_bcrypt_blob_key_dsa_v1_t m_header;
		mk_sl_cui_uint8_t m_uint8s[sizeof(mk_win_dll_bcrypt_blob_key_dsa_v1_t) + 3 * 128 + 20];
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_data_u mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_s mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_t;

	mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_t storage;
	mk_sl_cui_uint8_pt stor_q;
	mk_sl_cui_uint8_pt stor_p;
	mk_sl_cui_uint8_pt stor_g;
	mk_sl_cui_uint8_pt stor_pub;
	mk_sl_cui_uint8_pt stor_pri;
	mk_win_base_ntstatus_t st;
	mk_win_dll_bcrypt_provider_t dsa_provider;
	mk_win_dll_bcrypt_key_t dsa_keys;

	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	stor_q = ((mk_sl_cui_uint8_pt)(&storage.m_data.m_header.m_q[0]));
	stor_p = &storage.m_data.m_uint8s[sizeof(storage.m_data.m_header)];
	stor_g = stor_p + 128;
	stor_pub = stor_g + 128;
	stor_pri = stor_pub + 128;

	storage.m_data.m_header.m_magic = mk_win_dll_bcrypt_blob_key_dsa_v1_k_magic_pri;
	storage.m_data.m_header.m_key_len = 128;
	storage.m_data.m_header.m_count[0] = 0xff;
	storage.m_data.m_header.m_count[1] = 0xff;
	storage.m_data.m_header.m_count[2] = 0xff;
	storage.m_data.m_header.m_count[3] = 0xff;
	mk_lang_string_memclr_uc_fn(&storage.m_data.m_header.m_seed[0], mk_lang_countof(storage.m_data.m_header.m_seed));
	mk_sl_cui_uint8_from_bi_uchar_many(stor_q, &mk_lib_iip_key_sgn_dsa_sha1_windows_k_q.m_data.m_uchars[0], mk_lang_countof(mk_lib_iip_key_sgn_dsa_sha1_windows_k_q.m_data.m_uchars));
	mk_sl_cui_uint8_from_bi_uchar_many(stor_p, &mk_lib_iip_key_sgn_dsa_sha1_windows_k_p.m_data.m_uchars[0], mk_lang_countof(mk_lib_iip_key_sgn_dsa_sha1_windows_k_p.m_data.m_uchars));
	mk_sl_cui_uint8_from_bi_uchar_many(stor_g, &mk_lib_iip_key_sgn_dsa_sha1_windows_k_g.m_data.m_uchars[0], mk_lang_countof(mk_lib_iip_key_sgn_dsa_sha1_windows_k_g.m_data.m_uchars));
	mk_sl_cui_uint8_memclr_fn(stor_pub, 128);
	mk_sl_cui_uint8_memcpy_fn(stor_pri, u8s, 20);
	mk_lang_check_return(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_is_valid(u8s));

	st = mk_win_dll_bcrypt_open_algorithm_provider(&dsa_provider, mk_win_dll_bcrypt_k_algorithm_dsa, mk_win_base_null, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_import_key_pair(dsa_provider, mk_win_dll_bcrypt_key_get_null(), mk_win_dll_bcrypt_k_blob_type_dsa_private, &dsa_keys, &storage, sizeof(storage), mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_close_algorithm_provider(dsa_provider, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	pri->m_key_handle = dsa_keys;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_destroy(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pt const pri) mk_lang_noexcept
{
	mk_win_base_ntstatus_t st;

	mk_lang_assert(pri);

	st = mk_win_dll_bcrypt_destroy_key(pri->m_key_handle); mk_lang_check_return(st == 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_export_pub_to_u8s(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pub_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_u
	{
		mk_win_dll_bcrypt_blob_key_dsa_v1_t m_header;
		mk_sl_cui_uint8_t m_uint8s[sizeof(mk_win_dll_bcrypt_blob_key_dsa_v1_t) + 3 * 128];
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_u mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_s mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_t;

	mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_t storage;
	mk_sl_cui_uint8_pct stor_p;
	mk_sl_cui_uint8_pct stor_g;
	mk_sl_cui_uint8_pct stor_pub;
	mk_win_base_ntstatus_t st;
	mk_lang_types_ulong_t actual_len;

	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	stor_p = &storage.m_data.m_uint8s[sizeof(storage.m_data.m_header)];
	stor_g = stor_p + 128;
	stor_pub = stor_g + 128;

	st = mk_win_dll_bcrypt_export_key(pri->m_key_handle, mk_win_dll_bcrypt_key_get_null(), mk_win_dll_bcrypt_k_blob_type_dsa_public, &storage, sizeof(storage), &actual_len, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0); mk_lang_check_return(actual_len == sizeof(storage));
	mk_sl_cui_uint8_memcpy_fn(u8s, stor_pub, 128);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_sign_digest(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pct const pri, mk_lib_iip_key_sgn_dsa_sha1_windows_digest_pct const digest, mk_lib_iip_key_sgn_dsa_sha1_windows_signature_pt const signature) mk_lang_noexcept
{
	mk_win_base_ntstatus_t st;
	mk_lang_types_ulong_t actual_len;

	mk_lang_assert(pri);
	mk_lang_assert(digest);
	mk_lang_assert(signature);

	st = mk_win_dll_bcrypt_sign_hash(pri->m_key_handle, mk_win_base_null, &digest->m_data.m_uint8s[0], mk_lang_countof(digest->m_data.m_uint8s), &signature->m_data.m_uint8s[0], mk_lang_countof(signature->m_data.m_uint8s), &actual_len, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0); mk_lang_check_return(actual_len == mk_lang_countof(signature->m_data.m_uint8s));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_validate_signature(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pct const pri, mk_lib_iip_key_sgn_dsa_sha1_windows_digest_pct const digest, mk_lib_iip_key_sgn_dsa_sha1_windows_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_win_base_ntstatus_t st;

	mk_lang_assert(pri);
	mk_lang_assert(digest);
	mk_lang_assert(signature);
	mk_lang_assert(is_valid);

	st = mk_win_dll_bcrypt_verify_signature(pri->m_key_handle, mk_win_base_null, &digest->m_data.m_uint8s[0], mk_lang_countof(digest->m_data.m_uint8s), &signature->m_data.m_uint8s[0], mk_lang_countof(signature->m_data.m_uint8s), mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0 || st == ((mk_win_base_ntstatus_t)(0xc000a000l)));
	*is_valid = st == 0;
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pub_prrw_construct_from_u8s(mk_lib_iip_key_sgn_dsa_sha1_windows_pub_pt const pub, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pub_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_data_u
	{
		mk_win_dll_bcrypt_blob_key_dsa_v1_t m_header;
		mk_sl_cui_uint8_t m_uint8s[sizeof(mk_win_dll_bcrypt_blob_key_dsa_v1_t) + 3 * 128];
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_data_u mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_s mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_t;

	mk_lib_iip_key_sgn_dsa_sha1_windows_pri_construct_from_u8s_storage_t storage;
	mk_sl_cui_uint8_pt stor_q;
	mk_sl_cui_uint8_pt stor_p;
	mk_sl_cui_uint8_pt stor_g;
	mk_sl_cui_uint8_pt stor_pub;
	mk_win_base_ntstatus_t st;
	mk_win_dll_bcrypt_provider_t dsa_provider;
	mk_win_dll_bcrypt_key_t dsa_key;

	mk_lang_assert(pub);
	mk_lang_assert(u8s);

	stor_q = ((mk_sl_cui_uint8_pt)(&storage.m_data.m_header.m_q[0]));
	stor_p = &storage.m_data.m_uint8s[sizeof(storage.m_data.m_header)];
	stor_g = stor_p + 128;
	stor_pub = stor_g + 128;

	storage.m_data.m_header.m_magic = mk_win_dll_bcrypt_blob_key_dsa_v1_k_magic_pub;
	storage.m_data.m_header.m_key_len = 128;
	storage.m_data.m_header.m_count[0] = 0xff;
	storage.m_data.m_header.m_count[1] = 0xff;
	storage.m_data.m_header.m_count[2] = 0xff;
	storage.m_data.m_header.m_count[3] = 0xff;
	mk_lang_string_memclr_uc_fn(&storage.m_data.m_header.m_seed[0], mk_lang_countof(storage.m_data.m_header.m_seed));
	mk_sl_cui_uint8_from_bi_uchar_many(stor_q, &mk_lib_iip_key_sgn_dsa_sha1_windows_k_q.m_data.m_uchars[0], mk_lang_countof(mk_lib_iip_key_sgn_dsa_sha1_windows_k_q.m_data.m_uchars));
	mk_sl_cui_uint8_from_bi_uchar_many(stor_p, &mk_lib_iip_key_sgn_dsa_sha1_windows_k_p.m_data.m_uchars[0], mk_lang_countof(mk_lib_iip_key_sgn_dsa_sha1_windows_k_p.m_data.m_uchars));
	mk_sl_cui_uint8_from_bi_uchar_many(stor_g, &mk_lib_iip_key_sgn_dsa_sha1_windows_k_g.m_data.m_uchars[0], mk_lang_countof(mk_lib_iip_key_sgn_dsa_sha1_windows_k_g.m_data.m_uchars));
	mk_sl_cui_uint8_memcpy_fn(stor_pub, u8s, 128);

	st = mk_win_dll_bcrypt_open_algorithm_provider(&dsa_provider, mk_win_dll_bcrypt_k_algorithm_dsa, mk_win_base_null, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_import_key_pair(dsa_provider, mk_win_dll_bcrypt_key_get_null(), mk_win_dll_bcrypt_k_blob_type_dsa_public, &dsa_key, &storage, sizeof(storage), mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	st = mk_win_dll_bcrypt_close_algorithm_provider(dsa_provider, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0);
	pub->m_key_handle = dsa_key;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pub_prrw_destroy(mk_lib_iip_key_sgn_dsa_sha1_windows_pub_pt const pub) mk_lang_noexcept
{
	mk_win_base_ntstatus_t st;

	mk_lang_assert(pub);

	st = mk_win_dll_bcrypt_destroy_key(pub->m_key_handle); mk_lang_check_return(st == 0);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pub_prrw_export_to_u8s(mk_lib_iip_key_sgn_dsa_sha1_windows_pub_pct const pub, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pub_len_v)) mk_lang_noexcept
{
	union mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_u
	{
		mk_win_dll_bcrypt_blob_key_dsa_v1_t m_header;
		mk_sl_cui_uint8_t m_uint8s[sizeof(mk_win_dll_bcrypt_blob_key_dsa_v1_t) + 3 * 128];
	};
	typedef union mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_u mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_t;
	struct mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_s
	{
		mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_data_t m_data;
	};
	typedef struct mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_s mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_t;

	mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s_storage_t storage;
	mk_sl_cui_uint8_pct stor_p;
	mk_sl_cui_uint8_pct stor_g;
	mk_sl_cui_uint8_pct stor_pub;
	mk_win_base_ntstatus_t st;
	mk_lang_types_ulong_t actual_len;

	mk_lang_assert(pub);
	mk_lang_assert(u8s);

	stor_p = &storage.m_data.m_uint8s[sizeof(storage.m_data.m_header)];
	stor_g = stor_p + 128;
	stor_pub = stor_g + 128;

	st = mk_win_dll_bcrypt_export_key(pub->m_key_handle, mk_win_dll_bcrypt_key_get_null(), mk_win_dll_bcrypt_k_blob_type_dsa_public, &storage, sizeof(storage), &actual_len, mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0); mk_lang_check_return(actual_len == sizeof(storage));
	mk_sl_cui_uint8_memcpy_fn(u8s, stor_pub, 128);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pub_prrw_validate_signature(mk_lib_iip_key_sgn_dsa_sha1_windows_pub_pct const pub, mk_lib_iip_key_sgn_dsa_sha1_windows_digest_pct const digest, mk_lib_iip_key_sgn_dsa_sha1_windows_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_win_base_ntstatus_t st;

	mk_lang_assert(pub);
	mk_lang_assert(digest);
	mk_lang_assert(signature);
	mk_lang_assert(is_valid);

	st = mk_win_dll_bcrypt_verify_signature(pub->m_key_handle, mk_win_base_null, &digest->m_data.m_uint8s[0], mk_lang_countof(digest->m_data.m_uint8s), &signature->m_data.m_uint8s[0], mk_lang_countof(signature->m_data.m_uint8s), mk_win_dll_bcrypt_k_flag_none); mk_lang_check_return(st == 0 || st == ((mk_win_base_ntstatus_t)(0xc000a000l)));
	*is_valid = st == 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_get_public(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pct const pri, mk_lib_iip_key_sgn_dsa_sha1_windows_pub_pt const pub) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_t u8s[mk_lib_iip_key_sgn_dsa_sha1_windows_pub_len_v];

	mk_lang_assert(pri);
	mk_lang_assert(pub);

	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_export_pub_to_u8s(pri, &u8s[0]); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_dsa_sha1_windows_pub_prrw_construct_from_u8s(pub, &u8s[0]); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_st_hash_data(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_dsa_sha1_windows_digest_pt const digest) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_prst_hash_data(data_buf, data_len, digest);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_is_valid(mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pri_len_v), mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lang_assert(is_valid);

	*is_valid = mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_is_valid(u8s);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_generate_random(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pt const pri) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_generate_random(pri);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_construct_from_u8s(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pt const pri, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pri_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_construct_from_u8s(pri, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_destroy(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pt const pri) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_destroy(pri);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_export_pri_to_u8s(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pri_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_export_pri_to_u8s(pri, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_export_pub_to_u8s(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pub_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_export_pub_to_u8s(pri, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_get_public(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pct const pri, mk_lib_iip_key_sgn_dsa_sha1_windows_pub_pt const pub) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_get_public(pri, pub);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_sign_digest(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pct const pri, mk_lib_iip_key_sgn_dsa_sha1_windows_digest_pct const digest, mk_lib_iip_key_sgn_dsa_sha1_windows_signature_pt const signature) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_sign_digest(pri, digest, signature);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pri_rw_validate_signature(mk_lib_iip_key_sgn_dsa_sha1_windows_pri_pct const pri, mk_lib_iip_key_sgn_dsa_sha1_windows_digest_pct const digest, mk_lib_iip_key_sgn_dsa_sha1_windows_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pri_prrw_validate_signature(pri, digest, signature, is_valid);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_construct_from_u8s(mk_lib_iip_key_sgn_dsa_sha1_windows_pub_pt const pub, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pub_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pub_prrw_construct_from_u8s(pub, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_destroy(mk_lib_iip_key_sgn_dsa_sha1_windows_pub_pt const pub) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pub_prrw_destroy(pub);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_export_to_u8s(mk_lib_iip_key_sgn_dsa_sha1_windows_pub_pct const pub, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_dsa_sha1_windows_pub_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pub_prrw_export_to_u8s(pub, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_windows_pub_rw_validate_signature(mk_lib_iip_key_sgn_dsa_sha1_windows_pub_pct const pub, mk_lib_iip_key_sgn_dsa_sha1_windows_digest_pct const digest, mk_lib_iip_key_sgn_dsa_sha1_windows_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_dsa_sha1_windows_pub_prrw_validate_signature(pub, digest, signature, is_valid);
}


#else
static void mk_lib_iip_key_sgn_dsa_sha1_windows_dummy(void){}
#endif
#endif
