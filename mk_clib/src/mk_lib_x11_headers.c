#include "mk_lib_x11_headers.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if !mk_lib_x11_headers_have


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t DefaultScreen(Display* const display) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo Bool XCheckWindowEvent(Display* const display, Window const window, mk_lang_types_slong_t const event_mask, XEvent* const evt) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(window));
	((mk_lang_types_void_t)(event_mask));
	((mk_lang_types_void_t)(evt));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_jumbo mk_lang_types_sint_t XCloseDisplay(Display* const display) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_jumbo mk_lang_types_sint_t XDrawRectangle(Display* const display, Drawable const drawable, GC const gc, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_uint_t const w, mk_lang_types_uint_t const h) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(drawable));
	((mk_lang_types_void_t)(gc));
	((mk_lang_types_void_t)(x));
	((mk_lang_types_void_t)(y));
	((mk_lang_types_void_t)(w));
	((mk_lang_types_void_t)(h));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_jumbo mk_lang_types_sint_t XDrawString(Display* const display, Drawable const drawable, GC const gc, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_pchar_pct const text, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(drawable));
	((mk_lang_types_void_t)(gc));
	((mk_lang_types_void_t)(x));
	((mk_lang_types_void_t)(y));
	((mk_lang_types_void_t)(text));
	((mk_lang_types_void_t)(len));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_jumbo mk_lang_types_sint_t XFillRectangle(Display* const display, Drawable const drawable, GC const gc, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_uint_t const w, mk_lang_types_uint_t const h) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(drawable));
	((mk_lang_types_void_t)(gc));
	((mk_lang_types_void_t)(x));
	((mk_lang_types_void_t)(y));
	((mk_lang_types_void_t)(w));
	((mk_lang_types_void_t)(h));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_jumbo mk_lang_types_sint_t XFlush(Display* const display) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo GContext XGContextFromGC(GC const gc) mk_lang_noexcept
{
	((mk_lang_types_void_t)(gc));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo Status XGetWindowAttributes(Display* const display, Window const window, XWindowAttributes* const attributes) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(window));
	((mk_lang_types_void_t)(attributes));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo Atom XInternAtom(Display* const display, mk_lang_types_pchar_pct const atom_name, Bool const only_if_exists) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(atom_name));
	((mk_lang_types_void_t)(only_if_exists));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo KeySym XLookupKeysym(XKeyEvent* const key_event, mk_lang_types_sint_t const index) mk_lang_noexcept
{
	((mk_lang_types_void_t)(key_event));
	((mk_lang_types_void_t)(index));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_jumbo mk_lang_types_sint_t XNextEvent(Display* const display, XEvent* const evt) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(evt));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo Display* XOpenDisplay(mk_lang_types_pchar_pct const display_name) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display_name));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_jumbo mk_lang_types_sint_t XPeekEvent(Display* const display, XEvent* const evt) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(evt));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_jumbo mk_lang_types_sint_t XQueryTextExtents(Display* const display, XID const font_id, mk_lang_types_pchar_pct const text, mk_lang_types_sint_t const len, mk_lang_types_sint_pt const direction, mk_lang_types_sint_pt const ascent, mk_lang_types_sint_pt const descent, XCharStruct* const overall) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(font_id));
	((mk_lang_types_void_t)(text));
	((mk_lang_types_void_t)(len));
	((mk_lang_types_void_t)(direction));
	((mk_lang_types_void_t)(ascent));
	((mk_lang_types_void_t)(descent));
	((mk_lang_types_void_t)(overall));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo Status XSendEvent(Display* const display, Window const window, Bool const propagate, mk_lang_types_slong_t const event_mask, XEvent* const evt) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(window));
	((mk_lang_types_void_t)(propagate));
	((mk_lang_types_void_t)(event_mask));
	((mk_lang_types_void_t)(evt));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_jumbo mk_lang_types_sint_t XSetForeground(Display* const display, GC const gc, mk_lang_types_ulong_t const foreground) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(gc));
	((mk_lang_types_void_t)(foreground));
	mk_lang_assert(mk_lang_false);
	return 0;
}

mk_lang_jumbo mk_lang_types_sint_t XUnmapWindow(Display* const display, Window const window) mk_lang_noexcept
{
	((mk_lang_types_void_t)(display));
	((mk_lang_types_void_t)(window));
	mk_lang_assert(mk_lang_false);
	return 0;
}


#endif
