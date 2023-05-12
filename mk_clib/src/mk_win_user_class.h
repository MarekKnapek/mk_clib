#ifndef include_guard_mk_win_user_class
#define include_guard_mk_win_user_class


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_win_base.h"
#include "mk_win_kernel_atom.h"
#include "mk_win_tstring.h"
#include "mk_win_user_brush.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_icon.h"
#include "mk_win_user_window.h"


enum mk_win_user_class_style_e
{
	mk_win_user_class_style_e_dummy_none = 0,
	mk_win_user_class_style_e_vredraw         =     0x0001ul,
	mk_win_user_class_style_e_hredraw         =     0x0002ul,
	mk_win_user_class_style_e_keycvtwindow    =     0x0004ul,
	mk_win_user_class_style_e_dblclks         =     0x0008ul,
	mk_win_user_class_style_e_unknown_10      =     0x0010ul,
	mk_win_user_class_style_e_owndc           =     0x0020ul,
	mk_win_user_class_style_e_classdc         =     0x0040ul,
	mk_win_user_class_style_e_parentdc        =     0x0080ul,
	mk_win_user_class_style_e_nokeycvt        =     0x0100ul,
	mk_win_user_class_style_e_noclose         =     0x0200ul,
	mk_win_user_class_style_e_unknown_400     =     0x0400ul,
	mk_win_user_class_style_e_savebits        =     0x0800ul,
	mk_win_user_class_style_e_bytealignclient =     0x1000ul,
	mk_win_user_class_style_e_bytealignwindow =     0x2000ul,
	mk_win_user_class_style_e_globalclass     =     0x4000ul,
	mk_win_user_class_style_e_unknown_800     =     0x8000ul,
	mk_win_user_class_style_e_ime             = 0x00010000ul,
	mk_win_user_class_style_e_dropshadow      = 0x00020000ul,
	mk_win_user_class_style_e_dummy_end = 0
};
typedef enum mk_win_user_class_style_e mk_win_user_class_style_t;


#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_win_user_class_a_s
{
	mk_win_base_uint_t m_style;
	mk_win_user_window_wndproc_t m_wndproc;
	int m_class_extra;
	int m_wnd_extra;
	mk_win_base_instance_t m_instance;
	mk_win_user_icon_t m_icon;
	mk_win_user_cursor_t m_cursor;
	mk_win_user_brush_t m_background;
	mk_win_base_pchar_lpct m_menu_name;
	mk_win_base_pchar_lpct m_class_name;
};
typedef struct mk_win_user_class_a_s mk_win_user_class_a_t;
typedef mk_win_user_class_a_t const mk_win_user_class_a_ct;
typedef mk_win_user_class_a_t* mk_win_user_class_a_pt;
typedef mk_win_user_class_a_t const* mk_win_user_class_a_pct;
typedef mk_win_user_class_a_t mk_win_base_far* mk_win_user_class_a_lpt;
typedef mk_win_user_class_a_t mk_win_base_far const* mk_win_user_class_a_lpct;
typedef mk_win_user_class_a_t mk_win_base_near* mk_win_user_class_a_npt;
typedef mk_win_user_class_a_t mk_win_base_near const* mk_win_user_class_a_npct;
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif

#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_win_user_class_w_s
{
	mk_win_base_uint_t m_style;
	mk_win_user_window_wndproc_t m_wndproc;
	int m_class_extra;
	int m_wnd_extra;
	mk_win_base_instance_t m_instance;
	mk_win_user_icon_t m_icon;
	mk_win_user_cursor_t m_cursor;
	mk_win_user_brush_t m_background;
	mk_win_base_wchar_lpct m_menu_name;
	mk_win_base_wchar_lpct m_class_name;
};
typedef struct mk_win_user_class_w_s mk_win_user_class_w_t;
typedef mk_win_user_class_w_t const mk_win_user_class_w_ct;
typedef mk_win_user_class_w_t* mk_win_user_class_w_pt;
typedef mk_win_user_class_w_t const* mk_win_user_class_w_pct;
typedef mk_win_user_class_w_t mk_win_base_far* mk_win_user_class_w_lpt;
typedef mk_win_user_class_w_t mk_win_base_far const* mk_win_user_class_w_lpct;
typedef mk_win_user_class_w_t mk_win_base_near* mk_win_user_class_w_npt;
typedef mk_win_user_class_w_t mk_win_base_near const* mk_win_user_class_w_npct;
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif

#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_win_user_class_t_s
{
	mk_win_base_uint_t m_style;
	mk_win_user_window_wndproc_t m_wndproc;
	int m_class_extra;
	int m_wnd_extra;
	mk_win_base_instance_t m_instance;
	mk_win_user_icon_t m_icon;
	mk_win_user_cursor_t m_cursor;
	mk_win_user_brush_t m_background;
	mk_win_tstring_tchar_lpct m_menu_name;
	mk_win_tstring_tchar_lpct m_class_name;
};
typedef struct mk_win_user_class_t_s mk_win_user_class_t_t;
typedef mk_win_user_class_t_t const mk_win_user_class_t_ct;
typedef mk_win_user_class_t_t* mk_win_user_class_t_pt;
typedef mk_win_user_class_t_t const* mk_win_user_class_t_pct;
typedef mk_win_user_class_t_t mk_win_base_far* mk_win_user_class_t_lpt;
typedef mk_win_user_class_t_t mk_win_base_far const* mk_win_user_class_t_lpct;
typedef mk_win_user_class_t_t mk_win_base_near* mk_win_user_class_t_npt;
typedef mk_win_user_class_t_t mk_win_base_near const* mk_win_user_class_t_npct;
#if defined _MSC_VER && _MSC_VER == 1935
#pragma warning(pop)
#endif


mk_lang_jumbo mk_win_kernel_atom_t mk_win_user_class_a_register(mk_win_user_class_a_lpct const klass) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_a_unregister_by_name(mk_win_base_pchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_a_unregister_by_atom(mk_win_kernel_atom_t const atom, mk_win_base_instance_t const instance) mk_lang_noexcept;

mk_lang_jumbo mk_win_kernel_atom_t mk_win_user_class_w_register(mk_win_user_class_w_lpct const klass) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_w_unregister_by_name(mk_win_base_wchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_w_unregister_by_atom(mk_win_kernel_atom_t const atom, mk_win_base_instance_t const instance) mk_lang_noexcept;

mk_lang_jumbo mk_win_kernel_atom_t mk_win_user_class_t_register(mk_win_user_class_t_lpct const klass) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_t_unregister_by_name(mk_win_tstring_tchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_t_unregister_by_atom(mk_win_kernel_atom_t const atom, mk_win_base_instance_t const instance) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_class.c"
#endif
#endif
