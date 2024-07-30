#include "src/mk_lang_assert.h"
#include "src/mk_lang_bool.h"
#include "src/mk_lang_check.h"
#include "src/mk_lang_clamp.h"
#include "src/mk_lang_countof.h"
#include "src/mk_lang_div_roundup.h"
#include "src/mk_lang_inline.h"
#include "src/mk_lang_limits.h"
#include "src/mk_lang_max.h"
#include "src/mk_lang_min.h"
#include "src/mk_lang_nodiscard.h"
#include "src/mk_lang_noexcept.h"
#include "src/mk_lang_null.h"
#include "src/mk_lang_strlen.h"
#include "src/mk_lang_types.h"
#include "src/mk_lib_fe_x11.h"
#include "src/mk_lib_statistics.h"
#include "src/mk_lib_x11_cong.h"
#include "src/mk_lib_x11_list_view.h"
#include "src/mk_sl_mallocatorg.h"

#define mk_sl_vector_t_name mkfe_string
#define mk_sl_vector_t_element mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "src/mk_sl_vector_inl_fileh.h"
#include "src/mk_sl_vector_inl_filec.h"

#define mk_sl_vector_t_name mkfe_strings
#define mk_sl_vector_t_element mkfe_string_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "src/mk_sl_vector_inl_fileh.h"
#include "src/mk_sl_vector_inl_filec.h"

#define mk_lang_memcpy_t_name mkfe_memcpy_pc
#define mk_lang_memcpy_t_type mk_lang_types_pchar_t
#include "src/mk_lang_memcpy_inl_fileh.h"
#include "src/mk_lang_memcpy_inl_filec.h"

struct mkfe_file_s
{
	mkfe_string_t m_name;
	mk_lang_types_bool_t m_is_dir;
};
typedef struct mkfe_file_s mkfe_file_t;
typedef mkfe_file_t const mkfe_file_ct;
typedef mkfe_file_t* mkfe_file_pt;
typedef mkfe_file_t const* mkfe_file_pct;

#define mk_sl_vector_t_name mkfe_files
#define mk_sl_vector_t_element mkfe_file_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "src/mk_sl_vector_inl_fileh.h"
#include "src/mk_sl_vector_inl_filec.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mkfe_file_lt(mkfe_file_pct const a, mkfe_file_pct const b)
{
	mk_lang_types_bool_t ret;
	mk_lang_types_pchar_pct texta;
	mk_lang_types_pchar_pct textb;
	mk_lang_types_usize_t lena;
	mk_lang_types_usize_t lenb;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t cmpa;
	mk_lang_types_sint_t cmpb;

	mk_lang_assert(a);
	mk_lang_assert(b);

	if(a->m_is_dir && !b->m_is_dir)
	{
		ret = mk_lang_true;
	}
	else if(b->m_is_dir && !a->m_is_dir)
	{
		ret = mk_lang_false;
	}
	else
	{
		cmpb = 0;
		texta = mkfe_string_ro_data(&a->m_name); mk_lang_assert(texta && texta[0] != '\0');
		textb = mkfe_string_ro_data(&b->m_name); mk_lang_assert(textb && textb[0] != '\0');
		lena = mkfe_string_ro_size(&a->m_name); mk_lang_assert(lena >= 1);
		lenb = mkfe_string_ro_size(&b->m_name); mk_lang_assert(lenb >= 1);
		n = mk_lang_min(lena, lenb);
		for(i = 0; i != n; ++i)
		{
			if
			(
				((texta[i] >= 'a' && texta[i] <= 'z') || (texta[i] >= 'A' && texta[i] <= 'Z')) &&
				((textb[i] >= 'a' && textb[i] <= 'z') || (textb[i] >= 'A' && textb[i] <= 'Z'))
			)
			{
				cmpa =
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(texta[i])) | ((mk_lang_types_ushort_t)(1u << 5)))))) -
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(textb[i])) | ((mk_lang_types_ushort_t)(1u << 5))))));
				if(cmpb == 0)
				{
					cmpb =
						((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(texta[i])))) -
						((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(textb[i]))));
				}
			}
			else
			{
				cmpa =
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(texta[i])))) -
					((mk_lang_types_sint_t)(((mk_lang_types_ushort_t)(textb[i]))));
			}
			if(cmpa != 0)
			{
				ret = cmpa < 0;
				break;
			}
		}
		if(i == n)
		{
			if(cmpb != 0)
			{
				ret = cmpb < 0;
			}
			else
			{
				ret = lena <= lenb;
			}
		}
	}
	return ret;
}

#define mk_lang_bui_t_name mkfe_cntr
#define mk_lang_bui_t_base uint
#include "src/mk_lang_bui_inl_fileh.h"
#include "src/mk_lang_bui_inl_filec.h"

#define mk_sl_sort_merge_t_name mkfe_sort_files
#define mk_sl_sort_merge_t_data mkfe_file
#define mk_sl_sort_merge_t_counter mkfe_cntr
#define mk_sl_sort_merge_t_is_sorted mkfe_file_lt
#define mk_sl_sort_merge_t_first_round 1
#define mk_sl_sort_merge_t_proxy mk_lang_types_sint
#include "src/mk_sl_sort_merge_inl_fileh.h"
#include "src/mk_sl_sort_merge_inl_filec.h"

#define mk_sl_vector_t_name mkfe_ints
#define mk_sl_vector_t_element mk_lang_types_sint_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "src/mk_sl_vector_inl_fileh.h"
#include "src/mk_sl_vector_inl_filec.h"

#define mk_lang_swap_t_name mkfe_swap_ul
#define mk_lang_swap_t_type mk_lang_types_ulong_t
#include "src/mk_lang_swap_inl_fileh.h"
#include "src/mk_lang_swap_inl_filec.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


struct mkfe_s
{
	int x;
};
typedef struct mkfe_s mkfe_t;
typedef mkfe_t const mkfe_ct;
typedef mkfe_t* mkfe_pt;
typedef mkfe_t const* mkfe_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_init(mkfe_pt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);

	((mk_lang_types_void_t)(fe));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_deinit(mkfe_pt const fe) mk_lang_noexcept
{
	mk_lang_assert(fe);

	((mk_lang_types_void_t)(fe));
	return 0;
}

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_keypress(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	Display* display;
	Window window;
	mk_lang_types_sint_t err;
	KeySym ks;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t old;
	mk_lang_types_sint_t neu;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t rows;
	mk_lang_types_usize_t tus;
	XWindowAttributes attr;
	Status st;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == KeyPress);

	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	text_asc = fe->m_text_asc;
	text_des = fe->m_text_des;
	line_height = text_asc + text_des;
	tus = mkfe_files_ro_size(&fe->m_rows); mk_lang_assert(tus <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))); n = ((mk_lang_types_sint_t)(tus));
	ks = XLookupKeysym(&evt->xkey, 0);
	if(ks == XK_q)
	{
		fe->m_visible = mk_lang_false;
	}
	else if(ks == XK_Escape)
	{
		fe->m_visible = mk_lang_false;
	}
	else if(ks == XK_Return)
	{
		err = mkfe_x_go_deep(fe); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_BackSpace)
	{
		err = mkfe_x_go_up(fe); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_i)
	{
		#if mk_clib_app_fe_posix_mallocatorg_statistics_have
		err = mk_lib_statistics_hide(); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_show(); mk_lang_check_rereturn(err);
		#endif
	}
	else if(ks == XK_d)
	{
		mkfe_swap_ul_fn(&fe->m_black, &fe->m_white);
		err = mkfe_x_invalidate_all(fe); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_Up)
	{
		old = fe->m_idx;
		fe->m_idx = mk_lang_max(0, fe->m_idx - 1);
		neu = fe->m_idx;
		err = mkfe_x_invalidate_one(fe, old); mk_lang_check_rereturn(err);
		err = mkfe_x_invalidate_one(fe, neu); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_Down)
	{
		old = fe->m_idx;
		fe->m_idx = mk_lang_min(n - 1, fe->m_idx + 1);
		neu = fe->m_idx;
		err = mkfe_x_invalidate_one(fe, old); mk_lang_check_rereturn(err);
		err = mkfe_x_invalidate_one(fe, neu); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_Page_Up)
	{
		st = XGetWindowAttributes(display, window, &attr);
		rows = attr.height / line_height;
		old = fe->m_idx;
		fe->m_idx = mk_lang_max(0, fe->m_idx - rows);
		neu = fe->m_idx;
		err = mkfe_x_invalidate_one(fe, old); mk_lang_check_rereturn(err);
		err = mkfe_x_invalidate_one(fe, neu); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_Page_Down)
	{
		st = XGetWindowAttributes(display, window, &attr);
		rows = attr.height / line_height;
		old = fe->m_idx;
		fe->m_idx = mk_lang_min(n - 1, fe->m_idx + rows);
		neu = fe->m_idx;
		err = mkfe_x_invalidate_one(fe, old); mk_lang_check_rereturn(err);
		err = mkfe_x_invalidate_one(fe, neu); mk_lang_check_rereturn(err);
	}
	if(ks == XK_Home)
	{
		old = fe->m_idx;
		fe->m_idx = 0;
		neu = fe->m_idx;
		err = mkfe_x_invalidate_one(fe, old); mk_lang_check_rereturn(err);
		err = mkfe_x_invalidate_one(fe, neu); mk_lang_check_rereturn(err);
	}
	else if(ks == XK_End)
	{
		old = fe->m_idx;
		fe->m_idx = n - 1;
		neu = fe->m_idx;
		err = mkfe_x_invalidate_one(fe, old); mk_lang_check_rereturn(err);
		err = mkfe_x_invalidate_one(fe, neu); mk_lang_check_rereturn(err);
	}
	#if mk_clib_app_fe_posix_mallocatorg_statistics_have
	err = mk_lib_statistics_invalidate(); mk_lang_check_rereturn(err);
	#endif
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_buttonpress(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	mk_lang_types_sint_t y;
	mk_lang_types_sint_t idxold;
	mk_lang_types_sint_t idxnew;
	mk_lang_types_usize_t rowsus;
	mk_lang_types_sint_t rowssi;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t line_height;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ButtonPress);

	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	text_asc = fe->m_text_asc;
	text_des = fe->m_text_des;
	line_height = text_asc + text_des;
	y = evt->xbutton.y;
	idxold = fe->m_idx;
	idxnew = y / line_height;
	rowsus = mkfe_files_ro_size(&fe->m_rows); mk_lang_assert(rowsus <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))); rowssi = ((mk_lang_types_sint_t)(rowsus));
	if(idxnew >= 0 && idxnew < rowssi && idxnew != idxold)
	{
		fe->m_idx = idxnew;
		err = mkfe_x_invalidate_one(fe, idxold); mk_lang_check_rereturn(err);
		err = mkfe_x_invalidate_one(fe, idxnew); mk_lang_check_rereturn(err);
	}
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_delete(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	((mk_lang_types_void_t)(evt));
	fe->m_visible = mk_lang_false;
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_clientmessage(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Atom wmdelete;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	err = mk_lib_x11_cong_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
	if(((Atom)(evt->xclient.data.l[0])) == wmdelete){ err = mkfe_x_on_delete(fe, evt); mk_lang_check_rereturn(err); }
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_pump_all_window_specific(mkfe_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	Display* display;
	Window window;
	mk_lang_types_slong_t mask;
	XEvent* evt;
	XEvent e;
	mk_lang_types_bool_t consumed;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(at_least_one);

	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	mask = ExposureMask | ButtonPressMask | KeyPressMask;
	evt = &e;
	while(XCheckWindowEvent(display, window, mask, evt) == True)
	{
		*at_least_one = mk_lang_true;
		switch(evt->type)
		{
			case Expose       : err = mkfe_x_on_expose       (fe, evt); mk_lang_check_rereturn(err); break;
			case KeyPress     : err = mkfe_x_on_keypress     (fe, evt); mk_lang_check_rereturn(err); break;
			case ButtonPress  : err = mkfe_x_on_buttonpress  (fe, evt); mk_lang_check_rereturn(err); break;
			case ClientMessage: err = mkfe_x_on_clientmessage(fe, evt); mk_lang_check_rereturn(err); break;
		}
	}
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_pump_global(mkfe_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	Display* display;
	Window window;
	XEvent* evt;
	XEvent e;
	mk_lang_types_bool_t consumed;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(at_least_one);

	if(!fe->m_visible)
	{
		err = mkfe_x_hide(fe); mk_lang_check_rereturn(err);
	}
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	evt = &e;
	consumed = mk_lang_true;
	while(fe->m_visible && consumed)
	{
		consumed = mk_lang_false;
		tsi = XPeekEvent(display, evt);
		if(evt->type == ClientMessage)
		{
			if(evt->xclient.window == window)
			{
				consumed = mk_lang_true;
				*at_least_one = mk_lang_true;
				tsi = XNextEvent(display, evt);
				mk_lang_assert(evt->type == ClientMessage);
				mk_lang_assert(evt->xclient.window == window);
				err = mkfe_x_on_clientmessage(fe, evt); mk_lang_check_rereturn(err);
			}
		}
	}
	if(!fe->m_visible)
	{
		err = mkfe_x_hide(fe); mk_lang_check_rereturn(err);
	}
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_pump(mkfe_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	mk_lang_types_bool_t consumed;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(at_least_one);

	consumed = mk_lang_true;
	while(consumed)
	{
		consumed = mk_lang_false;
		err = mkfe_x_pump_all_window_specific(fe, &consumed); mk_lang_check_rereturn(err);
		err = mkfe_x_pump_global(fe, &consumed); mk_lang_check_rereturn(err);
		if(consumed)
		{
			*at_least_one = mk_lang_true;
		}
	}
	return 0;
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_run_(mkfe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	XEvent* evt;
	XEvent e;
	mk_lang_types_bool_t consumed;
	mk_lang_types_bool_t gudb;
	mk_lang_types_sint_t tsi;

	err = mkfe_x_gather_root(fe); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	evt = &e;
	consumed = mk_lang_true;
	while(fe->m_visible)
	{
		gudb = consumed;
		consumed = mk_lang_false;
		err = mkfe_x_pump(fe, &consumed); mk_lang_check_rereturn(err);
		#if mk_clib_app_fe_posix_mallocatorg_statistics_have
		if(fe->m_visible){ err = mk_lib_statistics_x11_pump(&consumed); mk_lang_check_rereturn(err); }
		#endif
		if(!consumed && !gudb)
		{
			tsi = XNextEvent(display, evt);
			consumed = mk_lang_true;
		}
	}
	return 0;
}*/

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_run(mkfe_pt const fe) mk_lang_noexcept
{
	XEvent* evt;
	XEvent e;
	mk_lang_types_sint_t err;
	Display* display;
	mk_lang_types_bool_t is_hidden;
	mk_lang_types_sint_t tsi;
	mk_lang_types_bool_t consumed;

	evt = &e;
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	err = mk_lib_fe_x11_show(); mk_lang_check_rereturn(err);
	for(;;)
	{
		err = mk_lib_fe_x11_is_hidden(&is_hidden); mk_lang_check_rereturn(err);
		if(is_hidden)
		{
			break;
		}
		tsi = XNextEvent(display, evt);
		err = mk_lib_fe_x11_on_event(evt, &consumed); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_on_event(evt, &consumed); mk_lang_check_rereturn(err);
		err = mk_lib_statistics_invalidate(); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_types_sint_t main(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mkfe_t fe;

	err = mk_sl_mallocatorg_init(); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_init(); mk_lang_check_rereturn(err);
	err = mk_lib_fe_x11_init(); mk_lang_check_rereturn(err);
	err = mk_lib_statistics_init(); mk_lang_check_rereturn(err);
	err = mkfe_x_init(&fe); mk_lang_check_rereturn(err);
	err = mkfe_x_run(&fe); mk_lang_check_rereturn(err);
	err = mkfe_x_deinit(&fe); mk_lang_check_rereturn(err);
	err = mk_lib_statistics_hide(); mk_lang_check_rereturn(err);
	err = mk_lib_statistics_deinit(); mk_lang_check_rereturn(err);
	err = mk_lib_fe_x11_hide(); mk_lang_check_rereturn(err);
	err = mk_lib_fe_x11_deinit(); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_deinit(); mk_lang_check_rereturn(err);
	err = mk_sl_mallocatorg_deinit(); mk_lang_check_rereturn(err);
	return 0;
}
