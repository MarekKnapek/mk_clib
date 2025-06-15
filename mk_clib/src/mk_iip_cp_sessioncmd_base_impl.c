#ifndef mk_include_guard_mk_iip_cp_sessioncmd_base_impl_c
#define mk_include_guard_mk_iip_cp_sessioncmd_base_impl_c
#include "mk_iip_cp_sessioncmd_base_impl.h"

#include "mk_iip_cp_message.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_mallocatorg.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_impl_rw_allocate(mk_iip_cp_sessioncmd_base_impl_ppt const sessioncmd_base_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_impl);

	err = mk_sl_mallocatorg_allocate(sizeof(**sessioncmd_base_impl), ((mk_lang_types_void_ppt)(sessioncmd_base_impl))); mk_lang_check_rereturn(err); mk_lang_assert(*sessioncmd_base_impl);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_impl_rw_deallocate(mk_iip_cp_sessioncmd_base_impl_pt const sessioncmd_base_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_impl);

	err = mk_sl_mallocatorg_deallocate(sessioncmd_base_impl, sizeof(*sessioncmd_base_impl)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_impl_rw_construct(mk_iip_cp_sessioncmd_base_impl_pt const sessioncmd_base_impl, mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_base_impl);
	mk_lang_assert(sessioncmd_base_intr);

	sessioncmd_base_impl->m_sessioncmd_base_intr = sessioncmd_base_intr;
	((mk_lang_types_void_t)(sessioncmd_base_impl->m_session_id));
	((mk_lang_types_void_t)(sessioncmd_base_impl->m_did_something));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_impl_rw_destruct(mk_iip_cp_sessioncmd_base_impl_pt const sessioncmd_base_impl) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_base_impl);

	((mk_lang_types_void_t)(sessioncmd_base_impl->m_sessioncmd_base_intr));
	((mk_lang_types_void_t)(sessioncmd_base_impl->m_session_id));
	((mk_lang_types_void_t)(sessioncmd_base_impl->m_did_something));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_impl_rw_allocate_and_construct(mk_iip_cp_sessioncmd_base_impl_ppt const sessioncmd_base_impl, mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_impl);
	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_impl_rw_allocate(sessioncmd_base_impl); mk_lang_check_rereturn(err); mk_lang_assert(*sessioncmd_base_impl);
	err = mk_iip_cp_sessioncmd_base_impl_rw_construct(*sessioncmd_base_impl, sessioncmd_base_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_impl_rw_destruct_and_deallocate(mk_iip_cp_sessioncmd_base_impl_pt const sessioncmd_base_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_impl);

	err = mk_iip_cp_sessioncmd_base_impl_rw_destruct(sessioncmd_base_impl); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sessioncmd_base_impl_rw_deallocate(sessioncmd_base_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_impl_rw_set_session_id(mk_iip_cp_sessioncmd_base_impl_pt const sessioncmd_base_impl, mk_iip_cp_type_sessionid_pct const session_id) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_base_impl);
	mk_lang_assert(session_id);

	sessioncmd_base_impl->m_session_id = session_id;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_sessionid_pct mk_iip_cp_sessioncmd_base_impl_rw_get_session_id(mk_iip_cp_sessioncmd_base_impl_pt const sessioncmd_base_impl) mk_lang_noexcept
{
	mk_iip_cp_type_sessionid_pct ret;

	mk_lang_assert(sessioncmd_base_impl);

	ret = sessioncmd_base_impl->m_session_id;
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_sessioncmd_base_impl_rw_did_something(mk_iip_cp_sessioncmd_base_impl_pt const sessioncmd_base_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(sessioncmd_base_impl);

	ret = sessioncmd_base_impl->m_did_something;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_impl_rw_on_msg(mk_iip_cp_sessioncmd_base_impl_pt const sessioncmd_base_impl, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_base_impl);
	mk_lang_assert(message);

	sessioncmd_base_impl->m_did_something = mk_lang_false;
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
		case mk_iip_cp_message_message_type_e_message_payload           : mk_lang_check_todo(); break;
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_impl_rw_make_msg(mk_iip_cp_sessioncmd_base_impl_pt const sessioncmd_base_impl, mk_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_base_impl);
	mk_lang_assert(message);

	sessioncmd_base_impl->m_did_something = mk_lang_false;
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_impl_rw_tick_single(mk_iip_cp_sessioncmd_base_impl_pt const sessioncmd_base_impl) mk_lang_noexcept
{
	mk_lang_assert(sessioncmd_base_impl);

	sessioncmd_base_impl->m_did_something = mk_lang_false;
	mk_lang_check_todo();
	return 0;
}


#endif
