#ifndef mk_include_guard_mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_c
#define mk_include_guard_mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_c
#include "mk_lib_iip_key_sgn_eddsa_25519_sha512_tom.h"

#include "mk_lang_external_ltc.h"
#if mk_lang_external_ltc_have

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_random_tom.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_generate_random(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pt const pri) mk_lang_noexcept
{
	mk_sl_random_tom_pt random_tom;
	mk_lang_types_sint_t st;

	mk_lang_assert(pri);
	mk_lang_check_return(find_hash(sha512_desc.name) != -1);

	random_tom = mk_sl_random_tom_get_internal_state(); mk_lang_assert(random_tom);
	st = ed25519_make_key(&random_tom->m_tom_prng_state, random_tom->m_tom_prng_idx, &pri->m_tom_key); mk_lang_check_return(st == CRYPT_OK);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_construct_from_u8s(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pt const pri, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v)) mk_lang_noexcept
{
	mk_lang_types_uchar_pct key_data_buf;
	mk_lang_types_ulong_t key_data_len;
	mk_lang_types_sint_t st;

	mk_lang_assert(pri);
	mk_lang_assert(u8s);
	mk_lang_check_return(find_hash(sha512_desc.name) != -1);

	key_data_buf = ((mk_lang_types_uchar_pct)(u8s));
	key_data_len = mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v;
	st = ed25519_import_raw(key_data_buf, key_data_len, PK_PRIVATE, &pri->m_tom_key); mk_lang_check_return(st == CRYPT_OK);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_destroy(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pt const pri) mk_lang_noexcept
{
	mk_lang_assert(pri);

	((mk_lang_types_void_t)(pri));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_export_pri_to_u8s(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v)) mk_lang_noexcept
{
	mk_lang_types_uchar_pt key_data_buf;
	mk_lang_types_ulong_t key_data_len;
	mk_lang_types_sint_t st;

	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	key_data_buf = ((mk_lang_types_uchar_pt)(u8s));
	key_data_len = mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v;
	st = ed25519_export(key_data_buf, &key_data_len, PK_PRIVATE, &pri->m_tom_key); mk_lang_check_return(st == CRYPT_OK); mk_lang_check_return(key_data_len == mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_export_pub_to_u8s(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_len_v)) mk_lang_noexcept
{
	mk_lang_types_uchar_pt key_data_buf;
	mk_lang_types_ulong_t key_data_len;
	mk_lang_types_sint_t st;

	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	key_data_buf = ((mk_lang_types_uchar_pt)(u8s));
	key_data_len = mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v;
	st = ed25519_export(key_data_buf, &key_data_len, PK_PUBLIC, &pri->m_tom_key); mk_lang_check_return(st == CRYPT_OK); mk_lang_check_return(key_data_len == mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_sign_message(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pct const pri, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_signature_pt const signature) mk_lang_noexcept
{
	mk_lang_types_uchar_pct msg;
	mk_lang_types_ulong_t msglen;
	mk_lang_types_uchar_pt sig;
	mk_lang_types_ulong_t siglen;
	mk_lang_types_sint_t st;

	mk_lang_assert(pri);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature);

	msg = ((mk_lang_types_uchar_pct)(data_buf));
	msglen = ((mk_lang_types_ulong_t)(data_len));
	sig = ((mk_lang_types_uchar_pt)(signature));
	siglen = ((mk_lang_types_ulong_t)(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_signature_len_v));
	st = ed25519_sign(msg, msglen, sig, &siglen, &pri->m_tom_key); mk_lang_check_return(st == CRYPT_OK); mk_lang_check_return(siglen == ((mk_lang_types_ulong_t)(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_signature_len_v)));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_validate_signature(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pct const pri, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lang_types_uchar_pct msg;
	mk_lang_types_ulong_t msglen;
	mk_lang_types_uchar_pt sig;
	mk_lang_types_ulong_t siglen;
	mk_lang_types_sint_t stat;
	mk_lang_types_sint_t st;

	mk_lang_assert(pri);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature);
	mk_lang_assert(is_valid);

	msg = ((mk_lang_types_uchar_pct)(data_buf));
	msglen = ((mk_lang_types_ulong_t)(data_len));
	sig = ((mk_lang_types_uchar_pt)(signature));
	siglen = ((mk_lang_types_ulong_t)(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_signature_len_v));
	st = ed25519_verify(msg, msglen, sig, siglen, &stat, &pri->m_tom_key); mk_lang_check_return(st == CRYPT_OK); mk_lang_check_return(stat == 0 || stat == 1);
	*is_valid = stat == 1;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_prrw_construct_from_u8s(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_pt const pub, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_len_v)) mk_lang_noexcept
{
	mk_lang_types_uchar_pct key_data_buf;
	mk_lang_types_ulong_t key_data_len;
	mk_lang_types_sint_t st;

	mk_lang_assert(pub);
	mk_lang_assert(u8s);

	key_data_buf = ((mk_lang_types_uchar_pct)(u8s));
	key_data_len = mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v;
	st = ed25519_import_raw(key_data_buf, key_data_len, PK_PUBLIC, &pub->m_tom_key); mk_lang_check_return(st == CRYPT_OK);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_prrw_destroy(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_pt const pub) mk_lang_noexcept
{
	mk_lang_assert(pub);

	((mk_lang_types_void_t)(pub));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_prrw_export_to_u8s(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_pct const pub, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_len_v)) mk_lang_noexcept
{
	mk_lang_types_uchar_pt key_data_buf;
	mk_lang_types_ulong_t key_data_len;
	mk_lang_types_sint_t st;

	mk_lang_assert(pub);
	mk_lang_assert(u8s);

	key_data_buf = ((mk_lang_types_uchar_pt)(u8s));
	key_data_len = mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v;
	st = ed25519_export(key_data_buf, &key_data_len, PK_PUBLIC, &pub->m_tom_key); mk_lang_check_return(st == CRYPT_OK); mk_lang_check_return(key_data_len == mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_prrw_validate_signature(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_pct const pub, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lang_types_uchar_pct msg;
	mk_lang_types_ulong_t msglen;
	mk_lang_types_uchar_pt sig;
	mk_lang_types_ulong_t siglen;
	mk_lang_types_sint_t stat;
	mk_lang_types_sint_t st;

	mk_lang_assert(pub);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature);
	mk_lang_assert(is_valid);

	msg = ((mk_lang_types_uchar_pct)(data_buf));
	msglen = ((mk_lang_types_ulong_t)(data_len));
	sig = ((mk_lang_types_uchar_pt)(signature));
	siglen = ((mk_lang_types_ulong_t)(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_signature_len_v));
	st = ed25519_verify(msg, msglen, sig, siglen, &stat, &pub->m_tom_key); mk_lang_check_return(st == CRYPT_OK); mk_lang_check_return(stat == 0 || stat == 1);
	*is_valid = stat == 1;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_get_public(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pct const pri, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_pt const pub) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_t u8s[mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_len_v];

	mk_lang_assert(pri);
	mk_lang_assert(pub);

	err = mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_export_pub_to_u8s(pri, &u8s[0]); mk_lang_check_rereturn(err);
	err = mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_prrw_construct_from_u8s(pub, &u8s[0]); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_rw_generate_random(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pt const pri) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_generate_random(pri);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_rw_construct_from_u8s(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pt const pri, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_construct_from_u8s(pri, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_rw_destroy(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pt const pri) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_destroy(pri);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_rw_export_pri_to_u8s(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_export_pri_to_u8s(pri, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_rw_export_pub_to_u8s(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_export_pub_to_u8s(pri, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_rw_get_public(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pct const pri, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_pt const pub) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_get_public(pri, pub);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_rw_sign_message(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pct const pri, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_signature_pt const signature) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_sign_message(pri, data_buf, data_len, signature);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_rw_validate_signature(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_pct const pri, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pri_prrw_validate_signature(pri, data_buf, data_len, signature, is_valid);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_rw_construct_from_u8s(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_pt const pub, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_prrw_construct_from_u8s(pub, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_rw_destroy(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_pt const pub) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_prrw_destroy(pub);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_rw_export_to_u8s(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_pct const pub, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_len_v)) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_prrw_export_to_u8s(pub, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_rw_validate_signature(mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_pct const pub, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_pub_prrw_validate_signature(pub, data_buf, data_len, signature, is_valid);
}


#else
void mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_dummy(void);
void mk_lib_iip_key_sgn_eddsa_25519_sha512_tom_dummy(void){}
#endif
#endif
