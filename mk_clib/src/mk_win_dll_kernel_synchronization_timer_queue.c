#ifndef mk_include_guard_mk_win_dll_kernel_synchronization_timer_queue_c
#define mk_include_guard_mk_win_dll_kernel_synchronization_timer_queue_c
#include "mk_win_dll_kernel_synchronization_timer_queue.h"

#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall ChangeTimerQueueTimer(mk_win_base_handle_t const queue, mk_win_base_handle_t const timer, mk_win_base_ulong_t const due_time, mk_win_base_ulong_t const period) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_handle_t mk_win_base_stdcall CreateTimerQueue(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall CreateTimerQueueTimer(mk_win_base_handle_pt const timer, mk_win_base_handle_t const queue, mk_win_dll_kernel_synchronization_timer_queue_callback_t const callback_fn, mk_win_base_void_lpt const callback_arg, mk_win_base_dword_t const due_time, mk_win_base_dword_t const period, mk_win_base_ulong_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall DeleteTimerQueue(mk_win_base_handle_t const queue) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall DeleteTimerQueueEx(mk_win_base_handle_t const queue, mk_win_base_handle_t const completion_event) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall DeleteTimerQueueTimer(mk_win_base_handle_t const queue, mk_win_base_handle_t const timer, mk_win_base_handle_t const completion_event) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_timer_queue_change_timer_queue_timer(mk_win_base_handle_t const queue, mk_win_base_handle_t const timer, mk_win_base_ulong_t const due_time, mk_win_base_ulong_t const period) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = ChangeTimerQueueTimer(queue, timer, due_time, period);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_timer_queue_create_timer_queue(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_handle_t ret;

	ret = CreateTimerQueue();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_timer_queue_create_timer_queue_timer(mk_win_base_handle_pt const timer, mk_win_base_handle_t const queue, mk_win_dll_kernel_synchronization_timer_queue_callback_t const callback_fn, mk_win_base_void_lpt const callback_arg, mk_win_base_dword_t const due_time, mk_win_base_dword_t const period, mk_win_base_ulong_t const flags) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = CreateTimerQueueTimer(timer, queue, callback_fn, callback_arg, due_time, period, flags);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_timer_queue_delete_timer_queue(mk_win_base_handle_t const queue) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = DeleteTimerQueue(queue);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_timer_queue_delete_timer_queue_ex(mk_win_base_handle_t const queue, mk_win_base_handle_t const completion_event) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = DeleteTimerQueueEx(queue, completion_event);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_timer_queue_delete_timer_queue_timer(mk_win_base_handle_t const queue, mk_win_base_handle_t const timer, mk_win_base_handle_t const completion_event) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = DeleteTimerQueueTimer(queue, timer, completion_event);
	return ret;
}


#endif
