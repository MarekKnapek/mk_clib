#ifndef mk_include_guard_mk_lib_iip_cp_message_str_h
#define mk_include_guard_mk_lib_iip_cp_message_str_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_lib_iip_cp_message);


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_str_to_json_message(mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len, mk_lib_iip_cp_message_pct const obj) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_message_str.c"
#endif
#endif
