#ifndef mk_include_guard_mk_lib_net_connector_h
#define mk_include_guard_mk_lib_net_connector_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_net.h"
#include "mk_lib_net_forwarder_iop_target_data.h"


mk_lang_forward(mk_lib_net_destination);
mk_lang_forward(mk_lib_net_iocp);
mk_lang_forward(mk_lib_net_iocp_iop);
mk_lang_forward(mk_sl_buffers_buffer);


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_connector_s
{
	mk_lib_net_socket_t m_socket;
	mk_lib_net_destination_t m_local_address;
	mk_lib_net_destination_t m_remote_address;
	mk_lib_net_forwarder_iop_target_data_t m_iop_target;
	mk_lang_types_void_pt m_user;
	mk_sl_buffers_buffer_pt m_in_data_buf;
	mk_lang_types_sint_t m_in_data_len;
	mk_lib_net_connect_request_t m_connect;
};
typedef struct mk_lib_net_connector_s mk_lib_net_connector_t;
mk_lang_typedef(mk_lib_net_connector);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connector_rw_construct(mk_lib_net_connector_pt const connector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connector_rw_destroy(mk_lib_net_connector_pt const connector) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connector_rw_connect_to_destination(mk_lib_net_connector_pt const connector, mk_lib_net_iocp_pt const iocp, mk_lib_net_destination_pct const destination) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_connector_rw_on_iop(mk_lib_net_connector_pt const connector, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_connector.c"
#endif
#endif
