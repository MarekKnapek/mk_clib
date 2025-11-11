#ifndef mk_include_guard_mk_win_dll_kernel_synchronization_timer_queue_h
#define mk_include_guard_mk_win_dll_kernel_synchronization_timer_queue_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


#define mk_win_dll_kernel_synchronization_timer_queue_flag_d_execute_default              ((mk_win_base_ulong_t)(0x00000000ul))
#define mk_win_dll_kernel_synchronization_timer_queue_flag_d_execute_in_io_thread         ((mk_win_base_ulong_t)(0x00000001ul))
#define mk_win_dll_kernel_synchronization_timer_queue_flag_d_execute_only_once            ((mk_win_base_ulong_t)(0x00000008ul))
#define mk_win_dll_kernel_synchronization_timer_queue_flag_d_execute_long_function        ((mk_win_base_ulong_t)(0x00000010ul))
#define mk_win_dll_kernel_synchronization_timer_queue_flag_d_execute_in_timer_thread      ((mk_win_base_ulong_t)(0x00000020ul))
#define mk_win_dll_kernel_synchronization_timer_queue_flag_d_execute_in_persistent_thread ((mk_win_base_ulong_t)(0x00000080ul))
#define mk_win_dll_kernel_synchronization_timer_queue_flag_d_transfer_impersonation       ((mk_win_base_ulong_t)(0x00000100ul))


mk_win_base_typedef_func(mk_win_base_void_t, mk_win_base_stdcall, mk_win_dll_kernel_synchronization_timer_queue_callback_t, (mk_win_base_void_lpt const parameter, mk_win_base_boolean_t const timer_or_wait_fired));


mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_timer_queue_change_timer_queue_timer(mk_win_base_handle_t const queue, mk_win_base_handle_t const timer, mk_win_base_ulong_t const due_time, mk_win_base_ulong_t const period) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_handle_t mk_win_dll_kernel_synchronization_timer_queue_create_timer_queue(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_timer_queue_create_timer_queue_timer(mk_win_base_handle_pt const timer, mk_win_base_handle_t const queue, mk_win_dll_kernel_synchronization_timer_queue_callback_t const callback_fn, mk_win_base_void_lpt const callback_arg, mk_win_base_dword_t const due_time, mk_win_base_dword_t const period, mk_win_base_ulong_t const flags) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_timer_queue_delete_timer_queue(mk_win_base_handle_t const queue) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_timer_queue_delete_timer_queue_ex(mk_win_base_handle_t const queue, mk_win_base_handle_t const completion_event) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_kernel_synchronization_timer_queue_delete_timer_queue_timer(mk_win_base_handle_t const queue, mk_win_base_handle_t const timer, mk_win_base_handle_t const completion_event) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_win_dll_kernel_synchronization_timer_queue.c"
#endif
#endif
