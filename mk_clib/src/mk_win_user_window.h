#ifndef mk_include_guard_win_user_window
#define mk_include_guard_win_user_window


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_gdi_dc.h"
#include "mk_win_kernel_atom.h"
#include "mk_win_user_menu.h"


enum mk_win_user_window_style_e
{
	mk_win_user_window_style_e_overlapped       = 0x0000ul << 16,
	mk_win_user_window_style_e_maximizebox      = 0x0001ul << 16,
	mk_win_user_window_style_e_tabstop          = 0x0001ul << 16,
	mk_win_user_window_style_e_minimizebox      = 0x0002ul << 16,
	mk_win_user_window_style_e_group            = 0x0002ul << 16,
	mk_win_user_window_style_e_thickframe       = 0x0004ul << 16,
	mk_win_user_window_style_e_sysmenu          = 0x0008ul << 16,
	mk_win_user_window_style_e_hscroll          = 0x0010ul << 16,
	mk_win_user_window_style_e_vscroll          = 0x0020ul << 16,
	mk_win_user_window_style_e_dlgframe         = 0x0040ul << 16,
	mk_win_user_window_style_e_border           = 0x0080ul << 16,
	mk_win_user_window_style_e_maximize         = 0x0100ul << 16,
	mk_win_user_window_style_e_clipchildren     = 0x0200ul << 16,
	mk_win_user_window_style_e_clipsiblings     = 0x0400ul << 16,
	mk_win_user_window_style_e_disabled         = 0x0800ul << 16,
	mk_win_user_window_style_e_visible          = 0x1000ul << 16,
	mk_win_user_window_style_e_minimize         = 0x2000ul << 16,
	mk_win_user_window_style_e_child            = 0x4000ul << 16,
	mk_win_user_window_style_e_popup            = 0x8000ul << 16,
	mk_win_user_window_style_e_tiled            = mk_win_user_window_style_e_overlapped,
	mk_win_user_window_style_e_sizebox          = mk_win_user_window_style_e_thickframe,
	mk_win_user_window_style_e_iconic           = mk_win_user_window_style_e_minimize,
	mk_win_user_window_style_e_childwindow      = mk_win_user_window_style_e_child,
	mk_win_user_window_style_e_caption          = mk_win_user_window_style_e_dlgframe | mk_win_user_window_style_e_border,
	mk_win_user_window_style_e_overlappedwindow = mk_win_user_window_style_e_overlapped | mk_win_user_window_style_e_maximizebox | mk_win_user_window_style_e_minimizebox | mk_win_user_window_style_e_thickframe | mk_win_user_window_style_e_sysmenu | mk_win_user_window_style_e_caption,
	mk_win_user_window_style_e_popupwindow      = mk_win_user_window_style_e_sysmenu | mk_win_user_window_style_e_border | mk_win_user_window_style_e_popup,
	mk_win_user_window_style_e_tiledwindow      = mk_win_user_window_style_e_overlappedwindow,
	mk_win_user_window_style_e_dummy_end        = 0
};
typedef enum mk_win_user_window_style_e mk_win_user_window_style_t;

enum mk_win_user_window_style_ex_e
{
	mk_win_user_window_style_ex_e_left                = 0x00000000ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_ltrreading          = 0x00000000ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_rightscrollbar      = 0x00000000ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_dlgmodalframe       = 0x00000001ul,
	mk_win_user_window_style_ex_e_noparentnotify      = 0x00000004ul,
	mk_win_user_window_style_ex_e_topmost             = 0x00000008ul,
	mk_win_user_window_style_ex_e_acceptfiles         = 0x00000010ul,
	mk_win_user_window_style_ex_e_transparent         = 0x00000020ul,
	mk_win_user_window_style_ex_e_mdichild            = 0x00000040ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_toolwindow          = 0x00000080ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_windowedge          = 0x00000100ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_clientedge          = 0x00000200ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_contexthelp         = 0x00000400ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_right               = 0x00001000ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_rtlreading          = 0x00002000ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_leftscrollbar       = 0x00004000ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_controlparent       = 0x00010000ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_staticedge          = 0x00020000ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_appwindow           = 0x00040000ul, /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_layered             = 0x00080000ul, /* _win32_winnt >= 0x0500 */
	mk_win_user_window_style_ex_e_noinheritlayout     = 0x00100000ul, /* winver >= 0x0500 */
	mk_win_user_window_style_ex_e_noredirectionbitmap = 0x00200000ul, /* winver >= 0x0602 */
	mk_win_user_window_style_ex_e_layoutrtl           = 0x00400000ul, /* winver >= 0x0500 */
	mk_win_user_window_style_ex_e_composited          = 0x02000000ul, /* _win32_winnt >= 0x0501 */
	mk_win_user_window_style_ex_e_noactivate          = 0x08000000ul, /* _win32_winnt >= 0x0500 */
	mk_win_user_window_style_ex_e_overlappedwindow    = (mk_win_user_window_style_ex_e_windowedge | mk_win_user_window_style_ex_e_clientedge), /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_palettewindow       = (mk_win_user_window_style_ex_e_topmost | mk_win_user_window_style_ex_e_toolwindow | mk_win_user_window_style_ex_e_windowedge), /* winver >= 0x0400 */
	mk_win_user_window_style_ex_e_dummy_end = 0
};
typedef enum mk_win_user_window_style_ex_e mk_win_user_window_style_ex_t;

enum mk_win_user_window_data_idx_e
{
	mk_win_user_window_data_idx_e_userdata      = (-21),
	mk_win_user_window_data_idx_e_exstyle       = (-20),
	mk_win_user_window_data_idx_e_style         = (-16),
	mk_win_user_window_data_idx_e_id            = (-12),
	mk_win_user_window_data_idx_e_hwndparent    = ( -8),
	mk_win_user_window_data_idx_e_hinstance     = ( -6),
	mk_win_user_window_data_idx_e_wndproc       = ( -4),
	mk_win_user_window_data_idx_e_custom        = (  0),
	mk_win_user_window_data_idx_e_dlg_msgresult = (  0),
	mk_win_user_window_data_idx_e_dlg_dlgproc   = (mk_win_user_window_data_idx_e_dlg_msgresult + ((int)(sizeof(mk_win_base_sintptr_t)))),
	mk_win_user_window_data_idx_e_dlg_user      = (mk_win_user_window_data_idx_e_dlg_dlgproc + ((int)(sizeof(void(mk_win_base_far mk_win_base_stdcall*)(void))))),
	mk_win_user_window_data_idx_e_dummy_end = 0
};
typedef enum mk_win_user_window_data_idx_e mk_win_user_window_data_idx_t;

enum mk_win_user_window_show_e
{
	mk_win_user_window_show_e_hide            =  0,
	mk_win_user_window_show_e_normal          =  1,
	mk_win_user_window_show_e_shownormal      =  1,
	mk_win_user_window_show_e_showminimized   =  2,
	mk_win_user_window_show_e_maximize        =  3,
	mk_win_user_window_show_e_showmaximized   =  3,
	mk_win_user_window_show_e_shownoactivate  =  4,
	mk_win_user_window_show_e_show            =  5,
	mk_win_user_window_show_e_minimize        =  6,
	mk_win_user_window_show_e_showminnoactive =  7,
	mk_win_user_window_show_e_showna          =  8,
	mk_win_user_window_show_e_restore         =  9,
	mk_win_user_window_show_e_showdefault     = 10,
	mk_win_user_window_show_e_forceminimize   = 11,
	mk_win_user_window_show_e_max             = 11,
	mk_win_user_window_show_e_dummy_end = 0
};
typedef enum mk_win_user_window_show_e mk_win_user_window_show_t;

enum mk_win_user_window_swp_e
{
	mk_win_user_window_swp_e_nosize         = 0x0001ul,
	mk_win_user_window_swp_e_nomove         = 0x0002ul,
	mk_win_user_window_swp_e_nozorder       = 0x0004ul,
	mk_win_user_window_swp_e_noredraw       = 0x0008ul,
	mk_win_user_window_swp_e_noactivate     = 0x0010ul,
	mk_win_user_window_swp_e_framechanged   = 0x0020ul,
	mk_win_user_window_swp_e_showwindow     = 0x0040ul,
	mk_win_user_window_swp_e_hidewindow     = 0x0080ul,
	mk_win_user_window_swp_e_nocopybits     = 0x0100ul,
	mk_win_user_window_swp_e_noownerzorder  = 0x0200ul,
	mk_win_user_window_swp_e_nosendchanging = 0x0400ul,
	mk_win_user_window_swp_e_defererase     = 0x2000ul, /* winver >= 0x0400 */
	mk_win_user_window_swp_e_asyncwindowpos = 0x4000ul, /* winver >= 0x0400 */
	mk_win_user_window_swp_e_drawframe      = mk_win_user_window_swp_e_framechanged,
	mk_win_user_window_swp_e_noreposition   = mk_win_user_window_swp_e_noownerzorder,
	mk_win_user_window_swp_e_dummy_end = 0
};
typedef enum mk_win_user_window_swp_e mk_win_user_window_swp_t;

enum mk_win_user_window_show_scrollbar_e
{
	mk_win_user_window_show_scrollbar_e_horz = 0,
	mk_win_user_window_show_scrollbar_e_vert = 1,
	mk_win_user_window_show_scrollbar_e_ctl  = 2,
	mk_win_user_window_show_scrollbar_e_both = 3,
	mk_win_user_window_show_scrollbar_e_dummy_end = 0
};
typedef enum mk_win_user_window_show_scrollbar_e mk_win_user_window_show_scrollbar_t;


#define mk_win_user_window_usedefault ((int)(0x80000000ul))


#if defined _MSC_VER && _MSC_VER >= 1935
#pragma warning(push)
#pragma warning(disable:4820) /* warning C4820: 'xxx': 'xxx' bytes padding added after data member 'xxx' */
#endif
struct mk_win_user_window_paint_s
{
	mk_win_gdi_dc_t m_dc;
	mk_win_base_bool_t m_erase;
	mk_win_base_rect_t m_rect;
	mk_win_base_bool_t m_restore;
	mk_win_base_bool_t m_update;
	unsigned char m_reserved[32];
};
typedef struct mk_win_user_window_paint_s mk_win_user_window_paint_t;
typedef mk_win_user_window_paint_t const mk_win_user_window_paint_ct;
typedef mk_win_user_window_paint_t* mk_win_user_window_paint_pt;
typedef mk_win_user_window_paint_t const* mk_win_user_window_paint_pct;
typedef mk_win_user_window_paint_t mk_win_base_far* mk_win_user_window_paint_lpt;
typedef mk_win_user_window_paint_t mk_win_base_far const* mk_win_user_window_paint_lpct;
typedef mk_win_user_window_paint_t mk_win_base_near* mk_win_user_window_paint_npt;
typedef mk_win_user_window_paint_t mk_win_base_near const* mk_win_user_window_paint_npct;
#if defined _MSC_VER && _MSC_VER >= 1935
#pragma warning(pop)
#endif


typedef mk_win_base_sintptr_t mk_win_user_window_lresult_t;
typedef mk_win_user_window_lresult_t const mk_win_user_window_lresult_ct;
typedef mk_win_user_window_lresult_t* mk_win_user_window_lresult_pt;
typedef mk_win_user_window_lresult_t const* mk_win_user_window_lresult_pct;
typedef mk_win_user_window_lresult_t mk_win_base_far* mk_win_user_window_lresult_lpt;
typedef mk_win_user_window_lresult_t mk_win_base_far const* mk_win_user_window_lresult_lpct;
typedef mk_win_user_window_lresult_t mk_win_base_near* mk_win_user_window_lresult_npt;
typedef mk_win_user_window_lresult_t mk_win_base_near const* mk_win_user_window_lresult_npct;

typedef mk_win_base_uintptr_t mk_win_user_window_wparam_t;
typedef mk_win_base_uintptr_t mk_win_user_window_lparam_t;
struct mk_win_user_window_handle_s; typedef struct mk_win_user_window_handle_s mk_win_user_window_handle_t; typedef mk_win_user_window_handle_t const* mk_win_user_window_t;
typedef mk_win_user_window_lresult_t(mk_win_base_stdcall*mk_win_user_window_wndproc_t)(mk_win_user_window_t, mk_win_base_uint_t, mk_win_user_window_wparam_t, mk_win_user_window_lparam_t) mk_lang_noexcept;


mk_lang_jumbo mk_win_user_window_t mk_win_user_window_a_create_by_name(mk_win_base_dword_t/*enum*/ const style_ex, mk_win_base_pchar_lpct const class_name, mk_win_base_pchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_t mk_win_user_window_a_create_by_atom(mk_win_base_dword_t const style_ex, mk_win_kernel_atom_t const atom, mk_win_base_pchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_a_set_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx, mk_win_base_uintptr_t const new_data) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_a_get_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_a_defproc(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_a_post(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;
mk_lang_jumbo int mk_win_user_window_a_get_text(mk_win_user_window_t const window, mk_win_base_pchar_lpt const text, int const max_len) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_a_set_text(mk_win_user_window_t const window, mk_win_base_pchar_lpct const text) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_a_call_proc(mk_win_user_window_wndproc_t const proc, mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;

mk_lang_jumbo mk_win_user_window_t mk_win_user_window_w_create_by_name(mk_win_base_dword_t const style_ex, mk_win_base_wchar_lpct const class_name, mk_win_base_wchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_t mk_win_user_window_w_create_by_atom(mk_win_base_dword_t const style_ex, mk_win_kernel_atom_t const atom, mk_win_base_wchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_w_set_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx, mk_win_base_uintptr_t const new_data) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_w_get_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_w_defproc(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_w_post(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;
mk_lang_jumbo int mk_win_user_window_w_get_text(mk_win_user_window_t const window, mk_win_base_wchar_lpt const text, int const max_len) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_w_set_text(mk_win_user_window_t const window, mk_win_base_wchar_lpct const text) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_w_call_proc(mk_win_user_window_wndproc_t const proc, mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;

mk_lang_jumbo mk_win_user_window_t mk_win_user_window_t_create_by_name(mk_win_base_dword_t const style_ex, mk_win_tstring_tchar_lpct const class_name, mk_win_tstring_tchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_t mk_win_user_window_t_create_by_atom(mk_win_base_dword_t const style_ex, mk_win_kernel_atom_t const atom, mk_win_tstring_tchar_lpct const window_name, mk_win_base_dword_t const style, int const x, int const y, int const width, int const height, mk_win_user_window_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_t_set_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx, mk_win_base_uintptr_t const new_data) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_t_get_data(mk_win_user_window_t const window, mk_win_user_window_data_idx_t const idx) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_t_defproc(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_t_post(mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;
mk_lang_jumbo int mk_win_user_window_t_get_text(mk_win_user_window_t const window, mk_win_tstring_tchar_lpt const text, int const max_len) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_t_set_text(mk_win_user_window_t const window, mk_win_tstring_tchar_lpct const text) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_lresult_t mk_win_user_window_t_call_proc(mk_win_user_window_wndproc_t const proc, mk_win_user_window_t const window, mk_win_base_uint_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;

mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_show(mk_win_user_window_t const window, mk_win_user_window_show_t const show) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_update(mk_win_user_window_t const window) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_get_client_rect(mk_win_user_window_t const window, mk_win_base_rect_lpt const rect) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_get_rect(mk_win_user_window_t const window, mk_win_base_rect_lpt const rect) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_set_pos(mk_win_user_window_t const window, mk_win_user_window_t const insert_after, int const x, int const y, int const width, int const height, mk_win_user_window_swp_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_gdi_dc_t mk_win_user_window_begin_paint(mk_win_user_window_t const window, mk_win_user_window_paint_lpt const paint) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_end_paint(mk_win_user_window_t const window, mk_win_user_window_paint_lpct const paint) mk_lang_noexcept;
mk_lang_jumbo mk_win_user_window_t mk_win_user_window_set_focus(mk_win_user_window_t const window) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_window_t mk_win_user_window_get_parent(mk_win_user_window_t const window) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_show_scrollbar(mk_win_user_window_t const window, mk_win_user_window_show_scrollbar_t const bar, mk_win_base_bool_t const show) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_user_window_t mk_win_user_window_get_desktop(void) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_window.c"
#endif
#endif
