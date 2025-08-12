#ifndef mk_include_guard_mk_lib_iip_key_sgn_c
#define mk_include_guard_mk_lib_iip_key_sgn_c
#include "mk_lib_iip_key_sgn.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_destination.h"
#include "mk_lib_iip_key_sgn_dsa_sha1.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_prrw_sign_data_null(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_sl_cui_uint8_pt const signature_buf, mk_lang_types_sint_t const signature_len, mk_lang_types_sint_pt const actual_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;
	mk_lang_types_sint_t err;
	mk_lib_iip_key_sgn_dsa_sha1_digest_t digest;
	mk_lib_iip_key_sgn_dsa_sha1_pri_t key;
	mk_lib_iip_key_sgn_dsa_sha1_signature_t signature;

	mk_lang_assert(local_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature_buf || signature_len == 0);
	mk_lang_assert(signature_len >= 0);
	mk_lang_assert(actual_len);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type == mk_lib_iip_cp_destination_cert_type_e_null);

	ptr = signature_buf;
	rem = signature_len;
	tlen = mk_lib_iip_key_sgn_dsa_sha1_signature_len_v;
	if(rem >= tlen)
	{
		err = mk_lib_iip_key_sgn_dsa_sha1_st_hash_data(data_buf, data_len, &digest); mk_lang_check_rereturn(err);
		err = mk_lib_iip_key_sgn_dsa_sha1_pri_rw_construct_from_u8s(&key, &local_destination->m_basic_buffer.m_sgn_pri_key.m_bytes[0]); mk_lang_check_rereturn(err);
		err = mk_lib_iip_key_sgn_dsa_sha1_pri_rw_sign_digest(&key, &digest, &signature); mk_lang_check_rereturn(err);
		err = mk_lib_iip_key_sgn_dsa_sha1_pri_rw_destroy(&key); mk_lang_check_rereturn(err);
		mk_sl_cui_uint8_memcpy_fn(signature_buf, &signature.m_base.m_data.m_uint8s[0], tlen); ptr += tlen; rem -= tlen;
	}
	tlen = signature_len - rem;
	*actual_len = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_prrw_sign_data_hidden(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_sl_cui_uint8_pt const signature_buf, mk_lang_types_sint_t const signature_len, mk_lang_types_sint_pt const actual_len) mk_lang_noexcept
{
	mk_lang_assert(local_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature_buf || signature_len == 0);
	mk_lang_assert(signature_len >= 0);
	mk_lang_assert(actual_len);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type == mk_lib_iip_cp_destination_cert_type_e_hidden);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_prrw_sign_data_signeda(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_sl_cui_uint8_pt const signature_buf, mk_lang_types_sint_t const signature_len, mk_lang_types_sint_pt const actual_len) mk_lang_noexcept
{
	mk_lang_assert(local_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature_buf || signature_len == 0);
	mk_lang_assert(signature_len >= 0);
	mk_lang_assert(actual_len);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type == mk_lib_iip_cp_destination_cert_type_e_signeda);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_prrw_sign_data_signedb(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_sl_cui_uint8_pt const signature_buf, mk_lang_types_sint_t const signature_len, mk_lang_types_sint_pt const actual_len) mk_lang_noexcept
{
	mk_lang_assert(local_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature_buf || signature_len == 0);
	mk_lang_assert(signature_len >= 0);
	mk_lang_assert(actual_len);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type == mk_lib_iip_cp_destination_cert_type_e_signedb);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_prrw_sign_data_key(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_sl_cui_uint8_pt const signature_buf, mk_lang_types_sint_t const signature_len, mk_lang_types_sint_pt const actual_len) mk_lang_noexcept
{
	mk_lang_assert(local_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature_buf || signature_len == 0);
	mk_lang_assert(signature_len >= 0);
	mk_lang_assert(actual_len);
	mk_lang_assert(local_destination->m_remote_destination.m_certificate.m_cert_type == mk_lib_iip_cp_destination_cert_type_e_key);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_key_sgn_prrw_sign_data(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_sl_cui_uint8_pt const signature_buf, mk_lang_types_sint_t const signature_len, mk_lang_types_sint_pt const actual_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(local_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(signature_buf || signature_len == 0);
	mk_lang_assert(signature_len >= 0);
	mk_lang_assert(actual_len);

	switch(local_destination->m_remote_destination.m_certificate.m_cert_type)
	{
		case mk_lib_iip_cp_destination_cert_type_e_null   : err = mk_lib_iip_key_sgn_prrw_sign_data_null   (local_destination, data_buf, data_len, signature_buf, signature_len, actual_len); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_destination_cert_type_e_hidden : err = mk_lib_iip_key_sgn_prrw_sign_data_hidden (local_destination, data_buf, data_len, signature_buf, signature_len, actual_len); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_destination_cert_type_e_signeda: err = mk_lib_iip_key_sgn_prrw_sign_data_signeda(local_destination, data_buf, data_len, signature_buf, signature_len, actual_len); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_destination_cert_type_e_signedb: err = mk_lib_iip_key_sgn_prrw_sign_data_signedb(local_destination, data_buf, data_len, signature_buf, signature_len, actual_len); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_destination_cert_type_e_key    : err = mk_lib_iip_key_sgn_prrw_sign_data_key    (local_destination, data_buf, data_len, signature_buf, signature_len, actual_len); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_destination_cert_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_key_sgn_rw_sign_data(mk_lib_iip_cp_destination_local_pct const local_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_sl_cui_uint8_pt const signature_buf, mk_lang_types_sint_t const signature_len, mk_lang_types_sint_pt const actual_len) mk_lang_noexcept
{
	return mk_lib_iip_key_sgn_prrw_sign_data(local_destination, data_buf, data_len, signature_buf, signature_len, actual_len);
}


#endif
