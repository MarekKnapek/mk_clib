#ifndef mk_include_guard_mk_lib_statistics
#define mk_include_guard_mk_lib_statistics


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_platform.h"
#include "mk_lib_x11_headers.h"


#if mk_lang_platform == mk_lang_platform_windows_61 || mk_lang_platform == mk_lang_platform_windows_60 || mk_lang_platform == mk_lang_platform_windows_51 || mk_lang_platform == mk_lang_platform_windows
#define mk_lib_statistics_evet_fn_args1 int msg, int wparam, int lparam /* todo */
#elif mk_lib_x11_headers_have
#define mk_lib_statistics_evet_fn_args1 XEvent* const evt
#else
#error todo xxxxxxxxxx
#endif


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_show(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_hide(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_invalidate(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_on_event(mk_lib_statistics_evet_fn_args1, mk_lang_types_bool_pt const consumed) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_statistics.c"
#endif
#endif
