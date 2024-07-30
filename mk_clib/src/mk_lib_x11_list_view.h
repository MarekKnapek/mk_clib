#ifndef mk_include_guard_mk_lib_x11_list_view
#define mk_include_guard_mk_lib_x11_list_view


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_x11_headers.h"


typedef mk_lang_types_void_pt mk_lib_x11_list_view_callctx_t;
typedef mk_lib_x11_list_view_callctx_t const mk_lib_x11_list_view_callctx_ct;
typedef mk_lib_x11_list_view_callctx_t* mk_lib_x11_list_view_callctx_pt;
typedef mk_lib_x11_list_view_callctx_t const* mk_lib_x11_list_view_callctx_pct;
#if mk_lang_version_at_least_cpp_17
typedef mk_lang_types_sint_t(*mk_lib_x11_list_view_callback_t)(mk_lib_x11_list_view_callctx_t const context, mk_lang_types_sint_t const idx, mk_lang_types_pchar_ppct const text, mk_lang_types_sint_pt const len) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_lang_types_sint_t mk_lib_x11_list_view_fn_dummy(mk_lib_x11_list_view_callctx_t const context, mk_lang_types_sint_t const idx, mk_lang_types_pchar_ppct const text, mk_lang_types_sint_pt const len) mk_lang_noexcept;
typedef decltype(&mk_lib_x11_list_view_fn_dummy) mk_lib_x11_list_view_callback_t;
#else
typedef mk_lang_types_sint_t(*mk_lib_x11_list_view_callback_t)(mk_lib_x11_list_view_callctx_t const context, mk_lang_types_sint_t const idx, mk_lang_types_pchar_ppct const text, mk_lang_types_sint_pt const len) mk_lang_noexcept;
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
	mk_lang_types_sint_t m_border;
	mk_lang_types_sint_t m_rows;
	mk_lang_types_sint_t m_auto_height;
	mk_lang_types_sint_t m_idx;
	mk_lib_x11_list_view_callback_t m_callback;
	mk_lib_x11_list_view_callctx_t m_context;
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
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_border(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const border) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_border(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const border) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_dimensions(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const x, mk_lang_types_sint_pt const y, mk_lang_types_sint_pt const w, mk_lang_types_sint_pt const h) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_dimensions(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const x, mk_lang_types_sint_t const y, mk_lang_types_sint_t const w, mk_lang_types_sint_t const h) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_rows(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const rows) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_rows(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const rows) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_auto_height(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const auto_height) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_auto_height(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const auto_height) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_idx(mk_lib_x11_list_view_pct const list_view, mk_lang_types_sint_pt const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_idx(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_ro_get_callback(mk_lib_x11_list_view_pct const list_view, mk_lib_x11_list_view_callback_pt const callback, mk_lib_x11_list_view_callctx_pt const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_set_callback(mk_lib_x11_list_view_pt const list_view, mk_lib_x11_list_view_callback_t const callback, mk_lib_x11_list_view_callctx_t const context) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_invalidate_row(mk_lib_x11_list_view_pt const list_view, mk_lang_types_sint_t const idx) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_invalidate_all(mk_lib_x11_list_view_pt const list_view) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_x11_list_view_rw_on_event(mk_lib_x11_list_view_pt const list_view, XEvent* const evt, mk_lang_types_bool_pt const consumed) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_x11_list_view.c"
#endif
#endif
