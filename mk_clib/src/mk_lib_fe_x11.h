#ifndef mk_include_guard_mk_lib_fe_x11
#define mk_include_guard_mk_lib_fe_x11


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_x11_headers.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_show(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_hide(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_is_hidden(mk_lang_types_bool_pt const is_hidden) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_invalidate_all(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_fe_x11_on_event(XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_fe_x11.c"
#endif
#endif
