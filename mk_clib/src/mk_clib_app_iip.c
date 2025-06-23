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

#pragma warning(push, 0)
#pragma warning(disable:4005)
#pragma warning(disable:4668)
#pragma warning(disable:4820)
#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <windows.h>
#pragma warning(pop)

#pragma comment(lib, "ws2_32.lib")


#include "mk_lib_net.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_lang_types.h"
#include "mk_lang_typedef.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_clib_app_iip_cp_destination_s
{
	mk_lib_net_ipv4_address_t m_address;
	mk_lib_net_tcp_port_t m_port;
};
typedef struct mk_clib_app_iip_cp_destination_s mk_clib_app_iip_cp_destination_t;
mk_lang_typedef(mk_clib_app_iip_cp_destination);
#include "mk_lang_warning_msvc_pop.h"


struct mk_clib_app_iip_s
{
	mk_clib_app_iip_cp_destination_t m_cp_destination;
};
typedef struct mk_clib_app_iip_s mk_clib_app_iip_t;
mk_lang_typedef(mk_clib_app_iip);


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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_iip_work(mk_lang_types_sint_t const argc, mk_lang_tchar_pcpct const argv, mk_lang_types_sint_pct const lens) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	//mk_lang_types_sint_t len;
	//mk_lang_bui_ushort_t port;
	mk_lang_types_pchar_pct port_buf;
	mk_lang_types_sint_t port_len;
	mk_lang_types_pchar_pct address_buf;
	mk_lang_types_sint_t address_len;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t st;
	mk_lib_net_async_connect_t async_connect;
	//mk_lib_net_async_rwc_t async_rwc;
	mk_lib_net_write_request_t write_request;
	mk_lib_net_read_request_t read_request;
	mk_lib_net_destination_t destination;
	//SOCKET sck;
	mk_lib_net_socket_t sck2;
	//unsigned long remote_addr_ulong;
	//struct sockaddr_in remote_addr_struct;
	//WSABUF buf;
	mk_sl_cui_uint8_t store[4 * 1024];
	//WSAOVERLAPPED ovr;
	//BOOL b;
	mk_lang_types_sint_t err;
	//mk_lang_types_sint_t event_id;
	mk_lib_iip_cp_message_t msg;
	mk_lib_iip_cp_message_serialize_error_code_t serialize_error_code;
	mk_lib_iip_cp_message_parse_error_code_t parse_error_code;
	mk_lang_types_sint_t consumed;
	//mk_lang_types_bool_t is_ready;
	//DWORD waited;
	//DWORD flags;
	//DWORD transfered;
	unsigned char tuc;

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

	address_buf = argv[1];
	port_buf = argv[2];
	address_len = mk_lang_str_len_n(argv[1]);
	port_len = mk_lang_str_len_n(argv[2]);

	err = mk_lib_net_ipv4_address_parse_pc(&destination.m_ipv4_address, address_buf, address_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1 && consumed <= address_len); mk_lang_check_return(!mk_lib_net_ipv4_address_is_any(&destination.m_ipv4_address)); mk_lang_check_return(!mk_lib_net_ipv4_address_is_none(&destination.m_ipv4_address));
	err = mk_lib_net_tcp_port_parse_pc(&destination.m_tcp_port, port_buf, port_len, &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_assert(consumed >= 1 && consumed <= port_len);

	err = mk_lib_net_init(); mk_lang_check_rereturn(err);

	err = mk_lib_net_socket_construct(&sck2, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&sck2); mk_lang_check_rereturn(err);

	err = mk_lib_net_async_connect_construct(&async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_associate_async_connect(&sck2, &async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_connect(&sck2, &destination); mk_lang_check_rereturn(err);

	err = mk_lib_net_async_connect_wait_infinite(&async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_connect_get_result(&async_connect, &st); mk_lang_check_rereturn(err); mk_lang_check_return(st == 0);
	err = mk_lib_net_async_connect_destroy(&async_connect); mk_lang_check_rereturn(err);

	/*err = mk_lib_net_async_rwc_construct(&async_rwc); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_associate_async_rwc(&sck2, &async_rwc); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_rwc_is_ready(&async_rwc, &is_ready); mk_lang_check_rereturn(err);
	if(is_ready)
	{
		err = mk_lib_net_async_rwc_get_result(&async_rwc, &event_id, &st); mk_lang_check_rereturn(err); mk_lang_check_return(st == 0);
	}*/

	tuc = 0x2a; mk_sl_cui_uint8_from_bi_uchar(&store[0], &tuc);
	err = mk_lib_iip_cp_message_construct(&msg, mk_lib_iip_cp_message_message_type_id_e_get_date); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_serialize_message(&store[1], mk_lang_countof(store) - 1, &serialize_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(serialize_error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	err = mk_clib_app_iip_debug_msg(&msg); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);

	/*err = mk_lib_net_async_rwc_wait_infinite(&async_rwc); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_rwc_get_result(&async_rwc, &event_id, &st); mk_lang_check_rereturn(err); mk_lang_check_return(st == 0);*/

	err = mk_lib_net_write_request_construct(&write_request, &sck2, &store[0], 1 + consumed); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_send(&sck2, &write_request); mk_lang_check_rereturn(err);

	err = mk_lib_net_write_request_wait_infinite(&write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_get_result(&write_request); mk_lang_check_rereturn(err);

	err = mk_lib_net_read_request_construct(&read_request, &sck2, &store[0], mk_lang_countof(store)); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_recv(&sck2, &read_request); mk_lang_check_rereturn(err);

	err = mk_lib_net_read_request_wait_infinite(&read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_get_result(&read_request); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_message_parse_message(&store[0], read_request.m_transferred, &parse_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	err = mk_clib_app_iip_debug_msg(&msg); mk_lang_check_rereturn(err);
	mk_lang_check_return(msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_set_date);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);

	err = mk_lib_net_write_request_destroy(&write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_destroy(&read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_deinit(); mk_lang_check_rereturn(err);

	/*
	sck = WSASocketW(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED | WSA_FLAG_NO_HANDLE_INHERIT); mk_lang_check_return(sck != INVALID_SOCKET);
	ovr.Internal = 0;
	ovr.InternalHigh = 0;
	ovr.Offset = 0;
	ovr.OffsetHigh = 0;
	ovr.hEvent = WSACreateEvent(); mk_lang_check_return(ovr.hEvent != WSA_INVALID_EVENT);

	len = mk_lang_bui_ushort_from_str_dec_n(&port, argv[2], mk_lang_str_len_n(argv[2])); mk_lang_check_return(len >= 1);
	remote_addr_ulong = inet_addr(argv[1]); mk_lang_check_return(remote_addr_ulong != INADDR_NONE); mk_lang_check_return(remote_addr_ulong != INADDR_ANY);
	remote_addr_struct.sin_family = AF_INET;
	remote_addr_struct.sin_addr.s_addr = remote_addr_ulong;
	remote_addr_struct.sin_port = htons(port);
	st = connect(sck, ((struct sockaddr*)(&remote_addr_struct)), sizeof(remote_addr_struct)); mk_lang_check_return(st == 0);

	tuc = 0x2a; mk_sl_cui_uint8_from_bi_uchar(&store[0], &tuc);
	err = mk_lib_iip_cp_message_construct(&msg, mk_lib_iip_cp_message_message_type_id_e_get_date); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_serialize_message(&store[1], mk_lang_countof(store) - 1, &serialize_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(serialize_error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);

	buf.buf = ((CHAR*)(&store[0]));
	buf.len = 1 + consumed;
	b = WSAResetEvent(ovr.hEvent); mk_lang_check_return(b == TRUE);
	st = WSASendTo(sck, &buf, 1, NULL, 0, NULL, 0, &ovr, NULL); mk_lang_check_return((st == 0) || (WSAGetLastError() == WSA_IO_PENDING));
	do
	{
		waited = WSAWaitForMultipleEvents(1, &ovr.hEvent, TRUE, WSA_INFINITE, TRUE);
	}while(waited == WSA_WAIT_IO_COMPLETION);
	mk_lang_check_return(waited == WSA_WAIT_EVENT_0);
	b = WSAGetOverlappedResult(sck, &ovr, &transfered, TRUE, &flags); mk_lang_check_return(b == TRUE);
	mk_lang_check_return(transfered == ((DWORD)(1 + consumed)));

	buf.len = mk_lang_countof(store);
	b = WSAResetEvent(ovr.hEvent); mk_lang_check_return(b == TRUE);
	flags = 0;
	st = WSARecv(sck, &buf, 1, NULL, &flags, &ovr, NULL); mk_lang_check_return((st == 0) || (WSAGetLastError() == WSA_IO_PENDING));
	do
	{
		waited = WSAWaitForMultipleEvents(1, &ovr.hEvent, TRUE, WSA_INFINITE, TRUE);
	}while(waited == WSA_WAIT_IO_COMPLETION);
	mk_lang_check_return(waited == WSA_WAIT_EVENT_0);
	b = WSAGetOverlappedResult(sck, &ovr, &transfered, TRUE, &flags); mk_lang_check_return(b == TRUE);
	mk_lang_check_return(transfered >= 1);
	err = mk_lib_iip_cp_message_parse_message(&store[0], transfered, &parse_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	mk_lang_check_return(msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_set_date);

	err = mk_lib_iip_cp_message_construct(&msg, mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_serialize_message(&store[0], mk_lang_countof(store), &serialize_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(serialize_error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok); mk_lang_check_return(consumed >= 1);
	err = mk_lib_iip_cp_message_destroy(&msg); mk_lang_check_rereturn(err);
	buf.buf = ((CHAR*)(&store[0]));
	buf.len = consumed;
	b = WSAResetEvent(ovr.hEvent); mk_lang_check_return(b == TRUE);
	st = WSASendTo(sck, &buf, 1, NULL, 0, NULL, 0, &ovr, NULL); mk_lang_check_return((st == 0) || (WSAGetLastError() == WSA_IO_PENDING));
	do
	{
		waited = WSAWaitForMultipleEvents(1, &ovr.hEvent, TRUE, WSA_INFINITE, TRUE);
	}while(waited == WSA_WAIT_IO_COMPLETION);
	mk_lang_check_return(waited == WSA_WAIT_EVENT_0);
	b = WSAGetOverlappedResult(sck, &ovr, &transfered, TRUE, &flags); mk_lang_check_return(b == TRUE);
	mk_lang_check_return(transfered == ((DWORD)(consumed)));

	buf.len = mk_lang_countof(store);
	b = WSAResetEvent(ovr.hEvent); mk_lang_check_return(b == TRUE);
	flags = 0;
	st = WSARecv(sck, &buf, 1, NULL, &flags, &ovr, NULL); mk_lang_check_return((st == 0) || (WSAGetLastError() == WSA_IO_PENDING));
	do
	{
		waited = WSAWaitForMultipleEvents(1, &ovr.hEvent, TRUE, WSA_INFINITE, TRUE);
	}while(waited == WSA_WAIT_IO_COMPLETION);
	mk_lang_check_return(waited == WSA_WAIT_EVENT_0);
	b = WSAGetOverlappedResult(sck, &ovr, &transfered, TRUE, &flags); mk_lang_check_return(b == TRUE);
	mk_lang_check_return(transfered >= 1);
	err = mk_lib_iip_cp_message_parse_message(&store[0], transfered, &parse_error_code, &consumed, &msg); mk_lang_check_rereturn(err); mk_lang_check_return(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_ok); mk_lang_check_return(consumed >= 1);

	st = shutdown(sck, SD_BOTH); mk_lang_check_return(st == 0);
	st = closesocket(sck); mk_lang_check_return(st == 0);
	b = WSACloseEvent(ovr.hEvent); mk_lang_check_return(b == TRUE);
	*/

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
