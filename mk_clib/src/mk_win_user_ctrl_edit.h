#ifndef mk_include_guard_win_user_ctrl_edit
#define mk_include_guard_win_user_ctrl_edit


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"


#define mk_win_user_ctrl_edit_name_a "edit"
#define mk_win_user_ctrl_edit_name_w L"edit"
#define mk_win_user_ctrl_edit_name_t mk_win_tstring_tchar_c("edit")


enum mk_win_user_ctrl_edit_style_e
{
	mk_win_user_ctrl_edit_style_e_left        = 0x0000ul,
	mk_win_user_ctrl_edit_style_e_center      = 0x0001ul,
	mk_win_user_ctrl_edit_style_e_right       = 0x0002ul,
	mk_win_user_ctrl_edit_style_e_multiline   = 0x0004ul,
	mk_win_user_ctrl_edit_style_e_uppercase   = 0x0008ul,
	mk_win_user_ctrl_edit_style_e_lowercase   = 0x0010ul,
	mk_win_user_ctrl_edit_style_e_password    = 0x0020ul,
	mk_win_user_ctrl_edit_style_e_autovscroll = 0x0040ul,
	mk_win_user_ctrl_edit_style_e_autohscroll = 0x0080ul,
	mk_win_user_ctrl_edit_style_e_nohidesel   = 0x0100ul,
	mk_win_user_ctrl_edit_style_e_oemconvert  = 0x0400ul,
	mk_win_user_ctrl_edit_style_e_readonly    = 0x0800ul,
	mk_win_user_ctrl_edit_style_e_wantreturn  = 0x1000ul,
	mk_win_user_ctrl_edit_style_e_number      = 0x2000ul, /* winver >= 0x0400 */
	mk_win_user_ctrl_edit_style_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_edit_style_e mk_win_user_ctrl_edit_style_t;

enum mk_win_user_ctrl_edit_notify_e
{
	mk_win_user_ctrl_edit_notify_e_setfocus     = 0x0100ul,
	mk_win_user_ctrl_edit_notify_e_killfocus    = 0x0200ul,
	mk_win_user_ctrl_edit_notify_e_change       = 0x0300ul,
	mk_win_user_ctrl_edit_notify_e_update       = 0x0400ul,
	mk_win_user_ctrl_edit_notify_e_errspace     = 0x0500ul,
	mk_win_user_ctrl_edit_notify_e_maxtext      = 0x0501ul,
	mk_win_user_ctrl_edit_notify_e_hscroll      = 0x0601ul,
	mk_win_user_ctrl_edit_notify_e_vscroll      = 0x0602ul,
	mk_win_user_ctrl_edit_notify_e_align_ltr_ec = 0x0700ul, /* _win32_winnt >= 0x0500 */
	mk_win_user_ctrl_edit_notify_e_align_rtl_ec = 0x0701ul, /* _win32_winnt >= 0x0500 */
	mk_win_user_ctrl_edit_notify_e_before_paste = 0x0800ul, /* winver >= 0x0604 */
	mk_win_user_ctrl_edit_notify_e_after_paste  = 0x0801ul, /* winver >= 0x0604 */
	mk_win_user_ctrl_edit_notify_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_edit_notify_e mk_win_user_ctrl_edit_notify_t;

enum mk_win_user_ctrl_edit_message_e
{
	mk_win_user_ctrl_edit_message_e_getsel              = 0x00b0ul,
	mk_win_user_ctrl_edit_message_e_setsel              = 0x00b1ul,
	mk_win_user_ctrl_edit_message_e_getrect             = 0x00b2ul,
	mk_win_user_ctrl_edit_message_e_setrect             = 0x00b3ul,
	mk_win_user_ctrl_edit_message_e_setrectnp           = 0x00b4ul,
	mk_win_user_ctrl_edit_message_e_scroll              = 0x00b5ul,
	mk_win_user_ctrl_edit_message_e_linescroll          = 0x00b6ul,
	mk_win_user_ctrl_edit_message_e_scrollcaret         = 0x00b7ul,
	mk_win_user_ctrl_edit_message_e_getmodify           = 0x00b8ul,
	mk_win_user_ctrl_edit_message_e_setmodify           = 0x00b9ul,
	mk_win_user_ctrl_edit_message_e_getlinecount        = 0x00baul,
	mk_win_user_ctrl_edit_message_e_lineindex           = 0x00bbul,
	mk_win_user_ctrl_edit_message_e_sethandle           = 0x00bcul,
	mk_win_user_ctrl_edit_message_e_gethandle           = 0x00bdul,
	mk_win_user_ctrl_edit_message_e_getthumb            = 0x00beul,
	mk_win_user_ctrl_edit_message_e_linelength          = 0x00c1ul,
	mk_win_user_ctrl_edit_message_e_replacesel          = 0x00c2ul,
	mk_win_user_ctrl_edit_message_e_getline             = 0x00c4ul,
	mk_win_user_ctrl_edit_message_e_limittext           = 0x00c5ul,
	mk_win_user_ctrl_edit_message_e_canundo             = 0x00c6ul,
	mk_win_user_ctrl_edit_message_e_undo                = 0x00c7ul,
	mk_win_user_ctrl_edit_message_e_fmtlines            = 0x00c8ul,
	mk_win_user_ctrl_edit_message_e_linefromchar        = 0x00c9ul,
	mk_win_user_ctrl_edit_message_e_settabstops         = 0x00cbul,
	mk_win_user_ctrl_edit_message_e_setpasswordchar     = 0x00ccul,
	mk_win_user_ctrl_edit_message_e_emptyundobuffer     = 0x00cdul,
	mk_win_user_ctrl_edit_message_e_getfirstvisibleline = 0x00ceul,
	mk_win_user_ctrl_edit_message_e_setreadonly         = 0x00cful,
	mk_win_user_ctrl_edit_message_e_setwordbreakproc    = 0x00d0ul,
	mk_win_user_ctrl_edit_message_e_getwordbreakproc    = 0x00d1ul,
	mk_win_user_ctrl_edit_message_e_getpasswordchar     = 0x00d2ul,
	mk_win_user_ctrl_edit_message_e_setmargins          = 0x00d3ul, /* winver >= 0x0400 */
	mk_win_user_ctrl_edit_message_e_getmargins          = 0x00d4ul, /* winver >= 0x0400 */
	mk_win_user_ctrl_edit_message_e_setlimittext        = mk_win_user_ctrl_edit_message_e_limittext, /* winver >= 0x0400 */
	mk_win_user_ctrl_edit_message_e_getlimittext        = 0x00d5ul, /* winver >= 0x0400 */
	mk_win_user_ctrl_edit_message_e_posfromchar         = 0x00d6ul, /* winver >= 0x0400 */
	mk_win_user_ctrl_edit_message_e_charfrompos         = 0x00d7ul, /* winver >= 0x0400 */
	mk_win_user_ctrl_edit_message_e_setimestatus        = 0x00d8ul, /* winver >= 0x0500 */
	mk_win_user_ctrl_edit_message_e_getimestatus        = 0x00d9ul, /* winver >= 0x0500 */
	mk_win_user_ctrl_edit_message_e_enablefeature       = 0x00daul, /* winver >= 0x0604 */
	mk_win_user_ctrl_edit_message_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_edit_message_e mk_win_user_ctrl_edit_message_t;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_ctrl_edit.c"
#endif
#endif
