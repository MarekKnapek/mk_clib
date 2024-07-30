#include "mk_lib_fe_x11.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clamp.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_strlen.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_fe_posix.h"
#include "mk_lib_statistics.h"
#include "mk_lib_x11_cong.h"
#include "mk_lib_x11_headers.h"
#include "mk_lib_x11_list_view.h"
#include "mk_sl_mallocatorg.h"

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
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

#define mk_sl_vector_t_name mk_lib_fe_x11_strings
#define mk_sl_vector_t_element mk_lib_fe_posix_string_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"

struct mk_lib_fe_x11_file_s
{
	mk_lib_fe_posix_string_t m_name;
	mk_lang_types_bool_t m_is_dir;
};
typedef struct mk_lib_fe_x11_file_s mk_lib_fe_x11_file_t;
typedef mk_lib_fe_x11_file_t const mk_lib_fe_x11_file_ct;
typedef mk_lib_fe_x11_file_t* mk_lib_fe_x11_file_pt;
typedef mk_lib_fe_x11_file_t const* mk_lib_fe_x11_file_pct;

#define mk_sl_vector_t_name mk_lib_fe_x11_files
#define mk_sl_vector_t_element mk_lib_fe_x11_file_t
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
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
		texta = mk_lib_fe_posix_string_ro_data(&a->m_name); mk_lang_assert(texta && texta[0] != '\0');
		textb = mk_lib_fe_posix_string_ro_data(&b->m_name); mk_lang_assert(textb && textb[0] != '\0');
		lena = mk_lib_fe_posix_string_ro_size(&a->m_name); mk_lang_assert(lena >= 1);
		lenb = mk_lib_fe_posix_string_ro_size(&b->m_name); mk_lang_assert(lenb >= 1);
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
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"


struct mk_lib_fe_x11_s
{
	mk_lang_types_bool_t m_visible;
	mk_lang_types_bool_t m_hidden;
	Window m_window;
	GC m_gc;
	mk_lib_fe_x11_string_t m_tmp;
	mk_lib_fe_posix_t m_server;
	mk_lib_x11_list_view_t m_list_view;
};
typedef struct mk_lib_fe_x11_s mk_lib_fe_x11_t;
typedef mk_lib_fe_x11_t const mk_lib_fe_x11_ct;
typedef mk_lib_fe_x11_t* mk_lib_fe_x11_pt;
typedef mk_lib_fe_x11_t const* mk_lib_fe_x11_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_dirify(mk_lib_fe_x11_pt const fe, mk_lib_fe_posix_file_pct const file, mk_lang_types_pchar_ppct const text_out, mk_lang_types_sint_pt const len_out) mk_lang_noexcept
{
	mk_lang_types_pchar_pct text;
	mk_lang_types_usize_t size;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_t elem;

	mk_lang_assert(fe);
	mk_lang_assert(file);
	mk_lang_assert(text_out);
	mk_lang_assert(len_out);

	text = mk_lib_fe_posix_string_ro_data(&file->m_name); mk_lang_assert(text && text[0] != '\0');
	size = mk_lib_fe_posix_string_ro_size(&file->m_name); mk_lang_assert(size >= 1 && size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))); len = ((mk_lang_types_sint_t)(size));
	if(file->m_is_dir)
	{
		err = mk_lib_fe_x11_string_rw_clear(&fe->m_tmp); mk_lang_check_rereturn(err);
		err = mk_lib_fe_x11_string_rw_reserve_at_least(&fe->m_tmp, 2 + size + 2); mk_lang_check_rereturn(err);
		elem = '['; err = mk_lib_fe_x11_string_rw_push_back_one(&fe->m_tmp, &elem); mk_lang_check_rereturn(err);
		elem = ' '; err = mk_lib_fe_x11_string_rw_push_back_one(&fe->m_tmp, &elem); mk_lang_check_rereturn(err);
		err = mk_lib_fe_x11_string_rw_push_back_many(&fe->m_tmp, text, size); mk_lang_check_rereturn(err);
		elem = ' '; err = mk_lib_fe_x11_string_rw_push_back_one(&fe->m_tmp, &elem); mk_lang_check_rereturn(err);
		elem = ']'; err = mk_lib_fe_x11_string_rw_push_back_one(&fe->m_tmp, &elem); mk_lang_check_rereturn(err);
		text = mk_lib_fe_x11_string_ro_data(&fe->m_tmp); mk_lang_assert(text && text[0] != '\0');
		size = mk_lib_fe_x11_string_ro_size(&fe->m_tmp); mk_lang_assert(size >= 1 && size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))); len = ((mk_lang_types_sint_t)(size));
	}
	*text_out = text;
	*len_out = len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_row(mk_lib_x11_list_view_callctx_t const context, mk_lang_types_sint_t const idx, mk_lang_types_pchar_ppct const text, mk_lang_types_sint_pt const len) mk_lang_noexcept
{
	mk_lib_fe_x11_pt fe;
	mk_lib_fe_posix_pct server;
	mk_lang_types_sint_t err;
	mk_lib_fe_posix_files_pct files;
	mk_lib_fe_posix_ints_pct sort;
	mk_lang_types_sint_t id;
	mk_lib_fe_posix_file_pct file;
	mk_lang_types_pchar_pct text_buf;
	mk_lang_types_sint_t text_len;

	mk_lang_assert(context);
	mk_lang_assert(text);
	mk_lang_assert(len);

	fe = ((mk_lib_fe_x11_pt)(context));
	server = &fe->m_server; mk_lang_assert(server);
	err = mk_lib_fe_posix_ro_get_files(server, &files); mk_lang_check_rereturn(err);
	err = mk_lib_fe_posix_ro_get_sort(server, &sort); mk_lang_check_rereturn(err);
	id = *mk_lib_fe_posix_ints_ro_at(sort, idx);
	file = mk_lib_fe_posix_files_ro_at(files, id); mk_lang_assert(file);
	err = mk_lib_fe_x11_prrw_dirify(fe, file, &text_buf, &text_len); mk_lang_check_rereturn(err); mk_lang_assert(text_buf && text_buf[0] != '\0'); mk_lang_assert(text_len >= 1);
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
	mk_lang_types_sint_t count;
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
	err = mk_lib_fe_x11_string_rw_construct(&fe->m_tmp); mk_lang_check_rereturn(err);
	err = mk_lib_fe_posix_rw_construct(&fe->m_server); mk_lang_check_rereturn(err);
	err = mk_lib_fe_posix_ro_get_count(&fe->m_server, &count); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_construct(&fe->m_list_view, display, window, gc); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_dimensions(&fe->m_list_view, 0, 0, 320, 200); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_callback(&fe->m_list_view, &mk_lib_fe_x11_prrw_on_row, fe); mk_lang_check_rereturn(err);
	err = mk_lib_x11_list_view_rw_set_rows(&fe->m_list_view, count); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_destruct(mk_lib_fe_x11_pt const fe) mk_lang_noexcept
{
	Window window;
	GC gc;
	mk_lib_fe_x11_string_pt tmp;
	mk_lib_fe_posix_string_pt path;
	mk_lib_fe_x11_files_pt rows;
	mk_lib_fe_posix_pt server;
	mk_lib_x11_list_view_pt list_view;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lib_fe_x11_file_pt row;
	mk_lib_fe_posix_string_pt name;
	Display* display;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(fe);

	window = fe->m_window;
	gc = fe->m_gc;
	tmp = &fe->m_tmp;
	server = &fe->m_server;
	list_view = &fe->m_list_view;
	err = mk_lib_x11_list_view_rw_destruct(list_view); mk_lang_check_rereturn(err);
	err = mk_lib_fe_posix_rw_destruct(server); mk_lang_check_rereturn(err);
	err = mk_lib_fe_x11_string_rw_destroy(tmp); mk_lang_check_rereturn(err);
	err = mk_lib_x11_cong_get_display(&display); mk_lang_check_rereturn(err);
	tsi = XFreeGC(display, gc);
	tsi = XDestroyWindow(display, window);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_prrw_is_hidden(mk_lib_fe_x11_pt const fe, mk_lang_types_bool_pt const is_hidden) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(is_hidden);

	*is_hidden = fe->m_hidden;
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
		err = mk_lib_fe_x11_prrw_invalidate_all(fe); mk_lang_check_rereturn(err);
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_keypress(mk_lib_fe_x11_pt const fe, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	Window ew;
	Window mw;
	KeySym ks;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t count;
	mk_lang_types_bool_t went;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == KeyPress);
	mk_lang_assert(consumed);

	ew = evt->xkey.window;
	mw = fe->m_window;
	if(ew == mw)
	{
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
			case XK_Return:
			{
				err = mk_lib_x11_list_view_ro_get_idx(&fe->m_list_view, &idx); mk_lang_check_rereturn(err);
				err = mk_lib_fe_posix_rw_go_dn(&fe->m_server, idx, &went); mk_lang_check_rereturn(err);
				if(went)
				{
					err = mk_lib_fe_posix_ro_get_count(&fe->m_server, &count); mk_lang_check_rereturn(err);
					err = mk_lib_x11_list_view_rw_set_rows(&fe->m_list_view, count); mk_lang_check_rereturn(err);
					err = mk_lib_x11_list_view_rw_set_idx(&fe->m_list_view, 0); mk_lang_check_rereturn(err);
					err = mk_lib_x11_list_view_rw_invalidate_all(&fe->m_list_view); mk_lang_check_rereturn(err);
				}
			}
			break;
			case XK_BackSpace:
			{
				err = mk_lib_fe_posix_rw_go_up(&fe->m_server, &went); mk_lang_check_rereturn(err);
				if(went)
				{
					err = mk_lib_fe_posix_ro_get_count(&fe->m_server, &count); mk_lang_check_rereturn(err);
					err = mk_lib_x11_list_view_rw_set_rows(&fe->m_list_view, count); mk_lang_check_rereturn(err);
					err = mk_lib_x11_list_view_rw_set_idx(&fe->m_list_view, 0); mk_lang_check_rereturn(err);
					err = mk_lib_x11_list_view_rw_invalidate_all(&fe->m_list_view); mk_lang_check_rereturn(err);
				}
			}
			break;
			case XK_i:
			{
				err = mk_lib_statistics_hide(); mk_lang_check_rereturn(err);
				err = mk_lib_statistics_show(); mk_lang_check_rereturn(err);
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
		*consumed = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_expose(mk_lib_fe_x11_pt const fe, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
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

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == Expose);
	mk_lang_assert(consumed);

	ew = evt->xexpose.window;
	mw = fe->m_window;
	if(ew == mw)
	{
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
		*consumed = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_configurenotify(mk_lib_fe_x11_pt const fe, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
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
	mk_lang_assert(consumed);

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
		*consumed = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_delete(mk_lib_fe_x11_pt const fe, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);
	mk_lang_assert(evt->xclient.window == fe->m_window);
	mk_lang_assert(consumed);

	((mk_lang_types_void_t)(evt));
	fe->m_visible = mk_lang_false;
	*consumed = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_clientmessage(mk_lib_fe_x11_pt const fe, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	Window ew;
	Window mw;
	mk_lang_types_sint_t err;
	Atom wmdelete;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);
	mk_lang_assert(consumed);

	ew = evt->xclient.window;
	mw = fe->m_window;
	if(ew == mw)
	{
		err = mk_lib_x11_cong_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
		if(((Atom)(evt->xclient.data.l[0])) == wmdelete){ err = mk_lib_fe_x11_prrw_on_delete(fe, evt, consumed); mk_lang_check_rereturn(err); }
	}
	return 0;
}

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_pump_window(mk_lib_fe_x11_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
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
}*/

/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_pump_global(mk_lib_fe_x11_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
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
}*/

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_fe_x11_prrw_on_event(mk_lib_fe_x11_pt const fe, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(consumed);

	switch(evt->type)
	{
		case KeyPress       : err = mk_lib_fe_x11_prrw_on_keypress       (fe, evt, consumed); mk_lang_check_rereturn(err); break;
		case Expose         : err = mk_lib_fe_x11_prrw_on_expose         (fe, evt, consumed); mk_lang_check_rereturn(err); break;
		case ConfigureNotify: err = mk_lib_fe_x11_prrw_on_configurenotify(fe, evt, consumed); mk_lang_check_rereturn(err); break;
		case ClientMessage  : err = mk_lib_fe_x11_prrw_on_clientmessage  (fe, evt, consumed); mk_lang_check_rereturn(err); break;
	}
	err = mk_lib_x11_list_view_rw_on_event(&fe->m_list_view, evt, consumed); mk_lang_check_rereturn(err);
	if(!fe->m_visible)
	{
		err = mk_lib_fe_x11_prrw_hide(fe); mk_lang_check_rereturn(err);
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_is_hidden(mk_lang_types_bool_pt const is_hidden) mk_lang_noexcept
{
	mk_lib_fe_x11_pt fe;
	mk_lang_types_sint_t err;

	mk_lang_assert(is_hidden);

	fe = &g_mk_lib_fe_x11;
	err = mk_lib_fe_x11_prrw_is_hidden(fe, is_hidden); mk_lang_check_rereturn(err);
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_on_event(XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept
{
	mk_lib_fe_x11_pt fe;
	mk_lang_types_sint_t err;

	mk_lang_assert(evt);
	mk_lang_assert(consumed);

	fe = &g_mk_lib_fe_x11;
	err = mk_lib_fe_x11_prrw_on_event(fe, evt, consumed); mk_lang_check_rereturn(err);
	return 0;
}
