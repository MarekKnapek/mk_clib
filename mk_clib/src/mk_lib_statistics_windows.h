#ifndef mk_include_guard_mk_lib_statistics_windows
#define mk_include_guard_mk_lib_statistics_windows


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_show(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_hide(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_invalidate(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_statistics_windows_pump(mk_lang_types_bool_pt const at_least_one) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lib_statistics_windows.c"
#endif
#endif
