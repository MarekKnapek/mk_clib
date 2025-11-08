#ifndef mk_include_guard_mk_win_dll_kernel_memory_management_c
#define mk_include_guard_mk_win_dll_kernel_memory_management_c
#include "mk_win_dll_kernel_memory_management.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_jumbo.h"
#include "mk_lang_extern.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_void_lpt mk_win_base_stdcall VirtualAlloc(mk_win_base_void_lpt const address, mk_win_base_usize_t const size, mk_win_base_dword_t const type, mk_win_base_dword_t const protection) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall VirtualFree(mk_win_base_void_lpt const address, mk_win_base_usize_t const size, mk_win_base_dword_t const type) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_void_lpt mk_win_dll_kernel_memory_management_virtual_alloc(mk_win_base_void_lpt const address, mk_win_base_usize_t const size, mk_win_base_dword_t const type, mk_win_base_dword_t const protection) mk_lang_noexcept
{
	mk_win_base_void_lpt ret;

	ret = VirtualAlloc(address, size, type, protection);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_memory_management_virtual_free(mk_win_base_void_lpt const address, mk_win_base_usize_t const size, mk_win_base_dword_t const type) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = VirtualFree(address, size, type);
	return ret;
}


#else
static void mk_win_dll_kernel_memory_management_dummy(void){}
#endif
#endif
