include(`mk_lib_iip_cp_message_create_session_strings.m')dnl
dnl
dnl
#ifndef mk_include_guard_mk_lib_iip_cp_message_create_session_strings_c
#define mk_include_guard_mk_lib_iip_cp_message_create_session_strings_c
#include "mk_lib_iip_cp_message_create_session_strings.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


mk_lib_iip_cp_message_create_session_strings_per_string(`', `#define mk_lib_iip_cp_message_create_session_strings_def_$1 "$2"', `')dnl

#define mk_lib_iip_cp_message_create_session_strings_defs \
mk_lib_iip_cp_message_create_session_strings_per_string(`', `	mk_lib_iip_cp_message_create_session_strings_def_$1 \', `')dnl
""

mk_lib_iip_cp_message_create_session_strings_per_string(`', `#define mk_lib_iip_cp_message_create_session_strings_len_$1 (mk_lang_countstr(mk_lib_iip_cp_message_create_session_strings_def_$1))', `')dnl

mk_lib_iip_cp_message_create_session_strings_per_string(`#define mk_lib_iip_cp_message_create_session_strings_off_$1 (0)', `#define mk_lib_iip_cp_message_create_session_strings_off_$1 ((mk_lib_iip_cp_message_create_session_strings_off_$3) + (mk_lib_iip_cp_message_create_session_strings_len_$3))', `')dnl

#define mk_lib_iip_cp_message_create_session_strings_offs \
{ \
mk_lib_iip_cp_message_create_session_strings_per_string(` \', `	mk_lib_iip_cp_message_create_session_strings_off_$1, \', `	mk_lib_iip_cp_message_create_session_strings_off_$1, \
	(mk_lib_iip_cp_message_create_session_strings_off_$1 + mk_lib_iip_cp_message_create_session_strings_len_$1) \')dnl
}


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_cp_message_create_session_strings_k_buf[] = mk_lib_iip_cp_message_create_session_strings_defs;
mk_lang_constexpr_static_inline mk_lang_types_ushort_t const mk_lib_iip_cp_message_create_session_strings_k_off[] = mk_lib_iip_cp_message_create_session_strings_offs;


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_message_create_session_strings_get_str_off(mk_lib_iip_cp_message_create_session_strings_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t off mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(mk_lib_iip_cp_message_create_session_strings_k_off) == mk_lib_iip_cp_message_create_session_strings_id_e_dummy_end);

	mk_lang_assert(id >= 0);
	mk_lang_assert(id <= mk_lib_iip_cp_message_create_session_strings_id_e_dummy_end);

	if(id == 0)
	{
		off = 0;
	}
	else
	{
		off = mk_lib_iip_cp_message_create_session_strings_k_off[id - 1];
	}
	mk_lang_assert(off >= 0);
	mk_lang_assert(off <= mk_lang_countstr(mk_lib_iip_cp_message_create_session_strings_k_buf));
	return off;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_pchar_pct mk_lib_iip_cp_message_create_session_strings_get_str_buf(mk_lib_iip_cp_message_create_session_strings_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t off mk_lang_constexpr_init;
	mk_lang_types_pchar_pct buf mk_lang_constexpr_init;

	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_iip_cp_message_create_session_strings_id_e_dummy_end);

	off = mk_lib_iip_cp_message_create_session_strings_get_str_off(id);
	buf = &mk_lib_iip_cp_message_create_session_strings_k_buf[off];
	mk_lang_assert(buf);
	mk_lang_assert(buf[0] != '\0');
	return buf;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_create_session_strings_get_str_len(mk_lib_iip_cp_message_create_session_strings_id_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t off_a mk_lang_constexpr_init;
	mk_lang_types_sint_t off_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_iip_cp_message_create_session_strings_id_e_dummy_end);

	off_a = mk_lib_iip_cp_message_create_session_strings_get_str_off(((mk_lib_iip_cp_message_create_session_strings_id_t)(id + 0)));
	off_b = mk_lib_iip_cp_message_create_session_strings_get_str_off(((mk_lib_iip_cp_message_create_session_strings_id_t)(id + 1)));
	mk_lang_assert(off_a < off_b);
	len = off_b - off_a;
	mk_lang_assert(len >= 1);
	mk_lang_assert(len <= mk_lang_countstr(mk_lib_iip_cp_message_create_session_strings_k_buf));
	return len;
}


#endif
