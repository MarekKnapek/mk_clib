#ifndef mk_include_guard_mk_lib_iip_key_enc_elgamal_c
#define mk_include_guard_mk_lib_iip_key_enc_elgamal_c
#include "mk_lib_iip_key_enc_elgamal.h"

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
#include "mk_lib_iip_random.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_prrw_is_valid(mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_priv_len_v), mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lang_assert(u8s);
	mk_lang_assert(is_valid);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_prrw_construct_random(mk_lib_iip_key_enc_elgamal_priv_pt const pri) mk_lang_noexcept
{
	mk_lang_assert(pri);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_prrw_construct_from_u8s(mk_lib_iip_key_enc_elgamal_priv_pt const pri, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_priv_len_v)) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_prrw_destroy(mk_lib_iip_key_enc_elgamal_priv_pt const pri) mk_lang_noexcept
{
	mk_lang_assert(pri);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_prrw_export_pri_to_u8s(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_priv_len_v)) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_prrw_export_pub_to_u8s(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_publ_len_v)) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_prrw_construct_public(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_lib_iip_key_enc_elgamal_publ_pt const pub) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(pub);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_prrw_decrypt(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pct const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const data_out_act) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(data_in_buf);
	mk_lang_assert(data_in_len);
	mk_lang_assert(data_out_buf);
	mk_lang_assert(data_out_len);
	mk_lang_assert(succeeded);
	mk_lang_assert(data_out_act);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_prrw_encrypt(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pct const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_act) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(data_in_buf);
	mk_lang_assert(data_in_len);
	mk_lang_assert(data_out_buf);
	mk_lang_assert(data_out_len);
	mk_lang_assert(data_out_act);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_prrw_construct_from_pri(mk_lib_iip_key_enc_elgamal_publ_pt const pub, mk_lib_iip_key_enc_elgamal_priv_pct const pri) mk_lang_noexcept
{
	mk_lang_assert(pub);
	mk_lang_assert(pri);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_prrw_construct_from_u8s(mk_lib_iip_key_enc_elgamal_publ_pt const pub, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_publ_len_v)) mk_lang_noexcept
{
	mk_lang_assert(pub);
	mk_lang_assert(u8s);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_prrw_destroy(mk_lib_iip_key_enc_elgamal_publ_pt const pub) mk_lang_noexcept
{
	mk_lang_assert(pub);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_prrw_export_to_u8s(mk_lib_iip_key_enc_elgamal_publ_pct const pub, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_publ_len_v)) mk_lang_noexcept
{
	mk_lang_assert(pub);
	mk_lang_assert(u8s);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_prrw_encrypt(mk_lib_iip_key_enc_elgamal_publ_pct const pub, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pct const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_act) mk_lang_noexcept
{
	mk_lang_assert(pub);
	mk_lang_assert(data_in_buf);
	mk_lang_assert(data_in_len);
	mk_lang_assert(data_out_buf);
	mk_lang_assert(data_out_len);
	mk_lang_assert(data_out_act);

	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_is_valid(mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_priv_len_v), mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_priv_prrw_is_valid(u8s, is_valid);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_construct_random(mk_lib_iip_key_enc_elgamal_priv_pt const pri) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_priv_prrw_construct_random(pri);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_construct_from_u8s(mk_lib_iip_key_enc_elgamal_priv_pt const pri, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_priv_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_priv_prrw_construct_from_u8s(pri, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_destroy(mk_lib_iip_key_enc_elgamal_priv_pt const pri) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_priv_prrw_destroy(pri);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_export_pri_to_u8s(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_priv_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_priv_prrw_export_pri_to_u8s(pri, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_export_pub_to_u8s(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_publ_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_priv_prrw_export_pub_to_u8s(pri, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_construct_public(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_lib_iip_key_enc_elgamal_publ_pt const pub) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_priv_prrw_construct_public(pri, pub);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_decrypt(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pct const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const data_out_act) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_priv_prrw_decrypt(pri, data_in_buf, data_in_len, data_out_buf, data_out_len, succeeded, data_out_act);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_priv_rw_encrypt(mk_lib_iip_key_enc_elgamal_priv_pct const pri, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pct const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_act) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_priv_prrw_encrypt(pri, data_in_buf, data_in_len, data_out_buf, data_out_len, data_out_act);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_rw_construct_from_pri(mk_lib_iip_key_enc_elgamal_publ_pt const pub, mk_lib_iip_key_enc_elgamal_priv_pct const pri) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_publ_prrw_construct_from_pri(pub, pri);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_rw_construct_from_u8s(mk_lib_iip_key_enc_elgamal_publ_pt const pub, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_enc_elgamal_publ_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_publ_prrw_construct_from_u8s(pub, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_rw_destroy(mk_lib_iip_key_enc_elgamal_publ_pt const pub) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_publ_prrw_destroy(pub);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_rw_export_to_u8s(mk_lib_iip_key_enc_elgamal_publ_pct const pub, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_enc_elgamal_publ_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_publ_prrw_export_to_u8s(pub, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_enc_elgamal_publ_rw_encrypt(mk_lib_iip_key_enc_elgamal_publ_pct const pub, mk_sl_cui_uint8_pct const data_in_buf, mk_lang_types_sint_t const data_in_len, mk_sl_cui_uint8_pct const data_out_buf, mk_lang_types_sint_t const data_out_len, mk_lang_types_sint_pt const data_out_act) mk_lang_noexcept
{
	return mk_lib_iip_key_enc_elgamal_publ_prrw_encrypt(pub, data_in_buf, data_in_len, data_out_buf, data_out_len, data_out_act);
}


#endif
