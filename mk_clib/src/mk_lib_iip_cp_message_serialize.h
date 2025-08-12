#ifndef mk_include_guard_mk_lib_iip_cp_message_serialize_h
#define mk_include_guard_mk_lib_iip_cp_message_serialize_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_lib_iip_cp_message);
mk_lang_forward(mk_sl_cui_uint8);


enum mk_lib_iip_cp_message_serialize_error_code_e
{
	mk_lib_iip_cp_message_serialize_error_code_e_ok,
	mk_lib_iip_cp_message_serialize_error_code_e_not_enough_free_space,
	mk_lib_iip_cp_message_serialize_error_code_e_other,
	mk_lib_iip_cp_message_serialize_error_code_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_serialize_error_code_e mk_lib_iip_cp_message_serialize_error_code_t;
mk_lang_typedef(mk_lib_iip_cp_message_serialize_error_code);


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_serialize_message(mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lib_iip_cp_message_serialize_error_code_pt const error_code, mk_lang_types_sint_pt const consumed, mk_lib_iip_cp_message_pt const obj) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_message_serialize.c"
#endif
#endif
