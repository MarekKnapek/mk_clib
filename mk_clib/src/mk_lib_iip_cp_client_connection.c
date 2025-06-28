#ifndef mk_include_guard_mk_lib_iip_cp_client_connection_c
#define mk_include_guard_mk_lib_iip_cp_client_connection_c
#include "mk_lib_iip_cp_client_connection.h"

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
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_client_session.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_parse.h"
#include "mk_lib_iip_cp_message_serialize.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_net.h"
#include "mk_sl_cui_uint8.h"


#define mk_sl_cui_t_name mk_lib_iip_cp_client_connection_handle
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_list_dbl_t_name mk_lib_iip_cp_client_connection_task_list
#define mk_sl_list_dbl_t_element_type mk_lib_iip_cp_client_connection_task_pt
#define mk_sl_list_dbl_t_mallocator_global mk_lib_iip_cp_mallocator_global
#include "mk_sl_list_dbl_inl_filec.h"
#include "mk_sl_list_dbl_inl_fileu.h"


#define mk_lib_iip_cp_client_connection_k_buffer_size (128 * 1024)
#define mk_lib_iip_cp_client_connection_k_buffer_algn ( 64 * 1024)


#if defined mk_lib_iip_cp_client_connection_debug_print_want
#if (mk_lib_iip_cp_client_connection_debug_print_want) == 0
#define mk_lib_iip_cp_client_connection_debug_print_have 0
#elif (mk_lib_iip_cp_client_connection_debug_print_want) == 1
#define mk_lib_iip_cp_client_connection_debug_print_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_lib_iip_cp_client_connection_debug_print_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lib_iip_cp_client_connection_debug_print_have 0
#else
#define mk_lib_iip_cp_client_connection_debug_print_have 1
#endif
#endif
#endif


#if mk_lib_iip_cp_client_connection_debug_print_have
#include "mk_lang_stdout.h"
#include "mk_lib_fmt.h"
#include "mk_lib_iip_cp_message_str.h"
#include "mk_lib_iip_time.h"
#include "mk_sl_time.h"
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_compute_time_offset(mk_lib_iip_cp_types_date_pct const time_server, mk_lib_iip_cp_types_date_pt const time_offset) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
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

#if mk_lib_iip_cp_client_connection_debug_print_have
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset_k_fmt[] = "Our time offset from server time is %lld ms.";
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset(mk_lib_iip_cp_types_date_pct const time_server) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_date_t time_offset;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[512];

	mk_lang_assert(time_server);

	err = mk_lib_iip_cp_client_connection_debug_print_compute_time_offset(time_server, &time_offset); mk_lang_check_rereturn(err);
	str_len = mk_lib_fmt_n_snnprintf(&str_buf[0], mk_lang_countof(str_buf), &mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset_k_fmt[0], mk_lang_countstr(mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset_k_fmt), &time_offset.m_elements[0]); mk_lang_check_return(str_len >= 1); mk_lang_assert(str_len <= mk_lang_countof(str_buf));
	err = mk_lang_stdout_println_n(&str_buf[0], str_len); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(time_server);

	((mk_lang_types_void_t)(time_server));
	return 0;
#endif
}

enum mk_lib_iip_cp_client_connection_debug_print_direction_e
{
	mk_lib_iip_cp_client_connection_debug_print_direction_e_incomming,
	mk_lib_iip_cp_client_connection_debug_print_direction_e_outgoing,
	mk_lib_iip_cp_client_connection_debug_print_direction_e_dummy_end
};
typedef enum mk_lib_iip_cp_client_connection_debug_print_direction_e mk_lib_iip_cp_client_connection_debug_print_direction_t;

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_time_now(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
	mk_sl_time_timestamp_t time_val;
	mk_lang_types_sint_t time_len;
	mk_lang_types_pchar_t time_str[mk_sl_time_k_str_len];
	mk_lang_types_sint_t err;

	mk_sl_time_timestamp_get_now(&time_val);
	time_len = mk_sl_time_timestamp_to_text(&time_val, &time_str[0], mk_lang_countof(time_str)); mk_lang_assert(time_len == mk_lang_countof(time_str));
	err = mk_lang_stdout_print_color_n(mk_lang_stdout_color_text_e_dark_magenta, &time_str[0], time_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n(" "); mk_lang_check_rereturn(err);
	return 0;
#else
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_msg(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_message_pct const msg, mk_lib_iip_cp_client_connection_debug_print_direction_t const direction) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pt target_buf;
	mk_lang_types_pchar_t str_buf[4 * 1024];
	mk_lang_types_sint_t target_len;
	mk_lang_types_sint_t str_len;
	mk_lang_stdout_color_text_t color;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(direction >= 0);
	mk_lang_assert(direction < mk_lib_iip_cp_client_connection_debug_print_direction_e_dummy_end);

	err = mk_lib_iip_cp_client_connection_debug_print_time_now(); mk_lang_check_rereturn(err);

	target_buf = &str_buf[0];
	target_len = mk_lang_countof(str_buf);
	err = mk_lib_net_socket_to_text(&task->m_connection.m_state.m_socket, target_buf, target_len, &str_len); mk_lang_check_rereturn(err); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= target_len);
	err = mk_lang_stdout_print_color_n(mk_lang_stdout_color_text_e_dark_cyan, target_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_print_lit_n(" "); mk_lang_check_rereturn(err);

	target_buf = &str_buf[0];
	target_len = mk_lang_countof(str_buf);
	color = direction == mk_lib_iip_cp_client_connection_debug_print_direction_e_incomming ? mk_lang_stdout_color_text_e_dark_green : mk_lang_stdout_color_text_e_dark_yellow;
	err = mk_lib_iip_cp_message_str_to_json_message(target_buf, target_len, &str_len, msg); mk_lang_check_rereturn(err); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= target_len);
	err = mk_lang_stdout_println_color_n(color, target_buf, str_len); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(direction >= 0);
	mk_lang_assert(direction < mk_lib_iip_cp_client_connection_debug_print_direction_e_dummy_end);

	((mk_lang_types_void_t)(task));
	((mk_lang_types_void_t)(msg));
	((mk_lang_types_void_t)(direction));
	return 0;
#endif
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_construct(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_client_connection_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(!mk_lib_net_ipv4_address_is_any(&settings->m_destination.m_ipv4_address));
	mk_lang_assert(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));
	mk_lang_assert(!mk_lib_net_tcp_port_is_zero(&settings->m_destination.m_tcp_port));
	mk_lang_assert(!mk_lib_net_tcp_port_is_max(&settings->m_destination.m_tcp_port));

	task->m_step = ((mk_lib_iip_cp_client_connection_task_step_t)(0));
	task->m_connection.m_settings.m_destination.m_ipv4_address = settings->m_destination.m_ipv4_address;
	task->m_connection.m_settings.m_destination.m_tcp_port = settings->m_destination.m_tcp_port;
	task->m_connection.m_settings.m_authentication.m_user_name = settings->m_authentication.m_user_name;
	task->m_connection.m_settings.m_authentication.m_password = settings->m_authentication.m_password;
	err = mk_lib_net_socket_construct_void(&task->m_connection.m_state.m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_connect_construct_void(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_construct_void(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_construct_void(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_tasks_rw_construct(&task->m_connection.m_state.m_sessions); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_session_idx = 0;
	task->m_connection.m_state.m_pending_send = mk_lang_false;
	task->m_connection.m_state.m_pending_recv = mk_lang_false;
	err = mk_lib_iip_cp_message_construct(&task->m_connection.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_task_list_rw_construct(&task->m_connection.m_state.m_pending_sessions_to_create); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_mallocator_global_allocate(mk_lang_roundup_add(mk_lib_iip_cp_client_connection_k_buffer_size, mk_lib_iip_cp_client_connection_k_buffer_algn), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); task->m_connection.m_state.m_buf_rcv.m_mallocation = mem; mk_lang_assert(task->m_connection.m_state.m_buf_rcv.m_mallocation); task->m_connection.m_state.m_buf_rcv.m_data = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(mem, mk_lib_iip_cp_client_connection_k_buffer_algn))); mk_lang_assert(task->m_connection.m_state.m_buf_rcv.m_data); task->m_connection.m_state.m_buf_rcv.m_used = 0;
	err = mk_lib_iip_cp_mallocator_global_allocate(mk_lang_roundup_add(mk_lib_iip_cp_client_connection_k_buffer_size, mk_lib_iip_cp_client_connection_k_buffer_algn), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); task->m_connection.m_state.m_buf_snd.m_mallocation = mem; mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_mallocation); task->m_connection.m_state.m_buf_snd.m_data = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(mem, mk_lib_iip_cp_client_connection_k_buffer_algn))); mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_data); task->m_connection.m_state.m_buf_snd.m_used = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_destroy(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_net_socket_destroy(&task->m_connection.m_state.m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_connect_destroy(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_destroy(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_destroy(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_tasks_rw_destroy(&task->m_connection.m_state.m_sessions); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_destroy(&task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_task_list_rw_destroy(&task->m_connection.m_state.m_pending_sessions_to_create); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_mallocator_global_deallocate(task->m_connection.m_state.m_buf_rcv.m_mallocation, mk_lang_roundup_add(mk_lib_iip_cp_client_connection_k_buffer_size, mk_lib_iip_cp_client_connection_k_buffer_algn)); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_mallocator_global_deallocate(task->m_connection.m_state.m_buf_snd.m_mallocation, mk_lang_roundup_add(mk_lib_iip_cp_client_connection_k_buffer_size, mk_lib_iip_cp_client_connection_k_buffer_algn)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_new_session(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pct const destination, mk_lib_iip_cp_client_session_task_ppt const session) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_task_ppt primary_ptr;
	mk_lib_iip_cp_client_session_task_pt primary_obj;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt ses;
	mk_lib_iip_cp_client_session_task_pt sss;
	mk_lang_types_void_pt mem;

	mk_lang_assert(task);
	mk_lang_assert(destination);
	mk_lang_assert(session);

	if(!mk_lib_iip_cp_client_session_tasks_rw_is_empty(&task->m_connection.m_state.m_sessions))
	{
		primary_ptr = mk_lib_iip_cp_client_session_tasks_rw_front(&task->m_connection.m_state.m_sessions); mk_lang_assert(primary_ptr); primary_obj = *primary_ptr; mk_lang_assert(primary_obj);
		mk_lang_assert(mk_lib_iip_integer_elgamal_pri_single_eq(&destination->m_key_elgamal_pri.m_data.m_val, &primary_obj->m_session.m_settings.m_destination.m_key_elgamal_pri.m_data.m_val));
		mk_lang_assert(mk_lib_iip_integer_elgamal_pub_single_eq(&destination->m_key_elgamal_pub.m_data.m_val, &primary_obj->m_session.m_settings.m_destination.m_key_elgamal_pub.m_data.m_val));
	}
	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*ses), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); ses = ((mk_lib_iip_cp_client_session_task_pt)(mem)); mk_lang_assert(ses); sss = ses; mk_lang_assert(sss);
	err = mk_lib_iip_cp_client_session_task_rw_construct(ses, destination); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_tasks_rw_push_back_move_single(&task->m_connection.m_state.m_sessions, &ses); mk_lang_check_rereturn(err);
	*session = sss;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_issue_read(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(!task->m_connection.m_state.m_pending_recv);
	mk_lang_assert(task->m_connection.m_state.m_buf_rcv.m_used >= 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_rcv.m_used < mk_lib_iip_cp_client_connection_k_buffer_size);

	err = mk_lib_net_read_request_reconstruct(&task->m_connection.m_state.m_read_request, &task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_buf_rcv.m_data[task->m_connection.m_state.m_buf_rcv.m_used], mk_lib_iip_cp_client_connection_k_buffer_size - task->m_connection.m_state.m_buf_rcv.m_used); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_recv(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_pending_recv = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_finish_read(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(task->m_connection.m_state.m_pending_recv);
	mk_lang_assert(task->m_connection.m_state.m_buf_rcv.m_used >= 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_rcv.m_used < mk_lib_iip_cp_client_connection_k_buffer_size);

	err = mk_lib_net_read_request_wait_infinite(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_get_result(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_buf_rcv.m_used += task->m_connection.m_state.m_read_request.m_transferred;
	mk_lang_assert(task->m_connection.m_state.m_buf_rcv.m_used >= 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_rcv.m_used <= mk_lib_iip_cp_client_connection_k_buffer_size);
	task->m_connection.m_state.m_pending_recv = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_issue_write(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(!task->m_connection.m_state.m_pending_send);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used > 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used <= mk_lib_iip_cp_client_connection_k_buffer_size);

	err = mk_lib_net_write_request_reconstruct(&task->m_connection.m_state.m_write_request, &task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_buf_snd.m_data[0], task->m_connection.m_state.m_buf_snd.m_used); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_send(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_pending_send = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_finish_write(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(task->m_connection.m_state.m_pending_send);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used > 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used <= mk_lib_iip_cp_client_connection_k_buffer_size);

	err = mk_lib_net_write_request_wait_infinite(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_get_result(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	mk_lang_assert(task->m_connection.m_state.m_write_request.m_transferred <= task->m_connection.m_state.m_buf_snd.m_used);
	if(task->m_connection.m_state.m_write_request.m_transferred == task->m_connection.m_state.m_buf_snd.m_used)
	{
		task->m_connection.m_state.m_buf_snd.m_used = 0;
	}
	else
	{
		mk_sl_cui_uint8_memmov_fn(&task->m_connection.m_state.m_buf_snd.m_data[0], &task->m_connection.m_state.m_buf_snd.m_data[task->m_connection.m_state.m_write_request.m_transferred], task->m_connection.m_state.m_buf_snd.m_used - task->m_connection.m_state.m_write_request.m_transferred);
		task->m_connection.m_state.m_buf_snd.m_used -= task->m_connection.m_state.m_write_request.m_transferred;
	}
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used >= 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used <= mk_lib_iip_cp_client_connection_k_buffer_size);
	task->m_connection.m_state.m_pending_send = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_parse_message(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lib_iip_cp_message_parse_error_code_t parse_error_code;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(task);
	mk_lang_assert(task->m_connection.m_state.m_buf_rcv.m_used >= 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_rcv.m_used <= mk_lib_iip_cp_client_connection_k_buffer_size);

	parse_error_code = mk_lib_iip_cp_message_parse_error_code_e_ok;
	err = mk_lib_iip_cp_message_parse_message(&task->m_connection.m_state.m_buf_rcv.m_data[0], task->m_connection.m_state.m_buf_rcv.m_used, &parse_error_code, &consumed, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err); mk_lang_check_return(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_ok); mk_lang_check_return(consumed >= 1); mk_lang_assert(consumed <= task->m_connection.m_state.m_buf_rcv.m_used); /* todo handle not enough data */
	err = mk_lib_iip_cp_client_connection_debug_print_msg(task, &task->m_connection.m_state.m_msg, mk_lib_iip_cp_client_connection_debug_print_direction_e_incomming); mk_lang_check_rereturn(err);
	if(consumed == task->m_connection.m_state.m_buf_rcv.m_used)
	{
		task->m_connection.m_state.m_buf_rcv.m_used = 0;
	}
	else
	{
		mk_sl_cui_uint8_memmov_fn(&task->m_connection.m_state.m_buf_rcv.m_data[0], &task->m_connection.m_state.m_buf_rcv.m_data[consumed], task->m_connection.m_state.m_buf_rcv.m_used - consumed);
		task->m_connection.m_state.m_buf_rcv.m_used -= consumed;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_serialize_introducer(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(task);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used >= 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used < mk_lib_iip_cp_client_connection_k_buffer_size);

	tuc = 0x2a; mk_sl_cui_uint8_from_bi_uchar(&task->m_connection.m_state.m_buf_snd.m_data[task->m_connection.m_state.m_buf_snd.m_used], &tuc);
	++task->m_connection.m_state.m_buf_snd.m_used;
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used > 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used <= mk_lib_iip_cp_client_connection_k_buffer_size);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_serialize_message_explicit(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_serialize_error_code_t serialize_error_code;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used >= 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used <= mk_lib_iip_cp_client_connection_k_buffer_size);

	serialize_error_code = mk_lib_iip_cp_message_serialize_error_code_e_ok;
	err = mk_lib_iip_cp_message_serialize_message(&task->m_connection.m_state.m_buf_snd.m_data[task->m_connection.m_state.m_buf_snd.m_used], mk_lib_iip_cp_client_connection_k_buffer_size - task->m_connection.m_state.m_buf_snd.m_used, &serialize_error_code, &consumed, msg); mk_lang_check_rereturn(err); mk_lang_check_return(serialize_error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok); mk_lang_check_return(consumed >= 1); mk_lang_assert(consumed <= mk_lib_iip_cp_client_connection_k_buffer_size - task->m_connection.m_state.m_buf_snd.m_used);
	err = mk_lib_iip_cp_client_connection_debug_print_msg(task, msg, mk_lib_iip_cp_client_connection_debug_print_direction_e_outgoing); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_buf_snd.m_used += consumed;
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used > 0);
	mk_lang_assert(task->m_connection.m_state.m_buf_snd.m_used <= mk_lib_iip_cp_client_connection_k_buffer_size);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_serialize_message_implicit(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_client_connection_task_prrw_serialize_message_explicit(task, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_prrw_session_id_to_session_obj(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_types_sessionid_pct const session_id, mk_lib_iip_cp_client_session_task_ppt const session_obj) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_task_pt res;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_session_task_ppt ses_ptr;
	mk_lib_iip_cp_client_session_task_pt ses_obj;

	mk_lang_assert(task);
	mk_lang_assert(session_id);
	mk_lang_assert(session_obj);

	/* todo something better than o(n) */
	res = mk_lang_null;
	n = mk_lib_iip_cp_client_session_tasks_rw_size(&task->m_connection.m_state.m_sessions);
	for(i = 0; i != n; ++i)
	{
		ses_ptr = mk_lib_iip_cp_client_session_tasks_rw_at(&task->m_connection.m_state.m_sessions, i); mk_lang_assert(ses_ptr); ses_obj = *ses_ptr; mk_lang_assert(ses_obj);
		if(ses_obj->m_session.m_state.m_has_id && mk_lib_iip_cp_types_sessionid_eq(&ses_obj->m_session.m_state.m_id, session_id))
		{
			res = ses_obj;
			break;
		}
	}
	*session_obj = res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_connect_request(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_connect_request);

	err = mk_lib_net_socket_reconstruct(&task->m_connection.m_state.m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&task->m_connection.m_state.m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_connect_reconstruct(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_associate_async_connect(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_connect(&task->m_connection.m_state.m_socket, &task->m_connection.m_settings.m_destination); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_connection_task_step_e_connect_finish;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_connect_finish(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_ready;
	mk_lang_types_sint_t st;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_connect_finish);

	err = mk_lib_net_async_connect_is_ready(&task->m_connection.m_state.m_async_connect, &is_ready); mk_lang_check_rereturn(err);
	if(is_ready || allow_to_block)
	{
		err = mk_lib_net_async_connect_wait_infinite(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
		err = mk_lib_net_async_connect_get_result(&task->m_connection.m_state.m_async_connect, &st); mk_lang_check_rereturn(err); mk_lang_check_return(st == 0);
		err = mk_lib_net_async_connect_reset(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
		task->m_step = mk_lib_iip_cp_client_connection_task_step_e_send_get_date_request;
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_send_get_date_request(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_send_get_date_request);

	err = mk_lib_iip_cp_client_connection_task_prrw_serialize_introducer(task); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_reconstruct(&task->m_connection.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_get_date); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_task_prrw_serialize_message_implicit(task); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_task_prrw_issue_write(task); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_connection_task_step_e_send_get_date_finish;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_send_get_date_finish(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_ready;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_send_get_date_finish);
	mk_lang_assert(task->m_connection.m_state.m_pending_send);

	err = mk_lib_net_write_request_is_ready(&task->m_connection.m_state.m_write_request, &is_ready); mk_lang_check_rereturn(err);
	if(is_ready || allow_to_block)
	{
		err = mk_lib_iip_cp_client_connection_task_prrw_finish_write(task); mk_lang_check_rereturn(err);
		task->m_step = mk_lib_iip_cp_client_connection_task_step_e_recv_set_date_request;
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_recv_set_date_request(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_recv_set_date_request);

	err = mk_lib_iip_cp_client_connection_task_prrw_issue_read(task); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_connection_task_step_e_recv_set_date_finish;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_recv_set_date_finish(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_ready;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_recv_set_date_finish);
	mk_lang_assert(task->m_connection.m_state.m_pending_recv);

	err = mk_lib_net_read_request_is_ready(&task->m_connection.m_state.m_read_request, &is_ready); mk_lang_check_rereturn(err);
	if(is_ready || allow_to_block)
	{
		err = mk_lib_iip_cp_client_connection_task_prrw_finish_read(task); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_connection_task_prrw_parse_message(task); mk_lang_check_rereturn(err);
		mk_lang_check_return(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_set_date);
		err = mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset(&task->m_connection.m_state.m_msg.m_mix.m_data.m_set_date.m_server_date); mk_lang_check_rereturn(err);
		task->m_step = mk_lib_iip_cp_client_connection_task_step_e_send_bandwidth_request;
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_send_bandwidth_request(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_send_bandwidth_request);

	err = mk_lib_iip_cp_message_reconstruct(&task->m_connection.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_task_prrw_serialize_message_implicit(task); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_task_prrw_issue_write(task); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_connection_task_step_e_send_bandwidth_finish;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_send_bandwidth_finish(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_ready;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_send_bandwidth_finish);
	mk_lang_assert(task->m_connection.m_state.m_pending_send);

	err = mk_lib_net_write_request_is_ready(&task->m_connection.m_state.m_write_request, &is_ready); mk_lang_check_rereturn(err);
	if(is_ready || allow_to_block)
	{
		err = mk_lib_iip_cp_client_connection_task_prrw_finish_write(task); mk_lang_check_rereturn(err);
		task->m_step = mk_lib_iip_cp_client_connection_task_step_e_recv_bandwidth_request;
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_recv_bandwidth_request(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_recv_bandwidth_request);

	err = mk_lib_iip_cp_client_connection_task_prrw_issue_read(task); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_connection_task_step_e_recv_bandwidth_finish;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_recv_bandwidth_finish(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_ready;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_recv_bandwidth_finish);
	mk_lang_assert(task->m_connection.m_state.m_pending_recv);

	err = mk_lib_net_read_request_is_ready(&task->m_connection.m_state.m_read_request, &is_ready); mk_lang_check_rereturn(err);
	if(is_ready || allow_to_block)
	{
		err = mk_lib_iip_cp_client_connection_task_prrw_finish_read(task); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_connection_task_prrw_parse_message(task); mk_lang_check_rereturn(err);
		mk_lang_check_return(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits);
		task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_ready(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_usize_t count;
	mk_lib_iip_cp_client_session_task_pt session_want_send;
	mk_lib_iip_cp_client_session_task_pt session_want_recv;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lib_iip_cp_client_session_task_ppt session_ptr;
	mk_lib_iip_cp_client_session_task_pt session_obj;
	mk_lib_iip_cp_client_session_task_result_t stp_res;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_ready;
	mk_lib_iip_cp_message_pt msg;
	mk_lang_types_bool_t break2;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_ready);

	count = mk_lib_iip_cp_client_session_tasks_rw_size(&task->m_connection.m_state.m_sessions);
	if(count != 0)
	{
		session_want_send = mk_lang_null;
		session_want_recv = mk_lang_null;
		n = count;
		for(i = 0; i != n; ++i)
		{
			break2 = mk_lang_false;
			idx = task->m_connection.m_state.m_session_idx % count;
			++task->m_connection.m_state.m_session_idx;
			session_ptr = mk_lib_iip_cp_client_session_tasks_rw_at(&task->m_connection.m_state.m_sessions, idx); mk_lang_assert(session_ptr); session_obj = *session_ptr; mk_lang_assert(session_obj);
			stp_res = mk_lib_iip_cp_client_session_task_result_e_dummy_end;
			err = mk_lib_iip_cp_client_session_task_rw_step(session_obj, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_session_task_result_e_dummy_end);
			switch(stp_res)
			{
				case mk_lib_iip_cp_client_session_task_result_e_did_something:
				{
					*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
					break2 = mk_lang_true;
				}
				break;
				case mk_lib_iip_cp_client_session_task_result_e_idling:
				{
				}
				break;
				case mk_lib_iip_cp_client_session_task_result_e_want_send:
				{
					if(!session_want_send)
					{
						session_want_send = session_obj;
					}
				}
				break;
				case mk_lib_iip_cp_client_session_task_result_e_want_recv:
				{
					if(!session_want_recv)
					{
						session_want_recv = session_obj;
					}
				}
				break;
				case mk_lib_iip_cp_client_session_task_result_e_dummy_end:
				{
					mk_lang_assert_false();
				}
				break;
				default:
				{
					mk_lang_assert_false();
				}
				break;
			}
			if(break2)
			{
				break;
			}
		}
		if(i == n)
		{
			mk_lang_clobber(&stp_res);
			if(session_want_send)
			{
				if(task->m_connection.m_state.m_pending_send)
				{
					err = mk_lib_net_write_request_is_ready(&task->m_connection.m_state.m_write_request, &is_ready); mk_lang_check_rereturn(err);
					if(is_ready || allow_to_block)
					{
						err = mk_lib_iip_cp_client_connection_task_prrw_finish_write(task); mk_lang_check_rereturn(err);
						*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
					}
					else
					{
						*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
					}
				}
				else
				{
					err = mk_lib_iip_cp_client_session_task_rw_gimme_msg(session_want_send, &msg); mk_lang_check_rereturn(err);
					if(msg->m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_create_session)
					{
						err = mk_lib_iip_cp_client_session_task_list_rw_push_back_copy(&task->m_connection.m_state.m_pending_sessions_to_create, &session_want_send); mk_lang_check_rereturn(err);
					}
					err = mk_lib_iip_cp_client_connection_task_prrw_serialize_message_explicit(task, msg); mk_lang_check_rereturn(err);
					err = mk_lib_iip_cp_client_connection_task_prrw_issue_write(task); mk_lang_check_rereturn(err);
					*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
				}
			}
			else if(session_want_recv)
			{
				if(task->m_connection.m_state.m_pending_recv)
				{
					err = mk_lib_net_read_request_is_ready(&task->m_connection.m_state.m_read_request, &is_ready); mk_lang_check_rereturn(err);
					if(is_ready || allow_to_block)
					{
						err = mk_lib_iip_cp_client_connection_task_prrw_finish_read(task); mk_lang_check_rereturn(err);
						task->m_step = mk_lib_iip_cp_client_connection_task_step_e_parse_incoming_msg;
						*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
					}
					else
					{
						*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
					}
				}
				else
				{
					err = mk_lib_iip_cp_client_connection_task_prrw_issue_read(task); mk_lang_check_rereturn(err);
					*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
				}
			}
			else if(stp_res == mk_lib_iip_cp_client_session_task_result_e_idling)
			{
				*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
			}
			else
			{
				mk_lang_assert_false();
			}
		}
		else
		{
			mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
		}
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_parse_incoming_msg(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_parse_incoming_msg);

	err = mk_lib_iip_cp_client_connection_task_prrw_parse_message(task); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_session_status_created(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_client_session_task_pt const session, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_session_status_pt msg_session_status;

	mk_lang_assert(task);
	mk_lang_assert(session);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_session_status);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_mix.m_data.m_session_status.m_status == mk_lib_iip_cp_message_session_status_status_id_e_created);
	mk_lang_assert(session->m_step == mk_lib_iip_cp_client_session_task_step_e_wait_msg_session_status);

	msg_session_status = &task->m_connection.m_state.m_msg.m_mix.m_data.m_session_status;
	session->m_session.m_state.m_id = msg_session_status->m_session_id;
	session->m_session.m_state.m_has_id = mk_lang_true;
	session->m_step = mk_lib_iip_cp_client_session_task_step_e_wait_msg_request_leaseset;
	task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_session_status(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_task_pt session;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_session_status_pt msg_session_status;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_session_status);

	err = mk_lib_iip_cp_client_session_task_list_rw_pop_front_move(&task->m_connection.m_state.m_pending_sessions_to_create, &session); mk_lang_check_rereturn(err); mk_lang_assert(session);
	msg_session_status = &task->m_connection.m_state.m_msg.m_mix.m_data.m_session_status;
	switch(msg_session_status->m_status)
	{
		case mk_lib_iip_cp_message_session_status_status_id_e_destroyed: mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_created  : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_session_status_created(task, session, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_updated  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_invalid  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_refused  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_request_lease_set(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_request_lease_set_pt msg_request_lease_set;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt session;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_request_lease_set);

	msg_request_lease_set = &task->m_connection.m_state.m_msg.m_mix.m_data.m_request_lease_set;
	err = mk_lib_iip_cp_client_connection_prrw_session_id_to_session_obj(task, &msg_request_lease_set->m_session_id, &session); mk_lang_check_rereturn(err); mk_lang_check_return(session);
	err = mk_lib_iip_cp_client_session_task_rw_on_msg(session, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_request_variable_lease_set(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_request_variable_lease_set_pt msg_request_variable_lease_set;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt session;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set);

	msg_request_variable_lease_set = &task->m_connection.m_state.m_msg.m_mix.m_data.m_request_variable_lease_set;
	err = mk_lib_iip_cp_client_connection_prrw_session_id_to_session_obj(task, &msg_request_variable_lease_set->m_session_id, &session); mk_lang_check_rereturn(err); mk_lang_check_return(session);
	err = mk_lib_iip_cp_client_session_task_rw_on_msg(session, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);

	switch(task->m_connection.m_state.m_msg.m_header.m_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_session_status   (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_request_lease_set(task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_request_variable_lease_set(task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_connection_task_step_e_connect_request       : err = mk_lib_iip_cp_client_connection_task_prrw_step_connect_request       (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_connect_finish        : err = mk_lib_iip_cp_client_connection_task_prrw_step_connect_finish        (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_send_get_date_request : err = mk_lib_iip_cp_client_connection_task_prrw_step_send_get_date_request (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_send_get_date_finish  : err = mk_lib_iip_cp_client_connection_task_prrw_step_send_get_date_finish  (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_recv_set_date_request : err = mk_lib_iip_cp_client_connection_task_prrw_step_recv_set_date_request (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_recv_set_date_finish  : err = mk_lib_iip_cp_client_connection_task_prrw_step_recv_set_date_finish  (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_send_bandwidth_request: err = mk_lib_iip_cp_client_connection_task_prrw_step_send_bandwidth_request(task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_send_bandwidth_finish : err = mk_lib_iip_cp_client_connection_task_prrw_step_send_bandwidth_finish (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_recv_bandwidth_request: err = mk_lib_iip_cp_client_connection_task_prrw_step_recv_bandwidth_request(task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_recv_bandwidth_finish : err = mk_lib_iip_cp_client_connection_task_prrw_step_recv_bandwidth_finish (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_ready                 : err = mk_lib_iip_cp_client_connection_task_prrw_step_ready                 (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_parse_incoming_msg    : err = mk_lib_iip_cp_client_connection_task_prrw_step_parse_incoming_msg    (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg          : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg          (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_construct(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_client_connection_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_construct(task, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_destroy(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_new_session(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pct const destination, mk_lib_iip_cp_client_session_task_ppt const session) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_new_session(task, destination, session);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_step(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_step(task, allow_to_block, step_result);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_construct_void(mk_lib_iip_cp_client_connection_task_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_destroy(mk_lib_iip_cp_client_connection_task_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_connection_task_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_construct_copy(mk_lib_iip_cp_client_connection_task_ppt const dst, mk_lib_iip_cp_client_connection_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_construct_move(mk_lib_iip_cp_client_connection_task_ppt const dst, mk_lib_iip_cp_client_connection_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_assign_copy(mk_lib_iip_cp_client_connection_task_ppt const dst, mk_lib_iip_cp_client_connection_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_assign_move(mk_lib_iip_cp_client_connection_task_ppt const dst, mk_lib_iip_cp_client_connection_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_connection_tasks
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_connection_task_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_connection_task_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_connection_task_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_connection_task_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_connection_task_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_connection_task_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_connection_task_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
