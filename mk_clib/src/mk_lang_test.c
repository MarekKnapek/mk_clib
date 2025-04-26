#ifndef mk_include_guard_mk_lang_test_c
#define mk_include_guard_mk_lang_test_c
#include "mk_lang_test.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stdout.h"
#include "mk_lang_types.h"


#if mk_lang_test_detail_have


mk_lang_jumbo mk_lang_types_void_t mk_lang_test_detail_impl(mk_lang_types_pchar_pct const msg_buf, mk_lang_types_sint_t const msg_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(msg_buf);
	mk_lang_assert(msg_buf[0] != '\0');
	mk_lang_assert(msg_len >= 1);

	err = mk_lang_stdout_println_n(msg_buf, msg_len); mk_lang_check_recrash(err);
}


#endif


#endif
