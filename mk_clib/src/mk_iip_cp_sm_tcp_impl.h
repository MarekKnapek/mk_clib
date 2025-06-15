#ifndef mk_include_guard_mk_iip_cp_sm_tcp_impl_h
#define mk_include_guard_mk_iip_cp_sm_tcp_impl_h


#include "mk_iip_cp_client_data.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_type.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#define mk_sl_ring_dynamic_t_name mk_iip_cp_sm_tcp_impl_vec
#define mk_sl_ring_dynamic_t_element mk_sl_cui_uint8_t
#define mk_sl_ring_dynamic_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_ring_dynamic_inl_fileh.h"
#include "mk_sl_ring_dynamic_inl_fileu.h"


mk_lang_struct_forward(mk_iip_cp_message);
mk_lang_struct_forward(mk_iip_cp_sm_tcp_intr);
mk_lang_struct_forward(mk_iip_cp_type_sessionid);


enum mk_iip_cp_sm_tcp_impl_state_e
{
	mk_iip_cp_sm_tcp_impl_state_e_fresh,
	mk_iip_cp_sm_tcp_impl_state_e_ready,
	mk_iip_cp_sm_tcp_impl_state_e_dummy_end
};
typedef enum mk_iip_cp_sm_tcp_impl_state_e mk_iip_cp_sm_tcp_impl_state_t;

struct mk_iip_cp_sm_tcp_impl_s
{
	mk_iip_cp_sm_tcp_intr_pt m_self_intr;
	mk_iip_cp_type_sessionid_pct m_session_id;
	mk_iip_cp_type_destination_elgamal_dsa_pct m_local_destination;
	mk_iip_cp_client_data_request_accept_pct m_accept_request;
	mk_iip_cp_client_data_response_accept_pt m_accept_response;
	mk_iip_cp_client_data_request_read_data_pct m_read_data_request;
	mk_iip_cp_client_data_response_read_data_pt m_read_data_response;
	mk_lang_types_bool_t m_did_something;
	mk_iip_cp_sm_tcp_impl_state_t m_state;
	mk_lang_types_bool_t m_accepted;
	mk_lang_types_sint_t m_wanted_port;
	mk_lang_types_sint_t m_local_port;
	mk_lang_types_sint_t m_remote_port;
	mk_sl_cui_uint32_t m_local_stream_id;
	mk_sl_cui_uint32_t m_remote_stream_id;
	mk_sl_cui_uint32_t m_sequence_number;
	mk_iip_cp_type_buffer_t m_remote_destination_blob;
	mk_iip_cp_type_destination_with_cert_t m_remote_destination_structured;
	mk_lang_types_bool_t m_has_message_to_end;
	mk_iip_cp_type_messageid_t m_message_id_to_end;
	mk_lang_types_bool_t m_want_ack;
	mk_lang_types_bool_t m_has_message_sent;
	mk_sl_cui_uint32_t m_message_nonce_sent;
	mk_iip_cp_sm_tcp_impl_vec_t m_data_rcv;
	mk_iip_cp_sm_tcp_impl_vec_t m_data_snd;
};
typedef struct mk_iip_cp_sm_tcp_impl_s mk_iip_cp_sm_tcp_impl_t;
mk_lang_struct_typedef(mk_iip_cp_sm_tcp_impl);


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_allocate(mk_iip_cp_sm_tcp_impl_ppt const sm_tcp_impl) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_deallocate(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_construct(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_sm_tcp_intr_pt const sessioncmd_tcp_intr) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_destruct(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_allocate_and_construct(mk_iip_cp_sm_tcp_impl_ppt const sm_tcp_impl, mk_iip_cp_sm_tcp_intr_pt const sessioncmd_tcp_intr) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_destruct_and_deallocate(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_set_session_id(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_type_sessionid_pct const session_id) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_set_local_destination(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_type_destination_elgamal_dsa_pct const local_destination) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_set_wanted_port(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_sl_cui_uint16_pct const wanted_port) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_set_accept_rr(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_client_data_request_accept_pct const request, mk_iip_cp_client_data_response_accept_pt const response) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_set_read_data_rr(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_client_data_request_read_data_pct const request, mk_iip_cp_client_data_response_read_data_pt const response) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_sessionid_pct mk_iip_cp_sm_tcp_impl_rw_get_session_id(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept;

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_sm_tcp_impl_rw_did_something(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_on_msg(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_make_msg(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_message_pt const message) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_tick_single(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_iip_cp_sm_tcp_impl.c"
#endif
#endif
