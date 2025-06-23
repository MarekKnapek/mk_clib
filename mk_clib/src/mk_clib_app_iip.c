#ifndef mk_include_guard_mk_clib_app_iip_c
#define mk_include_guard_mk_clib_app_iip_c
#include "mk_clib_app_iip.h"

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
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_fmt.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_parse.h"
#include "mk_lib_iip_cp_message_serialize.h"
#include "mk_lib_iip_cp_message_str.h"
#include "mk_lib_iip_time.h"
#include "mk_sl_cui_uint64.h"


#pragma comment(lib, "ws2_32.lib")


#include "mk_lib_net.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_lang_types.h"
#include "mk_lang_typedef.h"


enum mk_clib_app_iip_step_e
{
	mk_clib_app_iip_step_e_connect_beg,
	mk_clib_app_iip_step_e_connect_wait,
	mk_clib_app_iip_step_e_get_date_beg,
	mk_clib_app_iip_step_e_get_date_end,
	mk_clib_app_iip_step_e_set_date_beg,
	mk_clib_app_iip_step_e_set_date_end,
	mk_clib_app_iip_step_e_req_bw_beg,
	mk_clib_app_iip_step_e_req_bw_end,
	mk_clib_app_iip_step_e_rec_bw_beg,
	mk_clib_app_iip_step_e_rec_bw_end,
	mk_clib_app_iip_step_e_dummy_end
};
typedef enum mk_clib_app_iip_step_e mk_clib_app_iip_step_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_iip_s
{
	mk_clib_app_iip_step_t m_step;
	mk_lib_net_destination_t m_cp_destination;
	mk_lib_net_socket_t m_socket;
	mk_lib_net_write_request_t m_write_request;
	mk_lib_net_read_request_t m_read_request;
	mk_sl_cui_uint8_t m_store[4 * 1024];
	mk_lib_net_async_connect_t m_async_connect;
};
typedef struct mk_clib_app_iip_s mk_clib_app_iip_t;
mk_lang_typedef(mk_clib_app_iip);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_debug_msg(mk_lib_iip_cp_message_pct const msg) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_t str_buf[4 * 1024];
	mk_lang_types_sint_t str_len;

	mk_lang_assert(msg);

	err = mk_lib_iip_cp_message_str_to_json_message(&str_buf[0], mk_lang_countof(str_buf), &str_len, msg); mk_lang_check_rereturn(err); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= mk_lang_countof(str_buf));
	err = mk_lang_stdout_println_n(&str_buf[0], str_len); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_connect_beg(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_connect_beg);

	err = mk_lib_net_socket_construct(&app->m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&app->m_socket); mk_lang_check_rereturn(err);

	err = mk_lib_net_async_connect_construct(&app->m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_associate_async_connect(&app->m_socket, &app->m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_connect(&app->m_socket, &app->m_cp_destination); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_connect_wait(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t st;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_connect_wait);

	err = mk_lib_net_async_connect_wait_infinite(&app->m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_connect_get_result(&app->m_async_connect, &st); mk_lang_check_rereturn(err); mk_lang_check_return(st == 0);
	err = mk_lib_net_async_connect_destroy(&app->m_async_connect); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_get_date_beg(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_t msg;
	mk_lib_iip_cp_message_serialize_error_code_t serialize_error_code;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_get_date_beg);

	tuc = 0x2a; mk_sl_cui_uint8_from_bi_uchar(&app->m_store[0], &tuc);
	err = mk_lib_iip_cp_message_construct(&msg, mk_lib_iip_cp_message_message_type_id_e_get_date); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_serialize_message(&app->m_store[1], mk_lang_countof(app->m_store) - 1, &serialize_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(serialize_error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	err = mk_clib_app_iip_debug_msg(&msg); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);

	err = mk_lib_net_write_request_construct(&app->m_write_request, &app->m_socket, &app->m_store[0], 1 + consumed); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_send(&app->m_socket, &app->m_write_request); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_get_date_end(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_get_date_end);

	err = mk_lib_net_write_request_wait_infinite(&app->m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_get_result(&app->m_write_request); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_set_date_beg(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_set_date_beg);

	err = mk_lib_net_read_request_construct(&app->m_read_request, &app->m_socket, &app->m_store[0], mk_lang_countof(app->m_store)); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_recv(&app->m_socket, &app->m_read_request); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_set_date_end(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_parse_error_code_t parse_error_code;
	mk_lang_types_sint_t consumed;
	mk_lib_iip_cp_message_t msg;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_set_date_end);

	err = mk_lib_net_read_request_wait_infinite(&app->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_get_result(&app->m_read_request); mk_lang_check_rereturn(err);
	parse_error_code = mk_lib_iip_cp_message_parse_error_code_e_ok;
	err = mk_lib_iip_cp_message_parse_message(&app->m_store[0], app->m_read_request.m_transferred, &parse_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	err = mk_clib_app_iip_debug_msg(&msg); mk_lang_check_rereturn(err);
	mk_lang_check_return(msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_set_date);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_req_bw_beg(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_t msg;
	mk_lib_iip_cp_message_serialize_error_code_t serialize_error_code;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_req_bw_beg);

	err = mk_lib_iip_cp_message_construct(&msg, mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits); mk_lang_check_rereturn(err);
	serialize_error_code = mk_lib_iip_cp_message_serialize_error_code_e_ok;
	err = mk_lib_iip_cp_message_serialize_message(&app->m_store[0], mk_lang_countof(app->m_store), &serialize_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(serialize_error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	err = mk_clib_app_iip_debug_msg(&msg); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);

	err = mk_lib_net_write_request_construct(&app->m_write_request, &app->m_socket, &app->m_store[0], consumed); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_send(&app->m_socket, &app->m_write_request); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_req_bw_end(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_req_bw_end);

	err = mk_lib_net_write_request_wait_infinite(&app->m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_get_result(&app->m_write_request); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_rec_bw_beg(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_rec_bw_beg);

	err = mk_lib_net_read_request_construct(&app->m_read_request, &app->m_socket, &app->m_store[0], mk_lang_countof(app->m_store)); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_recv(&app->m_socket, &app->m_read_request); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step_rec_bw_end(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_parse_error_code_t parse_error_code;
	mk_lang_types_sint_t consumed;
	mk_lib_iip_cp_message_t msg;

	mk_lang_assert(app);
	mk_lang_assert(app->m_step == mk_clib_app_iip_step_e_rec_bw_end);

	err = mk_lib_net_read_request_wait_infinite(&app->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_get_result(&app->m_read_request); mk_lang_check_rereturn(err);
	parse_error_code = mk_lib_iip_cp_message_parse_error_code_e_ok;
	err = mk_lib_iip_cp_message_parse_message(&app->m_store[0], app->m_read_request.m_transferred, &parse_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	err = mk_clib_app_iip_debug_msg(&msg); mk_lang_check_rereturn(err);
	mk_lang_check_return(msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);
	app->m_step = ((mk_clib_app_iip_step_t)(((mk_lang_types_sint_t)(app->m_step)) + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_pr_step(mk_clib_app_iip_pt const app, mk_lang_types_bool_pt const done) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);
	mk_lang_assert(done);
	mk_lang_assert(*done == mk_lang_false);

	switch(app->m_step)
	{
		case mk_clib_app_iip_step_e_connect_beg: err = mk_clib_app_iip_pr_step_connect_beg(app); mk_lang_check_rereturn(err); break;
		case mk_clib_app_iip_step_e_connect_wait: err = mk_clib_app_iip_pr_step_connect_wait(app); mk_lang_check_rereturn(err); break;
		case mk_clib_app_iip_step_e_get_date_beg: err = mk_clib_app_iip_pr_step_get_date_beg(app); mk_lang_check_rereturn(err); break;
		case mk_clib_app_iip_step_e_get_date_end: err = mk_clib_app_iip_pr_step_get_date_end(app); mk_lang_check_rereturn(err); break;
		case mk_clib_app_iip_step_e_set_date_beg: err = mk_clib_app_iip_pr_step_set_date_beg(app); mk_lang_check_rereturn(err); break;
		case mk_clib_app_iip_step_e_set_date_end: err = mk_clib_app_iip_pr_step_set_date_end(app); mk_lang_check_rereturn(err); break;
		case mk_clib_app_iip_step_e_req_bw_beg: err = mk_clib_app_iip_pr_step_req_bw_beg(app); mk_lang_check_rereturn(err); break;
		case mk_clib_app_iip_step_e_req_bw_end: err = mk_clib_app_iip_pr_step_req_bw_end(app); mk_lang_check_rereturn(err); break;
		case mk_clib_app_iip_step_e_rec_bw_beg: err = mk_clib_app_iip_pr_step_rec_bw_beg(app); mk_lang_check_rereturn(err); break;
		case mk_clib_app_iip_step_e_rec_bw_end: err = mk_clib_app_iip_pr_step_rec_bw_end(app); mk_lang_check_rereturn(err); break;
		case mk_clib_app_iip_step_e_dummy_end: *done = mk_lang_true; break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_destroy(mk_clib_app_iip_pt const app) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(app);

	err = mk_lib_net_write_request_destroy(&app->m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_destroy(&app->m_read_request); mk_lang_check_rereturn(err);
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
	mk_lang_types_bool_t done;
	mk_lang_types_sint_t consumed;
	mk_clib_app_iip_t app;

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

	err = mk_lib_net_init(); mk_lang_check_rereturn(err);

	address_buf = argv[1];
	port_buf = argv[2];
	address_len = mk_lang_str_len_n(argv[1]);
	port_len = mk_lang_str_len_n(argv[2]);

	err = mk_lib_net_ipv4_address_parse_pc(&app.m_cp_destination.m_ipv4_address, address_buf, address_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1 && consumed <= address_len); mk_lang_check_return(!mk_lib_net_ipv4_address_is_any(&app.m_cp_destination.m_ipv4_address)); mk_lang_check_return(!mk_lib_net_ipv4_address_is_none(&app.m_cp_destination.m_ipv4_address));
	err = mk_lib_net_tcp_port_parse_pc(&app.m_cp_destination.m_tcp_port, port_buf, port_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1 && consumed <= port_len);

	done = mk_lang_false;
	do
	{
		err = mk_clib_app_iip_pr_step(&app, &done); mk_lang_check_rereturn(err);
	}while(!done);
	err = mk_clib_app_iip_destroy(&app); mk_lang_check_rereturn(err);

	err = mk_lib_net_deinit(); mk_lang_check_rereturn(err);
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
	err = mk_lang_command_line_parse(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_iip_wargs(argc, &argv[0], &lens[0]);
	return 0;
}


#else


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_iip_args(mk_lang_types_sint_t const argc, mk_lang_types_pchar_pcpct const argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t lens[3];

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
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
	return 0;
}


#endif


#endif
