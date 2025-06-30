#ifndef mk_include_guard_mk_lib_iip_cp_client_iocp_c
#define mk_include_guard_mk_lib_iip_cp_client_iocp_c
#include "mk_lib_iip_cp_client_iocp.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_client_connection.h"
#include "mk_lib_iip_cp_mallocator_global.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_construct(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lib_iip_cp_client_shared_pt const shared, mk_lib_iip_cp_client_iocp_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(shared);
	mk_lang_assert(settings);

	task->m_step = ((mk_lib_iip_cp_client_iocp_task_step_t)(0));
	task->m_iocp.m_settings = *settings;
	task->m_iocp.m_state.m_shared = shared;
	err = mk_lib_iip_cp_client_connection_tasks_rw_construct(&task->m_iocp.m_state.m_connections); mk_lang_check_rereturn(err);
	task->m_iocp.m_state.m_connection_idx = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_destroy(mk_lib_iip_cp_client_iocp_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_client_connection_tasks_rw_destroy(&task->m_iocp.m_state.m_connections); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_new_connection(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lib_iip_cp_client_connection_settings_pct const settings, mk_lib_iip_cp_client_connection_task_ppt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_connection_task_pt con;
	mk_lang_types_void_pt mem;
	mk_lib_iip_cp_client_connection_task_pt kon;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(connection);

	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*con), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); con = ((mk_lib_iip_cp_client_connection_task_pt)(mem)); mk_lang_assert(con); kon = con; mk_lang_assert(kon);
	err = mk_lib_iip_cp_client_connection_task_rw_construct(con, task->m_iocp.m_state.m_shared, settings); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_tasks_rw_push_back_move_single(&task->m_iocp.m_state.m_connections, &con); mk_lang_check_rereturn(err);
	*connection = kon;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_step_ready(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_iocp_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_usize_t count;
	mk_lang_types_bool_t break2;
	mk_lib_iip_cp_client_connection_task_pt connection_would_block;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lib_iip_cp_client_connection_task_ppt connection_ptr;
	mk_lib_iip_cp_client_connection_task_pt connection_val;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_iocp_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_iocp_task_step_e_ready);

	count = mk_lib_iip_cp_client_connection_tasks_rw_size(&task->m_iocp.m_state.m_connections);
	if(count != 0)
	{
		break2 = mk_lang_false;
		connection_would_block = mk_lang_null;
		n = count;
		for(i = 0; i != n; ++i)
		{
			idx = (task->m_iocp.m_state.m_connection_idx + i) % count;
			++task->m_iocp.m_state.m_connection_idx;
			connection_ptr = mk_lib_iip_cp_client_connection_tasks_rw_at(&task->m_iocp.m_state.m_connections, idx); mk_lang_assert(connection_ptr); connection_val = *connection_ptr; mk_lang_assert(connection_val);
			stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end;
			err = mk_lib_iip_cp_client_connection_task_rw_step(connection_val, mk_lang_false, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
			switch(stp_res)
			{
				case mk_lib_iip_cp_client_connection_task_result_e_did_something:
				{
					break2 = mk_lang_true;
				}
				break;
				case mk_lib_iip_cp_client_connection_task_result_e_would_block:
				{
					if(!connection_would_block)
					{
						connection_would_block = connection_val;
					}
				}
				break;
				case mk_lib_iip_cp_client_connection_task_result_e_did_nothing:
				{
					/* this is intentionally left blank */
				}
				break;
				case mk_lib_iip_cp_client_connection_task_result_e_dummy_end: mk_lang_assert_false(); break;
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
			mk_lang_assert(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_something);
			*step_result = mk_lib_iip_cp_client_iocp_task_result_e_did_something;
		}
		else
		{
			if(connection_would_block)
			{
				if(allow_to_block)
				{
					stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end;
					err = mk_lib_iip_cp_client_connection_task_rw_step(connection_would_block, mk_lang_true, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
					mk_lang_assert(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_something);
					*step_result = mk_lib_iip_cp_client_iocp_task_result_e_did_something;
				}
				else
				{
					*step_result = mk_lib_iip_cp_client_iocp_task_result_e_would_block;
				}
			}
			else
			{
				mk_lang_clobber(&stp_res);
				mk_lang_assert(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing);
				*step_result = mk_lib_iip_cp_client_iocp_task_result_e_did_nothing;
			}
		}
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_iocp_task_result_e_did_nothing;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_prrw_step(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_iocp_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_iocp_task_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_iocp_task_step_e_ready: err = mk_lib_iip_cp_client_iocp_task_prrw_step_ready(task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_iocp_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_iocp_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_rw_new_connection(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lib_iip_cp_client_connection_settings_pct const settings, mk_lib_iip_cp_client_connection_task_ppt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_iocp_task_prrw_new_connection(task, settings, connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_iocp_task_rw_step(mk_lib_iip_cp_client_iocp_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_iocp_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_iocp_task_prrw_step(task, allow_to_block, step_result);
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
