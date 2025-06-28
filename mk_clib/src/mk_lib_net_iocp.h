#ifndef mk_include_guard_mk_lib_net_iocp_h
#define mk_include_guard_mk_lib_net_iocp_h


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


struct mk_lib_net_iocp_s
{
	mk_win_dll_ws2_t m_handle;
};
typedef struct mk_lib_net_iocp_s mk_lib_net_iocp_t;
mk_lang_typedef(mk_lib_net_iocp);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_construct_void(mk_lib_net_iocp_socket_pt const socket) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_construct(mk_lib_net_iocp_socket_pt const socket, mk_lib_net_iocp_address_family_t const af, mk_lib_net_iocp_address_type_t const at, mk_lib_net_iocp_address_protocol_t const ap) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_reconstruct(mk_lib_net_iocp_socket_pt const socket, mk_lib_net_iocp_address_family_t const af, mk_lib_net_iocp_address_type_t const at, mk_lib_net_iocp_address_protocol_t const ap) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_destroy(mk_lib_net_iocp_socket_pt const socket) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_to_text(mk_lib_net_iocp_socket_pt const socket, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_set_option_nodelay_val(mk_lib_net_iocp_socket_pt const socket, mk_lang_types_bool_t const val) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_set_option_nodelay_true(mk_lib_net_iocp_socket_pt const socket) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_set_option_nodelay_false(mk_lib_net_iocp_socket_pt const socket) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_associate_async_connect(mk_lib_net_iocp_socket_pt const socket, mk_lib_net_iocp_async_connect_pt const async_connect) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_associate_async_rwc(mk_lib_net_iocp_socket_pt const socket, mk_lib_net_iocp_async_rwc_pt const async_rwc) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_connect(mk_lib_net_iocp_socket_pt const socket, mk_lib_net_iocp_destination_pct const destination) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_send(mk_lib_net_iocp_socket_pt const socket, mk_lib_net_iocp_write_request_pt const write_request) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_iocp_socket_recv(mk_lib_net_iocp_socket_pt const socket, mk_lib_net_iocp_read_request_pt const read_request) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_iocp.c"
#endif
#endif
