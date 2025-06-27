#ifndef mk_include_guard_mk_lib_net_h
#define mk_include_guard_mk_lib_net_h


#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"
#include "mk_win_dll_ws2.h"


enum mk_lib_net_address_family_e
{
	mk_lib_net_address_family_e_ipv4,
	mk_lib_net_address_family_e_ipv6,
	mk_lib_net_address_family_e_dummy_end
};
typedef enum mk_lib_net_address_family_e mk_lib_net_address_family_t;
mk_lang_typedef(mk_lib_net_address_family);

enum mk_lib_net_address_type_e
{
	mk_lib_net_address_type_e_stream,
	mk_lib_net_address_type_e_dgram,
	mk_lib_net_address_type_e_dummy_end
};
typedef enum mk_lib_net_address_type_e mk_lib_net_address_type_t;
mk_lang_typedef(mk_lib_net_address_type);

enum mk_lib_net_address_protocol_e
{
	mk_lib_net_address_protocol_e_tcp,
	mk_lib_net_address_protocol_e_udp,
	mk_lib_net_address_protocol_e_icmp,
	mk_lib_net_address_protocol_e_dummy_end
};
typedef enum mk_lib_net_address_protocol_e mk_lib_net_address_protocol_t;
mk_lang_typedef(mk_lib_net_address_protocol);


#define mk_sl_cui_t_name mk_lib_net_tcp_port
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint16
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint16_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_net_tcp_port_size_bits_d mk_sl_cui_uint16_size_bits_d
#define mk_lib_net_tcp_port_size_bytes_d (mk_sl_cui_uint16_size_bits_d / mk_lang_charbit)

#define mk_sl_cui_t_name mk_lib_net_udp_port
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint16
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint16_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_lib_net_udp_port_size_bits_d mk_sl_cui_uint16_size_bits_d
#define mk_lib_net_udp_port_size_bytes_d (mk_sl_cui_uint16_size_bits_d / mk_lang_charbit)


union mk_lib_net_ipv4_address_data_u
{
	mk_sl_cui_uint32_t m_u32;
	mk_sl_cui_uint16_t m_u16s[((mk_lang_types_sint_t)(mk_sl_cui_uint32_size_bytes_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint16_size_bytes_v))];
	mk_sl_cui_uint8_t m_u8s[((mk_lang_types_sint_t)(mk_sl_cui_uint32_size_bytes_v)) / ((mk_lang_types_sint_t)(mk_sl_cui_uint8_size_bytes_v))];
};
typedef union mk_lib_net_ipv4_address_data_u mk_lib_net_ipv4_address_data_t;
struct mk_lib_net_ipv4_address_s
{
	mk_lib_net_ipv4_address_data_t m_data;
};
typedef struct mk_lib_net_ipv4_address_s mk_lib_net_ipv4_address_t;
mk_lang_typedef(mk_lib_net_ipv4_address);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_destination_s
{
	mk_lib_net_ipv4_address_t m_ipv4_address;
	mk_lib_net_tcp_port_t m_tcp_port;
};
typedef struct mk_lib_net_destination_s mk_lib_net_destination_t;
mk_lang_typedef(mk_lib_net_destination);
#include "mk_lang_warning_msvc_pop.h"

struct mk_lib_net_socket_s
{
	mk_win_dll_ws2_socket_t m_handle;
};
typedef struct mk_lib_net_socket_s mk_lib_net_socket_t;
mk_lang_typedef(mk_lib_net_socket);

struct mk_lib_net_async_connect_s
{
	mk_win_dll_ws2_event_t m_event;
	mk_lib_net_socket_pt m_socket;
};
typedef struct mk_lib_net_async_connect_s mk_lib_net_async_connect_t;
mk_lang_typedef(mk_lib_net_async_connect);

struct mk_lib_net_async_rwc_s
{
	mk_win_dll_ws2_event_t m_event;
	mk_lib_net_socket_pt m_socket;
};
typedef struct mk_lib_net_async_rwc_s mk_lib_net_async_rwc_t;
mk_lang_typedef(mk_lib_net_async_rwc);

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_write_request_s
{
	mk_lib_net_socket_pt m_socket;
	mk_sl_cui_uint8_pct m_data_buf;
	mk_lang_types_sint_t m_data_len;
	mk_lang_types_uint_t m_flags;
	mk_lang_types_bool_t m_b;
	mk_lang_types_sint_t m_transferred;
	mk_win_dll_ws2_overlapped_t m_overlapped;
};
typedef struct mk_lib_net_write_request_s mk_lib_net_write_request_t;
mk_lang_typedef(mk_lib_net_write_request);
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_read_request_s
{
	mk_lib_net_socket_pt m_socket;
	mk_sl_cui_uint8_pt m_data_buf;
	mk_lang_types_sint_t m_data_len;
	mk_lang_types_uint_t m_flags;
	mk_lang_types_bool_t m_b;
	mk_lang_types_sint_t m_transferred;
	mk_win_dll_ws2_overlapped_t m_overlapped;
};
typedef struct mk_lib_net_read_request_s mk_lib_net_read_request_t;
mk_lang_typedef(mk_lib_net_read_request);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_tcp_port_parse_pc(mk_lib_net_tcp_port_pt const tcp_port, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_tcp_port_parse_u8(mk_lib_net_tcp_port_pt const tcp_port, mk_sl_cui_uint8_pct const bin_buf, mk_lang_types_sint_t const bin_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_udp_port_parse_pc(mk_lib_net_udp_port_pt const udp_port, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_udp_port_parse_u8(mk_lib_net_udp_port_pt const udp_port, mk_sl_cui_uint8_pct const bin_buf, mk_lang_types_sint_t const bin_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ipv4_address_parse_pc(mk_lib_net_ipv4_address_pt const ipv4_address, mk_lang_types_pchar_pct const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_ipv4_address_parse_u8(mk_lib_net_ipv4_address_pt const ipv4_address, mk_sl_cui_uint8_pct const bin_buf, mk_lang_types_sint_t const bin_len, mk_lang_types_bool_pt const success, mk_lang_types_sint_pt const consumed) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_net_ipv4_address_is_any(mk_lib_net_ipv4_address_pct const ipv4_address) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_net_ipv4_address_is_none(mk_lib_net_ipv4_address_pct const ipv4_address) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_deinit(mk_lang_types_void_t) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_construct_void(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_construct(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_reconstruct(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_destroy(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_is_ready(mk_lib_net_async_connect_pt const async_connect, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_wait_timeout(mk_lib_net_async_connect_pt const async_connect, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_wait_infinite(mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_connect_get_result(mk_lib_net_async_connect_pt const async_connect, mk_lang_types_sint_pt const result) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_construct(mk_lib_net_async_rwc_pt const async_rwc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_destroy(mk_lib_net_async_rwc_pt const async_rwc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_is_ready(mk_lib_net_async_rwc_pt const async_rwc, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_wait_timeout(mk_lib_net_async_rwc_pt const async_rwc, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_wait_infinite(mk_lib_net_async_rwc_pt const async_rwc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_async_rwc_get_result(mk_lib_net_async_rwc_pt const async_rwc, mk_lang_types_sint_pt const event_id, mk_lang_types_sint_pt const result) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_construct_void(mk_lib_net_write_request_pt const write_request) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_construct(mk_lib_net_write_request_pt const write_request, mk_lib_net_socket_pt const socket, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_reconstruct(mk_lib_net_write_request_pt const write_request, mk_lib_net_socket_pt const socket, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_destroy(mk_lib_net_write_request_pt const write_request) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_is_ready(mk_lib_net_write_request_pt const write_request, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_wait_timeout(mk_lib_net_write_request_pt const write_request, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_wait_infinite(mk_lib_net_write_request_pt const write_request) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_write_request_get_result(mk_lib_net_write_request_pt const write_request) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_construct_void(mk_lib_net_read_request_pt const read_request) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_construct(mk_lib_net_read_request_pt const read_request, mk_lib_net_socket_pt const socket, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_reconstruct(mk_lib_net_read_request_pt const read_request, mk_lib_net_socket_pt const socket, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_destroy(mk_lib_net_read_request_pt const read_request) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_is_ready(mk_lib_net_read_request_pt const read_request, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_wait_timeout(mk_lib_net_read_request_pt const read_request, mk_lang_types_sint_t const ms, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_wait_infinite(mk_lib_net_read_request_pt const read_request) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_read_request_get_result(mk_lib_net_read_request_pt const read_request) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_construct_void(mk_lib_net_socket_pt const socket) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_construct(mk_lib_net_socket_pt const socket, mk_lib_net_address_family_t const af, mk_lib_net_address_type_t const at, mk_lib_net_address_protocol_t const ap) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_reconstruct(mk_lib_net_socket_pt const socket, mk_lib_net_address_family_t const af, mk_lib_net_address_type_t const at, mk_lib_net_address_protocol_t const ap) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_destroy(mk_lib_net_socket_pt const socket) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_to_text(mk_lib_net_socket_pt const socket, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_set_option_nodelay_val(mk_lib_net_socket_pt const socket, mk_lang_types_bool_t const val) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_set_option_nodelay_true(mk_lib_net_socket_pt const socket) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_set_option_nodelay_false(mk_lib_net_socket_pt const socket) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_associate_async_connect(mk_lib_net_socket_pt const socket, mk_lib_net_async_connect_pt const async_connect) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_associate_async_rwc(mk_lib_net_socket_pt const socket, mk_lib_net_async_rwc_pt const async_rwc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_connect(mk_lib_net_socket_pt const socket, mk_lib_net_destination_pct const destination) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_send(mk_lib_net_socket_pt const socket, mk_lib_net_write_request_pt const write_request) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_socket_recv(mk_lib_net_socket_pt const socket, mk_lib_net_read_request_pt const read_request) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net.c"
#endif
#endif
