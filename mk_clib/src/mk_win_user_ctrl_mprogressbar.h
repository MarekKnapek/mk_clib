#ifndef include_guard_mk_win_user_ctrl_mprogressbar
#define include_guard_mk_win_user_ctrl_mprogressbar


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_user_message.h"


#define mk_win_user_ctrl_mprogressbar_name_a "mkwcpb"
#define mk_win_user_ctrl_mprogressbar_name_w L"mkwcpb"
#define mk_win_user_ctrl_mprogressbar_name_t mk_win_tstring_tchar_c("mkwcpb")


enum mk_win_user_ctrl_mprogressbar_style_e
{
	mk_win_user_ctrl_mprogressbar_style_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_mprogressbar_style_e mk_win_user_ctrl_mprogressbar_style_t;

enum mk_win_user_ctrl_mprogressbar_notify_e
{
	mk_win_user_ctrl_mprogressbar_notify_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_mprogressbar_notify_e mk_win_user_ctrl_mprogressbar_notify_t;

enum mk_win_user_ctrl_mprogressbar_message_e
{
	mk_win_user_ctrl_mprogressbar_message_e_set_position = mk_win_user_message_id_e_user + 1,
	mk_win_user_ctrl_mprogressbar_message_e_get_position = mk_win_user_message_id_e_user + 2,
	mk_win_user_ctrl_mprogressbar_message_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_mprogressbar_message_e mk_win_user_ctrl_mprogressbar_message_t;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_ctrl_mprogressbar.c"
#endif
#endif
