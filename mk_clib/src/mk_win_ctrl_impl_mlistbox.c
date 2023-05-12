#include "mk_win_ctrl_impl_mlistbox.h"

#include "mk_lang_abs.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_clamp.h"
#include "mk_lang_clobber.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_exception.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_gdi_bitmap.h"
#include "mk_win_gdi_dc.h"
#include "mk_win_gdi_font.h"
#include "mk_win_gdi_object.h"
#include "mk_win_kernel_atom.h"
#include "mk_win_kernel_dll.h"
#include "mk_win_kernel_errors.h"
#include "mk_win_main_heap.h"
#include "mk_win_tstring.h"
#include "mk_win_user_brush.h"
#include "mk_win_user_class.h"
#include "mk_win_user_color.h"
#include "mk_win_user_ctrl_mlistbox.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_message.h"
#include "mk_win_user_system_information.h"
#include "mk_win_user_window.h"





enum scroll_bar_id_e
{
	scroll_bar_id_e_horz = 0,
	scroll_bar_id_e_vert = 1,
	scroll_bar_id_e_ctl  = 2,
	scroll_bar_id_e_both = 3
};
typedef enum scroll_bar_id_e scroll_bar_id_t;

enum scroll_bar_event_e
{
	scroll_bar_event_e_lineleft      = 0,
	scroll_bar_event_e_lineup        = 0,
	scroll_bar_event_e_lineright     = 1,
	scroll_bar_event_e_linedown      = 1,
	scroll_bar_event_e_pageleft      = 2,
	scroll_bar_event_e_pageup        = 2,
	scroll_bar_event_e_pageright     = 3,
	scroll_bar_event_e_pagedown      = 3,
	scroll_bar_event_e_thumbposition = 4,
	scroll_bar_event_e_thumbtrack    = 5,
	scroll_bar_event_e_left          = 6,
	scroll_bar_event_e_top           = 6,
	scroll_bar_event_e_right         = 7,
	scroll_bar_event_e_bottom        = 7,
	scroll_bar_event_e_endscroll     = 8
};
typedef enum scroll_bar_event_e scroll_bar_event_t;

enum scroll_bar_enable_e
{
	scroll_bar_enable_e_enable_both   = 0,
	scroll_bar_enable_e_disable_left  = 1,
	scroll_bar_enable_e_disable_up    = 1,
	scroll_bar_enable_e_disable_right = 2,
	scroll_bar_enable_e_disable_down  = 2,
	scroll_bar_enable_e_disable_both  = 3,
	scroll_bar_enable_e_disable_ltup  = scroll_bar_enable_e_disable_left,
	scroll_bar_enable_e_disable_rtdn  = scroll_bar_enable_e_disable_right
};
typedef enum scroll_bar_enable_e scroll_bar_enable_t;


mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ShowScrollBar(mk_win_user_window_t, int, mk_win_base_bool_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetScrollRange(mk_win_user_window_t, int, int, int, mk_win_base_bool_t) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall EnableScrollBar(mk_win_user_window_t, mk_win_base_uint_t, mk_win_base_uint_t) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall SetScrollPos(mk_win_user_window_t, int, int, mk_win_base_bool_t) mk_lang_noexcept;
mk_win_base_dll_import int mk_win_base_stdcall GetScrollPos(mk_win_user_window_t, int) mk_lang_noexcept;
mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ScrollWindow(mk_win_user_window_t, int, int, mk_win_base_rect_lpct, mk_win_base_rect_lpct) mk_lang_noexcept;





static mk_win_kernel_atom_t g_mk_win_ctrl_impl_mlistbox_atom;


static mk_lang_inline void mk_win_ctrl_impl_mlistbox_recalculate_font(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_recalculate_lines_visible(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_recalculate_scroll_max(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_scrollbars_init(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_scrollbars_reset(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_invalidate_item(mk_win_ctrl_impl_mlistbox_lpt const self, int const idx) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_do_scroll(mk_win_ctrl_impl_mlistbox_lpt const self, int const scroll_cur_new) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_do_scroll_to_make_visible(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_do_select_idx(mk_win_ctrl_impl_mlistbox_lpt const self, int const cur_sel_new) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_do_select_xy(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_base_sshort_t const x, mk_win_base_sshort_t const y) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_fire_selchange(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_fire_lbuttondblclk(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_fire_return(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_create(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_size(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_setfocus(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_killfocus(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_paint(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_setfont(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_getfont(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_getdlgcode(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_return(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_prior(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_next(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_end(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_home(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_up(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_down(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_vscroll(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_lbuttondown(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_lbuttondblclk(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_mousewheel(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_setcursel(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_getcursel(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_setcurscroll(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_getcurscroll(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_set_strings_count(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_message_id_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_win_user_window_lresult_t mk_win_base_stdcall mk_win_ctrl_impl_mlistbox_wndproc(mk_win_user_window_t const window, mk_win_base_uint_t const message_uint, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;


mk_lang_jumbo void mk_win_ctrl_impl_mlistbox_register(void) mk_lang_noexcept
{
	mk_win_user_class_t_t wc;
	mk_lang_bool_t got;

	mk_lang_assert(g_mk_win_ctrl_impl_mlistbox_atom == 0);
	wc.m_style = mk_win_user_class_style_e_dblclks;
	wc.m_wndproc = &mk_win_ctrl_impl_mlistbox_wndproc;
	wc.m_class_extra = 0;
	wc.m_wnd_extra = sizeof(mk_win_ctrl_impl_mlistbox_lpt);
	got = mk_win_kernel_dll_t_get_handle_from_address(&g_mk_win_ctrl_impl_mlistbox_atom, ((mk_win_kernel_dll_module_lpt)(&wc.m_instance))); mk_lang_assert(got != 0);
	wc.m_icon = mk_win_base_null;
	wc.m_cursor = mk_win_user_cursor_t_load_by_id(mk_win_user_cursor_id_e_arrow);
	wc.m_background = mk_win_base_null;
	wc.m_menu_name = mk_win_base_null;
	wc.m_class_name = mk_win_user_ctrl_mlistbox_name_t;
	g_mk_win_ctrl_impl_mlistbox_atom = mk_win_user_class_t_register(&wc);
	mk_lang_assert(g_mk_win_ctrl_impl_mlistbox_atom != 0);
}

mk_lang_jumbo void mk_win_ctrl_impl_mlistbox_unregister(void) mk_lang_noexcept
{
	mk_lang_bool_t got;
	mk_win_kernel_dll_module_t module;
	mk_lang_bool_t unregistered;

	got = mk_win_kernel_dll_t_get_handle_from_address(&g_mk_win_ctrl_impl_mlistbox_atom, &module);
	mk_lang_assert(got != 0);
	unregistered = mk_win_user_class_t_unregister_by_atom(g_mk_win_ctrl_impl_mlistbox_atom, ((mk_win_base_instance_t)(module)));
	mk_lang_assert(unregistered == mk_win_base_true);
}


static mk_lang_inline void mk_win_ctrl_impl_mlistbox_recalculate_font(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept
{
	static mk_win_tstring_tchar_t const s_alphabet[] = {mk_win_tstring_tchar_c('a'), mk_win_tstring_tchar_c('b'), mk_win_tstring_tchar_c('c'), mk_win_tstring_tchar_c('d'), mk_win_tstring_tchar_c('e'), mk_win_tstring_tchar_c('f'), mk_win_tstring_tchar_c('g'), mk_win_tstring_tchar_c('h'), mk_win_tstring_tchar_c('i'), mk_win_tstring_tchar_c('j'), mk_win_tstring_tchar_c('k'), mk_win_tstring_tchar_c('l'), mk_win_tstring_tchar_c('m'), mk_win_tstring_tchar_c('n'), mk_win_tstring_tchar_c('o'), mk_win_tstring_tchar_c('p'), mk_win_tstring_tchar_c('q'), mk_win_tstring_tchar_c('r'), mk_win_tstring_tchar_c('s'), mk_win_tstring_tchar_c('t'), mk_win_tstring_tchar_c('u'), mk_win_tstring_tchar_c('v'), mk_win_tstring_tchar_c('w'), mk_win_tstring_tchar_c('x'), mk_win_tstring_tchar_c('y'), mk_win_tstring_tchar_c('z'), mk_win_tstring_tchar_c('A'), mk_win_tstring_tchar_c('B'), mk_win_tstring_tchar_c('C'), mk_win_tstring_tchar_c('D'), mk_win_tstring_tchar_c('E'), mk_win_tstring_tchar_c('F'), mk_win_tstring_tchar_c('G'), mk_win_tstring_tchar_c('H'), mk_win_tstring_tchar_c('I'), mk_win_tstring_tchar_c('J'), mk_win_tstring_tchar_c('K'), mk_win_tstring_tchar_c('L'), mk_win_tstring_tchar_c('M'), mk_win_tstring_tchar_c('N'), mk_win_tstring_tchar_c('O'), mk_win_tstring_tchar_c('P'), mk_win_tstring_tchar_c('Q'), mk_win_tstring_tchar_c('R'), mk_win_tstring_tchar_c('S'), mk_win_tstring_tchar_c('T'), mk_win_tstring_tchar_c('U'), mk_win_tstring_tchar_c('V'), mk_win_tstring_tchar_c('W'), mk_win_tstring_tchar_c('X'), mk_win_tstring_tchar_c('Y'), mk_win_tstring_tchar_c('Z')};
	static int const s_alphabet_len = ((int)(sizeof(s_alphabet) / sizeof(s_alphabet[0])));
	static mk_win_tstring_tchar_t const s_x = mk_win_tstring_tchar_c('x');

	mk_win_gdi_dc_t dc;
	mk_win_gdi_font_t old_font;
	mk_win_base_bool_t measured;
	mk_win_base_sizer_t size;
	int released;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);

	dc = mk_win_user_window_get_dc(self->m_self); mk_lang_assert(dc);
	mk_lang_clobber(&old_font);
	if(self->m_font){ old_font = ((mk_win_gdi_font_t)(mk_win_gdi_dc_select_object(dc, ((mk_win_gdi_object_t)(self->m_font))))); }
	measured = mk_win_gdi_dc_t_get_text_extent_point_32(dc, s_alphabet, s_alphabet_len, &size); mk_lang_assert(measured != 0); self->m_item_height = ((int)(size.m_h));
	measured = mk_win_gdi_dc_t_get_text_extent_point_32(dc, &s_x, 1, &size); mk_lang_assert(measured != 0); self->m_xwidth = ((int)(size.m_w));
	if(self->m_font){ old_font = ((mk_win_gdi_font_t)(mk_win_gdi_dc_select_object(dc, ((mk_win_gdi_object_t)(old_font))))); mk_lang_assert(old_font == self->m_font); }
	released = mk_win_user_window_release_dc(self->m_self, dc); mk_lang_assert(released != 0);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_recalculate_lines_visible(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept
{
	mk_win_base_bool_t got;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(self->m_item_height >= 1);

	got = mk_win_user_window_get_client_rect(self->m_self, &self->m_rect_client); mk_lang_assert(got != 0); mk_lang_assert(self->m_rect_client.m_left == 0); mk_lang_assert(self->m_rect_client.m_top == 0); mk_lang_assert(self->m_rect_client.m_right >= 0); mk_lang_assert(self->m_rect_client.m_bottom >= 0);
	self->m_lines_fully_visible = self->m_rect_client.m_bottom / self->m_item_height; mk_lang_assert(self->m_lines_fully_visible >= 0);
	self->m_lines_partially_visible = mk_lang_div_roundup(self->m_rect_client.m_bottom, self->m_item_height); mk_lang_assert(self->m_lines_partially_visible >= 1); mk_lang_assert(self->m_lines_partially_visible == self->m_lines_fully_visible || self->m_lines_partially_visible == self->m_lines_fully_visible + 1);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_recalculate_scroll_max(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(self->m_strings_count >= 0);
	mk_lang_assert(self->m_lines_fully_visible >= 0);

	self->m_scroll_max = mk_lang_max(0, self->m_strings_count - self->m_lines_fully_visible);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_scrollbars_init(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept
{
	mk_win_base_bool_t shown;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);

	mk_win_kernel_errors_set_last(mk_win_kernel_errors_id_e_success);
	shown = ShowScrollBar(self->m_self, scroll_bar_id_e_horz, mk_win_base_false); mk_lang_assert(shown != 0);
	shown = ShowScrollBar(self->m_self, scroll_bar_id_e_vert, mk_win_base_true); mk_lang_assert(shown != 0);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_scrollbars_reset(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept
{
	mk_win_base_bool_t set;
	mk_win_base_bool_t enabled;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(self->m_strings_count >= 0);

	mk_win_kernel_errors_set_last(mk_win_kernel_errors_id_e_success);
	set = SetScrollPos(self->m_self, scroll_bar_id_e_vert, 0, mk_win_base_false); mk_lang_assert(set != 0 || mk_win_kernel_errors_get_last() == 0);
	set = SetScrollRange(self->m_self, scroll_bar_id_e_vert, 0, self->m_scroll_max == 0 ? 1 : self->m_scroll_max, mk_win_base_false); mk_lang_assert(set != 0);
	enabled = EnableScrollBar(self->m_self, scroll_bar_id_e_vert, scroll_bar_enable_e_enable_both); mk_lang_assert(enabled != 0 || mk_win_kernel_errors_get_last() == 0);
	enabled = EnableScrollBar(self->m_self, scroll_bar_id_e_vert, self->m_scroll_max == 0 ? scroll_bar_enable_e_disable_both : scroll_bar_enable_e_disable_up); mk_lang_assert(enabled != 0 || mk_win_kernel_errors_get_last() == 0);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_invalidate_item(mk_win_ctrl_impl_mlistbox_lpt const self, int const idx) mk_lang_noexcept
{
	mk_win_base_rect_t rect;
	mk_win_base_bool_t invalidated;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(idx >= -1);
	mk_lang_assert(idx < self->m_strings_count);

	if(idx == -1)
	{
		return;
	}
	if(idx >= self->m_scroll_cur + 0 && idx < self->m_scroll_cur + self->m_lines_partially_visible)
	{
		rect.m_left = 0;
		rect.m_top = (idx - self->m_scroll_cur) * self->m_item_height;
		rect.m_right = self->m_rect_client.m_right;
		rect.m_bottom = rect.m_top + self->m_item_height;
		invalidated = mk_win_user_window_invalidate_rect(self->m_self, &rect, mk_win_base_false); mk_lang_assert(invalidated != 0);
	}
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_do_scroll(mk_win_ctrl_impl_mlistbox_lpt const self, int const scroll_cur_new) mk_lang_noexcept
{
	int scroll_delta;
	mk_win_base_bool_t set;
	mk_win_base_bool_t enabled;
	mk_win_base_bool_t scrolled;
	mk_win_base_bool_t invalidated;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(scroll_cur_new >= 0);
	mk_lang_assert(scroll_cur_new <= self->m_scroll_max);

	if(scroll_cur_new == self->m_scroll_cur)
	{
		return;
	}
	scroll_delta = self->m_scroll_cur - scroll_cur_new;
	self->m_scroll_cur = scroll_cur_new;
	mk_win_kernel_errors_set_last(mk_win_kernel_errors_id_e_success);
	set = SetScrollPos(self->m_self, scroll_bar_id_e_vert, scroll_cur_new, mk_win_base_true); mk_lang_assert(set != 0 || mk_win_kernel_errors_get_last() == 0);
	enabled = EnableScrollBar(self->m_self, scroll_bar_id_e_vert, scroll_bar_enable_e_enable_both); mk_lang_assert(enabled != 0 || mk_win_kernel_errors_get_last() == 0);
	if(scroll_cur_new == 0)
	{
		enabled = EnableScrollBar(self->m_self, scroll_bar_id_e_vert, scroll_bar_enable_e_disable_up); mk_lang_assert(enabled != 0 || mk_win_kernel_errors_get_last() == 0);
	}
	else if(scroll_cur_new == self->m_scroll_max)
	{
		enabled = EnableScrollBar(self->m_self, scroll_bar_id_e_vert, scroll_bar_enable_e_disable_down); mk_lang_assert(enabled != 0 || mk_win_kernel_errors_get_last() == 0);
	}
	if(mk_lang_abs(scroll_delta) <= self->m_lines_partially_visible)
	{
		if(self->m_has_focus)
		{
			if(self->m_cur_sel == -1)
			{
				invalidated = mk_win_user_window_invalidate_rect(self->m_self, mk_win_base_null, mk_win_base_false); mk_lang_assert(invalidated != 0);
			}
			else
			{
				mk_win_ctrl_impl_mlistbox_invalidate_item(self, self->m_cur_sel);
				scrolled = ScrollWindow(self->m_self, 0, scroll_delta * self->m_item_height, mk_win_base_null, mk_win_base_null); mk_lang_assert(scrolled != 0);
			}
		}
		else
		{
			scrolled = ScrollWindow(self->m_self, 0, scroll_delta * self->m_item_height, mk_win_base_null, mk_win_base_null); mk_lang_assert(scrolled != 0);
		}
	}
	else
	{
		invalidated = mk_win_user_window_invalidate_rect(self->m_self, mk_win_base_null, mk_win_base_false); mk_lang_assert(invalidated != 0);
	}
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_do_scroll_to_make_visible(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept
{
	int scroll_cur_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_cur_sel >= -1);
	mk_lang_assert(self->m_cur_sel < self->m_strings_count);

	if(self->m_cur_sel == -1)
	{
		return;
	}
	if(self->m_cur_sel < self->m_scroll_cur)
	{
		scroll_cur_new = self->m_cur_sel;
		mk_win_ctrl_impl_mlistbox_do_scroll(self, scroll_cur_new);
	}
	else if(self->m_cur_sel >= self->m_scroll_cur + self->m_lines_fully_visible)
	{
		scroll_cur_new = self->m_cur_sel - self->m_lines_fully_visible + 1;
		mk_win_ctrl_impl_mlistbox_do_scroll(self, scroll_cur_new);
	}
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_do_select_idx(mk_win_ctrl_impl_mlistbox_lpt const self, int const cur_sel_new) mk_lang_noexcept
{
	int cur_sel_old;
	mk_win_base_bool_t invalidated;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(cur_sel_new >= -1);
	mk_lang_assert(cur_sel_new < self->m_strings_count);

	if(cur_sel_new == self->m_cur_sel)
	{
		return;
	}
	cur_sel_old = self->m_cur_sel;
	self->m_cur_sel = cur_sel_new;
	mk_win_ctrl_impl_mlistbox_invalidate_item(self, cur_sel_old);
	mk_win_ctrl_impl_mlistbox_invalidate_item(self, cur_sel_new);
	if(self->m_has_focus && (cur_sel_old == -1 || cur_sel_new == -1))
	{
		invalidated = mk_win_user_window_invalidate_rect(self->m_self, mk_win_base_null, mk_win_base_false); mk_lang_assert(invalidated != 0);
	}
	mk_win_ctrl_impl_mlistbox_do_scroll_to_make_visible(self);
	mk_win_ctrl_impl_mlistbox_fire_selchange(self);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_do_select_xy(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_base_sshort_t const x, mk_win_base_sshort_t const y) mk_lang_noexcept
{
	int cur_sel_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(self->m_item_height >= 1);

	if(x < 0 || y < 0 || x > self->m_rect_client.m_right || y > self->m_rect_client.m_bottom)
	{
		cur_sel_new = -1;
	}
	else
	{
		cur_sel_new = self->m_scroll_cur + y / self->m_item_height;
		if(cur_sel_new > self->m_strings_count - 1)
		{
			cur_sel_new = -1;
		}
	}
	mk_win_ctrl_impl_mlistbox_do_select_idx(self, cur_sel_new);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_fire_selchange(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept
{
	mk_win_base_word_t id;
	mk_win_user_window_lresult_t lr;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);

	id = ((mk_win_base_word_t)(mk_win_user_window_t_get_data(self->m_self, mk_win_user_window_data_idx_e_id)));
	lr = mk_win_user_message_t_send(mk_win_user_window_get_parent(self->m_self), mk_win_user_message_id_e_command, ((mk_win_user_window_wparam_t)(((mk_win_user_window_wparam_t)(((mk_win_user_window_wparam_t)(mk_win_user_ctrl_mlistbox_notify_e_selchange)) << 16)) | ((mk_win_user_window_wparam_t)(((mk_win_user_window_wparam_t)(id)) << 0)))), ((mk_win_user_window_lparam_t)(self->m_self))); ((void)(lr));
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_fire_lbuttondblclk(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept
{
	mk_win_base_word_t id;
	mk_win_user_window_lresult_t lr;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);

	id = ((mk_win_base_word_t)(mk_win_user_window_t_get_data(self->m_self, mk_win_user_window_data_idx_e_id)));
	lr = mk_win_user_message_t_send(mk_win_user_window_get_parent(self->m_self), mk_win_user_message_id_e_command, ((mk_win_user_window_wparam_t)(((mk_win_user_window_wparam_t)(((mk_win_user_window_wparam_t)(mk_win_user_ctrl_mlistbox_notify_e_dblclk)) << 16)) | ((mk_win_user_window_wparam_t)(((mk_win_user_window_wparam_t)(id)) << 0)))), ((mk_win_user_window_lparam_t)(self->m_self))); ((void)(lr));
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_fire_return(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept
{
	mk_win_user_ctrl_mlistbox_nmhdr_t notify_hdr;
	mk_win_user_window_lresult_t lr;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);

	notify_hdr.m_from_window = self->m_self;
	notify_hdr.m_from_id = ((mk_win_base_word_t)(mk_win_user_window_t_get_data(self->m_self, mk_win_user_window_data_idx_e_id)));
	notify_hdr.m_code = mk_win_user_ctrl_mlistbox_notify_e_return;
	lr = mk_win_user_message_t_send(mk_win_user_window_get_parent(self->m_self), mk_win_user_message_id_e_notify, ((mk_win_user_window_wparam_t)(notify_hdr.m_from_id)), ((mk_win_user_window_lparam_t)(((mk_win_user_ctrl_mlistbox_nmhdr_lpct)(&notify_hdr))))); ((void)(lr));
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_create(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	mk_lang_assert(self->m_self);
	self->m_font = mk_win_base_null;
	self->m_rect_client.m_left = 0;
	self->m_rect_client.m_top = 0;
	self->m_rect_client.m_right = 0;
	self->m_rect_client.m_bottom = 0;
	self->m_item_height = 1;
	self->m_xwidth = 1;
	self->m_lines_fully_visible = 0;
	self->m_lines_partially_visible = 0;
	self->m_scroll_cur = 0;
	self->m_scroll_max = 0;
	self->m_strings_count = 0;
	self->m_cur_sel = ((int)(mk_win_user_ctrl_mlistbox_err_e_err));
	self->m_has_focus = mk_lang_false;
	mk_win_ctrl_impl_mlistbox_recalculate_font(self);
	mk_win_ctrl_impl_mlistbox_recalculate_lines_visible(self);
	mk_win_ctrl_impl_mlistbox_recalculate_scroll_max(self);
	mk_win_ctrl_impl_mlistbox_scrollbars_init(self);
	mk_win_ctrl_impl_mlistbox_scrollbars_reset(self);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_size(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	mk_win_ctrl_impl_mlistbox_recalculate_lines_visible(self);
	mk_win_ctrl_impl_mlistbox_recalculate_scroll_max(self);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_setfocus(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_base_bool_t invalidated;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	self->m_has_focus = mk_lang_true;
	if(self->m_cur_sel == -1)
	{
		invalidated = mk_win_user_window_invalidate_rect(self->m_self, mk_win_base_null, mk_win_base_false); mk_lang_assert(invalidated != 0);
	}
	else
	{
		mk_win_ctrl_impl_mlistbox_invalidate_item(self, self->m_cur_sel);
	}
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_killfocus(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_base_bool_t invalidated;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	self->m_has_focus = mk_lang_false;
	if(self->m_cur_sel == -1)
	{
		invalidated = mk_win_user_window_invalidate_rect(self->m_self, mk_win_base_null, mk_win_base_false); mk_lang_assert(invalidated != 0);
	}
	else
	{
		mk_win_ctrl_impl_mlistbox_invalidate_item(self, self->m_cur_sel);
	}
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_paint(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_gdi_dc_t dc;
	mk_win_user_window_paint_t ps;
	mk_win_base_rect_t rect_mem_dc;
	mk_win_gdi_dc_t dc_mem;
	mk_win_gdi_bitmap_t bm;
	mk_win_gdi_bitmap_t prev_bm;
	int filled;
	mk_win_base_bool_t deleted;
	mk_win_user_brush_t background_brush;
	int row_visual_repaint_beg;
	int row_visual_repaint_end;
	int row_data_repaint_beg;
	int row_data_repaint_end;
	int row_data_repaint_begr;
	int row_data_repaint_endr;
	mk_win_user_window_t parent;
	mk_win_base_word_t id;
	mk_win_user_ctrl_mlistbox_notify_get_string_t notify_get_string;
	mk_win_gdi_font_t old_font;
	mk_win_base_rect_t rect_mem_line;
	mk_win_base_dword_t prev_foreground;
	mk_win_base_dword_t prev_background;
	int i;
	int idx;
	mk_win_user_window_lresult_t lr;
	mk_win_base_bool_t drawn;
	mk_win_base_rect_t rect_blank;
	mk_win_base_bool_t blted;
	mk_win_base_bool_t ended;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	mk_win_kernel_errors_set_last(mk_win_kernel_errors_id_e_success);
	dc = mk_win_user_window_begin_paint(self->m_self, &ps); mk_lang_assert(dc); mk_lang_assert(ps.m_dc == dc); mk_lang_assert(ps.m_rect.m_left >= 0); mk_lang_assert(ps.m_rect.m_top >= 0); mk_lang_assert(ps.m_rect.m_right > ps.m_rect.m_left); mk_lang_assert(ps.m_rect.m_bottom > ps.m_rect.m_top);
	rect_mem_dc.m_left = 0;
	rect_mem_dc.m_top = 0;
	rect_mem_dc.m_right = ps.m_rect.m_right - ps.m_rect.m_left; mk_lang_assert(rect_mem_dc.m_right > 0);
	rect_mem_dc.m_bottom = ps.m_rect.m_bottom - ps.m_rect.m_top; mk_lang_assert(rect_mem_dc.m_bottom > 0);
	dc_mem = mk_win_gdi_dc_create_compatible(dc); mk_lang_assert(dc_mem);
	bm = mk_win_gdi_bitmap_create_compatible(dc, rect_mem_dc.m_right, rect_mem_dc.m_bottom); mk_lang_assert(bm);
	prev_bm = ((mk_win_gdi_bitmap_t)(mk_win_gdi_dc_select_object(dc_mem, ((mk_win_gdi_object_t)(bm)))));
	#if !defined NDEBUG
	{
		mk_win_user_brush_t debug_brush;
		debug_brush = mk_win_user_brush_create_solid(0x000000fful); mk_lang_assert(debug_brush);
		filled = mk_win_gdi_dc_fill_rect(dc, &ps.m_rect, debug_brush); mk_lang_assert(filled != 0);
		filled = mk_win_gdi_dc_fill_rect(dc_mem, &rect_mem_dc, debug_brush); mk_lang_assert(filled != 0);
		deleted = mk_win_gdi_object_delete(((mk_win_gdi_object_t)(debug_brush))); mk_lang_assert(deleted != 0);
	}
	#endif
	background_brush = mk_win_user_brush_get_syscolor(mk_win_user_color_id_e_window); mk_lang_assert(background_brush);
	/*if(ps.m_erase != 0)
	{
		filled = mk_win_gdi_dc_fill_rect(dc_mem, &rect_mem_dc, background_brush); mk_lang_assert(filled != 0);
	}*/
	row_visual_repaint_beg = ps.m_rect.m_top / self->m_item_height;
	row_visual_repaint_end = mk_lang_div_roundup(ps.m_rect.m_bottom, self->m_item_height); mk_lang_assert(row_visual_repaint_end > row_visual_repaint_beg);
	row_data_repaint_beg = row_visual_repaint_beg + self->m_scroll_cur;
	row_data_repaint_end = row_visual_repaint_end + self->m_scroll_cur;
	row_data_repaint_begr = mk_lang_min(self->m_strings_count, row_data_repaint_beg);
	row_data_repaint_endr = mk_lang_min(self->m_strings_count, row_data_repaint_end);
	parent = mk_win_user_window_get_parent(self->m_self); mk_lang_assert(parent);
	id = ((mk_win_base_word_t)(mk_win_user_window_t_get_data(self->m_self, mk_win_user_window_data_idx_e_id)));
	notify_get_string.m_hdr.m_from_window = self->m_self;
	notify_get_string.m_hdr.m_from_id = id;
	notify_get_string.m_hdr.m_code = mk_win_user_ctrl_mlistbox_notify_e_get_string;
	mk_lang_clobber(&old_font);
	if(self->m_font){ old_font = ((mk_win_gdi_font_t)(mk_win_gdi_dc_select_object(dc_mem, ((mk_win_gdi_object_t)(self->m_font))))); }
	rect_mem_line.m_left = rect_mem_dc.m_left;
	rect_mem_line.m_top = (ps.m_rect.m_top / self->m_item_height) * self->m_item_height - ps.m_rect.m_top;
	rect_mem_line.m_right = rect_mem_dc.m_right;
	rect_mem_line.m_bottom = rect_mem_line.m_top;
	mk_lang_clobber(&prev_foreground);
	mk_lang_clobber(&prev_background);
	for(i = 0; i != row_data_repaint_endr - row_data_repaint_begr; ++i)
	{
		idx = row_data_repaint_begr + i;
		notify_get_string.m_idx = idx;
		lr = mk_win_user_message_t_send(parent, mk_win_user_message_id_e_notify, ((mk_win_user_window_wparam_t)(id)), ((mk_win_user_window_lparam_t)(((mk_win_user_ctrl_mlistbox_notify_get_string_lpt)(&notify_get_string))))); ((void)(lr)); mk_lang_assert(notify_get_string.m_string_length >= 0);
		if(idx == self->m_cur_sel)
		{
			prev_foreground = mk_win_gdi_dc_set_text_color(dc_mem, mk_win_user_system_information_get_color(mk_win_user_color_id_e_highlighttext));
			prev_background = mk_win_gdi_dc_set_background_color(dc_mem, mk_win_user_system_information_get_color(mk_win_user_color_id_e_highlight));
		}
		rect_mem_line.m_bottom += self->m_item_height;
		drawn = mk_win_gdi_dc_t_ext_text_out(dc_mem, self->m_xwidth - ps.m_rect.m_left, rect_mem_line.m_top, mk_win_gdi_dc_ext_text_out_options_e_opaque | mk_win_gdi_dc_ext_text_out_options_e_clipped, &rect_mem_line, notify_get_string.m_string, notify_get_string.m_string_length, mk_win_base_null); mk_lang_assert(drawn != 0);
		if(idx == self->m_cur_sel)
		{
			if(self->m_has_focus)
			{
				drawn = mk_win_gdi_dc_draw_focus_rect(dc_mem, &rect_mem_line); mk_lang_assert(drawn != 0);
			}
			prev_foreground = mk_win_gdi_dc_set_text_color(dc_mem, prev_foreground); ((void)(prev_foreground));
			prev_background = mk_win_gdi_dc_set_background_color(dc_mem, prev_background); ((void)(prev_background));
		}
		rect_mem_line.m_top += self->m_item_height;
	}
	if(self->m_font){ old_font = ((mk_win_gdi_font_t)(mk_win_gdi_dc_select_object(dc_mem, ((mk_win_gdi_object_t)(old_font))))); mk_lang_assert(old_font == self->m_font); }
	rect_blank.m_left = rect_mem_dc.m_left;
	rect_blank.m_top = rect_mem_line.m_top;
	rect_blank.m_right = rect_mem_dc.m_right;
	rect_blank.m_bottom = rect_mem_dc.m_bottom;
	filled = mk_win_gdi_dc_fill_rect(dc_mem, &rect_blank, background_brush); mk_lang_assert(filled != 0);
	if(self->m_has_focus && self->m_cur_sel == -1)
	{
		rect_mem_line.m_left = self->m_rect_client.m_left - ps.m_rect.m_left;
		rect_mem_line.m_top = self->m_rect_client.m_top - ps.m_rect.m_top;
		rect_mem_line.m_right = rect_mem_line.m_left + (self->m_rect_client.m_right - self->m_rect_client.m_left);
		rect_mem_line.m_bottom = rect_mem_line.m_top + (self->m_rect_client.m_bottom - self->m_rect_client.m_top);
		drawn = mk_win_gdi_dc_draw_focus_rect(dc_mem, &rect_mem_line); mk_lang_assert(drawn != 0);
	}
	blted = mk_win_gdi_bitmap_bitblt(dc, ps.m_rect.m_left, ps.m_rect.m_top, rect_mem_dc.m_right, rect_mem_dc.m_bottom, dc_mem, 0, 0, mk_win_gdi_bitmap_rop_e_srccopy); mk_lang_assert(blted != 0);
	prev_bm = ((mk_win_gdi_bitmap_t)(mk_win_gdi_dc_select_object(dc_mem, ((mk_win_gdi_object_t)(prev_bm))))); mk_lang_assert(prev_bm == bm);
	deleted = mk_win_gdi_object_delete(((mk_win_gdi_object_t)(bm))); mk_lang_assert(deleted != 0);
	deleted = mk_win_gdi_dc_delete(dc_mem); mk_lang_assert(deleted != 0);
	ended = mk_win_user_window_end_paint(self->m_self, &ps); mk_lang_assert(ended != 0);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_setfont(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	self->m_font = ((mk_win_gdi_font_t)(wparam));
	mk_win_ctrl_impl_mlistbox_recalculate_font(self);
	mk_win_ctrl_impl_mlistbox_recalculate_lines_visible(self);
	mk_win_ctrl_impl_mlistbox_recalculate_scroll_max(self);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_getfont(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(wparam == 0);
	mk_lang_assert(lparam == 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	*override_lres = mk_lang_true;
	*lres = ((mk_win_user_window_lresult_t)(self->m_font));
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_getdlgcode(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_user_message_dlg_code_t dlgc;
	mk_win_user_message_lpct msg;
	mk_win_user_message_key_t key;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	dlgc = mk_win_user_message_dlg_code_e_wantarrows;
	if(lparam != 0)
	{
		msg = ((mk_win_user_message_lpct)(lparam));
		key = ((mk_win_user_message_key_t)(msg->m_wparam));
		if(key == mk_win_user_message_key_e_return)
		{
			dlgc |= mk_win_user_message_dlg_code_e_wantmessage;
		}
	}
	*override_lres = mk_lang_true;
	*lres = ((mk_win_user_window_lresult_t)(dlgc));
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_return(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	mk_win_ctrl_impl_mlistbox_fire_return(self);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_prior(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	int cur_sel_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	cur_sel_new = mk_lang_max(0, self->m_cur_sel - self->m_lines_fully_visible);
	mk_win_ctrl_impl_mlistbox_do_select_idx(self, cur_sel_new);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_next(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	int cur_sel_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	cur_sel_new = mk_lang_min(self->m_strings_count - 1, self->m_cur_sel + self->m_lines_fully_visible);
	mk_win_ctrl_impl_mlistbox_do_select_idx(self, cur_sel_new);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_end(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	int cur_sel_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	cur_sel_new = self->m_strings_count - 1;
	mk_win_ctrl_impl_mlistbox_do_select_idx(self, cur_sel_new);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_home(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	int cur_sel_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	cur_sel_new = 0;
	mk_win_ctrl_impl_mlistbox_do_select_idx(self, cur_sel_new);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_up(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	int cur_sel_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	cur_sel_new = mk_lang_max(0, self->m_cur_sel - 1);
	mk_win_ctrl_impl_mlistbox_do_select_idx(self, cur_sel_new);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown_down(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	int cur_sel_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	cur_sel_new = mk_lang_min(self->m_strings_count - 1, self->m_cur_sel + 1);
	mk_win_ctrl_impl_mlistbox_do_select_idx(self, cur_sel_new);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_keydown(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(push)
	#pragma warning(disable:4062) /* warning C4062: enumerator 'xxx' in switch of enum 'xxx' is not handled */
	#endif

	mk_win_user_message_key_t key;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	key = ((mk_win_user_message_key_t)(wparam));
	switch(key)
	{
		case mk_win_user_message_key_e_return: mk_win_ctrl_impl_mlistbox_on_msg_keydown_return(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_key_e_prior: mk_win_ctrl_impl_mlistbox_on_msg_keydown_prior(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_key_e_next: mk_win_ctrl_impl_mlistbox_on_msg_keydown_next(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_key_e_end: mk_win_ctrl_impl_mlistbox_on_msg_keydown_end(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_key_e_home: mk_win_ctrl_impl_mlistbox_on_msg_keydown_home(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_key_e_up: mk_win_ctrl_impl_mlistbox_on_msg_keydown_up(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_key_e_down: mk_win_ctrl_impl_mlistbox_on_msg_keydown_down(self, wparam, lparam, override_lres, lres); break;
	}

	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(pop)
	#endif
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_vscroll(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	scroll_bar_event_t event;
	int scroll_cur_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(lparam == 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	event = ((scroll_bar_event_t)(((mk_win_base_word_t)(wparam))));
	switch(event)
	{
		case scroll_bar_event_e_lineup: scroll_cur_new = self->m_scroll_cur - 1; break;
		case scroll_bar_event_e_linedown: scroll_cur_new = self->m_scroll_cur + 1; break;
		case scroll_bar_event_e_pageup: scroll_cur_new = self->m_scroll_cur - mk_lang_max(1, self->m_lines_fully_visible); break;
		case scroll_bar_event_e_pagedown: scroll_cur_new = self->m_scroll_cur + mk_lang_max(1, self->m_lines_fully_visible); break;
		case scroll_bar_event_e_thumbposition: scroll_cur_new = ((int)((wparam >> 16) & 0xfffful)); break; /* todo 16bit */
		case scroll_bar_event_e_thumbtrack: scroll_cur_new = ((int)((wparam >> 16) & 0xfffful)); break; /* todo 16bit */
		case scroll_bar_event_e_top: scroll_cur_new = 0; break;
		case scroll_bar_event_e_bottom: scroll_cur_new = self->m_scroll_max; break;
		case scroll_bar_event_e_endscroll: scroll_cur_new = self->m_scroll_cur; break;
		default: mk_lang_assert(0); break;
	}
	scroll_cur_new = mk_lang_clamp(scroll_cur_new, 0, self->m_scroll_max);
	mk_win_ctrl_impl_mlistbox_do_scroll(self, scroll_cur_new);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_lbuttondown(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_user_window_t prev;
	mk_win_user_message_mouse_key_t mouse_key;
	mk_win_base_sshort_t x;
	mk_win_base_sshort_t y;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	prev = mk_win_user_window_set_focus(self->m_self); ((void)(self));
	mouse_key = ((mk_win_user_message_mouse_key_t)(wparam));
	if(mouse_key == mk_win_user_message_mouse_key_e_lbutton)
	{
		x = ((mk_win_base_sshort_t)(((mk_win_base_ushort_t)(((mk_win_user_window_lparam_t)(((mk_win_user_window_lparam_t)(lparam >>  0)) & ((mk_win_user_window_lparam_t)(0xfffful))))))));
		y = ((mk_win_base_sshort_t)(((mk_win_base_ushort_t)(((mk_win_user_window_lparam_t)(((mk_win_user_window_lparam_t)(lparam >> 16)) & ((mk_win_user_window_lparam_t)(0xfffful))))))));
		mk_win_ctrl_impl_mlistbox_do_select_xy(self, x, y);
	}
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_lbuttondblclk(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_user_message_mouse_key_t mouse_key;
	mk_win_base_sshort_t x;
	mk_win_base_sshort_t y;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	mouse_key = ((mk_win_user_message_mouse_key_t)(wparam));
	if(mouse_key == mk_win_user_message_mouse_key_e_lbutton)
	{
		x = ((mk_win_base_sshort_t)(((mk_win_base_ushort_t)(((mk_win_user_window_lparam_t)(((mk_win_user_window_lparam_t)(lparam >>  0)) & ((mk_win_user_window_lparam_t)(0xfffful))))))));
		y = ((mk_win_base_sshort_t)(((mk_win_base_ushort_t)(((mk_win_user_window_lparam_t)(((mk_win_user_window_lparam_t)(lparam >> 16)) & ((mk_win_user_window_lparam_t)(0xfffful))))))));
		mk_win_ctrl_impl_mlistbox_do_select_xy(self, x, y);
		mk_win_ctrl_impl_mlistbox_fire_lbuttondblclk(self);
	}
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_mousewheel(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_user_message_mouse_key_t mouse_key;
	mk_win_base_sshort_t wheel_delta;
	mk_win_base_sshort_t x;
	mk_win_base_sshort_t y;
	int scroll_cur_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	mouse_key = ((mk_win_user_message_mouse_key_t)(((mk_win_base_ushort_t)(((mk_win_user_window_wparam_t)(((mk_win_user_window_wparam_t)(wparam >> 0)) & ((mk_win_user_window_wparam_t)(0xfffful))))))));
	wheel_delta = ((mk_win_base_sshort_t)(((mk_win_base_ushort_t)(((mk_win_user_window_wparam_t)(((mk_win_user_window_wparam_t)(wparam >> 16)) & ((mk_win_user_window_wparam_t)(0xfffful))))))));
	x = ((mk_win_base_sshort_t)(((mk_win_base_ushort_t)(((mk_win_user_window_lparam_t)(((mk_win_user_window_lparam_t)(lparam >>  0)) & ((mk_win_user_window_lparam_t)(0xfffful))))))));
	y = ((mk_win_base_sshort_t)(((mk_win_base_ushort_t)(((mk_win_user_window_lparam_t)(((mk_win_user_window_lparam_t)(lparam >> 16)) & ((mk_win_user_window_lparam_t)(0xfffful))))))));
	if(mouse_key == mk_win_user_message_mouse_key_e_dummy_none)
	{
		scroll_cur_new = mk_lang_clamp(self->m_scroll_cur - wheel_delta / 120, 0, self->m_scroll_max);
		mk_win_ctrl_impl_mlistbox_do_scroll(self, scroll_cur_new);
	}
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_setcursel(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	int cur_sel_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(lparam == 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	cur_sel_new = ((int)(wparam)); mk_lang_assert(cur_sel_new >= -1); mk_lang_assert(cur_sel_new < self->m_strings_count);
	mk_win_ctrl_impl_mlistbox_do_select_idx(self, cur_sel_new);
	*override_lres = mk_lang_true;
	*lres = ((mk_win_user_window_lresult_t)(self->m_cur_sel));
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_getcursel(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(wparam == 0);
	mk_lang_assert(lparam == 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	*override_lres = mk_lang_true;
	*lres = ((mk_win_user_window_lresult_t)(self->m_cur_sel));
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_setcurscroll(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	int scroll_cur_new;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(lparam == 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	scroll_cur_new = ((int)(wparam)); mk_lang_assert(scroll_cur_new >= 0); mk_lang_assert(scroll_cur_new <= self->m_scroll_max);
	mk_win_ctrl_impl_mlistbox_do_scroll(self, scroll_cur_new);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_getcurscroll(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(wparam == 0);
	mk_lang_assert(lparam == 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	*override_lres = mk_lang_true;
	*lres = ((mk_win_user_window_lresult_t)(self->m_scroll_cur));
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_set_strings_count(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_base_bool_t invalidated;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(lparam == 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	self->m_scroll_cur = 0;
	self->m_strings_count = ((int)(wparam)); mk_lang_assert(self->m_strings_count >= 0);
	self->m_cur_sel = -1;
	invalidated = mk_win_user_window_invalidate_rect(self->m_self, mk_win_base_null, mk_win_base_false); mk_lang_assert(invalidated != 0);
	mk_win_ctrl_impl_mlistbox_recalculate_scroll_max(self);
	mk_win_ctrl_impl_mlistbox_scrollbars_reset(self);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_message_id_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(push)
	#pragma warning(disable:4062) /* warning C4062: enumerator 'xxx' in switch of enum 'xxx' is not handled */
	#pragma warning(disable:4063) /* warning C4063: case 'xxx' is not a valid value for switch of enum 'xxx' */
	#endif

	switch(message)
	{
		case mk_win_user_message_id_e_create: mk_win_ctrl_impl_mlistbox_on_msg_create(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_size: mk_win_ctrl_impl_mlistbox_on_msg_size(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_setfocus: mk_win_ctrl_impl_mlistbox_on_msg_setfocus(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_killfocus: mk_win_ctrl_impl_mlistbox_on_msg_killfocus(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_paint: mk_win_ctrl_impl_mlistbox_on_msg_paint(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_setfont: mk_win_ctrl_impl_mlistbox_on_msg_setfont(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_getfont: mk_win_ctrl_impl_mlistbox_on_msg_getfont(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_getdlgcode: mk_win_ctrl_impl_mlistbox_on_msg_getdlgcode(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_keydown: mk_win_ctrl_impl_mlistbox_on_msg_keydown(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_vscroll: mk_win_ctrl_impl_mlistbox_on_msg_vscroll(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_lbuttondown: mk_win_ctrl_impl_mlistbox_on_msg_lbuttondown(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_lbuttondblclk: mk_win_ctrl_impl_mlistbox_on_msg_lbuttondblclk(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_mousewheel: mk_win_ctrl_impl_mlistbox_on_msg_mousewheel(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_ctrl_mlistbox_message_e_setcursel: mk_win_ctrl_impl_mlistbox_on_msg_setcursel(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_ctrl_mlistbox_message_e_getcursel: mk_win_ctrl_impl_mlistbox_on_msg_getcursel(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_ctrl_mlistbox_message_e_setcurscroll: mk_win_ctrl_impl_mlistbox_on_msg_setcurscroll(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_ctrl_mlistbox_message_e_getcurscroll: mk_win_ctrl_impl_mlistbox_on_msg_getcurscroll(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_ctrl_mlistbox_message_e_set_strings_count: mk_win_ctrl_impl_mlistbox_on_msg_set_strings_count(self, wparam, lparam, override_lres, lres); break;
	}

	#if defined _MSC_VER && _MSC_VER == 1935
	#pragma warning(pop)
	#endif
}

static mk_win_user_window_lresult_t mk_win_base_stdcall mk_win_ctrl_impl_mlistbox_wndproc(mk_win_user_window_t const window, mk_win_base_uint_t const message_uint, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_message_id_t message_id;
	mk_lang_exception_t ex;
	mk_win_ctrl_impl_mlistbox_lpt self;
	mk_win_base_uintptr_t data;
	mk_lang_bool_t override_lres;
	mk_win_user_window_lresult_t lres;

	mk_lang_assert(window);

	message_id = ((mk_win_user_message_id_t)(message_uint));
	if(message_id == mk_win_user_message_id_e_create)
	{
		mk_lang_exception_make_none(&ex);
		mk_win_main_heap_allocate(&ex, sizeof(*self), &self);
		if(mk_lang_exception_is(&ex))
		{
			return -1;
		}
		mk_lang_assert(self);
		self->m_self = window;
		data = mk_win_user_window_t_set_data(window, mk_win_user_window_data_idx_e_custom, ((mk_win_base_uintptr_t)(self))); mk_lang_assert(data == 0);
	}
	self = ((mk_win_ctrl_impl_mlistbox_lpt)(mk_win_user_window_t_get_data(window, mk_win_user_window_data_idx_e_custom))); mk_lang_assert(!self || self->m_self == window);
	override_lres = mk_lang_false;
	mk_lang_clobber(&lres);
	if(self)
	{
		mk_win_ctrl_impl_mlistbox_on_msg(self, message_id, wparam, lparam, &override_lres, &lres);
	}
	if(message_id == mk_win_user_message_id_e_destroy)
	{
		data = mk_win_user_window_t_set_data(window, mk_win_user_window_data_idx_e_custom, 0); mk_lang_assert(data == 0 || data == ((mk_win_base_uintptr_t)(self)));
		mk_win_main_heap_deallocate(self, sizeof(*self));
	}
	if(!override_lres)
	{
		lres = mk_win_user_window_t_defproc(window, message_uint, wparam, lparam);
	}
	return lres;
}
