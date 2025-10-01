#ifndef mk_include_guard_mk_lang_stdout_linuks_h
#define mk_include_guard_mk_lang_stdout_linuks_h


#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"


enum mk_lang_stdout_linuks_color_text_e
{
	mk_lang_stdout_linuks_color_text_e_dark_black,
	mk_lang_stdout_linuks_color_text_e_dark_red,
	mk_lang_stdout_linuks_color_text_e_dark_green,
	mk_lang_stdout_linuks_color_text_e_dark_blue,
	mk_lang_stdout_linuks_color_text_e_dark_yellow,
	mk_lang_stdout_linuks_color_text_e_dark_magenta,
	mk_lang_stdout_linuks_color_text_e_dark_cyan,
	mk_lang_stdout_linuks_color_text_e_dark_white,
	mk_lang_stdout_linuks_color_text_e_light_black,
	mk_lang_stdout_linuks_color_text_e_light_red,
	mk_lang_stdout_linuks_color_text_e_light_green,
	mk_lang_stdout_linuks_color_text_e_light_blue,
	mk_lang_stdout_linuks_color_text_e_light_yellow,
	mk_lang_stdout_linuks_color_text_e_light_magenta,
	mk_lang_stdout_linuks_color_text_e_light_cyan,
	mk_lang_stdout_linuks_color_text_e_light_white,
	mk_lang_stdout_linuks_color_text_e_dummy_end
};
typedef enum mk_lang_stdout_linuks_color_text_e mk_lang_stdout_linuks_color_text_t;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_print_color_n(mk_lang_stdout_linuks_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_print_color_w(mk_lang_stdout_linuks_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_print_color_t(mk_lang_stdout_linuks_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_println_color_n(mk_lang_stdout_linuks_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_println_color_w(mk_lang_stdout_linuks_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_println_color_t(mk_lang_stdout_linuks_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_print_color_n(mk_lang_stdout_linuks_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_print_color_w(mk_lang_stdout_linuks_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_print_color_t(mk_lang_stdout_linuks_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_println_color_n(mk_lang_stdout_linuks_color_text_t const color, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_println_color_w(mk_lang_stdout_linuks_color_text_t const color, mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_linuks_no_redirect_println_color_t(mk_lang_stdout_linuks_color_text_t const color, mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;

#define mk_lang_stdout_linuks_print_lit_n(x) mk_lang_stdout_linuks_print_n(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_linuks_print_lit_w(x) mk_lang_stdout_linuks_print_w(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_linuks_print_lit_t(x) mk_lang_stdout_linuks_print_t(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_linuks_println_lit_n(x) mk_lang_stdout_linuks_print_lit_n(x "\x0a")
#define mk_lang_stdout_linuks_println_lit_w(x) mk_lang_stdout_linuks_print_lit_w(x L"\x0a")
#define mk_lang_stdout_linuks_println_lit_t(x) mk_lang_stdout_linuks_print_lit_t(x mk_lang_tchar_c("\x0a"))
#define mk_lang_stdout_linuks_no_redirect_print_lit_n(x) mk_lang_stdout_linuks_no_redirect_print_n(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_linuks_no_redirect_print_lit_w(x) mk_lang_stdout_linuks_no_redirect_print_w(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_linuks_no_redirect_print_lit_t(x) mk_lang_stdout_linuks_no_redirect_print_t(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_linuks_no_redirect_println_lit_n(x) mk_lang_stdout_linuks_no_redirect_print_lit_n(x "\x0a")
#define mk_lang_stdout_linuks_no_redirect_println_lit_w(x) mk_lang_stdout_linuks_no_redirect_print_lit_w(x L"\x0a")
#define mk_lang_stdout_linuks_no_redirect_println_lit_t(x) mk_lang_stdout_linuks_no_redirect_print_lit_t(x mk_lang_tchar_c("\x0a"))


#if mk_lang_jumbo_have
#include "mk_lang_stdout_linuks.c"
#endif
#endif
