#ifndef include_guard_mk_lang_sizeof_test
#define include_guard_mk_lang_sizeof_test


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo void mk_lang_sizeof_test(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_sizeof_test.c"
#endif
#endif
