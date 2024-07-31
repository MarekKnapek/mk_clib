#ifndef mk_include_guard_mk_win_user_class
#define mk_include_guard_mk_win_user_class


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"
#include "mk_win_user_brush.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_icon.h"


enum mk_win_user_class_style_id_e
{
 mk_win_user_class_style_id_e_vredraw         = 0x00000001ul,
 mk_win_user_class_style_id_e_hredraw         = 0x00000002ul,
 mk_win_user_class_style_id_e_dblclks         = 0x00000008ul,
 mk_win_user_class_style_id_e_owndc           = 0x00000020ul,
 mk_win_user_class_style_id_e_classdc         = 0x00000040ul,
 mk_win_user_class_style_id_e_parentdc        = 0x00000080ul,
 mk_win_user_class_style_id_e_noclose         = 0x00000200ul,
 mk_win_user_class_style_id_e_savebits        = 0x00000800ul,
 mk_win_user_class_style_id_e_bytealignclient = 0x00001000ul,
 mk_win_user_class_style_id_e_bytealignwindow = 0x00002000ul,
 mk_win_user_class_style_id_e_globalclass     = 0x00004000ul,
 mk_win_user_class_style_id_e_ime             = 0x00010000ul,
 mk_win_user_class_style_id_e_dropshadow      = 0x00020000ul, /* _win32_winnt >= 0x0501 */
 mk_win_user_class_style_id_e_dummy_end
};
typedef enum mk_win_user_class_style_id_e mk_win_user_class_style_id_t;


#if mk_lang_version_at_least_cpp_17 || mk_lang_version_at_least_msvc_cpp_17
typedef mk_win_user_base_lresult_t(mk_win_base_stdcall*mk_win_user_class_callback_t)(mk_win_user_base_wnd_t, mk_win_base_uint_t, mk_win_user_base_wparam_t, mk_win_user_base_lparam_t) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_win_user_base_lresult_t mk_win_base_stdcall mk_win_user_class_callback_dummy(mk_win_user_base_wnd_t, mk_win_base_uint_t, mk_win_user_base_wparam_t, mk_win_user_base_lparam_t) mk_lang_noexcept;
typedef decltype(&mk_win_user_class_callback_dummy) mk_win_user_class_callback_t;
#else
typedef mk_win_user_base_lresult_t(mk_win_base_stdcall*mk_win_user_class_callback_t)(mk_win_user_base_wnd_t, mk_win_base_uint_t, mk_win_user_base_wparam_t, mk_win_user_base_lparam_t) mk_lang_noexcept;
#endif


struct mk_win_user_class_a_s
{
	mk_win_base_uint_t m_len;
	mk_win_base_uint_t m_style;
	mk_win_user_class_callback_t m_callback;
	mk_win_base_sint_t m_tra_cls;
	mk_win_base_sint_t m_tra_wnd;
	mk_win_base_instance_t m_instance;
	mk_win_user_icon_t m_icon_big;
	mk_win_user_cursor_t m_cursor;
	mk_win_user_brush_t m_background;
	mk_win_base_pchar_lpct m_menu;
	mk_win_base_pchar_lpct m_name;
};
typedef struct mk_win_user_class_a_s mk_win_user_class_a_t;
typedef mk_win_user_class_a_t const mk_win_user_class_a_ct;
typedef mk_win_user_class_a_t* mk_win_user_class_a_pt;
typedef mk_win_user_class_a_t const* mk_win_user_class_a_pct;
typedef mk_win_user_class_a_t mk_win_base_far* mk_win_user_class_a_lpt;
typedef mk_win_user_class_a_t mk_win_base_far const* mk_win_user_class_a_lpct;
typedef mk_win_user_class_a_t mk_win_base_near* mk_win_user_class_a_npt;
typedef mk_win_user_class_a_t mk_win_base_near const* mk_win_user_class_a_npct;
typedef mk_win_user_class_a_t* mk_lang_restrict mk_win_user_class_a_prt;
typedef mk_win_user_class_a_t const* mk_lang_restrict mk_win_user_class_a_prct;
typedef mk_win_user_class_a_t mk_win_base_far* mk_lang_restrict mk_win_user_class_a_lprt;
typedef mk_win_user_class_a_t mk_win_base_far const* mk_lang_restrict mk_win_user_class_a_lprct;
typedef mk_win_user_class_a_t mk_win_base_near* mk_lang_restrict mk_win_user_class_a_nprt;
typedef mk_win_user_class_a_t mk_win_base_near const* mk_lang_restrict mk_win_user_class_a_nprct;

struct mk_win_user_class_w_s
{
	mk_win_base_uint_t m_len;
	mk_win_base_uint_t m_style;
	mk_win_user_class_callback_t m_callback;
	mk_win_base_sint_t m_tra_cls;
	mk_win_base_sint_t m_tra_wnd;
	mk_win_base_instance_t m_instance;
	mk_win_user_icon_t m_icon_big;
	mk_win_user_cursor_t m_cursor;
	mk_win_user_brush_t m_background;
	mk_win_base_wchar_lpct m_menu;
	mk_win_base_wchar_lpct m_name;
};
typedef struct mk_win_user_class_w_s mk_win_user_class_w_t;
typedef mk_win_user_class_w_t const mk_win_user_class_w_ct;
typedef mk_win_user_class_w_t* mk_win_user_class_w_pt;
typedef mk_win_user_class_w_t const* mk_win_user_class_w_pct;
typedef mk_win_user_class_w_t mk_win_base_far* mk_win_user_class_w_lpt;
typedef mk_win_user_class_w_t mk_win_base_far const* mk_win_user_class_w_lpct;
typedef mk_win_user_class_w_t mk_win_base_near* mk_win_user_class_w_npt;
typedef mk_win_user_class_w_t mk_win_base_near const* mk_win_user_class_w_npct;
typedef mk_win_user_class_w_t* mk_lang_restrict mk_win_user_class_w_prt;
typedef mk_win_user_class_w_t const* mk_lang_restrict mk_win_user_class_w_prct;
typedef mk_win_user_class_w_t mk_win_base_far* mk_lang_restrict mk_win_user_class_w_lprt;
typedef mk_win_user_class_w_t mk_win_base_far const* mk_lang_restrict mk_win_user_class_w_lprct;
typedef mk_win_user_class_w_t mk_win_base_near* mk_lang_restrict mk_win_user_class_w_nprt;
typedef mk_win_user_class_w_t mk_win_base_near const* mk_lang_restrict mk_win_user_class_w_nprct;

struct mk_win_user_class_exa_s
{
	mk_win_base_uint_t m_len;
	mk_win_base_uint_t m_style;
	mk_win_user_class_callback_t m_callback;
	mk_win_base_sint_t m_extra_cls;
	mk_win_base_sint_t m_extra_wnd;
	mk_win_base_instance_t m_instance;
	mk_win_user_icon_t m_icon_big;
	mk_win_user_cursor_t m_cursor;
	mk_win_user_brush_t m_background;
	mk_win_base_pchar_lpct m_menu;
	mk_win_base_pchar_lpct m_name;
	mk_win_user_icon_t m_icon_smol;
};
typedef struct mk_win_user_class_exa_s mk_win_user_class_exa_t;
typedef mk_win_user_class_exa_t const mk_win_user_class_exa_ct;
typedef mk_win_user_class_exa_t* mk_win_user_class_exa_pt;
typedef mk_win_user_class_exa_t const* mk_win_user_class_exa_pct;
typedef mk_win_user_class_exa_t mk_win_base_far* mk_win_user_class_exa_lpt;
typedef mk_win_user_class_exa_t mk_win_base_far const* mk_win_user_class_exa_lpct;
typedef mk_win_user_class_exa_t mk_win_base_near* mk_win_user_class_exa_npt;
typedef mk_win_user_class_exa_t mk_win_base_near const* mk_win_user_class_exa_npct;
typedef mk_win_user_class_exa_t* mk_lang_restrict mk_win_user_class_exa_prt;
typedef mk_win_user_class_exa_t const* mk_lang_restrict mk_win_user_class_exa_prct;
typedef mk_win_user_class_exa_t mk_win_base_far* mk_lang_restrict mk_win_user_class_exa_lprt;
typedef mk_win_user_class_exa_t mk_win_base_far const* mk_lang_restrict mk_win_user_class_exa_lprct;
typedef mk_win_user_class_exa_t mk_win_base_near* mk_lang_restrict mk_win_user_class_exa_nprt;
typedef mk_win_user_class_exa_t mk_win_base_near const* mk_lang_restrict mk_win_user_class_exa_nprct;

struct mk_win_user_class_exw_s
{
	mk_win_base_uint_t m_len;
	mk_win_base_uint_t m_style;
	mk_win_user_class_callback_t m_callback;
	mk_win_base_sint_t m_extra_cls;
	mk_win_base_sint_t m_extra_wnd;
	mk_win_base_instance_t m_instance;
	mk_win_user_icon_t m_icon_big;
	mk_win_user_cursor_t m_cursor;
	mk_win_user_brush_t m_background;
	mk_win_base_wchar_lpct m_menu;
	mk_win_base_wchar_lpct m_name;
	mk_win_user_icon_t m_icon_smol;
};
typedef struct mk_win_user_class_exw_s mk_win_user_class_exw_t;
typedef mk_win_user_class_exw_t const mk_win_user_class_exw_ct;
typedef mk_win_user_class_exw_t* mk_win_user_class_exw_pt;
typedef mk_win_user_class_exw_t const* mk_win_user_class_exw_pct;
typedef mk_win_user_class_exw_t mk_win_base_far* mk_win_user_class_exw_lpt;
typedef mk_win_user_class_exw_t mk_win_base_far const* mk_win_user_class_exw_lpct;
typedef mk_win_user_class_exw_t mk_win_base_near* mk_win_user_class_exw_npt;
typedef mk_win_user_class_exw_t mk_win_base_near const* mk_win_user_class_exw_npct;
typedef mk_win_user_class_exw_t* mk_lang_restrict mk_win_user_class_exw_prt;
typedef mk_win_user_class_exw_t const* mk_lang_restrict mk_win_user_class_exw_prct;
typedef mk_win_user_class_exw_t mk_win_base_far* mk_lang_restrict mk_win_user_class_exw_lprt;
typedef mk_win_user_class_exw_t mk_win_base_far const* mk_lang_restrict mk_win_user_class_exw_lprct;
typedef mk_win_user_class_exw_t mk_win_base_near* mk_lang_restrict mk_win_user_class_exw_nprt;
typedef mk_win_user_class_exw_t mk_win_base_near const* mk_lang_restrict mk_win_user_class_exw_nprct;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_atom_t mk_win_user_class_register_a(mk_win_user_class_a_lpct const classa) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_atom_t mk_win_user_class_register_w(mk_win_user_class_w_lpct const classw) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_atom_t mk_win_user_class_register_exa(mk_win_user_class_exa_lpct const classexa) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_atom_t mk_win_user_class_register_exw(mk_win_user_class_exw_lpct const classexw) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_a_unregister(mk_win_base_pchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_class_w_unregister(mk_win_base_wchar_lpct const name, mk_win_base_instance_t const instance) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_class.c"
#endif
#endif
