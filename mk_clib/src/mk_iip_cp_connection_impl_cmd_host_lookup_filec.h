#ifndef mk_include_guard_mk_iip_cp_connection_impl_cmd_host_lookup_filec_h
#define mk_include_guard_mk_iip_cp_connection_impl_cmd_host_lookup_filec_h
#include "mk_iip_cp_connection_impl.c"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup_host_lookup_send(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_host_lookup_pt const cmd_host_lookup) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_host_lookup_pct request;
	mk_iip_cp_client_data_response_host_lookup_pt response;
	mk_iip_cp_session_intr_pt session;
	mk_lang_types_sint_t err;
	mk_iip_cp_message_host_lookup_pt msg_host_lookup;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_host_lookup);
	mk_lang_assert(cmd_host_lookup->m_stage == mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_lookup_send);
	mk_lang_assert(cmd_host_lookup->m_request);
	mk_lang_assert(cmd_host_lookup->m_response);
	mk_lang_assert(cmd_host_lookup->m_request->m_connection);
	mk_lang_assert(cmd_host_lookup->m_request->m_session);
	mk_lang_assert(cmd_host_lookup->m_request->m_hostname);
	mk_lang_assert(cmd_host_lookup->m_request->m_destination);
	mk_lang_assert(cmd_host_lookup->m_request->m_hostname->m_len >= 1);
	mk_lang_assert(cmd_host_lookup->m_request->m_hostname->m_buf[0] != '\0');

	request = cmd_host_lookup->m_request;
	response = cmd_host_lookup->m_response;
	session = request->m_session;
	err = mk_iip_cp_message_reconstruct(&connection_impl->m_message, mk_iip_cp_message_message_type_e_host_lookup); mk_lang_check_rereturn(err);
	msg_host_lookup = &connection_impl->m_message.m_mix.m_data.m_host_lookup;
	msg_host_lookup->m_session_id = *mk_iip_cp_session_intr_rw_get_session_id(session);
	mk_iip_cp_helper_generate_random_u32(&cmd_host_lookup->m_request_id); msg_host_lookup->m_request_id = cmd_host_lookup->m_request_id;
	msg_host_lookup->m_timeout_ms = 1 * 24 * 60 * 60 * 1000;
	msg_host_lookup->m_request_type = mk_iip_cp_message_host_lookup_request_type_e_name;
	msg_host_lookup->m_hostname = *request->m_hostname;
	err = mk_iip_cp_connection_impl_pr_send_message(connection_impl); mk_lang_check_rereturn(err);
	cmd_host_lookup->m_stage = mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_lookup_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup_host_lookup_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_host_lookup_pt const cmd_host_lookup) mk_lang_noexcept
{
	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_host_lookup);
	mk_lang_assert(cmd_host_lookup->m_stage == mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_lookup_wait);

	if(mk_iip_cp_connection_impl_pr_is_all_sent(connection_impl))
	{
		cmd_host_lookup->m_stage = mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_reply_recv;
		connection_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup_host_reply_recv(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_host_lookup_pt const cmd_host_lookup) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_host_lookup);
	mk_lang_assert(cmd_host_lookup->m_stage == mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_reply_recv);

	err = mk_iip_cp_connection_impl_pr_request_read_full_if_possible(connection_impl); mk_lang_check_rereturn(err);
	cmd_host_lookup->m_stage = mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_reply_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup_host_reply_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_host_lookup_pt const cmd_host_lookup) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_request_host_lookup_pct request;
	mk_iip_cp_client_data_response_host_lookup_pt response;
	mk_iip_cp_message_host_reply_pt msg_host_reply;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_host_lookup);
	mk_lang_assert(cmd_host_lookup->m_stage == mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_reply_wait);
	mk_lang_assert(cmd_host_lookup->m_request);
	mk_lang_assert(cmd_host_lookup->m_response);

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
					case mk_iip_cp_message_message_type_e_host_reply:
					{
						request = cmd_host_lookup->m_request;
						response = cmd_host_lookup->m_response;
						msg_host_reply = &connection_impl->m_message.m_mix.m_data.m_host_reply;
						mk_lang_assert(mk_iip_cp_session_intr_rw_get_session_id(request->m_session));
						if(mk_sl_cui_uint16_eq(&msg_host_reply->m_session_id.m_id, &mk_iip_cp_session_intr_rw_get_session_id(request->m_session)->m_id))
						{
							if(mk_sl_cui_uint32_eq(&msg_host_reply->m_request_id, &cmd_host_lookup->m_request_id))
							{
								if(msg_host_reply->m_result_code == mk_iip_cp_message_host_reply_result_code_e_success)
								{
									response->m_success = mk_lang_true;
									request->m_destination->m_len = msg_host_reply->m_destination.m_len;
									mk_sl_cui_uint8_memcpy(&request->m_destination->m_buf[0], &msg_host_reply->m_destination.m_buf[0], msg_host_reply->m_destination.m_len);
									cmd_host_lookup->m_stage = mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_finish;
									connection_impl->m_did_something = mk_lang_true;
								}
								else
								{
									/* todo reason for failure */
									response->m_success = mk_lang_false;
									cmd_host_lookup->m_stage = mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_finish;
									connection_impl->m_did_something = mk_lang_true;
								}
							}
							else
							{
								mk_lang_check_todo();
							}
						}
						else
						{
							mk_lang_check_todo();
						}
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup_finish(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_host_lookup_pt const cmd_host_lookup) mk_lang_noexcept
{
	mk_iip_cp_client_data_response_host_lookup_pt response;
	mk_iip_cp_connection_impl_cmd_pt cmd;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_host_lookup);
	mk_lang_assert(cmd_host_lookup->m_stage == mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_finish);

	response = cmd_host_lookup->m_response;
	response->m_done = mk_lang_true;
	cmd = ((mk_iip_cp_connection_impl_cmd_pt)(((mk_lang_types_uchar_pt)(cmd_host_lookup)) - mk_lang_offsetof(mk_iip_cp_connection_impl_cmd_t, m_mix)));
	mk_lang_assert(cmd->m_type == mk_iip_cp_connection_impl_cmd_type_e_host_lookup);
	mk_lang_assert(&cmd->m_mix.m_data.m_host_lookup == cmd_host_lookup);
	err = mk_iip_cp_connection_impl_cmds_rw_erase_element(&connection_impl->m_cmds, cmd); mk_lang_check_rereturn(err);
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_host_lookup_pt const cmd_host_lookup) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_host_lookup);

	switch(cmd_host_lookup->m_stage)
	{
		case mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_lookup_send: err = mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup_host_lookup_send(connection_impl, cmd_host_lookup); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_lookup_wait: err = mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup_host_lookup_wait(connection_impl, cmd_host_lookup); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_reply_recv : err = mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup_host_reply_recv (connection_impl, cmd_host_lookup); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_host_reply_wait : err = mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup_host_reply_wait (connection_impl, cmd_host_lookup); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_finish          : err = mk_iip_cp_connection_impl_pr_tick_cmd_host_lookup_finish          (connection_impl, cmd_host_lookup); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_host_lookup_stage_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}


#endif
