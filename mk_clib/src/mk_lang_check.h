#ifndef include_guard_mk_lang_check
#define include_guard_mk_lang_check


#include "mk_lang_jumbo.h"


#define mk_lang_check_if_failed(x) (!(x))


#if mk_lang_jumbo_want == 1
#include "mk_lang_check.c"
#endif
#endif