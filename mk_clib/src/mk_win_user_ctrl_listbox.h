#ifndef mk_include_guard_win_user_ctrl_listbox
#define mk_include_guard_win_user_ctrl_listbox


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_user_window.h"


#define mk_win_user_ctrl_listbox_name_a "listbox"
#define mk_win_user_ctrl_listbox_name_w L"listbox"
#define mk_win_user_ctrl_listbox_name_t mk_win_tstring_tchar_c("listbox")


enum mk_win_user_ctrl_listbox_style_e
{
	mk_win_user_ctrl_listbox_style_e_notify            = 0x0001ul,
	mk_win_user_ctrl_listbox_style_e_sort              = 0x0002ul,
	mk_win_user_ctrl_listbox_style_e_noredraw          = 0x0004ul,
	mk_win_user_ctrl_listbox_style_e_multiplesel       = 0x0008ul,
	mk_win_user_ctrl_listbox_style_e_ownerdrawfixed    = 0x0010ul,
	mk_win_user_ctrl_listbox_style_e_ownerdrawvariable = 0x0020ul,
	mk_win_user_ctrl_listbox_style_e_hasstrings        = 0x0040ul,
	mk_win_user_ctrl_listbox_style_e_usetabstops       = 0x0080ul,
	mk_win_user_ctrl_listbox_style_e_nointegralheight  = 0x0100ul,
	mk_win_user_ctrl_listbox_style_e_multicolumn       = 0x0200ul,
	mk_win_user_ctrl_listbox_style_e_wantkeyboardinput = 0x0400ul,
	mk_win_user_ctrl_listbox_style_e_extendedsel       = 0x0800ul,
	mk_win_user_ctrl_listbox_style_e_disablenoscroll   = 0x1000ul,
	mk_win_user_ctrl_listbox_style_e_nodata            = 0x2000ul,
	mk_win_user_ctrl_listbox_style_e_nosel             = 0x4000ul, /* winver >= 0x0400 */
	mk_win_user_ctrl_listbox_style_e_combobox          = 0x8000ul,
	mk_win_user_ctrl_listbox_style_e_standard          = (mk_win_user_ctrl_listbox_style_e_notify | mk_win_user_ctrl_listbox_style_e_sort | mk_win_user_window_style_e_vscroll | mk_win_user_window_style_e_border),
	mk_win_user_ctrl_listbox_style_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_listbox_style_e mk_win_user_ctrl_listbox_style_t;

enum mk_win_user_ctrl_listbox_notify_e
{
	mk_win_user_ctrl_listbox_notify_e_errspace  = -2,
	mk_win_user_ctrl_listbox_notify_e_selchange =  1,
	mk_win_user_ctrl_listbox_notify_e_dblclk    =  2,
	mk_win_user_ctrl_listbox_notify_e_selcancel =  3,
	mk_win_user_ctrl_listbox_notify_e_setfocus  =  4,
	mk_win_user_ctrl_listbox_notify_e_killfocus =  5,
	mk_win_user_ctrl_listbox_notify_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_listbox_notify_e mk_win_user_ctrl_listbox_notify_t;

enum mk_win_user_ctrl_listbox_message_e
{
	mk_win_user_ctrl_listbox_message_e_addstring           = 0x0180,
	mk_win_user_ctrl_listbox_message_e_insertstring        = 0x0181,
	mk_win_user_ctrl_listbox_message_e_deletestring        = 0x0182,
	mk_win_user_ctrl_listbox_message_e_selitemrangeex      = 0x0183,
	mk_win_user_ctrl_listbox_message_e_resetcontent        = 0x0184,
	mk_win_user_ctrl_listbox_message_e_setsel              = 0x0185,
	mk_win_user_ctrl_listbox_message_e_setcursel           = 0x0186,
	mk_win_user_ctrl_listbox_message_e_getsel              = 0x0187,
	mk_win_user_ctrl_listbox_message_e_getcursel           = 0x0188,
	mk_win_user_ctrl_listbox_message_e_gettext             = 0x0189,
	mk_win_user_ctrl_listbox_message_e_gettextlen          = 0x018a,
	mk_win_user_ctrl_listbox_message_e_getcount            = 0x018b,
	mk_win_user_ctrl_listbox_message_e_selectstring        = 0x018c,
	mk_win_user_ctrl_listbox_message_e_dir                 = 0x018d,
	mk_win_user_ctrl_listbox_message_e_gettopindex         = 0x018e,
	mk_win_user_ctrl_listbox_message_e_findstring          = 0x018f,
	mk_win_user_ctrl_listbox_message_e_getselcount         = 0x0190,
	mk_win_user_ctrl_listbox_message_e_getselitems         = 0x0191,
	mk_win_user_ctrl_listbox_message_e_settabstops         = 0x0192,
	mk_win_user_ctrl_listbox_message_e_gethorizontalextent = 0x0193,
	mk_win_user_ctrl_listbox_message_e_sethorizontalextent = 0x0194,
	mk_win_user_ctrl_listbox_message_e_setcolumnwidth      = 0x0195,
	mk_win_user_ctrl_listbox_message_e_addfile             = 0x0196,
	mk_win_user_ctrl_listbox_message_e_settopindex         = 0x0197,
	mk_win_user_ctrl_listbox_message_e_getitemrect         = 0x0198,
	mk_win_user_ctrl_listbox_message_e_getitemdata         = 0x0199,
	mk_win_user_ctrl_listbox_message_e_setitemdata         = 0x019a,
	mk_win_user_ctrl_listbox_message_e_selitemrange        = 0x019b,
	mk_win_user_ctrl_listbox_message_e_setanchorindex      = 0x019c,
	mk_win_user_ctrl_listbox_message_e_getanchorindex      = 0x019d,
	mk_win_user_ctrl_listbox_message_e_setcaretindex       = 0x019e,
	mk_win_user_ctrl_listbox_message_e_getcaretindex       = 0x019f,
	mk_win_user_ctrl_listbox_message_e_setitemheight       = 0x01a0,
	mk_win_user_ctrl_listbox_message_e_getitemheight       = 0x01a1,
	mk_win_user_ctrl_listbox_message_e_findstringexact     = 0x01a2,
	mk_win_user_ctrl_listbox_message_e_setlocale           = 0x01a5,
	mk_win_user_ctrl_listbox_message_e_getlocale           = 0x01a6,
	mk_win_user_ctrl_listbox_message_e_setcount            = 0x01a7,
	mk_win_user_ctrl_listbox_message_e_initstorage         = 0x01a8, /* winver >= 0x0400 */
	mk_win_user_ctrl_listbox_message_e_itemfrompoint       = 0x01a9, /* winver >= 0x0400 */
	mk_win_user_ctrl_listbox_message_e_multipleaddstring   = 0x01b1, /* _win32_wce >= 0x0400 */
	mk_win_user_ctrl_listbox_message_e_getlistboxinfo      = 0x01b2, /* _win32_winnt >= 0x0501 */
	mk_win_user_ctrl_listbox_message_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_listbox_message_e mk_win_user_ctrl_listbox_message_t;


enum mk_win_user_ctrl_listbox_err_e
{
	mk_win_user_ctrl_listbox_err_e_okay     =  0,
	mk_win_user_ctrl_listbox_err_e_err      = -1,
	mk_win_user_ctrl_listbox_err_e_errspace = -2,
	mk_win_user_ctrl_listbox_err_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_listbox_err_e mk_win_user_ctrl_listbox_err_t;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_ctrl_listbox.c"
#endif
#endif
