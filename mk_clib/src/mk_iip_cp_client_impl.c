#ifndef mk_include_guard_mk_iip_cp_client_impl_c
#define mk_include_guard_mk_iip_cp_client_impl_c
#include "mk_iip_cp_client_impl.h"

#include "mk_iip_cp_client_data.h"
#include "mk_iip_cp_client_data_impl.h"
#include "mk_iip_cp_connection_intr.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_type.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_sl_io_async_iocp.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_connection(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_connection_intr_pt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(connection);
	mk_lang_assert(!client_impl->m_did_something);

	err = mk_iip_cp_connection_intr_rw_tick_single(connection); mk_lang_check_rereturn(err);
	if(mk_iip_cp_connection_intr_rw_did_something(connection))
	{
		client_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_connections(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_usize_t count_connections;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_iip_cp_connection_intr_pt connection;
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(!client_impl->m_did_something);

	count_connections = mk_iip_cp_connection_intrs_rw_size(&client_impl->m_connections);
	if(count_connections != 0)
	{
		n = count_connections;
		for(i = 0; i != n; ++i)
		{
			++client_impl->m_idx;
			idx = client_impl->m_idx;
			idx = idx % count_connections;
			connection = mk_iip_cp_connection_intrs_rw_at(&client_impl->m_connections, idx); mk_lang_assert(connection);
			err = mk_iip_cp_client_impl_pr_tick_connection(client_impl, connection); mk_lang_check_rereturn(err);
			if(mk_iip_cp_client_impl_rw_did_something(client_impl))
			{
				break;
			}
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_connection_force(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_connection_intr_pt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(connection);
	mk_lang_assert(!client_impl->m_did_something);

	err = mk_iip_cp_connection_intr_rw_tick_force(connection); mk_lang_check_rereturn(err);
	if(mk_iip_cp_connection_intr_rw_did_something(connection))
	{
		client_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_connections_force(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_usize_t count_connections;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_iip_cp_connection_intr_pt connection;
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(!client_impl->m_did_something);

	count_connections = mk_iip_cp_connection_intrs_rw_size(&client_impl->m_connections);
	if(count_connections != 0)
	{
		n = count_connections;
		for(i = 0; i != n; ++i)
		{
			++client_impl->m_idx;
			idx = client_impl->m_idx;
			idx = idx % count_connections;
			connection = mk_iip_cp_connection_intrs_rw_at(&client_impl->m_connections, idx); mk_lang_assert(connection);
			err = mk_iip_cp_client_impl_pr_tick_connection_force(client_impl, connection); mk_lang_check_rereturn(err);
			if(mk_iip_cp_client_impl_rw_did_something(client_impl))
			{
				break;
			}
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_rr_connect(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_impl_rr_pt const rr) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_connect_pct request;
	mk_iip_cp_client_data_response_connect_pt response;
	mk_lang_types_sint_t err;
	mk_iip_cp_connection_intr_pt connection;

	mk_lang_assert(client_impl);
	mk_lang_assert(rr);
	mk_lang_assert(rr->m_type == mk_iip_cp_client_data_impl_type_e_connect);

	request = rr->m_request.m_mix.m_data.m_connect;
	response = rr->m_response.m_mix.m_data.m_connect;
	err = mk_iip_cp_connection_intrs_rw_push_back_void_one(&client_impl->m_connections); mk_lang_check_rereturn(err);
	connection = mk_iip_cp_connection_intrs_rw_back(&client_impl->m_connections); mk_lang_assert(connection);
	err = mk_iip_cp_connection_intr_rw_set_iocp(connection, &client_impl->m_iocp.m_iocp); mk_lang_check_rereturn(err);
	err = mk_iip_cp_connection_intr_rw_connect_to_i2cp(connection, request, response); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_data_impl_rrs_rw_pop_front_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	client_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_rr_create_session(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_impl_rr_pt const rr) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_create_session_pct request;
	mk_iip_cp_client_data_response_create_session_pt response;
	mk_iip_cp_connection_intr_pt connection;
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(rr);
	mk_lang_assert(rr->m_type == mk_iip_cp_client_data_impl_type_e_create_session);
	mk_lang_assert(rr->m_request.m_mix.m_data.m_create_session);
	mk_lang_assert(rr->m_response.m_mix.m_data.m_create_session);
	mk_lang_assert(rr->m_request.m_mix.m_data.m_create_session->m_connection);

	request = rr->m_request.m_mix.m_data.m_create_session;
	response = rr->m_response.m_mix.m_data.m_create_session;
	connection = request->m_connection;
	err = mk_iip_cp_connection_intr_rw_create_session(connection, request, response); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_data_impl_rrs_rw_pop_front_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	client_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_rr_get_bandwidth_limits(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_impl_rr_pt const rr) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_get_bandwidth_limits_pct request;
	mk_iip_cp_client_data_response_get_bandwidth_limits_pt response;
	mk_iip_cp_connection_intr_pt connection;
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(rr);
	mk_lang_assert(rr->m_type == mk_iip_cp_client_data_impl_type_e_get_bandwidth_limits);
	mk_lang_assert(rr->m_request.m_mix.m_data.m_get_bandwidth_limits);
	mk_lang_assert(rr->m_response.m_mix.m_data.m_get_bandwidth_limits);
	mk_lang_assert(rr->m_request.m_mix.m_data.m_get_bandwidth_limits->m_connection);

	request = rr->m_request.m_mix.m_data.m_get_bandwidth_limits;
	response = rr->m_response.m_mix.m_data.m_get_bandwidth_limits;
	connection = request->m_connection;
	err = mk_iip_cp_connection_intr_rw_get_bandwidth_limits(connection, request, response); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_data_impl_rrs_rw_pop_front_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	client_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_rr_host_lookup(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_impl_rr_pt const rr) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_host_lookup_pct request;
	mk_iip_cp_client_data_response_host_lookup_pt response;
	mk_iip_cp_connection_intr_pt connection;
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(rr);
	mk_lang_assert(rr->m_type == mk_iip_cp_client_data_impl_type_e_host_lookup);
	mk_lang_assert(rr->m_request.m_mix.m_data.m_host_lookup);
	mk_lang_assert(rr->m_response.m_mix.m_data.m_host_lookup);
	mk_lang_assert(rr->m_request.m_mix.m_data.m_host_lookup->m_connection);

	request = rr->m_request.m_mix.m_data.m_host_lookup;
	response = rr->m_response.m_mix.m_data.m_host_lookup;
	connection = request->m_connection;
	err = mk_iip_cp_connection_intr_rw_host_lookup(connection, request, response); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_data_impl_rrs_rw_pop_front_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	client_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_rr_accept(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_impl_rr_pt const rr) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_accept_pct request;
	mk_iip_cp_client_data_response_accept_pt response;
	mk_iip_cp_connection_intr_pt connection;
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(rr);
	mk_lang_assert(rr->m_type == mk_iip_cp_client_data_impl_type_e_accept);
	mk_lang_assert(rr->m_request.m_mix.m_data.m_accept);
	mk_lang_assert(rr->m_response.m_mix.m_data.m_accept);
	mk_lang_assert(rr->m_request.m_mix.m_data.m_accept->m_connection);

	request = rr->m_request.m_mix.m_data.m_accept;
	response = rr->m_response.m_mix.m_data.m_accept;
	connection = request->m_connection;
	err = mk_iip_cp_connection_intr_rw_accept(connection, request, response); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_data_impl_rrs_rw_pop_front_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	client_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_rr_read_data(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_impl_rr_pt const rr) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_read_data_pct request;
	mk_iip_cp_client_data_response_read_data_pt response;
	mk_iip_cp_connection_intr_pt connection;
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(rr);
	mk_lang_assert(rr->m_type == mk_iip_cp_client_data_impl_type_e_read_data);
	mk_lang_assert(rr->m_request.m_mix.m_data.m_read_data);
	mk_lang_assert(rr->m_response.m_mix.m_data.m_read_data);
	mk_lang_assert(rr->m_request.m_mix.m_data.m_read_data->m_connection);

	request = rr->m_request.m_mix.m_data.m_read_data;
	response = rr->m_response.m_mix.m_data.m_read_data;
	connection = request->m_connection;
	err = mk_iip_cp_connection_intr_rw_read_data(connection, request, response); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_data_impl_rrs_rw_pop_front_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	client_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_rr_send_data(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_impl_rr_pt const rr) mk_lang_noexcept
{
	mk_lang_assert(client_impl);
	mk_lang_assert(rr);
	mk_lang_assert(rr->m_type == mk_iip_cp_client_data_impl_type_e_send_data);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_rr(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_impl_rr_pt const rr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(rr);
	mk_lang_assert(!client_impl->m_did_something);

	switch(rr->m_type)
	{
		case mk_iip_cp_client_data_impl_type_e_connect             : err = mk_iip_cp_client_impl_pr_tick_rr_connect             (client_impl, rr); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_client_data_impl_type_e_create_session      : err = mk_iip_cp_client_impl_pr_tick_rr_create_session      (client_impl, rr); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_client_data_impl_type_e_get_bandwidth_limits: err = mk_iip_cp_client_impl_pr_tick_rr_get_bandwidth_limits(client_impl, rr); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_client_data_impl_type_e_host_lookup         : err = mk_iip_cp_client_impl_pr_tick_rr_host_lookup         (client_impl, rr); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_client_data_impl_type_e_accept              : err = mk_iip_cp_client_impl_pr_tick_rr_accept              (client_impl, rr); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_client_data_impl_type_e_read_data           : err = mk_iip_cp_client_impl_pr_tick_rr_read_data           (client_impl, rr); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_client_data_impl_type_e_send_data           : err = mk_iip_cp_client_impl_pr_tick_rr_send_data           (client_impl, rr); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_client_data_impl_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_rrs(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_iip_cp_client_data_impl_rr_pt rr;
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(!client_impl->m_did_something);

	if(!mk_iip_cp_client_data_impl_rrs_rw_is_empty(&client_impl->m_rrs))
	{
		rr = mk_iip_cp_client_data_impl_rrs_rw_front(&client_impl->m_rrs); mk_lang_assert(rr);
		err = mk_iip_cp_client_impl_pr_tick_rr(client_impl, rr); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_on_iorp(mk_iip_cp_client_impl_pt const client_impl, mk_sl_net_windows_iorp_xxx_pt const iorp) mk_lang_noexcept
{
	mk_iip_cp_connection_intr_pt connection;
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(iorp);
	mk_lang_assert(iorp->m_user);

	connection = ((mk_iip_cp_connection_intr_pt)(iorp->m_user)); mk_lang_assert(connection);
	err = mk_iip_cp_connection_intr_rw_on_iorp(connection, iorp); mk_lang_check_rereturn(err);
	if(mk_iip_cp_connection_intr_rw_did_something(connection))
	{
		client_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_nop_all_connections(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_iip_cp_connection_intr_pt connection;
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);

	n = mk_iip_cp_connection_intrs_rw_size(&client_impl->m_connections);
	for(i = 0; i != n; ++i)
	{
		connection = mk_iip_cp_connection_intrs_rw_at(&client_impl->m_connections, i); mk_lang_assert(connection);
		err = mk_iip_cp_connection_intr_rw_get_bandwidth_limits_internal(connection); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_wait_for(mk_iip_cp_client_impl_pt const client_impl, mk_lang_types_sint_t const ms) mk_lang_noexcept
{
	enum idle_timeout_ms_e{ idle_timeout_ms_v = 5 * 1000 }; typedef enum idle_timeout_ms_e idle_timeout_ms_t;
	mk_lang_types_sint_t ms_real;
	mk_lang_types_sint_t err;
	mk_sl_net_windows_iorp_xxx_pt iorp;
	mk_lang_types_bool_t timedout;

	mk_lang_assert(client_impl);
	mk_lang_assert(ms >= 0 && ms <= 1 * 24 * 60 * 60 * 1000);

	ms_real = mk_lang_min(ms, idle_timeout_ms_v);
	err = mk_sl_net_windows_wait_one_iorp_timeout_2(&client_impl->m_iocp.m_iocp, &iorp, ms_real, &timedout); mk_lang_check_rereturn(err);
	if(!timedout)
	{
		err = mk_iip_cp_client_impl_pr_on_iorp(client_impl, iorp); mk_lang_check_rereturn(err);
	}
	else
	{
		if(ms >= idle_timeout_ms_v)
		{
			err = mk_iip_cp_client_impl_pr_nop_all_connections(client_impl); mk_lang_check_rereturn(err);
			client_impl->m_did_something = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_tick_single(mk_iip_cp_client_impl_pt const client_impl, mk_lang_types_sint_t const ms) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(ms >= 0 && ms <= 1 * 24 * 60 * 60 * 1000);

	client_impl->m_did_something = mk_lang_false;
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_tick_connections      (client_impl    ); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_tick_rrs              (client_impl    ); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_tick_connections_force(client_impl    ); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_wait_for              (client_impl, ms); mk_lang_check_rereturn(err); }
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_allocate(mk_iip_cp_client_impl_ppt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**client_impl), ((mk_lang_types_void_ppt)(client_impl))); mk_lang_check_rereturn(err); mk_lang_assert(*client_impl);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_deallocate(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);

	err = mk_iip_cp_mallocator_global_deallocate(client_impl, sizeof(*client_impl)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_construct(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);

	err = mk_iip_cp_connection_intrs_rw_construct(&client_impl->m_connections); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_data_impl_rrs_rw_construct(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(client_impl->m_did_something));
	client_impl->m_idx = 0;
	err = mk_sl_io_async_iocp_construct(&client_impl->m_iocp, 0); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_destruct(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);

	err = mk_iip_cp_connection_intrs_rw_destroy(&client_impl->m_connections); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_data_impl_rrs_rw_destruct(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(client_impl->m_did_something));
	((mk_lang_types_void_t)(client_impl->m_idx));
	err = mk_sl_io_async_iocp_destruct(&client_impl->m_iocp); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_allocate_and_construct(mk_iip_cp_client_impl_ppt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);

	err = mk_iip_cp_client_impl_rw_allocate(client_impl); mk_lang_check_rereturn(err); mk_lang_assert(*client_impl);
	err = mk_iip_cp_client_impl_rw_construct(*client_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_destruct_and_deallocate(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);

	err = mk_iip_cp_client_impl_rw_destruct(client_impl); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_impl_rw_deallocate(client_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_client_impl_pr_has_outstanding_iorp(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_iip_cp_connection_intr_pt connection;

	mk_lang_assert(client_impl);

	ret = mk_lang_false;
	n = mk_iip_cp_connection_intrs_rw_size(&client_impl->m_connections);
	for(i = 0; i != n; ++i)
	{
		connection = mk_iip_cp_connection_intrs_rw_at(&client_impl->m_connections, i); mk_lang_assert(connection);
		ret = mk_iip_cp_connection_intr_rw_has_outstanding_iorp(connection);
		if(ret)
		{
			break;
		}
	}
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_wait_infinite(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_net_windows_iorp_xxx_pt iorp;

	mk_lang_assert(client_impl);

	if(mk_iip_cp_client_impl_pr_has_outstanding_iorp(client_impl))
	{
		err = mk_sl_net_windows_wait_one_iorp_infinite_2(&client_impl->m_iocp.m_iocp, &iorp); mk_lang_check_rereturn(err); mk_lang_assert(iorp);
		err = mk_iip_cp_client_impl_pr_on_iorp(client_impl, iorp); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_pr_wait_little(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_net_windows_iorp_xxx_pt iorp;
	mk_lang_types_bool_t timedout;

	mk_lang_assert(client_impl);

	err = mk_sl_net_windows_wait_one_iorp_timeout_2(&client_impl->m_iocp.m_iocp, &iorp, 0, &timedout); mk_lang_check_rereturn(err);
	if(!timedout)
	{
		err = mk_iip_cp_client_impl_pr_on_iorp(client_impl, iorp); mk_lang_check_rereturn(err);
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_client_impl_rw_did_something(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(client_impl);

	ret = client_impl->m_did_something;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_tick_single(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);

	client_impl->m_did_something = mk_lang_false;
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_tick_connections      (client_impl); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_tick_rrs              (client_impl); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_tick_connections_force(client_impl); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_wait_little           (client_impl); mk_lang_check_rereturn(err); }
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_tick_single2(mk_iip_cp_client_impl_pt const client_impl, mk_lang_types_sint_t const ms) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);
	mk_lang_assert(ms >= 0 && ms <= 1 * 24 * 60 * 60 * 1000);

	client_impl->m_did_something = mk_lang_false;
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_tick_connections      (client_impl    ); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_tick_rrs              (client_impl    ); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_tick_connections_force(client_impl    ); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_client_impl_rw_did_something(client_impl)){ err = mk_iip_cp_client_impl_pr_wait_for              (client_impl, ms); mk_lang_check_rereturn(err); }
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_tick_all(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);

	do
	{
		err = mk_iip_cp_client_impl_rw_tick_single(client_impl); mk_lang_check_rereturn(err);
	}while(mk_iip_cp_client_impl_rw_did_something(client_impl));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_tick_until_idle(mk_iip_cp_client_impl_pt const client_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_impl);

	do
	{
		err = mk_iip_cp_client_impl_rw_tick_all(client_impl); mk_lang_check_rereturn(err);
		err = mk_iip_cp_client_impl_pr_wait_infinite(client_impl); mk_lang_check_rereturn(err);
	}while(mk_iip_cp_client_impl_rw_did_something(client_impl));
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_generate_destination(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_request_generate_destination_pct const request, mk_iip_cp_client_data_response_generate_destination_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_impl_rr_pt rr;

	mk_lang_assert(client_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	err = mk_iip_cp_client_data_impl_rrs_rw_push_back_void_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	rr = mk_iip_cp_client_data_impl_rrs_rw_back(&client_impl->m_rrs); mk_lang_assert(rr);
	rr->m_type = mk_iip_cp_client_data_impl_type_e_generate_destination;
	rr->m_request.m_mix.m_data.m_generate_destination = request;
	rr->m_response.m_mix.m_data.m_generate_destination = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_connect_to_i2cp(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_request_connect_pct const request, mk_iip_cp_client_data_response_connect_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_impl_rr_pt rr;

	mk_lang_assert(client_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	response->m_done = mk_lang_false;
	err = mk_iip_cp_client_data_impl_rrs_rw_push_back_void_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	rr = mk_iip_cp_client_data_impl_rrs_rw_back(&client_impl->m_rrs); mk_lang_assert(rr);
	rr->m_type = mk_iip_cp_client_data_impl_type_e_connect;
	rr->m_request.m_mix.m_data.m_connect = request;
	rr->m_response.m_mix.m_data.m_connect = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_create_session(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_request_create_session_pct const request, mk_iip_cp_client_data_response_create_session_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_impl_rr_pt rr;

	mk_lang_assert(client_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	response->m_done = mk_lang_false;
	err = mk_iip_cp_client_data_impl_rrs_rw_push_back_void_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	rr = mk_iip_cp_client_data_impl_rrs_rw_back(&client_impl->m_rrs); mk_lang_assert(rr);
	rr->m_type = mk_iip_cp_client_data_impl_type_e_create_session;
	rr->m_request.m_mix.m_data.m_create_session = request;
	rr->m_response.m_mix.m_data.m_create_session = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_get_bandwidth_limits(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_request_get_bandwidth_limits_pct const request, mk_iip_cp_client_data_response_get_bandwidth_limits_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_impl_rr_pt rr;

	mk_lang_assert(client_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	response->m_done = mk_lang_false;
	err = mk_iip_cp_client_data_impl_rrs_rw_push_back_void_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	rr = mk_iip_cp_client_data_impl_rrs_rw_back(&client_impl->m_rrs); mk_lang_assert(rr);
	rr->m_type = mk_iip_cp_client_data_impl_type_e_get_bandwidth_limits;
	rr->m_request.m_mix.m_data.m_get_bandwidth_limits = request;
	rr->m_response.m_mix.m_data.m_get_bandwidth_limits = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_host_lookup(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_request_host_lookup_pct const request, mk_iip_cp_client_data_response_host_lookup_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_impl_rr_pt rr;

	mk_lang_assert(client_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	response->m_done = mk_lang_false;
	err = mk_iip_cp_client_data_impl_rrs_rw_push_back_void_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	rr = mk_iip_cp_client_data_impl_rrs_rw_back(&client_impl->m_rrs); mk_lang_assert(rr);
	rr->m_type = mk_iip_cp_client_data_impl_type_e_host_lookup;
	rr->m_request.m_mix.m_data.m_host_lookup = request;
	rr->m_response.m_mix.m_data.m_host_lookup = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_accept(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_request_accept_pct const request, mk_iip_cp_client_data_response_accept_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_impl_rr_pt rr;

	mk_lang_assert(client_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	response->m_done = mk_lang_false;
	err = mk_iip_cp_client_data_impl_rrs_rw_push_back_void_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	rr = mk_iip_cp_client_data_impl_rrs_rw_back(&client_impl->m_rrs); mk_lang_assert(rr);
	rr->m_type = mk_iip_cp_client_data_impl_type_e_accept;
	rr->m_request.m_mix.m_data.m_accept = request;
	rr->m_response.m_mix.m_data.m_accept = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_read_data(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_request_read_data_pct const request, mk_iip_cp_client_data_response_read_data_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_impl_rr_pt rr;

	mk_lang_assert(client_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	response->m_done = mk_lang_false;
	err = mk_iip_cp_client_data_impl_rrs_rw_push_back_void_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	rr = mk_iip_cp_client_data_impl_rrs_rw_back(&client_impl->m_rrs); mk_lang_assert(rr);
	rr->m_type = mk_iip_cp_client_data_impl_type_e_read_data;
	rr->m_request.m_mix.m_data.m_read_data = request;
	rr->m_response.m_mix.m_data.m_read_data = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_impl_rw_send_data(mk_iip_cp_client_impl_pt const client_impl, mk_iip_cp_client_data_request_send_data_pct const request, mk_iip_cp_client_data_response_send_data_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_impl_rr_pt rr;

	mk_lang_assert(client_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	err = mk_iip_cp_client_data_impl_rrs_rw_push_back_void_one(&client_impl->m_rrs); mk_lang_check_rereturn(err);
	rr = mk_iip_cp_client_data_impl_rrs_rw_back(&client_impl->m_rrs); mk_lang_assert(rr);
	rr->m_type = mk_iip_cp_client_data_impl_type_e_send_data;
	rr->m_request.m_mix.m_data.m_send_data = request;
	rr->m_response.m_mix.m_data.m_send_data = response;
	return 0;
}


#endif
