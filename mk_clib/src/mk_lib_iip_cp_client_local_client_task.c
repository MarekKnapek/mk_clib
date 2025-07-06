#ifndef mk_include_guard_mk_lib_iip_cp_client_local_client_c
#define mk_include_guard_mk_lib_iip_cp_client_local_client_c
#include "mk_lib_iip_cp_client_local_client_task.h"

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
#include "mk_lang_runtime_bool.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_client_session.h"
#include "mk_lib_iip_cp_client_shared.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_parse.h"
#include "mk_lib_iip_cp_message_serialize.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_iip_key_enc_elgamal_pri.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_logger.h"
#include "mk_lib_iip_logger_more.h"
#include "mk_lib_net.h"
#include "mk_sl_cui_uint8.h"
#include "mk_win_dll_kernel_time.h" /* todo */


#define mk_sl_cui_t_name mk_lib_iip_cp_client_local_client_handle
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#if defined mk_lib_iip_cp_client_local_client_debug_print_want
#if (mk_lib_iip_cp_client_local_client_debug_print_want) == 0
#define mk_lib_iip_cp_client_local_client_debug_print_have 0
#elif (mk_lib_iip_cp_client_local_client_debug_print_want) == 1
#define mk_lib_iip_cp_client_local_client_debug_print_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_lib_iip_cp_client_local_client_debug_print_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lib_iip_cp_client_local_client_debug_print_have 0
#else
#define mk_lib_iip_cp_client_local_client_debug_print_have 1
#endif
#endif
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_construct(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lib_iip_cp_client_local_client_task_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(settings->m_shared);

	task->m_step = ((mk_lib_iip_cp_client_local_client_task_step_t)(0));
	task->m_local.m_settings.m_shared = settings->m_shared;
	err = mk_lib_net_socket_construct(&task->m_local.m_state.m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&task->m_local.m_state.m_socket); mk_lang_check_rereturn(err);
	task->m_local.m_state.m_close_requested = mk_lang_false;
	task->m_local.m_state.m_last_action_timestamp = ((mk_lang_types_uint_t)(mk_win_dll_kernel_time_get_tick_count()));
	task->m_local.m_state.m_is_connected = mk_lang_false;
	task->m_local.m_state.m_buffer.m_ptr = ((mk_sl_cui_uint8_pt)(mk_lang_roundup_align(&task->m_local.m_state.m_buffer.m_data.m_u8s[0], mk_lib_iip_cp_client_local_client_buffer_algn)));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_destroy(mk_lib_iip_cp_client_local_client_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_net_socket_destroy(&task->m_local.m_state.m_socket); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_request_close(mk_lib_iip_cp_client_local_client_task_pt const task) mk_lang_noexcept
{
	mk_lang_assert(task);

	task->m_local.m_state.m_close_requested = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step_idle(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_uint_t current_timestamp;
	mk_lang_types_bool_t did_something;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t connect_time;
	mk_lang_types_bool_t is_connected;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_client_task_step_e_idle);

	current_timestamp = ((mk_lang_types_uint_t)(mk_win_dll_kernel_time_get_tick_count()));
	did_something = mk_lang_false;
	if(!did_something)
	{
		if(current_timestamp - task->m_local.m_state.m_last_action_timestamp >= 1 * 60 * 1000)
		{
			err = mk_lib_iip_cp_client_local_client_task_prrw_request_close(task); mk_lang_check_rereturn(err);
			*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_something;
			did_something = mk_lang_true;
		}
	}
	if(!did_something)
	{
		if(!task->m_local.m_state.m_is_connected)
		{
			err = mk_lib_net_socket_get_option_connect_time(&task->m_local.m_state.m_socket, &connect_time); mk_lang_check_rereturn(err);
			is_connected = connect_time != -1;
			if(is_connected)
			{
				task->m_local.m_state.m_is_connected = mk_lang_true;
				task->m_local.m_state.m_last_action_timestamp = current_timestamp;
				*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_something;
				did_something = mk_lang_true;
			}
		}
	}
	if(!did_something)
	{
		*step_result = mk_lib_iip_cp_client_local_client_task_result_e_did_nothing;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_prrw_step(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_local_client_task_step_e_idle: err = mk_lib_iip_cp_client_local_client_task_prrw_step_idle(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_client_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_construct(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lib_iip_cp_client_local_client_task_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_construct(task, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_destroy(mk_lib_iip_cp_client_local_client_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_request_close(mk_lib_iip_cp_client_local_client_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_request_close(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_on_iorp_done(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_on_iorp_done(task, bytes_transferred, overlapped);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_rw_step(mk_lib_iip_cp_client_local_client_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_client_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_client_task_prrw_step(task, allow_to_block, tm, step_result);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_void(mk_lib_iip_cp_client_local_client_task_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_destroy(mk_lib_iip_cp_client_local_client_task_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_local_client_task_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_copy(mk_lib_iip_cp_client_local_client_task_ppt const dst, mk_lib_iip_cp_client_local_client_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_move(mk_lib_iip_cp_client_local_client_task_ppt const dst, mk_lib_iip_cp_client_local_client_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_assign_copy(mk_lib_iip_cp_client_local_client_task_ppt const dst, mk_lib_iip_cp_client_local_client_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_client_task_ptr_rw_assign_move(mk_lib_iip_cp_client_local_client_task_ppt const dst, mk_lib_iip_cp_client_local_client_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_local_client_tasks
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_local_client_task_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_local_client_task_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_local_client_task_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_local_client_task_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_local_client_task_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
