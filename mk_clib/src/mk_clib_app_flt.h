#ifndef mk_include_guard_clib_app_flt
#define mk_include_guard_clib_app_flt


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo int mk_clib_app_flt(int const argc, char const* const* const argv) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_flt.c"
#endif
#endif
