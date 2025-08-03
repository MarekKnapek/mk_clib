#ifndef mk_include_guard_mk_lib_iip_key_sgn_dsa_sha1_c
#define mk_include_guard_mk_lib_iip_key_sgn_dsa_sha1_c
#include "mk_lib_iip_key_sgn_dsa_sha1.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint8);


#define mk_lib_iip_key_sgn_dsa_sha1_impl_st_hash_data mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _st_hash_data)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_is_valid mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pri_rw_is_valid)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_generate_random mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pri_rw_generate_random)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_construct_from_u8s mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pri_rw_construct_from_u8s)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_destroy mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pri_rw_destroy)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_export_pri_to_u8s mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pri_rw_export_pri_to_u8s)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_export_pub_to_u8s mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pri_rw_export_pub_to_u8s)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_get_public mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pri_rw_get_public )
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_sign_digest mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pri_rw_sign_digest)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_validate_signature mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pri_rw_validate_signature)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pub_rw_construct_from_u8s mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pub_rw_construct_from_u8s)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pub_rw_destroy mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pub_rw_destroy)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pub_rw_export_to_u8s mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pub_rw_export_to_u8s)
#define mk_lib_iip_key_sgn_dsa_sha1_impl_pub_rw_validate_signature mk_lang_concat(mk_lib_iip_key_sgn_dsa_sha1_base, _pub_rw_validate_signature)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_st_hash_data(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_key_sgn_dsa_sha1_digest_pt const digest) mk_lang_noexcept
{
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(digest);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_st_hash_data(data_buf, data_len, &digest->m_base);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_rw_is_valid(mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_dsa_sha1_pri_len_v), mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lang_assert(u8s);
	mk_lang_assert(is_valid);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_is_valid(u8s, is_valid);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_rw_generate_random(mk_lib_iip_key_sgn_dsa_sha1_pri_pt const pri) mk_lang_noexcept
{
	mk_lang_assert(pri);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_generate_random(&pri->m_base);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_rw_construct_from_u8s(mk_lib_iip_key_sgn_dsa_sha1_pri_pt const pri, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_dsa_sha1_pri_len_v)) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_construct_from_u8s(&pri->m_base, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_rw_destroy(mk_lib_iip_key_sgn_dsa_sha1_pri_pt const pri) mk_lang_noexcept
{
	mk_lang_assert(pri);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_destroy(&pri->m_base);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_rw_export_pri_to_u8s(mk_lib_iip_key_sgn_dsa_sha1_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_dsa_sha1_pri_len_v)) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_export_pri_to_u8s(&pri->m_base, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_rw_export_pub_to_u8s(mk_lib_iip_key_sgn_dsa_sha1_pri_pct const pri, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_dsa_sha1_pub_len_v)) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(u8s);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_export_pub_to_u8s(&pri->m_base, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_rw_get_public(mk_lib_iip_key_sgn_dsa_sha1_pri_pct const pri, mk_lib_iip_key_sgn_dsa_sha1_pub_pt const pub) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(pub);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_get_public(&pri->m_base, &pub->m_base);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_rw_sign_digest(mk_lib_iip_key_sgn_dsa_sha1_pri_pct const pri, mk_lib_iip_key_sgn_dsa_sha1_digest_pct const digest, mk_lib_iip_key_sgn_dsa_sha1_signature_pt const signature) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(digest);
	mk_lang_assert(signature);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_sign_digest(&pri->m_base, &digest->m_base, &signature->m_base);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pri_rw_validate_signature(mk_lib_iip_key_sgn_dsa_sha1_pri_pct const pri, mk_lib_iip_key_sgn_dsa_sha1_digest_pct const digest, mk_lib_iip_key_sgn_dsa_sha1_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lang_assert(pri);
	mk_lang_assert(digest);
	mk_lang_assert(signature);
	mk_lang_assert(is_valid);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pri_rw_validate_signature(&pri->m_base, &digest->m_base, &signature->m_base, is_valid);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pub_rw_construct_from_u8s(mk_lib_iip_key_sgn_dsa_sha1_pub_pt const pub, mk_lang_static_param(mk_sl_cui_uint8_ct, u8s, mk_lib_iip_key_sgn_dsa_sha1_pub_len_v)) mk_lang_noexcept
{
	mk_lang_assert(pub);
	mk_lang_assert(u8s);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pub_rw_construct_from_u8s(&pub->m_base, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pub_rw_destroy(mk_lib_iip_key_sgn_dsa_sha1_pub_pt const pub) mk_lang_noexcept
{
	mk_lang_assert(pub);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pub_rw_destroy(&pub->m_base);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pub_rw_export_to_u8s(mk_lib_iip_key_sgn_dsa_sha1_pub_pct const pub, mk_lang_static_param(mk_sl_cui_uint8_t, u8s, mk_lib_iip_key_sgn_dsa_sha1_pub_len_v)) mk_lang_noexcept
{
	mk_lang_assert(pub);
	mk_lang_assert(u8s);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pub_rw_export_to_u8s(&pub->m_base, u8s);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_dsa_sha1_pub_rw_validate_signature(mk_lib_iip_key_sgn_dsa_sha1_pub_pct const pub, mk_lib_iip_key_sgn_dsa_sha1_digest_pct const digest, mk_lib_iip_key_sgn_dsa_sha1_signature_pct const signature, mk_lang_types_bool_pt const is_valid) mk_lang_noexcept
{
	mk_lang_assert(pub);
	mk_lang_assert(digest);
	mk_lang_assert(signature);
	mk_lang_assert(is_valid);

	return mk_lib_iip_key_sgn_dsa_sha1_impl_pub_rw_validate_signature(&pub->m_base, &digest->m_base, &signature->m_base, is_valid);
}


#endif
