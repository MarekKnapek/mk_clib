#ifndef mk_include_guard_mk_lang_crash
#define mk_include_guard_mk_lang_crash


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_noreturn.h"


mk_lang_noreturn mk_lang_jumbo void mk_lang_crash(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_crash.c"
#endif
#endif
