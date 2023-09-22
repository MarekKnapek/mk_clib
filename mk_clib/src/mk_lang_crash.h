#ifndef mk_include_guard_mk_lang_crash
#define mk_include_guard_mk_lang_crash


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_stringify.h"


#if defined mk_lang_crash_detail_want && mk_lang_crash_detail_want == 1
#define mk_lang_crash_detail_have 1
#else
#define mk_lang_crash_detail_have 0
#endif


#if mk_lang_crash_detail_have
mk_lang_noreturn mk_lang_jumbo void mk_lang_crash_impl(char const* const msg) mk_lang_noexcept;
#define mk_lang_crash() mk_lang_crash_impl("crash--->" __FILE__ ":" mk_lang_stringify(__LINE__) "<---crash")
#else
mk_lang_noreturn mk_lang_jumbo void mk_lang_crash(void) mk_lang_noexcept;
#endif


#if mk_lang_jumbo_want == 1
#include "mk_lang_crash.c"
#endif
#endif
