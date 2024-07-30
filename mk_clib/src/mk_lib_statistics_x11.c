#include "mk_lib_statistics_x11.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_clamp.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_static_param.h"
#include "mk_lang_stringify.h"
#include "mk_lang_strlen.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_lib_x11_cong.h"
#include "mk_lib_x11_headers.h"
#include "mk_lib_x11_list_view.h"
#include "mk_sl_mallocatorg.h"
#include "mk_sl_uint128.h"

#define mk_lang_memcpy_t_name mk_lib_statistics_x11_memcpy_pc
#define mk_lang_memcpy_t_type mk_lang_types_pchar_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lang_memset_t_name mk_lib_statistics_x11_memset_pc
#define mk_lang_memset_t_type mk_lang_types_pchar_t
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"

#define mk_lang_swap_t_name mk_lib_statistics_x11_swap_ul
#define mk_lang_swap_t_type mk_lang_types_ulong_t
#include "mk_lang_swap_inl_fileh.h"
#include "mk_lang_swap_inl_filec.h"


mk_lang_constexpr_static_inline mk_lang_types_pchar_pct const mk_lib_statistics_x11_labels[] =
{
	"bytes allocated   ",
	"bytes deallocated ",
	"bytes peak        ",
	"bytes live        ",
	"blocks allocated  ",
	"blocks deallocated",
	"blocks peak       ",
	"blocks live       ",
};
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_statistics_x11_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789[]";


struct mk_lib_statistics_x11_cntrs_data_arrn_s
{
	mk_sl_cui_uint128_t m_bytes_allocated;
	mk_sl_cui_uint128_t m_bytes_deallocated;
	mk_sl_cui_uint128_t m_bytes_peak;
	mk_sl_cui_uint128_t m_bytes_live;
	mk_sl_cui_uint128_t m_blocks_allocated;
	mk_sl_cui_uint128_t m_blocks_deallocated;
	mk_sl_cui_uint128_t m_blocks_peak;
	mk_sl_cui_uint128_t m_blocks_live;
};
typedef struct mk_lib_statistics_x11_cntrs_data_arrn_s mk_lib_statistics_x11_cntrs_data_arrn_t;
struct mk_lib_statistics_x11_cntrs_data_arry_s
{
	mk_sl_cui_uint128_t m_cntrs[8];
};
typedef struct mk_lib_statistics_x11_cntrs_data_arry_s mk_lib_statistics_x11_cntrs_data_arry_t;
union mk_lib_statistics_x11_cntrs_data_u
{
	mk_lib_statistics_x11_cntrs_data_arrn_t m_arrn;
	mk_lib_statistics_x11_cntrs_data_arry_t m_arry;
};
typedef union mk_lib_statistics_x11_cntrs_data_u mk_lib_statistics_x11_cntrs_data_t;
struct mk_lib_statistics_x11_cntrs_s
{
	mk_lib_statistics_x11_cntrs_data_t m_data;
};
typedef struct mk_lib_statistics_x11_cntrs_s mk_lib_statistics_x11_cntrs_t;
typedef mk_lib_statistics_x11_cntrs_t const mk_lib_statistics_x11_cntrs_ct;
typedef mk_lib_statistics_x11_cntrs_t* mk_lib_statistics_x11_cntrs_pt;
typedef mk_lib_statistics_x11_cntrs_t const* mk_lib_statistics_x11_cntrs_pct;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_statistics_x11_cntrs_ro_eq(mk_lib_statistics_x11_cntrs_pct const a, mk_lib_statistics_x11_cntrs_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(a->m_data.m_arrn) == sizeof(a->m_data.m_arry));

	mk_lang_assert(a);
	mk_lang_assert(b);

	ret =
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[0], &b->m_data.m_arry.m_cntrs[0]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[1], &b->m_data.m_arry.m_cntrs[1]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[2], &b->m_data.m_arry.m_cntrs[2]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[3], &b->m_data.m_arry.m_cntrs[3]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[4], &b->m_data.m_arry.m_cntrs[4]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[5], &b->m_data.m_arry.m_cntrs[5]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[6], &b->m_data.m_arry.m_cntrs[6]) &&
		mk_sl_cui_uint128_eq(&a->m_data.m_arry.m_cntrs[7], &b->m_data.m_arry.m_cntrs[7]);
	return ret;
}

struct mk_lib_statistics_x11_s
{
	mk_lang_types_bool_t m_visible;
	mk_lang_types_sint_t m_screen;
	Window m_parent;
	Window m_window;
	GC m_gc;
	mk_lib_statistics_x11_cntrs_t m_cntrs_last;
	mk_lib_x11_list_view_t m_list_view;
	mk_lang_types_pchar_t m_tmp_str[32 + mk_sl_cui_uint128_strlendec_v];
};
typedef struct mk_lib_statistics_x11_s mk_lib_statistics_x11_t;
typedef mk_lib_statistics_x11_t const mk_lib_statistics_x11_ct;
typedef mk_lib_statistics_x11_t* mk_lib_statistics_x11_pt;
typedef mk_lib_statistics_x11_t const* mk_lib_statistics_x11_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_hide_(mk_lib_statistics_x11_pt const statistics) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(statistics);

	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	tsi = XUnmapWindow(display, window);
	statistics->m_visible = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_invalidate_all(mk_lib_statistics_x11_pt const statistics) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	Status st;
	XWindowAttributes attr;
	XEvent* evt;
	XEvent e;

	mk_lang_assert(statistics);

	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	st = XGetWindowAttributes(display, window, &attr);
	evt = &e;
	evt->type = Expose;
	evt->xexpose.type = Expose;
	evt->xexpose.serial = 0;
	evt->xexpose.send_event = True;
	evt->xexpose.display = display;
	evt->xexpose.window = window;
	evt->xexpose.x = 0;
	evt->xexpose.y = 0;
	evt->xexpose.width = attr.width;
	evt->xexpose.height = attr.height;
	evt->xexpose.count = 0;
	st = XSendEvent(display, window, False, ExposureMask, evt);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_expose(mk_lib_statistics_x11_pt const statistics, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	Window ew;
	Window mw;
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	Status st;
	XWindowAttributes attr;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == Expose);
	mk_lang_assert(consumed);

	ew = evt->xexpose.window;
	mw = statistics->m_window;
	if(ew == mw)
	{
		err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
		window = statistics->m_window;
		gc = statistics->m_gc;
		err = mk_lib_x11_cong_get_default_screen_black(&black); mk_lang_check_rereturn(err);
		err = mk_lib_x11_cong_get_default_screen_white(&white); mk_lang_check_rereturn(err);
		st = XGetWindowAttributes(display, window, &attr);
		if(evt->xexpose.x == 0 && evt->xexpose.y == 0 && evt->xexpose.width == attr.width && evt->xexpose.height == attr.height)
		{
			tsi = XSetForeground(display, gc, white);
			tsi = XFillRectangle(display, window, gc, 0, 0, attr.width, attr.height);
			tsi = XSetForeground(display, gc, black);
		}
		*consumed = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_keypress(mk_lib_statistics_x11_pt const statistics, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	Window ew;
	Window mw;
	KeySym ks;
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == KeyPress);
	mk_lang_assert(consumed);

	ew = evt->xkey.window;
	mw = statistics->m_window;
	if(ew == mw)
	{
		ks = XLookupKeysym(&evt->xkey, 0);
		switch(ks)
		{
			case XK_q:
			{
				statistics->m_visible = mk_lang_false;
				*consumed = mk_lang_true;
			}
			break;
			case XK_Escape:
			{
				statistics->m_visible = mk_lang_false;
				*consumed = mk_lang_true;
			}
			break;
			case XK_d:
			{
				err = mk_lib_x11_cong_get_default_screen_black(&black); mk_lang_check_rereturn(err);
				err = mk_lib_x11_cong_get_default_screen_white(&white); mk_lang_check_rereturn(err);
				mk_lib_statistics_x11_swap_ul_fn(&black, &white);
				err = mk_lib_x11_cong_set_default_screen_black(black); mk_lang_check_rereturn(err);
				err = mk_lib_x11_cong_set_default_screen_white(white); mk_lang_check_rereturn(err);
				err = mk_lib_statistics_x11_invalidate_all(statistics); mk_lang_check_rereturn(err);
				*consumed = mk_lang_true;
			}
			break;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_delete(mk_lib_statistics_x11_pt const statistics, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);
	mk_lang_assert(evt->xclient.window == statistics->m_window);
	mk_lang_assert(consumed);

	((mk_lang_types_void_t)(evt));
	statistics->m_visible = mk_lang_false;
	*consumed = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_configurenotify(mk_lib_statistics_x11_pt const statistics, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	Window ew;
	mk_lang_types_sint_t w;
	mk_lang_types_sint_t h;
	Window mw;
	mk_lib_x11_list_view_pt list_view;
	mk_lang_types_sint_t lvx;
	mk_lang_types_sint_t lvy;
	mk_lang_types_sint_t lvw;
	mk_lang_types_sint_t lvh;
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ConfigureNotify);
	mk_lang_assert(consumed);

	ew = evt->xconfigure.window;
	w = evt->xconfigure.width;
	h = evt->xconfigure.height;
	mw = statistics->m_window;
	list_view = &statistics->m_list_view;
	if(ew == mw)
	{
		lvx = 0;
		lvy = 0;
		lvw = w;
		lvh = h;
		err = mk_lib_x11_list_view_rw_set_dimensions(list_view, lvx, lvy, lvw, lvh); mk_lang_check_rereturn(err);
		*consumed = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_clientmessage(mk_lib_statistics_x11_pt const statistics, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	Window ew;
	Window mw;
	mk_lang_types_sint_t err;
	Atom wmdelete;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);
	mk_lang_assert(consumed);

	ew = evt->xclient.window;
	mw = statistics->m_window;
	if(ew == mw)
	{
		err = mk_lib_x11_cong_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
		if(((Atom)(evt->xclient.data.l[0])) == wmdelete){ err = mk_lib_statistics_x11_on_delete(statistics, evt, consumed); mk_lang_check_rereturn(err); }
	}
	return 0;
}

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_pump_all_window_specific(mk_lib_statistics_x11_pt const statistics, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	mk_lib_x11_list_view_pt list_view;
	Display* display;
	Window window;
	mk_lang_types_slong_t mask;
	XEvent* evt;
	XEvent e;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t consumed;

	mk_lang_assert(statistics);
	mk_lang_assert(at_least_one);

	list_view = &statistics->m_list_view;
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	mask = KeyPressMask | ButtonPressMask | ExposureMask | StructureNotifyMask;
	evt = &e;
	while(statistics->m_visible && XCheckWindowEvent(display, window, mask, evt) == True)
	{
		*at_least_one = mk_lang_true;
		switch(evt->type)
		{
			case KeyPress       : err = mk_lib_statistics_x11_on_keypress       (statistics, evt); mk_lang_check_rereturn(err); break;
			case Expose         : err = mk_lib_statistics_x11_on_expose         (statistics, evt); mk_lang_check_rereturn(err); break;
			case ConfigureNotify: err = mk_lib_statistics_x11_on_configurenotify(statistics, evt); mk_lang_check_rereturn(err); break;
			case ClientMessage  : err = mk_lib_statistics_x11_on_clientmessage  (statistics, evt); mk_lang_check_rereturn(err); break;
		}
		err = mk_lib_x11_list_view_rw_on_event(list_view, evt, &consumed); mk_lang_check_rereturn(err);
	}
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_pump_global(mk_lib_statistics_x11_pt const statistics, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	Display* display;
	Window window;
	XEvent* evt;
	XEvent e;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(at_least_one);

	if(!statistics->m_visible)
	{
		err = mk_lib_statistics_x11_hide_(statistics); mk_lang_check_rereturn(err);
	}
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	evt = &e;
	gud = mk_lang_true;
	while(statistics->m_visible && gud)
	{
		gud = mk_lang_false;
		tsi = XPeekEvent(display, evt);
		if(evt->type == ClientMessage)
		{
			if(evt->xclient.window == window)
			{
				gud = mk_lang_true;
				*at_least_one = mk_lang_true;
				tsi = XNextEvent(display, evt);
				mk_lang_assert(evt->type == ClientMessage);
				mk_lang_assert(evt->xclient.window == window);
				err = mk_lib_statistics_x11_on_clientmessage(statistics, evt); mk_lang_check_rereturn(err);
			}
		}
	}
	if(!statistics->m_visible)
	{
		err = mk_lib_statistics_x11_hide_(statistics); mk_lang_check_rereturn(err);
	}
	return 0;
}*/

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_longest_text(mk_lib_statistics_x11_pt const statistics, mk_lang_types_sint_pt const longest) mk_lang_noexcept
{
	mk_lang_types_sint_t big;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t len;
	mk_lang_types_pchar_t str[mk_sl_cui_uint128_strlendec_v];

	mk_lang_assert(statistics);
	mk_lang_assert(longest);

	big = 0;
	n = mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs);
	for(i = 0; i != n; ++i)
	{
		len = mk_sl_cui_uint128_to_str_dec_n(&statistics->m_cntrs_last.m_data.m_arry.m_cntrs[i], &str[0], mk_lang_countof(str)); mk_lang_assert(len >= 1 && len <= mk_lang_countof(str));
		big = mk_lang_max(big, len);
	}
	*longest = big;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_row(mk_lib_x11_list_view_callctx_t const context, mk_lang_types_sint_t const idx, mk_lang_types_pchar_ppct const text, mk_lang_types_sint_pt const len) mk_lang_noexcept
{
	mk_lib_statistics_x11_pt statistics;
	mk_sl_cui_uint128_pct cntr;
	mk_lang_types_sint_t lensi;
	mk_lang_types_pchar_t str[mk_sl_cui_uint128_strlendec_v];
	mk_lang_types_usize_t lenus;
	mk_lang_types_pchar_t space;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t longest;

	mk_lang_assert(context);
	mk_lang_assert(idx >= 0 && idx < mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs));
	mk_lang_assert(text);
	mk_lang_assert(len);

	statistics = ((mk_lib_statistics_x11_pt)(context));
	cntr = &statistics->m_cntrs_last.m_data.m_arry.m_cntrs[idx];
	lensi = mk_sl_cui_uint128_to_str_dec_n(cntr, &str[0], mk_lang_countof(str)); mk_lang_assert(lensi >= 1 && lensi <= mk_lang_countof(str));
	lenus = mk_lang_strlen_n_fn(mk_lib_statistics_x11_labels[idx]); mk_lang_assert(lenus <= mk_lang_countof(statistics->m_tmp_str) - mk_lang_countof(str) - 1);
	mk_lib_statistics_x11_memcpy_pc_fn(&statistics->m_tmp_str[0], &mk_lib_statistics_x11_labels[idx][0], lenus);
	space = ' ';
	statistics->m_tmp_str[lenus] = space;
	err = mk_lib_statistics_x11_longest_text(statistics, &longest); mk_lang_check_rereturn(err);
	mk_lib_statistics_x11_memset_pc_fn(&statistics->m_tmp_str[lenus + 1], &space, longest - lensi);
	mk_lib_statistics_x11_memcpy_pc_fn(&statistics->m_tmp_str[lenus + 1 + (longest - lensi)], &str[0], lensi);
	*text = &statistics->m_tmp_str[0];
	*len = ((mk_lang_types_sint_t)(lenus)) + 1 + (longest - lensi) + lensi;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_init_(mk_lib_statistics_x11_pt const statistics) mk_lang_noexcept
{
	mk_sl_cui_uint128_t zero;
	mk_lang_types_sint_t err;
	Display* display;
	Atom wmdelete;
	mk_lang_types_sint_t screen;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	Window parent;
	Window window;
	mk_lang_types_slong_t mask;
	mk_lang_types_sint_t tsi;
	GC gc;

	mk_lang_assert(statistics);

	mk_sl_cui_uint128_set_zero(&zero);
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
	screen = DefaultScreen(display);
	err = mk_lib_x11_cong_get_default_screen_black(&black); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_default_screen_white(&white); mk_lang_check_rereturn(err);
	parent = RootWindow(display, screen);
	window = XCreateSimpleWindow(display, parent, 0, 0, 220, 100, 0, black, white);
	mask = KeyPressMask | ButtonPressMask | ExposureMask | StructureNotifyMask;
	tsi = XSelectInput(display, window, mask);
	tsi = XSetStandardProperties(display, window, "statistics", mk_lang_null, None, mk_lang_null, 0, mk_lang_null);
	tsi = XSetWMProtocols(display, window, &wmdelete, 1);
	gc = XCreateGC(display, window, 0, mk_lang_null);
	tsi = XSetBackground(display, gc, white);
	tsi = XSetForeground(display, gc, black);
	tsi = XClearWindow(display, window);
	statistics->m_visible = mk_lang_false;
	statistics->m_screen = screen;
	statistics->m_parent = parent;
	statistics->m_window = window;
	statistics->m_gc = gc;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[0] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[1] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[2] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[3] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[4] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[5] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[6] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[7] = zero;
	err = mk_lib_x11_list_view_rw_construct(&statistics->m_list_view, display, window, gc); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_dimensions(&statistics->m_list_view, 0, 0, 220, 100); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_rows(&statistics->m_list_view, mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs)); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_auto_height(&statistics->m_list_view, mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs)); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_callback(&statistics->m_list_view, &mk_lib_statistics_x11_on_row, statistics); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_deinit_(mk_lib_statistics_x11_pt const statistics) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(statistics);

	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	gc = statistics->m_gc;
	err = mk_lib_x11_list_view_rw_destruct(&statistics->m_list_view); mk_lang_check_rereturn(err);
	tsi = XFreeGC(display, gc);
	tsi = XDestroyWindow(display, window);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_show_(mk_lib_statistics_x11_pt const statistics) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(statistics);

	err = mk_lib_statistics_x11_invalidate(); mk_lang_check_rereturn(err);
	if(!statistics->m_visible)
	{
		statistics->m_visible = mk_lang_true;
		err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
		window = statistics->m_window;
		tsi = XMapRaised(display, window);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_invalidate_(mk_lib_statistics_x11_pt const statistics) mk_lang_noexcept
{
	mk_lib_x11_list_view_pt list_view;
	mk_lang_types_sint_t err;
	mk_lib_statistics_x11_cntrs_t cntrs;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(statistics);

	list_view = &statistics->m_list_view;
	err = mk_sl_mallocatorg_statistics_get_all(&cntrs.m_data.m_arry.m_cntrs[0]); mk_lang_check_rereturn(err);
	n = mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs);
	for(i = 0; i != n; ++i)
	{
		if(!mk_sl_cui_uint128_eq(&cntrs.m_data.m_arry.m_cntrs[i], &statistics->m_cntrs_last.m_data.m_arry.m_cntrs[i]))
		{
			statistics->m_cntrs_last.m_data.m_arry.m_cntrs[i] = cntrs.m_data.m_arry.m_cntrs[i];
			if(statistics->m_visible)
			{
				err = mk_lib_x11_list_view_rw_invalidate_row(list_view, i); mk_lang_check_rereturn(err);
			}
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_event_(mk_lib_statistics_x11_pt const statistics, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(consumed);

	switch(evt->type)
	{
		case KeyPress       : err = mk_lib_statistics_x11_on_keypress       (statistics, evt, consumed); mk_lang_check_rereturn(err); break;
		case Expose         : err = mk_lib_statistics_x11_on_expose         (statistics, evt, consumed); mk_lang_check_rereturn(err); break;
		case ConfigureNotify: err = mk_lib_statistics_x11_on_configurenotify(statistics, evt, consumed); mk_lang_check_rereturn(err); break;
		case ClientMessage  : err = mk_lib_statistics_x11_on_clientmessage  (statistics, evt, consumed); mk_lang_check_rereturn(err); break;
	}
	err = mk_lib_x11_list_view_rw_on_event(&statistics->m_list_view, evt, consumed); mk_lang_check_rereturn(err);
	if(!statistics->m_visible)
	{
		err = mk_lib_statistics_x11_hide_(statistics); mk_lang_check_rereturn(err);
	}
	return 0;
}


static mk_lib_statistics_x11_t g_mk_lib_statistics_x11;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_statistics_x11_init_(&g_mk_lib_statistics_x11);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_statistics_x11_deinit_(&g_mk_lib_statistics_x11);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_show(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_statistics_x11_show_(&g_mk_lib_statistics_x11);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_hide(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_statistics_x11_hide_(&g_mk_lib_statistics_x11);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_invalidate(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_lib_statistics_x11_invalidate_(&g_mk_lib_statistics_x11);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_on_event(XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	return mk_lib_statistics_x11_on_event_(&g_mk_lib_statistics_x11, evt, consumed);
}
