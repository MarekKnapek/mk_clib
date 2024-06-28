#ifndef mk_include_guard_mk_win_kernel_thread
#define mk_include_guard_mk_win_kernel_thread


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_win_advapi_types.h"
#include "mk_win_base.h"


#if mk_lang_version_at_least_cpp_17
typedef mk_win_base_dword_t(mk_win_base_stdcall*mk_win_kernel_thread_callback_t)(mk_win_base_void_lpt const parameter) mk_lang_noexcept;
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
mk_win_base_dword_t mk_win_base_stdcall mk_win_kernel_thread_dummy(mk_win_base_void_lpt const parameter) mk_lang_noexcept;
typedef decltype(&mk_win_kernel_thread_dummy) mk_win_kernel_thread_callback_t;
#else
typedef mk_win_base_dword_t(mk_win_base_stdcall*mk_win_kernel_thread_callback_t)(mk_win_base_void_lpt const parameter) mk_lang_noexcept;
#endif


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_thread_get_current(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_thread_create(mk_win_advapi_base_security_attributes_lpct const sa, mk_win_base_usize_t const stack_len, mk_win_kernel_thread_callback_t const callback, mk_win_base_void_lpt const parameter, mk_win_base_dword_t const flags, mk_win_base_dword_lpt const tid) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_thread.c"
#endif
#endif
