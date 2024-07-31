#include "mk_lib_x11_cong.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_x11_headers.h"


struct mk_lib_x11_cong_s
{
	Display* m_display;
	mk_lang_types_sint_t m_screen;
	Window m_rootw;
	mk_lang_types_ulong_t m_black;
	mk_lang_types_ulong_t m_white;
	Atom m_wmdelete;
	mk_lib_x11_cong_window_pt m_windows;
};
typedef struct mk_lib_x11_cong_s mk_lib_x11_cong_t;
typedef mk_lib_x11_cong_t const mk_lib_x11_cong_ct;
typedef mk_lib_x11_cong_t* mk_lib_x11_cong_pt;
typedef mk_lib_x11_cong_t const* mk_lib_x11_cong_pct;


static mk_lib_x11_cong_t g_mk_lib_x11_cong;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	Display* display;
	mk_lang_types_sint_t screen;
	Window rootw;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	Atom wmdelete;

	x11_cong = &g_mk_lib_x11_cong;
	display = XOpenDisplay(mk_lang_null); mk_lang_check_return(display);
	screen = DefaultScreen(display);
	rootw = RootWindow(display, screen);
	black = BlackPixel(display, screen);
	white = WhitePixel(display, screen);
	wmdelete = XInternAtom(display, "WM_DELETE_WINDOW", False);
	x11_cong->m_display = display;
	x11_cong->m_screen = screen;
	x11_cong->m_rootw = rootw;
	x11_cong->m_black = black;
	x11_cong->m_white = white;
	x11_cong->m_wmdelete = wmdelete;
	x11_cong->m_windows = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	Display* display;
	mk_lang_types_sint_t tsi;

	x11_cong = &g_mk_lib_x11_cong;
	display = x11_cong->m_display;
	tsi = XCloseDisplay(display);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_display(Display** const display_out) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	Display* display;

	mk_lang_assert(display_out);

	x11_cong = &g_mk_lib_x11_cong;
	display = x11_cong->m_display;
	*display_out = display;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_default_screen_value(mk_lang_types_sint_pt const screen_out) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	mk_lang_types_sint_t screen;

	mk_lang_assert(screen_out);

	x11_cong = &g_mk_lib_x11_cong;
	screen = x11_cong->m_screen;
	*screen_out = screen;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_default_screen_rootw(Window* const rootw_out) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	mk_lang_types_ulong_t rootw;

	mk_lang_assert(rootw_out);

	x11_cong = &g_mk_lib_x11_cong;
	rootw = x11_cong->m_rootw;
	*rootw_out = rootw;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_default_screen_black(mk_lang_types_ulong_pt const black_out) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	mk_lang_types_ulong_t black;

	mk_lang_assert(black_out);

	x11_cong = &g_mk_lib_x11_cong;
	black = x11_cong->m_black;
	*black_out = black;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_default_screen_white(mk_lang_types_ulong_pt const white_out) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	mk_lang_types_ulong_t white;

	mk_lang_assert(white_out);

	x11_cong = &g_mk_lib_x11_cong;
	white = x11_cong->m_white;
	*white_out = white;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_set_default_screen_black(mk_lang_types_ulong_t const black) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;

	x11_cong = &g_mk_lib_x11_cong;
	x11_cong->m_black = black;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_set_default_screen_white(mk_lang_types_ulong_t const white) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;

	x11_cong = &g_mk_lib_x11_cong;
	x11_cong->m_white = white;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_wmdelete(Atom* const wmdelete) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	Atom wmdlt;

	mk_lang_assert(wmdelete);

	x11_cong = &g_mk_lib_x11_cong;
	wmdlt = x11_cong->m_wmdelete;
	*wmdelete = wmdlt;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_window_register(mk_lib_x11_cong_window_pt const window) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;

	mk_lang_assert(window);

	x11_cong = &g_mk_lib_x11_cong;
	window->m_next = mk_lang_null;
	window->m_prev = mk_lang_null;
	if(x11_cong->m_windows)
	{
		mk_lang_assert(!x11_cong->m_windows->m_prev);
		window->m_next = x11_cong->m_windows;
		x11_cong->m_windows->m_prev = window;
	}
	x11_cong->m_windows = window;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_window_unregister(mk_lib_x11_cong_window_pt const window) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;

	mk_lang_assert(window);
	mk_lang_assert(window->m_next || window->m_prev || g_mk_lib_x11_cong.m_windows == window);

	x11_cong = &g_mk_lib_x11_cong;
	if(window->m_next){ window->m_next->m_prev = window->m_prev; }
	if(window->m_prev){ window->m_prev->m_next = window->m_next; }
	if(x11_cong->m_windows == window)
	{
		x11_cong->m_windows = window->m_next;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_pr_invalidate(mk_lib_x11_cong_window_pt const window) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	Display* display;
	Window w;
	Status st;
	XWindowAttributes attr;
	XEvent* evt;
	XEvent e;

	mk_lang_assert(window);

	x11_cong = &g_mk_lib_x11_cong;
	display = x11_cong->m_display;
	w = window->m_window;
	st = XGetWindowAttributes(display, w, &attr);
	evt = &e;
	evt->type = Expose;
	evt->xexpose.type = Expose;
	evt->xexpose.serial = 0;
	evt->xexpose.send_event = True;
	evt->xexpose.display = display;
	evt->xexpose.window = w;
	evt->xexpose.x = 0;
	evt->xexpose.y = 0;
	evt->xexpose.width = attr.width;
	evt->xexpose.height = attr.height;
	evt->xexpose.count = 0;
	st = XSendEvent(display, w, False, ExposureMask, evt);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_windows_refresh(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	mk_lib_x11_cong_window_pt window;
	mk_lang_types_sint_t err;

	x11_cong = &g_mk_lib_x11_cong;
	window = x11_cong->m_windows;
	while(window)
	{
		err = mk_lib_x11_cong_pr_invalidate(window); mk_lang_check_rereturn(err);
		window = window->m_next;
	}
	return 0;
}
