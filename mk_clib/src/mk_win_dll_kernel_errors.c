#ifndef mk_include_guard_mk_win_dll_kernel_errors_c
#define mk_include_guard_mk_win_dll_kernel_errors_c
#include "mk_win_dll_kernel_errors.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetLastError(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_force_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall SetLastError(mk_win_base_dword_t const err) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_uint_t mk_win_base_stdcall SetErrorMode(mk_win_base_uint_t const errmode) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_errors_get_last(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetLastError();
	return ret;
}

mk_lang_jumbo mk_lang_types_void_t mk_win_dll_kernel_errors_set_last(mk_win_base_dword_t const err) mk_lang_noexcept
{
	SetLastError(err);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_uint_t mk_win_dll_kernel_errors_set_errmode(mk_win_base_uint_t const errmode) mk_lang_noexcept
{
	mk_win_base_uint_t ret;

	ret = SetErrorMode(errmode);
	return ret;
}


#else
static void mk_win_dll_kernel_errors_dummy(void){}
#endif
#endif
