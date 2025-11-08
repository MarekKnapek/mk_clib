#ifndef mk_include_guard_mk_lib_net_listener_h
#define mk_include_guard_mk_lib_net_listener_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_net.h"


mk_lang_forward(mk_lib_net_destination);
mk_lang_forward(mk_lib_net_iocp);
mk_lang_forward(mk_sl_buffers_buffer);


#include "mk_lang_warning_msvc_push_c4820.h"
mk_lang_forward(mk_lib_net_listener_client);
struct mk_lib_net_listener_client_s
{
	mk_lib_net_listener_client_pt m_prev;
	mk_lib_net_listener_client_pt m_next;
	mk_lib_net_socket_t m_socket;
	mk_lib_net_destination_t m_local_address;
	mk_lib_net_destination_t m_remote_address;
	mk_sl_buffers_buffer_pt m_in_data_buf;
	mk_lang_types_sint_t m_in_data_len;
};
typedef struct mk_lib_net_listener_client_s mk_lib_net_listener_client_t;
mk_lang_typedef(mk_lib_net_listener_client);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_listener_iop_s
{
	mk_lang_types_bool_t m_dequeued;
	mk_lang_types_bool_t m_successful_io_operation;
	mk_lang_types_sint_t m_bytes_transferred;
	mk_lang_types_uint_t m_fail_reason;
	mk_lang_types_uintptr_t m_key;
	mk_lang_types_void_pt m_overlapped;
};
typedef struct mk_lib_net_listener_iop_s mk_lib_net_listener_iop_t;
mk_lang_typedef(mk_lib_net_listener_iop);
#include "mk_lang_warning_msvc_pop.h"


struct mk_lib_net_listener_s
{
	mk_lib_net_socket_t m_socket;
	mk_lib_net_listener_client_pt m_client;
	mk_lib_net_listener_client_pt m_last_given;
	mk_lang_types_void_pct m_fn_accept_ex;
	mk_lang_types_void_pct m_fn_get_accept_ex_sock_addrs;
	mk_lib_net_ioctl_request_t m_request_fn_accept_ex;
	mk_lib_net_ioctl_request_t m_request_fn_get_accept_ex_sock_addrs;
	mk_lib_net_accept_request_t m_request_accept;
	mk_lib_net_listener_client_pt m_clients_beg;
	mk_lib_net_listener_client_pt m_clients_end;
};
typedef struct mk_lib_net_listener_s mk_lib_net_listener_t;
mk_lang_typedef(mk_lib_net_listener);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_rw_construct_void(mk_lib_net_listener_pt const listener) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_rw_construct_from_destination(mk_lib_net_listener_pt const listener, mk_lib_net_iocp_pt const iocp, mk_lib_net_destination_pct const destination) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_rw_destroy(mk_lib_net_listener_pt const listener) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_rw_on_iop(mk_lib_net_listener_pt const listener, mk_lib_net_listener_iop_pct const iop) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_rw_get_client(mk_lib_net_listener_pt const listener, mk_lib_net_listener_client_ppt const client) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_listener_client_rw_destroy(mk_lib_net_listener_client_pt const client) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_listener.c"
#endif
#endif
