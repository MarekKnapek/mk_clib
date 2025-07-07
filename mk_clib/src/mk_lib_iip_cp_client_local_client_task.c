#ifndef mk_include_guard_mk_lib_iip_cp_client_local_client_c
#define mk_include_guard_mk_lib_iip_cp_client_local_client_c
#include "mk_lib_iip_cp_client_local_client_task.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_roundup.h"
#include "mk_lang_runtime_bool.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_any_data_connection.h"
#include "mk_lib_iip_any_func_connection.h"
#include "mk_lib_iip_cp_client_session.h"
#include "mk_lib_iip_cp_client_shared.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_parse.h"
#include "mk_lib_iip_cp_message_serialize.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_iip_key_enc_elgamal_pri.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_logger.h"
#include "mk_lib_iip_logger_more.h"
#include "mk_lib_net.h"
#include "mk_sl_cui_uint8.h"
#include "mk_win_dll_kernel_time.h" /* todo */


#define mk_sl_cui_t_name mk_lib_iip_cp_client_local_client_handle
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#if defined mk_lib_iip_cp_client_local_client_debug_print_want
#if (mk_lib_iip_cp_client_local_client_debug_print_want) == 0
#define mk_lib_iip_cp_client_local_client_debug_print_have 0
#elif (mk_lib_iip_cp_client_local_client_debug_print_want) == 1
#define mk_lib_iip_cp_client_local_client_debug_print_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_lib_iip_cp_client_local_client_debug_print_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lib_iip_cp_client_local_client_debug_print_have 0
#else
#define mk_lib_iip_cp_client_local_client_debug_print_have 1
#endif
#endif
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_construct(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lib_iip_cp_client_local_client_task_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(settings->m_shared);

	task->m_step = ((mk_lib_iip_cp_client_local_client_task_step_t)(0));
	task->m_local.m_settings.m_shared = settings->m_shared;
	task->m_local.m_settings.m_listening_socket = settings->m_listening_socket;
	err = mk_lib_net_socket_construct(&task->m_local.m_state.m_client_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&task->m_local.m_state.m_client_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_construct_void(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_construct_void(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
	task->m_local.m_state.m_stop_requested = mk_lang_false;
	task->m_local.m_state.m_stop_acknowledged = mk_lang_false;
	task->m_local.m_state.m_is_connected = mk_lib_iip_cp_client_local_client_task_socket_state_e_not_connected_yet;
	task->m_local.m_state.m_last_action_timestamp = ((mk_lang_types_uint_t)(mk_win_dll_kernel_time_get_tick_count()));
	task->m_local.m_state.m_buffer.m_ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(&task->m_local.m_state.m_buffer.m_data.m_u8s[0], mk_lib_iip_cp_client_local_client_buffer_algn)));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_destroy(mk_lib_iip_cp_client_local_client_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_net_socket_destroy(&task->m_local.m_state.m_client_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_destroy(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_destroy(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_request_close(mk_lib_iip_cp_client_local_client_task_pt const task) mk_lang_noexcept
{
	mk_lang_assert(task);

	task->m_local.m_state.m_stop_requested = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_want_associate_socket(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lang_types_bool_t www;

	mk_lang_assert(task);
	mk_lang_assert(want);

	www = task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_want_associate_socket;
	*want = www;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_gimme_socket(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lib_net_socket_ppt const socket, mk_lib_iip_any_data_connection_ppt const associatee) mk_lang_noexcept
{
	mk_lang_types_bool_t want;

	mk_lang_assert(task);
	mk_lang_assert(socket);
	mk_lang_assert(associatee);
	mk_lang_assert(mk_lib_iip_cp_client_local_client_task_prrw_want_associate_socket(task, &want) == 0 && want);

	*socket = &task->m_local.m_state.m_client_socket;
	*associatee = &task->m_local.m_settings.m_type;
	task->m_step = mk_lib_iip_cp_client_local_client_task_step_e_rqst_accept_ex;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done_wait_accept_ex(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(successful_io_operation == mk_lang_false || successful_io_operation == mk_lang_true);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_wait_accept_ex);
	mk_lang_assert(overlapped == &task->m_local.m_state.m_ioctl_request.m_overlapped);

	err = mk_lib_net_ioctl_request_wait_infinite(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_b);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_transferred >= 0);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_transferred <= task->m_local.m_state.m_ioctl_request.m_out_data_len);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_transferred == ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_fn_ptr_accept_ex))));
	err = mk_lib_net_ioctl_request_reset(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_client_task_step_e_rqst_get_accept_ex_sock_addrs;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done_wait_get_accept_ex_sock_addrs(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(successful_io_operation == mk_lang_false || successful_io_operation == mk_lang_true);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_wait_get_accept_ex_sock_addrs);
	mk_lang_assert(overlapped == &task->m_local.m_state.m_ioctl_request.m_overlapped);

	err = mk_lib_net_ioctl_request_wait_infinite(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_b);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_transferred >= 0);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_transferred <= task->m_local.m_state.m_ioctl_request.m_out_data_len);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_transferred == ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_fn_ptr_get_accept_ex_sock_addrs))));
	err = mk_lib_net_ioctl_request_reset(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_client_task_step_e_accept_client;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done_wait_failed_accept(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(successful_io_operation == mk_lang_false);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_wait_failed_accept);
	mk_lang_assert(overlapped == &task->m_local.m_state.m_accept_request.m_overlapped);

	err = mk_lib_net_accept_request_wait_infinite(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_get_result(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
	mk_lang_check_return(!task->m_local.m_state.m_accept_request.m_b);
	mk_lang_check_return(task->m_local.m_state.m_accept_request.m_transferred >= 0);
	mk_lang_check_return(task->m_local.m_state.m_accept_request.m_transferred <= task->m_local.m_state.m_accept_request.m_out_data_len);
	err = mk_lib_net_accept_request_reset(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_client_task_step_e_want_die;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done_idle(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(successful_io_operation == mk_lang_false || successful_io_operation == mk_lang_true);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_idle);

	if
	(
		(task->m_local.m_state.m_is_connected == mk_lib_iip_cp_client_local_client_task_socket_state_e_not_connected_yet) ||
		(task->m_local.m_state.m_is_connected == mk_lib_iip_cp_client_local_client_task_socket_state_e_connected_no_data_yet) ||
		(mk_lang_false)
	)
	{
		if(task->m_local.m_state.m_is_connected == mk_lib_iip_cp_client_local_client_task_socket_state_e_not_connected_yet)
		{
			err = mk_lib_net_socket_set_option_update_accept_context(&task->m_local.m_state.m_client_socket, &task->m_local.m_settings.m_listening_socket); mk_lang_check_rereturn(err);
		}
		err = mk_lib_net_accept_request_wait_infinite(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
		err = mk_lib_net_accept_request_get_result(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
		mk_lang_check_return(task->m_local.m_state.m_accept_request.m_b);
		mk_lang_check_return(task->m_local.m_state.m_accept_request.m_transferred >= 1);
		mk_lang_check_return(task->m_local.m_state.m_accept_request.m_transferred < task->m_local.m_state.m_accept_request.m_out_data_len);
		err = mk_lib_net_accept_request_get_addresses(&task->m_local.m_state.m_accept_request, &task->m_local.m_state.m_destination_local, &task->m_local.m_state.m_destination_remote); mk_lang_check_rereturn(err);
		err = mk_lib_net_accept_request_reset(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
		task->m_local.m_state.m_is_connected = mk_lib_iip_cp_client_local_client_task_socket_state_e_connected_data_sent;
	}
	else
	{
		mk_lang_check_todo();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(successful_io_operation == mk_lang_false || successful_io_operation == mk_lang_true);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(mk_lang_false){}
	#include "mk_lang_warning_msvc_pop.h"
	else if(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_wait_accept_ex               ){ err = mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done_wait_accept_ex               (task, successful_io_operation, bytes_transferred, overlapped); mk_lang_check_rereturn(err); }
	else if(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_wait_get_accept_ex_sock_addrs){ err = mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done_wait_get_accept_ex_sock_addrs(task, successful_io_operation, bytes_transferred, overlapped); mk_lang_check_rereturn(err); }
	else if(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_wait_failed_accept           ){ err = mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done_wait_failed_accept           (task, successful_io_operation, bytes_transferred, overlapped); mk_lang_check_rereturn(err); }
	else if(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_idle                         ){ err = mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done_idle                         (task, successful_io_operation, bytes_transferred, overlapped); mk_lang_check_rereturn(err); }
	else{ mk_lang_assert_false(); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_rqst_accept_ex(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr;
	mk_lang_types_uchar_pt guid;
	mk_lang_types_uint_t control_code;
	mk_sl_cui_uint8_pct in_data_buf;
	mk_lang_types_sint_t in_data_len;
	mk_sl_cui_uint8_pt out_data_buf;
	mk_lang_types_sint_t out_data_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_rqst_accept_ex);

	ptr = 0;
	guid = ((mk_lang_types_uchar_pt)(&task->m_local.m_state.m_ioctl_request_guid));
	guid[ptr++] = 0xf1; guid[ptr++] = 0x7d; guid[ptr++] = 0x36; guid[ptr++] = 0xb5;
	guid[ptr++] = 0xac; guid[ptr++] = 0xcb; guid[ptr++] = 0xcf; guid[ptr++] = 0x11;
	guid[ptr++] = 0x95; guid[ptr++] = 0xca; guid[ptr++] = 0x00; guid[ptr++] = 0x80;
	guid[ptr++] = 0x5f; guid[ptr++] = 0x48; guid[ptr++] = 0xa1; guid[ptr++] = 0x92;
	control_code = ((mk_lang_types_uint_t)(mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer));
	in_data_buf = ((mk_sl_cui_uint8_pct)(&task->m_local.m_state.m_ioctl_request_guid));
	in_data_len = ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_ioctl_request_guid)));
	out_data_buf = ((mk_sl_cui_uint8_pt)(&task->m_local.m_state.m_fn_ptr_accept_ex));
	out_data_len = ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_fn_ptr_accept_ex)));
	err = mk_lib_net_ioctl_request_reconstruct(&task->m_local.m_state.m_ioctl_request, &task->m_local.m_settings.m_listening_socket, control_code, in_data_buf, in_data_len, out_data_buf, out_data_len); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_issue(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_client_task_step_e_wait_accept_ex;
	*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_wait_accept_ex(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_wait_accept_ex);

	*step_result = mk_lib_iip_cp_client_local_client_task_result_e_would_block;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_rqst_get_accept_ex_sock_addrs(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr;
	mk_lang_types_uchar_pt guid;
	mk_lang_types_uint_t control_code;
	mk_sl_cui_uint8_pct in_data_buf;
	mk_lang_types_sint_t in_data_len;
	mk_sl_cui_uint8_pt out_data_buf;
	mk_lang_types_sint_t out_data_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_rqst_get_accept_ex_sock_addrs);

	ptr = 0;
	guid = ((mk_lang_types_uchar_pt)(&task->m_local.m_state.m_ioctl_request_guid));
	guid[ptr++] = 0xf2; guid[ptr++] = 0x7d; guid[ptr++] = 0x36; guid[ptr++] = 0xb5;
	guid[ptr++] = 0xac; guid[ptr++] = 0xcb; guid[ptr++] = 0xcf; guid[ptr++] = 0x11;
	guid[ptr++] = 0x95; guid[ptr++] = 0xca; guid[ptr++] = 0x00; guid[ptr++] = 0x80;
	guid[ptr++] = 0x5f; guid[ptr++] = 0x48; guid[ptr++] = 0xa1; guid[ptr++] = 0x92;
	control_code = ((mk_lang_types_uint_t)(mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer));
	in_data_buf = ((mk_sl_cui_uint8_pct)(&task->m_local.m_state.m_ioctl_request_guid));
	in_data_len = ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_ioctl_request_guid)));
	out_data_buf = ((mk_sl_cui_uint8_pt)(&task->m_local.m_state.m_fn_ptr_get_accept_ex_sock_addrs));
	out_data_len = ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_fn_ptr_get_accept_ex_sock_addrs)));
	err = mk_lib_net_ioctl_request_reconstruct(&task->m_local.m_state.m_ioctl_request, &task->m_local.m_settings.m_listening_socket, control_code, in_data_buf, in_data_len, out_data_buf, out_data_len); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_issue(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_client_task_step_e_wait_get_accept_ex_sock_addrs;
	*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_wait_get_accept_ex_sock_addrs(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_wait_get_accept_ex_sock_addrs);

	*step_result = mk_lib_iip_cp_client_local_client_task_result_e_would_block;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_want_associate_socket(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_want_associate_socket);

	*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_nothing;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_accept_client(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_accept_client);

	err = mk_lib_net_accept_request_reconstruct(&task->m_local.m_state.m_accept_request, &task->m_local.m_state.m_fn_ptr_accept_ex, &task->m_local.m_state.m_fn_ptr_get_accept_ex_sock_addrs, &task->m_local.m_settings.m_listening_socket, &task->m_local.m_state.m_client_socket, task->m_local.m_state.m_buffer.m_ptr, mk_lib_iip_cp_client_local_client_buffer_size); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_issue(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_client_task_step_e_idle;
	*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_idle_no_stop(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_uint_t current_timestamp;
	mk_lang_types_bool_t did_something;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t connect_time;
	mk_lang_types_bool_t is_connected;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_idle);

	current_timestamp = ((mk_lang_types_uint_t)(mk_win_dll_kernel_time_get_tick_count()));
	did_something = mk_lang_false;
	if(!did_something)
	{
		if
		(
			(
				(task->m_local.m_state.m_is_connected == mk_lib_iip_cp_client_local_client_task_socket_state_e_connected_no_data_yet) ||
				(task->m_local.m_state.m_is_connected == mk_lib_iip_cp_client_local_client_task_socket_state_e_connected_data_sent) ||
				(mk_lang_false)
			) &&
			(current_timestamp - task->m_local.m_state.m_last_action_timestamp >= 1 * 60 * 1000) &&
			(mk_lang_true)
		)
		{
			err = mk_lib_iip_cp_client_local_client_task_prrw_request_close(task); mk_lang_check_rereturn(err);
			*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_something;
			did_something = mk_lang_true;
		}
	}
	if(!did_something)
	{
		if(task->m_local.m_state.m_is_connected == mk_lib_iip_cp_client_local_client_task_socket_state_e_not_connected_yet)
		{
			err = mk_lib_net_socket_get_option_connect_time(&task->m_local.m_state.m_client_socket, &connect_time); mk_lang_check_rereturn(err);
			is_connected = connect_time != -1;
			if(is_connected)
			{
				err = mk_lib_net_socket_set_option_update_accept_context(&task->m_local.m_state.m_client_socket, &task->m_local.m_settings.m_listening_socket); mk_lang_check_rereturn(err);
				err = mk_lib_net_socket_get_addresses(&task->m_local.m_state.m_client_socket, &task->m_local.m_state.m_destination_local, &task->m_local.m_state.m_destination_remote); mk_lang_check_rereturn(err);
				task->m_local.m_state.m_is_connected = mk_lib_iip_cp_client_local_client_task_socket_state_e_connected_no_data_yet;
				task->m_local.m_state.m_last_action_timestamp = current_timestamp;
				*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_something;
				did_something = mk_lang_true;
			}
		}
	}
	if(!did_something)
	{
		*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_nothing;
	}
	mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_idle_do_stop(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_idle);

	err = mk_lib_net_socket_reset(&task->m_local.m_state.m_client_socket); mk_lang_check_rereturn(err);
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(mk_lang_false){}
	#include "mk_lang_warning_msvc_pop.h"
	else if(task->m_local.m_state.m_is_connected == mk_lib_iip_cp_client_local_client_task_socket_state_e_not_connected_yet){ task->m_step = mk_lib_iip_cp_client_local_client_task_step_e_wait_failed_accept; }
	else if(task->m_local.m_state.m_is_connected == mk_lib_iip_cp_client_local_client_task_socket_state_e_connected_no_data_yet){ task->m_step = mk_lib_iip_cp_client_local_client_task_step_e_wait_failed_accept; }
	else if(task->m_local.m_state.m_is_connected == mk_lib_iip_cp_client_local_client_task_socket_state_e_connected_data_sent){ task->m_step = mk_lib_iip_cp_client_local_client_task_step_e_want_die; }
	else{ mk_lang_assert_false(); }
	*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_idle(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_idle);

	if(task->m_local.m_state.m_stop_requested && task->m_local.m_state.m_stop_acknowledged)
	{
		*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_nothing;
	}
	else if(task->m_local.m_state.m_stop_requested && !task->m_local.m_state.m_stop_acknowledged)
	{
		task->m_local.m_state.m_stop_acknowledged = mk_lang_true;
		err = mk_lib_iip_cp_client_local_client_task_prrw_step_idle_do_stop(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	}
	else
	{
		err = mk_lib_iip_cp_client_local_client_task_prrw_step_idle_no_stop(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_wait_failed_accept(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_wait_failed_accept);

	*step_result = mk_lib_iip_cp_client_local_client_task_result_e_would_block;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_want_die(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_want_die);

	*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_nothing;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_local_client_task_step_e_rqst_accept_ex               : err = mk_lib_iip_cp_client_local_client_task_prrw_step_rqst_accept_ex               (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_client_task_step_e_wait_accept_ex               : err = mk_lib_iip_cp_client_local_client_task_prrw_step_wait_accept_ex               (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_client_task_step_e_rqst_get_accept_ex_sock_addrs: err = mk_lib_iip_cp_client_local_client_task_prrw_step_rqst_get_accept_ex_sock_addrs(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_client_task_step_e_wait_get_accept_ex_sock_addrs: err = mk_lib_iip_cp_client_local_client_task_prrw_step_wait_get_accept_ex_sock_addrs(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_client_task_step_e_want_associate_socket        : err = mk_lib_iip_cp_client_local_client_task_prrw_step_want_associate_socket        (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_client_task_step_e_accept_client                : err = mk_lib_iip_cp_client_local_client_task_prrw_step_accept_client                (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_client_task_step_e_idle                         : err = mk_lib_iip_cp_client_local_client_task_prrw_step_idle                         (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_client_task_step_e_wait_failed_accept           : err = mk_lib_iip_cp_client_local_client_task_prrw_step_wait_failed_accept           (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_client_task_step_e_want_die                     : err = mk_lib_iip_cp_client_local_client_task_prrw_step_want_die                     (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_client_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_want_die(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lang_types_bool_t www;

	mk_lang_assert(task);
	mk_lang_assert(want);

	www = task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_want_die;
	*want = www;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_want_irp(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_void_pt const overlapped, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lang_types_bool_t www;

	mk_lang_assert(task);
	mk_lang_assert(overlapped);
	mk_lang_assert(want);

	www =
		overlapped == &task->m_local.m_state.m_ioctl_request.m_overlapped ||
		overlapped == &task->m_local.m_state.m_accept_request.m_overlapped ||
		(mk_lang_false);
	*want = www;
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lib_iip_cp_client_local_client_task_pt mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_settings_pt settings;
	mk_lib_iip_cp_client_local_client_pt local_listener;
	mk_lib_iip_cp_client_local_client_task_pt self;

	mk_lang_assert(connection);

	settings = ((mk_lib_iip_cp_client_local_client_task_settings_pt)(((mk_lang_types_uchar_pt)(connection)) - mk_lang_offsetof(mk_lib_iip_cp_client_local_client_task_settings_t, m_type)));
	local_listener = ((mk_lib_iip_cp_client_local_client_pt)(((mk_lang_types_uchar_pt)(settings)) - mk_lang_offsetof(mk_lib_iip_cp_client_local_client_t, m_settings)));
	self = ((mk_lib_iip_cp_client_local_client_task_pt)(((mk_lang_types_uchar_pt)(local_listener)) - mk_lang_offsetof(mk_lib_iip_cp_client_local_client_task_t, m_local)));
	return self;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_allocate(mk_lib_iip_any_data_connection_ppt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;
	mk_lib_iip_cp_client_local_client_task_pt self;

	mk_lang_assert(connection);

	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*self), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); self = ((mk_lib_iip_cp_client_local_client_task_pt)(mem)); mk_lang_assert(self);
	self->m_local.m_settings.m_type.m_data.m_id = mk_lib_iip_any_func_connection_type_e_mk_lib_iip_cp_client_local_client_task;
	*connection = &self->m_local.m_settings.m_type;
	mk_lang_assert(mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(*connection) == self);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_deallocate(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_mallocator_global_deallocate(self, sizeof(*self)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_construct(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_void_pt const settings) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_local_client_task_prrw_construct(self, settings); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_destroy(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_local_client_task_prrw_destroy(self); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_request_close(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_local_client_task_prrw_request_close(self); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_want_associate_socket(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_local_client_task_prrw_want_associate_socket(self, want); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_gimme_socket(mk_lib_iip_any_data_connection_pt const connection, mk_lib_net_socket_ppt const socket, mk_lib_iip_any_data_connection_ppt const associatee) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_local_client_task_prrw_gimme_socket(self, socket, associatee); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_on_iorp_done(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done(self, successful_io_operation, bytes_transferred, overlapped); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_step(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_any_data_connection_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_local_client_task_prrw_step(self, allow_to_block, tm, step_result); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_want_die(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_local_client_task_prrw_want_die(self, want); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_prrw_want_irp(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_void_pt const overlapped, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_local_client_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_local_client_task_prrw_want_irp(self, overlapped, want); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_construct(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lib_iip_cp_client_local_client_task_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_construct(task, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_destroy(mk_lib_iip_cp_client_local_client_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_request_close(mk_lib_iip_cp_client_local_client_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_request_close(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_want_associate_socket(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_want_associate_socket(task, want);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_gimme_socket(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lib_net_socket_ppt const socket, mk_lib_iip_any_data_connection_ppt const associatee) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_gimme_socket(task, socket, associatee);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_on_iorp_done(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done(task, successful_io_operation, bytes_transferred, overlapped);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_step(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_step(task, allow_to_block, tm, step_result);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_want_die(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_want_die(task, want);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_want_irp(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_void_pt const overlapped, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_want_irp(task, overlapped, want);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_allocate(mk_lib_iip_any_data_connection_ppt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_allocate(connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_deallocate(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_deallocate(connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_construct(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_void_pt const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_construct(connection, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_destroy(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_destroy(connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_request_close(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_request_close(connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_want_associate_socket(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_want_associate_socket(connection, want);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_gimme_socket(mk_lib_iip_any_data_connection_pt const connection, mk_lib_net_socket_ppt const socket, mk_lib_iip_any_data_connection_ppt const associatee) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_gimme_socket(connection, socket, associatee);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_on_iorp_done(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_on_iorp_done(connection, successful_io_operation, bytes_transferred, overlapped);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_step(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_any_data_connection_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_step(connection, allow_to_block, tm, step_result);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_want_die(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_want_die(connection, want);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_any_rw_want_irp(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_void_pt const overlapped, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_any_prrw_want_irp(connection, overlapped, want);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_void(mk_lib_iip_cp_client_local_client_task_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_destroy(mk_lib_iip_cp_client_local_client_task_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_local_client_task_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_copy(mk_lib_iip_cp_client_local_client_task_ppt const dst, mk_lib_iip_cp_client_local_client_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_move(mk_lib_iip_cp_client_local_client_task_ppt const dst, mk_lib_iip_cp_client_local_client_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_assign_copy(mk_lib_iip_cp_client_local_client_task_ppt const dst, mk_lib_iip_cp_client_local_client_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_assign_move(mk_lib_iip_cp_client_local_client_task_ppt const dst, mk_lib_iip_cp_client_local_client_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_local_client_tasks
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_local_client_task_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_local_client_task_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_local_client_task_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_local_client_task_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
