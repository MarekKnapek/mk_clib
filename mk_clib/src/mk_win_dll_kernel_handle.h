#ifndef mk_include_guard_mk_win_dll_kernel_handle_h
#define mk_include_guard_mk_win_dll_kernel_handle_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


#define mk_win_dll_kernel_handle_duplicate_close_source 0x00000001
#define mk_win_dll_kernel_handle_duplicate_same_access  0x00000002


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_handle_close(mk_win_base_handle_t const handle) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_handle_duplicate(mk_win_base_handle_t const src_process, mk_win_base_handle_t const src_handle, mk_win_base_handle_t const dst_process, mk_win_base_handle_lpt const dst_handle, mk_win_base_dword_t const desired_access, mk_win_base_bool_t const inheritable, mk_win_base_dword_t const flags) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_win_dll_kernel_handle.c"
#endif
#endif
