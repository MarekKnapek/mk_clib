#include "src/mk_lang_bool.h"
#include "src/mk_lang_assert.h"
#include "src/mk_lang_check.h"
#include "src/mk_lang_countof.h"
#include "src/mk_lang_inline.h"
#include "src/mk_lang_nodiscard.h"
#include "src/mk_lang_noexcept.h"
#include "src/mk_lang_null.h"
#include "src/mk_lang_types.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>


struct mkfe_s
{
	Display* m_display;
	mk_lang_types_sint_t m_screen;
	mk_lang_types_ulong_t m_black;
	mk_lang_types_ulong_t m_white;
	Window m_window;
	Atom m_wmdelete;
	GC m_gc;
	mk_lang_types_bool_t m_keep_running;
};
typedef struct mkfe_s mkfe_t;
typedef mkfe_t const mkfe_ct;
typedef mkfe_t* mkfe_pt;
typedef mkfe_t const* mkfe_pct;


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_init(mkfe_pt const fe) mk_lang_noexcept
{
	Display* display;
	mk_lang_types_sint_t screen;
	mk_lang_types_ulong_t black;
	mk_lang_types_ulong_t white;
	Window parent;
	Window window;
	mk_lang_types_sint_t tsi;
	Atom wmdelete;
	GC gc;

	mk_lang_assert(fe);

	display = XOpenDisplay(mk_lang_null); mk_lang_check_return(display);
	screen = DefaultScreen(display);
	black = BlackPixel(display, screen);
	white = WhitePixel(display, screen);
	parent = RootWindow(display, screen);
	window = XCreateSimpleWindow(display, parent, 0, 0, 320, 200, 5, black, white);
	tsi = XSetStandardProperties(display, window, "mkfe", mk_lang_null, None, mk_lang_null, 0, mk_lang_null);
	wmdelete = XInternAtom(display, "WM_DELETE_WINDOW", False);
	tsi = XSetWMProtocols(display, window, &wmdelete, 1);
	tsi = XSelectInput(display, window, ExposureMask | ButtonPressMask | KeyPressMask);
	gc = XCreateGC(display, window, 0, 0);
	tsi = XSetBackground(display, gc, white);
	tsi = XSetForeground(display ,gc , black);
	tsi = XClearWindow(display, window);
	tsi = XMapRaised(display, window);
	fe->m_display = display;
	fe->m_screen = screen;
	fe->m_black = black;
	fe->m_white = white;
	fe->m_window = window;
	fe->m_wmdelete = wmdelete;
	fe->m_gc = gc;
	fe->m_keep_running = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_deinit(mkfe_pt const fe) mk_lang_noexcept
{
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_display);

	display = fe->m_display;
	window = fe->m_window;
	gc = fe->m_gc;
	tsi = XFreeGC(display, gc);
	tsi = XDestroyWindow(display, window);
	tsi = XCloseDisplay(display);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_expose(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	Display* display;
	Window window;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_display);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == Expose);

	((mk_lang_types_void_t)(evt));
	display = fe->m_display;
	window = fe->m_window;
	if(evt->xexpose.count == 0)
	{
		tsi = XClearWindow(display, window);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_keypress(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_types_pchar_t text[8];
	KeySym key;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_display);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == KeyPress);

	if(XLookupString(&evt->xkey, &text[0], mk_lang_countof(text), &key, 0) == 1)
	{
		if(text[0] == 'q')
		{
			fe->m_keep_running = mk_lang_false;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_buttonpress(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	Display* display;
	Window window;
	GC gc;
	mk_lang_types_sint_t x;
	mk_lang_types_sint_t y;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_display);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ButtonPress);

	display = fe->m_display;
	window = fe->m_window;
	gc = fe->m_gc;
	x = evt->xbutton.x;
	y = evt->xbutton.y;
	tsi = XDrawString(display, window, gc, x, y, "test", mk_lang_countstr("test"));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_delete(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_assert(fe);
	mk_lang_assert(fe->m_display);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);
	mk_lang_assert(evt->xclient.data.l[0] == fe->m_wmdelete);
	mk_lang_assert(evt->xdestroywindow.event == fe->m_window);

	((mk_lang_types_void_t)(evt));
	fe->m_keep_running = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_on_clientmessage(mkfe_pt const fe, XEvent* const evt) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_display);
	mk_lang_assert(evt);
	mk_lang_assert(evt->type == ClientMessage);

	if(evt->xclient.data.l[0] == fe->m_wmdelete){ err = mkfe_x_on_delete(fe, evt); mk_lang_check_rereturn(err); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mkfe_x_run(mkfe_pt const fe) mk_lang_noexcept
{
	Display* display;
	XEvent* evt;
	XEvent e;
	mk_lang_types_sint_t tsi;
	mk_lang_types_sint_t err;

	mk_lang_assert(fe);
	mk_lang_assert(fe->m_display);

	display = fe->m_display;
	evt = &e;
	while(fe->m_keep_running)
	{
		tsi = XNextEvent(display, evt);
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


mk_lang_types_sint_t main(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mkfe_t fe;

	err = mkfe_x_init(&fe); mk_lang_check_rereturn(err);
	err = mkfe_x_run(&fe); mk_lang_check_rereturn(err);
	err = mkfe_x_deinit(&fe); mk_lang_check_rereturn(err);
	return 0;
}
