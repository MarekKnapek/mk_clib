#ifndef mk_include_guard_mk_lang_stdout_linux_c
#define mk_include_guard_mk_lang_stdout_linux_c
#include "mk_lang_stdout_linux.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_linux

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"

#include <unistd.h> /* write */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linux_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linux_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t fd;
	ssize_t written;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	fd = 0;
	written = write(fd, str_buf, str_len); mk_lang_check_return(written == str_len);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linux_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	mk_lang_assert(mk_lang_false);
	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linux_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_tchar_dispatch(mk_lang_stdout_linux_print_)(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linux_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_linux_print_n(str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_linux_print_lit_n("\n"); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linux_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	mk_lang_assert(mk_lang_false);
	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linux_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_tchar_dispatch(mk_lang_stdout_linux_println_)(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}


#endif
#endif
