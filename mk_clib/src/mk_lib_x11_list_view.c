#include "mk_lib_x11_list_view.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_clamp.h"
#include "mk_lang_countof.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_x11_cong.h"


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_x11_list_view_alphabet[] = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";


static mk_lang_inline mk_lang_types_void_t mk_lib_x11_list_view_rect_shrink(mk_lang_types_sint_t const ax, mk_lang_types_sint_t const ay, mk_lang_types_sint_t const aw, mk_lang_types_sint_t const ah, mk_lang_types_sint_t const border, mk_lang_types_sint_pt const bx, mk_lang_types_sint_pt const by, mk_lang_types_sint_pt const bw, mk_lang_types_sint_pt const bh) mk_lang_noexcept
{
	mk_lang_assert(border >= 0);

	*bx = ax + border;
	*by = ay + border;
	*bw = aw - 2 * border;
	*bh = ah - 2 * border;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_x11_list_view_rect_intersect_impl(mk_lang_types_sint_t const ax, mk_lang_types_sint_t const ay, mk_lang_types_sint_t const aw, mk_lang_types_sint_t const ah, mk_lang_types_sint_t const bx, mk_lang_types_sint_t const by, mk_lang_types_sint_t const bw, mk_lang_types_sint_t const bh) mk_lang_noexcept
{
	mk_lang_types_sint_t ar;
	mk_lang_types_sint_t ab;
	mk_lang_types_bool_t ret;

	mk_lang_assert(aw >= 0);
	mk_lang_assert(ah >= 0);
	mk_lang_assert(bw >= 0);
	mk_lang_assert(bh >= 0);

	ar = ax + aw;
	ab = ay + ah;
	ret = (bx >= ax && bx <= ar) && (by >= ay && by <= ab);
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_x11_list_view_rect_intersect(mk_lang_types_sint_t const ax, mk_lang_types_sint_t const ay, mk_lang_types_sint_t const aw, mk_lang_types_sint_t const ah, mk_lang_types_sint_t const bx, mk_lang_types_sint_t const by, mk_lang_types_sint_t const bw, mk_lang_types_sint_t const bh) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	ret = mk_lib_x11_list_view_rect_intersect_impl(ax, ay, aw, ah, bx, by, bw, bh) || mk_lib_x11_list_view_rect_intersect_impl(bx, by, bw, bh, ax, ay, aw, ah);
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_invalidate_all(mk_lib_x11_list_view_pct const list_view) mk_lang_noexcept
{
	mk_lang_types_sint_t x;
	mk_lang_types_sint_t y;
	mk_lang_types_sint_t w;
	mk_lang_types_sint_t h;
	Display* display;
	Window window;
	XEvent* evt;
	XEvent e;
	Status st;

	mk_lang_assert(list_view);

	x = list_view->m_x;
	y = list_view->m_y;
	w = list_view->m_w;
	h = list_view->m_h;
	display = list_view->m_display;
	window = list_view->m_window;
	evt = &e;
	evt->type = Expose;
	evt->xexpose.type = Expose;
	evt->xexpose.serial = 0;
	evt->xexpose.send_event = True;
	evt->xexpose.display = display;
	evt->xexpose.window = window;
	evt->xexpose.x = x;
	evt->xexpose.y = y;
	evt->xexpose.width = w;
	evt->xexpose.height = h;
	evt->xexpose.count = 0;
	st = XSendEvent(display, window, False, ExposureMask, evt);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_invalidate_row(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t x;
	mk_lang_types_sint_t y;
	mk_lang_types_sint_t w;
	mk_lang_types_sint_t border;
	Display* display;
	Window window;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t line_height;
	XEvent* evt;
	XEvent e;
	Status st;

	mk_lang_assert(list_view);
	mk_lang_assert(id >= 0);

	x = list_view->m_x;
	y = list_view->m_y;
	w = list_view->m_w;
	border = list_view->m_border;
	display = list_view->m_display;
	window = list_view->m_window;
	text_asc = list_view->m_text_asc;
	text_des = list_view->m_text_des;
	line_height = text_asc + text_des;
	evt = &e;
	evt->type = Expose;
	evt->xexpose.type = Expose;
	evt->xexpose.serial = 0;
	evt->xexpose.send_event = True;
	evt->xexpose.display = display;
	evt->xexpose.window = window;
	evt->xexpose.x = x + border;
	evt->xexpose.y = y + border + id * line_height;
	evt->xexpose.width = w - 2 * border;
	evt->xexpose.height = line_height;
	evt->xexpose.count = 0;
	st = XSendEvent(display, window, False, ExposureMask, evt);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prro_on_expose_row(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_t const id) mk_lang_noexcept
{
	mk_lang_types_sint_t mx;
	mk_lang_types_sint_t my;
	mk_lang_types_sint_t mw;
	mk_lang_types_sint_t border;
	mk_lang_types_sint_t rows;
	mk_lang_types_sint_t idx;
	mk_lib_x11_list_view_callback_t callback;
	mk_lib_x11_list_view_callctx_t context;
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t x;
	mk_lang_types_sint_t y;
	mk_lang_types_sint_t w;
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t tsi;
	mk_lang_types_pchar_pct text;
	mk_lang_types_sint_t len;

	mk_lang_assert(list_view);
	mk_lang_assert(list_view->m_callback);
	mk_lang_assert(id >= 0);

	mx = list_view->m_x;
	my = list_view->m_y;
	mw = list_view->m_w;
	border = list_view->m_border;
	rows = list_view->m_rows;
	idx = list_view->m_idx;
	callback = list_view->m_callback;
	context = list_view->m_context;
	display = list_view->m_display;
	window = list_view->m_window;
	gc = list_view->m_gc;
	text_asc = list_view->m_text_asc;
	text_des = list_view->m_text_des;
	x = mx + border;
	y = my + border;
	w = mw - 2 * border;
	err = mk_lib_x11_cong_get_default_screen_black(&black); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_default_screen_white(&white); mk_lang_check_rereturn(err);
	line_height = text_asc + text_des;
	mk_lang_assert(line_height >= 1);
	y = y + id * line_height;
	if(id != idx)
	{
		tsi = XSetForeground(display, gc, white);
		tsi = XFillRectangle(display, window, gc, x, y, w, line_height);
		tsi = XSetForeground(display, gc, black);
	}
	else
	{
		tsi = XFillRectangle(display, window, gc, x, y, w, line_height);
		tsi = XSetForeground(display, gc, white);
	}
	if(id < rows)
	{
		err = callback(context, id, &text, &len); mk_lang_check_rereturn(err); mk_lang_assert(len >= 0 && (len == 0 || (text && text[0] != '\0')));
		if(len != 0)
		{
			y += (line_height - text_des);
			tsi = XDrawString(display, window, gc, x, y, text, len);
			y -= (line_height - text_des);
		}
	}
	if(id != idx)
	{
	}
	else
	{
		tsi = XSetForeground(display, gc, black);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_refresh_font_dimensions(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept
{
	Display* display;
	GC gc;
	GContext gcid;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t direction;
	mk_lang_types_sint_t ascent;
	mk_lang_types_sint_t descent;
	XCharStruct overall;

	mk_lang_assert(list_view);

	display = list_view->m_display;
	gc = list_view->m_gc;
	gcid = XGContextFromGC(gc);
	tsi = XQueryTextExtents(display, gcid, &mk_lib_x11_list_view_alphabet[0], mk_lang_countstr(mk_lib_x11_list_view_alphabet), &direction, &ascent, &descent, &overall); mk_lang_assert(overall.ascent + overall.descent >= 1);
	list_view->m_text_asc = overall.ascent;
	list_view->m_text_des = overall.descent;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_construct(mk_lib_x11_list_view_pt const list_view, Display* const display, Window const window, GC const gc) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	list_view->m_x = 0;
	list_view->m_y = 0;
	list_view->m_w = 0;
	list_view->m_h = 0;
	list_view->m_border = 0;
	list_view->m_rows = 0;
	list_view->m_auto_height = 0;
	list_view->m_idx = 0;
	list_view->m_callback = mk_lang_null;
	list_view->m_display = display;
	list_view->m_window = window;
	list_view->m_gc = gc;
	list_view->m_text_asc = 1;
	list_view->m_text_des = 1;
	err = mk_lib_x11_list_view_prrw_refresh_font_dimensions(list_view); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_destruct(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept
{
	mk_lang_assert(list_view);

	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_border(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const border) mk_lang_noexcept
{
	mk_lang_assert(list_view);
	mk_lang_assert(border);

	*border = list_view->m_border;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_border(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const border) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	if(list_view->m_border != border)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
		list_view->m_border = border;
		err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_dimensions(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const x, mk_lang_types_sint_pt const y, mk_lang_types_sint_pt const w, mk_lang_types_sint_pt const h) mk_lang_noexcept
{
	mk_lang_assert(list_view);
	mk_lang_assert(x);
	mk_lang_assert(y);
	mk_lang_assert(w);
	mk_lang_assert(h);

	*x = list_view->m_x;
	*y = list_view->m_y;
	*w = list_view->m_w;
	*h = list_view->m_h;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_dimensions(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	if
	(
		list_view->m_x != x ||
		list_view->m_y != y ||
		list_view->m_w != w ||
		list_view->m_h != h
	)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
		list_view->m_x = x;
		list_view->m_y = y;
		list_view->m_w = w;
		list_view->m_h = h;
		err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_rows(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const rows) mk_lang_noexcept
{
	mk_lang_assert(list_view);
	mk_lang_assert(rows);

	*rows = list_view->m_rows;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_rows(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const rows) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	if(list_view->m_rows != rows)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
		list_view->m_rows = rows;
		err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_auto_height(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const auto_height) mk_lang_noexcept
{
	mk_lang_assert(list_view);
	mk_lang_assert(auto_height);

	*auto_height = list_view->m_auto_height;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_auto_height(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const auto_height) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	if(list_view->m_auto_height != auto_height)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
		list_view->m_auto_height = auto_height;
		err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_idx(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const idx) mk_lang_noexcept
{
	mk_lang_assert(list_view);
	mk_lang_assert(idx);

	*idx = list_view->m_idx;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_idx(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	if(list_view->m_idx != idx)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, list_view->m_idx); mk_lang_check_rereturn(err);
		list_view->m_idx = idx;
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, list_view->m_idx); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_callback(mk_lib_x11_list_view_pct const list_view, mk_lib_x11_list_view_callback_pt const callback, mk_lib_x11_list_view_callctx_pt const context) mk_lang_noexcept
{
	mk_lang_assert(list_view);
	mk_lang_assert(callback);
	mk_lang_assert(context);

	*callback = list_view->m_callback;
	*context = list_view->m_context;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_callback(mk_lib_x11_list_view_pt const list_view, mk_lib_x11_list_view_callback_t const callback, mk_lib_x11_list_view_callctx_t const context) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	if
	(
		list_view->m_callback != callback ||
		list_view->m_context != context
	)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
		list_view->m_callback = callback;
		list_view->m_context = context;
		err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_invalidate_row(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);
	mk_lang_assert(idx >= 0 && idx < list_view->m_rows);

	err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_invalidate_all(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_keypres_home(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept
{
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	idx_old = list_view->m_idx;
	list_view->m_idx = 0;
	idx_new = list_view->m_idx;
	if(idx_new != idx_old)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_old); mk_lang_check_rereturn(err);
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_new); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_keypres_up(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept
{
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	idx_old = list_view->m_idx;
	list_view->m_idx = mk_lang_max(0, list_view->m_idx - 1);
	idx_new = list_view->m_idx;
	if(idx_new != idx_old)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_old); mk_lang_check_rereturn(err);
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_new); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_keypres_down(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept
{
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	idx_old = list_view->m_idx;
	list_view->m_idx = mk_lang_min(list_view->m_rows - 1, list_view->m_idx + 1);
	idx_new = list_view->m_idx;
	if(idx_new != idx_old)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_old); mk_lang_check_rereturn(err);
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_new); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_keypres_page_up(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept
{
	mk_lang_types_sint_t rows;
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	rows = list_view->m_h / (list_view->m_text_asc + list_view->m_text_des);
	idx_old = list_view->m_idx;
	list_view->m_idx = mk_lang_max(0, list_view->m_idx - rows);
	idx_new = list_view->m_idx;
	if(idx_new != idx_old)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_old); mk_lang_check_rereturn(err);
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_new); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_keypres_page_down(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept
{
	mk_lang_types_sint_t rows;
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	rows = list_view->m_h / (list_view->m_text_asc + list_view->m_text_des);
	idx_old = list_view->m_idx;
	list_view->m_idx = mk_lang_min(list_view->m_rows - 1, list_view->m_idx + rows);
	idx_new = list_view->m_idx;
	if(idx_new != idx_old)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_old); mk_lang_check_rereturn(err);
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_new); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_keypres_end(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept
{
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t idx_new;
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);

	idx_old = list_view->m_idx;
	list_view->m_idx = list_view->m_rows - 1;
	idx_new = list_view->m_idx;
	if(idx_new != idx_old)
	{
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_old); mk_lang_check_rereturn(err);
		err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_new); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_keypres(mk_lib_x11_list_view_pt const list_view, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	KeySym ks;
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == KeyPress);
	mk_lang_assert(consumed);

	if(evt->xkey.window == list_view->m_window)
	{
		ks = XLookupKeysym(&evt->xkey, 0);
		switch(ks)
		{
			case XK_Home     : err = mk_lib_x11_list_view_prrw_on_keypres_home     (list_view); mk_lang_check_rereturn(err); *consumed = mk_lang_true; break;
			case XK_Up       : err = mk_lib_x11_list_view_prrw_on_keypres_up       (list_view); mk_lang_check_rereturn(err); *consumed = mk_lang_true; break;
			case XK_Down     : err = mk_lib_x11_list_view_prrw_on_keypres_down     (list_view); mk_lang_check_rereturn(err); *consumed = mk_lang_true; break;
			case XK_Page_Up  : err = mk_lib_x11_list_view_prrw_on_keypres_page_up  (list_view); mk_lang_check_rereturn(err); *consumed = mk_lang_true; break;
			case XK_Page_Down: err = mk_lib_x11_list_view_prrw_on_keypres_page_down(list_view); mk_lang_check_rereturn(err); *consumed = mk_lang_true; break;
			case XK_End      : err = mk_lib_x11_list_view_prrw_on_keypres_end      (list_view); mk_lang_check_rereturn(err); *consumed = mk_lang_true; break;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_buttonpress(mk_lib_x11_list_view_pt const list_view, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t bx;
	mk_lang_types_sint_t by;
	mk_lang_types_sint_t mx;
	mk_lang_types_sint_t my;
	mk_lang_types_sint_t mw;
	mk_lang_types_sint_t mh;
	mk_lang_types_sint_t border;
	mk_lang_types_sint_t rows;
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t mr;
	mk_lang_types_sint_t mb;
	mk_lang_types_sint_t idx_cur;
	mk_lang_types_sint_t idx_new;
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);
	mk_lang_assert(list_view->m_w >= 0);
	mk_lang_assert(list_view->m_h >= 0);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ButtonPress);
	mk_lang_assert(consumed);

	if(evt->xbutton.window == list_view->m_window)
	{
		bx = evt->xbutton.x;
		by = evt->xbutton.y;
		mx = list_view->m_x;
		my = list_view->m_y;
		mw = list_view->m_w;
		mh = list_view->m_h;
		border = list_view->m_border;
		rows = list_view->m_rows;
		idx_old = list_view->m_idx;
		text_asc = list_view->m_text_asc;
		text_des = list_view->m_text_des;
		line_height = text_asc + text_des; mk_lang_assert(line_height >= 1);
		mk_lib_x11_list_view_rect_shrink(mx, my, mw, mh, border, &mx, &my, &mw, &mh);
		mr = mx + mw;
		mb = my + mh;
		if(bx >= mx && bx <= mr && by >= my && by <= mb)
		{
			idx_cur = (by - my) / line_height;
			idx_new = mk_lang_min(mk_lang_max(0, rows - 1), idx_cur);
			if(idx_new != idx_old)
			{
				list_view->m_idx = idx_new;
				err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_old); mk_lang_check_rereturn(err);
				err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_new); mk_lang_check_rereturn(err);
			}
			*consumed = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_expose(mk_lib_x11_list_view_pt const list_view, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t ex;
	mk_lang_types_sint_t ey;
	mk_lang_types_sint_t ew;
	mk_lang_types_sint_t eh;
	mk_lang_types_sint_t mx;
	mk_lang_types_sint_t my;
	mk_lang_types_sint_t mw;
	mk_lang_types_sint_t mh;
	mk_lang_types_sint_t border;
	mk_lang_types_sint_t rows;
	mk_lang_types_sint_t auto_height;
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t er;
	mk_lang_types_sint_t eb;
	mk_lang_types_sint_t mr;
	mk_lang_types_sint_t mb;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t cx;
	mk_lang_types_sint_t cy;
	mk_lang_types_sint_t cw;
	mk_lang_types_sint_t ch;
	mk_lang_types_sint_t cr;
	mk_lang_types_sint_t cb;
	mk_lang_types_sint_t y_min;
	mk_lang_types_sint_t y_max;
	mk_lang_types_sint_t idx_min;
	mk_lang_types_sint_t idx_max;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(list_view);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == Expose);
	mk_lang_assert(consumed);

	if(evt->xexpose.window == list_view->m_window)
	{
		ex = evt->xexpose.x;
		ey = evt->xexpose.y;
		ew = evt->xexpose.width;
		eh = evt->xexpose.height;
		mx = list_view->m_x;
		my = list_view->m_y;
		mw = list_view->m_w;
		mh = list_view->m_h;
		border = list_view->m_border;
		rows = list_view->m_rows;
		auto_height = list_view->m_auto_height;
		display = list_view->m_display;
		window = list_view->m_window;
		gc = list_view->m_gc;
		text_asc = list_view->m_text_asc;
		text_des = list_view->m_text_des;
		er = ex + ew;
		eb = ey + eh;
		mr = mx + mw;
		mb = my + mh;
		line_height = text_asc + text_des;
		mk_lang_assert(line_height >= 1);
		if(mw >= 1 && mh >= 1 && ew >= 1 && eh >= 1)
		{
			mk_lib_x11_list_view_rect_shrink(mx, my, mw, mh, border, &cx, &cy, &cw, &ch);
			cr = cx + cw;
			cb = cy + ch;
			if(cw >= 1 && ch >= 1)
			{
				if(mk_lib_x11_list_view_rect_intersect(mx, my, mw, mh, ex, ey, ew, eh))
				{
					if(mk_lib_x11_list_view_rect_intersect(mx, my, mw, mh, cx, cy, cw, ch))
					{
						y_min = mk_lang_max(cy, ey);
						y_max = mk_lang_min(cb, eb);
						mk_lang_assert(y_max >= y_min);
						idx_min = (y_min - my) / line_height;
						idx_max = mk_lang_div_roundup(y_max - my, line_height);
						mk_lang_assert(idx_min <= idx_max);
						for(idx = idx_min; idx != idx_max; ++idx)
						{
							err = mk_lib_x11_list_view_prro_on_expose_row(list_view, idx); mk_lang_check_rereturn(err);
						}
					}
					mk_lang_assert(auto_height >= 0);
					if(auto_height != 0)
					{
						mh = line_height * auto_height + 2 * border;
						if(list_view->m_h != mh)
						{
							err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
							list_view->m_h = mh;
							err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
						}
					}
					if(border != 0)
					{
						tsi = XDrawRectangle(display, window, gc, mx, my, mw - 1, mh - 1);
					}
					*consumed = mk_lang_true;
				}
			}
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_on_event(mk_lib_x11_list_view_pt const list_view, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(list_view);
	mk_lang_assert(evt);
	mk_lang_assert(consumed);

	switch(evt->type)
	{
		case KeyPress   : err = mk_lib_x11_list_view_prrw_on_keypres    (list_view, evt, consumed); mk_lang_check_rereturn(err); break;
		case ButtonPress: err = mk_lib_x11_list_view_prrw_on_buttonpress(list_view, evt, consumed); mk_lang_check_rereturn(err); break;
		case Expose     : err = mk_lib_x11_list_view_prrw_on_expose     (list_view, evt, consumed); mk_lang_check_rereturn(err); break;
	}
	return 0;
}
