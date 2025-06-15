#ifndef mk_include_guard_mk_iip_cp_connection_impl_cmd_connect_filec_h
#define mk_include_guard_mk_iip_cp_connection_impl_cmd_connect_filec_h
#include "mk_iip_cp_connection_impl.c"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_connect_connect_request(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_connect_pt const cmd_connect) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_connect);
	mk_lang_assert(cmd_connect->m_stage == mk_iip_cp_connection_impl_cmd_connect_stage_e_connect_request);

	err = mk_sl_net_windows_destination_construct_ipv4(&connection_impl->m_ip_destination, &cmd_connect->m_request->m_ipv4_str_buf[0], cmd_connect->m_request->m_tcp_port_str_buf); mk_lang_check_rereturn(err);
	err = mk_sl_io_async_iocp_windows_associate_sck(connection_impl->m_iocp, &connection_impl->m_socket, ((mk_lang_types_usize_t)(((mk_win_base_uintptr_t)(&connection_impl->m_socket))))); mk_lang_check_rereturn(err);
	err = mk_sl_net_windows_socket_connect(&connection_impl->m_socket, &connection_impl->m_ip_destination, &connection_impl->m_connect_ctx); mk_lang_check_rereturn(err);
	cmd_connect->m_stage = mk_iip_cp_connection_impl_cmd_connect_stage_e_connect_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_connect_connect_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_connect_pt const cmd_connect) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_connect);
	mk_lang_assert(cmd_connect->m_stage == mk_iip_cp_connection_impl_cmd_connect_stage_e_connect_wait);

	if(connection_impl->m_force)
	{
		err = mk_sl_net_windows_ctx_connect_wait(&connection_impl->m_connect_ctx); mk_lang_check_rereturn(err);
		cmd_connect->m_stage = mk_iip_cp_connection_impl_cmd_connect_stage_e_protocol_byte_send;
		connection_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_connect_protocol_byte_send(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_connect_pt const cmd_connect) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_cui_uint8_pt buf;
	mk_lang_types_uchar_t tuc;
	mk_lang_types_usize_t tus;
	mk_lang_types_sint_t len;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_connect);
	mk_lang_assert(!connection_impl->m_has_write_iorp);
	mk_lang_assert(cmd_connect->m_stage == mk_iip_cp_connection_impl_cmd_connect_stage_e_protocol_byte_send);

	err = mk_iip_cp_connection_impl_buffer_rw_push_back_void_many(&connection_impl->m_snd_buf, 1); mk_lang_check_rereturn(err);
	buf = mk_iip_cp_connection_impl_buffer_rw_parta_buf(&connection_impl->m_snd_buf); mk_lang_assert(buf);
	tuc = 0x2a; mk_sl_cui_uint8_from_bi_uchar(&buf[0], &tuc);
	tus = mk_iip_cp_connection_impl_buffer_rw_size(&connection_impl->m_snd_buf); len = ((mk_lang_types_sint_t)(tus));
	err = mk_sl_net_windows_iorpw_reconstruct(&connection_impl->m_iorpw, buf, len); mk_lang_check_rereturn(err);
	err = mk_sl_net_windows_socket_request_write(&connection_impl->m_socket, &connection_impl->m_iorpw); mk_lang_check_rereturn(err);
	connection_impl->m_has_write_iorp = mk_lang_true;
	cmd_connect->m_stage = mk_iip_cp_connection_impl_cmd_connect_stage_e_protocol_byte_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_connect_protocol_byte_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_connect_pt const cmd_connect) mk_lang_noexcept
{
	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_connect);
	mk_lang_assert(cmd_connect->m_stage == mk_iip_cp_connection_impl_cmd_connect_stage_e_protocol_byte_wait);

	if(mk_iip_cp_connection_impl_pr_is_all_sent(connection_impl))
	{
		cmd_connect->m_stage = mk_iip_cp_connection_impl_cmd_connect_stage_e_get_date_send;
		connection_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_connect_get_date_send(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_connect_pt const cmd_connect) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_connect_pct request;
	mk_iip_cp_message_pt message;
	mk_lang_types_sint_t err;
	mk_iip_cp_message_get_date_pt msg_get_date;
	mk_iip_cp_type_strpair_pt strs;
	mk_iip_cp_type_string_pt name_key;
	mk_iip_cp_type_string_pt name_val;
	mk_iip_cp_type_string_pt pass_key;
	mk_iip_cp_type_string_pt pass_val;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_connect);
	mk_lang_assert(cmd_connect->m_stage == mk_iip_cp_connection_impl_cmd_connect_stage_e_get_date_send);
	mk_lang_assert(cmd_connect->m_request);

	request = cmd_connect->m_request;
	message = &connection_impl->m_message;
	err = mk_iip_cp_message_reconstruct(message, mk_iip_cp_message_message_type_e_get_date); mk_lang_check_rereturn(err);
	msg_get_date = &message->m_mix.m_data.m_get_date;
	msg_get_date->m_client_version.m_len = 0;
	if(request->m_username_str_len != 0)
	{
		err = mk_iip_cp_type_strpairs_rw_push_back_void_many(&msg_get_date->m_authentication.m_strpairs, 2); mk_lang_check_rereturn(err);
		strs = mk_iip_cp_type_strpairs_rw_data(&msg_get_date->m_authentication.m_strpairs); mk_lang_assert(strs);
		name_key = &strs[0].m_key;
		name_val = &strs[0].m_val;
		pass_key = &strs[1].m_key;
		pass_val = &strs[1].m_val;
		name_key->m_len = mk_iip_cp_message_mapping_key_get_date_username_str_len;
		mk_lang_string_memcpy_pc_fn(&name_key->m_buf[0], &mk_iip_cp_message_mapping_key_get_date_username_str_buf[0], mk_iip_cp_message_mapping_key_get_date_username_str_len);
		name_val->m_len = request->m_username_str_len;
		mk_lang_string_memcpy_pc_fn(&name_val->m_buf[0], request->m_username_str_buf, request->m_username_str_len);
		pass_key->m_len = mk_iip_cp_message_mapping_key_get_date_password_str_len;
		mk_lang_string_memcpy_pc_fn(&pass_key->m_buf[0], &mk_iip_cp_message_mapping_key_get_date_password_str_buf[0], mk_iip_cp_message_mapping_key_get_date_password_str_len);
		pass_val->m_len = request->m_password_str_len;
		mk_lang_string_memcpy_pc_fn(&pass_val->m_buf[0], request->m_password_str_buf, request->m_password_str_len);
	}
	err = mk_iip_cp_connection_impl_pr_send_message(connection_impl); mk_lang_check_rereturn(err);
	cmd_connect->m_stage = mk_iip_cp_connection_impl_cmd_connect_stage_e_get_date_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_connect_get_date_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_connect_pt const cmd_connect) mk_lang_noexcept
{
	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_connect);
	mk_lang_assert(cmd_connect->m_stage == mk_iip_cp_connection_impl_cmd_connect_stage_e_get_date_wait);

	if(mk_iip_cp_connection_impl_pr_is_all_sent(connection_impl))
	{
		cmd_connect->m_stage = mk_iip_cp_connection_impl_cmd_connect_stage_e_set_date_recv;
		connection_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_connect_set_date_recv(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_connect_pt const cmd_connect) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_connect);
	mk_lang_assert(!connection_impl->m_has_read_iorp);
	mk_lang_assert(cmd_connect->m_stage == mk_iip_cp_connection_impl_cmd_connect_stage_e_set_date_recv);

	err = mk_iip_cp_connection_impl_pr_request_read_full(connection_impl); mk_lang_check_rereturn(err);
	cmd_connect->m_stage = mk_iip_cp_connection_impl_cmd_connect_stage_e_set_date_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_connect_set_date_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_connect_pt const cmd_connect) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_response_connect_pt response;
	mk_iip_cp_message_set_date_pt msg_set_date;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_connect);
	mk_lang_assert(cmd_connect->m_stage == mk_iip_cp_connection_impl_cmd_connect_stage_e_set_date_wait);
	mk_lang_assert(cmd_connect->m_response);

	if((!connection_impl->m_has_read_iorp && !mk_iip_cp_connection_impl_buffer_ro_is_empty(&connection_impl->m_rcv_buf)) || (connection_impl->m_has_read_iorp && mk_iip_cp_connection_impl_buffer_ro_size(&connection_impl->m_rcv_buf) > mk_iip_cp_connection_impl_pr_grow_count))
	{
		err = mk_iip_cp_connection_impl_pr_parse_message(connection_impl); mk_lang_check_rereturn(err);
		if(connection_impl->m_errcodep == mk_iip_cp_message_parse_errcode_e_ok)
		{
			err = mk_iip_cp_connection_impl_pr_rerequest_read_full(connection_impl); mk_lang_check_rereturn(err);
			mk_lang_assert(connection_impl->m_message.m_header.m_type == mk_iip_cp_message_message_type_e_set_date);
			response = cmd_connect->m_response;
			msg_set_date = &connection_impl->m_message.m_mix.m_data.m_set_date;
			response->m_connection = connection_impl->m_connection_intr;
			connection_impl->m_server_date_val = msg_set_date->m_server_date;
			connection_impl->m_server_version = msg_set_date->m_server_version;
			mk_iip_cp_helper_get_time_now(&connection_impl->m_server_date_now.m_ms_since_unix);
			response->m_success = mk_lang_true;
			cmd_connect->m_stage = mk_iip_cp_connection_impl_cmd_connect_stage_e_finish;
			connection_impl->m_did_something = mk_lang_true;
		}
		else
		{
			mk_lang_check_todo(); /* issue new read request */
		}
	}
	else
	{
		mk_lang_assert(connection_impl->m_has_read_iorp);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_connect_finish(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_connect_pt const cmd_connect) mk_lang_noexcept
{
	mk_iip_cp_client_data_response_connect_pt response;
	mk_iip_cp_connection_impl_cmd_pt cmd;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_connect);
	mk_lang_assert(cmd_connect->m_stage == mk_iip_cp_connection_impl_cmd_connect_stage_e_finish);
	mk_lang_assert(cmd_connect->m_response);

	response = cmd_connect->m_response;
	response->m_done = mk_lang_true;
	cmd = ((mk_iip_cp_connection_impl_cmd_pt)(((mk_lang_types_uchar_pt)(cmd_connect)) - mk_lang_offsetof(mk_iip_cp_connection_impl_cmd_t, m_mix)));
	mk_lang_assert(cmd->m_type == mk_iip_cp_connection_impl_cmd_type_e_connect);
	mk_lang_assert(&cmd->m_mix.m_data.m_connect == cmd_connect);
	err = mk_iip_cp_connection_impl_cmds_rw_erase_element(&connection_impl->m_cmds, cmd); mk_lang_check_rereturn(err);
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_connect(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_connect_pt const cmd_connect) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_connect);

	switch(cmd_connect->m_stage)
	{
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_connect_request   : err = mk_iip_cp_connection_impl_pr_tick_cmd_connect_connect_request   (connection_impl, cmd_connect); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_connect_wait      : err = mk_iip_cp_connection_impl_pr_tick_cmd_connect_connect_wait      (connection_impl, cmd_connect); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_protocol_byte_send: err = mk_iip_cp_connection_impl_pr_tick_cmd_connect_protocol_byte_send(connection_impl, cmd_connect); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_protocol_byte_wait: err = mk_iip_cp_connection_impl_pr_tick_cmd_connect_protocol_byte_wait(connection_impl, cmd_connect); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_get_date_send     : err = mk_iip_cp_connection_impl_pr_tick_cmd_connect_get_date_send     (connection_impl, cmd_connect); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_get_date_wait     : err = mk_iip_cp_connection_impl_pr_tick_cmd_connect_get_date_wait     (connection_impl, cmd_connect); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_set_date_recv     : err = mk_iip_cp_connection_impl_pr_tick_cmd_connect_set_date_recv     (connection_impl, cmd_connect); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_set_date_wait     : err = mk_iip_cp_connection_impl_pr_tick_cmd_connect_set_date_wait     (connection_impl, cmd_connect); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_finish            : err = mk_iip_cp_connection_impl_pr_tick_cmd_connect_finish            (connection_impl, cmd_connect); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}


#endif
