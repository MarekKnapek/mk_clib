#ifndef mk_include_guard_mk_lib_iip_cp_client_connection_c
#define mk_include_guard_mk_lib_iip_cp_client_connection_c
#include "mk_lib_iip_cp_client_connection_task.h"

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
#include "mk_lang_offsetof.h"
#include "mk_lang_roundup.h"
#include "mk_lang_types.h"
#include "mk_lib_fmt.h"
#include "mk_lib_iip_any_data_connection.h"
#include "mk_lib_iip_cp_client_session.h"
#include "mk_lib_iip_cp_client_shared.h"
#include "mk_lib_iip_cp_client_types.h"
#include "mk_lib_iip_cp_destination.h"
#include "mk_lib_iip_cp_dynamic_ring.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_lib_iip_cp_message.h"
#include "mk_lib_iip_cp_message_parse.h"
#include "mk_lib_iip_cp_message_serialize.h"
#include "mk_lib_iip_cp_message_str.h"
#include "mk_lib_iip_cp_types.h"
#include "mk_lib_iip_key_enc_elgamal_pri.h"
#include "mk_lib_iip_key_enc_elgamal_pub.h"
#include "mk_lib_iip_logger.h"
#include "mk_lib_iip_logger_more.h"
#include "mk_lib_iip_time.h"
#include "mk_lib_net.h"
#include "mk_sl_cui_uint8.h"
#include "mk_sl_time.h"


#define mk_sl_cui_t_name mk_lib_iip_cp_client_connection_handle
#define mk_sl_cui_t_base_type_name mk_lang_bui_uintptr
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_lang_bui_uintptr_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


#define mk_lib_iip_cp_client_connection_k_buffer_size (64 * 1024)


#if defined mk_lib_iip_cp_client_connection_debug_print_want
#if (mk_lib_iip_cp_client_connection_debug_print_want) == 0
#define mk_lib_iip_cp_client_connection_debug_print_have 0
#elif (mk_lib_iip_cp_client_connection_debug_print_want) == 1
#define mk_lib_iip_cp_client_connection_debug_print_have 1
#else
#error xxxxxxxxxx
#endif
#else
#if defined DEBUG || defined _DEBUG
#define mk_lib_iip_cp_client_connection_debug_print_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lib_iip_cp_client_connection_debug_print_have 0
#else
#define mk_lib_iip_cp_client_connection_debug_print_have 1
#endif
#endif
#endif


mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_cp_client_connection_k_api_ver[] = "0.9.66";


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_compute_time_offset(mk_lib_iip_cp_types_date_pct const time_server, mk_lib_iip_cp_types_date_pt const time_offset) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
	mk_lib_iip_cp_types_date_t time_client;

	mk_lang_assert(time_server);
	mk_lang_assert(time_offset);

	mk_lib_iip_time_get_now(&time_client.m_elements[0]);
	mk_lib_iip_cp_types_date_sub3_wrap_cid_cod(&time_client, time_server, time_offset);
	return 0;
#else
	mk_lang_assert(time_server);
	mk_lang_assert(time_offset);

	((mk_lang_types_void_t)(time_server));
	((mk_lang_types_void_t)(time_offset));
	return 0;
#endif
}

#if mk_lib_iip_cp_client_connection_debug_print_have
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset_k_fmt[] = "Our time offset from server time is %lld ms.";
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_types_date_pct const time_server) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_types_date_t time_offset;
	mk_lang_types_sint_t str_len;
	mk_lang_types_pchar_t str_buf[512];

	mk_lang_assert(task);
	mk_lang_assert(time_server);
	mk_lang_assert(task->m_connection.m_settings.m_shared);

	err = mk_lib_iip_cp_client_connection_debug_print_compute_time_offset(time_server, &time_offset); mk_lang_check_rereturn(err);
	str_len = mk_lib_fmt_n_snnprintf(&str_buf[0], mk_lang_countof(str_buf), &mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset_k_fmt[0], mk_lang_countstr(mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset_k_fmt), &time_offset.m_elements[0]); mk_lang_check_return(str_len >= 1); mk_lang_assert(str_len <= mk_lang_countof(str_buf));
	err = mk_lib_iip_logger_rw_begin_line(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_append_current_time(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(&task->m_connection.m_settings.m_shared->m_logger, &str_buf[0], str_len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_line(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(task);
	mk_lang_assert(time_server);

	((mk_lang_types_void_t)(task));
	((mk_lang_types_void_t)(time_server));
	return 0;
#endif
}

enum mk_lib_iip_cp_client_connection_debug_print_direction_e
{
	mk_lib_iip_cp_client_connection_debug_print_direction_e_incomming,
	mk_lib_iip_cp_client_connection_debug_print_direction_e_outgoing,
	mk_lib_iip_cp_client_connection_debug_print_direction_e_dummy_end
};
typedef enum mk_lib_iip_cp_client_connection_debug_print_direction_e mk_lib_iip_cp_client_connection_debug_print_direction_t;

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_msg(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_message_pct const msg, mk_lib_iip_cp_client_connection_debug_print_direction_t const direction) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pt target_buf;
	mk_lang_types_pchar_t str_buf[64 * 1024];
	mk_lang_types_sint_t target_len;
	mk_lang_types_sint_t str_len;
	mk_lib_iip_logger_color_text_t color;

	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(direction >= 0);
	mk_lang_assert(direction < mk_lib_iip_cp_client_connection_debug_print_direction_e_dummy_end);
	mk_lang_assert(task->m_connection.m_settings.m_shared);

	err = mk_lib_iip_logger_rw_begin_line(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_append_current_time(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	target_buf = &str_buf[0];
	target_len = mk_lang_countof(str_buf);
	err = mk_lib_net_socket_to_text(&task->m_connection.m_state.m_socket, target_buf, target_len, &str_len); mk_lang_check_rereturn(err); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= target_len);
	err = mk_lib_iip_logger_rw_begin_color(&task->m_connection.m_settings.m_shared->m_logger, mk_lib_iip_logger_color_text_e_dark_cyan); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(&task->m_connection.m_settings.m_shared->m_logger, target_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_color(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print_str_lit(&task->m_connection.m_settings.m_shared->m_logger, " "); mk_lang_check_rereturn(err);
	target_buf = &str_buf[0];
	target_len = mk_lang_countof(str_buf);
	color = direction == mk_lib_iip_cp_client_connection_debug_print_direction_e_incomming ? mk_lib_iip_logger_color_text_e_dark_green : mk_lib_iip_logger_color_text_e_dark_yellow;
	err = mk_lib_iip_cp_message_str_to_json_message(target_buf, target_len, &str_len, msg); mk_lang_check_rereturn(err); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= target_len);
	err = mk_lib_iip_logger_rw_begin_color(&task->m_connection.m_settings.m_shared->m_logger, color); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(&task->m_connection.m_settings.m_shared->m_logger, target_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_color(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_line(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(task);
	mk_lang_assert(msg);
	mk_lang_assert(direction >= 0);
	mk_lang_assert(direction < mk_lib_iip_cp_client_connection_debug_print_direction_e_dummy_end);

	((mk_lang_types_void_t)(task));
	((mk_lang_types_void_t)(msg));
	((mk_lang_types_void_t)(direction));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_requesting_read(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pt target_buf;
	mk_lang_types_pchar_t str_buf[4 * 1024];
	mk_lang_types_sint_t target_len;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(task);

	err = mk_lib_iip_logger_rw_begin_line(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_append_current_time(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	target_buf = &str_buf[0];
	target_len = mk_lang_countof(str_buf);
	err = mk_lib_net_socket_to_text(&task->m_connection.m_state.m_socket, target_buf, target_len, &str_len); mk_lang_check_rereturn(err); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= target_len);
	err = mk_lib_iip_logger_rw_begin_color(&task->m_connection.m_settings.m_shared->m_logger, mk_lib_iip_logger_color_text_e_dark_cyan); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(&task->m_connection.m_settings.m_shared->m_logger, target_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_color(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print_str_lit(&task->m_connection.m_settings.m_shared->m_logger, " "); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_begin_color(&task->m_connection.m_settings.m_shared->m_logger, mk_lib_iip_logger_color_text_e_dark_green); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print_str_lit(&task->m_connection.m_settings.m_shared->m_logger, "Requesting read."); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_color(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_line(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(task);

	((mk_lang_types_void_t)(task));
	return 0;
#endif
}

#if mk_lib_iip_cp_client_connection_debug_print_have
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_cp_client_connection_debug_print_read_finished_k_fmt[] = "Read finished in %t.";
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_read_finished(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
	mk_lib_iip_logger_pt logger;
	mk_lang_types_pchar_pt sml_str_ptr;
	mk_lang_types_pchar_t sml_str_buf[64];
	mk_lang_types_sint_t sml_str_cap;
	mk_lang_types_pchar_pt big_str_ptr;
	mk_lang_types_pchar_t big_str_buf[1 * 1024];
	mk_lang_types_sint_t big_str_cap;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t sml_str_len;
	mk_sl_time_timestamp_t now;
	mk_sl_time_duration_t dur;
	mk_lang_types_sint_t big_str_len;

	mk_lang_assert(task);

	logger = &task->m_connection.m_settings.m_shared->m_logger;
	sml_str_ptr = &sml_str_buf[0];
	sml_str_cap = mk_lang_countof(sml_str_buf);
	big_str_ptr = &big_str_buf[0];
	big_str_cap = mk_lang_countof(big_str_buf);
	err = mk_lib_iip_logger_rw_begin_line(logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_append_current_time(logger); mk_lang_check_rereturn(err);

	err = mk_lib_net_socket_to_text(&task->m_connection.m_state.m_socket, sml_str_ptr, sml_str_cap, &sml_str_len); mk_lang_check_rereturn(err); mk_lang_assert(sml_str_len >= 1); mk_lang_assert(sml_str_len <= sml_str_cap);
	err = mk_lib_iip_logger_rw_begin_color(logger, mk_lib_iip_logger_color_text_e_dark_cyan); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(logger, sml_str_ptr, sml_str_len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_color(logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print_str_lit(logger, " "); mk_lang_check_rereturn(err);

	mk_sl_time_timestamp_get_now(&now);
	mk_sl_time_timestamp_get_duration(&task->m_connection.m_state.m_time_req_recv, &now, &dur);
	sml_str_len = mk_sl_time_duration_to_text(&dur, sml_str_ptr, sml_str_cap); mk_lang_assert(sml_str_len >= 1); mk_lang_assert(sml_str_len <= sml_str_cap);
	big_str_len = mk_lib_fmt_n_snnprintf(big_str_buf, big_str_cap, &mk_lib_iip_cp_client_connection_debug_print_read_finished_k_fmt[0], mk_lang_countstr(mk_lib_iip_cp_client_connection_debug_print_read_finished_k_fmt), sml_str_ptr, sml_str_len); mk_lang_check_return(big_str_len >= 1); mk_lang_assert(big_str_len <= big_str_cap);
	err = mk_lib_iip_logger_rw_begin_color(logger, mk_lib_iip_logger_color_text_e_dark_green); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(logger, big_str_ptr, big_str_len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_color(logger); mk_lang_check_rereturn(err);

	err = mk_lib_iip_logger_rw_end_line(logger); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(task);

	((mk_lang_types_void_t)(task));
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_requesting_write(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pt target_buf;
	mk_lang_types_pchar_t str_buf[4 * 1024];
	mk_lang_types_sint_t target_len;
	mk_lang_types_sint_t str_len;

	mk_lang_assert(task);

	err = mk_lib_iip_logger_rw_begin_line(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_append_current_time(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	target_buf = &str_buf[0];
	target_len = mk_lang_countof(str_buf);
	err = mk_lib_net_socket_to_text(&task->m_connection.m_state.m_socket, target_buf, target_len, &str_len); mk_lang_check_rereturn(err); mk_lang_assert(str_len >= 1); mk_lang_assert(str_len <= target_len);
	err = mk_lib_iip_logger_rw_begin_color(&task->m_connection.m_settings.m_shared->m_logger, mk_lib_iip_logger_color_text_e_dark_cyan); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(&task->m_connection.m_settings.m_shared->m_logger, target_buf, str_len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_color(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print_str_lit(&task->m_connection.m_settings.m_shared->m_logger, " "); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_begin_color(&task->m_connection.m_settings.m_shared->m_logger, mk_lib_iip_logger_color_text_e_dark_yellow); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print_str_lit(&task->m_connection.m_settings.m_shared->m_logger, "Requesting write."); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_color(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_line(&task->m_connection.m_settings.m_shared->m_logger); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(task);

	((mk_lang_types_void_t)(task));
	return 0;
#endif
}

#if mk_lib_iip_cp_client_connection_debug_print_have
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_cp_client_connection_debug_print_write_finished_k_fmt[] = "Write finished in %t.";
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_debug_print_write_finished(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
#if mk_lib_iip_cp_client_connection_debug_print_have
	mk_lib_iip_logger_pt logger;
	mk_lang_types_pchar_pt sml_str_ptr;
	mk_lang_types_pchar_t sml_str_buf[64];
	mk_lang_types_sint_t sml_str_cap;
	mk_lang_types_pchar_pt big_str_ptr;
	mk_lang_types_pchar_t big_str_buf[1 * 1024];
	mk_lang_types_sint_t big_str_cap;
	mk_lang_types_sint_t err;
	mk_lang_types_sint_t sml_str_len;
	mk_sl_time_timestamp_t now;
	mk_sl_time_duration_t dur;
	mk_lang_types_sint_t big_str_len;

	mk_lang_assert(task);

	logger = &task->m_connection.m_settings.m_shared->m_logger;
	sml_str_ptr = &sml_str_buf[0];
	sml_str_cap = mk_lang_countof(sml_str_buf);
	big_str_ptr = &big_str_buf[0];
	big_str_cap = mk_lang_countof(big_str_buf);
	err = mk_lib_iip_logger_rw_begin_line(logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_append_current_time(logger); mk_lang_check_rereturn(err);

	err = mk_lib_net_socket_to_text(&task->m_connection.m_state.m_socket, sml_str_ptr, sml_str_cap, &sml_str_len); mk_lang_check_rereturn(err); mk_lang_assert(sml_str_len >= 1); mk_lang_assert(sml_str_len <= sml_str_cap);
	err = mk_lib_iip_logger_rw_begin_color(logger, mk_lib_iip_logger_color_text_e_dark_cyan); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(logger, sml_str_ptr, sml_str_len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_color(logger); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print_str_lit(logger, " "); mk_lang_check_rereturn(err);

	mk_sl_time_timestamp_get_now(&now);
	mk_sl_time_timestamp_get_duration(&task->m_connection.m_state.m_time_req_send, &now, &dur);
	sml_str_len = mk_sl_time_duration_to_text(&dur, sml_str_ptr, sml_str_cap); mk_lang_assert(sml_str_len >= 1); mk_lang_assert(sml_str_len <= sml_str_cap);
	big_str_len = mk_lib_fmt_n_snnprintf(big_str_buf, big_str_cap, &mk_lib_iip_cp_client_connection_debug_print_write_finished_k_fmt[0], mk_lang_countstr(mk_lib_iip_cp_client_connection_debug_print_write_finished_k_fmt), sml_str_ptr, sml_str_len); mk_lang_check_return(big_str_len >= 1); mk_lang_assert(big_str_len <= big_str_cap);
	err = mk_lib_iip_logger_rw_begin_color(logger, mk_lib_iip_logger_color_text_e_dark_yellow); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_print(logger, big_str_ptr, big_str_len); mk_lang_check_rereturn(err);
	err = mk_lib_iip_logger_rw_end_color(logger); mk_lang_check_rereturn(err);

	err = mk_lib_iip_logger_rw_end_line(logger); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(task);

	((mk_lang_types_void_t)(task));
	return 0;
#endif
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_issue_read(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt data;
	mk_lang_types_usize_t size;

	mk_lang_assert(task);
	mk_lang_assert(!task->m_connection.m_state.m_pending_recv);

	err = mk_lib_iip_cp_client_connection_debug_print_requesting_read(task); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_reserve_additional(&task->m_connection.m_state.m_buf_rcv, mk_lib_iip_cp_client_connection_k_buffer_size); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&task->m_connection.m_state.m_buf_rcv); mk_lang_check_rereturn(err);
	data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_free_data_a(&task->m_connection.m_state.m_buf_rcv);
	size = mk_lib_iip_cp_dynamic_ring_u8_rw_get_free_size_a(&task->m_connection.m_state.m_buf_rcv);
	mk_lang_assert(data && size >= mk_lib_iip_cp_client_connection_k_buffer_size);
	err = mk_lib_net_read_request_reconstruct(&task->m_connection.m_state.m_read_request, &task->m_connection.m_state.m_socket, data, ((mk_lang_types_sint_t)(size))); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_recv(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	mk_sl_time_timestamp_get_now(&task->m_connection.m_state.m_time_req_recv);
	task->m_connection.m_state.m_pending_recv = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_issue_write(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pct data;
	mk_lang_types_usize_t size;

	mk_lang_assert(task);
	mk_lang_assert(!task->m_connection.m_state.m_pending_send);

	err = mk_lib_iip_cp_client_connection_debug_print_requesting_write(task); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&task->m_connection.m_state.m_buf_snd); mk_lang_check_rereturn(err);
	data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&task->m_connection.m_state.m_buf_snd); mk_lang_assert(data);
	size = mk_lib_iip_cp_dynamic_ring_u8_rw_get_size_a(&task->m_connection.m_state.m_buf_snd); mk_lang_assert(size == mk_lib_iip_cp_dynamic_ring_u8_rw_get_size(&task->m_connection.m_state.m_buf_snd));
	err = mk_lib_net_write_request_reconstruct(&task->m_connection.m_state.m_write_request, &task->m_connection.m_state.m_socket, data, ((mk_lang_types_sint_t)(size))); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_send(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	mk_sl_time_timestamp_get_now(&task->m_connection.m_state.m_time_req_send);
	task->m_connection.m_state.m_pending_send = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_finish_read(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_sint_t const bytes_transferred) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(task->m_connection.m_state.m_pending_recv);

	err = mk_lib_net_read_request_wait_infinite(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_get_result(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	mk_lang_assert(task->m_connection.m_state.m_read_request.m_transferred == bytes_transferred);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_void(&task->m_connection.m_state.m_buf_rcv, ((mk_lang_types_usize_t)(bytes_transferred))); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_pending_recv = mk_lang_false;
	if(bytes_transferred == 0)
	{
		task->m_connection.m_state.m_disconnected = mk_lang_true;
	}
	err = mk_lib_iip_cp_client_connection_debug_print_read_finished(task); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_finish_write(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_sint_t const bytes_transferred) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(task->m_connection.m_state.m_pending_send);

	err = mk_lib_net_write_request_wait_infinite(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_get_result(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	mk_lang_assert(task->m_connection.m_state.m_write_request.m_transferred == bytes_transferred);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&task->m_connection.m_state.m_buf_snd, ((mk_lang_types_usize_t)(bytes_transferred))); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_pending_send = mk_lang_false;
	err = mk_lib_iip_cp_client_connection_debug_print_write_finished(task); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_parse_message(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lib_iip_cp_message_parse_error_code_t parse_error_code;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pct data;
	mk_lang_types_usize_t size;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(task);

	parse_error_code = mk_lib_iip_cp_message_parse_error_code_e_ok;
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&task->m_connection.m_state.m_buf_rcv); mk_lang_check_rereturn(err);
	data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_data_a(&task->m_connection.m_state.m_buf_rcv);
	size = mk_lib_iip_cp_dynamic_ring_u8_rw_get_size_a(&task->m_connection.m_state.m_buf_rcv);
	err = mk_lib_iip_cp_message_parse_message(data, ((mk_lang_types_sint_t)(size)), &parse_error_code, &consumed, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	switch(parse_error_code)
	{
		case mk_lib_iip_cp_message_parse_error_code_e_ok                            : break;
		case mk_lib_iip_cp_message_parse_error_code_e_not_enough_data               : break;
		case mk_lib_iip_cp_message_parse_error_code_e_too_much_data                 : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_parse_error_code_e_unknown_message_type          : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_parse_error_code_e_unknown_session_status_status : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_parse_error_code_e_unknown_message_status_status : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_parse_error_code_e_unknown_host_reply_result_code: mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_parse_error_code_e_too_many_tunnels              : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_parse_error_code_e_too_many_leases               : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_parse_error_code_e_too_big_mapping               : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_parse_error_code_e_unexpected_char               : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_parse_error_code_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	if(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_ok)
	{
		mk_lang_assert(consumed >= 0);
		mk_lang_assert(consumed <= ((mk_lang_types_sint_t)(size)));
		err = mk_lib_iip_cp_dynamic_ring_u8_rw_pop_front_many(&task->m_connection.m_state.m_buf_rcv, ((mk_lang_types_usize_t)(consumed))); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_connection_debug_print_msg(task, &task->m_connection.m_state.m_msg, mk_lib_iip_cp_client_connection_debug_print_direction_e_incomming); mk_lang_check_rereturn(err);
	}
	else if(parse_error_code == mk_lib_iip_cp_message_parse_error_code_e_not_enough_data)
	{
		err = mk_lib_iip_cp_message_reconstruct(&task->m_connection.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_dummy_end); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_serialize_introducer(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_uchar_t tuc;
	mk_sl_cui_uint8_t u8;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	tuc = 0x2a; mk_sl_cui_uint8_from_bi_uchar(&u8, &tuc);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_move_single(&task->m_connection.m_state.m_buf_snd, &u8); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_serialize_message_explicit(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_message_pt const msg) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt data;
	mk_lang_types_usize_t size;
	mk_lib_iip_cp_message_serialize_error_code_t serialize_error_code;
	mk_lang_types_sint_t consumed;

	mk_lang_assert(task);
	mk_lang_assert(msg);

	err = mk_lib_iip_cp_dynamic_ring_u8_rw_reserve_additional(&task->m_connection.m_state.m_buf_snd, mk_lib_iip_cp_client_connection_k_buffer_size - 1); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_consolidate(&task->m_connection.m_state.m_buf_snd); mk_lang_check_rereturn(err);
	data = mk_lib_iip_cp_dynamic_ring_u8_rw_get_free_data_a(&task->m_connection.m_state.m_buf_snd); mk_lang_assert(data);
	size = mk_lib_iip_cp_dynamic_ring_u8_rw_get_free_size_a(&task->m_connection.m_state.m_buf_snd); mk_lang_assert(size >= mk_lib_iip_cp_client_connection_k_buffer_size - 1);
	serialize_error_code = mk_lib_iip_cp_message_serialize_error_code_e_ok;
	err = mk_lib_iip_cp_message_serialize_message(data, ((mk_lang_types_sint_t)(size)), &serialize_error_code, &consumed, msg); mk_lang_check_rereturn(err); mk_lang_check_return(serialize_error_code == mk_lib_iip_cp_message_serialize_error_code_e_ok); mk_lang_check_return(consumed >= 1); mk_lang_assert(consumed <= ((mk_lang_types_sint_t)(size)));
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_push_back_void(&task->m_connection.m_state.m_buf_snd, ((mk_lang_types_usize_t)(consumed))); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_debug_print_msg(task, msg, mk_lib_iip_cp_client_connection_debug_print_direction_e_outgoing); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_serialize_message_implicit(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_iip_cp_client_connection_task_prrw_serialize_message_explicit(task, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_prrw_session_id_to_session_obj(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_types_sessionid_pct const session_id, mk_lib_iip_cp_client_session_task_ppt const session_obj) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_task_pt res;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_session_task_ppt ses_ptr;
	mk_lib_iip_cp_client_session_task_pt ses_obj;

	mk_lang_assert(task);
	mk_lang_assert(session_id);
	mk_lang_assert(session_obj);

	/* todo something better than o(n) */
	res = mk_lang_null;
	n = mk_lib_iip_cp_client_session_tasks_rw_size(&task->m_connection.m_state.m_sessions);
	for(i = 0; i != n; ++i)
	{
		ses_ptr = mk_lib_iip_cp_client_session_tasks_rw_at(&task->m_connection.m_state.m_sessions, i); mk_lang_assert(ses_ptr); ses_obj = *ses_ptr; mk_lang_assert(ses_obj);
		if(ses_obj->m_session.m_state.m_has_id && mk_lib_iip_cp_types_sessionid_eq(&ses_obj->m_session.m_state.m_id, session_id))
		{
			res = ses_obj;
			break;
		}
	}
	*session_obj = res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_construct(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_client_connection_task_settings_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(settings->m_shared);
	mk_lang_assert(!mk_lib_net_ipv4_address_is_any(&settings->m_destination.m_ipv4_address));
	mk_lang_assert(!mk_lib_net_ipv4_address_is_none(&settings->m_destination.m_ipv4_address));
	mk_lang_assert(!mk_lib_net_tcp_port_is_zero(&settings->m_destination.m_tcp_port));
	mk_lang_assert(!mk_lib_net_tcp_port_is_max(&settings->m_destination.m_tcp_port));

	task->m_connection.m_settings.m_shared = settings->m_shared;
	task->m_connection.m_settings.m_destination.m_ipv4_address = settings->m_destination.m_ipv4_address;
	task->m_connection.m_settings.m_destination.m_tcp_port = settings->m_destination.m_tcp_port;
	task->m_connection.m_settings.m_authentication.m_username = settings->m_authentication.m_username;
	task->m_connection.m_settings.m_authentication.m_password = settings->m_authentication.m_password;

	task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(0));
	err = mk_lib_net_socket_construct_void(&task->m_connection.m_state.m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_connect_construct_void(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_construct_void(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_construct_void(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_tasks_rw_construct(&task->m_connection.m_state.m_sessions); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_session_idx = 0;
	task->m_connection.m_state.m_session_want_die = mk_lang_null;
	task->m_connection.m_state.m_session_want_snd = mk_lang_null;
	task->m_connection.m_state.m_session_want_rcv = mk_lang_null;
	task->m_connection.m_state.m_pending_session_to_create = mk_lang_null;
	task->m_connection.m_state.m_stop_requested = mk_lang_false;
	task->m_connection.m_state.m_stop_acknowledged = mk_lang_false;
	task->m_connection.m_state.m_disconnected = mk_lang_false;
	task->m_connection.m_state.m_has_msg = mk_lang_false;
	task->m_connection.m_state.m_pending_send = mk_lang_false;
	task->m_connection.m_state.m_pending_recv = mk_lang_false;
	task->m_connection.m_state.m_want_die = mk_lang_false;
	mk_sl_time_timestamp_set_zero(&task->m_connection.m_state.m_time_req_send);
	mk_sl_time_timestamp_set_zero(&task->m_connection.m_state.m_time_req_recv);
	err = mk_lib_iip_cp_message_construct(&task->m_connection.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_construct(&task->m_connection.m_state.m_buf_rcv); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_construct(&task->m_connection.m_state.m_buf_snd); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_destroy(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);

	err = mk_lib_net_socket_destroy(&task->m_connection.m_state.m_socket); mk_lang_check_rereturn(err);
	err = mk_lib_net_async_connect_destroy(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_write_request_destroy(&task->m_connection.m_state.m_write_request); mk_lang_check_rereturn(err);
	err = mk_lib_net_read_request_destroy(&task->m_connection.m_state.m_read_request); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_lib_iip_cp_client_session_tasks_rw_is_empty(&task->m_connection.m_state.m_sessions));
	err = mk_lib_iip_cp_client_session_tasks_rw_destroy(&task->m_connection.m_state.m_sessions); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_destroy(&task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_destroy(&task->m_connection.m_state.m_buf_rcv); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_dynamic_ring_u8_rw_destroy(&task->m_connection.m_state.m_buf_snd); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_request_close(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	mk_lang_assert(task);

	task->m_connection.m_state.m_stop_requested = mk_lang_true;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_want_associate_socket(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lang_types_bool_t wand;

	mk_lang_assert(task);
	mk_lang_assert(want);

	wand = task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_want_associate_socket;
	*want = wand;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_gimme_socket(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_net_socket_ppt const socket, mk_lib_iip_any_data_connection_ppt const associatee) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(socket);
	mk_lang_assert(associatee);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_want_associate_socket);

	*socket = &task->m_connection.m_state.m_socket;
	*associatee = &task->m_connection.m_settings.m_type;
	task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_on_iorp_done(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(successful_io_operation == mk_lang_false || successful_io_operation == mk_lang_true);
	mk_lang_assert(bytes_transferred >= 0);
	mk_lang_assert(overlapped);
	mk_lang_assert
	(
		(overlapped == &task->m_connection.m_state.m_read_request.m_overlapped && task->m_connection.m_state.m_pending_recv) ||
		(overlapped == &task->m_connection.m_state.m_write_request.m_overlapped && task->m_connection.m_state.m_pending_send)
	);

	if(overlapped == &task->m_connection.m_state.m_read_request.m_overlapped && task->m_connection.m_state.m_pending_recv)
	{
		err = mk_lib_iip_cp_client_connection_task_prrw_finish_read(task, bytes_transferred); mk_lang_check_rereturn(err);
		#include "mk_lang_warning_msvc_push_c4127.h"
		if(mk_lang_false){}
		#include "mk_lang_warning_msvc_pop.h"
		else if(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_recv_set_date_finish)
		{
			err = mk_lib_iip_cp_client_connection_task_prrw_parse_message(task); mk_lang_check_rereturn(err);
			mk_lang_check_return(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_set_date);
			err = mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset(task, &task->m_connection.m_state.m_msg.m_mix.m_data.m_set_date.m_server_date); mk_lang_check_rereturn(err);
			task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1));
		}
		else if(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_recv_bandwidth_finish)
		{
			err = mk_lib_iip_cp_client_connection_task_prrw_parse_message(task); mk_lang_check_rereturn(err);
			mk_lang_check_return(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits);
			task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1));
		}
		else if(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_ready)
		{
			/* blank */
		}
		else
		{
			mk_lang_assert_false();
		}
	}
	else if(overlapped == &task->m_connection.m_state.m_write_request.m_overlapped && task->m_connection.m_state.m_pending_send)
	{
		err = mk_lib_iip_cp_client_connection_task_prrw_finish_write(task, bytes_transferred); mk_lang_check_rereturn(err);
		#include "mk_lang_warning_msvc_push_c4127.h"
		if(mk_lang_false){}
		#include "mk_lang_warning_msvc_pop.h"
		else if(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_send_get_date_finish ){ task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1)); }
		else if(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_send_bandwidth_finish){ task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1)); }
		else if(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_ready                ){ /* this is intentionally left blank */ }
		else{ mk_lang_assert_false(); }
	}
	else
	{
		mk_lang_assert_false();
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_ready(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
#include "mk_lang_warning_clang_push_conditional_uninitialized.h"
	mk_lang_types_usize_t count;
	mk_lib_iip_cp_client_session_task_pt session_want_send;
	mk_lib_iip_cp_client_session_task_pt session_want_recv;
	mk_lang_types_bool_t want;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lib_iip_cp_client_session_task_ppt session_ptr;
	mk_lib_iip_cp_client_session_task_pt session_obj;
	mk_lib_iip_cp_client_session_task_pt want_die;
	mk_lib_iip_cp_client_session_task_result_t stp_res;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_pt msg;
	mk_lang_types_bool_t break2;
	mk_lang_types_bool_t did_something;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	++task->m_connection.m_state.m_session_idx;
	want_die = mk_lang_null;
	if(task->m_connection.m_state.m_stop_requested && !task->m_connection.m_state.m_stop_acknowledged)
	{
		task->m_connection.m_state.m_stop_acknowledged = mk_lang_true;
		n = mk_lib_iip_cp_client_session_tasks_rw_size(&task->m_connection.m_state.m_sessions);
		for(i = 0; i != n; ++i)
		{
			session_ptr = mk_lib_iip_cp_client_session_tasks_rw_at(&task->m_connection.m_state.m_sessions, i); mk_lang_assert(session_ptr); session_obj = *session_ptr; mk_lang_assert(session_obj);
			err = mk_lib_iip_cp_client_session_task_rw_request_close(session_obj); mk_lang_check_rereturn(err);
		}
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	else
	{
		count = mk_lib_iip_cp_client_session_tasks_rw_size(&task->m_connection.m_state.m_sessions);
		if(count != 0)
		{
			session_want_send = mk_lang_null;
			session_want_recv = mk_lang_null;
			n = count;
			for(i = 0; i != n; ++i)
			{
				break2 = mk_lang_false;
				idx = (i + task->m_connection.m_state.m_session_idx) % count;
				session_ptr = mk_lib_iip_cp_client_session_tasks_rw_at(&task->m_connection.m_state.m_sessions, idx); mk_lang_assert(session_ptr); session_obj = *session_ptr; mk_lang_assert(session_obj);
				stp_res = mk_lib_iip_cp_client_session_task_result_e_dummy_end;
				err = mk_lib_iip_cp_client_session_task_rw_step(session_obj, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_session_task_result_e_dummy_end);
				switch(stp_res)
				{
					case mk_lib_iip_cp_client_session_task_result_e_did_something:
					{
						*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
						break2 = mk_lang_true;
					}
					break;
					case mk_lib_iip_cp_client_session_task_result_e_idling:
					{
						err = mk_lib_iip_cp_client_session_task_rw_want_die(session_obj, &want); mk_lang_check_rereturn(err);
						if(want)
						{
							want_die = session_obj;
						}
					}
					break;
					case mk_lib_iip_cp_client_session_task_result_e_want_send:
					{
						if(!session_want_send)
						{
							session_want_send = session_obj;
						}
					}
					break;
					case mk_lib_iip_cp_client_session_task_result_e_want_recv:
					{
						if(!session_want_recv)
						{
							session_want_recv = session_obj;
						}
					}
					break;
					case mk_lib_iip_cp_client_session_task_result_e_dummy_end:
					{
						mk_lang_assert_false();
					}
					break;
					default:
					{
						mk_lang_assert_false();
					}
					break;
				}
				if(break2)
				{
					break;
				}
			}
			if(i == n)
			{
				mk_lang_clobber(&stp_res);
				if(!task->m_connection.m_state.m_disconnected)
				{
					did_something = mk_lang_false;
					if(!mk_lib_iip_cp_dynamic_ring_u8_rw_is_empty(&task->m_connection.m_state.m_buf_rcv))
					{
						err = mk_lib_iip_cp_client_connection_task_prrw_parse_message(task); mk_lang_check_rereturn(err);
						if(task->m_connection.m_state.m_msg.m_header.m_type != mk_lib_iip_cp_message_message_type_id_e_dummy_end)
						{
							//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg;
							*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
							did_something = mk_lang_true;
						}
					}
					if(!did_something)
					{
						if(session_want_send)
						{
							if(task->m_connection.m_state.m_pending_send)
							{
								*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
							}
							else
							{
								err = mk_lib_iip_cp_client_session_task_rw_gimme_msg(session_want_send, &msg); mk_lang_check_rereturn(err);
								if(msg->m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_create_session)
								{
									mk_lang_assert(!task->m_connection.m_state.m_pending_session_to_create);
									task->m_connection.m_state.m_pending_session_to_create = session_want_send;
								}
								err = mk_lib_iip_cp_client_connection_task_prrw_serialize_message_explicit(task, msg); mk_lang_check_rereturn(err);
								err = mk_lib_iip_cp_client_connection_task_prrw_issue_write(task); mk_lang_check_rereturn(err);
								*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
							}
						}
						else if(session_want_recv)
						{
							if(task->m_connection.m_state.m_pending_recv)
							{
								*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
							}
							else
							{
								err = mk_lib_iip_cp_client_connection_task_prrw_issue_read(task); mk_lang_check_rereturn(err);
								*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
							}
						}
						else if(stp_res == mk_lib_iip_cp_client_session_task_result_e_idling)
						{
							if(task->m_connection.m_state.m_pending_recv)
							{
								*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
							}
							else
							{
								err = mk_lib_iip_cp_client_connection_task_prrw_issue_read(task); mk_lang_check_rereturn(err);
								*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
							}
						}
						else
						{
							mk_lang_assert_false();
						}
					}
				}
				else
				{
					*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
				}
			}
			else
			{
				mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
			}
		}
		else
		{
			*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
		}
	}
	if(*step_result == mk_lib_iip_cp_client_connection_task_result_e_did_nothing && want_die)
	{
		err = mk_lib_iip_cp_client_session_tasks_rw_erase_value(&task->m_connection.m_state.m_sessions, &want_die); mk_lang_check_rereturn(err);
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	if(task->m_connection.m_state.m_stop_requested && task->m_connection.m_state.m_stop_acknowledged && *step_result == mk_lib_iip_cp_client_connection_task_result_e_did_nothing)
	{
		if((mk_lib_iip_cp_client_session_tasks_rw_is_empty(&task->m_connection.m_state.m_sessions)))
		{
			//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_want_die;
			*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
		}
	}
	return 0;
#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_parse_incoming_msg(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_parse_incoming_msg);

	if(!mk_lib_iip_cp_dynamic_ring_u8_ro_is_empty(&task->m_connection.m_state.m_buf_rcv))
	{
		err = mk_lib_iip_cp_client_connection_task_prrw_parse_message(task); mk_lang_check_rereturn(err);
		//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg;
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	else
	{
		task->m_connection.m_state.m_disconnected = mk_lang_true;
		//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_session_status_destroyed(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_session_status_pt msg_session_status;
	mk_lib_iip_cp_client_session_task_pt session;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_session_status);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_mix.m_data.m_session_status.m_status == mk_lib_iip_cp_message_session_status_status_id_e_destroyed);

	msg_session_status = &task->m_connection.m_state.m_msg.m_mix.m_data.m_session_status;
	err = mk_lib_iip_cp_client_connection_prrw_session_id_to_session_obj(task, &msg_session_status->m_session_id, &session); mk_lang_check_rereturn(err); mk_lang_check_return(session);
	err = mk_lib_iip_cp_client_session_task_rw_on_msg(session, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_session_status_created(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_pt msg;
	mk_lib_iip_cp_client_session_task_pt session;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_session_status);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_mix.m_data.m_session_status.m_status == mk_lib_iip_cp_message_session_status_status_id_e_created);

	msg = &task->m_connection.m_state.m_msg;
	mk_lang_check_return(task->m_connection.m_state.m_pending_session_to_create);
	session = task->m_connection.m_state.m_pending_session_to_create;
	task->m_connection.m_state.m_pending_session_to_create = mk_lang_null;
	err = mk_lib_iip_cp_client_session_task_rw_on_msg(session, msg); mk_lang_check_rereturn(err);
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_create_session(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_create_session_pt msg_create_session;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_create_session);

	/*msg_create_session = &task->m_connection.m_state.m_msg.m_mix.m_data.m_create_session;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_reconfigure_session(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_reconfigure_session_pt msg_reconfigure_session;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_reconfigure_session);

	/*msg_reconfigure_session = &task->m_connection.m_state.m_msg.m_mix.m_data.m_reconfigure_session;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_destroy_session(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_destroy_session_pt msg_destroy_session;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_destroy_session);

	/*msg_destroy_session = &task->m_connection.m_state.m_msg.m_mix.m_data.m_destroy_session;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_create_lease_set(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_create_lease_set_pt msg_create_lease_set;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_create_lease_set);

	/*msg_create_lease_set = &task->m_connection.m_state.m_msg.m_mix.m_data.m_create_lease_set;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_send_message(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_send_message_pt msg_send_message;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_send_message);

	/*msg_send_message = &task->m_connection.m_state.m_msg.m_mix.m_data.m_send_message;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_receive_message_begin(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_receive_message_begin_pt msg_receive_message_begin;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_receive_message_begin);

	/*msg_receive_message_begin = &task->m_connection.m_state.m_msg.m_mix.m_data.m_receive_message_begin;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_receive_message_end(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_receive_message_end_pt msg_receive_message_end;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_receive_message_end);

	/*msg_receive_message_end = &task->m_connection.m_state.m_msg.m_mix.m_data.m_receive_message_end;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_get_bandwidth_limits(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_get_bandwidth_limits_pt msg_get_bandwidth_limits;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits);

	/*msg_get_bandwidth_limits = &task->m_connection.m_state.m_msg.m_mix.m_data.m_get_bandwidth_limits;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_session_status(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_session_status_pt msg_session_status;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_session_status);

	msg_session_status = &task->m_connection.m_state.m_msg.m_mix.m_data.m_session_status;
	switch(msg_session_status->m_status)
	{
		case mk_lib_iip_cp_message_session_status_status_id_e_destroyed: err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_session_status_destroyed(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_session_status_status_id_e_created  : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_session_status_created  (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_session_status_status_id_e_updated  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_invalid  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_refused  : mk_lang_check_todo(); break;
		case mk_lib_iip_cp_message_session_status_status_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_request_lease_set(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_request_lease_set_pt msg_request_lease_set;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt session;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_request_lease_set);

	msg_request_lease_set = &task->m_connection.m_state.m_msg.m_mix.m_data.m_request_lease_set;
	err = mk_lib_iip_cp_client_connection_prrw_session_id_to_session_obj(task, &msg_request_lease_set->m_session_id, &session); mk_lang_check_rereturn(err); mk_lang_check_return(session);
	err = mk_lib_iip_cp_client_session_task_rw_on_msg(session, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_message_status(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_message_status_pt msg_message_status;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt session;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_message_status);

	msg_message_status = &task->m_connection.m_state.m_msg.m_mix.m_data.m_message_status;
	err = mk_lib_iip_cp_client_connection_prrw_session_id_to_session_obj(task, &msg_message_status->m_session_id, &session); mk_lang_check_rereturn(err); mk_lang_check_return(session);
	err = mk_lib_iip_cp_client_session_task_rw_on_msg(session, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_bandwidth_limits(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_bandwidth_limits_pt msg_bandwidth_limits;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits);

	/*msg_bandwidth_limits = &task->m_connection.m_state.m_msg.m_mix.m_data.m_bandwidth_limits;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_report_abuse(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_report_abuse_pt msg_report_abuse;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_report_abuse);

	/*msg_report_abuse = &task->m_connection.m_state.m_msg.m_mix.m_data.m_report_abuse;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_disconnect(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_disconnect_pt msg_disconnect;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_disconnect);

	/*msg_disconnect = &task->m_connection.m_state.m_msg.m_mix.m_data.m_disconnect;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_message_payload(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_message_payload_pt msg_message_payload;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt session;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_message_payload);

	msg_message_payload = &task->m_connection.m_state.m_msg.m_mix.m_data.m_message_payload;
	err = mk_lib_iip_cp_client_connection_prrw_session_id_to_session_obj(task, &msg_message_payload->m_session_id, &session); mk_lang_check_rereturn(err); mk_lang_check_return(session);
	err = mk_lib_iip_cp_client_session_task_rw_on_msg(session, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_get_date(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_get_date_pt msg_get_date;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_get_date);

	/*msg_get_date = &task->m_connection.m_state.m_msg.m_mix.m_data.m_get_date;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_set_date(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_set_date_pt msg_set_date;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_set_date);

	msg_set_date = &task->m_connection.m_state.m_msg.m_mix.m_data.m_set_date;
	err = mk_lib_iip_cp_client_connection_debug_print_compute_and_print_time_offset(task, &msg_set_date->m_server_date); mk_lang_check_rereturn(err);
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_dest_lookup(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_dest_lookup_pt msg_dest_lookup;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_dest_lookup);

	/*msg_dest_lookup = &task->m_connection.m_state.m_msg.m_mix.m_data.m_dest_lookup;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_dest_reply(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_dest_reply_pt msg_dest_reply;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_dest_reply);

	/*msg_dest_reply = &task->m_connection.m_state.m_msg.m_mix.m_data.m_dest_reply;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_send_message_expires(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_send_message_expires_pt msg_send_message_expires;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_send_message_expires);

	/*msg_send_message_expires = &task->m_connection.m_state.m_msg.m_mix.m_data.m_send_message_expires;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_request_variable_lease_set(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_request_variable_lease_set_pt msg_request_variable_lease_set;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt session;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set);

	msg_request_variable_lease_set = &task->m_connection.m_state.m_msg.m_mix.m_data.m_request_variable_lease_set;
	err = mk_lib_iip_cp_client_connection_prrw_session_id_to_session_obj(task, &msg_request_variable_lease_set->m_session_id, &session); mk_lang_check_rereturn(err); mk_lang_check_return(session);
	err = mk_lib_iip_cp_client_session_task_rw_on_msg(session, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_host_lookup(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_host_lookup_pt msg_host_lookup;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_host_lookup);

	/*msg_host_lookup = &task->m_connection.m_state.m_msg.m_mix.m_data.m_host_lookup;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_host_reply(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_message_host_reply_pt msg_host_reply;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt session;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_host_reply);

	msg_host_reply = &task->m_connection.m_state.m_msg.m_mix.m_data.m_host_reply;
	err = mk_lib_iip_cp_client_connection_prrw_session_id_to_session_obj(task, &msg_host_reply->m_session_id, &session); mk_lang_check_rereturn(err); mk_lang_check_return(session);
	err = mk_lib_iip_cp_client_session_task_rw_on_msg(session, &task->m_connection.m_state.m_msg); mk_lang_check_rereturn(err);
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_create_lease_set2(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_create_lease_set2_pt msg_create_lease_set2;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_create_lease_set2);

	/*msg_create_lease_set2 = &task->m_connection.m_state.m_msg.m_mix.m_data.m_create_lease_set2;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_blinding_info(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	/*mk_lib_iip_cp_message_blinding_info_pt msg_blinding_info;*/

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);
	mk_lang_assert(task->m_connection.m_state.m_msg.m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_blinding_info);

	/*msg_blinding_info = &task->m_connection.m_state.m_msg.m_mix.m_data.m_blinding_info;*/
	mk_lang_check_todo();
	//task->m_step = mk_lib_iip_cp_client_connection_task_step_e_ready;
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	switch(task->m_connection.m_state.m_msg.m_header.m_type)
	{
		case mk_lib_iip_cp_message_message_type_id_e_create_session            : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_create_session            (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_reconfigure_session       : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_reconfigure_session       (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_destroy_session           : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_destroy_session           (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set          : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_create_lease_set          (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message              : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_send_message              (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_begin     : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_receive_message_begin     (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_receive_message_end       : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_receive_message_end       (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits      : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_get_bandwidth_limits      (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_session_status            : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_session_status            (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_request_lease_set         : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_request_lease_set         (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_message_status            : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_message_status            (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_bandwidth_limits          : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_bandwidth_limits          (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_report_abuse              : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_report_abuse              (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_disconnect                : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_disconnect                (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_message_payload           : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_message_payload           (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_get_date                  : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_get_date                  (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_set_date                  : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_set_date                  (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_lookup               : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_dest_lookup               (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_dest_reply                : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_dest_reply                (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_send_message_expires      : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_send_message_expires      (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_request_variable_lease_set: err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_request_variable_lease_set(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_host_lookup               : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_host_lookup               (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_host_reply                : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_host_reply                (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_create_lease_set2         : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_create_lease_set2         (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_blinding_info             : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg_blinding_info             (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); /*mk_lang_assert(task->m_step != mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg);*/ break;
		case mk_lib_iip_cp_message_message_type_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_want_die(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	//mk_lang_assert(task->m_step == mk_lib_iip_cp_client_connection_task_step_e_want_die);

	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step2(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	//mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
#if 0
	switch(task->m_step)
	{
		case mk_lib_iip_cp_client_connection_task_step_e_create_socket         : mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_create_socket         (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_want_associate_socket : mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_want_associate_socket (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_connect_begin         : mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_connect_begin         (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_connect_finish        : mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_connect_finish        (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_send_get_date_request : mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_send_get_date_request (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_send_get_date_finish  : mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_send_get_date_finish  (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_recv_set_date_request : mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_set_date_request (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_recv_set_date_finish  : mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_set_date_finish  (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_send_bandwidth_request: mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_send_bandwidth_request(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_send_bandwidth_finish : mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_send_bandwidth_finish (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_recv_bandwidth_request: mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_bandwidth_request(task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_recv_bandwidth_finish : mk_lang_assert_false(); /* err = mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_bandwidth_finish (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); */ break;
		case mk_lib_iip_cp_client_connection_task_step_e_ready                 : err = mk_lib_iip_cp_client_connection_task_prrw_step_ready                 (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_parse_incoming_msg    : err = mk_lib_iip_cp_client_connection_task_prrw_step_parse_incoming_msg    (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_dispatch_msg          : err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg          (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_want_die              : err = mk_lib_iip_cp_client_connection_task_prrw_step_want_die              (task, allow_to_block, tm, step_result); mk_lang_check_rereturn(err); mk_lang_assert(*step_result != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
		case mk_lib_iip_cp_client_connection_task_step_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
#endif
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_is_inited(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_pt const is) mk_lang_noexcept
{
	mk_lang_types_bool_t iz;

	mk_lang_assert(task);
	mk_lang_assert(is);
	mk_lang_assert(task->m_connection.m_state.m_init_state >= 0);
	mk_lang_assert(task->m_connection.m_state.m_init_state < mk_lib_iip_cp_client_connection_task_init_e_dummy_end);

	iz = task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_ready;
	*is = iz;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_create_socket(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_create_socket);

	err = mk_lib_net_socket_reconstruct(&task->m_connection.m_state.m_socket, mk_lib_net_address_family_e_ipv4, mk_lib_net_address_type_e_stream, mk_lib_net_address_protocol_e_tcp); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_set_option_nodelay_true(&task->m_connection.m_state.m_socket); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1));
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_want_associate_socket(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_want_associate_socket);

	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_connect_begin(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_connect_begin);

	err = mk_lib_net_async_connect_reconstruct(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_associate_async_connect(&task->m_connection.m_state.m_socket, &task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
	err = mk_lib_net_socket_connect(&task->m_connection.m_state.m_socket, &task->m_connection.m_settings.m_destination); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1));
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_connect_finish(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_ready;
	mk_lang_types_sint_t st;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_connect_finish);

	err = mk_lib_net_async_connect_is_ready(&task->m_connection.m_state.m_async_connect, &is_ready); mk_lang_check_rereturn(err);
	if(is_ready || allow_to_block)
	{
		if(tm == -1)
		{
			err = mk_lib_net_async_connect_wait_infinite(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
			is_ready = mk_lang_true;
		}
		else
		{
			err = mk_lib_net_async_connect_wait_timeout(&task->m_connection.m_state.m_async_connect, tm, &is_ready); mk_lang_check_rereturn(err);
		}
		if(is_ready)
		{
			err = mk_lib_net_async_connect_get_result(&task->m_connection.m_state.m_async_connect, &st); mk_lang_check_rereturn(err); mk_lang_check_return(st == 0);
			err = mk_lib_net_async_connect_reset(&task->m_connection.m_state.m_async_connect); mk_lang_check_rereturn(err);
			task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1));
			*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
		}
		else
		{
			*step_result = mk_lib_iip_cp_client_connection_task_result_e_timed_out;
		}
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_send_get_date_request(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_message_pt msg;
	mk_lib_iip_cp_message_get_date_pt msg_get_date;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_send_get_date_request);

	err = mk_lib_iip_cp_dynamic_ring_u8_rw_reserve_at_least(&task->m_connection.m_state.m_buf_snd, mk_lib_iip_cp_client_connection_k_buffer_size); mk_lang_check_rereturn(err);
	msg = &task->m_connection.m_state.m_msg;
	msg_get_date = &msg->m_mix.m_data.m_get_date;
	err = mk_lib_iip_cp_client_connection_task_prrw_serialize_introducer(task); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_message_reconstruct(msg, mk_lib_iip_cp_message_message_type_id_e_get_date); mk_lang_check_rereturn(err);
	mk_lang_string_memcpy_pc_fn(&msg_get_date->m_api_version.m_buf[0], &mk_lib_iip_cp_client_connection_k_api_ver[0], mk_lang_countstr(mk_lib_iip_cp_client_connection_k_api_ver)); msg_get_date->m_api_version.m_len = mk_lang_countstr(mk_lib_iip_cp_client_connection_k_api_ver);
	if
	(
		(task->m_connection.m_settings.m_authentication.m_username.m_len != 0) &&
		(task->m_connection.m_settings.m_authentication.m_password.m_len != 0) &&
		(mk_lang_true)
	)
	{
		err = mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_username(&msg_get_date->m_authentication.m_strpairs, &task->m_connection.m_settings.m_authentication.m_username.m_buf[0], task->m_connection.m_settings.m_authentication.m_username.m_len); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_client_types_session_settings_options_rw_set_i2cp_password(&msg_get_date->m_authentication.m_strpairs, &task->m_connection.m_settings.m_authentication.m_password.m_buf[0], task->m_connection.m_settings.m_authentication.m_password.m_len); mk_lang_check_rereturn(err);
	}
	err = mk_lib_iip_cp_client_connection_task_prrw_serialize_message_implicit(task); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_task_prrw_issue_write(task); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1));
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_send_get_date_finish(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_send_get_date_finish);
	mk_lang_assert(task->m_connection.m_state.m_pending_send);

	*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_set_date_request(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_recv_set_date_request);

	err = mk_lib_iip_cp_client_connection_task_prrw_issue_read(task); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1));
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_set_date_finish(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_recv_set_date_finish);
	mk_lang_assert(task->m_connection.m_state.m_pending_recv);

	*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_send_bandwidth_request(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_send_bandwidth_request);

	err = mk_lib_iip_cp_message_reconstruct(&task->m_connection.m_state.m_msg, mk_lib_iip_cp_message_message_type_id_e_get_bandwidth_limits); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_task_prrw_serialize_message_implicit(task); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_connection_task_prrw_issue_write(task); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1));
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_send_bandwidth_finish(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_send_bandwidth_finish);
	mk_lang_assert(task->m_connection.m_state.m_pending_send);

	*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_bandwidth_request(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_recv_bandwidth_request);

	err = mk_lib_iip_cp_client_connection_task_prrw_issue_read(task); mk_lang_check_rereturn(err);
	task->m_connection.m_state.m_init_state = ((mk_lib_iip_cp_client_connection_task_init_t)(task->m_connection.m_state.m_init_state + 1));
	*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_bandwidth_finish(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(task->m_connection.m_state.m_init_state == mk_lib_iip_cp_client_connection_task_init_e_recv_bandwidth_finish);
	mk_lang_assert(task->m_connection.m_state.m_pending_recv);

	*step_result = mk_lib_iip_cp_client_connection_task_result_e_would_block;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_init(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_inited;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	err = mk_lib_iip_cp_client_connection_task_prrw_is_inited(task, &is_inited); mk_lang_check_rereturn(err);
	if(!is_inited)
	{
		stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end;
		switch(task->m_connection.m_state.m_init_state)
		{
			case mk_lib_iip_cp_client_connection_task_init_e_create_socket         : err = mk_lib_iip_cp_client_connection_task_prrw_step_init_create_socket         (task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_want_associate_socket : err = mk_lib_iip_cp_client_connection_task_prrw_step_init_want_associate_socket (task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_connect_begin         : err = mk_lib_iip_cp_client_connection_task_prrw_step_init_connect_begin         (task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_connect_finish        : err = mk_lib_iip_cp_client_connection_task_prrw_step_init_connect_finish        (task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_send_get_date_request : err = mk_lib_iip_cp_client_connection_task_prrw_step_init_send_get_date_request (task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_send_get_date_finish  : err = mk_lib_iip_cp_client_connection_task_prrw_step_init_send_get_date_finish  (task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_recv_set_date_request : err = mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_set_date_request (task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_recv_set_date_finish  : err = mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_set_date_finish  (task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_send_bandwidth_request: err = mk_lib_iip_cp_client_connection_task_prrw_step_init_send_bandwidth_request(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_send_bandwidth_finish : err = mk_lib_iip_cp_client_connection_task_prrw_step_init_send_bandwidth_finish (task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_recv_bandwidth_request: err = mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_bandwidth_request(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_recv_bandwidth_finish : err = mk_lib_iip_cp_client_connection_task_prrw_step_init_recv_bandwidth_finish (task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); break;
			case mk_lib_iip_cp_client_connection_task_init_e_ready: mk_lang_assert_false(); break;
			case mk_lib_iip_cp_client_connection_task_init_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}
		*step_result = stp_res;
	}
	else
	{
		*step_result = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	}
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_acknowledge_stop(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_result_t stp_res;
	mk_lang_types_bool_t is_inited;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lib_iip_cp_client_session_task_ppt session_ptr;
	mk_lib_iip_cp_client_session_task_pt session_obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	err = mk_lib_iip_cp_client_connection_task_prrw_is_inited(task, &is_inited); mk_lang_check_rereturn(err);
	if(is_inited && task->m_connection.m_state.m_stop_requested && !task->m_connection.m_state.m_stop_acknowledged)
	{
		task->m_connection.m_state.m_stop_acknowledged = mk_lang_true;
		n = mk_lib_iip_cp_client_session_tasks_rw_size(&task->m_connection.m_state.m_sessions);
		for(i = 0; i != n; ++i)
		{
			session_ptr = mk_lib_iip_cp_client_session_tasks_rw_at(&task->m_connection.m_state.m_sessions, i); mk_lang_assert(session_ptr); session_obj = *session_ptr; mk_lang_assert(session_obj);
			err = mk_lib_iip_cp_client_session_task_rw_request_close(session_obj); mk_lang_check_rereturn(err);
		}
		stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_sub_sessions_do(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_result_t stp_res_a;
	mk_lang_types_usize_t count;
	mk_lib_iip_cp_client_session_task_pt session_want_snd;
	mk_lib_iip_cp_client_session_task_pt session_want_rcv;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lang_types_bool_t break2;
	mk_lib_iip_cp_client_session_task_ppt session_ptr;
	mk_lib_iip_cp_client_session_task_pt session_obj;
	mk_lib_iip_cp_client_session_task_result_t stp_res;
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t want;
	mk_lib_iip_cp_client_session_task_ppt session_want_die;
	mk_lang_types_bool_t is_inited;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	task->m_connection.m_state.m_session_want_die = mk_lang_null;
	task->m_connection.m_state.m_session_want_snd = mk_lang_null;
	task->m_connection.m_state.m_session_want_rcv = mk_lang_null;
	stp_res_a = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	err = mk_lib_iip_cp_client_connection_task_prrw_is_inited(task, &is_inited); mk_lang_check_rereturn(err);
	if(is_inited && !task->m_connection.m_state.m_stop_requested && !task->m_connection.m_state.m_disconnected)
	{
		count = mk_lib_iip_cp_client_session_tasks_rw_size(&task->m_connection.m_state.m_sessions);
		if(count != 0)
		{
			++task->m_connection.m_state.m_session_idx;
			session_want_die = mk_lang_null;
			session_want_snd = mk_lang_null;
			session_want_rcv = mk_lang_null;
			n = count;
			for(i = 0; i != n; ++i)
			{
				break2 = mk_lang_false;
				idx = (i + task->m_connection.m_state.m_session_idx) % count;
				session_ptr = mk_lib_iip_cp_client_session_tasks_rw_at(&task->m_connection.m_state.m_sessions, idx); mk_lang_assert(session_ptr); session_obj = *session_ptr; mk_lang_assert(session_obj);
				stp_res = mk_lib_iip_cp_client_session_task_result_e_dummy_end; err = mk_lib_iip_cp_client_session_task_rw_step(session_obj, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_session_task_result_e_dummy_end);
				switch(stp_res)
				{
					case mk_lib_iip_cp_client_session_task_result_e_did_something:
					{
						stp_res_a = mk_lib_iip_cp_client_connection_task_result_e_did_something;
						break2 = mk_lang_true;
					}
					break;
					case mk_lib_iip_cp_client_session_task_result_e_idling:
					{
						err = mk_lib_iip_cp_client_session_task_rw_want_die(session_obj, &want); mk_lang_check_rereturn(err);
						if(want)
						{
							session_want_die = session_ptr;
						}
					}
					break;
					case mk_lib_iip_cp_client_session_task_result_e_want_send:
					{
						if(!session_want_snd)
						{
							session_want_snd = session_obj;
						}
					}
					break;
					case mk_lib_iip_cp_client_session_task_result_e_want_recv:
					{
						if(!session_want_rcv)
						{
							session_want_rcv = session_obj;
						}
					}
					break;
					case mk_lib_iip_cp_client_session_task_result_e_dummy_end:
					{
						mk_lang_assert_false();
					}
					break;
					default:
					{
						mk_lang_assert_false();
					}
					break;
				}
				if(break2)
				{
					break;
				}
			}
			task->m_connection.m_state.m_session_want_die = session_want_die;
			task->m_connection.m_state.m_session_want_snd = session_want_snd;
			task->m_connection.m_state.m_session_want_rcv = session_want_rcv;
		}
	}
	*step_result = stp_res_a;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_sub_sessions_want_die(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_inited;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	err = mk_lib_iip_cp_client_connection_task_prrw_is_inited(task, &is_inited); mk_lang_check_rereturn(err);
	if(is_inited && task->m_connection.m_state.m_session_want_die)
	{
		err = mk_lib_iip_cp_client_session_tasks_rw_erase_element(&task->m_connection.m_state.m_sessions, task->m_connection.m_state.m_session_want_die); mk_lang_check_rereturn(err);
		stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_something;
	}
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_sub_sessions_want_snd(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_inited;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;
	mk_lib_iip_cp_message_pt msg;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	err = mk_lib_iip_cp_client_connection_task_prrw_is_inited(task, &is_inited); mk_lang_check_rereturn(err);
	if(is_inited && task->m_connection.m_state.m_session_want_snd)
	{
		if(task->m_connection.m_state.m_pending_send)
		{
			stp_res = mk_lib_iip_cp_client_connection_task_result_e_would_block;
		}
		else
		{
			err = mk_lib_iip_cp_client_session_task_rw_gimme_msg(task->m_connection.m_state.m_session_want_snd, &msg); mk_lang_check_rereturn(err); mk_lang_assert(msg);
			if(msg->m_header.m_type == mk_lib_iip_cp_message_message_type_id_e_create_session)
			{
				mk_lang_assert(!task->m_connection.m_state.m_pending_session_to_create);
				task->m_connection.m_state.m_pending_session_to_create = task->m_connection.m_state.m_session_want_snd;
			}
			err = mk_lib_iip_cp_client_connection_task_prrw_serialize_message_explicit(task, msg); mk_lang_check_rereturn(err);
			err = mk_lib_iip_cp_client_connection_task_prrw_issue_write(task); mk_lang_check_rereturn(err);
			stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_something;
		}
	}
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_process_msg(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_inited;
	mk_lib_iip_cp_client_connection_task_result_t stp_res_a;
	mk_lib_iip_cp_client_connection_task_result_t stp_res_b;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	stp_res_a = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	err = mk_lib_iip_cp_client_connection_task_prrw_is_inited(task, &is_inited); mk_lang_check_rereturn(err);
	if(is_inited && task->m_connection.m_state.m_has_msg)
	{
		task->m_connection.m_state.m_has_msg = mk_lang_false;
		stp_res_b = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_dispatch_msg(task, allow_to_block, tm, &stp_res_b); mk_lang_check_rereturn(err); mk_lang_assert(stp_res_b != mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
		stp_res_a = stp_res_b;
	}
	*step_result = stp_res_a;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_parse_buf(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_inited;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);
	mk_lang_assert(!task->m_connection.m_state.m_has_msg);

	stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	err = mk_lib_iip_cp_client_connection_task_prrw_is_inited(task, &is_inited); mk_lang_check_rereturn(err);
	if(is_inited && !mk_lib_iip_cp_dynamic_ring_u8_rw_is_empty(&task->m_connection.m_state.m_buf_rcv))
	{
		err = mk_lib_iip_cp_client_connection_task_prrw_parse_message(task); mk_lang_check_rereturn(err);
		if(task->m_connection.m_state.m_msg.m_header.m_type != mk_lib_iip_cp_message_message_type_id_e_dummy_end)
		{
			task->m_connection.m_state.m_has_msg = mk_lang_true;
			stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_something;
		}
	}
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_sub_sessions_want_rcv(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_inited;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	err = mk_lib_iip_cp_client_connection_task_prrw_is_inited(task, &is_inited); mk_lang_check_rereturn(err);
	if(is_inited && task->m_connection.m_state.m_session_want_rcv)
	{
		if(task->m_connection.m_state.m_pending_recv)
		{
			stp_res = mk_lib_iip_cp_client_connection_task_result_e_would_block;
		}
		else
		{
			err = mk_lib_iip_cp_client_connection_task_prrw_issue_read(task); mk_lang_check_rereturn(err);
			stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_something;
		}
	}
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_want_rcv(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_inited;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	err = mk_lib_iip_cp_client_connection_task_prrw_is_inited(task, &is_inited); mk_lang_check_rereturn(err);
	if(is_inited)
	{
		if(task->m_connection.m_state.m_pending_recv)
		{
			stp_res = mk_lib_iip_cp_client_connection_task_result_e_would_block;
		}
		else
		{
			err = mk_lib_iip_cp_client_connection_task_prrw_issue_read(task); mk_lang_check_rereturn(err);
			stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_something;
		}
	}
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step_want_die_all_done(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_bool_t is_inited;
	mk_lib_iip_cp_client_connection_task_result_t stp_res;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	err = mk_lib_iip_cp_client_connection_task_prrw_is_inited(task, &is_inited); mk_lang_check_rereturn(err);
	if(is_inited && !task->m_connection.m_state.m_want_die && task->m_connection.m_state.m_stop_requested && task->m_connection.m_state.m_stop_acknowledged)
	{
		if((mk_lib_iip_cp_client_session_tasks_rw_is_empty(&task->m_connection.m_state.m_sessions)))
		{
			task->m_connection.m_state.m_want_die = mk_lang_true;
			stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_something;
		}
	}
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_step(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_result_t stp_res;
	mk_lang_types_sint_t err;

	mk_lang_assert(task);
	mk_lang_assert(allow_to_block == mk_lang_true || allow_to_block == mk_lang_false);
	mk_lang_assert((tm >= 0 && tm <= 10 * 60 * 1000) || tm == -1);
	mk_lang_assert(step_result);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_task_result_e_dummy_end);

	stp_res = mk_lib_iip_cp_client_connection_task_result_e_did_nothing;
	if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing){ stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_init(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing){ stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_acknowledge_stop(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing){ stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_sub_sessions_do(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing){ stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_sub_sessions_want_die(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing){ stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_sub_sessions_want_snd(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing){ stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_process_msg(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing){ stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_parse_buf(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing){ stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_sub_sessions_want_rcv(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing){ stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_want_rcv(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); }
	if(stp_res == mk_lib_iip_cp_client_connection_task_result_e_did_nothing){ stp_res = mk_lib_iip_cp_client_connection_task_result_e_dummy_end; err = mk_lib_iip_cp_client_connection_task_prrw_step_want_die_all_done(task, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); mk_lang_assert(stp_res != mk_lib_iip_cp_client_connection_task_result_e_dummy_end); }
	*step_result = stp_res;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_want_die(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lang_types_bool_t wand;

	mk_lang_assert(task);
	mk_lang_assert(want);

	wand = task->m_connection.m_state.m_want_die;
	*want = wand;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_prrw_new_session(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_client_session_settings_pct const settings, mk_lib_iip_cp_client_session_task_ppt const session) mk_lang_noexcept
{
	mk_lib_iip_cp_client_session_task_pt primary_ses;
	mk_lib_iip_cp_client_session_task_ppt primary_ptr;
	mk_lib_iip_cp_client_session_task_pt primary_obj;
	mk_lang_types_sint_t err;
	mk_lib_iip_cp_client_session_task_pt ses;
	mk_lib_iip_cp_client_session_task_pt sss;
	mk_lang_types_void_pt mem;

	mk_lang_assert(task);
	mk_lang_assert(settings);
	mk_lang_assert(session);

	if(mk_lib_iip_cp_client_session_tasks_rw_is_empty(&task->m_connection.m_state.m_sessions))
	{
		mk_lang_assert(mk_lib_iip_cp_client_session_handle_is_zero(&settings->m_master_session));
	}
	else
	{
		mk_lang_assert(!mk_lib_iip_cp_client_session_handle_is_zero(&settings->m_master_session));
		primary_ses = ((mk_lib_iip_cp_client_session_task_pt)(settings->m_master_session.m_elements[0]));
		primary_ptr = mk_lib_iip_cp_client_session_tasks_rw_front(&task->m_connection.m_state.m_sessions); mk_lang_assert(primary_ptr); primary_obj = *primary_ptr; mk_lang_assert(primary_obj);
		mk_lang_assert(primary_ses == primary_obj);
		mk_lang_assert(mk_lib_iip_cp_destination_local_ro_eq_enc(&settings->m_local_destination, &primary_obj->m_session.m_settings.m_local_destination));
		err = mk_lib_iip_cp_client_session_task_rw_on_child_session_spawned(primary_ses); mk_lang_check_rereturn(err);
	}
	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*ses), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); ses = ((mk_lib_iip_cp_client_session_task_pt)(mem)); mk_lang_assert(ses); sss = ses; mk_lang_assert(sss);
	err = mk_lib_iip_cp_client_session_task_rw_construct(ses, task->m_connection.m_settings.m_shared, settings); mk_lang_check_rereturn(err);
	err = mk_lib_iip_cp_client_session_tasks_rw_push_back_move_single(&task->m_connection.m_state.m_sessions, &ses); mk_lang_check_rereturn(err);
	*session = sss;
	return 0;
}


mk_lang_nodiscard static mk_lang_inline mk_lib_iip_cp_client_connection_task_pt mk_lib_iip_cp_client_connection_task_prrw_type_to_self(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_settings_pt settings;
	mk_lib_iip_cp_client_connection_pt local_listener;
	mk_lib_iip_cp_client_connection_task_pt self;

	mk_lang_assert(connection);

	#include "mk_lang_warning_clang_push_cast_align.h"
	settings = ((mk_lib_iip_cp_client_connection_task_settings_pt)(((mk_lang_types_uchar_pt)(connection)) - mk_lang_offsetof(mk_lib_iip_cp_client_connection_task_settings_t, m_type)));
	local_listener = ((mk_lib_iip_cp_client_connection_pt)(((mk_lang_types_uchar_pt)(settings)) - mk_lang_offsetof(mk_lib_iip_cp_client_connection_t, m_settings)));
	self = ((mk_lib_iip_cp_client_connection_task_pt)(((mk_lang_types_uchar_pt)(local_listener)) - mk_lang_offsetof(mk_lib_iip_cp_client_connection_task_t, m_connection)));
	#include "mk_lang_warning_clang_pop.h"
	return self;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_allocate(mk_lib_iip_any_data_connection_ppt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;
	mk_lib_iip_cp_client_connection_task_pt self;

	mk_lang_assert(connection);

	err = mk_lib_iip_cp_mallocator_global_allocate(sizeof(*self), &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); self = ((mk_lib_iip_cp_client_connection_task_pt)(mem)); mk_lang_assert(self);
	self->m_connection.m_settings.m_type.m_data.m_id = mk_lib_iip_any_data_connection_type_e_mk_lib_iip_cp_client_connection_task;
	*connection = &self->m_connection.m_settings.m_type;
	mk_lang_assert(mk_lib_iip_cp_client_connection_task_prrw_type_to_self(*connection) == self);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_deallocate(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_connection_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_mallocator_global_deallocate(self, sizeof(*self)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_construct(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_void_pt const settings) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_connection_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_connection_task_prrw_construct(self, ((mk_lib_iip_cp_client_connection_task_settings_pct)(settings))); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_destroy(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_connection_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_connection_task_prrw_destroy(self); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_request_close(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_connection_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_connection_task_prrw_request_close(self); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_want_associate_socket(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_connection_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_connection_task_prrw_want_associate_socket(self, want); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_gimme_socket(mk_lib_iip_any_data_connection_pt const connection, mk_lib_net_socket_ppt const socket, mk_lib_iip_any_data_connection_ppt const associatee) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_connection_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_connection_task_prrw_gimme_socket(self, socket, associatee); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_on_iorp_done(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_connection_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_connection_task_prrw_on_iorp_done(self, successful_io_operation, bytes_transferred, overlapped); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_step(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_any_data_connection_result_pt const step_result) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_connection_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_connection_task_prrw_step(self, allow_to_block, tm, ((mk_lib_iip_cp_client_connection_task_result_pt)(step_result))); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_want_die(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_connection_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_connection_task_prrw_want_die(self, want); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_prrw_new_session(mk_lib_iip_any_data_connection_pt const connection, mk_lib_iip_cp_client_session_settings_pct const settings, mk_lib_iip_cp_client_session_task_ppt const session) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt self;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection);

	self = mk_lib_iip_cp_client_connection_task_prrw_type_to_self(connection); mk_lang_assert(self);
	err = mk_lib_iip_cp_client_connection_task_prrw_new_session(self, settings, session); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_construct(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_client_connection_task_settings_pct const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_construct(task, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_destroy(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_destroy(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_request_close(mk_lib_iip_cp_client_connection_task_pt const task) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_request_close(task);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_want_associate_socket(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_want_associate_socket(task, want);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_gimme_socket(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_net_socket_ppt const socket, mk_lib_iip_any_data_connection_ppt const associatee) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_gimme_socket(task, socket, associatee);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_on_iorp_done(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_on_iorp_done(task, successful_io_operation, bytes_transferred, overlapped);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_step(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_task_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_step(task, allow_to_block, tm, step_result);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_want_die(mk_lib_iip_cp_client_connection_task_pt const task, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_want_die(task, want);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_rw_new_session(mk_lib_iip_cp_client_connection_task_pt const task, mk_lib_iip_cp_client_session_settings_pct const settings, mk_lib_iip_cp_client_session_task_ppt const session) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_prrw_new_session(task, settings, session);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_allocate(mk_lib_iip_any_data_connection_ppt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_allocate(connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_deallocate(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_deallocate(connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_construct(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_void_pt const settings) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_construct(connection, settings);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_destroy(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_destroy(connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_request_close(mk_lib_iip_any_data_connection_pt const connection) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_request_close(connection);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_want_associate_socket(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_want_associate_socket(connection, want);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_gimme_socket(mk_lib_iip_any_data_connection_pt const connection, mk_lib_net_socket_ppt const socket, mk_lib_iip_any_data_connection_ppt const associatee) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_gimme_socket(connection, socket, associatee);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_on_iorp_done(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_t const successful_io_operation, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_on_iorp_done(connection, successful_io_operation, bytes_transferred, overlapped);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_step(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_any_data_connection_result_pt const step_result) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_step(connection, allow_to_block, tm, step_result);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_want_die(mk_lib_iip_any_data_connection_pt const connection, mk_lang_types_bool_pt const want) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_want_die(connection, want);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_any_rw_new_session(mk_lib_iip_any_data_connection_pt const connection, mk_lib_iip_cp_client_session_settings_pct const settings, mk_lib_iip_cp_client_session_task_ppt const session) mk_lang_noexcept
{
	return mk_lib_iip_cp_client_connection_task_any_prrw_new_session(connection, settings, session);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_construct_void(mk_lib_iip_cp_client_connection_task_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_destroy(mk_lib_iip_cp_client_connection_task_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_task_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_connection_task_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_construct_copy(mk_lib_iip_cp_client_connection_task_ppt const dst, mk_lib_iip_cp_client_connection_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_construct_move(mk_lib_iip_cp_client_connection_task_ppt const dst, mk_lib_iip_cp_client_connection_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_assign_copy(mk_lib_iip_cp_client_connection_task_ppt const dst, mk_lib_iip_cp_client_connection_task_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_task_ptr_rw_assign_move(mk_lib_iip_cp_client_connection_task_ppt const dst, mk_lib_iip_cp_client_connection_task_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_connection_tasks
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_connection_task_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_connection_task_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_connection_task_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_connection_task_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_connection_task_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_connection_task_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_connection_task_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
