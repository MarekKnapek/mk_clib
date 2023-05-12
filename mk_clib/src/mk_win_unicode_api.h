#ifndef include_guard_mk_win_unicode
#define include_guard_mk_win_unicode


#include "mk_lang_arch.h"
#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"


#define mk_win_unicode_api_oold 2001
#define mk_win_unicode_api_ansi 2002
#define mk_win_unicode_api_both 2003
#define mk_win_unicode_api_wide 2004

#if mk_lang_arch == mk_lang_arch_x8616
#define mk_win_unicode_api mk_win_unicode_api_oold
#elif mk_lang_arch == mk_lang_arch_x8632
#define mk_win_unicode_api mk_win_unicode_api_both
#else
#define mk_win_unicode_api mk_win_unicode_api_wide
#endif


#if mk_win_unicode_api == mk_win_unicode_api_both
mk_lang_jumbo mk_lang_bool_t mk_win_unicode_api_is_wide(void) mk_lang_noexcept;
#endif


#if mk_lang_jumbo_want == 1
#include "mk_win_unicode_api.c"
#endif
#endif
