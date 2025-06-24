#ifndef mk_include_guard_mk_win_dll_ws2_c
#define mk_include_guard_mk_win_dll_ws2_c
#include "mk_win_dll_ws2.h"

#include "mk_lang_bui.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"

#define mk_sl_cui_t_name mk_win_dll_ws2_socket
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#if mk_lang_msvc_ver != 0
#pragma comment(lib, "ws2_32.lib")
#endif


mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall WSAStartup(mk_win_base_word_t const version_required, mk_win_dll_ws2_data_pt const data) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall WSACleanup(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall WSAGetLastError(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_dll_ws2_event_t mk_win_base_stdcall WSACreateEvent(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WSACloseEvent(mk_win_dll_ws2_event_t const evt) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WSASetEvent(mk_win_dll_ws2_event_t const evt) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WSAResetEvent(mk_win_dll_ws2_event_t const evt) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_dll_ws2_socket_t mk_win_base_stdcall WSASocketA(mk_win_base_sint_t const family, mk_win_base_sint_t const type, mk_win_base_sint_t const protocol, mk_win_dll_ws2_protocol_info_a_pt const protocol_info, mk_win_base_uint_t const group, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_dll_ws2_socket_t mk_win_base_stdcall WSASocketW(mk_win_base_sint_t const family, mk_win_base_sint_t const type, mk_win_base_sint_t const protocol, mk_win_dll_ws2_protocol_info_w_pt const protocol_info, mk_win_base_uint_t const group, mk_win_base_dword_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall WSAEventSelect(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_event_t const evt, mk_win_base_ulong_t const evts) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall WSAConnect(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pct const addr_buf, mk_win_base_sint_t const addr_len, mk_win_dll_ws2_user_data_pt const caller_data, mk_win_dll_ws2_user_data_pt const callee_data, mk_win_dll_ws2_qos_pt const qos_socket, mk_win_dll_ws2_qos_pt const qos_group) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_dll_ws2_socket_t mk_win_base_stdcall WSAAccept(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pt const addr_buf, mk_win_base_sint_pt const addr_len, mk_win_dll_ws2_accept_condition_func_inner_t const condition_fnc, mk_win_base_uintptr_t const condition_ctx) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_dword_t mk_win_base_stdcall WSAWaitForMultipleEvents(mk_win_base_dword_t const count, mk_win_dll_ws2_event_pct const evts, mk_win_base_bool_t const all, mk_win_base_dword_t const timeout, mk_win_base_bool_t const alertable) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_bool_t mk_win_base_stdcall WSAGetOverlappedResult(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_base_dword_lpt const transferred, mk_win_base_bool_t const wait, mk_win_base_dword_lpt const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall WSASend(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_user_data_pt const bufs, mk_win_base_dword_t const count, mk_win_base_dword_pt const sent, mk_win_base_dword_t const flags, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_dll_ws2_completion_routine_t const callback) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall WSARecv(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_user_data_pt const bufs, mk_win_base_dword_t const count, mk_win_base_dword_lpt const read, mk_win_base_dword_lpt const flags, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_dll_ws2_completion_routine_t const callback) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_ulong_t mk_win_base_stdcall inet_addr(mk_win_base_pchar_lpct const address) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_dll_ws2_socket_t mk_win_base_stdcall socket(mk_win_base_sint_t const family, mk_win_base_sint_t const type, mk_win_base_sint_t const protocol) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall shutdown(mk_win_dll_ws2_socket_t const sck, mk_lang_types_sint_t const how) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall closesocket(mk_win_dll_ws2_socket_t const sck) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall setsockopt(mk_win_dll_ws2_socket_t const sck, mk_win_base_sint_t const level, mk_win_base_sint_t const opt_name, mk_win_base_void_pct const opt_val_buf, mk_win_base_sint_t const opt_val_len) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall connect(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pct const addr_buf, mk_win_base_sint_t const addr_len) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall bind(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pct const addr_buf, mk_win_base_sint_t const addr_len) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall listen(mk_win_dll_ws2_socket_t const sck, mk_win_base_sint_t const backlog) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall send(mk_win_dll_ws2_socket_t const sck, mk_win_base_void_lpct const buf, mk_win_base_sint_t const len, mk_win_base_sint_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall recv(mk_win_dll_ws2_socket_t const sck, mk_win_base_void_lpt const buf, mk_win_base_sint_t const len, mk_win_base_sint_t const flags) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_nodiscard mk_win_base_dll_import mk_win_base_sint_t mk_win_base_stdcall WSAEnumNetworkEvents(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_event_t const evt, mk_win_dll_ws2_network_events_lpt const network_events) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_startup(mk_win_base_ushort_t const version_required, mk_win_dll_ws2_data_pt const data) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = WSAStartup(version_required, data);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_cleanup(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = WSACleanup();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_get_last_error(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = WSAGetLastError();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ws2_event_t mk_win_dll_ws2_create_event(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_dll_ws2_event_t ret;

	ret = WSACreateEvent();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_ws2_close_event(mk_win_dll_ws2_event_t const evt) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WSACloseEvent(evt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_ws2_set_event(mk_win_dll_ws2_event_t const evt) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WSASetEvent(evt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_ws2_reset_event(mk_win_dll_ws2_event_t const evt) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WSAResetEvent(evt);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ws2_socket_t mk_win_dll_ws2_socketa(mk_win_base_sint_t const family, mk_win_base_sint_t const type, mk_win_base_sint_t const protocol, mk_win_dll_ws2_protocol_info_a_pt const protocol_info, mk_win_base_uint_t const group, mk_win_base_dword_t const flags) mk_lang_noexcept
{
	mk_win_dll_ws2_socket_t ret;

	ret = WSASocketA(family, type, protocol, protocol_info, group, flags);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ws2_socket_t mk_win_dll_ws2_socketw(mk_win_base_sint_t const family, mk_win_base_sint_t const type, mk_win_base_sint_t const protocol, mk_win_dll_ws2_protocol_info_w_pt const protocol_info, mk_win_base_uint_t const group, mk_win_base_dword_t const flags) mk_lang_noexcept
{
	mk_win_dll_ws2_socket_t ret;

	ret = WSASocketW(family, type, protocol, protocol_info, group, flags);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_event_select(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_event_t const evt, mk_win_base_ulong_t const evts) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = WSAEventSelect(sck, evt, evts);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_connect2(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pct const addr_buf, mk_win_base_sint_t const addr_len, mk_win_dll_ws2_user_data_pt const caller_data, mk_win_dll_ws2_user_data_pt const callee_data, mk_win_dll_ws2_qos_pt const qos_socket, mk_win_dll_ws2_qos_pt const qos_group) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = WSAConnect(sck, addr_buf, addr_len, caller_data, callee_data, qos_socket, qos_group);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ws2_socket_t mk_win_dll_ws2_accept2(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pt const addr_buf, mk_win_base_sint_pt const addr_len, mk_win_dll_ws2_accept_condition_func_inner_t const condition_fnc, mk_win_base_uintptr_t const condition_ctx) mk_lang_noexcept
{
	mk_win_dll_ws2_socket_t ret;

	ret = WSAAccept(sck, addr_buf, addr_len, condition_fnc, condition_ctx);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_dword_t mk_win_dll_ws2_wait_for_multiple_events(mk_win_base_dword_t const count, mk_win_dll_ws2_event_pct const evts, mk_win_base_bool_t const all, mk_win_base_dword_t const timeout, mk_win_base_bool_t const alertable) mk_lang_noexcept
{
	mk_win_base_dword_t ret;

	ret = WSAWaitForMultipleEvents(count, evts, all, timeout, alertable);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_bool_t mk_win_dll_ws2_get_overlapped_result(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_base_dword_lpt const transferred, mk_win_base_bool_t const wait, mk_win_base_dword_lpt const flags) mk_lang_noexcept
{
	mk_win_base_bool_t ret;

	ret = WSAGetOverlappedResult(sck, overlapped, transferred, wait, flags);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_send2(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_user_data_pt const bufs, mk_win_base_dword_t const count, mk_win_base_dword_pt const sent, mk_win_base_dword_t const flags, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_dll_ws2_completion_routine_t const callback) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = WSASend(sck, bufs, count, sent, flags, overlapped, callback);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_recv2(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_user_data_pt const bufs, mk_win_base_dword_t const count, mk_win_base_dword_lpt const read, mk_win_base_dword_lpt const flags, mk_win_dll_ws2_overlapped_pt const overlapped, mk_win_dll_ws2_completion_routine_t const callback) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = WSARecv(sck, bufs, count, read, flags, overlapped, callback);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_ulong_t mk_win_dll_ws2_inet_addr(mk_win_base_pchar_pct const address) mk_lang_noexcept
{
	mk_win_base_ulong_t ret;

	ret = inet_addr(address);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_dll_ws2_socket_t mk_win_dll_ws2_socket(mk_win_base_sint_t const family, mk_win_base_sint_t const type, mk_win_base_sint_t const protocol) mk_lang_noexcept
{
	mk_win_dll_ws2_socket_t ret;

	ret = socket(family, type, protocol);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_shutdown(mk_win_dll_ws2_socket_t const sck, mk_lang_types_sint_t const how) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = shutdown(sck, how);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_closesocket(mk_win_dll_ws2_socket_t const sck) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = closesocket(sck);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_setsockopt(mk_win_dll_ws2_socket_t const sck, mk_win_base_sint_t const level, mk_win_base_sint_t const opt_name, mk_win_base_void_pct const opt_val_buf, mk_win_base_sint_t const opt_val_len) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = setsockopt(sck, level, opt_name, opt_val_buf, opt_val_len);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_connect(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pct const addr_buf, mk_win_base_sint_t const addr_len) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = connect(sck, addr_buf, addr_len);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_bind(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_sock_addr_pct const addr_buf, mk_win_base_sint_t const addr_len) mk_lang_noexcept
{
	mk_win_base_sint_t  ret;


	ret = bind(sck, addr_buf, addr_len);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_listen(mk_win_dll_ws2_socket_t const sck, mk_win_base_sint_t const backlog) mk_lang_noexcept
{
	mk_win_base_sint_t  ret;


	ret = listen(sck, backlog);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_send(mk_win_dll_ws2_socket_t const sck, mk_win_base_void_pct const buf, mk_win_base_sint_t const len, mk_win_base_sint_t const flags) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = send(sck, buf, len, flags);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_recv(mk_win_dll_ws2_socket_t const sck, mk_win_base_void_pt const buf, mk_win_base_sint_t const len, mk_win_base_sint_t const flags) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = recv(sck, buf, len, flags);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_win_base_sint_t mk_win_dll_ws2_enum_network_events(mk_win_dll_ws2_socket_t const sck, mk_win_dll_ws2_event_t const evt, mk_win_dll_ws2_network_events_pt const network_events) mk_lang_noexcept
{
	mk_win_base_sint_t ret;

	ret = WSAEnumNetworkEvents(sck, evt, network_events);
	return ret;
}


#endif
