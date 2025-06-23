#ifndef mk_include_guard_mk_win_dll_kernel_console_c
#define mk_include_guard_mk_win_dll_kernel_console_c
#include "mk_win_dll_kernel_console.h"


#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any


#include "mk_lang_assert.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


#if mk_lang_msvc_ver != 0
#pragma comment(lib, "kernel32.lib")
#endif


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetConsoleCtrlHandler(mk_win_dll_kernel_console_handler_t const handler, mk_win_base_bool_t const add) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall GetStdHandle(mk_win_base_dword_t const handle_id) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetConsoleMode(mk_win_base_handle_t const handle, mk_win_base_dword_lpt const mode) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WriteConsoleA(mk_win_base_handle_t const handle, mk_win_base_pchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WriteConsoleW(mk_win_base_handle_t const handle, mk_win_base_wchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall GetConsoleScreenBufferInfo(mk_win_base_handle_t const handle, mk_win_dll_kernel_console_console_screen_buffer_info_lpt const console_screen_buffer_info) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetConsoleTextAttribute(mk_win_base_handle_t const handle, mk_win_base_word_t const attributes) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_set_ctrl_handler(mk_win_dll_kernel_console_handler_t const handler, mk_win_base_bool_t const add) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SetConsoleCtrlHandler(handler, add);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_console_get_std_handle(mk_win_dll_kernel_console_std_handle_id_t const handle_id) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = GetStdHandle(((mk_win_base_dword_t)(handle_id)));
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_get_mode(mk_win_base_handle_t const handle, mk_win_base_dword_lpt const mode) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetConsoleMode(handle, mode);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_a_write(mk_win_base_handle_t const handle, mk_win_base_pchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WriteConsoleA(handle, buff, len, nwritten, reserved);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_w_write(mk_win_base_handle_t const handle, mk_win_base_wchar_lpct const buff, mk_win_base_dword_t const len, mk_win_base_dword_lpt const nwritten, mk_win_base_void_lpt const reserved) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WriteConsoleW(handle, buff, len, nwritten, reserved);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_get_console_screen_buffer_info(mk_win_base_handle_t const handle, mk_win_dll_kernel_console_console_screen_buffer_info_pt const console_screen_buffer_info) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = GetConsoleScreenBufferInfo(handle, console_screen_buffer_info);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_console_set_console_text_attribute(mk_win_base_handle_t const handle, mk_win_base_word_t const attributes) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SetConsoleTextAttribute(handle, attributes);
	return ret;
}


#else
static void mk_win_dll_kernel_console_dummy(void){}
#endif
#endif
