#ifndef mk_include_guard_mk_lib_net_connector_c
#define mk_include_guard_mk_lib_net_connector_c
#include "mk_lib_net_connector.h"

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
#include "mk_lib_net_iocp.h"
#include "mk_sl_buffers.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_mallocator.h"
#include "mk_win_dll_ws2.h"


#if mk_lang_configuration_is_debug
#include "mk_lang_stdout.h"
#include "mk_lang_str_lit.h"
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_connector_prrw_construct(mk_lib_net_connector_pt const connector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);

	err = mk_lib_net_socket_construct_void(&connector->m_socket); mk_lang_check_rereturn(err);
	mk_lib_net_destination_clear(&connector->m_local_address);
	mk_lib_net_destination_clear(&connector->m_remote_address);
	err = mk_lib_net_forwarder_iop_target_data_rw_construct(&connector->m_iop_target, mk_lib_net_forwarder_iop_target_data_id_e_connector); mk_lang_check_rereturn(err);
	connector->m_user = mk_lang_null;
	connector->m_in_data_buf = mk_lang_null;
	connector->m_in_data_len = 0;
	err = mk_lib_net_connect_request_construct_void(&connector->m_connect); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_connector_prrw_destroy(mk_lib_net_connector_pt const connector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);

	err = mk_lib_net_socket_destroy(&connector->m_socket); mk_lang_check_rereturn(err);
	if(connector->m_in_data_buf){ err = mk_lib_net_buffers_rw_deallocate_one(connector->m_in_data_buf); mk_lang_check_rereturn(err); }
	err = mk_lib_net_connect_request_destroy(&connector->m_connect); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_connector_prrw_connect_to_destination(mk_lib_net_connector_pt const connector, mk_lib_net_iocp_pt const iocp, mk_lib_net_destination_pct const destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);
	mk_lang_assert(iocp);
	mk_lang_assert(destination);

	err = mk_lib_net_socket_reconstruct(&connector->m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&connector->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_associate_with_socket(iocp, ((mk_lang_types_uintptr_t)(&connector->m_iop_target)), &connector->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_connect_request_reconstruct(&connector->m_connect, &connector->m_socket, destination); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_connect(&connector->m_socket, destination); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connector_prrw_on_iop(mk_lib_net_connector_pt const connector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_assert(connector);
	mk_lang_assert(iop);

	mk_lang_check_todo();
	return 0;
}





/*mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_connector_prrw_destroy(mk_lib_net_connector_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_connector_pt client;
	mk_lib_net_connector_pt next;

	mk_lang_assert(listener);

err = mk_lib_net_buffers_rw_allocate_one(&connector->m_in_data_buf); mk_lang_check_rereturn(err); mk_lang_assert(connector->m_in_data_buf);
	err = mk_lib_net_socket_destroy(&connector->m_socket);
	err = mk_lib_net_ioctl_request_destroy(&connector->m_request_fn_accept_ex);
	err = mk_lib_net_ioctl_request_destroy(&connector->m_request_fn_get_accept_ex_sock_addrs);
	err = mk_lib_net_accept_request_destroy(&connector->m_request_accept); mk_lang_check_rereturn(err);
	client = connector->m_client;
	if(client)
	{
		err = mk_lib_net_connector_prrw_destroy(client); mk_lang_check_rereturn(err);
		err = mk_sl_mallocator_deallocate(client, sizeof(*client)); mk_lang_check_rereturn(err);
	}
	client = connector->m_clients_beg;
	while(client)
	{
		next = connector->m_next;
		err = mk_lib_net_connector_prrw_destroy(client); mk_lang_check_rereturn(err);
		err = mk_sl_mallocator_deallocate(client, sizeof(*client)); mk_lang_check_rereturn(err);
		client = next;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_connector_prrw_accept_log(mk_lib_net_connector_pt const listener) mk_lang_noexcept
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_connector_prrw_accept(mk_lib_net_connector_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_connector_pt client;
	mk_lang_types_void_pt mem;

	mk_lang_assert(listener);
	mk_lang_assert(!connector->m_client);

	err = mk_sl_mallocator_allocate(sizeof(*client), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); client = ((mk_lib_net_connector_pt)(mem)); mk_lang_assert(client);
	err = mk_lib_net_connector_prrw_construct(client); mk_lang_check_rereturn(err);
	connector->m_client = client;
	err = mk_lib_net_accept_request_reconstruct(&connector->m_request_accept, &connector->m_fn_accept_ex, &connector->m_fn_get_accept_ex_sock_addrs, &connector->m_socket, &connector->m_connector->m_socket, &connector->m_connector->m_in_data_buf->m_data.m_uint8s[0], mk_sl_buffers_buffer_size_d); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_issue(&connector->m_request_accept); mk_lang_check_rereturn(err);
	err = mk_lib_net_connector_prrw_accept_log(listener); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_connector_prrw_on_iop_fn_accept_ex(mk_lib_net_connector_pt const listener, mk_lib_net_iocp_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_overlapped);
	mk_lang_assert(iop->m_successful_io_operation);
	mk_lang_assert(iop->m_overlapped == &connector->m_request_fn_accept_ex.m_overlapped);

	err = mk_lib_net_ioctl_request_wait_infinite(&connector->m_request_fn_accept_ex); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&connector->m_request_fn_accept_ex); mk_lang_check_rereturn(err);
	mk_lang_check_return(connector->m_request_fn_accept_ex.m_b != mk_lang_false);
	mk_lang_check_return(connector->m_request_fn_accept_ex.m_transferred == sizeof(connector->m_fn_accept_ex));
	err = mk_lib_net_ioctl_request_reset(&connector->m_request_fn_accept_ex); mk_lang_check_rereturn(err);
	connector->m_request_fn_accept_ex.m_done = mk_lang_true;
	if(connector->m_request_fn_get_accept_ex_sock_addrs.m_done)
	{
		err = mk_lib_net_connector_prrw_accept(listener); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_connector_prrw_on_iop_fn_get_accept_ex_sock_addrs(mk_lib_net_connector_pt const listener, mk_lib_net_iocp_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_overlapped);
	mk_lang_assert(iop->m_successful_io_operation);
	mk_lang_assert(iop->m_overlapped == &connector->m_request_fn_get_accept_ex_sock_addrs.m_overlapped);

	err = mk_lib_net_ioctl_request_wait_infinite(&connector->m_request_fn_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&connector->m_request_fn_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	mk_lang_check_return(connector->m_request_fn_get_accept_ex_sock_addrs.m_b != mk_lang_false);
	mk_lang_check_return(connector->m_request_fn_get_accept_ex_sock_addrs.m_transferred == sizeof(connector->m_fn_get_accept_ex_sock_addrs));
	err = mk_lib_net_ioctl_request_reset(&connector->m_request_fn_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	connector->m_request_fn_get_accept_ex_sock_addrs.m_done = mk_lang_true;
	if(connector->m_request_fn_accept_ex.m_done)
	{
		err = mk_lib_net_connector_prrw_accept(listener); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_connector_prrw_on_iop_accept(mk_lib_net_connector_pt const listener, mk_lib_net_iocp_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_overlapped);
	mk_lang_assert(iop->m_successful_io_operation);
	mk_lang_assert(iop->m_overlapped == &connector->m_request_accept.m_overlapped);
	mk_lang_assert(connector->m_request_fn_accept_ex.m_done);
	mk_lang_assert(connector->m_request_fn_get_accept_ex_sock_addrs.m_done);

	err = mk_lib_net_accept_request_wait_infinite(&connector->m_request_accept); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_get_result(&connector->m_request_accept); mk_lang_check_rereturn(err);
	mk_lang_check_return(connector->m_request_accept.m_b != mk_lang_false);
	mk_lang_check_return(connector->m_request_accept.m_transferred == iop->m_bytes_transferred);
	mk_lang_check_return(connector->m_request_accept.m_transferred >= 1);
	err = mk_lib_net_connector_prrw_add_client(listener); mk_lang_check_rereturn(err);
	err = mk_lib_net_connector_prrw_accept(listener); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_connector_prrw_on_iop(mk_lib_net_connector_pt const listener, mk_lib_net_iocp_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_overlapped);

	if(iop->m_successful_io_operation)
	{
		if     (iop->m_overlapped == &connector->m_request_fn_accept_ex.m_overlapped               ){ err = mk_lib_net_connector_prrw_on_iop_fn_accept_ex               (listener, iop); mk_lang_check_rereturn(err); }
		else if(iop->m_overlapped == &connector->m_request_fn_get_accept_ex_sock_addrs.m_overlapped){ err = mk_lib_net_connector_prrw_on_iop_fn_get_accept_ex_sock_addrs(listener, iop); mk_lang_check_rereturn(err); }
		else if(iop->m_overlapped == &connector->m_request_accept.m_overlapped                     ){ err = mk_lib_net_connector_prrw_on_iop_accept                     (listener, iop); mk_lang_check_rereturn(err); }
		else                                                                                       { mk_lang_assert_false(); }
	}
	else
	{
		mk_lang_check_todo();
	}
	return 0;
}*/


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connector_rw_construct(mk_lib_net_connector_pt const connector) mk_lang_noexcept
{
	return mk_lib_net_connector_prrw_construct(connector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connector_rw_destroy(mk_lib_net_connector_pt const connector) mk_lang_noexcept
{
	return mk_lib_net_connector_prrw_destroy(connector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connector_rw_connect_to_destination(mk_lib_net_connector_pt const connector, mk_lib_net_iocp_pt const iocp, mk_lib_net_destination_pct const destination) mk_lang_noexcept
{
	return mk_lib_net_connector_prrw_connect_to_destination(connector, iocp, destination);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connector_rw_on_iop(mk_lib_net_connector_pt const connector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	return mk_lib_net_connector_prrw_on_iop(connector, iop);
}


#endif
