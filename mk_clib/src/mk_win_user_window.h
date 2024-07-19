#ifndef mk_include_guard_mk_win_user_window
#define mk_include_guard_mk_win_user_window


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_user_base.h"
#include "mk_win_user_dc.h"
#include "mk_win_user_menu.h"
#include "mk_win_user_region.h"


enum mk_win_user_window_styleex_id_e
{
	mk_win_user_window_styleex_id_e_left                = 0x00000000ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_ltrreading          = 0x00000000ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_rightscrollbar      = 0x00000000ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_dlgmodalframe       = 0x00000001ul,
	mk_win_user_window_styleex_id_e_noparentnotify      = 0x00000004ul,
	mk_win_user_window_styleex_id_e_topmost             = 0x00000008ul,
	mk_win_user_window_styleex_id_e_acceptfiles         = 0x00000010ul,
	mk_win_user_window_styleex_id_e_transparent         = 0x00000020ul,
	mk_win_user_window_styleex_id_e_mdichild            = 0x00000040ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_toolwindow          = 0x00000080ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_windowedge          = 0x00000100ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_clientedge          = 0x00000200ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_contexthelp         = 0x00000400ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_right               = 0x00001000ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_rtlreading          = 0x00002000ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_leftscrollbar       = 0x00004000ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_controlparent       = 0x00010000ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_staticedge          = 0x00020000ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_appwindow           = 0x00040000ul, /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_layered             = 0x00080000ul ,/* _win32_winnt >= 0x0500 */
	mk_win_user_window_styleex_id_e_noinheritlayout     = 0x00100000ul, /* winver >= 0x0500 */
	mk_win_user_window_styleex_id_e_noredirectionbitmap = 0x00200000ul, /* winver >= 0x0602 */
	mk_win_user_window_styleex_id_e_layoutrtl           = 0x00400000ul, /* winver >= 0x0500 */
	mk_win_user_window_styleex_id_e_composited          = 0x02000000ul, /* _win32_winnt >= 0x0501 */
	mk_win_user_window_styleex_id_e_noactivate          = 0x08000000ul, /* _win32_winnt >= 0x0500 */
	mk_win_user_window_styleex_id_e_overlappedwindow    = (mk_win_user_window_styleex_id_e_windowedge | mk_win_user_window_styleex_id_e_clientedge), /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_palettewindow       = (mk_win_user_window_styleex_id_e_windowedge | mk_win_user_window_styleex_id_e_toolwindow| mk_win_user_window_styleex_id_e_topmost), /* winver >= 0x0400 */
	mk_win_user_window_styleex_id_e_dummy_end
};
typedef enum mk_win_user_window_styleex_id_e mk_win_user_window_styleex_id_t;

enum mk_win_user_window_style_id_e
{
	mk_win_user_window_style_id_e_overlapped       = 0x00000000ul,
	mk_win_user_window_style_id_e_maximizebox      = 0x00010000ul,
	mk_win_user_window_style_id_e_minimizebox      = 0x00020000ul,
	mk_win_user_window_style_id_e_tabstop          = 0x00010000ul,
	mk_win_user_window_style_id_e_group            = 0x00020000ul,
	mk_win_user_window_style_id_e_thickframe       = 0x00040000ul,
	mk_win_user_window_style_id_e_sysmenu          = 0x00080000ul,
	mk_win_user_window_style_id_e_hscroll          = 0x00100000ul,
	mk_win_user_window_style_id_e_vscroll          = 0x00200000ul,
	mk_win_user_window_style_id_e_dlgframe         = 0x00400000ul,
	mk_win_user_window_style_id_e_border           = 0x00800000ul,
	mk_win_user_window_style_id_e_maximize         = 0x01000000ul,
	mk_win_user_window_style_id_e_clipchildren     = 0x02000000ul,
	mk_win_user_window_style_id_e_clipsiblings     = 0x04000000ul,
	mk_win_user_window_style_id_e_disabled         = 0x08000000ul,
	mk_win_user_window_style_id_e_visible          = 0x10000000ul,
	mk_win_user_window_style_id_e_minimize         = 0x20000000ul,
	mk_win_user_window_style_id_e_child            = 0x40000000ul,
	mk_win_user_window_style_id_e_popup            = 0x80000000ul,
	mk_win_user_window_style_id_e_tiled            = mk_win_user_window_style_id_e_overlapped,
	mk_win_user_window_style_id_e_sizebox          = mk_win_user_window_style_id_e_thickframe,
	mk_win_user_window_style_id_e_iconic           = mk_win_user_window_style_id_e_minimize,
	mk_win_user_window_style_id_e_caption          = mk_win_user_window_style_id_e_dlgframe | mk_win_user_window_style_id_e_border,
	mk_win_user_window_style_id_e_overlappedwindow = mk_win_user_window_style_id_e_overlapped | mk_win_user_window_style_id_e_maximizebox | mk_win_user_window_style_id_e_minimizebox | mk_win_user_window_style_id_e_thickframe | mk_win_user_window_style_id_e_sysmenu | mk_win_user_window_style_id_e_caption,
	mk_win_user_window_style_id_e_tiledwindow      = mk_win_user_window_style_id_e_overlappedwindow,
	mk_win_user_window_style_id_e_popupwindow      = mk_win_user_window_style_id_e_sysmenu | mk_win_user_window_style_id_e_border | mk_win_user_window_style_id_e_popup,
	mk_win_user_window_style_id_e_childwindow      = mk_win_user_window_style_id_e_child,
	mk_win_user_window_style_id_e_dummy_end
};
typedef enum mk_win_user_window_style_id_e mk_win_user_window_style_id_t;

enum mk_win_user_window_data_id_e
{
	mk_win_user_window_data_id_e_userdata   = -21,
	mk_win_user_window_data_id_e_exstyle    = -20,
	mk_win_user_window_data_id_e_style      = -16,
	mk_win_user_window_data_id_e_id         = -12,
	mk_win_user_window_data_id_e_hwndparent =  -8,
	mk_win_user_window_data_id_e_hinstance  =  -6,
	mk_win_user_window_data_id_e_wndproc    =  -4,
	mk_win_user_window_data_id_e_dummy_end
};
typedef enum mk_win_user_window_data_id_e mk_win_user_window_data_id_t;

enum mk_win_user_window_show_e
{
	mk_win_user_window_show_e_hide            =  0,
	mk_win_user_window_show_e_shownormal      =  1,
	mk_win_user_window_show_e_normal          =  1,
	mk_win_user_window_show_e_showminimized   =  2,
	mk_win_user_window_show_e_showmaximized   =  3,
	mk_win_user_window_show_e_maximize        =  3,
	mk_win_user_window_show_e_shownoactivate  =  4,
	mk_win_user_window_show_e_show            =  5,
	mk_win_user_window_show_e_minimize        =  6,
	mk_win_user_window_show_e_showminnoactive =  7,
	mk_win_user_window_show_e_showna          =  8,
	mk_win_user_window_show_e_restore         =  9,
	mk_win_user_window_show_e_showdefault     = 10,
	mk_win_user_window_show_e_forceminimize   = 11,
	mk_win_user_window_show_e_max             = 11,
	mk_win_user_window_show_e_dummy_end
};
typedef enum mk_win_user_window_show_e mk_win_user_window_show_t;

enum mk_win_user_window_scrollbar_e
{
	mk_win_user_window_scrollbar_e_horz = 0,
	mk_win_user_window_scrollbar_e_vert = 1,
	mk_win_user_window_scrollbar_e_ctl  = 2,
	mk_win_user_window_scrollbar_e_both = 3,
	mk_win_user_window_scrollbar_e_dummy_end
};
typedef enum mk_win_user_window_scrollbar_e mk_win_user_window_scrollbar_t;

enum mk_win_user_window_scrollbar_arrow_e
{
	mk_win_user_window_scrollbar_arrow_e_enable_both   = 0x0000,
	mk_win_user_window_scrollbar_arrow_e_disable_both  = 0x0003,
	mk_win_user_window_scrollbar_arrow_e_disable_left  = 0x0001,
	mk_win_user_window_scrollbar_arrow_e_disable_right = 0x0002,
	mk_win_user_window_scrollbar_arrow_e_disable_up    = 0x0001,
	mk_win_user_window_scrollbar_arrow_e_disable_down  = 0x0002,
	mk_win_user_window_scrollbar_arrow_e_dummy_end
};
typedef enum mk_win_user_window_scrollbar_arrow_e mk_win_user_window_scrollbar_arrow_t;

enum mk_win_user_window_scrollbar_info_e
{
	mk_win_user_window_scrollbar_info_e_range           =  0x0001,
	mk_win_user_window_scrollbar_info_e_page            =  0x0002,
	mk_win_user_window_scrollbar_info_e_pos             =  0x0004,
	mk_win_user_window_scrollbar_info_e_disablenoscroll =  0x0008,
	mk_win_user_window_scrollbar_info_e_trackpos        =  0x0010,
	mk_win_user_window_scrollbar_info_e_all             =  mk_win_user_window_scrollbar_info_e_range | mk_win_user_window_scrollbar_info_e_page | mk_win_user_window_scrollbar_info_e_pos | mk_win_user_window_scrollbar_info_e_trackpos,
	mk_win_user_window_scrollbar_info_e_dummy_end
};
typedef enum mk_win_user_window_scrollbar_info_e mk_win_user_window_scrollbar_info_t;


#define mk_win_user_window_use_default ((mk_win_base_sint_t)(0x80000000ul))


struct mk_win_user_window_scrollinfo_s
{
	mk_win_base_uint_t m_len;
	mk_win_base_uint_t m_mask;
	mk_win_base_sint_t m_min;
	mk_win_base_sint_t m_max;
	mk_win_base_uint_t m_page;
	mk_win_base_sint_t m_pos;
	mk_win_base_sint_t m_track_pos;
};
typedef struct mk_win_user_window_scrollinfo_s mk_win_user_window_scrollinfo_t;
typedef mk_win_user_window_scrollinfo_t const mk_win_user_window_scrollinfo_ct;
typedef mk_win_user_window_scrollinfo_t* mk_win_user_window_scrollinfo_pt;
typedef mk_win_user_window_scrollinfo_t const* mk_win_user_window_scrollinfo_pct;
typedef mk_win_user_window_scrollinfo_t mk_win_base_far* mk_win_user_window_scrollinfo_lpt;
typedef mk_win_user_window_scrollinfo_t mk_win_base_far const* mk_win_user_window_scrollinfo_lpct;
typedef mk_win_user_window_scrollinfo_t mk_win_base_near* mk_win_user_window_scrollinfo_npt;
typedef mk_win_user_window_scrollinfo_t mk_win_base_near const* mk_win_user_window_scrollinfo_npct;
typedef mk_win_user_window_scrollinfo_t* mk_lang_restrict mk_win_user_window_scrollinfo_prt;
typedef mk_win_user_window_scrollinfo_t const* mk_lang_restrict mk_win_user_window_scrollinfo_prct;
typedef mk_win_user_window_scrollinfo_t mk_win_base_far* mk_lang_restrict mk_win_user_window_scrollinfo_lprt;
typedef mk_win_user_window_scrollinfo_t mk_win_base_far const* mk_lang_restrict mk_win_user_window_scrollinfo_lprct;
typedef mk_win_user_window_scrollinfo_t mk_win_base_near* mk_lang_restrict mk_win_user_window_scrollinfo_nprt;
typedef mk_win_user_window_scrollinfo_t mk_win_base_near const* mk_lang_restrict mk_win_user_window_scrollinfo_nprct;


mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_wnd_t mk_win_user_window_a_create(mk_win_base_pchar_lpct const class_name, mk_win_base_pchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_wnd_t mk_win_user_window_w_create(mk_win_base_wchar_lpct const class_name, mk_win_base_wchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_wnd_t mk_win_user_window_a_createex(mk_win_base_dword_t const styleex, mk_win_base_pchar_lpct const class_name, mk_win_base_pchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_wnd_t mk_win_user_window_w_createex(mk_win_base_dword_t const styleex, mk_win_base_wchar_lpct const class_name, mk_win_base_wchar_lpct const window_name, mk_win_base_dword_t const style, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h, mk_win_user_base_wnd_t const parent, mk_win_user_menu_t const menu, mk_win_base_instance_t const instance, mk_win_base_void_lpt const param) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_show(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const show) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_update(mk_win_user_base_wnd_t const wnd) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_scrollbar_show(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const bar, mk_win_base_bool_t const show) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_scrollbar_enable(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const flags, mk_win_base_uint_t const arrows) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_scrollbar_info_set(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const bar, mk_win_user_window_scrollinfo_lpct const scrollinfo, mk_win_base_bool_t const redraw) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_lresult_t mk_win_user_window_a_def_proc(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_lresult_t mk_win_user_window_w_def_proc(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_wparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_w_data_set(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const idx, mk_win_base_uintptr_t const newdata) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_uintptr_t mk_win_user_window_w_data_get(mk_win_user_base_wnd_t const wnd, mk_win_base_sint_t const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_pos_set(mk_win_user_base_wnd_t const wnd, mk_win_user_base_wnd_t const insert_after, mk_win_base_sint_t const x, mk_win_base_sint_t const y, mk_win_base_sint_t const w, mk_win_base_sint_t const h, mk_win_base_uint_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_base_lresult_t mk_win_user_window_w_msg_send(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_lparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_w_msg_post(mk_win_user_base_wnd_t const wnd, mk_win_base_uint_t const msg, mk_win_user_base_lparam_t const wparam, mk_win_user_base_lparam_t const lparam) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_invalidate_region(mk_win_user_base_wnd_t const wnd, mk_win_user_region_t const region, mk_win_base_bool_t const erase) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_get_rect_client(mk_win_user_base_wnd_t const wnd, mk_win_base_rect_lpt const rect) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_dc_t mk_win_user_window_dc_get_client(mk_win_user_base_wnd_t const wnd) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_user_window_dc_release(mk_win_user_base_wnd_t const wnd, mk_win_user_dc_t const dc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_user_dc_t mk_win_user_window_paint_begin(mk_win_user_base_wnd_t const wnd, mk_win_user_base_ps_lpt const ps) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_paint_end(mk_win_user_base_wnd_t const wnd, mk_win_user_base_ps_lpct const ps) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_user_window_rect_adjust_ex(mk_win_base_rect_lpt const rect, mk_win_base_dword_t const style, mk_win_base_bool_t const menu, mk_win_base_dword_t const styleex) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_user_window.c"
#endif
#endif
