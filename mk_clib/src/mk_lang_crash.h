#ifndef mk_include_guard_lang_crash
#define mk_include_guard_lang_crash


#include "mk_lang_jumbo.h"


mk_lang_jumbo void mk_lang_crash(void);


#if mk_lang_jumbo_want == 1
#include "mk_lang_crash.c"
#endif
#endif
