#ifndef mk_include_guard_mk_lib_iip_cp_message_serialize_c
#define mk_include_guard_mk_lib_iip_cp_message_serialize_c
#include "mk_lib_iip_cp_message_serialize.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_iip_key_enc_elgamal_pri.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_key_sgn.h"
#include "mk_lib_iip_random.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"
#include "mk_sl_uint_more.h"


#define mk_lib_iip_cp_message_serialize_k_max_sint_val (128ul * 1024ul)
#define mk_lib_iip_cp_message_serialize_k_max_timeout (1ul * 24ul * 60ul * 60ul * 1000ul)
#define mk_lib_iip_cp_message_serialize_destination_blob_enc_pub_max (256)
#define mk_lib_iip_cp_message_serialize_destination_blob_sgn_pub_max (128)


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_uchars(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lang_types_uchar_pct const obj_buf, mk_lang_types_sint_t const obj_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj_buf || obj_len == 0);
	mk_lang_assert(obj_len >= 0);
	mk_lang_assert(((mk_lang_types_ulong_t)(obj_len)) < mk_lib_iip_cp_message_serialize_k_max_sint_val);

	ptr = data_buf;
	rem = data_len;
	tlen = obj_len * 1;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_serialize_error_code_e_not_enough_free_space;
		return 0;
	}
	mk_sl_cui_uint8_from_bi_uchar_many(ptr, obj_buf, ((mk_lang_types_usize_t)(obj_len)));
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_u8s(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint8_pct const obj_buf, mk_lang_types_sint_t const obj_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj_buf || obj_len == 0);
	mk_lang_assert(obj_len >= 0);
	mk_lang_assert(((mk_lang_types_ulong_t)(obj_len)) < mk_lib_iip_cp_message_serialize_k_max_sint_val);

	ptr = data_buf;
	rem = data_len;
	tlen = obj_len * 1;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_serialize_error_code_e_not_enough_free_space;
		return 0;
	}
	mk_sl_cui_uint8_memcpy_fn(ptr, obj_buf, ((mk_lang_types_usize_t)(obj_len)));
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_u8(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint8_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	tlen = mk_sl_cui_uint8_size_bytes_v;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_serialize_error_code_e_not_enough_free_space;
		return 0;
	}
	ptr[0] = *obj;
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_u16(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint16_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	tlen = mk_sl_cui_uint16_size_bytes_v;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_serialize_error_code_e_not_enough_free_space;
		return 0;
	}
	mk_sl_uint_convert_16_8_be_to_sml(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_u32(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint32_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	tlen = mk_sl_cui_uint32_size_bytes_v;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_serialize_error_code_e_not_enough_free_space;
		return 0;
	}
	mk_sl_uint_convert_32_8_be_to_sml(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_u64(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint64_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	tlen = mk_sl_cui_uint64_size_bytes_v;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_serialize_error_code_e_not_enough_free_space;
		return 0;
	}
	mk_sl_uint_convert_64_8_be_to_sml(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_pchar(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lang_types_pchar_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_sl_cui_uint8_from_bi_pchar(&tu8, obj);
	err = mk_lib_iip_cp_message_serialize_u8(ptr, rem, error_code, &tlen, &tu8); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_sint_8(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_assert(*obj >= 0x00);
	mk_lang_assert(*obj <= 0xff);
	mk_sl_cui_uint8_from_bi_sint(&tu8, obj);
	err = mk_lib_iip_cp_message_serialize_u8(ptr, rem, error_code, &tlen, &tu8); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_sint_16(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16 mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_assert(*obj >= 0x0000);
	mk_lang_assert(*obj <= 0x7fff);
	mk_sl_cui_uint16_from_bi_sint(&tu16, obj);
	err = mk_lib_iip_cp_message_serialize_u16(ptr, rem, error_code, &tlen, &tu16); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_sint_32(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_assert(((mk_lang_types_slong_t)(*obj)) >= 0);
	mk_lang_assert(((mk_lang_types_ulong_t)(*obj)) <= mk_lib_iip_cp_message_serialize_k_max_sint_val);
	mk_sl_cui_uint32_from_bi_sint(&tu32, obj);
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &tu32); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_timeout_ms(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_assert(((mk_lang_types_slong_t)(*obj)) >= 0);
	mk_lang_assert(((mk_lang_types_ulong_t)(*obj)) <= mk_lib_iip_cp_message_serialize_k_max_timeout);
	mk_sl_cui_uint32_from_bi_sint(&tu32, obj);
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &tu32); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_enum_message_type(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_message_type_id_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_message_type_val_t val mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	val = mk_lib_iip_cp_message_message_type_id_to_message_type_val(*obj);
	tsi = ((mk_lang_types_sint_t)(val));
	err = mk_lib_iip_cp_message_serialize_sint_8(ptr, rem, error_code, &tlen, &tsi); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_enum_host_lookup_request_type(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_host_lookup_request_type_id_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_host_lookup_request_type_val_t val mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	val = mk_lib_iip_cp_message_host_lookup_request_type_id_to_host_lookup_request_type_val(*obj);
	tsi = ((mk_lang_types_sint_t)(val));
	err = mk_lib_iip_cp_message_serialize_sint_8(ptr, rem, error_code, &tlen, &tsi); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_enum_certificate_type(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_certificate_type_id_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_certificate_type_val_t val mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	val = mk_lib_iip_cp_message_certificate_type_id_to_certificate_type_val(*obj);
	tsi = ((mk_lang_types_sint_t)(val));
	err = mk_lib_iip_cp_message_serialize_sint_8(ptr, rem, error_code, &tlen, &tsi); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_enum_session_status_status(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_session_status_status_id_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_session_status_status_val_t val mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	val = mk_lib_iip_cp_message_session_status_status_id_to_session_status_status_val(*obj);
	tsi = ((mk_lang_types_sint_t)(val));
	err = mk_lib_iip_cp_message_serialize_sint_8(ptr, rem, error_code, &tlen, &tsi); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_sessionid(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_sessionid_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_u16(ptr, rem, error_code, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_messageid(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_messageid_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_tunnelid(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_tunnelid_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_requestid(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_requestid_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_nonce(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_nonce_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_date(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_date_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_u64(ptr, rem, error_code, &tlen, &obj->m_elements[0].m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

/*mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_elgamal_key_pri(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_key_enc_elgamal_pri_pct const obj) mk_lang_noexcept
{
	union mk_lib_iip_cp_message_serialize_elgamal_key_pri_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_enc_elgamal_pri_integer_single_size_bytes_v];
		mk_lib_iip_key_enc_elgamal_pri_t m_elgamal_key_pri;
	};
	typedef union mk_lib_iip_cp_message_serialize_elgamal_key_pri_data_u mk_lib_iip_cp_message_serialize_elgamal_key_pri_data_t;
	struct mk_lib_iip_cp_message_serialize_elgamal_key_pri_s
	{
		mk_lib_iip_cp_message_serialize_elgamal_key_pri_data_t m_data;
	};
	typedef struct mk_lib_iip_cp_message_serialize_elgamal_key_pri_s mk_lib_iip_cp_message_serialize_elgamal_key_pri_t;

	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_serialize_elgamal_key_pri_t storage mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lib_iip_key_enc_elgamal_pri_integer_single_to_buis_uchar_be(&obj->m_data.m_integer, &storage.m_data.m_uchars[0]);
	err = mk_lib_iip_cp_message_serialize_uchars(ptr, rem, error_code, &tlen, &storage.m_data.m_uchars[0], mk_lang_countof(storage.m_data.m_uchars)); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}*/

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_dsa_sha1_key_pri(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_key_sgn_dsa_sha1_pri_pct const obj) mk_lang_noexcept
{
	union mk_lib_iip_cp_message_serialize_dsa_sha1_key_pri_data_u
	{
		mk_sl_cui_uint8_t m_uint8s[mk_lib_iip_key_sgn_dsa_sha1_pri_len_v];
		mk_lib_iip_key_sgn_dsa_sha1_pri_t m_dsa_sha1_key_pri;
	};
	typedef union mk_lib_iip_cp_message_serialize_dsa_sha1_key_pri_data_u mk_lib_iip_cp_message_serialize_dsa_sha1_key_pri_data_t;
	struct mk_lib_iip_cp_message_serialize_dsa_sha1_key_pri_s
	{
		mk_lib_iip_cp_message_serialize_dsa_sha1_key_pri_data_t m_data;
	};
	typedef struct mk_lib_iip_cp_message_serialize_dsa_sha1_key_pri_s mk_lib_iip_cp_message_serialize_dsa_sha1_key_pri_t;

	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_serialize_dsa_sha1_key_pri_t storage mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		err = mk_lib_iip_key_sgn_dsa_sha1_pri_rw_export_pri_to_u8s(obj, &storage.m_data.m_uint8s[0]); mk_lang_check_rereturn(err);
	}
	else
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_sl_cui_uint8_memclr_fn(&storage.m_data.m_uint8s[0], mk_lang_countof(storage.m_data.m_uint8s));
		#include "mk_lang_warning_clang_pop.h"
	}
	err = mk_lib_iip_cp_message_serialize_u8s(ptr, rem, error_code, &tlen, &storage.m_data.m_uint8s[0], mk_lang_countof(storage.m_data.m_uint8s)); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_ecdsa_sha256_p256_key_pub(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_pct const obj) mk_lang_noexcept
{
	union mk_lib_iip_cp_message_serialize_ecdsa_sha256_p256_key_pub_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_size_bytes_v];
		mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_t m_ecdsa_sha256_p256_key_pub;
	};
	typedef union mk_lib_iip_cp_message_serialize_ecdsa_sha256_p256_key_pub_data_u mk_lib_iip_cp_message_serialize_ecdsa_sha256_p256_key_pub_data_t;
	struct mk_lib_iip_cp_message_serialize_ecdsa_sha256_p256_key_pub_s
	{
		mk_lib_iip_cp_message_serialize_ecdsa_sha256_p256_key_pub_data_t m_data;
	};
	typedef struct mk_lib_iip_cp_message_serialize_ecdsa_sha256_p256_key_pub_s mk_lib_iip_cp_message_serialize_ecdsa_sha256_p256_key_pub_t;

	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_serialize_ecdsa_sha256_p256_key_pub_t storage mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lib_iip_key_sgn_ecdsa_sha256_p256_pub_integer_single_to_buis_uchar_be(&obj->m_data.m_integer, &storage.m_data.m_uchars[0]);
	err = mk_lib_iip_cp_message_serialize_uchars(ptr, rem, error_code, &tlen, &storage.m_data.m_uchars[0], mk_lang_min(mk_lib_iip_cp_message_serialize_destination_blob_sgn_pub_max, mk_lang_countof(storage.m_data.m_uchars))); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_dsa_sha1_signature(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_key_sgn_dsa_sha1_signature_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_u8s(ptr, rem, error_code, &tlen, &obj->m_base.m_data.m_uint8s[0], mk_lang_countof(obj->m_base.m_data.m_uint8s)); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_certificate_empty(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lib_iip_cp_message_certificate_type_id_t certificate_type_id mk_lang_constexpr_init;
	mk_lang_types_sint_t certificate_data_len mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);

	ptr = data_buf;
	rem = data_len;
	certificate_type_id = mk_lib_iip_cp_message_certificate_type_id_e_null;
	certificate_data_len = 0;
	err = mk_lib_iip_cp_message_serialize_enum_certificate_type(ptr, rem, error_code, &tlen, &certificate_type_id ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_sint_16              (ptr, rem, error_code, &tlen, &certificate_data_len); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_remote_destination(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_destination_remote_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	err = mk_lib_iip_cp_destination_remote_ro_to_bytes(obj, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *error_code = mk_lib_iip_cp_message_serialize_error_code_e_other; return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_remote_destination_2(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_destination_remote_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	err = mk_lib_iip_cp_destination_remote_ro_enc_to_bytes(obj, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *error_code = mk_lib_iip_cp_message_serialize_error_code_e_other; return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_destination_remote_ro_sgn_to_bytes(obj, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *error_code = mk_lib_iip_cp_message_serialize_error_code_e_other; return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_buf_buf(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_buffer_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_u8s(ptr, rem, error_code, &tlen, &obj->m_buf[0], obj->m_len); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_buffer(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_buffer_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_sint_32     (ptr, rem, error_code, &tlen, &obj->m_len); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_buf_buf(ptr, rem, error_code, &tlen, obj        ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_str_buf(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_string_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	tlen = obj->m_len;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_serialize_error_code_e_not_enough_free_space;
		return 0;
	}
	mk_sl_cui_uint8_from_bi_pchar_many(ptr, &obj->m_buf[0], ((mk_lang_types_usize_t)(obj->m_len)));
	ptr += tlen;
	rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_string(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_string_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_sint_8 (ptr, rem, error_code, &tlen, &obj->m_len); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_str_buf(ptr, rem, error_code, &tlen, obj        ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_strpair(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_strpair_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_pchar_t sep_key_val mk_lang_constexpr_init;
	mk_lang_types_pchar_t sep_pairs mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	sep_key_val = '=';
	sep_pairs = ';';
	err = mk_lib_iip_cp_message_serialize_type_string(ptr, rem, error_code, &tlen, &obj->m_key ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_pchar      (ptr, rem, error_code, &tlen, &sep_key_val); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_string(ptr, rem, error_code, &tlen, &obj->m_val ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_pchar      (ptr, rem, error_code, &tlen, &sep_pairs  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_strpairs(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_strpairs_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_iip_cp_types_strpair_pct strpair;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	n = mk_lib_iip_cp_types_strpairs_ro_size(obj);
	for(i = 0; i != n; ++i)
	{
		strpair = mk_lib_iip_cp_types_strpairs_ro_at(obj, i); mk_lang_assert(strpair);
		err = mk_lib_iip_cp_message_serialize_type_strpair(ptr, rem, error_code, &tlen, strpair); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_mapping(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_mapping_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptb mk_lang_constexpr_init;
	mk_lang_types_sint_t reb mk_lang_constexpr_init;
	mk_lang_types_sint_t unknown_len mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t marker mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	ptb = ptr; reb = rem; unknown_len = 0;
	err = mk_lib_iip_cp_message_serialize_sint_16      (ptr, rem, error_code, &tlen, &unknown_len    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; marker = rem;
	err = mk_lib_iip_cp_message_serialize_type_strpairs(ptr, rem, error_code, &tlen, &obj->m_strpairs); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; unknown_len = marker - rem; reb = mk_lang_min(reb, mk_sl_cui_uint16_size_bytes_v);
	err = mk_lib_iip_cp_message_serialize_sint_16      (ptb, reb, error_code, &tlen, &unknown_len    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem);
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_hash(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_hash_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_u8s(ptr, rem, error_code, &tlen, &obj->m_digest.m_data.m_uint8s[0], mk_lang_countof(obj->m_digest.m_data.m_uint8s)); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_lease(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_lease_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_hash    (ptr, rem, error_code, &tlen, &obj->m_router_hash); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_tunnelid(ptr, rem, error_code, &tlen, &obj->m_tunnel_id  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_date    (ptr, rem, error_code, &tlen, &obj->m_end_date   ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_leases_buf(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_leases_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_iip_cp_types_lease_pct lease mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	n = mk_lib_iip_cp_types_leases_ro_size(obj);
	for(i = 0; i != n; ++i)
	{
		lease = mk_lib_iip_cp_types_leases_ro_at(obj, i); mk_lang_assert(lease);
		err = mk_lib_iip_cp_message_serialize_type_lease(ptr, rem, error_code, &tlen, lease); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_leases(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_leases_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t count;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	count = mk_lib_iip_cp_types_leases_ro_sise(obj);
	err = mk_lib_iip_cp_message_serialize_sint_8         (ptr, rem, error_code, &tlen, &count); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_leases_buf(ptr, rem, error_code, &tlen, obj   ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_leaseset(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_leaseset_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint8_pt snapshot_ptr;
	mk_lang_types_sint_t snapshot_rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	snapshot_ptr = ptr; snapshot_rem = rem;
	err = mk_lib_iip_cp_message_serialize_type_remote_destination  (ptr, rem, error_code, &tlen, &obj->m_local_destination.m_remote_destination ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_remote_destination_2(ptr, rem, error_code, &tlen, &obj->m_local_destination.m_remote_destination ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_leases              (ptr, rem, error_code, &tlen, &obj->m_leases                                 ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_key_sgn_rw_sign_data                          (&obj->m_local_destination, snapshot_ptr, snapshot_rem - rem, ptr, rem, &tlen); mk_lang_check_rereturn(err); if(!(tlen >= 32)                                                 ){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_type_session_config(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_session_config_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_cui_uint8_pct snapshot_ptr;
	mk_lang_types_sint_t snapshot_rem;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	snapshot_ptr = ptr; snapshot_rem = rem;
	err = mk_lib_iip_cp_message_serialize_type_remote_destination(ptr, rem, error_code, &tlen, &obj->m_local_destination.m_remote_destination ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_mapping           (ptr, rem, error_code, &tlen, &obj->m_options                                ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_date              (ptr, rem, error_code, &tlen, &obj->m_creation_date                          ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_key_sgn_rw_sign_data                        (&obj->m_local_destination, snapshot_ptr, snapshot_rem - rem, ptr, rem, &tlen); mk_lang_check_rereturn(err); if(!(tlen >= 32)                                                 ){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_header(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_header_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_sint_32          (ptr, rem, error_code, &tlen, &obj->m_len ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_enum_message_type(ptr, rem, error_code, &tlen, &obj->m_type); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_create_session(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_create_session_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_session_config(ptr, rem, error_code, &tlen, &obj->m_session_config); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_reconfigure_session(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_reconfigure_session_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_destroy_session(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_destroy_session_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_sessionid(ptr, rem, error_code, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_dsa_signing_private_key(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_create_lease_set_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	err = mk_lib_iip_cp_destination_local_ro_sgn_to_bytes(&obj->m_leaseset.m_local_destination, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *error_code = mk_lib_iip_cp_message_serialize_error_code_e_other; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_create_lease_set_enc_pri(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_create_lease_set_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	gud = mk_lang_true;
	err = mk_lib_iip_cp_destination_local_ro_enc_to_bytes(&obj->m_leaseset.m_local_destination, ptr, rem, &gud, &tlen); mk_lang_check_rereturn(err); if(!gud){ *error_code = mk_lib_iip_cp_message_serialize_error_code_e_other; return 0; } mk_lang_assert(tlen >= 1); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_create_lease_set(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_create_lease_set_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_sessionid              (ptr, rem, error_code, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_dsa_signing_private_key     (ptr, rem, error_code, &tlen, obj               ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_msg_create_lease_set_enc_pri(ptr, rem, error_code, &tlen, obj               ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_leaseset               (ptr, rem, error_code, &tlen, &obj->m_leaseset  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_send_message(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_send_message_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_sessionid         (ptr, rem, error_code, &tlen, &obj->m_session_id        ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_remote_destination(ptr, rem, error_code, &tlen, &obj->m_remote_destination); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_buffer            (ptr, rem, error_code, &tlen, &obj->m_payload           ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_nonce             (ptr, rem, error_code, &tlen, &obj->m_nonce             ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_receive_message_begin(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_receive_message_begin_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_sessionid(ptr, rem, error_code, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_messageid(ptr, rem, error_code, &tlen, &obj->m_message_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_receive_message_end(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_receive_message_end_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_sessionid(ptr, rem, error_code, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_messageid(ptr, rem, error_code, &tlen, &obj->m_message_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_get_bandwidth_limits(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_get_bandwidth_limits_pct const obj) mk_lang_noexcept
{
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	rem = data_len;
	((mk_lang_types_void_t)(obj));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_session_status(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_session_status_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_sessionid            (ptr, rem, error_code, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_enum_session_status_status(ptr, rem, error_code, &tlen, &obj->m_status    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_request_lease_set(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_request_lease_set_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_message_status(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_message_status_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_bandwidth_limits(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_bandwidth_limits_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_client_inbound_limit_kbps       ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_client_outbound_limit_kbps      ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_router_inbound_limit_kbps       ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_router_inbound_burst_limit_kbps ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_router_outbound_limit_kbps      ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_router_outbound_burst_limit_kbps); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_router_burst_time_seconds       ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_1                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_2                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_3                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_4                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_5                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_6                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_7                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_8                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_9                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_report_abuse(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_report_abuse_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_disconnect(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_disconnect_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_string(ptr, rem, error_code, &tlen, &obj->m_reason); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_message_payload(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_message_payload_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_get_date(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_get_date_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_string (ptr, rem, error_code, &tlen, &obj->m_api_version   ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_mapping(ptr, rem, error_code, &tlen, &obj->m_authentication); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_set_date(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_set_date_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_date  (ptr, rem, error_code, &tlen, &obj->m_server_date); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_string(ptr, rem, error_code, &tlen, &obj->m_api_version); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_dest_lookup(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_dest_lookup_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_dest_reply(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_dest_reply_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_send_message_expires(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_send_message_expires_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_request_variable_lease_set(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_request_variable_lease_set_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_host_lookup(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_host_lookup_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_serialize_type_sessionid               (ptr, rem, error_code, &tlen, &obj->m_session_id  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_requestid               (ptr, rem, error_code, &tlen, &obj->m_request_id  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_timeout_ms                   (ptr, rem, error_code, &tlen, &obj->m_timeout_ms  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_enum_host_lookup_request_type(ptr, rem, error_code, &tlen, &obj->m_request_type); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_serialize_type_string                  (ptr, rem, error_code, &tlen, &obj->m_hostname    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_host_reply(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_host_reply_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_create_lease_set2(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_create_lease_set2_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_msg_blinding_info(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_blinding_info_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	mk_lang_check_todo();
	((mk_lang_types_void_t)(ptr));
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_mix(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_pct const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	switch(obj->m_header.m_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : err = mk_lib_iip_cp_message_serialize_msg_create_session            (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_create_session            ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : err = mk_lib_iip_cp_message_serialize_msg_reconfigure_session       (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_reconfigure_session       ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : err = mk_lib_iip_cp_message_serialize_msg_destroy_session           (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_destroy_session           ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : err = mk_lib_iip_cp_message_serialize_msg_create_lease_set          (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_create_lease_set          ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : err = mk_lib_iip_cp_message_serialize_msg_send_message              (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_send_message              ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : err = mk_lib_iip_cp_message_serialize_msg_receive_message_begin     (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_receive_message_begin     ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : err = mk_lib_iip_cp_message_serialize_msg_receive_message_end       (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_receive_message_end       ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : err = mk_lib_iip_cp_message_serialize_msg_get_bandwidth_limits      (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_get_bandwidth_limits      ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : err = mk_lib_iip_cp_message_serialize_msg_session_status            (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_session_status            ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : err = mk_lib_iip_cp_message_serialize_msg_request_lease_set         (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_request_lease_set         ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : err = mk_lib_iip_cp_message_serialize_msg_message_status            (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_message_status            ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : err = mk_lib_iip_cp_message_serialize_msg_bandwidth_limits          (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_bandwidth_limits          ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : err = mk_lib_iip_cp_message_serialize_msg_report_abuse              (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_report_abuse              ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : err = mk_lib_iip_cp_message_serialize_msg_disconnect                (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_disconnect                ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : err = mk_lib_iip_cp_message_serialize_msg_message_payload           (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_message_payload           ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : err = mk_lib_iip_cp_message_serialize_msg_get_date                  (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_get_date                  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : err = mk_lib_iip_cp_message_serialize_msg_set_date                  (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_set_date                  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : err = mk_lib_iip_cp_message_serialize_msg_dest_lookup               (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_dest_lookup               ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : err = mk_lib_iip_cp_message_serialize_msg_dest_reply                (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_dest_reply                ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : err = mk_lib_iip_cp_message_serialize_msg_send_message_expires      (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_send_message_expires      ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: err = mk_lib_iip_cp_message_serialize_msg_request_variable_lease_set(ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_request_variable_lease_set); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : err = mk_lib_iip_cp_message_serialize_msg_host_lookup               (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_host_lookup               ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : err = mk_lib_iip_cp_message_serialize_msg_host_reply                (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_host_reply                ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : err = mk_lib_iip_cp_message_serialize_msg_create_lease_set2         (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_create_lease_set2         ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : err = mk_lib_iip_cp_message_serialize_msg_blinding_info             (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_blinding_info             ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_message(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt ptb mk_lang_constexpr_init;
	mk_lang_types_sint_t reb mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_sl_cui_uint8_pt snapshot_ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t snapshot_rem mk_lang_constexpr_init;
	mk_lang_types_sint_t marker mk_lang_constexpr_init;
	mk_lang_types_sint_t content_len mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	snapshot_ptr = ptr; snapshot_rem = rem;
	err = mk_lib_iip_cp_message_serialize_header (ptr, rem, error_code, &tlen, &obj->m_header); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; marker = rem;
	err = mk_lib_iip_cp_message_serialize_mix    (ptr, rem, error_code, &tlen, obj           ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	ptb = snapshot_ptr; reb = snapshot_rem; content_len = marker - rem; reb = mk_lang_min(reb, mk_sl_cui_uint32_size_bytes_v); obj->m_header.m_len = content_len;
	err = mk_lib_iip_cp_message_serialize_sint_32(ptb, reb, error_code, &tlen, &content_len  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_serialize_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem);
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


#endif
