#ifndef mk_include_guard_mk_lang_check_c
#define mk_include_guard_mk_lang_check_c
#include "mk_lang_check.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lang_check_to_bool_impl(mk_lang_types_bool_t const b) mk_lang_noexcept
{
	return b;
}

#if mk_lang_check_debug_have
#include "mk_lang_assert.h"
#include "mk_lang_stdout.h"
mk_lang_jumbo mk_lang_types_void_t mk_lang_check_print_impl(mk_lang_types_pchar_pct const msg_buf, mk_lang_types_sint_t const msg_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(msg_buf || msg_len == 0);
	mk_lang_assert(msg_len >= 0);

	err = mk_lang_stdout_print_n(msg_buf, msg_len); ((mk_lang_types_void_t)(err));
}
#endif


#endif
