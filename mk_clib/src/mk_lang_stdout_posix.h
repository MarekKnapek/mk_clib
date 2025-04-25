#ifndef mk_include_guard_mk_lang_stdout_posix_h
#define mk_include_guard_mk_lang_stdout_posix_h


#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_print_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_println_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_println_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_posix_println_t(mk_lang_tchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;

#define mk_lang_stdout_posix_print_lit_n(x) mk_lang_stdout_posix_print_n(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_posix_print_lit_w(x) mk_lang_stdout_posix_print_w(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_posix_print_lit_t(x) mk_lang_stdout_posix_print_t(&(x)[0], mk_lang_countstr((x)))
#define mk_lang_stdout_posix_println_lit_n(x) mk_lang_stdout_posix_print_lit_n(x "\n")
#define mk_lang_stdout_posix_println_lit_w(x) mk_lang_stdout_posix_print_lit_w(x L"\n")
#define mk_lang_stdout_posix_println_lit_t(x) mk_lang_stdout_posix_print_lit_t(x mk_lang_tchar_c("\n"))


#if mk_lang_jumbo_have
#include "mk_lang_stdout_posix.c"
#endif
#endif
