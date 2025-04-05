#ifndef mk_include_guard_mk_win_dll_kernel_handle_c
#define mk_include_guard_mk_win_dll_kernel_handle_c
#include "mk_win_dll_kernel_handle.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CloseHandle(mk_win_base_handle_t const handle) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_handle_close(mk_win_base_handle_t const handle) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = CloseHandle(handle);
	return ret;
}


#endif
#endif
