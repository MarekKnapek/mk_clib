#ifndef mk_include_guard_clib_app_simple_window
#define mk_include_guard_clib_app_simple_window


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"


mk_lang_jumbo int mk_clib_app_simple_window_winmain(mk_win_base_instance_t const instance, mk_win_base_instance_t const previous, mk_win_tstring_tchar_lpct const cmd, int const show) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_simple_window.c"
#endif
#endif
