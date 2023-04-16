#ifndef mk_include_guard_lang_info_macros
#define mk_include_guard_lang_info_macros


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


mk_lang_jumbo void mk_lang_info_macros_print(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_info_macros.c"
#endif
#endif
