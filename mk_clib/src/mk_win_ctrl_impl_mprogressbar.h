#ifndef include_guard_mk_win_ctrl_impl_mprogressbar
#define include_guard_mk_win_ctrl_impl_mprogressbar


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_user_window.h"


#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_win_ctrl_impl_mprogressbar_s
{
	mk_win_user_window_t m_self;
	mk_win_user_window_t m_native;
	int m_percent;
};
typedef struct mk_win_ctrl_impl_mprogressbar_s mk_win_ctrl_impl_mprogressbar_t;
typedef mk_win_ctrl_impl_mprogressbar_t const mk_win_ctrl_impl_mprogressbar_ct;
typedef mk_win_ctrl_impl_mprogressbar_t* mk_win_ctrl_impl_mprogressbar_pt;
typedef mk_win_ctrl_impl_mprogressbar_t const* mk_win_ctrl_impl_mprogressbar_pct;
typedef mk_win_ctrl_impl_mprogressbar_t mk_win_base_far* mk_win_ctrl_impl_mprogressbar_lpt;
typedef mk_win_ctrl_impl_mprogressbar_t mk_win_base_far const* mk_win_ctrl_impl_mprogressbar_lpct;
typedef mk_win_ctrl_impl_mprogressbar_t mk_win_base_near* mk_win_ctrl_impl_mprogressbar_npt;
typedef mk_win_ctrl_impl_mprogressbar_t mk_win_base_near const* mk_win_ctrl_impl_mprogressbar_npct;
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif


mk_lang_jumbo void mk_win_ctrl_impl_mprogressbar_register(void) mk_lang_noexcept;
mk_lang_jumbo void mk_win_ctrl_impl_mprogressbar_unregister(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_ctrl_impl_mprogressbar.c"
#endif
#endif
