#ifndef mk_include_guard_mk_iip_cp_sessioncmd_tcp_impl_c
#define mk_include_guard_mk_iip_cp_sessioncmd_tcp_impl_c
#include "mk_iip_cp_sessioncmd_tcp_impl.h"

#include "mk_iip_cp_client_data.h"
#include "mk_iip_cp_message.h"
#include "mk_iip_cp_packet_base.h"
#include "mk_iip_cp_packet_tcp.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_zlib.h"
#include "mk_sl_mallocatorg.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"


#define mk_sl_ring_dynamic_t_name mk_iip_cp_sessioncmd_tcp_impl_vec
#define mk_sl_ring_dynamic_t_element mk_sl_cui_uint8_t
#define mk_sl_ring_dynamic_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_ring_dynamic_inl_filec.h"
#include "mk_sl_ring_dynamic_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_pr_on_msg_message_payload(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl, mk_iip_cp_message_message_payload_pct const msg_message_payload) mk_lang_noexcept
{
	mk_sl_cui_uint16_t remote_port;
	mk_sl_cui_uint16_t local_port;
	mk_lang_types_sint_t protocol;
	mk_lang_types_sint_t err;
	mk_iip_cp_type_buffer_t decompressed;
	mk_iip_cp_packet_tcp_t packet;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t outlen;

	mk_lang_assert(sessioncmd_tcp_impl);
	mk_lang_assert(msg_message_payload);
	mk_lang_assert(sessioncmd_tcp_impl->m_session_id);
	mk_lang_assert(mk_sl_cui_uint16_eq(&msg_message_payload->m_session_id.m_id, &sessioncmd_tcp_impl->m_session_id->m_id));

	if(mk_iip_cp_packet_base_is_compressed_buf(&msg_message_payload->m_payload))
	{
		mk_sl_uint_16_from_8_be(&remote_port, &msg_message_payload->m_payload.m_buf[4]);
		mk_sl_uint_16_from_8_be(&local_port, &msg_message_payload->m_payload.m_buf[6]);
		mk_sl_cui_uint8_to_bi_sint(&msg_message_payload->m_payload.m_buf[9], &protocol);
		if(protocol == mk_iip_cp_packet_base_protocol_id_e_streaming)
		{
			err = mk_lib_zlib_decompress(&msg_message_payload->m_payload.m_buf[0], msg_message_payload->m_payload.m_len, &decompressed.m_buf[0], mk_lang_countof(decompressed.m_buf), &decompressed.m_len); mk_lang_check_rereturn(err);
			err = mk_iip_cp_packet_tcp_rw_construct(&packet); mk_lang_check_rereturn(err);
			err = mk_iip_cp_packet_tcp_rw_parse(&packet, &decompressed.m_buf[0], decompressed.m_len, &gud, &outlen); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(outlen == decompressed.m_len);
			if(mk_iip_cp_packet_tcp_ro_is_valid(&packet))
			{
				if(sessioncmd_tcp_impl->m_state == mk_iip_cp_sessioncmd_tcp_impl_state_e_listening && mk_iip_cp_packet_tcp_ro_is_initial_remote_syn(&packet))
				{
					mk_iip_cp_helper_generate_random_u32_non_zero(&sessioncmd_tcp_impl->m_local_stream_id);
					sessioncmd_tcp_impl->m_remote_stream_id = packet.m_remote_stream_id;
					err = mk_iip_cp_packet_tcp_ro_get_option_from_structured(&packet, &sessioncmd_tcp_impl->m_remote_destination_structured, &outlen); mk_lang_check_rereturn(err);
					mk_sl_cui_uint8_memcpy(&sessioncmd_tcp_impl->m_remote_destination_blob.m_buf[0], mk_iip_cp_packet_tcp_ro_get_option_from_blob_buf(&packet), mk_iip_cp_packet_tcp_ro_get_option_from_blob_len(&packet)); sessioncmd_tcp_impl->m_remote_destination_blob.m_len = mk_iip_cp_packet_tcp_ro_get_option_from_blob_len(&packet);
					/* todo validate signature, and do it sooner */
					err = mk_iip_cp_sessioncmd_tcp_impl_vec_rw_clear(&sessioncmd_tcp_impl->m_data_rcv); mk_lang_check_rereturn(err);
					err = mk_iip_cp_sessioncmd_tcp_impl_vec_rw_push_back_many(&sessioncmd_tcp_impl->m_data_rcv, mk_iip_cp_packet_tcp_ro_get_payload_buf(&packet), mk_iip_cp_packet_tcp_ro_get_payload_len(&packet)); mk_lang_check_rereturn(err);
					sessioncmd_tcp_impl->m_message_id_to_end = msg_message_payload->m_message_id;
					sessioncmd_tcp_impl->m_response->m_success = mk_lang_true;
					sessioncmd_tcp_impl->m_response->m_done = mk_lang_true;
					sessioncmd_tcp_impl->m_state = mk_iip_cp_sessioncmd_tcp_impl_state_e_submit_message_end;
					sessioncmd_tcp_impl->m_did_something = mk_lang_true;
				}
				else if(sessioncmd_tcp_impl->m_state == mk_iip_cp_sessioncmd_tcp_impl_state_e_ready && !mk_iip_cp_packet_tcp_ro_is_initial_remote_syn(&packet))
				{
					mk_lang_check_todo();
				}
				else
				{
					mk_lang_check_todo();
				}
			}
			else
			{
				mk_lang_check_todo(); /* bad header, bad format */
			}
			err = mk_iip_cp_packet_tcp_rw_destroy(&packet); mk_lang_check_rereturn(err);
		}
		else
		{
			/* not interested */
		}
	}
	else
	{
		mk_lang_check_todo(); /* not compressed, bad format */
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_allocate(mk_iip_cp_sessioncmd_tcp_impl_ppt const sessioncmd_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_tcp_impl);

	err = mk_sl_mallocatorg_allocate(sizeof(**sessioncmd_tcp_impl), ((mk_lang_types_void_ppt)(sessioncmd_tcp_impl))); mk_lang_check_rereturn(err); mk_lang_assert(*sessioncmd_tcp_impl);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_deallocate(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_tcp_impl);

	err = mk_sl_mallocatorg_deallocate(sessioncmd_tcp_impl, sizeof(*sessioncmd_tcp_impl)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_construct(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl, mk_iip_cp_sessioncmd_tcp_intr_pt const sessioncmd_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_tcp_impl);
	mk_lang_assert(sessioncmd_tcp_intr);

	sessioncmd_tcp_impl->m_sessioncmd_tcp_intr = sessioncmd_tcp_intr;
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_session_id));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_did_something));
	sessioncmd_tcp_impl->m_state = mk_iip_cp_sessioncmd_tcp_impl_state_e_listening;
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_remote_destination_blob));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_remote_destination_structured));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_remote_stream_id));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_local_stream_id));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_message_id_to_end));
	err = mk_iip_cp_sessioncmd_tcp_impl_vec_rw_construct(&sessioncmd_tcp_impl->m_data_rcv); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sessioncmd_tcp_impl_vec_rw_construct(&sessioncmd_tcp_impl->m_data_snd); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_socket));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_response));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_destruct(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_tcp_impl);

	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_sessioncmd_tcp_intr));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_session_id));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_did_something));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_state));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_remote_destination_blob));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_remote_destination_structured));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_remote_stream_id));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_local_stream_id));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_message_id_to_end));
	err = mk_iip_cp_sessioncmd_tcp_impl_vec_rw_destruct(&sessioncmd_tcp_impl->m_data_rcv); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sessioncmd_tcp_impl_vec_rw_destruct(&sessioncmd_tcp_impl->m_data_snd); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_socket));
	((mk_lang_types_void_t)(sessioncmd_tcp_impl->m_response));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_allocate_and_construct(mk_iip_cp_sessioncmd_tcp_impl_ppt const sessioncmd_tcp_impl, mk_iip_cp_sessioncmd_tcp_intr_pt const sessioncmd_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_tcp_impl);
	mk_lang_assert(sessioncmd_tcp_intr);

	err = mk_iip_cp_sessioncmd_tcp_impl_rw_allocate(sessioncmd_tcp_impl); mk_lang_check_rereturn(err); mk_lang_assert(*sessioncmd_tcp_impl);
	err = mk_iip_cp_sessioncmd_tcp_impl_rw_construct(*sessioncmd_tcp_impl, sessioncmd_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_destruct_and_deallocate(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_tcp_impl);

	err = mk_iip_cp_sessioncmd_tcp_impl_rw_destruct(sessioncmd_tcp_impl); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sessioncmd_tcp_impl_rw_deallocate(sessioncmd_tcp_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_set_session_id(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl, mk_iip_cp_type_sessionid_pct const session_id) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_tcp_impl);
	mk_lang_assert(session_id);

	sessioncmd_tcp_impl->m_session_id = session_id;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_set_socket(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl, mk_iip_cp_socket_tcp_intr_pt const socket) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_tcp_impl);
	mk_lang_assert(socket);

	sessioncmd_tcp_impl->m_socket = socket;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_set_response(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl, mk_iip_cp_client_data_response_accept_pt const response) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_tcp_impl);
	mk_lang_assert(response);

	sessioncmd_tcp_impl->m_response = response;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_sessionid_pct mk_iip_cp_sessioncmd_tcp_impl_rw_get_session_id(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl) mk_lang_noexcept
{
	mk_iip_cp_type_sessionid_pct ret;

	mk_lang_assert(sessioncmd_tcp_impl);

	ret = sessioncmd_tcp_impl->m_session_id;
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_sessioncmd_tcp_impl_rw_did_something(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(sessioncmd_tcp_impl);

	ret = sessioncmd_tcp_impl->m_did_something;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_on_msg(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_tcp_impl);
	mk_lang_assert(message);

	sessioncmd_tcp_impl->m_did_something = mk_lang_false;
	switch(message->m_header.m_type)
	{
		case mk_iip_cp_message_message_type_e_create_session            : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_reconfigure_session       : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_destroy_session           : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_create_lease_set          : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_send_message              : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_receive_message_begin     : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_receive_message_end       : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_get_bandwidth_limits      : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_session_status            : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_request_lease_set         : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_message_status            : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_bandwidth_limits          : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_report_abuse              : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_disconnect                : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_message_payload           : err = mk_iip_cp_sessioncmd_tcp_impl_pr_on_msg_message_payload(sessioncmd_tcp_impl, &message->m_mix.m_data.m_message_payload); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_message_message_type_e_get_date                  : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_set_date                  : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_dest_lookup               : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_dest_reply                : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_send_message_expires      : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_request_variable_lease_set: mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_host_lookup               : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_host_reply                : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_create_lease_set2         : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_blinding_info             : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_make_msg(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl, mk_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_message_receive_message_end_pt msg_receive_message_end;

	mk_lang_assert(sessioncmd_tcp_impl);
	mk_lang_assert(message);

	sessioncmd_tcp_impl->m_did_something = mk_lang_false;
	if(sessioncmd_tcp_impl->m_state == mk_iip_cp_sessioncmd_tcp_impl_state_e_submit_message_end)
	{
		err = mk_iip_cp_message_reconstruct(message, mk_iip_cp_message_message_type_e_receive_message_end); mk_lang_check_rereturn(err);
		msg_receive_message_end = &message->m_mix.m_data.m_receive_message_end;
		msg_receive_message_end->m_session_id = *sessioncmd_tcp_impl->m_session_id;
		msg_receive_message_end->m_message_id = sessioncmd_tcp_impl->m_message_id_to_end;
		sessioncmd_tcp_impl->m_state = mk_iip_cp_sessioncmd_tcp_impl_state_e_ready;
		sessioncmd_tcp_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_tcp_impl_rw_tick_single(mk_iip_cp_sessioncmd_tcp_impl_pt const sessioncmd_tcp_impl) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_tcp_impl);

	sessioncmd_tcp_impl->m_did_something = mk_lang_false;
	mk_lang_check_todo();
	return 0;
}


#endif
