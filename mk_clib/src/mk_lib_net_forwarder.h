#ifndef mk_include_guard_mk_lib_net_forwarder_h
#define mk_include_guard_mk_lib_net_forwarder_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_net_iocp.h"
#include "mk_sl_mallocator.h"
#include "mk_win_base.h"
#include "mk_win_dll_ws2.h"


mk_lang_forward(mk_lib_net_destination);
mk_lang_forward(mk_lib_net_listener);
mk_lang_forward(mk_lib_net_listener_client);


#define mk_sl_vector_t_name mk_lib_net_forwarder_listeners
#define mk_sl_vector_t_element_type mk_lib_net_listener_pt
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_fileu.h"

#define mk_sl_vector_t_name mk_lib_net_forwarder_clients
#define mk_sl_vector_t_element_type mk_lib_net_listener_client_pt
#define mk_sl_vector_t_mallocatorg mk_sl_mallocator
#include "mk_sl_vector_inl_fileh.h"
#include "mk_sl_vector_inl_fileu.h"


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_net_forwarder_s
{
	mk_lib_net_iocp_t m_iocp;
	mk_lang_types_bool_t m_want_stop;
	mk_lib_net_forwarder_listeners_t m_listeners;
	mk_lib_net_forwarder_clients_t m_clients;
	mk_win_dll_ws2_event_t m_event;
	mk_win_base_handle_t m_thread;
};
typedef struct mk_lib_net_forwarder_s mk_lib_net_forwarder_t;
mk_lang_typedef(mk_lib_net_forwarder);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_rw_construct(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_rw_destroy(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_rw_add_listener(mk_lib_net_forwarder_pt const forwarder, mk_lib_net_destination_pct const destination) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_rw_request_stop(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_rw_run(mk_lib_net_forwarder_pt const forwarder) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_net_forwarder.c"
#endif
#endif
