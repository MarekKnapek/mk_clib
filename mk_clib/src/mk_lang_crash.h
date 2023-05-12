#ifndef include_guard_mk_lang_crash
#define include_guard_mk_lang_crash


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_noreturn.h"


#if defined mk_lang_crash_detail && mk_lang_crash_detail == 1
#define mk_lang_crash_detail_impl 1
#elif defined mk_lang_crash_detail && mk_lang_crash_detail == 0
#define mk_lang_crash_detail_impl 0
#else
#if defined NDEBUG
#define mk_lang_crash_detail_impl 0
#else
#define mk_lang_crash_detail_impl 1
#endif
#endif


#if mk_lang_crash_detail_impl

mk_lang_noreturn mk_lang_jumbo void mk_lang_crash_impl(char const* const file, int const line, char const* const line_str) mk_lang_noexcept;
#define mk_lang_crash_to_string_2(x) # x
#define mk_lang_crash_to_string(x) mk_lang_crash_to_string_2(x)
#define mk_lang_crash() mk_lang_crash_impl(__FILE__ , __LINE__, mk_lang_crash_to_string(__LINE__))

#else

mk_lang_noreturn mk_lang_jumbo void mk_lang_crash(void) mk_lang_noexcept;

#endif


#if mk_lang_jumbo_want == 1
#include "mk_lang_crash.c"
#endif
#endif
