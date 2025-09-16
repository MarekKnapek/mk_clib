#ifndef mk_include_guard_mk_lang_stdout_portable_c
#define mk_include_guard_mk_lang_stdout_portable_c
#include "mk_lang_stdout_portable.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <stdio.h> /* printf */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t len;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	len = printf("%.*s", str_len, str_buf); mk_lang_check_return(len == str_len);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t len;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	len = printf("%.*ls", str_len, str_buf); mk_lang_check_return(len == str_len);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_tchar_dispatch(mk_lang_stdout_portable_print_)(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t len;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	len = printf("%.*s\n", str_len, str_buf); mk_lang_check_return(len >= str_len + 1);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t len;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	len = printf("%.*ls\n", str_len, str_buf); mk_lang_check_return(len >= str_len + 1);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	err = mk_lang_tchar_dispatch(mk_lang_stdout_portable_println_)(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_print_color_n(mk_lang_stdout_portable_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_portable_color_text_e_dummy_end);

	((mk_lang_types_void_t)(color));
	err = mk_lang_stdout_portable_print_n(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_print_color_w(mk_lang_stdout_portable_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_portable_color_text_e_dummy_end);

	((mk_lang_types_void_t)(color));
	err = mk_lang_stdout_portable_print_w(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_print_color_t(mk_lang_stdout_portable_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_portable_color_text_e_dummy_end);

	((mk_lang_types_void_t)(color));
	err = mk_lang_stdout_portable_print_t(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_println_color_n(mk_lang_stdout_portable_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_portable_color_text_e_dummy_end);

	((mk_lang_types_void_t)(color));
	err = mk_lang_stdout_portable_println_n(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_println_color_w(mk_lang_stdout_portable_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_portable_color_text_e_dummy_end);

	((mk_lang_types_void_t)(color));
	err = mk_lang_stdout_portable_println_w(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_portable_println_color_t(mk_lang_stdout_portable_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(color >= 0);
	mk_lang_assert(color < mk_lang_stdout_portable_color_text_e_dummy_end);

	((mk_lang_types_void_t)(color));
	err = mk_lang_stdout_portable_println_t(str_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
}


#endif
