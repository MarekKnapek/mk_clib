#ifndef mk_include_guard_mk_lib_iip_net_streaming_packet_c
#define mk_include_guard_mk_lib_iip_net_streaming_packet_c
#include "mk_lib_iip_net_streaming_packet.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_crypto_hash_stream_sha2_256.h"
#include "mk_lib_iip_base32_encoder.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"
#include "mk_sl_uint_more.h"


#define mk_sl_fixed_vector_t_name mk_lib_iip_net_streaming_packet_nacks
#define mk_sl_fixed_vector_t_element_type mk_sl_cui_uint32_t
#define mk_sl_fixed_vector_t_capacity 0xff
#include "mk_sl_fixed_vector_inl_filec.h"
#include "mk_sl_fixed_vector_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_u16(mk_sl_cui_uint16_pt const obj, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	tlen = mk_sl_cui_uint16_size_bytes_v;
	if((!(rem >= tlen)))
	{
		*success = mk_lang_false;
		return 0;
	}
	mk_sl_uint_convert_16_8_be_to_big(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_u32(mk_sl_cui_uint32_pt const obj, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	tlen = mk_sl_cui_uint32_size_bytes_v;
	if((!(rem >= tlen)))
	{
		*success = mk_lang_false;
		return 0;
	}
	mk_sl_uint_convert_32_8_be_to_big(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_s8(mk_lang_types_sint_pt const obj, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	tlen = mk_sl_cui_uint8_size_bytes_v;
	if((!(rem >= tlen)))
	{
		*success = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_to_bi_sint(&ptr[0], obj);
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_s16(mk_lang_types_sint_pt const obj, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint16_t u16;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_u16(&u16, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_sl_cui_uint16_to_bi_sint(&u16, obj);
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_nacks_2(mk_lib_iip_net_streaming_packet_nacks_pt const obj, mk_lang_types_sint_t const count, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint32_t u32;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(count >= 0x00);
	mk_lang_assert(count <= 0xff);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_lib_iip_net_streaming_packet_prrw_parse_u32(&u32, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
		err = mk_lib_iip_net_streaming_packet_nacks_rw_push_back_copy_single(obj, &u32); mk_lang_check_rereturn(err);
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_nacks(mk_lib_iip_net_streaming_packet_nacks_pt const obj, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t count;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_nacks_rw_clear(obj); mk_lang_check_rereturn(err);
	err = mk_lib_iip_net_streaming_packet_prrw_parse_s8     (&count    , ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_nacks_2(obj, count, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_flags(mk_lib_iip_net_streaming_packet_flag_pt const obj, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint16_t u16;
	mk_lang_types_sint_t tlen;
	mk_lang_types_ushort_t tus;

	mk_lang_assert(obj);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_u16(&u16, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_sl_cui_uint16_to_bi_ushort(&u16, &tus);
	*obj = ((mk_lib_iip_net_streaming_packet_flag_t)(tus));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_destination(mk_lib_iip_cp_types_remote_destination_pt const obj, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t tlen;
	mk_lib_iip_cp_types_destination_buffer_t dst_buf;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t cert_type;
	mk_lang_types_sint_t key_cert_len;
	mk_lang_types_sint_t sgn_key_type;
	mk_lang_types_sint_t enc_key_type;

	mk_lang_static_assert((mk_lang_countof(dst_buf.m_crpt_pub_key) + mk_lang_countof(dst_buf.m_sign_pub_key)) + (((mk_lang_types_sint_t)(mk_sl_cui_uint8_size_bytes_v)) + ((mk_lang_types_sint_t)(mk_sl_cui_uint16_size_bytes_v))) == 387);

	mk_lang_assert(obj);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	tlen = 387;
	if((!(rem >= tlen)))
	{
		*success = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_memcpy_fn(&dst_buf.m_crpt_pub_key[0], &ptr[0], mk_lang_countof(dst_buf.m_crpt_pub_key)); ptr += mk_lang_countof(dst_buf.m_crpt_pub_key); rem -= mk_lang_countof(dst_buf.m_crpt_pub_key);
	mk_sl_cui_uint8_memcpy_fn(&dst_buf.m_sign_pub_key[0], &ptr[0], mk_lang_countof(dst_buf.m_sign_pub_key)); ptr += mk_lang_countof(dst_buf.m_sign_pub_key); rem -= mk_lang_countof(dst_buf.m_sign_pub_key);
	err = mk_lib_iip_net_streaming_packet_prrw_parse_s8(&cert_type, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	switch(cert_type)
	{
		case mk_lib_iip_cp_types_certificate_type_e_null    : mk_lang_check_todo();  break;
		case mk_lib_iip_cp_types_certificate_type_e_hashcash: mk_lang_check_todo();  break;
		case mk_lib_iip_cp_types_certificate_type_e_hidden  : mk_lang_check_todo();  break;
		case mk_lib_iip_cp_types_certificate_type_e_signed  : mk_lang_check_todo();  break;
		case mk_lib_iip_cp_types_certificate_type_e_multiple: mk_lang_check_todo();  break;
		case mk_lib_iip_cp_types_certificate_type_e_key     : /* this is intentionally left blank */ break;
		case mk_lib_iip_cp_types_certificate_type_e_dummy_end: mk_lang_assert_false();  break;
		default: mk_lang_assert_false();  break;
	}
	err = mk_lib_iip_net_streaming_packet_prrw_parse_s16(&key_cert_len, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_lang_check_return(key_cert_len == 4);
	err = mk_lib_iip_net_streaming_packet_prrw_parse_s16(&sgn_key_type, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_s16(&enc_key_type, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	if(enc_key_type == mk_lib_iip_cp_types_crpt_key_type_e_elgamal && sgn_key_type == mk_lib_iip_cp_types_sign_key_type_e_eddsa_sha512_ed25519)
	{
		obj->m_type = mk_lib_iip_cp_types_remote_destination_type_e_elgamal_eddsa_sha512_ed25519;
		mk_lib_iip_key_enc_elgamal_pub_integer_single_from_u8s_be(&obj->m_data.m_elgamal_eddsa_sha512_ed25519.m_enc_pub.m_data.m_integer, &dst_buf.m_crpt_pub_key[0]);
		mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_integer_single_from_u8s_be(&obj->m_data.m_elgamal_eddsa_sha512_ed25519.m_sgn_pub.m_data.m_integer, &dst_buf.m_sign_pub_key[0]);
	}
	else
	{
		mk_lang_check_todo();
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_options_delay(mk_lib_iip_net_streaming_packet_options_pt const obj, mk_lib_iip_net_streaming_packet_flag_t const flags, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(flags || !flags);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	if((flags & mk_lib_iip_net_streaming_packet_flag_e_delay_requested) != 0)
	{
		err = mk_lib_iip_net_streaming_packet_prrw_parse_s16(&obj->m_delay, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}
	else
	{
		obj->m_delay = -1;
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_options_from_b32(mk_lib_iip_net_streaming_packet_b32_pt const obj, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_lib_crypto_hash_stream_sha2_256_t hasher;
	mk_lib_crypto_hash_stream_sha2_256_digest_t digest;
	mk_lang_types_sint_t len;

	mk_lang_assert(obj);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	mk_lib_crypto_hash_stream_sha2_256_init(&hasher);
	mk_lib_crypto_hash_stream_sha2_256_append_u8s(&hasher, data_buf, ((mk_lang_types_usize_t)(data_len)));
	mk_lib_crypto_hash_stream_sha2_256_finish(&hasher, &digest);
	mk_lib_iip_base32_encoder_fn(&digest.m_data.m_uint8s[0], mk_lang_countof(digest.m_data.m_uint8s), &obj->m_pchars[0], mk_lang_countof(obj->m_pchars), &len); mk_lang_assert(len == 52);
	#if mk_lib_iip_net_streaming_packet_b32_has_extra_zero
	obj->m_pchars[52] = '\0';
	#endif
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_options_from(mk_lib_iip_net_streaming_packet_options_pt const obj, mk_lib_iip_net_streaming_packet_flag_t const flags, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(flags || !flags);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	if((flags & mk_lib_iip_net_streaming_packet_flag_e_from_included) != 0)
	{
		if
		(!(
			((flags & mk_lib_iip_net_streaming_packet_flag_e_synchronize) != 0) ||
			((flags & mk_lib_iip_net_streaming_packet_flag_e_echo) != 0) ||
			((flags & mk_lib_iip_net_streaming_packet_flag_e_reset) != 0) ||
			mk_lang_false
		))
		{
			*success = mk_lang_false;
			return 0;
		}
		err = mk_lib_iip_net_streaming_packet_prrw_parse_destination(&obj->m_from, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
		err = mk_lib_iip_net_streaming_packet_prrw_parse_options_from_b32(&obj->m_b32, ptr - tlen, tlen); mk_lang_check_rereturn(err);
	}
	else
	{
		obj->m_from.m_type = mk_lib_iip_cp_types_remote_destination_type_e_dummy_end;
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_options_max_packet_size(mk_lib_iip_net_streaming_packet_options_pt const obj, mk_lib_iip_net_streaming_packet_flag_t const flags, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(flags || !flags);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	if((flags & mk_lib_iip_net_streaming_packet_flag_e_max_packet_size_included) != 0)
	{
		if
		(!(
			((flags & mk_lib_iip_net_streaming_packet_flag_e_synchronize) != 0) ||
			mk_lang_false
		))
		{
			*success = mk_lang_false;
			return 0;
		}
		err = mk_lib_iip_net_streaming_packet_prrw_parse_s16(&obj->m_max_packet_size, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}
	else
	{
		obj->m_max_packet_size = -1;
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_options_offline_signature(mk_lib_iip_net_streaming_packet_options_pt const obj, mk_lib_iip_net_streaming_packet_flag_t const flags, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(flags || !flags);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	if((flags & mk_lib_iip_net_streaming_packet_flag_e_offline_signature) != 0)
	{
		if
		(!(
			((flags & mk_lib_iip_net_streaming_packet_flag_e_from_included) != 0) ||
			mk_lang_false
		))
		{
			*success = mk_lang_false;
			return 0;
		}
		((mk_lang_types_void_t)(ptr));
		((mk_lang_types_void_t)(rem));
		((mk_lang_types_void_t)(gud));
		((mk_lang_types_void_t)(tlen));
		mk_lang_check_todo();
	}
	else
	{
		obj->m_offline_signature = -1;
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_options_signature(mk_lib_iip_net_streaming_packet_options_pt const obj, mk_lib_iip_net_streaming_packet_flag_t const flags, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;
	mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_t signature;

	mk_lang_assert(obj);
	mk_lang_assert(flags || !flags);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	if((flags & mk_lib_iip_net_streaming_packet_flag_e_signature_included) != 0)
	{
		if
		(!(
			((flags & mk_lib_iip_net_streaming_packet_flag_e_synchronize) != 0) ||
			((flags & mk_lib_iip_net_streaming_packet_flag_e_close) != 0) ||
			((flags & mk_lib_iip_net_streaming_packet_flag_e_reset) != 0) ||
			((flags & mk_lib_iip_net_streaming_packet_flag_e_echo) != 0) ||
			mk_lang_false
		))
		{
			*success = mk_lang_false;
			return 0;
		}
		tlen = mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_len_v;
		if(!(rem >= tlen))
		{
			*success = mk_lang_false;
			return 0;
		}
		mk_sl_cui_uint8_to_bi_uchar_many(&ptr[0], &signature.m_ucs[0], mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_len_v);
		ptr += mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_len_v;
		rem -= mk_lib_iip_key_sgn_eddsa_sha512_ed25519_pub_signature_len_v;
		/* todo validate signature */
	}
	else
	{
		obj->m_offline_signature = -1;
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_options_len(mk_lib_iip_net_streaming_packet_options_pt const obj, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint16_t u16;
	mk_lang_types_sint_t tlen;
	mk_lang_types_ushort_t tus;

	mk_lang_assert(obj);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_u16(&u16, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_sl_cui_uint16_to_bi_ushort(&u16, &tus);
	#include "mk_lang_warning_clang_push_cast_qual.h"
	obj->m_len = ((mk_lang_types_sint_t)(tus));
	obj->m_buf = ((mk_sl_cui_uint8_pt)(ptr));
	#include "mk_lang_warning_clang_pop.h"
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_options_2(mk_lib_iip_net_streaming_packet_options_pt const obj, mk_lib_iip_net_streaming_packet_flag_t const flags, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(flags || !flags);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	mk_lang_assert(obj->m_len <= rem);
	rem = obj->m_len;
	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_options_delay            (obj, flags, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_options_from             (obj, flags, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_options_max_packet_size  (obj, flags, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_options_offline_signature(obj, flags, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_options_signature        (obj, flags, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_lang_check_return(rem == 0);
	tlen = obj->m_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_options(mk_lib_iip_net_streaming_packet_options_pt const obj, mk_lib_iip_net_streaming_packet_flag_t const flags, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(obj);
	mk_lang_assert(flags || !flags);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_options_len(obj,        ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_options_2  (obj, flags, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_prrw_parse_payload(mk_sl_cui_uint8_ppt const payload_buf, mk_lang_types_sint_pt const payload_len, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(payload_buf);
	mk_lang_assert(payload_len);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	#include "mk_lang_warning_clang_push_cast_qual.h"
	*payload_buf = ((mk_sl_cui_uint8_pt)(ptr));
	*payload_len = rem;
	#include "mk_lang_warning_clang_pop.h"
	ptr += rem;
	rem -= rem;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_rw_construct(mk_lib_iip_net_streaming_packet_pt const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(packet);

	err = mk_lib_iip_net_streaming_packet_nacks_rw_construct_void(&packet->m_nacks); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_net_streaming_packet_rw_parse(mk_lib_iip_net_streaming_packet_pt const packet, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_bool_pt const success) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(packet);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(*success == mk_lang_true);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_u32    (&packet->m_send_stream_id                     , ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_u32    (&packet->m_recv_stream_id                     , ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_u32    (&packet->m_sequence_number                    , ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_u32    (&packet->m_ack_through                        , ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_nacks  (&packet->m_nacks                              , ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_s8     (&packet->m_resend_delay                       , ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_flags  (&packet->m_flags                              , ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_options(&packet->m_options, packet->m_flags           , ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_net_streaming_packet_prrw_parse_payload(&packet->m_payload_buf, &packet->m_payload_len, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *success = mk_lang_false; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_lang_check_return(rem == 0);
	return 0;
}


#endif
