#ifndef mk_include_guard_mk_lib_net_forwarder_iop_target_logic_c
#define mk_include_guard_mk_lib_net_forwarder_iop_target_logic_c
#include "mk_lib_net_forwarder_iop_target_logic.h"

#include "mk_lang_assert.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_offsetof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lib_net_connector.h"
#include "mk_lib_net_forwarder_iop_target_data.h"
#include "mk_lib_net_listener.h"


mk_lang_nodiscard static mk_lang_inline mk_lib_net_listener_pt mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_listener(mk_lib_net_forwarder_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_listener_pt listener;

	//mk_lang_static_assert(mk_lang_offsetof(mk_lib_net_listener_t, m_iop_target) == 288); /* natvis */

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_forwarder_iop_target_data_id_e_dummy_end);

	if(target->m_id == mk_lib_net_forwarder_iop_target_data_id_e_listener)
	{
		offset = mk_lang_offsetof(mk_lib_net_listener_t, m_iop_target);
		listener = ((mk_lib_net_listener_pt)(((mk_lang_types_uchar_pt)(target)) - offset));
		return listener;
	}
	else
	{
		return mk_lang_null;
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lib_net_listener_client_pt mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_client(mk_lib_net_forwarder_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_listener_client_pt client;

	//mk_lang_static_assert(mk_lang_offsetof(mk_lib_net_listener_client_t, m_iop_target) == 40); /* natvis */

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_forwarder_iop_target_data_id_e_dummy_end);

	if(target->m_id == mk_lib_net_forwarder_iop_target_data_id_e_client)
	{
		offset = mk_lang_offsetof(mk_lib_net_listener_client_t, m_iop_target);
		client = ((mk_lib_net_listener_client_pt)(((mk_lang_types_uchar_pt)(target)) - offset));
		return client;
	}
	else
	{
		return mk_lang_null;
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lib_net_connector_pt mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_connector(mk_lib_net_forwarder_iop_target_data_pt const target) mk_lang_noexcept
{
	mk_lang_types_sint_t offset;
	mk_lib_net_connector_pt connector;

	//mk_lang_static_assert(mk_lang_offsetof(mk_lib_net_connector_t, m_iop_target) == 24); /* natvis */

	mk_lang_assert(target);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_forwarder_iop_target_data_id_e_dummy_end);

	if(target->m_id == mk_lib_net_forwarder_iop_target_data_id_e_connector)
	{
		offset = mk_lang_offsetof(mk_lib_net_connector_t, m_iop_target);
		connector = ((mk_lib_net_connector_pt)(((mk_lang_types_uchar_pt)(target)) - offset));
		return connector;
	}
	else
	{
		return mk_lang_null;
	}
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_lib_net_forwarder_iop_target_logic_prrw_on_iop(mk_lib_net_forwarder_iop_target_data_pt const target, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(target);
	mk_lang_assert(iop);
	mk_lang_assert(target->m_id >= 0);
	mk_lang_assert(target->m_id < mk_lib_net_forwarder_iop_target_data_id_e_dummy_end);

	switch(target->m_id)
	{
		case mk_lib_net_forwarder_iop_target_data_id_e_listener : err = mk_lib_net_listener_rw_on_iop       (mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_listener (target), iop); break;
		case mk_lib_net_forwarder_iop_target_data_id_e_client   : err = mk_lib_net_listener_client_rw_on_iop(mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_client   (target), iop); break;
		case mk_lib_net_forwarder_iop_target_data_id_e_connector: err = mk_lib_net_connector_rw_on_iop      (mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_connector(target), iop); break;
		case mk_lib_net_forwarder_iop_target_data_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lib_net_listener_pt mk_lib_net_forwarder_iop_target_logic_rw_cast_to_listener(mk_lib_net_forwarder_iop_target_data_pt const target) mk_lang_noexcept
{
	return mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_listener(target);
}

mk_lang_nodiscard mk_lang_jumbo mk_lib_net_listener_client_pt mk_lib_net_forwarder_iop_target_logic_rw_cast_to_client(mk_lib_net_forwarder_iop_target_data_pt const target) mk_lang_noexcept
{
	return mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_client(target);
}

mk_lang_nodiscard mk_lang_jumbo mk_lib_net_connector_pt mk_lib_net_forwarder_iop_target_logic_rw_cast_to_connector(mk_lib_net_forwarder_iop_target_data_pt const target) mk_lang_noexcept
{
	return mk_lib_net_forwarder_iop_target_logic_prrw_cast_to_connector(target);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_net_forwarder_iop_target_logic_rw_on_iop(mk_lib_net_forwarder_iop_target_data_pt const target, mk_lib_net_iocp_iop_pct const iop) mk_lang_noexcept
{
	return mk_lib_net_forwarder_iop_target_logic_prrw_on_iop(target, iop);
}


#endif
