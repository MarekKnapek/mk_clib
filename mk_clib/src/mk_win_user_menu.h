#ifndef include_guard_mk_win_user_menu
#define include_guard_mk_win_user_menu


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_win_base.h"
#include "mk_win_kernel_atom.h"
#include "mk_win_user_brush.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_icon.h"


struct mk_win_user_menu_handle_s; typedef struct mk_win_user_menu_handle_s mk_win_user_menu_handle_t; typedef mk_win_user_menu_handle_t const* mk_win_user_menu_t;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_menu.c"
#endif
#endif
