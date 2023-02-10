#ifndef mk_include_guard_clib_app_info
#define mk_include_guard_clib_app_info


#include "mk_lang_jumbo.h"


mk_lang_jumbo int mk_clib_app_info_void(void);


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_info.c"
#endif
#endif
