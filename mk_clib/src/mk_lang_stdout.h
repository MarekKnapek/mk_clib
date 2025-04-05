#ifndef mk_include_guard_mk_lang_stdout_h
#define mk_include_guard_mk_lang_stdout_h


#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_n(mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_stdout_print_w(mk_lang_types_wchar_pct const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;

#define mk_lang_stdout_print_lit_w(x) mk_lang_stdout_print_w(&(x)[0], mk_lang_countstr((x)))


#if mk_lang_jumbo_have
#include "mk_lang_stdout.c"
#endif
#endif
