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
#include "mk_lang_types.h"
#include "mk_lib_net_iocp.h"
#include "mk_lib_net_listener.h"
#include "mk_sl_mallocator.h"


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


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_construct(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	forwarder->m_want_stop = mk_lang_false;
	err = mk_lib_net_iocp_construct(&forwarder->m_iocp, 0); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_listeners_rw_construct(&forwarder->m_listeners); mk_lang_check_rereturn(err);
	err = mk_lib_net_forwarder_clients_rw_construct(&forwarder->m_clients); mk_lang_check_rereturn(err);
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_destroy(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	err = mk_lib_net_iocp_destroy(&forwarder->m_iocp); mk_lang_check_rereturn(err);
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_on_new_client(mk_lib_net_forwarder_pt const forwarder, mk_lib_net_listener_client_pt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);
	mk_lang_assert(client);

	err = mk_lib_net_forwarder_clients_rw_push_back_copy_single(&forwarder->m_clients, &client); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_collect_iop(mk_lib_net_forwarder_pt const forwarder, mk_lib_net_listener_iop_pt const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);
	mk_lang_assert(iop);

	err = mk_lib_net_iocp_dequeue_packet_infinite(&forwarder->m_iocp, &iop->m_dequeued, &iop->m_successful_io_operation, &iop->m_bytes_transferred, &iop->m_key, &iop->m_overlapped, &iop->m_fail_reason); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_prrw_dispatch_iop(mk_lib_net_forwarder_pt const forwarder, mk_lib_net_listener_iop_pt const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
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
			listener = ((mk_lib_net_listener_pt)(iop->m_key));
			err = mk_lib_net_listener_rw_on_iop(listener, iop); mk_lang_check_rereturn(err);
			err = mk_lib_net_listener_rw_get_client(listener, &client); mk_lang_check_rereturn(err);
			if(client)
			{
				err = mk_lib_net_forwarder_prrw_on_new_client(forwarder, client); mk_lang_check_rereturn(err);
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
	mk_lib_net_listener_iop_t iop;

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
