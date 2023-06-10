#ifndef mk_include_guard_mk_clib_app_factorial
#define mk_include_guard_mk_clib_app_factorial


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo int mk_clib_app_factorial(int const argc, char const* const* const argv) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_factorial.c"
#endif
#endif
