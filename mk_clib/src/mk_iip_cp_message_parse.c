#ifndef mk_include_guard_mk_iip_cp_message_parse_c
#define mk_include_guard_mk_iip_cp_message_parse_c
#include "mk_iip_cp_message_parse.h"

#include "mk_iip_cp_base.h"
#include "mk_iip_cp_helper.h"
#include "mk_iip_cp_message.h"
#include "mk_iip_cp_type.h"
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
#include "mk_sl_uint.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint64.h"
#include "mk_sl_uint8.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_u8s(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint8_pt const objbuf, mk_lang_types_sint_t const objlen) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(objbuf || objlen == 0);
	mk_lang_assert(objlen >= 0);

	ptr = buf;
	rem = len;

	tlen = objlen * mk_sl_cui_uint8_sizebytes_v;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_parse_errcode_e_not_enough_data;
		return 0;
	}
	mk_iip_cp_helper_memcpy_u8_fn(objbuf, ptr, objlen);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_u8(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint8_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

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
		*errcode = mk_iip_cp_message_parse_errcode_e_not_enough_data;
		return 0;
	}
	*obj = ptr[0];
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_u16(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint16_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

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
		*errcode = mk_iip_cp_message_parse_errcode_e_not_enough_data;
		return 0;
	}
	mk_sl_uint_16_from_8_be(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_u32(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint32_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

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
		*errcode = mk_iip_cp_message_parse_errcode_e_not_enough_data;
		return 0;
	}
	mk_sl_uint_32_from_8_be(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_u64(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_sl_cui_uint64_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

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
		*errcode = mk_iip_cp_message_parse_errcode_e_not_enough_data;
		return 0;
	}
	mk_sl_uint_64_from_8_be(obj, &ptr[0]);
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_s8(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_sl_cui_uint8_t tu8 mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_u8(ptr, rem, errcode, &tlen, &tu8); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	mk_sl_cui_uint8_to_bi_sint(&tu8, obj);

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_s32(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_lang_types_sint_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tu32 mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &tu32); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	mk_sl_cui_uint32_to_bi_ulong(&tu32, &tul);
	if(tul >= 128ul * 1024ul)
	{
		*errcode = mk_iip_cp_message_parse_errcode_e_wrong_length;
		return 0;
	}
	*obj = ((mk_lang_types_sint_t)(tul));

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_message_type(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_message_type_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_s8(ptr, rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	switch(tsi)
	{
		case mk_iip_cp_message_message_type_e_create_session            : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_reconfigure_session       : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_destroy_session           : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_create_lease_set          : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_send_message              : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_receive_message_begin     : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_receive_message_end       : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_get_bandwidth_limits      : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_session_status            : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_request_lease_set         : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_message_status            : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_bandwidth_limits          : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_report_abuse              : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_disconnect                : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_message_payload           : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_get_date                  : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_set_date                  : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_dest_lookup               : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_dest_reply                : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_send_message_expires      : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_request_variable_lease_set: gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_host_lookup               : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_host_reply                : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_create_lease_set2         : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_type_e_blinding_info             : gud = mk_lang_true; break;
		default: gud = mk_lang_false; break;
	}
	if(!gud)
	{
		*errcode = mk_iip_cp_message_parse_errcode_e_unknown_message_type;
		return 0;
	}
	*obj = ((mk_iip_cp_message_message_type_t)(tsi));

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_session_status_status(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_session_status_status_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_s8(ptr, rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	switch(tsi)
	{
		case mk_iip_cp_message_session_status_status_e_destroyed: gud = mk_lang_true; break;
		case mk_iip_cp_message_session_status_status_e_created  : gud = mk_lang_true; break;
		case mk_iip_cp_message_session_status_status_e_updated  : gud = mk_lang_true; break;
		case mk_iip_cp_message_session_status_status_e_invalid  : gud = mk_lang_true; break;
		case mk_iip_cp_message_session_status_status_e_refused  : gud = mk_lang_true; break;
		default: gud = mk_lang_false; break;
	}
	if(!gud)
	{
		*errcode = mk_iip_cp_message_parse_errcode_e_unknown_session_status_status;
		return 0;
	}
	*obj = ((mk_iip_cp_message_session_status_status_t)(tsi));

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_host_reply_result_code(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_host_reply_result_code_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_s8(ptr, rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	switch(tsi)
	{
		case mk_iip_cp_message_host_reply_result_code_e_success                                 : gud = mk_lang_true; break;
		case mk_iip_cp_message_host_reply_result_code_e_failure                                 : gud = mk_lang_true; break;
		case mk_iip_cp_message_host_reply_result_code_e_lookup_password_required                : gud = mk_lang_true; break;
		case mk_iip_cp_message_host_reply_result_code_e_private_key_required                    : gud = mk_lang_true; break;
		case mk_iip_cp_message_host_reply_result_code_e_lookup_password_and_private_key_required: gud = mk_lang_true; break;
		case mk_iip_cp_message_host_reply_result_code_e_leaseset_decryption_failure             : gud = mk_lang_true; break;
		default: gud = mk_lang_false; break;
	}
	if(!gud)
	{
		*errcode = mk_iip_cp_message_parse_errcode_e_unknown_host_reply_result_code;
		return 0;
	}
	*obj = ((mk_iip_cp_message_host_reply_result_code_t)(tsi));

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_message_status_status(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_message_status_status_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_s8(ptr, rem, errcode, &tlen, &tsi); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	switch(tsi)
	{
		case mk_iip_cp_message_message_status_status_e_available             : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_accepted              : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_best_effort_success   : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_best_effort_failure   : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_guaranteed_success    : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_guaranteed_failure    : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_local_success         : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_local_failure         : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_router_failure        : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_network_failure       : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_bad_session           : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_bad_message           : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_bad_options           : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_overflow_failure      : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_message_expired       : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_bad_local_leaseset    : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_no_local_tunnels      : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_unsupported_encryption: gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_bad_destination       : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_bad_leaseset          : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_expired_leaseset      : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_no_leaseset           : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_meta_leaseset         : gud = mk_lang_true; break;
		case mk_iip_cp_message_message_status_status_e_loopback_denied       : gud = mk_lang_true; break;
		default: gud = mk_lang_false; break;
	}
	if(!gud)
	{
		*errcode = mk_iip_cp_message_parse_errcode_e_unknown_host_reply_result_code;
		return 0;
	}
	*obj = ((mk_iip_cp_message_message_status_status_t)(tsi));

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_sessionid(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_sessionid_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_u16(ptr, rem, errcode, &tlen, &obj->m_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_messageid(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_messageid_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_tunnelid(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_tunnelid_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_date(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_date_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_u64(ptr, rem, errcode, &tlen, &obj->m_ms_since_unix); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_hash(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_hash_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_u8s(ptr, rem, errcode, &tlen, &obj->m_digest.m_uint8s[0], mk_lib_crypto_hash_block_sha2_256_digest_len); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_buffer_rem(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_buffer_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	tlen = rem;
	if(!(rem >= tlen))
	{
		*errcode = mk_iip_cp_message_parse_errcode_e_not_enough_data;
		return 0;
	}
	if(!(tlen <= mk_lang_countof(obj->m_buf)))
	{
		*errcode = mk_iip_cp_message_parse_errcode_e_too_much_data;
		return 0;
	}
	mk_iip_cp_helper_memcpy_u8_fn(&obj->m_buf[0], ptr, tlen);
	obj->m_len = tlen;
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_bufbuf(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_buffer_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_u8s(ptr, rem, errcode, &tlen, &obj->m_buf[0], obj->m_len); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_buffer_len(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_buffer_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_s32   (ptr, rem, errcode, &tlen, &obj->m_len); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_bufbuf(ptr, rem, errcode, &tlen, obj        ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_strbuf(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_string_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

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
		*errcode = mk_iip_cp_message_parse_errcode_e_not_enough_data;
		return 0;
	}
	mk_iip_cp_helper_u8s_to_pchars(ptr, &obj->m_buf[0], tlen);
	obj->m_buf[tlen] = '\0';
	ptr += tlen;
	rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_string(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_string_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_s8    (ptr, rem, errcode, &tlen, &obj->m_len); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_strbuf(ptr, rem, errcode, &tlen, obj        ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_optstring(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_string_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	if(rem != 0)
	{
		err = mk_iip_cp_message_parse_string(ptr, rem, errcode, &tlen, obj); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	}
	else
	{
		obj->m_len = 0;
		obj->m_buf[0] = '\0';
	}

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_hash_and_tunnelid(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_hash_and_tunnelid_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_hash    (ptr, rem, errcode, &tlen, &obj->m_router_hash); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_tunnelid(ptr, rem, errcode, &tlen, &obj->m_tunnel_id  ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_hash_and_tunnelids(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_hash_and_tunnelids_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t count mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_iip_cp_type_hash_and_tunnelid_pt element mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_s8(ptr, rem, errcode, &tlen, &count); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	mk_lang_assert(count >= 0);
	if(!(count <= mk_iip_cp_type_hash_and_tunnelids_len_v))
	{
		*errcode = mk_iip_cp_message_parse_errcode_e_wrong_length;
		return 0;
	}
	err = mk_iip_cp_type_hash_and_tunnelids_rw_setsize_dy(obj, count); mk_lang_check_rereturn(err);
	n = count;
	for(i = 0; i != n; ++i)
	{
		element = mk_iip_cp_type_hash_and_tunnelids_rw_at(obj, i); mk_lang_assert(element);
		err = mk_iip_cp_message_parse_hash_and_tunnelid(ptr, rem, errcode, &tlen, element); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	}

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_lease(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_lease_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_hash    (ptr, rem, errcode, &tlen, &obj->m_router_hash); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_tunnelid(ptr, rem, errcode, &tlen, &obj->m_tunnel_id  ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_date    (ptr, rem, errcode, &tlen, &obj->m_end_date   ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_leases(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_type_leases_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;
	mk_lang_types_sint_t count mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_iip_cp_type_lease_pt lease mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_s8(ptr, rem, errcode, &tlen, &count); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	mk_lang_assert(count >= 0);
	if(!(count <= mk_iip_cp_type_hash_and_tunnelids_len_v))
	{
		*errcode = mk_iip_cp_message_parse_errcode_e_wrong_length;
		return 0;
	}
	err = mk_iip_cp_type_leases_rw_construct(obj); mk_lang_check_rereturn(err);
	err = mk_iip_cp_type_leases_rw_setsize_dy(obj, count); mk_lang_check_rereturn(err);
	n = count;
	for(i = 0; i != n; ++i)
	{
		lease = mk_iip_cp_type_leases_rw_at(obj, i); mk_lang_assert(lease);
		err = mk_iip_cp_message_parse_lease(ptr, rem, errcode, &tlen, lease); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	}

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_create_session(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_create_session_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_reconfigure_session(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_reconfigure_session_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_destroy_session(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_destroy_session_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_create_lease_set(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_create_lease_set_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_send_message(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_send_message_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_receive_message_begin(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_receive_message_begin_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_receive_message_end(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_receive_message_end_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_get_bandwidth_limits(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_get_bandwidth_limits_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_session_status(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_session_status_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_sessionid            (ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_session_status_status(ptr, rem, errcode, &tlen, &obj->m_status    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_request_lease_set(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_request_lease_set_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_sessionid         (ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_hash_and_tunnelids(ptr, rem, errcode, &tlen, &obj->m_tunnels   ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_date              (ptr, rem, errcode, &tlen, &obj->m_end_date  ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_message_status(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_message_status_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_sessionid            (ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_messageid            (ptr, rem, errcode, &tlen, &obj->m_message_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_message_status_status(ptr, rem, errcode, &tlen, &obj->m_status    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_s32                  (ptr, rem, errcode, &tlen, &obj->m_size      ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32                  (ptr, rem, errcode, &tlen, &obj->m_nonce     ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_bandwidth_limits(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_bandwidth_limits_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_client_inbound_limit_kbps       ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_client_outbound_limit_kbps      ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_router_inbound_limit_kbps       ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_router_inbound_burst_limit_kbps ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_router_outbound_limit_kbps      ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_router_outbound_burst_limit_kbps); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_router_burst_time_seconds       ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_future_use_1                    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_future_use_2                    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_future_use_3                    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_future_use_4                    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_future_use_5                    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_future_use_6                    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_future_use_7                    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_future_use_8                    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32(ptr, rem, errcode, &tlen, &obj->m_bandwidth_limits.m_future_use_9                    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_report_abuse(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_report_abuse_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_disconnect(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_disconnect_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_string(ptr, rem, errcode, &tlen, &obj->m_reason); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_message_payload(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_message_payload_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_sessionid (ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_messageid (ptr, rem, errcode, &tlen, &obj->m_message_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_buffer_len(ptr, rem, errcode, &tlen, &obj->m_payload   ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_get_date(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_get_date_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_set_date(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_set_date_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_date     (ptr, rem, errcode, &tlen, &obj->m_server_date   ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_optstring(ptr, rem, errcode, &tlen, &obj->m_server_version); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_dest_lookup(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_dest_lookup_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_dest_reply(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_dest_reply_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_send_message_expires(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_send_message_expires_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_request_variable_lease_set(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_request_variable_lease_set_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_sessionid(ptr, rem, errcode, &tlen, &obj->m_session_id); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_leases   (ptr, rem, errcode, &tlen, &obj->m_leases    ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_host_lookup(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_host_lookup_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_host_reply(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_host_reply_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_sessionid             (ptr, rem, errcode, &tlen, &obj->m_session_id ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_u32                   (ptr, rem, errcode, &tlen, &obj->m_request_id ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_host_reply_result_code(ptr, rem, errcode, &tlen, &obj->m_result_code); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	if(obj->m_result_code == mk_iip_cp_message_host_reply_result_code_e_success)
	{
		err = mk_iip_cp_message_parse_buffer_rem(ptr, rem, errcode, &tlen, &obj->m_destination); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	}
	else
	{
		obj->m_destination.m_len = 0;
	}

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_create_lease_set2(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_create_lease_set2_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_msg_blinding_info(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_blinding_info_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	mk_lang_check_todo();

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_iip_cp_message_parse_header(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_header_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_s32         (ptr, rem, errcode, &tlen, &obj->m_len ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	err = mk_iip_cp_message_parse_message_type(ptr, rem, errcode, &tlen, &obj->m_type); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_parse_message(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_pt const obj) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;
	mk_lang_types_sint_t tlen mk_lang_constexpr_init;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(obj);

	ptr = buf;
	rem = len;

	err = mk_iip_cp_message_parse_header(ptr, rem, errcode, &tlen, &obj->m_header); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen;
	switch(obj->m_header.m_type)
	{
		case mk_iip_cp_message_message_type_e_create_session            : err = mk_iip_cp_message_parse_msg_create_session            (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_create_session            ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_reconfigure_session       : err = mk_iip_cp_message_parse_msg_reconfigure_session       (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_reconfigure_session       ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_destroy_session           : err = mk_iip_cp_message_parse_msg_destroy_session           (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_destroy_session           ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_create_lease_set          : err = mk_iip_cp_message_parse_msg_create_lease_set          (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_create_lease_set          ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_send_message              : err = mk_iip_cp_message_parse_msg_send_message              (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_send_message              ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_receive_message_begin     : err = mk_iip_cp_message_parse_msg_receive_message_begin     (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_receive_message_begin     ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_receive_message_end       : err = mk_iip_cp_message_parse_msg_receive_message_end       (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_receive_message_end       ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_get_bandwidth_limits      : err = mk_iip_cp_message_parse_msg_get_bandwidth_limits      (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_get_bandwidth_limits      ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_session_status            : err = mk_iip_cp_message_parse_msg_session_status            (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_session_status            ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_request_lease_set         : err = mk_iip_cp_message_parse_msg_request_lease_set         (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_request_lease_set         ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_message_status            : err = mk_iip_cp_message_parse_msg_message_status            (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_message_status            ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_bandwidth_limits          : err = mk_iip_cp_message_parse_msg_bandwidth_limits          (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_bandwidth_limits          ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_report_abuse              : err = mk_iip_cp_message_parse_msg_report_abuse              (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_report_abuse              ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_disconnect                : err = mk_iip_cp_message_parse_msg_disconnect                (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_disconnect                ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_message_payload           : err = mk_iip_cp_message_parse_msg_message_payload           (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_message_payload           ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_get_date                  : err = mk_iip_cp_message_parse_msg_get_date                  (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_get_date                  ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_set_date                  : err = mk_iip_cp_message_parse_msg_set_date                  (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_set_date                  ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_dest_lookup               : err = mk_iip_cp_message_parse_msg_dest_lookup               (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_dest_lookup               ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_dest_reply                : err = mk_iip_cp_message_parse_msg_dest_reply                (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_dest_reply                ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_send_message_expires      : err = mk_iip_cp_message_parse_msg_send_message_expires      (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_send_message_expires      ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_request_variable_lease_set: err = mk_iip_cp_message_parse_msg_request_variable_lease_set(ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_request_variable_lease_set); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_host_lookup               : err = mk_iip_cp_message_parse_msg_host_lookup               (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_host_lookup               ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_host_reply                : err = mk_iip_cp_message_parse_msg_host_reply                (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_host_reply                ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_create_lease_set2         : err = mk_iip_cp_message_parse_msg_create_lease_set2         (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_create_lease_set2         ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		case mk_iip_cp_message_message_type_e_blinding_info             : err = mk_iip_cp_message_parse_msg_blinding_info             (ptr, rem, errcode, &tlen, &obj->m_mix.m_data.m_blinding_info             ); mk_lang_check_rereturn(err); if(*errcode != mk_iip_cp_message_parse_errcode_e_ok){ return 0; } ptr += tlen; rem -= tlen; break;
		default: mk_lang_assert(mk_lang_false); break;
	}

	tlen = len - rem;
	*errcode = mk_iip_cp_message_parse_errcode_e_ok;
	*consumed = tlen;
	return 0;
}


#endif
