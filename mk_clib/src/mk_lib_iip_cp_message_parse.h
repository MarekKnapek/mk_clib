#ifndef mk_include_guard_mk_lib_iip_cp_message_parse_h
#define mk_include_guard_mk_lib_iip_cp_message_parse_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


mk_lang_forward(mk_lib_iip_cp_message);


enum mk_lib_iip_cp_message_parse_error_code_e
{
	mk_lib_iip_cp_message_parse_error_code_e_ok,
	mk_lib_iip_cp_message_parse_error_code_e_not_enough_data,
	mk_lib_iip_cp_message_parse_error_code_e_too_much_data,
	mk_lib_iip_cp_message_parse_error_code_e_unknown_message_type,
	mk_lib_iip_cp_message_parse_error_code_e_unknown_session_status_status,
	mk_lib_iip_cp_message_parse_error_code_e_unknown_message_status_status,
	mk_lib_iip_cp_message_parse_error_code_e_too_many_tunnels,
	mk_lib_iip_cp_message_parse_error_code_e_too_many_leases,

	mk_lib_iip_cp_message_parse_error_code_e_wrong_length,
	mk_lib_iip_cp_message_parse_error_code_e_unknown_host_reply_result_code,
	mk_lib_iip_cp_message_parse_error_code_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_parse_error_code_e mk_lib_iip_cp_message_parse_error_code_t;
mk_lang_typedef(mk_lib_iip_cp_message_parse_error_code);


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_parse_message(mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_parse_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_pt const obj) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_message_parse.c"
#endif
#endif
