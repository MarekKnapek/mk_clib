#ifndef mk_include_guard_mk_lib_net_forwarder_c
#define mk_include_guard_mk_lib_net_forwarder_c
#include "mk_lib_net_forwarder.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_str_lit.h"
#include "mk_lang_types.h"
#include "mk_lib_net_connector.h"
#include "mk_lib_net_forwarder_iop_target_data.h"
#include "mk_lib_net_forwarder_iop_target_logic.h"
#include "mk_lib_net_iocp.h"
#include "mk_lib_net_listener.h"
#include "mk_sl_mallocator.h"
#include "mk_win_dll_kernel_process.h"
#include "mk_win_dll_kernel_synchronization.h"


#define mk_sl_vector_t_name mk_lib_net_forwarder_listeners
#define mk_sl_vector_t_element_type mk_lib_net_listener_pt
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

#define mk_sl_vector_t_name mk_lib_net_forwarder_clients
#define mk_sl_vector_t_element_type mk_lib_net_listener_client_pt
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#define mk_lib_net_forwarder_k_iocp_id_poke 0
#define mk_lib_net_forwarder_k_iocp_id_end 1
#define mk_lib_net_forwarder_k_iocp_id_connected 2


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_construct(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	forwarder->m_want_stop = mk_lang_false;
	err = mk_lib_net_iocp_construct(&forwarder->m_iocp, 0); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_listeners_rw_construct(&forwarder->m_listeners); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_clients_rw_construct(&forwarder->m_clients); mk_lang_check_rereturn(err);
	forwarder->m_thread = mk_win_base_handle_get_null();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_reap_listeners(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_net_listener_ppt pelem;
	mk_lib_net_listener_pt elem;
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	n = mk_lib_net_forwarder_listeners_rw_size(&forwarder->m_listeners);
	for(i = 0; i != n; ++i)
	{
		pelem = mk_lib_net_forwarder_listeners_rw_at(&forwarder->m_listeners, i); mk_lang_assert(pelem); elem = *pelem; mk_lang_assert(elem);
		err = mk_lib_net_listener_rw_destroy(elem); mk_lang_check_rereturn(err);
		err = mk_sl_mallocator_deallocate(elem, sizeof(*elem)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_reap_connectors(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_net_listener_client_ppt pelem;
	mk_lib_net_listener_client_pt elem;
	mk_lib_net_connector_pt connector;
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	n = mk_lib_net_forwarder_clients_rw_size(&forwarder->m_clients);
	for(i = 0; i != n; ++i)
	{
		pelem = mk_lib_net_forwarder_clients_rw_at(&forwarder->m_clients, i); mk_lang_assert(pelem); elem = *pelem; mk_lang_assert(elem);
		connector = ((mk_lib_net_connector_pt)(elem->m_user));
		if(connector)
		{
			err = mk_lib_net_connector_rw_destroy(connector); mk_lang_check_rereturn(err);
			err = mk_sl_mallocator_deallocate(connector, sizeof(*connector)); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_stop_thread(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t waited;

	mk_lang_assert(forwarder);

	if(!mk_win_base_handle_is_null(forwarder->m_thread))
	{
		mk_lang_assert(!mk_win_dll_ws2_event_is_null(forwarder->m_event));
		b = mk_win_dll_ws2_set_event(forwarder->m_event); mk_lang_check_return(b != mk_win_base_false);
		waited = mk_win_dll_kernel_synchronization_wait_one(forwarder->m_thread, mk_win_base_infinite); mk_lang_check_return(waited == 0);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_destroy(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	err = mk_lib_net_forwarder_prrw_stop_thread(forwarder); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_destroy(&forwarder->m_iocp); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_prrw_reap_connectors(forwarder); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_prrw_reap_listeners(forwarder); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_listeners_rw_destroy(&forwarder->m_listeners); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_clients_rw_destroy(&forwarder->m_clients); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_add_listener(mk_lib_net_forwarder_pt const forwarder, mk_lib_net_destination_pct const destination) mk_lang_noexcept
{
	mk_lib_net_listener_pt listener;
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	err = mk_lib_net_forwarder_listeners_rw_reserve_additional(&forwarder->m_listeners, 1); mk_lang_check_rereturn(err);
	err = mk_sl_mallocator_allocate(sizeof(*listener), ((mk_lang_types_void_ppt)(&listener))); mk_lang_check_rereturn(err); mk_lang_assert(listener);
	err = mk_lib_net_listener_rw_construct_from_destination(listener, &forwarder->m_iocp, destination); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_listeners_rw_push_back_copy_single(&forwarder->m_listeners, &listener); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_request_stop(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	forwarder->m_want_stop = mk_lang_true;
	err = mk_lib_net_iocp_post(&forwarder->m_iocp, 0, mk_lib_net_forwarder_k_iocp_id_poke, mk_lang_null); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_on_get_server_destiation(mk_lib_net_forwarder_pt const forwarder, mk_lib_net_destination_pt const destination) mk_lang_noexcept
{
	#define mk_lib_net_forwarder_k_ip_address "127.0.0.1"
	#define mk_lib_net_forwarder_k_tcp_port 7654

	mk_lang_types_sint_t err;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(forwarder);
	mk_lang_assert(destination);

	err = mk_lib_net_ipv4_address_parse_pc(&destination->m_ipv4_address, mk_lang_str_lit(mk_lib_net_forwarder_k_ip_address), &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_assert(gud); mk_lang_assert(consumed == mk_lang_countstr(mk_lib_net_forwarder_k_ip_address));
	destination->m_tcp_port.m_elements[0].m_elements[0] = mk_lib_net_forwarder_k_tcp_port;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_thread_proc(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_win_dll_ws2_event_t evts[16];
	mk_win_base_dword_t count;
	mk_win_base_bool_t b;
	mk_win_dll_ws2_event_pt events;
	mk_win_base_bool_t all;
	mk_win_base_dword_t timeout;
	mk_win_base_bool_t alertable;
	mk_win_base_dword_t waited;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t idx;
	mk_lang_types_sint_t err;
	mk_lib_net_listener_client_ppt pclient;
	mk_lib_net_listener_client_pt client;
	mk_lib_net_connector_pt connector;
	mk_lib_net_connector_pt connectors[mk_lang_countof(evts) - 1];

	mk_lang_assert(forwarder);

	do
	{
		evts[0] = forwarder->m_event;
		count = 1;
		n = mk_lib_net_forwarder_clients_rw_size(&forwarder->m_clients);
		for(i = 0; i != n; ++i)
		{
			if(count == mk_lang_countof(evts))
			{
				break;
			}
			pclient = mk_lib_net_forwarder_clients_rw_at(&forwarder->m_clients, i); mk_lang_assert(pclient); client = *pclient; mk_lang_assert(client);
			if(client->m_user)
			{
				connector = ((mk_lib_net_connector_pt)(client->m_user));
				if(!mk_win_dll_ws2_event_is_null(connector->m_connect.m_event))
				{
					evts[count] = connector->m_connect.m_event;
					connectors[count - 1] = connector;
					++count;
				}
			}
		}
		events = &evts[0];
		all = mk_win_base_false;
		timeout = mk_win_dll_ws2_infinite;
		alertable = mk_win_base_true;
		do
		{
			waited = mk_win_dll_ws2_wait_for_multiple_events(count, events, all, timeout, alertable);
			mk_lang_check_return(!(waited >= mk_win_dll_ws2_wait_abandoned_0 + 0 && waited < mk_win_dll_ws2_wait_abandoned_0 + count));
			mk_lang_check_return(!(waited == mk_win_dll_ws2_wait_timeout));
			mk_lang_check_return(!(waited == mk_win_dll_ws2_wait_failed));
			if(waited == mk_win_dll_ws2_wait_object_0 + 0)
			{
				b = mk_win_dll_ws2_reset_event(forwarder->m_event); mk_lang_check_return(b != mk_win_base_false);
				if(forwarder->m_want_stop)
				{
					break;
				}
			}
			else if(waited >= mk_win_dll_ws2_wait_object_0 + 1 && waited < mk_win_dll_ws2_wait_object_0 + count)
			{
				idx = ((mk_lang_types_sint_t)(waited - (mk_win_dll_ws2_wait_object_0 + 1))); mk_lang_assert(idx >= 0); mk_lang_assert(idx < ((mk_lang_types_sint_t)(count)) - 1);
				connector = connectors[idx];
				err = mk_lib_net_connect_request_reset(&connector->m_connect); mk_lang_check_rereturn(err);
				err = mk_lib_net_iocp_post(&forwarder->m_iocp, 0, ((mk_lang_types_uintptr_t)(connector)), ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_forwarder_k_iocp_id_connected))))); mk_lang_check_rereturn(err);
			}
			else if(waited == mk_win_dll_ws2_wait_io_completion)
			{
				/* empty */
			}
			else
			{
				mk_lang_check_return(mk_lang_runtime_bool_fn_false);
			}
		}while(waited == mk_win_dll_ws2_wait_io_completion);
	}while(!forwarder->m_want_stop);
	return 0;
}

mk_lang_nodiscard static mk_win_base_dword_t mk_win_base_far mk_win_base_stdcall mk_lib_net_forwarder_prrw_win_thread_proc(mk_win_base_void_lpt const parameter) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lib_net_forwarder_prrw_thread_proc(((mk_lib_net_forwarder_pt)(parameter)));
	return ((mk_win_base_dword_t)(err));
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_make_thread(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_dword_t tid;

	mk_lang_assert(forwarder);

	if(mk_win_base_handle_is_null(forwarder->m_thread))
	{
		mk_lang_assert(mk_win_dll_ws2_event_is_null(forwarder->m_event));
		forwarder->m_event = mk_win_dll_ws2_create_event(); mk_lang_check_return(!mk_win_dll_ws2_event_is_null(forwarder->m_event));
		b = mk_win_dll_ws2_reset_event(forwarder->m_event); mk_lang_check_return(b != mk_win_base_false);
		forwarder->m_thread = mk_win_dll_kernel_process_create_thread(mk_win_base_null, 0, &mk_lib_net_forwarder_prrw_win_thread_proc,forwarder, 0, &tid); mk_lang_check_return(!mk_win_base_handle_is_null(forwarder->m_thread));
	}
	else
	{
		mk_lang_assert(!mk_win_dll_ws2_event_is_null(forwarder->m_event));
		b = mk_win_dll_ws2_set_event(forwarder->m_event); mk_lang_check_return(b != mk_win_base_false);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_on_new_client(mk_lib_net_forwarder_pt const forwarder, mk_lib_net_listener_client_pt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_connector_pt connector;
	mk_lang_types_void_pt mem;
	mk_lib_net_destination_t destination;

	mk_lang_assert(forwarder);
	mk_lang_assert(client);

	err = mk_lib_net_forwarder_clients_rw_push_back_copy_single(&forwarder->m_clients, &client); mk_lang_check_rereturn(err);
	err = mk_sl_mallocator_allocate(sizeof(*connector), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); connector = ((mk_lib_net_connector_pt)(mem)); mk_lang_assert(connector);
	err = mk_lib_net_connector_rw_construct(connector); mk_lang_check_rereturn(err);
	mk_lang_assert(!client->m_user);
	mk_lang_assert(!connector->m_user);
	client->m_user = connector;
	connector->m_user = client;
	err = mk_lib_net_forwarder_prrw_on_get_server_destiation(forwarder, &destination); mk_lang_check_rereturn(err);
	err = mk_lib_net_connector_rw_connect_to_destination(connector, &forwarder->m_iocp, &destination); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_prrw_make_thread(forwarder); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_collect_iop(mk_lib_net_forwarder_pt const forwarder, mk_lib_net_iocp_iop_pt const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);
	mk_lang_assert(iop);

	err = mk_lib_net_iocp_dequeue_packet_infinite(&forwarder->m_iocp, &iop->m_dequeued, &iop->m_successful_io_operation, &iop->m_bytes_transferred, &iop->m_key, &iop->m_overlapped, &iop->m_fail_reason); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_dispatch_iop(mk_lib_net_forwarder_pt const forwarder, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_forwarder_iop_target_data_pt target;
	mk_lib_net_listener_pt listener;
	mk_lib_net_listener_client_pt client;

	mk_lang_assert(forwarder);
	mk_lang_assert(iop);

	if(iop->m_dequeued)
	{
		if
		(
			(iop->m_key == mk_lib_net_forwarder_k_iocp_id_poke) &&
			(iop->m_overlapped == mk_lang_null) &&
			(iop->m_bytes_transferred == 0) &&
			mk_lang_true
		)
		{
		}
		else if
		(
			(iop->m_key == mk_lib_net_forwarder_k_iocp_id_end) &&
			(iop->m_overlapped == mk_lang_null) &&
			(iop->m_bytes_transferred == 0) &&
			mk_lang_true
		)
		{
			forwarder->m_want_stop = mk_lang_true;
		}
		else
		{
			target = ((mk_lib_net_forwarder_iop_target_data_pt)(iop->m_key));
			err = mk_lib_net_forwarder_iop_target_logic_rw_on_iop(target, iop); mk_lang_check_rereturn(err);
			listener = mk_lib_net_forwarder_iop_target_logic_rw_cast_to_listener(target);
			if(listener)
			{
				err = mk_lib_net_listener_rw_get_client(listener, &client); mk_lang_check_rereturn(err);
				if(client)
				{
					err = mk_lib_net_forwarder_prrw_on_new_client(forwarder, client); mk_lang_check_rereturn(err);
				}
			}

		}
	}
	else
	{
		mk_lang_check_todo();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_run(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_iocp_iop_t iop;

	mk_lang_assert(forwarder);

	while(!forwarder->m_want_stop)
	{
		err = mk_lib_net_forwarder_prrw_collect_iop(forwarder, &iop); mk_lang_check_rereturn(err);
		err = mk_lib_net_forwarder_prrw_dispatch_iop(forwarder, &iop); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_rw_construct(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	return mk_lib_net_forwarder_prrw_construct(forwarder);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_rw_destroy(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	return mk_lib_net_forwarder_prrw_destroy(forwarder);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_rw_add_listener(mk_lib_net_forwarder_pt const forwarder, mk_lib_net_destination_pct const destination) mk_lang_noexcept
{
	return mk_lib_net_forwarder_prrw_add_listener(forwarder, destination);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_rw_request_stop(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	return mk_lib_net_forwarder_prrw_request_stop(forwarder);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_rw_run(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	return mk_lib_net_forwarder_prrw_run(forwarder);
}


#endif
