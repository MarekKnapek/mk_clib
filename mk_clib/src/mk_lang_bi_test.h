#ifndef mk_include_guard_lang_bi_test
#define mk_include_guard_lang_bi_test


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo void mk_lang_bi_test(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_bi_test.c"
#endif
#endif
