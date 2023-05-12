#ifndef include_guard_mk_win_user_ctrl_static
#define include_guard_mk_win_user_ctrl_static


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"


#define mk_win_user_ctrl_static_name_a "static"
#define mk_win_user_ctrl_static_name_w L"static"
#define mk_win_user_ctrl_static_name_t mk_win_tstring_tchar_c("static")


enum mk_win_user_ctrl_static_style_e
{
	mk_win_user_ctrl_static_style_e_left            = 0x00000000l,
	mk_win_user_ctrl_static_style_e_center          = 0x00000001l,
	mk_win_user_ctrl_static_style_e_right           = 0x00000002l,
	mk_win_user_ctrl_static_style_e_icon            = 0x00000003l,
	mk_win_user_ctrl_static_style_e_blackrect       = 0x00000004l,
	mk_win_user_ctrl_static_style_e_grayrect        = 0x00000005l,
	mk_win_user_ctrl_static_style_e_whiterect       = 0x00000006l,
	mk_win_user_ctrl_static_style_e_blackframe      = 0x00000007l,
	mk_win_user_ctrl_static_style_e_grayframe       = 0x00000008l,
	mk_win_user_ctrl_static_style_e_whiteframe      = 0x00000009l,
	mk_win_user_ctrl_static_style_e_useritem        = 0x0000000al,
	mk_win_user_ctrl_static_style_e_simple          = 0x0000000bl,
	mk_win_user_ctrl_static_style_e_leftnowordwrap  = 0x0000000cl,
	mk_win_user_ctrl_static_style_e_ownerdraw       = 0x0000000dl, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_bitmap          = 0x0000000el, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_enhmetafile     = 0x0000000fl, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_etchedhorz      = 0x00000010l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_etchedvert      = 0x00000011l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_etchedframe     = 0x00000012l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_typemask        = 0x0000001fl, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_realsizecontrol = 0x00000040l, /* winver >= 0x0501 */
	mk_win_user_ctrl_static_style_e_noprefix        = 0x00000080l,
	mk_win_user_ctrl_static_style_e_notify          = 0x00000100l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_centerimage     = 0x00000200l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_rightjust       = 0x00000400l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_realsizeimage   = 0x00000800l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_sunken          = 0x00001000l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_editcontrol     = 0x00002000l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_endellipsis     = 0x00004000l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_pathellipsis    = 0x00008000l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_wordellipsis    = 0x0000c000l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_ellipsismask    = 0x0000c000l, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_style_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_static_style_e mk_win_user_ctrl_static_style_t;

enum mk_win_user_ctrl_static_notify_e
{
	mk_win_user_ctrl_static_notify_e_clicked = 0x0000,
	mk_win_user_ctrl_static_notify_e_dblclk  = 0x0001,
	mk_win_user_ctrl_static_notify_e_enable  = 0x0002,
	mk_win_user_ctrl_static_notify_e_disable = 0x0003,
	mk_win_user_ctrl_static_notify_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_static_notify_e mk_win_user_ctrl_static_notify_t;

enum mk_win_user_ctrl_static_message_e
{
	mk_win_user_ctrl_static_message_e_seticon  = 0x0170ul,
	mk_win_user_ctrl_static_message_e_geticon  = 0x0171ul,
	mk_win_user_ctrl_static_message_e_setimage = 0x0172ul, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_message_e_getimage = 0x0173ul, /* winver >= 0x0400 */
	mk_win_user_ctrl_static_message_e_msgmax   = 0x0174ul,
	mk_win_user_ctrl_static_message_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_static_message_e mk_win_user_ctrl_static_message_t;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_ctrl_static.c"
#endif
#endif
