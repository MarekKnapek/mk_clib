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
