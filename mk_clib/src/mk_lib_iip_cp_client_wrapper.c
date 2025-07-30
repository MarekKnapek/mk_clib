#ifndef mk_include_guard_mk_lib_iip_cp_client_wrapper_c
#define mk_include_guard_mk_lib_iip_cp_client_wrapper_c
#include "mk_lib_iip_cp_client_wrapper.h"

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_charbit.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_any_data_connection.h"
#include "mk_lib_iip_cp_client_application.h"
#include "mk_lib_iip_cp_client_connection_task.h"
#include "mk_lib_iip_cp_client_local_listener_task.h"
#include "mk_lib_iip_cp_client_socket.h"
#include "mk_lib_iip_cp_client_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"


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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_request_close(mk_lib_iip_cp_client_wrapper_task_pt const task) mk_lang_noexcept
{
	mk_lib_iip_cp_client_application_task_pt app;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_wrapper_is_zero(&task->m_wrapper));

	app = ((mk_lib_iip_cp_client_application_task_pt)(task->m_wrapper.m_elements[0])); mk_lang_assert(app);
	err = mk_lib_iip_cp_client_application_task_rw_request_close(app); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_poke(mk_lib_iip_cp_client_wrapper_task_pt const task) mk_lang_noexcept
{
	mk_lib_iip_cp_client_application_task_pt app;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	app = ((mk_lib_iip_cp_client_application_task_pt)(task->m_wrapper.m_elements[0])); mk_lang_assert(app);
	err = mk_lib_iip_cp_client_application_task_rw_poke(app); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_new_local(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_local_settings_pct const settings, mk_lib_iip_cp_client_types_handle_local_pt const local) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_listener_task_settings_t config;
	mk_lib_iip_cp_client_application_task_pt app;
	mk_lang_types_sint_t err;
	mk_lib_iip_any_data_connection_pt lokal;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(local);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_wrapper_is_zero(&task->m_wrapper));

	config.m_destination = settings->m_destination;
	app = ((mk_lib_iip_cp_client_application_task_pt)(task->m_wrapper.m_elements[0])); mk_lang_assert(app);
	err = mk_lib_iip_cp_client_application_task_rw_new_local_listener(app, &config, &lokal); mk_lang_check_rereturn(err); mk_lang_assert(lokal);
	local->m_elements[0] = ((mk_lib_iip_cp_client_types_handle_local_base_t)(lokal));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_new_connection(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_connection_settings_pct const settings, mk_lib_iip_cp_client_types_handle_connection_pt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_settings_t config;
	mk_lib_iip_cp_client_application_task_pt app;
	mk_lang_types_sint_t err;
	mk_lib_iip_any_data_connection_pt konnection;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(connection);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_wrapper_is_zero(&task->m_wrapper));

	config.m_destination = settings->m_destination;
	config.m_authentication.m_username = settings->m_authentication.m_username;
	config.m_authentication.m_password = settings->m_authentication.m_password;
	app = ((mk_lib_iip_cp_client_application_task_pt)(task->m_wrapper.m_elements[0])); mk_lang_assert(app);
	err = mk_lib_iip_cp_client_application_task_rw_new_connection(app, &config, &konnection); mk_lang_check_rereturn(err); mk_lang_assert(konnection);
	connection->m_elements[0] = ((mk_lib_iip_cp_client_types_handle_connection_base_t)(konnection));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_new_session(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_session_settings_pct const settings, mk_lib_iip_cp_client_types_handle_session_pt const session) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_settings_t config;
	mk_lib_iip_any_data_connection_pt connection;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt zession;
	
	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(session);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_connection_is_zero(&settings->m_connection));

	config.m_destination = settings->m_destination;
	config.m_master_session.m_elements[0] = settings->m_master_session.m_elements[0];
	config.m_options = settings->m_options;
	connection = ((mk_lib_iip_any_data_connection_pt)(settings->m_connection.m_elements[0])); mk_lang_assert(connection);
	mk_lang_assert(connection->m_data.m_id == mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task);
	err = mk_lib_iip_cp_client_connection_task_any_rw_new_session(connection, &config, &zession); mk_lang_check_rereturn(err); mk_lang_assert(zession);
	session->m_elements[0] = ((mk_lib_iip_cp_client_types_handle_session_base_t)(zession));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_lookup_host_name(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_lookup_host_name_pt const request) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t uptr;
	mk_lib_iip_cp_client_session_task_pt session;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(request);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_session_is_zero(&request->m_session));
	mk_lang_assert(request->m_host_name_buf);
	mk_lang_assert(request->m_host_name_buf[0] != '\0');
	mk_lang_assert(request->m_host_name_len >= 0x01);
	mk_lang_assert(request->m_host_name_len <= 0xff);
	mk_lang_assert(request->m_done == mk_lang_false);

	mk_lib_iip_cp_client_types_handle_session_to_base(&request->m_session, &uptr); mk_lang_assert(uptr != 0);
	session = ((mk_lib_iip_cp_client_session_task_pt)(uptr)); mk_lang_assert(session);
	err = mk_lib_iip_cp_client_session_task_rw_lookup_host_name(session, request); mk_lang_check_rereturn(err);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_lookup_host_name_is_zero(&request->m_internal));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_new_socket_listener(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_socket_listener_settings_pct const settings, mk_lib_iip_cp_client_types_handle_socket_listener_pt const socket_listener) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t uptr;
	mk_lib_iip_cp_client_session_task_pt session;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(socket_listener);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_session_is_zero(&settings->m_session));

	((mk_lang_types_void_t)(task));
	mk_lib_iip_cp_client_types_handle_session_to_base(&settings->m_session, &uptr); mk_lang_assert(uptr != 0);
	session = ((mk_lib_iip_cp_client_session_task_pt)(uptr)); mk_lang_assert(session);
	err = mk_lib_iip_cp_client_session_task_rw_new_socket_listener(session, settings, socket_listener); mk_lang_check_rereturn(err);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_socket_listener_is_zero(socket_listener));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_socket_recv(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_handle_socket_listener_pt const socket_listener, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const recvd) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t uptr;
	mk_lib_iip_cp_client_socket_task_pt sck_lst;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(socket_listener);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(recvd);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_socket_listener_is_zero(socket_listener));

	((mk_lang_types_void_t)(task));
	mk_lib_iip_cp_client_types_handle_socket_listener_to_base(socket_listener, &uptr); mk_lang_assert(uptr != 0);
	sck_lst = ((mk_lib_iip_cp_client_socket_task_pt)(uptr)); mk_lang_assert(sck_lst);
	err = mk_lib_iip_cp_client_socket_task_rw_recv(sck_lst, data_buf, data_len, recvd); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_socket_send(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_handle_socket_listener_pt const socket_listener, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const sent) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t uptr;
	mk_lib_iip_cp_client_socket_task_pt sck_lst;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(socket_listener);
	mk_lang_assert(data_buf || data_len == 0);
	mk_lang_assert(data_len >= 0);
	mk_lang_assert(sent);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_socket_listener_is_zero(socket_listener));

	((mk_lang_types_void_t)(task));
	mk_lib_iip_cp_client_types_handle_socket_listener_to_base(socket_listener, &uptr); mk_lang_assert(uptr != 0);
	sck_lst = ((mk_lib_iip_cp_client_socket_task_pt)(uptr)); mk_lang_assert(sck_lst);
	err = mk_lib_iip_cp_client_socket_task_rw_send(sck_lst, data_buf, data_len, sent); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_step(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_wrapper_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_application_task_pt app;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_application_task_result_t stp_res;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_wrapper_is_zero(&task->m_wrapper));

	app = ((mk_lib_iip_cp_client_application_task_pt)(task->m_wrapper.m_elements[0])); mk_lang_assert(app);
	stp_res = mk_lib_iip_cp_client_application_task_result_e_dummy_end;
	err = mk_lib_iip_cp_client_application_task_rw_step(app, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_application_task_result_e_dummy_end);
	*step_result = ((mk_lib_iip_cp_client_wrapper_task_result_t)(stp_res));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_run_no_block(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_wrapper_task_result_pt const result) mk_lang_noexcept
{
	mk_lang_types_bool_t break2;
	mk_lib_iip_cp_client_wrapper_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(result);
	mk_lang_assert(*result == mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end);

	for(;;)
	{
		break2 = mk_lang_false;
		stp_res = mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end;
		err = mk_lib_iip_cp_client_wrapper_task_prrw_step(task, mk_lang_false, 0, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end);
		switch(stp_res)
		{
			case mk_lib_iip_cp_client_wrapper_task_result_e_did_something: /* this is intentionally left blank */ break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_would_block: break2 = mk_lang_true; break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_timed_out: mk_lang_assert_false(); break;
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
	*result = stp_res;
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
		err = mk_lib_iip_cp_client_wrapper_task_prrw_step(task, mk_lang_true, -1, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end);
		switch(stp_res)
		{
			case mk_lib_iip_cp_client_wrapper_task_result_e_did_something: /* this is intentionally left blank */ break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_would_block: mk_lang_assert_false(); break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_timed_out: mk_lang_assert_false(); break;
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_prrw_run_block_tm(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_wrapper_task_result_pt const result) mk_lang_noexcept
{
	mk_lang_types_bool_t break2;
	mk_lib_iip_cp_client_wrapper_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(tm >= 0);
	mk_lang_assert(tm <= 10 * 60 * 1000);
	mk_lang_assert(result);
	mk_lang_assert(*result == mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end);

	for(;;)
	{
		break2 = mk_lang_false;
		stp_res = mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end;
		err = mk_lib_iip_cp_client_wrapper_task_prrw_step(task, mk_lang_true, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_wrapper_task_result_e_dummy_end);
		switch(stp_res)
		{
			case mk_lib_iip_cp_client_wrapper_task_result_e_did_something: /* this is intentionally left blank */ break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_would_block: mk_lang_assert_false(); break;
			case mk_lib_iip_cp_client_wrapper_task_result_e_timed_out: break2 = mk_lang_true; break;
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
		(stp_res == mk_lib_iip_cp_client_wrapper_task_result_e_timed_out) ||
		(stp_res == mk_lib_iip_cp_client_wrapper_task_result_e_did_nothing) ||
		mk_lang_false
	);
	*result = stp_res;
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_request_close(mk_lib_iip_cp_client_wrapper_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_request_close(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_poke(mk_lib_iip_cp_client_wrapper_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_poke(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_new_local_listener(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_local_settings_pct const settings, mk_lib_iip_cp_client_types_handle_local_pt const local) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_new_local(task, settings, local);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_new_connection(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_connection_settings_pct const settings, mk_lib_iip_cp_client_types_handle_connection_pt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_new_connection(task, settings, connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_new_session(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_session_settings_pct const settings, mk_lib_iip_cp_client_types_handle_session_pt const session) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_new_session(task, settings, session);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_lookup_host_name(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_lookup_host_name_pt const request) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_lookup_host_name(task, request);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_new_socket_listener(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_socket_listener_settings_pct const settings, mk_lib_iip_cp_client_types_handle_socket_listener_pt const socket_listener) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_new_socket_listener(task, settings, socket_listener);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_socket_recv(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_handle_socket_listener_pt const socket_listener, mk_sl_cui_uint8_pt const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const recvd) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_socket_recv(task, socket_listener, data_buf, data_len, recvd);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_socket_send(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_types_handle_socket_listener_pt const socket_listener, mk_sl_cui_uint8_pct const data_buf, mk_lang_types_sint_t const data_len, mk_lang_types_sint_pt const sent) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_socket_send(task, socket_listener, data_buf, data_len, sent);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_step(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_wrapper_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_step(task, allow_to_block, tm, step_result);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_run_no_block(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lib_iip_cp_client_wrapper_task_result_pt const result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_run_no_block(task, result);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_run_do_block(mk_lib_iip_cp_client_wrapper_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_run_do_block(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_wrapper_task_rw_run_block_tm(mk_lib_iip_cp_client_wrapper_task_pt const task, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_wrapper_task_result_pt const result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_wrapper_task_prrw_run_block_tm(task, tm, result);
}


#endif
