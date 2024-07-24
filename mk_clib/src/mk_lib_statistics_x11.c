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
#include "mk_lang_platform.h"
#include "mk_lang_static_param.h"
#include "mk_lang_stringify.h"
#include "mk_lang_strlen.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"
#include "mk_lib_crypto_hash_stream_sha1.h"
#include "mk_sl_uint128.h"

#define mk_lang_memcpy_t_name mk_lib_statistics_x11_memcpy_pc
#define mk_lang_memcpy_t_type mk_lang_types_pchar_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"


#if mk_lang_platform_x11_have == 1

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>


#define mk_lib_statistics_x11_mallocatorg_id_disp        11
#define mk_lib_statistics_x11_mallocatorg_id_portablec   12
#define mk_lib_statistics_x11_mallocatorg_id_portablecpp 13
#define mk_lib_statistics_x11_mallocatorg_id_windows     14
#define mk_lib_statistics_x11_mallocatorg_id_tracer      15

#if defined mk_lib_statistics_x11_mallocatorg_want && (mk_lib_statistics_x11_mallocatorg_want) == mk_lib_statistics_x11_mallocatorg_id_disp
#define mk_lib_statistics_x11_mallocatorg_id mk_lib_statistics_x11_mallocatorg_id_disp
#elif defined mk_lib_statistics_x11_mallocatorg_want && (mk_lib_statistics_x11_mallocatorg_want) == mk_lib_statistics_x11_mallocatorg_id_portablec
#define mk_lib_statistics_x11_mallocatorg_id mk_lib_statistics_x11_mallocatorg_id_portablec
#elif defined mk_lib_statistics_x11_mallocatorg_want && (mk_lib_statistics_x11_mallocatorg_want) == mk_lib_statistics_x11_mallocatorg_id_portablecpp
#define mk_lib_statistics_x11_mallocatorg_id mk_lib_statistics_x11_mallocatorg_id_portablecpp
#elif defined mk_lib_statistics_x11_mallocatorg_want && (mk_lib_statistics_x11_mallocatorg_want) == mk_lib_statistics_x11_mallocatorg_id_windows
#define mk_lib_statistics_x11_mallocatorg_id mk_lib_statistics_x11_mallocatorg_id_windows
#elif defined mk_lib_statistics_x11_mallocatorg_want && (mk_lib_statistics_x11_mallocatorg_want) == mk_lib_statistics_x11_mallocatorg_id_tracer
#define mk_lib_statistics_x11_mallocatorg_id mk_lib_statistics_x11_mallocatorg_id_tracer
#elif !defined mk_lib_statistics_x11_mallocatorg_want
#if defined NDEBUG
#define mk_lib_statistics_x11_mallocatorg_id mk_lib_statistics_x11_mallocatorg_id_disp
#else
#define mk_lib_statistics_x11_mallocatorg_id mk_lib_statistics_x11_mallocatorg_id_tracer
#endif
#else
#error xxxxxxxxxx
#endif

#if mk_lib_statistics_x11_mallocatorg_id == mk_lib_statistics_x11_mallocatorg_id_disp
#include "mk_sl_mallocatorg.h"
#define mk_lib_statistics_x11_mallocatorg_name mk_sl_mallocatorg
#elif mk_lib_statistics_x11_mallocatorg_id == mk_lib_statistics_x11_mallocatorg_id_portablec
#include "mk_sl_mallocatorg_portablec.h"
#define mk_lib_statistics_x11_mallocatorg_name mk_sl_mallocatorg_portablec
#elif mk_lib_statistics_x11_mallocatorg_id == mk_lib_statistics_x11_mallocatorg_id_portablecpp
#include "mk_sl_mallocatorg_portablecpp.hpp"
#define mk_lib_statistics_x11_mallocatorg_name mk_sl_mallocatorg_portablecpp
#elif mk_lib_statistics_x11_mallocatorg_id == mk_lib_statistics_x11_mallocatorg_id_windows
#include "mk_sl_mallocatorg_windows.h"
#define mk_lib_statistics_x11_mallocatorg_name mk_sl_mallocatorg_windows
#elif mk_lib_statistics_x11_mallocatorg_id == mk_lib_statistics_x11_mallocatorg_id_tracer
#include "mk_sl_mallocg_tracer.h"
#define mk_lib_statistics_x11_mallocatorg_name mk_sl_mallocg_tracer
#else
#error xxxxxxxxxx
#endif
#define mk_lib_statistics_x11_mallocatorg_init                              mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _init)
#define mk_lib_statistics_x11_mallocatorg_deinit                            mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _deinit)
#define mk_lib_statistics_x11_mallocatorg_allocate                          mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _allocate)
#define mk_lib_statistics_x11_mallocatorg_deallocate                        mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _deallocate)
#define mk_lib_statistics_x11_mallocatorg_reallocate                        mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _reallocate)
#define mk_lib_statistics_x11_mallocatorg_statistics_get_bytes_allocated    mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _statistics_get_bytes_allocated)
#define mk_lib_statistics_x11_mallocatorg_statistics_get_bytes_deallocated  mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _statistics_get_bytes_deallocated)
#define mk_lib_statistics_x11_mallocatorg_statistics_get_bytes_live         mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _statistics_get_bytes_live)
#define mk_lib_statistics_x11_mallocatorg_statistics_get_bytes_peak         mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _statistics_get_bytes_peak)
#define mk_lib_statistics_x11_mallocatorg_statistics_get_blocks_allocated   mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _statistics_get_blocks_allocated)
#define mk_lib_statistics_x11_mallocatorg_statistics_get_blocks_deallocated mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _statistics_get_blocks_deallocated)
#define mk_lib_statistics_x11_mallocatorg_statistics_get_blocks_live        mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _statistics_get_blocks_live)
#define mk_lib_statistics_x11_mallocatorg_statistics_get_blocks_peak        mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _statistics_get_blocks_peak)
#define mk_lib_statistics_x11_mallocatorg_statistics_get_all                mk_lang_concat(mk_lib_statistics_x11_mallocatorg_name, _statistics_get_all)


mk_lang_constexpr_static_inline mk_lang_types_pchar_pct const mk_lib_statistics_x11_labels[] =
{
	"bytes allocated",
	"bytes deallocated",
	"bytes peak",
	"bytes live",
	"blocks allocated",
	"blocks deallocated",
	"blocks peak",
	"blocks live",
};


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
	mk_lang_types_bool_t m_keep_running;
	mk_lang_types_bool_t m_closed;
	mk_lang_types_sint_t m_screen;
	mk_lang_types_ulong_t m_black;
	mk_lang_types_ulong_t m_white;
	Window m_parent;
	Window m_window;
	GC m_gc;
	mk_lang_types_sint_t m_idx;
	mk_lang_types_sint_t m_line_height;
	mk_lang_types_sint_t m_line_hcur;
	mk_lib_statistics_x11_cntrs_t m_cntrs_last;
};
typedef struct mk_lib_statistics_x11_s mk_lib_statistics_x11_t;
typedef mk_lib_statistics_x11_t const mk_lib_statistics_x11_ct;
typedef mk_lib_statistics_x11_t* mk_lib_statistics_x11_pt;
typedef mk_lib_statistics_x11_t const* mk_lib_statistics_x11_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_invalidate_one(mk_lib_statistics_x11_pt const statistics, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	mk_lang_types_sint_t line_height;
	Status st;
	XEvent* evt;
	XEvent e;
	XWindowAttributes attr;

	mk_lang_assert(statistics);

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	line_height = statistics->m_line_height;
	st = XGetWindowAttributes(display, window, &attr);
	evt = &e;
	evt->type = Expose;
	evt->xexpose.type = Expose;
	evt->xexpose.serial = 0;
	evt->xexpose.send_event = True;
	evt->xexpose.display = display;
	evt->xexpose.window = window;
	evt->xexpose.x = 0;
	evt->xexpose.y = idx * line_height;
	evt->xexpose.width = attr.width;
	evt->xexpose.height = line_height;
	evt->xexpose.count = 0;
	st = XSendEvent(display, window, False, ExposureMask, &e);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_invalidate_all(mk_lib_statistics_x11_pt const statistics) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	XEvent e;
	Status st;
	XWindowAttributes attr;

	mk_lang_assert(statistics);

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	st = XGetWindowAttributes(display, window, &attr);
	e.type = Expose;
	e.xexpose.type = Expose;
	e.xexpose.serial = 0;
	e.xexpose.send_event = True;
	e.xexpose.display = display;
	e.xexpose.window = window;
	e.xexpose.x = 0;
	e.xexpose.y = 0;
	e.xexpose.width = attr.width;
	e.xexpose.height = attr.height;
	e.xexpose.count = 0;
	st = XSendEvent(display, window, False, ExposureMask, &e);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_expose_row(mk_lib_statistics_x11_pt const statistics, XEvent* const evt, mk_lang_types_sint_t const width, mk_lang_types_bool_t const measure, mk_lang_types_sint_t const idx) mk_lang_noexcept
{
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	mk_lang_types_sint_t tsi;
	Status st;
	GContext gcid;
	mk_lang_types_sint_t y;
	mk_lang_types_pchar_pct buf;
	mk_lang_types_usize_t lenus;
	mk_lang_types_sint_t lensi;
	mk_lang_types_sint_t height;
	mk_lang_types_sint_t height_max;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t direction;
	mk_lang_types_sint_t ascent;
	mk_lang_types_sint_t descent;
	XCharStruct dimensions;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint128_pct cntr;
	mk_lang_types_pchar_t str[mk_sl_cui_uint128_strlendec_v];
	mk_lang_types_pchar_t msg[32 + mk_lang_countof(str)];

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == Expose);
	mk_lang_assert(evt->xexpose.count == 0);
	mk_lang_assert(idx >= 0 && idx <= mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs));

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	gc = statistics->m_gc;
	black = statistics->m_black;
	white = statistics->m_white;
	line_height = statistics->m_line_height;
	height_max = line_height;
	gcid = XGContextFromGC(gc);
	cntr = &statistics->m_cntrs_last.m_data.m_arry.m_cntrs[idx];
	lensi = mk_sl_cui_uint128_to_str_dec_n(cntr, &str[0], mk_lang_countof(str)); mk_lang_assert(lensi >= 1 && lensi <= mk_lang_countof(str));
	lenus = mk_lang_strlen_n_fn(mk_lib_statistics_x11_labels[idx]);
	mk_lib_statistics_x11_memcpy_pc_fn(&msg[0], &mk_lib_statistics_x11_labels[idx][0], lenus);
	msg[lenus] = ' ';
	mk_lib_statistics_x11_memcpy_pc_fn(&msg[lenus + 1], &str[0], lensi);
	if(measure)
	{
		tsi = XQueryTextExtents(display, gcid, &str[0], lenus + 1 + lensi, &direction, &ascent, &descent, &dimensions);
		height = dimensions.ascent + dimensions.descent;
		height_max = mk_lang_max(height_max, height);
	}
	y = idx * line_height;
	if(idx != statistics->m_idx)
	{
		tsi = XSetForeground(display, gc, white);
		tsi = XFillRectangle(display, window, gc, 0, y, width, line_height);
		tsi = XSetForeground(display, gc, black);
	}
	else
	{
		tsi = XFillRectangle(display, window, gc, 0, y, width, line_height);
		tsi = XSetForeground(display, gc, white);
	}
	y += line_height;
	tsi = XDrawString(display, window, gc, 0, y, &str[0], lensi);
	if(idx == statistics->m_idx)
	{
		tsi = XSetForeground(display, gc, black);
	}
	statistics->m_line_hcur = mk_lang_max(statistics->m_line_hcur, height_max);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_expose(mk_lib_statistics_x11_pt const statistics, XEvent* const evt) mk_lang_noexcept
{
	Display* display;
	Window window;
	mk_lang_types_sint_t tsi;
	Status st;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	XWindowAttributes attr;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t ymin;
	mk_lang_types_sint_t ymax;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == Expose);

	if(evt->xexpose.count == 0)
	{
		err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
		window = statistics->m_window;
		statistics->m_line_hcur = 0;
		st = XGetWindowAttributes(display, window, &attr);
		n = mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs);
		if(evt->xexpose.x == 0 && evt->xexpose.y == 0 && evt->xexpose.width == attr.width && evt->xexpose.height == attr.height)
		{
			tsi = XClearWindow(display, window);
			for(i = 0; i != n; ++i)
			{
				err = mk_lib_statistics_x11_on_expose_row(statistics, evt, attr.width, mk_lang_true, i); mk_lang_check_rereturn(err);
			}
		}
		else
		{
			i = evt->xexpose.y / statistics->m_line_height;
			i = mk_lang_min(i, n);
			n = mk_lang_min(n, i + mk_lang_div_roundup(evt->xexpose.height, statistics->m_line_height));
			for(; i != n; ++i)
			{
				err = mk_lib_statistics_x11_on_expose_row(statistics, evt, attr.width, mk_lang_false, i); mk_lang_check_rereturn(err);
			}
		}
	}
	tsi = XFlush(display);
	if(statistics->m_line_height < statistics->m_line_hcur)
	{
		statistics->m_line_height = statistics->m_line_hcur;
		err = mk_lib_statistics_x11_invalidate_all(statistics); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_keypress(mk_lib_statistics_x11_pt const statistics, XEvent* const evt) mk_lang_noexcept
{
	Display* display;
	Window window;
	mk_lang_types_sint_t idxmin;
	mk_lang_types_sint_t idxmax;
	KeySym ks;
	mk_lang_types_sint_t idxold;
	mk_lang_types_sint_t idxnew;
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == KeyPress);

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	idxmin = 0;
	idxmax = mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs) - 1;
	ks = XLookupKeysym(&evt->xkey, 0);
	if(ks == XK_q)
	{
		statistics->m_keep_running = mk_lang_false;
	}
	else if(ks == XK_Escape)
	{
		statistics->m_keep_running = mk_lang_false;
	}
	else if(ks == XK_Up)
	{
		idxold = statistics->m_idx;
		statistics->m_idx = mk_lang_clamp(statistics->m_idx - 1, idxmin, idxmax);
		idxnew = statistics->m_idx;
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxold); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxnew); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_Down)
	{
		idxold = statistics->m_idx;
		statistics->m_idx = mk_lang_clamp(statistics->m_idx + 1, idxmin, idxmax);
		idxnew = statistics->m_idx;
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxold); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxnew); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_Page_Up)
	{
		idxold = statistics->m_idx;
		statistics->m_idx = mk_lang_clamp(statistics->m_idx - 10, idxmin, idxmax);
		idxnew = statistics->m_idx;
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxold); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxnew); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_Page_Down)
	{
		idxold = statistics->m_idx;
		statistics->m_idx = mk_lang_clamp(statistics->m_idx + 10, idxmin, idxmax);
		idxnew = statistics->m_idx;
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxold); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxnew); mk_lang_check_rereturn(err);
	}
	if(ks == XK_Home)
	{
		idxold = statistics->m_idx;
		statistics->m_idx = mk_lang_clamp(statistics->m_idx - 20, idxmin, idxmax);
		idxnew = statistics->m_idx;
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxold); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxnew); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_End)
	{
		idxold = statistics->m_idx;
		statistics->m_idx = mk_lang_clamp(statistics->m_idx + 20, idxmin, idxmax);
		idxnew = statistics->m_idx;
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxold); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxnew); mk_lang_check_rereturn(err);
	}
	err = mk_lib_statistics_invalidate(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_buttonpress(mk_lib_statistics_x11_pt const statistics, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_sint_t x;
	mk_lang_types_sint_t y;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ButtonPress);

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	gc = statistics->m_gc;
	x = evt->xbutton.x;
	y = evt->xbutton.y;
	tsi = XDrawString(display, window, gc, x, y, "test", mk_lang_countstr("test"));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_delete(mk_lib_statistics_x11_pt const statistics, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	((mk_lang_types_void_t)(evt));
	statistics->m_keep_running = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_clientmessage(mk_lib_statistics_x11_pt const statistics, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Atom wmdelete;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	err = mk_lib_x11_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
	if(evt->xclient.data.l[0] == wmdelete){ err = mk_lib_statistics_x11_on_delete(statistics, evt); mk_lang_check_rereturn(err); }
	return 0;
}


static mk_lib_statistics_x11_t g_mk_lib_statistics_x11;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_x11_pt statistics;
	mk_lang_types_sint_t err;
	Display* display;
	mk_lang_types_sint_t screen;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	Window parent;

	statistics = &g_mk_lib_statistics_x11;
	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	screen = DefaultScreen(display);
	black = BlackPixel(display, screen);
	white = WhitePixel(display, screen);
	parent = RootWindow(display, screen);
	statistics->m_keep_running = mk_lang_true;
	statistics->m_closed = mk_lang_false;
	statistics->m_screen = screen;
	statistics->m_black = black;
	statistics->m_white = white;
	statistics->m_parent = parent;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_x11_pt statistics;

	statistics = &g_mk_lib_statistics_x11;
	((mk_lang_types_void_t)(statistics));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_display(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_x11_pt statistics;
	mk_sl_cui_uint128_t zero;
	mk_lang_types_sint_t err;
	Display* display;
	Window parent;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	Window window;
	mk_lang_types_sint_t tsi;
	Atom wmdelete;
	GC gc;

	statistics = &g_mk_lib_statistics_x11;
	mk_sl_cui_uint128_set_zero(&zero);
	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	err = mk_lib_x11_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
	parent = statistics->m_parent;
	black = statistics->m_black;
	white = statistics->m_white;
	window = XCreateSimpleWindow(display, parent, 0, 0, 250, 220, 5, black, white);
	tsi = XSetStandardProperties(display, window, "statistics", mk_lang_null, None, mk_lang_null, 0, mk_lang_null);
	tsi = XSetWMProtocols(display, window, &wmdelete, 1);
	tsi = XSelectInput(display, window, ExposureMask | ButtonPressMask | KeyPressMask);
	gc = XCreateGC(display, window, 0, 0);
	tsi = XSetBackground(display, gc, white);
	tsi = XSetForeground(display ,gc , black);
	tsi = XClearWindow(display, window);
	tsi = XMapRaised(display, window);
	statistics->m_window = window;
	statistics->m_gc = gc;
	statistics->m_idx = 0;
	statistics->m_line_height = 0;
	statistics->m_line_hcur = 0;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[0] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[1] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[2] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[3] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[4] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[5] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[6] = zero;
	statistics->m_cntrs_last.m_data.m_arry.m_cntrs[7] = zero;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_close(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_x11_pt statistics;
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_sint_t tsi;

	statistics = &g_mk_lib_statistics_x11;
	if(!statistics->m_closed)
	{
		statistics->m_closed = mk_lang_true;
		err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
		window = statistics->m_window;
		gc = statistics->m_gc;
		tsi = XFreeGC(display, gc);
		tsi = XDestroyWindow(display, window);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_invalidate(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_x11_pt statistics;
	mk_lang_types_sint_t err;
	mk_lib_statistics_x11_cntrs_t cntrs;
	Display* display;
	Window window;
	Status st;
	XWindowAttributes attr;
	XEvent e;

	statistics = &g_mk_lib_statistics_x11;
	if(!statistics->m_closed)
	{
		err = mk_lib_statistics_x11_mallocatorg_statistics_get_all(&cntrs.m_data.m_arry.m_cntrs[0]); mk_lang_check_rereturn(err);
		if(!mk_lib_statistics_x11_cntrs_ro_eq(&cntrs, &statistics->m_cntrs_last))
		{
			statistics->m_cntrs_last = cntrs;
			err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
			window = statistics->m_window;
			st = XGetWindowAttributes(display, window, &attr);
			e.type = Expose;
			e.xexpose.type = Expose;
			e.xexpose.serial = 0;
			e.xexpose.send_event = True;
			e.xexpose.display = display;
			e.xexpose.window = window;
			e.xexpose.x = 0;
			e.xexpose.y = 0;
			e.xexpose.width = attr.width;
			e.xexpose.height = attr.height;
			e.xexpose.count = 0;
			st = XSendEvent(display, window, False, ExposureMask, &e);
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_pump(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_statistics_x11_pt statistics;
	Display* display;
	Window window;
	mk_lang_types_slong_t mask;
	XEvent* evt;
	XEvent e;
	Bool b;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;

	statistics = &g_mk_lib_statistics_x11;
	if(statistics->m_keep_running && !statistics->m_closed)
	{
		err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
		window = statistics->m_window;
		mask = ExposureMask | ButtonPressMask | KeyPressMask;
		evt = &e;
		for(;;)
		{
			gud = (b = XCheckWindowEvent(display, window, mask, evt)) == True;
			if(!gud)
			{
				break;
			}
			switch(evt->type)
			{
				case Expose       : err = mk_lib_statistics_x11_on_expose       (statistics, evt); mk_lang_check_rereturn(err); break;
				case KeyPress     : err = mk_lib_statistics_x11_on_keypress     (statistics, evt); mk_lang_check_rereturn(err); break;
				case ButtonPress  : err = mk_lib_statistics_x11_on_buttonpress  (statistics, evt); mk_lang_check_rereturn(err); break;
				case ClientMessage: err = mk_lib_statistics_x11_on_clientmessage(statistics, evt); mk_lang_check_rereturn(err); break;
			}
		}
		if(!statistics->m_keep_running)
		{
			err = mk_lib_statistics_x11_close(); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}


#endif
