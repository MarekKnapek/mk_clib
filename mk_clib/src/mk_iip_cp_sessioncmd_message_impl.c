#ifndef mk_include_guard_mk_iip_cp_sessioncmd_message_impl_c
#define mk_include_guard_mk_iip_cp_sessioncmd_message_impl_c
#include "mk_iip_cp_sessioncmd_message_impl.h"

#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_message.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_zlib.h"
#include "mk_sl_uint.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_sessioncmd_message_impl_pr_is_compressed(mk_iip_cp_type_buffer_pct const data) mk_lang_noexcept
{
	mk_lang_types_bool_t res;
	mk_lang_types_uchar_t tuc;

	mk_lang_assert(data);
	mk_lang_assert(data->m_len >= 0);

	res =
		data->m_len >= 10 &&
		(mk_sl_cui_uint8_to_bi_uchar(&data->m_buf[0], &tuc), tuc == 0x1f) &&
		(mk_sl_cui_uint8_to_bi_uchar(&data->m_buf[1], &tuc), tuc == 0x8b) &&
		(mk_sl_cui_uint8_to_bi_uchar(&data->m_buf[2], &tuc), tuc == 0x08) &&
		mk_lang_true;
	return res;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_pr_on_msg_message_status_available(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl, mk_iip_cp_message_message_status_pct const msg_message_status) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_message_impl);
	mk_lang_assert(msg_message_status);
	mk_lang_assert(sessioncmd_message_impl->m_session_id);
	mk_lang_assert(mk_sl_cui_uint16_eq(&msg_message_status->m_session_id.m_id, &sessioncmd_message_impl->m_session_id->m_id));
	mk_lang_assert(msg_message_status->m_status == mk_iip_cp_message_message_status_status_e_available);

	sessioncmd_message_impl->m_want_receive = mk_lang_true;
	sessioncmd_message_impl->m_message_id = msg_message_status->m_message_id;
	sessioncmd_message_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_pr_on_msg_message_status(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl, mk_iip_cp_message_message_status_pct const msg_message_status) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_message_impl);
	mk_lang_assert(msg_message_status);
	mk_lang_assert(sessioncmd_message_impl->m_session_id);
	mk_lang_assert(mk_sl_cui_uint16_eq(&msg_message_status->m_session_id.m_id, &sessioncmd_message_impl->m_session_id->m_id));

	msg_message_status->m_message_id; /* todo track state per message id */
	switch(msg_message_status->m_status)
	{
		case mk_iip_cp_message_message_status_status_e_available             : err = mk_iip_cp_sessioncmd_message_impl_pr_on_msg_message_status_available(sessioncmd_message_impl, msg_message_status); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_message_message_status_status_e_accepted              : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_best_effort_success   : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_best_effort_failure   : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_guaranteed_success    : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_guaranteed_failure    : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_local_success         : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_local_failure         : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_router_failure        : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_network_failure       : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_bad_session           : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_bad_message           : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_bad_options           : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_overflow_failure      : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_message_expired       : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_bad_local_leaseset    : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_no_local_tunnels      : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_unsupported_encryption: mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_bad_destination       : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_bad_leaseset          : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_expired_leaseset      : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_no_leaseset           : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_meta_leaseset         : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_status_status_e_loopback_denied       : mk_lang_check_todo(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_pr_on_msg_message_payload(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl, mk_iip_cp_message_message_payload_pct const msg_message_payload) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint16_t src_port;
	mk_sl_cui_uint16_t dst_port;
	mk_lang_types_sint_t protocol;

	mk_lang_assert(sessioncmd_message_impl);
	mk_lang_assert(msg_message_payload);
	mk_lang_assert(sessioncmd_message_impl->m_session_id);
	mk_lang_assert(mk_sl_cui_uint16_eq(&msg_message_payload->m_session_id.m_id, &sessioncmd_message_impl->m_session_id->m_id));

	msg_message_payload->m_message_id; /* todo track state per message id */
	if(mk_iip_cp_sessioncmd_message_impl_pr_is_compressed(&msg_message_payload->m_payload))
	{
		mk_sl_uint_16_from_8_be(&src_port, &msg_message_payload->m_payload.m_buf[4]);
		mk_sl_uint_16_from_8_be(&dst_port, &msg_message_payload->m_payload.m_buf[6]);
		mk_sl_cui_uint8_to_bi_sint(&msg_message_payload->m_payload.m_buf[9], &protocol);
		err = mk_lib_zlib_decompress(&msg_message_payload->m_payload.m_buf[0], msg_message_payload->m_payload.m_len, &sessioncmd_message_impl->m_message_content.m_buf[0], mk_lang_countof(sessioncmd_message_impl->m_message_content.m_buf), &sessioncmd_message_impl->m_message_content.m_len); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_todo(); /* bad format */
	}
	//mk_lang_check_todo(); /* todo do something with payload */
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_rw_allocate(mk_iip_cp_sessioncmd_message_impl_ppt const sessioncmd_message_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_message_impl);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**sessioncmd_message_impl), ((mk_lang_types_void_ppt)(sessioncmd_message_impl))); mk_lang_check_rereturn(err); mk_lang_assert(*sessioncmd_message_impl);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_rw_deallocate(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_message_impl);

	err = mk_iip_cp_mallocator_global_deallocate(sessioncmd_message_impl, sizeof(*sessioncmd_message_impl)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_rw_construct(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl, mk_iip_cp_sessioncmd_message_intr_pt const sessioncmd_message_intr) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_message_impl);
	mk_lang_assert(sessioncmd_message_intr);

	sessioncmd_message_impl->m_sessioncmd_message_intr = sessioncmd_message_intr;
	((mk_lang_types_void_t)(sessioncmd_message_impl->m_session_id));
	((mk_lang_types_void_t)(sessioncmd_message_impl->m_did_something));
	sessioncmd_message_impl->m_want_receive = mk_lang_false;
	((mk_lang_types_void_t)(sessioncmd_message_impl->m_message_id));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_rw_destruct(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_message_impl);

	((mk_lang_types_void_t)(sessioncmd_message_impl->m_sessioncmd_message_intr));
	((mk_lang_types_void_t)(sessioncmd_message_impl->m_session_id));
	((mk_lang_types_void_t)(sessioncmd_message_impl->m_did_something));
	((mk_lang_types_void_t)(sessioncmd_message_impl->m_want_receive));
	((mk_lang_types_void_t)(sessioncmd_message_impl->m_message_id));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_rw_allocate_and_construct(mk_iip_cp_sessioncmd_message_impl_ppt const sessioncmd_message_impl, mk_iip_cp_sessioncmd_message_intr_pt const sessioncmd_message_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_message_impl);
	mk_lang_assert(sessioncmd_message_intr);

	err = mk_iip_cp_sessioncmd_message_impl_rw_allocate(sessioncmd_message_impl); mk_lang_check_rereturn(err); mk_lang_assert(*sessioncmd_message_impl);
	err = mk_iip_cp_sessioncmd_message_impl_rw_construct(*sessioncmd_message_impl, sessioncmd_message_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_rw_destruct_and_deallocate(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_message_impl);

	err = mk_iip_cp_sessioncmd_message_impl_rw_destruct(sessioncmd_message_impl); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sessioncmd_message_impl_rw_deallocate(sessioncmd_message_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_rw_set_session_id(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl, mk_iip_cp_type_sessionid_pct const session_id) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_message_impl);
	mk_lang_assert(session_id);

	sessioncmd_message_impl->m_session_id = session_id;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_sessionid_pct mk_iip_cp_sessioncmd_message_impl_rw_get_session_id(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl) mk_lang_noexcept
{
	mk_iip_cp_type_sessionid_pct ret;

	mk_lang_assert(sessioncmd_message_impl);

	ret = sessioncmd_message_impl->m_session_id;
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_sessioncmd_message_impl_rw_did_something(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(sessioncmd_message_impl);

	ret = sessioncmd_message_impl->m_did_something;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_rw_on_msg(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_message_impl);
	mk_lang_assert(message);

	sessioncmd_message_impl->m_did_something = mk_lang_false;
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
		case mk_iip_cp_message_message_type_e_message_status            : err = mk_iip_cp_sessioncmd_message_impl_pr_on_msg_message_status(sessioncmd_message_impl, &message->m_mix.m_data.m_message_status); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_message_message_type_e_bandwidth_limits          : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_report_abuse              : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_disconnect                : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_message_payload           : err = mk_iip_cp_sessioncmd_message_impl_pr_on_msg_message_payload(sessioncmd_message_impl, &message->m_mix.m_data.m_message_payload); mk_lang_check_rereturn(err); break;
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_rw_make_msg(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl, mk_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_message_receive_message_begin_pt msg_receive_message_begin;

	mk_lang_assert(sessioncmd_message_impl);
	mk_lang_assert(message);

	sessioncmd_message_impl->m_did_something = mk_lang_false;
	if(sessioncmd_message_impl->m_want_receive)
	{
		err = mk_iip_cp_message_reconstruct(message, mk_iip_cp_message_message_type_e_receive_message_begin); mk_lang_check_rereturn(err);
		msg_receive_message_begin = &message->m_mix.m_data.m_receive_message_begin;
		msg_receive_message_begin->m_session_id = *sessioncmd_message_impl->m_session_id;
		msg_receive_message_begin->m_message_id = sessioncmd_message_impl->m_message_id;
		sessioncmd_message_impl->m_want_receive = mk_lang_false;
		sessioncmd_message_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_message_impl_rw_tick_single(mk_iip_cp_sessioncmd_message_impl_pt const sessioncmd_message_impl) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_message_impl);

	sessioncmd_message_impl->m_did_something = mk_lang_false;
	return 0;
}


#endif
