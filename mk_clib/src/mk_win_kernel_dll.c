#include "mk_win_kernel_dll.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_module_t mk_win_base_stdcall GetModuleHandleA(mk_win_base_pchar_lpct const module_name) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_module_t mk_win_base_stdcall GetModuleHandleW(mk_win_base_wchar_lpct const module_name) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetModuleHandleExW(mk_win_base_dword_t const flags, mk_win_base_wchar_lpct const module_name, mk_win_base_module_pt const module) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_module_t mk_win_kernel_dll_a_get_module_handle(mk_win_base_pchar_lpct const module_name) mk_lang_noexcept
{
	mk_win_base_module_t ret;

	ret = GetModuleHandleA(module_name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_module_t mk_win_kernel_dll_w_get_module_handle(mk_win_base_wchar_lpct const module_name) mk_lang_noexcept
{
	mk_win_base_module_t ret;

	ret = GetModuleHandleW(module_name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_dll_w_get_module_handle_ex(mk_win_base_dword_t const flags, mk_win_base_wchar_lpct const module_name, mk_win_base_module_pt const module) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetModuleHandleExW(flags, module_name, module);
	return ret;
}
