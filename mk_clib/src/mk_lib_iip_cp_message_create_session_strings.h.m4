include(`mk_lib_iip_cp_message_create_session_strings.m')dnl
dnl
dnl
#ifndef mk_include_guard_mk_lib_iip_cp_message_create_session_strings_h
#define mk_include_guard_mk_lib_iip_cp_message_create_session_strings_h



#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


enum mk_lib_iip_cp_message_create_session_strings_id_e
{
mk_lib_iip_cp_message_create_session_strings_per_string(`', `	mk_lib_iip_cp_message_create_session_strings_id_e_$1,', `')dnl
	mk_lib_iip_cp_message_create_session_strings_id_e_dummy_end
};
typedef enum mk_lib_iip_cp_message_create_session_strings_id_e mk_lib_iip_cp_message_create_session_strings_id_t;
mk_lang_typedef(mk_lib_iip_cp_message_create_session_strings_id);


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_pchar_pct mk_lib_iip_cp_message_create_session_strings_get_str_buf(mk_lib_iip_cp_message_create_session_strings_id_t const id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_create_session_strings_get_str_len(mk_lib_iip_cp_message_create_session_strings_id_t const id) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_cp_message_create_session_strings.c"
#endif
#endif
