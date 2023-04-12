#ifndef mk_include_guard_clib_app_flt_cpp
#define mk_include_guard_clib_app_flt_cpp


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo int mk_clib_app_flt_cpp(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_flt_cpp.cpp"
#endif
#endif
