#ifndef mk_include_guard_mk_lib_iip_cp_client_local_listener_c
#define mk_include_guard_mk_lib_iip_cp_client_local_listener_c
#include "mk_lib_iip_cp_client_local_listener_task.h"

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


#define mk_sl_cui_t_name mk_lib_iip_cp_client_local_listener_handle
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#if defined mk_lib_iip_cp_client_local_listener_debug_print_want
#if (mk_lib_iip_cp_client_local_listener_debug_print_want) == 0
#define mk_lib_iip_cp_client_local_listener_debug_print_have 0
#elif (mk_lib_iip_cp_client_local_listener_debug_print_want) == 1
#define mk_lib_iip_cp_client_local_listener_debug_print_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_lib_iip_cp_client_local_listener_debug_print_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lib_iip_cp_client_local_listener_debug_print_have 0
#else
#define mk_lib_iip_cp_client_local_listener_debug_print_have 1
#endif
#endif
#endif


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_construct(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lib_iip_cp_client_local_listener_task_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(settings->m_shared);
	mk_lang_assert(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));
	mk_lang_assert(!mk_lib_net_tcp_port_is_zero(&settings->m_destination.m_tcp_port));
	mk_lang_assert(!mk_lib_net_tcp_port_is_max(&settings->m_destination.m_tcp_port));

	task->m_step = ((mk_lib_iip_cp_client_local_listener_task_step_t)(0));
	task->m_local.m_settings.m_shared = settings->m_shared;
	task->m_local.m_settings.m_destination.m_ipv4_address = settings->m_destination.m_ipv4_address;
	task->m_local.m_settings.m_destination.m_tcp_port = settings->m_destination.m_tcp_port;
	err = mk_lib_net_socket_construct_void(&task->m_local.m_state.m_listening_socket); mk_lang_check_rereturn(err);
	task->m_local.m_state.m_stop_requested = mk_lang_false;
	task->m_local.m_state.m_stop_acknowledged = mk_lang_false;
	err = mk_lib_iip_cp_client_local_client_tasks_rw_construct(&task->m_local.m_state.m_clients); mk_lang_check_rereturn(err);
	task->m_local.m_state.m_client_idx = 0;
	task->m_local.m_state.m_client_want_associate = mk_lang_null;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_destroy(mk_lib_iip_cp_client_local_listener_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_net_socket_destroy(&task->m_local.m_state.m_listening_socket); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_local_client_tasks_rw_destroy(&task->m_local.m_state.m_clients); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_request_close(mk_lib_iip_cp_client_local_listener_task_pt const task) mk_lang_noexcept
{
	mk_lang_assert(task);

	task->m_local.m_state.m_stop_requested = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_lib_iip_cp_client_local_listener_task_prrw_want_associate_socket(mk_lib_iip_cp_client_local_listener_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_bool_t want;

	mk_lang_assert(task);

	want =
		task->m_step == mk_lib_iip_cp_client_local_listener_task_step_e_want_associate_socket ||
		task->m_local.m_state.m_client_want_associate != mk_lang_null ||
		mk_lang_false;
	return want;
}

mk_lang_nodiscard static mk_lang_inline mk_lib_net_socket_pt mk_lib_iip_cp_client_local_listener_task_prrw_gimme_socket(mk_lib_iip_cp_client_local_listener_task_pt const task) mk_lang_noexcept
{
	mk_lib_net_socket_pt socket;

	mk_lang_assert(task);
	mk_lang_assert(mk_lib_iip_cp_client_local_listener_task_prrw_want_associate_socket(task));

	if(task->m_step == mk_lib_iip_cp_client_local_listener_task_step_e_want_associate_socket)
	{
		socket = &task->m_local.m_state.m_listening_socket;
		task->m_step = mk_lib_iip_cp_client_local_listener_task_step_e_bind_socket;
	}
	else if(task->m_local.m_state.m_client_want_associate != mk_lang_null)
	{
		socket = mk_lib_iip_cp_client_local_client_task_rw_gimme_socket(task->m_local.m_state.m_client_want_associate);
		task->m_local.m_state.m_client_want_associate = mk_lang_null;
	}
	else
	{
		mk_lang_assert_false();
	}
	mk_lang_clobber(&socket);
	return socket;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_on_iorp_done(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);

	mk_lang_assert_false();
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_step_create_socket(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_listener_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_listener_task_step_e_create_socket);

	err = mk_lib_net_socket_reconstruct(&task->m_local.m_state.m_listening_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&task->m_local.m_state.m_listening_socket); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_listener_task_step_e_want_associate_socket;
	*step_result = mk_lib_iip_cp_client_local_listener_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_step_want_associate_socket(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_listener_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_listener_task_step_e_want_associate_socket);

	*step_result = mk_lib_iip_cp_client_local_listener_task_result_e_did_nothing;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_step_bind_socket(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_listener_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_listener_task_step_e_bind_socket);

	err = mk_lib_net_socket_bind(&task->m_local.m_state.m_listening_socket, &task->m_local.m_settings.m_destination); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_listener_task_step_e_listen_socket;
	*step_result = mk_lib_iip_cp_client_local_listener_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_step_listen_socket(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_listener_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_listener_task_step_e_listen_socket);

	err = mk_lib_net_socket_listen(&task->m_local.m_state.m_listening_socket); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_listener_task_step_e_create_client;
	*step_result = mk_lib_iip_cp_client_local_listener_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_step_create_client(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_listener_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_client_task_settings_t settings;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_local_client_task_pt client;
	mk_lang_types_void_pt mem;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_listener_task_step_e_create_client);

	settings.m_shared = task->m_local.m_settings.m_shared;
	settings.m_listening_socket = task->m_local.m_state.m_listening_socket;
	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*client), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); client = ((mk_lib_iip_cp_client_local_client_task_pt)(mem)); mk_lang_assert(client);
	err = mk_lib_iip_cp_client_local_client_task_rw_construct(client, &settings); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_local_client_tasks_rw_push_back_move_single(&task->m_local.m_state.m_clients, &client); mk_lang_check_rereturn(err);
	task->m_step = mk_lib_iip_cp_client_local_listener_task_step_e_idle;
	*step_result = mk_lib_iip_cp_client_local_listener_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_step_idle_no_stop(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_listener_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_bool_t at_least_one_would_block;
	mk_lang_types_bool_t want_want_associate;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lang_types_bool_t break2;
	mk_lib_iip_cp_client_local_client_task_ppt client_ptr;
	mk_lib_iip_cp_client_local_client_task_pt client_val;
	mk_lib_iip_cp_client_local_client_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_listener_task_step_e_idle);

	task->m_local.m_state.m_client_want_associate = mk_lang_null;
	at_least_one_would_block = mk_lang_false;
	++task->m_local.m_state.m_client_idx;
	n = mk_lib_iip_cp_client_local_client_tasks_rw_size(&task->m_local.m_state.m_clients);
	for(i = 0; i != n; ++i)
	{
		idx = task->m_local.m_state.m_client_idx + i;
		idx = idx % n;
		break2 = mk_lang_false;
		client_ptr = mk_lib_iip_cp_client_local_client_tasks_rw_at(&task->m_local.m_state.m_clients, i); mk_lang_assert(client_ptr); client_val = *client_ptr; mk_lang_assert(client_val);
		stp_res = mk_lib_iip_cp_client_local_client_task_result_e_dummy_end;
		err = mk_lib_iip_cp_client_local_client_task_rw_step(client_val, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_local_client_task_result_e_dummy_end);
		switch(stp_res)
		{
			case mk_lib_iip_cp_client_local_client_task_result_e_did_something:
			{
				*step_result = mk_lib_iip_cp_client_local_listener_task_result_e_did_something;
				break2 = mk_lang_true;
			}
			break;
			case mk_lib_iip_cp_client_local_client_task_result_e_would_block:
			{
				at_least_one_would_block = mk_lang_true;
			}
			break;
			case mk_lib_iip_cp_client_local_client_task_result_e_timed_out:
			{
				*step_result = mk_lib_iip_cp_client_local_listener_task_result_e_timed_out;
				break2 = mk_lang_true;
			}
			break;
			case mk_lib_iip_cp_client_local_client_task_result_e_did_nothing:
			{
				want_want_associate = mk_lib_iip_cp_client_local_client_task_rw_want_associate_socket(client_val);
				if(want_want_associate)
				{
					task->m_local.m_state.m_client_want_associate = client_val;
				}
			}
			break;
			case mk_lib_iip_cp_client_local_client_task_result_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}
		if(break2)
		{
			break;
		}
	}
	if(i == n)
	{
		if(at_least_one_would_block)
		{
			*step_result = mk_lib_iip_cp_client_local_listener_task_result_e_would_block;
		}
		else
		{
			*step_result = mk_lib_iip_cp_client_local_listener_task_result_e_did_nothing;
		}
	}
	else
	{
		mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_listener_task_result_e_did_something);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_step_idle_do_stop(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_listener_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_local_client_task_ppt client_ptr;
	mk_lib_iip_cp_client_local_client_task_pt client_val;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_listener_task_step_e_idle);

	n = mk_lib_iip_cp_client_local_client_tasks_rw_size(&task->m_local.m_state.m_clients);
	for(i = 0; i != n; ++i)
	{
		client_ptr = mk_lib_iip_cp_client_local_client_tasks_rw_at(&task->m_local.m_state.m_clients, i); mk_lang_assert(client_ptr); client_val = *client_ptr; mk_lang_assert(client_val);
		err = mk_lib_iip_cp_client_local_client_task_rw_request_close(client_val); mk_lang_check_rereturn(err);
	}
	*step_result = mk_lib_iip_cp_client_local_listener_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_step_idle(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_listener_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);
	mk_lang_assert(task->m_step == mk_lib_iip_cp_client_local_listener_task_step_e_idle);

	if(task->m_local.m_state.m_stop_requested && !task->m_local.m_state.m_stop_acknowledged)
	{
		task->m_local.m_state.m_stop_acknowledged = mk_lang_true;
		err = mk_lib_iip_cp_client_local_listener_task_prrw_step_idle_do_stop(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);
	}
	else
	{
		err = mk_lib_iip_cp_client_local_listener_task_prrw_step_idle_no_stop(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_prrw_step(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_listener_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end);

	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_local_listener_task_step_e_create_socket        : err = mk_lib_iip_cp_client_local_listener_task_prrw_step_create_socket        (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_listener_task_step_e_want_associate_socket: err = mk_lib_iip_cp_client_local_listener_task_prrw_step_want_associate_socket(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_listener_task_step_e_bind_socket          : err = mk_lib_iip_cp_client_local_listener_task_prrw_step_bind_socket          (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_listener_task_step_e_listen_socket        : err = mk_lib_iip_cp_client_local_listener_task_prrw_step_listen_socket        (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_listener_task_step_e_create_client        : err = mk_lib_iip_cp_client_local_listener_task_prrw_step_create_client        (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_listener_task_step_e_idle                 : err = mk_lib_iip_cp_client_local_listener_task_prrw_step_idle                 (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_local_listener_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_local_listener_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_rw_construct(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lib_iip_cp_client_local_listener_task_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_listener_task_prrw_construct(task, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_rw_destroy(mk_lib_iip_cp_client_local_listener_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_listener_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_rw_request_close(mk_lib_iip_cp_client_local_listener_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_listener_task_prrw_request_close(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_client_local_listener_task_rw_want_associate_socket(mk_lib_iip_cp_client_local_listener_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_listener_task_prrw_want_associate_socket(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lib_net_socket_pt mk_lib_iip_cp_client_local_listener_task_rw_gimme_socket(mk_lib_iip_cp_client_local_listener_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_listener_task_prrw_gimme_socket(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_rw_on_iorp_done(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_listener_task_prrw_on_iorp_done(task, bytes_transferred, overlapped);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_rw_step(mk_lib_iip_cp_client_local_listener_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_local_listener_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_local_listener_task_prrw_step(task, allow_to_block, tm, step_result);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_ptr_rw_construct_void(mk_lib_iip_cp_client_local_listener_task_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_ptr_rw_destroy(mk_lib_iip_cp_client_local_listener_task_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_local_listener_task_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_local_listener_task_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_ptr_rw_construct_copy(mk_lib_iip_cp_client_local_listener_task_ppt const dst, mk_lib_iip_cp_client_local_listener_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_ptr_rw_construct_move(mk_lib_iip_cp_client_local_listener_task_ppt const dst, mk_lib_iip_cp_client_local_listener_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_ptr_rw_assign_copy(mk_lib_iip_cp_client_local_listener_task_ppt const dst, mk_lib_iip_cp_client_local_listener_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_local_listener_task_ptr_rw_assign_move(mk_lib_iip_cp_client_local_listener_task_ppt const dst, mk_lib_iip_cp_client_local_listener_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_local_listener_tasks
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_local_listener_task_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_local_listener_task_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_local_listener_task_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_local_listener_task_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_local_listener_task_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_local_listener_task_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_local_listener_task_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
