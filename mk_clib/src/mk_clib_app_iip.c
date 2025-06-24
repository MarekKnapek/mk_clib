#ifndef mk_include_guard_mk_clib_app_iip_c
#define mk_include_guard_mk_clib_app_iip_c
#include "mk_clib_app_iip.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_command_line.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_exe_name.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stdout.h"
#include "mk_lang_str_len.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_fmt.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_parse.h"
#include "mk_lib_iip_cp_message_serialize.h"
#include "mk_lib_iip_cp_message_str.h"
#include "mk_lib_iip_time.h"
#include "mk_lib_net.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_io_reader_file.h"
#include "mk_sl_io_writer_file.h"
#include "mk_sl_random.h"
#include "mk_sl_uint_more.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_debug_msg(mk_lib_iip_cp_message_pct const msg, mk_lang_types_bool_t const incomming) mk_lang_noexcept
{
	mk_lang_stdout_color_text_t color;
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_t str_buf[4 * 1024];
	mk_lang_types_sint_t str_len;

	mk_lang_assert(msg);
	mk_lang_assert(incomming == mk_lang_true || incomming == mk_lang_false);

	color = incomming ? mk_lang_stdout_color_text_e_dark_green : mk_lang_stdout_color_text_e_dark_yellow;
	err = mk_lib_iip_cp_message_str_to_json_message(&str_buf[0], mk_lang_countof(str_buf), &str_len, msg); mk_lang_check_rereturn(err); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= mk_lang_countof(str_buf));
	err = mk_lang_stdout_println_color_n(color, &str_buf[0], str_len); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_compute_time_offset(mk_lib_iip_cp_types_date_pct const time_server, mk_lib_iip_cp_types_date_pt const time_offset) mk_lang_noexcept
{
	mk_lib_iip_cp_types_date_t time_client;

	mk_lang_assert(time_server);
	mk_lang_assert(time_offset);

	mk_lib_iip_time_get_now(&time_client.m_elements[0]);
	mk_lib_iip_cp_types_date_sub3_wrap_cid_cod(&time_client, time_server, time_offset);
	return 0;
}

mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_clib_app_iip_pr_compute_and_print_time_offset_k_fmt[] = "Our time offset from server time is %lld ms.";

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_compute_and_print_time_offset(mk_lib_iip_cp_types_date_pct const time_server) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_date_t time_offset;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[512];

	mk_lang_assert(time_server);

	err = mk_clib_app_iip_pr_compute_time_offset(time_server, &time_offset); mk_lang_check_rereturn(err);
	str_len = mk_lib_fmt_n_snnprintf(&str_buf[0], mk_lang_countof(str_buf), &mk_clib_app_iip_pr_compute_and_print_time_offset_k_fmt[0], mk_lang_countstr(mk_clib_app_iip_pr_compute_and_print_time_offset_k_fmt), &time_offset.m_elements[0]); mk_lang_check_return(str_len >= 1); mk_lang_assert(str_len <= mk_lang_countof(str_buf));
	err = mk_lang_stdout_println_n(&str_buf[0], str_len); mk_lang_check_rereturn(err);
	return 0;
}


enum mk_clib_app_iip_step_result_e
{
	mk_clib_app_iip_step_result_e_did_something,
	mk_clib_app_iip_step_result_e_would_block,
	mk_clib_app_iip_step_result_e_did_nothing,
	mk_clib_app_iip_step_result_e_dummy_end
};
typedef enum mk_clib_app_iip_step_result_e mk_clib_app_iip_step_result_t;
mk_lang_typedef(mk_clib_app_iip_step_result);


union mk_clib_app_iip_buffer_4k_data_u
{
	mk_sl_cui_uint8_t m_u8s[4 * 1024];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_clib_app_iip_buffer_4k_data_u mk_clib_app_iip_buffer_4k_data_t;
struct mk_clib_app_iip_buffer_4k_s
{
	mk_lang_alignas(4 * 1024) mk_clib_app_iip_buffer_4k_data_t m_data;
};
typedef struct mk_clib_app_iip_buffer_4k_s mk_clib_app_iip_buffer_4k_t;
mk_lang_typedef(mk_clib_app_iip_buffer_4k);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_iip_connection_iip_cp_authentication_s
{
	mk_lib_iip_cp_types_string_t m_user_name;
	mk_lib_iip_cp_types_string_t m_password;
};
typedef struct mk_clib_app_iip_connection_iip_cp_authentication_s mk_clib_app_iip_connection_iip_cp_authentication_t;
mk_lang_typedef(mk_clib_app_iip_connection_iip_cp_authentication);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_iip_connection_iip_cp_settings_s
{
	mk_lib_net_destination_t m_destination;
	mk_clib_app_iip_connection_iip_cp_authentication_t m_authentication;
};
typedef struct mk_clib_app_iip_connection_iip_cp_settings_s mk_clib_app_iip_connection_iip_cp_settings_t;
mk_lang_typedef(mk_clib_app_iip_connection_iip_cp_settings);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_iip_connection_iip_cp_state_s
{
	mk_lib_net_socket_t m_socket;
	mk_lib_net_write_request_t m_write_request;
	mk_lib_net_read_request_t m_read_request;
	mk_lib_net_async_connect_t m_async_connect;
	mk_clib_app_iip_buffer_4k_t m_store;
};
typedef struct mk_clib_app_iip_connection_iip_cp_state_s mk_clib_app_iip_connection_iip_cp_state_t;
mk_lang_typedef(mk_clib_app_iip_connection_iip_cp_state);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_iip_connection_iip_cp_s
{
	mk_clib_app_iip_connection_iip_cp_settings_t m_settings;
	mk_clib_app_iip_connection_iip_cp_state_t m_state;
};
typedef struct mk_clib_app_iip_connection_iip_cp_s mk_clib_app_iip_connection_iip_cp_t;
mk_lang_typedef(mk_clib_app_iip_connection_iip_cp_state);
#include "mk_lang_warning_msvc_pop.h"

enum mk_clib_app_iip_task_connection_iip_cp_step_e
{
	mk_clib_app_iip_task_connection_iip_cp_step_e_connect_request,
	mk_clib_app_iip_task_connection_iip_cp_step_e_connect_finish,
	mk_clib_app_iip_task_connection_iip_cp_step_e_send_get_date_request,
	mk_clib_app_iip_task_connection_iip_cp_step_e_send_get_date_finish,
	mk_clib_app_iip_task_connection_iip_cp_step_e_recv_set_date_request,
	mk_clib_app_iip_task_connection_iip_cp_step_e_recv_set_date_finish,
	mk_clib_app_iip_task_connection_iip_cp_step_e_send_bandwidth_request,
	mk_clib_app_iip_task_connection_iip_cp_step_e_send_bandwidth_finish,
	mk_clib_app_iip_task_connection_iip_cp_step_e_recv_bandwidth_request,
	mk_clib_app_iip_task_connection_iip_cp_step_e_recv_bandwidth_finish,
	mk_clib_app_iip_task_connection_iip_cp_step_e_idle,
	mk_clib_app_iip_task_connection_iip_cp_step_e_dummy_end
};
typedef enum mk_clib_app_iip_task_connection_iip_cp_step_e mk_clib_app_iip_task_connection_iip_cp_step_t;

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_iip_task_connection_iip_cp_s
{
	mk_clib_app_iip_task_connection_iip_cp_step_t m_step;
	mk_clib_app_iip_connection_iip_cp_t m_connection;
};
typedef struct mk_clib_app_iip_task_connection_iip_cp_s mk_clib_app_iip_task_connection_iip_cp_t;
mk_lang_typedef(mk_clib_app_iip_task_connection_iip_cp);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_rw_construct(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_clib_app_iip_connection_iip_cp_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(!mk_lib_net_ipv4_address_is_any(&settings->m_destination.m_ipv4_address));
	mk_lang_assert(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));
	mk_lang_assert(!mk_lib_net_tcp_port_is_zero(&settings->m_destination.m_tcp_port));
	mk_lang_assert(!mk_lib_net_tcp_port_is_max(&settings->m_destination.m_tcp_port));

	task->m_step = ((mk_clib_app_iip_task_connection_iip_cp_step_t)(0));
	task->m_connection.m_settings.m_destination.m_ipv4_address = settings->m_destination.m_ipv4_address;
	task->m_connection.m_settings.m_destination.m_tcp_port = settings->m_destination.m_tcp_port;
	task->m_connection.m_settings.m_authentication.m_user_name = settings->m_authentication.m_user_name;
	task->m_connection.m_settings.m_authentication.m_password = settings->m_authentication.m_password;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_rw_destroy(mk_clib_app_iip_task_connection_iip_cp_pt const task) mk_lang_noexcept
{
	mk_lang_assert(task);

	((mk_lang_types_void_t)(task));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_connect_request(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_connect_request);

	err = mk_lib_net_socket_construct(&task->m_connection.m_state.m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&task->m_connection.m_state.m_socket); mk_lang_check_rereturn(err);

	err = mk_lib_net_async_connect_construct(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_associate_async_connect(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_connect(&task->m_connection.m_state.m_socket, &task->m_connection.m_settings.m_destination); mk_lang_check_rereturn(err);

	task->m_step = mk_clib_app_iip_task_connection_iip_cp_step_e_connect_finish;
	*step_result = mk_clib_app_iip_step_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_connect_finish(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t st;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_connect_finish);

	if(allow_to_block)
	{
		err = mk_lib_net_async_connect_wait_infinite(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
		err = mk_lib_net_async_connect_get_result(&task->m_connection.m_state.m_async_connect, &st); mk_lang_check_rereturn(err); mk_lang_check_return(st == 0);
		err = mk_lib_net_async_connect_destroy(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
		task->m_step = mk_clib_app_iip_task_connection_iip_cp_step_e_send_get_date_request;
		*step_result = mk_clib_app_iip_step_result_e_did_something;
	}
	else
	{
		*step_result = mk_clib_app_iip_step_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_send_get_date_request(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr;
	mk_lang_types_uchar_t tuc;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_t msg;
	mk_lib_iip_cp_message_serialize_error_code_t serialize_error_code;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_send_get_date_request);

	ptr = 0;
	tuc = 0x2a; mk_sl_cui_uint8_from_bi_uchar(&task->m_connection.m_state.m_store.m_data.m_u8s[ptr], &tuc); ptr += 1;
	err = mk_lib_iip_cp_message_construct(&msg, mk_lib_iip_cp_message_message_type_id_e_get_date); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_serialize_message(&task->m_connection.m_state.m_store.m_data.m_u8s[ptr], mk_lang_countof(task->m_connection.m_state.m_store.m_data.m_u8s) - ptr, &serialize_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(serialize_error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok); mk_lang_check_return(consumed >= 1); mk_lang_assert(consumed <= mk_lang_countof(task->m_connection.m_state.m_store.m_data.m_u8s) - ptr); ptr += consumed;
	err = mk_clib_app_iip_debug_msg(&msg, mk_lang_false); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);

	err = mk_lib_net_write_request_construct(&task->m_connection.m_state.m_write_request, &task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_store.m_data.m_u8s[0], ptr); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_send(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);

	task->m_step = mk_clib_app_iip_task_connection_iip_cp_step_e_send_get_date_finish;
	*step_result = mk_clib_app_iip_step_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_send_get_date_finish(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_send_get_date_finish);

	if(allow_to_block)
	{
		err = mk_lib_net_write_request_wait_infinite(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
		err = mk_lib_net_write_request_get_result(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
		task->m_step = mk_clib_app_iip_task_connection_iip_cp_step_e_recv_set_date_request;
		*step_result = mk_clib_app_iip_step_result_e_did_something;
	}
	else
	{
		*step_result = mk_clib_app_iip_step_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_recv_set_date_request(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_recv_set_date_request);

	err = mk_lib_net_read_request_construct(&task->m_connection.m_state.m_read_request, &task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_store.m_data.m_u8s[0], mk_lang_countof(task->m_connection.m_state.m_store.m_data.m_u8s)); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_recv(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	task->m_step = mk_clib_app_iip_task_connection_iip_cp_step_e_recv_set_date_finish;
	*step_result = mk_clib_app_iip_step_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_recv_set_date_finish(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_parse_error_code_t parse_error_code;
	mk_lang_types_sint_t consumed;
	mk_lib_iip_cp_message_t msg;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_recv_set_date_finish);

	if(allow_to_block)
	{
		err = mk_lib_net_read_request_wait_infinite(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
		err = mk_lib_net_read_request_get_result(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
		parse_error_code = mk_lib_iip_cp_message_parse_error_code_e_ok;
		err = mk_lib_iip_cp_message_parse_message(&task->m_connection.m_state.m_store.m_data.m_u8s[0], task->m_connection.m_state.m_read_request.m_transferred, &parse_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_ok); mk_lang_check_return(consumed >= 1); mk_lang_assert(consumed <= task->m_connection.m_state.m_read_request.m_transferred);
		err = mk_clib_app_iip_debug_msg(&msg, mk_lang_true); mk_lang_check_rereturn(err);
		mk_lang_check_return(msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_set_date);
		err = mk_clib_app_iip_pr_compute_and_print_time_offset(&msg.m_mix.m_data.m_set_date.m_server_date); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);
		task->m_step = mk_clib_app_iip_task_connection_iip_cp_step_e_send_bandwidth_request;
		*step_result = mk_clib_app_iip_step_result_e_did_something;
	}
	else
	{
		*step_result = mk_clib_app_iip_step_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_send_bandwidth_request(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_t msg;
	mk_lib_iip_cp_message_serialize_error_code_t serialize_error_code;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_send_bandwidth_request);

	err = mk_lib_iip_cp_message_construct(&msg, mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits); mk_lang_check_rereturn(err);
	serialize_error_code = mk_lib_iip_cp_message_serialize_error_code_e_ok;
	err = mk_lib_iip_cp_message_serialize_message(&task->m_connection.m_state.m_store.m_data.m_u8s[0], mk_lang_countof(task->m_connection.m_state.m_store.m_data.m_u8s), &serialize_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(serialize_error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok); mk_lang_check_return(consumed >= 1); mk_lang_assert(consumed <= mk_lang_countof(task->m_connection.m_state.m_store.m_data.m_u8s));
	err = mk_clib_app_iip_debug_msg(&msg, mk_lang_false); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);

	err = mk_lib_net_write_request_construct(&task->m_connection.m_state.m_write_request, &task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_store.m_data.m_u8s[0], consumed); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_send(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);

	task->m_step = mk_clib_app_iip_task_connection_iip_cp_step_e_send_bandwidth_finish;
	*step_result = mk_clib_app_iip_step_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_send_bandwidth_finish(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_send_bandwidth_finish);

	if(allow_to_block)
	{
		err = mk_lib_net_write_request_wait_infinite(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
		err = mk_lib_net_write_request_get_result(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
		task->m_step = mk_clib_app_iip_task_connection_iip_cp_step_e_recv_bandwidth_request;
		*step_result = mk_clib_app_iip_step_result_e_did_something;
	}
	else
	{
		*step_result = mk_clib_app_iip_step_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_recv_bandwidth_request(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_recv_bandwidth_request);

	err = mk_lib_net_read_request_construct(&task->m_connection.m_state.m_read_request, &task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_store.m_data.m_u8s[0], mk_lang_countof(task->m_connection.m_state.m_store.m_data.m_u8s)); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_recv(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	task->m_step = mk_clib_app_iip_task_connection_iip_cp_step_e_recv_bandwidth_finish;
	*step_result = mk_clib_app_iip_step_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_recv_bandwidth_finish(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_parse_error_code_t parse_error_code;
	mk_lang_types_sint_t consumed;
	mk_lib_iip_cp_message_t msg;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_recv_bandwidth_finish);

	if(allow_to_block)
	{
		err = mk_lib_net_read_request_wait_infinite(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
		err = mk_lib_net_read_request_get_result(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
		parse_error_code = mk_lib_iip_cp_message_parse_error_code_e_ok;
		err = mk_lib_iip_cp_message_parse_message(&task->m_connection.m_state.m_store.m_data.m_u8s[0], task->m_connection.m_state.m_read_request.m_transferred, &parse_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_ok); mk_lang_check_return(consumed >= 1); mk_lang_assert(consumed <= task->m_connection.m_state.m_read_request.m_transferred);
		err = mk_clib_app_iip_debug_msg(&msg, mk_lang_true); mk_lang_check_rereturn(err);
		mk_lang_check_return(msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits);
		err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);
		task->m_step = mk_clib_app_iip_task_connection_iip_cp_step_e_idle;
		*step_result = mk_clib_app_iip_step_result_e_did_something;
	}
	else
	{
		*step_result = mk_clib_app_iip_step_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_prrw_step_idle(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_clib_app_iip_task_connection_iip_cp_step_e_idle);

	*step_result = mk_clib_app_iip_step_result_e_did_nothing;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_task_connection_iip_cp_rw_step(mk_clib_app_iip_task_connection_iip_cp_pt const task, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_clib_app_iip_task_connection_iip_cp_step_e_connect_request       : err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_connect_request       (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_connect_finish        : err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_connect_finish        (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_send_get_date_request : err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_send_get_date_request (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_send_get_date_finish  : err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_send_get_date_finish  (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_recv_set_date_request : err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_recv_set_date_request (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_recv_set_date_finish  : err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_recv_set_date_finish  (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_send_bandwidth_request: err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_send_bandwidth_request(task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_send_bandwidth_finish : err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_send_bandwidth_finish (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_recv_bandwidth_request: err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_recv_bandwidth_request(task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_recv_bandwidth_finish : err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_recv_bandwidth_finish (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_idle                  : err = mk_clib_app_iip_task_connection_iip_cp_prrw_step_idle                  (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end); break;
		case mk_clib_app_iip_task_connection_iip_cp_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_iip_s
{
	mk_clib_app_iip_task_connection_iip_cp_t m_connection;
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_t m_iip_destination;
	mk_lib_iip_cp_types_sessionid_t m_session_id;
};
typedef struct mk_clib_app_iip_s mk_clib_app_iip_t;
mk_lang_typedef(mk_clib_app_iip);
#include "mk_lang_warning_msvc_pop.h"


/*
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_send_create_session_request(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_t msg;
	mk_lib_iip_cp_message_create_session_pt create_session;
	mk_lib_iip_cp_message_serialize_error_code_t serialize_error_code;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_send_create_session_request);

	err = mk_lib_iip_cp_message_construct(&msg, mk_lib_iip_cp_message_message_type_id_e_create_session); mk_lang_check_rereturn(err);
	create_session = &msg.m_mix.m_data.m_create_session;
	create_session->m_session_config.m_destination = app->m_iip_destination;
	mk_lib_iip_time_get_now(&create_session->m_session_config.m_creation_date.m_elements[0]);

	serialize_error_code = mk_lib_iip_cp_message_serialize_error_code_e_ok;
	err = mk_lib_iip_cp_message_serialize_message(&app->m_connection.m_state.m_store.m_data.m_u8s[0], mk_lang_countof(app->m_connection.m_state.m_store.m_data.m_u8s), &serialize_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(serialize_error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	err = mk_clib_app_iip_debug_msg(&msg, mk_lang_false); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);

	err = mk_lib_net_write_request_construct(&app->m_connection.m_state.m_write_request, &app->m_connection.m_state.m_socket, &app->m_connection.m_state.m_store.m_data.m_u8s[0], consumed); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_send(&app->m_connection.m_state.m_socket, &app->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_send_create_session_finish(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_send_create_session_finish);

	err = mk_lib_net_write_request_wait_infinite(&app->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_get_result(&app->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_recv_session_status_request(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_recv_session_status_request);

	err = mk_lib_net_read_request_construct(&app->m_connection.m_state.m_read_request, &app->m_connection.m_state.m_socket, &app->m_connection.m_state.m_store.m_data.m_u8s[0], mk_lang_countof(app->m_connection.m_state.m_store.m_data.m_u8s)); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_recv(&app->m_connection.m_state.m_socket, &app->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_recv_session_status_finish(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_parse_error_code_t parse_error_code;
	mk_lang_types_sint_t consumed;
	mk_lib_iip_cp_message_t msg;
	mk_lib_iip_cp_message_session_status_pt session_status;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_recv_session_status_finish);

	err = mk_lib_net_read_request_wait_infinite(&app->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_get_result(&app->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	parse_error_code = mk_lib_iip_cp_message_parse_error_code_e_ok;
	err = mk_lib_iip_cp_message_parse_message(&app->m_connection.m_state.m_store.m_data.m_u8s[0], app->m_connection.m_state.m_read_request.m_transferred, &parse_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	err = mk_clib_app_iip_debug_msg(&msg, mk_lang_true); mk_lang_check_rereturn(err);
	mk_lang_check_return(msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_session_status);
	session_status = &msg.m_mix.m_data.m_session_status;
	mk_lang_check_return(session_status->m_status == mk_lib_iip_cp_message_session_status_status_id_e_created);
	app->m_session_id = session_status->m_session_id;
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}
*/

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_generate_new_destination(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt destination;
	mk_lang_types_sint_t err;

	mk_lang_assert(app);

	destination = &app->m_iip_destination;
	err = mk_lib_iip_crypt_elgamal_key_pri_generate_random(&destination->m_key_elgamal_pri); mk_lang_check_rereturn(err);
	mk_lib_iip_crypt_elgamal_key_pri_compute_public(&destination->m_key_elgamal_pri, &destination->m_key_elgamal_pub);
	err = mk_lib_iip_crypt_dsa_sha1_key_pri_generate_random(&destination->m_key_dsa_sha1_pri); mk_lang_check_rereturn(err);
	mk_lib_iip_crypt_dsa_sha1_key_pri_compute_public(&destination->m_key_dsa_sha1_pri, &destination->m_key_dsa_sha1_pub);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_save_destination_pri_only(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt destination;
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v)))];
	mk_sl_cui_uint8_t bin_buf[mk_lang_countof(str_buf)];
	mk_lang_types_sint_t written;

	mk_lang_assert(app);

	destination = &app->m_iip_destination;
	err = mk_sl_io_writer_file_open_n(&writer, "destination.txt"); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_integer_elgamal_pri_single_to_str_hexf_n(&destination->m_key_elgamal_pri.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_to_str_hexf_n(&destination->m_key_dsa_sha1_pri.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_save_destination_pri_pub(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt destination;
	mk_lang_types_sint_t err;
	mk_sl_io_writer_file_t writer;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[mk_lang_max(mk_lang_max(mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pub_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pub_single_strlen_hex_v)))];
	mk_sl_cui_uint8_t bin_buf[mk_lang_countof(str_buf)];
	mk_lang_types_sint_t written;

	mk_lang_assert(app);

	destination = &app->m_iip_destination;
	err = mk_sl_io_writer_file_open_n(&writer, "destination.txt"); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_integer_elgamal_pri_single_to_str_hexf_n(&destination->m_key_elgamal_pri.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_to_str_hexf_n(&destination->m_key_dsa_sha1_pri.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_integer_elgamal_pub_single_to_str_hexf_n(&destination->m_key_elgamal_pub.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pub_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_len = mk_lib_iip_integer_dsa_sha1_pub_single_to_str_hexf_n(&destination->m_key_dsa_sha1_pub.m_data.m_val, &str_buf[0], mk_lang_countof(str_buf)); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pub_single_strlen_hex_v);
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	str_buf[0] = '\x0a'; str_len = 1;
	mk_sl_cui_uint8_from_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_sl_io_writer_file_write(&writer, &bin_buf[0], str_len, &written); mk_lang_check_rereturn(err); mk_lang_check_return(written == str_len);

	err = mk_sl_io_writer_file_close(&writer); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_generate_and_save_destination_pri_only(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);

	err = mk_clib_app_iip_pr_generate_new_destination(app); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_pr_save_destination_pri_only(app); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_generate_and_save_destination_pri_pub(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);

	err = mk_clib_app_iip_pr_generate_new_destination(app); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_pr_save_destination_pri_pub(app); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_load_destination_pri_only(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt destination;
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t reader;
	mk_lang_types_sint_t str_len;
	mk_sl_cui_uint8_t bin_buf[mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v)))];
	mk_lang_types_sint_t read;
	mk_lang_types_pchar_t str_buf[mk_lang_countof(bin_buf)];
	mk_lang_types_bool_t is_valid;

	mk_lang_assert(app);

	destination = &app->m_iip_destination;
	err = mk_sl_io_reader_file_open_n(&reader, "destination.txt"); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_elgamal_pri_single_from_str_hex_n(&destination->m_key_elgamal_pri.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_from_str_hex_n(&destination->m_key_dsa_sha1_pri.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v);

	err = mk_sl_io_reader_file_close(&reader); mk_lang_check_rereturn(err);

	is_valid = mk_lib_iip_crypt_dsa_sha1_key_pri_is_valid(&destination->m_key_dsa_sha1_pri); mk_lang_check_return(is_valid);
	mk_lib_iip_crypt_elgamal_key_pri_compute_public(&destination->m_key_elgamal_pri, &destination->m_key_elgamal_pub);
	mk_lib_iip_crypt_dsa_sha1_key_pri_compute_public(&destination->m_key_dsa_sha1_pri, &destination->m_key_dsa_sha1_pub);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_load_destination_pri_pub(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pt destination;
	mk_lang_types_sint_t err;
	mk_sl_io_reader_file_t reader;
	mk_lang_types_sint_t str_len;
	mk_sl_cui_uint8_t bin_buf[mk_lang_max(mk_lang_max(mk_lang_max(((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v)), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_integer_elgamal_pub_single_strlen_hex_v))), ((mk_lang_types_sint_t)(mk_lib_iip_integer_dsa_sha1_pub_single_strlen_hex_v)))];
	mk_lang_types_sint_t read;
	mk_lang_types_pchar_t str_buf[mk_lang_countof(bin_buf)];

	mk_lang_assert(app);

	destination = &app->m_iip_destination;
	err = mk_sl_io_reader_file_open_n(&reader, "destination.txt"); mk_lang_check_rereturn(err);

	str_len = mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_elgamal_pri_single_from_str_hex_n(&destination->m_key_elgamal_pri.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pri_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_dsa_sha1_pri_single_from_str_hex_n(&destination->m_key_dsa_sha1_pri.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pri_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_integer_elgamal_pub_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_elgamal_pub_single_from_str_hex_n(&destination->m_key_elgamal_pub.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_elgamal_pub_single_strlen_hex_v);

	str_len = 1;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	mk_lang_check_return(str_buf[0] == '\x0a');

	str_len = mk_lib_iip_integer_dsa_sha1_pub_single_strlen_hex_v;
	err = mk_sl_io_reader_file_read(&reader, &bin_buf[0], str_len, &read); mk_lang_check_rereturn(err); mk_lang_check_return(read == str_len);
	mk_sl_cui_uint8_to_bi_pchar_many(&bin_buf[0], &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	str_len = mk_lib_iip_integer_dsa_sha1_pub_single_from_str_hex_n(&destination->m_key_dsa_sha1_pub.m_data.m_val, &str_buf[0], str_len); mk_lang_assert(str_len == mk_lib_iip_integer_dsa_sha1_pub_single_strlen_hex_v);

	err = mk_sl_io_reader_file_close(&reader); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step(mk_clib_app_iip_pt const app, mk_lang_types_bool_t const allow_to_block, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);

	err = mk_clib_app_iip_task_connection_iip_cp_rw_step(&app->m_connection, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_clib_app_iip_step_result_e_dummy_end);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_construct(mk_clib_app_iip_pt const app, mk_clib_app_iip_connection_iip_cp_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(settings);

	err = mk_clib_app_iip_task_connection_iip_cp_rw_construct(&app->m_connection, settings); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destroy(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);

	err = mk_clib_app_iip_task_connection_iip_cp_rw_destroy(&app->m_connection); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_run_non_block(mk_clib_app_iip_pt const app, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_bool_t allow_to_block;
	mk_clib_app_iip_step_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);

	allow_to_block = mk_lang_false;
	do
	{
		stp_res = mk_clib_app_iip_step_result_e_dummy_end;
		err = mk_clib_app_iip_pr_step(app, allow_to_block, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_clib_app_iip_step_result_e_dummy_end);
	}while(step_result == mk_clib_app_iip_step_result_e_did_something);
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_run_single_block(mk_clib_app_iip_pt const app, mk_clib_app_iip_step_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_bool_t allow_to_block;
	mk_clib_app_iip_step_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_clib_app_iip_step_result_e_dummy_end);

	allow_to_block = mk_lang_true;
	stp_res = mk_clib_app_iip_step_result_e_dummy_end;
	err = mk_clib_app_iip_pr_step(app, allow_to_block, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_clib_app_iip_step_result_e_dummy_end);
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_run(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_clib_app_iip_step_result_t step_result;
	mk_lang_types_sint_t err;

	mk_lang_assert(app);

	for(;;)
	{
		step_result = mk_clib_app_iip_step_result_e_dummy_end;
		err = mk_clib_app_iip_pr_run_non_block(app, &step_result); mk_lang_check_rereturn(err); mk_lang_assert(step_result != mk_clib_app_iip_step_result_e_dummy_end);
		if(step_result == mk_clib_app_iip_step_result_e_did_nothing)
		{
			break;
		}
		step_result = mk_clib_app_iip_step_result_e_dummy_end;
		err = mk_clib_app_iip_pr_run_single_block(app, &step_result); mk_lang_check_rereturn(err); mk_lang_assert(step_result != mk_clib_app_iip_step_result_e_dummy_end);
		if(step_result == mk_clib_app_iip_step_result_e_did_nothing)
		{
			break;
		}
	}
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_work(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_pchar_pct port_buf;
	mk_lang_types_sint_t port_len;
	mk_lang_types_pchar_pct address_buf;
	mk_lang_types_sint_t address_len;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t consumed;
	mk_clib_app_iip_t app;
	mk_lang_types_pchar_t address_store[64];
	mk_lang_types_pchar_t port_store[64];
	mk_clib_app_iip_connection_iip_cp_settings_t settings;

	mk_lang_assert(argc == 3);
	mk_lang_assert(argv);
	mk_lang_assert(lens);

	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_assert(argv[i]);
		mk_lang_assert(argv[i][0] != mk_lang_tchar_c('\0'));
		mk_lang_assert(lens[i] >= 1);
	}

	address_len = mk_lang_str_len_t(argv[1]);
	address_len = mk_lang_min(address_len, mk_lang_countof(address_store));
	mk_lang_tchar_to_bi_pchar_many(argv[1], &address_store[0], address_len);
	address_buf = &address_store[0];

	port_len = mk_lang_str_len_t(argv[2]);
	port_len = mk_lang_min(port_len, mk_lang_countof(port_store));
	mk_lang_tchar_to_bi_pchar_many(argv[2], &port_store[0], port_len);
	port_buf = &port_store[0];

	err = mk_lib_net_ipv4_address_parse_pc(&settings.m_destination.m_ipv4_address, address_buf, address_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1 && consumed <= address_len);
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_any(&settings.m_destination.m_ipv4_address));
	mk_lang_check_return(!mk_lib_net_ipv4_address_is_none(&settings.m_destination.m_ipv4_address));
	err = mk_lib_net_tcp_port_parse_pc(&settings.m_destination.m_tcp_port, port_buf, port_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1 && consumed <= port_len);
	mk_lang_check_return(!mk_lib_net_tcp_port_is_zero(&settings.m_destination.m_tcp_port));
	mk_lang_check_return(!mk_lib_net_tcp_port_is_max(&settings.m_destination.m_tcp_port));
	settings.m_authentication.m_user_name.m_len = 0;
	settings.m_authentication.m_password.m_len = 0;

	err = mk_clib_app_iip_construct(&app, &settings); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_pr_load_destination_pri_pub(&app); mk_lang_check_rereturn(err);
	/*err = mk_clib_app_iip_pr_generate_and_save_destination_pri_only(&app); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_pr_generate_and_save_destination_pri_pub(&app); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_pr_load_destination_pri_only(&app); mk_lang_check_rereturn(err);*/
	/*err = mk_clib_app_iip_pr_save_destination_pri_pub(&app); mk_lang_check_rereturn(err);*/
	err = mk_clib_app_iip_run(&app); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_destroy(&app); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_n("Gud.");
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_usage(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_tchar_pct exe_name;
	mk_lang_types_sint_t exe_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t len;
	mk_lang_tchar_t buf[4 * 1024];
	mk_sl_cui_uint64_t time_val;
	mk_lang_types_pchar_t time_str[24];
	mk_lang_types_sint_t time_len;

	mk_lang_assert(argc == 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	exe_name = mk_lang_exe_name_get_t(argv[0]); mk_lang_check_return(exe_name); mk_lang_check_return(exe_name[0] != mk_lang_tchar_c('\0'));
	exe_len = lens[0] - ((mk_lang_types_sint_t)(exe_name - argv[0])); mk_lang_check_return(exe_len >= 1);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("iip")); mk_lang_check_rereturn(err);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("exe name: %t")), exe_name, exe_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	mk_lib_iip_time_get_now(&time_val);
	mk_lib_iip_time_to_text(&time_val, &time_str[0], mk_lang_countof(time_str), &time_len);
	len = mk_lib_fmt_t_snnprintf(&buf[0], mk_lang_countof(buf), mk_lib_fmt_lit_and_len(mk_lang_tchar_c("time: %ht")), &time_str[0], time_len); mk_lang_check_return(len >= 1); err = mk_lang_stdout_println_t(&buf[0], len); mk_lang_check_rereturn(err);
	err = mk_lang_stdout_println_lit_t(mk_lang_tchar_c("")); mk_lang_check_rereturn(err);
	return 0;
}


#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_wargs(mk_lang_types_sint_t const argc, mk_lang_types_wchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	if(argc == 1)
	{
		err = mk_clib_app_iip_usage(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 3);
		err = mk_clib_app_iip_work(argc, argv, lens); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_iip_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	mk_lang_assert(peb);

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_sl_random_init(); mk_lang_check_rereturn(err);
	err = mk_lib_net_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_wargs(argc, &argv[0], &lens[0]);
	err = mk_lib_net_deinit(); mk_lang_check_rereturn(err);
	err = mk_sl_random_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_iip_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t lens[3];

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_sl_random_init(); mk_lang_check_rereturn(err);
	err = mk_lib_net_init(); mk_lang_check_rereturn(err);
	if(argc == 1)
	{
		lens[0] = mk_lang_str_len_n(argv[0]);
		err = mk_clib_app_iip_usage(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_return(argc == 3);
		lens[0] = mk_lang_str_len_t(argv[0]);
		lens[1] = mk_lang_str_len_t(argv[1]);
		lens[2] = mk_lang_str_len_t(argv[2]);
		err = mk_clib_app_iip_work(argc, argv, &lens[0]); mk_lang_check_rereturn(err);
	}
	err = mk_lib_net_deinit(); mk_lang_check_rereturn(err);
	err = mk_sl_random_deinit(); mk_lang_check_rereturn(err);
	return 0;
}


#endif


#endif
