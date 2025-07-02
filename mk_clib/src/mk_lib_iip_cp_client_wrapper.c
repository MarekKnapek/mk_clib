#ifndef mk_include_guard_mk_lib_iip_cp_client_wrapper_c
#define mk_include_guard_mk_lib_iip_cp_client_wrapper_c
#include "mk_lib_iip_cp_client_wrapper.h"

#include "mk_lang_check.h"
#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_client_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_client_application.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_construct(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_application_settings_pct const settings) mk_lang_noexcept
{
	mk_lib_iip_cp_client_application_settings_t config;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_application_task_pt app;
	mk_lang_types_void_pt mem;

	mk_lang_assert(task);
	mk_lang_assert(settings);

	config.m_iocp_settings.m_dummy = settings->m_iocp_settings.m_dummy;
	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*app), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); app = ((mk_lib_iip_cp_client_application_task_pt)(mem)); mk_lang_assert(app);
	err = mk_lib_iip_cp_client_application_task_rw_construct(app, &config); mk_lang_check_rereturn(err);
	task->m_wrapper.m_elements[0] = ((mk_lib_iip_cp_client_types_handle_wrapper_base_t)(app));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_destroy(mk_lib_iip_cp_client_wrapper_task_pt const task) mk_lang_noexcept
{
	mk_lib_iip_cp_client_application_task_pt app;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	app = ((mk_lib_iip_cp_client_application_task_pt)(task->m_wrapper.m_elements[0])); mk_lang_assert(app);
	err = mk_lib_iip_cp_client_application_task_rw_destroy(app); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_mallocator_global_deallocate(app, sizeof(*app)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_new_connection(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_connection_settings_pct const settings, mk_lib_iip_cp_client_types_handle_connection_pt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_settings_t config;
	mk_lib_iip_cp_client_application_task_pt app;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_connection_task_pt konnection;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(connection);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_wrapper_is_zero(&task->m_wrapper));

	config.m_destination = settings->m_destination;
	config.m_authentication.m_user_name = settings->m_authentication.m_user_name;
	config.m_authentication.m_password = settings->m_authentication.m_password;
	app = ((mk_lib_iip_cp_client_application_task_pt)(task->m_wrapper.m_elements[0])); mk_lang_assert(app);
	err = mk_lib_iip_cp_client_application_task_rw_new_connection(app, &config, &konnection); mk_lang_check_rereturn(err); mk_lang_assert(konnection);
	connection->m_elements[0] = ((mk_lib_iip_cp_client_types_handle_connection_base_t)(konnection));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_new_session(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_session_settings_pct const settings, mk_lib_iip_cp_client_types_handle_session_pt const session) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_settings_t config;
	mk_lib_iip_cp_client_connection_task_pt connection;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt zession;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(session);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_connection_is_zero(&settings->m_connection));

	config.m_destination = settings->m_destination;
	config.m_master_session.m_elements[0] = settings->m_master_session.m_elements[0];
	connection = ((mk_lib_iip_cp_client_connection_task_pt)(settings->m_connection.m_elements[0])); mk_lang_assert(connection);
	err = mk_lib_iip_cp_client_connection_task_rw_new_session(connection, &config, &zession); mk_lang_check_rereturn(err); mk_lang_assert(zession);
	session->m_elements[0] = ((mk_lib_iip_cp_client_types_handle_session_base_t)(zession));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_step(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_wrapper_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_application_task_pt app;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_application_task_result_t stp_res;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_wrapper_is_zero(&task->m_wrapper));

	app = ((mk_lib_iip_cp_client_application_task_pt)(task->m_wrapper.m_elements[0])); mk_lang_assert(app);
	stp_res = mk_lib_iip_cp_client_application_task_result_e_dummy_end;
	err = mk_lib_iip_cp_client_application_task_rw_step(app, allow_to_block, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_application_task_result_e_dummy_end);
	*step_result = ((mk_lib_iip_cp_client_wrapper_task_result_t)(stp_res));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_run_no_block(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lang_types_bool_pt const would_block) mk_lang_noexcept
{
	mk_lang_types_bool_t break2;
	mk_lib_iip_cp_client_wrapper_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(would_block);

	for(;;)
	{
		break2 = mk_lang_false;
		stp_res = mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end;
		err = mk_lib_iip_cp_client_wrapper_task_prrw_step(task, mk_lang_false, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end);
		switch(stp_res)
		{
			case mk_lib_iip_cp_client_wrapper_task_result_e_did_something: /* this is intentionally left blank */ break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_would_block: break2 = mk_lang_true; break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_did_nothing: break2 = mk_lang_true; break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}
		if(break2)
		{
			break;
		}
	}
	mk_lang_assert
	(
		(stp_res == mk_lib_iip_cp_client_wrapper_task_result_e_did_nothing) ||
		(stp_res == mk_lib_iip_cp_client_wrapper_task_result_e_would_block) ||
		mk_lang_false
	);
	*would_block = stp_res == mk_lib_iip_cp_client_wrapper_task_result_e_would_block;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_run_do_block(mk_lib_iip_cp_client_wrapper_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_bool_t break2;
	mk_lib_iip_cp_client_wrapper_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	for(;;)
	{
		break2 = mk_lang_false;
		stp_res = mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end;
		err = mk_lib_iip_cp_client_wrapper_task_prrw_step(task, mk_lang_true, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end);
		switch(stp_res)
		{
			case mk_lib_iip_cp_client_wrapper_task_result_e_did_something: /* this is intentionally left blank */ break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_would_block: mk_lang_assert_false(); break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_did_nothing: break2 = mk_lang_true; break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}
		if(break2)
		{
			break;
		}
	}
	mk_lang_assert(stp_res == mk_lib_iip_cp_client_wrapper_task_result_e_did_nothing);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_construct(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_application_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_construct(task, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_destroy(mk_lib_iip_cp_client_wrapper_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_new_connection(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_connection_settings_pct const settings, mk_lib_iip_cp_client_types_handle_connection_pt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_new_connection(task, settings, connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_new_session(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_session_settings_pct const settings, mk_lib_iip_cp_client_types_handle_session_pt const session) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_new_session(task, settings, session);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_step(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_wrapper_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_step(task, allow_to_block, step_result);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_run_no_block(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lang_types_bool_pt const would_block) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_run_no_block(task, would_block);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_run_do_block(mk_lib_iip_cp_client_wrapper_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_run_do_block(task);
}


#endif
