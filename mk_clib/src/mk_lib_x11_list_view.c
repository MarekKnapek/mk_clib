#include "mk_lib_x11_list_view.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_platform.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_platform_x11_have == 1
#else
static mk_lang_inline mk_lang_types_sint_t XDrawString(Display* const display, Drawable const drawable, GC const gc, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_pchar_pct const text, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(drawable));
	((mk_lang_types_void_t)(gc));
	((mk_lang_types_void_t)(x));
	((mk_lang_types_void_t)(y));
	((mk_lang_types_void_t)(text));
	((mk_lang_types_void_t)(len));
	return 0;
}
#endif


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
	ret =
		((b_x >= a_x && b_x <= a_r) || (b_r >= a_x && b_r <= a_r)) ||
		((b_y >= a_y && b_y <= a_b) || (b_b >= a_y && b_b <= a_b));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_x11_list_view_rect_intersect(mk_lang_static_param(mk_lang_types_sint_ct, a, 4), mk_lang_static_param(mk_lang_types_sint_ct, b, 4)) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	ret = mk_lib_x11_list_view_rect_intersect_impl(a, b) || mk_lib_x11_list_view_rect_intersect_impl(b, a);
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_x11_list_view_prro_on_expose_row(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t mx;
	mk_lang_types_sint_t my;
	mk_lib_x11_list_view_callback_t callback;
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t x;
	mk_lang_types_sint_t y;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct text;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(list_view);
	mk_lang_assert(list_view->m_callback);
	mk_lang_assert(idx >= 0 && idx < list_view->m_rows);

	mx = list_view->m_x;
	my = list_view->m_y;
	callback = list_view->m_callback;
	display = list_view->m_display;
	window = list_view->m_window;
	gc = list_view->m_gc;
	text_asc = list_view->m_text_asc;
	text_des = list_view->m_text_des;
	line_height = text_asc + text_des;
	mk_lang_assert(line_height >= 1);
	x = mx;
	y = my + idx * line_height + line_height - text_des;
	err = callback(idx, &text, &len); mk_lang_check_rereturn(err); mk_lang_assert(len >= 0 && (len == 0 || (text && text[0] != '\0')));
	tsi = XDrawString(display, window, gc, x, y, text, len);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_construct(mk_lib_x11_list_view_pt const list_view, Display* const display, Window const window, GC const gc) mk_lang_noexcept
{
	mk_lang_assert(list_view);

	list_view->m_x = 0;
	list_view->m_y = 0;
	list_view->m_w = 0;
	list_view->m_h = 0;
	list_view->m_rows = 0;
	list_view->m_callback = mk_lang_null;
	list_view->m_display = display;
	list_view->m_window = window;
	list_view->m_gc = gc;
	list_view->m_text_asc = 1;
	list_view->m_text_des = 1;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_destruct(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept
{
	mk_lang_assert(list_view);

	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_dimensions(mk_lib_x11_list_view_pct const list_view, mk_lang_static_param(mk_lang_types_sint_t, dimensions, 4)) mk_lang_noexcept
{
	mk_lang_assert(list_view);
	mk_lang_assert(dimensions);

	dimensions[0] = list_view->m_x;
	dimensions[1] = list_view->m_y;
	dimensions[2] = list_view->m_w;
	dimensions[3] = list_view->m_h;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_dimensions(mk_lib_x11_list_view_pt const list_view, mk_lang_static_param(mk_lang_types_sint_ct, dimensions, 4)) mk_lang_noexcept
{
	mk_lang_assert(list_view);
	mk_lang_assert(dimensions);

	list_view->m_x = dimensions[0];
	list_view->m_y = dimensions[1];
	list_view->m_w = dimensions[2];
	list_view->m_h = dimensions[3];
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_callback(mk_lib_x11_list_view_pct const list_view, mk_lib_x11_list_view_callback_pt const callback) mk_lang_noexcept
{
	mk_lang_assert(list_view);
	mk_lang_assert(callback);

	*callback = list_view->m_callback;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_callback(mk_lib_x11_list_view_pt const list_view, mk_lib_x11_list_view_callback_t const callback) mk_lang_noexcept
{
	mk_lang_assert(list_view);

	list_view->m_callback = callback;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_on_expose(mk_lib_x11_list_view_pct const list_view, mk_lang_static_param(mk_lang_types_sint_ct, dimensions, 4)) mk_lang_noexcept
{
	mk_lang_types_sint_t my_rect[4];
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

	mk_lang_assert(list_view);
	mk_lang_assert(dimensions);

	my_rect[0] = list_view->m_x;
	my_rect[1] = list_view->m_y;
	my_rect[2] = list_view->m_w;
	my_rect[3] = list_view->m_h;
	text_asc = list_view->m_text_asc;
	text_des = list_view->m_text_des;
	line_height = text_asc + text_des;
	mk_lang_assert(line_height >= 1);
	if(mk_lib_x11_list_view_rect_intersect(&my_rect[0], &dimensions[0]))
	{
		a_x = my_rect[0];
		a_y = my_rect[1];
		a_w = my_rect[2];
		a_h = my_rect[3];
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
		mk_lang_assert(y_max >= y_min);
		idx_min = (y_min - a_y) / line_height;
		idx_max = mk_lang_div_roundup(y_max - a_y, line_height);
		mk_lang_assert(idx_min <= idx_max);
		for(idx = idx_min; idx != idx_max; ++idx)
		{
			err = mk_lib_x11_list_view_prro_on_expose_row(list_view, idx); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}
