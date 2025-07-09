#ifndef mk_include_guard_mk_lib_iip_any_func_connection_c
#define mk_include_guard_mk_lib_iip_any_func_connection_c
#include "mk_lib_iip_any_func_connection.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_any_data.h"
#include "mk_lib_iip_any_data_connection.h"

#include "mk_lib_iip_cp_client_connection_task.h"
#include "mk_lib_iip_cp_client_local_client_task.h"
#include "mk_lib_iip_cp_client_local_listener_task.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_func_connection_rw_allocate(mk_lib_iip_any_data_connection_ppt const connection, mk_lib_iip_any_data_connection_type_t const type) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);
	mk_lang_assert(type >= 0);
	mk_lang_assert(type < mk_lib_iip_any_data_connection_type_e_dummy_end);

	switch(type)
	{
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task    : err = mk_lib_iip_cp_client_connection_task_any_rw_allocate    (connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_client_task  : err = mk_lib_iip_cp_client_local_client_task_any_rw_allocate  (connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_listener_task: err = mk_lib_iip_cp_client_local_listener_task_any_rw_allocate(connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_func_connection_rw_deallocate(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);
	mk_lang_assert(connection->m_data.m_id >= 0);
	mk_lang_assert(connection->m_data.m_id < mk_lib_iip_any_data_connection_type_e_dummy_end);

	switch(connection->m_data.m_id)
	{
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task    : err = mk_lib_iip_cp_client_connection_task_any_rw_deallocate    (connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_client_task  : err = mk_lib_iip_cp_client_local_client_task_any_rw_deallocate  (connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_listener_task: err = mk_lib_iip_cp_client_local_listener_task_any_rw_deallocate(connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_func_connection_rw_construct(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_void_pt const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);
	mk_lang_assert(connection->m_data.m_id >= 0);
	mk_lang_assert(connection->m_data.m_id < mk_lib_iip_any_data_connection_type_e_dummy_end);
	mk_lang_assert(settings || !settings);

	switch(connection->m_data.m_id)
	{
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task    : err = mk_lib_iip_cp_client_connection_task_any_rw_construct    (connection, settings); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_client_task  : err = mk_lib_iip_cp_client_local_client_task_any_rw_construct  (connection, settings); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_listener_task: err = mk_lib_iip_cp_client_local_listener_task_any_rw_construct(connection, settings); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_func_connection_rw_destroy(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);
	mk_lang_assert(connection->m_data.m_id >= 0);
	mk_lang_assert(connection->m_data.m_id < mk_lib_iip_any_data_connection_type_e_dummy_end);

	switch(connection->m_data.m_id)
	{
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task    : err = mk_lib_iip_cp_client_connection_task_any_rw_destroy    (connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_client_task  : err = mk_lib_iip_cp_client_local_client_task_any_rw_destroy  (connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_listener_task: err = mk_lib_iip_cp_client_local_listener_task_any_rw_destroy(connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_func_connection_rw_request_close(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);
	mk_lang_assert(connection->m_data.m_id >= 0);
	mk_lang_assert(connection->m_data.m_id < mk_lib_iip_any_data_connection_type_e_dummy_end);

	switch(connection->m_data.m_id)
	{
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task    : err = mk_lib_iip_cp_client_connection_task_any_rw_request_close    (connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_client_task  : err = mk_lib_iip_cp_client_local_client_task_any_rw_request_close  (connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_listener_task: err = mk_lib_iip_cp_client_local_listener_task_any_rw_request_close(connection); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_func_connection_rw_want_associate_socket(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);
	mk_lang_assert(connection->m_data.m_id >= 0);
	mk_lang_assert(connection->m_data.m_id < mk_lib_iip_any_data_connection_type_e_dummy_end);

	switch(connection->m_data.m_id)
	{
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task    : err = mk_lib_iip_cp_client_connection_task_any_rw_want_associate_socket    (connection, want); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_client_task  : err = mk_lib_iip_cp_client_local_client_task_any_rw_want_associate_socket  (connection, want); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_listener_task: err = mk_lib_iip_cp_client_local_listener_task_any_rw_want_associate_socket(connection, want); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_func_connection_rw_gimme_socket(mk_lib_iip_any_data_connection_pt const connection, mk_lib_net_socket_ppt const socket, mk_lib_iip_any_data_connection_ppt const associatee) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);
	mk_lang_assert(connection->m_data.m_id >= 0);
	mk_lang_assert(connection->m_data.m_id < mk_lib_iip_any_data_connection_type_e_dummy_end);

	switch(connection->m_data.m_id)
	{
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task    : err = mk_lib_iip_cp_client_connection_task_any_rw_gimme_socket    (connection, socket, associatee); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_client_task  : err = mk_lib_iip_cp_client_local_client_task_any_rw_gimme_socket  (connection, socket, associatee); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_listener_task: err = mk_lib_iip_cp_client_local_listener_task_any_rw_gimme_socket(connection, socket, associatee); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_func_connection_rw_on_iorp_done(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);
	mk_lang_assert(connection->m_data.m_id >= 0);
	mk_lang_assert(connection->m_data.m_id < mk_lib_iip_any_data_connection_type_e_dummy_end);

	switch(connection->m_data.m_id)
	{
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task    : err = mk_lib_iip_cp_client_connection_task_any_rw_on_iorp_done    (connection, successful_io_operation, bytes_transferred, overlapped); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_client_task  : err = mk_lib_iip_cp_client_local_client_task_any_rw_on_iorp_done  (connection, successful_io_operation, bytes_transferred, overlapped); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_listener_task: err = mk_lib_iip_cp_client_local_listener_task_any_rw_on_iorp_done(connection, successful_io_operation, bytes_transferred, overlapped); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_func_connection_rw_step(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_any_data_connection_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);
	mk_lang_assert(connection->m_data.m_id >= 0);
	mk_lang_assert(connection->m_data.m_id < mk_lib_iip_any_data_connection_type_e_dummy_end);

	switch(connection->m_data.m_id)
	{
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task    : err = mk_lib_iip_cp_client_connection_task_any_rw_step    (connection, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_client_task  : err = mk_lib_iip_cp_client_local_client_task_any_rw_step  (connection, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_listener_task: err = mk_lib_iip_cp_client_local_listener_task_any_rw_step(connection, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_func_connection_rw_want_die(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);
	mk_lang_assert(connection->m_data.m_id >= 0);
	mk_lang_assert(connection->m_data.m_id < mk_lib_iip_any_data_connection_type_e_dummy_end);

	switch(connection->m_data.m_id)
	{
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task    : err = mk_lib_iip_cp_client_connection_task_any_rw_want_die    (connection, want); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_client_task  : err = mk_lib_iip_cp_client_local_client_task_any_rw_want_die  (connection, want); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_local_listener_task: err = mk_lib_iip_cp_client_local_listener_task_any_rw_want_die(connection, want); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_any_data_connection_type_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


#endif
