#ifndef mk_include_guard_mk_lib_iip_cp_client_session_c
#define mk_include_guard_mk_lib_iip_cp_client_session_c
#include "mk_lib_iip_cp_client_session.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_runtime_bool.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_iip_time.h"


#define mk_sl_cui_t_name mk_lib_iip_cp_client_session_handle
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_list_dbl_t_name mk_lib_iip_cp_client_session_task_list
#define mk_sl_list_dbl_t_element_type mk_lib_iip_cp_client_session_task_pt
#define mk_sl_list_dbl_t_mallocator_global mk_lib_iip_cp_mallocator_global
#include "mk_sl_list_dbl_inl_filec.h"
#include "mk_sl_list_dbl_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_construct(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pct const destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(destination);

	task->m_step = ((mk_lib_iip_cp_client_session_task_step_t)(0));
	task->m_session.m_settings.m_destination = *destination;
	task->m_session.m_state.m_has_id = mk_lang_false;
	err = mk_lib_iip_cp_message_construct(&task->m_session.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits); mk_lang_check_rereturn(err);
	task->m_session.m_state.m_has_msg_pending = mk_lang_false;
	err = mk_lib_iip_cp_types_leasez_rw_construct(&task->m_session.m_state.m_leases); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_destroy(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_message_destroy(&task->m_session.m_state.m_msg); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_types_leasez_rw_destroy(&task->m_session.m_state.m_leases); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_gimme_msg(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_ppt const msg) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert
	(
		task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_session ||
		task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_lease_set ||
		mk_lang_false
	);

	*msg = &task->m_session.m_state.m_msg;
	task->m_session.m_state.m_has_msg_pending = mk_lang_false;
	if(mk_lang_runtime_bool_fn_false){}
	else if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_session  ){ task->m_step = mk_lib_iip_cp_client_session_task_step_e_wait_msg_session_status; }
	else if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_lease_set){ task->m_step = mk_lib_iip_cp_client_session_task_step_e_idle                      ; }
	else{ mk_lang_assert_false(); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_request_variable_lease_set(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_request_variable_lease_set_pt msg_request_variable_lease_set;
	mk_lib_iip_cp_types_lease_pt data;
	mk_lang_types_usize_t size;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_create_lease_set_pt msg_create_lease_set;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);
	mk_lang_assert(!task->m_session.m_state.m_has_msg_pending);

	mk_lang_check_return(task->m_step == mk_lib_iip_cp_client_session_task_step_e_wait_msg_request_leaseset);
	msg_request_variable_lease_set = &msg->m_mix.m_data.m_request_variable_lease_set;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_request_variable_lease_set->m_session_id, &task->m_session.m_state.m_id));

	data = mk_lib_iip_cp_types_leases_rw_data(&msg_request_variable_lease_set->m_leases);
	size = mk_lib_iip_cp_types_leases_rw_size(&msg_request_variable_lease_set->m_leases);
	err = mk_lib_iip_cp_types_leasez_rw_push_back_move_many(&task->m_session.m_state.m_leases, data, size); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_message_reconstruct(&task->m_session.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_create_lease_set); mk_lang_check_rereturn(err);
	msg_create_lease_set = &task->m_session.m_state.m_msg.m_mix.m_data.m_create_lease_set;
	msg_create_lease_set->m_session_id = task->m_session.m_state.m_id;
	msg_create_lease_set->m_key_sgn_pri = task->m_session.m_settings.m_destination.m_key_dsa_sha1_pri;
	msg_create_lease_set->m_key_enc_pri = task->m_session.m_settings.m_destination.m_key_elgamal_pri;
	msg_create_lease_set->m_leaseset.m_destination = task->m_session.m_settings.m_destination;
	err = mk_lib_iip_cp_types_leases_rw_push_back_copy_many(&msg_create_lease_set->m_leaseset.m_leases, data, size); mk_lang_check_rereturn(err);
	task->m_session.m_state.m_has_msg_pending = mk_lang_true;

	task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_lease_set;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(msg);

	switch(msg->m_header.m_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: err = mk_lib_iip_cp_client_session_task_prrw_on_msg_request_variable_lease_set(task, msg); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_make_msg_create_session(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	#define mk_lib_iip_cp_client_session_task_prrw_step_make_msg_create_session_my_name "mk_clib_app_iip"

	mk_lib_iip_cp_message_pt msg;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_create_session_pt msg_create_session;
	mk_lib_iip_cp_types_strpair_pt str_pair;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_make_msg_create_session);
	mk_lang_assert(!task->m_session.m_state.m_has_msg_pending);

	msg = &task->m_session.m_state.m_msg;
	err = mk_lib_iip_cp_message_reconstruct(msg, mk_lib_iip_cp_message_message_type_id_e_create_session); mk_lang_check_rereturn(err);
	msg_create_session = &msg->m_mix.m_data.m_create_session;
	msg_create_session->m_session_config.m_destination = task->m_session.m_settings.m_destination;
	err = mk_lib_iip_cp_types_strpairs_rw_grow_by(&msg_create_session->m_session_config.m_options.m_strpairs, 1); mk_lang_check_rereturn(err);
	str_pair = mk_lib_iip_cp_types_strpairs_rw_back(&msg_create_session->m_session_config.m_options.m_strpairs); mk_lang_assert(str_pair);
	mk_lang_string_memcpy_pc_fn(&str_pair->m_key.m_buf[0], &mk_lib_iip_cp_message_mapping_val_create_session_inbound_nickname_str_buf[0], mk_lang_countstr(mk_lib_iip_cp_message_mapping_val_create_session_inbound_nickname_str_buf)); str_pair->m_key.m_len = mk_lang_countstr(mk_lib_iip_cp_message_mapping_val_create_session_inbound_nickname_str_buf);
	mk_lang_string_memcpy_pc_fn(&str_pair->m_val.m_buf[0], &mk_lib_iip_cp_client_session_task_prrw_step_make_msg_create_session_my_name[0], mk_lang_countstr(mk_lib_iip_cp_client_session_task_prrw_step_make_msg_create_session_my_name)); str_pair->m_val.m_len = mk_lang_countstr(mk_lib_iip_cp_client_session_task_prrw_step_make_msg_create_session_my_name);
	mk_lib_iip_time_get_now(&msg_create_session->m_session_config.m_creation_date.m_elements[0]);
	task->m_session.m_state.m_has_msg_pending = mk_lang_true;
	task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_session;
	*step_result = mk_lib_iip_cp_client_session_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_create_session(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_session);
	mk_lang_assert(task->m_session.m_state.m_has_msg_pending);

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_want_send;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_wait_msg_session_status(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_wait_msg_session_status);

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_want_recv;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_wait_msg_request_leaseset(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_wait_msg_request_leaseset);

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_want_recv;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_create_lease_set(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_lease_set);
	mk_lang_assert(task->m_session.m_state.m_has_msg_pending);

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_want_send;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_idle(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle);

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_idling;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_session_task_step_e_make_msg_create_session    : err = mk_lib_iip_cp_client_session_task_prrw_step_make_msg_create_session    (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_session  : err = mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_create_session  (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_wait_msg_session_status    : err = mk_lib_iip_cp_client_session_task_prrw_step_wait_msg_session_status    (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_wait_msg_request_leaseset  : err = mk_lib_iip_cp_client_session_task_prrw_step_wait_msg_request_leaseset  (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_lease_set: err = mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_create_lease_set(task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_idle                       : err = mk_lib_iip_cp_client_session_task_prrw_step_idle                       (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_assert
	(
		((*step_result == mk_lib_iip_cp_client_session_task_result_e_want_send && task->m_session.m_state.m_has_msg_pending) || (*step_result != mk_lib_iip_cp_client_session_task_result_e_want_send)) &&
		((*step_result == mk_lib_iip_cp_client_session_task_result_e_want_recv && !task->m_session.m_state.m_has_msg_pending) || (*step_result != mk_lib_iip_cp_client_session_task_result_e_want_recv)) &&
		mk_lang_true
	);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_construct(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_types_destination_elgamal_dsa_sha1_pct const destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(destination);

	err = mk_lib_iip_cp_client_session_task_prrw_construct(task, destination); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_destroy(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_client_session_task_prrw_destroy(task); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_gimme_msg(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_ppt const msg) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(msg);

	err = mk_lib_iip_cp_client_session_task_prrw_gimme_msg(task, msg); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_on_msg(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(msg);

	err = mk_lib_iip_cp_client_session_task_prrw_on_msg(task, msg); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_step(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);

	err = mk_lib_iip_cp_client_session_task_prrw_step(task, step_result); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_ptr_rw_construct_void(mk_lib_iip_cp_client_session_task_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_ptr_rw_destroy(mk_lib_iip_cp_client_session_task_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_task_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_session_task_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_ptr_rw_construct_copy(mk_lib_iip_cp_client_session_task_ppt const dst, mk_lib_iip_cp_client_session_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_ptr_rw_construct_move(mk_lib_iip_cp_client_session_task_ppt const dst, mk_lib_iip_cp_client_session_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_ptr_rw_assign_copy(mk_lib_iip_cp_client_session_task_ppt const dst, mk_lib_iip_cp_client_session_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_ptr_rw_assign_move(mk_lib_iip_cp_client_session_task_ppt const dst, mk_lib_iip_cp_client_session_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_session_tasks
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_session_task_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_session_task_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_session_task_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_session_task_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_session_task_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_session_task_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_session_task_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
