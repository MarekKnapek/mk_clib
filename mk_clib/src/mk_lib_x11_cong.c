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
	Atom wmdelete;

	x11_cong = &g_mk_lib_x11_cong;
	display = XOpenDisplay(mk_lang_null); mk_lang_check_return(display);
	wmdelete = XInternAtom(display, "WM_DELETE_WINDOW", False);
	x11_cong->m_display = display;
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_cong_get_display(Display** const display) mk_lang_noexcept
{
	mk_lib_x11_cong_pt x11_cong;
	Display* dspl;

	mk_lang_assert(display);

	x11_cong = &g_mk_lib_x11_cong;
	dspl = x11_cong->m_display;
	*display = dspl;
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
