#ifndef include_guard_mk_clib_app_test
#define include_guard_mk_clib_app_test


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo int mk_clib_app_test_void(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_test.c"
#endif
#endif
