#ifndef mk_include_guard_mk_win_dll_kernel_process_h
#define mk_include_guard_mk_win_dll_kernel_process_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_process_get_current(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_wchar_lpt mk_win_dll_kernel_process_get_command_line(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_win_dll_kernel_process_exit(mk_lang_types_uint_t const exit_code) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_win_dll_kernel_process.c"
#endif
#endif
