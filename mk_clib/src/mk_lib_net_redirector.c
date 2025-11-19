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
#include "mk_lib_net.h"
#include "mk_lib_net_buffers.h"
#include "mk_lib_net_iocp.h"
#include "mk_sl_buffers.h"
#include "mk_sl_mallocator.h"
#include "mk_sl_vector_copy.h"
#include "mk_win_dll_kernel_handle.h"
#include "mk_win_dll_kernel_process.h"
#include "mk_win_dll_kernel_synchronization.h"
#include "mk_win_dll_kernel_synchronization_critical_section.h"
#include "mk_win_dll_kernel_synchronization_event.h"
#include "mk_win_dll_kernel_synchronization_timer_queue.h"


#define mk_lib_net_redirector_k_accept_clients (8)
#define mk_lib_net_redirector_k_iocp_key_special (0x00000010)
#define mk_lib_net_redirector_k_iocp_overlapped_special_poke      (0x00000010)
#define mk_lib_net_redirector_k_iocp_overlapped_special_end       (0x00000020)
#define mk_lib_net_redirector_k_iocp_overlapped_special_timer     (0x00000030)
#define mk_lib_net_redirector_k_iocp_overlapped_special_connector (0x00000040)


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
	mk_lib_net_redirector_iop_target_data_id_e_client,
	mk_lib_net_redirector_iop_target_data_id_e_connector,
	mk_lib_net_redirector_iop_target_data_id_e_forwarder,
	mk_lib_net_redirector_iop_target_data_id_e_listener_pure,
	mk_lib_net_redirector_iop_target_data_id_e_listener_client,
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

	target->m_id = ((mk_lang_types_uchar_t)(id));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_iop_target_data_prrw_destroy(mk_lib_net_redirector_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_iop_target_data_id_e_dummy_end);

	((mk_lang_types_void_t)(target));
	return 0;
}


enum mk_lib_net_redirector_client_state_id_e
{
	mk_lib_net_redirector_client_state_id_e_accept_not_issued_yet,
	mk_lib_net_redirector_client_state_id_e_accept_issued,
	mk_lib_net_redirector_client_state_id_e_connected_no_data_transferred_yet,
	mk_lib_net_redirector_client_state_id_e_connected_some_data_transferred,
	mk_lib_net_redirector_client_state_id_e_dummy_end
};
typedef enum mk_lib_net_redirector_client_state_id_e mk_lib_net_redirector_client_state_id_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_client_s
{
	mk_lib_net_socket_t m_socket;
	mk_lib_net_destination_t m_local_address;
	mk_lib_net_destination_t m_remote_address;
	mk_lib_net_redirector_client_state_id_t m_state;
	mk_lib_net_redirector_iop_target_data_t m_iop_target;
	mk_lang_types_bool_t m_pending_send;
	mk_lang_types_bool_t m_pending_recv;
	mk_sl_buffers_buffer_pt m_recv_buffer;
	mk_sl_buffers_buffer_pt m_send_buffer;
	mk_lang_types_sint_t m_recv_amount;
	mk_lang_types_sint_t m_send_amount;
	mk_lib_net_read_request_t m_read_request;
	mk_lib_net_write_request_t m_write_request;
	mk_lib_net_accept_request_t m_accept_request;
};
typedef struct mk_lib_net_redirector_client_s mk_lib_net_redirector_client_t;
mk_lang_typedef(mk_lib_net_redirector_client);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_allocate(mk_lib_net_redirector_client_ppt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_client_pt obj;
	mk_lang_types_void_pt mem;

	mk_lang_assert(client);

	err = mk_sl_mallocator_allocate(sizeof(*obj), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
	obj = ((mk_lib_net_redirector_client_pt)(mem)); mk_lang_assert(obj);
	*client = obj;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_deallocate(mk_lib_net_redirector_client_ppt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);
	mk_lang_assert(*client);

	err = mk_sl_mallocator_deallocate(*client, sizeof(**client)); mk_lang_check_rereturn(err);
	mk_lang_assert((*client = mk_lang_null, mk_lang_true));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_construct(mk_lib_net_redirector_client_pt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);

	err = mk_lib_net_socket_construct(&client->m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&client->m_socket); mk_lang_check_rereturn(err);
	mk_lang_assert((mk_lib_net_destination_clear(&client->m_local_address), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&client->m_remote_address), mk_lang_true));
	client->m_state = mk_lib_net_redirector_client_state_id_e_accept_not_issued_yet;
	err = mk_lib_net_redirector_iop_target_data_prrw_construct(&client->m_iop_target, mk_lib_net_redirector_iop_target_data_id_e_client); mk_lang_check_rereturn(err);
	client->m_pending_send = mk_lang_false;
	client->m_pending_recv = mk_lang_false;
	err = mk_lib_net_buffers_rw_allocate_one(&client->m_recv_buffer); mk_lang_check_rereturn(err);
	client->m_send_buffer = mk_lang_null;
	client->m_recv_amount = 0;
	client->m_send_amount = 0;
	err = mk_lib_net_read_request_construct_void(&client->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_construct_void(&client->m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_construct_void(&client->m_accept_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_destroy(mk_lib_net_redirector_client_pt const client) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);

	err = mk_lib_net_socket_destroy(&client->m_socket); mk_lang_check_rereturn(err);
	mk_lang_assert((mk_lib_net_destination_clear(&client->m_local_address), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&client->m_remote_address), mk_lang_true));
	mk_lang_assert((client->m_state = mk_lib_net_redirector_client_state_id_e_accept_not_issued_yet, mk_lang_true));
	err = mk_lib_net_redirector_iop_target_data_prrw_destroy(&client->m_iop_target); mk_lang_check_rereturn(err);
	mk_lang_assert((client->m_pending_send = mk_lang_false, mk_lang_true));
	mk_lang_assert((client->m_pending_recv = mk_lang_false, mk_lang_true));
	if(client->m_recv_buffer){ err = mk_lib_net_buffers_rw_deallocate_one(client->m_recv_buffer); mk_lang_check_rereturn(err); mk_lang_assert((client->m_recv_buffer = mk_lang_null, mk_lang_true)); }
	mk_lang_assert((client->m_send_buffer = mk_lang_null, mk_lang_true));
	mk_lang_assert((client->m_recv_amount = 0, mk_lang_true));
	mk_lang_assert((client->m_send_amount = 0, mk_lang_true));
	err = mk_lib_net_read_request_destroy(&client->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_destroy(&client->m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_destroy(&client->m_accept_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_issue_read(mk_lib_net_redirector_client_pt const client, mk_sl_buffers_buffer_pt const buffer) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);
	mk_lang_assert(buffer);
	mk_lang_assert(!client->m_pending_recv);

	err = mk_lib_net_read_request_reconstruct(&client->m_read_request, &client->m_socket, &buffer->m_data.m_uint8s[0], mk_lang_countof(buffer->m_data.m_uint8s)); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_issue(&client->m_read_request); mk_lang_check_rereturn(err);
	client->m_pending_recv = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_issue_write(mk_lib_net_redirector_client_pt const client, mk_sl_buffers_buffer_pct const buffer, mk_lang_types_sint_t const amount) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);
	mk_lang_assert(buffer);
	mk_lang_assert(amount >= 1);
	mk_lang_assert(!client->m_pending_send);

	err = mk_lib_net_write_request_reconstruct(&client->m_write_request, &client->m_socket, &buffer->m_data.m_uint8s[0], amount); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_issue(&client->m_write_request); mk_lang_check_rereturn(err);
	client->m_pending_send = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_on_iop_read(mk_lib_net_redirector_client_pt const client, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_buffers_buffer_pt buffer;
	mk_lang_types_sint_t amount;

	mk_lang_assert(client);
	mk_lang_assert(iop);
	mk_lang_assert(client->m_pending_recv);
	mk_lang_assert(!client->m_recv_buffer);
	mk_lang_assert(client->m_recv_amount == 0);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&client->m_iop_target)));
	mk_lang_assert(iop->m_overlapped == &client->m_read_request.m_overlapped);

	err = mk_lib_net_read_request_wait_infinite(&client->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_get_result(&client->m_read_request); mk_lang_check_rereturn(err);
	mk_lang_assert(client->m_read_request.m_done);
	mk_lang_assert(client->m_read_request.m_b);
	mk_lang_check_return(iop->m_successful_io_operation); /* todo */
	mk_lang_assert(iop->m_bytes_transferred == client->m_read_request.m_transferred);
	buffer = ((mk_sl_buffers_buffer_pt)(client->m_read_request.m_data_buf));
	amount = client->m_read_request.m_transferred;
	client->m_recv_buffer = buffer;
	client->m_recv_amount = amount;
	client->m_pending_recv = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_on_iop_write(mk_lib_net_redirector_client_pt const client, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_buffers_buffer_pt buffer;
	mk_lang_types_sint_t amount;

	mk_lang_assert(client);
	mk_lang_assert(iop);
	mk_lang_assert(client->m_pending_send);
	mk_lang_assert(!client->m_send_buffer);
	mk_lang_assert(client->m_send_amount == 0);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&client->m_iop_target)));
	mk_lang_assert(iop->m_overlapped == &client->m_write_request.m_overlapped);

	err = mk_lib_net_write_request_wait_infinite(&client->m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_get_result(&client->m_write_request); mk_lang_check_rereturn(err);
	mk_lang_assert(client->m_write_request.m_done);
	mk_lang_assert(client->m_write_request.m_b);
	mk_lang_check_return(iop->m_successful_io_operation); /* todo */
	mk_lang_assert(iop->m_bytes_transferred == client->m_write_request.m_transferred);
	buffer = ((mk_sl_buffers_buffer_pt)(client->m_write_request.m_data_buf));
	amount = client->m_write_request.m_transferred;
	client->m_send_buffer = buffer;
	client->m_send_amount = amount;
	client->m_pending_send = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_client_prrw_on_iop(mk_lib_net_redirector_client_pt const client, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&client->m_iop_target)));

	if(mk_lang_runtime_bool_fn_false){}
	else if(iop->m_overlapped == &client->m_read_request .m_overlapped){ err = mk_lib_net_redirector_client_prrw_on_iop_read (client, iop); mk_lang_check_rereturn(err); }
	else if(iop->m_overlapped == &client->m_write_request.m_overlapped){ err = mk_lib_net_redirector_client_prrw_on_iop_write(client, iop); mk_lang_check_rereturn(err); }
	else{ mk_lang_assert_false(); }
	return 0;
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_connector_s
{
	mk_lib_net_socket_t m_socket;
	mk_lib_net_destination_t m_local_address;
	mk_lib_net_destination_t m_remote_address;
	mk_lib_net_redirector_iop_target_data_t m_iop_target;
	mk_lang_types_bool_t m_pending_send;
	mk_lang_types_bool_t m_pending_recv;
	mk_sl_buffers_buffer_pt m_recv_buffer;
	mk_sl_buffers_buffer_pt m_send_buffer;
	mk_lang_types_sint_t m_recv_amount;
	mk_lang_types_sint_t m_send_amount;
	mk_lib_net_read_request_t m_read_request;
	mk_lib_net_write_request_t m_write_request;
	mk_lib_net_connect_request_t m_connect_request;
};
typedef struct mk_lib_net_redirector_connector_s mk_lib_net_redirector_connector_t;
mk_lang_typedef(mk_lib_net_redirector_connector);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_allocate(mk_lib_net_redirector_connector_ppt const connector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_connector_pt obj;
	mk_lang_types_void_pt mem;

	mk_lang_assert(connector);

	err = mk_sl_mallocator_allocate(sizeof(*obj), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
	obj = ((mk_lib_net_redirector_connector_pt)(mem)); mk_lang_assert(obj);
	*connector = obj;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_deallocate(mk_lib_net_redirector_connector_ppt const connector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);
	mk_lang_assert(*connector);

	err = mk_sl_mallocator_deallocate(*connector, sizeof(**connector)); mk_lang_check_rereturn(err);
	mk_lang_assert((*connector = mk_lang_null, mk_lang_true));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_construct(mk_lib_net_redirector_connector_pt const connector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);

	err = mk_lib_net_socket_construct(&connector->m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&connector->m_socket); mk_lang_check_rereturn(err);
	mk_lang_assert((mk_lib_net_destination_clear(&connector->m_local_address), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&connector->m_remote_address), mk_lang_true));
	err = mk_lib_net_redirector_iop_target_data_prrw_construct(&connector->m_iop_target, mk_lib_net_redirector_iop_target_data_id_e_connector); mk_lang_check_rereturn(err);
	connector->m_pending_send = mk_lang_false;
	connector->m_pending_recv = mk_lang_false;
	connector->m_recv_buffer = mk_lang_null;
	connector->m_send_buffer = mk_lang_null;
	connector->m_recv_amount = 0;
	connector->m_send_amount = 0;
	err = mk_lib_net_read_request_construct_void(&connector->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_construct_void(&connector->m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_connect_request_construct_void(&connector->m_connect_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_destroy(mk_lib_net_redirector_connector_pt const connector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);

	err = mk_lib_net_socket_destroy(&connector->m_socket); mk_lang_check_rereturn(err);
	mk_lang_assert((mk_lib_net_destination_clear(&connector->m_local_address), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&connector->m_remote_address), mk_lang_true));
	err = mk_lib_net_redirector_iop_target_data_prrw_destroy(&connector->m_iop_target); mk_lang_check_rereturn(err);
	mk_lang_assert((connector->m_pending_send = mk_lang_false, mk_lang_true));
	mk_lang_assert((connector->m_pending_recv = mk_lang_false, mk_lang_true));
	mk_lang_assert((connector->m_recv_buffer = mk_lang_null, mk_lang_true));
	mk_lang_assert((connector->m_send_buffer = mk_lang_null, mk_lang_true));
	mk_lang_assert((connector->m_recv_amount = 0, mk_lang_true));
	mk_lang_assert((connector->m_send_amount = 0, mk_lang_true));
	err = mk_lib_net_read_request_destroy(&connector->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_destroy(&connector->m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_connect_request_destroy(&connector->m_connect_request); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_on_iop_read(mk_lib_net_redirector_connector_pt const connector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_buffers_buffer_pt buffer;
	mk_lang_types_sint_t amount;

	mk_lang_assert(connector);
	mk_lang_assert(iop);
	mk_lang_assert(connector->m_pending_recv);
	mk_lang_assert(!connector->m_recv_buffer);
	mk_lang_assert(connector->m_recv_amount == 0);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&connector->m_iop_target)));
	mk_lang_assert(iop->m_overlapped == &connector->m_read_request.m_overlapped);

	err = mk_lib_net_read_request_wait_infinite(&connector->m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_get_result(&connector->m_read_request); mk_lang_check_rereturn(err);
	mk_lang_assert(connector->m_read_request.m_done);
	mk_lang_assert(connector->m_read_request.m_b);
	mk_lang_check_return(iop->m_successful_io_operation); /* todo */
	mk_lang_assert(iop->m_bytes_transferred == connector->m_read_request.m_transferred);
	buffer = ((mk_sl_buffers_buffer_pt)(connector->m_read_request.m_data_buf));
	amount = connector->m_read_request.m_transferred;
	connector->m_recv_buffer = buffer;
	connector->m_recv_amount = amount;
	connector->m_pending_recv = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_on_iop_write(mk_lib_net_redirector_connector_pt const connector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_buffers_buffer_pt buffer;
	mk_lang_types_sint_t amount;

	mk_lang_assert(connector);
	mk_lang_assert(iop);
	mk_lang_assert(connector->m_pending_send);
	mk_lang_assert(!connector->m_send_buffer);
	mk_lang_assert(connector->m_send_amount == 0);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&connector->m_iop_target)));
	mk_lang_assert(iop->m_overlapped == &connector->m_write_request.m_overlapped);

	err = mk_lib_net_write_request_wait_infinite(&connector->m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_get_result(&connector->m_write_request); mk_lang_check_rereturn(err);
	mk_lang_assert(connector->m_write_request.m_done);
	mk_lang_assert(connector->m_write_request.m_b);
	mk_lang_check_return(iop->m_successful_io_operation); /* todo */
	mk_lang_assert(iop->m_bytes_transferred == connector->m_write_request.m_transferred);
	buffer = ((mk_sl_buffers_buffer_pt)(connector->m_write_request.m_data_buf));
	amount = connector->m_write_request.m_transferred;
	connector->m_send_buffer = buffer;
	connector->m_send_amount = amount;
	connector->m_pending_send = mk_lang_false;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_connector_prrw_on_iop(mk_lib_net_redirector_connector_pt const connector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connector);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&connector->m_iop_target)));

	if(mk_lang_runtime_bool_fn_false){}
	else if(iop->m_overlapped == &connector->m_read_request .m_overlapped){ err = mk_lib_net_redirector_connector_prrw_on_iop_read (connector, iop); mk_lang_check_rereturn(err); }
	else if(iop->m_overlapped == &connector->m_write_request.m_overlapped){ err = mk_lib_net_redirector_connector_prrw_on_iop_write(connector, iop); mk_lang_check_rereturn(err); }
	else{ mk_lang_assert_false(); }
	return 0;
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_forwarder_s
{
	mk_lib_net_destination_t m_src;
	mk_lib_net_destination_t m_dst;
	mk_lib_net_redirector_client_t m_client;
	mk_lib_net_redirector_connector_t m_connector;
	mk_lib_net_redirector_iop_target_data_t m_iop_target;
};
typedef struct mk_lib_net_redirector_forwarder_s mk_lib_net_redirector_forwarder_t;
mk_lang_typedef(mk_lib_net_redirector_forwarder);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_allocate(mk_lib_net_redirector_forwarder_ppt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_forwarder_pt obj;
	mk_lang_types_void_pt mem;

	mk_lang_assert(forwarder);

	err = mk_sl_mallocator_allocate(sizeof(*obj), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
	obj = ((mk_lib_net_redirector_forwarder_pt)(mem)); mk_lang_assert(obj);
	*forwarder = obj;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_deallocate(mk_lib_net_redirector_forwarder_ppt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);
	mk_lang_assert(*forwarder);

	err = mk_sl_mallocator_deallocate(*forwarder, sizeof(**forwarder)); mk_lang_check_rereturn(err);
	mk_lang_assert((*forwarder = mk_lang_null, mk_lang_true));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_construct(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);
	mk_lang_assert(src);
	mk_lang_assert(dst);

	forwarder->m_src = *src;
	forwarder->m_dst = *dst;
	err = mk_lib_net_redirector_client_prrw_construct(&forwarder->m_client); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_connector_prrw_construct(&forwarder->m_connector); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_iop_target_data_prrw_construct(&forwarder->m_iop_target, mk_lib_net_redirector_iop_target_data_id_e_forwarder); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_destroy(mk_lib_net_redirector_forwarder_pt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	mk_lang_assert((mk_lib_net_destination_clear(&forwarder->m_src), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&forwarder->m_dst), mk_lang_true));
	err = mk_lib_net_redirector_client_prrw_destroy(&forwarder->m_client); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_connector_prrw_destroy(&forwarder->m_connector); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_iop_target_data_prrw_destroy(&forwarder->m_iop_target); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_on_iop(mk_lib_net_redirector_forwarder_pt const forwarder, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_assert(forwarder);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&forwarder->m_iop_target)));

	if(mk_lang_runtime_bool_fn_false){}
	else{ mk_lang_assert_false(); }
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_vec_construct_void(mk_lib_net_redirector_forwarder_ppt const forwarder) mk_lang_noexcept
{
	mk_lang_assert(forwarder);

	*forwarder = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_vec_destruct(mk_lib_net_redirector_forwarder_ppt const forwarder) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(forwarder);

	if(*forwarder)
	{
		err = mk_lib_net_redirector_forwarder_prrw_destroy(*forwarder); mk_lang_check_rereturn(err);
		err = mk_lib_net_redirector_forwarder_prrw_deallocate(forwarder); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_vec_copy_construct(mk_lib_net_redirector_forwarder_ppt const dst, mk_lib_net_redirector_forwarder_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_vec_move_construct(mk_lib_net_redirector_forwarder_ppt const dst, mk_lib_net_redirector_forwarder_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_vec_copy_assign(mk_lib_net_redirector_forwarder_ppt const dst, mk_lib_net_redirector_forwarder_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_forwarder_prrw_vec_move_assign(mk_lib_net_redirector_forwarder_ppt const dst, mk_lib_net_redirector_forwarder_ppt const src) mk_lang_noexcept
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
#define mk_sl_vector_t_element_construct_void mk_lib_net_redirector_forwarder_prrw_vec_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_net_redirector_forwarder_prrw_vec_destruct
#define mk_sl_vector_t_element_copy_construct mk_lib_net_redirector_forwarder_prrw_vec_copy_construct
#define mk_sl_vector_t_element_move_construct mk_lib_net_redirector_forwarder_prrw_vec_move_construct
#define mk_sl_vector_t_element_copy_assign mk_lib_net_redirector_forwarder_prrw_vec_copy_assign
#define mk_sl_vector_t_element_move_assign mk_lib_net_redirector_forwarder_prrw_vec_move_assign
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_listener_s
{
	mk_lib_net_destination_t m_src;
	mk_lib_net_destination_t m_dst;
	mk_lib_net_socket_t m_socket;
	mk_lib_net_redirector_iop_target_data_t m_iop_target;
	mk_lib_net_redirector_iop_target_data_t m_iop_client_target;
	mk_lib_net_iocp_pt m_iocp;
	mk_lib_net_redirector_forwarders_t m_forwarders;
	mk_win_dll_ws2_fn_accept_ex_t m_fn_accept_ex;
	mk_win_dll_ws2_fn_get_accept_ex_sock_addrs_t m_fn_get_accept_ex_sock_addrs;
	mk_lib_net_ioctl_request_t m_fn_request_accept_ex;
	mk_lib_net_ioctl_request_t m_fn_request_get_accept_ex_sock_addrs;
};
typedef struct mk_lib_net_redirector_listener_s mk_lib_net_redirector_listener_t;
mk_lang_typedef(mk_lib_net_redirector_listener);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_allocate(mk_lib_net_redirector_listener_ppt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_listener_pt obj;
	mk_lang_types_void_pt mem;

	mk_lang_assert(listener);

	err = mk_sl_mallocator_allocate(sizeof(*obj), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
	obj = ((mk_lib_net_redirector_listener_pt)(mem)); mk_lang_assert(obj);
	*listener = obj;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_deallocate(mk_lib_net_redirector_listener_ppt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(*listener);

	err = mk_sl_mallocator_deallocate(*listener, sizeof(**listener)); mk_lang_check_rereturn(err);
	mk_lang_assert((*listener = mk_lang_null, mk_lang_true));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_construct(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_iocp_pt const iocp, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iocp);
	mk_lang_assert(src);
	mk_lang_assert(dst);

	listener->m_src = *src;
	listener->m_dst = *dst;
	err = mk_lib_net_socket_construct(&listener->m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_iop_target_data_prrw_construct(&listener->m_iop_target, mk_lib_net_redirector_iop_target_data_id_e_listener_pure); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_iop_target_data_prrw_construct(&listener->m_iop_client_target, mk_lib_net_redirector_iop_target_data_id_e_listener_client); mk_lang_check_rereturn(err);
	listener->m_iocp = iocp;
	err = mk_lib_net_redirector_forwarders_rw_construct(&listener->m_forwarders); mk_lang_check_rereturn(err);
	mk_lang_assert((listener->m_fn_accept_ex = mk_lang_null, mk_lang_true));
	mk_lang_assert((listener->m_fn_get_accept_ex_sock_addrs = mk_lang_null, mk_lang_true));
	err = mk_lib_net_ioctl_request_construct_void(&listener->m_fn_request_accept_ex); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_construct_void(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);

	err = mk_lib_net_socket_bind(&listener->m_socket, &listener->m_src); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_listen(&listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_associate_with_socket(iocp, ((mk_lang_types_uintptr_t)(&listener->m_iop_target)), &listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_reconstruct(&listener->m_fn_request_accept_ex               , &listener->m_socket, ((mk_lang_types_uint_t)(mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer)), &mk_lib_net_redirector_k_fn_guid_accept_ex               .m_data.m_uint8s[0], mk_lang_countof(mk_lib_net_redirector_k_fn_guid_accept_ex               .m_data.m_uchars), ((mk_sl_cui_uint8_pt)(&listener->m_fn_accept_ex               )), sizeof(listener->m_fn_accept_ex               )); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_reconstruct(&listener->m_fn_request_get_accept_ex_sock_addrs, &listener->m_socket, ((mk_lang_types_uint_t)(mk_win_dll_ws2_ioctl_control_code_e_get_extension_function_pointer)), &mk_lib_net_redirector_k_fn_guid_get_accept_ex_sock_addrs.m_data.m_uint8s[0], mk_lang_countof(mk_lib_net_redirector_k_fn_guid_get_accept_ex_sock_addrs.m_data.m_uchars), ((mk_sl_cui_uint8_pt)(&listener->m_fn_get_accept_ex_sock_addrs)), sizeof(listener->m_fn_get_accept_ex_sock_addrs)); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_issue(&listener->m_fn_request_accept_ex               ); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_issue(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_destroy(mk_lib_net_redirector_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);

	mk_lang_assert((mk_lib_net_destination_clear(&listener->m_src), mk_lang_true));
	mk_lang_assert((mk_lib_net_destination_clear(&listener->m_dst), mk_lang_true));
	err = mk_lib_net_socket_destroy(&listener->m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_iop_target_data_prrw_destroy(&listener->m_iop_target); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_iop_target_data_prrw_destroy(&listener->m_iop_client_target); mk_lang_check_rereturn(err);
	mk_lang_assert((listener->m_iocp = mk_lang_null, mk_lang_true));
	err = mk_lib_net_redirector_forwarders_rw_destroy(&listener->m_forwarders); mk_lang_check_rereturn(err);
	mk_lang_assert((listener->m_fn_accept_ex = mk_lang_null, mk_lang_true));
	mk_lang_assert((listener->m_fn_get_accept_ex_sock_addrs = mk_lang_null, mk_lang_true));
	err = mk_lib_net_ioctl_request_destroy(&listener->m_fn_request_accept_ex); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_destroy(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_accept_one(mk_lib_net_redirector_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_forwarder_pt forwarder;

	mk_lang_assert(listener);

	err = mk_lib_net_redirector_forwarders_rw_reserve_additional(&listener->m_forwarders, 1); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_forwarder_prrw_allocate(&forwarder); mk_lang_check_rereturn(err); mk_lang_assert(forwarder);
	err = mk_lib_net_redirector_forwarder_prrw_construct(forwarder, &listener->m_src, &listener->m_dst); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_associate_with_socket(listener->m_iocp, ((mk_lang_types_uintptr_t)(&listener->m_iop_client_target)), &forwarder->m_client.m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_reconstruct(&forwarder->m_client.m_accept_request, &listener->m_fn_accept_ex, &listener->m_fn_get_accept_ex_sock_addrs, &listener->m_socket, &forwarder->m_client.m_socket, &forwarder->m_client.m_recv_buffer->m_data.m_uint8s[0], mk_lang_countof(forwarder->m_client.m_recv_buffer->m_data.m_uint8s)); mk_lang_check_rereturn(err);
	mk_lang_assert(forwarder->m_client.m_state == mk_lib_net_redirector_client_state_id_e_accept_not_issued_yet); forwarder->m_client.m_state = mk_lib_net_redirector_client_state_id_e_accept_issued;
	mk_lang_assert(!forwarder->m_client.m_pending_recv); forwarder->m_client.m_pending_recv = mk_lang_true;
	mk_lang_assert(forwarder->m_client.m_recv_buffer); forwarder->m_client.m_recv_buffer = mk_lang_null;
	err = mk_lib_net_accept_request_issue(&forwarder->m_client.m_accept_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_forwarders_rw_push_back_move_single(&listener->m_forwarders, &forwarder); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_accept_all(mk_lib_net_redirector_listener_pt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(listener);

	err = mk_lib_net_redirector_forwarders_rw_reserve_at_least(&listener->m_forwarders, mk_lib_net_redirector_k_accept_clients); mk_lang_check_rereturn(err);
	n = mk_lib_net_redirector_k_accept_clients;
	for(i = 0; i != n; ++i)
	{
		err = mk_lib_net_redirector_listener_prrw_accept_one(listener); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_on_iop_fn_accept_ex(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&listener->m_iop_target)));
	mk_lang_assert(iop->m_overlapped == &listener->m_fn_request_accept_ex.m_overlapped);

	mk_lang_check_return(iop->m_successful_io_operation);
	mk_lang_check_return(iop->m_bytes_transferred == 0);
	err = mk_lib_net_ioctl_request_wait_infinite(&listener->m_fn_request_accept_ex); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&listener->m_fn_request_accept_ex); mk_lang_check_rereturn(err);
	mk_lang_assert(listener->m_fn_request_accept_ex.m_done);
	mk_lang_check_return(listener->m_fn_request_accept_ex.m_b != mk_lang_false);
	mk_lang_check_return(listener->m_fn_request_accept_ex.m_transferred == sizeof(listener->m_fn_accept_ex));
	err = mk_lib_net_ioctl_request_reset(&listener->m_fn_request_accept_ex); mk_lang_check_rereturn(err);
	if(listener->m_fn_request_get_accept_ex_sock_addrs.m_done)
	{
		err = mk_lib_net_redirector_listener_prrw_accept_all(listener); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_on_iop_fn_get_accept_ex_sock_addrs(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&listener->m_iop_target)));
	mk_lang_assert(iop->m_overlapped == &listener->m_fn_request_get_accept_ex_sock_addrs.m_overlapped);

	mk_lang_check_return(iop->m_successful_io_operation);
	mk_lang_check_return(iop->m_bytes_transferred == 0);
	err = mk_lib_net_ioctl_request_wait_infinite(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	err = mk_lib_net_ioctl_request_get_result(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	mk_lang_assert(listener->m_fn_request_get_accept_ex_sock_addrs.m_done);
	mk_lang_check_return(listener->m_fn_request_get_accept_ex_sock_addrs.m_b != mk_lang_false);
	mk_lang_check_return(listener->m_fn_request_get_accept_ex_sock_addrs.m_transferred == sizeof(listener->m_fn_get_accept_ex_sock_addrs));
	err = mk_lib_net_ioctl_request_reset(&listener->m_fn_request_get_accept_ex_sock_addrs); mk_lang_check_rereturn(err);
	if(listener->m_fn_request_accept_ex.m_done)
	{
		err = mk_lib_net_redirector_listener_prrw_accept_all(listener); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_on_iop_client_accepted(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_accept_request_pt accept_request;
	mk_lib_net_redirector_client_pt client;
	mk_lib_net_redirector_forwarder_pt forwarder;
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&listener->m_iop_target)));
	mk_lang_assert(iop->m_overlapped);

	offset = mk_lang_offsetof(mk_lib_net_accept_request_t, m_overlapped);
	accept_request = ((mk_lib_net_accept_request_pt)(((mk_lang_types_uchar_pt)(iop->m_overlapped)) - offset));
	offset = mk_lang_offsetof(mk_lib_net_redirector_client_t, m_accept_request);
	client = ((mk_lib_net_redirector_client_pt)(((mk_lang_types_uchar_pt)(accept_request)) - offset));
	offset = mk_lang_offsetof(mk_lib_net_redirector_forwarder_t, m_client);
	forwarder = ((mk_lib_net_redirector_forwarder_pt)(((mk_lang_types_uchar_pt)(client)) - offset));
	mk_lang_check_return(iop->m_successful_io_operation);
	mk_lang_check_return(iop->m_bytes_transferred >= 1);
	mk_lang_assert(iop->m_overlapped == &forwarder->m_client.m_accept_request.m_overlapped);
	err = mk_lib_net_accept_request_wait_infinite(&client->m_accept_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_accept_request_get_result(&client->m_accept_request); mk_lang_check_rereturn(err);
	mk_lang_check_return(client->m_accept_request.m_b != mk_lang_false);
	mk_lang_check_return(client->m_accept_request.m_transferred == iop->m_bytes_transferred);
	err = mk_lib_net_accept_request_reset(&client->m_accept_request); mk_lang_check_rereturn(err);

	mk_lang_assert(client->m_pending_recv); client->m_pending_recv = mk_lang_false;
	mk_lang_assert(!client->m_recv_buffer); client->m_recv_buffer = ((mk_sl_buffers_buffer_pt)(client->m_accept_request.m_out_data_buf));
	client->m_recv_amount = iop->m_bytes_transferred;
	mk_lang_assert(client->m_state == mk_lib_net_redirector_client_state_id_e_accept_issued || client->m_state == mk_lib_net_redirector_client_state_id_e_connected_no_data_transferred_yet); client->m_state = mk_lib_net_redirector_client_state_id_e_connected_some_data_transferred;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_on_iop_pure(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&listener->m_iop_target)));

	if(mk_lang_runtime_bool_fn_false){}
	else if(iop->m_overlapped == &listener->m_fn_request_accept_ex               .m_overlapped){ err = mk_lib_net_redirector_listener_prrw_on_iop_fn_accept_ex               (listener, iop); mk_lang_check_rereturn(err); }
	else if(iop->m_overlapped == &listener->m_fn_request_get_accept_ex_sock_addrs.m_overlapped){ err = mk_lib_net_redirector_listener_prrw_on_iop_fn_get_accept_ex_sock_addrs(listener, iop); mk_lang_check_rereturn(err); }
	else                                                                                       { err = mk_lib_net_redirector_listener_prrw_on_iop_client_accepted            (listener, iop); mk_lang_check_rereturn(err); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_on_iop_client(mk_lib_net_redirector_listener_pt const listener, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_assert(listener);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(&listener->m_iop_client_target)));

	mk_lang_check_todo();
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_vec_construct_void(mk_lib_net_redirector_listener_ppt const listener) mk_lang_noexcept
{
	mk_lang_assert(listener);

	*listener = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_vec_destruct(mk_lib_net_redirector_listener_ppt const listener) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(listener);

	if(*listener)
	{
		err = mk_lib_net_redirector_listener_prrw_destroy(*listener); mk_lang_check_rereturn(err);
		err = mk_lib_net_redirector_listener_prrw_deallocate(listener); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_vec_copy_construct(mk_lib_net_redirector_listener_ppt const dst, mk_lib_net_redirector_listener_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_vec_move_construct(mk_lib_net_redirector_listener_ppt const dst, mk_lib_net_redirector_listener_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_vec_copy_assign(mk_lib_net_redirector_listener_ppt const dst, mk_lib_net_redirector_listener_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_listener_prrw_vec_move_assign(mk_lib_net_redirector_listener_ppt const dst, mk_lib_net_redirector_listener_ppt const src) mk_lang_noexcept
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
#define mk_sl_vector_t_element_construct_void mk_lib_net_redirector_listener_prrw_vec_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_net_redirector_listener_prrw_vec_destruct
#define mk_sl_vector_t_element_copy_construct mk_lib_net_redirector_listener_prrw_vec_copy_construct
#define mk_sl_vector_t_element_move_construct mk_lib_net_redirector_listener_prrw_vec_move_construct
#define mk_sl_vector_t_element_copy_assign mk_lib_net_redirector_listener_prrw_vec_copy_assign
#define mk_sl_vector_t_element_move_assign mk_lib_net_redirector_listener_prrw_vec_move_assign
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lib_net_redirector_client_pt mk_lib_net_redirector_iop_target_logic_prrw_cast_to_client(mk_lib_net_redirector_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_redirector_client_pt obj;

	/* natvis */
	mk_lang_static_assert
	(
		mk_lang_offsetof(mk_lib_net_redirector_client_t, m_iop_target) ==
		sizeof(obj->m_socket) +
		sizeof(obj->m_local_address) +
		sizeof(obj->m_remote_address) +
		sizeof(obj->m_state) +
		0
	);

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_iop_target_data_id_e_dummy_end);

	if(target->m_id == mk_lib_net_redirector_iop_target_data_id_e_client)
	{
		offset = mk_lang_offsetof(mk_lib_net_redirector_client_t, m_iop_target);
		obj = ((mk_lib_net_redirector_client_pt)(((mk_lang_types_uchar_pt)(target)) - offset));
		return obj;
	}
	else
	{
		return mk_lang_null;
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lib_net_redirector_connector_pt mk_lib_net_redirector_iop_target_logic_prrw_cast_to_connector(mk_lib_net_redirector_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_redirector_connector_pt obj;

	/* natvis */
	mk_lang_static_assert
	(
		mk_lang_offsetof(mk_lib_net_redirector_connector_t, m_iop_target) ==
		sizeof(obj->m_socket) +
		sizeof(obj->m_local_address) +
		sizeof(obj->m_remote_address) +
		0
	);

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_iop_target_data_id_e_dummy_end);

	if(target->m_id == mk_lib_net_redirector_iop_target_data_id_e_connector)
	{
		offset = mk_lang_offsetof(mk_lib_net_redirector_connector_t, m_iop_target);
		obj = ((mk_lib_net_redirector_connector_pt)(((mk_lang_types_uchar_pt)(target)) - offset));
		return obj;
	}
	else
	{
		return mk_lang_null;
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lib_net_redirector_forwarder_pt mk_lib_net_redirector_iop_target_logic_prrw_cast_to_forwarder(mk_lib_net_redirector_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_redirector_forwarder_pt obj;

	/* natvis */
	mk_lang_static_assert
	(
		mk_lang_offsetof(mk_lib_net_redirector_forwarder_t, m_iop_target) ==
		sizeof(obj->m_src) +
		sizeof(obj->m_dst) +
		sizeof(obj->m_client) +
		sizeof(obj->m_connector) +
		0
	);

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_iop_target_data_id_e_dummy_end);

	if(target->m_id == mk_lib_net_redirector_iop_target_data_id_e_forwarder)
	{
		offset = mk_lang_offsetof(mk_lib_net_redirector_forwarder_t, m_iop_target);
		obj = ((mk_lib_net_redirector_forwarder_pt)(((mk_lang_types_uchar_pt)(target)) - offset));
		return obj;
	}
	else
	{
		return mk_lang_null;
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lib_net_redirector_listener_pt mk_lib_net_redirector_iop_target_logic_prrw_cast_to_listener_pure(mk_lib_net_redirector_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_redirector_listener_pt obj;

	/* natvis */
	mk_lang_static_assert
	(
		mk_lang_offsetof(mk_lib_net_redirector_listener_t, m_iop_target) ==
		sizeof(obj->m_src) +
		sizeof(obj->m_dst) +
		sizeof(obj->m_socket) +
		0
	);

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_iop_target_data_id_e_dummy_end);

	if(target->m_id == mk_lib_net_redirector_iop_target_data_id_e_listener_pure)
	{
		offset = mk_lang_offsetof(mk_lib_net_redirector_listener_t, m_iop_target);
		obj = ((mk_lib_net_redirector_listener_pt)(((mk_lang_types_uchar_pt)(target)) - offset));
		return obj;
	}
	else
	{
		return mk_lang_null;
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lib_net_redirector_listener_pt mk_lib_net_redirector_iop_target_logic_prrw_cast_to_listener_client(mk_lib_net_redirector_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_redirector_listener_pt obj;

	/* natvis */
	mk_lang_static_assert
	(
		mk_lang_offsetof(mk_lib_net_redirector_listener_t, m_iop_client_target) ==
		sizeof(obj->m_src) +
		sizeof(obj->m_dst) +
		sizeof(obj->m_socket) +
		sizeof(obj->m_iop_client_target) +
		0
	);

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_iop_target_data_id_e_dummy_end);

	if(target->m_id == mk_lib_net_redirector_iop_target_data_id_e_listener_pure)
	{
		offset = mk_lang_offsetof(mk_lib_net_redirector_listener_t, m_iop_target);
		obj = ((mk_lib_net_redirector_listener_pt)(((mk_lang_types_uchar_pt)(target)) - offset));
		return obj;
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
	mk_lang_assert(target->m_id < mk_lib_net_redirector_iop_target_data_id_e_dummy_end);

	switch(target->m_id)
	{
		case mk_lib_net_redirector_iop_target_data_id_e_client         : { mk_lib_net_redirector_client_pt    obj; obj = mk_lib_net_redirector_iop_target_logic_prrw_cast_to_client         (target); mk_lang_assert(obj); err = mk_lib_net_redirector_client_prrw_on_iop         (obj, iop); } break;
		case mk_lib_net_redirector_iop_target_data_id_e_connector      : { mk_lib_net_redirector_connector_pt obj; obj = mk_lib_net_redirector_iop_target_logic_prrw_cast_to_connector      (target); mk_lang_assert(obj); err = mk_lib_net_redirector_connector_prrw_on_iop      (obj, iop); } break;
		case mk_lib_net_redirector_iop_target_data_id_e_forwarder      : { mk_lib_net_redirector_forwarder_pt obj; obj = mk_lib_net_redirector_iop_target_logic_prrw_cast_to_forwarder      (target); mk_lang_assert(obj); err = mk_lib_net_redirector_forwarder_prrw_on_iop      (obj, iop); } break;
		case mk_lib_net_redirector_iop_target_data_id_e_listener_pure  : { mk_lib_net_redirector_listener_pt  obj; obj = mk_lib_net_redirector_iop_target_logic_prrw_cast_to_listener_pure  (target); mk_lang_assert(obj); err = mk_lib_net_redirector_listener_prrw_on_iop_pure  (obj, iop); } break;
		case mk_lib_net_redirector_iop_target_data_id_e_listener_client: { mk_lib_net_redirector_listener_pt  obj; obj = mk_lib_net_redirector_iop_target_logic_prrw_cast_to_listener_client(target); mk_lang_assert(obj); err = mk_lib_net_redirector_listener_prrw_on_iop_client(obj, iop); } break;
		case mk_lib_net_redirector_iop_target_data_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


enum mk_lib_net_redirector_driven_target_data_id_e
{
	mk_lib_net_redirector_driven_target_data_id_e_redirector,
	mk_lib_net_redirector_driven_target_data_id_e_dummy_end
};
typedef enum mk_lib_net_redirector_driven_target_data_id_e mk_lib_net_redirector_driven_target_data_id_t;
mk_lang_typedef(mk_lib_net_redirector_driven_target_data_id);


struct mk_lib_net_redirector_driven_target_data_s
{
	mk_lang_types_uchar_t m_id;
};
typedef struct mk_lib_net_redirector_driven_target_data_s mk_lib_net_redirector_driven_target_data_t;
mk_lang_typedef(mk_lib_net_redirector_driven_target_data);


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driven_target_data_prrw_construct(mk_lib_net_redirector_driven_target_data_pt const target, mk_lib_net_redirector_driven_target_data_id_t const id) mk_lang_noexcept
{
	mk_lang_assert(target);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_net_redirector_driven_target_data_id_e_dummy_end);

	target->m_id = ((mk_lang_types_uchar_t)(id));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driven_target_data_prrw_destroy(mk_lib_net_redirector_driven_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_assert(target);

	((mk_lang_types_void_t)(target));
	return 0;
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_redirector_s
{
	mk_lib_net_redirector_driven_target_data_t m_driven_target;
	mk_lib_net_iocp_pt m_iocp;
	mk_lib_net_redirector_listeners_t m_listeners;
	//mk_lib_net_redirector_dyn_events_t m_waiting_to_connect;
	//mk_lib_net_redirector_waiter_t m_waiter;
};
typedef struct mk_lib_net_redirector_redirector_s mk_lib_net_redirector_redirector_t;
mk_lang_typedef(mk_lib_net_redirector_redirector);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_redirector_prrw_allocate(mk_lib_net_redirector_redirector_ppt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_redirector_pt obj;
	mk_lang_types_void_pt mem;

	mk_lang_assert(redirector);

	err = mk_sl_mallocator_allocate(sizeof(*obj), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
	obj = ((mk_lib_net_redirector_redirector_pt)(mem)); mk_lang_assert(obj);
	*redirector = obj;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_redirector_prrw_deallocate(mk_lib_net_redirector_redirector_ppt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);
	mk_lang_assert(*redirector);

	err = mk_sl_mallocator_deallocate(*redirector, sizeof(**redirector)); mk_lang_check_rereturn(err);
	mk_lang_assert((*redirector = mk_lang_null, mk_lang_true));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_redirector_prrw_construct(mk_lib_net_redirector_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_redirector_driven_target_data_prrw_construct(&redirector->m_driven_target, mk_lib_net_redirector_driven_target_data_id_e_redirector); mk_lang_check_rereturn(err);
	mk_lang_assert((redirector->m_iocp = mk_lang_null, mk_lang_true));
	err = mk_lib_net_redirector_listeners_rw_construct(&redirector->m_listeners); mk_lang_check_rereturn(err);
	//err = mk_lib_net_redirector_dyn_events_rw_construct(&redirector->m_waiting_to_connect); mk_lang_check_rereturn(err);
	//err = mk_lib_net_redirector_waiter_prrw_construct(&redirector->m_waiter); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_redirector_prrw_destroy(mk_lib_net_redirector_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_redirector_driven_target_data_prrw_destroy(&redirector->m_driven_target); mk_lang_check_rereturn(err);
	mk_lang_assert((redirector->m_iocp = mk_lang_null, mk_lang_true));
	err = mk_lib_net_redirector_listeners_rw_destroy(&redirector->m_listeners); mk_lang_check_rereturn(err);
	//err = mk_lib_net_redirector_dyn_events_rw_destroy(&redirector->m_waiting_to_connect); mk_lang_check_rereturn(err);
	//err = mk_lib_net_redirector_waiter_prrw_destroy(&redirector->m_waiter); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_redirector_prrw_set_iocp(mk_lib_net_redirector_redirector_pt const redirector, mk_lib_net_iocp_pt const iocp) mk_lang_noexcept
{
	mk_lang_assert(redirector);
	mk_lang_assert(iocp);
	mk_lang_assert(!redirector->m_iocp);

	redirector->m_iocp = iocp;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_redirector_prrw_add_redirect(mk_lib_net_redirector_redirector_pt const redirector, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_listener_pt listener;
	mk_lib_net_redirector_listener_pt tmp;

	mk_lang_assert(redirector);
	mk_lang_assert(src);
	mk_lang_assert(dst);

	err = mk_lib_net_redirector_listeners_rw_reserve_additional(&redirector->m_listeners, 1); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_listener_prrw_allocate(&listener); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_listener_prrw_construct(listener, redirector->m_iocp, src, dst); mk_lang_check_rereturn(err); tmp = listener;
	err = mk_lib_net_redirector_listeners_rw_push_back_move_single(&redirector->m_listeners, &listener); mk_lang_check_rereturn(err); listener = tmp;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_redirector_prrw_on_end(mk_lib_net_redirector_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_assert(redirector);

	//mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_redirector_prrw_on_timer(mk_lib_net_redirector_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_assert(redirector);

	//mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_redirector_prrw_on_iop(mk_lib_net_redirector_redirector_pt const redirector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_assert(redirector);
	mk_lang_assert(iop);

	mk_lang_check_todo();
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lib_net_redirector_redirector_pt mk_lib_net_redirector_driven_target_logic_prrw_cast_to_redirector(mk_lib_net_redirector_driven_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_redirector_redirector_pt obj;

	/* natvis */
	mk_lang_static_assert
	(
		mk_lang_offsetof(mk_lib_net_redirector_redirector_t, m_driven_target) ==
		0
	);

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_driven_target_data_id_e_dummy_end);

	if(target->m_id == mk_lib_net_redirector_driven_target_data_id_e_redirector)
	{
		offset = mk_lang_offsetof(mk_lib_net_redirector_redirector_t, m_driven_target);
		obj = ((mk_lib_net_redirector_redirector_pt)(((mk_lang_types_uchar_pt)(target)) - offset));
		return obj;
	}
	else
	{
		return mk_lang_null;
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driven_target_logic_prrw_on_end(mk_lib_net_redirector_driven_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_driven_target_data_id_e_dummy_end);

	switch(target->m_id)
	{
		case mk_lib_net_redirector_driven_target_data_id_e_redirector: { mk_lib_net_redirector_redirector_pt obj; obj = mk_lib_net_redirector_driven_target_logic_prrw_cast_to_redirector(target); mk_lang_assert(obj); err = mk_lib_net_redirector_redirector_prrw_on_end(obj); mk_lang_check_rereturn(err); } break;
		case mk_lib_net_redirector_driven_target_data_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driven_target_logic_prrw_on_timer(mk_lib_net_redirector_driven_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_driven_target_data_id_e_dummy_end);

	switch(target->m_id)
	{
		case mk_lib_net_redirector_driven_target_data_id_e_redirector: { mk_lib_net_redirector_redirector_pt obj; obj = mk_lib_net_redirector_driven_target_logic_prrw_cast_to_redirector(target); mk_lang_assert(obj); err = mk_lib_net_redirector_redirector_prrw_on_timer(obj); mk_lang_check_rereturn(err); } break;
		case mk_lib_net_redirector_driven_target_data_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driven_target_logic_prrw_on_iop(mk_lib_net_redirector_driven_target_data_pt const target, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(target);
	mk_lang_assert(iop);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_redirector_driven_target_data_id_e_dummy_end);

	switch(target->m_id)
	{
		case mk_lib_net_redirector_driven_target_data_id_e_redirector: { mk_lib_net_redirector_redirector_pt obj; obj = mk_lib_net_redirector_driven_target_logic_prrw_cast_to_redirector(target); mk_lang_assert(obj); err = mk_lib_net_redirector_redirector_prrw_on_iop(obj, iop); mk_lang_check_rereturn(err); } break;
		case mk_lib_net_redirector_driven_target_data_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_redirector_driver_s
{
	mk_lib_net_iocp_t m_iocp;
	mk_win_base_handle_t m_queue;
	mk_win_base_handle_t m_timer;
	mk_lang_types_bool_t m_want_end_a;
	mk_lang_types_bool_t m_want_end_b;
	mk_lib_net_redirector_driven_target_data_pt m_driven_target;
};
typedef struct mk_lib_net_redirector_driver_s mk_lib_net_redirector_driver_t;
mk_lang_typedef(mk_lib_net_redirector_driver);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_allocate(mk_lib_net_redirector_driver_ppt const driver) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_driver_pt obj;
	mk_lang_types_void_pt mem;

	mk_lang_assert(driver);

	err = mk_sl_mallocator_allocate(sizeof(*obj), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
	obj = ((mk_lib_net_redirector_driver_pt)(mem)); mk_lang_assert(obj);
	*driver = obj;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_deallocate(mk_lib_net_redirector_driver_ppt const driver) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(driver);
	mk_lang_assert(*driver);

	err = mk_sl_mallocator_deallocate(*driver, sizeof(**driver)); mk_lang_check_rereturn(err);
	mk_lang_assert((*driver = mk_lang_null, mk_lang_true));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_construct(mk_lib_net_redirector_driver_pt const driver) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(driver);

	err = mk_lib_net_iocp_construct(&driver->m_iocp, 0); mk_lang_check_rereturn(err);
	driver->m_queue = mk_win_dll_kernel_synchronization_timer_queue_create_timer_queue(); mk_lang_check_return(!mk_win_base_handle_is_null(driver->m_timer));
	mk_lang_assert((driver->m_timer = mk_win_base_handle_get_null(), mk_lang_true));
	driver->m_want_end_a = mk_lang_false;
	driver->m_want_end_b = mk_lang_false;
	mk_lang_assert((driver->m_driven_target = mk_lang_null, mk_lang_true));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_destroy(mk_lib_net_redirector_driver_pt const driver) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_win_base_bool_t b;

	mk_lang_assert(driver);

	err = mk_lib_net_iocp_destroy(&driver->m_iocp); mk_lang_check_rereturn(err);
	b = mk_win_dll_kernel_synchronization_timer_queue_delete_timer_queue(driver->m_queue); mk_lang_check_return(b != mk_win_base_false);
	mk_lang_assert((driver->m_timer = mk_win_base_handle_get_null(), mk_lang_true));
	mk_lang_assert((driver->m_want_end_a = mk_lang_false, mk_lang_true));
	mk_lang_assert((driver->m_want_end_b = mk_lang_false, mk_lang_true));
	mk_lang_assert((driver->m_driven_target = mk_lang_null, mk_lang_true));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_set_target(mk_lib_net_redirector_driver_pt const driver, mk_lib_net_redirector_driven_target_data_pt const driven_target) mk_lang_noexcept
{
	mk_lang_assert(driver);
	mk_lang_assert(driven_target);
	mk_lang_assert(!driver->m_driven_target);

	driver->m_driven_target = driven_target;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_kill_timer(mk_lib_net_redirector_driver_pt const driver) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(driver);
	mk_lang_assert(!mk_win_base_handle_is_null(driver->m_queue));
	mk_lang_assert(!mk_win_base_handle_is_null(driver->m_timer));

	b = mk_win_dll_kernel_synchronization_timer_queue_delete_timer_queue_timer(driver->m_queue, driver->m_timer, mk_win_base_handle_get_invalid()); mk_lang_check_return(b != mk_win_base_false);
	mk_lang_assert((driver->m_timer = mk_win_base_handle_get_null(), mk_lang_true));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_on_timer(mk_lib_net_redirector_driver_pt const driver) mk_lang_noexcept
{
	mk_lib_net_iocp_pt iocp;
	mk_lang_types_sint_t bytes_transferred;
	mk_lang_types_uintptr_t key;
	mk_lang_types_void_pt overlapped;
	mk_lang_types_sint_t err;

	mk_lang_assert(driver);

	iocp = &driver->m_iocp;
	bytes_transferred = 0;
	key = ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special));
	overlapped = ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_timer))));
	err = mk_lib_net_iocp_post(iocp, bytes_transferred, key, overlapped); mk_lang_check_rereturn(err);
	return 0;
}

static mk_lang_types_void_t mk_win_base_stdcall mk_lib_net_redirector_driver_prrw_on_win_timer(mk_win_base_void_lpt const parameter, mk_win_base_boolean_t const timer_or_wait_fired) mk_lang_noexcept
{
	mk_lib_net_redirector_driver_pt redirector;
	mk_lang_types_sint_t err;

	mk_lang_assert(parameter);
	mk_lang_assert(timer_or_wait_fired == mk_win_base_true);

	redirector = ((mk_lib_net_redirector_driver_pt)(parameter)); mk_lang_assert(redirector);
	err = mk_lib_net_redirector_driver_prrw_on_timer(redirector); mk_lang_check_recrash(err);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_request_timer(mk_lib_net_redirector_driver_pt const driver) mk_lang_noexcept
{
	mk_win_base_bool_t b;

	mk_lang_assert(driver);
	mk_lang_assert(!mk_win_base_handle_is_null(driver->m_queue));
	mk_lang_assert(mk_win_base_handle_is_null(driver->m_timer));

	b = mk_win_dll_kernel_synchronization_timer_queue_create_timer_queue_timer(&driver->m_timer, driver->m_queue, &mk_lib_net_redirector_driver_prrw_on_win_timer, driver, 1000, 0, mk_win_dll_kernel_synchronization_timer_queue_flag_d_execute_only_once | mk_win_dll_kernel_synchronization_timer_queue_flag_d_execute_in_timer_thread); mk_lang_check_return(b != mk_win_base_false); mk_lang_check_return(!mk_win_base_handle_is_null(driver->m_timer));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_dispatch_me_end(mk_lib_net_redirector_driver_pt const driver, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(driver);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special)));
	mk_lang_assert(iop->m_successful_io_operation);
	mk_lang_assert(iop->m_overlapped == ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_end)))));

	err = mk_lib_net_redirector_driven_target_logic_prrw_on_end(driver->m_driven_target); mk_lang_check_rereturn(err);
	driver->m_want_end_a = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_dispatch_me_timer(mk_lib_net_redirector_driver_pt const driver, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(driver);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special)));
	mk_lang_assert(iop->m_successful_io_operation);
	mk_lang_assert(iop->m_overlapped == ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_timer)))));

	err = mk_lib_net_redirector_driver_prrw_kill_timer(driver); mk_lang_check_rereturn(err);
	if(!driver->m_want_end_a)
	{
		err = mk_lib_net_redirector_driven_target_logic_prrw_on_timer(driver->m_driven_target); mk_lang_check_rereturn(err);
		err = mk_lib_net_redirector_driver_prrw_request_timer(driver); mk_lang_check_rereturn(err);
	}
	else
	{
		driver->m_want_end_b = mk_lang_true;
		err = mk_lang_stdout_no_redirect_println_n(mk_lang_str_lit("Exiting.")); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_dispatch_me(mk_lib_net_redirector_driver_pt const driver, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(driver);
	mk_lang_assert(iop);
	mk_lang_assert(iop->m_dequeued);
	mk_lang_assert(iop->m_key == ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special)));
	mk_lang_assert(iop->m_successful_io_operation);

	if(mk_lang_runtime_bool_fn_false){}
	else if(iop->m_overlapped == ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_end  ))))){ err = mk_lib_net_redirector_driver_prrw_dispatch_me_end  (driver, iop); mk_lang_check_rereturn(err); }
	else if(iop->m_overlapped == ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_timer))))){ err = mk_lib_net_redirector_driver_prrw_dispatch_me_timer(driver, iop); mk_lang_check_rereturn(err); }
	else{ mk_lang_assert_false(); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_dispatch(mk_lib_net_redirector_driver_pt const driver, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lib_net_redirector_iop_target_data_pt target;
	mk_lang_types_sint_t err;

	mk_lang_assert(driver);
	mk_lang_assert(iop);

	if(iop->m_dequeued)
	{
		if(iop->m_key == ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special)))
		{
			err = mk_lib_net_redirector_driver_prrw_dispatch_me(driver, iop); mk_lang_check_rereturn(err);
		}
		else
		{
			target = ((mk_lib_net_redirector_iop_target_data_pt)(iop->m_key));
			err = mk_lib_net_redirector_iop_target_logic_prrw_on_iop(target, iop); mk_lang_check_rereturn(err);
		}
	}
	else
	{
		mk_lang_check_todo();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_drive(mk_lib_net_redirector_driver_pt const driver) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_iocp_iop_t iop;

	mk_lang_assert(driver);
	mk_lang_assert(driver->m_driven_target);

	err = mk_lib_net_redirector_driver_prrw_request_timer(driver); mk_lang_check_rereturn(err);
	do
	{
		err = mk_lib_net_iocp_dequeue_packet_infinite(&driver->m_iocp, &iop.m_dequeued, &iop.m_successful_io_operation, &iop.m_bytes_transferred, &iop.m_key, &iop.m_overlapped, &iop.m_fail_reason); mk_lang_check_rereturn(err);
		err = mk_lib_net_redirector_driver_prrw_dispatch(driver, &iop); mk_lang_check_rereturn(err);
	}while(!driver->m_want_end_b);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_driver_prrw_request_stop(mk_lib_net_redirector_driver_pt const driver) mk_lang_noexcept
{
	mk_lib_net_iocp_pt iocp;
	mk_lang_types_sint_t bytes_transferred;
	mk_lang_types_uintptr_t key;
	mk_lang_types_void_pt overlapped;
	mk_lang_types_sint_t err;

	mk_lang_assert(driver);

	iocp = &driver->m_iocp;
	bytes_transferred = 0;
	key = ((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_key_special));
	overlapped = ((mk_lang_types_void_pt)(((mk_lang_types_uintptr_t)(mk_lib_net_redirector_k_iocp_overlapped_special_end))));
	err = mk_lib_net_iocp_post(iocp, bytes_transferred, key, overlapped); mk_lang_check_rereturn(err);
	return 0;
}


struct mk_lib_net_redirector_impl_s
{
	mk_lib_net_redirector_driver_t m_driver;
	mk_lib_net_redirector_redirector_t m_redirector;
};
typedef struct mk_lib_net_redirector_impl_s mk_lib_net_redirector_impl_t;
mk_lang_typedef(mk_lib_net_redirector_impl);


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_allocate(mk_lib_net_redirector_impl_ppt const impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_net_redirector_impl_pt obj;
	mk_lang_types_void_pt mem;

	mk_lang_assert(impl);

	err = mk_sl_mallocator_allocate(sizeof(*obj), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem);
	obj = ((mk_lib_net_redirector_impl_pt)(mem)); mk_lang_assert(obj);
	*impl = obj;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_deallocate(mk_lib_net_redirector_impl_ppt const impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(impl);
	mk_lang_assert(*impl);

	err = mk_sl_mallocator_deallocate(*impl, sizeof(**impl)); mk_lang_check_rereturn(err);
	mk_lang_assert((*impl = mk_lang_null, mk_lang_true));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_construct(mk_lib_net_redirector_impl_pt const impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(impl);

	err = mk_lib_net_redirector_driver_prrw_construct(&impl->m_driver); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_redirector_prrw_construct(&impl->m_redirector); mk_lang_check_rereturn(err);

	err = mk_lib_net_redirector_driver_prrw_set_target(&impl->m_driver, &impl->m_redirector.m_driven_target); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_redirector_prrw_set_iocp(&impl->m_redirector, &impl->m_driver.m_iocp); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_destroy(mk_lib_net_redirector_impl_pt const impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(impl);

	err = mk_lib_net_redirector_driver_prrw_destroy(&impl->m_driver); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_redirector_prrw_destroy(&impl->m_redirector); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_run(mk_lib_net_redirector_impl_pt const impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(impl);

	err = mk_lib_net_redirector_driver_prrw_drive(&impl->m_driver); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_request_stop(mk_lib_net_redirector_impl_pt const impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(impl);

	err = mk_lib_net_redirector_driver_prrw_request_stop(&impl->m_driver); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_impl_prrw_add_redirect(mk_lib_net_redirector_impl_pt const impl, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(impl);
	mk_lang_assert(src);
	mk_lang_assert(dst);

	err = mk_lib_net_redirector_redirector_prrw_add_redirect(&impl->m_redirector, src, dst); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_prrw_construct(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);

	err = mk_lib_net_redirector_impl_prrw_allocate(&redirector->m_impl); mk_lang_check_rereturn(err);
	err = mk_lib_net_redirector_impl_prrw_construct(redirector->m_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_prrw_destroy(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);
	mk_lang_assert(redirector->m_impl);

	err = mk_lib_net_redirector_impl_prrw_destroy(redirector->m_impl); mk_lang_check_rereturn(err); mk_lang_assert(redirector->m_impl);
	err = mk_lib_net_redirector_impl_prrw_deallocate(&redirector->m_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_prrw_run(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);
	mk_lang_assert(redirector->m_impl);

	err = mk_lib_net_redirector_impl_prrw_run(redirector->m_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_prrw_request_stop(mk_lib_net_redirector_pt const redirector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);
	mk_lang_assert(redirector->m_impl);

	err = mk_lib_net_redirector_impl_prrw_request_stop(redirector->m_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_prrw_add_redirect(mk_lib_net_redirector_pt const redirector, mk_lib_net_destination_pct const src, mk_lib_net_destination_pct const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(redirector);
	mk_lang_assert(src);
	mk_lang_assert(dst);

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
