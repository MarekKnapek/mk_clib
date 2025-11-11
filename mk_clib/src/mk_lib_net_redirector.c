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
#include "mk_lang_offsetof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_stdout.h"
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
#include "mk_win_dll_kernel_synchronization_timer_queue.h"


#define mk_lib_net_redirector_k_iocp_key_special 0x00000010
#define mk_lib_net_redirector_k_iocp_overlapped_special_poke  (0x00000010)
#define mk_lib_net_redirector_k_iocp_overlapped_special_end   (0x00000020)
#define mk_lib_net_redirector_k_iocp_overlapped_special_timer (0x00000030)


union mk_lib_net_redirector_guid_data_u
{
	mk_lang_types_uchar_t m_uchars[16];
	mk_sl_cui_uint8_t m_uint8s[16];
	mk_lang_types_ulllong_t m_align;
};
typedef union mk_lib_net_redirector_guid_data_u mk_lib_net_redirector_guid_data_t;
struct mk_lib_net_redirector_guid_s
{
	mk_lang_alignas(sizeof(mk_lib_net_redirector_guid_data_t)) mk_lib_net_redirector_guid_data_t m_data;
};
typedef struct mk_lib_net_redirector_guid_s mk_lib_net_redirector_guid_t;
mk_lang_typedef(mk_lib_net_redirector_guid);


mk_lang_constexpr_static_inline mk_lib_net_redirector_guid_t const mk_lib_net_redirector_k_fn_guid_accept_ex                = {{{ 0xf1, 0x7d, 0x36, 0xb5, 0xac, 0xcb, 0xcf, 0x11, 0x95, 0xca, 0x00, 0x80, 0x5f, 0x48, 0xa1, 0x92 }}};
mk_lang_constexpr_static_inline mk_lib_net_redirector_guid_t const mk_lib_net_redirector_k_fn_guid_get_accept_ex_sock_addrs = {{{ 0xf2, 0x7d, 0x36, 0xb5, 0xac, 0xcb, 0xcf, 0x11, 0x95, 0xca, 0x00, 0x80, 0x5f, 0x48, 0xa1, 0x92 }}};


enum mk_lib_net_redirector_iop_target_data_id_e
{
	mk_lib_net_redirector_iop_target_data_id_e_listener,
	mk_lib_net_redirector_iop_target_data_id_e_client,
	mk_lib_net_redirector_iop_target_data_id_e_connector,
	mk_lib_net_redirector_iop_target_data_id_e_dummy_end
};
typedef enum mk_lib_net_redirector_iop_target_data_id_e mk_lib_net_redirector_iop_target_data_id_t;
mk_lang_typedef(mk_lib_net_redirector_iop_target_data_id);


struct mk_lib_net_redirector_iop_target_data_s
{
	mk_lang_types_uchar_t m_id;
};
typedef struct mk_lib_net_redirector_iop_target_data_s mk_lib_net_redirector_iop_target_data_t;
mk_lang_typedef(mk_lib_net_redirector_iop_target_data);


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_iop_target_data_prrw_construct(mk_lib_net_redirector_iop_target_data_pt const target, mk_lib_net_redirector_iop_target_data_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(target);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_net_redirector_iop_target_data_id_e_dummy_end);

	target->m_id = id;
	return 0;
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_client_s
{
	mk_lib_net_socket_t m_socket;
	mk_lib_net_destination_t m_local_address;
	mk_lib_net_destination_t m_remote_address;
	mk_lib_net_read_request_t m_read_request;
	mk_lib_net_write_request_t m_write_request;
	mk_sl_buffers_buffer_pt m_incomming_buffer;
	mk_lang_types_sint_t m_incomming_amount;
};
typedef struct mk_lib_net_redirector_client_s mk_lib_net_redirector_client_t;
mk_lang_typedef(mk_lib_net_redirector_client);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_construct(mk_lib_net_redirector_client_pt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);

	err = mk_lib_net_socket_construct(&client->m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&client->m_socket); mk_lang_check_rereturn(err);
	mk_lang_assert((mk_lib_net_destination_clear(&client->m_local_address), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&client->m_remote_address), mk_lang_true));
	err = mk_lib_net_read_request_construct_void(&client->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_construct_void(&client->m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_buffers_rw_allocate_one(&client->m_incomming_buffer); mk_lang_check_rereturn(err); mk_lang_assert(client->m_incomming_amount);
	client->m_incomming_amount = 0;
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
	if(client->m_incomming_amount){ err = mk_lib_net_buffers_rw_deallocate_one(client->m_incomming_buffer); mk_lang_check_rereturn(err); }
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
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	if(forwarder->m_client)
	{
		err = mk_lib_net_redirector_client_prrw_destroy(forwarder->m_client); mk_lang_check_rereturn(err);
		err = mk_sl_mallocator_deallocate(forwarder->m_client, sizeof(*forwarder->m_client)); mk_lang_check_rereturn(err);
	}
	if(forwarder->m_connector)
	{
		mk_lang_check_todo();
	}
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


mk_win_base_typedef_func(mk_win_base_bool_t, mk_win_base_stdcall, mk_lib_net_redirector_fn_accept_ex_t, (mk_win_dll_ws2_socket_t const socket_listen, mk_win_dll_ws2_socket_t const socket_accept, mk_win_base_void_lpt const out_data_buf, mk_win_base_dword_t const out_data_len, mk_win_base_dword_t const local_address_len, mk_win_base_dword_t const remote_address_len, mk_win_base_dword_lpt const transferred, mk_win_dll_ws2_overlapped_lpt const overlapped));
mk_win_base_typedef_func(mk_lang_types_void_t, mk_win_base_stdcall, mk_lib_net_redirector_fn_get_accept_ex_sock_addrs_t, (mk_win_base_void_lpct const in_data_buf, mk_win_base_dword_t const in_data_len, mk_win_base_dword_t const local_address_len, mk_win_base_dword_t const remote_address_len, mk_win_dll_ws2_sock_addr_lplpt const local_address_obj, mk_win_base_sint_lpt const local_address_real, mk_win_dll_ws2_sock_addr_lplpt const remote_address_obj, mk_win_base_sint_lpt const remote_address_real));
#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_listener_s
{
	mk_lib_net_destination_t m_src;
	mk_lib_net_destination_t m_dst;
	mk_lib_net_redirector_client_pt m_client;
	mk_lib_net_socket_t m_socket;
	mk_lib_net_redirector_fn_accept_ex_t m_fn_accept_ex;
	mk_lib_net_redirector_fn_get_accept_ex_sock_addrs_t m_fn_get_accept_ex_sock_addrs;
	mk_lib_net_redirector_iop_target_data_t m_iop_target;
	mk_lib_net_redirector_forwarders_t m_forwarders;
	mk_lib_net_ioctl_request_t m_fn_request_accept_ex;
	mk_lib_net_ioctl_request_t m_fn_request_get_accept_ex_sock_addrs;
	mk_lib_net_accept_request_t m_accept_request;
};
typedef struct mk_lib_net_redirector_listener_s mk_lib_net_redirector_listener_t;
mk_lang_typedef(mk_lib_net_redirector_listener);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_construct(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(src);
	mk_lang_assert(dst);

	listener->m_src = *src;
	listener->m_dst = *dst;
	listener->m_client = mk_lang_null;
	err = mk_lib_net_socket_construct(&listener->m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_bind(&listener->m_socket, &listener->m_src); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_listen(&listener->m_socket); mk_lang_check_rereturn(err);
	listener->m_fn_accept_ex = mk_lang_null;
	listener->m_fn_get_accept_ex_sock_addrs = mk_lang_null;
	err = mk_lib_net_redirector_iop_target_data_prrw_construct(&listener->m_iop_target, mk_lib_net_forwarder_iop_target_data_id_e_listener); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_forwarders_rw_construct(&listener->m_forwarders); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_construct(&listener->m_fn_request_accept_ex               , &listener->m_socket, ((mk_lang_types_uint_t)(mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer)), &mk_lib_net_redirector_k_fn_guid_accept_ex               .m_data.m_uint8s[0], mk_lang_countof(mk_lib_net_redirector_k_fn_guid_accept_ex               .m_data.m_uchars), ((mk_sl_cui_uint8_pt)(&listener->m_fn_accept_ex               )), sizeof(listener->m_fn_accept_ex               )); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_construct(&listener->m_fn_request_get_accept_ex_sock_addrs, &listener->m_socket, ((mk_lang_types_uint_t)(mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer)), &mk_lib_net_redirector_k_fn_guid_get_accept_ex_sock_addrs.m_data.m_uint8s[0], mk_lang_countof(mk_lib_net_redirector_k_fn_guid_get_accept_ex_sock_addrs.m_data.m_uchars), ((mk_sl_cui_uint8_pt)(&listener->m_fn_get_accept_ex_sock_addrs)), sizeof(listener->m_fn_get_accept_ex_sock_addrs)); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_construct_void(&listener->m_accept_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_destroy(mk_lib_net_redirector_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);

	if(listener->m_client)
	{
		err = mk_lib_net_redirector_client_prrw_destroy(listener->m_client); mk_lang_check_rereturn(err);
		err = mk_sl_mallocator_deallocate(listener->m_client, sizeof(*listener->m_client)); mk_lang_check_rereturn(err);
	}
	err = mk_lib_net_socket_destroy(&listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_forwarders_rw_destroy(&listener->m_forwarders); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_destroy(&listener->m_fn_request_accept_ex               ); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_destroy(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_destroy(&listener->m_accept_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_issue_requests(mk_lib_net_redirector_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);

	err = mk_lib_net_ioctl_request_issue(&listener->m_fn_request_accept_ex               ); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_issue(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_accept(mk_lib_net_redirector_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_client_pt client;
	mk_lang_types_void_pt mem;

	mk_lang_assert(listener);
	mk_lang_assert(!listener->m_client);

	err = mk_sl_mallocator_allocate(sizeof(*client), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); client = ((mk_lib_net_redirector_client_pt)(mem)); mk_lang_assert(client);
	err = mk_lib_net_redirector_client_prrw_construct(client); mk_lang_check_rereturn(err);
	listener->m_client = client;
	err = mk_lib_net_accept_request_reconstruct(&listener->m_accept_request, &listener->m_fn_accept_ex, &listener->m_fn_get_accept_ex_sock_addrs, &listener->m_socket, &listener->m_client->m_socket, &listener->m_client->m_incomming_buffer->m_data.m_uint8s[0], mk_lang_countof(listener->m_client->m_incomming_buffer->m_data.m_uint8s)); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_issue(&listener->m_accept_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_on_iop_fn_request_accept_ex(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_overlapped);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&listener->m_iop_target)));
	mk_lang_assert(iop->m_overlapped == &listener->m_fn_request_accept_ex.m_overlapped);

	mk_lang_check_return(iop->m_successful_io_operation);
	err = mk_lib_net_ioctl_request_wait_infinite(&listener->m_fn_request_accept_ex); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&listener->m_fn_request_accept_ex); mk_lang_check_rereturn(err);
	mk_lang_check_return(listener->m_fn_request_accept_ex.m_b != mk_lang_false);
	mk_lang_check_return(listener->m_fn_request_accept_ex.m_transferred == sizeof(listener->m_fn_accept_ex));
	err = mk_lib_net_ioctl_request_reset(&listener->m_fn_request_accept_ex); mk_lang_check_rereturn(err);
	if(listener->m_fn_request_get_accept_ex_sock_addrs.m_done)
	{
		err = mk_lib_net_redirector_listener_prrw_accept(listener); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_on_iop_fn_request_get_accept_ex_sock_addrs(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_overlapped);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&listener->m_iop_target)));
	mk_lang_assert(iop->m_overlapped == &listener->m_fn_request_get_accept_ex_sock_addrs.m_overlapped);

	mk_lang_check_return(iop->m_successful_io_operation);
	err = mk_lib_net_ioctl_request_wait_infinite(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	mk_lang_check_return(listener->m_fn_request_get_accept_ex_sock_addrs.m_b != mk_lang_false);
	mk_lang_check_return(listener->m_fn_request_get_accept_ex_sock_addrs.m_transferred == sizeof(listener->m_fn_get_accept_ex_sock_addrs));
	err = mk_lib_net_ioctl_request_reset(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	if(listener->m_fn_request_accept_ex.m_done)
	{
		err = mk_lib_net_redirector_listener_prrw_accept(listener); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_on_iop_accept(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(listener->m_client);
	mk_lang_assert(listener->m_client->m_incomming_amount == 0);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_overlapped);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&listener->m_iop_target)));
	mk_lang_assert(iop->m_overlapped == &listener->m_accept_request.m_overlapped);

	mk_lang_check_return(iop->m_successful_io_operation);
	err = mk_lib_net_accept_request_wait_infinite(&listener->m_accept_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_get_result(&listener->m_accept_request); mk_lang_check_rereturn(err);
	mk_lang_check_return(listener->m_accept_request.m_b != mk_lang_false);
	mk_lang_check_return(listener->m_accept_request.m_transferred >= 1);
	err = mk_lib_net_accept_request_get_addresses(&listener->m_accept_request, &listener->m_client->m_local_address, &listener->m_client->m_remote_address); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_reset(&listener->m_accept_request); mk_lang_check_rereturn(err);
	listener->m_client->m_incomming_amount = listener->m_accept_request.m_transferred;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_on_iop(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_overlapped);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&listener->m_iop_target)));

	if(mk_lang_runtime_bool_fn_false){ mk_lang_assert_false(); }
	else if(iop->m_overlapped == &listener->m_fn_request_accept_ex               .m_overlapped){ err = mk_lib_net_redirector_listener_prrw_on_iop_fn_request_accept_ex               (listener, iop); mk_lang_check_rereturn(err); }
	else if(iop->m_overlapped == &listener->m_fn_request_get_accept_ex_sock_addrs.m_overlapped){ err = mk_lib_net_redirector_listener_prrw_on_iop_fn_request_get_accept_ex_sock_addrs(listener, iop); mk_lang_check_rereturn(err); }
	else if(iop->m_overlapped == &listener->m_accept_request                     .m_overlapped){ err = mk_lib_net_redirector_listener_prrw_on_iop_accept                             (listener, iop); mk_lang_check_rereturn(err); }
	else{ mk_lang_assert_false(); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_on_timer(mk_lib_net_redirector_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_assert(listener);

	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrwv_construct_void(mk_lib_net_redirector_listener_ppt const listener) mk_lang_noexcept
{
	mk_lang_assert(listener);

	*listener = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrwv_destruct(mk_lib_net_redirector_listener_ppt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);

	if(*listener)
	{
		err = mk_lib_net_redirector_listener_prrw_destroy(*listener); mk_lang_check_rereturn(err);
		err = mk_sl_mallocator_deallocate(*listener, sizeof(**listener)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrwv_copy_construct(mk_lib_net_redirector_listener_ppt const dst, mk_lib_net_redirector_listener_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrwv_move_construct(mk_lib_net_redirector_listener_ppt const dst, mk_lib_net_redirector_listener_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrwv_copy_assign(mk_lib_net_redirector_listener_ppt const dst, mk_lib_net_redirector_listener_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrwv_move_assign(mk_lib_net_redirector_listener_ppt const dst, mk_lib_net_redirector_listener_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_net_redirector_listeners
#define mk_sl_vector_t_element_type mk_lib_net_redirector_listener_pt
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#define mk_sl_vector_t_copy_style mk_sl_vector_copy_use_custom
#define mk_sl_vector_t_element_construct_void mk_lib_net_redirector_listener_prrwv_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_net_redirector_listener_prrwv_destruct
#define mk_sl_vector_t_element_copy_construct mk_lib_net_redirector_listener_prrwv_copy_construct
#define mk_sl_vector_t_element_move_construct mk_lib_net_redirector_listener_prrwv_move_construct
#define mk_sl_vector_t_element_copy_assign mk_lib_net_redirector_listener_prrwv_copy_assign
#define mk_sl_vector_t_element_move_assign mk_lib_net_redirector_listener_prrwv_move_assign
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lib_net_redirector_listener_pt mk_lib_net_redirector_iop_target_logic_prrw_cast_to_listener(mk_lib_net_redirector_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_redirector_listener_pt listener;

	mk_lang_static_assert(mk_lang_offsetof(mk_lib_net_redirector_listener_t, m_iop_target) == 8 + 8 + 4 * sizeof(mk_lang_types_void_pt)); /* natvis */

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_iop_target_data_id_e_dummy_end);

	if(target->m_id == mk_lib_net_redirector_iop_target_data_id_e_listener)
	{
		offset = mk_lang_offsetof(mk_lib_net_redirector_listener_t, m_iop_target);
		listener = ((mk_lib_net_redirector_listener_pt)(((mk_lang_types_uchar_pt)(target)) - offset));
		return listener;
	}
	else
	{
		return mk_lang_null;
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_iop_target_logic_prrw_on_iop(mk_lib_net_redirector_iop_target_data_pt const target, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(target);
	mk_lang_assert(iop);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_forwarder_iop_target_data_id_e_dummy_end);

	switch(target->m_id)
	{
		case mk_lib_net_forwarder_iop_target_data_id_e_listener : err = mk_lib_net_redirector_listener_prrw_on_iop(mk_lib_net_redirector_iop_target_logic_prrw_cast_to_listener(target), iop); break;
		/*case mk_lib_net_forwarder_iop_target_data_id_e_client   : err = mk_lib_net_listener_client_rw_on_iop(mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_client   (target), iop); break;
		case mk_lib_net_forwarder_iop_target_data_id_e_connector: err = mk_lib_net_connector_rw_on_iop      (mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_connector(target), iop); break;*/
		case mk_lib_net_forwarder_iop_target_data_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_impl_s
{
	mk_lib_net_iocp_t m_iocp;
	mk_lang_types_bool_t m_want_end_a;
	mk_lang_types_bool_t m_want_end_b;
	mk_lib_net_redirector_listeners_t m_listeners;
	mk_win_base_handle_t m_queue;
	mk_win_base_handle_t m_timer;
};
typedef struct mk_lib_net_redirector_impl_s mk_lib_net_redirector_impl_s;
mk_lang_typedef(mk_lib_net_redirector_impl);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_on_timer(mk_lib_net_redirector_impl_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_iocp_post(&redirector->m_iocp, 0, ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special)), ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_timer))))); mk_lang_check_rereturn(err);
	return 0;
}

static mk_lang_types_void_t mk_win_base_stdcall mk_lib_net_redirector_impl_prrw_on_win_timer(mk_win_base_void_lpt const parameter, mk_win_base_boolean_t const timer_or_wait_fired) mk_lang_noexcept
{
	mk_lib_net_redirector_impl_pt redirector;
	mk_lang_types_sint_t err;

	mk_lang_assert(parameter);
	mk_lang_assert(timer_or_wait_fired == mk_win_base_true);

	redirector = ((mk_lib_net_redirector_impl_pt)(parameter)); mk_lang_assert(redirector);
	err = mk_lib_net_redirector_impl_prrw_on_timer(redirector); mk_lang_check_recrash(err);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_request_timer(mk_lib_net_redirector_impl_pt const redirector) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(redirector);
	mk_lang_assert(!mk_win_base_handle_is_null(redirector->m_queue));

	b = mk_win_dll_kernel_synchronization_timer_queue_create_timer_queue_timer(&redirector->m_timer, redirector->m_queue, &mk_lib_net_redirector_impl_prrw_on_win_timer, redirector, 1000, 0, mk_win_dll_kernel_synchronization_timer_queue_flag_d_execute_only_once | mk_win_dll_kernel_synchronization_timer_queue_flag_d_execute_in_timer_thread); mk_lang_check_return(b != mk_win_base_false); mk_lang_check_return(!mk_win_base_handle_is_null(redirector->m_timer));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_construct(mk_lib_net_redirector_impl_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_iocp_construct(&redirector->m_iocp, 0); mk_lang_check_rereturn(err);
	redirector->m_want_end_a = mk_lang_false;
	redirector->m_want_end_b = mk_lang_false;
	err = mk_lib_net_redirector_listeners_rw_construct(&redirector->m_listeners); mk_lang_check_rereturn(err);
	redirector->m_queue = mk_win_dll_kernel_synchronization_timer_queue_create_timer_queue(); mk_lang_check_return(!mk_win_base_handle_is_null(redirector->m_timer));
	err = mk_lib_net_redirector_impl_prrw_request_timer(redirector); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_destroy(mk_lib_net_redirector_impl_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;

	mk_lang_assert(redirector);

	err = mk_lib_net_iocp_destroy(&redirector->m_iocp); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_listeners_rw_destroy(&redirector->m_listeners); mk_lang_check_rereturn(err);
	b = mk_win_dll_kernel_synchronization_timer_queue_delete_timer_queue(redirector->m_queue); mk_lang_check_return(b != mk_win_base_false);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_post_dispatch(mk_lib_net_redirector_impl_pt const redirector, mk_lib_net_redirector_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lib_net_redirector_listener_pt listener;
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_forwarder_pt forwarder;
	mk_lang_types_void_pt mem;

	mk_lang_assert(redirector);
	mk_lang_assert(target);

	listener = mk_lib_net_redirector_iop_target_logic_prrw_cast_to_listener(target);
	if(listener)
	{
		if(listener->m_client)
		{
			if(listener->m_client->m_incomming_amount >= 1) /* todo is connected */
			{
				/* todo get address from client */
				err = mk_sl_mallocator_allocate(sizeof(*forwarder), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); forwarder = ((mk_lib_net_redirector_forwarder_pt)(mem)); mk_lang_assert(forwarder);
				err = mk_lib_net_redirector_forwarder_prrw_construct(forwarder, &listener->m_src, &listener->m_dst); mk_lang_check_rereturn(err);
				forwarder->m_client = listener->m_client;
				listener->m_client = mk_lang_null;
				err = mk_lib_net_redirector_forwarders_rw_push_back_move_single(&listener->m_forwarders, &forwarder); mk_lang_check_rereturn(err);
				err = mk_lib_net_redirector_listener_prrw_accept(listener); mk_lang_check_rereturn(err);
			}
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_dispatch_on_end(mk_lib_net_redirector_impl_pt const redirector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_assert(redirector);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special)));
	mk_lang_assert(iop->m_overlapped == ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_end)))));

	redirector->m_want_end_a = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_dispatch_on_timer2(mk_lib_net_redirector_impl_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_net_redirector_listener_ppt pelem;
	mk_lib_net_redirector_listener_pt elem;
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	n = mk_lib_net_redirector_listeners_rw_size(&redirector->m_listeners);
	for(i = 0; i != n; ++i)
	{
		pelem = mk_lib_net_redirector_listeners_rw_at(&redirector->m_listeners, i); mk_lang_assert(pelem); elem = *pelem; mk_lang_assert(elem);
		err = mk_lib_net_redirector_listener_prrw_on_timer(elem); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_dispatch_on_timer(mk_lib_net_redirector_impl_pt const redirector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special)));
	mk_lang_assert(iop->m_overlapped == ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_timer)))));

	b = mk_win_dll_kernel_synchronization_timer_queue_delete_timer_queue_timer(redirector->m_queue, redirector->m_timer, mk_win_base_handle_get_invalid()); mk_lang_check_return(b != mk_win_base_false);
	if(!redirector->m_want_end_a)
	{
		err = mk_lib_net_redirector_impl_prrw_dispatch_on_timer2(redirector); mk_lang_check_rereturn(err);
		err = mk_lib_net_redirector_impl_prrw_request_timer(redirector); mk_lang_check_rereturn(err);
	}
	else
	{
		redirector->m_want_end_b = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_dispatch(mk_lib_net_redirector_impl_pt const redirector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lib_net_redirector_iop_target_data_pt target;
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);
	mk_lang_assert(iop);

	if(iop->m_dequeued)
	{
		if(iop->m_key == ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special)))
		{
			if(iop->m_overlapped == ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_end)))))
			{
				err = mk_lib_net_redirector_impl_prrw_dispatch_on_end(redirector, iop); mk_lang_check_rereturn(err);
			}
			else if(iop->m_overlapped == ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_timer)))))
			{
				err = mk_lib_net_redirector_impl_prrw_dispatch_on_timer(redirector, iop); mk_lang_check_rereturn(err);
			}
			else
			{
				mk_lang_check_todo();
			}
		}
		else
		{
			target = ((mk_lib_net_redirector_iop_target_data_pt)(iop->m_key));
			err = mk_lib_net_redirector_iop_target_logic_prrw_on_iop(target, iop); mk_lang_check_rereturn(err);
			err = mk_lib_net_redirector_impl_prrw_post_dispatch(redirector, target); mk_lang_check_rereturn(err);
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
	}while(!redirector->m_want_end_b);
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
	mk_lib_net_redirector_listener_pt listener;
	mk_lang_types_void_pt mem;

	mk_lang_assert(redirector);
	mk_lang_assert(src);
	mk_lang_assert(dst);

	err = mk_lib_net_redirector_listeners_rw_reserve_additional(&redirector->m_listeners, 1); mk_lang_check_rereturn(err);
	err = mk_sl_mallocator_allocate(sizeof(*listener), &mem); mk_lang_check_rereturn(err); listener = ((mk_lib_net_redirector_listener_pt)(mem)); mk_lang_assert(listener);
	err = mk_lib_net_redirector_listener_prrw_construct(listener, src, dst); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_associate_with_socket(&redirector->m_iocp, ((mk_lang_types_uintptr_t)(&listener->m_iop_target)), &listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_listener_prrw_issue_requests(listener); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_listeners_rw_push_back_move_single(&redirector->m_listeners, &listener); mk_lang_check_rereturn(err);
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
