#include "mk_win_kernel_process.h"

#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall GetCurrentProcess(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_wchar_lpt mk_win_base_stdcall GetCommandLineW(mk_lang_types_void_t) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_process_get_current(mk_lang_types_void_t) mk_lang_noexcept
{
#if defined NDEBUG
	mk_win_base_handle_t ret;

	ret.m_data = ((mk_win_base_void_pct)(((mk_lang_types_uintptr_t)(((mk_lang_types_sintptr_t)(((mk_lang_types_sint_t)(-1))))))));
	return ret;
#else
	mk_win_base_handle_t ret;

	ret = GetCurrentProcess();
	return ret;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_wchar_lpt mk_win_kernel_process_get_command_line(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_wchar_lpt ret;

	ret = GetCommandLineW();
	return ret;
}
