#include "mk_lib_x11_list_view.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
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


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_x11_list_view_rect_intersect_impl(mk_lang_static_param(mk_lang_types_sint_ct, a, 4), mk_lang_static_param(mk_lang_types_sint_ct, b, 4)) mk_lang_noexcept
{
	mk_lang_types_sint_t a_x;
	mk_lang_types_sint_t a_y;
	mk_lang_types_sint_t a_w;
	mk_lang_types_sint_t a_h;
	mk_lang_types_sint_t a_r;
	mk_lang_types_sint_t a_b;
	mk_lang_types_sint_t b_x;
	mk_lang_types_sint_t b_y;
	mk_lang_types_sint_t b_w;
	mk_lang_types_sint_t b_h;
	mk_lang_types_sint_t b_r;
	mk_lang_types_sint_t b_b;
	mk_lang_types_bool_t ret;

	mk_lang_assert(a);
	mk_lang_assert(b);

	a_x = a[0];
	a_y = a[1];
	a_w = a[2];
	a_h = a[3];
	a_r = a_x + a_w;
	a_b = a_y + a_h;
	b_x = b[0];
	b_y = b[1];
	b_w = b[2];
	b_h = b[3];
	b_r = b_x + b_w;
	b_b = b_y + b_h;
	mk_lang_assert(a_w >= 0);
	mk_lang_assert(a_h >= 0);
	mk_lang_assert(b_w >= 0);
	mk_lang_assert(b_h >= 0);
	ret = (b_x >= a_x && b_x <= a_r) && (b_y >= a_y && b_y <= a_b);
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_x11_list_view_rect_intersect(mk_lang_static_param(mk_lang_types_sint_ct, a, 4), mk_lang_static_param(mk_lang_types_sint_ct, b, 4)) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	ret = mk_lib_x11_list_view_rect_intersect_impl(a, b) || mk_lib_x11_list_view_rect_intersect_impl(b, a);
/*printf("intersect %d %d %d %d x %d %d %d %d = %d\n", a[0], a[1], a[2], a[3], b[0], b[1], b[2], b[3], ret);*/
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
	mk_lang_assert(id >= 0 && id < list_view->m_rows);

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
	mk_lang_types_sint_t idx;
	mk_lib_x11_list_view_callback_t callback;
	mk_lib_x11_list_view_callctx_t context;
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t x;
	mk_lang_types_sint_t y;
	mk_lang_types_sint_t w;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct text;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(list_view);
	mk_lang_assert(list_view->m_callback);
	mk_lang_assert(id >= 0);

	mx = list_view->m_x + list_view->m_border;
	my = list_view->m_y + list_view->m_border;
	mw = list_view->m_w - 2 * list_view->m_border;
	idx = list_view->m_idx;
	callback = list_view->m_callback;
	context = list_view->m_context;
	display = list_view->m_display;
	window = list_view->m_window;
	gc = list_view->m_gc;
	err = mk_lib_x11_cong_get_default_screen_black(&black); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_default_screen_white(&white); mk_lang_check_rereturn(err);
	text_asc = list_view->m_text_asc;
	text_des = list_view->m_text_des;
	line_height = text_asc + text_des;
	mk_lang_assert(line_height >= 1);
	x = mx;
	y = my + id * line_height;
	w = mw;
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
	if(id < list_view->m_rows)
	{
		err = callback(context, id, &text, &len); mk_lang_check_rereturn(err); mk_lang_assert(len >= 0 && (len == 0 || (text && text[0] != '\0')));
		y += (line_height - text_des);
		tsi = XDrawString(display, window, gc, x, y, text, len);
		y -= (line_height - text_des);
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


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_construct(mk_lib_x11_list_view_pt const list_view, Display* const display, Window const window, GC const gc) mk_lang_noexcept
{
	GContext gcid;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t direction;
	mk_lang_types_sint_t ascent;
	mk_lang_types_sint_t descent;
	XCharStruct overall;

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
	gcid = XGContextFromGC(gc);
	tsi = XQueryTextExtents(display, gcid, &mk_lib_x11_list_view_alphabet[0], mk_lang_countstr(mk_lib_x11_list_view_alphabet), &direction, &ascent, &descent, &overall); mk_lang_assert(overall.ascent + overall.descent >= 1);
	list_view->m_text_asc = overall.ascent;
	list_view->m_text_des = overall.descent;
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
	mk_lang_assert(list_view);

	list_view->m_border = border;
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
	mk_lang_assert(list_view);

	list_view->m_x = x;
	list_view->m_y = y;
	list_view->m_w = w;
	list_view->m_h = h;
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
	mk_lang_assert(list_view);

	list_view->m_rows = rows;
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
	mk_lang_assert(list_view);

	list_view->m_auto_height = auto_height;
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
	mk_lang_assert(list_view);

	list_view->m_callback = callback;
	list_view->m_context = context;
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
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_buttonpress(mk_lib_x11_list_view_pt const list_view, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t x;
	mk_lang_types_sint_t y;
	mk_lang_types_sint_t mx;
	mk_lang_types_sint_t my;
	mk_lang_types_sint_t mw;
	mk_lang_types_sint_t mh;
	mk_lang_types_sint_t border;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t idx_old;
	mk_lang_types_sint_t rows;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t mr;
	mk_lang_types_sint_t mb;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t idx_new;
	

	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	mk_lang_types_usize_t rowsus;
	mk_lang_types_sint_t rowssi;

	mk_lang_assert(list_view);
	mk_lang_assert(list_view->m_w >= 0);
	mk_lang_assert(list_view->m_h >= 0);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ButtonPress);
	mk_lang_assert(consumed);

	x = evt->xbutton.x;
	y = evt->xbutton.y;
	mx = list_view->m_x;
	my = list_view->m_y;
	mw = list_view->m_w;
	mh = list_view->m_h;
	border = list_view->m_border;
	text_asc = list_view->m_text_asc;
	text_des = list_view->m_text_des;
	idx_old = list_view->m_idx;
	rows = list_view->m_rows;
	line_height = text_asc + text_des;
	mr = mx + mw;
	mb = my + mh;
	if(x >= mx && x <= mr && y >= my && y <= mb)
	{
		mx += border;
		my += border;
		mw -= 2 * border;
		mh -= 2 * border;
		mr -= border;
		mb -= border;
		if(x >= mx && x <= mr && y >= my && y <= mb)
		{
			idx = (y - my) / line_height;
			idx_new = mk_lang_min(mk_lang_max(0, rows - 1), idx);
			if(idx_new != idx_old)
			{
				list_view->m_idx = idx_new;
				err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_old); mk_lang_check_rereturn(err);
				err = mk_lib_x11_list_view_prrw_invalidate_row(list_view, idx_new); mk_lang_check_rereturn(err);
			}
		}
		*consumed = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prrw_on_expose(mk_lib_x11_list_view_pt const list_view, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t dimensions[4];
	mk_lang_types_sint_t rect_outer[4];
	mk_lang_types_sint_t rect_inner[4];
	mk_lang_types_sint_t rows;
	mk_lang_types_sint_t auto_height;
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t a_x;
	mk_lang_types_sint_t a_y;
	mk_lang_types_sint_t a_w;
	mk_lang_types_sint_t a_h;
	mk_lang_types_sint_t a_r;
	mk_lang_types_sint_t a_b;
	mk_lang_types_sint_t b_x;
	mk_lang_types_sint_t b_y;
	mk_lang_types_sint_t b_w;
	mk_lang_types_sint_t b_h;
	mk_lang_types_sint_t b_r;
	mk_lang_types_sint_t b_b;
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

	dimensions[0] = evt->xexpose.x;
	dimensions[1] = evt->xexpose.y;
	dimensions[2] = evt->xexpose.width;
	dimensions[3] = evt->xexpose.height;
	rect_outer[0] = list_view->m_x;
	rect_outer[1] = list_view->m_y;
	rect_outer[2] = list_view->m_w;
	rect_outer[3] = list_view->m_h;
	rect_inner[0] = list_view->m_x + list_view->m_border;
	rect_inner[1] = list_view->m_y + list_view->m_border;
	rect_inner[2] = list_view->m_w - 2 * list_view->m_border;
	rect_inner[3] = list_view->m_h - 2 * list_view->m_border;
	rows = list_view->m_rows;
	auto_height = list_view->m_auto_height;
	display = list_view->m_display;
	window = list_view->m_window;
	gc = list_view->m_gc;
	text_asc = list_view->m_text_asc;
	text_des = list_view->m_text_des;
	line_height = text_asc + text_des;
	mk_lang_assert(line_height >= 1);
	if(mk_lib_x11_list_view_rect_intersect(&rect_outer[0], &dimensions[0]))
	{
		if(mk_lib_x11_list_view_rect_intersect(&rect_inner[0], &dimensions[0]))
		{
			a_x = rect_inner[0];
			a_y = rect_inner[1];
			a_w = rect_inner[2];
			a_h = rect_inner[3];
			a_r = a_x + a_w;
			a_b = a_y + a_h;
			b_x = dimensions[0];
			b_y = dimensions[1];
			b_w = dimensions[2];
			b_h = dimensions[3];
			b_r = b_x + b_w;
			b_b = b_y + b_h;
			mk_lang_assert(a_w >= 0);
			mk_lang_assert(a_h >= 0);
			mk_lang_assert(b_w >= 0);
			mk_lang_assert(b_h >= 0);
			y_min = mk_lang_max(a_y, b_y);
			y_max = mk_lang_min(a_b, b_b);
//printf("on expose ax=%d ay=%d aw=%d ah=%d ar=%d ab=%d bx=%d by=%d bw=%d bh=%d br=%d bb=%d\n", a_x, a_y, a_w, a_h, a_r, a_b, b_x, b_y, b_w, b_h, b_r, b_b);
			mk_lang_assert(y_max >= y_min);
			idx_min = (y_min - a_y) / line_height;
			idx_max = mk_lang_div_roundup(y_max - a_y, line_height);
			mk_lang_assert(idx_min <= idx_max);
			for(idx = idx_min; idx != idx_max; ++idx)
			{
				err = mk_lib_x11_list_view_prro_on_expose_row(list_view, idx); mk_lang_check_rereturn(err);
			}
		}
		if(list_view->m_border != 0)
		{
			a_x = rect_outer[0];
			a_y = rect_outer[1];
			a_w = rect_outer[2];
			a_h = rect_outer[3];
			a_r = a_x + a_w;
			a_b = a_y + a_h;
			tsi = XDrawRectangle(display, window, gc, a_x, a_y, a_w - 1, a_h - 1);
		}
		mk_lang_assert(auto_height >= 0);
		if(auto_height != 0)
		{
			a_h = line_height * auto_height;
			if(list_view->m_h != a_h)
			{
				err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
				list_view->m_h = a_h;
				err = mk_lib_x11_list_view_prrw_invalidate_all(list_view); mk_lang_check_rereturn(err);
			}
		}
		*consumed = mk_lang_true;
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
