#ifndef mk_include_guard_mk_win_comctl_base
#define mk_include_guard_mk_win_comctl_base


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"


struct mk_win_comctl_base_nmhdr_s
{
	mk_win_user_base_wnd_t m_wnd;
	mk_win_base_uintptr_t m_id_from;
	mk_win_base_uint_t m_code;
};
typedef struct mk_win_comctl_base_nmhdr_s mk_win_comctl_base_nmhdr_t;
typedef mk_win_comctl_base_nmhdr_t const mk_win_comctl_base_nmhdr_ct;
typedef mk_win_comctl_base_nmhdr_t* mk_win_comctl_base_nmhdr_pt;
typedef mk_win_comctl_base_nmhdr_t const* mk_win_comctl_base_nmhdr_pct;


mk_lang_jumbo mk_lang_types_void_t mk_win_comctl_base_init(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_comctl_base.c"
#endif
#endif
