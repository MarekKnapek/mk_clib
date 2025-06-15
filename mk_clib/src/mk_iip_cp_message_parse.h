#ifndef mk_include_guard_mk_iip_cp_message_parse_h
#define mk_include_guard_mk_iip_cp_message_parse_h


#include "mk_iip_cp_message.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


enum mk_iip_cp_message_parse_errcode_e
{
	mk_iip_cp_message_parse_errcode_e_ok,
	mk_iip_cp_message_parse_errcode_e_not_enough_data,
	mk_iip_cp_message_parse_errcode_e_too_much_data,
	mk_iip_cp_message_parse_errcode_e_wrong_length,
	mk_iip_cp_message_parse_errcode_e_unknown_message_type,
	mk_iip_cp_message_parse_errcode_e_unknown_host_reply_result_code,
	mk_iip_cp_message_parse_errcode_e_unknown_session_status_status,
	mk_iip_cp_message_parse_errcode_e_dummy_end
};
typedef enum mk_iip_cp_message_parse_errcode_e mk_iip_cp_message_parse_errcode_t;
typedef mk_iip_cp_message_parse_errcode_t* mk_iip_cp_message_parse_errcode_pt;
typedef mk_iip_cp_message_parse_errcode_t const* mk_iip_cp_message_parse_errcode_pct;


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_parse_message(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_pt const obj) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_message_parse.c"
#endif
#endif
