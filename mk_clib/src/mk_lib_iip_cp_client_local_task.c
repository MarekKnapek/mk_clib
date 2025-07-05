#ifndef mk_include_guard_mk_lib_iip_cp_client_local_c
#define mk_include_guard_mk_lib_iip_cp_client_local_c
#include "mk_lib_iip_cp_client_local_task.h"

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
#include "mk_lang_roundup.h"
#include "mk_lang_runtime_bool.h"
#include "mk_lang_types.h"
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


#define mk_sl_cui_t_name mk_lib_iip_cp_client_local_handle
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#define mk_lib_iip_cp_client_local_k_buffer_size (128 * 1024)
#define mk_lib_iip_cp_client_local_k_buffer_algn ( 64 * 1024)


#if defined mk_lib_iip_cp_client_local_debug_print_want
#if (mk_lib_iip_cp_client_local_debug_print_want) == 0
#define mk_lib_iip_cp_client_local_debug_print_have 0
#elif (mk_lib_iip_cp_client_local_debug_print_want) == 1
#define mk_lib_iip_cp_client_local_debug_print_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_lib_iip_cp_client_local_debug_print_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lib_iip_cp_client_local_debug_print_have 0
#else
#define mk_lib_iip_cp_client_local_debug_print_have 1
#endif
#endif
#endif


#if mk_lib_iip_cp_client_local_debug_print_have
#include "mk_lib_fmt.h"
#include "mk_lib_iip_cp_message_str.h"
#include "mk_lib_iip_time.h"
#endif


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_cp_client_local_k_api_ver[] = "0.9.66";


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_debug_print_compute_time_offset(mk_lib_iip_cp_types_date_pct const time_server, mk_lib_iip_cp_types_date_pt const time_offset) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_local_debug_print_have
	mk_lib_iip_cp_types_date_t time_client;

	mk_lang_assert(time_server);
	mk_lang_assert(time_offset);

	mk_lib_iip_time_get_now(&time_client.m_elements[0]);
	mk_lib_iip_cp_types_date_sub3_wrap_cid_cod(&time_client, time_server, time_offset);
	return 0;
#else
	mk_lang_assert(time_server);
	mk_lang_assert(time_offset);

	((mk_lang_types_void_t)(time_server));
	((mk_lang_types_void_t)(time_offset));
	return 0;
#endif
}

#if mk_lib_iip_cp_client_local_debug_print_have
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_cp_client_local_debug_print_compute_and_print_time_offset_k_fmt[] = "Our time offset from server time is %lld ms.";
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_debug_print_compute_and_print_time_offset(mk_lib_iip_cp_client_local_task_pt const task, mk_lib_iip_cp_types_date_pct const time_server) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_local_debug_print_have
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_date_t time_offset;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[512];

	mk_lang_assert(task);
	mk_lang_assert(time_server);
	mk_lang_assert(task->m_local.m_settings.m_shared);

	err = mk_lib_iip_cp_client_local_debug_print_compute_time_offset(time_server, &time_offset); mk_lang_check_rereturn(err);
	str_len = mk_lib_fmt_n_snnprintf(&str_buf[0], mk_lang_countof(str_buf), &mk_lib_iip_cp_client_local_debug_print_compute_and_print_time_offset_k_fmt[0], mk_lang_countstr(mk_lib_iip_cp_client_local_debug_print_compute_and_print_time_offset_k_fmt), &time_offset.m_elements[0]); mk_lang_check_return(str_len >= 1); mk_lang_assert(str_len <= mk_lang_countof(str_buf));
	{
		err = mk_lib_iip_logger_rw_begin_line(&task->m_local.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_append_current_time(&task->m_local.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_print(&task->m_local.m_settings.m_shared->m_logger, &str_buf[0], str_len); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_end_line(&task->m_local.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	}
	return 0;
#else
	mk_lang_assert(task);
	mk_lang_assert(time_server);

	((mk_lang_types_void_t)(task));
	((mk_lang_types_void_t)(time_server));
	return 0;
#endif
}

enum mk_lib_iip_cp_client_local_debug_print_direction_e
{
	mk_lib_iip_cp_client_local_debug_print_direction_e_incomming,
	mk_lib_iip_cp_client_local_debug_print_direction_e_outgoing,
	mk_lib_iip_cp_client_local_debug_print_direction_e_dummy_end
};
typedef enum mk_lib_iip_cp_client_local_debug_print_direction_e mk_lib_iip_cp_client_local_debug_print_direction_t;

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_debug_print_msg(mk_lib_iip_cp_client_local_task_pt const task, mk_lib_iip_cp_message_pct const msg, mk_lib_iip_cp_client_local_debug_print_direction_t const direction) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_local_debug_print_have
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pt target_buf;
	mk_lang_types_pchar_t str_buf[4 * 1024];
	mk_lang_types_sint_t target_len;
	mk_lang_types_sint_t str_len;
	mk_lib_iip_logger_color_text_t color;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(direction >= 0);
	mk_lang_assert(direction < mk_lib_iip_cp_client_local_debug_print_direction_e_dummy_end);
	mk_lang_assert(task->m_local.m_settings.m_shared);

	err = mk_lib_iip_logger_rw_begin_line(&task->m_local.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_append_current_time(&task->m_local.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	target_buf = &str_buf[0];
	target_len = mk_lang_countof(str_buf);
	err = mk_lib_net_socket_to_text(&task->m_local.m_state.m_socket, target_buf, target_len, &str_len); mk_lang_check_rereturn(err); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= target_len);
	{
		err = mk_lib_iip_logger_rw_begin_color(&task->m_local.m_settings.m_shared->m_logger, mk_lib_iip_logger_color_text_e_dark_cyan); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_print(&task->m_local.m_settings.m_shared->m_logger, target_buf, str_len); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_end_color(&task->m_local.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_print_str_lit(&task->m_local.m_settings.m_shared->m_logger, " "); mk_lang_check_rereturn(err);
	}
	target_buf = &str_buf[0];
	target_len = mk_lang_countof(str_buf);
	color = direction == mk_lib_iip_cp_client_local_debug_print_direction_e_incomming ? mk_lib_iip_logger_color_text_e_dark_green : mk_lib_iip_logger_color_text_e_dark_yellow;
	err = mk_lib_iip_cp_message_str_to_json_message(target_buf, target_len, &str_len, msg); mk_lang_check_rereturn(err); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= target_len);
	{
		err = mk_lib_iip_logger_rw_begin_color(&task->m_local.m_settings.m_shared->m_logger, color); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_print(&task->m_local.m_settings.m_shared->m_logger, target_buf, str_len); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_end_color(&task->m_local.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_end_line(&task->m_local.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	}
	return 0;
#else
	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(direction >= 0);
	mk_lang_assert(direction < mk_lib_iip_cp_client_local_debug_print_direction_e_dummy_end);

	((mk_lang_types_void_t)(task));
	((mk_lang_types_void_t)(msg));
	((mk_lang_types_void_t)(direction));
	return 0;
#endif
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_construct(mk_lib_iip_cp_client_local_task_pt const task, mk_lib_iip_cp_client_local_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(settings->m_shared);
	mk_lang_assert(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));
	mk_lang_assert(!mk_lib_net_tcp_port_is_zero(&settings->m_destination.m_tcp_port));
	mk_lang_assert(!mk_lib_net_tcp_port_is_max(&settings->m_destination.m_tcp_port));

	task->m_step = ((mk_lib_iip_cp_client_local_task_step_t)(0));
	task->m_local.m_settings.m_shared = settings->m_shared;
	task->m_local.m_settings.m_destination.m_ipv4_address = settings->m_destination.m_ipv4_address;
	task->m_local.m_settings.m_destination.m_tcp_port = settings->m_destination.m_tcp_port;
	err = mk_lib_net_socket_construct_void(&task->m_local.m_state.m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_construct_void(&task->m_local.m_state.m_child); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_construct_void(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_construct_void(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);

	task->m_local.m_state.m_session_idx = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_destroy(mk_lib_iip_cp_client_local_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_net_socket_destroy(&task->m_local.m_state.m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_destroy(&task->m_local.m_state.m_child); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_destroy(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_destroy(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_request_close(mk_lib_iip_cp_client_local_task_pt const task) mk_lang_noexcept
{
	mk_lang_assert(task);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_cp_client_local_task_prrw_want_associate_socket(mk_lib_iip_cp_client_local_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_bool_t want;

	mk_lang_assert(task);

	want =
		(task->m_step == mk_lib_iip_cp_client_local_task_step_e_want_associate_socket) ||
		(task->m_step == mk_lib_iip_cp_client_local_task_step_e_want_associate_child) ||
		mk_lang_false;
	return want;
}

mk_lang_nodiscard static mk_lang_inline mk_lib_net_socket_pt mk_lib_iip_cp_client_local_task_prrw_gimme_socket(mk_lib_iip_cp_client_local_task_pt const task) mk_lang_noexcept
{
	mk_lib_net_socket_pt socket;

	mk_lang_assert(task);
	mk_lang_assert
	(
		(task->m_step == mk_lib_iip_cp_client_local_task_step_e_want_associate_socket) ||
		(task->m_step == mk_lib_iip_cp_client_local_task_step_e_want_associate_child) ||
		mk_lang_false
	);

	if(mk_lang_runtime_bool_fn_false){}
	else if(task->m_step == mk_lib_iip_cp_client_local_task_step_e_want_associate_socket){ socket = &task->m_local.m_state.m_socket; task->m_step = mk_lib_iip_cp_client_local_task_step_e_bind_socket  ; }
	else if(task->m_step == mk_lib_iip_cp_client_local_task_step_e_want_associate_child ){ socket = &task->m_local.m_state.m_child ; task->m_step = mk_lib_iip_cp_client_local_task_step_e_accept_client; }
	else{ mk_lang_assert_false(); }
	mk_lang_clobber(&socket);
	return socket;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_on_iorp_done_wait_accept_ex(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_wait_accept_ex);

	err = mk_lib_net_ioctl_request_wait_infinite(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_b);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_transferred == ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_fn_ptr_accept_ex))));
	task->m_step = mk_lib_iip_cp_client_local_task_step_e_reqv_get_accept_ex_sock_addrs;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_on_iorp_done_wait_get_accept_ex_sock_addrs(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_wait_get_accept_ex_sock_addrs);

	err = mk_lib_net_ioctl_request_wait_infinite(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_b);
	mk_lang_check_return(task->m_local.m_state.m_ioctl_request.m_transferred == ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_fn_ptr_get_accept_ex_sock_addrs))));
	task->m_step = mk_lib_iip_cp_client_local_task_step_e_create_child_socket;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_on_iorp_done_idle(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_idle);

	err = mk_lib_net_accept_request_wait_infinite(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_get_result(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
	mk_lang_check_return(task->m_local.m_state.m_accept_request.m_b);
	mk_lang_check_return(task->m_local.m_state.m_accept_request.m_transferred >= 0);
	mk_lang_check_return(task->m_local.m_state.m_accept_request.m_transferred < task->m_local.m_state.m_accept_request.m_out_data_len);
	err = mk_lib_net_accept_request_get_addresses(&task->m_local.m_state.m_accept_request, &task->m_local.m_state.m_client_address_local, &task->m_local.m_state.m_client_address_remote); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_task_step_e_idle;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_on_iorp_done(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(mk_lang_false){}
	#include "mk_lang_warning_msvc_pop.h"
	else if(task->m_step == mk_lib_iip_cp_client_local_task_step_e_wait_accept_ex               ){ err = mk_lib_iip_cp_client_local_task_prrw_on_iorp_done_wait_accept_ex               (task, bytes_transferred, overlapped); mk_lang_check_rereturn(err); }
	else if(task->m_step == mk_lib_iip_cp_client_local_task_step_e_wait_get_accept_ex_sock_addrs){ err = mk_lib_iip_cp_client_local_task_prrw_on_iorp_done_wait_get_accept_ex_sock_addrs(task, bytes_transferred, overlapped); mk_lang_check_rereturn(err); }
	else if(task->m_step == mk_lib_iip_cp_client_local_task_step_e_idle                         ){ err = mk_lib_iip_cp_client_local_task_prrw_on_iorp_done_idle                         (task, bytes_transferred, overlapped); mk_lang_check_rereturn(err); }
	else{ mk_lang_assert_false(); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_create_socket(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_create_socket);

	err = mk_lib_net_socket_reconstruct(&task->m_local.m_state.m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&task->m_local.m_state.m_socket); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_task_step_e_want_associate_socket;
	*step_result = mk_lib_iip_cp_client_local_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_want_associate_socket(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_want_associate_socket);

	*step_result = mk_lib_iip_cp_client_local_task_result_e_did_nothing;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_bind_socket(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_bind_socket);

	err = mk_lib_net_socket_bind(&task->m_local.m_state.m_socket, &task->m_local.m_settings.m_destination); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_task_step_e_listen_socket;
	*step_result = mk_lib_iip_cp_client_local_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_listen_socket(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_listen_socket);

	err = mk_lib_net_socket_listen(&task->m_local.m_state.m_socket); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_task_step_e_reqv_accept_ex;
	*step_result = mk_lib_iip_cp_client_local_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_reqv_accept_ex(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr;
	mk_lang_types_uchar_pt guid;
	mk_lang_types_sint_t control_code;
	mk_sl_cui_uint8_pct in_data_buf;
	mk_lang_types_sint_t in_data_len;
	mk_sl_cui_uint8_pt out_data_buf;
	mk_lang_types_sint_t out_data_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_reqv_accept_ex);

	ptr = 0;
	guid = ((mk_lang_types_uchar_pt)(&task->m_local.m_state.m_ioctl_request_input));
	guid[ptr++] = 0xf1; guid[ptr++] = 0x7d; guid[ptr++] = 0x36; guid[ptr++] = 0xb5;
	guid[ptr++] = 0xac; guid[ptr++] = 0xcb; guid[ptr++] = 0xcf; guid[ptr++] = 0x11;
	guid[ptr++] = 0x95; guid[ptr++] = 0xca; guid[ptr++] = 0x00; guid[ptr++] = 0x80;
	guid[ptr++] = 0x5f; guid[ptr++] = 0x48; guid[ptr++] = 0xa1; guid[ptr++] = 0x92;
	control_code = mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer;
	in_data_buf = ((mk_sl_cui_uint8_pct)(&task->m_local.m_state.m_ioctl_request_input));
	in_data_len = ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_ioctl_request_input)));
	out_data_buf = ((mk_sl_cui_uint8_pt)(&task->m_local.m_state.m_fn_ptr_accept_ex));
	out_data_len = ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_fn_ptr_accept_ex)));
	err = mk_lib_net_ioctl_request_reconstruct(&task->m_local.m_state.m_ioctl_request, &task->m_local.m_state.m_socket, control_code, in_data_buf, in_data_len, out_data_buf, out_data_len); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_ioctl(&task->m_local.m_state.m_socket, &task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_task_step_e_wait_accept_ex;
	*step_result = mk_lib_iip_cp_client_local_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_wait_accept_ex(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_wait_accept_ex);

	*step_result = mk_lib_iip_cp_client_local_task_result_e_would_block;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_reqv_get_accept_ex_sock_addrs(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr;
	mk_lang_types_uchar_pt guid;
	mk_lang_types_sint_t control_code;
	mk_sl_cui_uint8_pct in_data_buf;
	mk_lang_types_sint_t in_data_len;
	mk_sl_cui_uint8_pt out_data_buf;
	mk_lang_types_sint_t out_data_len;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_reqv_get_accept_ex_sock_addrs);

	ptr = 0;
	guid = ((mk_lang_types_uchar_pt)(&task->m_local.m_state.m_ioctl_request_input));
	guid[ptr++] = 0xf2; guid[ptr++] = 0x7d; guid[ptr++] = 0x36; guid[ptr++] = 0xb5;
	guid[ptr++] = 0xac; guid[ptr++] = 0xcb; guid[ptr++] = 0xcf; guid[ptr++] = 0x11;
	guid[ptr++] = 0x95; guid[ptr++] = 0xca; guid[ptr++] = 0x00; guid[ptr++] = 0x80;
	guid[ptr++] = 0x5f; guid[ptr++] = 0x48; guid[ptr++] = 0xa1; guid[ptr++] = 0x92;
	control_code = mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer;
	in_data_buf = ((mk_sl_cui_uint8_pct)(&task->m_local.m_state.m_ioctl_request_input));
	in_data_len = ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_ioctl_request_input)));
	out_data_buf = ((mk_sl_cui_uint8_pt)(&task->m_local.m_state.m_fn_ptr_get_accept_ex_sock_addrs));
	out_data_len = ((mk_lang_types_sint_t)(sizeof(task->m_local.m_state.m_fn_ptr_get_accept_ex_sock_addrs)));
	err = mk_lib_net_ioctl_request_reconstruct(&task->m_local.m_state.m_ioctl_request, &task->m_local.m_state.m_socket, control_code, in_data_buf, in_data_len, out_data_buf, out_data_len); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_ioctl(&task->m_local.m_state.m_socket, &task->m_local.m_state.m_ioctl_request); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_task_step_e_wait_get_accept_ex_sock_addrs;
	*step_result = mk_lib_iip_cp_client_local_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_wait_get_accept_ex_sock_addrs(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_wait_get_accept_ex_sock_addrs);

	*step_result = mk_lib_iip_cp_client_local_task_result_e_would_block;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_create_child_socket(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_create_child_socket);

	err = mk_lib_net_socket_reconstruct(&task->m_local.m_state.m_child, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&task->m_local.m_state.m_socket); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_task_step_e_want_associate_child;
	*step_result = mk_lib_iip_cp_client_local_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_want_associate_child(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_want_associate_child);

	*step_result = mk_lib_iip_cp_client_local_task_result_e_did_nothing;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_accept_client(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_accept_client);

	err = mk_lib_net_accept_request_reconstruct(&task->m_local.m_state.m_accept_request, &task->m_local.m_state.m_fn_ptr_accept_ex, &task->m_local.m_state.m_fn_ptr_get_accept_ex_sock_addrs, &task->m_local.m_state.m_socket, &task->m_local.m_state.m_child, &task->m_local.m_state.m_accept_buf[0], mk_lang_countof(task->m_local.m_state.m_accept_buf)); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_issue(&task->m_local.m_state.m_accept_request); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_task_step_e_idle;
	*step_result = mk_lib_iip_cp_client_local_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step_idle(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t connect_time;
	mk_lang_types_bool_t client_connected;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_task_step_e_idle);

	err = mk_lib_net_socket_get_option_connect_time(&task->m_local.m_state.m_child, &connect_time); mk_lang_check_rereturn(err);
	client_connected = connect_time != -1;
	*step_result = mk_lib_iip_cp_client_local_task_result_e_did_nothing;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_prrw_step(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_task_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_local_task_step_e_create_socket                : err = mk_lib_iip_cp_client_local_task_prrw_step_create_socket                (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_want_associate_socket        : err = mk_lib_iip_cp_client_local_task_prrw_step_want_associate_socket        (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_bind_socket                  : err = mk_lib_iip_cp_client_local_task_prrw_step_bind_socket                  (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_listen_socket                : err = mk_lib_iip_cp_client_local_task_prrw_step_listen_socket                (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_reqv_accept_ex               : err = mk_lib_iip_cp_client_local_task_prrw_step_reqv_accept_ex               (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_wait_accept_ex               : err = mk_lib_iip_cp_client_local_task_prrw_step_wait_accept_ex               (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_reqv_get_accept_ex_sock_addrs: err = mk_lib_iip_cp_client_local_task_prrw_step_reqv_get_accept_ex_sock_addrs(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_wait_get_accept_ex_sock_addrs: err = mk_lib_iip_cp_client_local_task_prrw_step_wait_get_accept_ex_sock_addrs(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_create_child_socket          : err = mk_lib_iip_cp_client_local_task_prrw_step_create_child_socket          (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_want_associate_child         : err = mk_lib_iip_cp_client_local_task_prrw_step_want_associate_child         (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_accept_client                : err = mk_lib_iip_cp_client_local_task_prrw_step_accept_client                (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_idle                         : err = mk_lib_iip_cp_client_local_task_prrw_step_idle                         (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_rw_construct(mk_lib_iip_cp_client_local_task_pt const task, mk_lib_iip_cp_client_local_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_task_prrw_construct(task, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_rw_destroy(mk_lib_iip_cp_client_local_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_rw_request_close(mk_lib_iip_cp_client_local_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_task_prrw_request_close(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_client_local_task_rw_want_associate_socket(mk_lib_iip_cp_client_local_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_task_prrw_want_associate_socket(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lib_net_socket_pt mk_lib_iip_cp_client_local_task_rw_gimme_socket(mk_lib_iip_cp_client_local_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_task_prrw_gimme_socket(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_rw_on_iorp_done(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_task_prrw_on_iorp_done(task, bytes_transferred, overlapped);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_rw_step(mk_lib_iip_cp_client_local_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_task_prrw_step(task, allow_to_block, tm, step_result);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_ptr_rw_construct_void(mk_lib_iip_cp_client_local_task_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_ptr_rw_destroy(mk_lib_iip_cp_client_local_task_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_task_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_local_task_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_ptr_rw_construct_copy(mk_lib_iip_cp_client_local_task_ppt const dst, mk_lib_iip_cp_client_local_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_ptr_rw_construct_move(mk_lib_iip_cp_client_local_task_ppt const dst, mk_lib_iip_cp_client_local_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_ptr_rw_assign_copy(mk_lib_iip_cp_client_local_task_ppt const dst, mk_lib_iip_cp_client_local_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_task_ptr_rw_assign_move(mk_lib_iip_cp_client_local_task_ppt const dst, mk_lib_iip_cp_client_local_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_local_tasks
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_local_task_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_local_task_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_local_task_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_local_task_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_local_task_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_local_task_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_local_task_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
