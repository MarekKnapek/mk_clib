#ifndef mk_include_guard_mk_win_dll_kernel_synchronization_waitable_timer_c
#define mk_include_guard_mk_win_dll_kernel_synchronization_waitable_timer_c
#include "mk_win_dll_kernel_synchronization_waitable_timer.h"

#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_win_base.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CancelWaitableTimer(mk_win_base_handle_t const timer) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateWaitableTimerW(mk_win_base_void_lpt const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_wchar_lpct const name) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateWaitableTimerExW(mk_win_base_void_lpt const security_attributes, mk_win_base_wchar_lpct const name, mk_win_base_dword_t const flags, mk_win_base_dword_t const desired_access) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall OpenWaitableTimerW(mk_win_base_dword_t const desired_access, mk_win_base_bool_t const inherit, mk_win_base_wchar_lpct const name) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetWaitableTimer(mk_win_base_handle_t const timer, mk_win_base_large_integer_lpct const due_time, mk_win_base_slong_t const period, mk_win_dll_kernel_synchronization_waitable_timer_completion_routine_t const completion_routine, mk_win_base_void_lpt const completion_arg, mk_win_base_bool_t const resume) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall SetWaitableTimerEx(mk_win_base_handle_t const timer, mk_win_base_large_integer_lpct const due_time, mk_win_base_slong_t const period, mk_win_dll_kernel_synchronization_waitable_timer_completion_routine_t const completion_routine, mk_win_base_void_lpt const completion_arg, mk_win_dll_kernel_synchronization_waitable_timer_reason_context_lpt const wake_context, mk_win_base_ulong_t const tolerable_delay) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_waitable_timer_cancel_waitable_timer(mk_win_base_handle_t const timer) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = CancelWaitableTimer(timer);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_waitable_timer_create_waitable_timer_w(mk_win_base_void_lpt const security_attributes, mk_win_base_bool_t const manual_reset, mk_win_base_wchar_lpct const name) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateWaitableTimerW(security_attributes, manual_reset, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_waitable_timer_create_waitable_timer_ex_w(mk_win_base_void_lpt const security_attributes, mk_win_base_wchar_lpct const name, mk_win_base_dword_t const flags, mk_win_base_dword_t const desired_access) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateWaitableTimerExW(security_attributes, name, flags, desired_access);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_waitable_timer_open_waitable_timer_w(mk_win_base_dword_t const desired_access, mk_win_base_bool_t const inherit, mk_win_base_wchar_lpct const name) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = OpenWaitableTimerW(desired_access, inherit, name);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_waitable_timer_set_waitable_timer(mk_win_base_handle_t const timer, mk_win_base_large_integer_lpct const due_time, mk_win_base_slong_t const period, mk_win_dll_kernel_synchronization_waitable_timer_completion_routine_t const completion_routine, mk_win_base_void_lpt const completion_arg, mk_win_base_bool_t const resume) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SetWaitableTimer(timer, due_time, period, completion_routine, completion_arg, resume);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_waitable_timer_set_waitable_timer_ex(mk_win_base_handle_t const timer, mk_win_base_large_integer_lpct const due_time, mk_win_base_slong_t const period, mk_win_dll_kernel_synchronization_waitable_timer_completion_routine_t const completion_routine, mk_win_base_void_lpt const completion_arg, mk_win_dll_kernel_synchronization_waitable_timer_reason_context_lpt const wake_context, mk_win_base_ulong_t const tolerable_delay) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = SetWaitableTimerEx(timer, due_time, period, completion_routine, completion_arg, wake_context, tolerable_delay);
	return ret;
}


#endif
