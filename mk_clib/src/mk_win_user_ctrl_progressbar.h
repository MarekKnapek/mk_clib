#ifndef mk_include_guard_win_user_ctrl_progressbar
#define mk_include_guard_win_user_ctrl_progressbar


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_user_message.h"


#define mk_win_user_ctrl_progressbar_name_a "msctls_progress32"
#define mk_win_user_ctrl_progressbar_name_w L"msctls_progress32"
#define mk_win_user_ctrl_progressbar_name_t mk_win_tstring_tchar_c("msctls_progress32")


enum mk_win_user_ctrl_progressbar_style_e
{
	mk_win_user_ctrl_progressbar_style_e_smooth        = 0x0001, /* version 4.70 */
	mk_win_user_ctrl_progressbar_style_e_vertical      = 0x0004, /* version 4.70 */
	mk_win_user_ctrl_progressbar_style_e_marquee       = 0x0008, /* ntddi_version >= ntddi_winxp */ /* version 6.0 */
	mk_win_user_ctrl_progressbar_style_e_smoothreverse = 0x0010, /* ntddi_version >= ntddi_vista */ /* version 6.0 */
	mk_win_user_ctrl_progressbar_style_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_progressbar_style_e mk_win_user_ctrl_progressbar_style_t;

enum mk_win_user_ctrl_progressbar_notify_e
{
	mk_win_user_ctrl_progressbar_notify_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_progressbar_notify_e mk_win_user_ctrl_progressbar_notify_t;

enum mk_win_user_ctrl_progressbar_message_e
{
	mk_win_user_ctrl_progressbar_message_e_setrange    = mk_win_user_message_id_e_user +  1,
	mk_win_user_ctrl_progressbar_message_e_setpos      = mk_win_user_message_id_e_user +  2,
	mk_win_user_ctrl_progressbar_message_e_deltapos    = mk_win_user_message_id_e_user +  3,
	mk_win_user_ctrl_progressbar_message_e_setstep     = mk_win_user_message_id_e_user +  4,
	mk_win_user_ctrl_progressbar_message_e_stepit      = mk_win_user_message_id_e_user +  5,
	mk_win_user_ctrl_progressbar_message_e_setrange32  = mk_win_user_message_id_e_user +  6,
	mk_win_user_ctrl_progressbar_message_e_getrange    = mk_win_user_message_id_e_user +  7,
	mk_win_user_ctrl_progressbar_message_e_getpos      = mk_win_user_message_id_e_user +  8,
	mk_win_user_ctrl_progressbar_message_e_setbarcolor = mk_win_user_message_id_e_user +  9,
	mk_win_user_ctrl_progressbar_message_e_setmarquee  = mk_win_user_message_id_e_user + 10, /* ntddi_version >= ntddi_winxp */
	mk_win_user_ctrl_progressbar_message_e_getstep     = mk_win_user_message_id_e_user + 13, /* ntddi_version >= ntddi_vista */
	mk_win_user_ctrl_progressbar_message_e_getbkcolor  = mk_win_user_message_id_e_user + 14, /* ntddi_version >= ntddi_vista */
	mk_win_user_ctrl_progressbar_message_e_getbarcolor = mk_win_user_message_id_e_user + 15, /* ntddi_version >= ntddi_vista */
	mk_win_user_ctrl_progressbar_message_e_setstate    = mk_win_user_message_id_e_user + 16, /* ntddi_version >= ntddi_vista */
	mk_win_user_ctrl_progressbar_message_e_getstate    = mk_win_user_message_id_e_user + 17, /* ntddi_version >= ntddi_vista */
	mk_win_user_ctrl_progressbar_message_e_setbkcolor  = 0x2000 + 1,
	mk_win_user_ctrl_progressbar_message_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_progressbar_message_e mk_win_user_ctrl_progressbar_message_t;


struct mk_win_user_ctrl_progressbar_range_s
{
	int m_low;
	int m_high;
};
typedef struct mk_win_user_ctrl_progressbar_range_s mk_win_user_ctrl_progressbar_range_t;
typedef mk_win_user_ctrl_progressbar_range_t const mk_win_user_ctrl_progressbar_range_ct;
typedef mk_win_user_ctrl_progressbar_range_t* mk_win_user_ctrl_progressbar_range_pt;
typedef mk_win_user_ctrl_progressbar_range_t const* mk_win_user_ctrl_progressbar_range_pct;
typedef mk_win_user_ctrl_progressbar_range_t mk_win_base_far* mk_win_user_ctrl_progressbar_range_lpt;
typedef mk_win_user_ctrl_progressbar_range_t mk_win_base_far const* mk_win_user_ctrl_progressbar_range_lpct;
typedef mk_win_user_ctrl_progressbar_range_t mk_win_base_near* mk_win_user_ctrl_progressbar_range_npt;
typedef mk_win_user_ctrl_progressbar_range_t mk_win_base_near const* mk_win_user_ctrl_progressbar_range_npct;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_ctrl_progressbar.c"
#endif
#endif
