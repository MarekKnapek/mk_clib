#ifndef mk_include_guard_mk_iip_cp_sessioncmd_leaseset_impl_c
#define mk_include_guard_mk_iip_cp_sessioncmd_leaseset_impl_c
#include "mk_iip_cp_sessioncmd_leaseset_impl.h"

#include "mk_iip_cp_helper.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_message.h"
#include "mk_iip_cp_type.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint64.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_pr_prune_leases(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl) mk_lang_noexcept
{
	mk_iip_cp_type_date_t now;
	mk_lang_types_bool_t repeat;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_iip_cp_type_lease_pt lease;
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_leaseset_impl);

	mk_iip_cp_helper_get_time_now(&now.m_ms_since_unix);
	/* todo more efficient algorithm */
	do
	{
		repeat = mk_lang_false;
		n = mk_iip_cp_type_leasess_rw_size(&sessioncmd_leaseset_impl->m_confirmed);
		for(i = 0; i != n; ++i)
		{
			lease = mk_iip_cp_type_leasess_rw_at(&sessioncmd_leaseset_impl->m_confirmed, i); mk_lang_assert(lease);
			if(mk_sl_cui_uint64_lt(&lease->m_end_date.m_ms_since_unix, &now.m_ms_since_unix))
			{
				err = mk_iip_cp_type_leasess_rw_erase_element(&sessioncmd_leaseset_impl->m_confirmed, lease); mk_lang_check_rereturn(err);
				repeat = mk_lang_true;
				break;
			}
		}
	}while(repeat);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_pr_on_msg_request_lease_set(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl, mk_iip_cp_message_request_lease_set_pct const msg_request_lease_set) mk_lang_noexcept
{
	mk_lang_types_usize_t count;
	mk_lang_types_sint_t err;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_iip_cp_type_hash_and_tunnelid_pct tunnel;
	mk_iip_cp_type_lease_pt lease;

	mk_lang_assert(sessioncmd_leaseset_impl);
	mk_lang_assert(msg_request_lease_set);
	mk_lang_assert(sessioncmd_leaseset_impl->m_session_id);
	mk_lang_assert(mk_sl_cui_uint16_eq(&msg_request_lease_set->m_session_id.m_id, &sessioncmd_leaseset_impl->m_session_id->m_id));

	count = mk_iip_cp_type_hash_and_tunnelids_ro_size(&msg_request_lease_set->m_tunnels);
	if(count != 0)
	{
		err = mk_iip_cp_type_leasess_rw_reserve_additional(&sessioncmd_leaseset_impl->m_unconfirmed, count); mk_lang_check_rereturn(err);
		n = count;
		for(i = 0; i != n; ++i)
		{
			tunnel = mk_iip_cp_type_hash_and_tunnelids_ro_at(&msg_request_lease_set->m_tunnels, i); mk_lang_assert(tunnel);
			err = mk_iip_cp_type_leasess_rw_push_back_void_one(&sessioncmd_leaseset_impl->m_unconfirmed); mk_lang_check_rereturn(err);
			lease = mk_iip_cp_type_leasess_rw_back(&sessioncmd_leaseset_impl->m_unconfirmed); mk_lang_assert(lease);
			lease->m_router_hash = tunnel->m_router_hash;
			lease->m_tunnel_id = tunnel->m_tunnel_id;
			lease->m_end_date = msg_request_lease_set->m_end_date;
		}
		err = mk_iip_cp_sessioncmd_leaseset_impl_pr_prune_leases(sessioncmd_leaseset_impl); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_todo(); /* todo issue warning about empty leaseset */
	}
	sessioncmd_leaseset_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_pr_on_msg_request_variable_lease_set(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl, mk_iip_cp_message_request_variable_lease_set_pct const msg_request_variable_lease_set) mk_lang_noexcept
{
	mk_lang_types_usize_t count;
	mk_lang_types_sint_t err;
	mk_iip_cp_type_lease_pct tunnels;

	mk_lang_assert(sessioncmd_leaseset_impl);
	mk_lang_assert(msg_request_variable_lease_set);
	mk_lang_assert(sessioncmd_leaseset_impl->m_session_id);
	mk_lang_assert(mk_sl_cui_uint16_eq(&msg_request_variable_lease_set->m_session_id.m_id, &sessioncmd_leaseset_impl->m_session_id->m_id));

	count = mk_iip_cp_type_leases_ro_size(&msg_request_variable_lease_set->m_leases);
	if(count != 0)
	{
		tunnels = mk_iip_cp_type_leases_ro_data(&msg_request_variable_lease_set->m_leases); mk_lang_assert(tunnels);
		err = mk_iip_cp_type_leasess_rw_push_back_many(&sessioncmd_leaseset_impl->m_unconfirmed, tunnels, count); mk_lang_check_rereturn(err);
		err = mk_iip_cp_sessioncmd_leaseset_impl_pr_prune_leases(sessioncmd_leaseset_impl); mk_lang_check_rereturn(err);
	}
	else
	{
		mk_lang_check_todo(); /* todo issue warning about empty leaseset */
	}
	sessioncmd_leaseset_impl->m_did_something = mk_lang_true;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_allocate(mk_iip_cp_sessioncmd_leaseset_impl_ppt const sessioncmd_leaseset_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_leaseset_impl);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**sessioncmd_leaseset_impl), ((mk_lang_types_void_ppt)(sessioncmd_leaseset_impl))); mk_lang_check_rereturn(err); mk_lang_assert(*sessioncmd_leaseset_impl);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_deallocate(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_leaseset_impl);

	err = mk_iip_cp_mallocator_global_deallocate(sessioncmd_leaseset_impl, sizeof(*sessioncmd_leaseset_impl)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_construct(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl, mk_iip_cp_sessioncmd_leaseset_intr_pt const sessioncmd_leaseset_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_leaseset_impl);
	mk_lang_assert(sessioncmd_leaseset_intr);

	sessioncmd_leaseset_impl->m_sessioncmd_leaseset_intr = sessioncmd_leaseset_intr;
	((mk_lang_types_void_t)(sessioncmd_leaseset_impl->m_session_id));
	((mk_lang_types_void_t)(sessioncmd_leaseset_impl->m_destination));
	((mk_lang_types_void_t)(sessioncmd_leaseset_impl->m_did_something));
	err = mk_iip_cp_type_leasess_rw_construct(&sessioncmd_leaseset_impl->m_unconfirmed); mk_lang_check_rereturn(err);
	err = mk_iip_cp_type_leasess_rw_construct(&sessioncmd_leaseset_impl->m_confirmed); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_destruct(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_leaseset_impl);

	((mk_lang_types_void_t)(sessioncmd_leaseset_impl->m_sessioncmd_leaseset_intr));
	((mk_lang_types_void_t)(sessioncmd_leaseset_impl->m_session_id));
	((mk_lang_types_void_t)(sessioncmd_leaseset_impl->m_destination));
	((mk_lang_types_void_t)(sessioncmd_leaseset_impl->m_did_something));
	err = mk_iip_cp_type_leasess_rw_destroy(&sessioncmd_leaseset_impl->m_unconfirmed); mk_lang_check_rereturn(err);
	err = mk_iip_cp_type_leasess_rw_destroy(&sessioncmd_leaseset_impl->m_confirmed); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_allocate_and_construct(mk_iip_cp_sessioncmd_leaseset_impl_ppt const sessioncmd_leaseset_impl, mk_iip_cp_sessioncmd_leaseset_intr_pt const sessioncmd_leaseset_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_leaseset_impl);
	mk_lang_assert(sessioncmd_leaseset_intr);

	err = mk_iip_cp_sessioncmd_leaseset_impl_rw_allocate(sessioncmd_leaseset_impl); mk_lang_check_rereturn(err); mk_lang_assert(*sessioncmd_leaseset_impl);
	err = mk_iip_cp_sessioncmd_leaseset_impl_rw_construct(*sessioncmd_leaseset_impl, sessioncmd_leaseset_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_destruct_and_deallocate(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_leaseset_impl);

	err = mk_iip_cp_sessioncmd_leaseset_impl_rw_destruct(sessioncmd_leaseset_impl); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sessioncmd_leaseset_impl_rw_deallocate(sessioncmd_leaseset_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_set_session_id(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl, mk_iip_cp_type_sessionid_pct const session_id) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_leaseset_impl);
	mk_lang_assert(session_id);

	sessioncmd_leaseset_impl->m_session_id = session_id;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_set_destination(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl, mk_iip_cp_type_destination_elgamal_dsa_pct const destination) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_leaseset_impl);
	mk_lang_assert(destination);

	sessioncmd_leaseset_impl->m_destination = destination;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_sessionid_pct mk_iip_cp_sessioncmd_leaseset_impl_rw_get_session_id(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl) mk_lang_noexcept
{
	mk_iip_cp_type_sessionid_pct ret;

	mk_lang_assert(sessioncmd_leaseset_impl);

	ret = sessioncmd_leaseset_impl->m_session_id;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_destination_elgamal_dsa_pct mk_iip_cp_sessioncmd_leaseset_impl_rw_get_destination(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl) mk_lang_noexcept
{
	mk_iip_cp_type_destination_elgamal_dsa_pct ret;

	mk_lang_assert(sessioncmd_leaseset_impl);

	ret = sessioncmd_leaseset_impl->m_destination;
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_sessioncmd_leaseset_impl_rw_did_something(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(sessioncmd_leaseset_impl);

	ret = sessioncmd_leaseset_impl->m_did_something;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_on_msg(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_leaseset_impl);
	mk_lang_assert(message);

	sessioncmd_leaseset_impl->m_did_something = mk_lang_false;
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
		case mk_iip_cp_message_message_type_e_request_lease_set         : err = mk_iip_cp_sessioncmd_leaseset_impl_pr_on_msg_request_lease_set(sessioncmd_leaseset_impl, &message->m_mix.m_data.m_request_lease_set); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_message_message_type_e_message_status            : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_bandwidth_limits          : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_report_abuse              : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_disconnect                : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_message_payload           : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_get_date                  : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_set_date                  : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_dest_lookup               : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_dest_reply                : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_send_message_expires      : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_request_variable_lease_set: err = mk_iip_cp_sessioncmd_leaseset_impl_pr_on_msg_request_variable_lease_set(sessioncmd_leaseset_impl, &message->m_mix.m_data.m_request_variable_lease_set); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_message_message_type_e_host_lookup               : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_host_reply                : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_create_lease_set2         : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_blinding_info             : mk_lang_check_todo(); break;
		case mk_iip_cp_message_message_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_make_msg(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl, mk_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_message_create_lease_set_pt msg_create_lease_set;
	mk_lang_types_usize_t count_have;
	mk_lang_types_usize_t count_tocopy;
	mk_iip_cp_type_lease_pct leases_start;

	mk_lang_assert(sessioncmd_leaseset_impl);
	mk_lang_assert(message);
	mk_lang_assert(sessioncmd_leaseset_impl->m_session_id);
	mk_lang_assert(sessioncmd_leaseset_impl->m_destination);

	sessioncmd_leaseset_impl->m_did_something = mk_lang_false;
	if(!mk_iip_cp_type_leasess_ro_is_empty(&sessioncmd_leaseset_impl->m_unconfirmed))
	{
		err = mk_iip_cp_sessioncmd_leaseset_impl_pr_prune_leases(sessioncmd_leaseset_impl); mk_lang_check_rereturn(err);
	}
	if(!mk_iip_cp_type_leasess_ro_is_empty(&sessioncmd_leaseset_impl->m_unconfirmed))
	{
		err = mk_iip_cp_message_reconstruct(message, mk_iip_cp_message_message_type_e_create_lease_set); mk_lang_check_rereturn(err);
		msg_create_lease_set = &message->m_mix.m_data.m_create_lease_set;
		msg_create_lease_set->m_session_id = *sessioncmd_leaseset_impl->m_session_id;
		msg_create_lease_set->m_key_sgn_pri = sessioncmd_leaseset_impl->m_destination->m_key_dsa_pri;
		msg_create_lease_set->m_key_enc_pri = sessioncmd_leaseset_impl->m_destination->m_key_elgamal_pri;
		msg_create_lease_set->m_leaseset.m_destination = *sessioncmd_leaseset_impl->m_destination;
		err = mk_iip_cp_type_leases_rw_clear_dy(&msg_create_lease_set->m_leaseset.m_leases); mk_lang_check_rereturn(err);
		count_have = mk_iip_cp_type_leasess_rw_size(&sessioncmd_leaseset_impl->m_unconfirmed);
		count_tocopy = mk_lang_min(((mk_lang_types_usize_t)(mk_iip_cp_type_leases_len_v)), count_have);
		leases_start = mk_iip_cp_type_leasess_ro_at(&sessioncmd_leaseset_impl->m_unconfirmed, count_have - count_tocopy); mk_lang_assert(leases_start);
		err = mk_iip_cp_type_leases_rw_push_back_many(&msg_create_lease_set->m_leaseset.m_leases, leases_start, count_tocopy); mk_lang_check_rereturn(err);
		err = mk_iip_cp_type_leasess_rw_push_back_many(&sessioncmd_leaseset_impl->m_confirmed, leases_start, count_tocopy); mk_lang_check_rereturn(err);
		err = mk_iip_cp_type_leasess_rw_pop_back_many_dy(&sessioncmd_leaseset_impl->m_unconfirmed, count_tocopy); mk_lang_check_rereturn(err);
		sessioncmd_leaseset_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_leaseset_impl_rw_tick_single(mk_iip_cp_sessioncmd_leaseset_impl_pt const sessioncmd_leaseset_impl) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_leaseset_impl);

	sessioncmd_leaseset_impl->m_did_something = mk_lang_false;
	return 0;
}


#endif
