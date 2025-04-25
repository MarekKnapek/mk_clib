#ifndef mk_include_guard_mk_win_dll_kernel_handle_h
#define mk_include_guard_mk_win_dll_kernel_handle_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_handle_close(mk_win_base_handle_t const handle) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_win_dll_kernel_handle.c"
#endif
#endif
