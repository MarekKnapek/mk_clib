#ifndef mk_include_guard_mk_lib_x11_list_view
#define mk_include_guard_mk_lib_x11_list_view


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_static_param.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if mk_lang_platform_x11_have == 1
#else
struct Display{ mk_lang_types_sint_t m_dummy; }; typedef struct Display Display;
struct Window { mk_lang_types_sint_t m_dummy; }; typedef struct Window  Window ;
struct GC     { mk_lang_types_sint_t m_dummy; }; typedef struct GC      GC     ;
typedef Window Drawable;
#endif


#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_sint_t(*mk_lib_x11_list_view_callback_t)(mk_lang_types_sint_t const idx, mk_lang_types_pchar_ppct const text, mk_lang_types_sint_pt const len) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_types_sint_t mk_lib_x11_list_view_fn_dummy(mk_lang_types_sint_t const idx, mk_lang_types_pchar_ppct const text, mk_lang_types_sint_pt const len) mk_lang_noexcept;
typedef decltype(&mk_lib_x11_list_view_fn_dummy) mk_lib_x11_list_view_callback_t;
#else
typedef mk_lang_types_sint_t(*mk_lib_x11_list_view_callback_t)(mk_lang_types_sint_t const idx, mk_lang_types_pchar_ppct const text, mk_lang_types_sint_pt const len) mk_lang_noexcept;
#endif
typedef mk_lib_x11_list_view_callback_t const mk_lib_x11_list_view_callback_ct;
typedef mk_lib_x11_list_view_callback_t* mk_lib_x11_list_view_callback_pt;
typedef mk_lib_x11_list_view_callback_t const* mk_lib_x11_list_view_callback_pct;


struct mk_lib_x11_list_view_s
{
	mk_lang_types_sint_t m_x;
	mk_lang_types_sint_t m_y;
	mk_lang_types_sint_t m_w;
	mk_lang_types_sint_t m_h;
	mk_lang_types_sint_t m_rows;
	mk_lib_x11_list_view_callback_t m_callback;
	Display* m_display;
	Window m_window;
	GC m_gc;
	mk_lang_types_sint_t m_text_asc;
	mk_lang_types_sint_t m_text_des;
};
typedef struct mk_lib_x11_list_view_s mk_lib_x11_list_view_t;
typedef mk_lib_x11_list_view_t const mk_lib_x11_list_view_ct;
typedef mk_lib_x11_list_view_t* mk_lib_x11_list_view_pt;
typedef mk_lib_x11_list_view_t const* mk_lib_x11_list_view_pct;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_construct(mk_lib_x11_list_view_pt const list_view, Display* const display, Window const window, GC const gc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_destruct(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_dimensions(mk_lib_x11_list_view_pct const list_view, mk_lang_static_param(mk_lang_types_sint_t, dimensions, 4)) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_dimensions(mk_lib_x11_list_view_pt const list_view, mk_lang_static_param(mk_lang_types_sint_ct, dimensions, 4)) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_rows(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const rows) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_rows(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const rows) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_callback(mk_lib_x11_list_view_pct const list_view, mk_lib_x11_list_view_callback_pt const callback) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_callback(mk_lib_x11_list_view_pt const list_view, mk_lib_x11_list_view_callback_t const callback) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_on_expose(mk_lib_x11_list_view_pct const list_view, mk_lang_static_param(mk_lang_types_sint_ct, dimensions, 4)) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_x11_list_view.c"
#endif
#endif
