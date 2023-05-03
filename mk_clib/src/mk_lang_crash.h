#ifndef mk_include_guard_lang_crash
#define mk_include_guard_lang_crash


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_noreturn.h"


#if defined NDEBUG

mk_lang_noreturn mk_lang_jumbo void mk_lang_crash(void) mk_lang_noexcept;

#else

mk_lang_noreturn mk_lang_jumbo void mk_lang_crash_impl(char const* const file, int const line) mk_lang_noexcept;
#define mk_lang_crash() mk_lang_crash_impl(__FILE__ , __LINE__)

#endif


#if mk_lang_jumbo_want == 1
#include "mk_lang_crash.c"
#endif
#endif
