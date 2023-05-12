#ifndef include_guard_mk_clib_app_file_explorer
#define include_guard_mk_clib_app_file_explorer


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"


mk_lang_jumbo int mk_clib_app_file_explorer_winmain(mk_win_base_instance_t const instance, mk_win_base_instance_t const previous, mk_win_tstring_tchar_lpct const cmd, int const show) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_app_file_explorer.c"
#endif
#endif
