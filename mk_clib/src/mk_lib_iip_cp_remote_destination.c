#ifndef mk_include_guard_mk_lib_iip_cp_remote_destination_c
#define mk_include_guard_mk_lib_iip_cp_remote_destination_c
#include "mk_lib_iip_cp_remote_destination.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_key_sgn_dsa_sha1.h"
#include "mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub.h"
#include "mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub.h"
#include "mk_lib_iip_time.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


#if 0

#define mk_sl_cui_t_name mk_lib_iip_cp_remote_destination_sessionid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint16
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint16_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_remote_destination_messageid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_remote_destination_tunnelid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_remote_destination_requestid
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_remote_destination_nonce
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint32
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint32_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_cp_remote_destination_date
#define mk_sl_cui_t_base_type_name mk_lib_iip_time_timestamp
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lib_iip_time_timestamp_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_strpair_rw_construct_void(mk_lib_iip_cp_remote_destination_strpair_pt const strpair) mk_lang_noexcept
{
	mk_lang_assert(strpair);

	strpair->m_key.m_len = 0;
	strpair->m_val.m_len = 0;
	#if defined DEBUG || defined _DEBUG
	strpair->m_key.m_buf[0] = '\0';
	strpair->m_val.m_buf[0] = '\0';
	#endif
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_strpair_rw_destroy(mk_lib_iip_cp_remote_destination_strpair_pt const strpair) mk_lang_noexcept
{
	mk_lang_assert(strpair);

	((mk_lang_types_void_t)(strpair));
	return 0;
}

#define mk_sl_fixed_vector_t_name mk_lib_iip_cp_remote_destination_strpairs
#define mk_sl_fixed_vector_t_element_type mk_lib_iip_cp_remote_destination_strpair_t
#define mk_sl_fixed_vector_t_capacity 16 /* todo */
#define mk_sl_fixed_vector_t_element_construct_void mk_lib_iip_cp_remote_destination_strpair_rw_construct_void
#define mk_sl_fixed_vector_t_element_destroy mk_lib_iip_cp_remote_destination_strpair_rw_destroy
#include "mk_sl_fixed_vector_inl_filec.h"
#include "mk_sl_fixed_vector_inl_fileu.h"

#define mk_sl_fixed_vector_t_name mk_lib_iip_cp_remote_destination_hash_and_tunnelids
#define mk_sl_fixed_vector_t_element_type mk_lib_iip_cp_remote_destination_hash_and_tunnelid_t
#define mk_sl_fixed_vector_t_capacity 16
#include "mk_sl_fixed_vector_inl_filec.h"
#include "mk_sl_fixed_vector_inl_fileu.h"

#define mk_sl_fixed_vector_t_name mk_lib_iip_cp_remote_destination_leases
#define mk_sl_fixed_vector_t_element_type mk_lib_iip_cp_remote_destination_lease_t
#define mk_sl_fixed_vector_t_capacity 16
#include "mk_sl_fixed_vector_inl_filec.h"
#include "mk_sl_fixed_vector_inl_fileu.h"

#define mk_sl_vector_t_name mk_lib_iip_cp_remote_destination_leasez
#define mk_sl_vector_t_element_type mk_lib_iip_cp_remote_destination_lease_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_get_signature_len(mk_lib_iip_cp_remote_destination_sgn_key_type_t const key_type) mk_lang_noexcept
{
	mk_lang_types_sint_t res mk_lang_constexpr_init;

	switch(key_type)
	{
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_dsa_sha1              : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_dsa_sha1              ; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha256_p256     : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_ecdsa_sha256_p256     ; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha384_p384     : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_ecdsa_sha384_p384     ; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha512_p521     : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_ecdsa_sha512_p521     ; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha256_2048       : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_rsa_sha256_2048       ; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha384_3072       : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_rsa_sha384_3072       ; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha512_4096       : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_rsa_sha512_4096       ; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519  : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_eddsa_sha512_ed25519  ; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519ph: res = mk_lib_iip_cp_remote_destination_sgnature_len_e_eddsa_sha512_ed25519ph; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_gost_a                : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_gost_a                ; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_gost_b                : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_gost_b                ; break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_reddsa_sha512_ed25519 : res = mk_lib_iip_cp_remote_destination_sgnature_len_e_reddsa_sha512_ed25519 ; break;
		#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_lang_clobber(&res);
	return res;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_destination_with_cert_from_u8s(mk_lib_iip_cp_remote_destination_destination_with_cert_pt const destination, mk_sl_cui_uint8_pct const databuf, mk_lang_types_sint_t const datalen, mk_lang_types_sint_pt const outlen) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16 mk_lang_constexpr_init;
	mk_lang_types_sint_t lena mk_lang_constexpr_init;
	mk_lang_types_sint_t lenb mk_lang_constexpr_init;

	mk_lang_assert(destination);
	mk_lang_assert(databuf || datalen == 0);
	mk_lang_assert(datalen >= 0);
	mk_lang_assert(outlen || !outlen);

	mk_lang_check_return(datalen >= (256 + 128) + (1 + 2));
	mk_sl_cui_uint8_memcpy_fn(&destination->m_destination_buffer.m_crpt_pub_key[0], &databuf[0 * 256], 256);
	mk_sl_cui_uint8_memcpy_fn(&destination->m_destination_buffer.m_sgn_pub_key[0], &databuf[1 * 256], 128);
	mk_sl_cui_uint8_to_bi_sint(&databuf[(256 + 128) + (0)], &tsi);
	gud = mk_lang_false;
	switch(tsi)
	{
		case mk_lib_iip_cp_remote_destination_certificate_type_e_null    : gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_hashcash: gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_hidden  : gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_signed  : gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_multiple: gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_key     : gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_dummy_end: break;
		default: break;
	}
	mk_lang_check_return(gud);
	destination->m_certificate.m_type = ((mk_lib_iip_cp_remote_destination_certificate_type_t)(tsi));
	mk_sl_uint_convert_16_8_be_to_big(&tu16, &databuf[(256 + 128) + (1)]);
	mk_sl_cui_uint16_to_bi_sint(&tu16, &tsi);
	destination->m_certificate.m_len = tsi;
	mk_lang_check_return
	(
		((datalen == (256 + 128) + (1 + 2 + destination->m_certificate.m_len)) && (!outlen)) ||
		((datalen >= (256 + 128) + (1 + 2 + destination->m_certificate.m_len)) && (outlen))
	);
	if(destination->m_certificate.m_type == mk_lib_iip_cp_remote_destination_certificate_type_e_null)
	{
	}
	if(destination->m_certificate.m_type == mk_lib_iip_cp_remote_destination_certificate_type_e_key)
	{
		mk_lang_check_return(destination->m_certificate.m_len >= 4);
		mk_sl_uint_convert_16_8_be_to_big(&tu16, &databuf[(256 + 128) + (1 + 2 + 0 * 2)]);
		mk_sl_cui_uint16_to_bi_sint(&tu16, &tsi);
		gud = mk_lang_false;
		switch(tsi)
		{
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_dsa_sha1              : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha256_p256     : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha384_p384     : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha512_p521     : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha256_2048       : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha384_3072       : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha512_4096       : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519  : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519ph: gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_gost_a                : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_gost_b                : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_reddsa_sha512_ed25519 : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_dummy_end: break;
			default: break;
		}
		mk_lang_check_return(gud);
		destination->m_cert.m_data.m_keycert.m_sgn_type = ((mk_lib_iip_cp_remote_destination_sgn_key_type_t)(tsi));
		mk_sl_uint_convert_16_8_be_to_big(&tu16, &databuf[(256 + 128) + (1 + 2 + 1 * 2)]);
		mk_sl_cui_uint16_to_bi_sint(&tu16, &tsi);
		gud = mk_lang_false;
		switch(tsi)
		{
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_elgamal: gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_p256   : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_p384   : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_p521   : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_x25519 : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_dummy_end: break;
			default: break;
		}
		mk_lang_check_return(gud);
		destination->m_cert.m_data.m_keycert.m_enc_type = ((mk_lib_iip_cp_remote_destination_enc_key_type_t)(tsi));
		lena = mk_lib_iip_cp_remote_destination_get_key_additional_len_sgn(destination->m_cert.m_data.m_keycert.m_sgn_type);
		lenb = mk_lib_iip_cp_remote_destination_get_key_additional_len_enc(destination->m_cert.m_data.m_keycert.m_enc_type);
		mk_lang_check_return(destination->m_certificate.m_len == (2 + 2 + lena + lenb));
		mk_lang_check_return
		(
			((datalen == (256 + 128) + (1 + 2 + (2 + 2 + lena + lenb))) && (!outlen)) || 
			((datalen >= (256 + 128) + (1 + 2 + (2 + 2 + lena + lenb))) && (outlen))
		);
		mk_sl_cui_uint8_memcpy_fn(&destination->m_cert.m_data.m_keycert.m_sgn_pub_key[0], &databuf[(256 + 128) + (1 + 2 + (2 + 2 + 0 * lena))], ((mk_lang_types_usize_t)(lena)));
		mk_sl_cui_uint8_memcpy_fn(&destination->m_cert.m_data.m_keycert.m_crpt_pub_key[0], &databuf[(256 + 128) + (1 + 2 + (2 + 2 + 1 * lena))], ((mk_lang_types_usize_t)(lenb)));
		if(outlen)
		{
			*outlen = (256 + 128) + (1 + 2 + (2 + 2 + lena + lenb));
		}
	}
	else
	{
		mk_lang_check_todo(); /* todo other cert types */
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_destination_with_cert_from_buffer(mk_lib_iip_cp_remote_destination_destination_with_cert_pt const destination, mk_lib_iip_cp_remote_destination_buffer_pct const buffer) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct databuf mk_lang_constexpr_init;
	mk_lang_types_sint_t datalen mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(destination);
	mk_lang_assert(buffer);

	databuf = &buffer->m_buf[0];
	datalen = buffer->m_len;
	err = mk_lib_iip_cp_remote_destination_destination_with_cert_from_u8s(destination, databuf, datalen, mk_lang_null); mk_lang_check_rereturn(err);
	return 0;
}
#endif














mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_get_key_additional_len_sgn(mk_lib_iip_cp_remote_destination_sgn_key_type_t const key_type) mk_lang_noexcept
{
	mk_lang_types_sint_t res mk_lang_constexpr_init;

	switch(key_type)
	{
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_dsa_sha1              : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_dsa_sha1               - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha256_p256     : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_ecdsa_sha256_p256      - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha384_p384     : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_ecdsa_sha384_p384      - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha512_p521     : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_ecdsa_sha512_p521      - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha256_2048       : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_rsa_sha256_2048        - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha384_3072       : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_rsa_sha384_3072        - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha512_4096       : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_rsa_sha512_4096        - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519  : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_eddsa_sha512_ed25519   - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519ph: res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_eddsa_sha512_ed25519ph - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_gost_a                : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_gost_a                 - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_gost_b                : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_gost_b                 - 128); break;
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_reddsa_sha512_ed25519 : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_sgn_key_len_e_reddsa_sha512_ed25519  - 128); break;
		#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
		case mk_lib_iip_cp_remote_destination_sgn_key_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_lang_clobber(&res);
	return res;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_get_key_additional_len_enc(mk_lib_iip_cp_remote_destination_enc_key_type_t const key_type) mk_lang_noexcept
{
	mk_lang_types_sint_t res mk_lang_constexpr_init;

	switch(key_type)
	{
		case mk_lib_iip_cp_remote_destination_enc_key_type_e_elgamal: res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_enc_key_len_e_elgamal - 256); break;
		case mk_lib_iip_cp_remote_destination_enc_key_type_e_p256   : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_enc_key_len_e_p256    - 256); break;
		case mk_lib_iip_cp_remote_destination_enc_key_type_e_p384   : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_enc_key_len_e_p384    - 256); break;
		case mk_lib_iip_cp_remote_destination_enc_key_type_e_p521   : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_enc_key_len_e_p521    - 256); break;
		case mk_lib_iip_cp_remote_destination_enc_key_type_e_x25519 : res = mk_lang_max(0, mk_lib_iip_cp_remote_destination_enc_key_len_e_x25519  - 256); break;
		#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
		case mk_lib_iip_cp_remote_destination_enc_key_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
		#include "mk_lang_warning_clang_pop.h"
	}
	mk_lang_clobber(&res);
	return res;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_prrw_from_bytes(mk_lib_iip_cp_remote_destination_pt const remote_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct enc_data_buf mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct sgn_data_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t cert_type_num mk_lang_constexpr_init;
	mk_lib_iip_cp_remote_destination_certificate_type_t cert_type_id mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16 mk_lang_constexpr_init;
	mk_lang_types_sint_t cert_len mk_lang_constexpr_init;
	mk_lang_types_sint_t sgn_type_num mk_lang_constexpr_init;
	mk_lib_iip_cp_remote_destination_sgn_key_type_t sgn_type_id mk_lang_constexpr_init;
	mk_lang_types_sint_t enc_type_num mk_lang_constexpr_init;
	mk_lib_iip_cp_remote_destination_enc_key_type_t enc_type_id mk_lang_constexpr_init;
	mk_lang_types_sint_t sgn_additional_data_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct sgn_additional_data_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t enc_additional_data_len mk_lang_constexpr_init;
	mk_sl_cui_uint8_pct enc_additional_data_buf mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_assert(remote_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(succeeded);
	mk_lang_assert(*succeeded == mk_lang_true);
	mk_lang_assert(consumed);

	ptr = data_buf;
	rem = data_len;

	tlen = 256;
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	enc_data_buf = ptr;
	ptr += tlen;
	rem -= tlen;

	tlen = 128;
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	sgn_data_buf = ptr;
	ptr += tlen;
	rem -= tlen;

	tlen = mk_sl_cui_uint8_size_bytes_v;
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_to_bi_sint(ptr, &cert_type_num);
	ptr += tlen;
	rem -= tlen;

	switch(cert_type_num)
	{
		case mk_lib_iip_cp_remote_destination_certificate_type_e_null     : gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_hash_cash: gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_hidden   : gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_signed   : gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_multiple : gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_key      : gud = mk_lang_true; break;
		case mk_lib_iip_cp_remote_destination_certificate_type_e_dummy_end: gud = mk_lang_false; break;
		default: gud = mk_lang_false; break;
	}
	if(!gud)
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	cert_type_id = ((mk_lib_iip_cp_remote_destination_certificate_type_t)(cert_type_num));

	if
	(!(
		(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_null) ||
		(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_hidden) ||
		(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_signed) ||
		(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_key) ||
		(mk_lang_false)
	))
	{
		mk_lang_debug_break(); /* todo */
		*succeeded = mk_lang_false;
		return 0;
	}

	tlen = mk_sl_cui_uint16_size_bytes_v;
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	mk_sl_uint_convert_16_8_be_to_big(&tu16, ptr);
	mk_sl_cui_uint16_to_bi_sint(&tu16, &cert_len);
	ptr += tlen;
	rem -= tlen;

	if
	(!(
		(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_null && cert_len == 0) ||
		(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_hidden && cert_len == 0) ||
		(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_signed && (cert_len == 40 || cert_len == 40 + 32)) ||
		(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_key && cert_len >= 2 * mk_sl_cui_uint16_size_bytes_v) ||
		(mk_lang_false)
	))
	{
		*succeeded = mk_lang_false;
		return 0;
	}

	if(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_null)
	{
		remote_destination->m_certificate.m_cert_type = mk_lib_iip_cp_remote_destination_cert_type_e_null;
	}
	else if(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_hidden)
	{
		remote_destination->m_certificate.m_cert_type = mk_lib_iip_cp_remote_destination_cert_type_e_hidden;
	}
	else if(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_signed)
	{
		if(cert_len == 40)
		{
			remote_destination->m_certificate.m_cert_type = mk_lib_iip_cp_remote_destination_cert_type_e_signeda;
			mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_certificate.m_cert_data.m_data.m_signeda.m_dsa_signature[0], ptr, 40); ptr += 40; rem -= 40;
		}
		else if(cert_len == 40 + 32)
		{
			remote_destination->m_certificate.m_cert_type = mk_lib_iip_cp_remote_destination_cert_type_e_signedb;
			mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signeda.m_dsa_signature[0], ptr, 40); ptr += 40; rem -= 40;
			mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_certificate.m_cert_data.m_data.m_signedb.m_signing_destination_hash[0], ptr, 32); ptr += 32; rem -= 32;
		}
		else
		{
			mk_lang_assert_false();
		}
	}
	else if(cert_type_id == mk_lib_iip_cp_remote_destination_certificate_type_e_key)
	{
		remote_destination->m_certificate.m_cert_type = mk_lib_iip_cp_remote_destination_cert_type_e_key;
		tlen = mk_sl_cui_uint16_size_bytes_v;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		mk_sl_uint_convert_16_8_be_to_big(&tu16, ptr);
		mk_sl_cui_uint16_to_bi_sint(&tu16, &sgn_type_num);
		ptr += tlen;
		rem -= tlen;

		switch(sgn_type_num)
		{
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_dsa_sha1              : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha256_p256     : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha384_p384     : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha512_p521     : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha256_2048       : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha384_3072       : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha512_4096       : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519  : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519ph: gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_gost_a                : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_gost_b                : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_reddsa_sha512_ed25519 : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_dummy_end: gud = mk_lang_false; break;
			default: gud = mk_lang_false; break;
		}
		if(!gud)
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		sgn_type_id = ((mk_lib_iip_cp_remote_destination_sgn_key_type_t)(sgn_type_num));

		tlen = mk_sl_cui_uint16_size_bytes_v;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		mk_sl_uint_convert_16_8_be_to_big(&tu16, ptr);
		mk_sl_cui_uint16_to_bi_sint(&tu16, &enc_type_num);
		ptr += tlen;
		rem -= tlen;

		switch(enc_type_num)
		{
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_elgamal: gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_p256   : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_p384   : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_p521   : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_x25519 : gud = mk_lang_true; break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_dummy_end: gud = mk_lang_false; break;
			default: gud = mk_lang_false; break;
		}
		if(!gud)
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		enc_type_id = ((mk_lib_iip_cp_remote_destination_enc_key_type_t)(enc_type_num));

		sgn_additional_data_len = mk_lib_iip_cp_remote_destination_get_key_additional_len_sgn(sgn_type_id);
		tlen = sgn_additional_data_len;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		sgn_additional_data_buf = ptr;
		ptr += tlen;
		rem -= tlen;

		enc_additional_data_len = mk_lib_iip_cp_remote_destination_get_key_additional_len_enc(enc_type_id);
		tlen = enc_additional_data_len;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		enc_additional_data_buf = ptr;
		ptr += tlen;
		rem -= tlen;

		if(!(mk_sl_cui_uint16_size_bytes_v + mk_sl_cui_uint16_size_bytes_v + sgn_additional_data_len + enc_additional_data_len == cert_len))
		{
			*succeeded = mk_lang_false;
			return 0;
		}

		remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_type = enc_type_id;
		remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_type = sgn_type_id;
		mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_certificate.m_cert_data.m_data.m_key.m_sgn_pub_key[0], sgn_additional_data_buf, sgn_additional_data_len);
		mk_sl_cui_uint8_memcpy_fn(&remote_destination->m_certificate.m_cert_data.m_data.m_key.m_enc_pub_key[0], enc_additional_data_buf, enc_additional_data_len);
	}
	else
	{
		mk_lang_assert_false();
	}

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_prrw_to_bytes(mk_lib_iip_cp_remote_destination_pct const remote_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_assert(remote_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(succeeded);
	mk_lang_assert(*succeeded == mk_lang_true);
	mk_lang_assert(consumed);
#if 0
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt enc_data_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt sgn_data_buf mk_lang_constexpr_init;
	mk_lang_types_sint_t cert_type mk_lang_constexpr_init;
	mk_lang_types_sint_t cert_len mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16 mk_lang_constexpr_init;
	mk_lib_iip_cp_remote_destination_sgn_key_type_t sgn_type_id mk_lang_constexpr_init;
	mk_lang_types_sint_t sgn_type_num mk_lang_constexpr_init;
	mk_lib_iip_cp_remote_destination_enc_key_type_t enc_type_id mk_lang_constexpr_init;
	mk_lang_types_sint_t enc_type_num mk_lang_constexpr_init;
	/*mk_sl_cui_uint8_pt sgn_additional_data_buf mk_lang_constexpr_init;*/
	mk_lang_types_sint_t sgn_additional_data_len mk_lang_constexpr_init;
	/*mk_sl_cui_uint8_pt enc_additional_data_buf mk_lang_constexpr_init;*/
	mk_lang_types_sint_t enc_additional_data_len mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(remote_destination);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(succeeded);
	mk_lang_assert(*succeeded == mk_lang_true);
	mk_lang_assert(consumed);

	ptr = data_buf;
	rem = data_len;

	enc_data_buf = ptr;
	tlen = 256;
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	ptr += tlen;
	rem -= tlen;

	sgn_data_buf = ptr;
	tlen = 128;
	if(!(rem >= tlen))
	{
		*succeeded = mk_lang_false;
		return 0;
	}
	ptr += tlen;
	rem -= tlen;

	if(remote_destination->m_type != mk_lib_iip_cp_remote_destination_remote_destination_type_e_legacy)
	{

		cert_type = mk_lib_iip_cp_remote_destination_certificate_type_e_key;
		tlen = mk_sl_cui_uint8_size_bytes_v;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		mk_sl_cui_uint8_from_bi_sint(ptr, &cert_type);
		ptr += tlen;
		rem -= tlen;

		cert_len = 2 * mk_sl_cui_uint16_size_bytes_v;
		tlen = mk_sl_cui_uint16_size_bytes_v;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		mk_sl_cui_uint16_from_bi_sint(&tu16, &cert_len);
		mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
		ptr += tlen;
		rem -= tlen;

		switch(remote_destination->m_type)
		{
			case mk_lib_iip_cp_remote_destination_remote_destination_type_e_legacy: mk_lang_assert_false(); break;
			case mk_lib_iip_cp_remote_destination_remote_destination_type_e_elgamal_dsa_sha1            : sgn_type_id = mk_lib_iip_cp_remote_destination_sgn_key_type_e_dsa_sha1            ; break;
			case mk_lib_iip_cp_remote_destination_remote_destination_type_e_elgamal_ecdsa_sha256_p256   : sgn_type_id = mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha256_p256   ; break;
			case mk_lib_iip_cp_remote_destination_remote_destination_type_e_elgamal_eddsa_sha512_ed25519: sgn_type_id = mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519; break;
			case mk_lib_iip_cp_remote_destination_remote_destination_type_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}
		mk_lang_clobber(&sgn_type_id);
		sgn_type_num = sgn_type_id;
		tlen = mk_sl_cui_uint16_size_bytes_v;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		mk_sl_cui_uint16_from_bi_sint(&tu16, &sgn_type_num);
		mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
		ptr += tlen;
		rem -= tlen;

		switch(remote_destination->m_type)
		{
			case mk_lib_iip_cp_remote_destination_remote_destination_type_e_legacy: mk_lang_assert_false(); break;
			case mk_lib_iip_cp_remote_destination_remote_destination_type_e_elgamal_dsa_sha1            : enc_type_id = mk_lib_iip_cp_remote_destination_enc_key_type_e_elgamal; break;
			case mk_lib_iip_cp_remote_destination_remote_destination_type_e_elgamal_ecdsa_sha256_p256   : enc_type_id = mk_lib_iip_cp_remote_destination_enc_key_type_e_elgamal; break;
			case mk_lib_iip_cp_remote_destination_remote_destination_type_e_elgamal_eddsa_sha512_ed25519: enc_type_id = mk_lib_iip_cp_remote_destination_enc_key_type_e_elgamal; break;
			case mk_lib_iip_cp_remote_destination_remote_destination_type_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}
		mk_lang_clobber(&enc_type_id);
		enc_type_num = enc_type_id;
		tlen = mk_sl_cui_uint16_size_bytes_v;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		mk_sl_cui_uint16_from_bi_sint(&tu16, &enc_type_num);
		mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
		ptr += tlen;
		rem -= tlen;

		/*sgn_additional_data_buf = ptr;*/
		sgn_additional_data_len = mk_lib_iip_cp_remote_destination_get_key_additional_len_sgn(sgn_type_id);
		tlen = sgn_additional_data_len;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		ptr += tlen;
		rem -= tlen;

		/*enc_additional_data_buf = ptr;*/
		enc_additional_data_len = mk_lib_iip_cp_remote_destination_get_key_additional_len_enc(enc_type_id);
		tlen = enc_additional_data_len;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		ptr += tlen;
		rem -= tlen;

		switch(enc_type_id)
		{
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_elgamal: mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be(&remote_destination->m_data.m_elgamal_ecdsa_sha256_p256.m_enc_pub.m_data.m_integer, enc_data_buf); break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_p256   : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_p384   : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_p521   : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_x25519 : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_enc_key_type_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}

		switch(sgn_type_id)
		{
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_dsa_sha1              : err = mk_lib_iip_key_sgn_dsa_sha1_pub_rw_export_to_u8s(&remote_destination->m_data.m_elgamal_dsa_sha1.m_sgn_pub, sgn_data_buf); mk_lang_check_rereturn(err); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha256_p256     : mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_to_u8s_be(&remote_destination->m_data.m_elgamal_ecdsa_sha256_p256.m_sgn_pub.m_data.m_integer, sgn_data_buf); mk_sl_cui_uint8_memcpy_fn(sgn_data_buf + 128 - mk_lang_countof(remote_destination->m_data.m_elgamal_ecdsa_sha256_p256.m_padding_2), &remote_destination->m_data.m_elgamal_ecdsa_sha256_p256.m_padding_2[0], ((mk_lang_types_usize_t)(mk_lang_countof(remote_destination->m_data.m_elgamal_ecdsa_sha256_p256.m_padding_2)))); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha384_p384     : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_ecdsa_sha512_p521     : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha256_2048       : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha384_3072       : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_rsa_sha512_4096       : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519  : mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_integer_single_to_u8s_be(&remote_destination->m_data.m_elgamal_eddsa_sha512_ed25519.m_sgn_pub.m_data.m_integer, sgn_data_buf); mk_sl_cui_uint8_memcpy_fn(sgn_data_buf + 128 - mk_lang_countof(remote_destination->m_data.m_elgamal_eddsa_sha512_ed25519.m_padding_2), &remote_destination->m_data.m_elgamal_eddsa_sha512_ed25519.m_padding_2[0], ((mk_lang_types_usize_t)(mk_lang_countof(remote_destination->m_data.m_elgamal_eddsa_sha512_ed25519.m_padding_2)))); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_eddsa_sha512_ed25519ph: mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_gost_a                : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_gost_b                : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_reddsa_sha512_ed25519 : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_remote_destination_sgn_key_type_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}

	}
	else
	{

		cert_type = mk_lib_iip_cp_remote_destination_certificate_type_e_null;
		tlen = mk_sl_cui_uint8_size_bytes_v;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		mk_sl_cui_uint8_from_bi_sint(ptr, &cert_type);
		ptr += tlen;
		rem -= tlen;

		cert_len = 0;
		tlen = mk_sl_cui_uint16_size_bytes_v;
		if(!(rem >= tlen))
		{
			*succeeded = mk_lang_false;
			return 0;
		}
		mk_sl_cui_uint16_from_bi_sint(&tu16, &cert_len);
		mk_sl_uint_convert_16_8_be_to_sml(&tu16, ptr);
		ptr += tlen;
		rem -= tlen;

		mk_lib_iip_key_enc_elgamal_pub_integer_single_to_u8s_be(&remote_destination->m_data.m_legacy.m_enc_pub.m_data.m_integer, enc_data_buf);
		err = mk_lib_iip_key_sgn_dsa_sha1_pub_rw_export_to_u8s(&remote_destination->m_data.m_legacy.m_sgn_pub, sgn_data_buf); mk_lang_check_rereturn(err);

	}

	tlen = data_len - rem;
	*consumed = tlen;
#endif
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_rw_from_bytes(mk_lib_iip_cp_remote_destination_pt const remote_destination, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_cp_remote_destination_prrw_from_bytes(remote_destination, data_buf, data_len, succeeded, consumed);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_remote_destination_rw_to_bytes(mk_lib_iip_cp_remote_destination_pct const remote_destination, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const succeeded, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	return mk_lib_iip_cp_remote_destination_prrw_to_bytes(remote_destination, data_buf, data_len, succeeded, consumed);
}


#endif
