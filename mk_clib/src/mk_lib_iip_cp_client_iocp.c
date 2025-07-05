#ifndef mk_include_guard_mk_lib_iip_cp_client_iocp_c
#define mk_include_guard_mk_lib_iip_cp_client_iocp_c
#include "mk_lib_iip_cp_client_iocp.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_client_connection_task.h"
#include "mk_lib_iip_cp_client_local_task.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_net_connection_any1.h"
#include "mk_lib_net_iocp.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_connections_elm_rw_construct_void(mk_lib_net_connection_any2_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_connections_elm_rw_destroy(mk_lib_net_connection_any2_ppt const x) mk_lang_noexcept
{
	mk_lib_net_connection_any2_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_net_connection_any2_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_connections_elm_rw_construct_copy(mk_lib_net_connection_any2_ppt const dst, mk_lib_net_connection_any2_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_connections_elm_rw_construct_move(mk_lib_net_connection_any2_ppt const dst, mk_lib_net_connection_any2_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_connections_elm_rw_assign_copy(mk_lib_net_connection_any2_ppt const dst, mk_lib_net_connection_any2_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_connections_elm_rw_assign_move(mk_lib_net_connection_any2_ppt const dst, mk_lib_net_connection_any2_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_iocp_connections
#define mk_sl_vector_t_element_type mk_lib_net_connection_any2_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_iocp_connections_elm_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_iocp_connections_elm_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_iocp_connections_elm_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_iocp_connections_elm_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_iocp_connections_elm_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_iocp_connections_elm_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_construct(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lib_iip_cp_client_shared_pt const shared, mk_lib_iip_cp_client_iocp_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(shared);
	mk_lang_assert(settings);

	task->m_step = ((mk_lib_iip_cp_client_iocp_task_step_t)(0));
	task->m_iocp.m_settings = *settings;
	task->m_iocp.m_state.m_shared = shared;
	err = mk_lib_net_iocp_construct(&task->m_iocp.m_state.m_iocp, 0); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_iocp_connections_rw_construct(&task->m_iocp.m_state.m_connections); mk_lang_check_rereturn(err);
	task->m_iocp.m_state.m_connection_idx = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_destroy(mk_lib_iip_cp_client_iocp_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_client_iocp_connections_rw_destroy(&task->m_iocp.m_state.m_connections); mk_lang_check_rereturn(err);
	err = mk_lib_net_iocp_destroy(&task->m_iocp.m_state.m_iocp); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_poke(mk_lib_iip_cp_client_iocp_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_net_iocp_post(&task->m_iocp.m_state.m_iocp, 0, mk_lang_limits_uintptr_max, mk_lang_null); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_new_local(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lib_iip_cp_client_local_settings_pct const settings, mk_lib_net_connection_any2_ppt const local) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_settings_t config;
	mk_lang_types_sint_t err;
	mk_lib_net_connection_any2_pt con;
	mk_lang_types_void_pt mem;
	mk_lib_net_connection_any2_pt kon;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(local);

	config = *settings;
	config.m_shared = task->m_iocp.m_state.m_shared;
	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*con), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); con = ((mk_lib_net_connection_any2_pt)(mem)); mk_lang_assert(con); kon = con; mk_lang_assert(kon);
	err = mk_lib_net_connection_any2_rw_construct(con, mk_lib_net_connection_any1_id_e_mk_lib_iip_cp_client_local_task, &config); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_iocp_connections_rw_push_back_move_single(&task->m_iocp.m_state.m_connections, &con); mk_lang_check_rereturn(err);
	*local = kon;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_new_connection(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lib_iip_cp_client_connection_settings_pct const settings, mk_lib_net_connection_any2_ppt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_settings_t config;
	mk_lang_types_sint_t err;
	mk_lib_net_connection_any2_pt con;
	mk_lang_types_void_pt mem;
	mk_lib_net_connection_any2_pt kon;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(connection);

	config = *settings;
	config.m_shared = task->m_iocp.m_state.m_shared;
	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*con), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); con = ((mk_lib_net_connection_any2_pt)(mem)); mk_lang_assert(con); kon = con; mk_lang_assert(kon);
	err = mk_lib_net_connection_any2_rw_construct(con, mk_lib_net_connection_any1_id_e_mk_lib_iip_cp_client_connection_task, &config); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_iocp_connections_rw_push_back_move_single(&task->m_iocp.m_state.m_connections, &con); mk_lang_check_rereturn(err);
	*connection = kon;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_wait_for_iocp_packet(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lang_types_sint_t const tm, mk_lang_types_bool_pt const is_ready) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t dequeued;
	mk_lang_types_bool_t successful_io_operation;
	mk_lang_types_sint_t bytes_transferred;
	mk_lang_types_uintptr_t key;
	mk_lang_types_void_pt overlapped;
	mk_lang_types_uint_t fail_reason;
	mk_lang_types_bool_t rdy;
	mk_lib_net_connection_any2_pt connection;

	mk_lang_assert(task);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(is_ready);

	if(tm == -1)
	{
		err = mk_lib_net_iocp_dequeue_packet_infinite(&task->m_iocp.m_state.m_iocp, &dequeued, &successful_io_operation, &bytes_transferred, &key, &overlapped, &fail_reason); mk_lang_check_rereturn(err);
		rdy = mk_lang_true;
	}
	else
	{
		err = mk_lib_net_iocp_dequeue_packet_tm(&task->m_iocp.m_state.m_iocp, tm, &rdy, &dequeued, &successful_io_operation, &bytes_transferred, &key, &overlapped, &fail_reason); mk_lang_check_rereturn(err);
	}
	if(rdy)
	{
		mk_lang_check_return(dequeued);
		mk_lang_check_return(successful_io_operation); /* todo */
		if(key != mk_lang_limits_uintptr_max)
		{
			mk_lang_assert(key != 0); connection = ((mk_lib_net_connection_any2_pt)(key)); mk_lang_assert(connection);
			err = mk_lib_net_connection_any2_rw_on_iorp_done(connection, bytes_transferred, overlapped); mk_lang_check_rereturn(err);
		}
		else
		{
			/* poke */
		}
	}
	*is_ready = rdy;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_step_ready_did_nothing_yet(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_iocp_task_result_pt const step_result, mk_lang_types_bool_t const at_least_one_would_block, mk_lang_types_bool_t const at_least_one_did_nothing) mk_lang_noexcept
{
	mk_lang_types_bool_t did_something;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lib_net_connection_any2_ppt connection_ptr;
	mk_lib_net_connection_any2_pt connection_val;
	mk_lib_net_socket_pt socket;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t break2;
	mk_lib_net_connection_any2_result_t stp_res;
	mk_lang_types_bool_t is_ready;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(at_least_one_would_block == mk_lang_true || at_least_one_would_block == mk_lang_false);
	mk_lang_assert(at_least_one_did_nothing == mk_lang_true || at_least_one_did_nothing == mk_lang_false);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_iocp_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_iocp_task_step_e_ready);

	did_something = mk_lang_false;
	if(!did_something && at_least_one_did_nothing)
	{
		n = mk_lib_iip_cp_client_iocp_connections_rw_size(&task->m_iocp.m_state.m_connections);
		for(i = 0; i != n; ++i)
		{
			idx = (task->m_iocp.m_state.m_connection_idx + i) % n;
			connection_ptr = mk_lib_iip_cp_client_iocp_connections_rw_at(&task->m_iocp.m_state.m_connections, idx); mk_lang_assert(connection_ptr); connection_val = *connection_ptr; mk_lang_assert(connection_val);
			if(mk_lib_net_connection_any2_rw_want_associate_socket(connection_val))
			{
				socket = mk_lib_net_connection_any2_rw_gimme_socket(connection_val); mk_lang_assert(socket);
				err = mk_lib_net_iocp_associate_with_socket(&task->m_iocp.m_state.m_iocp, ((mk_lang_types_uintptr_t)(connection_val)), socket); mk_lang_check_rereturn(err);
				did_something = mk_lang_true;
				*step_result = mk_lib_iip_cp_client_iocp_task_result_e_did_something;
				break;
			}
		}
	}
	if(!did_something && at_least_one_would_block && allow_to_block)
	{
		n = mk_lib_iip_cp_client_iocp_connections_rw_size(&task->m_iocp.m_state.m_connections);
		for(i = 0; i != n; ++i)
		{
			break2 = mk_lang_false;
			idx = (task->m_iocp.m_state.m_connection_idx + i) % n;
			connection_ptr = mk_lib_iip_cp_client_iocp_connections_rw_at(&task->m_iocp.m_state.m_connections, idx); mk_lang_assert(connection_ptr); connection_val = *connection_ptr; mk_lang_assert(connection_val);
			stp_res = mk_lib_net_connection_any2_result_e_dummy_end;
			err = mk_lib_net_connection_any2_rw_step(connection_val, mk_lang_true, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_net_connection_any2_result_e_dummy_end);
			switch(stp_res)
			{
				case mk_lib_net_connection_any2_result_e_did_something:
				{
					break2 = mk_lang_true;
					did_something = mk_lang_true;
					*step_result = mk_lib_iip_cp_client_iocp_task_result_e_did_something;
				}
				break;
				case mk_lib_net_connection_any2_result_e_would_block: /* this is intentionally left blank */ break;
				case mk_lib_net_connection_any2_result_e_timed_out:
				{
					break2 = mk_lang_true;
					did_something = mk_lang_true;
					*step_result = mk_lib_iip_cp_client_iocp_task_result_e_timed_out;
				}
				break;
				case mk_lib_net_connection_any2_result_e_did_nothing: /* this is intentionally left blank */ break;
				case mk_lib_net_connection_any2_result_e_dummy_end: mk_lang_assert_false(); break;
				default: mk_lang_assert_false(); break;
			}
			if(break2)
			{
				break;
			}
		}
	}
	if(!did_something && at_least_one_would_block && allow_to_block)
	{
		err = mk_lib_iip_cp_client_iocp_task_prrw_wait_for_iocp_packet(task, tm, &is_ready); mk_lang_check_rereturn(err);
		if(is_ready)
		{
			did_something = mk_lang_true;
			*step_result = mk_lib_iip_cp_client_iocp_task_result_e_did_something;
		}
		else
		{
			did_something = mk_lang_true;
			*step_result = mk_lib_iip_cp_client_iocp_task_result_e_timed_out;
		}
	}
	if(!did_something && !allow_to_block)
	{
		*step_result = mk_lib_iip_cp_client_iocp_task_result_e_would_block;
		did_something = mk_lang_true;
	}
	if(!did_something && at_least_one_did_nothing && allow_to_block)
	{
		*step_result = mk_lib_iip_cp_client_iocp_task_result_e_did_nothing;
		did_something = mk_lang_true;
	}
	mk_lang_assert(did_something);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_step_ready(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_iocp_task_result_pt const step_result) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_lang_types_usize_t count;
	mk_lang_types_bool_t break2;
	mk_lang_types_bool_t at_least_one_would_block;
	mk_lang_types_bool_t at_least_one_did_nothing;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lib_net_connection_any2_ppt connection_ptr;
	mk_lib_net_connection_any2_pt connection_val;
	mk_lib_net_connection_any2_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_iocp_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_iocp_task_step_e_ready);

	count = mk_lib_iip_cp_client_iocp_connections_rw_size(&task->m_iocp.m_state.m_connections);
	if(count != 0)
	{
		break2 = mk_lang_false;
		at_least_one_would_block = mk_lang_false;
		at_least_one_did_nothing = mk_lang_false;
		n = count;
		for(i = 0; i != n; ++i)
		{
			idx = (task->m_iocp.m_state.m_connection_idx + i) % count;
			++task->m_iocp.m_state.m_connection_idx;
			connection_ptr = mk_lib_iip_cp_client_iocp_connections_rw_at(&task->m_iocp.m_state.m_connections, idx); mk_lang_assert(connection_ptr); connection_val = *connection_ptr; mk_lang_assert(connection_val);
			stp_res = mk_lib_net_connection_any2_result_e_dummy_end;
			err = mk_lib_net_connection_any2_rw_step(connection_val, mk_lang_false, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_net_connection_any2_result_e_dummy_end);
			switch(stp_res)
			{
				case mk_lib_net_connection_any2_result_e_did_something:
				{
					break2 = mk_lang_true;
				}
				break;
				case mk_lib_net_connection_any2_result_e_would_block:
				{
					at_least_one_would_block = mk_lang_true;
				}
				break;
				case mk_lib_net_connection_any2_result_e_timed_out:
				{
					mk_lang_assert_false();
				}
				break;
				case mk_lib_net_connection_any2_result_e_did_nothing:
				{
					at_least_one_did_nothing = mk_lang_true;
				}
				break;
				case mk_lib_net_connection_any2_result_e_dummy_end: mk_lang_assert_false(); break;
				default: mk_lang_assert_false(); break;
			}
			if(break2)
			{
				break;
			}
		}
		if(i != n)
		{
			mk_lang_clobber(&stp_res);
			mk_lang_assert(stp_res == mk_lib_net_connection_any2_result_e_did_something);
			*step_result = mk_lib_iip_cp_client_iocp_task_result_e_did_something;
		}
		else
		{
			err = mk_lib_iip_cp_client_iocp_task_prrw_step_ready_did_nothing_yet(task, allow_to_block, tm, step_result, at_least_one_would_block, at_least_one_did_nothing); mk_lang_check_rereturn(err);
		}
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_iocp_task_result_e_did_nothing;
	}
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_step(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_iocp_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_iocp_task_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_iocp_task_step_e_ready: err = mk_lib_iip_cp_client_iocp_task_prrw_step_ready(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_iocp_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_iocp_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_request_close(mk_lib_iip_cp_client_iocp_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_net_connection_any2_ppt connection_ptr;
	mk_lib_net_connection_any2_pt connection_val;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	n = mk_lib_iip_cp_client_iocp_connections_rw_size(&task->m_iocp.m_state.m_connections);
	for(i = 0; i != n; ++i)
	{
		connection_ptr = mk_lib_iip_cp_client_iocp_connections_rw_at(&task->m_iocp.m_state.m_connections, i); mk_lang_assert(connection_ptr); connection_val = *connection_ptr; mk_lang_assert(connection_val);
		err = mk_lib_net_connection_any2_rw_request_close(connection_val); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_rw_construct(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lib_iip_cp_client_shared_pt const shared, mk_lib_iip_cp_client_iocp_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_iocp_task_prrw_construct(task, shared, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_rw_destroy(mk_lib_iip_cp_client_iocp_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_iocp_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_rw_poke(mk_lib_iip_cp_client_iocp_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_iocp_task_prrw_poke(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_rw_new_local(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lib_iip_cp_client_local_settings_pct const settings, mk_lib_net_connection_any2_ppt const local) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_iocp_task_prrw_new_local(task, settings, local);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_rw_new_connection(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lib_iip_cp_client_connection_settings_pct const settings, mk_lib_net_connection_any2_ppt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_iocp_task_prrw_new_connection(task, settings, connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_rw_step(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_iocp_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_iocp_task_prrw_step(task, allow_to_block, tm, step_result);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_rw_request_close(mk_lib_iip_cp_client_iocp_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_iocp_task_prrw_request_close(task);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_ptr_rw_construct_void(mk_lib_iip_cp_client_iocp_task_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_ptr_rw_destroy(mk_lib_iip_cp_client_iocp_task_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_iocp_task_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_iocp_task_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_ptr_rw_construct_copy(mk_lib_iip_cp_client_iocp_task_ppt const dst, mk_lib_iip_cp_client_iocp_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_ptr_rw_construct_move(mk_lib_iip_cp_client_iocp_task_ppt const dst, mk_lib_iip_cp_client_iocp_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_ptr_rw_assign_copy(mk_lib_iip_cp_client_iocp_task_ppt const dst, mk_lib_iip_cp_client_iocp_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_ptr_rw_assign_move(mk_lib_iip_cp_client_iocp_task_ppt const dst, mk_lib_iip_cp_client_iocp_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_iocp_tasks
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_iocp_task_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_iocp_task_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_iocp_task_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_iocp_task_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_iocp_task_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_iocp_task_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_iocp_task_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
