#ifndef mk_include_guard_win_winmain
#define mk_include_guard_win_winmain


#include "mk_lang_jumbo.h"
#include "mk_win_unicode_api.h"


#if mk_win_unicode_api == mk_win_unicode_api_wide
#define mk_win_winmain wWinMain
#else
#define mk_win_winmain WinMain
#endif


#if mk_lang_jumbo_want == 1
/*#include "mk_win_winmain.c"*/
#endif
#endif
