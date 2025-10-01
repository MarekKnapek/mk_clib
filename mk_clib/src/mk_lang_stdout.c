#ifndef mk_include_guard_mk_lang_stdout_c
#define mk_include_guard_mk_lang_stdout_c
#include "mk_lang_stdout.h"

#include "mk_lang_arch.h"
#include "mk_lang_concat.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"


#if mk_lang_platform_is_windows_at_least_any
#include "mk_lang_stdout_windows.h"
#define mk_lang_stdout_prefix windows
#elif mk_lang_arch_is_emscripten
#include "mk_lang_stdout_emscripten.h"
#define mk_lang_stdout_prefix emscripten
#elif mk_lang_platform_is_linux
#include "mk_lang_stdout_linuks.h"
#define mk_lang_stdout_prefix linuks
#elif mk_lang_platform_is_posix_at_least_any
#include "mk_lang_stdout_posix.h"
#define mk_lang_stdout_prefix posix
#elif mk_lang_platform_is_portable
#include "mk_lang_stdout_portable.h"
#define mk_lang_stdout_prefix portable
#else
#error xxxxxxxxxx
#endif
#define mk_lang_stdout_impl_color_text_t mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _color_text_t)
#define mk_lang_stdout_impl_init mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _init)
#define mk_lang_stdout_impl_print_n mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _print_n)
#define mk_lang_stdout_impl_print_w mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _print_w)
#define mk_lang_stdout_impl_print_t mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _print_t)
#define mk_lang_stdout_impl_println_n mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _println_n)
#define mk_lang_stdout_impl_println_w mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _println_w)
#define mk_lang_stdout_impl_println_t mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _println_t)
#define mk_lang_stdout_impl_print_color_n mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _print_color_n)
#define mk_lang_stdout_impl_print_color_w mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _print_color_w)
#define mk_lang_stdout_impl_print_color_t mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _print_color_t)
#define mk_lang_stdout_impl_println_color_n mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _println_color_n)
#define mk_lang_stdout_impl_println_color_w mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _println_color_w)
#define mk_lang_stdout_impl_println_color_t mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _println_color_t)
#define mk_lang_stdout_no_redirect_impl_print_n mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _print_n)
#define mk_lang_stdout_no_redirect_impl_print_w mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _print_w)
#define mk_lang_stdout_no_redirect_impl_print_t mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _print_t)
#define mk_lang_stdout_no_redirect_impl_println_n mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _println_n)
#define mk_lang_stdout_no_redirect_impl_println_w mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _println_w)
#define mk_lang_stdout_no_redirect_impl_println_t mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _println_t)
#define mk_lang_stdout_no_redirect_impl_print_color_n mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _print_color_n)
#define mk_lang_stdout_no_redirect_impl_print_color_w mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _print_color_w)
#define mk_lang_stdout_no_redirect_impl_print_color_t mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _print_color_t)
#define mk_lang_stdout_no_redirect_impl_println_color_n mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _println_color_n)
#define mk_lang_stdout_no_redirect_impl_println_color_w mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _println_color_w)
#define mk_lang_stdout_no_redirect_impl_println_color_t mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_stdout_, mk_lang_stdout_prefix), _no_redirect), _println_color_t)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lang_stdout_impl_init();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_print_n(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_print_w(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_print_t(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_println_n(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_println_w(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_println_t(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_color_n(mk_lang_stdout_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_print_color_n(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_color_w(mk_lang_stdout_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_print_color_w(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_color_t(mk_lang_stdout_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_print_color_t(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_color_n(mk_lang_stdout_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_println_color_n(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_color_w(mk_lang_stdout_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_println_color_w(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_color_t(mk_lang_stdout_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_impl_println_color_t(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_print_n(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_print_w(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_print_t(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_println_n(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_println_w(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_println_t(str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_color_n(mk_lang_stdout_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_print_color_n(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_color_w(mk_lang_stdout_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_print_color_w(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_color_t(mk_lang_stdout_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_print_color_t(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_color_n(mk_lang_stdout_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_println_color_n(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_color_w(mk_lang_stdout_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_println_color_w(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_color_t(mk_lang_stdout_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	return mk_lang_stdout_no_redirect_impl_println_color_t(((mk_lang_stdout_impl_color_text_t)(color)), str_buf, str_len);
}


#endif
