#ifndef mk_include_guard_mk_lang_info_platform_h
#define mk_include_guard_mk_lang_info_platform_h


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo mk_lang_types_void_t mk_lang_info_platform_print(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_lang_info_platform.c"
#endif
#endif
