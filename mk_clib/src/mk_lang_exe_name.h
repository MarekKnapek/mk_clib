#ifndef mk_include_guard_mk_lang_exe_name_h
#define mk_include_guard_mk_lang_exe_name_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_pchar_pct mk_lang_exe_name_get_n(mk_lang_types_pchar_pct const arg) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_wchar_pct mk_lang_exe_name_get_w(mk_lang_types_wchar_pct const arg) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_tchar_pct mk_lang_exe_name_get_t(mk_lang_tchar_pct const arg) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lang_exe_name.c"
#endif
#endif
