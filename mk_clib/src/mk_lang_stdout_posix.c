#ifndef mk_include_guard_mk_lang_stdout_posix_c
#define mk_include_guard_mk_lang_stdout_posix_c
#include "mk_lang_stdout_posix.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_posix_at_least_any

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


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t fd;
	ssize_t written;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	fd = 0;
	written = write(fd, str_buf, str_len); mk_lang_check_return(written == str_len);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	mk_lang_assert(mk_lang_false);
	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_tchar_dispatch(mk_lang_stdout_posix_print_)(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_print_n(str_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_posix_print_lit_n("\n"); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	mk_lang_assert(mk_lang_false);
	mk_lang_check_return(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_tchar_dispatch(mk_lang_stdout_posix_println_)(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_print_n(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_print_w(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_gcc_push_type_limits.h"
	#include "mk_lang_warning_clang_push_tautological_value_range_compare.h"
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	#include "mk_lang_warning_clang_pop.h"
	#include "mk_lang_warning_gcc_pop.h"

	err = mk_lang_stdout_posix_print_t(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_println_n(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_println_w(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_println_t(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_print_color_n(mk_lang_stdout_posix_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_posix_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_print_color_n(color, str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_print_color_w(mk_lang_stdout_posix_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_posix_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_print_color_w(color, str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_print_color_t(mk_lang_stdout_posix_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_posix_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_print_color_t(color, str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_println_color_n(mk_lang_stdout_posix_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_posix_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_println_color_n(color, str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_println_color_w(mk_lang_stdout_posix_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_posix_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_println_color_w(color, str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_no_redirect_println_color_t(mk_lang_stdout_posix_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_posix_color_text_e_dummy_end);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_stdout_posix_println_color_t(color, str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}


#endif
#endif
