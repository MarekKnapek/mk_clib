#include "mk_lib_x11.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"


#if mk_lang_platform_x11_have == 1


#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>


struct mk_lib_x11_s
{
	Display* m_display;
};
typedef struct mk_lib_x11_s mk_lib_x11_t;
typedef mk_lib_x11_t const mk_lib_x11_ct;
typedef mk_lib_x11_t* mk_lib_x11_pt;
typedef mk_lib_x11_t const* mk_lib_x11_pct;


static mk_lib_x11_t g_mk_lib_x11;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_x11_pt x11;
	Display* display;

	x11 = &g_mk_lib_x11;
	display = XOpenDisplay(mk_lang_null); mk_lang_check_return(display);
	x11->m_display = display;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lib_x11_pt x11;
	Display* display;
	mk_lang_types_sint_t tsi;

	x11 = &g_mk_lib_x11;
	display = x11->m_display;
	tsi = XCloseDisplay(display);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_get(Display** const display) mk_lang_noexcept
{
	mk_lib_x11_pt x11;
	Display* dspl;
	mk_lang_types_sint_t tsi;

	mk_lang_assert(display);

	x11 = &g_mk_lib_x11;
	dspl = x11->m_display;
	*display = dspl;
	return 0;
}


#endif
