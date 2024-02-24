#include "mk_win_kernel_time.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall GetTickCount(void) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import void mk_win_base_stdcall GetSystemTime(mk_win_kernel_time_system_time_lpt) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SystemTimeToFileTime(mk_win_kernel_time_system_time_lpct, mk_win_kernel_time_file_time_lpt) mk_lang_noexcept;
mk_lang_extern_c mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall FileTimeToSystemTime(mk_win_kernel_time_file_time_lpct, mk_win_kernel_time_system_time_lpt) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_kernel_time_get_tick_count(void) mk_lang_noexcept
{
	mk_win_base_dword_t gtc;

	gtc = GetTickCount();
	return gtc;
}

mk_lang_jumbo void mk_win_kernel_time_get_system_time(mk_win_kernel_time_system_time_lpt const system_time) mk_lang_noexcept
{
	mk_lang_assert(system_time);

	GetSystemTime(system_time);
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_time_system_to_file_time(mk_win_kernel_time_system_time_pct const system_time, mk_win_kernel_time_file_time_pt const file_time) mk_lang_noexcept
{
	mk_win_base_bool_t converted;

	mk_lang_assert(system_time);
	mk_lang_assert(file_time);

	converted = SystemTimeToFileTime(system_time, file_time);
	return converted;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_time_file_to_system_time(mk_win_kernel_time_file_time_pct const file_time, mk_win_kernel_time_system_time_pt const system_time) mk_lang_noexcept
{
	mk_win_base_bool_t converted;

	mk_lang_assert(file_time);
	mk_lang_assert(system_time);

	converted = FileTimeToSystemTime(file_time, system_time);
	return converted;
}
