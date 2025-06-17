#ifndef mk_include_guard_mk_win_dll_kernel_time_c
#define mk_include_guard_mk_win_dll_kernel_time_c
#include "mk_win_dll_kernel_time.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_jumbo.h"
#include "mk_lang_extern.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetTickCount(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_force_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall GetSystemTime(mk_win_dll_kernel_time_system_time_lpt const system_time) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SystemTimeToFileTime(mk_win_dll_kernel_time_system_time_lpct const system_time, mk_win_dll_kernel_time_file_time_lpt const file_time) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FileTimeToSystemTime(mk_win_dll_kernel_time_file_time_lpct const file_time, mk_win_dll_kernel_time_system_time_lpt const system_time) mk_lang_noexcept;
mk_lang_extern_force_c mk_win_base_dll_import mk_lang_types_void_t mk_win_base_stdcall GetSystemTimePreciseAsFileTime(mk_win_dll_kernel_time_file_time_lpt const file_time) mk_lang_noexcept; /* since Windows 8 and Windows Server 2012 */


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_kernel_time_get_tick_count(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = GetTickCount();
	return ret;
}

mk_lang_jumbo mk_lang_types_void_t mk_win_dll_kernel_time_get_system_time(mk_win_dll_kernel_time_system_time_lpt const system_time) mk_lang_noexcept
{
	GetSystemTime(system_time);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_time_system_to_file_time(mk_win_dll_kernel_time_system_time_lpct const system_time, mk_win_dll_kernel_time_file_time_lpt const file_time) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SystemTimeToFileTime(system_time, file_time);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_time_file_to_system_time(mk_win_dll_kernel_time_file_time_lpct const file_time, mk_win_dll_kernel_time_system_time_lpt const system_time) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = FileTimeToSystemTime(file_time, system_time);
	return ret;
}

mk_lang_jumbo mk_lang_types_void_t mk_win_dll_kernel_time_get_system_time_precise_as_file_time(mk_win_dll_kernel_time_file_time_lpt const file_time) mk_lang_noexcept
{
	GetSystemTimePreciseAsFileTime(file_time);
}


#else
static void mk_win_dll_kernel_time_dummy(void){}
#endif
#endif
