#include "src/mk_lang_clamp.h"
#include "src/mk_lang_assert.h"
#include "src/mk_lang_bool.h"
#include "src/mk_lang_check.h"
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
#include "src/mk_lib_x11.h"

#define mk_clib_app_fe_posix_mallocatorg_id_disp        11
#define mk_clib_app_fe_posix_mallocatorg_id_portablec   12
#define mk_clib_app_fe_posix_mallocatorg_id_portablecpp 13
#define mk_clib_app_fe_posix_mallocatorg_id_windows     14
#define mk_clib_app_fe_posix_mallocatorg_id_tracer      15
#if defined mk_clib_app_fe_posix_mallocatorg_want && (mk_clib_app_fe_posix_mallocatorg_want) == mk_clib_app_fe_posix_mallocatorg_id_disp
#define mk_clib_app_fe_posix_mallocatorg_id mk_clib_app_fe_posix_mallocatorg_id_disp
#elif defined mk_clib_app_fe_posix_mallocatorg_want && (mk_clib_app_fe_posix_mallocatorg_want) == mk_clib_app_fe_posix_mallocatorg_id_portablec
#define mk_clib_app_fe_posix_mallocatorg_id mk_clib_app_fe_posix_mallocatorg_id_portablec
#elif defined mk_clib_app_fe_posix_mallocatorg_want && (mk_clib_app_fe_posix_mallocatorg_want) == mk_clib_app_fe_posix_mallocatorg_id_portablecpp
#define mk_clib_app_fe_posix_mallocatorg_id mk_clib_app_fe_posix_mallocatorg_id_portablecpp
#elif defined mk_clib_app_fe_posix_mallocatorg_want && (mk_clib_app_fe_posix_mallocatorg_want) == mk_clib_app_fe_posix_mallocatorg_id_windows
#define mk_clib_app_fe_posix_mallocatorg_id mk_clib_app_fe_posix_mallocatorg_id_windows
#elif defined mk_clib_app_fe_posix_mallocatorg_want && (mk_clib_app_fe_posix_mallocatorg_want) == mk_clib_app_fe_posix_mallocatorg_id_tracer
#define mk_clib_app_fe_posix_mallocatorg_id mk_clib_app_fe_posix_mallocatorg_id_tracer
#elif !defined mk_clib_app_fe_posix_mallocatorg_want
#if defined NDEBUG
#define mk_clib_app_fe_posix_mallocatorg_id mk_clib_app_fe_posix_mallocatorg_id_disp
#else
#define mk_clib_app_fe_posix_mallocatorg_id mk_clib_app_fe_posix_mallocatorg_id_tracer
#endif
#else
#error xxxxxxxxxx
#endif
#if mk_clib_app_fe_posix_mallocatorg_id == mk_clib_app_fe_posix_mallocatorg_id_disp
#include "src/mk_sl_mallocatorg.h"
#define mk_clib_app_fe_posix_mallocatorg_name mk_sl_mallocatorg
#elif mk_clib_app_fe_posix_mallocatorg_id == mk_clib_app_fe_posix_mallocatorg_id_portablec
#include "src/mk_sl_mallocatorg_portablec.h"
#define mk_clib_app_fe_posix_mallocatorg_name mk_sl_mallocatorg_portablec
#elif mk_clib_app_fe_posix_mallocatorg_id == mk_clib_app_fe_posix_mallocatorg_id_portablecpp
#include "src/mk_sl_mallocatorg_portablecpp.hpp"
#define mk_clib_app_fe_posix_mallocatorg_name mk_sl_mallocatorg_portablecpp
#elif mk_clib_app_fe_posix_mallocatorg_id == mk_clib_app_fe_posix_mallocatorg_id_windows
#include "src/mk_sl_mallocatorg_windows.h"
#define mk_clib_app_fe_posix_mallocatorg_name mk_sl_mallocatorg_windows
#elif mk_clib_app_fe_posix_mallocatorg_id == mk_clib_app_fe_posix_mallocatorg_id_tracer
#include "src/mk_sl_mallocg_tracer.h"
#define mk_clib_app_fe_posix_mallocatorg_name mk_sl_mallocg_tracer
#else
#error xxxxxxxxxx
#endif
#define mk_clib_app_fe_posix_mallocatorg_init mk_lang_concat(mk_clib_app_fe_posix_mallocatorg_name, _init)
#define mk_clib_app_fe_posix_mallocatorg_deinit mk_lang_concat(mk_clib_app_fe_posix_mallocatorg_name, _deinit)
#if defined mk_clib_app_fe_posix_mallocatorg_statistics_want && (mk_clib_app_fe_posix_mallocatorg_statistics_want) == 0
#define mk_clib_app_fe_posix_mallocatorg_statistics_have 0
#elif defined mk_clib_app_fe_posix_mallocatorg_statistics_want && (mk_clib_app_fe_posix_mallocatorg_statistics_want) == 1
#define mk_clib_app_fe_posix_mallocatorg_statistics_have 1
#elif mk_clib_app_fe_posix_mallocatorg_id == mk_clib_app_fe_posix_mallocatorg_id_tracer
#define mk_clib_app_fe_posix_mallocatorg_statistics_have 1
#else
#define mk_clib_app_fe_posix_mallocatorg_statistics_have 0
#endif
#if mk_clib_app_fe_posix_mallocatorg_statistics_have
#define mk_lib_statistics_mallocatorg_want mk_clib_app_fe_posix_mallocatorg_id
#include "src/mk_lib_statistics.h"
#endif

#define mk_sl_vector_t_name mkfe_string
#define mk_sl_vector_t_element mk_lang_types_pchar_t
#define mk_sl_vector_t_mallocatorg mk_clib_app_fe_posix_mallocatorg_name
#include "src/mk_sl_vector_inl_fileh.h"
#include "src/mk_sl_vector_inl_filec.h"

#define mk_sl_vector_t_name mkfe_strings
#define mk_sl_vector_t_element mkfe_string_t
#define mk_sl_vector_t_mallocatorg mk_clib_app_fe_posix_mallocatorg_name
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
#define mk_sl_vector_t_mallocatorg mk_clib_app_fe_posix_mallocatorg_name
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
#define mk_sl_vector_t_mallocatorg mk_clib_app_fe_posix_mallocatorg_name
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
	mk_lang_types_sint_t m_screen;
	mk_lang_types_ulong_t m_black;
	mk_lang_types_ulong_t m_white;
	Window m_window;
	GC m_gc;
	mk_lang_types_bool_t m_visible;
	mk_lang_types_bool_t m_hidden;
	mkfe_files_t m_rows;
	mkfe_ints_t m_sort;
	mkfe_string_t m_curr_path;
	mkfe_string_t m_tmp_str;
	mk_lang_types_sint_t m_idx;
	mk_lang_types_sint_t m_text_asc;
	mk_lang_types_sint_t m_text_des;
	mk_lang_types_sint_t m_cur_asc;
	mk_lang_types_sint_t m_cur_des;
};
typedef struct mkfe_s mkfe_t;
typedef mkfe_t const mkfe_ct;
typedef mkfe_t* mkfe_pt;
typedef mkfe_t const* mkfe_pct;


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mkfe_x_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789[]";


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_init(mkfe_pt const fe) mk_lang_noexcept
{
	Display* display;
	mk_lang_types_sint_t screen;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	Window parent;
	Window window;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;
	Atom wmdelete;
	GC gc;
	GContext gcid;
	mk_lang_types_sint_t direction;
	mk_lang_types_sint_t ascent;
	mk_lang_types_sint_t descent;
	XCharStruct dimensions;

	mk_lang_assert(fe);

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	err = mk_lib_x11_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
	screen = DefaultScreen(display);
	black = BlackPixel(display, screen);
	white = WhitePixel(display, screen);
	parent = RootWindow(display, screen);
	window = XCreateSimpleWindow(display, parent, 0, 0, 320, 200, 5, black, white);
	tsi = XSetStandardProperties(display, window, "mkfe", mk_lang_null, None, mk_lang_null, 0, mk_lang_null);
	tsi = XSetWMProtocols(display, window, &wmdelete, 1);
	tsi = XSelectInput(display, window, ExposureMask | ButtonPressMask | KeyPressMask);
	gc = XCreateGC(display, window, 0, 0);
	tsi = XSetBackground(display, gc, white);
	tsi = XSetForeground(display ,gc, black);
	tsi = XClearWindow(display, window);
	tsi = XMapRaised(display, window);
	fe->m_screen = screen;
	fe->m_black = black;
	fe->m_white = white;
	fe->m_window = window;
	fe->m_gc = gc;
	fe->m_visible = mk_lang_true;
	fe->m_hidden = mk_lang_false;
	fe->m_text_asc = 1;
	fe->m_text_des = 0;
	fe->m_cur_asc = 1;
	fe->m_cur_des = 0;
	err = mkfe_files_rw_construct(&fe->m_rows); mk_lang_check_rereturn(err);
	err = mkfe_ints_rw_construct(&fe->m_sort); mk_lang_check_rereturn(err);
	err = mkfe_string_rw_construct(&fe->m_curr_path); mk_lang_check_rereturn(err);
	err = mkfe_string_rw_construct(&fe->m_tmp_str); mk_lang_check_rereturn(err);
	gcid = XGContextFromGC(gc);
	tsi = XQueryTextExtents(display, gcid, &mkfe_x_alphabet[0], mk_lang_countstr(mkfe_x_alphabet), &direction, &ascent, &descent, &dimensions);
	fe->m_text_asc = dimensions.ascent;
	fe->m_text_des = dimensions.descent;
	fe->m_cur_asc = dimensions.ascent;
	fe->m_cur_des = dimensions.descent;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_deinit(mkfe_pt const fe) mk_lang_noexcept
{
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_sint_t tsi;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t err;
	mkfe_file_pt row;

	mk_lang_assert(fe);

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	gc = fe->m_gc;
	tsi = XFreeGC(display, gc);
	tsi = XDestroyWindow(display, window);
	n = mkfe_files_ro_size(&fe->m_rows);
	for(i = 0; i != n; ++i)
	{
		row = mkfe_files_rw_at(&fe->m_rows, i); mk_lang_assert(row);
		err = mkfe_string_rw_destroy(&row->m_name); mk_lang_check_rereturn(err);
	}
	err = mkfe_files_rw_destroy(&fe->m_rows); mk_lang_check_rereturn(err);
	err = mkfe_ints_rw_destroy(&fe->m_sort); mk_lang_check_rereturn(err);
	err = mkfe_string_rw_destroy(&fe->m_curr_path); mk_lang_check_rereturn(err);
	err = mkfe_string_rw_destroy(&fe->m_tmp_str); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_sort(mkfe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t count;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mkfe_file_pt files_buf;
	mk_lang_types_sint_pt sort_buf;

	mk_lang_assert(fe);

	err = mkfe_ints_rw_clear(&fe->m_sort); mk_lang_check_rereturn(err);
	count = mkfe_files_ro_size(&fe->m_rows); mk_lang_assert(count >= 0 && count <= mk_lang_limits_usize_max / 2 && count <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)) / 2);
	if(count != 0)
	{
		files_buf = mkfe_files_rw_data(&fe->m_rows); mk_lang_assert(files_buf);
		err = mkfe_ints_rw_push_back_void(&fe->m_sort, count * 2); mk_lang_check_rereturn(err);
		sort_buf = mkfe_ints_rw_data(&fe->m_sort); mk_lang_assert(sort_buf);
		n = count;
		for(i = 0; i != n; ++i)
		{
			sort_buf[i] = ((mk_lang_types_sint_t)(i));
		}
		mkfe_sort_files_proxy(&files_buf[0], &sort_buf[0], ((mkfe_cntr_t)(count)), &sort_buf[count]);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_gather_dir(mkfe_pt const fe, mkfe_string_pt const dir) mk_lang_noexcept
{
	mk_lang_types_pchar_t nul;
	mk_lang_types_pchar_t slash;
	mk_lang_types_pchar_pt buf;
	mk_lang_types_usize_t len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t tsi;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t j;
	DIR* d;
	struct dirent* e;
	mkfe_file_pt row;
	struct stat st;

	mk_lang_assert(fe);
	mk_lang_assert(dir);

	nul = '\0';
	slash = '/';
	len = mkfe_string_ro_size(dir); mk_lang_assert(len >= 0);
	err = mkfe_string_rw_resize(&fe->m_tmp_str, len + 1); mk_lang_check_rereturn(err);
	if(len != 0)
	{
		mkfe_memcpy_pc_fn(mkfe_string_rw_data(&fe->m_tmp_str), mkfe_string_ro_data(dir), len);
	}
	mkfe_string_rw_data(&fe->m_tmp_str)[len] = slash;
	if(len == 0)
	{
		err = mkfe_string_rw_push_back_one(dir, &slash); mk_lang_check_rereturn(err);
	}
	err = mkfe_string_rw_push_back_one(dir, &nul); mk_lang_check_rereturn(err);
	buf = mkfe_string_rw_data(dir); mk_lang_assert(buf && buf[0] != '\0');
	i = 0;
	d = opendir(buf); mk_lang_check_return(d);
	while((e = readdir(d)) != mk_lang_null)
	{
		if
		(!(
			(e->d_name[0] == '.' && e->d_name[1] == '\0') ||
			(e->d_name[0] == '.' && e->d_name[1] == '.' && e->d_name[2] == '\0') ||
			mk_lang_false
		))
		{
			len = mk_lang_strlen_n_fn(&e->d_name[0]); mk_lang_assert(len >= 1);
			if(i < mkfe_files_ro_size(&fe->m_rows))
			{
				row = mkfe_files_rw_at(&fe->m_rows, i); mk_lang_assert(row);
				err = mkfe_string_rw_clear(&row->m_name); mk_lang_check_rereturn(err);
			}
			else
			{
				err = mkfe_files_rw_push_back_void(&fe->m_rows, 1); mk_lang_check_rereturn(err);
				row = mkfe_files_rw_back(&fe->m_rows); mk_lang_assert(row);
				err = mkfe_string_rw_construct(&row->m_name); mk_lang_check_rereturn(err);
			}
			err = mkfe_string_rw_push_back_many(&row->m_name, &e->d_name[0], len); mk_lang_check_rereturn(err);
			err = mkfe_string_rw_push_back_many(&fe->m_tmp_str, &e->d_name[0], len); mk_lang_check_rereturn(err);
			err = mkfe_string_rw_push_back_one(&fe->m_tmp_str, &nul); mk_lang_check_rereturn(err);
			tsi = stat(mkfe_string_ro_data(&fe->m_tmp_str), &st); mk_lang_check_return(tsi == 0);
			row->m_is_dir = !!S_ISDIR(st.st_mode);
			err = mkfe_string_rw_shrink(&fe->m_tmp_str, len + 1); mk_lang_check_rereturn(err);
			++i;
		}
	}
	tsi = closedir(d); mk_lang_check_return(tsi == 0);
	n = mkfe_files_ro_size(&fe->m_rows);
	if(i < n)
	{
		n = n - i;
		for(j = 0; j != n; ++j)
		{
			err = mkfe_string_rw_destroy(&mkfe_files_rw_at(&fe->m_rows, i + j)->m_name); mk_lang_check_rereturn(err);
		}
	}
	err = mkfe_files_rw_resize(&fe->m_rows, i); mk_lang_check_rereturn(err);
	err = mkfe_x_sort(fe); mk_lang_check_rereturn(err);
	if(mkfe_string_ro_size(dir) != 2)
	{
		err = mkfe_string_rw_shrink(dir, 1); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mkfe_string_rw_clear(dir); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_gather_root(mkfe_pt const fe) mk_lang_noexcept
{
	mkfe_string_t root;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);

	err = mkfe_string_rw_construct(&root); mk_lang_check_rereturn(err);
	err = mkfe_x_gather_dir(fe, &root); mk_lang_check_rereturn(err);
	err = mkfe_string_rw_destroy(&root); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mkfe_x_hide(mkfe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(fe);

	if(!fe->m_hidden)
	{
		fe->m_hidden = mk_lang_true;
		err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
		window = fe->m_window;
		tsi = XUnmapWindow(display, window);
		fe->m_visible = mk_lang_false;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_invalidate_all(mkfe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	XEvent e;
	Status st;
	XWindowAttributes attr;

	mk_lang_assert(fe);

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_invalidate_one(mkfe_pt const fe, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	Window window;
	XEvent e;
	Status st;
	XWindowAttributes attr;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t line_height;

	mk_lang_assert(fe);

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	text_asc = fe->m_text_asc;
	text_des = fe->m_text_des;
	line_height = text_asc + text_des;
	st = XGetWindowAttributes(display, window, &attr);
	e.type = Expose;
	e.xexpose.type = Expose;
	e.xexpose.serial = 0;
	e.xexpose.send_event = True;
	e.xexpose.display = display;
	e.xexpose.window = window;
	e.xexpose.x = 0;
	e.xexpose.y = idx * line_height;
	e.xexpose.width = attr.width;
	e.xexpose.height = line_height;
	e.xexpose.count = 0;
	st = XSendEvent(display, window, False, ExposureMask, &e);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_go_deep(mkfe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_pchar_t slash;
	mk_lang_types_sint_pct idxp;
	mk_lang_types_sint_t idx;
	mkfe_file_pct row;
	mkfe_string_pct name;
	mk_lang_types_pchar_pct buf;
	mk_lang_types_usize_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);

	if(!mkfe_files_ro_is_empty(&fe->m_rows))
	{
		slash = '/';
		idxp = mkfe_ints_ro_at(&fe->m_sort, fe->m_idx); mk_lang_assert(idxp); idx = *idxp;
		row = mkfe_files_ro_at(&fe->m_rows, idx); mk_lang_assert(row);
		if(row->m_is_dir)
		{
			name = &row->m_name; mk_lang_assert(name);
			buf = mkfe_string_ro_data(name); mk_lang_assert(buf && buf[0] != '\0');
			len = mkfe_string_ro_size(name); mk_lang_assert(len >= 1);
			err = mkfe_string_rw_push_back_one(&fe->m_curr_path, &slash); mk_lang_check_rereturn(err);
			err = mkfe_string_rw_push_back_many(&fe->m_curr_path, buf, len); mk_lang_check_rereturn(err);
			err = mkfe_x_gather_dir(fe, &fe->m_curr_path); mk_lang_check_rereturn(err);
			fe->m_idx = 0;
			err = mkfe_x_invalidate_all(fe); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_go_up(mkfe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_pchar_t slash;
	mk_lang_types_sint_pct idxp;
	mk_lang_types_sint_t idx;
	mkfe_file_pct row;
	mkfe_string_pct name;
	mk_lang_types_pchar_pct buf;
	mk_lang_types_usize_t len;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t j;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);

	slash = '/';
	len = mkfe_string_ro_size(&fe->m_curr_path); mk_lang_assert(len >= 0);
	if(len != 0)
	{
		buf = mkfe_string_ro_data(&fe->m_curr_path); mk_lang_assert(buf && buf[0] != '\0');
		n = len;
		for(i = 0; i != n; ++i)
		{
			j = (n - 1) - i;
			if(buf[j] == slash)
			{
				break;
			}
		}
		if(i != n)
		{
			err = mkfe_string_rw_resize(&fe->m_curr_path, j); mk_lang_check_rereturn(err);
		}
		else
		{
			err = mkfe_string_rw_clear(&fe->m_curr_path); mk_lang_check_rereturn(err);
		}
	}
	err = mkfe_x_gather_dir(fe, &fe->m_curr_path); mk_lang_check_rereturn(err);
	fe->m_idx = 0;
	err = mkfe_x_invalidate_all(fe); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_dirify(mkfe_pt const fe, mkfe_file_pct const file, mkfe_string_pct* const dirifyed) mk_lang_noexcept
{
	mkfe_string_pct name;
	mk_lang_types_pchar_pct src;
	mk_lang_types_usize_t len;
	mkfe_string_pt out;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pt dst;

	mk_lang_assert(fe);
	mk_lang_assert(file);
	mk_lang_assert(dirifyed);

	name = &file->m_name; mk_lang_assert(name);
	if(file->m_is_dir)
	{
		src = mkfe_string_ro_data(name); mk_lang_assert(src && src[0] != '\0');
		len = mkfe_string_ro_size(name); mk_lang_assert(len >= 1);
		out = &fe->m_tmp_str; mk_lang_assert(out);
		err = mkfe_string_rw_resize(out, 2 + len + 2); mk_lang_check_rereturn(err);
		dst = mkfe_string_rw_data(out); mk_lang_assert(dst);
		dst[0] = '[';
		dst[1] = ' ';
		mkfe_memcpy_pc_fn(&dst[2], src, len);
		dst[2 + len + 0] = ' ';
		dst[2 + len + 1] = ']';
		*dirifyed = out;
	}
	else
	{
		*dirifyed = name;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_expose_row(mkfe_pt const fe, XEvent* const evt, mk_lang_types_sint_t const width, mk_lang_types_bool_t const measure, mk_lang_types_sint_t const idx) mk_lang_noexcept
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
	mkfe_file_pct row;
	mk_lang_types_pchar_pct buf;
	mk_lang_types_usize_t lenus;
	mk_lang_types_sint_t lensi;
	mk_lang_types_sint_t cur_asc;
	mk_lang_types_sint_t cur_des;
	mk_lang_types_sint_t direction;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t line_height;
	mk_lang_types_sint_t ascent;
	mk_lang_types_sint_t descent;
	XCharStruct dimensions;
	mk_lang_types_sint_t err;
	mkfe_string_pct str;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == Expose);
	mk_lang_assert(evt->xexpose.count == 0);

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	gc = fe->m_gc;
	black = fe->m_black;
	white = fe->m_white;
	cur_asc = fe->m_cur_asc;
	cur_des = fe->m_cur_des;
	text_asc = fe->m_text_asc;
	text_des = fe->m_text_des;
	line_height = text_asc + text_des;
	gcid = XGContextFromGC(gc);
	row = mkfe_files_ro_at(&fe->m_rows, *mkfe_ints_ro_at(&fe->m_sort, idx)); mk_lang_assert(row);
	err = mkfe_x_dirify(fe, row, &str); mk_lang_check_rereturn(err);
	buf = mkfe_string_ro_data(str); mk_lang_assert(buf && buf[0] != '\0');
	lenus = mkfe_string_ro_size(str); mk_lang_assert(lenus >= 1 && lenus <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max))); lensi = ((mk_lang_types_sint_t)(lenus)); mk_lang_assert(lensi >= 1);
	if(measure && mk_lang_false)
	{
		tsi = XQueryTextExtents(display, gcid, buf, lensi, &direction, &ascent, &descent, &dimensions);
		cur_asc = mk_lang_max(cur_asc, dimensions.ascent);
		cur_des = mk_lang_max(cur_des, dimensions.descent);
	}
	y = idx * line_height;
	if(idx != fe->m_idx)
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
	y -= text_des;
	tsi = XDrawString(display, window, gc, 0, y, buf, lensi);
	y += text_des;
	if(idx == fe->m_idx)
	{
		tsi = XSetForeground(display, gc, black);
	}
	fe->m_cur_asc = cur_asc;
	fe->m_cur_des = cur_des;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_expose(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	mk_lang_types_sint_t tsi;
	Status st;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t visible_rows;
	mk_lang_types_usize_t i;
	XWindowAttributes attr;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t ymin;
	mk_lang_types_sint_t ymax;
	mk_lang_types_sint_t text_asc;
	mk_lang_types_sint_t text_des;
	mk_lang_types_sint_t line_height;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == Expose);

	if(evt->xexpose.count == 0)
	{
		err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
		window = fe->m_window;
		gc = fe->m_gc;
		black = fe->m_black;
		white = fe->m_white;
		text_asc = fe->m_text_asc;
		text_des = fe->m_text_des;
		line_height = text_asc + text_des;
		st = XGetWindowAttributes(display, window, &attr);
		visible_rows = ((mk_lang_types_usize_t)(mk_lang_div_roundup(attr.height, line_height)));
		n = mkfe_files_ro_size(&fe->m_rows);
		n = mk_lang_min(n, visible_rows);
		if(evt->xexpose.x == 0 && evt->xexpose.y == 0 && evt->xexpose.width == attr.width && evt->xexpose.height == attr.height)
		{
			tsi = XSetForeground(display ,gc , white);
			tsi = XFillRectangle(display, window, gc, 0, 0, attr.width, attr.height);
			tsi = XSetForeground(display ,gc , black);
			for(i = 0; i != n; ++i)
			{
				err = mkfe_x_on_expose_row(fe, evt, attr.width, mk_lang_true, i); mk_lang_check_rereturn(err);
			}
			#if mk_clib_app_fe_posix_mallocatorg_statistics_have
			err = mk_lib_statistics_invalidate(); mk_lang_check_rereturn(err);
			#endif
		}
		else
		{
			i = evt->xexpose.y / line_height;
			i = mk_lang_min(i, n);
			n = mk_lang_min(n, i + mk_lang_div_roundup(evt->xexpose.height, line_height));
			for(; i != n; ++i)
			{
				err = mkfe_x_on_expose_row(fe, evt, attr.width, mk_lang_false, i); mk_lang_check_rereturn(err);
			}
		}
	}
	tsi = XFlush(display);
	if(fe->m_text_asc != fe->m_cur_asc || fe->m_text_des != fe->m_cur_des)
	{
		fe->m_text_asc = fe->m_cur_asc;
		fe->m_text_des = fe->m_cur_des;
		err = mkfe_x_invalidate_all(fe); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_keypress(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
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

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
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
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_buttonpress(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
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

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
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
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_delete(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	((mk_lang_types_void_t)(evt));
	fe->m_visible = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_clientmessage(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Atom wmdelete;

	mk_lang_assert(fe);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	err = mk_lib_x11_get_wmdelete(&wmdelete); mk_lang_check_rereturn(err);
	if(((Atom)(evt->xclient.data.l[0])) == wmdelete){ err = mkfe_x_on_delete(fe, evt); mk_lang_check_rereturn(err); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_pump_all_window_specific(mkfe_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	Display* display;
	Window window;
	mk_lang_types_slong_t mask;
	XEvent* evt;
	XEvent e;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(at_least_one);

	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
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
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_pump_global(mkfe_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
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
		err = mkfe_x_hide(fe); mk_lang_check_rereturn(err);
	}
	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	window = fe->m_window;
	evt = &e;
	gud = mk_lang_true;
	while(fe->m_visible && gud)
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
				err = mkfe_x_on_clientmessage(fe, evt); mk_lang_check_rereturn(err);
			}
		}
	}
	if(!fe->m_visible)
	{
		err = mkfe_x_hide(fe); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_pump(mkfe_pt const fe, mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(at_least_one);

	gud = mk_lang_true;
	while(gud)
	{
		gud = mk_lang_false;
		err = mkfe_x_pump_all_window_specific(fe, &gud); mk_lang_check_rereturn(err);
		err = mkfe_x_pump_global(fe, &gud); mk_lang_check_rereturn(err);
		if(gud)
		{
			*at_least_one = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_run(mkfe_pt const fe) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	Display* display;
	XEvent* evt;
	XEvent e;
	mk_lang_types_bool_t guda;
	mk_lang_types_bool_t gudb;
	mk_lang_types_sint_t tsi;

	err = mkfe_x_gather_root(fe); mk_lang_check_rereturn(err);
	err = mk_lib_x11_get_display(&display); mk_lang_check_rereturn(err);
	evt = &e;
	guda = mk_lang_true;
	while(fe->m_visible)
	{
		gudb = guda;
		guda = mk_lang_false;
		err = mkfe_x_pump(fe, &guda); mk_lang_check_rereturn(err);
		#if mk_clib_app_fe_posix_mallocatorg_statistics_have
		if(fe->m_visible){ err = mk_lib_statistics_x11_pump(&guda); mk_lang_check_rereturn(err); }
		#endif
		if(!guda && !gudb)
		{
			tsi = XNextEvent(display, evt); /* drop */
			guda = mk_lang_true;
		}
	}
	return 0;
}


mk_lang_types_sint_t main(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mkfe_t fe;

	err = mk_clib_app_fe_posix_mallocatorg_init(); mk_lang_check_rereturn(err);
	err = mk_lib_x11_init(); mk_lang_check_rereturn(err);
	#if mk_clib_app_fe_posix_mallocatorg_statistics_have
	err = mk_lib_statistics_init(); mk_lang_check_rereturn(err);
	#endif
	err = mkfe_x_init(&fe); mk_lang_check_rereturn(err);
	err = mkfe_x_run(&fe); mk_lang_check_rereturn(err);
	err = mkfe_x_deinit(&fe); mk_lang_check_rereturn(err);
	#if mk_clib_app_fe_posix_mallocatorg_statistics_have
	err = mk_lib_statistics_hide(); mk_lang_check_rereturn(err);
	err = mk_lib_statistics_deinit(); mk_lang_check_rereturn(err);
	#endif
	err = mk_lib_x11_deinit(); mk_lang_check_rereturn(err);
	err = mk_clib_app_fe_posix_mallocatorg_deinit(); mk_lang_check_rereturn(err);
	return 0;
}
