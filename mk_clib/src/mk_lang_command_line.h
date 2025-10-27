#ifndef mk_include_guard_mk_lang_command_line_h
#define mk_include_guard_mk_lang_command_line_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_command_line_parse_std(mk_lang_types_sint_t const argc_in, mk_lang_types_pchar_pcpct const argv_in, mk_lang_types_pchar_ppct const argv_out, mk_lang_types_sint_pt const lens_out, mk_lang_types_sint_t const count, mk_lang_types_sint_pt const argc_out) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_command_line_parse_win(mk_lang_types_wchar_pct const cmdline, mk_lang_types_wchar_ppct const argv, mk_lang_types_sint_pt const lens, mk_lang_types_sint_t const count, mk_lang_types_sint_pt const argc) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lang_command_line.c"
#endif
#endif
