#ifndef mk_include_guard_mk_iip_cp_sm_tcp_impl_c
#define mk_include_guard_mk_iip_cp_sm_tcp_impl_c
#include "mk_iip_cp_sm_tcp_impl.h"

#include "mk_iip_cp_base.h"
#include "mk_iip_cp_client_data.h"
#include "mk_iip_cp_destination.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_message.h"
#include "mk_iip_cp_packet_base.h"
#include "mk_iip_cp_packet_tcp.h"
#include "mk_iip_cp_socket_tcp_intr.h"
#include "mk_iip_cp_type.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"
#include "mk_lib_zlib.h"
#include "mk_sl_uint.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint32.h"
#include "mk_sl_uint8.h"


#define mk_sl_ring_dynamic_t_name mk_iip_cp_sm_tcp_impl_vec
#define mk_sl_ring_dynamic_t_element mk_sl_cui_uint8_t
#define mk_sl_ring_dynamic_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_ring_dynamic_inl_filec.h"
#include "mk_sl_ring_dynamic_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_pr_init(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_message_message_payload_pct const msg_message_payload, mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t outlen;

	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(msg_message_payload);
	mk_lang_assert(packet);
	mk_lang_assert(sm_tcp_impl->m_accept_request);
	mk_lang_assert(sm_tcp_impl->m_accept_request->m_socket);
	mk_lang_assert(sm_tcp_impl->m_accept_request->m_remote_destination);
	mk_lang_assert(sm_tcp_impl->m_accept_response);

	mk_iip_cp_helper_generate_random_u32_non_zero(&sm_tcp_impl->m_local_stream_id);
	mk_sl_cui_uint32_set_zero(&sm_tcp_impl->m_sequence_number);
	sm_tcp_impl->m_remote_stream_id = packet->m_remote_stream_id;
	err = mk_iip_cp_packet_tcp_ro_get_option_from_structured(packet, &sm_tcp_impl->m_remote_destination_structured, &outlen); mk_lang_check_rereturn(err);
	mk_sl_cui_uint8_memcpy(&sm_tcp_impl->m_remote_destination_blob.m_buf[0], mk_iip_cp_packet_tcp_ro_get_option_from_blob_buf(packet), mk_iip_cp_packet_tcp_ro_get_option_from_blob_len(packet)); sm_tcp_impl->m_remote_destination_blob.m_len = mk_iip_cp_packet_tcp_ro_get_option_from_blob_len(packet);
	/* todo validate signature, and do it sooner */
	err = mk_iip_cp_sm_tcp_impl_vec_rw_clear(&sm_tcp_impl->m_data_rcv); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sm_tcp_impl_vec_rw_push_back_many(&sm_tcp_impl->m_data_rcv, mk_iip_cp_packet_tcp_ro_get_payload_buf(packet), mk_iip_cp_packet_tcp_ro_get_payload_len(packet)); mk_lang_check_rereturn(err);
	err = mk_iip_cp_socket_tcp_intr_rw_set_tcpsm(sm_tcp_impl->m_accept_request->m_socket, &sm_tcp_impl->m_self_intr); mk_lang_check_rereturn(err);
	*sm_tcp_impl->m_accept_request->m_remote_destination = sm_tcp_impl->m_remote_destination_blob;
	sm_tcp_impl->m_accept_response->m_success = mk_lang_true;
	sm_tcp_impl->m_accept_response->m_done = mk_lang_true;
	mk_lang_assert(!sm_tcp_impl->m_has_message_to_end);
	sm_tcp_impl->m_has_message_to_end = mk_lang_true;
	sm_tcp_impl->m_message_id_to_end = msg_message_payload->m_message_id;
	sm_tcp_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_pr_continue(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_message_message_payload_pct const msg_message_payload, mk_iip_cp_packet_tcp_pct const packet) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;

	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(msg_message_payload);
	mk_lang_assert(packet);

	gud = mk_lang_true;
	if(gud)
	{
		mk_lang_assert(sm_tcp_impl->m_remote_destination_blob.m_len >= 256 + 128);
		if(!(mk_sl_cui_uint8_memcmp(mk_iip_cp_packet_tcp_ro_get_option_from_blob_buf(packet), &sm_tcp_impl->m_remote_destination_blob.m_buf[0], mk_iip_cp_packet_tcp_ro_get_option_from_blob_len(packet)) == 0))
		{
			gud = mk_lang_false;
		}
	}
	if(gud)
	{
		mk_lang_check_todo();
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_pr_on_msg_message_payload(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_message_message_payload_pct const msg_message_payload) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_sint_t remote_port;
	mk_lang_types_sint_t local_port;
	mk_lang_types_sint_t protocol;
	mk_lang_types_sint_t err;
	mk_iip_cp_type_buffer_t decompressed;
	mk_iip_cp_packet_tcp_t packet;
	mk_lang_types_sint_t outlen;

	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(msg_message_payload);
	mk_lang_assert(sm_tcp_impl->m_session_id);
	mk_lang_assert(mk_sl_cui_uint16_eq(&msg_message_payload->m_session_id.m_id, &sm_tcp_impl->m_session_id->m_id));

	gud = mk_lang_true;
	if(gud)
	{
		err = mk_iip_cp_packet_tcp_rw_construct(&packet); mk_lang_check_rereturn(err);
		if(!(mk_iip_cp_packet_base_is_compressed_buf(&msg_message_payload->m_payload)))
		{
			mk_lang_check_todo(); /* todo, not compressed, bad format */
			gud = mk_lang_false;
		}
	}
	if(gud)
	{
		mk_sl_uint_16_from_8_be(&tu16, &msg_message_payload->m_payload.m_buf[4]); mk_sl_cui_uint16_to_bi_sint(&tu16, &remote_port);
		mk_sl_uint_16_from_8_be(&tu16, &msg_message_payload->m_payload.m_buf[6]); mk_sl_cui_uint16_to_bi_sint(&tu16, &local_port);
		mk_sl_cui_uint8_to_bi_sint(&msg_message_payload->m_payload.m_buf[9], &protocol);
		if(!(protocol == mk_iip_cp_packet_base_protocol_id_e_streaming))
		{
			gud = mk_lang_false;
		}
	}
	if(gud)
	{
		err = mk_lib_zlib_decompress(&msg_message_payload->m_payload.m_buf[0], msg_message_payload->m_payload.m_len, &decompressed.m_buf[0], mk_lang_countof(decompressed.m_buf), &decompressed.m_len); mk_lang_check_rereturn(err);
		err = mk_iip_cp_packet_tcp_rw_parse(&packet, &decompressed.m_buf[0], decompressed.m_len, &gud, &outlen); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(outlen == decompressed.m_len);
		if(!(mk_iip_cp_packet_tcp_ro_is_valid(&packet)))
		{
			gud = mk_lang_false;
		}
	}
	if(gud)
	{
		mk_lang_clobber(&local_port);
		mk_lang_clobber(&remote_port);
		if(mk_iip_cp_packet_tcp_ro_is_initial_remote_syn(&packet) && sm_tcp_impl->m_local_port == -1 && sm_tcp_impl->m_remote_port == -1 && (sm_tcp_impl->m_wanted_port == 0 || sm_tcp_impl->m_wanted_port == local_port))
		{
			mk_lang_assert(sm_tcp_impl->m_local_port == -1);
			mk_lang_assert(sm_tcp_impl->m_remote_port == -1);
			sm_tcp_impl->m_local_port = local_port;
			sm_tcp_impl->m_remote_port = remote_port;
			err = mk_iip_cp_sm_tcp_impl_pr_init(sm_tcp_impl, msg_message_payload, &packet); mk_lang_check_rereturn(err);
		}
		else if(mk_iip_cp_packet_tcp_ro_is_initial_remote_syn(&packet) && sm_tcp_impl->m_local_port == local_port && sm_tcp_impl->m_remote_port == remote_port && (sm_tcp_impl->m_wanted_port == 0 || sm_tcp_impl->m_wanted_port == local_port) && mk_sl_cui_uint32_eq(&sm_tcp_impl->m_remote_stream_id, &packet.m_remote_stream_id))
		{
			mk_lang_check_todo(); /* re-syn */
		}
		else
		{
			mk_lang_assert(sm_tcp_impl->m_local_port != -1);
			mk_lang_assert(sm_tcp_impl->m_remote_port != -1);
			if(local_port == sm_tcp_impl->m_local_port && remote_port == sm_tcp_impl->m_remote_port)
			{
				err = mk_iip_cp_sm_tcp_impl_pr_continue(sm_tcp_impl, msg_message_payload, &packet); mk_lang_check_rereturn(err);
			}
		}
	}
	err = mk_iip_cp_packet_tcp_rw_destroy(&packet); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_pr_make_msg_ack(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_packet_tcp_t packet;
	mk_lang_types_bool_t gud;
	mk_lang_types_sint_t consumed;
	mk_iip_cp_base_dsa_signature_t signature;
	mk_sl_cui_uint8_t zero;
	mk_iip_cp_type_buffer_t decompressed;
	mk_iip_cp_type_buffer_pt compressed;
	mk_sl_cui_uint16_t tu16;
	mk_lang_types_sint_t tsi;
	mk_iip_cp_message_send_message_pt msg_send_message;

	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(message);
	mk_lang_assert(sm_tcp_impl->m_want_ack);

	err = mk_iip_cp_packet_tcp_rw_construct(&packet); mk_lang_check_rereturn(err);

	packet.m_local_stream_id = sm_tcp_impl->m_local_stream_id;
	packet.m_remote_stream_id = sm_tcp_impl->m_remote_stream_id;
	packet.m_sequence_number = sm_tcp_impl->m_sequence_number;
	mk_sl_cui_uint32_inc1(&sm_tcp_impl->m_sequence_number); /* ??? */
	mk_sl_cui_uint32_set_zero(&packet.m_ack_through);
	packet.m_resend_delay = 2;
	packet.m_flags = ((mk_iip_cp_packet_tcp_flags_t)(mk_iip_cp_packet_tcp_flags_e_synchronize | mk_iip_cp_packet_tcp_flags_e_close | mk_iip_cp_packet_tcp_flags_e_signature_included | mk_iip_cp_packet_tcp_flags_e_from_included));
	err = mk_iip_cp_packet_tcp_buffer_rw_push_back_void_many(&packet.m_options_and_payload, 256+128+1+2); mk_lang_check_rereturn(err);
	err = mk_iip_cp_destination_serialize_elgamal_dsa(mk_iip_cp_packet_tcp_buffer_rw_data(&packet.m_options_and_payload), 256+128+1+2, &gud, &consumed, sm_tcp_impl->m_local_destination); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(consumed >= 1);
	err = mk_iip_cp_packet_tcp_buffer_rw_shrink_dy(&packet.m_options_and_payload, 256+128+1+2 - consumed); mk_lang_check_rereturn(err);
	err = mk_iip_cp_packet_tcp_buffer_rw_push_back_void_many(&packet.m_options_and_payload, 40); mk_lang_check_rereturn(err);
	mk_sl_cui_uint8_set_zero(&zero); mk_sl_cui_uint8_memset(mk_iip_cp_packet_tcp_buffer_rw_data(&packet.m_options_and_payload) + mk_iip_cp_packet_tcp_buffer_ro_size(&packet.m_options_and_payload) - 40, &zero, 40);
	mk_iip_cp_base_dsa_sign_k_has_n(&sm_tcp_impl->m_local_destination->m_key_dsa_pri, mk_iip_cp_packet_tcp_buffer_ro_data(&packet.m_options_and_payload), ((mk_lang_types_sint_t)(mk_iip_cp_packet_tcp_buffer_ro_size(&packet.m_options_and_payload))), &signature);
	mk_sl_cui_uint8_memcpy(mk_iip_cp_packet_tcp_buffer_rw_data(&packet.m_options_and_payload) + mk_iip_cp_packet_tcp_buffer_ro_size(&packet.m_options_and_payload) - 40, &signature.m_data.m_uint8s[0], 40);
	packet.m_options_buf = &mk_iip_cp_packet_tcp_buffer_ro_data(&packet.m_options_and_payload)[0];
	packet.m_options_len = ((mk_lang_types_sint_t)(mk_iip_cp_packet_tcp_buffer_ro_size(&packet.m_options_and_payload)));
	packet.m_payload_buf = 0;
	packet.m_payload_len = 0;

	err = mk_iip_cp_message_reconstruct(message, mk_iip_cp_message_message_type_e_send_message); mk_lang_check_rereturn(err);
	msg_send_message = &message->m_mix.m_data.m_send_message;
	msg_send_message->m_session_id = *sm_tcp_impl->m_session_id;
	msg_send_message->m_destination;
	err = mk_iip_cp_destination_serialize_elgamal_dsa(&msg_send_message->m_destination.m_buf[0], mk_lang_countof(msg_send_message->m_destination.m_buf), &gud, &consumed, sm_tcp_impl->m_local_destination); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(consumed >= 1); msg_send_message->m_destination.m_len = consumed;
	compressed = &msg_send_message->m_payload;
	mk_iip_cp_helper_generate_random_u32_non_zero(&msg_send_message->m_nonce);

	err = mk_iip_cp_packet_tcp_ro_serialize(&packet, &decompressed.m_buf[0], mk_lang_countof(decompressed.m_buf), &gud, &consumed); mk_lang_check_rereturn(err); mk_lang_check_return(gud); mk_lang_check_return(consumed >= 1); decompressed.m_len = consumed;
	err = mk_lib_zlib_compress(&decompressed.m_buf[0], decompressed.m_len, 1, &compressed->m_buf[0], mk_lang_countof(compressed->m_buf), &consumed); mk_lang_check_rereturn(err); compressed->m_len = consumed;
	mk_sl_cui_uint16_from_bi_sint(&tu16, &sm_tcp_impl->m_remote_port); mk_sl_uint_16_to_8_be(&tu16, &compressed->m_buf[4]);
	mk_sl_cui_uint16_from_bi_sint(&tu16, &sm_tcp_impl->m_local_port); mk_sl_uint_16_to_8_be(&tu16, &compressed->m_buf[6]);
	tsi = 0x02; mk_sl_cui_uint8_from_bi_sint(&compressed->m_buf[8], &tsi);
	tsi = mk_iip_cp_packet_base_protocol_id_e_streaming; mk_sl_cui_uint8_from_bi_sint(&compressed->m_buf[9], &tsi);

	err = mk_iip_cp_packet_tcp_rw_destroy(&packet); mk_lang_check_rereturn(err);

	sm_tcp_impl->m_want_ack = mk_lang_false;
	sm_tcp_impl->m_has_message_sent = mk_lang_true;
	sm_tcp_impl->m_message_nonce_sent = msg_send_message->m_nonce;
	sm_tcp_impl->m_did_something = mk_lang_true;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_allocate(mk_iip_cp_sm_tcp_impl_ppt const sm_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_impl);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**sm_tcp_impl), ((mk_lang_types_void_ppt)(sm_tcp_impl))); mk_lang_check_rereturn(err); mk_lang_assert(*sm_tcp_impl);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_deallocate(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_impl);

	err = mk_iip_cp_mallocator_global_deallocate(sm_tcp_impl, sizeof(*sm_tcp_impl)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_construct(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_sm_tcp_intr_pt const sessioncmd_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(sessioncmd_tcp_intr);

	sm_tcp_impl->m_self_intr = sessioncmd_tcp_intr;
	((mk_lang_types_void_t)(sm_tcp_impl->m_session_id));
	((mk_lang_types_void_t)(sm_tcp_impl->m_local_destination));
	((mk_lang_types_void_t)(sm_tcp_impl->m_accept_request));
	((mk_lang_types_void_t)(sm_tcp_impl->m_accept_response));
	sm_tcp_impl->m_read_data_request = mk_lang_null;
	sm_tcp_impl->m_read_data_response = mk_lang_null;
	((mk_lang_types_void_t)(sm_tcp_impl->m_did_something));
	sm_tcp_impl->m_state = mk_iip_cp_sm_tcp_impl_state_e_fresh;
	sm_tcp_impl->m_accepted = mk_lang_false;
	sm_tcp_impl->m_wanted_port = -1;
	sm_tcp_impl->m_local_port = -1;
	sm_tcp_impl->m_remote_port = -1;
	((mk_lang_types_void_t)(sm_tcp_impl->m_local_stream_id));
	((mk_lang_types_void_t)(sm_tcp_impl->m_remote_stream_id));
	((mk_lang_types_void_t)(sm_tcp_impl->m_sequence_number));
	((mk_lang_types_void_t)(sm_tcp_impl->m_remote_destination_blob));
	((mk_lang_types_void_t)(sm_tcp_impl->m_remote_destination_structured));
	sm_tcp_impl->m_has_message_to_end = mk_lang_false;
	((mk_lang_types_void_t)(sm_tcp_impl->m_message_id_to_end));
	sm_tcp_impl->m_want_ack = mk_lang_false;
	sm_tcp_impl->m_has_message_sent = mk_lang_false;
	((mk_lang_types_void_t)(sm_tcp_impl->m_message_nonce_sent));
	err = mk_iip_cp_sm_tcp_impl_vec_rw_construct(&sm_tcp_impl->m_data_rcv); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sm_tcp_impl_vec_rw_construct(&sm_tcp_impl->m_data_snd); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_destruct(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_impl);

	((mk_lang_types_void_t)(sm_tcp_impl->m_self_intr));
	((mk_lang_types_void_t)(sm_tcp_impl->m_session_id));
	((mk_lang_types_void_t)(sm_tcp_impl->m_local_destination));
	((mk_lang_types_void_t)(sm_tcp_impl->m_accept_request));
	((mk_lang_types_void_t)(sm_tcp_impl->m_accept_response));
	((mk_lang_types_void_t)(sm_tcp_impl->m_read_data_request));
	((mk_lang_types_void_t)(sm_tcp_impl->m_read_data_response));
	((mk_lang_types_void_t)(sm_tcp_impl->m_did_something));
	((mk_lang_types_void_t)(sm_tcp_impl->m_state));
	((mk_lang_types_void_t)(sm_tcp_impl->m_accepted));
	((mk_lang_types_void_t)(sm_tcp_impl->m_wanted_port));
	((mk_lang_types_void_t)(sm_tcp_impl->m_local_port));
	((mk_lang_types_void_t)(sm_tcp_impl->m_remote_port));
	((mk_lang_types_void_t)(sm_tcp_impl->m_local_stream_id));
	((mk_lang_types_void_t)(sm_tcp_impl->m_remote_stream_id));
	((mk_lang_types_void_t)(sm_tcp_impl->m_sequence_number));
	((mk_lang_types_void_t)(sm_tcp_impl->m_remote_destination_blob));
	((mk_lang_types_void_t)(sm_tcp_impl->m_remote_destination_structured));
	((mk_lang_types_void_t)(sm_tcp_impl->m_has_message_to_end));
	((mk_lang_types_void_t)(sm_tcp_impl->m_message_id_to_end));
	((mk_lang_types_void_t)(sm_tcp_impl->m_want_ack));
	((mk_lang_types_void_t)(sm_tcp_impl->m_has_message_sent));
	((mk_lang_types_void_t)(sm_tcp_impl->m_message_nonce_sent));
	err = mk_iip_cp_sm_tcp_impl_vec_rw_destruct(&sm_tcp_impl->m_data_rcv); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sm_tcp_impl_vec_rw_destruct(&sm_tcp_impl->m_data_snd); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_allocate_and_construct(mk_iip_cp_sm_tcp_impl_ppt const sm_tcp_impl, mk_iip_cp_sm_tcp_intr_pt const sessioncmd_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(sessioncmd_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_allocate(sm_tcp_impl); mk_lang_check_rereturn(err); mk_lang_assert(*sm_tcp_impl);
	err = mk_iip_cp_sm_tcp_impl_rw_construct(*sm_tcp_impl, sessioncmd_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_destruct_and_deallocate(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_impl);

	err = mk_iip_cp_sm_tcp_impl_rw_destruct(sm_tcp_impl); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sm_tcp_impl_rw_deallocate(sm_tcp_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_set_session_id(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_type_sessionid_pct const session_id) mk_lang_noexcept
{
	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(session_id);

	sm_tcp_impl->m_session_id = session_id;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_set_local_destination(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_type_destination_elgamal_dsa_pct const local_destination) mk_lang_noexcept
{
	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(local_destination);

	sm_tcp_impl->m_local_destination = local_destination;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_set_wanted_port(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_sl_cui_uint16_pct const wanted_port) mk_lang_noexcept
{
	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(wanted_port);

	mk_sl_cui_uint16_to_bi_sint(wanted_port, &sm_tcp_impl->m_wanted_port);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_set_accept_rr(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_client_data_request_accept_pct const request, mk_iip_cp_client_data_response_accept_pt const response) mk_lang_noexcept
{
	mk_iip_cp_destination_pct local_destination;

	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	sm_tcp_impl->m_accept_request = request;
	sm_tcp_impl->m_accept_response = response;
	local_destination = mk_iip_cp_socket_tcp_intr_rw_get_destination(request->m_socket); mk_lang_assert(local_destination);
	mk_sl_cui_uint16_to_bi_sint(&local_destination->m_port, &sm_tcp_impl->m_wanted_port);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_set_read_data_rr(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_client_data_request_read_data_pct const request, mk_iip_cp_client_data_response_read_data_pt const response) mk_lang_noexcept
{
	mk_lang_types_usize_t tus;
	mk_lang_types_sint_t have;
	mk_lang_types_sint_t to_transfer;
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(request);
	mk_lang_assert(request->m_payload);
	mk_lang_assert(request->m_payload->m_len >= 1);
	mk_lang_assert(response);

	sm_tcp_impl->m_read_data_request = request;
	sm_tcp_impl->m_read_data_response = response;
	if(!mk_iip_cp_sm_tcp_impl_vec_ro_is_empty(&sm_tcp_impl->m_data_rcv))
	{
		tus = mk_iip_cp_sm_tcp_impl_vec_ro_size(&sm_tcp_impl->m_data_rcv); have = ((mk_lang_types_sint_t)(tus));
		to_transfer = mk_lang_min(have, sm_tcp_impl->m_read_data_request->m_payload->m_len);
		err = mk_iip_cp_sm_tcp_impl_vec_rw_copy_from_front_and_pop_and_reset(&sm_tcp_impl->m_data_rcv, &sm_tcp_impl->m_read_data_request->m_payload->m_buf[0], to_transfer); mk_lang_check_rereturn(err);
		sm_tcp_impl->m_read_data_request->m_payload->m_len = to_transfer;
		sm_tcp_impl->m_read_data_response->m_success = mk_lang_true;
		sm_tcp_impl->m_read_data_response->m_done = mk_lang_true;
		sm_tcp_impl->m_read_data_request = mk_lang_null;
		sm_tcp_impl->m_read_data_response = mk_lang_null;
		if(mk_iip_cp_sm_tcp_impl_vec_ro_is_empty(&sm_tcp_impl->m_data_rcv))
		{
			sm_tcp_impl->m_want_ack = mk_lang_true;
		}
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_sessionid_pct mk_iip_cp_sm_tcp_impl_rw_get_session_id(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept
{
	mk_iip_cp_type_sessionid_pct ret;

	mk_lang_assert(sm_tcp_impl);

	ret = sm_tcp_impl->m_session_id;
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_sm_tcp_impl_rw_did_something(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(sm_tcp_impl);

	ret = sm_tcp_impl->m_did_something;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_on_msg(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(message);

	sm_tcp_impl->m_did_something = mk_lang_false;
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
		case mk_iip_cp_message_message_type_e_message_payload           : err = mk_iip_cp_sm_tcp_impl_pr_on_msg_message_payload(sm_tcp_impl, &message->m_mix.m_data.m_message_payload); mk_lang_check_rereturn(err); break;
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_make_msg(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl, mk_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_message_receive_message_end_pt msg_receive_message_end;

	mk_lang_assert(sm_tcp_impl);
	mk_lang_assert(message);

	sm_tcp_impl->m_did_something = mk_lang_false;
	if(sm_tcp_impl->m_has_message_to_end)
	{
		sm_tcp_impl->m_has_message_to_end = mk_lang_false;
		err = mk_iip_cp_message_reconstruct(message, mk_iip_cp_message_message_type_e_receive_message_end); mk_lang_check_rereturn(err);
		msg_receive_message_end = &message->m_mix.m_data.m_receive_message_end;
		msg_receive_message_end->m_session_id = *sm_tcp_impl->m_session_id;
		msg_receive_message_end->m_message_id = sm_tcp_impl->m_message_id_to_end;
		sm_tcp_impl->m_did_something = mk_lang_true;
	}
	else if(sm_tcp_impl->m_want_ack)
	{
		err = mk_iip_cp_sm_tcp_impl_pr_make_msg_ack(sm_tcp_impl, message); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_impl_rw_tick_single(mk_iip_cp_sm_tcp_impl_pt const sm_tcp_impl) mk_lang_noexcept
{
	mk_lang_assert(sm_tcp_impl);

	sm_tcp_impl->m_did_something = mk_lang_false;
	return 0;
}


#endif
