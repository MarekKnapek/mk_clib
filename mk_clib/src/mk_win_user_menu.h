#ifndef mk_include_guard_mk_win_user_menu
#define mk_include_guard_mk_win_user_menu


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_win_base_make_handle(mk_win_user_menu)


/*mk_lang_nodiscard mk_lang_jumbo mk_win_user_menu_t mk_win_user_menu_a_load(mk_win_base_instance_t const instance, mk_win_base_pchar_lpct const name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_menu_t mk_win_user_menu_w_load(mk_win_base_instance_t const instance, mk_win_base_wchar_lpct const name) mk_lang_noexcept;*/


#if mk_lang_jumbo_want == 1
#include "mk_win_user_menu.c"
#endif
#endif
