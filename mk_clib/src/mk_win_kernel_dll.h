#ifndef mk_include_guard_mk_win_kernel_dll
#define mk_include_guard_mk_win_kernel_dll


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


enum mk_win_kernel_dll_get_module_handle_ex_flags_e
{
	mk_win_kernel_dll_get_module_handle_ex_flags_e_pin                = 0x00000001,
	mk_win_kernel_dll_get_module_handle_ex_flags_e_unchanged_refcount = 0x00000002,
	mk_win_kernel_dll_get_module_handle_ex_flags_e_from_address       = 0x00000004,
	mk_win_kernel_dll_get_module_handle_ex_flags_e_dummy_end
};
typedef enum mk_win_kernel_dll_get_module_handle_ex_flags_e mk_win_kernel_dll_get_module_handle_ex_flags_t;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_module_t mk_win_kernel_dll_a_get_module_handle(mk_win_base_pchar_lpct const module_name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_module_t mk_win_kernel_dll_w_get_module_handle(mk_win_base_wchar_lpct const module_name) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_dll_w_get_module_handle_ex(mk_win_base_dword_t const flags, mk_win_base_wchar_lpct const module_name, mk_win_base_module_pt const module) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_dll.c"
#endif
#endif
