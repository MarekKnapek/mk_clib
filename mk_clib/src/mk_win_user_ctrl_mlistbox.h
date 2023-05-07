#ifndef mk_include_guard_win_user_ctrl_mlistbox
#define mk_include_guard_win_user_ctrl_mlistbox


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_user_message.h"
#include "mk_win_user_window.h"


#define mk_win_user_ctrl_mlistbox_name_a "mkwclb"
#define mk_win_user_ctrl_mlistbox_name_w L"mkwclb"
#define mk_win_user_ctrl_mlistbox_name_t mk_win_tstring_tchar_c("mkwclb")


enum mk_win_user_ctrl_mlistbox_style_e
{
	mk_win_user_ctrl_mlistbox_style_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_mlistbox_style_e mk_win_user_ctrl_mlistbox_style_t;

enum mk_win_user_ctrl_mlistbox_notify_e
{
	mk_win_user_ctrl_mlistbox_notify_e_selchange,
	mk_win_user_ctrl_mlistbox_notify_e_dblclk,
	mk_win_user_ctrl_mlistbox_notify_e_return,
	mk_win_user_ctrl_mlistbox_notify_e_get_string,
	mk_win_user_ctrl_mlistbox_notify_e_dummy_end
};
typedef enum mk_win_user_ctrl_mlistbox_notify_e mk_win_user_ctrl_mlistbox_notify_t;

enum mk_win_user_ctrl_mlistbox_message_e
{
	mk_win_user_ctrl_mlistbox_message_e_dummy_start = mk_win_user_message_id_e_user,
	mk_win_user_ctrl_mlistbox_message_e_setcursel,
	mk_win_user_ctrl_mlistbox_message_e_getcursel,
	mk_win_user_ctrl_mlistbox_message_e_set_strings_count,
	mk_win_user_ctrl_mlistbox_message_e_dummy_end
};
typedef enum mk_win_user_ctrl_mlistbox_message_e mk_win_user_ctrl_mlistbox_message_t;

enum mk_win_user_ctrl_mlistbox_err_e
{
	mk_win_user_ctrl_mlistbox_err_e_okay     =  0, /* not used */
	mk_win_user_ctrl_mlistbox_err_e_err      = -1,
	mk_win_user_ctrl_mlistbox_err_e_errspace = -2, /* not used */
	mk_win_user_ctrl_mlistbox_err_e_dummy_end = 0
};
typedef enum mk_win_user_ctrl_mlistbox_err_e mk_win_user_ctrl_mlistbox_err_t;


struct mk_win_user_ctrl_mlistbox_nmhdr_s
{
	mk_win_user_window_t m_from_window;
	mk_win_base_uint_t m_from_id;
	mk_win_base_uint_t m_code;
};
typedef struct mk_win_user_ctrl_mlistbox_nmhdr_s mk_win_user_ctrl_mlistbox_nmhdr_t;
typedef mk_win_user_ctrl_mlistbox_nmhdr_t const mk_win_user_ctrl_mlistbox_nmhdr_ct;
typedef mk_win_user_ctrl_mlistbox_nmhdr_t* mk_win_user_ctrl_mlistbox_nmhdr_pt;
typedef mk_win_user_ctrl_mlistbox_nmhdr_t const* mk_win_user_ctrl_mlistbox_nmhdr_pct;
typedef mk_win_user_ctrl_mlistbox_nmhdr_t mk_win_base_far* mk_win_user_ctrl_mlistbox_nmhdr_lpt;
typedef mk_win_user_ctrl_mlistbox_nmhdr_t mk_win_base_far const* mk_win_user_ctrl_mlistbox_nmhdr_lpct;
typedef mk_win_user_ctrl_mlistbox_nmhdr_t mk_win_base_near* mk_win_user_ctrl_mlistbox_nmhdr_npt;
typedef mk_win_user_ctrl_mlistbox_nmhdr_t mk_win_base_near const* mk_win_user_ctrl_mlistbox_nmhdr_npct;

#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_win_user_ctrl_mlistbox_notify_get_string_s
{
	mk_win_user_ctrl_mlistbox_nmhdr_t m_hdr;
	int m_idx;
	mk_win_tstring_tchar_lpct m_string;
	int m_string_length;
};
typedef struct mk_win_user_ctrl_mlistbox_notify_get_string_s mk_win_user_ctrl_mlistbox_notify_get_string_t;
typedef mk_win_user_ctrl_mlistbox_notify_get_string_t const mk_win_user_ctrl_mlistbox_notify_get_string_ct;
typedef mk_win_user_ctrl_mlistbox_notify_get_string_t* mk_win_user_ctrl_mlistbox_notify_get_string_pt;
typedef mk_win_user_ctrl_mlistbox_notify_get_string_t const* mk_win_user_ctrl_mlistbox_notify_get_string_pct;
typedef mk_win_user_ctrl_mlistbox_notify_get_string_t mk_win_base_far* mk_win_user_ctrl_mlistbox_notify_get_string_lpt;
typedef mk_win_user_ctrl_mlistbox_notify_get_string_t mk_win_base_far const* mk_win_user_ctrl_mlistbox_notify_get_string_lpct;
typedef mk_win_user_ctrl_mlistbox_notify_get_string_t mk_win_base_near* mk_win_user_ctrl_mlistbox_notify_get_string_npt;
typedef mk_win_user_ctrl_mlistbox_notify_get_string_t mk_win_base_near const* mk_win_user_ctrl_mlistbox_notify_get_string_npct;
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif


#if mk_lang_jumbo_want == 1
#include "mk_win_user_ctrl_mlistbox.c"
#endif
#endif
