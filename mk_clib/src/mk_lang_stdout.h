#ifndef mk_include_guard_mk_lang_stdout_h
#define mk_include_guard_mk_lang_stdout_h


#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"


#if mk_lang_platform_is_windows_at_least_any
#define mk_lang_stdout_impl_nl_n "\x0d\x0a"
#define mk_lang_stdout_impl_nl_w L"\x0d\x0a"
#define mk_lang_stdout_impl_nl_t mk_lang_tchar_c("\x0d\x0a")
#elif mk_lang_platform_is_linux
#define mk_lang_stdout_impl_nl_n "\n"
#define mk_lang_stdout_impl_nl_w L"\n"
#define mk_lang_stdout_impl_nl_t mk_lang_tchar_c("\n")
#elif mk_lang_platform_is_posix_at_least_any
#define mk_lang_stdout_impl_nl_n "\n"
#define mk_lang_stdout_impl_nl_w L"\n"
#define mk_lang_stdout_impl_nl_t mk_lang_tchar_c("\n")
#elif mk_lang_platform_is_portable
#define mk_lang_stdout_impl_nl_n "\n"
#define mk_lang_stdout_impl_nl_w L"\n"
#define mk_lang_stdout_impl_nl_t mk_lang_tchar_c("\n")
#else
#error xxxxxxxxxx
#endif


enum mk_lang_stdout_color_text_e
{
	mk_lang_stdout_color_text_e_dark_black,
	mk_lang_stdout_color_text_e_dark_red,
	mk_lang_stdout_color_text_e_dark_green,
	mk_lang_stdout_color_text_e_dark_blue,
	mk_lang_stdout_color_text_e_dark_yellow,
	mk_lang_stdout_color_text_e_dark_magenta,
	mk_lang_stdout_color_text_e_dark_cyan,
	mk_lang_stdout_color_text_e_dark_white,
	mk_lang_stdout_color_text_e_light_black,
	mk_lang_stdout_color_text_e_light_red,
	mk_lang_stdout_color_text_e_light_green,
	mk_lang_stdout_color_text_e_light_blue,
	mk_lang_stdout_color_text_e_light_yellow,
	mk_lang_stdout_color_text_e_light_magenta,
	mk_lang_stdout_color_text_e_light_cyan,
	mk_lang_stdout_color_text_e_light_white,
	mk_lang_stdout_color_text_e_dummy_end
};
typedef enum mk_lang_stdout_color_text_e mk_lang_stdout_color_text_t;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_color_n(mk_lang_stdout_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_color_w(mk_lang_stdout_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_color_t(mk_lang_stdout_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_color_n(mk_lang_stdout_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_color_w(mk_lang_stdout_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_println_color_t(mk_lang_stdout_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_color_n(mk_lang_stdout_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_color_w(mk_lang_stdout_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_print_color_t(mk_lang_stdout_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_color_n(mk_lang_stdout_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_color_w(mk_lang_stdout_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_no_redirect_println_color_t(mk_lang_stdout_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;

#define mk_lang_stdout_print_lit_n(x) mk_lang_stdout_print_n(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_print_lit_w(x) mk_lang_stdout_print_w(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_print_lit_t(x) mk_lang_stdout_print_t(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_println_lit_n(x) mk_lang_stdout_print_lit_n(x mk_lang_stdout_impl_nl_n)
#define mk_lang_stdout_println_lit_w(x) mk_lang_stdout_print_lit_w(x mk_lang_stdout_impl_nl_w)
#define mk_lang_stdout_println_lit_t(x) mk_lang_stdout_print_lit_t(x mk_lang_stdout_impl_nl_t)
#define mk_lang_stdout_no_redirect_print_lit_n(x) mk_lang_stdout_no_redirect_print_n(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_no_redirect_print_lit_w(x) mk_lang_stdout_no_redirect_print_w(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_no_redirect_print_lit_t(x) mk_lang_stdout_no_redirect_print_t(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_no_redirect_println_lit_n(x) mk_lang_stdout_no_redirect_print_lit_n(x mk_lang_stdout_impl_nl_n)
#define mk_lang_stdout_no_redirect_println_lit_w(x) mk_lang_stdout_no_redirect_print_lit_w(x mk_lang_stdout_impl_nl_w)
#define mk_lang_stdout_no_redirect_println_lit_t(x) mk_lang_stdout_no_redirect_print_lit_t(x mk_lang_stdout_impl_nl_t)


#if mk_lang_jumbo_have
#include "mk_lang_stdout.c"
#endif
#endif
