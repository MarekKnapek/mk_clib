#ifndef mk_include_guard_lang_sizeof_test
#define mk_include_guard_lang_sizeof_test


#include "mk_lang_jumbo.h"


mk_lang_jumbo void mk_lang_sizeof_test(void);


#if mk_lang_jumbo_want == 1
#include "mk_lang_sizeof_test.c"
#endif
#endif