#ifndef mk_include_guard_mk_lib_iip_cp_client_session_c
#define mk_include_guard_mk_lib_iip_cp_client_session_c
#include "mk_lib_iip_cp_client_session.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_runtime_bool.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_lib_fmt.h"
#include "mk_lib_iip_cp_client_shared.h"
#include "mk_lib_iip_cp_client_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_iip_http.h"
#include "mk_lib_iip_logger.h"
#include "mk_lib_iip_logger_more.h"
#include "mk_lib_iip_net_streaming_packet.h"
#include "mk_lib_iip_random.h"
#include "mk_lib_iip_time.h"
#include "mk_lib_zlib.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_uint_convert.h"


#define mk_sl_cui_t_name mk_lib_iip_cp_client_session_handle
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#if defined mk_lib_iip_cp_client_session_debug_print_want
#if (mk_lib_iip_cp_client_session_debug_print_want) == 0
#define mk_lib_iip_cp_client_session_debug_print_have 0
#elif (mk_lib_iip_cp_client_session_debug_print_want) == 1
#define mk_lib_iip_cp_client_session_debug_print_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_lib_iip_cp_client_session_debug_print_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lib_iip_cp_client_session_debug_print_have 0
#else
#define mk_lib_iip_cp_client_session_debug_print_have 1
#endif
#endif
#endif


#if mk_lib_iip_cp_client_session_debug_print_have
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_cp_client_session_debug_print_got_packet_k_fmt[] = "Got packet from %t.";
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_debug_print_got_packet(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_net_streaming_packet_pct const packet) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_session_debug_print_have
	mk_lang_types_pchar_pct b32;
	mk_lib_iip_logger_pt logger;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[512];
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(packet);

	if((packet->m_flags & mk_lib_iip_net_streaming_packet_flag_e_from_included) != 0)
	{
		b32 = &packet->m_options.m_b32.m_pchars[0];
		logger = &task->m_session.m_state.m_shared->m_logger;
		str_len = mk_lib_fmt_n_snnprintf(&str_buf[0], mk_lang_countof(str_buf), &mk_lib_iip_cp_client_session_debug_print_got_packet_k_fmt[0], mk_lang_countstr(mk_lib_iip_cp_client_session_debug_print_got_packet_k_fmt), b32, 52); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= mk_lang_countof(str_buf));
		err = mk_lib_iip_logger_rw_begin_line(logger); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_append_current_time(logger); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_print(logger, &str_buf[0], str_len); mk_lang_check_rereturn(err);
		err = mk_lib_iip_logger_rw_end_line(logger); mk_lang_check_rereturn(err);
	}
	return 0;
#else
	mk_lang_assert(task);
	mk_lang_assert(packet);

	((mk_lang_types_void_t)(task));
	((mk_lang_types_void_t)(packet));
	return 0;
#endif
}


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_lib_iip_cp_client_session_lookup_host_name_s
{
	mk_lib_iip_cp_client_types_lookup_host_name_pt m_request;
	mk_lib_iip_cp_types_requestid_t m_request_id;
	mk_lib_iip_time_timestamp_t m_created;
};
typedef struct mk_lib_iip_cp_client_session_lookup_host_name_s mk_lib_iip_cp_client_session_lookup_host_name_t;
mk_lang_typedef(mk_lib_iip_cp_client_session_lookup_host_name);
#include "mk_lang_warning_msvc_pop.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_construct_void(mk_lib_iip_cp_client_session_lookup_host_name_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_destroy(mk_lib_iip_cp_client_session_lookup_host_name_ppt const x) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	if(*x)
	{
		err = mk_lib_iip_cp_mallocator_global_deallocate(*x, sizeof(**x)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_construct_copy(mk_lib_iip_cp_client_session_lookup_host_name_ppt const dst, mk_lib_iip_cp_client_session_lookup_host_name_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	((mk_lang_types_void_t)(dst));
	((mk_lang_types_void_t)(src));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_construct_move(mk_lib_iip_cp_client_session_lookup_host_name_ppt const dst, mk_lib_iip_cp_client_session_lookup_host_name_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_assign_copy(mk_lib_iip_cp_client_session_lookup_host_name_ppt const dst, mk_lib_iip_cp_client_session_lookup_host_name_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	((mk_lang_types_void_t)(dst));
	((mk_lang_types_void_t)(src));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_assign_move(mk_lib_iip_cp_client_session_lookup_host_name_ppt const dst, mk_lib_iip_cp_client_session_lookup_host_name_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	((mk_lang_types_void_t)(dst));
	((mk_lang_types_void_t)(src));
	mk_lang_check_todo();
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_session_lookups_host_name
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_session_lookup_host_name_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_session_lookup_host_name_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_message_status_rw_construct_void(mk_lib_iip_cp_client_session_message_status_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_message_status_rw_destroy(mk_lib_iip_cp_client_session_message_status_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_message_status_rw_construct_copy(mk_lib_iip_cp_client_session_message_status_pt const dst, mk_lib_iip_cp_client_session_message_status_pct const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_message_status_rw_construct_move(mk_lib_iip_cp_client_session_message_status_pt const dst, mk_lib_iip_cp_client_session_message_status_pt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_message_status_rw_assign_copy(mk_lib_iip_cp_client_session_message_status_pt const dst, mk_lib_iip_cp_client_session_message_status_pct const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_message_status_rw_assign_move(mk_lib_iip_cp_client_session_message_status_pt const dst, mk_lib_iip_cp_client_session_message_status_pt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
}


#define mk_sl_dynamic_ring_t_name mk_lib_iip_cp_client_session_message_statuses
#define mk_sl_dynamic_ring_t_element_type mk_lib_iip_cp_client_session_message_status_t
#define mk_sl_dynamic_ring_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_dynamic_ring_t_element_construct_void mk_lib_iip_cp_client_session_message_status_rw_construct_void
#define mk_sl_dynamic_ring_t_element_destruct mk_lib_iip_cp_client_session_message_status_rw_destroy
#define mk_sl_dynamic_ring_t_element_construct_copy mk_lib_iip_cp_client_session_message_status_rw_construct_copy
#define mk_sl_dynamic_ring_t_element_construct_move mk_lib_iip_cp_client_session_message_status_rw_construct_move
#define mk_sl_dynamic_ring_t_element_assign_copy mk_lib_iip_cp_client_session_message_status_rw_assign_copy
#define mk_sl_dynamic_ring_t_element_assign_move mk_lib_iip_cp_client_session_message_status_rw_assign_move
#include "mk_sl_dynamic_ring_inl_filec.h"
#include "mk_sl_dynamic_ring_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_construct(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_shared_pt const shared, mk_lib_iip_cp_client_session_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(shared);
	mk_lang_assert(settings);

	task->m_step = ((mk_lib_iip_cp_client_session_task_step_t)(0));
	task->m_session.m_settings = *settings;
	task->m_session.m_state.m_shared = shared;
	task->m_session.m_state.m_has_id = mk_lang_false;
	task->m_session.m_state.m_child_sessions = 0;
	task->m_session.m_state.m_stop_requested = mk_lang_false;
	err = mk_lib_iip_cp_message_construct(&task->m_session.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_dummy_end); mk_lang_check_rereturn(err);
	task->m_session.m_state.m_has_msg_pending = mk_lang_false;
	err = mk_lib_iip_cp_types_leasez_rw_construct(&task->m_session.m_state.m_leases); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_message_statuses_rw_construct(&task->m_session.m_state.m_msgs_available); mk_lang_check_rereturn(err);
	task->m_session.m_state.m_msg_expecting = mk_lang_false;
	err = mk_lib_iip_cp_client_socket_tasks_rw_construct(&task->m_session.m_state.m_listening_sockets); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_tasks_rw_construct(&task->m_session.m_state.m_connecting_sockets); mk_lang_check_rereturn(err);
	task->m_session.m_state.m_idx_listening_sockets = 0;
	task->m_session.m_state.m_idx_connecting_sockets = 0;
	task->m_session.m_state.m_msg_from_socket = mk_lang_null;
	task->m_session.m_state.m_msg_to_be_accepted = mk_lang_null;
	err = mk_lib_iip_cp_client_session_lookups_host_name_rw_construct(&task->m_session.m_state.m_lookups_host_name_a); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_lookups_host_name_rw_construct(&task->m_session.m_state.m_lookups_host_name_b); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_destroy(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_message_destroy(&task->m_session.m_state.m_msg); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_types_leasez_rw_destroy(&task->m_session.m_state.m_leases); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_message_statuses_rw_destroy(&task->m_session.m_state.m_msgs_available); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_tasks_rw_destroy(&task->m_session.m_state.m_listening_sockets); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_tasks_rw_destroy(&task->m_session.m_state.m_connecting_sockets); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_lookups_host_name_rw_destroy(&task->m_session.m_state.m_lookups_host_name_a); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_lookups_host_name_rw_destroy(&task->m_session.m_state.m_lookups_host_name_b); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_child_session_spawned(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(mk_lib_iip_cp_client_session_handle_is_zero(&task->m_session.m_settings.m_master_session));
	mk_lang_assert(task->m_session.m_state.m_child_sessions >= 0);

	++task->m_session.m_state.m_child_sessions;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_child_session_died(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(mk_lib_iip_cp_client_session_handle_is_zero(&task->m_session.m_settings.m_master_session));
	mk_lang_assert(task->m_session.m_state.m_child_sessions >= 1);

	--task->m_session.m_state.m_child_sessions;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_new_socket_listener(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_types_socket_listener_settings_pct const settings, mk_lib_iip_cp_client_types_handle_socket_listener_pt const socket_listener) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t uptr;
	mk_lib_iip_cp_client_session_task_pt session;
	mk_lib_iip_cp_client_socket_settings_t config;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_socket_task_pt sock_list;
	mk_lang_types_void_pt mem;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(socket_listener);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_session_is_zero(&settings->m_session));
	mk_lang_assert((mk_lib_iip_cp_client_types_handle_session_to_base(&settings->m_session, &uptr), uptr != 0));
	mk_lang_assert((session = ((mk_lib_iip_cp_client_session_task_pt)(uptr)), session));
	mk_lang_assert(session == task);

	config.m_shared = task->m_session.m_state.m_shared;
	config.m_session_id = &task->m_session.m_state.m_id;
	config.m_listener = mk_lang_true;
	config.m_local_destination = &task->m_session.m_settings.m_local_destination;
	config.m_local_port = settings->m_port;
	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*sock_list), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); sock_list = ((mk_lib_iip_cp_client_socket_task_pt)(mem)); mk_lang_assert(sock_list);
	err = mk_lib_iip_cp_client_socket_task_rw_construct(sock_list, &config); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_tasks_rw_push_back_copy_single(&task->m_session.m_state.m_listening_sockets, &sock_list); mk_lang_check_rereturn(err);
	uptr = ((mk_lang_bui_uintptr_t)(sock_list));
	mk_lib_iip_cp_client_types_handle_socket_listener_from_base(socket_listener, &uptr);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_gimme_msg(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_ppt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_task_pt master_session;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert
	(
		task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_session ||
		task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_lease_set ||
		task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_begin ||
		task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_end ||
		task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_destroy_session ||
		task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_from_socket ||
		task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_lookup ||
		mk_lang_false
	);

	if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_destroy_session)
	{
		if(!mk_lib_iip_cp_client_session_handle_is_zero(&task->m_session.m_settings.m_master_session))
		{
			master_session = ((mk_lib_iip_cp_client_session_task_pt)(task->m_session.m_settings.m_master_session.m_elements[0])); mk_lang_assert(master_session);
			err = mk_lib_iip_cp_client_session_task_prrw_on_child_session_died(master_session); mk_lang_check_rereturn(err);
		}
	}

	if(task->m_step != mk_lib_iip_cp_client_session_task_step_e_pickup_msg_from_socket)
	{
		*msg = &task->m_session.m_state.m_msg;
	}
	else
	{
		mk_lang_assert(task->m_session.m_state.m_msg_from_socket);
		*msg = task->m_session.m_state.m_msg_from_socket;
		task->m_session.m_state.m_msg_to_be_accepted = task->m_session.m_state.m_msg_from_socket;
		task->m_session.m_state.m_msg_from_socket = mk_lang_null;
	}
	task->m_session.m_state.m_has_msg_pending = mk_lang_false;
	if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_begin)
	{
		task->m_session.m_state.m_msg_expecting = mk_lang_true;
	}
	if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_end)
	{
		mk_lang_assert(!mk_lib_iip_cp_client_session_message_statuses_rw_is_empty(&task->m_session.m_state.m_msgs_available));
		err = mk_lib_iip_cp_client_session_message_statuses_rw_pop_front_single(&task->m_session.m_state.m_msgs_available); mk_lang_check_rereturn(err);
	}
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(mk_lang_false){}
	#include "mk_lang_warning_msvc_pop.h"
	else if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_session       ){ task->m_step = mk_lib_iip_cp_client_session_task_step_e_wait_msg_session_status; }
	else if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_lease_set     ){ task->m_step = mk_lib_iip_cp_client_session_task_step_e_idle                   ; }
	else if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_begin){ task->m_step = mk_lib_iip_cp_client_session_task_step_e_idle                   ; }
	else if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_end  ){ task->m_step = mk_lib_iip_cp_client_session_task_step_e_idle                   ; }
	else if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_destroy_session      ){ task->m_step = mk_lib_iip_cp_client_session_task_step_e_destroy_sent           ; }
	else if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_from_socket          ){ task->m_step = mk_lib_iip_cp_client_session_task_step_e_idle                   ; }
	else if(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_lookup               ){ task->m_step = mk_lib_iip_cp_client_session_task_step_e_idle                   ; }
	else{ mk_lang_assert_false(); }
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_prune_old_leases(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	mk_lib_iip_cp_types_date_t curr_time;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lib_iip_cp_types_lease_pt lease;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	mk_lib_iip_time_get_now(&curr_time.m_elements[0]);
	n = mk_lib_iip_cp_types_leasez_rw_size(&task->m_session.m_state.m_leases);
	for(i = 0; i != n; ++i)
	{
		idx = (n - 1) - i;
		lease = mk_lib_iip_cp_types_leasez_rw_at(&task->m_session.m_state.m_leases, idx); mk_lang_assert(lease);
		if(mk_lib_iip_cp_types_date_lt(&lease->m_end_date, &curr_time))
		{
			err = mk_lib_iip_cp_types_leasez_rw_erase_at(&task->m_session.m_state.m_leases, idx); mk_lang_check_rereturn(err);
			--i;
			--n;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_session_status(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_session_status_pt msg_session_status;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);

	mk_lang_check_return(task->m_step == mk_lib_iip_cp_client_session_task_step_e_destroy_sent);
	msg_session_status = &msg->m_mix.m_data.m_session_status;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_session_status->m_session_id, &task->m_session.m_state.m_id));

	switch(msg_session_status->m_status)
	{
		case mk_lib_iip_cp_message_session_status_status_id_e_destroyed: task->m_step = mk_lib_iip_cp_client_session_task_step_e_destroyed_total; break;
		case mk_lib_iip_cp_message_session_status_status_id_e_created  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_updated  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_invalid  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_refused  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_request_lease_set(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_request_lease_set_pt msg_request_lease_set;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_hash_and_tunnelid_pt data;
	mk_lang_types_usize_t size;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_types_lease_t lease;
	mk_lib_iip_cp_types_lease_pt leases;
	mk_lib_iip_cp_message_create_lease_set_pt msg_create_lease_set;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);
	mk_lang_assert(!task->m_session.m_state.m_has_msg_pending);

	mk_lang_check_return
	(
		(task->m_step == mk_lib_iip_cp_client_session_task_step_e_wait_msg_request_leaseset) ||
		(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle) ||
		mk_lang_false
	);
	msg_request_lease_set = &msg->m_mix.m_data.m_request_lease_set;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_request_lease_set->m_session_id, &task->m_session.m_state.m_id));

	err = mk_lib_iip_cp_client_session_task_prrw_prune_old_leases(task); mk_lang_check_rereturn(err);
	data = mk_lib_iip_cp_types_hash_and_tunnelids_rw_data(&msg_request_lease_set->m_tunnels);
	size = mk_lib_iip_cp_types_hash_and_tunnelids_rw_size(&msg_request_lease_set->m_tunnels);
	mk_lang_check_return(size != 0);
	err = mk_lib_iip_cp_types_leasez_rw_reserve_additional(&task->m_session.m_state.m_leases, size); mk_lang_check_rereturn(err);
	n = size;
	for(i = 0; i != n; ++i)
	{
		lease.m_router_hash = data[i].m_router_hash;
		lease.m_tunnel_id = data[i].m_tunnel_id;
		lease.m_end_date = msg_request_lease_set->m_end_date;
		err = mk_lib_iip_cp_types_leasez_rw_push_back_move_single(&task->m_session.m_state.m_leases, &lease); mk_lang_check_rereturn(err);
	}
	leases = mk_lib_iip_cp_types_leasez_rw_back(&task->m_session.m_state.m_leases); mk_lang_assert(leases);
	leases -= (size - 1);

	err = mk_lib_iip_cp_message_reconstruct(&task->m_session.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_create_lease_set); mk_lang_check_rereturn(err);
	msg_create_lease_set = &task->m_session.m_state.m_msg.m_mix.m_data.m_create_lease_set;
	msg_create_lease_set->m_session_id = task->m_session.m_state.m_id;
	msg_create_lease_set->m_key_sgn_pri = task->m_session.m_settings.m_local_destination.m_private_data.m_key_dsa_sha1_pri;
	msg_create_lease_set->m_key_enc_pri = task->m_session.m_settings.m_local_destination.m_private_data.m_key_elgamal_pri;
	msg_create_lease_set->m_leaseset.m_destination = task->m_session.m_settings.m_local_destination;
	err = mk_lib_iip_cp_types_leases_rw_push_back_copy_many(&msg_create_lease_set->m_leaseset.m_leases, leases, size); mk_lang_check_rereturn(err);
	task->m_session.m_state.m_has_msg_pending = mk_lang_true;

	task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_lease_set;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_incoming_streaming_packet(mk_lib_iip_cp_client_session_task_pt const task, mk_sl_cui_uint16_pct const src_port, mk_sl_cui_uint16_pct const dst_port, mk_lib_iip_net_streaming_packet_pct const packet) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_first;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_socket_task_ppt sck_ptr;
	mk_lib_iip_cp_client_socket_task_pt sck_obj;
	mk_lang_types_bool_t consumed;

	mk_lang_assert(task);
	mk_lang_assert(src_port);
	mk_lang_assert(dst_port);
	mk_lang_assert(packet);

	err = mk_lib_iip_net_streaming_packet_ro_is_initial_in_stream(packet, &is_first); mk_lang_check_rereturn(err);
	if(is_first)
	{
		n = mk_lib_iip_cp_client_socket_tasks_rw_size(&task->m_session.m_state.m_listening_sockets);
		for(i = 0; i != n; ++i)
		{
			sck_ptr = mk_lib_iip_cp_client_socket_tasks_rw_at(&task->m_session.m_state.m_listening_sockets, i); mk_lang_assert(sck_ptr); sck_obj = *sck_ptr; mk_lang_assert(sck_obj);
			err = mk_lib_iip_cp_client_socket_task_rw_on_packet(sck_obj, src_port, dst_port, packet, &consumed); mk_lang_check_rereturn(err);
			if(consumed)
			{
				break;
			}
		}
	}
	else
	{
		mk_lang_check_todo();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_parse_incoming_message_payload_streaming(mk_lib_iip_cp_client_session_task_pt const task, mk_sl_cui_uint16_pct const src_port, mk_sl_cui_uint16_pct const dst_port, mk_lib_iip_cp_types_buffer_pct const payload) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct src_buf;
	mk_lang_types_sint_t src_len;
	mk_sl_cui_uint8_pt dst_buf;
	mk_sl_cui_uint8_t decompressed_buf[128 * 1024];
	mk_lang_types_sint_t decompressed_len;
	mk_lang_types_sint_t dst_len;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t out_len;
	mk_lib_iip_net_streaming_packet_t packet;
	mk_lang_types_bool_t gud;

	mk_lang_assert(task);
	mk_lang_assert(src_port);
	mk_lang_assert(dst_port);
	mk_lang_assert(payload);

	src_buf = &payload->m_buf[0];
	src_len = payload->m_len;
	dst_buf = &decompressed_buf[0];
	dst_len = mk_lang_countof(decompressed_buf);
	err = mk_lib_zlib_decompress(src_buf, src_len, dst_buf, dst_len, &out_len); mk_lang_check_rereturn(err);
	decompressed_len = out_len;

	gud = mk_lang_true;
	err = mk_lib_iip_net_streaming_packet_rw_construct(&packet); mk_lang_check_rereturn(err);
	err = mk_lib_iip_net_streaming_packet_rw_parse(&packet, &decompressed_buf[0], decompressed_len, &gud); mk_lang_check_rereturn(err); mk_lang_check_return(gud);
	err = mk_lib_iip_cp_client_session_debug_print_got_packet(task, &packet); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_client_session_task_prrw_on_incoming_streaming_packet(task, src_port, dst_port, &packet); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_parse_incoming_message_payload_datagram(mk_lib_iip_cp_client_session_task_pt const task, mk_sl_cui_uint16_pct const src_port, mk_sl_cui_uint16_pct const dst_port, mk_lib_iip_cp_types_buffer_pct const payload) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(src_port);
	mk_lang_assert(dst_port);
	mk_lang_assert(payload);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_parse_incoming_message_payload_raw_datagram(mk_lib_iip_cp_client_session_task_pt const task, mk_sl_cui_uint16_pct const src_port, mk_sl_cui_uint16_pct const dst_port, mk_lib_iip_cp_types_buffer_pct const payload) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(src_port);
	mk_lang_assert(dst_port);
	mk_lang_assert(payload);

	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_parse_incoming_message_payload_unknown(mk_lib_iip_cp_client_session_task_pt const task, mk_sl_cui_uint16_pct const src_port, mk_sl_cui_uint16_pct const dst_port, mk_lib_iip_cp_types_buffer_pct const payload) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(src_port);
	mk_lang_assert(dst_port);
	mk_lang_assert(payload);

	/* drop */
	((mk_lang_types_void_t)(task));
	((mk_lang_types_void_t)(src_port));
	((mk_lang_types_void_t)(dst_port));
	((mk_lang_types_void_t)(payload));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_parse_incoming_message_payload(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_types_buffer_pct const payload) mk_lang_noexcept
{
	mk_lang_types_sint_t ptr;
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint8_t tu8;
	mk_sl_cui_uint16_t src_port;
	mk_sl_cui_uint16_t dst_port;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(payload);

	mk_lang_check_return(payload->m_len >= 10);
	ptr = 0;
	tuc = 0x1f; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); mk_lang_check_return(mk_sl_cui_uint8_eq(&payload->m_buf[ptr], &tu8)); ++ptr;
	tuc = 0x8b; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); mk_lang_check_return(mk_sl_cui_uint8_eq(&payload->m_buf[ptr], &tu8)); ++ptr;
	tuc = 0x08; mk_sl_cui_uint8_from_bi_uchar(&tu8, &tuc); mk_lang_check_return(mk_sl_cui_uint8_eq(&payload->m_buf[ptr], &tu8)); ++ptr;
	mk_sl_uint_convert_16_8_be_to_big(&src_port, &payload->m_buf[4]);
	mk_sl_uint_convert_16_8_be_to_big(&dst_port, &payload->m_buf[6]);
	mk_sl_cui_uint8_to_bi_uchar(&payload->m_buf[9], &tuc);
	switch(tuc)
	{
		case 6 : err = mk_lib_iip_cp_client_session_task_prrw_parse_incoming_message_payload_streaming   (task, &src_port, &dst_port, payload); mk_lang_check_rereturn(err); break;
		case 17: err = mk_lib_iip_cp_client_session_task_prrw_parse_incoming_message_payload_datagram    (task, &src_port, &dst_port, payload); mk_lang_check_rereturn(err); break;
		case 18: err = mk_lib_iip_cp_client_session_task_prrw_parse_incoming_message_payload_raw_datagram(task, &src_port, &dst_port, payload); mk_lang_check_rereturn(err); break;
		default: err = mk_lib_iip_cp_client_session_task_prrw_parse_incoming_message_payload_unknown     (task, &src_port, &dst_port, payload); mk_lang_check_rereturn(err); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status_available(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_message_status_pt msg_message_status;
	mk_lib_iip_cp_client_session_message_status_t msg_st;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);

	msg_message_status = &msg->m_mix.m_data.m_message_status;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_message_status->m_session_id, &task->m_session.m_state.m_id));
	mk_lang_assert(msg_message_status->m_status == mk_lib_iip_cp_message_message_status_status_id_e_available);

	msg_st.m_message_id = msg_message_status->m_message_id;
	msg_st.m_size = msg_message_status->m_size;
	msg_st.m_nonce = msg_message_status->m_nonce;
	err = mk_lib_iip_cp_client_session_message_statuses_rw_push_back_move_single(&task->m_session.m_state.m_msgs_available, &msg_st); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status_accepted(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_message_status_pt msg_message_status;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);

	msg_message_status = &msg->m_mix.m_data.m_message_status;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_message_status->m_session_id, &task->m_session.m_state.m_id));
	mk_lang_assert(msg_message_status->m_status == mk_lib_iip_cp_message_message_status_status_id_e_accepted);

	if(task->m_session.m_state.m_msg_to_be_accepted)
	{
		mk_lang_assert(task->m_session.m_state.m_msg_to_be_accepted->m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_send_message);
		/* todo multiple messages sent, to be accepted or only single send until accept */
		/*mk_lang_check_return(mk_lib_iip_cp_types_nonce_eq(&msg_message_status->m_nonce, &task->m_session.m_state.m_msg_to_be_accepted->m_mix.m_data.m_send_message.m_nonce));*/
		task->m_session.m_state.m_msg_to_be_accepted = mk_lang_null;
	}
	else
	{
		//mk_lang_check_todo();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status_best_effort_failure(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_message_status_pt msg_message_status;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);

	msg_message_status = &msg->m_mix.m_data.m_message_status;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_message_status->m_session_id, &task->m_session.m_state.m_id));
	mk_lang_assert(msg_message_status->m_status == mk_lib_iip_cp_message_message_status_status_id_e_best_effort_failure);

	/* todo nonce */
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status_guaranteed_success(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_message_status_pt msg_message_status;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);

	msg_message_status = &msg->m_mix.m_data.m_message_status;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_message_status->m_session_id, &task->m_session.m_state.m_id));
	mk_lang_assert(msg_message_status->m_status == mk_lib_iip_cp_message_message_status_status_id_e_guaranteed_success);

	/* todo nonce */
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status_no_leaseset(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_message_status_pt msg_message_status;
	mk_lib_iip_cp_client_socket_task_ppt socket_ptr;
	mk_lib_iip_cp_client_socket_task_pt socket_obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);

	msg_message_status = &msg->m_mix.m_data.m_message_status;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_message_status->m_session_id, &task->m_session.m_state.m_id));
	mk_lang_assert(msg_message_status->m_status == mk_lib_iip_cp_message_message_status_status_id_e_no_leaseset);

	socket_ptr = mk_lib_iip_cp_client_socket_tasks_rw_at(&task->m_session.m_state.m_listening_sockets, 0); mk_lang_assert(socket_ptr); socket_obj = *socket_ptr; mk_lang_assert(socket_obj);
	socket_obj->m_socket.m_state.m_waiting_for_syn = mk_lang_true;
	socket_obj->m_socket.m_state.m_our_syn_sent = mk_lang_false;
	err = mk_lib_iip_cp_client_socket_packets_with_payload_rw_clear(&socket_obj->m_socket.m_state.m_packets_to_ack); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_socket_packets_with_payload_rw_clear(&socket_obj->m_socket.m_state.m_incoming_packets); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_message_status_pt msg_message_status;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);

	msg_message_status = &msg->m_mix.m_data.m_message_status;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_message_status->m_session_id, &task->m_session.m_state.m_id));
	switch(msg_message_status->m_status)
	{
		case mk_lib_iip_cp_message_message_status_status_id_e_available             : err = mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status_available(task, msg); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_accepted              : err = mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status_accepted (task, msg); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_best_effort_success   : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_best_effort_failure   : err = mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status_best_effort_failure(task, msg); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_guaranteed_success    : err = mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status_guaranteed_success (task, msg); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_guaranteed_failure    : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_local_success         : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_local_failure         : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_router_failure        : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_network_failure       : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_session           : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_message           : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_options           : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_overflow_failure      : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_message_expired       : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_local_leaseset    : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_no_local_tunnels      : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_unsupported_encryption: mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_destination       : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_bad_leaseset          : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_expired_leaseset      : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_no_leaseset           : err = mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status_no_leaseset(task, msg); mk_lang_check_rereturn(err); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_meta_leaseset         : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_loopback_denied       : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_message_status_status_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_message_payload(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lib_iip_cp_message_message_payload_pt msg_message_payload;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_receive_message_end_pt msg_receive_message_end;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);
	mk_lang_assert(!task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle);

	msg_message_payload = &msg->m_mix.m_data.m_message_payload;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_message_payload->m_session_id, &task->m_session.m_state.m_id));
	if(task->m_session.m_state.m_msg_expecting)
	{
		mk_lang_assert(!mk_lib_iip_cp_client_session_message_statuses_rw_is_empty(&task->m_session.m_state.m_msgs_available));
		mk_lang_assert(mk_lib_iip_cp_client_session_message_statuses_rw_get_front(&task->m_session.m_state.m_msgs_available));
		mk_lang_assert(mk_lib_iip_cp_types_messageid_eq(&msg_message_payload->m_message_id, &mk_lib_iip_cp_client_session_message_statuses_rw_get_front(&task->m_session.m_state.m_msgs_available)->m_message_id));
		mk_lang_assert(msg_message_payload->m_payload.m_len == mk_lib_iip_cp_client_session_message_statuses_rw_get_front(&task->m_session.m_state.m_msgs_available)->m_size);
	}
	err = mk_lib_iip_cp_client_session_task_prrw_parse_incoming_message_payload(task, &msg_message_payload->m_payload); mk_lang_check_rereturn(err);
	if(task->m_session.m_state.m_msg_expecting)
	{
		task->m_session.m_state.m_msg_expecting = mk_lang_false;
		err = mk_lib_iip_cp_message_reconstruct(&task->m_session.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_receive_message_end); mk_lang_check_rereturn(err);
		msg_receive_message_end = &task->m_session.m_state.m_msg.m_mix.m_data.m_receive_message_end;
		msg_receive_message_end->m_session_id = task->m_session.m_state.m_id;
		msg_receive_message_end->m_message_id = mk_lib_iip_cp_client_session_message_statuses_rw_get_front(&task->m_session.m_state.m_msgs_available)->m_message_id;
		task->m_session.m_state.m_has_msg_pending = mk_lang_true;
		task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_end;
	}
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

	mk_lang_check_return
	(
		(task->m_step == mk_lib_iip_cp_client_session_task_step_e_wait_msg_request_leaseset) ||
		(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle) ||
		mk_lang_false
	);
	msg_request_variable_lease_set = &msg->m_mix.m_data.m_request_variable_lease_set;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_request_variable_lease_set->m_session_id, &task->m_session.m_state.m_id));

	err = mk_lib_iip_cp_client_session_task_prrw_prune_old_leases(task); mk_lang_check_rereturn(err);
	data = mk_lib_iip_cp_types_leases_rw_data(&msg_request_variable_lease_set->m_leases);
	size = mk_lib_iip_cp_types_leases_rw_size(&msg_request_variable_lease_set->m_leases);
	mk_lang_check_return(size != 0);
	err = mk_lib_iip_cp_types_leasez_rw_push_back_move_many(&task->m_session.m_state.m_leases, data, size); mk_lang_check_rereturn(err);

	err = mk_lib_iip_cp_message_reconstruct(&task->m_session.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_create_lease_set); mk_lang_check_rereturn(err);
	msg_create_lease_set = &task->m_session.m_state.m_msg.m_mix.m_data.m_create_lease_set;
	msg_create_lease_set->m_session_id = task->m_session.m_state.m_id;
	msg_create_lease_set->m_key_sgn_pri = task->m_session.m_settings.m_local_destination.m_private_data.m_key_dsa_sha1_pri;
	msg_create_lease_set->m_key_enc_pri = task->m_session.m_settings.m_local_destination.m_private_data.m_key_elgamal_pri;
	msg_create_lease_set->m_leaseset.m_destination = task->m_session.m_settings.m_local_destination;
	err = mk_lib_iip_cp_types_leases_rw_push_back_copy_many(&msg_create_lease_set->m_leaseset.m_leases, data, size); mk_lang_check_rereturn(err);
	task->m_session.m_state.m_has_msg_pending = mk_lang_true;

	task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_lease_set;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg_host_reply(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_lib_iip_cp_message_host_reply_pt msg_host_reply;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_session_lookup_host_name_ppt lookup_host_name_ptr;
	mk_lib_iip_cp_client_session_lookup_host_name_pt lookup_host_name_obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(task->m_session.m_state.m_has_id);
	mk_lang_assert(!task->m_session.m_state.m_has_msg_pending);

	mk_lang_check_return
	(
		(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle) ||
		(mk_lang_false)
	);
	msg_host_reply = &msg->m_mix.m_data.m_host_reply;
	mk_lang_assert(mk_lib_iip_cp_types_sessionid_eq(&msg_host_reply->m_session_id, &task->m_session.m_state.m_id));

	n = mk_lib_iip_cp_client_session_lookups_host_name_rw_size(&task->m_session.m_state.m_lookups_host_name_b);
	for(i = 0; i != n; ++i)
	{
		lookup_host_name_ptr = mk_lib_iip_cp_client_session_lookups_host_name_rw_at(&task->m_session.m_state.m_lookups_host_name_b, i); mk_lang_assert(lookup_host_name_ptr); lookup_host_name_obj = *lookup_host_name_ptr; mk_lang_assert(lookup_host_name_obj);
		if(mk_lib_iip_cp_types_requestid_eq(&lookup_host_name_obj->m_request_id, &msg_host_reply->m_request_id))
		{
			break;
		}
	}
	if(i != n)
	{
		mk_lang_clobber(&lookup_host_name_ptr);
		mk_lang_clobber(&lookup_host_name_obj);
		mk_lang_assert(lookup_host_name_ptr);
		mk_lang_assert(lookup_host_name_obj);
		mk_lang_assert(lookup_host_name_obj->m_request);
		lookup_host_name_obj->m_request->m_result_code = ((mk_lang_types_sint_t)(msg_host_reply->m_result_code));
		if(msg_host_reply->m_result_code == mk_lib_iip_cp_message_host_reply_result_code_id_e_success)
		{
			err = mk_lib_iip_buffer_rw_clear(&lookup_host_name_obj->m_request->m_destination); mk_lang_check_rereturn(err);
			err = mk_lib_iip_buffer_rw_push_back_copy_many(&lookup_host_name_obj->m_request->m_destination, &msg_host_reply->m_destination.m_buf[0], ((mk_lang_types_usize_t)(msg_host_reply->m_destination.m_len))); mk_lang_check_rereturn(err);
		}
		lookup_host_name_obj->m_request->m_done = mk_lang_true;
		err = mk_lib_iip_cp_client_session_lookups_host_name_rw_erase_element(&task->m_session.m_state.m_lookups_host_name_b, lookup_host_name_ptr); mk_lang_check_rereturn(err);
	}
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_on_msg(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(msg);

	if
	(
		(
			(task->m_step == mk_lib_iip_cp_client_session_task_step_e_destroy_sent) ||
			(task->m_step == mk_lib_iip_cp_client_session_task_step_e_destroyed_total) ||
			(mk_lang_false)
		) &&
		(msg->m_header.m_type != mk_lib_iip_cp_message_message_type_id_e_session_status)
	)
	{
		/* drop */
	}
	else
	{
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
			case mk_lib_iip_cp_message_message_type_id_e_session_status            : err = mk_lib_iip_cp_client_session_task_prrw_on_msg_session_status   (task, msg); mk_lang_check_rereturn(err); break;
			case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : err = mk_lib_iip_cp_client_session_task_prrw_on_msg_request_lease_set(task, msg); mk_lang_check_rereturn(err); break;
			case mk_lib_iip_cp_message_message_type_id_e_message_status            : err = mk_lib_iip_cp_client_session_task_prrw_on_msg_message_status   (task, msg); mk_lang_check_rereturn(err); break;
			case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_disconnect                : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_message_payload           : err = mk_lib_iip_cp_client_session_task_prrw_on_msg_message_payload(task, msg); mk_lang_check_rereturn(err); break;
			case mk_lib_iip_cp_message_message_type_id_e_get_date                  : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_set_date                  : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: err = mk_lib_iip_cp_client_session_task_prrw_on_msg_request_variable_lease_set(task, msg); mk_lang_check_rereturn(err); break;
			case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_host_reply                : err = mk_lib_iip_cp_client_session_task_prrw_on_msg_host_reply(task, msg); mk_lang_check_rereturn(err); break;
			case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : mk_lang_check_todo(); break;
			case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_make_msg_create_session(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_bool_t waiting_for_master;
	mk_lib_iip_cp_client_session_task_pt master;
	mk_lib_iip_cp_message_pt msg;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_create_session_pt msg_create_session;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_make_msg_create_session);
	mk_lang_assert(!task->m_session.m_state.m_has_msg_pending);

	waiting_for_master = mk_lang_false;
	if(!mk_lib_iip_cp_client_session_handle_is_zero(&task->m_session.m_settings.m_master_session))
	{
		master = ((mk_lib_iip_cp_client_session_task_pt)(task->m_session.m_settings.m_master_session.m_elements[0])); mk_lang_assert(master);
		if(!master->m_session.m_state.m_has_id)
		{
			waiting_for_master = mk_lang_true;
		}
	}
	if(!waiting_for_master)
	{
		msg = &task->m_session.m_state.m_msg;
		err = mk_lib_iip_cp_message_reconstruct(msg, mk_lib_iip_cp_message_message_type_id_e_create_session); mk_lang_check_rereturn(err);
		msg_create_session = &msg->m_mix.m_data.m_create_session;
		msg_create_session->m_session_config.m_destination = task->m_session.m_settings.m_local_destination;
		msg_create_session->m_session_config.m_options.m_strpairs = task->m_session.m_settings.m_options;
		mk_lib_iip_time_get_now(&msg_create_session->m_session_config.m_creation_date.m_elements[0]);
		task->m_session.m_state.m_has_msg_pending = mk_lang_true;
		task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_session;
		*step_result = mk_lib_iip_cp_client_session_task_result_e_did_something;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_session_task_result_e_idling;
	}
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

	if(!task->m_session.m_state.m_stop_requested)
	{
		*step_result = mk_lib_iip_cp_client_session_task_result_e_want_recv;
	}
	else
	{
		task->m_step = mk_lib_iip_cp_client_session_task_step_e_idle;
		*step_result = mk_lib_iip_cp_client_session_task_result_e_did_something;
	}
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_receive_message_begin(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_begin);
	mk_lang_assert(task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert(!mk_lib_iip_cp_client_session_message_statuses_rw_is_empty(&task->m_session.m_state.m_msgs_available));

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_want_send;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_receive_message_end(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_end);
	mk_lang_assert(task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert(!mk_lib_iip_cp_client_session_message_statuses_rw_is_empty(&task->m_session.m_state.m_msgs_available));

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_want_send;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_destroy_session(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_destroy_session);
	mk_lang_assert(task->m_session.m_state.m_has_msg_pending);

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_want_send;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_from_socket(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_from_socket);
	mk_lang_assert(task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert(task->m_session.m_state.m_msg_from_socket);

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_want_send;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_lookup(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_pickup_msg_lookup);
	mk_lang_assert(task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert(task->m_session.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_host_lookup);

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_want_send;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_idle_listening_sockets(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_bool_t did_something;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lib_iip_cp_client_socket_task_ppt socket_ptr;
	mk_lib_iip_cp_client_socket_task_pt socket_val;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_pt msg;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle);
	mk_lang_assert(!task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert(!task->m_session.m_state.m_msg_from_socket);

	did_something = mk_lang_false;
	++task->m_session.m_state.m_idx_listening_sockets;
	n = mk_lib_iip_cp_client_socket_tasks_rw_size(&task->m_session.m_state.m_listening_sockets);
	for(i = 0; i != n; ++i)
	{
		idx = (task->m_session.m_state.m_idx_listening_sockets + i) % n;
		socket_ptr = mk_lib_iip_cp_client_socket_tasks_rw_at(&task->m_session.m_state.m_listening_sockets, idx); mk_lang_assert(socket_ptr); socket_val = *socket_ptr; mk_lang_assert(socket_val);
		err = mk_lib_iip_cp_client_socket_task_rw_gimme_msg(socket_val, &msg); mk_lang_check_rereturn(err);
		if(msg)
		{
			task->m_session.m_state.m_has_msg_pending = mk_lang_true;
			task->m_session.m_state.m_msg_from_socket = msg;
			task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_from_socket;
			*step_result = mk_lib_iip_cp_client_session_task_result_e_did_something;
			did_something = mk_lang_true;
			break;
		}
	}
	if(!did_something)
	{
		*step_result = mk_lib_iip_cp_client_session_task_result_e_idling;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_idle_pickup_available_msg(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_message_status_pt msg_st;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_receive_message_begin_pt msg_receive_message_begin;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle);
	mk_lang_assert(!task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert(!task->m_session.m_state.m_msg_from_socket);

	if(!task->m_session.m_state.m_msg_expecting && !mk_lib_iip_cp_client_session_message_statuses_rw_is_empty(&task->m_session.m_state.m_msgs_available))
	{
		msg_st = mk_lib_iip_cp_client_session_message_statuses_rw_get_front(&task->m_session.m_state.m_msgs_available); mk_lang_assert(msg_st);

		err = mk_lib_iip_cp_message_reconstruct(&task->m_session.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_receive_message_begin); mk_lang_check_rereturn(err);
		msg_receive_message_begin = &task->m_session.m_state.m_msg.m_mix.m_data.m_receive_message_begin;
		msg_receive_message_begin->m_session_id = task->m_session.m_state.m_id;
		msg_receive_message_begin->m_message_id = msg_st->m_message_id;

		task->m_session.m_state.m_has_msg_pending = mk_lang_true;
		task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_begin;
		*step_result = mk_lib_iip_cp_client_session_task_result_e_did_something;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_session_task_result_e_idling;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_idle_erase_too_old_lookups(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_bool_t did_something;
	mk_lib_iip_time_timestamp_t now;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_session_lookup_host_name_ppt lookup_ptr;
	mk_lib_iip_cp_client_session_lookup_host_name_pt lookup_obj;
	mk_lib_iip_time_duration_t age;
	mk_lang_types_slong_t tsl;
	mk_lib_iip_time_duration_t too_old;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle);
	mk_lang_assert(!task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert(!task->m_session.m_state.m_msg_from_socket);

	did_something = mk_lang_false;
	mk_lib_iip_time_get_now(&now);
	n = mk_lib_iip_cp_client_session_lookups_host_name_rw_size(&task->m_session.m_state.m_lookups_host_name_b);
	for(i = 0; i != n; ++i)
	{
		lookup_ptr = mk_lib_iip_cp_client_session_lookups_host_name_rw_at(&task->m_session.m_state.m_lookups_host_name_b, i); mk_lang_assert(lookup_ptr); lookup_obj = *lookup_ptr; mk_lang_assert(lookup_obj);
		mk_lib_iip_time_timestamp_get_duration(&lookup_obj->m_created, &now, &age);
		tsl = 15l * 1000l; mk_lib_iip_time_duration_from_bi_slong(&too_old, &tsl);
		if(mk_lib_iip_time_duration_gt(&age, &too_old))
		{
			mk_lang_assert(lookup_obj->m_request);
			lookup_obj->m_request->m_done = mk_lang_true;
			lookup_obj->m_request->m_result_code = mk_lib_iip_cp_message_host_reply_result_code_id_e_dummy_end; /* timeout */
			err = mk_lib_iip_cp_client_session_lookups_host_name_rw_erase_at(&task->m_session.m_state.m_lookups_host_name_b, i); mk_lang_check_rereturn(err);
			did_something = mk_lang_true;
			*step_result = mk_lib_iip_cp_client_session_task_result_e_did_something;
			break;
		}
	}
	if(!did_something)
	{
		*step_result = mk_lib_iip_cp_client_session_task_result_e_idling;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_idle_connecting_sockets(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_bool_t did_something;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lib_iip_cp_client_socket_task_ppt socket_ptr;
	mk_lib_iip_cp_client_socket_task_pt socket_val;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_pt msg;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle);
	mk_lang_assert(!task->m_session.m_state.m_has_msg_pending);
	mk_lang_assert(!task->m_session.m_state.m_msg_from_socket);

	did_something = mk_lang_false;
	++task->m_session.m_state.m_idx_connecting_sockets;
	n = mk_lib_iip_cp_client_socket_tasks_rw_size(&task->m_session.m_state.m_connecting_sockets);
	for(i = 0; i != n; ++i)
	{
		idx = (task->m_session.m_state.m_idx_connecting_sockets + i) % n;
		socket_ptr = mk_lib_iip_cp_client_socket_tasks_rw_at(&task->m_session.m_state.m_connecting_sockets, idx); mk_lang_assert(socket_ptr); socket_val = *socket_ptr; mk_lang_assert(socket_val);
		err = mk_lib_iip_cp_client_socket_task_rw_gimme_msg(socket_val, &msg); mk_lang_check_rereturn(err);
		if(msg)
		{
			task->m_session.m_state.m_has_msg_pending = mk_lang_true;
			task->m_session.m_state.m_msg_from_socket = msg;
			task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_from_socket;
			*step_result = mk_lib_iip_cp_client_session_task_result_e_did_something;
			did_something = mk_lang_true;
			break;
		}
	}
	if(!did_something)
	{
		*step_result = mk_lib_iip_cp_client_session_task_result_e_idling;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_idle_lookup_host_name(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_lookup_host_name_ppt lookup_ptr;
	mk_lib_iip_cp_client_session_lookup_host_name_pt lookup_obj;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_host_lookup_pt msg_host_lookup;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle);

	if
	(
		(task->m_session.m_state.m_has_id) &&
		(!task->m_session.m_state.m_has_msg_pending) &&
		(!mk_lib_iip_cp_client_session_lookups_host_name_rw_is_empty(&task->m_session.m_state.m_lookups_host_name_a)) &&
		(mk_lang_true)
	)
	{
		lookup_ptr = mk_lib_iip_cp_client_session_lookups_host_name_rw_front(&task->m_session.m_state.m_lookups_host_name_a); mk_lang_assert(lookup_ptr); lookup_obj = *lookup_ptr; mk_lang_assert(lookup_obj);
		mk_lang_assert(lookup_obj->m_request);
		mk_lang_assert(!lookup_obj->m_request->m_done);
		mk_lang_assert(lookup_obj->m_request->m_host_name_buf);
		mk_lang_assert(lookup_obj->m_request->m_host_name_len >= 0x01);
		mk_lang_assert(lookup_obj->m_request->m_host_name_len <= 0xff);

		err = mk_lib_iip_cp_message_reconstruct(&task->m_session.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_host_lookup); mk_lang_check_rereturn(err);
		msg_host_lookup = &task->m_session.m_state.m_msg.m_mix.m_data.m_host_lookup;
		msg_host_lookup->m_session_id = task->m_session.m_state.m_id;
		msg_host_lookup->m_request_id = lookup_obj->m_request_id;
		msg_host_lookup->m_timeout_ms = 10 * 1000;
		msg_host_lookup->m_request_type = mk_lib_iip_cp_message_host_lookup_request_type_id_e_name;
		msg_host_lookup->m_hostname.m_len = lookup_obj->m_request->m_host_name_len;
		mk_lang_string_memcpy_pc_fn(&msg_host_lookup->m_hostname.m_buf[0], lookup_obj->m_request->m_host_name_buf, ((mk_lang_types_usize_t)(lookup_obj->m_request->m_host_name_len)));
		mk_lib_iip_time_get_now(&lookup_obj->m_created);

		err = mk_lib_iip_cp_client_session_lookups_host_name_rw_push_back_move_single(&task->m_session.m_state.m_lookups_host_name_b, lookup_ptr); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_session_lookups_host_name_rw_pop_front_single(&task->m_session.m_state.m_lookups_host_name_a); mk_lang_check_rereturn(err);

		task->m_session.m_state.m_has_msg_pending = mk_lang_true;
		task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_lookup;
		*step_result = mk_lib_iip_cp_client_session_task_result_e_did_something;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_session_task_result_e_idling;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_idle_construct_destroy_session_msg(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_destroy_session_pt msg_destroy_session;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle);

	if
	(
		(task->m_session.m_state.m_stop_requested && !task->m_session.m_state.m_has_msg_pending && !mk_lib_iip_cp_client_session_handle_is_zero(&task->m_session.m_settings.m_master_session)) ||
		(task->m_session.m_state.m_stop_requested && !task->m_session.m_state.m_has_msg_pending && mk_lib_iip_cp_client_session_handle_is_zero(&task->m_session.m_settings.m_master_session) && task->m_session.m_state.m_child_sessions == 0) ||
		(mk_lang_false)
	)
	{
		err = mk_lib_iip_cp_message_reconstruct(&task->m_session.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_destroy_session); mk_lang_check_rereturn(err);
		msg_destroy_session = &task->m_session.m_state.m_msg.m_mix.m_data.m_destroy_session;
		msg_destroy_session->m_session_id = task->m_session.m_state.m_id;
		task->m_session.m_state.m_has_msg_pending = mk_lang_true;
		task->m_step = mk_lib_iip_cp_client_session_task_step_e_pickup_msg_destroy_session;
		*step_result = mk_lib_iip_cp_client_session_task_result_e_did_something;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_session_task_result_e_idling;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_idle(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_idle);

	stp_res = mk_lib_iip_cp_client_session_task_result_e_idling;
	if(stp_res == mk_lib_iip_cp_client_session_task_result_e_idling){ stp_res = mk_lib_iip_cp_client_session_task_result_e_dummy_end; err = mk_lib_iip_cp_client_session_task_prrw_step_idle_construct_destroy_session_msg(task, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_session_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_session_task_result_e_idling){ stp_res = mk_lib_iip_cp_client_session_task_result_e_dummy_end; err = mk_lib_iip_cp_client_session_task_prrw_step_idle_lookup_host_name             (task, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_session_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_session_task_result_e_idling){ stp_res = mk_lib_iip_cp_client_session_task_result_e_dummy_end; err = mk_lib_iip_cp_client_session_task_prrw_step_idle_connecting_sockets           (task, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_session_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_session_task_result_e_idling){ stp_res = mk_lib_iip_cp_client_session_task_result_e_dummy_end; err = mk_lib_iip_cp_client_session_task_prrw_step_idle_listening_sockets            (task, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_session_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_session_task_result_e_idling){ stp_res = mk_lib_iip_cp_client_session_task_result_e_dummy_end; err = mk_lib_iip_cp_client_session_task_prrw_step_idle_pickup_available_msg         (task, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_session_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_session_task_result_e_idling){ stp_res = mk_lib_iip_cp_client_session_task_result_e_dummy_end; err = mk_lib_iip_cp_client_session_task_prrw_step_idle_erase_too_old_lookups        (task, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_session_task_result_e_dummy_end); }
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_destroy_sent(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_destroy_sent);

	((mk_lang_types_void_t)(task));
	*step_result = mk_lib_iip_cp_client_session_task_result_e_idling;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_step_destroyed_total(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_session_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_session_task_step_e_destroyed_total);

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
		case mk_lib_iip_cp_client_session_task_step_e_make_msg_create_session         : err = mk_lib_iip_cp_client_session_task_prrw_step_make_msg_create_session         (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_session       : err = mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_create_session       (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_wait_msg_session_status         : err = mk_lib_iip_cp_client_session_task_prrw_step_wait_msg_session_status         (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_wait_msg_request_leaseset       : err = mk_lib_iip_cp_client_session_task_prrw_step_wait_msg_request_leaseset       (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_pickup_msg_create_lease_set     : err = mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_create_lease_set     (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_begin: err = mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_receive_message_begin(task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_pickup_msg_receive_message_end  : err = mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_receive_message_end  (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_pickup_msg_destroy_session      : err = mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_destroy_session      (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_pickup_msg_from_socket          : err = mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_from_socket          (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_pickup_msg_lookup               : err = mk_lib_iip_cp_client_session_task_prrw_step_pickup_msg_lookup               (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_idle                            : err = mk_lib_iip_cp_client_session_task_prrw_step_idle                            (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_destroy_sent                    : err = mk_lib_iip_cp_client_session_task_prrw_step_destroy_sent                    (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_session_task_step_e_destroyed_total                 : err = mk_lib_iip_cp_client_session_task_prrw_step_destroyed_total                 (task, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_session_task_result_e_dummy_end); break;
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

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_request_close(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	mk_lang_assert(task);

	task->m_session.m_state.m_stop_requested = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_want_die(mk_lib_iip_cp_client_session_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lang_types_bool_t wand;

	mk_lang_assert(task);
	mk_lang_assert(want);

	wand =
		(task->m_step == mk_lib_iip_cp_client_session_task_step_e_destroy_sent) ||
		(task->m_step == mk_lib_iip_cp_client_session_task_step_e_destroyed_total) ||
		(mk_lang_false);
	*want = wand;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_lookup_host_name(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_types_lookup_host_name_pt const request) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t uptr;
	mk_lib_iip_cp_client_session_task_pt session;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_lookup_host_name_pt req;
	mk_lib_iip_cp_client_session_lookup_host_name_pt rrr;
	mk_lang_types_void_pt mem;

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
	mk_lang_assert(session == task);

	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*req), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); req = ((mk_lib_iip_cp_client_session_lookup_host_name_pt)(mem)); mk_lang_assert(req); rrr = req;
	err = mk_lib_iip_cp_client_session_lookups_host_name_rw_push_back_move_single(&task->m_session.m_state.m_lookups_host_name_a, &req); mk_lang_check_rereturn(err); req = rrr;
	err = mk_lib_iip_random_generate_u32_non_zero(&req->m_request_id.m_elements[0]); mk_lang_check_rereturn(err);
	req->m_request = request;
	uptr = ((mk_lang_bui_uintptr_t)(req)); mk_lib_iip_cp_client_types_handle_lookup_host_name_from_base(&request->m_internal, &uptr);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_get_new_local_port(mk_lib_iip_cp_client_session_task_pt const task, mk_sl_cui_uint16_pt const port) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(port);

	err = mk_lib_iip_random_generate_u16_any(port); mk_lang_check_rereturn(err);
	/* todo not clashing with existing sockets */
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_prrw_connect_to(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_types_socket_connect_settings_pct const settings, mk_lib_iip_cp_client_types_handle_socket_connect_pt const socket) mk_lang_noexcept
{
	mk_lang_bui_uintptr_t uptr;
	mk_lib_iip_cp_client_session_task_pt session;
	mk_lib_iip_cp_client_socket_settings_t config;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_socket_task_pt sck;
	mk_lang_types_void_pt mem;
	mk_lib_iip_cp_client_socket_task_pt sss;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(socket);
	mk_lang_assert(!mk_lib_iip_cp_client_types_handle_session_is_zero(&settings->m_session));
	mk_lang_assert((mk_lib_iip_cp_client_types_handle_session_to_base(&settings->m_session, &uptr), uptr != 0));
	mk_lang_assert((session = ((mk_lib_iip_cp_client_session_task_pt)(uptr)), session));
	mk_lang_assert(session == task);

	config.m_shared = task->m_session.m_state.m_shared;
	config.m_session_id = &task->m_session.m_state.m_id;
	config.m_listener = mk_lang_false;
	config.m_local_destination = &task->m_session.m_settings.m_local_destination;
	err = mk_lib_iip_cp_client_session_task_prrw_get_new_local_port(task, &config.m_local_port); mk_lang_check_rereturn(err);
	config.m_remote_destination = settings->m_destination;
	config.m_remote_port = settings->m_port;

	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*sck), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); sck = ((mk_lib_iip_cp_client_socket_task_pt)(mem)); mk_lang_assert(sck);
	err = mk_lib_iip_cp_client_socket_task_rw_construct(sck, &config); mk_lang_check_rereturn(err); sss = sck;
	err = mk_lib_iip_cp_client_socket_tasks_rw_push_back_move_single(&task->m_session.m_state.m_connecting_sockets, &sck); mk_lang_check_rereturn(err); sck = sss;
	uptr = ((mk_lang_bui_uintptr_t)(sck));
	mk_lib_iip_cp_client_types_handle_socket_connect_from_base(socket, &uptr);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_construct(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_shared_pt const shared, mk_lib_iip_cp_client_session_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_construct(task, shared, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_destroy(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_on_child_session_spawned(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_on_child_session_spawned(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_on_child_session_died(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_on_child_session_died(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_new_socket_listener(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_types_socket_listener_settings_pct const settings, mk_lib_iip_cp_client_types_handle_socket_listener_pt const socket_listener) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_new_socket_listener(task, settings, socket_listener);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_gimme_msg(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_ppt const msg) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_gimme_msg(task, msg);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_on_msg(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_on_msg(task, msg);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_step(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_session_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_step(task, step_result);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_request_close(mk_lib_iip_cp_client_session_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_request_close(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_want_die(mk_lib_iip_cp_client_session_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_want_die(task, want);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_lookup_host_name(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_types_lookup_host_name_pt const request) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_lookup_host_name(task, request);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_session_task_rw_connect_to(mk_lib_iip_cp_client_session_task_pt const task, mk_lib_iip_cp_client_types_socket_connect_settings_pct const settings, mk_lib_iip_cp_client_types_handle_socket_connect_pt const socket) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_session_task_prrw_connect_to(task, settings, socket);
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
	mk_lib_iip_cp_client_session_task_pt tmp;

	mk_lang_assert(dst);
	mk_lang_assert(src);

	tmp = *dst;
	*dst = *src;
	*src = tmp;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_client_session_task_ptr_ro_eq(mk_lib_iip_cp_client_session_task_pcpt const a, mk_lib_iip_cp_client_session_task_pcpt const b) mk_lang_noexcept
{
	mk_lang_types_bool_t eq;

	mk_lang_assert(a);
	mk_lang_assert(b);

	eq = *a == *b;
	return eq;
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
#define mk_sl_vector_t_element_eq mk_lib_iip_cp_client_session_task_ptr_ro_eq
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
