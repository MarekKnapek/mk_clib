#ifndef include_guard_mk_win_ctrl_impl_mlistbox
#define include_guard_mk_win_ctrl_impl_mlistbox


#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_gdi_font.h"
#include "mk_win_tstring.h"
#include "mk_win_user_window.h"


#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_win_ctrl_impl_mlistbox_s
{
	mk_win_user_window_t m_self;
	mk_win_gdi_font_t m_font;
	mk_win_base_rect_t m_rect_client;
	int m_item_height;
	int m_xwidth;
	int m_lines_fully_visible;
	int m_lines_partially_visible;
	int m_scroll_cur;
	int m_scroll_max;
	int m_strings_count;
	int m_cur_sel;
	mk_lang_bool_t m_has_focus;
};
typedef struct mk_win_ctrl_impl_mlistbox_s mk_win_ctrl_impl_mlistbox_t;
typedef mk_win_ctrl_impl_mlistbox_t const mk_win_ctrl_impl_mlistbox_ct;
typedef mk_win_ctrl_impl_mlistbox_t* mk_win_ctrl_impl_mlistbox_pt;
typedef mk_win_ctrl_impl_mlistbox_t const* mk_win_ctrl_impl_mlistbox_pct;
typedef mk_win_ctrl_impl_mlistbox_t mk_win_base_far* mk_win_ctrl_impl_mlistbox_lpt;
typedef mk_win_ctrl_impl_mlistbox_t mk_win_base_far const* mk_win_ctrl_impl_mlistbox_lpct;
typedef mk_win_ctrl_impl_mlistbox_t mk_win_base_near* mk_win_ctrl_impl_mlistbox_npt;
typedef mk_win_ctrl_impl_mlistbox_t mk_win_base_near const* mk_win_ctrl_impl_mlistbox_npct;
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif


mk_lang_jumbo void mk_win_ctrl_impl_mlistbox_register(void) mk_lang_noexcept;
mk_lang_jumbo void mk_win_ctrl_impl_mlistbox_unregister(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_ctrl_impl_mlistbox.c"
#endif
#endif
