#ifndef mk_include_guard_clib_app_test
#define mk_include_guard_clib_app_test


#include "mk_lang_jumbo.h"


mk_lang_jumbo int mk_clib_app_test_void(void);


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_test.c"
#endif
#endif
