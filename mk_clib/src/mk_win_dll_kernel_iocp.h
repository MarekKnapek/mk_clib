#ifndef mk_include_guard_mk_win_dll_kernel_iocp_h
#define mk_include_guard_mk_win_dll_kernel_iocp_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_win_base_make_handle(mk_win_dll_kernel_iocp);


mk_lang_nodiscard mk_lang_jumbo mk_win_dll_kernel_iocp_t mk_win_dll_kernel_iocp_create(mk_win_base_handle_t const file, mk_win_dll_kernel_iocp_t const existing_iocp, mk_win_base_uintptr_t const key, mk_win_base_dword_t const concurrency) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_iocp_get_status(mk_win_dll_kernel_iocp_t const iocp, mk_win_base_dword_lpt const bytes_transfered, mk_win_base_uintptr_lpt const key, mk_win_base_void_lplpt const overlapped, mk_win_base_dword_t const timeout) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_iocp_post(mk_win_dll_kernel_iocp_t const iocp, mk_win_base_dword_t const bytes_transfered, mk_win_base_uintptr_t const key, mk_win_base_void_lpt  const overlapped) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_win_dll_kernel_iocp.c"
#endif
#endif
