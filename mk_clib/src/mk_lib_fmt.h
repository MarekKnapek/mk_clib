#ifndef mk_include_guard_mk_lib_fmt
#define mk_include_guard_mk_lib_fmt


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <stdarg.h> /* va_list */


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_fmt_v(mk_lang_types_pchar_pct const fmt, va_list const vp, mk_lang_types_pchar_pt const dst) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_lib_fmt(mk_lang_types_pchar_pct const fmt, mk_lang_types_pchar_pt const dst, ...) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fmt_sprintf(mk_lang_types_pchar_pt const dst, mk_lang_types_pchar_pct const fmt, ...) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_fmt.c"
#endif
#endif
