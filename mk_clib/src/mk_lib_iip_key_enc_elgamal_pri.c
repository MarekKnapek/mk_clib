#ifndef mk_include_guard_mk_lib_iip_key_enc_elgamal_pri_c
#define mk_include_guard_mk_lib_iip_key_enc_elgamal_pri_c
#include "mk_lib_iip_key_enc_elgamal_pri.h"

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_random.h"


#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_pri_integer_single
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (1 * ((256 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_key_enc_elgamal_pri_integer_double
#define mk_sl_cui_t_base_type_name mk_lang_bui_uint
#define mk_sl_cui_t_count (2 * ((256 * mk_lang_charbit) / mk_lang_bui_uint_size_bits_d))
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single(mk_lib_iip_key_enc_elgamal_pri_integer_single_pct const a, mk_lib_iip_key_enc_elgamal_pub_integer_single_pt const b) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pri_integer_single_size_bytes_v)), ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)))];
		mk_lib_iip_key_enc_elgamal_pri_integer_single_t m_pri_single;
		mk_lib_iip_key_enc_elgamal_pub_integer_single_t m_pub_single;
	};
	typedef union mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single_data_u mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single_data_t;
	struct mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single_s
	{
		mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single_s mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single_t;

	mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single_t storage mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pri_integer_single_size_bytes_v)) == ((mk_lang_types_sint_t)(mk_lib_iip_key_enc_elgamal_pub_integer_single_size_bytes_v)));

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_lib_iip_key_enc_elgamal_pri_integer_single_to_buis_uchar_le(a, &storage.m_data.m_uchars[0]);
	mk_lib_iip_key_enc_elgamal_pub_integer_single_from_buis_uchar_le(b, &storage.m_data.m_uchars[0]);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_pri_generate_random(mk_lib_iip_key_enc_elgamal_pri_pt const pri) mk_lang_noexcept
{
	union mk_lib_iip_key_enc_elgamal_pri_generate_random_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_pri_integer_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_pri_t m_elgamal_key_pri;
	};
	typedef union mk_lib_iip_key_enc_elgamal_pri_generate_random_data_u mk_lib_iip_key_enc_elgamal_pri_generate_random_data_t;
	struct mk_lib_iip_key_enc_elgamal_pri_generate_random_s
	{
		mk_lib_iip_key_enc_elgamal_pri_generate_random_data_t m_data;
	};
	typedef struct mk_lib_iip_key_enc_elgamal_pri_generate_random_s mk_lib_iip_key_enc_elgamal_pri_generate_random_t;

	mk_lang_types_sint_t err;
	mk_lib_iip_key_enc_elgamal_pri_generate_random_t storage;

	mk_lang_assert(pri);

	err = mk_lib_iip_random_generate_uchars(&storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err);
	mk_lib_iip_key_enc_elgamal_pri_integer_single_from_buis_uchar_le(&pri->m_data.m_integer, &storage.m_data.m_uchars[0]);
	return 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_key_enc_elgamal_pri_compute_public(mk_lib_iip_key_enc_elgamal_pri_pct const pri, mk_lib_iip_key_enc_elgamal_pub_pt const pub) mk_lang_noexcept
{
	mk_lib_iip_key_enc_elgamal_pub_integer_single_t generator mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_pub_integer_single_t prime mk_lang_constexpr_init;
	mk_lib_iip_key_enc_elgamal_pub_integer_single_t priv mk_lang_constexpr_init;

	mk_lang_assert(pri);
	mk_lang_assert(pub);

	mk_lib_iip_key_enc_elgamal_pub_integer_single_set_two(&generator);
	mk_lib_iip_key_enc_elgamal_pub_integer_single_load_p(&prime);
	mk_lib_iip_key_enc_elgamal_pri_integer_single_to_pub_single(&pri->m_data.m_integer, &priv);
	mk_lib_iip_key_enc_elgamal_pub_integer_single_mod_pow(&generator, &priv, &prime, &pub->m_data.m_integer);
}


#endif
