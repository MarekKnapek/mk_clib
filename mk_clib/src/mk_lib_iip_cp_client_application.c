#ifndef mk_include_guard_mk_lib_iip_cp_client_application_c
#define mk_include_guard_mk_lib_iip_cp_client_application_c
#include "mk_lib_iip_cp_client_application.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_client_iocp.h"
#include "mk_lib_iip_cp_client_shared.h"
#include "mk_lib_iip_cp_mallocator_global.h"


mk_lang_forward(mk_lib_iip_cp_client_connection_settings);
mk_lang_forward(mk_lib_iip_cp_client_connection_task);


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_prrw_construct(mk_lib_iip_cp_client_application_task_pt const task, mk_lib_iip_cp_client_application_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(settings);

	task->m_step = ((mk_lib_iip_cp_client_application_task_step_t)(0));
	task->m_application.m_settings = *settings;
	err = mk_lib_iip_cp_client_shared_rw_construct(&task->m_application.m_state.m_shared); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_iocp_task_rw_construct(&task->m_application.m_state.m_iocp, &task->m_application.m_state.m_shared, &task->m_application.m_settings.m_iocp_settings); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_prrw_destroy(mk_lib_iip_cp_client_application_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_client_shared_rw_destroy(&task->m_application.m_state.m_shared); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_iocp_task_rw_destroy(&task->m_application.m_state.m_iocp); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_prrw_new_connection(mk_lib_iip_cp_client_application_task_pt const task, mk_lib_iip_cp_client_connection_settings_pct const settings, mk_lib_iip_cp_client_connection_task_ppt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(connection);

	err = mk_lib_iip_cp_client_iocp_task_rw_new_connection(&task->m_application.m_state.m_iocp, settings, connection); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_prrw_step_ready(mk_lib_iip_cp_client_application_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_application_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_iocp_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_application_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_application_task_step_e_ready);

	stp_res = mk_lib_iip_cp_client_iocp_task_result_e_dummy_end;
	err = mk_lib_iip_cp_client_iocp_task_rw_step(&task->m_application.m_state.m_iocp, allow_to_block, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_iocp_task_result_e_dummy_end);
	switch(stp_res)
	{
		case mk_lib_iip_cp_client_iocp_task_result_e_did_something: *step_result = mk_lib_iip_cp_client_application_task_result_e_did_something; break;
		case mk_lib_iip_cp_client_iocp_task_result_e_would_block  : *step_result = mk_lib_iip_cp_client_application_task_result_e_would_block  ; break;
		case mk_lib_iip_cp_client_iocp_task_result_e_did_nothing  : *step_result = mk_lib_iip_cp_client_application_task_result_e_did_nothing  ; break;
		case mk_lib_iip_cp_client_iocp_task_result_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_prrw_step(mk_lib_iip_cp_client_application_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_application_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_application_task_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_application_task_step_e_ready: err = mk_lib_iip_cp_client_application_task_prrw_step_ready(task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_iocp_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_rw_construct(mk_lib_iip_cp_client_application_task_pt const task, mk_lib_iip_cp_client_application_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_application_task_prrw_construct(task, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_rw_destroy(mk_lib_iip_cp_client_application_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_application_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_rw_new_connection(mk_lib_iip_cp_client_application_task_pt const task, mk_lib_iip_cp_client_connection_settings_pct const settings, mk_lib_iip_cp_client_connection_task_ppt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_application_task_prrw_new_connection(task, settings, connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_rw_step(mk_lib_iip_cp_client_application_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_application_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_application_task_prrw_step(task, allow_to_block, step_result);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_ptr_rw_construct_void(mk_lib_iip_cp_client_application_task_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_ptr_rw_destroy(mk_lib_iip_cp_client_application_task_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_application_task_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_application_task_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_ptr_rw_construct_copy(mk_lib_iip_cp_client_application_task_ppt const dst, mk_lib_iip_cp_client_application_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_ptr_rw_construct_move(mk_lib_iip_cp_client_application_task_ppt const dst, mk_lib_iip_cp_client_application_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_ptr_rw_assign_copy(mk_lib_iip_cp_client_application_task_ppt const dst, mk_lib_iip_cp_client_application_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_ptr_rw_assign_move(mk_lib_iip_cp_client_application_task_ppt const dst, mk_lib_iip_cp_client_application_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_application_tasks
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_application_task_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_application_task_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_application_task_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_application_task_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_application_task_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_application_task_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_application_task_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
