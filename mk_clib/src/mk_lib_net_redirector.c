#ifndef mk_include_guard_mk_lib_net_redirector_c
#define mk_include_guard_mk_lib_net_redirector_c
#include "mk_lib_net_redirector.h"

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
#include "mk_lib_net_buffers.h"
#include "mk_lib_net_iocp.h"
#include "mk_lib_net_listener.h"
#include "mk_sl_buffers.h"
#include "mk_sl_mallocator.h"
#include "mk_sl_vector_copy.h"
#include "mk_win_dll_kernel_process.h"
#include "mk_win_dll_kernel_synchronization.h"


#define mk_lib_net_redirector_k_iocp_key_special 0x00000010
#define mk_lib_net_redirector_k_iocp_overlapped_special_poke 0x00000010
#define mk_lib_net_redirector_k_iocp_overlapped_special_end 0x00000020
#define mk_lib_net_redirector_k_iocp_id_connected 2


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_client_s
{
	mk_lib_net_socket_t m_socket;
	mk_lib_net_destination_t m_local_address;
	mk_lib_net_destination_t m_remote_address;
	mk_lib_net_read_request_t m_read_request;
	mk_lib_net_write_request_t m_write_request;
};
typedef struct mk_lib_net_redirector_client_s mk_lib_net_redirector_client_t;
mk_lang_typedef(mk_lib_net_redirector_client);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_construct(mk_lib_net_redirector_client_pt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);

	err = mk_lib_net_socket_construct_void(&client->m_socket); mk_lang_check_rereturn(err);
	mk_lang_assert((mk_lib_net_destination_clear(&client->m_local_address), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&client->m_remote_address), mk_lang_true));
	err = mk_lib_net_read_request_construct_void(&client->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_construct_void(&client->m_write_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_destroy(mk_lib_net_redirector_client_pt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);

	err = mk_lib_net_socket_destroy(&client->m_socket); mk_lang_check_rereturn(err);
	mk_lang_assert((mk_lib_net_destination_clear(&client->m_local_address), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&client->m_remote_address), mk_lang_true));
	err = mk_lib_net_read_request_destroy(&client->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_destroy(&client->m_write_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_issue_read(mk_lib_net_redirector_client_pt const client, mk_sl_buffers_buffer_pt const buffer) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);
	mk_lang_assert(buffer);

	err = mk_lib_net_read_request_reconstruct(&client->m_read_request, &client->m_socket, &buffer->m_data.m_uint8s[0], mk_lang_countof(buffer->m_data.m_uint8s)); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_issue(&client->m_read_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_issue_write(mk_lib_net_redirector_client_pt const client, mk_sl_buffers_buffer_pt const buffer, mk_lang_types_sint_t const amount) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);
	mk_lang_assert(buffer);
	mk_lang_assert(amount >= 1);

	err = mk_lib_net_write_request_reconstruct(&client->m_write_request, &client->m_socket, &buffer->m_data.m_uint8s[0], amount); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_issue(&client->m_write_request); mk_lang_check_rereturn(err);
	return 0;
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_connector_s
{
	mk_lib_net_socket_t m_socket;
	mk_lib_net_destination_t m_local_address;
	mk_lib_net_destination_t m_remote_address;
	mk_lib_net_connect_request_t m_connect_request;
	mk_lib_net_read_request_t m_read_request;
	mk_lib_net_write_request_t m_write_request;
};
typedef struct mk_lib_net_redirector_connector_s mk_lib_net_redirector_connector_t;
mk_lang_typedef(mk_lib_net_redirector_connector);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_construct(mk_lib_net_redirector_connector_pt const connector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);

	err = mk_lib_net_socket_construct_void(&connector->m_socket); mk_lang_check_rereturn(err);
	mk_lang_assert((mk_lib_net_destination_clear(&connector->m_local_address), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&connector->m_remote_address), mk_lang_true));
	err = mk_lib_net_connect_request_construct_void(&connector->m_connect_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_construct_void(&connector->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_construct_void(&connector->m_write_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_destroy(mk_lib_net_redirector_connector_pt const connector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);

	err = mk_lib_net_socket_destroy(&connector->m_socket); mk_lang_check_rereturn(err);
	mk_lang_assert((mk_lib_net_destination_clear(&connector->m_local_address), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&connector->m_remote_address), mk_lang_true));
	err = mk_lib_net_connect_request_destroy(&connector->m_connect_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_destroy(&connector->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_destroy(&connector->m_write_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_issue_read(mk_lib_net_redirector_connector_pt const connector, mk_sl_buffers_buffer_pt const buffer) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);
	mk_lang_assert(buffer);

	err = mk_lib_net_read_request_reconstruct(&connector->m_read_request, &connector->m_socket, &buffer->m_data.m_uint8s[0], mk_lang_countof(buffer->m_data.m_uint8s)); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_issue(&connector->m_read_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_issue_write(mk_lib_net_redirector_connector_pt const connector, mk_sl_buffers_buffer_pt const buffer, mk_lang_types_sint_t const amount) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);
	mk_lang_assert(buffer);
	mk_lang_assert(amount >= 1);

	err = mk_lib_net_write_request_reconstruct(&connector->m_write_request, &connector->m_socket, &buffer->m_data.m_uint8s[0], amount); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_issue(&connector->m_write_request); mk_lang_check_rereturn(err);
	return 0;
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_forwarder_s
{
	mk_lib_net_destination_t m_src;
	mk_lib_net_destination_t m_dst;
	mk_lib_net_redirector_client_pt m_client;
	mk_lib_net_redirector_connector_pt m_connector;
	mk_sl_buffers_buffer_pt m_buffer;
	mk_sl_buffers_buffer_pt m_buffer_to_write_client;
	mk_sl_buffers_buffer_pt m_buffer_to_write_connector;
	mk_lang_types_sint_t m_amount_to_write_client;
	mk_lang_types_sint_t m_amount_to_write_connector;
	mk_lang_types_bool_t m_pending_read_client;
	mk_lang_types_bool_t m_pending_read_connector;
	mk_lang_types_bool_t m_pending_write_client;
	mk_lang_types_bool_t m_pending_write_connector;
};
typedef struct mk_lib_net_redirector_forwarder_s mk_lib_net_redirector_forwarder_t;
mk_lang_typedef(mk_lib_net_redirector_forwarder);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_construct(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept
{
	mk_lang_assert(forwarder);
	mk_lang_assert(src);
	mk_lang_assert(dst);

	forwarder->m_src = *src;
	forwarder->m_dst = *dst;
	forwarder->m_client = mk_lang_null;
	forwarder->m_connector = mk_lang_null;
	forwarder->m_buffer = mk_lang_null;
	forwarder->m_buffer_to_write_client = mk_lang_null;
	forwarder->m_buffer_to_write_connector = mk_lang_null;
	forwarder->m_amount_to_write_client = 0;
	forwarder->m_amount_to_write_connector = 0;
	forwarder->m_pending_read_client = mk_lang_false;
	forwarder->m_pending_read_connector = mk_lang_false;
	forwarder->m_pending_write_client = mk_lang_false;
	forwarder->m_pending_write_connector = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_destroy(mk_lib_net_redirector_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_assert(forwarder);

	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_step_client_read(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_buffers_buffer_pt buffer;

	mk_lang_assert(forwarder);
	mk_lang_assert(did);
	mk_lang_assert(*did == mk_lang_false);

	if(!forwarder->m_pending_read_client && !forwarder->m_buffer_to_write_connector)
	{
		if(!forwarder->m_buffer)
		{
			err = mk_lib_net_buffers_rw_allocate_one(&forwarder->m_buffer); mk_lang_check_rereturn(err);
			*did = mk_lang_true;
		}
		else
		{
			buffer = forwarder->m_buffer;
			forwarder->m_buffer = mk_lang_null;
			err = mk_lib_net_redirector_client_prrw_issue_read(forwarder->m_client, buffer); mk_lang_check_rereturn(err);
			forwarder->m_pending_read_client = mk_lang_true;
			*did = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_step_client_write(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_buffers_buffer_pt buffer;
	mk_lang_types_sint_t amount;
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);
	mk_lang_assert(did);
	mk_lang_assert(*did == mk_lang_false);

	buffer = forwarder->m_buffer_to_write_client;
	amount = forwarder->m_amount_to_write_client;
	mk_lang_assert((buffer && amount >= 1) || (!buffer && amount == 0));
	if(!forwarder->m_pending_write_client && buffer)
	{
		forwarder->m_buffer_to_write_client = mk_lang_null;
		forwarder->m_amount_to_write_client = 0;
		err = mk_lib_net_redirector_client_prrw_issue_write(forwarder->m_client, buffer, amount); mk_lang_check_rereturn(err);
		forwarder->m_pending_write_client = mk_lang_true;
		*did = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_step_connector_read(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_buffers_buffer_pt buffer;

	mk_lang_assert(forwarder);
	mk_lang_assert(did);
	mk_lang_assert(*did == mk_lang_false);

	if(!forwarder->m_pending_read_connector && !forwarder->m_buffer_to_write_client)
	{
		if(!forwarder->m_buffer)
		{
			err = mk_lib_net_buffers_rw_allocate_one(&forwarder->m_buffer); mk_lang_check_rereturn(err);
			*did = mk_lang_true;
		}
		else
		{
			buffer = forwarder->m_buffer;
			forwarder->m_buffer = mk_lang_null;
			err = mk_lib_net_redirector_connector_prrw_issue_read(forwarder->m_connector, buffer); mk_lang_check_rereturn(err);
			forwarder->m_pending_read_connector = mk_lang_true;
			*did = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_step_connector_write(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lang_types_bool_pt const did) mk_lang_noexcept
{
	mk_sl_buffers_buffer_pt buffer;
	mk_lang_types_sint_t amount;
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);
	mk_lang_assert(did);
	mk_lang_assert(*did == mk_lang_false);

	buffer = forwarder->m_buffer_to_write_connector;
	amount = forwarder->m_amount_to_write_connector;
	mk_lang_assert((buffer && amount >= 1) || (!buffer && amount == 0));
	if(!forwarder->m_pending_write_connector && buffer)
	{
		forwarder->m_buffer_to_write_connector = mk_lang_null;
		forwarder->m_amount_to_write_connector = 0;
		err = mk_lib_net_redirector_connector_prrw_issue_write(forwarder->m_connector, buffer, amount); mk_lang_check_rereturn(err);
		forwarder->m_pending_write_connector = mk_lang_true;
		*did = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_step(mk_lib_net_redirector_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t done;

	mk_lang_assert(forwarder);

	for(;;)
	{
		done = mk_lang_false;
		err = mk_lib_net_redirector_forwarder_prrw_step_client_read    (forwarder, &done); mk_lang_check_rereturn(err); if(done){ break; }
		err = mk_lib_net_redirector_forwarder_prrw_step_connector_read (forwarder, &done); mk_lang_check_rereturn(err); if(done){ break; }
		err = mk_lib_net_redirector_forwarder_prrw_step_client_write   (forwarder, &done); mk_lang_check_rereturn(err); if(done){ break; }
		err = mk_lib_net_redirector_forwarder_prrw_step_connector_write(forwarder, &done); mk_lang_check_rereturn(err); if(done){ break; }
		break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_on_client_read_finished(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_buffers_buffer_pt buffer;
	mk_lang_types_sint_t amount;

	mk_lang_assert(forwarder);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(forwarder)));
	mk_lang_assert(iop->m_overlapped == &forwarder->m_client->m_read_request.m_overlapped);

	err = mk_lib_net_read_request_wait_infinite(&forwarder->m_client->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_get_result(&forwarder->m_client->m_read_request); mk_lang_check_rereturn(err);
	mk_lang_assert(forwarder->m_client->m_read_request.m_done);
	mk_lang_assert(forwarder->m_client->m_read_request.m_b);
	if(iop->m_successful_io_operation)
	{
		mk_lang_assert(forwarder->m_client->m_read_request.m_transferred == iop->m_bytes_transferred);
		buffer = ((mk_sl_buffers_buffer_pt)(forwarder->m_client->m_read_request.m_data_buf));
		amount = forwarder->m_client->m_read_request.m_transferred;
		mk_lang_assert(buffer);
		mk_lang_assert(amount >= 1);
		mk_lang_assert(forwarder->m_buffer_to_write_connector == mk_lang_null);
		mk_lang_assert(forwarder->m_amount_to_write_connector == 0);
		forwarder->m_buffer_to_write_connector = buffer;
		forwarder->m_amount_to_write_connector = amount;
	}
	else
	{
		mk_lang_check_todo();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_on_client_write_finished(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_assert(forwarder);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(forwarder)));
	mk_lang_assert(iop->m_overlapped == &forwarder->m_client->m_write_request.m_overlapped);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_on_connector_read_finished(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_buffers_buffer_pt buffer;
	mk_lang_types_sint_t amount;

	mk_lang_assert(forwarder);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(forwarder)));
	mk_lang_assert(iop->m_overlapped == &forwarder->m_connector->m_read_request.m_overlapped);

	err = mk_lib_net_read_request_wait_infinite(&forwarder->m_connector->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_get_result(&forwarder->m_connector->m_read_request); mk_lang_check_rereturn(err);
	mk_lang_assert(forwarder->m_connector->m_read_request.m_done);
	mk_lang_assert(forwarder->m_connector->m_read_request.m_b);
	if(iop->m_successful_io_operation)
	{
		mk_lang_assert(forwarder->m_connector->m_read_request.m_transferred == iop->m_bytes_transferred);
		buffer = ((mk_sl_buffers_buffer_pt)(forwarder->m_connector->m_read_request.m_data_buf));
		amount = forwarder->m_connector->m_read_request.m_transferred;
		mk_lang_assert(buffer);
		mk_lang_assert(amount >= 1);
		mk_lang_assert(forwarder->m_buffer_to_write_client == mk_lang_null);
		mk_lang_assert(forwarder->m_amount_to_write_client == 0);
		forwarder->m_buffer_to_write_client = buffer;
		forwarder->m_amount_to_write_client = amount;
	}
	else
	{
		mk_lang_check_todo();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_on_connector_write_finished(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_assert(forwarder);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(forwarder)));
	mk_lang_assert(iop->m_overlapped == &forwarder->m_connector->m_write_request.m_overlapped);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_on_iop(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(forwarder)));

	if(mk_lang_runtime_bool_fn_false){}
	else if(iop->m_overlapped == &forwarder->m_client   ->m_read_request .m_overlapped){ err = mk_lib_net_redirector_forwarder_prrw_on_client_read_finished    (forwarder, iop); mk_lang_check_rereturn(err); }
	else if(iop->m_overlapped == &forwarder->m_client   ->m_write_request.m_overlapped){ err = mk_lib_net_redirector_forwarder_prrw_on_client_write_finished   (forwarder, iop); mk_lang_check_rereturn(err); }
	else if(iop->m_overlapped == &forwarder->m_connector->m_read_request .m_overlapped){ err = mk_lib_net_redirector_forwarder_prrw_on_connector_read_finished (forwarder, iop); mk_lang_check_rereturn(err); }
	else if(iop->m_overlapped == &forwarder->m_connector->m_write_request.m_overlapped){ err = mk_lib_net_redirector_forwarder_prrw_on_connector_write_finished(forwarder, iop); mk_lang_check_rereturn(err); }
	else{ mk_lang_assert_false(); }
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrwv_construct_void(mk_lib_net_redirector_forwarder_ppt const forwarder) mk_lang_noexcept
{
	mk_lang_assert(forwarder);

	*forwarder = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrwv_destruct(mk_lib_net_redirector_forwarder_ppt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	if(*forwarder)
	{
		err = mk_lib_net_redirector_forwarder_prrw_destroy(*forwarder); mk_lang_check_rereturn(err);
		err = mk_sl_mallocator_deallocate(*forwarder, sizeof(**forwarder)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrwv_copy_construct(mk_lib_net_redirector_forwarder_ppt const dst, mk_lib_net_redirector_forwarder_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrwv_move_construct(mk_lib_net_redirector_forwarder_ppt const dst, mk_lib_net_redirector_forwarder_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrwv_copy_assign(mk_lib_net_redirector_forwarder_ppt const dst, mk_lib_net_redirector_forwarder_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrwv_move_assign(mk_lib_net_redirector_forwarder_ppt const dst, mk_lib_net_redirector_forwarder_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_net_redirector_forwarders
#define mk_sl_vector_t_element_type mk_lib_net_redirector_forwarder_pt
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_custom
#define mk_sl_vector_t_element_construct_void mk_lib_net_redirector_forwarder_prrwv_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_net_redirector_forwarder_prrwv_destruct
#define mk_sl_vector_t_element_copy_construct mk_lib_net_redirector_forwarder_prrwv_copy_construct
#define mk_sl_vector_t_element_move_construct mk_lib_net_redirector_forwarder_prrwv_move_construct
#define mk_sl_vector_t_element_copy_assign mk_lib_net_redirector_forwarder_prrwv_copy_assign
#define mk_sl_vector_t_element_move_assign mk_lib_net_redirector_forwarder_prrwv_move_assign
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_impl_s
{
	mk_lib_net_iocp_t m_iocp;
	mk_lang_types_bool_t m_want_end;
	mk_lib_net_redirector_forwarders_t forwarders;
};
typedef struct mk_lib_net_redirector_impl_s mk_lib_net_redirector_impl_s;
mk_lang_typedef(mk_lib_net_redirector_impl);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_construct(mk_lib_net_redirector_impl_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_iocp_construct(&redirector->m_iocp, 0); mk_lang_check_rereturn(err);
	redirector->m_want_end = mk_lang_false;
	err = mk_lib_net_redirector_forwarders_rw_construct(&redirector->forwarders); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_destroy(mk_lib_net_redirector_impl_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_iocp_destroy(&redirector->m_iocp); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_forwarders_rw_destroy(&redirector->forwarders); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_dispatch(mk_lib_net_redirector_impl_pt const redirector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_assert(redirector);
	mk_lang_assert(iop);

	if(iop->m_dequeued)
	{
		if(iop->m_key == ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special)))
		{
			if(iop->m_overlapped == ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_end)))))
			{
				redirector->m_want_end = mk_lang_true;
			}
			else
			{
				mk_lang_check_todo();
			}
		}
		else
		{
			mk_lang_check_todo();
		}
	}
	else
	{
		mk_lang_check_todo();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_run(mk_lib_net_redirector_impl_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_iocp_iop_t iop;

	mk_lang_assert(redirector);

	do
	{
		err = mk_lib_net_iocp_dequeue_packet_infinite(&redirector->m_iocp, &iop.m_dequeued, &iop.m_successful_io_operation, &iop.m_bytes_transferred, &iop.m_key, &iop.m_overlapped, &iop.m_fail_reason); mk_lang_check_rereturn(err);
		err = mk_lib_net_redirector_impl_prrw_dispatch(redirector, &iop); mk_lang_check_rereturn(err);
	}while(!redirector->m_want_end);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_request_stop(mk_lib_net_redirector_impl_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_iocp_post(&redirector->m_iocp, 0, ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special)), ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_end))))); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_add_redirect(mk_lib_net_redirector_impl_pt const redirector, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_forwarder_pt forwarder;
	mk_lang_types_void_pt mem;

	mk_lang_assert(redirector);
	mk_lang_assert(src);
	mk_lang_assert(dst);

	err = mk_lib_net_redirector_forwarders_rw_reserve_additional(&redirector->forwarders, 1); mk_lang_check_rereturn(err);
	err = mk_sl_mallocator_allocate(sizeof(*forwarder), &mem); mk_lang_check_rereturn(err); forwarder = ((mk_lib_net_redirector_forwarder_pt)(mem)); mk_lang_assert(forwarder);
	err = mk_lib_net_redirector_forwarder_prrw_construct(forwarder, src, dst); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_forwarders_rw_push_back_move_single(&redirector->forwarders, &forwarder); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_prrw_construct(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;

	mk_lang_assert(redirector);

	err = mk_sl_mallocator_allocate(sizeof(*redirector->m_impl), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); redirector->m_impl = ((mk_lib_net_redirector_impl_pt)(mem)); mk_lang_assert(redirector->m_impl);
	err = mk_lib_net_redirector_impl_prrw_construct(redirector->m_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_prrw_destroy(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);
	mk_lang_assert(redirector->m_impl);

	err = mk_lib_net_redirector_impl_prrw_destroy(redirector->m_impl); mk_lang_check_rereturn(err);
	err = mk_sl_mallocator_deallocate(redirector->m_impl, sizeof(*redirector->m_impl)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_prrw_run(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_redirector_impl_prrw_run(redirector->m_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_prrw_request_stop(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_redirector_impl_prrw_request_stop(redirector->m_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_prrw_add_redirect(mk_lib_net_redirector_pt const redirector, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_redirector_impl_prrw_add_redirect(redirector->m_impl, src, dst); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_rw_construct(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	return mk_lib_net_redirector_prrw_construct(redirector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_rw_destroy(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	return mk_lib_net_redirector_prrw_destroy(redirector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_rw_run(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	return mk_lib_net_redirector_prrw_run(redirector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_rw_request_stop(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	return mk_lib_net_redirector_prrw_request_stop(redirector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_redirector_rw_add_redirect(mk_lib_net_redirector_pt const redirector, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept
{
	return mk_lib_net_redirector_prrw_add_redirect(redirector, src, dst);
}


#endif
