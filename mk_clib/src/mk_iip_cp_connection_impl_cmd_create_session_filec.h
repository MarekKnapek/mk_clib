#ifndef mk_include_guard_mk_iip_cp_connection_impl_cmd_create_session_filec_h
#define mk_include_guard_mk_iip_cp_connection_impl_cmd_create_session_filec_h
#include "mk_iip_cp_connection_impl.c"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_create_session_create_session_send(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_create_session_pt const cmd_create_session) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_create_session_pct request;
	mk_iip_cp_message_pt message;
	mk_lang_types_sint_t err;
	mk_iip_cp_message_create_session_pt msg_create_session;
	mk_iip_cp_type_strpair_pt strs;
	mk_iip_cp_type_string_pt in_key;
	mk_iip_cp_type_string_pt in_val;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_create_session);
	mk_lang_assert(cmd_create_session->m_stage == mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_session_send);
	mk_lang_assert(cmd_create_session->m_request);
	mk_lang_assert(cmd_create_session->m_request->m_destination);

	request = cmd_create_session->m_request;
	message = &connection_impl->m_message;
	err = mk_iip_cp_message_reconstruct(message, mk_iip_cp_message_message_type_e_create_session); mk_lang_check_rereturn(err);
	msg_create_session = &message->m_mix.m_data.m_create_session;
	msg_create_session->m_session_config.m_destination = *request->m_destination;
	if(request->m_nickname_str_len != 0)
	{
		err = mk_iip_cp_type_strpairs_rw_setsize_dy(&msg_create_session->m_session_config.m_options.m_strpairs, 1); mk_lang_check_rereturn(err);
		strs = mk_iip_cp_type_strpairs_rw_data(&msg_create_session->m_session_config.m_options.m_strpairs); mk_lang_assert(strs);
		in_key = &strs[0].m_key;
		in_val = &strs[0].m_val;
		in_key->m_len = mk_iip_cp_message_mapping_val_create_session_inbound_nickname_str_len;
		mk_lang_string_memcpy_pc_fn(&in_key->m_buf[0], &mk_iip_cp_message_mapping_val_create_session_inbound_nickname_str_buf[0], mk_iip_cp_message_mapping_val_create_session_inbound_nickname_str_len);
		in_val->m_len = request->m_nickname_str_len;
		mk_lang_string_memcpy_pc_fn(&in_val->m_buf[0], request->m_nickname_str_buf, request->m_nickname_str_len);
	}
	mk_iip_cp_helper_get_time_now(&msg_create_session->m_session_config.m_creation_date.m_ms_since_unix); mk_lang_assert(!mk_sl_cui_uint64_is_zero(&msg_create_session->m_session_config.m_creation_date.m_ms_since_unix));
	err = mk_iip_cp_connection_impl_pr_send_message(connection_impl); mk_lang_check_rereturn(err);
	cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_session_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_create_session_create_session_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_create_session_pt const cmd_create_session) mk_lang_noexcept
{
	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_create_session);
	mk_lang_assert(cmd_create_session->m_stage == mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_session_wait);

	if(mk_iip_cp_connection_impl_pr_is_all_sent(connection_impl))
	{
		cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_session_status_recv;
		connection_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_create_session_session_status_recv(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_create_session_pt const cmd_create_session) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_create_session);
	mk_lang_assert(cmd_create_session->m_stage == mk_iip_cp_connection_impl_cmd_create_session_stage_e_session_status_recv);

	err = mk_iip_cp_connection_impl_pr_request_read_full_if_possible(connection_impl); mk_lang_check_rereturn(err);
	cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_session_status_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_create_session_session_status_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_create_session_pt const cmd_create_session) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_request_create_session_pct request;
	mk_iip_cp_client_data_response_create_session_pt response;
	mk_iip_cp_message_session_status_pt msg_session_status;
	mk_iip_cp_session_intr_pt session;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_create_session);
	mk_lang_assert(cmd_create_session->m_stage == mk_iip_cp_connection_impl_cmd_create_session_stage_e_session_status_wait);
	mk_lang_assert(cmd_create_session->m_request);
	mk_lang_assert(cmd_create_session->m_response);

	if((!connection_impl->m_has_read_iorp && !mk_iip_cp_connection_impl_buffer_ro_is_empty(&connection_impl->m_rcv_buf)) || (connection_impl->m_has_read_iorp && mk_iip_cp_connection_impl_buffer_ro_size(&connection_impl->m_rcv_buf) > mk_iip_cp_connection_impl_pr_grow_count))
	{
		err = mk_iip_cp_connection_impl_pr_parse_message(connection_impl); mk_lang_check_rereturn(err);
		switch(connection_impl->m_errcodep)
		{
			case mk_iip_cp_message_parse_errcode_e_ok:
			{
				err = mk_iip_cp_connection_impl_pr_rerequest_read_full(connection_impl); mk_lang_check_rereturn(err);
				switch(connection_impl->m_message.m_header.m_type)
				{
					case mk_iip_cp_message_message_type_e_session_status:
					{
						request = cmd_create_session->m_request;
						response = cmd_create_session->m_response;
						msg_session_status = &connection_impl->m_message.m_mix.m_data.m_session_status;
						switch(msg_session_status->m_status)
						{
							case mk_iip_cp_message_session_status_status_e_created:
							{
								err =	mk_iip_cp_session_intrs_rw_push_back_void_one(&connection_impl->m_sessions); mk_lang_check_rereturn(err);
								session =	mk_iip_cp_session_intrs_rw_back(&connection_impl->m_sessions); mk_lang_assert(session);
								err = mk_iip_cp_session_intr_rw_set_connection(session, &connection_impl->m_connection_intr); mk_lang_check_rereturn(err);
								err = mk_iip_cp_session_intr_rw_set_session_id(session, &msg_session_status->m_session_id); mk_lang_check_rereturn(err);
								err = mk_iip_cp_session_intr_rw_set_destination(session, request->m_destination); mk_lang_check_rereturn(err);
								response->m_session = session;
								cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_request_lease_set_recv;
								connection_impl->m_did_something = mk_lang_true;
							}
							break;
							default:
							{
								mk_lang_check_todo();
							}
							break;
						}
					}
					break;
					default:
					{
						mk_lang_check_todo();
					}
					break;
				}
			}
			break;
			default:
			{
				mk_lang_check_todo(); /* issue new read request */
			}
			break;
		}
	}
	else
	{
		mk_lang_assert(connection_impl->m_has_read_iorp);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_create_session_request_lease_set_recv(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_create_session_pt const cmd_create_session) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_create_session);
	mk_lang_assert(cmd_create_session->m_stage == mk_iip_cp_connection_impl_cmd_create_session_stage_e_request_lease_set_recv);

	err = mk_iip_cp_connection_impl_pr_request_read_full_if_possible(connection_impl); mk_lang_check_rereturn(err);
	cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_request_lease_set_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_create_session_request_lease_set_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_create_session_pt const cmd_create_session) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_request_create_session_pct request;
	mk_iip_cp_client_data_response_create_session_pt response;
	mk_iip_cp_message_request_lease_set_pt msg_request_lease_set;
	mk_iip_cp_message_request_variable_lease_set_pt msg_request_variable_lease_set;
	mk_iip_cp_session_intr_pt session;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_create_session);
	mk_lang_assert(cmd_create_session->m_stage == mk_iip_cp_connection_impl_cmd_create_session_stage_e_request_lease_set_wait);
	mk_lang_assert(cmd_create_session->m_request);
	mk_lang_assert(cmd_create_session->m_response);

	if((!connection_impl->m_has_read_iorp && !mk_iip_cp_connection_impl_buffer_ro_is_empty(&connection_impl->m_rcv_buf)) || (connection_impl->m_has_read_iorp && mk_iip_cp_connection_impl_buffer_ro_size(&connection_impl->m_rcv_buf) > mk_iip_cp_connection_impl_pr_grow_count))
	{
		err = mk_iip_cp_connection_impl_pr_parse_message(connection_impl); mk_lang_check_rereturn(err);
		switch(connection_impl->m_errcodep)
		{
			case mk_iip_cp_message_parse_errcode_e_ok:
			{
				err = mk_iip_cp_connection_impl_pr_rerequest_read_full(connection_impl); mk_lang_check_rereturn(err);
				switch(connection_impl->m_message.m_header.m_type)
				{
					case mk_iip_cp_message_message_type_e_request_lease_set:
					{
						request = cmd_create_session->m_request;
						response = cmd_create_session->m_response;
						msg_request_lease_set = &connection_impl->m_message.m_mix.m_data.m_request_lease_set;
						mk_lang_assert(response->m_session);
						mk_lang_assert(mk_iip_cp_session_intr_rw_get_session_id(response->m_session));
						mk_lang_assert(mk_sl_cui_uint16_eq(&msg_request_lease_set->m_session_id.m_id, &mk_iip_cp_session_intr_rw_get_session_id(response->m_session)->m_id));
						mk_lang_assert(((err = mk_iip_cp_connection_impl_pr_sessionid_to_session(connection_impl, &msg_request_lease_set->m_session_id, &session)), mk_lang_true)); mk_lang_check_rereturn(err); mk_lang_assert(session); mk_lang_assert(session == response->m_session);
						err = mk_iip_cp_session_intr_rw_on_msg(response->m_session, &connection_impl->m_message); mk_lang_check_rereturn(err);
						cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_lease_set_send;
						connection_impl->m_did_something = mk_lang_true;
					}
					break;
					case mk_iip_cp_message_message_type_e_request_variable_lease_set:
					{
						request = cmd_create_session->m_request;
						response = cmd_create_session->m_response;
						msg_request_variable_lease_set = &connection_impl->m_message.m_mix.m_data.m_request_variable_lease_set;
						mk_lang_assert(response->m_session);
						mk_lang_assert(mk_iip_cp_session_intr_rw_get_session_id(response->m_session));
						mk_lang_assert(mk_sl_cui_uint16_eq(&msg_request_variable_lease_set->m_session_id.m_id, &mk_iip_cp_session_intr_rw_get_session_id(response->m_session)->m_id));
						mk_lang_assert(((err = mk_iip_cp_connection_impl_pr_sessionid_to_session(connection_impl, &msg_request_variable_lease_set->m_session_id, &session)), mk_lang_true)); mk_lang_check_rereturn(err); mk_lang_assert(session); mk_lang_assert(session == response->m_session);
						err = mk_iip_cp_session_intr_rw_on_msg(response->m_session, &connection_impl->m_message); mk_lang_check_rereturn(err);
						cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_lease_set_send;
						connection_impl->m_did_something = mk_lang_true;
					}
					break;
					default:
					{
						err = mk_iip_cp_connection_impl_rw_on_msg(connection_impl); mk_lang_check_rereturn(err);
					}
					break;
				}
			}
			break;
			default:
			{
				mk_lang_check_todo(); /* issue new read request */
			}
			break;
		}
	}
	else
	{
		mk_lang_assert(connection_impl->m_has_read_iorp);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_create_session_create_lease_set_send(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_create_session_pt const cmd_create_session) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_create_session_pct request;
	mk_iip_cp_client_data_response_create_session_pt response;
	mk_iip_cp_session_intr_pt session;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_create_session);
	mk_lang_assert(cmd_create_session->m_stage == mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_lease_set_send);

	request = cmd_create_session->m_request;
	response = cmd_create_session->m_response;
	session = response->m_session;
	err = mk_iip_cp_session_intr_rw_make_msg(session, &connection_impl->m_message); mk_lang_check_rereturn(err);
	if(!cmd_create_session->m_at_least_one)
	{
		mk_lang_check_return(mk_iip_cp_session_intr_rw_did_something(session));
		cmd_create_session->m_at_least_one = mk_lang_true;
	}
	if(mk_iip_cp_session_intr_rw_did_something(session))
	{
		err = mk_iip_cp_connection_impl_pr_send_message(connection_impl); mk_lang_check_rereturn(err);
		cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_lease_set_wait;
		connection_impl->m_did_something = mk_lang_true;
	}
	else
	{
		cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_finish;
		connection_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_create_session_create_lease_set_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_create_session_pt const cmd_create_session) mk_lang_noexcept
{
	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_create_session);
	mk_lang_assert(cmd_create_session->m_stage == mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_lease_set_wait);

	if(mk_iip_cp_connection_impl_pr_is_all_sent(connection_impl))
	{
		cmd_create_session->m_stage = mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_lease_set_send;
		connection_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_create_session_finish(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_create_session_pt const cmd_create_session) mk_lang_noexcept
{
	mk_iip_cp_client_data_response_create_session_pt response;
	mk_iip_cp_connection_impl_cmd_pt cmd;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_create_session);
	mk_lang_assert(cmd_create_session->m_stage == mk_iip_cp_connection_impl_cmd_create_session_stage_e_finish);

	response = cmd_create_session->m_response;
	response->m_success = mk_lang_true;
	response->m_done = mk_lang_true;
	cmd = ((mk_iip_cp_connection_impl_cmd_pt)(((mk_lang_types_uchar_pt)(cmd_create_session)) - mk_lang_offsetof(mk_iip_cp_connection_impl_cmd_t, m_mix)));
	mk_lang_assert(cmd->m_type == mk_iip_cp_connection_impl_cmd_type_e_create_session);
	mk_lang_assert(&cmd->m_mix.m_data.m_create_session == cmd_create_session);
	err = mk_iip_cp_connection_impl_cmds_rw_erase_element(&connection_impl->m_cmds, cmd); mk_lang_check_rereturn(err);
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_create_session(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_create_session_pt const cmd_create_session) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_create_session);

	switch(cmd_create_session->m_stage)
	{
		case mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_session_send   : err = mk_iip_cp_connection_impl_pr_tick_cmd_create_session_create_session_send   (connection_impl, cmd_create_session); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_session_wait   : err = mk_iip_cp_connection_impl_pr_tick_cmd_create_session_create_session_wait   (connection_impl, cmd_create_session); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_create_session_stage_e_session_status_recv   : err = mk_iip_cp_connection_impl_pr_tick_cmd_create_session_session_status_recv   (connection_impl, cmd_create_session); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_create_session_stage_e_session_status_wait   : err = mk_iip_cp_connection_impl_pr_tick_cmd_create_session_session_status_wait   (connection_impl, cmd_create_session); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_create_session_stage_e_request_lease_set_recv: err = mk_iip_cp_connection_impl_pr_tick_cmd_create_session_request_lease_set_recv(connection_impl, cmd_create_session); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_create_session_stage_e_request_lease_set_wait: err = mk_iip_cp_connection_impl_pr_tick_cmd_create_session_request_lease_set_wait(connection_impl, cmd_create_session); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_lease_set_send : err = mk_iip_cp_connection_impl_pr_tick_cmd_create_session_create_lease_set_send (connection_impl, cmd_create_session); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_create_session_stage_e_create_lease_set_wait : err = mk_iip_cp_connection_impl_pr_tick_cmd_create_session_create_lease_set_wait (connection_impl, cmd_create_session); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_create_session_stage_e_finish                : err = mk_iip_cp_connection_impl_pr_tick_cmd_create_session_finish                (connection_impl, cmd_create_session); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_connect_stage_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}


#endif
