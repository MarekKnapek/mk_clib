#ifndef mk_include_guard_mk_iip_cp_connection_impl_cmd_accept_filec_h
#define mk_include_guard_mk_iip_cp_connection_impl_cmd_accept_filec_h
#include "mk_iip_cp_connection_impl.c"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_impl_pr_tick_cmd_accept(mk_iip_cp_connection_impl_pt const connection_impl, mk_iip_cp_connection_impl_cmd_accept_pt const cmd_accept) mk_lang_noexcept
{
	mk_iip_cp_client_data_request_accept_pct request;
	mk_iip_cp_client_data_response_accept_pt response;
	mk_iip_cp_session_intr_pt session;
	mk_lang_types_sint_t err;
	mk_iip_cp_connection_impl_cmd_pt cmd;

	mk_lang_assert(connection_impl);
	mk_lang_assert(cmd_accept);
	mk_lang_assert(cmd_accept->m_request);
	mk_lang_assert(cmd_accept->m_request->m_session);
	mk_lang_assert(cmd_accept->m_response);

	request = cmd_accept->m_request;
	response = cmd_accept->m_response;
	session = request->m_session;
	err = mk_iip_cp_session_intr_rw_accept(session, request, response); mk_lang_check_rereturn(err);

	cmd = ((mk_iip_cp_connection_impl_cmd_pt)(((mk_lang_types_uchar_pt)(cmd_accept)) - mk_lang_offsetof(mk_iip_cp_connection_impl_cmd_t, m_mix)));
	mk_lang_assert(cmd->m_type == mk_iip_cp_connection_impl_cmd_type_e_accept);
	mk_lang_assert(&cmd->m_mix.m_data.m_accept == cmd_accept);
	err = mk_iip_cp_connection_impl_cmds_rw_erase_element(&connection_impl->m_cmds, cmd); mk_lang_check_rereturn(err);
	connection_impl->m_did_something = mk_lang_true;
	return 0;
}


#endif
