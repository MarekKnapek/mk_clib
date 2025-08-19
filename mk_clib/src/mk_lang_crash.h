#ifndef mk_include_guard_mk_lang_crash_h
#define mk_include_guard_mk_lang_crash_h


#include "mk_lang_configuration.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if defined mk_lang_crash_detail_want && (mk_lang_crash_detail_want) == 1
#define mk_lang_crash_detail_have 1
#elif defined mk_lang_crash_detail_want && (mk_lang_crash_detail_want) == 0
#define mk_lang_crash_detail_have 0
#elif !defined mk_lang_crash_detail_want
#if mk_lang_configuration_is_debug
#define mk_lang_crash_detail_have 1
#elif mk_lang_configuration_is_release
#define mk_lang_crash_detail_have 0
#else
#error xxxxxxxxxx
#endif
#else
#error xxxxxxxxxx
#endif


#if mk_lang_crash_detail_have


#include "mk_lang_debug_break.h"
#include "mk_lang_stringify.h"

mk_lang_jumbo mk_lang_types_void_t mk_lang_crash_for_real(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_lang_crash_print_msg(mk_lang_types_pchar_pct const msg) mk_lang_noexcept;

#define mk_lang_crash() ((mk_lang_types_void_t)(mk_lang_crash_print_msg("crash--->" __FILE__ ":" mk_lang_stringify(__LINE__) "<---crash"), mk_lang_debug_break(), mk_lang_crash_for_real()))


#else


mk_lang_jumbo mk_lang_types_void_t mk_lang_crash(mk_lang_types_void_t) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_lang_crash.c"
#endif
#endif
