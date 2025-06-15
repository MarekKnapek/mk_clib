#ifndef mk_include_guard_mk_iip_cp_session_impl_c
#define mk_include_guard_mk_iip_cp_session_impl_c
#include "mk_iip_cp_session_impl.h"

#include "mk_iip_cp_client_data.h"
#include "mk_iip_cp_destination.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_message.h"
#include "mk_iip_cp_sessioncmd_leaseset_intr.h"
#include "mk_iip_cp_sessioncmd_message_intr.h"
#include "mk_iip_cp_sm_tcp_intr.h"
#include "mk_iip_cp_socket_tcp_intr.h"
#include "mk_iip_cp_type.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_uint16.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_pr_on_msg_request_lease_set(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);
	mk_lang_assert(message);

	err = mk_iip_cp_sessioncmd_leaseset_intr_rw_on_msg(&session_impl->m_cmd_leaseset, message); mk_lang_check_rereturn(err);
	if(mk_iip_cp_sessioncmd_leaseset_intr_rw_did_something(&session_impl->m_cmd_leaseset))
	{
		session_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_pr_on_msg_message_status(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);
	mk_lang_assert(message);

	err = mk_iip_cp_sessioncmd_message_intr_rw_on_msg(&session_impl->m_cmd_message, message); mk_lang_check_rereturn(err);
	if(mk_iip_cp_sessioncmd_message_intr_rw_did_something(&session_impl->m_cmd_message))
	{
		session_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_pr_on_msg_message_payload(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_iip_cp_sm_tcp_intr_pt sm_tcp;
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);
	mk_lang_assert(message);
	mk_lang_assert(!session_impl->m_did_something);
	mk_lang_assert(message->m_header.m_type == mk_iip_cp_message_message_type_e_message_payload);
	mk_lang_assert(mk_sl_cui_uint16_eq(&message->m_mix.m_data.m_message_payload.m_session_id.m_id, &session_impl->m_session_id.m_id));

	n = mk_iip_cp_sm_tcp_intrs_rw_size(&session_impl->m_sms_tcp);
	for(i = 0; i != n; ++i)
	{
		sm_tcp = mk_iip_cp_sm_tcp_intrs_rw_at(&session_impl->m_sms_tcp, i); mk_lang_assert(sm_tcp);
		err = mk_iip_cp_sm_tcp_intr_rw_on_msg(sm_tcp, message); mk_lang_check_rereturn(err);
		if(mk_iip_cp_sm_tcp_intr_rw_did_something(sm_tcp))
		{
			session_impl->m_did_something = mk_lang_true;
			break;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_pr_on_msg_request_variable_lease_set(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);
	mk_lang_assert(message);

	err = mk_iip_cp_sessioncmd_leaseset_intr_rw_on_msg(&session_impl->m_cmd_leaseset, message); mk_lang_check_rereturn(err);
	if(mk_iip_cp_sessioncmd_leaseset_intr_rw_did_something(&session_impl->m_cmd_leaseset))
	{
		session_impl->m_did_something = mk_lang_true;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_allocate(mk_iip_cp_session_impl_ppt const session_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**session_impl), ((mk_lang_types_void_ppt)(session_impl))); mk_lang_check_rereturn(err); mk_lang_assert(*session_impl);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_deallocate(mk_iip_cp_session_impl_pt const session_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);

	err = mk_iip_cp_mallocator_global_deallocate(session_impl, sizeof(*session_impl)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_construct(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);
	mk_lang_assert(session_intr);

	session_impl->m_session_intr = session_intr;
	((mk_lang_types_void_t)(session_impl->m_connection));
	((mk_lang_types_void_t)(session_impl->m_session_id));
	((mk_lang_types_void_t)(session_impl->m_destination));
	session_impl->m_did_something = mk_lang_false;
	err = mk_iip_cp_sessioncmd_leaseset_intr_rw_construct(&session_impl->m_cmd_leaseset); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sm_tcp_intrs_rw_construct(&session_impl->m_sms_tcp); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sessioncmd_message_intr_rw_construct(&session_impl->m_cmd_message); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_destruct(mk_iip_cp_session_impl_pt const session_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);

	((mk_lang_types_void_t)(session_impl->m_session_intr));
	((mk_lang_types_void_t)(session_impl->m_connection));
	((mk_lang_types_void_t)(session_impl->m_session_id));
	((mk_lang_types_void_t)(session_impl->m_destination));
	((mk_lang_types_void_t)(session_impl->m_did_something));
	err = mk_iip_cp_sessioncmd_leaseset_intr_rw_destruct(&session_impl->m_cmd_leaseset); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sm_tcp_intrs_rw_destroy(&session_impl->m_sms_tcp); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sessioncmd_message_intr_rw_destruct(&session_impl->m_cmd_message); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_allocate_and_construct(mk_iip_cp_session_impl_ppt const session_impl, mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);
	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_allocate(session_impl); mk_lang_check_rereturn(err); mk_lang_assert(*session_impl);
	err = mk_iip_cp_session_impl_rw_construct(*session_impl, session_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_destruct_and_deallocate(mk_iip_cp_session_impl_pt const session_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);

	err = mk_iip_cp_session_impl_rw_destruct(session_impl); mk_lang_check_rereturn(err);
	err = mk_iip_cp_session_impl_rw_deallocate(session_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_set_connection(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_connection_intr_pcpt const connection) mk_lang_noexcept
{
	mk_lang_assert(session_impl);
	mk_lang_assert(connection);

	session_impl->m_connection = *connection;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_set_session_id(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_type_sessionid_pct const session_id) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);
	mk_lang_assert(session_id);

	session_impl->m_session_id = *session_id;
	err = mk_iip_cp_sessioncmd_leaseset_intr_rw_set_session_id(&session_impl->m_cmd_leaseset, session_id); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sessioncmd_message_intr_rw_set_session_id(&session_impl->m_cmd_message, session_id); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_set_destination(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_type_destination_elgamal_dsa_pct const destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);
	mk_lang_assert(destination);

	session_impl->m_destination = *destination;
	err = mk_iip_cp_sessioncmd_leaseset_intr_rw_set_destination(&session_impl->m_cmd_leaseset, destination); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_connection_intr_pcpt mk_iip_cp_session_impl_rw_get_connection(mk_iip_cp_session_impl_pt const session_impl) mk_lang_noexcept
{
	mk_iip_cp_connection_intr_pcpt ret;

	mk_lang_assert(session_impl);

	ret = &session_impl->m_connection;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_sessionid_pct mk_iip_cp_session_impl_rw_get_session_id(mk_iip_cp_session_impl_pt const session_impl) mk_lang_noexcept
{
	mk_iip_cp_type_sessionid_pct ret;

	mk_lang_assert(session_impl);

	ret = &session_impl->m_session_id;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_destination_elgamal_dsa_pct mk_iip_cp_session_impl_rw_get_destination(mk_iip_cp_session_impl_pt const session_impl) mk_lang_noexcept
{
	mk_iip_cp_type_destination_elgamal_dsa_pct ret;

	mk_lang_assert(session_impl);

	ret = &session_impl->m_destination;
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_session_impl_rw_did_something(mk_iip_cp_session_impl_pt const session_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(session_impl);

	ret = session_impl->m_did_something;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_tick_single(mk_iip_cp_session_impl_pt const session_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);

	session_impl->m_did_something = mk_lang_false;
	if(!session_impl->m_did_something){ err = mk_iip_cp_sessioncmd_leaseset_intr_rw_tick_single(&session_impl->m_cmd_leaseset); mk_lang_check_rereturn(err); } if(mk_iip_cp_sessioncmd_leaseset_intr_rw_did_something(&session_impl->m_cmd_leaseset)){ session_impl->m_did_something = mk_lang_true; }
	if(!session_impl->m_did_something){ err = mk_iip_cp_sessioncmd_message_intr_rw_tick_single (&session_impl->m_cmd_message ); mk_lang_check_rereturn(err); } if(mk_iip_cp_sessioncmd_message_intr_rw_did_something (&session_impl->m_cmd_message )){ session_impl->m_did_something = mk_lang_true; }
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_on_msg(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_impl);
	mk_lang_assert(message);

	session_impl->m_did_something = mk_lang_false;
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
		case mk_iip_cp_message_message_type_e_request_lease_set         : err = mk_iip_cp_session_impl_pr_on_msg_request_lease_set(session_impl, message); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_message_message_type_e_message_status            : err = mk_iip_cp_session_impl_pr_on_msg_message_status(session_impl, message); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_message_message_type_e_bandwidth_limits          : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_report_abuse              : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_disconnect                : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_message_payload           : err = mk_iip_cp_session_impl_pr_on_msg_message_payload(session_impl, message); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_message_message_type_e_get_date                  : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_set_date                  : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_dest_lookup               : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_dest_reply                : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_send_message_expires      : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_request_variable_lease_set: err = mk_iip_cp_session_impl_pr_on_msg_request_variable_lease_set(session_impl, message); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_message_message_type_e_host_lookup               : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_host_reply                : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_create_lease_set2         : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_blinding_info             : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_make_msg(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_iip_cp_sm_tcp_intr_pt sm_tcp;

	mk_lang_assert(session_impl);
	mk_lang_assert(message);

	session_impl->m_did_something = mk_lang_false;
	if(!session_impl->m_did_something){  err = mk_iip_cp_sessioncmd_leaseset_intr_rw_make_msg(&session_impl->m_cmd_leaseset, message); mk_lang_check_rereturn(err); } if(mk_iip_cp_sessioncmd_leaseset_intr_rw_did_something(&session_impl->m_cmd_leaseset)){ session_impl->m_did_something = mk_lang_true; }
	if(!session_impl->m_did_something){  err = mk_iip_cp_sessioncmd_message_intr_rw_make_msg (&session_impl->m_cmd_message , message); mk_lang_check_rereturn(err); } if(mk_iip_cp_sessioncmd_message_intr_rw_did_something (&session_impl->m_cmd_message )){ session_impl->m_did_something = mk_lang_true; }
	if(!session_impl->m_did_something)
	{
		n = mk_iip_cp_sm_tcp_intrs_rw_size(&session_impl->m_sms_tcp);
		for(i = 0; i != n; ++i)
		{
			sm_tcp = mk_iip_cp_sm_tcp_intrs_rw_at(&session_impl->m_sms_tcp, i); mk_lang_assert(sm_tcp);
			err = mk_iip_cp_sm_tcp_intr_rw_make_msg(sm_tcp, message); mk_lang_check_rereturn(err);
			if(mk_iip_cp_sm_tcp_intr_rw_did_something(sm_tcp))
			{
				session_impl->m_did_something = mk_lang_true;
				break;
			}
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_accept(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_client_data_request_accept_pct const request, mk_iip_cp_client_data_response_accept_pt const response) mk_lang_noexcept
{
	mk_iip_cp_destination_pct destination;
	mk_lang_types_sint_t err;
	mk_iip_cp_sm_tcp_intr_pt sm_tcp;

	mk_lang_assert(session_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);
	mk_lang_assert(request->m_connection == session_impl->m_connection);
	mk_lang_assert(request->m_session == session_impl->m_session_intr);
	mk_lang_assert(request->m_socket);

	destination = mk_iip_cp_socket_tcp_intr_rw_get_destination(request->m_socket); mk_lang_assert(destination);
	mk_lang_assert(mk_lang_string_memcmp_uc_fn(((mk_lang_types_uchar_pct)(&session_impl->m_destination)), ((mk_lang_types_uchar_pct)(&destination->m_destination)), sizeof(destination->m_destination)) == 0);
	err = mk_iip_cp_sm_tcp_intrs_rw_push_back_void_one(&session_impl->m_sms_tcp); mk_lang_check_rereturn(err);
	sm_tcp = mk_iip_cp_sm_tcp_intrs_rw_back(&session_impl->m_sms_tcp); mk_lang_assert(sm_tcp);
	err = mk_iip_cp_sm_tcp_intr_rw_set_session_id(sm_tcp, &session_impl->m_session_id); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sm_tcp_intr_rw_set_local_destination(sm_tcp, &session_impl->m_destination); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sm_tcp_intr_rw_set_accept_rr(sm_tcp, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impl_rw_read_data(mk_iip_cp_session_impl_pt const session_impl, mk_iip_cp_client_data_request_read_data_pct const request, mk_iip_cp_client_data_response_read_data_pt const response) mk_lang_noexcept
{
	mk_iip_cp_destination_pct destination;
	mk_lang_types_sint_t err;
	mk_iip_cp_sm_tcp_intr_pcpt sm_tcp_p;
	mk_iip_cp_sm_tcp_intr_pt sm_tcp_v;

	mk_lang_assert(session_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);
	mk_lang_assert(request->m_connection == session_impl->m_connection);
	mk_lang_assert(request->m_session == session_impl->m_session_intr);
	mk_lang_assert(request->m_socket);

	destination = mk_iip_cp_socket_tcp_intr_rw_get_destination(request->m_socket); mk_lang_assert(destination);
	mk_lang_assert(mk_lang_string_memcmp_uc_fn(((mk_lang_types_uchar_pct)(&session_impl->m_destination)), ((mk_lang_types_uchar_pct)(&destination->m_destination)), sizeof(destination->m_destination)) == 0);
	sm_tcp_p = mk_iip_cp_socket_tcp_intr_rw_get_tcpsm(request->m_socket); mk_lang_assert(sm_tcp_p); sm_tcp_v = *sm_tcp_p; mk_lang_assert(sm_tcp_v);
	err = mk_iip_cp_sm_tcp_intr_rw_set_read_data_rr(sm_tcp_v, request, response); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impls_pr_element_construct_void(mk_iip_cp_session_impl_ppt const session) mk_lang_noexcept
{
	mk_lang_assert(session);

	*session = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_impls_pr_element_destruct(mk_iip_cp_session_impl_ppt const session) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session);
	mk_lang_assert(*session);

	err = mk_iip_cp_session_impl_rw_destruct_and_deallocate(*session); mk_lang_check_rereturn(err);
	return 0;
}

#define mk_sl_vector_t_name mk_iip_cp_session_impls
#define mk_sl_vector_t_element mk_iip_cp_session_impl_pt
#define mk_sl_vector_t_element_construct_void mk_iip_cp_session_impls_pr_element_construct_void
#define mk_sl_vector_t_element_destruct mk_iip_cp_session_impls_pr_element_destruct
#define mk_sl_vector_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
