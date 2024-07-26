#ifndef mk_include_guard_mk_lib_x11
#define mk_include_guard_mk_lib_x11


#include "mk_lang_platform.h"


#if mk_lang_platform_x11_have == 1


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_get_display(Display** const display) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_get_wmdelete(Atom* const wmdelete) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_want == 1
#include "mk_lib_x11.c"
#endif
#endif
