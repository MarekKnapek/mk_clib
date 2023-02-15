#ifndef mk_include_guard_clib_test
#define mk_include_guard_clib_test


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo void mk_clib_test(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_test.c"
#endif
#endif
