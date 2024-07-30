#include "mk_lib_fe_x11.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clamp.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_strlen.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_x11_cong.h"
#include "mk_lib_x11_headers.h"
#include "mk_lib_x11_list_view.h"

#define mk_lib_fe_x11_mallocatorg_id_disp        11
#define mk_lib_fe_x11_mallocatorg_id_portablec   12
#define mk_lib_fe_x11_mallocatorg_id_portablecpp 13
#define mk_lib_fe_x11_mallocatorg_id_windows     14
#define mk_lib_fe_x11_mallocatorg_id_tracer      15
#if defined mk_lib_fe_x11_mallocatorg_want && (mk_lib_fe_x11_mallocatorg_want) == mk_lib_fe_x11_mallocatorg_id_disp
#define mk_lib_fe_x11_mallocatorg_id mk_lib_fe_x11_mallocatorg_id_disp
#elif defined mk_lib_fe_x11_mallocatorg_want && (mk_lib_fe_x11_mallocatorg_want) == mk_lib_fe_x11_mallocatorg_id_portablec
#define mk_lib_fe_x11_mallocatorg_id mk_lib_fe_x11_mallocatorg_id_portablec
#elif defined mk_lib_fe_x11_mallocatorg_want && (mk_lib_fe_x11_mallocatorg_want) == mk_lib_fe_x11_mallocatorg_id_portablecpp
#define mk_lib_fe_x11_mallocatorg_id mk_lib_fe_x11_mallocatorg_id_portablecpp
#elif defined mk_lib_fe_x11_mallocatorg_want && (mk_lib_fe_x11_mallocatorg_want) == mk_lib_fe_x11_mallocatorg_id_windows
#define mk_lib_fe_x11_mallocatorg_id mk_lib_fe_x11_mallocatorg_id_windows
#elif defined mk_lib_fe_x11_mallocatorg_want && (mk_lib_fe_x11_mallocatorg_want) == mk_lib_fe_x11_mallocatorg_id_tracer
#define mk_lib_fe_x11_mallocatorg_id mk_lib_fe_x11_mallocatorg_id_tracer
#elif !defined mk_lib_fe_x11_mallocatorg_want
#if defined NDEBUG
#define mk_lib_fe_x11_mallocatorg_id mk_lib_fe_x11_mallocatorg_id_disp
#else
#define mk_lib_fe_x11_mallocatorg_id mk_lib_fe_x11_mallocatorg_id_tracer
#endif
#else
#error xxxxxxxxxx
#endif
#if mk_lib_fe_x11_mallocatorg_id == mk_lib_fe_x11_mallocatorg_id_disp
#include "mk_sl_mallocatorg.h"
#define mk_lib_fe_x11_mallocatorg_name mk_sl_mallocatorg
#elif mk_lib_fe_x11_mallocatorg_id == mk_lib_fe_x11_mallocatorg_id_portablec
#include "mk_sl_mallocatorg_portablec.h"
#define mk_lib_fe_x11_mallocatorg_name mk_sl_mallocatorg_portablec
#elif mk_lib_fe_x11_mallocatorg_id == mk_lib_fe_x11_mallocatorg_id_portablecpp
#include "mk_sl_mallocatorg_portablecpp.hpp"
#define mk_lib_fe_x11_mallocatorg_name mk_sl_mallocatorg_portablecpp
#elif mk_lib_fe_x11_mallocatorg_id == mk_lib_fe_x11_mallocatorg_id_windows
#include "mk_sl_mallocatorg_windows.h"
#define mk_lib_fe_x11_mallocatorg_name mk_sl_mallocatorg_windows
#elif mk_lib_fe_x11_mallocatorg_id == mk_lib_fe_x11_mallocatorg_id_tracer
#include "mk_sl_mallocg_tracer.h"
#define mk_lib_fe_x11_mallocatorg_name mk_sl_mallocg_tracer
#else
#error xxxxxxxxxx
#endif
#define mk_lib_fe_x11_mallocatorg_init                      mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _init)
#define mk_lib_fe_x11_mallocatorg_deinit                    mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _deinit)
#define mk_lib_fe_x11_mallocatorg_allocate                  mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _allocate)
#define mk_lib_fe_x11_mallocatorg_deallocate                mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _deallocate)
#define mk_lib_fe_x11_mallocatorg_reallocate                mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _reallocate)
#define mk_lib_fe_x11_mallocatorg_fe_get_bytes_allocated    mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _fe_get_bytes_allocated)
#define mk_lib_fe_x11_mallocatorg_fe_get_bytes_deallocated  mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _fe_get_bytes_deallocated)
#define mk_lib_fe_x11_mallocatorg_fe_get_bytes_live         mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _fe_get_bytes_live)
#define mk_lib_fe_x11_mallocatorg_fe_get_bytes_peak         mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _fe_get_bytes_peak)
#define mk_lib_fe_x11_mallocatorg_fe_get_blocks_allocated   mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _fe_get_blocks_allocated)
#define mk_lib_fe_x11_mallocatorg_fe_get_blocks_deallocated mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _fe_get_blocks_deallocated)
#define mk_lib_fe_x11_mallocatorg_fe_get_blocks_live        mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _fe_get_blocks_live)
#define mk_lib_fe_x11_mallocatorg_fe_get_blocks_peak        mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _fe_get_blocks_peak)
#define mk_lib_fe_x11_mallocatorg_fe_get_all                mk_lang_concat(mk_lib_fe_x11_mallocatorg_name, _fe_get_all)

#define mk_lang_memcpy_t_name mk_lib_fe_x11_memcpy_pc
#define mk_lang_memcpy_t_type mk_lang_types_pchar_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_lang_memset_t_name mk_lib_fe_x11_memset_pc
#define mk_lang_memset_t_type mk_lang_types_pchar_t
#include "mk_lang_memset_inl_fileh.h"
#include "mk_lang_memset_inl_filec.h"

#define mk_lang_swap_t_name mk_lib_fe_x11_swap_ul
#define mk_lang_swap_t_type mk_lang_types_ulong_t
#include "mk_lang_swap_inl_fileh.h"
#include "mk_lang_swap_inl_filec.h"

#define mk_sl_vector_t_name mk_lib_fe_x11_string
#define mk_sl_vector_t_element mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorg mk_lib_fe_x11_mallocatorg_name
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

#define mk_sl_vector_t_name mk_lib_fe_x11_strings
#define mk_sl_vector_t_element mk_lib_fe_x11_string_t
#define mk_sl_vector_t_mallocatorg mk_lib_fe_x11_mallocatorg_name
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

struct mk_lib_fe_x11_file_s
{
	mk_lib_fe_x11_string_t m_name;
	mk_lang_types_bool_t m_is_dir;
};
typedef struct mk_lib_fe_x11_file_s mk_lib_fe_x11_file_t;
typedef mk_lib_fe_x11_file_t const mk_lib_fe_x11_file_ct;
typedef mk_lib_fe_x11_file_t* mk_lib_fe_x11_file_pt;
typedef mk_lib_fe_x11_file_t const* mk_lib_fe_x11_file_pct;

#define mk_sl_vector_t_name mk_lib_fe_x11_files
#define mk_sl_vector_t_element mk_lib_fe_x11_file_t
#define mk_sl_vector_t_mallocatorg mk_lib_fe_x11_mallocatorg_name
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_fe_x11_file_lt(mk_lib_fe_x11_file_pct const a, mk_lib_fe_x11_file_pct const b) mk_lang_noexcept
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
		texta = mk_lib_fe_x11_string_ro_data(&a->m_name); mk_lang_assert(texta && texta[0] != '\0');
		textb = mk_lib_fe_x11_string_ro_data(&b->m_name); mk_lang_assert(textb && textb[0] != '\0');
		lena = mk_lib_fe_x11_string_ro_size(&a->m_name); mk_lang_assert(lena >= 1);
		lenb = mk_lib_fe_x11_string_ro_size(&b->m_name); mk_lang_assert(lenb >= 1);
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
					((mk_lang_types_sint_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(texta[i])) | ((mk_lang_types_uchar_t)(1u << 5)))))) -
					((mk_lang_types_sint_t)(((mk_lang_types_uchar_t)(((mk_lang_types_uchar_t)(textb[i])) | ((mk_lang_types_uchar_t)(1u << 5))))));
				if(cmpb == 0)
				{
					cmpb =
						((mk_lang_types_sint_t)(((mk_lang_types_uchar_t)(texta[i])))) -
						((mk_lang_types_sint_t)(((mk_lang_types_uchar_t)(textb[i]))));
				}
			}
			else
			{
				cmpa =
					((mk_lang_types_sint_t)(((mk_lang_types_uchar_t)(texta[i])))) -
					((mk_lang_types_sint_t)(((mk_lang_types_uchar_t)(textb[i]))));
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

#define mk_lang_bui_t_name mk_lib_fe_x11_cntr
#define mk_lang_bui_t_base uint
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_sort_merge_t_name mk_lib_fe_x11_sort_files
#define mk_sl_sort_merge_t_data mk_lib_fe_x11_file
#define mk_sl_sort_merge_t_counter mk_lib_fe_x11_cntr
#define mk_sl_sort_merge_t_is_sorted mk_lib_fe_x11_file_lt
#define mk_sl_sort_merge_t_first_round 1
#define mk_sl_sort_merge_t_proxy mk_lang_types_sint
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"

#define mk_sl_vector_t_name mk_lib_fe_x11_ints
#define mk_sl_vector_t_element mk_lang_types_sint_t
#define mk_sl_vector_t_mallocatorg mk_lib_fe_x11_mallocatorg_name
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"


struct mk_lib_fe_x11_s
{
	mk_lang_types_bool_t m_visible;
	mk_lang_types_bool_t m_hidden;
	Window m_window;
	GC m_gc;
	mk_lib_fe_x11_string_t m_path;
	mk_lib_fe_x11_files_t m_rows;
	mk_lib_x11_list_view_t m_list_view;
};
typedef struct mk_lib_fe_x11_s mk_lib_fe_x11_t;
typedef mk_lib_fe_x11_t const mk_lib_fe_x11_ct;
typedef mk_lib_fe_x11_t* mk_lib_fe_x11_pt;
typedef mk_lib_fe_x11_t const* mk_lib_fe_x11_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prro_on_row(mk_lib_x11_list_view_callctx_t const context, mk_lang_types_sint_t const idx, mk_lang_types_pchar_ppct const text, mk_lang_types_sint_pt const len) mk_lang_noexcept
{
	mk_lib_fe_x11_pct fe;
	mk_lib_fe_x11_files_pct rows;
	mk_lib_fe_x11_file_pct row;
	mk_lib_fe_x11_string_pct name;
	mk_lang_types_pchar_pct text_buf;
	mk_lang_types_sint_t text_len;

	mk_lang_assert(context);
	mk_lang_assert(idx >= 0 && idx < ((mk_lang_types_sint_t)(mk_lib_fe_x11_files_ro_size(&((mk_lib_fe_x11_pct)(context))->m_rows))));
	mk_lang_assert(text);
	mk_lang_assert(len);

	fe = ((mk_lib_fe_x11_pct)(context));
	rows = &fe->m_rows;
	row = mk_lib_fe_x11_files_ro_at(rows, idx); mk_lang_assert(row);
	name = &row->m_name; mk_lang_assert(name);
	text_buf = mk_lib_fe_x11_string_ro_data(name); mk_lang_assert(text_buf && text_buf[0] != '\0');
	text_len = ((mk_lang_types_sint_t)(mk_lib_fe_x11_string_ro_size(name))); mk_lang_assert(text_len >= 1);
	*text = text_buf;
	*len = text_len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_construct(mk_lib_fe_x11_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	mk_lang_types_sint_t screen;
	Window parent;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	Atom wmdelete;
	Window window;
	mk_lang_types_slong_t mask;
	mk_lang_types_sint_t tsi;
	GC gc;

	mk_lang_assert(fe);

	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_default_screen_value(&screen); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_default_screen_rootw(&parent); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_default_screen_black(&black); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_default_screen_white(&white); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
	window = XCreateSimpleWindow(display, parent, 0, 0, 320, 200, 5, black, white);
	mask = KeyPressMask | ButtonPressMask | ExposureMask | StructureNotifyMask;
	tsi = XSelectInput(display, window, mask);
	tsi = XSetStandardProperties(display, window, "fe", mk_lang_null, None, mk_lang_null, 0, mk_lang_null);
	tsi = XSetWMProtocols(display, window, &wmdelete, 1);
	gc = XCreateGC(display, window, 0, mk_lang_null);
	tsi = XSetBackground(display, gc, white);
	tsi = XSetForeground(display, gc, black);
	tsi = XClearWindow(display, window);
	fe->m_visible = mk_lang_false;
	fe->m_hidden = mk_lang_false;
	fe->m_window = window;
	fe->m_gc = gc;
	err = mk_lib_fe_x11_string_rw_construct(&fe->m_path); mk_lang_check_rereturn(err);
	err = mk_lib_fe_x11_files_rw_construct(&fe->m_rows); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_construct(&fe->m_list_view, display, window, gc); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_dimensions(&fe->m_list_view, 0, 0, 320, 200); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_callback(&fe->m_list_view, &mk_lib_fe_x11_prro_on_row, fe); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_destruct(mk_lib_fe_x11_pt const fe) mk_lang_noexcept
{
	Window window;
	GC gc;
	mk_lib_fe_x11_string_pt path;
	mk_lib_fe_x11_files_pt rows;
	mk_lib_x11_list_view_pt list_view;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_fe_x11_file_pt row;
	mk_lib_fe_x11_string_pt name;
	Display* display;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(fe);

	window = fe->m_window;
	gc = fe->m_gc;
	path = &fe->m_path;
	rows = &fe->m_rows;
	list_view = &fe->m_list_view;
	err = mk_lib_x11_list_view_rw_destruct(list_view); mk_lang_check_rereturn(err);
	n = ((mk_lang_types_sint_t)(mk_lib_fe_x11_files_ro_size(rows)));
	for(i = 0; i != n; ++i)
	{
		row = mk_lib_fe_x11_files_rw_at(rows, i); mk_lang_assert(row);
		name = &row->m_name; mk_lang_assert(name);
		err = mk_lib_fe_x11_string_rw_destroy(name); mk_lang_check_rereturn(err);
	}
	err = mk_lib_fe_x11_files_rw_destroy(rows); mk_lang_check_rereturn(err);
	err = mk_lib_fe_x11_string_rw_destroy(path); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	tsi = XFreeGC(display, gc);
	tsi = XDestroyWindow(display, window);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_show(mk_lib_fe_x11_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(fe);

	if(!fe->m_visible)
	{
		fe->m_visible = mk_lang_true;
		fe->m_hidden = mk_lang_false;
		err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
		window = fe->m_window;
		tsi = XMapRaised(display, window);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_hide(mk_lib_fe_x11_pt const fe) mk_lang_noexcept
{
	Window window;
	mk_lang_types_sint_t err;
	Display* display;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(fe);

	fe->m_visible = mk_lang_false;
	if(!fe->m_hidden)
	{
		fe->m_hidden = mk_lang_true;
		window = fe->m_window;
		err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
		tsi = XUnmapWindow(display, window);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_invalidate_all(mk_lib_fe_x11_pt const fe) mk_lang_noexcept
{
	mk_lib_x11_list_view_pt list_view;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);

	list_view = &fe->m_list_view;
	/* todo invalidate whole current window, not just single control in it, the list view */
	err = mk_lib_x11_list_view_rw_invalidate_all(list_view); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_keypress(mk_lib_fe_x11_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	KeySym ks;
	mk_lang_types_sint_t err;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == KeyPress);

	ks = XLookupKeysym(&evt->xkey, 0);
	switch(ks)
	{
		case XK_q:
		{
			fe->m_visible = mk_lang_false;
		}
		break;
		case XK_Escape:
		{
			fe->m_visible = mk_lang_false;
		}
		break;
		case XK_d:
		{
			err = mk_lib_x11_cong_get_default_screen_black(&black); mk_lang_check_rereturn(err);
			err = mk_lib_x11_cong_get_default_screen_white(&white); mk_lang_check_rereturn(err);
			mk_lib_fe_x11_swap_ul_fn(&black, &white);
			err = mk_lib_x11_cong_set_default_screen_black(black); mk_lang_check_rereturn(err);
			err = mk_lib_x11_cong_set_default_screen_white(white); mk_lang_check_rereturn(err);
			err = mk_lib_fe_x11_prrw_invalidate_all(fe); mk_lang_check_rereturn(err);
		}
		break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_expose(mk_lib_fe_x11_pt const fe, XEvent* const evt) mk_lang_noexcept
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

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == Expose);

	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	gc = fe->m_gc;
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_configurenotify(mk_lib_fe_x11_pt const fe, XEvent* const evt) mk_lang_noexcept
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

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ConfigureNotify);

	ew = evt->xconfigure.window;
	w = evt->xconfigure.width;
	h = evt->xconfigure.height;
	mw = fe->m_window;
	list_view = &fe->m_list_view;
	if(ew == mw)
	{
		lvx = 0;
		lvy = 0;
		lvw = w;
		lvh = h;
		err = mk_lib_x11_list_view_rw_set_dimensions(list_view, lvx, lvy, lvw, lvh); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_delete(mk_lib_fe_x11_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	((mk_lang_types_void_t)(evt));
	fe->m_visible = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_clientmessage(mk_lib_fe_x11_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Atom wmdelete;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	err = mk_lib_x11_cong_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
	if(((Atom)(evt->xclient.data.l[0])) == wmdelete){ err = mk_lib_fe_x11_prrw_on_delete(fe, evt); mk_lang_check_rereturn(err); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_pump_window(mk_lib_fe_x11_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	mk_lib_x11_list_view_pt list_view;
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	mk_lang_types_slong_t mask;
	XEvent* evt;
	XEvent e;
	mk_lang_types_bool_t consumed;

	mk_lang_assert(fe);
	mk_lang_assert(at_least_one);

	list_view = &fe->m_list_view;
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	mask = KeyPressMask | ButtonPressMask | ExposureMask | StructureNotifyMask;
	evt = &e;
	while(fe->m_visible && XCheckWindowEvent(display, window, mask, evt) == True)
	{
		*at_least_one = mk_lang_true;
		switch(evt->type)
		{
			case KeyPress       : err = mk_lib_fe_x11_prrw_on_keypress       (fe, evt); mk_lang_check_rereturn(err); break;
			case Expose         : err = mk_lib_fe_x11_prrw_on_expose         (fe, evt); mk_lang_check_rereturn(err); break;
			case ConfigureNotify: err = mk_lib_fe_x11_prrw_on_configurenotify(fe, evt); mk_lang_check_rereturn(err); break;
			case ClientMessage  : err = mk_lib_fe_x11_prrw_on_clientmessage  (fe, evt); mk_lang_check_rereturn(err); break;
		}
		err = mk_lib_x11_list_view_rw_on_event(list_view, evt, &consumed); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_pump_global(mk_lib_fe_x11_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	Display* display;
	Window window;
	XEvent* evt;
	XEvent e;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(at_least_one);

	if(!fe->m_visible)
	{
		err = mk_lib_fe_x11_prrw_hide(fe); mk_lang_check_rereturn(err);
	}
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	evt = &e;
	gud = mk_lang_true;
	while(gud)
	{
		gud = mk_lang_false;
		tsi = XPeekEvent(display, evt);
		if(evt->type == ClientMessage && evt->xclient.window == window)
		{
			gud = mk_lang_true;
			*at_least_one = mk_lang_true;
			tsi = XNextEvent(display, evt);
			mk_lang_assert(evt->type == ClientMessage);
			mk_lang_assert(evt->xclient.window == window);
			err = mk_lib_fe_x11_prrw_on_clientmessage(fe, evt); mk_lang_check_rereturn(err);
		}
	}
	if(!fe->m_visible)
	{
		err = mk_lib_fe_x11_prrw_hide(fe); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_pump(mk_lib_fe_x11_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(at_least_one);

	gud = mk_lang_true;
	while(gud)
	{
		gud = mk_lang_false;
		err = mk_lib_fe_x11_prrw_pump_window(fe, &gud); mk_lang_check_rereturn(err);
		err = mk_lib_fe_x11_prrw_pump_global(fe, &gud); mk_lang_check_rereturn(err);
		if(gud)
		{
			*at_least_one = mk_lang_true;
		}
	}
	return 0;
}


static mk_lib_fe_x11_t g_mk_lib_fe_x11;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_fe_x11_pt fe;
	mk_lang_types_sint_t err;

	fe = &g_mk_lib_fe_x11;
	err = mk_lib_fe_x11_prrw_construct(fe); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_fe_x11_pt fe;
	mk_lang_types_sint_t err;

	fe = &g_mk_lib_fe_x11;
	err = mk_lib_fe_x11_prrw_destruct(fe); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_show(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_fe_x11_pt fe;
	mk_lang_types_sint_t err;

	fe = &g_mk_lib_fe_x11;
	err = mk_lib_fe_x11_prrw_show(fe); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_hide(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_fe_x11_pt fe;
	mk_lang_types_sint_t err;

	fe = &g_mk_lib_fe_x11;
	err = mk_lib_fe_x11_prrw_hide(fe); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_invalidate_all(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_fe_x11_pt fe;
	mk_lang_types_sint_t err;

	fe = &g_mk_lib_fe_x11;
	err = mk_lib_fe_x11_prrw_invalidate_all(fe); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_pump(mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	mk_lib_fe_x11_pt fe;
	mk_lang_types_sint_t err;

	mk_lang_assert(at_least_one);

	fe = &g_mk_lib_fe_x11;
	err = mk_lib_fe_x11_prrw_pump(fe, at_least_one); mk_lang_check_rereturn(err);
	return 0;
}
