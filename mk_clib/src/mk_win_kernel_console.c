#include "mk_win_kernel_console.h"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetConsoleCtrlHandler(mk_win_kernel_console_handler_lpt const handler, mk_win_base_bool_t const add) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall GetStdHandle(mk_win_base_dword_t const handle_id) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WriteConsoleA(mk_win_base_handle_t const handle, mk_win_base_pchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept;
mk_lang_extern_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WriteConsoleW(mk_win_base_handle_t const handle, mk_win_base_wchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_console_set_ctrl_handler(mk_win_kernel_console_handler_lpt const handler, mk_win_base_bool_t const add) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	mk_lang_assert(add == mk_win_base_false || add == mk_win_base_true);

	ret = SetConsoleCtrlHandler(handler, add);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_kernel_console_get_std_handle(mk_win_kernel_console_std_handle_id_t const handle_id) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = GetStdHandle(((mk_win_base_dword_t)(handle_id)));
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_console_a_write(mk_win_base_handle_t const handle, mk_win_base_pchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WriteConsoleA(handle, buff, len, nwritten, reserved);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_kernel_console_w_write(mk_win_base_handle_t const handle, mk_win_base_wchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WriteConsoleW(handle, buff, len, nwritten, reserved);
	return ret;
}
