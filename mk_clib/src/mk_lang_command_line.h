#ifndef mk_include_guard_mk_lang_command_line_h
#define mk_include_guard_mk_lang_command_line_h


#include "mk_lang_types.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_jumbo.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_command_line_parse(mk_lang_types_wchar_pct const cmdline, mk_lang_types_wchar_ppct const argv, mk_lang_types_sint_pt const lens, mk_lang_types_sint_t const count, mk_lang_types_sint_pt const argc) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lang_command_line.c"
#endif
#endif
