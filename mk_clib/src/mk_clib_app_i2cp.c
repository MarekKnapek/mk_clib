#ifndef mk_include_guard_mk_clib_app_i2cp_c
#define mk_include_guard_mk_clib_app_i2cp_c
#include "mk_clib_app_i2cp.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_command_line.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_stdout.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_parse.h"
#include "mk_lib_iip_cp_message_serialize.h"
#include "mk_lib_net.h"
#include "mk_lib_net_iocp.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_dynamic_ring.h"
#include "mk_win_base.h"
#include "mk_win_dll_ws2.h"





#include "mk_lang_concat.h"
#if mk_lang_version_at_least_cpp_17
#define mk_lang_typedef_func_win_non_void(ret, name, args) \
typedef ret(mk_win_base_stdcall*name)args mk_lang_noexcept
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#define mk_lang_typedef_func_win_non_void(ret, name, args) \
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import ret mk_win_base_stdcall mk_lang_concat(mk_lang_typedef_func_dummy_, name)args mk_lang_noexcept; \
typedef decltype(&mk_lang_concat(mk_lang_typedef_func_dummy_, name)) name
#else
#define mk_lang_typedef_func_win_non_void(ret, name, args) \
typedef ret(mk_win_base_stdcall*name)args mk_lang_noexcept
#endif

#if mk_lang_version_at_least_cpp_17
#define mk_lang_typedef_func_win_void(ret, name, args) \
typedef ret(mk_win_base_stdcall*name)args mk_lang_noexcept
#elif mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11
#define mk_lang_typedef_func_win_void(ret, name, args) \
mk_lang_extern_force_c mk_win_base_dll_import ret mk_win_base_stdcall mk_lang_concat(mk_lang_typedef_func_dummy_, name)args mk_lang_noexcept; \
typedef decltype(&mk_lang_concat(mk_lang_typedef_func_dummy_, name)) name
#else
#define mk_lang_typedef_func_win_void(ret, name, args) \
typedef ret(mk_win_base_stdcall*name)args mk_lang_noexcept
#endif





union mk_clib_app_i2cp_guid_data_u
{
	mk_lang_types_uchar_t m_uchars[16];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_clib_app_i2cp_guid_data_u mk_clib_app_i2cp_guid_data_t;
struct mk_clib_app_i2cp_guid_s
{
	mk_clib_app_i2cp_guid_data_t m_data;
};
typedef struct mk_clib_app_i2cp_guid_s mk_clib_app_i2cp_guid_t;
mk_lang_typedef(mk_clib_app_i2cp_guid);


mk_lang_typedef_func_win_non_void(mk_win_base_bool_t, mk_clib_app_i2cp_accept_ex_t, (mk_win_dll_ws2_socket_t const socket_listen, mk_win_dll_ws2_socket_t const socket_accept, mk_win_base_void_lpt const out_data_buf, mk_win_base_dword_t const out_data_len, mk_win_base_dword_t const local_address_len, mk_win_base_dword_t const remote_address_len, mk_win_base_dword_lpt const transferred, mk_win_dll_ws2_overlapped_lpt const overlapped));
mk_lang_typedef_func_win_void(mk_lang_types_void_t, mk_clib_app_i2cp_get_accept_ex_sock_addrs_t, (mk_win_base_void_lpct const in_data_buf, mk_win_base_dword_t const in_data_len, mk_win_base_dword_t const local_address_len, mk_win_base_dword_t const remote_address_len, mk_win_dll_ws2_sock_addr_lplpt const local_address_obj, mk_win_base_sint_lpt const local_address_real, mk_win_dll_ws2_sock_addr_lplpt const remote_address_obj, mk_win_base_sint_lpt const remote_address_real));


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_i2cp_checker_s
{
	mk_sl_dynamic_ring_u8_t m_client_to_server;
	mk_sl_dynamic_ring_u8_t m_server_to_client;
	mk_lang_types_bool_t m_introducer_seen;
};
typedef struct mk_clib_app_i2cp_checker_s mk_clib_app_i2cp_checker_t;
mk_lang_typedef(mk_clib_app_i2cp_checker);
#include "mk_lang_warning_msvc_pop.h"
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_checker_rw_construct(mk_clib_app_i2cp_checker_pt const checker) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(checker);

	err = mk_sl_dynamic_ring_u8_rw_construct(&checker->m_client_to_server); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_construct(&checker->m_server_to_client); mk_lang_check_rereturn(err);
	return 0;
}
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_checker_rw_destroy(mk_clib_app_i2cp_checker_pt const checker) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(checker);

	err = mk_sl_dynamic_ring_u8_rw_destroy(&checker->m_client_to_server); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_destroy(&checker->m_server_to_client); mk_lang_check_rereturn(err);
	return 0;
}
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_checker_rw_check_introducer(mk_clib_app_i2cp_checker_pt const checker) mk_lang_noexcept
{
	mk_sl_cui_uint8_pt front;
	mk_lang_types_pchar_t tpc;
	mk_lang_types_sint_t err;

	mk_lang_assert(checker);

	if(!checker->m_introducer_seen)
	{
		if(!mk_sl_dynamic_ring_u8_rw_is_empty(&checker->m_client_to_server))
		{
			front = mk_sl_dynamic_ring_u8_rw_get_front(&checker->m_client_to_server); mk_lang_assert(front);
			mk_sl_cui_uint8_to_bi_pchar(front, &tpc);
			if(tpc == '\x2a')
			{
				checker->m_introducer_seen = mk_lang_true;
				err = mk_sl_dynamic_ring_u8_rw_pop_front_single(&checker->m_client_to_server); mk_lang_check_rereturn(err);
			}
		}
	}
	return 0;
}
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_checker_rw_check_deserialize_message_2(mk_clib_app_i2cp_checker_pt const checker, mk_sl_dynamic_ring_u8_pt const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt data_buf;
	mk_lang_types_sint_t data_len;
	mk_lib_iip_cp_message_parse_error_code_t error_code_in;
	mk_lang_types_sint_t consumed_in;
	mk_lib_iip_cp_message_t msg;
	mk_sl_cui_uint8_t out_buf[128 * 1024];
	mk_lib_iip_cp_message_serialize_error_code_t error_code_out;
	mk_lang_types_sint_t consumed_out;

	mk_lang_assert(checker);
	mk_lang_assert(ring);

	err = mk_sl_dynamic_ring_u8_rw_consolidate(ring); mk_lang_check_rereturn(err);
	data_buf = mk_sl_dynamic_ring_u8_rw_get_data_a(ring);
	data_len = mk_sl_dynamic_ring_u8_rw_get_sise_a(ring);
	error_code_in = mk_lib_iip_cp_message_parse_error_code_e_ok; err = mk_lib_iip_cp_message_parse_message(data_buf, data_len, &error_code_in, &consumed_in, &msg); mk_lang_check_rereturn(err);
	if(error_code_in == mk_lib_iip_cp_message_parse_error_code_e_ok)
	{
		mk_lang_assert(consumed_in >= 1);
		mk_lang_assert(consumed_in <= data_len);
		error_code_out = mk_lib_iip_cp_message_serialize_error_code_e_ok; err = mk_lib_iip_cp_message_serialize_message(&out_buf[0], mk_lang_countof(out_buf), &error_code_out, &consumed_out, &msg); mk_lang_check_rereturn(err);
		mk_lang_check_return(error_code_out == mk_lib_iip_cp_message_serialize_error_code_e_ok);
		mk_lang_check_return(consumed_out == consumed_in);
		mk_lang_check_return(mk_sl_cui_uint8_memcmp_fn(&out_buf[0], data_buf, consumed_out) == 0);
		err = mk_sl_dynamic_ring_u8_rw_pop_front_many(ring, consumed_out); mk_lang_check_rereturn(err);
	}
	return 0;
}
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_checker_rw_check_deserialize_message(mk_clib_app_i2cp_checker_pt const checker) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(checker);

	err = mk_clib_app_i2cp_checker_rw_check_deserialize_message_2(checker, &checker->m_client_to_server); mk_lang_check_rereturn(err);
	err = mk_clib_app_i2cp_checker_rw_check_deserialize_message_2(checker, &checker->m_server_to_client); mk_lang_check_rereturn(err);
	return 0;
}
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_checker_rw_append_data(mk_clib_app_i2cp_checker_pt const checker, mk_lang_types_bool_t const from_client, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_sl_dynamic_ring_u8_pt target;
	mk_lang_types_sint_t err;

	mk_lang_assert(checker);
	mk_lang_assert(from_client == mk_lang_false || from_client == mk_lang_true);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);

	target = from_client ? &checker->m_client_to_server : &checker->m_server_to_client;
	err = mk_sl_dynamic_ring_u8_rw_push_back_copy_many(target, data_buf, data_len); mk_lang_check_rereturn(err);
	err = mk_clib_app_i2cp_checker_rw_check_introducer(checker); mk_lang_check_rereturn(err);
	err = mk_clib_app_i2cp_checker_rw_check_deserialize_message(checker); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_global_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_cpuid_init();
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_mallocator_global_init(); mk_lang_check_rereturn(err);
	err = mk_lib_net_init(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_global_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lib_net_deinit(); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_mallocator_global_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_global_main(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t ptr;
	mk_lang_tchar_pct arg_local_ip_buf;
	mk_lang_types_sint_t arg_local_ip_len;
	mk_lang_tchar_pct arg_local_port_buf;
	mk_lang_types_sint_t arg_local_port_len;
	mk_lang_tchar_pct arg_remote_ip_buf;
	mk_lang_types_sint_t arg_remote_ip_len;
	mk_lang_tchar_pct arg_remote_port_buf;
	mk_lang_types_sint_t arg_remote_port_len;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t err;
	mk_lib_net_destination_t destination_listen;
	mk_lang_types_sint_t consumed;
	mk_lib_net_destination_t destination_server;
	mk_sl_dynamic_ring_u8_t ring_from_client_to_server_a;
	mk_sl_dynamic_ring_u8_t ring_from_client_to_server_b;
	mk_sl_dynamic_ring_u8_t ring_from_server_to_client_a;
	mk_sl_dynamic_ring_u8_t ring_from_server_to_client_b;
	mk_lib_net_iocp_t iocp;
	mk_lib_net_socket_t sck_to_listen;
	mk_lib_net_socket_t sck_to_client;
	mk_lib_net_socket_t sck_to_server;
	mk_lang_types_uintptr_t key_listen;
	mk_lang_types_uintptr_t key_client;
	mk_lang_types_uintptr_t key_server;
	mk_lang_types_uchar_pt guid;
	mk_clib_app_i2cp_guid_t guid_storage;
	mk_lib_net_ioctl_request_t ioctl_request;
	mk_clib_app_i2cp_accept_ex_t accept_ex;
	mk_lang_types_bool_t dequeued;
	mk_lang_types_bool_t successful_io_operation;
	mk_lang_types_sint_t bytes_transferred;
	mk_lang_types_uintptr_t key;
	mk_lang_types_void_pt overlapped;
	mk_lang_types_uint_t fail_reason;
	mk_clib_app_i2cp_get_accept_ex_sock_addrs_t get_accept_ex_sock_addrs;
	mk_lib_net_read_request_t read_req_client;
	mk_lib_net_read_request_t read_req_server;
	mk_lib_net_write_request_t write_req_client;
	mk_lib_net_write_request_t write_req_server;
	mk_sl_cui_uint8_pt data_from_client_to_server_buf_a;
	mk_lang_types_usize_t data_from_client_to_server_len_a;
	mk_lib_net_accept_request_t accept_request;
	mk_lib_net_destination_t address_local;
	mk_lib_net_destination_t address_remote;
	mk_lib_net_async_connect_t connect;
	mk_lang_types_sint_t st;
	mk_sl_cui_uint8_pt data_from_client_to_server_buf_b;
	mk_sl_cui_uint8_pt data_from_server_to_client_buf_a;
	mk_sl_cui_uint8_pt data_from_server_to_client_buf_b;
	mk_lang_types_usize_t data_from_client_to_server_len_b;
	mk_lang_types_usize_t data_from_server_to_client_len_a;
	mk_lang_types_usize_t data_from_server_to_client_len_b;
	mk_clib_app_i2cp_checker_t checker;

	mk_lang_assert(argc >= 1);
	mk_lang_assert(argv);
	mk_lang_assert(lens);
	mk_lang_assert(argv[0]);
	mk_lang_assert(argv[0][0] != mk_lang_tchar_c('\0'));
	mk_lang_assert(lens[0] >= 1);

	mk_lang_check_return(argc == 5);
	n = argc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_check_return(argv[i]);
		mk_lang_check_return(argv[i][0] != mk_lang_tchar_c('\0'));
		mk_lang_check_return(lens[i] >= 1);
	}
	ptr = 1;
	arg_local_ip_buf = argv[ptr]; arg_local_ip_len = lens[ptr]; ++ptr;
	arg_local_port_buf = argv[ptr]; arg_local_port_len = lens[ptr]; ++ptr;
	arg_remote_ip_buf = argv[ptr]; arg_remote_ip_len = lens[ptr]; ++ptr;
	arg_remote_port_buf = argv[ptr]; arg_remote_port_len = lens[ptr]; ++ptr;
	gud = mk_lang_true;
	err = mk_clib_app_i2cp_checker_rw_construct(&checker); mk_lang_check_rereturn(err);
	err = mk_lib_net_ipv4_address_parse_tc(&destination_listen.m_ipv4_address, arg_local_ip_buf, arg_local_ip_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(consumed >= 1);
	err = mk_lib_net_tcp_port_parse_tc(&destination_listen.m_tcp_port, arg_local_port_buf, arg_local_port_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(consumed >= 1);
	err = mk_lib_net_ipv4_address_parse_tc(&destination_server.m_ipv4_address, arg_remote_ip_buf, arg_remote_ip_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(consumed >= 1);
	err = mk_lib_net_tcp_port_parse_tc(&destination_server.m_tcp_port, arg_remote_port_buf, arg_remote_port_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(consumed >= 1);
	err = mk_sl_dynamic_ring_u8_rw_construct(&ring_from_client_to_server_a); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_construct(&ring_from_client_to_server_b); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_construct(&ring_from_server_to_client_a); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_construct(&ring_from_server_to_client_b); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_reserve_at_least(&ring_from_client_to_server_a, 4 * 1024); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_reserve_at_least(&ring_from_client_to_server_b, 4 * 1024); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_reserve_at_least(&ring_from_server_to_client_a, 4 * 1024); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_reserve_at_least(&ring_from_server_to_client_b, 4 * 1024); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_construct(&iocp, 0); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_construct(&sck_to_listen, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_construct(&sck_to_client, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_construct(&sck_to_server, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&sck_to_listen); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&sck_to_client); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&sck_to_server); mk_lang_check_rereturn(err);
	key_listen = ((mk_lang_types_uintptr_t)(&sck_to_listen));
	key_client = ((mk_lang_types_uintptr_t)(&sck_to_client));
	key_server = ((mk_lang_types_uintptr_t)(&sck_to_server));
	err = mk_lib_net_iocp_associate_with_socket(&iocp, key_listen, &sck_to_listen); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_associate_with_socket(&iocp, key_client, &sck_to_client); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_associate_with_socket(&iocp, key_server, &sck_to_server); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_bind(&sck_to_listen, &destination_listen); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_listen(&sck_to_listen); mk_lang_check_rereturn(err);
	ptr = 0;
	guid = &guid_storage.m_data.m_uchars[0];
	guid[ptr++] = 0xf1; guid[ptr++] = 0x7d; guid[ptr++] = 0x36; guid[ptr++] = 0xb5;
	guid[ptr++] = 0xac; guid[ptr++] = 0xcb; guid[ptr++] = 0xcf; guid[ptr++] = 0x11;
	guid[ptr++] = 0x95; guid[ptr++] = 0xca; guid[ptr++] = 0x00; guid[ptr++] = 0x80;
	guid[ptr++] = 0x5f; guid[ptr++] = 0x48; guid[ptr++] = 0xa1; guid[ptr++] = 0x92;
	err = mk_lib_net_ioctl_request_construct(&ioctl_request, &sck_to_listen, ((mk_lang_types_uint_t)(mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer)), ((mk_sl_cui_uint8_pct)(&guid[0])), 16, ((mk_sl_cui_uint8_pt)(&accept_ex)), sizeof(accept_ex)); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_issue(&ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_dequeue_packet_infinite(&iocp, &dequeued, &successful_io_operation, &bytes_transferred, &key, &overlapped, &fail_reason); mk_lang_check_rereturn(err); mk_lang_check_return(dequeued); mk_lang_check_return(successful_io_operation); mk_lang_check_return(bytes_transferred == 0); mk_lang_check_return(key == ((mk_lang_types_uintptr_t)(&sck_to_listen))); mk_lang_check_return(overlapped);
	err = mk_lib_net_ioctl_request_wait_infinite(&ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&ioctl_request); mk_lang_check_rereturn(err); mk_lang_check_return(ioctl_request.m_b); mk_lang_check_return(ioctl_request.m_transferred == sizeof(accept_ex));
	ptr = 0;
	guid[ptr++] = 0xf2; guid[ptr++] = 0x7d; guid[ptr++] = 0x36; guid[ptr++] = 0xb5;
	guid[ptr++] = 0xac; guid[ptr++] = 0xcb; guid[ptr++] = 0xcf; guid[ptr++] = 0x11;
	guid[ptr++] = 0x95; guid[ptr++] = 0xca; guid[ptr++] = 0x00; guid[ptr++] = 0x80;
	guid[ptr++] = 0x5f; guid[ptr++] = 0x48; guid[ptr++] = 0xa1; guid[ptr++] = 0x92;
	err = mk_lib_net_ioctl_request_reconstruct(&ioctl_request, &sck_to_listen, ((mk_lang_types_uint_t)(mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer)), ((mk_sl_cui_uint8_pct)(&guid[0])), 16, ((mk_sl_cui_uint8_pt)(&get_accept_ex_sock_addrs)), sizeof(get_accept_ex_sock_addrs)); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_issue(&ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_dequeue_packet_infinite(&iocp, &dequeued, &successful_io_operation, &bytes_transferred, &key, &overlapped, &fail_reason); mk_lang_check_rereturn(err); mk_lang_check_return(dequeued); mk_lang_check_return(successful_io_operation); mk_lang_check_return(bytes_transferred == 0); mk_lang_check_return(key == ((mk_lang_types_uintptr_t)(&sck_to_listen))); mk_lang_check_return(overlapped);
	err = mk_lib_net_ioctl_request_wait_infinite(&ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&ioctl_request); mk_lang_check_rereturn(err); mk_lang_check_return(ioctl_request.m_b); mk_lang_check_return(ioctl_request.m_transferred == sizeof(get_accept_ex_sock_addrs));
	err = mk_lib_net_ioctl_request_reset(&ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_construct(&read_req_client, &sck_to_client, mk_lang_null, 0); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_construct(&read_req_server, &sck_to_server, mk_lang_null, 0); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_construct(&write_req_client, &sck_to_client, mk_lang_null, 0); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_construct(&write_req_server, &sck_to_server, mk_lang_null, 0); mk_lang_check_rereturn(err);

	err = mk_sl_dynamic_ring_u8_rw_clear(&ring_from_client_to_server_a); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_reserve_at_least(&ring_from_client_to_server_a, 4 * 1024); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_consolidate(&ring_from_client_to_server_a); mk_lang_check_rereturn(err);
	data_from_client_to_server_buf_a = mk_sl_dynamic_ring_u8_rw_get_free_data_a(&ring_from_client_to_server_a);
	data_from_client_to_server_len_a = mk_sl_dynamic_ring_u8_rw_get_free_size_a(&ring_from_client_to_server_a);

	err = mk_lib_net_accept_request_construct(&accept_request, &accept_ex, &get_accept_ex_sock_addrs, &sck_to_listen, &sck_to_client, data_from_client_to_server_buf_a, ((mk_lang_types_sint_t)(data_from_client_to_server_len_a))); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_issue(&accept_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_wait_infinite(&accept_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_get_result(&accept_request); mk_lang_check_rereturn(err); mk_lang_check_return(accept_request.m_b);
	err = mk_lib_net_accept_request_get_addresses(&accept_request, &address_local, &address_remote); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_reset(&accept_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_update_accept_context(&sck_to_client, &sck_to_listen); mk_lang_check_rereturn(err);

	err = mk_lib_net_async_connect_construct(&connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_associate_async_connect(&sck_to_server, &connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_connect(&sck_to_server, &destination_server); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_dequeue_packet_infinite(&iocp, &dequeued, &successful_io_operation, &bytes_transferred, &key, &overlapped, &fail_reason); mk_lang_check_rereturn(err); mk_lang_check_return(dequeued); mk_lang_check_return(successful_io_operation); mk_lang_check_return(bytes_transferred >= 1); mk_lang_check_return(key == ((mk_lang_types_uintptr_t)(&sck_to_listen))); mk_lang_check_return(overlapped);
	err = mk_lib_net_async_connect_wait_infinite(&connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_connect_get_result(&connect, &st); mk_lang_check_rereturn(err); mk_lang_check_return(st == 0);
	err = mk_lib_net_async_connect_reset(&connect); mk_lang_check_rereturn(err);

	if(accept_request.m_transferred != 0)
	{
		err = mk_clib_app_i2cp_checker_rw_append_data(&checker, mk_lang_true, accept_request.m_out_data_buf, accept_request.m_transferred); mk_lang_check_rereturn(err);
		err = mk_lib_net_write_request_reconstruct(&write_req_server, &sck_to_server, accept_request.m_out_data_buf, accept_request.m_transferred); mk_lang_check_rereturn(err);
		err = mk_lib_net_socket_send(&sck_to_server, &write_req_server); mk_lang_check_rereturn(err);
		err = mk_lib_net_iocp_dequeue_packet_infinite(&iocp, &dequeued, &successful_io_operation, &bytes_transferred, &key, &overlapped, &fail_reason); mk_lang_check_rereturn(err); mk_lang_check_return(dequeued); mk_lang_check_return(successful_io_operation); mk_lang_check_return(bytes_transferred == accept_request.m_transferred); mk_lang_check_return(key == ((mk_lang_types_uintptr_t)(&sck_to_server))); mk_lang_check_return(overlapped);
		err = mk_lib_net_write_request_wait_infinite(&write_req_server); mk_lang_check_rereturn(err);
		err = mk_lib_net_write_request_get_result(&write_req_server); mk_lang_check_rereturn(err); mk_lang_check_return(write_req_server.m_b); mk_lang_check_return(write_req_server.m_transferred == accept_request.m_transferred);
		err = mk_lib_net_write_request_reconstruct(&write_req_server, &sck_to_server, mk_lang_null, 0); mk_lang_check_rereturn(err);
	}

	err = mk_sl_dynamic_ring_u8_rw_clear(&ring_from_client_to_server_a); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_clear(&ring_from_client_to_server_b); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_clear(&ring_from_server_to_client_a); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_clear(&ring_from_server_to_client_b); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_reserve_at_least(&ring_from_client_to_server_a, 4 * 1024); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_reserve_at_least(&ring_from_client_to_server_b, 4 * 1024); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_reserve_at_least(&ring_from_server_to_client_a, 4 * 1024); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_reserve_at_least(&ring_from_server_to_client_b, 4 * 1024); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_consolidate(&ring_from_client_to_server_a); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_consolidate(&ring_from_client_to_server_b); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_consolidate(&ring_from_server_to_client_a); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_consolidate(&ring_from_server_to_client_b); mk_lang_check_rereturn(err);
	data_from_client_to_server_buf_a = mk_sl_dynamic_ring_u8_rw_get_free_data_a(&ring_from_client_to_server_a);
	data_from_client_to_server_buf_b = mk_sl_dynamic_ring_u8_rw_get_free_data_a(&ring_from_client_to_server_b);
	data_from_server_to_client_buf_a = mk_sl_dynamic_ring_u8_rw_get_free_data_a(&ring_from_server_to_client_a);
	data_from_server_to_client_buf_b = mk_sl_dynamic_ring_u8_rw_get_free_data_a(&ring_from_server_to_client_b);
	data_from_client_to_server_len_a = mk_sl_dynamic_ring_u8_rw_get_free_size_a(&ring_from_client_to_server_a);
	data_from_client_to_server_len_b = mk_sl_dynamic_ring_u8_rw_get_free_size_a(&ring_from_client_to_server_b);
	data_from_server_to_client_len_a = mk_sl_dynamic_ring_u8_rw_get_free_size_a(&ring_from_server_to_client_a);
	data_from_server_to_client_len_b = mk_sl_dynamic_ring_u8_rw_get_free_size_a(&ring_from_server_to_client_b);
	err = mk_lib_net_read_request_reconstruct(&read_req_client, &sck_to_client, data_from_client_to_server_buf_a, ((mk_lang_types_sint_t)(data_from_client_to_server_len_a))); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_reconstruct(&read_req_server, &sck_to_server, data_from_server_to_client_buf_a, ((mk_lang_types_sint_t)(data_from_server_to_client_len_a))); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_recv(&sck_to_client, &read_req_client); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_recv(&sck_to_server, &read_req_server); mk_lang_check_rereturn(err);

	for(;;)
	{
		err = mk_lib_net_iocp_dequeue_packet_infinite(&iocp, &dequeued, &successful_io_operation, &bytes_transferred, &key, &overlapped, &fail_reason); mk_lang_check_rereturn(err); mk_lang_check_return(dequeued);
		if(successful_io_operation)
		{
			#include "mk_lang_warning_msvc_push_c4127.h"
			if(mk_lang_false){}
			#include "mk_lang_warning_msvc_pop.h"
			else if(key == key_client)
			{
				mk_lang_check_return(key == ((mk_lang_types_uintptr_t)(&sck_to_client)));
				mk_lang_check_return(overlapped);
				#include "mk_lang_warning_msvc_push_c4127.h"
				if(mk_lang_false){}
				#include "mk_lang_warning_msvc_pop.h"
				else if(overlapped == &read_req_client.m_overlapped)
				{
					err = mk_lib_net_read_request_wait_infinite(&read_req_client); mk_lang_check_rereturn(err);
					err = mk_lib_net_read_request_get_result(&read_req_client); mk_lang_check_rereturn(err); mk_lang_check_return(read_req_client.m_b); mk_lang_check_return(bytes_transferred == read_req_client.m_transferred); mk_lang_check_return(read_req_client.m_transferred <= read_req_client.m_data_len);
					if(read_req_client.m_transferred == 0)
					{
						break;
					}
					mk_lang_check_return(read_req_client.m_transferred >= 1);
					err = mk_clib_app_i2cp_checker_rw_append_data(&checker, mk_lang_true, read_req_client.m_data_buf, read_req_client.m_transferred); mk_lang_check_rereturn(err);
					if(write_req_server.m_data_buf == mk_lang_null && write_req_server.m_data_len == 0)
					{
						err = mk_lib_net_write_request_reconstruct(&write_req_server, &sck_to_server, read_req_client.m_data_buf, read_req_client.m_transferred); mk_lang_check_rereturn(err);
						err = mk_lib_net_socket_send(&sck_to_server, &write_req_server); mk_lang_check_rereturn(err);
						err = mk_lib_net_read_request_reconstruct(&read_req_client, &sck_to_client, mk_lang_null, 0); mk_lang_check_rereturn(err);
					}
					if(data_from_client_to_server_buf_a != read_req_client.m_data_buf && data_from_client_to_server_buf_a != write_req_server.m_data_buf)
					{
						err = mk_lib_net_read_request_reconstruct(&read_req_client, &sck_to_client, data_from_client_to_server_buf_a, ((mk_lang_types_sint_t)(data_from_client_to_server_len_a))); mk_lang_check_rereturn(err);
						err = mk_lib_net_socket_recv(&sck_to_client, &read_req_client); mk_lang_check_rereturn(err);
					}
					else if(data_from_client_to_server_buf_b != read_req_client.m_data_buf && data_from_client_to_server_buf_b != write_req_server.m_data_buf)
					{
						err = mk_lib_net_read_request_reconstruct(&read_req_client, &sck_to_client, data_from_client_to_server_buf_b, ((mk_lang_types_sint_t)(data_from_client_to_server_len_b))); mk_lang_check_rereturn(err);
						err = mk_lib_net_socket_recv(&sck_to_client, &read_req_client); mk_lang_check_rereturn(err);
					}
				}
				else if(overlapped == &write_req_client.m_overlapped)
				{
					err = mk_lib_net_write_request_wait_infinite(&write_req_client); mk_lang_check_rereturn(err);
					err = mk_lib_net_write_request_get_result(&write_req_client); mk_lang_check_rereturn(err); mk_lang_check_return(write_req_client.m_b); mk_lang_check_return(bytes_transferred == write_req_client.m_transferred); mk_lang_check_return(write_req_client.m_transferred == write_req_client.m_data_len);
					if(read_req_server.m_data_buf == mk_lang_null && read_req_server.m_data_len == 0)
					{
						err = mk_lib_net_read_request_reconstruct(&read_req_server, &sck_to_server, ((mk_sl_cui_uint8_pt)(write_req_client.m_data_buf)), write_req_client.m_data_len); mk_lang_check_rereturn(err);
						err = mk_lib_net_socket_recv(&sck_to_server, &read_req_server); mk_lang_check_rereturn(err);
					}
					err = mk_lib_net_write_request_reconstruct(&write_req_client, &sck_to_client, mk_lang_null, 0); mk_lang_check_rereturn(err);
					if(read_req_server.m_done)
					{
						mk_lang_check_return(read_req_server.m_transferred >= 1);
						err = mk_lib_net_write_request_reconstruct(&write_req_client, &sck_to_client, read_req_server.m_data_buf, read_req_server.m_transferred); mk_lang_check_rereturn(err);
						err = mk_lib_net_socket_send(&sck_to_client, &write_req_client); mk_lang_check_rereturn(err);
						err = mk_lib_net_read_request_reconstruct(&read_req_server, &sck_to_server, mk_lang_null, 0); mk_lang_check_rereturn(err);
					}
				}
				else
				{
					mk_lang_assert_false();
				}
			}
			else if(key == key_server)
			{
				mk_lang_check_return(key == ((mk_lang_types_uintptr_t)(&sck_to_server)));
				mk_lang_check_return(overlapped);
				#include "mk_lang_warning_msvc_push_c4127.h"
				if(mk_lang_false){}
				#include "mk_lang_warning_msvc_pop.h"
				else if(overlapped == &read_req_server.m_overlapped)
				{
					err = mk_lib_net_read_request_wait_infinite(&read_req_server); mk_lang_check_rereturn(err);
					err = mk_lib_net_read_request_get_result(&read_req_server); mk_lang_check_rereturn(err); mk_lang_check_return(read_req_server.m_b); mk_lang_check_return(bytes_transferred == read_req_server.m_transferred); mk_lang_check_return(read_req_server.m_transferred <= read_req_server.m_data_len);
					if(read_req_server.m_transferred == 0)
					{
						break;
					}
					mk_lang_check_return(read_req_server.m_transferred >= 1);
					err = mk_clib_app_i2cp_checker_rw_append_data(&checker, mk_lang_false, read_req_server.m_data_buf, read_req_server.m_transferred); mk_lang_check_rereturn(err);
					if(write_req_client.m_data_buf == mk_lang_null && write_req_client.m_data_len == 0)
					{
						err = mk_lib_net_write_request_reconstruct(&write_req_client, &sck_to_client, read_req_server.m_data_buf, read_req_server.m_transferred); mk_lang_check_rereturn(err);
						err = mk_lib_net_socket_send(&sck_to_client, &write_req_client); mk_lang_check_rereturn(err);
						err = mk_lib_net_read_request_reconstruct(&read_req_server, &sck_to_server, mk_lang_null, 0); mk_lang_check_rereturn(err);
					}
					if(data_from_server_to_client_buf_a != read_req_server.m_data_buf && data_from_server_to_client_buf_a != write_req_client.m_data_buf)
					{
						err = mk_lib_net_read_request_reconstruct(&read_req_server, &sck_to_server, data_from_server_to_client_buf_a, ((mk_lang_types_sint_t)(data_from_server_to_client_len_a))); mk_lang_check_rereturn(err);
						err = mk_lib_net_socket_recv(&sck_to_server, &read_req_server); mk_lang_check_rereturn(err);
					}
					else if(data_from_server_to_client_buf_b != read_req_server.m_data_buf && data_from_server_to_client_buf_b != write_req_client.m_data_buf)
					{
						err = mk_lib_net_read_request_reconstruct(&read_req_server, &sck_to_server, data_from_server_to_client_buf_b, ((mk_lang_types_sint_t)(data_from_server_to_client_len_b))); mk_lang_check_rereturn(err);
						err = mk_lib_net_socket_recv(&sck_to_server, &read_req_server); mk_lang_check_rereturn(err);
					}
				}
				else if(overlapped == &write_req_server.m_overlapped)
				{
					err = mk_lib_net_write_request_wait_infinite(&write_req_server); mk_lang_check_rereturn(err);
					err = mk_lib_net_write_request_get_result(&write_req_server); mk_lang_check_rereturn(err); mk_lang_check_return(write_req_server.m_b); mk_lang_check_return(bytes_transferred == write_req_server.m_transferred); mk_lang_check_return(write_req_server.m_transferred == write_req_server.m_data_len);
					if(read_req_client.m_data_buf == mk_lang_null && read_req_client.m_data_len == 0)
					{
						err = mk_lib_net_read_request_reconstruct(&read_req_client, &sck_to_client, ((mk_sl_cui_uint8_pt)(write_req_server.m_data_buf)), write_req_server.m_data_len); mk_lang_check_rereturn(err);
						err = mk_lib_net_socket_recv(&sck_to_client, &read_req_client); mk_lang_check_rereturn(err);
					}
					err = mk_lib_net_write_request_reconstruct(&write_req_server, &sck_to_server, mk_lang_null, 0); mk_lang_check_rereturn(err);
					if(read_req_client.m_done)
					{
						mk_lang_check_return(read_req_client.m_transferred >= 1);
						err = mk_lib_net_write_request_reconstruct(&write_req_server, &sck_to_server, read_req_client.m_data_buf, read_req_client.m_transferred); mk_lang_check_rereturn(err);
						err = mk_lib_net_socket_send(&sck_to_server, &write_req_server); mk_lang_check_rereturn(err);
						err = mk_lib_net_read_request_reconstruct(&read_req_client, &sck_to_client, mk_lang_null, 0); mk_lang_check_rereturn(err);
					}
				}
				else
				{
					mk_lang_assert_false();
				}
			}
		}
		else
		{
			break;
		}
	}

	err = mk_lib_net_async_connect_destroy(&connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_destroy(&accept_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_destroy(&write_req_server); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_destroy(&write_req_client); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_destroy(&read_req_server); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_destroy(&read_req_client); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_destroy(&ioctl_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_shutdown(&sck_to_server); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_shutdown(&sck_to_client); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_destroy(&sck_to_server); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_destroy(&sck_to_client); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_destroy(&sck_to_listen); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_destroy(&iocp); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_destroy(&ring_from_server_to_client_a); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_destroy(&ring_from_server_to_client_b); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_destroy(&ring_from_client_to_server_a); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_u8_rw_destroy(&ring_from_client_to_server_b); mk_lang_check_rereturn(err);
	err = mk_clib_app_i2cp_checker_rw_destroy(&checker); mk_lang_check_rereturn(err);
	return 0;
}


#if mk_lang_entry_point_have


#include "mk_win_dll_kernel_process.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_peb_2(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_wchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	mk_lang_assert(peb);

	err = mk_clib_app_i2cp_global_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_win(mk_win_dll_kernel_process_get_command_line(), &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_i2cp_global_main(argc, &argv[0], &lens[0]);
	err = mk_clib_app_i2cp_global_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_i2cp_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err_b;
	mk_lang_types_sint_t err;

	err_b = mk_clib_app_i2cp_peb_2(peb);
	if(err_b == 0)
	{
		err = mk_lang_stdout_println_lit_n("Gud."); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_lang_stdout_println_lit_n("Bad."); mk_lang_check_rereturn(err);
	}
	mk_lang_check_rereturn(err_b);
	return 0;
}


#else


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_i2cp_args_2(mk_lang_types_sint_t const std_argc, mk_lang_types_pchar_pcpct const std_argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pct argv[16];
	mk_lang_types_sint_t lens[mk_lang_countof(argv)];
	mk_lang_types_sint_t argc;

	err = mk_clib_app_i2cp_global_init(); mk_lang_check_rereturn(err);
	err = mk_lang_command_line_parse_std(std_argc, std_argv, &argv[0], &lens[0], mk_lang_countof(argv), &argc); mk_lang_check_rereturn(err);
	err = mk_clib_app_i2cp_global_main(argc, &argv[0], &lens[0]); mk_lang_check_rereturn(err);
	err = mk_clib_app_i2cp_global_deinit(); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_i2cp_args(mk_lang_types_sint_t const std_argc, mk_lang_types_pchar_pcpct const std_argv) mk_lang_noexcept
{
	mk_lang_types_sint_t err_b;
	mk_lang_types_sint_t err;

	err_b = mk_clib_app_i2cp_args_2(std_argc, std_argv);
	if(err_b == 0)
	{
		err = mk_lang_stdout_println_lit_n("Gud."); mk_lang_check_rereturn(err);
	}
	else
	{
		err = mk_lang_stdout_println_lit_n("Bad."); mk_lang_check_rereturn(err);
	}
	mk_lang_check_rereturn(err_b);
	return 0;
}


#endif


#endif
