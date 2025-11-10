#ifndef mk_include_guard_mk_lib_net_forwarder_iop_target_logic_h
#define mk_include_guard_mk_lib_net_forwarder_iop_target_logic_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_lib_net_connector);
mk_lang_forward(mk_lib_net_forwarder_iop_target_data);
mk_lang_forward(mk_lib_net_iocp_iop);
mk_lang_forward(mk_lib_net_listener);
mk_lang_forward(mk_lib_net_listener_client);


mk_lang_nodiscard mk_lang_jumbo mk_lib_net_listener_pt mk_lib_net_forwarder_iop_target_logic_rw_cast_to_listener(mk_lib_net_forwarder_iop_target_data_pt const target) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lib_net_listener_client_pt mk_lib_net_forwarder_iop_target_logic_rw_cast_to_client(mk_lib_net_forwarder_iop_target_data_pt const target) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lib_net_connector_pt mk_lib_net_forwarder_iop_target_logic_rw_cast_to_connector(mk_lib_net_forwarder_iop_target_data_pt const target) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_iop_target_logic_rw_on_iop(mk_lib_net_forwarder_iop_target_data_pt const target, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_forwarder_iop_target_logic.c"
#endif
#endif
