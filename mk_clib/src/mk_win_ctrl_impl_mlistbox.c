#include "mk_win_ctrl_impl_mlistbox.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_clobber.h"
#include "mk_lang_exception.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_gdi_bitmap.h"
#include "mk_win_gdi_dc.h"
#include "mk_win_gdi_object.h"
#include "mk_win_kernel_atom.h"
#include "mk_win_kernel_dll.h"
#include "mk_win_main_heap.h"
#include "mk_win_tstring.h"
#include "mk_win_user_brush.h"
#include "mk_win_user_class.h"
#include "mk_win_user_color.h"
#include "mk_win_user_ctrl_mlistbox.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_message.h"
#include "mk_win_user_window.h"


static mk_lang_inline void mk_win_ctrl_impl_mlistbox_measure_font(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_create(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_paint(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_setfont(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_set_strings_count(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_message_id_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_win_user_window_lresult_t mk_win_base_stdcall mk_win_ctrl_impl_mlistbox_wndproc(mk_win_user_window_t const window, mk_win_base_uint_t const message_uint, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;


static mk_win_kernel_atom_t g_mk_win_ctrl_impl_mlistbox_atom;


mk_lang_jumbo void mk_win_ctrl_impl_mlistbox_register(void) mk_lang_noexcept
{
	mk_win_user_class_t_t wc;
	mk_lang_bool_t got;

	mk_lang_assert(g_mk_win_ctrl_impl_mlistbox_atom == 0);
	wc.m_style = 0;
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


static mk_lang_inline void mk_win_ctrl_impl_mlistbox_measure_font(mk_win_ctrl_impl_mlistbox_lpt const self) mk_lang_noexcept
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
	measured = mk_win_gdi_dc_t_get_text_extent_point_32(dc, &s_x, 1, &size); mk_lang_assert(measured != 0); self->m_x_width = ((int)(size.m_w));
	if(self->m_font){ old_font = ((mk_win_gdi_font_t)(mk_win_gdi_dc_select_object(dc, ((mk_win_gdi_object_t)(old_font))))); mk_lang_assert(old_font == self->m_font); }
	released = mk_win_user_window_release_dc(self->m_self, dc); mk_lang_assert(released != 0);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_create(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	self->m_font = mk_win_base_null;
	self->m_item_height = 0;
	self->m_x_width = 0;
	self->m_strings_count = 0;
	mk_win_ctrl_impl_mlistbox_measure_font(self);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_paint(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_base_bool_t got;
	mk_win_base_rect_t rect;
	mk_win_user_brush_t foreground;
	mk_win_user_brush_t background;
	mk_win_gdi_dc_t dc;
	mk_win_user_window_paint_t ps;
	mk_win_gdi_dc_t mem_dc;
	mk_win_gdi_bitmap_t bm;
	mk_win_gdi_bitmap_t prev_bm;
	int filled;
	mk_win_gdi_font_t old_font;
	mk_win_user_window_t parent;
	mk_win_base_word_t id;
	mk_win_user_ctrl_mlistbox_notify_get_string_t notify_get_string;
	mk_win_base_size_t n;
	mk_win_base_size_t i;
	mk_win_user_window_lresult_t lr;
	mk_win_base_bool_t drawn;
	mk_win_base_bool_t blted;
	mk_win_base_bool_t deleted;
	mk_win_base_bool_t ended;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	((void)(wparam));
	((void)(lparam));
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	got = mk_win_user_window_get_client_rect(self->m_self, &rect); mk_lang_assert(got != 0); mk_lang_assert(rect.m_left == 0); mk_lang_assert(rect.m_top == 0);
	foreground = mk_win_user_brush_get_syscolor(mk_win_user_color_id_e_windowtext); mk_lang_assert(foreground);
	background = mk_win_user_brush_get_syscolor(mk_win_user_color_id_e_window); mk_lang_assert(background);
	dc = mk_win_user_window_begin_paint(self->m_self, &ps); mk_lang_assert(dc);
	mem_dc = mk_win_gdi_dc_create_compatible(dc); mk_lang_assert(mem_dc);
	bm = mk_win_gdi_bitmap_create_compatible(dc, rect.m_right, rect.m_bottom); mk_lang_assert(bm);
	prev_bm = ((mk_win_gdi_bitmap_t)(mk_win_gdi_dc_select_object(mem_dc, ((mk_win_gdi_object_t)(bm)))));
	#if !defined NDEBUG
	{
		mk_win_user_brush_t debug;
		debug = mk_win_user_brush_get_syscolor(mk_win_user_color_id_e_highlight); mk_lang_assert(debug);
		filled = mk_win_gdi_dc_fill_rect(mem_dc, &rect, debug); mk_lang_assert(filled != 0);
	}
	#endif
	filled = mk_win_gdi_dc_fill_rect(mem_dc, &rect, background); mk_lang_assert(filled != 0);
	mk_lang_clobber(&old_font);
	if(self->m_font){ old_font = ((mk_win_gdi_font_t)(mk_win_gdi_dc_select_object(mem_dc, ((mk_win_gdi_object_t)(self->m_font))))); }
	parent = mk_win_user_window_get_parent(self->m_self); mk_lang_assert(parent);
	id = ((mk_win_base_word_t)(mk_win_user_window_t_get_data(self->m_self, mk_win_user_window_data_idx_e_id))); /* or GetDlgCtrlID */ /* or hmenu in create struct in wm create */
	notify_get_string.m_hdr.m_from_window = self->m_self;
	notify_get_string.m_hdr.m_from_id = id;
	notify_get_string.m_hdr.m_code = mk_win_user_ctrl_mlistbox_notify_e_get_string;
	n = self->m_strings_count;
	for(i = 0; i != n; ++i)
	{
		notify_get_string.m_idx = i;
		lr = mk_win_user_message_t_send(parent, mk_win_user_message_id_e_notify, ((mk_win_user_window_wparam_t)(id)), ((mk_win_user_window_lparam_t)(((mk_win_user_ctrl_mlistbox_notify_get_string_lpt)(&notify_get_string))))); ((void)(lr));
		drawn = mk_win_gdi_dc_t_ext_text_out(mem_dc, self->m_x_width, ((int)(i * self->m_item_height)), mk_win_gdi_dc_ext_text_out_options_e_none, mk_win_base_null, notify_get_string.m_string, notify_get_string.m_string_length, mk_win_base_null); mk_lang_assert(drawn != 0);
	}
	if(self->m_font){ old_font = ((mk_win_gdi_font_t)(mk_win_gdi_dc_select_object(mem_dc, ((mk_win_gdi_object_t)(old_font))))); mk_lang_assert(old_font == self->m_font); }
	blted = mk_win_gdi_bitmap_bitblt(dc, 0, 0, rect.m_right, rect.m_bottom, mem_dc, 0, 0, mk_win_gdi_bitmap_rop_e_srccopy); mk_lang_assert(blted != 0);
	prev_bm = ((mk_win_gdi_bitmap_t)(mk_win_gdi_dc_select_object(mem_dc, ((mk_win_gdi_object_t)(prev_bm))))); mk_lang_assert(prev_bm == bm);
	deleted = mk_win_gdi_object_delete(((mk_win_gdi_object_t)(bm))); mk_lang_assert(deleted != 0);
	deleted = mk_win_gdi_dc_delete(mem_dc); mk_lang_assert(deleted != 0);
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
	mk_win_ctrl_impl_mlistbox_measure_font(self);
}

static mk_lang_inline void mk_win_ctrl_impl_mlistbox_on_msg_set_strings_count(mk_win_ctrl_impl_mlistbox_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(wparam == 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	self->m_strings_count = ((mk_win_base_size_t)(lparam));
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
		case mk_win_user_message_id_e_paint: mk_win_ctrl_impl_mlistbox_on_msg_paint(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_setfont: mk_win_ctrl_impl_mlistbox_on_msg_setfont(self, wparam, lparam, override_lres, lres); break;
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
		data = mk_win_user_window_t_set_data(window, mk_win_user_window_data_idx_e_custom, ((mk_win_base_uintptr_t)(self)));
		mk_lang_assert(data == 0);
	}
	self = ((mk_win_ctrl_impl_mlistbox_lpt)(mk_win_user_window_t_get_data(window, mk_win_user_window_data_idx_e_custom)));
	mk_lang_assert(!self || self->m_self == window);
	override_lres = mk_lang_false;
	mk_lang_clobber(&lres);
	if(self)
	{
		mk_win_ctrl_impl_mlistbox_on_msg(self, message_id, wparam, lparam, &override_lres, &lres);
	}
	if(message_id == mk_win_user_message_id_e_destroy)
	{
		data = mk_win_user_window_t_set_data(window, mk_win_user_window_data_idx_e_custom, 0);
		mk_lang_assert(data == 0 || data == ((mk_win_base_uintptr_t)(self)));
		mk_win_main_heap_deallocate(self, sizeof(*self));
	}
	if(!override_lres)
	{
		lres = mk_win_user_window_t_defproc(window, message_uint, wparam, lparam);
	}
	return lres;
}
