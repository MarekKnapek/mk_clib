#ifndef mk_include_guard_mk_iip_cp_connection_impl_c
#define mk_include_guard_mk_iip_cp_connection_impl_c
#include "mk_iip_cp_connection_impl.h"

#include "mk_iip_cp_client_data.h"
#include "mk_iip_cp_client_data_impl.h"
#include "mk_iip_cp_helper.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_message.h"
#include "mk_iip_cp_message_parse.h"
#include "mk_iip_cp_message_serialize.h"
#include "mk_iip_cp_session_intr.h"
#include "mk_iip_cp_type.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_net_windows.h"
#include "mk_sl_uint16.h"
#include "mk_sl_uint8.h"
#include "mk_win_utils.h"


#define mk_sl_ring_dynamic_t_name mk_iip_cp_connection_impl_buffer
#define mk_sl_ring_dynamic_t_element mk_sl_cui_uint8_t
#define mk_sl_ring_dynamic_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_ring_dynamic_inl_filec.h"
#include "mk_sl_ring_dynamic_inl_fileu.h"

#define mk_sl_vector_t_name mk_iip_cp_connection_impl_cmds
#define mk_sl_vector_t_element mk_iip_cp_connection_impl_cmd_t
#define mk_sl_vector_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#if defined mk_iip_cp_connection_impl_debug_message_want && (mk_iip_cp_connection_impl_debug_message_want) == 1
#define mk_iip_cp_connection_impl_debug_message_have 1
#elif defined mk_iip_cp_connection_impl_debug_message_want && (mk_iip_cp_connection_impl_debug_message_want) == 0
#define mk_iip_cp_connection_impl_debug_message_have 0
#else
	#if defined DEBUG || defined _DEBUG
	#define mk_iip_cp_connection_impl_debug_message_have 1
	#else
		#if defined NDEBUG
		#define mk_iip_cp_connection_impl_debug_message_have 0
		#else
		#define mk_iip_cp_connection_impl_debug_message_have 1
		#endif
	#endif
#endif
#if mk_iip_cp_connection_impl_debug_message_have
#include "mk_iip_cp_message_tostr.h"
#include "mk_sl_io_console.h"
#endif


#define mk_iip_cp_connection_impl_pr_grow_count (128 * 1024)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_allocate(mk_iip_cp_connection_impl_ppt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**connection_impl), ((mk_lang_types_void_ppt)(connection_impl))); mk_lang_check_rereturn(err); mk_lang_assert(*connection_impl);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_deallocate(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);

	err = mk_iip_cp_mallocator_global_deallocate(connection_impl, sizeof(*connection_impl)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_construct(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(connection_intr);

	connection_impl->m_connection_intr = connection_intr;
	((mk_lang_types_void_t)(connection_impl->m_server_date_val));
	((mk_lang_types_void_t)(connection_impl->m_server_date_now));
	((mk_lang_types_void_t)(connection_impl->m_server_version));
	err = mk_iip_cp_session_intrs_rw_construct(&connection_impl->m_sessions); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(connection_impl->m_did_something));
	err = mk_iip_cp_connection_impl_cmds_rw_construct(&connection_impl->m_cmds); mk_lang_check_rereturn(err);
	connection_impl->m_sub_item_idx = 0;
	connection_impl->m_force = mk_lang_false;
	((mk_lang_types_void_t)(connection_impl->m_ip_destination));
	connection_impl->m_has_read_iorp = mk_lang_false;
	connection_impl->m_has_write_iorp = mk_lang_false;
	err = mk_sl_net_windows_ctx_connect_construct(&connection_impl->m_connect_ctx); mk_lang_check_rereturn(err);
	err = mk_sl_net_windows_socket_construct_iv4_tcp_noassoc(&connection_impl->m_socket); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(connection_impl->m_iocp));
	((mk_lang_types_void_t)(connection_impl->m_errcodep));
	((mk_lang_types_void_t)(connection_impl->m_errcodes));
	((mk_lang_types_void_t)(connection_impl->m_consumed));
	err = mk_iip_cp_message_construct(&connection_impl->m_message, mk_iip_cp_message_message_type_e_dummy_end); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(connection_impl->m_request_get_bandwidth_limits_internal));
	((mk_lang_types_void_t)(connection_impl->m_response_get_bandwidth_limits_internal));
	((mk_lang_types_void_t)(connection_impl->m_bandwidth_limits));
	err = mk_sl_net_windows_iorpr_construct(&connection_impl->m_iorpr, mk_lang_null, 0); mk_lang_check_rereturn(err); connection_impl->m_iorpr.m_user = connection_intr;
	err = mk_sl_net_windows_iorpw_construct(&connection_impl->m_iorpw, mk_lang_null, 0); mk_lang_check_rereturn(err); connection_impl->m_iorpw.m_user = connection_intr;
	err = mk_iip_cp_connection_impl_buffer_rw_construct(&connection_impl->m_snd_buf); mk_lang_check_rereturn(err);
	err = mk_iip_cp_connection_impl_buffer_rw_construct(&connection_impl->m_rcv_buf); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_destruct(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);

	((mk_lang_types_void_t)(connection_impl->m_connection_intr));
	((mk_lang_types_void_t)(connection_impl->m_server_date_val));
	((mk_lang_types_void_t)(connection_impl->m_server_date_now));
	((mk_lang_types_void_t)(connection_impl->m_server_version));
	err = mk_iip_cp_session_intrs_rw_destroy(&connection_impl->m_sessions); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(connection_impl->m_did_something));
	err = mk_iip_cp_connection_impl_cmds_rw_destroy(&connection_impl->m_cmds); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(connection_impl->m_sub_item_idx));
	((mk_lang_types_void_t)(connection_impl->m_force));
	((mk_lang_types_void_t)(connection_impl->m_ip_destination));
	((mk_lang_types_void_t)(connection_impl->m_has_read_iorp));
	((mk_lang_types_void_t)(connection_impl->m_has_write_iorp));
	err = mk_sl_net_windows_ctx_connect_destruct(&connection_impl->m_connect_ctx); mk_lang_check_rereturn(err);
	err = mk_sl_net_windows_socket_destruct(&connection_impl->m_socket); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(connection_impl->m_iocp));
	((mk_lang_types_void_t)(connection_impl->m_errcodep));
	((mk_lang_types_void_t)(connection_impl->m_errcodes));
	((mk_lang_types_void_t)(connection_impl->m_consumed));
	err = mk_iip_cp_message_destroy(&connection_impl->m_message); mk_lang_check_rereturn(err);
	((mk_lang_types_void_t)(connection_impl->m_request_get_bandwidth_limits_internal));
	((mk_lang_types_void_t)(connection_impl->m_response_get_bandwidth_limits_internal));
	((mk_lang_types_void_t)(connection_impl->m_bandwidth_limits));
	err = mk_sl_net_windows_iorpr_destruct(&connection_impl->m_iorpr); mk_lang_check_rereturn(err);
	err = mk_sl_net_windows_iorpw_destruct(&connection_impl->m_iorpw); mk_lang_check_rereturn(err);
	err = mk_iip_cp_connection_impl_buffer_rw_destruct(&connection_impl->m_snd_buf); mk_lang_check_rereturn(err);
	err = mk_iip_cp_connection_impl_buffer_rw_destruct(&connection_impl->m_rcv_buf); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_allocate_and_construct(mk_iip_cp_connection_impl_ppt const connection_impl, mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_allocate(connection_impl); mk_lang_check_rereturn(err); mk_lang_assert(*connection_impl);
	err = mk_iip_cp_connection_impl_rw_construct(*connection_impl, connection_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_destruct_and_deallocate(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);

	err = mk_iip_cp_connection_impl_rw_destruct(connection_impl); mk_lang_check_rereturn(err);
	err = mk_iip_cp_connection_impl_rw_deallocate(connection_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_set_iocp(mk_iip_cp_connection_impl_pt const connection_impl, mk_sl_io_async_iocp_windows_pt const iocp) mk_lang_noexcept
{
	mk_lang_assert(connection_impl);
	mk_lang_assert(iocp);

	connection_impl->m_iocp = iocp;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_sessionid_to_session(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_type_sessionid_pct const session_id, mk_iip_cp_session_intr_ppt const session) mk_lang_noexcept
{
	mk_iip_cp_session_intr_pt res;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_iip_cp_session_intr_pt ses;
	mk_iip_cp_type_sessionid_pct sid;

	mk_lang_assert(connection_impl);
	mk_lang_assert(session_id);
	mk_lang_assert(session);

	/* todo faster than o(n) */
	res = mk_lang_null;
	n = mk_iip_cp_session_intrs_ro_size(&connection_impl->m_sessions);
	for(i = 0; i != n; ++i)
	{
		ses = mk_iip_cp_session_intrs_rw_at(&connection_impl->m_sessions, i); mk_lang_assert(ses);
		sid = mk_iip_cp_session_intr_rw_get_session_id(ses); mk_lang_assert(sid);
		if(mk_sl_cui_uint16_eq(&sid->m_id, &session_id->m_id))
		{
			res = ses;
			break;
		}
	}
	*session = res;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_request_read_full(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_usize_t old_idx;
	mk_sl_cui_uint8_pt buf;
	mk_lang_types_usize_t tus;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_has_read_iorp);

	connection_impl->m_has_read_iorp = mk_lang_true;
	old_idx = mk_iip_cp_connection_impl_buffer_ro_size(&connection_impl->m_rcv_buf);
	err = mk_iip_cp_connection_impl_buffer_rw_push_back_void_many(&connection_impl->m_rcv_buf, mk_iip_cp_connection_impl_pr_grow_count); mk_lang_check_rereturn(err);
	buf = mk_iip_cp_connection_impl_buffer_rw_at(&connection_impl->m_rcv_buf, old_idx); mk_lang_assert(buf);
	tus = mk_iip_cp_connection_impl_buffer_rw_contiguous_at(&connection_impl->m_rcv_buf, old_idx); len = ((mk_lang_types_sint_t)(tus));
	err = mk_sl_net_windows_iorpr_reconstruct(&connection_impl->m_iorpr, buf, len); mk_lang_check_rereturn(err);
	err = mk_sl_net_windows_socket_request_read(&connection_impl->m_socket, &connection_impl->m_iorpr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_rerequest_read_full(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_has_read_iorp);

	err = mk_iip_cp_connection_impl_pr_request_read_full(connection_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_request_read_full_if_possible(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);

	if(!connection_impl->m_has_read_iorp)
	{
		err = mk_iip_cp_connection_impl_pr_request_read_full(connection_impl); mk_lang_check_rereturn(err); mk_lang_assert(connection_impl->m_has_read_iorp);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_serialize_message_log(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_serialize_errcode_pct const errcode, mk_lang_types_sint_pct const consumed, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
#if mk_iip_cp_connection_impl_debug_message_have
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pt strbuf;
	mk_lang_types_pchar_t buffer[4 * 1024];
	mk_lang_types_sint_t strlen;
	mk_lang_types_pchar_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(message);

	err = mk_win_utils_write_current_time_to_console(); mk_lang_check_rereturn(err);
	strbuf = &buffer[0];
	strlen = mk_lang_countof(buffer);
	ptr = strbuf;
	rem = strlen;
	err = mk_iip_cp_message_tostr_message_post_serialize_a(ptr, rem, &tlen, errcode, consumed, message); mk_lang_check_rereturn(err); ptr += tlen; rem -= tlen;
	mk_lang_check_return(rem >= 1); ptr[0] = '\0';
	tlen = strlen - rem;
	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(strbuf)), tlen); mk_lang_check_rereturn(err);
	ptr = strbuf;
	rem = strlen;
	err = mk_iip_cp_message_tostr_message_post_serialize_b(ptr, rem, &tlen, errcode, consumed, message); mk_lang_check_rereturn(err); ptr += tlen; rem -= tlen;
	mk_lang_check_return(rem >= 2); ptr[0] = '\x0d'; ptr[1] = '\x0a'; ptr += 2; rem -= 2;
	mk_lang_check_return(rem >= 1); ptr[0] = '\0';
	tlen = strlen - rem;
	err = mk_sl_io_console_write_colored_n(mk_sl_io_console_color_text_e_dark_green, ((mk_sl_cui_uint8_pct)(strbuf)), tlen); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(message);

	((mk_lang_types_void_t)(buf));
	((mk_lang_types_void_t)(len));
	((mk_lang_types_void_t)(errcode));
	((mk_lang_types_void_t)(consumed));
	((mk_lang_types_void_t)(message));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_parse_message_log(mk_sl_cui_uint8_pct const buf, mk_lang_types_sint_t const len, mk_iip_cp_message_parse_errcode_pct const errcode, mk_lang_types_sint_pct const consumed, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
#if mk_iip_cp_connection_impl_debug_message_have
	mk_lang_types_sint_t err;
	mk_lang_types_pchar_pt strbuf;
	mk_lang_types_pchar_t buffer[4 * 1024];
	mk_lang_types_sint_t strlen;
	mk_lang_types_pchar_pt ptr;
	mk_lang_types_sint_t rem;
	mk_lang_types_sint_t tlen;

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(message);

	err = mk_win_utils_write_current_time_to_console(); mk_lang_check_rereturn(err);
	strbuf = &buffer[0];
	strlen = mk_lang_countof(buffer);
	ptr = strbuf;
	rem = strlen;
	err = mk_iip_cp_message_tostr_message_post_parse_a(ptr, rem, &tlen, errcode, consumed, message); mk_lang_check_rereturn(err); ptr += tlen; rem -= tlen;
	mk_lang_check_return(rem >= 1); ptr[0] = '\0';
	tlen = strlen - rem;
	err = mk_sl_io_console_write_n(((mk_sl_cui_uint8_pct)(strbuf)), tlen); mk_lang_check_rereturn(err);
	ptr = strbuf;
	rem = strlen;
	err = mk_iip_cp_message_tostr_message_post_parse_b(ptr, rem, &tlen, errcode, consumed, message); mk_lang_check_rereturn(err); ptr += tlen; rem -= tlen;
	mk_lang_check_return(rem >= 2); ptr[0] = '\x0d'; ptr[1] = '\x0a'; ptr += 2; rem -= 2;
	mk_lang_check_return(rem >= 1); ptr[0] = '\0';
	tlen = strlen - rem;
	err = mk_sl_io_console_write_colored_n(mk_sl_io_console_color_text_e_dark_yellow, ((mk_sl_cui_uint8_pct)(strbuf)), tlen); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(errcode);
	mk_lang_assert(consumed);
	mk_lang_assert(message);

	((mk_lang_types_void_t)(buf));
	((mk_lang_types_void_t)(len));
	((mk_lang_types_void_t)(errcode));
	((mk_lang_types_void_t)(consumed));
	((mk_lang_types_void_t)(message));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_serialize_message(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_usize_t old_size;
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt buf;
	mk_lang_types_usize_t tus;
	mk_lang_types_sint_t len;

	mk_lang_assert(connection_impl);

	old_size = mk_iip_cp_connection_impl_buffer_ro_size(&connection_impl->m_snd_buf);
	err = mk_iip_cp_connection_impl_buffer_rw_push_back_void_many(&connection_impl->m_snd_buf, mk_iip_cp_connection_impl_pr_grow_count); mk_lang_check_rereturn(err);
	buf = mk_iip_cp_connection_impl_buffer_rw_at(&connection_impl->m_snd_buf, old_size); mk_lang_assert(buf);
	tus = mk_iip_cp_connection_impl_buffer_rw_contiguous_at(&connection_impl->m_snd_buf, old_size); len = ((mk_lang_types_sint_t)(tus));
	err = mk_iip_cp_message_serialize_message(buf, len, &connection_impl->m_errcodes, &connection_impl->m_consumed, &connection_impl->m_message); mk_lang_check_rereturn(err);
	err = mk_iip_cp_connection_impl_buffer_rw_pop_back_many(&connection_impl->m_snd_buf, mk_iip_cp_connection_impl_pr_grow_count - connection_impl->m_consumed); mk_lang_check_rereturn(err);
	err = mk_iip_cp_connection_impl_pr_serialize_message_log(buf, len, &connection_impl->m_errcodes, &connection_impl->m_consumed, &connection_impl->m_message); mk_lang_check_rereturn(err);
	mk_lang_check_return(connection_impl->m_errcodes == mk_iip_cp_message_serialize_errcode_e_ok); /* todo */
	mk_lang_check_return(connection_impl->m_consumed >= 1); /* todo */
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_parse_message(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t sub;
	mk_sl_cui_uint8_pct buf;
	mk_lang_types_usize_t tus;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);

	sub = connection_impl->m_has_read_iorp ? mk_iip_cp_connection_impl_pr_grow_count : 0;
	buf = mk_iip_cp_connection_impl_buffer_ro_parta_buf(&connection_impl->m_rcv_buf); mk_lang_assert(buf);
	tus = mk_iip_cp_connection_impl_buffer_ro_parta_len(&connection_impl->m_rcv_buf); len = ((mk_lang_types_sint_t)(tus)); len = mk_lang_max(0, len - sub);
	err = mk_iip_cp_message_destroy(&connection_impl->m_message); mk_lang_check_rereturn(err);
	err = mk_iip_cp_message_parse_message(buf, len, &connection_impl->m_errcodep, &connection_impl->m_consumed, &connection_impl->m_message); mk_lang_check_rereturn(err);
	/*if(connection_impl->m_errcodep == mk_iip_cp_message_parse_errcode_e_not_enough_data && mk_iip_cp_connection_impl_buffer_ro_parta_len(&connection_impl->m_rcv_buf) != 0)
	{
		err = mk_iip_cp_connection_impl_buffer_rw_linearize(&connection_impl->m_rcv_buf); mk_lang_check_rereturn(err);
		buf = mk_iip_cp_connection_impl_buffer_ro_parta_buf(&connection_impl->m_rcv_buf); mk_lang_assert(buf);
		tus = mk_iip_cp_connection_impl_buffer_ro_parta_len(&connection_impl->m_rcv_buf); len = ((mk_lang_types_sint_t)(tus)); len = mk_lang_max(0, len - sub);
		err = mk_iip_cp_message_parse_message(buf, len, &connection_impl->m_errcodep, &connection_impl->m_consumed, &connection_impl->m_message); mk_lang_check_rereturn(err);
	}*/
	err = mk_iip_cp_connection_impl_pr_parse_message_log(buf, len, &connection_impl->m_errcodep, &connection_impl->m_consumed, &connection_impl->m_message); mk_lang_check_rereturn(err);
	if(connection_impl->m_errcodep == mk_iip_cp_message_parse_errcode_e_ok)
	{
		mk_lang_assert(connection_impl->m_consumed >= 5);
		err = mk_iip_cp_connection_impl_buffer_rw_pop_front_many(&connection_impl->m_rcv_buf, connection_impl->m_consumed); mk_lang_check_rereturn(err);
		if(!connection_impl->m_has_read_iorp)
		{
			err = mk_iip_cp_connection_impl_buffer_rw_reset_if_possible(&connection_impl->m_rcv_buf); mk_lang_check_rereturn(err);
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_reqsend_message(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_sl_cui_uint8_pct buf;
	mk_lang_types_usize_t tus;
	mk_lang_types_sint_t len;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_has_write_iorp);

	buf = mk_iip_cp_connection_impl_buffer_ro_parta_buf(&connection_impl->m_snd_buf); mk_lang_assert(buf);
	tus = mk_iip_cp_connection_impl_buffer_ro_parta_len(&connection_impl->m_snd_buf); len = ((mk_lang_types_sint_t)(tus)); mk_lang_assert(len >= 1);
	err = mk_sl_net_windows_iorpw_reconstruct(&connection_impl->m_iorpw, buf, len); mk_lang_check_rereturn(err);
	err = mk_sl_net_windows_socket_request_write(&connection_impl->m_socket, &connection_impl->m_iorpw); mk_lang_check_rereturn(err);
	connection_impl->m_has_write_iorp = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_send_message(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);

	err = mk_iip_cp_connection_impl_pr_serialize_message(connection_impl); mk_lang_check_rereturn(err);
	err = mk_iip_cp_connection_impl_pr_reqsend_message(connection_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_connection_impl_pr_is_all_sent(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(connection_impl);

	ret = mk_iip_cp_connection_impl_buffer_ro_is_empty(&connection_impl->m_snd_buf);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_connection_impl_rw_did_something(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(connection_impl);

	ret = connection_impl->m_did_something;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_connection_impl_rw_has_outstanding_iorp(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(connection_impl);

	ret = connection_impl->m_has_write_iorp || connection_impl->m_has_read_iorp;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_on_msg_self_set_date(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_did_something);
	mk_lang_assert(mk_iip_cp_message_is_per_connection(connection_impl->m_message.m_header.m_type));
	mk_lang_assert(connection_impl->m_message.m_header.m_type == mk_iip_cp_message_message_type_e_set_date);

	connection_impl->m_server_date_val = connection_impl->m_message.m_mix.m_data.m_set_date.m_server_date;
	mk_iip_cp_helper_get_time_now(&connection_impl->m_server_date_now.m_ms_since_unix);
	connection_impl->m_server_version = connection_impl->m_message.m_mix.m_data.m_set_date.m_server_version;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_on_msg_self(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_did_something);
	mk_lang_assert(mk_iip_cp_message_is_server_to_client(connection_impl->m_message.m_header.m_type));

	if(mk_iip_cp_message_is_per_connection(connection_impl->m_message.m_header.m_type))
	{
		switch(connection_impl->m_message.m_header.m_type)
		{
			case mk_iip_cp_message_message_type_e_create_session            : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_reconfigure_session       : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_destroy_session           : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_create_lease_set          : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_send_message              : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_receive_message_begin     : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_receive_message_end       : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_get_bandwidth_limits      : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_session_status            : mk_lang_check_todo(); break;
			case mk_iip_cp_message_message_type_e_request_lease_set         : mk_lang_check_todo(); break;
			case mk_iip_cp_message_message_type_e_message_status            : mk_lang_check_todo(); break;
			case mk_iip_cp_message_message_type_e_bandwidth_limits          : mk_lang_check_todo(); break;
			case mk_iip_cp_message_message_type_e_report_abuse              : mk_lang_check_todo(); break;
			case mk_iip_cp_message_message_type_e_disconnect                : mk_lang_check_todo(); break;
			case mk_iip_cp_message_message_type_e_message_payload           : mk_lang_check_todo(); break;
			case mk_iip_cp_message_message_type_e_get_date                  : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_set_date                  : err = mk_iip_cp_connection_impl_rw_on_msg_self_set_date(connection_impl); mk_lang_check_rereturn(err); break;
			case mk_iip_cp_message_message_type_e_dest_lookup               : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_dest_reply                : mk_lang_check_todo(); break;
			case mk_iip_cp_message_message_type_e_send_message_expires      : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_request_variable_lease_set: mk_lang_check_todo(); break;
			case mk_iip_cp_message_message_type_e_host_lookup               : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_host_reply                : mk_lang_check_todo(); break;
			case mk_iip_cp_message_message_type_e_create_lease_set2         : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_blinding_info             : mk_lang_assert(mk_lang_false); break;
			case mk_iip_cp_message_message_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
			default: mk_lang_assert(mk_lang_false); break;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_on_msg_sessions(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_iip_cp_session_intr_pt session;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_did_something);
	mk_lang_assert(mk_iip_cp_message_is_server_to_client(connection_impl->m_message.m_header.m_type));

	if(mk_iip_cp_message_is_per_session(connection_impl->m_message.m_header.m_type))
	{
		n = mk_iip_cp_session_intrs_rw_size(&connection_impl->m_sessions);
		for(i = 0; i != n; ++i)
		{
			session = mk_iip_cp_session_intrs_rw_at(&connection_impl->m_sessions, i); mk_lang_assert(session);
			err = mk_iip_cp_session_intr_rw_on_msg(session, &connection_impl->m_message); mk_lang_check_rereturn(err);
			if(mk_iip_cp_session_intr_rw_did_something(session))
			{
				connection_impl->m_did_something = mk_lang_true;
				break;
			}
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_on_msg(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_did_something);

	if(mk_iip_cp_message_is_server_to_client(connection_impl->m_message.m_header.m_type))
	{
		if(!mk_iip_cp_connection_impl_rw_did_something(connection_impl)){ err = mk_iip_cp_connection_impl_rw_on_msg_self    (connection_impl); mk_lang_check_rereturn(err); }
		if(!mk_iip_cp_connection_impl_rw_did_something(connection_impl)){ err = mk_iip_cp_connection_impl_rw_on_msg_sessions(connection_impl); mk_lang_check_rereturn(err); }
		if(!mk_iip_cp_connection_impl_rw_did_something(connection_impl))
		{
			mk_lang_check_todo(); /* message not processed */
		}
	}
	else
	{
		mk_lang_check_todo(); /* bad message type */
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_on_iorp(mk_iip_cp_connection_impl_pt const connection_impl, mk_sl_net_windows_iorp_xxx_pt const iorp) mk_lang_noexcept
{
	mk_lang_types_sint_t transferred;
	mk_lang_types_usize_t tus;
	mk_lang_types_sint_t size;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(iorp);
	mk_lang_assert(iorp->m_user == connection_impl->m_connection_intr);

	connection_impl->m_did_something = mk_lang_false;
	if(iorp->m_is_read)
	{
		mk_lang_assert(connection_impl->m_has_read_iorp);
		if(iorp->m_b != 0)
		{
			transferred = ((mk_lang_types_sint_t)(iorp->m_transferred));
			err = mk_iip_cp_connection_impl_buffer_rw_pop_back_many(&connection_impl->m_rcv_buf, mk_iip_cp_connection_impl_pr_grow_count - transferred); mk_lang_check_rereturn(err);
			connection_impl->m_has_read_iorp = mk_lang_false;
			connection_impl->m_did_something = mk_lang_true;
		}
		else
		{
			mk_lang_check_todo();
		}
	}
	else
	{
		mk_lang_assert(connection_impl->m_has_write_iorp);
		if(iorp->m_b != 0)
		{
			transferred = ((mk_lang_types_sint_t)(iorp->m_transferred));
			tus = mk_iip_cp_connection_impl_buffer_ro_size(&connection_impl->m_snd_buf); size = ((mk_lang_types_sint_t)(tus));
			mk_lang_assert(transferred <= size);
			err = mk_iip_cp_connection_impl_buffer_rw_pop_front_many(&connection_impl->m_snd_buf, transferred); mk_lang_check_rereturn(err);
			err = mk_iip_cp_connection_impl_buffer_rw_reset_if_possible(&connection_impl->m_snd_buf); mk_lang_check_rereturn(err);
			connection_impl->m_has_write_iorp = mk_lang_false;
			connection_impl->m_did_something = mk_lang_true;
		}
		else
		{
			mk_lang_check_todo();
		}
	}
	return 0;
}

#include "mk_iip_cp_connection_impl_cmd_connect_filec.h"
#include "mk_iip_cp_connection_impl_cmd_create_session_filec.h"
#include "mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_filec.h"
#include "mk_iip_cp_connection_impl_cmd_host_lookup_filec.h"
#include "mk_iip_cp_connection_impl_cmd_accept_filec.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_pt const cmd) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd);

	switch(cmd->m_type)
	{
		case mk_iip_cp_connection_impl_cmd_type_e_connect             : err = mk_iip_cp_connection_impl_pr_tick_cmd_connect             (connection_impl, &cmd->m_mix.m_data.m_connect             ); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_type_e_create_session      : err = mk_iip_cp_connection_impl_pr_tick_cmd_create_session      (connection_impl, &cmd->m_mix.m_data.m_create_session      ); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_type_e_get_bandwidth_limits: err = mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits(connection_impl, &cmd->m_mix.m_data.m_get_bandwidth_limits); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_type_e_host_lookup         : err = mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup         (connection_impl, &cmd->m_mix.m_data.m_host_lookup         ); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_type_e_accept              : err = mk_iip_cp_connection_impl_pr_tick_cmd_accept              (connection_impl, &cmd->m_mix.m_data.m_accept         ); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_type_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmds(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_iip_cp_connection_impl_cmd_pt cmd;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_did_something);

	n = mk_iip_cp_connection_impl_cmds_rw_size(&connection_impl->m_cmds);
	for(i = 0; i != n; ++i)
	{
		++connection_impl->m_sub_item_idx;
		idx = connection_impl->m_sub_item_idx;
		idx = idx % n;
		cmd = mk_iip_cp_connection_impl_cmds_rw_at(&connection_impl->m_cmds, idx); mk_lang_assert(cmd);
		err = mk_iip_cp_connection_impl_pr_tick_cmd(connection_impl, cmd); mk_lang_check_rereturn(err);
		if(connection_impl->m_did_something)
		{
			break;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_session(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_session_intr_pt const session) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(session);
	mk_lang_assert(!connection_impl->m_did_something);

	if(!connection_impl->m_has_write_iorp)
	{
		err = mk_iip_cp_session_intr_rw_make_msg(session, &connection_impl->m_message); mk_lang_check_rereturn(err);
		if(mk_iip_cp_session_intr_rw_did_something(session))
		{
			err = mk_iip_cp_connection_impl_pr_send_message(connection_impl); mk_lang_check_rereturn(err);
			connection_impl->m_did_something = mk_lang_true;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_sessions(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_iip_cp_session_intr_pt session;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_did_something);

	n = mk_iip_cp_session_intrs_rw_size(&connection_impl->m_sessions);
	for(i = 0; i != n; ++i)
	{
		++connection_impl->m_sub_item_idx;
		idx = connection_impl->m_sub_item_idx;
		idx = idx % n;
		session = mk_iip_cp_session_intrs_rw_at(&connection_impl->m_sessions, idx); mk_lang_assert(session);
		err = mk_iip_cp_connection_impl_pr_tick_session(connection_impl, session); mk_lang_check_rereturn(err);
		if(connection_impl->m_did_something)
		{
			break;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_rcv_buf(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_did_something);

	if((!connection_impl->m_has_read_iorp && !mk_iip_cp_connection_impl_buffer_ro_is_empty(&connection_impl->m_rcv_buf)) || (connection_impl->m_has_read_iorp && mk_iip_cp_connection_impl_buffer_ro_size(&connection_impl->m_rcv_buf) > mk_iip_cp_connection_impl_pr_grow_count))
	{
		err = mk_iip_cp_connection_impl_pr_parse_message(connection_impl); mk_lang_check_rereturn(err);
		switch(connection_impl->m_errcodep)
		{
			case mk_iip_cp_message_parse_errcode_e_ok:
			{
				err = mk_iip_cp_connection_impl_pr_rerequest_read_full(connection_impl); mk_lang_check_rereturn(err);
				err = mk_iip_cp_connection_impl_rw_on_msg(connection_impl); mk_lang_check_rereturn(err);
			}
			break;
			default:
			{
				mk_lang_check_todo(); /* issue new read request */
			}
			break;
		}
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_tick_single(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);

	connection_impl->m_did_something = mk_lang_false;
	if(!mk_iip_cp_connection_impl_rw_did_something(connection_impl)){ err = mk_iip_cp_connection_impl_pr_tick_cmds    (connection_impl); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_connection_impl_rw_did_something(connection_impl)){ err = mk_iip_cp_connection_impl_pr_tick_sessions(connection_impl); mk_lang_check_rereturn(err); }
	if(!mk_iip_cp_connection_impl_rw_did_something(connection_impl)){ err = mk_iip_cp_connection_impl_pr_tick_rcv_buf (connection_impl); mk_lang_check_rereturn(err); }
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmds_force(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(!connection_impl->m_did_something);
	mk_lang_assert(!connection_impl->m_force);

	connection_impl->m_force = mk_lang_true;
	err = mk_iip_cp_connection_impl_rw_tick_single(connection_impl); mk_lang_check_rereturn(err);
	connection_impl->m_force = mk_lang_false;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_tick_force(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);

	connection_impl->m_did_something = mk_lang_false;
	err = mk_iip_cp_connection_impl_pr_tick_cmds_force(connection_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_connect_to_i2cp(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_client_data_request_connect_pct const request, mk_iip_cp_client_data_response_connect_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_connection_impl_cmd_pt cmd;
	mk_iip_cp_connection_impl_cmd_connect_pt cmd_connect;

	mk_lang_assert(connection_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	err = mk_iip_cp_connection_impl_cmds_rw_push_back_void_one(&connection_impl->m_cmds); mk_lang_check_rereturn(err);
	cmd = mk_iip_cp_connection_impl_cmds_rw_back(&connection_impl->m_cmds); mk_lang_assert(cmd);
	cmd->m_type = mk_iip_cp_connection_impl_cmd_type_e_connect;
	cmd_connect = &cmd->m_mix.m_data.m_connect;
	cmd_connect->m_stage = mk_iip_cp_connection_impl_cmd_connect_stage_e_connect_request;
	cmd_connect->m_request = request;
	cmd_connect->m_response = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_create_session(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_client_data_request_create_session_pct const request, mk_iip_cp_client_data_response_create_session_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_connection_impl_cmd_pt cmd;
	mk_iip_cp_connection_impl_cmd_create_session_pt cmd_create_session;

	mk_lang_assert(connection_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	err = mk_iip_cp_connection_impl_cmds_rw_push_back_void_one(&connection_impl->m_cmds); mk_lang_check_rereturn(err);
	cmd = mk_iip_cp_connection_impl_cmds_rw_back(&connection_impl->m_cmds); mk_lang_assert(cmd);
	cmd->m_type = mk_iip_cp_connection_impl_cmd_type_e_create_session;
	cmd_create_session = &cmd->m_mix.m_data.m_create_session;
	cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_session_send;
	cmd_create_session->m_request = request;
	cmd_create_session->m_response = response;
	cmd_create_session->m_at_least_one = mk_lang_false;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_get_bandwidth_limits(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_client_data_request_get_bandwidth_limits_pct const request, mk_iip_cp_client_data_response_get_bandwidth_limits_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_connection_impl_cmd_pt cmd;
	mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_pt cmd_get_bandwidth_limits;

	mk_lang_assert(connection_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	err = mk_iip_cp_connection_impl_cmds_rw_push_back_void_one(&connection_impl->m_cmds); mk_lang_check_rereturn(err);
	cmd = mk_iip_cp_connection_impl_cmds_rw_back(&connection_impl->m_cmds); mk_lang_assert(cmd);
	cmd->m_type = mk_iip_cp_connection_impl_cmd_type_e_get_bandwidth_limits;
	cmd_get_bandwidth_limits = &cmd->m_mix.m_data.m_get_bandwidth_limits;
	cmd_get_bandwidth_limits->m_stage = mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_get_bandwidth_limits_send;
	cmd_get_bandwidth_limits->m_request = request;
	cmd_get_bandwidth_limits->m_response = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_host_lookup(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_client_data_request_host_lookup_pct const request, mk_iip_cp_client_data_response_host_lookup_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_connection_impl_cmd_pt cmd;
	mk_iip_cp_connection_impl_cmd_host_lookup_pt cmd_host_lookup;

	mk_lang_assert(connection_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	err = mk_iip_cp_connection_impl_cmds_rw_push_back_void_one(&connection_impl->m_cmds); mk_lang_check_rereturn(err);
	cmd = mk_iip_cp_connection_impl_cmds_rw_back(&connection_impl->m_cmds); mk_lang_assert(cmd);
	cmd->m_type = mk_iip_cp_connection_impl_cmd_type_e_host_lookup;
	cmd_host_lookup = &cmd->m_mix.m_data.m_host_lookup;
	cmd_host_lookup->m_stage = mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_lookup_send;
	cmd_host_lookup->m_request = request;
	cmd_host_lookup->m_response = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_accept(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_client_data_request_accept_pct const request, mk_iip_cp_client_data_response_accept_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_connection_impl_cmd_pt cmd;
	mk_iip_cp_connection_impl_cmd_accept_pt cmd_accept;

	mk_lang_assert(connection_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	err = mk_iip_cp_connection_impl_cmds_rw_push_back_void_one(&connection_impl->m_cmds); mk_lang_check_rereturn(err);
	cmd = mk_iip_cp_connection_impl_cmds_rw_back(&connection_impl->m_cmds); mk_lang_assert(cmd);
	cmd->m_type = mk_iip_cp_connection_impl_cmd_type_e_accept;
	cmd_accept = &cmd->m_mix.m_data.m_accept;
	cmd_accept->m_stage = mk_iip_cp_connection_impl_cmd_accept_stage_e_accept_send;
	cmd_accept->m_request = request;
	cmd_accept->m_response = response;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_read_data(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_client_data_request_read_data_pct const request, mk_iip_cp_client_data_response_read_data_pt const response) mk_lang_noexcept
{
	mk_iip_cp_session_intr_pt session;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(request);
	mk_lang_assert(response);

	session = request->m_session;
	err = mk_iip_cp_session_intr_rw_read_data(session, request, response); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_rw_get_bandwidth_limits_internal(mk_iip_cp_connection_impl_pt const connection_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);

	connection_impl->m_request_get_bandwidth_limits_internal.m_connection = connection_impl->m_connection_intr;
	connection_impl->m_request_get_bandwidth_limits_internal.m_bandwidth_limits = &connection_impl->m_bandwidth_limits;
	err = mk_iip_cp_connection_impl_rw_get_bandwidth_limits(connection_impl, &connection_impl->m_request_get_bandwidth_limits_internal, &connection_impl->m_response_get_bandwidth_limits_internal); mk_lang_check_rereturn(err);
	return 0;
}


#endif
