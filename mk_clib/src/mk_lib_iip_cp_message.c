#ifndef mk_include_guard_mk_lib_iip_cp_message_c
#define mk_include_guard_mk_lib_iip_cp_message_c
#include "mk_lib_iip_cp_message.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_types.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_is_server_to_client(mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(message_type >= 0 && message_type < mk_lib_iip_cp_message_message_type_id_e_dummy_end);

	switch(message_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&ret);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_is_client_to_server(mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(message_type >= 0 && message_type < mk_lib_iip_cp_message_message_type_id_e_dummy_end);

	switch(message_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : ret = mk_lang_true ; break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&ret);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_is_per_connection(mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(message_type >= 0 && message_type < mk_lib_iip_cp_message_message_type_id_e_dummy_end);

	switch(message_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : ret = mk_lang_true; break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : ret = mk_lang_true; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&ret);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_message_is_per_session(mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(message_type >= 0 && message_type < mk_lib_iip_cp_message_message_type_id_e_dummy_end);

	switch(message_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : ret = mk_lang_true; break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : ret = mk_lang_true; break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : ret = mk_lang_true; break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : ret = mk_lang_false; break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: ret = mk_lang_true; break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : ret = 0; mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&ret);
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_create_session(mk_lib_iip_cp_message_create_session_pt const msg_create_session) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(msg_create_session);

	err = mk_lib_iip_cp_types_strpairs_rw_construct_void(&msg_create_session->m_session_config.m_options.m_strpairs); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_create_session(mk_lib_iip_cp_message_create_session_pt const msg_create_session) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(msg_create_session);

	err = mk_lib_iip_cp_types_strpairs_rw_destroy(&msg_create_session->m_session_config.m_options.m_strpairs); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_reconfigure_session(mk_lib_iip_cp_message_reconfigure_session_pt const msg_reconfigure_session) mk_lang_noexcept
{
	mk_lang_assert(msg_reconfigure_session);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_reconfigure_session(mk_lib_iip_cp_message_reconfigure_session_pt const msg_reconfigure_session) mk_lang_noexcept
{
	mk_lang_assert(msg_reconfigure_session);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_destroy_session(mk_lib_iip_cp_message_destroy_session_pt const msg_destroy_session) mk_lang_noexcept
{
	mk_lang_assert(msg_destroy_session);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_destroy_session(mk_lib_iip_cp_message_destroy_session_pt const msg_destroy_session) mk_lang_noexcept
{
	mk_lang_assert(msg_destroy_session);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_create_lease_set(mk_lib_iip_cp_message_create_lease_set_pt const msg_create_lease_set) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(msg_create_lease_set);

	err = mk_lib_iip_cp_types_leases_rw_construct_void(&msg_create_lease_set->m_leaseset.m_leases); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_create_lease_set(mk_lib_iip_cp_message_create_lease_set_pt const msg_create_lease_set) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(msg_create_lease_set);

	err = mk_lib_iip_cp_types_leases_rw_destroy(&msg_create_lease_set->m_leaseset.m_leases); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_send_message(mk_lib_iip_cp_message_send_message_pt const msg_send_message) mk_lang_noexcept
{
	mk_lang_assert(msg_send_message);

	((mk_lang_types_void_t)(msg_send_message->m_session_id));
	((mk_lang_types_void_t)(msg_send_message->m_destination));
	((mk_lang_types_void_t)(msg_send_message->m_payload));
	((mk_lang_types_void_t)(msg_send_message->m_nonce));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_send_message(mk_lib_iip_cp_message_send_message_pt const msg_send_message) mk_lang_noexcept
{
	mk_lang_assert(msg_send_message);

	((mk_lang_types_void_t)(msg_send_message->m_session_id));
	((mk_lang_types_void_t)(msg_send_message->m_destination));
	((mk_lang_types_void_t)(msg_send_message->m_payload));
	((mk_lang_types_void_t)(msg_send_message->m_nonce));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_receive_message_begin(mk_lib_iip_cp_message_receive_message_begin_pt const msg_receive_message_begin) mk_lang_noexcept
{
	mk_lang_assert(msg_receive_message_begin);

	((mk_lang_types_void_t)(msg_receive_message_begin->m_session_id));
	((mk_lang_types_void_t)(msg_receive_message_begin->m_message_id));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_receive_message_begin(mk_lib_iip_cp_message_receive_message_begin_pt const msg_receive_message_begin) mk_lang_noexcept
{
	mk_lang_assert(msg_receive_message_begin);

	((mk_lang_types_void_t)(msg_receive_message_begin->m_session_id));
	((mk_lang_types_void_t)(msg_receive_message_begin->m_message_id));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_receive_message_end(mk_lib_iip_cp_message_receive_message_end_pt const msg_receive_message_end) mk_lang_noexcept
{
	mk_lang_assert(msg_receive_message_end);

	((mk_lang_types_void_t)(msg_receive_message_end->m_session_id));
	((mk_lang_types_void_t)(msg_receive_message_end->m_message_id));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_receive_message_end(mk_lib_iip_cp_message_receive_message_end_pt const msg_receive_message_end) mk_lang_noexcept
{
	mk_lang_assert(msg_receive_message_end);

	((mk_lang_types_void_t)(msg_receive_message_end->m_session_id));
	((mk_lang_types_void_t)(msg_receive_message_end->m_message_id));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_get_bandwidth_limits(mk_lib_iip_cp_message_get_bandwidth_limits_pt const msg_get_bandwidth_limits) mk_lang_noexcept
{
	mk_lang_assert(msg_get_bandwidth_limits);

	((mk_lang_types_void_t)(msg_get_bandwidth_limits));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_get_bandwidth_limits(mk_lib_iip_cp_message_get_bandwidth_limits_pt const msg_get_bandwidth_limits) mk_lang_noexcept
{
	mk_lang_assert(msg_get_bandwidth_limits);

	((mk_lang_types_void_t)(msg_get_bandwidth_limits));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_session_status(mk_lib_iip_cp_message_session_status_pt const msg_session_status) mk_lang_noexcept
{
	mk_lang_assert(msg_session_status);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_session_status(mk_lib_iip_cp_message_session_status_pt const msg_session_status) mk_lang_noexcept
{
	mk_lang_assert(msg_session_status);

	((mk_lang_types_void_t)(msg_session_status));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_request_lease_set(mk_lib_iip_cp_message_request_lease_set_pt const msg_request_lease_set) mk_lang_noexcept
{
	mk_lang_assert(msg_request_lease_set);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_request_lease_set(mk_lib_iip_cp_message_request_lease_set_pt const msg_request_lease_set) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(msg_request_lease_set);

	err = mk_lib_iip_cp_types_hash_and_tunnelids_rw_destroy(&msg_request_lease_set->m_tunnels); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_message_status(mk_lib_iip_cp_message_message_status_pt const msg_message_status) mk_lang_noexcept
{
	mk_lang_assert(msg_message_status);

	((mk_lang_types_void_t)(msg_message_status->m_session_id));
	((mk_lang_types_void_t)(msg_message_status->m_message_id));
	((mk_lang_types_void_t)(msg_message_status->m_status));
	((mk_lang_types_void_t)(msg_message_status->m_size));
	((mk_lang_types_void_t)(msg_message_status->m_nonce));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_message_status(mk_lib_iip_cp_message_message_status_pt const msg_message_status) mk_lang_noexcept
{
	mk_lang_assert(msg_message_status);

	((mk_lang_types_void_t)(msg_message_status->m_session_id));
	((mk_lang_types_void_t)(msg_message_status->m_message_id));
	((mk_lang_types_void_t)(msg_message_status->m_status));
	((mk_lang_types_void_t)(msg_message_status->m_size));
	((mk_lang_types_void_t)(msg_message_status->m_nonce));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_bandwidth_limits(mk_lib_iip_cp_message_bandwidth_limits_pt const msg_bandwidth_limits) mk_lang_noexcept
{
	mk_lang_assert(msg_bandwidth_limits);

	((mk_lang_types_void_t)(msg_bandwidth_limits));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_bandwidth_limits(mk_lib_iip_cp_message_bandwidth_limits_pt const msg_bandwidth_limits) mk_lang_noexcept
{
	mk_lang_assert(msg_bandwidth_limits);

	((mk_lang_types_void_t)(msg_bandwidth_limits));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_report_abuse(mk_lib_iip_cp_message_report_abuse_pt const msg_report_abuse) mk_lang_noexcept
{
	mk_lang_assert(msg_report_abuse);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_report_abuse(mk_lib_iip_cp_message_report_abuse_pt const msg_report_abuse) mk_lang_noexcept
{
	mk_lang_assert(msg_report_abuse);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_disconnect(mk_lib_iip_cp_message_disconnect_pt const msg_disconnect) mk_lang_noexcept
{
	mk_lang_assert(msg_disconnect);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_disconnect(mk_lib_iip_cp_message_disconnect_pt const msg_disconnect) mk_lang_noexcept
{
	mk_lang_assert(msg_disconnect);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_message_payload(mk_lib_iip_cp_message_message_payload_pt const msg_message_payload) mk_lang_noexcept
{
	mk_lang_assert(msg_message_payload);

	((mk_lang_types_void_t)(msg_message_payload->m_session_id));
	((mk_lang_types_void_t)(msg_message_payload->m_message_id));
	((mk_lang_types_void_t)(msg_message_payload->m_payload));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_message_payload(mk_lib_iip_cp_message_message_payload_pt const msg_message_payload) mk_lang_noexcept
{
	mk_lang_assert(msg_message_payload);

	((mk_lang_types_void_t)(msg_message_payload->m_session_id));
	((mk_lang_types_void_t)(msg_message_payload->m_message_id));
	((mk_lang_types_void_t)(msg_message_payload->m_payload));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_get_date(mk_lib_iip_cp_message_get_date_pt const msg_get_date) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(msg_get_date);

	err = mk_lib_iip_cp_types_strpairs_rw_construct_void(&msg_get_date->m_authentication.m_strpairs); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_get_date(mk_lib_iip_cp_message_get_date_pt const msg_get_date) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(msg_get_date);

	err = mk_lib_iip_cp_types_strpairs_rw_destroy(&msg_get_date->m_authentication.m_strpairs); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_set_date(mk_lib_iip_cp_message_set_date_pt const msg_set_date) mk_lang_noexcept
{
	mk_lang_assert(msg_set_date);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_set_date(mk_lib_iip_cp_message_set_date_pt const msg_set_date) mk_lang_noexcept
{
	mk_lang_assert(msg_set_date);

	((mk_lang_types_void_t)(msg_set_date));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_dest_lookup(mk_lib_iip_cp_message_dest_lookup_pt const msg_dest_lookup) mk_lang_noexcept
{
	mk_lang_assert(msg_dest_lookup);

	((mk_lang_types_void_t)(msg_dest_lookup));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_dest_lookup(mk_lib_iip_cp_message_dest_lookup_pt const msg_dest_lookup) mk_lang_noexcept
{
	mk_lang_assert(msg_dest_lookup);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_dest_reply(mk_lib_iip_cp_message_dest_reply_pt const msg_dest_reply) mk_lang_noexcept
{
	mk_lang_assert(msg_dest_reply);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_dest_reply(mk_lib_iip_cp_message_dest_reply_pt const msg_dest_reply) mk_lang_noexcept
{
	mk_lang_assert(msg_dest_reply);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_send_message_expires(mk_lib_iip_cp_message_send_message_expires_pt const msg_send_message_expires) mk_lang_noexcept
{
	mk_lang_assert(msg_send_message_expires);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_send_message_expires(mk_lib_iip_cp_message_send_message_expires_pt const msg_send_message_expires) mk_lang_noexcept
{
	mk_lang_assert(msg_send_message_expires);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_request_variable_lease_set(mk_lib_iip_cp_message_request_variable_lease_set_pt const msg_request_variable_lease_set) mk_lang_noexcept
{
	mk_lang_assert(msg_request_variable_lease_set);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_request_variable_lease_set(mk_lib_iip_cp_message_request_variable_lease_set_pt const msg_request_variable_lease_set) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(msg_request_variable_lease_set);

	err = mk_lib_iip_cp_types_leases_rw_destroy(&msg_request_variable_lease_set->m_leases); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_host_lookup(mk_lib_iip_cp_message_host_lookup_pt const msg_host_lookup) mk_lang_noexcept
{
	mk_lang_assert(msg_host_lookup);

	((mk_lang_types_void_t)(msg_host_lookup));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_host_lookup(mk_lib_iip_cp_message_host_lookup_pt const msg_host_lookup) mk_lang_noexcept
{
	mk_lang_assert(msg_host_lookup);

	((mk_lang_types_void_t)(msg_host_lookup));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_host_reply(mk_lib_iip_cp_message_host_reply_pt const msg_host_reply) mk_lang_noexcept
{
	mk_lang_assert(msg_host_reply);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_host_reply(mk_lib_iip_cp_message_host_reply_pt const msg_host_reply) mk_lang_noexcept
{
	mk_lang_assert(msg_host_reply);

	((mk_lang_types_void_t)(msg_host_reply));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_create_lease_set2(mk_lib_iip_cp_message_create_lease_set2_pt const msg_create_lease_set2) mk_lang_noexcept
{
	mk_lang_assert(msg_create_lease_set2);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_create_lease_set2(mk_lib_iip_cp_message_create_lease_set2_pt const msg_create_lease_set2) mk_lang_noexcept
{
	mk_lang_assert(msg_create_lease_set2);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct_blinding_info(mk_lib_iip_cp_message_blinding_info_pt const msg_blinding_info) mk_lang_noexcept
{
	mk_lang_assert(msg_blinding_info);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy_blinding_info(mk_lib_iip_cp_message_blinding_info_pt const msg_blinding_info) mk_lang_noexcept
{
	mk_lang_assert(msg_blinding_info);

	mk_lang_check_todo();
	return 0;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_construct(mk_lib_iip_cp_message_pt const message, mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(message);
	mk_lang_assert(message_type >= 0 && message_type < mk_lib_iip_cp_message_message_type_id_e_dummy_end);

	message->m_header.m_len = 0;
	message->m_header.m_type = message_type;
	switch(message_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : err = mk_lib_iip_cp_message_construct_create_session            (&message->m_mix.m_data.m_create_session            ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : err = mk_lib_iip_cp_message_construct_reconfigure_session       (&message->m_mix.m_data.m_reconfigure_session       ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : err = mk_lib_iip_cp_message_construct_destroy_session           (&message->m_mix.m_data.m_destroy_session           ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : err = mk_lib_iip_cp_message_construct_create_lease_set          (&message->m_mix.m_data.m_create_lease_set          ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : err = mk_lib_iip_cp_message_construct_send_message              (&message->m_mix.m_data.m_send_message              ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : err = mk_lib_iip_cp_message_construct_receive_message_begin     (&message->m_mix.m_data.m_receive_message_begin     ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : err = mk_lib_iip_cp_message_construct_receive_message_end       (&message->m_mix.m_data.m_receive_message_end       ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : err = mk_lib_iip_cp_message_construct_get_bandwidth_limits      (&message->m_mix.m_data.m_get_bandwidth_limits      ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : err = mk_lib_iip_cp_message_construct_session_status            (&message->m_mix.m_data.m_session_status            ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : err = mk_lib_iip_cp_message_construct_request_lease_set         (&message->m_mix.m_data.m_request_lease_set         ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : err = mk_lib_iip_cp_message_construct_message_status            (&message->m_mix.m_data.m_message_status            ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : err = mk_lib_iip_cp_message_construct_bandwidth_limits          (&message->m_mix.m_data.m_bandwidth_limits          ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : err = mk_lib_iip_cp_message_construct_report_abuse              (&message->m_mix.m_data.m_report_abuse              ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : err = mk_lib_iip_cp_message_construct_disconnect                (&message->m_mix.m_data.m_disconnect                ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : err = mk_lib_iip_cp_message_construct_message_payload           (&message->m_mix.m_data.m_message_payload           ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : err = mk_lib_iip_cp_message_construct_get_date                  (&message->m_mix.m_data.m_get_date                  ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : err = mk_lib_iip_cp_message_construct_set_date                  (&message->m_mix.m_data.m_set_date                  ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : err = mk_lib_iip_cp_message_construct_dest_lookup               (&message->m_mix.m_data.m_dest_lookup               ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : err = mk_lib_iip_cp_message_construct_dest_reply                (&message->m_mix.m_data.m_dest_reply                ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : err = mk_lib_iip_cp_message_construct_send_message_expires      (&message->m_mix.m_data.m_send_message_expires      ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: err = mk_lib_iip_cp_message_construct_request_variable_lease_set(&message->m_mix.m_data.m_request_variable_lease_set); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : err = mk_lib_iip_cp_message_construct_host_lookup               (&message->m_mix.m_data.m_host_lookup               ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : err = mk_lib_iip_cp_message_construct_host_reply                (&message->m_mix.m_data.m_host_reply                ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : err = mk_lib_iip_cp_message_construct_create_lease_set2         (&message->m_mix.m_data.m_create_lease_set2         ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : err = mk_lib_iip_cp_message_construct_blinding_info             (&message->m_mix.m_data.m_blinding_info             ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_destroy(mk_lib_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(message);

	switch(message->m_header.m_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : err = mk_lib_iip_cp_message_destroy_create_session            (&message->m_mix.m_data.m_create_session            ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : err = mk_lib_iip_cp_message_destroy_reconfigure_session       (&message->m_mix.m_data.m_reconfigure_session       ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : err = mk_lib_iip_cp_message_destroy_destroy_session           (&message->m_mix.m_data.m_destroy_session           ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : err = mk_lib_iip_cp_message_destroy_create_lease_set          (&message->m_mix.m_data.m_create_lease_set          ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : err = mk_lib_iip_cp_message_destroy_send_message              (&message->m_mix.m_data.m_send_message              ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : err = mk_lib_iip_cp_message_destroy_receive_message_begin     (&message->m_mix.m_data.m_receive_message_begin     ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : err = mk_lib_iip_cp_message_destroy_receive_message_end       (&message->m_mix.m_data.m_receive_message_end       ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : err = mk_lib_iip_cp_message_destroy_get_bandwidth_limits      (&message->m_mix.m_data.m_get_bandwidth_limits      ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : err = mk_lib_iip_cp_message_destroy_session_status            (&message->m_mix.m_data.m_session_status            ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : err = mk_lib_iip_cp_message_destroy_request_lease_set         (&message->m_mix.m_data.m_request_lease_set         ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : err = mk_lib_iip_cp_message_destroy_message_status            (&message->m_mix.m_data.m_message_status            ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : err = mk_lib_iip_cp_message_destroy_bandwidth_limits          (&message->m_mix.m_data.m_bandwidth_limits          ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : err = mk_lib_iip_cp_message_destroy_report_abuse              (&message->m_mix.m_data.m_report_abuse              ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : err = mk_lib_iip_cp_message_destroy_disconnect                (&message->m_mix.m_data.m_disconnect                ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : err = mk_lib_iip_cp_message_destroy_message_payload           (&message->m_mix.m_data.m_message_payload           ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : err = mk_lib_iip_cp_message_destroy_get_date                  (&message->m_mix.m_data.m_get_date                  ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : err = mk_lib_iip_cp_message_destroy_set_date                  (&message->m_mix.m_data.m_set_date                  ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : err = mk_lib_iip_cp_message_destroy_dest_lookup               (&message->m_mix.m_data.m_dest_lookup               ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : err = mk_lib_iip_cp_message_destroy_dest_reply                (&message->m_mix.m_data.m_dest_reply                ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : err = mk_lib_iip_cp_message_destroy_send_message_expires      (&message->m_mix.m_data.m_send_message_expires      ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: err = mk_lib_iip_cp_message_destroy_request_variable_lease_set(&message->m_mix.m_data.m_request_variable_lease_set); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : err = mk_lib_iip_cp_message_destroy_host_lookup               (&message->m_mix.m_data.m_host_lookup               ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : err = mk_lib_iip_cp_message_destroy_host_reply                (&message->m_mix.m_data.m_host_reply                ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : err = mk_lib_iip_cp_message_destroy_create_lease_set2         (&message->m_mix.m_data.m_create_lease_set2         ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : err = mk_lib_iip_cp_message_destroy_blinding_info             (&message->m_mix.m_data.m_blinding_info             ); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_message_reconstruct(mk_lib_iip_cp_message_pt const message, mk_lib_iip_cp_message_message_type_id_t const message_type) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(message);
	mk_lang_assert(message_type >= 0 && message_type < mk_lib_iip_cp_message_message_type_id_e_dummy_end);

	if(message->m_header.m_type != message_type)
	{
		err = mk_lib_iip_cp_message_destroy(message); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_message_construct(message, message_type); mk_lang_check_rereturn(err);
	}
	return 0;
}


#endif
