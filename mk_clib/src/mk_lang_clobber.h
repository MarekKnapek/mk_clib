#ifndef include_guard_mk_lang_clobber
#define include_guard_mk_lang_clobber


#include "mk_lang_jumbo.h"


mk_lang_jumbo void mk_lang_clobber(void const* const arg);


#if mk_lang_jumbo_want == 1
#include "mk_lang_clobber.c"
#endif
#endif
