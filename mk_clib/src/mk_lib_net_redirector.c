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
#include "mk_lang_str_lit.h"
#include "mk_lang_types.h"
#include "mk_lib_net_buffers.h"
#include "mk_lib_net_iocp.h"
#include "mk_lib_net_listener.h"
#include "mk_sl_buffers.h"
#include "mk_sl_mallocator.h"
#include "mk_sl_vector_copy.h"
#include "mk_win_dll_kernel_handle.h"
#include "mk_win_dll_kernel_process.h"
#include "mk_win_dll_kernel_synchronization.h"
#include "mk_win_dll_kernel_synchronization_critical_section.h"
#include "mk_win_dll_kernel_synchronization_event.h"
#include "mk_win_dll_kernel_synchronization_timer_queue.h"


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
	client->m_recv_buffer = mk_lang_null;
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
	mk_lang_assert((((mk_lang_types_void_t)(&client->m_iop_target)), mk_lang_true));
	mk_lang_assert((client->m_pending_send = mk_lang_false, mk_lang_true));
	mk_lang_assert((client->m_pending_recv = mk_lang_false, mk_lang_true));
	mk_lang_assert((client->m_recv_buffer = mk_lang_null, mk_lang_true));
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
	mk_lang_assert((((mk_lang_types_void_t)(&connector->m_iop_target)), mk_lang_true));
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
	mk_lang_assert((((mk_lang_types_void_t)(&forwarder->m_iop_target)), mk_lang_true));
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_redirector_iop_target_logic_prrw_on_iop(mk_lib_net_redirector_iop_target_data_pt const target, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(target);
	mk_lang_assert(iop);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_forwarder_iop_target_data_id_e_dummy_end);

	switch(target->m_id)
	{
		case mk_lib_net_redirector_iop_target_data_id_e_client   : { mk_lib_net_redirector_client_pt    obj; obj = mk_lib_net_redirector_iop_target_logic_prrw_cast_to_client   (target); mk_lang_assert(obj); err = mk_lib_net_redirector_client_prrw_on_iop   (obj, iop); } break;
		case mk_lib_net_redirector_iop_target_data_id_e_connector: { mk_lib_net_redirector_connector_pt obj; obj = mk_lib_net_redirector_iop_target_logic_prrw_cast_to_connector(target); mk_lang_assert(obj); err = mk_lib_net_redirector_connector_prrw_on_iop(obj, iop); } break;
		case mk_lib_net_redirector_iop_target_data_id_e_forwarder: { mk_lib_net_redirector_forwarder_pt obj; obj = mk_lib_net_redirector_iop_target_logic_prrw_cast_to_forwarder(target); mk_lang_assert(obj); err = mk_lib_net_redirector_forwarder_prrw_on_iop(obj, iop); } break;
		case mk_lib_net_forwarder_iop_target_data_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


#endif
