#ifndef mk_include_guard_mk_win_dll_kernel_synchronization_event_c
#define mk_include_guard_mk_win_dll_kernel_synchronization_event_c
#include "mk_win_dll_kernel_synchronization_event.h"

#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateEventA(mk_win_base_void_lpt const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_base_pchar_lpct const name) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateEventW(mk_win_base_void_lpt const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_base_wchar_lpct const name) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateEventExA(mk_win_base_void_lpt const security_attributes, mk_win_base_pchar_lpct const name, mk_win_base_dword_t const flags, mk_win_base_dword_t const desired_access) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateEventExW(mk_win_base_void_lpt const security_attributes, mk_win_base_wchar_lpct const name, mk_win_base_dword_t const flags, mk_win_base_dword_t const desired_access) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall OpenEventA(mk_win_base_dword_t const desired_access, mk_win_base_bool_t const inherit, mk_win_base_pchar_lpct const name) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall OpenEventW(mk_win_base_dword_t const desired_access, mk_win_base_bool_t const inherit, mk_win_base_wchar_lpct const name) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall PulseEvent(mk_win_base_handle_t const event) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ResetEvent(mk_win_base_handle_t const event) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetEvent(mk_win_base_handle_t const event) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_event_create_event_a(mk_win_base_void_lpt const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_base_pchar_lpct const name) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateEventA(security_attributes, manual_reset, initial_state, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_event_create_event_w(mk_win_base_void_lpt const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_bool_t const initial_state, mk_win_base_wchar_lpct const name) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateEventW(security_attributes, manual_reset, initial_state, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_event_create_event_ex_a(mk_win_base_void_lpt const security_attributes, mk_win_base_pchar_lpct const name, mk_win_base_dword_t const flags, mk_win_base_dword_t const desired_access) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateEventExA(security_attributes, name, flags, desired_access);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_event_create_event_ex_w(mk_win_base_void_lpt const security_attributes, mk_win_base_wchar_lpct const name, mk_win_base_dword_t const flags, mk_win_base_dword_t const desired_access) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateEventExW(security_attributes, name, flags, desired_access);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_event_open_event_a(mk_win_base_dword_t const desired_access, mk_win_base_bool_t const inherit, mk_win_base_pchar_lpct const name) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = OpenEventA(desired_access, inherit, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_event_open_event_w(mk_win_base_dword_t const desired_access, mk_win_base_bool_t const inherit, mk_win_base_wchar_lpct const name) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = OpenEventW(desired_access, inherit, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_event_pulse_event(mk_win_base_handle_t const event) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = PulseEvent(event);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_event_reset_event(mk_win_base_handle_t const event) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = ResetEvent(event);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_event_set_event(mk_win_base_handle_t const event) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SetEvent(event);
	return ret;
}


#endif
