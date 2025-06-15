#ifndef mk_include_guard_mk_iip_cp_message_tostr_h
#define mk_include_guard_mk_iip_cp_message_tostr_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"


mk_lang_struct_forward(mk_iip_cp_message);
enum mk_iip_cp_message_parse_errcode_e; typedef enum mk_iip_cp_message_parse_errcode_e mk_iip_cp_message_parse_errcode_t; mk_lang_struct_typedef(mk_iip_cp_message_parse_errcode);
enum mk_iip_cp_message_serialize_errcode_e; typedef enum mk_iip_cp_message_serialize_errcode_e mk_iip_cp_message_serialize_errcode_t; mk_lang_struct_typedef(mk_iip_cp_message_serialize_errcode);


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_tostr_message_post_serialize_a(mk_lang_types_pchar_pt const strbuf, mk_lang_types_sint_t const strlen, mk_lang_types_sint_pt const outlen, mk_iip_cp_message_serialize_errcode_pct const errcode, mk_lang_types_sint_pct const consumed, mk_iip_cp_message_pct const message) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_tostr_message_post_serialize_b(mk_lang_types_pchar_pt const strbuf, mk_lang_types_sint_t const strlen, mk_lang_types_sint_pt const outlen, mk_iip_cp_message_serialize_errcode_pct const errcode, mk_lang_types_sint_pct const consumed, mk_iip_cp_message_pct const message) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_tostr_message_post_parse_a(mk_lang_types_pchar_pt const strbuf, mk_lang_types_sint_t const strlen, mk_lang_types_sint_pt const outlen, mk_iip_cp_message_parse_errcode_pct const errcode, mk_lang_types_sint_pct const consumed, mk_iip_cp_message_pct const message) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_message_tostr_message_post_parse_b(mk_lang_types_pchar_pt const strbuf, mk_lang_types_sint_t const strlen, mk_lang_types_sint_pt const outlen, mk_iip_cp_message_parse_errcode_pct const errcode, mk_lang_types_sint_pct const consumed, mk_iip_cp_message_pct const message) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_message_tostr.c"
#endif
#endif
