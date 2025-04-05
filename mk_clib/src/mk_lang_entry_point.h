#ifndef mk_include_guard_mk_lang_entry_point_h
#define mk_include_guard_mk_lang_entry_point_h


#include "mk_lang_types.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_jumbo.h"


#if defined mk_lang_entry_point_want && (mk_lang_entry_point_want) == 1
#define mk_lang_entry_point_vant 1
#elif defined mk_lang_entry_point_want && (mk_lang_entry_point_want) == 0
#define mk_lang_entry_point_vant 0
#elif !defined mk_lang_entry_point_want
#define mk_lang_entry_point_vant 0
#else
#error xxxxxxxxxx
#endif

#if mk_lang_entry_point_vant
#define mk_lang_entry_point_have 1
#else
#define mk_lang_entry_point_have 0
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lang_entry_point_parse_cmdline(mk_lang_types_wchar_pct const cmdline, mk_lang_types_wchar_ppct const argv, mk_lang_types_sint_pt const lens, mk_lang_types_sint_t const count, mk_lang_types_sint_pt const argc) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lang_entry_point.c"
#endif
#endif
