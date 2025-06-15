#ifndef mk_include_guard_mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_filec_h
#define mk_include_guard_mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_filec_h
#include "mk_iip_cp_connection_impl.c"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits_get_bandwidth_limits_send(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_pt const cmd_get_bandwidth_limits) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_get_bandwidth_limits_pct request;
	mk_iip_cp_client_data_response_get_bandwidth_limits_pt response;
	mk_lang_types_sint_t err;
	mk_iip_cp_message_get_bandwidth_limits_pt msg_get_bandwidth_limits;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_get_bandwidth_limits);
	mk_lang_assert(cmd_get_bandwidth_limits->m_stage == mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_get_bandwidth_limits_send);
	mk_lang_assert(cmd_get_bandwidth_limits->m_request);
	mk_lang_assert(cmd_get_bandwidth_limits->m_response);
	mk_lang_assert(cmd_get_bandwidth_limits->m_request->m_connection);

	request = cmd_get_bandwidth_limits->m_request;
	response = cmd_get_bandwidth_limits->m_response;
	err = mk_iip_cp_message_reconstruct(&connection_impl->m_message, mk_iip_cp_message_message_type_e_get_bandwidth_limits); mk_lang_check_rereturn(err);
	msg_get_bandwidth_limits = &connection_impl->m_message.m_mix.m_data.m_get_bandwidth_limits;
	err = mk_iip_cp_connection_impl_pr_send_message(connection_impl); mk_lang_check_rereturn(err);
	cmd_get_bandwidth_limits->m_stage = mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_get_bandwidth_limits_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits_get_bandwidth_limits_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_pt const cmd_get_bandwidth_limits) mk_lang_noexcept
{
	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_get_bandwidth_limits);
	mk_lang_assert(cmd_get_bandwidth_limits->m_stage == mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_get_bandwidth_limits_wait);

	if(mk_iip_cp_connection_impl_pr_is_all_sent(connection_impl))
	{
		cmd_get_bandwidth_limits->m_stage = mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_bandwidth_limits_recv;
		connection_impl->m_did_something = mk_lang_true;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits_bandwidth_limits_recv(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_pt const cmd_get_bandwidth_limits) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_get_bandwidth_limits);
	mk_lang_assert(cmd_get_bandwidth_limits->m_stage == mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_bandwidth_limits_recv);

	err = mk_iip_cp_connection_impl_pr_request_read_full_if_possible(connection_impl); mk_lang_check_rereturn(err);
	cmd_get_bandwidth_limits->m_stage = mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_bandwidth_limits_wait;
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits_bandwidth_limits_wait(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_pt const cmd_get_bandwidth_limits) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_iip_cp_client_data_request_get_bandwidth_limits_pct request;
	mk_iip_cp_client_data_response_get_bandwidth_limits_pt response;
	mk_iip_cp_message_bandwidth_limits_pt msg_bandwidth_limits;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_get_bandwidth_limits);
	mk_lang_assert(cmd_get_bandwidth_limits->m_stage == mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_bandwidth_limits_wait);
	mk_lang_assert(cmd_get_bandwidth_limits->m_request);
	mk_lang_assert(cmd_get_bandwidth_limits->m_response);

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
					case mk_iip_cp_message_message_type_e_bandwidth_limits:
					{
						request = cmd_get_bandwidth_limits->m_request;
						response = cmd_get_bandwidth_limits->m_response;
						msg_bandwidth_limits = &connection_impl->m_message.m_mix.m_data.m_bandwidth_limits;
						*request->m_bandwidth_limits = msg_bandwidth_limits->m_bandwidth_limits;
						cmd_get_bandwidth_limits->m_stage = mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_finish;
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits_finish(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_pt const cmd_get_bandwidth_limits) mk_lang_noexcept
{
	mk_iip_cp_client_data_response_get_bandwidth_limits_pt response;
	mk_iip_cp_connection_impl_cmd_pt cmd;
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_get_bandwidth_limits);
	mk_lang_assert(cmd_get_bandwidth_limits->m_stage == mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_finish);

	response = cmd_get_bandwidth_limits->m_response;
	response->m_success = mk_lang_true;
	response->m_done = mk_lang_true;
	cmd = ((mk_iip_cp_connection_impl_cmd_pt)(((mk_lang_types_uchar_pt)(cmd_get_bandwidth_limits)) - mk_lang_offsetof(mk_iip_cp_connection_impl_cmd_t, m_mix)));
	mk_lang_assert(cmd->m_type == mk_iip_cp_connection_impl_cmd_type_e_get_bandwidth_limits);
	mk_lang_assert(&cmd->m_mix.m_data.m_get_bandwidth_limits == cmd_get_bandwidth_limits);
	err = mk_iip_cp_connection_impl_cmds_rw_erase_element(&connection_impl->m_cmds, cmd); mk_lang_check_rereturn(err);
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_pt const cmd_get_bandwidth_limits) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_get_bandwidth_limits);

	switch(cmd_get_bandwidth_limits->m_stage)
	{
		case mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_get_bandwidth_limits_send: err = mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits_get_bandwidth_limits_send(connection_impl, cmd_get_bandwidth_limits); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_get_bandwidth_limits_wait: err = mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits_get_bandwidth_limits_wait(connection_impl, cmd_get_bandwidth_limits); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_bandwidth_limits_recv    : err = mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits_bandwidth_limits_recv    (connection_impl, cmd_get_bandwidth_limits); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_bandwidth_limits_wait    : err = mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits_bandwidth_limits_wait    (connection_impl, cmd_get_bandwidth_limits); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_finish                   : err = mk_iip_cp_connection_impl_pr_tick_cmd_get_bandwidth_limits_finish                   (connection_impl, cmd_get_bandwidth_limits); mk_lang_check_rereturn(err); break;
		case mk_iip_cp_connection_impl_cmd_get_bandwidth_limits_stage_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}


#endif
