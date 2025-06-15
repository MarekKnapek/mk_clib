#ifndef mk_include_guard_mk_iip_cp_destination_c
#define mk_include_guard_mk_iip_cp_destination_c
#include "mk_iip_cp_destination.h"

#include "mk_iip_cp_type.h"
#include "mk_iip_cp_helper.h"
#include "mk_iip_cp_message.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint8.h"
#include "mk_sl_uint.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_destination_serialize_uchars(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed, mk_lang_types_uchar_pct const objs, mk_lang_types_sint_t const objlen) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);
	mk_lang_assert(objs || objlen == 0);
	mk_lang_assert(objlen >= 0 && objlen <= 128 * 1024);

	ptr = buf;
	rem = len;

	tlen = objlen;
	if(!(rem >= tlen))
	{
		*gud = mk_lang_false;
		return 0;
	}
	mk_iip_cp_helper_uchars_to_u8s(&objs[0], &ptr[0], tlen);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*gud = mk_lang_true;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_destination_serialize_elgamal_key_public(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed, mk_iip_cp_base_elgamal_key_pub_pct const obj) mk_lang_noexcept
{
	union mk_iip_cp_destination_serialize_elgamal_key_public_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_elgamal_single_sizebytes_v];
		mk_iip_cp_helper_cui_elgamal_single_t m_elgamal_key_public;
	};
	typedef union mk_iip_cp_destination_serialize_elgamal_key_public_data_u mk_iip_cp_destination_serialize_elgamal_key_public_data_t;
	struct mk_iip_cp_destination_serialize_elgamal_key_public_s
	{
		mk_iip_cp_destination_serialize_elgamal_key_public_data_t m_data;
	};
	typedef struct mk_iip_cp_destination_serialize_elgamal_key_public_s mk_iip_cp_destination_serialize_elgamal_key_public_t;

	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_iip_cp_destination_serialize_elgamal_key_public_t storage;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_iip_cp_helper_cui_elgamal_single_to_buis_uchar_be(&obj->m_data.m_val, &storage.m_data.m_uchars[0]);
	err = mk_iip_cp_destination_serialize_uchars(ptr, rem, gud, &tlen, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err); if(!*gud){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*gud = mk_lang_true;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_destination_serialize_dsa_key_public(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed, mk_iip_cp_base_dsa_key_pub_pct const obj) mk_lang_noexcept
{
	union mk_iip_cp_destination_serialize_dsa_key_public_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_iip_cp_helper_cui_dsa_pub_single_sizebytes_v];
		mk_iip_cp_helper_cui_dsa_pub_single_t m_dsa_key_public;
	};
	typedef union mk_iip_cp_destination_serialize_dsa_key_public_data_u mk_iip_cp_destination_serialize_dsa_key_public_data_t;
	struct mk_iip_cp_destination_serialize_dsa_key_public_s
	{
		mk_iip_cp_destination_serialize_dsa_key_public_data_t m_data;
	};
	typedef struct mk_iip_cp_destination_serialize_dsa_key_public_s mk_iip_cp_destination_serialize_dsa_key_public_t;

	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_iip_cp_destination_serialize_dsa_key_public_t storage;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_iip_cp_helper_cui_dsa_pub_single_to_buis_uchar_be(&obj->m_data.m_val, &storage.m_data.m_uchars[0]);
	err = mk_iip_cp_destination_serialize_uchars(ptr, rem, gud, &tlen, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err); if(!*gud){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*gud = mk_lang_true;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_destination_serialize_s8(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);
	mk_lang_assert(*obj >= 0x00);
	mk_lang_assert(*obj <= 0xff);

	ptr = buf;
	rem = len;

	tlen = mk_sl_cui_uint8_sizebytes_v;
	if(!(rem >= tlen))
	{
		*gud = mk_lang_false;
		return 0;
	}
	mk_sl_cui_uint8_from_bi_sint(&ptr[0], obj);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*gud = mk_lang_true;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_destination_serialize_u16(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint16_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	tlen = mk_sl_cui_uint16_sizebytes_v;
	if(!(rem >= tlen))
	{
		*gud = mk_lang_false;
		return 0;
	}
	mk_sl_uint_16_to_8_be(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*gud = mk_lang_true;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_destination_serialize_s16(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);
	mk_lang_assert(*obj >= 0x0000u);
	mk_lang_assert(*obj <= 0xffffu);

	ptr = buf;
	rem = len;

	mk_sl_cui_uint16_from_bi_sint(&tu16, obj);
	err = mk_iip_cp_destination_serialize_u16(ptr, rem, gud, &tlen, &tu16); mk_lang_check_rereturn(err); if(!*gud){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*gud = mk_lang_true;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_destination_serialize_certificate_type(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_certificate_type_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(gud);
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
	tsi = ((mk_lang_types_sint_t)(*obj)); err = mk_iip_cp_destination_serialize_s8(ptr, rem, gud, &tlen, &tsi); mk_lang_check_rereturn(err); if(!*gud){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*gud = mk_lang_true;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_destination_serialize_certificate_empty(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_iip_cp_message_certificate_type_t ct;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);

	ptr = buf;
	rem = len;

	ct = mk_iip_cp_message_certificate_type_e_null; err = mk_iip_cp_destination_serialize_certificate_type(ptr, rem, gud, &tlen, &ct); mk_lang_check_rereturn(err); if(!*gud){ return 0; } ptr += tlen; rem -= tlen;
	tsi = 0; err = mk_iip_cp_destination_serialize_s16(ptr, rem, gud, &tlen, &tsi); mk_lang_check_rereturn(err); if(!*gud){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*gud = mk_lang_true;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_destination_serialize_elgamal_dsa(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_lang_types_bool_pt const gud, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_destination_elgamal_dsa_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(gud);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_destination_serialize_elgamal_key_public(ptr, rem, gud, &tlen, &obj->m_key_elgamal_pub); mk_lang_check_rereturn(err); if(!*gud){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_destination_serialize_dsa_key_public(ptr, rem, gud, &tlen, &obj->m_key_dsa_pub); mk_lang_check_rereturn(err); if(!*gud){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_destination_serialize_certificate_empty(ptr, rem, gud, &tlen); mk_lang_check_rereturn(err); if(!*gud){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*gud = mk_lang_true;
	*consumed = tlen;
	return 0;
}


#endif
