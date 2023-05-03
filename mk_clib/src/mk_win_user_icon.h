#ifndef mk_include_guard_win_user_icon
#define mk_include_guard_win_user_icon


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"


enum mk_win_user_icon_id_e
{
	mk_win_user_icon_id_e_application = 32512,
	mk_win_user_icon_id_e_hand        = 32513,
	mk_win_user_icon_id_e_question    = 32514,
	mk_win_user_icon_id_e_exclamation = 32515,
	mk_win_user_icon_id_e_asterisk    = 32516,
	mk_win_user_icon_id_e_winlogo     = 32517,
	mk_win_user_icon_id_e_shield      = 32518,
	mk_win_user_icon_id_e_error       = mk_win_user_icon_id_e_hand,
	mk_win_user_icon_id_e_warning     = mk_win_user_icon_id_e_exclamation,
	mk_win_user_icon_id_e_information = mk_win_user_icon_id_e_asterisk,
	mk_win_user_icon_id_e_dummy_end = 0
};
typedef enum mk_win_user_icon_id_e mk_win_user_icon_id_t;


struct mk_win_user_icon_handle_s; typedef struct mk_win_user_icon_handle_s mk_win_user_icon_handle_t; typedef mk_win_user_icon_handle_t const* mk_win_user_icon_t;


mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_a_load_by_name(mk_win_base_instance_t const instance, mk_win_base_pchar_lpct const name) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_a_load_by_id(mk_win_base_instance_t const instance, mk_win_user_icon_id_t const id) mk_lang_noexcept;

mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_w_load_by_name(mk_win_base_instance_t const instance, mk_win_base_wchar_lpct const name) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_w_load_by_id(mk_win_base_instance_t const instance, mk_win_user_icon_id_t const id) mk_lang_noexcept;

mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_t_load_by_name(mk_win_base_instance_t const instance, mk_win_tstring_tchar_lpct const name) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_icon_t mk_win_user_icon_t_load_by_id(mk_win_base_instance_t const instance, mk_win_user_icon_id_t const id) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_icon.c"
#endif
#endif
