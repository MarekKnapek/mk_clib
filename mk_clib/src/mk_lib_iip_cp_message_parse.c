#ifndef mk_include_guard_mk_lib_iip_cp_message_parse_c
#define mk_include_guard_mk_lib_iip_cp_message_parse_c
#include "mk_lib_iip_cp_message_parse.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"
#include "mk_sl_uint_more.h"


#define mk_lib_iip_cp_message_parse_k_max_msg_len (128ul * 1024ul)


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_u8s(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint8_pt const obj_buf, mk_lang_types_sint_t const obj_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj_buf || obj_len == 0);
	mk_lang_assert(obj_len >= 0);

	ptr = data_buf;
	rem = data_len;

	tlen = obj_len * mk_sl_cui_uint8_size_bytes_v;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_not_enough_data;
		return 0;
	}
	mk_sl_cui_uint8_memcpy_fn(obj_buf, ptr, ((mk_lang_types_usize_t)(obj_len)));
	ptr += tlen;
	rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_u8(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint8_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	tlen = mk_sl_cui_uint8_size_bytes_v;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_not_enough_data;
		return 0;
	}
	*obj = ptr[0];
	ptr += tlen;
	rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_u16(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint16_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	tlen = mk_sl_cui_uint16_size_bytes_v;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_not_enough_data;
		return 0;
	}
	mk_sl_uint_convert_16_8_be_to_big(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_u32(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint32_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	tlen = mk_sl_cui_uint32_size_bytes_v;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_not_enough_data;
		return 0;
	}
	mk_sl_uint_convert_32_8_be_to_big(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_u64(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint64_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	tlen = mk_sl_cui_uint64_size_bytes_v;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_not_enough_data;
		return 0;
	}
	mk_sl_uint_convert_64_8_be_to_big(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_sint(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &tu32); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_sl_cui_uint32_to_bi_ulong(&tu32, &tul);
	if(tul >= mk_lib_iip_cp_message_parse_k_max_msg_len)
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_too_much_data;
		return 0;
	}
	*obj = ((mk_lang_types_sint_t)(tul));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_char(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lang_types_pchar_t const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;
	mk_lang_types_pchar_t tpc mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj == '\0' || obj != '\0');

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u8(ptr, rem, error_code, &tlen, &tu8); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_sl_cui_uint8_to_bi_pchar(&tu8, &tpc);
	if(!(tpc == obj))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_unexpected_char;
		return 0;
	}

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_s8(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u8(ptr, rem, error_code, &tlen, &tu8); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_sl_cui_uint8_to_bi_sint(&tu8, obj);

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_s16(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_sl_cui_uint16_t tu16 mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_ulong_t)(mk_lang_limits_sint_max)) >= ((mk_lang_types_ulong_t)(0xfffful)));

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u16(ptr, rem, error_code, &tlen, &tu16); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_sl_cui_uint16_to_bi_sint(&tu16, obj);

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_enum_message_type(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_message_type_id_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_bool_t is_known mk_lang_constexpr_init;
	mk_lib_iip_cp_message_message_type_val_t message_type_val mk_lang_constexpr_init;
	mk_lib_iip_cp_message_message_type_id_t message_type_id mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_s8(ptr, rem, error_code, &tlen, &tsi); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	is_known = mk_lib_iip_cp_message_message_type_val_is_known(tsi);
	if(!is_known)
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_unknown_message_type;
		return 0;
	}
	message_type_val = ((mk_lib_iip_cp_message_message_type_val_t)(tsi));
	message_type_id = mk_lib_iip_cp_message_message_type_val_to_message_type_id(message_type_val);
	*obj = message_type_id;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_enum_session_status_status(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_session_status_status_id_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_bool_t is_known mk_lang_constexpr_init;
	mk_lib_iip_cp_message_session_status_status_val_t session_status_status_val mk_lang_constexpr_init;
	mk_lib_iip_cp_message_session_status_status_id_t session_status_status_id mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_s8(ptr, rem, error_code, &tlen, &tsi); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	is_known = mk_lib_iip_cp_message_session_status_status_val_is_known(tsi);
	if(!is_known)
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_unknown_session_status_status;
		return 0;
	}
	session_status_status_val = ((mk_lib_iip_cp_message_session_status_status_val_t)(tsi));
	session_status_status_id = mk_lib_iip_cp_message_session_status_status_val_to_session_status_status_id(session_status_status_val);
	*obj = session_status_status_id;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_enum_message_status_status(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_message_status_status_id_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_bool_t is_known mk_lang_constexpr_init;
	mk_lib_iip_cp_message_message_status_status_val_t message_status_status_val mk_lang_constexpr_init;
	mk_lib_iip_cp_message_message_status_status_id_t message_status_status_id mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_s8(ptr, rem, error_code, &tlen, &tsi); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	is_known = mk_lib_iip_cp_message_message_status_status_val_is_known(tsi);
	if(!is_known)
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_unknown_message_status_status;
		return 0;
	}
	message_status_status_val = ((mk_lib_iip_cp_message_message_status_status_val_t)(tsi));
	message_status_status_id = mk_lib_iip_cp_message_message_status_status_val_to_message_status_status_id(message_status_status_val);
	*obj = message_status_status_id;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_enum_host_reply_result_code(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_host_reply_result_code_id_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_bool_t is_known mk_lang_constexpr_init;
	mk_lib_iip_cp_message_host_reply_result_code_val_t host_reply_result_code_val mk_lang_constexpr_init;
	mk_lib_iip_cp_message_host_reply_result_code_id_t host_reply_result_code_id mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_s8(ptr, rem, error_code, &tlen, &tsi); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	is_known = mk_lib_iip_cp_message_host_reply_result_code_val_is_known(tsi);
	if(!is_known)
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_unknown_host_reply_result_code;
		return 0;
	}
	host_reply_result_code_val = ((mk_lib_iip_cp_message_host_reply_result_code_val_t)(tsi));
	host_reply_result_code_id = mk_lib_iip_cp_message_host_reply_result_code_val_to_host_reply_result_code_id(host_reply_result_code_val);
	*obj = host_reply_result_code_id;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_sessionid(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_sessionid_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u16(ptr, rem, error_code, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_messageid(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_messageid_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_tunnelid(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_tunnelid_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_requestid(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_requestid_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_nonce(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_nonce_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_date(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_date_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u64(ptr, rem, error_code, &tlen, &obj->m_elements[0].m_elements[0]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_strbuf(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_string_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	mk_lang_assert(obj->m_len >= 0x00);
	mk_lang_assert(obj->m_len <= 0xff);
	tlen = obj->m_len;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_not_enough_data;
		return 0;
	}
	mk_sl_cui_uint8_to_bi_pchar_many(ptr, &obj->m_buf[0], ((mk_lang_types_usize_t)(tlen)));
	obj->m_buf[tlen] = '\0';
	ptr += tlen;
	rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_string(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_string_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_s8    (ptr, rem, error_code, &tlen, &obj->m_len); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_strbuf(ptr, rem, error_code, &tlen, obj        ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_opt_string(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_string_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	if(rem != 0)
	{
		err = mk_lib_iip_cp_message_parse_type_string(ptr, rem, error_code, &tlen, obj); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}
	else
	{
		obj->m_len = 0;
		obj->m_buf[0] = '\0';
	}

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_str_pair(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_strpair_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_parse_type_string(ptr, rem, error_code, &tlen, &obj->m_key); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_char       (ptr, rem, error_code, &tlen, '='        ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_string(ptr, rem, error_code, &tlen, &obj->m_val); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_char       (ptr, rem, error_code, &tlen, ';'        ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_str_pairs(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_strpairs_pt const obj, mk_lang_types_sint_t const mapping_len) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t rrr mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);
	mk_lang_assert(mapping_len >= 0);

	ptr = data_buf;
	rem = data_len;
	if(!(mapping_len <= rem))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_too_big_mapping;
		return 0;
	}
	rrr = mapping_len;
	obj->m_size = 0;
	while(rrr != 0)
	{
		err = mk_lib_iip_cp_message_parse_type_str_pair(ptr, rrr, error_code, &tlen, &obj->m_arr[obj->m_size]); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
		mk_lang_assert(tlen <= rrr); rrr -= tlen;
		++obj->m_size;
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_mapping(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_mapping_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t mapping_len mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_s16           (ptr, rem, error_code, &tlen, &mapping_len                 ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_str_pairs(ptr, rem, error_code, &tlen, &obj->m_strpairs, mapping_len); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_buf_buf(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_buffer_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	mk_lang_assert(obj->m_len >= 0);
	if(!(obj->m_len <= mk_lang_countof(obj->m_buf)))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_too_much_data;
		return 0;
	}
	err = mk_lib_iip_cp_message_parse_u8s(ptr, rem, error_code, &tlen, &obj->m_buf[0], obj->m_len); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_buffer(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_buffer_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_sint   (ptr, rem, error_code, &tlen, &obj->m_len); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_buf_buf(ptr, rem, error_code, &tlen, obj        ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_rem_buffer(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_buffer_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	tlen = rem;
	if(!(rem >= tlen))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_not_enough_data;
		return 0;
	}
	if(!(tlen <= mk_lang_countof(obj->m_buf)))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_too_much_data;
		return 0;
	}
	mk_sl_cui_uint8_memcpy_fn(&obj->m_buf[0], ptr, ((mk_lang_types_usize_t)(tlen)));
	obj->m_len = tlen;
	ptr += tlen;
	rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_hash(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_hash_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u8s(ptr, rem, error_code, &tlen, &obj->m_digest.m_data.m_uint8s[0], mk_lang_countof(obj->m_digest.m_data.m_uint8s)); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_hash_and_tunnelid(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_hash_and_tunnelid_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_hash    (ptr, rem, error_code, &tlen, &obj->m_router_hash); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_tunnelid(ptr, rem, error_code, &tlen, &obj->m_tunnel_id  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_hash_and_tunnelids(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_hash_and_tunnelids_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t count mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_iip_cp_types_hash_and_tunnelid_pt hash_and_tunnelid mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_s8(ptr, rem, error_code, &tlen, &count); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_lang_assert(count >= 0);
	if(!(((mk_lang_types_usize_t)(count)) <= mk_lib_iip_cp_types_hash_and_tunnelids_capacity_v))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_too_many_tunnels;
		return 0;
	}
	err = mk_lib_iip_cp_types_hash_and_tunnelids_rw_resize_to(obj, ((mk_lang_types_usize_t)(count))); mk_lang_check_rereturn(err);
	n = count;
	for(i = 0; i != n; ++i)
	{
		hash_and_tunnelid = mk_lib_iip_cp_types_hash_and_tunnelids_rw_at(obj, ((mk_lang_types_usize_t)(i))); mk_lang_assert(hash_and_tunnelid);
		err = mk_lib_iip_cp_message_parse_type_hash_and_tunnelid(ptr, rem, error_code, &tlen, hash_and_tunnelid); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_lease(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_lease_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_hash    (ptr, rem, error_code, &tlen, &obj->m_router_hash); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_tunnelid(ptr, rem, error_code, &tlen, &obj->m_tunnel_id  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_date    (ptr, rem, error_code, &tlen, &obj->m_end_date   ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_type_leases(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_types_leases_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t count mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lib_iip_cp_types_lease_pt lease mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_s8(ptr, rem, error_code, &tlen, &count); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	mk_lang_assert(count >= 0);
	if(!(((mk_lang_types_usize_t)(count)) <= mk_lib_iip_cp_types_hash_and_tunnelids_capacity_v))
	{
		*error_code = mk_lib_iip_cp_message_parse_error_code_e_too_many_leases;
		return 0;
	}
	err = mk_lib_iip_cp_types_leases_rw_construct_void(obj); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_types_leases_rw_resize_to(obj, ((mk_lang_types_usize_t)(count))); mk_lang_check_rereturn(err);
	n = count;
	for(i = 0; i != n; ++i)
	{
		lease = mk_lib_iip_cp_types_leases_rw_at(obj, ((mk_lang_types_usize_t)(i))); mk_lang_assert(lease);
		err = mk_lib_iip_cp_message_parse_lease(ptr, rem, error_code, &tlen, lease); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_header(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_header_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_sint             (ptr, rem, error_code, &tlen, &obj->m_len ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_enum_message_type(ptr, rem, error_code, &tlen, &obj->m_type); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_create_session(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_create_session_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_reconfigure_session(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_reconfigure_session_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_destroy_session(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_destroy_session_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_create_lease_set(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_create_lease_set_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_send_message(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_send_message_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_receive_message_begin(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_receive_message_begin_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_receive_message_end(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_receive_message_end_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_get_bandwidth_limits(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_get_bandwidth_limits_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_session_status(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_session_status_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_sessionid            (ptr, rem, error_code, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_enum_session_status_status(ptr, rem, error_code, &tlen, &obj->m_status    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_request_lease_set(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_request_lease_set_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_sessionid         (ptr, rem, error_code, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_hash_and_tunnelids(ptr, rem, error_code, &tlen, &obj->m_tunnels   ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_date              (ptr, rem, error_code, &tlen, &obj->m_end_date  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_message_status(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_message_status_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_sessionid            (ptr, rem, error_code, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_messageid            (ptr, rem, error_code, &tlen, &obj->m_message_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_enum_message_status_status(ptr, rem, error_code, &tlen, &obj->m_status    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_sint                      (ptr, rem, error_code, &tlen, &obj->m_size      ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_nonce                (ptr, rem, error_code, &tlen, &obj->m_nonce     ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_bandwidth_limits(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_bandwidth_limits_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_client_inbound_limit_kbps       ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_client_outbound_limit_kbps      ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_router_inbound_limit_kbps       ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_router_inbound_burst_limit_kbps ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_router_outbound_limit_kbps      ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_router_outbound_burst_limit_kbps); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_router_burst_time_seconds       ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_1                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_2                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_3                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_4                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_5                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_6                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_7                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_8                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_u32(ptr, rem, error_code, &tlen, &obj->m_bandwidth_limits.m_future_use_9                    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_report_abuse(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_report_abuse_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_disconnect(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_disconnect_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_string(ptr, rem, error_code, &tlen, &obj->m_reason); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_message_payload(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_message_payload_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_sessionid (ptr, rem, error_code, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_messageid (ptr, rem, error_code, &tlen, &obj->m_message_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_buffer    (ptr, rem, error_code, &tlen, &obj->m_payload   ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_get_date(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_get_date_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_string (ptr, rem, error_code, &tlen, &obj->m_api_version   ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_mapping(ptr, rem, error_code, &tlen, &obj->m_authentication); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_set_date(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_set_date_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_date      (ptr, rem, error_code, &tlen, &obj->m_server_date   ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_opt_string(ptr, rem, error_code, &tlen, &obj->m_server_version); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_dest_lookup(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_dest_lookup_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_dest_reply(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_dest_reply_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_send_message_expires(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_send_message_expires_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_request_variable_lease_set(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_request_variable_lease_set_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_sessionid(ptr, rem, error_code, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_leases   (ptr, rem, error_code, &tlen, &obj->m_leases    ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_host_lookup(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_host_lookup_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_host_reply(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_host_reply_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	err = mk_lib_iip_cp_message_parse_type_sessionid             (ptr, rem, error_code, &tlen, &obj->m_session_id ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_type_requestid             (ptr, rem, error_code, &tlen, &obj->m_request_id ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_enum_host_reply_result_code(ptr, rem, error_code, &tlen, &obj->m_result_code); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	if(obj->m_result_code == mk_lib_iip_cp_message_host_reply_result_code_id_e_success)
	{
		err = mk_lib_iip_cp_message_parse_type_rem_buffer(ptr, rem, error_code, &tlen, &obj->m_destination); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	}
	else
	{
		obj->m_destination.m_len = 0;
	}

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_create_lease_set2(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_create_lease_set2_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_msg_blinding_info(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_blinding_info_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_check_todo();
	}
	((mk_lang_types_void_t)(ptr));
	((mk_lang_types_void_t)(rem));

	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_parse_mix(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_header_pct const header, mk_lib_iip_cp_message_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(header);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_reconstruct(obj, header->m_type); mk_lang_check_rereturn(err); obj->m_header = *header;
	switch(obj->m_header.m_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : err = mk_lib_iip_cp_message_parse_msg_create_session            (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_create_session            ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : err = mk_lib_iip_cp_message_parse_msg_reconfigure_session       (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_reconfigure_session       ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : err = mk_lib_iip_cp_message_parse_msg_destroy_session           (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_destroy_session           ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : err = mk_lib_iip_cp_message_parse_msg_create_lease_set          (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_create_lease_set          ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : err = mk_lib_iip_cp_message_parse_msg_send_message              (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_send_message              ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : err = mk_lib_iip_cp_message_parse_msg_receive_message_begin     (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_receive_message_begin     ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : err = mk_lib_iip_cp_message_parse_msg_receive_message_end       (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_receive_message_end       ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : err = mk_lib_iip_cp_message_parse_msg_get_bandwidth_limits      (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_get_bandwidth_limits      ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : err = mk_lib_iip_cp_message_parse_msg_session_status            (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_session_status            ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : err = mk_lib_iip_cp_message_parse_msg_request_lease_set         (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_request_lease_set         ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : err = mk_lib_iip_cp_message_parse_msg_message_status            (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_message_status            ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : err = mk_lib_iip_cp_message_parse_msg_bandwidth_limits          (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_bandwidth_limits          ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : err = mk_lib_iip_cp_message_parse_msg_report_abuse              (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_report_abuse              ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : err = mk_lib_iip_cp_message_parse_msg_disconnect                (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_disconnect                ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : err = mk_lib_iip_cp_message_parse_msg_message_payload           (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_message_payload           ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : err = mk_lib_iip_cp_message_parse_msg_get_date                  (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_get_date                  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : err = mk_lib_iip_cp_message_parse_msg_set_date                  (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_set_date                  ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : err = mk_lib_iip_cp_message_parse_msg_dest_lookup               (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_dest_lookup               ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : err = mk_lib_iip_cp_message_parse_msg_dest_reply                (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_dest_reply                ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : err = mk_lib_iip_cp_message_parse_msg_send_message_expires      (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_send_message_expires      ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: err = mk_lib_iip_cp_message_parse_msg_request_variable_lease_set(ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_request_variable_lease_set); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : err = mk_lib_iip_cp_message_parse_msg_host_lookup               (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_host_lookup               ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : err = mk_lib_iip_cp_message_parse_msg_host_reply                (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_host_reply                ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : err = mk_lib_iip_cp_message_parse_msg_create_lease_set2         (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_create_lease_set2         ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : err = mk_lib_iip_cp_message_parse_msg_blinding_info             (ptr, rem, error_code, &tlen, &obj->m_mix.m_data.m_blinding_info             ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen; break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_parse_message(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lib_iip_cp_message_header_t header mk_lang_constexpr_init;

	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(error_code);
	mk_lang_assert(*error_code == mk_lib_iip_cp_message_parse_error_code_e_ok);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = data_buf;
	rem = data_len;
	err = mk_lib_iip_cp_message_parse_header(ptr, rem, error_code, &tlen, &header     ); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	err = mk_lib_iip_cp_message_parse_mix   (ptr, rem, error_code, &tlen, &header, obj); mk_lang_check_rereturn(err); if(*error_code != mk_lib_iip_cp_message_parse_error_code_e_ok){ return 0; } mk_lang_assert(tlen >= 0); mk_lang_assert(tlen <= rem); ptr += tlen; rem -= tlen;
	tlen = data_len - rem;
	*consumed = tlen;
	return 0;
}


#endif
