#ifndef mk_include_guard_mk_iip_cp_client_data_h
#define mk_include_guard_mk_iip_cp_client_data_h


#include "mk_iip_cp_type.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_sl_net_windows.h"


mk_lang_struct_forward(mk_iip_cp_connection_intr);
mk_lang_struct_forward(mk_iip_cp_session_intr);
mk_lang_struct_forward(mk_iip_cp_socket_tcp_intr);
mk_lang_struct_forward(mk_iip_cp_type_destination_elgamal_dsa);


struct mk_iip_cp_client_data_request_generate_destination_s
{
	mk_iip_cp_type_destination_elgamal_dsa_pt m_destination;
};
typedef struct mk_iip_cp_client_data_request_generate_destination_s mk_iip_cp_client_data_request_generate_destination_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_generate_destination);

struct mk_iip_cp_client_data_response_generate_destination_s
{
	mk_iip_cp_type_destination_elgamal_dsa_pct m_destination;
};
typedef struct mk_iip_cp_client_data_response_generate_destination_s mk_iip_cp_client_data_response_generate_destination_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_generate_destination);


struct mk_iip_cp_client_data_request_connect_s
{
	mk_lang_types_pchar_pct m_ipv4_str_buf;
	mk_lang_types_sint_t m_ipv4_str_len;
	mk_lang_types_pchar_pct m_tcp_port_str_buf;
	mk_lang_types_sint_t m_tcp_port_str_len;
	mk_lang_types_pchar_pct m_username_str_buf;
	mk_lang_types_sint_t m_username_str_len;
	mk_lang_types_pchar_pct m_password_str_buf;
	mk_lang_types_sint_t m_password_str_len;
};
typedef struct mk_iip_cp_client_data_request_connect_s mk_iip_cp_client_data_request_connect_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_connect);

struct mk_iip_cp_client_data_response_connect_s
{
	mk_lang_types_bool_t m_done;
	mk_lang_types_bool_t m_success;
	mk_iip_cp_connection_intr_pt m_connection;
};
typedef struct mk_iip_cp_client_data_response_connect_s mk_iip_cp_client_data_response_connect_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_connect);


struct mk_iip_cp_client_data_request_connect_v2_s
{
	mk_iip_cp_client_data_request_connect_pct m_connect_v1;
	mk_sl_net_windows_socket_t m_socket;
};
typedef struct mk_iip_cp_client_data_request_connect_v2_s mk_iip_cp_client_data_request_connect_v2_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_connect_v2);

struct mk_iip_cp_client_data_response_connect_v2_s
{
	mk_iip_cp_client_data_response_connect_pt m_connect_v1;
};
typedef struct mk_iip_cp_client_data_response_connect_v2_s mk_iip_cp_client_data_response_connect_v2_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_connect_v2);


struct mk_iip_cp_client_data_request_connect_v3_s
{
	mk_iip_cp_client_data_request_connect_pct m_connect_v1;
};
typedef struct mk_iip_cp_client_data_request_connect_v3_s mk_iip_cp_client_data_request_connect_v3_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_connect_v3);

struct mk_iip_cp_client_data_response_connect_v3_s
{
	mk_iip_cp_client_data_response_connect_pt m_connect_v1;
};
typedef struct mk_iip_cp_client_data_response_connect_v3_s mk_iip_cp_client_data_response_connect_v3_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_connect_v3);


struct mk_iip_cp_client_data_request_connect_v4_s
{
	mk_iip_cp_client_data_request_connect_pct m_connect_v1;
};
typedef struct mk_iip_cp_client_data_request_connect_v4_s mk_iip_cp_client_data_request_connect_v4_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_connect_v4);

struct mk_iip_cp_client_data_response_connect_v4_s
{
	mk_iip_cp_client_data_response_connect_pt m_connect_v1;
};
typedef struct mk_iip_cp_client_data_response_connect_v4_s mk_iip_cp_client_data_response_connect_v4_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_connect_v4);


struct mk_iip_cp_client_data_request_connect_v5_send_protocol_byte_s
{
	mk_iip_cp_client_data_request_connect_pct m_connect_v1;
};
typedef struct mk_iip_cp_client_data_request_connect_v5_send_protocol_byte_s mk_iip_cp_client_data_request_connect_v5_send_protocol_byte_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_connect_v5_send_protocol_byte);

struct mk_iip_cp_client_data_response_connect_v5_send_protocol_byte_s
{
	mk_iip_cp_client_data_response_connect_pt m_connect_v1;
};
typedef struct mk_iip_cp_client_data_response_connect_v5_send_protocol_byte_s mk_iip_cp_client_data_response_connect_v5_send_protocol_byte_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_connect_v5_send_protocol_byte);


struct mk_iip_cp_client_data_request_connect_v6_wait_protocol_byte_s
{
	mk_iip_cp_client_data_request_connect_pct m_connect_v1;
};
typedef struct mk_iip_cp_client_data_request_connect_v6_wait_protocol_byte_s mk_iip_cp_client_data_request_connect_v6_wait_protocol_byte_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_connect_v6_wait_protocol_byte);

struct mk_iip_cp_client_data_response_connect_v6_wait_protocol_byte_s
{
	mk_iip_cp_client_data_response_connect_pt m_connect_v1;
};
typedef struct mk_iip_cp_client_data_response_connect_v6_wait_protocol_byte_s mk_iip_cp_client_data_response_connect_v6_wait_protocol_byte_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_connect_v6_wait_protocol_byte);


struct mk_iip_cp_client_data_request_create_session_s
{
	mk_iip_cp_connection_intr_pt m_connection;
	mk_iip_cp_type_destination_elgamal_dsa_pct m_destination;
	mk_lang_types_pchar_pct m_nickname_str_buf;
	mk_lang_types_sint_t m_nickname_str_len;
};
typedef struct mk_iip_cp_client_data_request_create_session_s mk_iip_cp_client_data_request_create_session_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_create_session);

struct mk_iip_cp_client_data_response_create_session_s
{
	mk_lang_types_bool_t m_done;
	mk_lang_types_bool_t m_success;
	mk_iip_cp_session_intr_pt m_session;
};
typedef struct mk_iip_cp_client_data_response_create_session_s mk_iip_cp_client_data_response_create_session_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_create_session);


struct mk_iip_cp_client_data_request_get_bandwidth_limits_s
{
	mk_iip_cp_connection_intr_pt m_connection;
	mk_iip_cp_type_bandwidth_limits_pt m_bandwidth_limits;
};
typedef struct mk_iip_cp_client_data_request_get_bandwidth_limits_s mk_iip_cp_client_data_request_get_bandwidth_limits_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_get_bandwidth_limits);

struct mk_iip_cp_client_data_response_get_bandwidth_limits_s
{
	mk_lang_types_bool_t m_done;
	mk_lang_types_bool_t m_success;
};
typedef struct mk_iip_cp_client_data_response_get_bandwidth_limits_s mk_iip_cp_client_data_response_get_bandwidth_limits_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_get_bandwidth_limits);


struct mk_iip_cp_client_data_request_host_lookup_s
{
	mk_iip_cp_connection_intr_pt m_connection;
	mk_iip_cp_session_intr_pt m_session;
	mk_iip_cp_type_string_pct m_hostname;
	mk_iip_cp_type_buffer_pt m_destination;
};
typedef struct mk_iip_cp_client_data_request_host_lookup_s mk_iip_cp_client_data_request_host_lookup_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_host_lookup);

struct mk_iip_cp_client_data_response_host_lookup_s
{
	mk_lang_types_bool_t m_done;
	mk_lang_types_bool_t m_success;
};
typedef struct mk_iip_cp_client_data_response_host_lookup_s mk_iip_cp_client_data_response_host_lookup_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_host_lookup);


struct mk_iip_cp_client_data_request_accept_s
{
	mk_iip_cp_connection_intr_pt m_connection;
	mk_iip_cp_session_intr_pt m_session;
	mk_iip_cp_socket_tcp_intr_pt m_socket;
	mk_iip_cp_type_buffer_pt m_remote_destination;
};
typedef struct mk_iip_cp_client_data_request_accept_s mk_iip_cp_client_data_request_accept_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_accept);

struct mk_iip_cp_client_data_response_accept_s
{
	mk_lang_types_bool_t m_done;
	mk_lang_types_bool_t m_success;
};
typedef struct mk_iip_cp_client_data_response_accept_s mk_iip_cp_client_data_response_accept_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_accept);


struct mk_iip_cp_client_data_request_read_data_s
{
	mk_iip_cp_connection_intr_pt m_connection;
	mk_iip_cp_session_intr_pt m_session;
	mk_iip_cp_socket_tcp_intr_pt m_socket;
	mk_iip_cp_type_buffer_pt m_payload;
};
typedef struct mk_iip_cp_client_data_request_read_data_s mk_iip_cp_client_data_request_read_data_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_read_data);

struct mk_iip_cp_client_data_response_read_data_s
{
	mk_lang_types_bool_t m_done;
	mk_lang_types_bool_t m_success;
};
typedef struct mk_iip_cp_client_data_response_read_data_s mk_iip_cp_client_data_response_read_data_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_read_data);


struct mk_iip_cp_client_data_request_send_data_s
{
	mk_iip_cp_connection_intr_pt m_connection;
	mk_iip_cp_session_intr_pt m_session;
	mk_iip_cp_type_buffer_pct m_destination;
	mk_iip_cp_type_buffer_pct m_payload;
};
typedef struct mk_iip_cp_client_data_request_send_data_s mk_iip_cp_client_data_request_send_data_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_request_send_data);

struct mk_iip_cp_client_data_response_send_data_s
{
	mk_lang_types_bool_t m_gud;
	mk_sl_cui_uint32_t m_nonce;
};
typedef struct mk_iip_cp_client_data_response_send_data_s mk_iip_cp_client_data_response_send_data_t;
mk_lang_struct_typedef(mk_iip_cp_client_data_response_send_data);


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_client_data.c"
#endif
#endif
