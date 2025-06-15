#ifndef mk_include_guard_mk_iip_cp_message_serialize_h
#define mk_include_guard_mk_iip_cp_message_serialize_h


#include "mk_iip_cp_message.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


enum mk_iip_cp_message_serialize_errcode_e
{
	mk_iip_cp_message_serialize_errcode_e_ok,
	mk_iip_cp_message_serialize_errcode_e_not_enough_space,
	mk_iip_cp_message_serialize_errcode_e_dummy_end
};
typedef enum mk_iip_cp_message_serialize_errcode_e mk_iip_cp_message_serialize_errcode_t;
typedef mk_iip_cp_message_serialize_errcode_t* mk_iip_cp_message_serialize_errcode_pt;
typedef mk_iip_cp_message_serialize_errcode_t const* mk_iip_cp_message_serialize_errcode_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_serialize_message(mk_sl_cui_uint8_pt const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pt const errcode, mk_lang_types_sint_pt const consumed, mk_iip_cp_message_pct const obj) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_message_serialize.c"
#endif
#endif
