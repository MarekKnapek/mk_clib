#ifndef mk_include_guard_win_kernel_dll
#define mk_include_guard_win_kernel_dll


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"
#include "mk_win_tstring.h"
#include "mk_win_tstring.h"


enum mk_win_kernel_dll_get_handle_ex_e
{
	mk_win_kernel_dll_get_handle_ex_e_pin                = 0x00000001,
	mk_win_kernel_dll_get_handle_ex_e_unchanged_refcount = 0x00000002,
	mk_win_kernel_dll_get_handle_ex_e_from_address       = 0x00000004,
	mk_win_kernel_dll_get_handle_ex_e_dummy_end = 0
};
typedef enum mk_win_kernel_dll_get_handle_ex_e mk_win_kernel_dll_get_handle_ex_t;


struct mk_win_kernel_dll_module_handle_s; typedef struct mk_win_kernel_dll_module_handle_s mk_win_kernel_dll_module_handle_t; typedef mk_win_kernel_dll_module_handle_t const* mk_win_kernel_dll_module_t;
typedef mk_win_kernel_dll_module_t const mk_win_kernel_dll_module_ct;
typedef mk_win_kernel_dll_module_t* mk_win_kernel_dll_module_pt;
typedef mk_win_kernel_dll_module_t const* mk_win_kernel_dll_module_pct;
typedef mk_win_kernel_dll_module_t mk_win_base_far* mk_win_kernel_dll_module_lpt;
typedef mk_win_kernel_dll_module_t mk_win_base_far const* mk_win_kernel_dll_module_lpct;
typedef mk_win_kernel_dll_module_t mk_win_base_near* mk_win_kernel_dll_module_npt;
typedef mk_win_kernel_dll_module_t mk_win_base_near const* mk_win_kernel_dll_module_npct;


mk_lang_nodiscard mk_lang_jumbo mk_win_kernel_dll_module_t mk_win_kernel_dll_a_get_handle(mk_win_base_pchar_lpct const name) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_dll_a_get_handle_ex(mk_win_kernel_dll_get_handle_ex_t const flags, mk_win_base_pchar_lpct const name, mk_win_kernel_dll_module_lpt const module) mk_lang_noexcept;

mk_lang_jumbo mk_win_kernel_dll_module_t mk_win_kernel_dll_w_get_handle(mk_win_base_wchar_lpct const name) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_dll_w_get_handle_ex(mk_win_kernel_dll_get_handle_ex_t const flags, mk_win_base_wchar_lpct const name, mk_win_kernel_dll_module_lpt const module) mk_lang_noexcept;

mk_lang_jumbo mk_win_kernel_dll_module_t mk_win_kernel_dll_t_get_handle(mk_win_tstring_tchar_lpct const name) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_dll_t_get_handle_ex(mk_win_kernel_dll_get_handle_ex_t const flags, mk_win_tstring_tchar_lpct const name, mk_win_kernel_dll_module_lpt const module) mk_lang_noexcept;
mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_dll_t_get_handle_from_address(mk_win_base_void_lpct const address, mk_win_kernel_dll_module_lpt const module) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_win_base_proc_t mk_win_kernel_dll_get_proc_address(mk_win_kernel_dll_module_t const module, mk_win_base_pchar_lpct const name) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_win_kernel_dll.c"
#endif
#endif
