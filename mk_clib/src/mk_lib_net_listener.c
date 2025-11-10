#ifndef mk_include_guard_mk_lib_net_listener_c
#define mk_include_guard_mk_lib_net_listener_c
#include "mk_lib_net_listener.h"

#include "mk_lang_alignas.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_configuration.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_net.h"
#include "mk_lib_net_buffers.h"
#include "mk_lib_net_forwarder_iop_target_data.h"
#include "mk_lib_net_iocp.h"
#include "mk_sl_buffers.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_mallocator.h"
#include "mk_win_dll_ws2.h"


#if mk_lang_configuration_is_debug
#include "mk_lang_stdout.h"
#include "mk_lang_str_lit.h"
#endif


union mk_lib_net_listener_guid_data_u
{
	mk_lang_types_uchar_t m_uchars[16];
	mk_sl_cui_uint8_t m_uint8s[16];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_net_listener_guid_data_u mk_lib_net_listener_guid_data_t;
struct mk_lib_net_listener_guid_s
{
	mk_lang_alignas(sizeof(mk_lib_net_listener_guid_data_t)) mk_lib_net_listener_guid_data_t m_data;
};
typedef struct mk_lib_net_listener_guid_s mk_lib_net_listener_guid_t;
mk_lang_typedef(mk_lib_net_listener_guid);


mk_lang_constexpr_static_inline mk_lib_net_listener_guid_t const mk_lib_net_listener_k_fn_guid_accept_ex                = {{{ 0xf1, 0x7d, 0x36, 0xb5, 0xac, 0xcb, 0xcf, 0x11, 0x95, 0xca, 0x00, 0x80, 0x5f, 0x48, 0xa1, 0x92 }}};
mk_lang_constexpr_static_inline mk_lib_net_listener_guid_t const mk_lib_net_listener_k_fn_guid_get_accept_ex_sock_addrs = {{{ 0xf2, 0x7d, 0x36, 0xb5, 0xac, 0xcb, 0xcf, 0x11, 0x95, 0xca, 0x00, 0x80, 0x5f, 0x48, 0xa1, 0x92 }}};


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_client_prrw_construct(mk_lib_net_listener_client_pt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);

	client->m_prev = mk_lang_null;
	client->m_next = mk_lang_null;
	err = mk_lib_net_socket_construct(&client->m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	mk_lib_net_destination_clear(&client->m_local_address);
	mk_lib_net_destination_clear(&client->m_remote_address);
	err = mk_lib_net_forwarder_iop_target_data_rw_construct(&client->m_iop_target, mk_lib_net_forwarder_iop_target_data_id_e_client); mk_lang_check_rereturn(err);
	client->m_user = mk_lang_null;
	err = mk_lib_net_buffers_rw_allocate_one(&client->m_in_data_buf); mk_lang_check_rereturn(err); mk_lang_assert(client->m_in_data_buf);
	client->m_in_data_len = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_client_prrw_on_iop(mk_lib_net_listener_client_pt const client, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_assert(client);
	mk_lang_assert(iop);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_client_prrw_destroy(mk_lib_net_listener_client_pt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);

	err = mk_lib_net_socket_destroy(&client->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_buffers_rw_deallocate_one(client->m_in_data_buf); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_add_client(mk_lib_net_listener_pt const listener) mk_lang_noexcept
{
	mk_lib_net_listener_client_pt client;
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(listener->m_client);

	client = listener->m_client;
	client->m_prev = listener->m_clients_end; if(listener->m_clients_end){ mk_lang_assert(!listener->m_clients_end->m_next); listener->m_clients_end->m_next = client; }
	client->m_next = mk_lang_null;
	err = mk_lib_net_socket_set_option_update_accept_context(&client->m_socket, &listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_get_addresses(&listener->m_request_accept, &client->m_local_address, &client->m_remote_address); mk_lang_check_rereturn(err);
	client->m_in_data_buf = ((mk_sl_buffers_buffer_pt)(listener->m_request_accept.m_out_data_buf));
	client->m_in_data_len = listener->m_request_accept.m_transferred;

	listener->m_clients_end = client;
	if(!listener->m_clients_beg){ listener->m_clients_beg = client; }
	listener->m_client = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_get_fn_accept_ex(mk_lib_net_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);

	err = mk_lib_net_ioctl_request_reconstruct(&listener->m_request_fn_accept_ex, &listener->m_socket, ((mk_lang_types_uint_t)(mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer)), ((mk_sl_cui_uint8_pct)(&mk_lib_net_listener_k_fn_guid_accept_ex.m_data.m_uchars[0])), mk_lang_countof(mk_lib_net_listener_k_fn_guid_accept_ex.m_data.m_uchars), ((mk_sl_cui_uint8_pt)(&listener->m_fn_accept_ex)), sizeof(listener->m_fn_accept_ex)); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_issue(&listener->m_request_fn_accept_ex); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_get_fn_get_accept_ex_sock_addrs(mk_lib_net_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);

	err = mk_lib_net_ioctl_request_reconstruct(&listener->m_request_fn_get_accept_ex_sock_addrs, &listener->m_socket, ((mk_lang_types_uint_t)(mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer)), ((mk_sl_cui_uint8_pct)(&mk_lib_net_listener_k_fn_guid_get_accept_ex_sock_addrs.m_data.m_uchars[0])), mk_lang_countof(mk_lib_net_listener_k_fn_guid_get_accept_ex_sock_addrs.m_data.m_uchars), ((mk_sl_cui_uint8_pt)(&listener->m_fn_get_accept_ex_sock_addrs)), sizeof(listener->m_fn_get_accept_ex_sock_addrs)); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_issue(&listener->m_request_fn_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_construct_void(mk_lib_net_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);

	err = mk_lib_net_socket_construct_void(&listener->m_socket); mk_lang_check_rereturn(err);
	listener->m_client = mk_lang_null;
	listener->m_last_given = mk_lang_null;
	listener->m_fn_accept_ex = mk_lang_null;
	listener->m_fn_get_accept_ex_sock_addrs = mk_lang_null;
	err = mk_lib_net_ioctl_request_construct_void(&listener->m_request_fn_accept_ex); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_construct_void(&listener->m_request_fn_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_construct_void(&listener->m_request_accept); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_iop_target_data_rw_construct(&listener->m_iop_target, mk_lib_net_forwarder_iop_target_data_id_e_listener); mk_lang_check_rereturn(err);
	listener->m_clients_beg = mk_lang_null;
	listener->m_clients_end = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_construct_from_destination(mk_lib_net_listener_pt const listener, mk_lib_net_iocp_pt const iocp, mk_lib_net_destination_pct const destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iocp);
	mk_lang_assert(destination);

	err = mk_lib_net_listener_prrw_construct_void(listener); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_reconstruct(&listener->m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_associate_with_socket(iocp, ((mk_lang_types_uintptr_t)(&listener->m_iop_target)), &listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_bind(&listener->m_socket, destination); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_listen(&listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_listener_prrw_get_fn_accept_ex(listener); mk_lang_check_rereturn(err);
	err = mk_lib_net_listener_prrw_get_fn_get_accept_ex_sock_addrs(listener); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_destroy(mk_lib_net_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_listener_client_pt client;
	mk_lib_net_listener_client_pt next;

	mk_lang_assert(listener);

	err = mk_lib_net_socket_destroy(&listener->m_socket);
	err = mk_lib_net_ioctl_request_destroy(&listener->m_request_fn_accept_ex);
	err = mk_lib_net_ioctl_request_destroy(&listener->m_request_fn_get_accept_ex_sock_addrs);
	err = mk_lib_net_accept_request_destroy(&listener->m_request_accept); mk_lang_check_rereturn(err);
	client = listener->m_client;
	if(client)
	{
		err = mk_lib_net_listener_client_prrw_destroy(client); mk_lang_check_rereturn(err);
		err = mk_sl_mallocator_deallocate(client, sizeof(*client)); mk_lang_check_rereturn(err);
	}
	client = listener->m_clients_beg;
	while(client)
	{
		next = client->m_next;
		err = mk_lib_net_listener_client_prrw_destroy(client); mk_lang_check_rereturn(err);
		err = mk_sl_mallocator_deallocate(client, sizeof(*client)); mk_lang_check_rereturn(err);
		client = next;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_accept_log(mk_lib_net_listener_pt const listener) mk_lang_noexcept
{
#if mk_lang_configuration_is_debug
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);

	((mk_lang_types_void_t)(listener));
	err = mk_lang_stdout_println_n(mk_lang_str_lit("Accepting...")); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(listener);

	((mk_lang_types_void_t)(listener));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_accept(mk_lib_net_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_listener_client_pt client;
	mk_lang_types_void_pt mem;

	mk_lang_assert(listener);
	mk_lang_assert(!listener->m_client);

	err = mk_sl_mallocator_allocate(sizeof(*client), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); client = ((mk_lib_net_listener_client_pt)(mem)); mk_lang_assert(client);
	err = mk_lib_net_listener_client_prrw_construct(client); mk_lang_check_rereturn(err);
	listener->m_client = client;
	err = mk_lib_net_accept_request_reconstruct(&listener->m_request_accept, &listener->m_fn_accept_ex, &listener->m_fn_get_accept_ex_sock_addrs, &listener->m_socket, &listener->m_client->m_socket, &listener->m_client->m_in_data_buf->m_data.m_uint8s[0], mk_sl_buffers_buffer_size_d); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_issue(&listener->m_request_accept); mk_lang_check_rereturn(err);
	err = mk_lib_net_listener_prrw_accept_log(listener); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_on_iop_fn_accept_ex(mk_lib_net_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_overlapped);
	mk_lang_assert(iop->m_successful_io_operation);
	mk_lang_assert(iop->m_overlapped == &listener->m_request_fn_accept_ex.m_overlapped);

	err = mk_lib_net_ioctl_request_wait_infinite(&listener->m_request_fn_accept_ex); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&listener->m_request_fn_accept_ex); mk_lang_check_rereturn(err);
	mk_lang_check_return(listener->m_request_fn_accept_ex.m_b != mk_lang_false);
	mk_lang_check_return(listener->m_request_fn_accept_ex.m_transferred == sizeof(listener->m_fn_accept_ex));
	err = mk_lib_net_ioctl_request_reset(&listener->m_request_fn_accept_ex); mk_lang_check_rereturn(err);
	listener->m_request_fn_accept_ex.m_done = mk_lang_true;
	if(listener->m_request_fn_get_accept_ex_sock_addrs.m_done)
	{
		err = mk_lib_net_listener_prrw_accept(listener); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_on_iop_fn_get_accept_ex_sock_addrs(mk_lib_net_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_overlapped);
	mk_lang_assert(iop->m_successful_io_operation);
	mk_lang_assert(iop->m_overlapped == &listener->m_request_fn_get_accept_ex_sock_addrs.m_overlapped);

	err = mk_lib_net_ioctl_request_wait_infinite(&listener->m_request_fn_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&listener->m_request_fn_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	mk_lang_check_return(listener->m_request_fn_get_accept_ex_sock_addrs.m_b != mk_lang_false);
	mk_lang_check_return(listener->m_request_fn_get_accept_ex_sock_addrs.m_transferred == sizeof(listener->m_fn_get_accept_ex_sock_addrs));
	err = mk_lib_net_ioctl_request_reset(&listener->m_request_fn_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	listener->m_request_fn_get_accept_ex_sock_addrs.m_done = mk_lang_true;
	if(listener->m_request_fn_accept_ex.m_done)
	{
		err = mk_lib_net_listener_prrw_accept(listener); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_on_iop_accept(mk_lib_net_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_overlapped);
	mk_lang_assert(iop->m_successful_io_operation);
	mk_lang_assert(iop->m_overlapped == &listener->m_request_accept.m_overlapped);
	mk_lang_assert(listener->m_request_fn_accept_ex.m_done);
	mk_lang_assert(listener->m_request_fn_get_accept_ex_sock_addrs.m_done);

	err = mk_lib_net_accept_request_wait_infinite(&listener->m_request_accept); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_get_result(&listener->m_request_accept); mk_lang_check_rereturn(err);
	mk_lang_check_return(listener->m_request_accept.m_b != mk_lang_false);
	mk_lang_check_return(listener->m_request_accept.m_transferred == iop->m_bytes_transferred);
	mk_lang_check_return(listener->m_request_accept.m_transferred >= 1);
	err = mk_lib_net_listener_prrw_add_client(listener); mk_lang_check_rereturn(err);
	err = mk_lib_net_listener_prrw_accept(listener); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_on_iop(mk_lib_net_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_overlapped);

	if(iop->m_successful_io_operation)
	{
		if     (iop->m_overlapped == &listener->m_request_fn_accept_ex.m_overlapped               ){ err = mk_lib_net_listener_prrw_on_iop_fn_accept_ex               (listener, iop); mk_lang_check_rereturn(err); }
		else if(iop->m_overlapped == &listener->m_request_fn_get_accept_ex_sock_addrs.m_overlapped){ err = mk_lib_net_listener_prrw_on_iop_fn_get_accept_ex_sock_addrs(listener, iop); mk_lang_check_rereturn(err); }
		else if(iop->m_overlapped == &listener->m_request_accept.m_overlapped                     ){ err = mk_lib_net_listener_prrw_on_iop_accept                     (listener, iop); mk_lang_check_rereturn(err); }
		else                                                                                       { mk_lang_assert_false(); }
	}
	else
	{
		mk_lang_check_todo();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_listener_prrw_get_client(mk_lib_net_listener_pt const listener, mk_lib_net_listener_client_ppt const client) mk_lang_noexcept
{
	mk_lang_assert(listener);
	mk_lang_assert(client);

	if(listener->m_last_given)
	{
		listener->m_last_given = listener->m_last_given->m_next;
	}
	else
	{
		listener->m_last_given = listener->m_clients_beg;
	}
	*client = listener->m_last_given;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_rw_construct_void(mk_lib_net_listener_pt const listener) mk_lang_noexcept
{
	return mk_lib_net_listener_prrw_construct_void(listener);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_rw_construct_from_destination(mk_lib_net_listener_pt const listener, mk_lib_net_iocp_pt const iocp, mk_lib_net_destination_pct const destination) mk_lang_noexcept
{
	return mk_lib_net_listener_prrw_construct_from_destination(listener, iocp, destination);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_rw_destroy(mk_lib_net_listener_pt const listener) mk_lang_noexcept
{
	return mk_lib_net_listener_prrw_destroy(listener);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_rw_on_iop(mk_lib_net_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	return mk_lib_net_listener_prrw_on_iop(listener, iop);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_rw_get_client(mk_lib_net_listener_pt const listener, mk_lib_net_listener_client_ppt const client) mk_lang_noexcept
{
	return mk_lib_net_listener_prrw_get_client(listener, client);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_client_rw_on_iop(mk_lib_net_listener_client_pt const client, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	return mk_lib_net_listener_client_prrw_on_iop(client, iop);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_client_rw_destroy(mk_lib_net_listener_client_pt const client) mk_lang_noexcept
{
	return mk_lib_net_listener_client_prrw_destroy(client);
}


#endif
