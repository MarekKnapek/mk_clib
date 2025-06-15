#ifndef mk_include_guard_mk_iip_cp_message_serialize_c
#define mk_include_guard_mk_iip_cp_message_serialize_c
#include "mk_iip_cp_message_serialize.h"

#include "mk_iip_cp_base.h"
#include "mk_iip_cp_helper.h"
#include "mk_iip_cp_message.h"
#include "mk_iip_cp_type.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_types.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


#define mk_iip_cp_message_serialize_destination_blob_enc_pub_max 256
#define mk_iip_cp_message_serialize_destination_blob_sgn_pub_max 128
#define mk_iip_cp_message_serialize_destination_blob_capacity ((mk_iip_cp_message_serialize_destination_blob_enc_pub_max) + (mk_iip_cp_message_serialize_destination_blob_sgn_pub_max))
#define mk_iip_cp_message_serialize_destination_blob_padding_len_max ((mk_iip_cp_message_serialize_destination_blob_capacity) - ((mk_iip_cp_message_serialize_destination_blob_enc_pub_max) + (mk_iip_cp_message_serialize_destination_blob_sgn_pub_max)))


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_s8(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);
	mk_lang_assert(*obj >= 0x00);
	mk_lang_assert(*obj <= 0xff);

	ptr = buf;
	rem = len;

	tlen = mk_sl_cui_uint8_sizebytes_v;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_serialize_errcode_e_not_enough_space;
		return 0;
	}
	mk_sl_cui_uint8_from_bi_sint(&ptr[0], obj);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_u8(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint8_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	tlen = mk_sl_cui_uint8_sizebytes_v;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_serialize_errcode_e_not_enough_space;
		return 0;
	}
	ptr[0] = *obj;
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_u16(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint16_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	tlen = mk_sl_cui_uint16_sizebytes_v;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_serialize_errcode_e_not_enough_space;
		return 0;
	}
	mk_sl_uint_16_to_8_be(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_u32(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint32_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	tlen = mk_sl_cui_uint32_sizebytes_v;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_serialize_errcode_e_not_enough_space;
		return 0;
	}
	mk_sl_uint_32_to_8_be(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_u64(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint64_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	tlen = mk_sl_cui_uint64_sizebytes_v;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_serialize_errcode_e_not_enough_space;
		return 0;
	}
	mk_sl_uint_64_to_8_be(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_s16(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);
	mk_lang_assert(*obj >= 0);
	mk_lang_assert(*obj <= 128 * 1024);

	ptr = buf;
	rem = len;

	mk_sl_cui_uint16_from_bi_sint(&tu16, obj);
	err = mk_iip_cp_message_serialize_u16(ptr, rem, errcode, &tlen, &tu16); mk_lang_check_rereturn(err);
	if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok)
	{
		return 0;
	}
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_s32(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);
	mk_lang_assert(*obj >= 0);
	mk_lang_assert(*obj <= 128 * 1024);

	ptr = buf;
	rem = len;

	mk_sl_cui_uint32_from_bi_sint(&tu32, obj);
	err = mk_iip_cp_message_serialize_u32(ptr, rem, errcode, &tlen, &tu32); mk_lang_check_rereturn(err);
	if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok)
	{
		return 0;
	}
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_s32b(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);
	mk_lang_assert(*obj >= 0);

	ptr = buf;
	rem = len;

	mk_sl_cui_uint32_from_bi_sint(&tu32, obj);
	err = mk_iip_cp_message_serialize_u32(ptr, rem, errcode, &tlen, &tu32); mk_lang_check_rereturn(err);
	if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok)
	{
		return 0;
	}
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_pc(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_lang_types_pchar_t const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint8_t tu8;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);

	ptr = buf;
	rem = len;

	mk_sl_cui_uint8_from_bi_pchar(&tu8, &obj);
	err = mk_iip_cp_message_serialize_u8(ptr, rem, errcode, &tlen, &tu8); mk_lang_check_rereturn(err);
	if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok)
	{
		return 0;
	}
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_u8s(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint8_pct const objs, mk_lang_types_sint_t const objlen) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(objs || objlen == 0);
	mk_lang_assert(objlen >= 0 && objlen <= 128 * 1024);

	ptr = buf;
	rem = len;

	tlen = objlen;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_serialize_errcode_e_not_enough_space;
		return 0;
	}
	mk_iip_cp_helper_memcpy_u8_fn(&ptr[0], objs, tlen);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_uchars(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_lang_types_uchar_pct const objs, mk_lang_types_sint_t const objlen) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(objs || objlen == 0);
	mk_lang_assert(objlen >= 0 && objlen <= 128 * 1024);

	ptr = buf;
	rem = len;

	tlen = objlen;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_serialize_errcode_e_not_enough_space;
		return 0;
	}
	mk_iip_cp_helper_uchars_to_u8s(&objs[0], &ptr[0], tlen);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_message_type(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_message_type_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	switch(*obj)
	{
		case mk_iip_cp_message_message_type_e_create_session            : break;
		case mk_iip_cp_message_message_type_e_reconfigure_session       : break;
		case mk_iip_cp_message_message_type_e_destroy_session           : break;
		case mk_iip_cp_message_message_type_e_create_lease_set          : break;
		case mk_iip_cp_message_message_type_e_send_message              : break;
		case mk_iip_cp_message_message_type_e_receive_message_begin     : break;
		case mk_iip_cp_message_message_type_e_receive_message_end       : break;
		case mk_iip_cp_message_message_type_e_get_bandwidth_limits      : break;
		case mk_iip_cp_message_message_type_e_session_status            : break;
		case mk_iip_cp_message_message_type_e_request_lease_set         : break;
		case mk_iip_cp_message_message_type_e_message_status            : break;
		case mk_iip_cp_message_message_type_e_bandwidth_limits          : break;
		case mk_iip_cp_message_message_type_e_report_abuse              : break;
		case mk_iip_cp_message_message_type_e_disconnect                : break;
		case mk_iip_cp_message_message_type_e_message_payload           : break;
		case mk_iip_cp_message_message_type_e_get_date                  : break;
		case mk_iip_cp_message_message_type_e_set_date                  : break;
		case mk_iip_cp_message_message_type_e_dest_lookup               : break;
		case mk_iip_cp_message_message_type_e_dest_reply                : break;
		case mk_iip_cp_message_message_type_e_send_message_expires      : break;
		case mk_iip_cp_message_message_type_e_request_variable_lease_set: break;
		case mk_iip_cp_message_message_type_e_host_lookup               : break;
		case mk_iip_cp_message_message_type_e_host_reply                : break;
		case mk_iip_cp_message_message_type_e_create_lease_set2         : break;
		case mk_iip_cp_message_message_type_e_blinding_info             : break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	tsi = ((mk_lang_types_sint_t)(*obj));
	err = mk_iip_cp_message_serialize_s8(ptr, rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_certificate_type(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_certificate_type_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	switch(*obj)
	{
		case mk_iip_cp_message_certificate_type_e_null: break;
		case mk_iip_cp_message_certificate_type_e_hashcash: break;
		case mk_iip_cp_message_certificate_type_e_hidden: break;
		case mk_iip_cp_message_certificate_type_e_signed: break;
		case mk_iip_cp_message_certificate_type_e_multiple: break;
		case mk_iip_cp_message_certificate_type_e_key: break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	tsi = ((mk_lang_types_sint_t)(*obj)); err = mk_iip_cp_message_serialize_s8(ptr, rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_host_lookup_request_type(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_host_lookup_request_type_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	switch(*obj)
	{
		case mk_iip_cp_message_host_lookup_request_type_e_hash: break;
		case mk_iip_cp_message_host_lookup_request_type_e_name: break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	tsi = ((mk_lang_types_sint_t)(*obj));
	err = mk_iip_cp_message_serialize_s8(ptr, rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_elgamal_key_private(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_base_elgamal_key_pri_pct const obj) mk_lang_noexcept
{
	union mk_iip_cp_message_serialize_elgamal_key_private_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_elgamal_single_sizebytes_v];
		mk_iip_cp_helper_cui_elgamal_single_t m_elgamal_key_private;
	};
	typedef union mk_iip_cp_message_serialize_elgamal_key_private_data_u mk_iip_cp_message_serialize_elgamal_key_private_data_t;
	struct mk_iip_cp_message_serialize_elgamal_key_private_s
	{
		mk_iip_cp_message_serialize_elgamal_key_private_data_t m_data;
	};
	typedef struct mk_iip_cp_message_serialize_elgamal_key_private_s mk_iip_cp_message_serialize_elgamal_key_private_t;

	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_iip_cp_message_serialize_elgamal_key_private_t storage;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_iip_cp_helper_cui_elgamal_single_to_buis_uchar_be(&obj->m_data.m_val, &storage.m_data.m_uchars[0]);
	err = mk_iip_cp_message_serialize_uchars(ptr, rem, errcode, &tlen, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_elgamal_key_public(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_base_elgamal_key_pub_pct const obj) mk_lang_noexcept
{
	union mk_iip_cp_message_serialize_elgamal_key_public_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_elgamal_single_sizebytes_v];
		mk_iip_cp_helper_cui_elgamal_single_t m_elgamal_key_public;
	};
	typedef union mk_iip_cp_message_serialize_elgamal_key_public_data_u mk_iip_cp_message_serialize_elgamal_key_public_data_t;
	struct mk_iip_cp_message_serialize_elgamal_key_public_s
	{
		mk_iip_cp_message_serialize_elgamal_key_public_data_t m_data;
	};
	typedef struct mk_iip_cp_message_serialize_elgamal_key_public_s mk_iip_cp_message_serialize_elgamal_key_public_t;

	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_iip_cp_message_serialize_elgamal_key_public_t storage;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_iip_cp_helper_cui_elgamal_single_to_buis_uchar_be(&obj->m_data.m_val, &storage.m_data.m_uchars[0]);
	err = mk_iip_cp_message_serialize_uchars(ptr, rem, errcode, &tlen, &storage.m_data.m_uchars[0], mk_lang_min(mk_iip_cp_message_serialize_destination_blob_enc_pub_max, mk_lang_countof(storage.m_data.m_uchars))); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_dsa_key_private(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_base_dsa_key_pri_pct const obj) mk_lang_noexcept
{
	union mk_iip_cp_message_serialize_dsa_key_private_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pri_single_t m_dsa_key_private;
	};
	typedef union mk_iip_cp_message_serialize_dsa_key_private_data_u mk_iip_cp_message_serialize_dsa_key_private_data_t;
	struct mk_iip_cp_message_serialize_dsa_key_private_s
	{
		mk_iip_cp_message_serialize_dsa_key_private_data_t m_data;
	};
	typedef struct mk_iip_cp_message_serialize_dsa_key_private_s mk_iip_cp_message_serialize_dsa_key_private_t;

	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_iip_cp_message_serialize_dsa_key_private_t storage;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_iip_cp_helper_cui_dsa_pri_single_to_buis_uchar_be(&obj->m_data.m_val, &storage.m_data.m_uchars[0]);
	err = mk_iip_cp_message_serialize_uchars(ptr, rem, errcode, &tlen, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_dsa_key_public(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_base_dsa_key_pub_pct const obj) mk_lang_noexcept
{
	union mk_iip_cp_message_serialize_dsa_key_public_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pub_single_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pub_single_t m_dsa_key_public;
	};
	typedef union mk_iip_cp_message_serialize_dsa_key_public_data_u mk_iip_cp_message_serialize_dsa_key_public_data_t;
	struct mk_iip_cp_message_serialize_dsa_key_public_s
	{
		mk_iip_cp_message_serialize_dsa_key_public_data_t m_data;
	};
	typedef struct mk_iip_cp_message_serialize_dsa_key_public_s mk_iip_cp_message_serialize_dsa_key_public_t;

	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_iip_cp_message_serialize_dsa_key_public_t storage;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_iip_cp_helper_cui_dsa_pub_single_to_buis_uchar_be(&obj->m_data.m_val, &storage.m_data.m_uchars[0]);
	err = mk_iip_cp_message_serialize_uchars(ptr, rem, errcode, &tlen, &storage.m_data.m_uchars[0], mk_lang_min(mk_iip_cp_message_serialize_destination_blob_sgn_pub_max, mk_lang_countof(storage.m_data.m_uchars))); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_dsa_signature(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_base_dsa_signature_pct const obj) mk_lang_noexcept
{
	union mk_iip_cp_message_serialize_dsa_signature_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_base_dsa_signature_len_v];
		mk_iip_cp_base_dsa_signature_t m_dsa_signature;
	};
	typedef union mk_iip_cp_message_serialize_dsa_signature_data_u mk_iip_cp_message_serialize_dsa_signature_data_t;
	struct mk_iip_cp_message_serialize_dsa_signature_s
	{
		mk_iip_cp_message_serialize_dsa_signature_data_t m_data;
	};
	typedef struct mk_iip_cp_message_serialize_dsa_signature_s mk_iip_cp_message_serialize_dsa_signature_t;

	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_iip_cp_message_serialize_dsa_signature_t storage;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_iip_cp_helper_cui_dsa_pri_single_to_buis_uchar_be(&obj->m_data.m_rs.m_r, &storage.m_data.m_uchars[0 * mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v]);
	mk_iip_cp_helper_cui_dsa_pri_single_to_buis_uchar_be(&obj->m_data.m_rs.m_s, &storage.m_data.m_uchars[1 * mk_iip_cp_helper_cui_dsa_pri_single_sizebytes_v]);

	err = mk_iip_cp_message_serialize_uchars(ptr, rem, errcode, &tlen, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_certificate_empty(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_iip_cp_message_certificate_type_t ct;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);

	ptr = buf;
	rem = len;

	ct = mk_iip_cp_message_certificate_type_e_null; err = mk_iip_cp_message_serialize_certificate_type(ptr, rem, errcode, &tlen, &ct); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	tsi = 0; err = mk_iip_cp_message_serialize_s16(ptr, rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_sessionid(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_sessionid_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_u16(ptr, rem, errcode, &tlen, &obj->m_id); mk_lang_check_rereturn(err);
	if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok)
	{
		return 0;
	}
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_messageid(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_messageid_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_u32(ptr, rem, errcode, &tlen, &obj->m_id); mk_lang_check_rereturn(err);
	if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok)
	{
		return 0;
	}
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_tunnelid(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_tunnelid_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_u32(ptr, rem, errcode, &tlen, &obj->m_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_date(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_date_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_u64(ptr, rem, errcode, &tlen, &obj->m_ms_since_unix); mk_lang_check_rereturn(err);
	if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok)
	{
		return 0;
	}
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_hash(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_hash_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	tlen = mk_lib_crypto_hash_block_sha2_256_digest_len;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_serialize_errcode_e_not_enough_space;
		return 0;
	}
	mk_iip_cp_helper_memcpy_u8_fn(&ptr[0], &obj->m_digest.m_uint8s[0], mk_lib_crypto_hash_block_sha2_256_digest_len);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_bufbuf(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_buffer_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_u8s(ptr, rem, errcode, &tlen, &obj->m_buf[0], obj->m_len); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_buffer(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_buffer_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_s32(ptr, rem, errcode, &tlen, &obj->m_len); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_bufbuf(ptr, rem, errcode, &tlen, obj); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_strbuf(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_string_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	tlen = obj->m_len;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_serialize_errcode_e_not_enough_space;
		return 0;
	}
	n = tlen;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_pchar(&ptr[i], &obj->m_buf[i]);
	}
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_string(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_string_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_s8(ptr, rem, errcode, &tlen, &obj->m_len); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_strbuf(ptr, rem, errcode, &tlen, obj); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_strpair(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_strpair_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_string(ptr, rem, errcode, &tlen, &obj->m_key); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_pc(ptr, rem, errcode, &tlen, '='); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_string(ptr, rem, errcode, &tlen, &obj->m_val); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_pc(ptr, rem, errcode, &tlen, ';'); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_strpairs(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_strpairs_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	n = mk_iip_cp_type_strpairs_ro_size(obj);
	for(i = 0; i != n; ++i)
	{
		err = mk_iip_cp_message_serialize_strpair(ptr, rem, errcode, &tlen, mk_iip_cp_type_strpairs_ro_at(obj, i)); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	}

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_mapping(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_mapping_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint8_pt snapshot_ptr;
	mk_lang_types_sint_t snapshot_rem;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;
	mk_lang_types_sint_t marker;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	snapshot_ptr = ptr; snapshot_rem = rem; tsi = 0; err = mk_iip_cp_message_serialize_s16(ptr, rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	marker = rem; err = mk_iip_cp_message_serialize_strpairs(ptr, rem, errcode, &tlen, &obj->m_strpairs); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	tsi = marker - rem; err = mk_iip_cp_message_serialize_s16(snapshot_ptr, snapshot_rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; };

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_lease(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_lease_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_hash(ptr, rem, errcode, &tlen, &obj->m_router_hash); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_tunnelid(ptr, rem, errcode, &tlen, &obj->m_tunnel_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_date(ptr, rem, errcode, &tlen, &obj->m_end_date); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_leases_buf(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_leases_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	n = mk_iip_cp_type_leases_ro_size(obj);
	for(i = 0; i != n; ++i)
	{
		err = mk_iip_cp_message_serialize_lease(ptr, rem, errcode, &tlen, mk_iip_cp_type_leases_ro_at(obj, i)); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	}

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_leases(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_leases_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t count;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	count = ((mk_lang_types_sint_t)(mk_iip_cp_type_leases_ro_size(obj))); err = mk_iip_cp_message_serialize_s8(ptr, rem, errcode, &tlen, &count); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_leases_buf(ptr, rem, errcode, &tlen, obj); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_destination_elgamal_dsa(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_destination_elgamal_dsa_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t key_enc_first_half_len;
	mk_lang_types_sint_t key_sgn_first_half_len;
	mk_lang_types_sint_t padding_len;
	mk_sl_cui_uint8_t padding_buf[mk_lang_max(1, mk_iip_cp_message_serialize_destination_blob_padding_len_max)];
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	key_enc_first_half_len = mk_lang_min(mk_iip_cp_message_serialize_destination_blob_enc_pub_max, mk_iip_cp_helper_cui_elgamal_single_sizebytes_v);
	key_sgn_first_half_len = mk_lang_min(mk_iip_cp_message_serialize_destination_blob_sgn_pub_max, mk_iip_cp_helper_cui_dsa_pub_single_sizebytes_v);
	padding_len = mk_iip_cp_message_serialize_destination_blob_capacity - (key_enc_first_half_len + key_sgn_first_half_len);
	mk_iip_cp_helper_generate_random_u8s(&padding_buf[0], padding_len);

	err = mk_iip_cp_message_serialize_elgamal_key_public(ptr, rem, errcode, &tlen, &obj->m_key_elgamal_pub); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } mk_lang_assert(tlen == key_enc_first_half_len); ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_u8s(ptr, rem, errcode, &tlen, &padding_buf[0], padding_len); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } mk_lang_assert(tlen == padding_len); ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_dsa_key_public(ptr, rem, errcode, &tlen, &obj->m_key_dsa_pub); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } mk_lang_assert(tlen == key_sgn_first_half_len); ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_certificate_empty(ptr, rem, errcode, &tlen); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_leaseset(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_leaseset_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint8_pt snapshot_ptr;
	mk_lang_types_sint_t snapshot_rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;
	mk_lang_types_sint_t to_sign_len;
	mk_iip_cp_base_dsa_signature_t signature;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	snapshot_ptr = ptr; snapshot_rem = rem;
	err = mk_iip_cp_message_serialize_destination_elgamal_dsa(ptr, rem, errcode, &tlen, &obj->m_destination); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_elgamal_key_public(ptr, rem, errcode, &tlen, &obj->m_destination.m_key_elgamal_pub); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_dsa_key_public(ptr, rem, errcode, &tlen, &obj->m_destination.m_key_dsa_pub); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_leases(ptr, rem, errcode, &tlen, &obj->m_leases); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	to_sign_len = snapshot_rem - rem; mk_iip_cp_base_dsa_sign_k_has_n(&obj->m_destination.m_key_dsa_pri, snapshot_ptr, to_sign_len, &signature);
	err = mk_iip_cp_message_serialize_dsa_signature(ptr, rem, errcode, &tlen, &signature); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } mk_lang_assert(tlen == mk_iip_cp_base_dsa_signature_len_v); ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_session_config(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_session_config_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint8_pct snapshot_ptr;
	mk_lang_types_sint_t snapshot_rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;
	mk_lang_types_sint_t to_sign_len;
	mk_iip_cp_base_dsa_signature_t signature;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	snapshot_ptr = ptr; snapshot_rem = rem;
	err = mk_iip_cp_message_serialize_destination_elgamal_dsa(ptr, rem, errcode, &tlen, &obj->m_destination); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_mapping(ptr, rem, errcode, &tlen, &obj->m_options); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_date(ptr, rem, errcode, &tlen, &obj->m_creation_date); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	to_sign_len = snapshot_rem - rem; mk_iip_cp_base_dsa_sign_k_has_n(&obj->m_destination.m_key_dsa_pri, snapshot_ptr, to_sign_len, &signature);
	err = mk_iip_cp_message_serialize_dsa_signature(ptr, rem, errcode, &tlen, &signature); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } mk_lang_assert(tlen == mk_iip_cp_base_dsa_signature_len_v); ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_message_header(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_header_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_s32(ptr, rem, errcode, &tlen, &obj->m_len); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_message_type(ptr, rem, errcode, &tlen, &obj->m_type); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_create_session(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_create_session_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_session_config(ptr, rem, errcode, &tlen, &obj->m_session_config); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_reconfigure_session(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_reconfigure_session_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_destroy_session(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_destroy_session_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_sessionid(ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_create_lease_set(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_create_lease_set_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_sessionid(ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_dsa_key_private(ptr, rem, errcode, &tlen, &obj->m_key_sgn_pri); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_elgamal_key_private(ptr, rem, errcode, &tlen, &obj->m_key_enc_pri); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_leaseset(ptr, rem, errcode, &tlen, &obj->m_leaseset); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_send_message(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_send_message_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_sessionid(ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_buffer(ptr, rem, errcode, &tlen, &obj->m_destination); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_buffer(ptr, rem, errcode, &tlen, &obj->m_payload); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_u32(ptr, rem, errcode, &tlen, &obj->m_nonce); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_receive_message_begin(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_receive_message_begin_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_sessionid(ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_messageid(ptr, rem, errcode, &tlen, &obj->m_message_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_receive_message_end(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_receive_message_end_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_sessionid(ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_messageid(ptr, rem, errcode, &tlen, &obj->m_message_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_get_bandwidth_limits(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_get_bandwidth_limits_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	((mk_lang_types_void_t)(obj));

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_session_status(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_session_status_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_request_lease_set(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_request_lease_set_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_message_status(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_message_status_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_bandwidth_limits(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_bandwidth_limits_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_report_abuse(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_report_abuse_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_disconnect(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_disconnect_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_string(ptr, rem, errcode, &tlen, &obj->m_reason); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_message_payload(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_message_payload_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_get_date(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_get_date_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_string(ptr, rem, errcode, &tlen, &obj->m_client_version); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_mapping(ptr, rem, errcode, &tlen, &obj->m_authentication); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_set_date(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_set_date_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_dest_lookup(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_dest_lookup_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_dest_reply(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_dest_reply_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_send_message_expires(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_send_message_expires_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_request_variable_lease_set(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_request_variable_lease_set_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_host_lookup(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_host_lookup_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_serialize_sessionid(ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_u32(ptr, rem, errcode, &tlen, &obj->m_request_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_s32b(ptr, rem, errcode, &tlen, &obj->m_timeout_ms); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_host_lookup_request_type(ptr, rem, errcode, &tlen, &obj->m_request_type); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_serialize_string(ptr, rem, errcode, &tlen, &obj->m_hostname); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_host_reply(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_host_reply_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_create_lease_set2(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_create_lease_set2_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_msg_blinding_info(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_blinding_info_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_message(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint8_pt snapshot_ptr;
	mk_lang_types_sint_t snapshot_rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t marker;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	snapshot_ptr = ptr; snapshot_rem = rem; err = mk_iip_cp_message_serialize_message_header(ptr, rem, errcode, &tlen, &obj->m_header); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	marker = rem;
	switch(obj->m_header.m_type)
	{
		case mk_iip_cp_message_message_type_e_create_session            : err = mk_iip_cp_message_serialize_msg_create_session            (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_create_session            ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_reconfigure_session       : err = mk_iip_cp_message_serialize_msg_reconfigure_session       (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_reconfigure_session       ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_destroy_session           : err = mk_iip_cp_message_serialize_msg_destroy_session           (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_destroy_session           ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_create_lease_set          : err = mk_iip_cp_message_serialize_msg_create_lease_set          (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_create_lease_set          ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_send_message              : err = mk_iip_cp_message_serialize_msg_send_message              (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_send_message              ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_receive_message_begin     : err = mk_iip_cp_message_serialize_msg_receive_message_begin     (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_receive_message_begin     ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_receive_message_end       : err = mk_iip_cp_message_serialize_msg_receive_message_end       (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_receive_message_end       ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_get_bandwidth_limits      : err = mk_iip_cp_message_serialize_msg_get_bandwidth_limits      (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_get_bandwidth_limits      ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_session_status            : err = mk_iip_cp_message_serialize_msg_session_status            (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_session_status            ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_request_lease_set         : err = mk_iip_cp_message_serialize_msg_request_lease_set         (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_request_lease_set         ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_message_status            : err = mk_iip_cp_message_serialize_msg_message_status            (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_message_status            ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_bandwidth_limits          : err = mk_iip_cp_message_serialize_msg_bandwidth_limits          (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_bandwidth_limits          ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_report_abuse              : err = mk_iip_cp_message_serialize_msg_report_abuse              (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_report_abuse              ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_disconnect                : err = mk_iip_cp_message_serialize_msg_disconnect                (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_disconnect                ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_message_payload           : err = mk_iip_cp_message_serialize_msg_message_payload           (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_message_payload           ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_get_date                  : err = mk_iip_cp_message_serialize_msg_get_date                  (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_get_date                  ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_set_date                  : err = mk_iip_cp_message_serialize_msg_set_date                  (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_set_date                  ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_dest_lookup               : err = mk_iip_cp_message_serialize_msg_dest_lookup               (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_dest_lookup               ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_dest_reply                : err = mk_iip_cp_message_serialize_msg_dest_reply                (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_dest_reply                ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_send_message_expires      : err = mk_iip_cp_message_serialize_msg_send_message_expires      (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_send_message_expires      ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_request_variable_lease_set: err = mk_iip_cp_message_serialize_msg_request_variable_lease_set(ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_request_variable_lease_set); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_host_lookup               : err = mk_iip_cp_message_serialize_msg_host_lookup               (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_host_lookup               ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_host_reply                : err = mk_iip_cp_message_serialize_msg_host_reply                (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_host_reply                ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_create_lease_set2         : err = mk_iip_cp_message_serialize_msg_create_lease_set2         (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_create_lease_set2         ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_blinding_info             : err = mk_iip_cp_message_serialize_msg_blinding_info             (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_blinding_info             ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	tsi = marker - rem; err = mk_iip_cp_message_serialize_s32(snapshot_ptr, snapshot_rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_serialize_errcode_e_ok){ return 0; }

	tlen = len - rem;
	*errcode = mk_iip_cp_message_serialize_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


#endif
