#ifndef mk_include_guard_mk_lib_net_c
#define mk_include_guard_mk_lib_net_c
#include "mk_lib_net.h"

#include "mk_lang_null.h"
#include "mk_lang_bool.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_more.h"
#include "mk_win_base.h"
#include "mk_win_dll_ws2.h"
#include "mk_win_dll_ntdll.h"
#include "mk_win_dll_kernel_errors.h"


#define mk_sl_cui_t_name mk_lib_net_tcp_port
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint16
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint16_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_net_udp_port
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint16
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint16_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_pr_port_parse_pc(mk_sl_cui_uint16_pt const port, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t len;
	mk_lang_types_bool_t gud;

	mk_lang_assert(port);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	len = mk_sl_cui_uint16_from_str_dec_n(port, str_buf, str_len);
	mk_lang_assert((len >= 1 && len <= str_len) || (!(len >= 1)));
	gud = len >= 1;
	*success = gud;
	*consumed = len;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_pr_port_parse_u8(mk_sl_cui_uint16_pt const port, mk_sl_cui_uint8_pct const bin_buf, mk_lang_types_sint_t const bin_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[4 * mk_sl_cui_uint16_strlen_dec_v];
	mk_lang_types_sint_t err;

	mk_lang_assert(port);
	mk_lang_assert(bin_buf || bin_len == 0);
	mk_lang_assert(bin_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	str_len = mk_lang_min(bin_len, mk_lang_countof(str_buf));
	mk_sl_cui_uint8_to_bi_pchar_many(bin_buf, &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_lib_net_pr_port_parse_pc(port, &str_buf[0], str_len, success, consumed); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_tcp_port_parse_pc(mk_lib_net_tcp_port_pt const tcp_port, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tcp_port);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	err = mk_lib_net_pr_port_parse_pc(&tcp_port->m_elements[0], str_buf, str_len, success, consumed); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_tcp_port_parse_u8(mk_lib_net_tcp_port_pt const tcp_port, mk_sl_cui_uint8_pct const bin_buf, mk_lang_types_sint_t const bin_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(tcp_port);
	mk_lang_assert(bin_buf || bin_len == 0);
	mk_lang_assert(bin_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	err = mk_lib_net_pr_port_parse_u8(&tcp_port->m_elements[0], bin_buf, bin_len, success, consumed); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_udp_port_parse_pc(mk_lib_net_udp_port_pt const udp_port, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(udp_port);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	err = mk_lib_net_pr_port_parse_pc(&udp_port->m_elements[0], str_buf, str_len, success, consumed); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_udp_port_parse_u8(mk_lib_net_udp_port_pt const udp_port, mk_sl_cui_uint8_pct const bin_buf, mk_lang_types_sint_t const bin_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(udp_port);
	mk_lang_assert(bin_buf || bin_len == 0);
	mk_lang_assert(bin_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	err = mk_lib_net_pr_port_parse_u8(&udp_port->m_elements[0], bin_buf, bin_len, success, consumed); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ipv4_address_parse_pc(mk_lib_net_ipv4_address_pt const ipv4_address, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_win_dll_ntdll_status_t st;
	mk_lang_types_pchar_pct terminator;
	mk_win_dll_ws2_ipv4_addr_t addr;
	mk_lang_types_sint_t len;

	mk_lang_assert(ipv4_address);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	st = mk_win_dll_ntdll_rtl_ipv4_string_to_address_a(str_buf, mk_win_base_true, &terminator, &addr); mk_lang_check_return(st == 0);
	mk_sl_cui_uint32_from_bi_ulong(&ipv4_address->m_data.m_u32, &addr.m_data.m_uls[0]);
	len = ((mk_lang_types_sint_t)(terminator - str_buf));
	mk_lang_assert(len >= 1 && len <= str_len);
	*success = mk_lang_true;
	*consumed = len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ipv4_address_parse_u8(mk_lib_net_ipv4_address_pt const ipv4_address, mk_sl_cui_uint8_pct const bin_buf, mk_lang_types_sint_t const bin_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept
{
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[4 * (mk_sl_cui_uint8_strlen_dec_v + 1 + mk_sl_cui_uint8_strlen_dec_v + 1 + mk_sl_cui_uint8_strlen_dec_v + 1 + mk_sl_cui_uint8_strlen_dec_v)];
	mk_lang_types_sint_t err;

	mk_lang_assert(ipv4_address);
	mk_lang_assert(bin_buf || bin_len == 0);
	mk_lang_assert(bin_len >= 0);
	mk_lang_assert(success);
	mk_lang_assert(consumed);

	str_len = mk_lang_min(bin_len, mk_lang_countof(str_buf));
	mk_sl_cui_uint8_to_bi_pchar_many(bin_buf, &str_buf[0], ((mk_lang_types_usize_t)(str_len)));
	err = mk_lib_net_ipv4_address_parse_pc(ipv4_address, &str_buf[0], str_len, success, consumed); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_net_ipv4_address_is_any(mk_lib_net_ipv4_address_pct const ipv4_address) mk_lang_noexcept
{
	mk_lang_types_bool_t is;

	mk_lang_assert(ipv4_address);

	is = mk_sl_cui_uint32_is_zero(&ipv4_address->m_data.m_u32);
	return is;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_net_ipv4_address_is_none(mk_lib_net_ipv4_address_pct const ipv4_address) mk_lang_noexcept
{
	mk_lang_types_bool_t is;

	mk_lang_assert(ipv4_address);

	is = mk_sl_cui_uint32_is_max(&ipv4_address->m_data.m_u32);
	return is;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_sint_t st;
	mk_win_dll_ws2_data_t data;

	st = mk_win_dll_ws2_startup(mk_win_base_make_word(2, 2), &data); mk_lang_check_return(st == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_sint_t st;

	st = mk_win_dll_ws2_cleanup(); mk_lang_check_return(st == 0);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_construct_void(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept
{
	mk_lang_assert(async_connect);

	async_connect->m_event.m_data = mk_win_dll_ws2_event_invalid_val;
	async_connect->m_socket = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_construct(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept
{
	mk_lang_assert(async_connect);

	async_connect->m_event = mk_win_dll_ws2_create_event(); mk_lang_check_return(async_connect->m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	async_connect->m_socket = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_reconstruct(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept
{
	mk_lang_assert(async_connect);

	if(async_connect->m_event.m_data == mk_win_dll_ws2_event_invalid_val)
	{
		async_connect->m_event = mk_win_dll_ws2_create_event(); mk_lang_check_return(async_connect->m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	}
	async_connect->m_socket = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_destroy(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(async_connect);

	if(async_connect->m_event.m_data != mk_win_dll_ws2_event_invalid_val)
	{
		b = mk_win_dll_ws2_close_event(async_connect->m_event); mk_lang_check_return(b != mk_win_base_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_reset(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(async_connect);

	err = mk_lib_net_async_connect_destroy(async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_connect_construct_void(async_connect); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_is_ready(mk_lib_net_async_connect_pt const async_connect, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(async_connect);
	mk_lang_assert(is_ready);
	mk_lang_assert(async_connect->m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &async_connect->m_event, mk_win_base_false, 0, mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_wait_timeout(mk_lib_net_async_connect_pt const async_connect, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(async_connect);
	mk_lang_assert(ms >= 0);
	mk_lang_assert(is_ready);
	mk_lang_assert(async_connect->m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &async_connect->m_event, mk_win_base_false, ((mk_win_base_dword_t)(ms)), mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_wait_infinite(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept
{
	mk_win_base_dword_t waited;

	mk_lang_assert(async_connect);
	mk_lang_assert(async_connect->m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &async_connect->m_event, mk_win_base_false, mk_win_dll_ws2_infinite, mk_win_base_false); mk_lang_check_return(waited == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_get_result(mk_lib_net_async_connect_pt const async_connect, mk_lang_types_sint_pt const result) mk_lang_noexcept
{
	mk_lang_types_sint_t st;
	mk_win_dll_ws2_network_events_t events;
	mk_lang_types_sint_t res;

	mk_lang_assert(async_connect);
	mk_lang_assert(result);
	mk_lang_assert(async_connect->m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(async_connect->m_socket);
	mk_lang_assert(async_connect->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	st = mk_win_dll_ws2_enum_network_events(async_connect->m_socket->m_handle, async_connect->m_event, &events); mk_lang_check_return(st == 0);
	mk_lang_check_return(events.m_event_ids == mk_win_dll_ws2_sck_evt_id_e_fd_connect);
	res = events.m_error_codes[mk_win_dll_ws2_sck_evt_bit_e_connect];
	mk_lang_check_return
	(
		(res == 0) ||
		(res == mk_win_dll_kernel_errors_id_e_wsaeafnosupport) || /* Addresses in the specified family cannot be used with this socket. */
		(res == mk_win_dll_kernel_errors_id_e_wsaenetunreach ) || /* The network cannot be reached from this host at this time. */
		(res == mk_win_dll_kernel_errors_id_e_wsaenobufs     ) || /* No buffer space is available. The socket cannot be connected. */
		(res == mk_win_dll_kernel_errors_id_e_wsaetimedout   ) || /* An attempt to connect timed out without establishing a connection */
		(res == mk_win_dll_kernel_errors_id_e_wsaeconnrefused) || /* The attempt to connect was forcefully rejected. */
		mk_lang_false
	);
	*result = res;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_construct(mk_lib_net_async_rwc_pt const async_rwc) mk_lang_noexcept
{
	mk_lang_assert(async_rwc);

	async_rwc->m_event = mk_win_dll_ws2_create_event(); mk_lang_check_return(async_rwc->m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	async_rwc->m_socket = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_destroy(mk_lib_net_async_rwc_pt const async_rwc) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(async_rwc);
	mk_lang_assert(async_rwc->m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	b = mk_win_dll_ws2_close_event(async_rwc->m_event); mk_lang_check_return(b != mk_win_base_false);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_is_ready(mk_lib_net_async_rwc_pt const async_rwc, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(async_rwc);
	mk_lang_assert(is_ready);
	mk_lang_assert(async_rwc->m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &async_rwc->m_event, mk_win_base_false, 0, mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_wait_timeout(mk_lib_net_async_rwc_pt const async_rwc, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(async_rwc);
	mk_lang_assert(ms >= 0);
	mk_lang_assert(is_ready);
	mk_lang_assert(async_rwc->m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &async_rwc->m_event, mk_win_base_false, ((mk_win_base_dword_t)(ms)), mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_wait_infinite(mk_lib_net_async_rwc_pt const async_rwc) mk_lang_noexcept
{
	mk_win_base_dword_t waited;

	mk_lang_assert(async_rwc);
	mk_lang_assert(async_rwc->m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &async_rwc->m_event, mk_win_base_false, mk_win_dll_ws2_infinite, mk_win_base_false); mk_lang_check_return(waited == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_get_result(mk_lib_net_async_rwc_pt const async_rwc, mk_lang_types_sint_pt const event_id, mk_lang_types_sint_pt const result) mk_lang_noexcept
{
	mk_lang_types_sint_t st;
	mk_win_dll_ws2_network_events_t events;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t res;

	mk_lang_assert(async_rwc);
	mk_lang_assert(event_id);
	mk_lang_assert(result);
	mk_lang_assert(async_rwc->m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(async_rwc->m_socket);
	mk_lang_assert(async_rwc->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	st = mk_win_dll_ws2_enum_network_events(async_rwc->m_socket->m_handle, async_rwc->m_event, &events); mk_lang_check_return(st == 0);
	mk_lang_check_return
	(
		((events.m_event_ids & mk_win_dll_ws2_sck_evt_id_e_fd_read) != 0) ||
		((events.m_event_ids & mk_win_dll_ws2_sck_evt_id_e_fd_write) != 0) ||
		((events.m_event_ids & mk_win_dll_ws2_sck_evt_id_e_fd_close) != 0) ||
		mk_lang_false
	);
	idx =
		((events.m_event_ids & mk_win_dll_ws2_sck_evt_id_e_fd_close) != 0) ?
		(mk_win_dll_ws2_sck_evt_bit_e_close) :
		(
			((events.m_event_ids & mk_win_dll_ws2_sck_evt_id_e_fd_write) != 0) ?
			(mk_win_dll_ws2_sck_evt_bit_e_write) :
			(
				((events.m_event_ids & mk_win_dll_ws2_sck_evt_id_e_fd_read) != 0) ?
				(mk_win_dll_ws2_sck_evt_bit_e_read) :
				(666)
			)
		);
	res = events.m_error_codes[idx];
	mk_lang_check_return
	(
		(res == 0) ||
		(
			(idx == mk_win_dll_ws2_sck_evt_bit_e_read) &&
			(
				(res == mk_win_dll_kernel_errors_id_e_wsaenetdown) || /* The network subsystem has failed. */
				mk_lang_false
			)
		) ||
		(
			(idx == mk_win_dll_ws2_sck_evt_bit_e_write) &&
			(
				(res == mk_win_dll_kernel_errors_id_e_wsaenetdown) || /* The network subsystem has failed. */
				mk_lang_false
			)
		) ||
		(
			(idx == mk_win_dll_ws2_sck_evt_bit_e_close) &&
			(
				(res == mk_win_dll_kernel_errors_id_e_wsaenetdown    ) || /* The network subsystem has failed. */
				(res == mk_win_dll_kernel_errors_id_e_wsaeconnaborted) || /* The connection was terminated due to a time-out or other failure. */
				(res == mk_win_dll_kernel_errors_id_e_wsaeconnreset  ) || /* The connection was reset by the remote side. */
				mk_lang_false
			)
		) ||
		mk_lang_false
	);
	*event_id = idx;
	*result = res;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_construct_void(mk_lib_net_write_request_pt const write_request) mk_lang_noexcept
{
	mk_lang_assert(write_request);

	write_request->m_overlapped.m_event.m_data = mk_win_dll_ws2_event_invalid_val;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_construct(mk_lib_net_write_request_pt const write_request, mk_lib_net_socket_pt const socket, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_win_dll_ws2_event_t event;

	mk_lang_assert(write_request);
	mk_lang_assert(socket);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	event = mk_win_dll_ws2_create_event(); mk_lang_check_return(event.m_data != mk_win_dll_ws2_event_invalid_val);
	write_request->m_socket = socket;
	write_request->m_data_buf = data_buf;
	write_request->m_data_len = data_len;
	write_request->m_flags = 0;
	write_request->m_b = mk_lang_false;
	write_request->m_transferred = 0;
	write_request->m_overlapped.m_internal_lo = 0;
	write_request->m_overlapped.m_internal_hi = 0;
	write_request->m_overlapped.m_offset_lo = 0;
	write_request->m_overlapped.m_offset_hi = 0;
	write_request->m_overlapped.m_event = event;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_reconstruct(mk_lib_net_write_request_pt const write_request, mk_lib_net_socket_pt const socket, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_win_dll_ws2_event_t event;

	mk_lang_assert(write_request);
	mk_lang_assert(socket);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	write_request->m_socket = socket;
	write_request->m_data_buf = data_buf;
	write_request->m_data_len = data_len;
	write_request->m_flags = 0;
	write_request->m_b = mk_lang_false;
	write_request->m_transferred = 0;
	write_request->m_overlapped.m_internal_lo = 0;
	write_request->m_overlapped.m_internal_hi = 0;
	write_request->m_overlapped.m_offset_lo = 0;
	write_request->m_overlapped.m_offset_hi = 0;
	if(write_request->m_overlapped.m_event.m_data == mk_win_dll_ws2_event_invalid_val)
	{
		event = mk_win_dll_ws2_create_event(); mk_lang_check_return(event.m_data != mk_win_dll_ws2_event_invalid_val);
		write_request->m_overlapped.m_event = event;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_destroy(mk_lib_net_write_request_pt const write_request) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(write_request);

	if(write_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val)
	{
		b = mk_win_dll_ws2_close_event(write_request->m_overlapped.m_event); mk_lang_check_return(b != mk_win_base_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_is_ready(mk_lib_net_write_request_pt const write_request, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(write_request);
	mk_lang_assert(is_ready);
	mk_lang_assert(write_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(write_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &write_request->m_overlapped.m_event, mk_win_base_false, 0, mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_wait_timeout(mk_lib_net_write_request_pt const write_request, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(write_request);
	mk_lang_assert(ms);
	mk_lang_assert(is_ready);
	mk_lang_assert(write_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(write_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &write_request->m_overlapped.m_event, mk_win_base_false, ((mk_win_base_dword_t)(ms)), mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_wait_infinite(mk_lib_net_write_request_pt const write_request) mk_lang_noexcept
{
	mk_win_base_dword_t waited;

	mk_lang_assert(write_request);
	mk_lang_assert(write_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(write_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &write_request->m_overlapped.m_event, mk_win_base_false, mk_win_dll_ws2_infinite, mk_win_base_false); mk_lang_check_return(waited == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_get_result(mk_lib_net_write_request_pt const write_request) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t transferred;
	mk_win_base_dword_t flags;

	mk_lang_assert(write_request);
	mk_lang_assert(write_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(write_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	b = mk_win_dll_ws2_get_overlapped_result(write_request->m_socket->m_handle, &write_request->m_overlapped, &transferred, mk_win_base_true, &flags);
	write_request->m_b = b != mk_win_base_false;
	write_request->m_transferred = ((mk_lang_types_sint_t)(transferred));
	write_request->m_flags = ((mk_lang_types_uint_t)(flags));
	mk_lang_check_return(!write_request->m_b || write_request->m_transferred <= write_request->m_data_len);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_construct_void(mk_lib_net_read_request_pt const read_request) mk_lang_noexcept
{
	mk_lang_assert(read_request);

	read_request->m_overlapped.m_event.m_data = mk_win_dll_ws2_event_invalid_val;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_construct(mk_lib_net_read_request_pt const read_request, mk_lib_net_socket_pt const socket, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_win_dll_ws2_event_t event;

	mk_lang_assert(read_request);
	mk_lang_assert(socket);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	event = mk_win_dll_ws2_create_event(); mk_lang_check_return(event.m_data != mk_win_dll_ws2_event_invalid_val);
	read_request->m_socket = socket;
	read_request->m_data_buf = data_buf;
	read_request->m_data_len = data_len;
	read_request->m_flags = 0;
	read_request->m_b = mk_lang_false;
	read_request->m_transferred = 0;
	read_request->m_overlapped.m_internal_lo = 0;
	read_request->m_overlapped.m_internal_hi = 0;
	read_request->m_overlapped.m_offset_lo = 0;
	read_request->m_overlapped.m_offset_hi = 0;
	read_request->m_overlapped.m_event = event;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_reconstruct(mk_lib_net_read_request_pt const read_request, mk_lib_net_socket_pt const socket, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept
{
	mk_win_dll_ws2_event_t event;

	mk_lang_assert(read_request);
	mk_lang_assert(socket);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	read_request->m_socket = socket;
	read_request->m_data_buf = data_buf;
	read_request->m_data_len = data_len;
	read_request->m_flags = 0;
	read_request->m_b = mk_lang_false;
	read_request->m_transferred = 0;
	read_request->m_overlapped.m_internal_lo = 0;
	read_request->m_overlapped.m_internal_hi = 0;
	read_request->m_overlapped.m_offset_lo = 0;
	read_request->m_overlapped.m_offset_hi = 0;
	if(read_request->m_overlapped.m_event.m_data == mk_win_dll_ws2_event_invalid_val)
	{
		event = mk_win_dll_ws2_create_event(); mk_lang_check_return(event.m_data != mk_win_dll_ws2_event_invalid_val);
		read_request->m_overlapped.m_event = event;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_destroy(mk_lib_net_read_request_pt const read_request) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(read_request);

	if(read_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val)
	{
		b = mk_win_dll_ws2_close_event(read_request->m_overlapped.m_event); mk_lang_check_return(b != mk_win_base_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_is_ready(mk_lib_net_read_request_pt const read_request, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(read_request);
	mk_lang_assert(is_ready);
	mk_lang_assert(read_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(read_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &read_request->m_overlapped.m_event, mk_win_base_false, 0, mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_wait_timeout(mk_lib_net_read_request_pt const read_request, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(read_request);
	mk_lang_assert(ms);
	mk_lang_assert(is_ready);
	mk_lang_assert(read_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(read_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &read_request->m_overlapped.m_event, mk_win_base_false, ((mk_win_base_dword_t)(ms)), mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_wait_infinite(mk_lib_net_read_request_pt const read_request) mk_lang_noexcept
{
	mk_win_base_dword_t waited;

	mk_lang_assert(read_request);
	mk_lang_assert(read_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(read_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &read_request->m_overlapped.m_event, mk_win_base_false, mk_win_dll_ws2_infinite, mk_win_base_false); mk_lang_check_return(waited == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_get_result(mk_lib_net_read_request_pt const read_request) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t transferred;
	mk_win_base_dword_t flags;

	mk_lang_assert(read_request);
	mk_lang_assert(read_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(read_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	b = mk_win_dll_ws2_get_overlapped_result(read_request->m_socket->m_handle, &read_request->m_overlapped, &transferred, mk_win_base_true, &flags);
	read_request->m_b = b != mk_win_base_false;
	read_request->m_transferred = ((mk_lang_types_sint_t)(transferred));
	read_request->m_flags = ((mk_lang_types_uint_t)(flags));
	mk_lang_check_return(!read_request->m_b || read_request->m_transferred <= read_request->m_data_len);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ioctl_request_construct_void(mk_lib_net_ioctl_request_pt const ioctl_request) mk_lang_noexcept
{
	mk_lang_assert(ioctl_request);

	ioctl_request->m_overlapped.m_event.m_data = mk_win_dll_ws2_event_invalid_val;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ioctl_request_construct(mk_lib_net_ioctl_request_pt const ioctl_request, mk_lib_net_socket_pt const socket, mk_lang_types_uint_t const control_code, mk_sl_cui_uint8_pct const in_data_buf, mk_lang_types_sint_t const in_data_len, mk_sl_cui_uint8_pt const out_data_buf, mk_lang_types_sint_t const out_data_len) mk_lang_noexcept
{
	mk_win_dll_ws2_event_t event;

	mk_lang_assert(ioctl_request);
	mk_lang_assert(socket);
	mk_lang_assert(control_code || !control_code);
	mk_lang_assert(in_data_buf || in_data_len == 0);
	mk_lang_assert(in_data_len >= 0);
	mk_lang_assert(out_data_buf || out_data_len == 0);
	mk_lang_assert(out_data_len >= 0);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	event = mk_win_dll_ws2_create_event(); mk_lang_check_return(event.m_data != mk_win_dll_ws2_event_invalid_val);
	ioctl_request->m_socket = socket;
	ioctl_request->m_control_code = control_code;
	ioctl_request->m_in_data_buf = in_data_buf;
	ioctl_request->m_in_data_len = in_data_len;
	ioctl_request->m_out_data_buf = out_data_buf;
	ioctl_request->m_out_data_len = out_data_len;
	ioctl_request->m_flags = 0;
	ioctl_request->m_b = mk_lang_false;
	ioctl_request->m_transferred = 0;
	ioctl_request->m_overlapped.m_internal_lo = 0;
	ioctl_request->m_overlapped.m_internal_hi = 0;
	ioctl_request->m_overlapped.m_offset_lo = 0;
	ioctl_request->m_overlapped.m_offset_hi = 0;
	ioctl_request->m_overlapped.m_event = event;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ioctl_request_reconstruct(mk_lib_net_ioctl_request_pt const ioctl_request, mk_lib_net_socket_pt const socket, mk_lang_types_uint_t const control_code, mk_sl_cui_uint8_pct const in_data_buf, mk_lang_types_sint_t const in_data_len, mk_sl_cui_uint8_pt const out_data_buf, mk_lang_types_sint_t const out_data_len) mk_lang_noexcept
{
	mk_win_dll_ws2_event_t event;

	mk_lang_assert(ioctl_request);
	mk_lang_assert(socket);
	mk_lang_assert(control_code || !control_code);
	mk_lang_assert(in_data_buf || in_data_len == 0);
	mk_lang_assert(in_data_len >= 0);
	mk_lang_assert(out_data_buf || out_data_len == 0);
	mk_lang_assert(out_data_len >= 0);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	ioctl_request->m_socket = socket;
	ioctl_request->m_control_code = control_code;
	ioctl_request->m_in_data_buf = in_data_buf;
	ioctl_request->m_in_data_len = in_data_len;
	ioctl_request->m_out_data_buf = out_data_buf;
	ioctl_request->m_out_data_len = out_data_len;
	ioctl_request->m_flags = 0;
	ioctl_request->m_b = mk_lang_false;
	ioctl_request->m_transferred = 0;
	ioctl_request->m_overlapped.m_internal_lo = 0;
	ioctl_request->m_overlapped.m_internal_hi = 0;
	ioctl_request->m_overlapped.m_offset_lo = 0;
	ioctl_request->m_overlapped.m_offset_hi = 0;
	if(ioctl_request->m_overlapped.m_event.m_data == mk_win_dll_ws2_event_invalid_val)
	{
		event = mk_win_dll_ws2_create_event(); mk_lang_check_return(event.m_data != mk_win_dll_ws2_event_invalid_val);
		ioctl_request->m_overlapped.m_event = event;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ioctl_request_destroy(mk_lib_net_ioctl_request_pt const ioctl_request) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(ioctl_request);

	if(ioctl_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val)
	{
		mk_lang_assert(ioctl_request);
		mk_lang_assert(ioctl_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
		mk_lang_assert(ioctl_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);
		b = mk_win_dll_ws2_close_event(ioctl_request->m_overlapped.m_event); mk_lang_check_return(b != mk_win_base_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ioctl_request_reset(mk_lib_net_ioctl_request_pt const ioctl_request) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(ioctl_request);
	mk_lang_assert(ioctl_request->m_socket);
	mk_lang_assert(ioctl_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(ioctl_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	b = mk_win_dll_ws2_close_event(ioctl_request->m_overlapped.m_event); mk_lang_check_return(b != mk_win_base_false);
	ioctl_request->m_overlapped.m_event.m_data = mk_win_dll_ws2_event_invalid_val;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ioctl_request_issue(mk_lib_net_ioctl_request_pt const ioctl_request) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(ioctl_request);
	mk_lang_assert(ioctl_request->m_socket);
	mk_lang_assert(ioctl_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(ioctl_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	err = mk_lib_net_socket_ioctl(ioctl_request->m_socket, ioctl_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ioctl_request_is_ready(mk_lib_net_ioctl_request_pt const ioctl_request, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(ioctl_request);
	mk_lang_assert(is_ready);
	mk_lang_assert(ioctl_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(ioctl_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &ioctl_request->m_overlapped.m_event, mk_win_base_false, 0, mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ioctl_request_wait_timeout(mk_lib_net_ioctl_request_pt const ioctl_request, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(ioctl_request);
	mk_lang_assert(ms);
	mk_lang_assert(is_ready);
	mk_lang_assert(ioctl_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(ioctl_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &ioctl_request->m_overlapped.m_event, mk_win_base_false, ((mk_win_base_dword_t)(ms)), mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ioctl_request_wait_infinite(mk_lib_net_ioctl_request_pt const ioctl_request) mk_lang_noexcept
{
	mk_win_base_dword_t waited;

	mk_lang_assert(ioctl_request);
	mk_lang_assert(ioctl_request->m_socket);
	mk_lang_assert(ioctl_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(ioctl_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &ioctl_request->m_overlapped.m_event, mk_win_base_false, mk_win_dll_ws2_infinite, mk_win_base_false); mk_lang_check_return(waited == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ioctl_request_get_result(mk_lib_net_ioctl_request_pt const ioctl_request) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t transferred;
	mk_win_base_dword_t flags;

	mk_lang_assert(ioctl_request);
	mk_lang_assert(ioctl_request->m_socket);
	mk_lang_assert(ioctl_request->m_socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(ioctl_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	b = mk_win_dll_ws2_get_overlapped_result(ioctl_request->m_socket->m_handle, &ioctl_request->m_overlapped, &transferred, mk_win_base_true, &flags);
	mk_lang_assert(ioctl_request->m_transferred == -1 || transferred == 0);
	ioctl_request->m_b = b != mk_win_base_false;
	if(ioctl_request->m_transferred == -1){ ioctl_request->m_transferred = ((mk_lang_types_sint_t)(transferred)); }
	ioctl_request->m_flags = ((mk_lang_types_uint_t)(flags));
	mk_lang_check_return(!ioctl_request->m_b || ioctl_request->m_transferred <= ioctl_request->m_out_data_len);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_construct_void(mk_lib_net_accept_request_pt const accept_request) mk_lang_noexcept
{
	mk_lang_assert(accept_request);

	accept_request->m_overlapped.m_event.m_data = mk_win_dll_ws2_event_invalid_val;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_construct(mk_lib_net_accept_request_pt const accept_request, mk_lang_types_void_pct const fn_ptr_accept_ex, mk_lang_types_void_pct const fn_ptr_get_accept_ex_sock_addrs, mk_lib_net_socket_pt const socket_listen, mk_lib_net_socket_pt const socket_accept, mk_sl_cui_uint8_pt const out_data_buf, mk_lang_types_sint_t const out_data_len) mk_lang_noexcept
{
	mk_win_dll_ws2_event_t event;

	mk_lang_assert(accept_request);
	mk_lang_assert(fn_ptr_accept_ex);
	mk_lang_assert(fn_ptr_get_accept_ex_sock_addrs);
	mk_lang_assert(socket_listen);
	mk_lang_assert(socket_accept);
	mk_lang_assert(out_data_buf);
	mk_lang_assert(out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	event = mk_win_dll_ws2_create_event(); mk_lang_check_return(event.m_data != mk_win_dll_ws2_event_invalid_val);
	accept_request->m_fn_ptr_accept_ex = fn_ptr_accept_ex;
	accept_request->m_fn_ptr_get_accept_ex_sock_addrs = fn_ptr_get_accept_ex_sock_addrs;
	accept_request->m_socket_listen = socket_listen;
	accept_request->m_socket_accept = socket_accept;
	accept_request->m_out_data_buf = out_data_buf;
	accept_request->m_out_data_len = out_data_len;
	accept_request->m_b = mk_lang_false;
	accept_request->m_flags = 0;
	accept_request->m_transferred = 0;
	accept_request->m_overlapped.m_internal_lo = 0;
	accept_request->m_overlapped.m_internal_hi = 0;
	accept_request->m_overlapped.m_offset_lo = 0;
	accept_request->m_overlapped.m_offset_hi = 0;
	accept_request->m_overlapped.m_event = event;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_reconstruct(mk_lib_net_accept_request_pt const accept_request, mk_lang_types_void_pct const fn_ptr_accept_ex, mk_lang_types_void_pct const fn_ptr_get_accept_ex_sock_addrs, mk_lib_net_socket_pt const socket_listen, mk_lib_net_socket_pt const socket_accept, mk_sl_cui_uint8_pt const out_data_buf, mk_lang_types_sint_t const out_data_len) mk_lang_noexcept
{
	mk_win_dll_ws2_event_t event;

	mk_lang_assert(accept_request);
	mk_lang_assert(fn_ptr_accept_ex);
	mk_lang_assert(fn_ptr_get_accept_ex_sock_addrs);
	mk_lang_assert(socket_listen);
	mk_lang_assert(socket_accept);
	mk_lang_assert(out_data_buf);
	mk_lang_assert(out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	accept_request->m_fn_ptr_accept_ex = fn_ptr_accept_ex;
	accept_request->m_fn_ptr_get_accept_ex_sock_addrs = fn_ptr_get_accept_ex_sock_addrs;
	accept_request->m_socket_listen = socket_listen;
	accept_request->m_socket_accept = socket_accept;
	accept_request->m_out_data_buf = out_data_buf;
	accept_request->m_out_data_len = out_data_len;
	accept_request->m_b = mk_lang_false;
	accept_request->m_flags = 0;
	accept_request->m_transferred = 0;
	accept_request->m_overlapped.m_internal_lo = 0;
	accept_request->m_overlapped.m_internal_hi = 0;
	accept_request->m_overlapped.m_offset_lo = 0;
	accept_request->m_overlapped.m_offset_hi = 0;
	if(accept_request->m_overlapped.m_event.m_data == mk_win_dll_ws2_event_invalid_val)
	{
		event = mk_win_dll_ws2_create_event(); mk_lang_check_return(event.m_data != mk_win_dll_ws2_event_invalid_val);
		accept_request->m_overlapped.m_event = event;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_destroy(mk_lib_net_accept_request_pt const accept_request) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(accept_request);

	if(accept_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val)
	{
		mk_lang_assert(accept_request->m_fn_ptr_accept_ex);
		mk_lang_assert(accept_request->m_fn_ptr_get_accept_ex_sock_addrs);
		mk_lang_assert(accept_request->m_socket_listen);
		mk_lang_assert(accept_request->m_socket_accept);
		mk_lang_assert(accept_request->m_out_data_buf);
		mk_lang_assert(accept_request->m_out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
		mk_lang_assert(accept_request->m_socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
		mk_lang_assert(accept_request->m_socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
		mk_lang_assert(accept_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);
		b = mk_win_dll_ws2_close_event(accept_request->m_overlapped.m_event); mk_lang_check_return(b != mk_win_base_false);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_reset(mk_lib_net_accept_request_pt const accept_request) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(accept_request);
	mk_lang_assert(accept_request->m_fn_ptr_accept_ex);
	mk_lang_assert(accept_request->m_fn_ptr_get_accept_ex_sock_addrs);
	mk_lang_assert(accept_request->m_socket_listen);
	mk_lang_assert(accept_request->m_socket_accept);
	mk_lang_assert(accept_request->m_out_data_buf);
	mk_lang_assert(accept_request->m_out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(accept_request->m_socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	b = mk_win_dll_ws2_close_event(accept_request->m_overlapped.m_event); mk_lang_check_return(b != mk_win_base_false);
	accept_request->m_overlapped.m_event.m_data = mk_win_dll_ws2_event_invalid_val;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_issue(mk_lib_net_accept_request_pt const accept_request) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(accept_request);
	mk_lang_assert(accept_request->m_fn_ptr_accept_ex);
	mk_lang_assert(accept_request->m_fn_ptr_get_accept_ex_sock_addrs);
	mk_lang_assert(accept_request->m_socket_listen);
	mk_lang_assert(accept_request->m_socket_accept);
	mk_lang_assert(accept_request->m_out_data_buf);
	mk_lang_assert(accept_request->m_out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(accept_request->m_socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	err = mk_lib_net_socket_accept(accept_request->m_fn_ptr_accept_ex, accept_request->m_socket_listen, accept_request->m_socket_accept, accept_request->m_out_data_buf, accept_request->m_out_data_len, ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))), ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))), &accept_request->m_transferred, &accept_request->m_overlapped); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_is_ready(mk_lib_net_accept_request_pt const accept_request, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(accept_request);
	mk_lang_assert(accept_request->m_fn_ptr_accept_ex);
	mk_lang_assert(accept_request->m_fn_ptr_get_accept_ex_sock_addrs);
	mk_lang_assert(accept_request->m_socket_listen);
	mk_lang_assert(accept_request->m_socket_accept);
	mk_lang_assert(accept_request->m_out_data_buf);
	mk_lang_assert(accept_request->m_out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(accept_request->m_socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &accept_request->m_overlapped.m_event, mk_win_base_false, 0, mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_wait_timeout(mk_lib_net_accept_request_pt const accept_request, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_win_base_dword_t waited;
	mk_lang_types_bool_t is;

	mk_lang_assert(accept_request);
	mk_lang_assert(accept_request->m_fn_ptr_accept_ex);
	mk_lang_assert(accept_request->m_fn_ptr_get_accept_ex_sock_addrs);
	mk_lang_assert(accept_request->m_socket_listen);
	mk_lang_assert(accept_request->m_socket_accept);
	mk_lang_assert(accept_request->m_out_data_buf);
	mk_lang_assert(accept_request->m_out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(accept_request->m_socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &accept_request->m_overlapped.m_event, mk_win_base_false, ((mk_win_base_dword_t)(ms)), mk_win_base_false); mk_lang_check_return(waited == 0 || waited == mk_win_dll_ws2_timeout);
	is = waited == 0;
	*is_ready = is;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_wait_infinite(mk_lib_net_accept_request_pt const accept_request) mk_lang_noexcept
{
	mk_win_base_dword_t waited;

	mk_lang_assert(accept_request);
	mk_lang_assert(accept_request->m_fn_ptr_accept_ex);
	mk_lang_assert(accept_request->m_fn_ptr_get_accept_ex_sock_addrs);
	mk_lang_assert(accept_request->m_socket_listen);
	mk_lang_assert(accept_request->m_socket_accept);
	mk_lang_assert(accept_request->m_out_data_buf);
	mk_lang_assert(accept_request->m_out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(accept_request->m_socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	waited = mk_win_dll_ws2_wait_for_multiple_events(1, &accept_request->m_overlapped.m_event, mk_win_base_false, mk_win_dll_ws2_infinite, mk_win_base_false); mk_lang_check_return(waited == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_get_result(mk_lib_net_accept_request_pt const accept_request) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t transferred;
	mk_win_base_dword_t flags;

	mk_lang_assert(accept_request);
	mk_lang_assert(accept_request->m_fn_ptr_accept_ex);
	mk_lang_assert(accept_request->m_fn_ptr_get_accept_ex_sock_addrs);
	mk_lang_assert(accept_request->m_socket_listen);
	mk_lang_assert(accept_request->m_socket_accept);
	mk_lang_assert(accept_request->m_out_data_buf);
	mk_lang_assert(accept_request->m_out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(accept_request->m_socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	b = mk_win_dll_ws2_get_overlapped_result(accept_request->m_socket_listen->m_handle, &accept_request->m_overlapped, &transferred, mk_win_base_true, &flags);
	accept_request->m_b = b != mk_win_base_false;
	mk_lang_assert(accept_request->m_transferred == -1 || transferred == 0);
	if(accept_request->m_transferred == -1){ accept_request->m_transferred = ((mk_lang_types_sint_t)(transferred)); }
	accept_request->m_flags = ((mk_lang_types_uint_t)(flags));
	mk_lang_check_return(!accept_request->m_b || accept_request->m_transferred <= accept_request->m_out_data_len);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_addr_to_address(mk_win_dll_ws2_sock_addr_pct addr, mk_lib_net_destination_pt const address) mk_lang_noexcept
{
	mk_lang_types_ushort_t tus;

	mk_lang_assert(addr);
	mk_lang_assert(address);

	switch(addr->m_data.m_family)
	{
		case mk_win_dll_ws2_address_family_e_inet:
		{
			mk_sl_cui_uint8_from_bi_uchar(&address->m_ipv4_address.m_data.m_u8s[0], &addr->m_data.m_ipv4.m_address.m_data.m_ucs[0]);
			mk_sl_cui_uint8_from_bi_uchar(&address->m_ipv4_address.m_data.m_u8s[1], &addr->m_data.m_ipv4.m_address.m_data.m_ucs[1]);
			mk_sl_cui_uint8_from_bi_uchar(&address->m_ipv4_address.m_data.m_u8s[2], &addr->m_data.m_ipv4.m_address.m_data.m_ucs[2]);
			mk_sl_cui_uint8_from_bi_uchar(&address->m_ipv4_address.m_data.m_u8s[3], &addr->m_data.m_ipv4.m_address.m_data.m_ucs[3]);
			tus = mk_win_dll_ws2_ntohs(addr->m_data.m_ipv4.m_port);
			mk_lib_net_tcp_port_from_bi_ushort(&address->m_tcp_port, &tus);
		}
		break;
		default:
		{
			mk_lang_check_todo();
		}
		break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_accept_request_get_addresses(mk_lib_net_accept_request_pt const accept_request, mk_lib_net_destination_pt const address_local, mk_lib_net_destination_pt const address_remote) mk_lang_noexcept
{
	mk_win_dll_ws2_sock_addr_lpt addr_local_obj;
	mk_win_dll_ws2_sock_addr_lpt addr_remote_obj;
	mk_win_base_sint_t addr_local_real;
	mk_win_base_sint_t addr_remote_real;
	mk_lang_types_sint_t err;

	mk_lang_assert(accept_request);
	mk_lang_assert(address_local);
	mk_lang_assert(address_remote);
	mk_lang_assert(accept_request->m_fn_ptr_accept_ex);
	mk_lang_assert(accept_request->m_fn_ptr_get_accept_ex_sock_addrs);
	mk_lang_assert(accept_request->m_socket_listen);
	mk_lang_assert(accept_request->m_socket_accept);
	mk_lang_assert(accept_request->m_out_data_buf);
	mk_lang_assert(accept_request->m_out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(accept_request->m_socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(accept_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	mk_win_dll_ws2_get_accept_ex_sock_addrs(accept_request->m_fn_ptr_get_accept_ex_sock_addrs, accept_request->m_out_data_buf, ((mk_win_base_dword_t)(accept_request->m_out_data_len)), ((mk_win_base_sint_t)(sizeof(*addr_local_obj))), ((mk_win_base_sint_t)(sizeof(*addr_remote_obj))), &addr_local_obj, &addr_local_real, &addr_remote_obj, &addr_remote_real);
	mk_lang_assert(addr_local_real >= 1);
	mk_lang_assert(addr_local_real <= ((mk_win_base_sint_t)(sizeof(*addr_local_obj))));
	mk_lang_assert(addr_remote_real >= 1);
	mk_lang_assert(addr_remote_real <= ((mk_win_base_sint_t)(sizeof(*addr_remote_obj))));
	err = mk_lib_net_addr_to_address(addr_local_obj, address_local); mk_lang_check_rereturn(err);
	err = mk_lib_net_addr_to_address(addr_remote_obj, address_remote); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_construct_void(mk_lib_net_socket_pt const socket) mk_lang_noexcept
{
	mk_lang_assert(socket);

	socket->m_handle.m_elements[0] = mk_win_dll_ws2_invalid_socket;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_construct(mk_lib_net_socket_pt const socket, mk_lib_net_address_family_t const af, mk_lib_net_address_type_t const at, mk_lib_net_address_protocol_t const ap) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_sometimes_uninitialized.h"
	mk_win_base_sint_t family;
	mk_win_base_sint_t type;
	mk_win_base_sint_t protocol;
	mk_win_dll_ws2_protocol_info_w_pt protocol_info;
	mk_win_base_uint_t group;
	mk_win_base_dword_t flags;

	mk_lang_assert(socket);
	mk_lang_assert(af >= 0);
	mk_lang_assert(af < mk_lib_net_address_family_e_dummy_end);
	mk_lang_assert(at >= 0);
	mk_lang_assert(at < mk_lib_net_address_type_e_dummy_end);
	mk_lang_assert(ap >= 0);
	mk_lang_assert(ap < mk_lib_net_address_protocol_e_dummy_end);

	switch(af)
	{
		case mk_lib_net_address_family_e_ipv4: family = mk_win_dll_ws2_address_family_e_inet ; break;
		case mk_lib_net_address_family_e_ipv6: family = mk_win_dll_ws2_address_family_e_inet6; break;
		case mk_lib_net_address_family_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&family);
	switch(at)
	{
		case mk_lib_net_address_type_e_stream: type = mk_win_dll_ws2_address_type_e_stream; break;
		case mk_lib_net_address_type_e_dgram : type = mk_win_dll_ws2_address_type_e_dgram ; break;
		case mk_lib_net_address_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&type);
	switch(ap)
	{
		case mk_lib_net_address_protocol_e_tcp : protocol = mk_win_dll_ws2_address_protocol_e_tcp ; break;
		case mk_lib_net_address_protocol_e_udp : protocol = mk_win_dll_ws2_address_protocol_e_udp ; break;
		case mk_lib_net_address_protocol_e_icmp: protocol = mk_win_dll_ws2_address_protocol_e_icmp; break;
		case mk_lib_net_address_protocol_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&protocol);
	protocol_info = mk_lang_null;
	group = 0;
	flags = mk_win_dll_ws2_address_flags_e_overlapped | mk_win_dll_ws2_address_flags_e_no_handle_inherit;
	socket->m_handle = mk_win_dll_ws2_socketw(family, type, protocol, protocol_info, group, flags); mk_lang_check_return(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_reconstruct(mk_lib_net_socket_pt const socket, mk_lib_net_address_family_t const af, mk_lib_net_address_type_t const at, mk_lib_net_address_protocol_t const ap) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket);
	mk_lang_assert(af >= 0);
	mk_lang_assert(af < mk_lib_net_address_family_e_dummy_end);
	mk_lang_assert(at >= 0);
	mk_lang_assert(at < mk_lib_net_address_type_e_dummy_end);
	mk_lang_assert(ap >= 0);
	mk_lang_assert(ap < mk_lib_net_address_protocol_e_dummy_end);

	if(socket->m_handle.m_elements[0] == mk_win_dll_ws2_invalid_socket)
	{
		err = mk_lib_net_socket_construct(socket, af, at, ap); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_destroy(mk_lib_net_socket_pt const socket) mk_lang_noexcept
{
	mk_lang_types_sint_t st;

	mk_lang_assert(socket);

	if(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket)
	{
		//st = mk_win_dll_ws2_shutdown(socket->m_handle, mk_win_dll_ws2_shutdown_how_e_both); mk_lang_check_return(st == 0);
		st = mk_win_dll_ws2_closesocket(socket->m_handle); mk_lang_check_return(st == 0);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_to_text(mk_lib_net_socket_pt const socket, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t len;

	mk_lang_assert(socket);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	ptr = str_buf;
	rem = str_len;
	if(rem >= 2)
	{
		ptr[0] = '0';
		ptr[1] = 'x';
	}
	ptr += 2;
	rem -= 2;
	len = mk_win_dll_ws2_socket_to_str_hex_n(&socket->m_handle, ptr, rem); mk_lang_assert((!(len >= 1)) || (len >= 1 && len <= str_len)); ptr += len; rem -= len;
	len = str_len - rem;
	*out_len = len;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_set_option_nodelay_val(mk_lib_net_socket_pt const socket, mk_lang_types_bool_t const val) mk_lang_noexcept
{
	mk_win_base_dword_t vvv;
	mk_win_dll_ws2_socket_t s;
	mk_win_base_sint_t level;
	mk_win_base_sint_t opt_name;
	mk_win_base_void_pct opt_val_buf;
	mk_win_base_sint_t opt_val_len;
	mk_lang_types_sint_t st;

	mk_lang_assert(socket);
	mk_lang_assert(val == mk_lang_false || val == mk_lang_true);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	vvv = val ? 1 : 0;
	s = socket->m_handle;
	level = mk_win_dll_ws2_sck_level_tcp;
	opt_name = mk_win_dll_ws2_sck_opt_tcp_e_tcp_nodelay;
	opt_val_buf = &vvv;
	opt_val_len = ((mk_win_base_sint_t)(sizeof(vvv)));
	st = mk_win_dll_ws2_setsockopt(s, level, opt_name, opt_val_buf, opt_val_len); mk_lang_check_return(st == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_set_option_nodelay_true(mk_lib_net_socket_pt const socket) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	err = mk_lib_net_socket_set_option_nodelay_val(socket, mk_lang_true); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_set_option_nodelay_false(mk_lib_net_socket_pt const socket) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	err = mk_lib_net_socket_set_option_nodelay_val(socket, mk_lang_false); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_get_option_connect_time(mk_lib_net_socket_pt const socket, mk_lang_types_sint_pt const connect_time) mk_lang_noexcept
{
	mk_win_dll_ws2_socket_t s;
	mk_win_base_sint_t level;
	mk_win_base_sint_t opt_name;
	mk_win_base_void_pt opt_val_buf;
	mk_win_base_dword_t vvv;
	mk_win_base_sint_t opt_val_len;
	mk_win_base_sint_t opt_val_real;
	mk_lang_types_sint_t st;
	mk_lang_types_sint_t time;

	mk_lang_assert(socket);
	mk_lang_assert(connect_time);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	s = socket->m_handle;
	level = mk_win_dll_ws2_sck_level_socket;
	opt_name = mk_win_dll_ws2_sck_opt_socket_e_connect_time;
	opt_val_buf = &vvv;
	opt_val_len = ((mk_win_base_sint_t)(sizeof(vvv)));
	opt_val_real = opt_val_len;
	st = mk_win_dll_ws2_getsockopt(s, level, opt_name, opt_val_buf, &opt_val_real); mk_lang_check_return(st == 0); mk_lang_check_return(opt_val_real == opt_val_len);
	if(vvv != ((mk_win_base_dword_t)(0xfffffffful)))
	{
		time = ((mk_lang_types_sint_t)(vvv));
		if(time == -1){ time = -2; }
		*connect_time = time;
	}
	else
	{
		*connect_time = -1;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_associate_async_connect(mk_lib_net_socket_pt const socket, mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept
{
	mk_lang_types_sint_t st;

	mk_lang_assert(socket);
	mk_lang_assert(async_connect);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(async_connect->m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(!async_connect->m_socket);

	st = mk_win_dll_ws2_event_select(socket->m_handle, async_connect->m_event, mk_win_dll_ws2_sck_evt_id_e_fd_connect); mk_lang_check_return(st == 0);
	async_connect->m_socket = socket;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_associate_async_rwc(mk_lib_net_socket_pt const socket, mk_lib_net_async_rwc_pt const async_rwc) mk_lang_noexcept
{
	mk_lang_types_sint_t st;

	mk_lang_assert(socket);
	mk_lang_assert(async_rwc);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(async_rwc->m_event.m_data != mk_win_dll_ws2_event_invalid_val);
	mk_lang_assert(!async_rwc->m_socket);

	st = mk_win_dll_ws2_event_select(socket->m_handle, async_rwc->m_event, mk_win_dll_ws2_sck_evt_id_e_fd_read | mk_win_dll_ws2_sck_evt_id_e_fd_write | mk_win_dll_ws2_sck_evt_id_e_fd_close); mk_lang_check_return(st == 0);
	async_rwc->m_socket = socket;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_connect(mk_lib_net_socket_pt const socket, mk_lib_net_destination_pct const destination) mk_lang_noexcept
{
	mk_win_dll_ws2_socket_t s;
	mk_lang_types_ushort_t tus;
	mk_win_dll_ws2_sock_addr_t addr;
	mk_win_dll_ws2_sock_addr_pt addr_buf;
	mk_win_base_sint_t addr_len;
	mk_win_dll_ws2_user_data_pt caller_data;
	mk_win_dll_ws2_user_data_pt callee_data;
	mk_win_dll_ws2_qos_pt qos_socket;
	mk_win_dll_ws2_qos_pt qos_group;
	mk_lang_types_sint_t st;
	mk_lang_types_sint_t gle;

	mk_lang_assert(socket);
	mk_lang_assert(destination);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(!mk_lib_net_ipv4_address_is_any(&destination->m_ipv4_address));
	mk_lang_assert(!mk_lib_net_ipv4_address_is_none(&destination->m_ipv4_address));
	mk_lang_assert(!mk_lib_net_tcp_port_is_zero(&destination->m_tcp_port));

	s = socket->m_handle;
	mk_lib_net_tcp_port_to_bi_ushort(&destination->m_tcp_port, &tus);
	addr.m_data.m_family = mk_win_dll_ws2_address_family_e_inet;
	addr.m_data.m_ipv4.m_family = mk_win_dll_ws2_address_family_e_inet;
	addr.m_data.m_ipv4.m_port = mk_win_dll_ws2_htons(tus);
	mk_sl_cui_uint32_to_bi_ulong(&destination->m_ipv4_address.m_data.m_u32, &addr.m_data.m_ipv4.m_address.m_data.m_uls[0]);
	addr_buf = &addr;
	addr_len = ((mk_win_base_sint_t)(sizeof(addr)));
	caller_data = mk_win_base_null;
	callee_data = mk_win_base_null;
	qos_socket = mk_win_base_null;
	qos_group = mk_win_base_null;
	st = mk_win_dll_ws2_connect2(s, addr_buf, addr_len, caller_data, callee_data, qos_socket, qos_group); mk_lang_check_return((st == 0) || (st != 0 && (gle = mk_win_dll_ws2_get_last_error()) == mk_win_dll_kernel_errors_id_e_wsaewouldblock));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_bind(mk_lib_net_socket_pt const socket, mk_lib_net_destination_pct const destination) mk_lang_noexcept
{
	mk_win_dll_ws2_socket_t s;
	mk_lang_types_ushort_t tus;
	mk_win_dll_ws2_sock_addr_t addr_obj;
	mk_win_dll_ws2_sock_addr_pt addr_buf;
	mk_win_base_sint_t addr_len;
	mk_lang_types_sint_t st;

	mk_lang_assert(socket);
	mk_lang_assert(destination);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(!mk_lib_net_ipv4_address_is_none(&destination->m_ipv4_address));
	mk_lang_assert(!mk_lib_net_tcp_port_is_zero(&destination->m_tcp_port));

	s = socket->m_handle;
	mk_lib_net_tcp_port_to_bi_ushort(&destination->m_tcp_port, &tus);
	addr_obj.m_data.m_family = mk_win_dll_ws2_address_family_e_inet;
	addr_obj.m_data.m_ipv4.m_family = mk_win_dll_ws2_address_family_e_inet;
	addr_obj.m_data.m_ipv4.m_port = mk_win_dll_ws2_htons(tus);
	mk_sl_cui_uint32_to_bi_ulong(&destination->m_ipv4_address.m_data.m_u32, &addr_obj.m_data.m_ipv4.m_address.m_data.m_uls[0]);
	addr_buf = &addr_obj;
	addr_len = ((mk_win_base_sint_t)(sizeof(addr_obj)));
	st = mk_win_dll_ws2_bind(s, addr_buf, addr_len); mk_lang_check_return(st == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_listen(mk_lib_net_socket_pt const socket) mk_lang_noexcept
{
	mk_win_dll_ws2_socket_t s;
	mk_lang_types_sint_t st;

	mk_lang_assert(socket);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	s = socket->m_handle;
	st = mk_win_dll_ws2_listen(s, mk_win_dll_ws2_max_conn); mk_lang_check_return(st == 0);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_accept(mk_lang_types_void_pct const fn_ptr, mk_lib_net_socket_pt const socket_listen, mk_lib_net_socket_pt const socket_accept, mk_sl_cui_uint8_pt const out_data_buf, mk_lang_types_sint_t const out_data_len, mk_lang_types_sint_t const local_address_len, mk_lang_types_sint_t const remote_address_len, mk_lang_types_sint_pt const transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t trans;
	mk_win_base_sint_t gle;

	mk_lang_assert(fn_ptr);
	mk_lang_assert(socket_listen);
	mk_lang_assert(socket_accept);
	mk_lang_assert(out_data_buf);
	mk_lang_assert(out_data_len >= 2 * ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(local_address_len >= ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(remote_address_len >= ((mk_lang_types_sint_t)(sizeof(mk_win_dll_ws2_sock_addr_t))));
	mk_lang_assert(transferred);
	mk_lang_assert(overlapped);
	mk_lang_assert(socket_listen->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(socket_accept->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);

	b = mk_win_dll_ws2_accept_ex(fn_ptr, socket_listen->m_handle, socket_accept->m_handle, out_data_buf, ((mk_win_base_dword_t)(out_data_len)), ((mk_win_base_dword_t)(local_address_len)), ((mk_win_base_dword_t)(remote_address_len)), &trans, ((mk_win_dll_ws2_overlapped_pt)(overlapped))); mk_lang_check_return((b != mk_win_base_false) || ((gle = mk_win_dll_ws2_get_last_error()) == mk_win_dll_kernel_errors_id_e_io_pending));
	if(b != mk_win_base_false)
	{
		mk_lang_assert(trans <= ((mk_win_base_dword_t)(out_data_len)));
		*transferred = ((mk_lang_types_sint_t)(trans));
	}
	else
	{
		*transferred = -1;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_send(mk_lib_net_socket_pt const socket, mk_lib_net_write_request_pt const write_request) mk_lang_noexcept
{
	mk_win_dll_ws2_user_data_t buf;
	mk_lang_types_sint_t st;
	mk_lang_types_sint_t gle;

	mk_lang_assert(socket);
	mk_lang_assert(write_request);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(write_request->m_data_buf || write_request->m_data_len == 0);
	mk_lang_assert(write_request->m_data_len >= 0);
	mk_lang_assert(write_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	#include "mk_lang_warning_clang_push_cast_qual.h"
	buf.m_len = ((mk_win_base_ulong_t)(write_request->m_data_len));
	buf.m_buf = ((mk_win_base_void_pt)(write_request->m_data_buf));
	#include "mk_lang_warning_clang_pop.h"
	st = mk_win_dll_ws2_send2(socket->m_handle, &buf, 1, mk_lang_null, write_request->m_flags, &write_request->m_overlapped, mk_lang_null); mk_lang_check_return((st == 0) || (st != 0 && (gle = mk_win_dll_ws2_get_last_error()) == mk_win_dll_kernel_errors_id_e_io_pending));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_recv(mk_lib_net_socket_pt const socket, mk_lib_net_read_request_pt const read_request) mk_lang_noexcept
{
	mk_win_dll_ws2_user_data_t buf;
	mk_win_base_dword_t flags;
	mk_lang_types_sint_t st;
	mk_lang_types_sint_t gle;

	mk_lang_assert(socket);
	mk_lang_assert(read_request);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(read_request->m_data_buf || read_request->m_data_len == 0);
	mk_lang_assert(read_request->m_data_len >= 0);
	mk_lang_assert(read_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	buf.m_len = ((mk_win_base_ulong_t)(read_request->m_data_len));
	buf.m_buf = ((mk_win_base_void_pt)(read_request->m_data_buf));
	flags = ((mk_win_base_dword_t)(read_request->m_flags));
	st = mk_win_dll_ws2_recv2(socket->m_handle, &buf, 1, mk_lang_null, &flags, &read_request->m_overlapped, mk_lang_null); mk_lang_check_return((st == 0) || (st != 0 && (gle = mk_win_dll_ws2_get_last_error()) == mk_win_dll_kernel_errors_id_e_io_pending));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_ioctl(mk_lib_net_socket_pt const socket, mk_lib_net_ioctl_request_pt const ioctl_request) mk_lang_noexcept
{
	mk_win_dll_ws2_socket_t s;
	mk_win_base_dword_t control_code;
	mk_win_base_void_lpct in_data_buf;
	mk_win_base_dword_t in_data_len;
	mk_win_base_void_lpt out_data_buf;
	mk_win_base_dword_t out_data_len;
	mk_win_base_dword_lpt transferred;
	mk_win_base_dword_t trns;
	mk_win_dll_ws2_overlapped_lpt overlapped;
	mk_win_base_void_lpt /* todo */ callback;
	mk_lang_types_sint_t st;
	mk_lang_types_sint_t gle;

	mk_lang_assert(socket);
	mk_lang_assert(ioctl_request);
	mk_lang_assert(socket->m_handle.m_elements[0] != mk_win_dll_ws2_invalid_socket);
	mk_lang_assert(ioctl_request->m_in_data_buf || ioctl_request->m_in_data_len == 0);
	mk_lang_assert(ioctl_request->m_in_data_len >= 0);
	mk_lang_assert(ioctl_request->m_out_data_buf || ioctl_request->m_out_data_len == 0);
	mk_lang_assert(ioctl_request->m_out_data_len >= 0);
	mk_lang_assert(ioctl_request->m_overlapped.m_event.m_data != mk_win_dll_ws2_event_invalid_val);

	ioctl_request->m_transferred = -1;
	s = socket->m_handle;
	control_code = ioctl_request->m_control_code;
	in_data_buf = ioctl_request->m_in_data_buf;
	in_data_len = ((mk_win_base_dword_t)(ioctl_request->m_in_data_len));
	out_data_buf = ioctl_request->m_out_data_buf;
	out_data_len = ((mk_win_base_dword_t)(ioctl_request->m_out_data_len));
	transferred = &trns;
	overlapped = &ioctl_request->m_overlapped;
	callback = mk_win_base_null;
	st = mk_win_dll_ws2_send2_ioctl(s, control_code, in_data_buf, in_data_len, out_data_buf, out_data_len, transferred, overlapped, callback); mk_lang_check_return((st == 0) || (st != 0 && (gle = mk_win_dll_ws2_get_last_error()) == mk_win_dll_kernel_errors_id_e_io_pending));
	if(st == 0)
	{
		ioctl_request->m_transferred = ((mk_lang_types_sint_t)(trns));
	}
	return 0;
}


#endif
