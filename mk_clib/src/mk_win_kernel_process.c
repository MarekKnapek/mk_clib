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
	mk_win_base_handle_t ret;

	ret = GetCurrentProcess();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_wchar_lpt mk_win_kernel_process_get_command_line(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_wchar_lpt ret;

	ret = GetCommandLineW();
	return ret;
}
