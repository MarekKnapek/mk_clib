#ifndef mk_include_guard_mk_lib_iip_cp_client_application_c
#define mk_include_guard_mk_lib_iip_cp_client_application_c
#include "mk_lib_iip_cp_client_application.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_roundup.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_client_session.h"
#include "mk_lib_iip_cp_client_shared.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_parse.h"
#include "mk_lib_iip_cp_message_serialize.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_iip_logger.h"
#include "mk_lib_net.h"
#include "mk_sl_cui_uint8.h"


#define mk_sl_cui_t_name mk_lib_iip_cp_client_application_handle
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#if defined mk_lib_iip_cp_client_application_debug_print_want
#if (mk_lib_iip_cp_client_application_debug_print_want) == 0
#define mk_lib_iip_cp_client_application_debug_print_have 0
#elif (mk_lib_iip_cp_client_application_debug_print_want) == 1
#define mk_lib_iip_cp_client_application_debug_print_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_lib_iip_cp_client_application_debug_print_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lib_iip_cp_client_application_debug_print_have 0
#else
#define mk_lib_iip_cp_client_application_debug_print_have 1
#endif
#endif
#endif


#if mk_lib_iip_cp_client_application_debug_print_have
#include "mk_lib_fmt.h"
#include "mk_lib_iip_cp_message_str.h"
#include "mk_lib_iip_time.h"
#include "mk_sl_time.h"
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_prrw_construct(mk_lib_iip_cp_client_application_task_pt const task, mk_lib_iip_cp_client_application_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(settings);

	task->m_step = ((mk_lib_iip_cp_client_application_task_step_t)(0));
	task->m_application.m_settings = *settings;
	err = mk_lib_iip_cp_client_shared_rw_construct(&task->m_application.m_state.m_shared); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_tasks_rw_construct(&task->m_application.m_state.m_connections); mk_lang_check_rereturn(err);
	task->m_application.m_state.m_connection_idx = 0;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_prrw_destroy(mk_lib_iip_cp_client_application_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_client_shared_rw_destroy(&task->m_application.m_state.m_shared); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_tasks_rw_destroy(&task->m_application.m_state.m_connections); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_prrw_new_connection(mk_lib_iip_cp_client_application_task_pt const task, mk_lib_iip_cp_client_connection_settings_pct const settings, mk_lib_iip_cp_client_connection_task_ppt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_connection_task_pt con;
	mk_lang_types_void_pt mem;
	mk_lib_iip_cp_client_connection_task_pt kon;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(connection);

	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*con), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); con = ((mk_lib_iip_cp_client_connection_task_pt)(mem)); mk_lang_assert(con); kon = con; mk_lang_assert(kon);
	err = mk_lib_iip_cp_client_connection_task_rw_construct(con, &task->m_application.m_state.m_shared, settings); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_tasks_rw_push_back_move_single(&task->m_application.m_state.m_connections, &con); mk_lang_check_rereturn(err);
	*connection = kon;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_application_task_prrw_step(mk_lib_iip_cp_client_application_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lib_iip_cp_client_application_task_result_pt const step_result) mk_lang_noexcept
{
	//mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_application_task_result_e_dummy_end);

	switch(task->m_step)
	{
		/*case mk_lib_iip_cp_client_application_task_step_e_connect_request       : err = mk_lib_iip_cp_client_application_task_prrw_step_connect_request       (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_connect_finish        : err = mk_lib_iip_cp_client_application_task_prrw_step_connect_finish        (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_send_get_date_request : err = mk_lib_iip_cp_client_application_task_prrw_step_send_get_date_request (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_send_get_date_finish  : err = mk_lib_iip_cp_client_application_task_prrw_step_send_get_date_finish  (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_recv_set_date_request : err = mk_lib_iip_cp_client_application_task_prrw_step_recv_set_date_request (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_recv_set_date_finish  : err = mk_lib_iip_cp_client_application_task_prrw_step_recv_set_date_finish  (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_send_bandwidth_request: err = mk_lib_iip_cp_client_application_task_prrw_step_send_bandwidth_request(task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_send_bandwidth_finish : err = mk_lib_iip_cp_client_application_task_prrw_step_send_bandwidth_finish (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_recv_bandwidth_request: err = mk_lib_iip_cp_client_application_task_prrw_step_recv_bandwidth_request(task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_recv_bandwidth_finish : err = mk_lib_iip_cp_client_application_task_prrw_step_recv_bandwidth_finish (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_ready                 : err = mk_lib_iip_cp_client_application_task_prrw_step_ready                 (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_parse_incoming_msg    : err = mk_lib_iip_cp_client_application_task_prrw_step_parse_incoming_msg    (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_application_task_step_e_dispatch_msg          : err = mk_lib_iip_cp_client_application_task_prrw_step_dispatch_msg          (task, allow_to_block, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_application_task_result_e_dummy_end); break;*/
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
