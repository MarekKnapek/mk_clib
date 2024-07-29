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
#include "mk_sl_uint128.h"

#define mk_lang_memcpy_t_name mk_lib_statistics_x11_memcpy_pc
#define mk_lang_memcpy_t_type mk_lang_types_pchar_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lang_swap_t_name mk_lib_statistics_x11_swap_ul
#define mk_lang_swap_t_type mk_lang_types_ulong_t
#include "mk_lang_swap_inl_fileh.h"
#include "mk_lang_swap_inl_filec.h"


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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_expose(mk_lib_statistics_x11_pt const statistics, XEvent* const evt) mk_lang_noexcept
{
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
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_keypress(mk_lib_statistics_x11_pt const statistics, XEvent* const evt) mk_lang_noexcept
{
	KeySym ks;
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == KeyPress);

	ks = XLookupKeysym(&evt->xkey, 0);
	switch(ks)
	{
		case XK_q:
		{
			statistics->m_visible = mk_lang_false;
		}
		break;
		case XK_Escape:
		{
			statistics->m_visible = mk_lang_false;
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
		}
		break;
	}
	return 0;
}

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_buttonpress(mk_lib_statistics_x11_pt const statistics, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	mk_lang_types_sint_t y;
	mk_lang_types_sint_t idxold;
	mk_lang_types_sint_t idxnew;
	mk_lang_types_usize_t rowsus;
	mk_lang_types_sint_t rowssi;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ButtonPress);

	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = statistics->m_window;
	y = evt->xbutton.y;
	idxold = statistics->m_idx;
	idxnew = y / statistics->m_line_height;
	rowssi = mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs);
	if(idxnew >= 0 && idxnew < rowssi && idxnew != idxold)
	{
		statistics->m_idx = idxnew;
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxold); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_x11_invalidate_one(statistics, idxnew); mk_lang_check_rereturn(err);
	}
	return 0;
}*/

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_delete(mk_lib_statistics_x11_pt const statistics, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	((mk_lang_types_void_t)(evt));
	statistics->m_visible = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_clientmessage(mk_lib_statistics_x11_pt const statistics, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Atom wmdelete;

	mk_lang_assert(statistics);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	err = mk_lib_x11_cong_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
	if(((Atom)(evt->xclient.data.l[0])) == wmdelete){ err = mk_lib_statistics_x11_on_delete(statistics, evt); mk_lang_check_rereturn(err); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_pump_all_window_specific(mk_lib_statistics_x11_pt const statistics, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
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
	mask = ExposureMask | ButtonPressMask | KeyPressMask;
	evt = &e;
	while(statistics->m_visible && XCheckWindowEvent(display, window, mask, evt) == True)
	{
		*at_least_one = mk_lang_true;
		switch(evt->type)
		{
			case Expose       : err = mk_lib_statistics_x11_on_expose       (statistics, evt); mk_lang_check_rereturn(err); break;
			case KeyPress     : err = mk_lib_statistics_x11_on_keypress     (statistics, evt); mk_lang_check_rereturn(err); break;
			/*case ButtonPress  : err = mk_lib_statistics_x11_on_buttonpress  (statistics, evt); mk_lang_check_rereturn(err); break;*/
			case ClientMessage: err = mk_lib_statistics_x11_on_clientmessage(statistics, evt); mk_lang_check_rereturn(err); break;
		}
		err = mk_lib_x11_list_view_rw_on_event(list_view, evt, &consumed); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_pump_global(mk_lib_statistics_x11_pt const statistics, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
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
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_on_row(mk_lib_x11_list_view_callctx_t const context, mk_lang_types_sint_t const idx, mk_lang_types_pchar_ppct const text, mk_lang_types_sint_pt const len) mk_lang_noexcept
{
	mk_lib_statistics_x11_pt statistics;
	mk_sl_cui_uint128_pct cntr;
	mk_lang_types_sint_t lensi;
	mk_lang_types_pchar_t str[mk_sl_cui_uint128_strlendec_v];
	mk_lang_types_usize_t lenus;

	mk_lang_assert(context);
	mk_lang_assert(idx >= 0 && idx < mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs));
	mk_lang_assert(text);
	mk_lang_assert(len);

	statistics = ((mk_lib_statistics_x11_pt)(context));
	cntr = &statistics->m_cntrs_last.m_data.m_arry.m_cntrs[idx];
	lensi = mk_sl_cui_uint128_to_str_dec_n(cntr, &str[0], mk_lang_countof(str)); mk_lang_assert(lensi >= 1 && lensi <= mk_lang_countof(str));
	lenus = mk_lang_strlen_n_fn(mk_lib_statistics_x11_labels[idx]); mk_lang_assert(lenus <= mk_lang_countof(statistics->m_tmp_str) - mk_lang_countof(str) - 1);
	mk_lib_statistics_x11_memcpy_pc_fn(&statistics->m_tmp_str[0], &mk_lib_statistics_x11_labels[idx][0], lenus);
	statistics->m_tmp_str[lenus] = ' ';
	mk_lib_statistics_x11_memcpy_pc_fn(&statistics->m_tmp_str[lenus + 1], &str[0], lensi);
	*text = &statistics->m_tmp_str[0];
	*len = ((mk_lang_types_sint_t)(lenus)) + 1 + lensi;
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
	GC gc;
	mk_lang_types_sint_t tsi;
	GContext gcid;
	mk_lang_types_sint_t direction;
	mk_lang_types_sint_t ascent;
	mk_lang_types_sint_t descent;
	XCharStruct text_dimensions;
	mk_lang_types_sint_t rect[4];

	mk_lang_assert(statistics);

	mk_sl_cui_uint128_set_zero(&zero);
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
	screen = DefaultScreen(display);
	err = mk_lib_x11_cong_get_default_screen_black(&black); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_default_screen_white(&white); mk_lang_check_rereturn(err);
	parent = RootWindow(display, screen);
	window = XCreateSimpleWindow(display, parent, 0, 0, 220, 100, 0, black, white);
	tsi = XSelectInput(display, window, ExposureMask | ButtonPressMask | KeyPressMask);
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
	err = mk_lib_x11_list_view_rw_set_callback(&statistics->m_list_view, &mk_lib_statistics_x11_on_row, statistics); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_rows(&statistics->m_list_view, mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs)); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_auto_height(&statistics->m_list_view, mk_lang_countof(statistics->m_cntrs_last.m_data.m_arry.m_cntrs)); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_dimensions(&statistics->m_list_view, 0, 0, 220, 100); mk_lang_check_rereturn(err);
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
	err = mk_lib_statistics_x11_mallocatorg_statistics_get_all(&cntrs.m_data.m_arry.m_cntrs[0]); mk_lang_check_rereturn(err);
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_statistics_x11_pump_(mk_lib_statistics_x11_pt const statistics, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;

	mk_lang_assert(statistics);
	mk_lang_assert(at_least_one);

	gud = mk_lang_true;
	while(gud)
	{
		gud = mk_lang_false;
		err = mk_lib_statistics_x11_pump_all_window_specific(statistics, &gud); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_x11_pump_global             (statistics, &gud); mk_lang_check_rereturn(err);
		if(gud)
		{
			*at_least_one = mk_lang_true;
		}
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_x11_pump(mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	return mk_lib_statistics_x11_pump_(&g_mk_lib_statistics_x11, at_least_one);
}
