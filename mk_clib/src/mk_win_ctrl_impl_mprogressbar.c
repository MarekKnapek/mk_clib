#include "mk_win_ctrl_impl_mprogressbar.h"

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
#include "mk_win_user_ctrl_mprogressbar.h"
#include "mk_win_user_ctrl_progressbar.h"
#include "mk_win_user_cursor.h"
#include "mk_win_user_message.h"
#include "mk_win_user_window.h"


static mk_lang_inline void mk_win_ctrl_impl_mprogressbar_on_msg_create(mk_win_ctrl_impl_mprogressbar_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mprogressbar_on_msg_paint(mk_win_ctrl_impl_mprogressbar_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mprogressbar_on_msg_set_position(mk_win_ctrl_impl_mprogressbar_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mprogressbar_on_msg_get_position(mk_win_ctrl_impl_mprogressbar_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_lang_inline void mk_win_ctrl_impl_mprogressbar_on_msg(mk_win_ctrl_impl_mprogressbar_lpt const self, mk_win_user_message_id_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept;
static mk_win_user_window_lresult_t mk_win_base_stdcall mk_win_ctrl_impl_mprogressbar_wndproc(mk_win_user_window_t const window, mk_win_base_uint_t const message_uint, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept;


mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall InvalidateRect(mk_win_user_window_t, mk_win_base_rect_lpct, mk_lang_bool_t) mk_lang_noexcept; /* todo move somewhere else */


static mk_win_kernel_atom_t g_mk_win_ctrl_impl_mprogressbar_atom;


mk_lang_jumbo void mk_win_ctrl_impl_mprogressbar_register(void) mk_lang_noexcept
{
	mk_win_user_class_t_t wc;
	mk_lang_bool_t got;

	mk_lang_assert(g_mk_win_ctrl_impl_mprogressbar_atom == 0);
	wc.m_style = 0;
	wc.m_wndproc = &mk_win_ctrl_impl_mprogressbar_wndproc;
	wc.m_class_extra = 0;
	wc.m_wnd_extra = sizeof(mk_win_ctrl_impl_mprogressbar_lpt);
	got = mk_win_kernel_dll_t_get_handle_from_address(&g_mk_win_ctrl_impl_mprogressbar_atom, ((mk_win_kernel_dll_module_lpt)(&wc.m_instance))); mk_lang_assert(got != 0);
	wc.m_icon = mk_win_base_null;
	wc.m_cursor = mk_win_user_cursor_t_load_by_id(mk_win_user_cursor_id_e_arrow);
	wc.m_background = mk_win_base_null;
	wc.m_menu_name = mk_win_base_null;
	wc.m_class_name = mk_win_user_ctrl_mprogressbar_name_t;
	g_mk_win_ctrl_impl_mprogressbar_atom = mk_win_user_class_t_register(&wc);
	mk_lang_assert(g_mk_win_ctrl_impl_mprogressbar_atom != 0);
}

mk_lang_jumbo void mk_win_ctrl_impl_mprogressbar_unregister(void) mk_lang_noexcept
{
	mk_lang_bool_t got;
	mk_win_kernel_dll_module_t module;
	mk_lang_bool_t unregistered;

	got = mk_win_kernel_dll_t_get_handle_from_address(&g_mk_win_ctrl_impl_mprogressbar_atom, &module);
	mk_lang_assert(got != 0);
	unregistered = mk_win_user_class_t_unregister_by_atom(g_mk_win_ctrl_impl_mprogressbar_atom, ((mk_win_base_instance_t)(module)));
	mk_lang_assert(unregistered == mk_win_base_true);
}


static mk_lang_inline void mk_win_ctrl_impl_mprogressbar_on_msg_create(mk_win_ctrl_impl_mprogressbar_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_base_bool_t got;
	mk_win_base_rect_t rect;
	mk_win_base_instance_t instance;
	mk_win_user_window_lresult_t lr;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);
	((void)(wparam));
	((void)(lparam));

	self->m_percent = 0;
	got = mk_win_user_window_get_rect(self->m_self, &rect); mk_lang_assert(got != 0);
	got = mk_win_kernel_dll_t_get_handle_from_address(&g_mk_win_ctrl_impl_mprogressbar_atom, ((mk_win_kernel_dll_module_lpt)(&instance))); mk_lang_assert(got != 0);
	self->m_native = mk_win_user_window_t_create_by_name
	(
		0,
		mk_win_user_ctrl_progressbar_name_t,
		mk_win_tstring_tchar_c(""),
			mk_win_user_ctrl_progressbar_style_e_smooth |
			mk_win_user_window_style_e_visible |
			mk_win_user_window_style_e_child |
			0,
		0,
		0,
		rect.m_right - rect.m_left,
		rect.m_bottom - rect.m_top,
		self->m_self,
		mk_win_base_null,
		instance,
		mk_win_base_null
	);
	if(self->m_native)
	{
		lr = mk_win_user_message_t_send(self->m_native, mk_win_user_ctrl_progressbar_message_e_setrange, 0, ((mk_win_user_window_lparam_t)(((mk_win_user_window_lparam_t)(((mk_win_user_window_lparam_t)(((mk_win_base_word_t)(10000)))) << 16)) | ((mk_win_user_window_lparam_t)(((mk_win_base_word_t)(0))))))); mk_lang_assert(lr == ((mk_win_user_window_lresult_t)(((mk_win_user_window_lparam_t)(((mk_win_user_window_lparam_t)(((mk_win_user_window_lparam_t)(((mk_win_base_word_t)(100)))) << 16)) | ((mk_win_user_window_lparam_t)(((mk_win_base_word_t)(0)))))))));
	}
}

static mk_lang_inline void mk_win_ctrl_impl_mprogressbar_on_msg_paint(mk_win_ctrl_impl_mprogressbar_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_win_base_uintptr_t style;
	mk_lang_bool_t has_border;
	int border_adjust;
	mk_win_base_bool_t got;
	mk_win_base_rect_t rect_orig;
	mk_win_base_rect_t rect_a;
	mk_win_base_rect_t rect_b;
	mk_win_user_brush_t foreground;
	mk_win_user_brush_t background;
	mk_win_gdi_dc_t dc;
	mk_win_user_window_paint_t ps;
	mk_win_gdi_dc_t mem_dc;
	mk_win_gdi_bitmap_t bm;
	mk_win_gdi_bitmap_t prev_bm;
	int filled;
	mk_win_user_brush_t frame;
	mk_win_base_bool_t blted;
	mk_win_base_bool_t deleted;
	mk_win_base_bool_t ended;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);
	((void)(wparam));
	((void)(lparam));

	if(self->m_native)
	{
		return;
	}
	style = mk_win_user_window_t_get_data(self->m_self, mk_win_user_window_data_idx_e_style);
	has_border = (style & mk_win_user_window_style_e_border) != 0;
	border_adjust = (!has_border ? 1 : 0);
	got = mk_win_user_window_get_client_rect(self->m_self, &rect_orig); mk_lang_assert(got != 0); mk_lang_assert(rect_orig.m_left == 0); mk_lang_assert(rect_orig.m_top == 0);
	if(!(rect_orig.m_right >= (1 + 2 * border_adjust) && rect_orig.m_bottom >= (1 + 2 * border_adjust))) return;
	rect_a.m_left = rect_orig.m_left + border_adjust;
	rect_a.m_top = rect_orig.m_top + border_adjust;
	rect_a.m_right = border_adjust + ((((rect_orig.m_right - (2 * border_adjust)) * self->m_percent) + (10000 / 2)) / 10000);
	rect_a.m_bottom = rect_orig.m_bottom - border_adjust;
	rect_b.m_left = rect_a.m_right;
	rect_b.m_top = rect_a.m_top;
	rect_b.m_right = rect_orig.m_right - border_adjust;
	rect_b.m_bottom = rect_a.m_bottom;
	foreground = mk_win_user_brush_get_syscolor(mk_win_user_color_id_e_windowtext); mk_lang_assert(foreground);
	background = mk_win_user_brush_get_syscolor(mk_win_user_color_id_e_window); mk_lang_assert(background);
	dc = mk_win_user_window_begin_paint(self->m_self, &ps); mk_lang_assert(dc);
	mem_dc = mk_win_gdi_dc_create_compatible(dc); mk_lang_assert(mem_dc);
	bm = mk_win_gdi_bitmap_create_compatible(dc, rect_orig.m_right, rect_orig.m_bottom); mk_lang_assert(bm);
	prev_bm = ((mk_win_gdi_bitmap_t)(mk_win_gdi_dc_select_object(mem_dc, ((mk_win_gdi_object_t)(bm)))));
	#if !defined NDEBUG
	{
		mk_win_user_brush_t debug;
		debug = mk_win_user_brush_get_syscolor(mk_win_user_color_id_e_highlight); mk_lang_assert(debug);
		filled = mk_win_gdi_dc_fill_rect(mem_dc, &rect_orig, debug); mk_lang_assert(filled != 0);
	}
	#endif
	if(!has_border)
	{
		frame = mk_win_user_brush_get_syscolor(mk_win_user_color_id_e_windowframe); mk_lang_assert(frame);
		filled = mk_win_gdi_dc_frame_rect(mem_dc, &rect_orig, frame); mk_lang_assert(filled != 0);
	}
	filled = mk_win_gdi_dc_fill_rect(mem_dc, &rect_a, foreground); mk_lang_assert(filled != 0);
	filled = mk_win_gdi_dc_fill_rect(mem_dc, &rect_b, background); mk_lang_assert(filled != 0);
	blted = mk_win_gdi_bitmap_bitblt(dc, 0, 0, rect_orig.m_right, rect_orig.m_bottom, mem_dc, 0, 0, mk_win_gdi_bitmap_rop_e_srccopy); mk_lang_assert(blted != 0);
	prev_bm = ((mk_win_gdi_bitmap_t)(mk_win_gdi_dc_select_object(mem_dc, ((mk_win_gdi_object_t)(prev_bm))))); mk_lang_assert(prev_bm == bm);
	deleted = mk_win_gdi_object_delete(((mk_win_gdi_object_t)(bm))); mk_lang_assert(deleted != 0);
	deleted = mk_win_gdi_dc_delete(mem_dc); mk_lang_assert(deleted != 0);
	ended = mk_win_user_window_end_paint(self->m_self, &ps); mk_lang_assert(ended != 0);
}

static mk_lang_inline void mk_win_ctrl_impl_mprogressbar_on_msg_set_position(mk_win_ctrl_impl_mprogressbar_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	int new_pos;
	int old_pos;
	mk_win_user_window_lresult_t prev;
	mk_win_base_bool_t invalidated;

	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(/*wparam >= 0 && */wparam <= 10000);
	mk_lang_assert(lparam == 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	new_pos = ((int)(wparam));
	if(new_pos != self->m_percent)
	{
		old_pos = self->m_percent;
		self->m_percent = new_pos;
		if(self->m_native)
		{
			prev = mk_win_user_message_t_send(self->m_native, mk_win_user_ctrl_progressbar_message_e_setpos, ((mk_win_user_window_wparam_t)(self->m_percent)), 0); mk_lang_assert(prev == ((mk_win_user_window_lresult_t)(old_pos)));
		}
		else
		{
			invalidated = InvalidateRect(self->m_self, mk_win_base_null, mk_win_base_false); mk_lang_assert(invalidated != 0);
		}
	}
}

static mk_lang_inline void mk_win_ctrl_impl_mprogressbar_on_msg_get_position(mk_win_ctrl_impl_mprogressbar_lpt const self, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	mk_lang_assert(self);
	mk_lang_assert(self->m_self);
	mk_lang_assert(/*wparam >= 0 && */wparam <= 10000);
	mk_lang_assert(lparam == 0);
	mk_lang_assert(override_lres);
	mk_lang_assert(lres);

	*override_lres = mk_lang_true;
	*lres = ((mk_win_user_window_lresult_t)(self->m_percent));
}

static mk_lang_inline void mk_win_ctrl_impl_mprogressbar_on_msg(mk_win_ctrl_impl_mprogressbar_lpt const self, mk_win_user_message_id_t const message, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam, mk_lang_bool_pt const override_lres, mk_win_user_window_lresult_pt const lres) mk_lang_noexcept
{
	#if defined _MSC_VER && _MSC_VER >= 1935
	#pragma warning(push)
	#pragma warning(disable:4062) /* warning C4062: enumerator 'xxx' in switch of enum 'xxx' is not handled */
	#pragma warning(disable:4063) /* warning C4063: case 'xxx' is not a valid value for switch of enum 'xxx' */
	#endif

	switch(message)
	{
		case mk_win_user_message_id_e_create: mk_win_ctrl_impl_mprogressbar_on_msg_create(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_message_id_e_paint: mk_win_ctrl_impl_mprogressbar_on_msg_paint(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_ctrl_mprogressbar_message_e_set_position: mk_win_ctrl_impl_mprogressbar_on_msg_set_position(self, wparam, lparam, override_lres, lres); break;
		case mk_win_user_ctrl_mprogressbar_message_e_get_position: mk_win_ctrl_impl_mprogressbar_on_msg_get_position(self, wparam, lparam, override_lres, lres); break;
	}

	#if defined _MSC_VER && _MSC_VER >= 1935
	#pragma warning(pop)
	#endif
}

static mk_win_user_window_lresult_t mk_win_base_stdcall mk_win_ctrl_impl_mprogressbar_wndproc(mk_win_user_window_t const window, mk_win_base_uint_t const message_uint, mk_win_user_window_wparam_t const wparam, mk_win_user_window_lparam_t const lparam) mk_lang_noexcept
{
	mk_win_user_message_id_t message_id;
	mk_lang_exception_t ex;
	mk_win_ctrl_impl_mprogressbar_lpt self;
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
	self = ((mk_win_ctrl_impl_mprogressbar_lpt)(mk_win_user_window_t_get_data(window, mk_win_user_window_data_idx_e_custom)));
	mk_lang_assert(!self || self->m_self == window);
	override_lres = mk_lang_false;
	mk_lang_clobber(&lres);
	if(self)
	{
		mk_win_ctrl_impl_mprogressbar_on_msg(self, message_id, wparam, lparam, &override_lres, &lres);
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
