#ifndef mk_include_guard_mk_iip_cp_sm_tcp_intr_c
#define mk_include_guard_mk_iip_cp_sm_tcp_intr_c
#include "mk_iip_cp_sm_tcp_intr.h"

#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_sm_tcp_impl.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_allocate(mk_iip_cp_sm_tcp_intr_ppt const sm_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**sm_tcp_intr), ((mk_lang_types_void_ppt)(sm_tcp_intr))); mk_lang_check_rereturn(err); mk_lang_assert(*sm_tcp_intr);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_deallocate(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_mallocator_global_deallocate(sm_tcp_intr, sizeof(*sm_tcp_intr)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_construct(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_allocate_and_construct(&sm_tcp_intr->m_sessioncmd_tcp_impl, sm_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_destruct(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_destruct_and_deallocate(sm_tcp_intr->m_sessioncmd_tcp_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_allocate_and_construct(mk_iip_cp_sm_tcp_intr_ppt const sm_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_intr_rw_allocate(sm_tcp_intr); mk_lang_check_rereturn(err); mk_lang_assert(*sm_tcp_intr);
	err = mk_iip_cp_sm_tcp_intr_rw_construct(*sm_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_destruct_and_deallocate(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_intr_rw_destruct(sm_tcp_intr); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sm_tcp_intr_rw_deallocate(sm_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_set_session_id(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr, mk_iip_cp_type_sessionid_pct const session_id) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_set_session_id(sm_tcp_intr->m_sessioncmd_tcp_impl, session_id); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_set_local_destination(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr, mk_iip_cp_type_destination_elgamal_dsa_pct const local_destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_set_local_destination(sm_tcp_intr->m_sessioncmd_tcp_impl, local_destination); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_set_wanted_port(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr, mk_sl_cui_uint16_pct const wanted_port) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_set_wanted_port(sm_tcp_intr->m_sessioncmd_tcp_impl, wanted_port); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_set_accept_rr(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr, mk_iip_cp_client_data_request_accept_pct const request, mk_iip_cp_client_data_response_accept_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_set_accept_rr(sm_tcp_intr->m_sessioncmd_tcp_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_set_read_data_rr(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr, mk_iip_cp_client_data_request_read_data_pct const request, mk_iip_cp_client_data_response_read_data_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_set_read_data_rr(sm_tcp_intr->m_sessioncmd_tcp_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_sessionid_pct mk_iip_cp_sm_tcp_intr_rw_get_session_id(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr) mk_lang_noexcept
{
	mk_iip_cp_type_sessionid_pct ret;

	mk_lang_assert(sm_tcp_intr);

	ret = mk_iip_cp_sm_tcp_impl_rw_get_session_id(sm_tcp_intr->m_sessioncmd_tcp_impl);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_sm_tcp_intr_rw_did_something(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(sm_tcp_intr);

	ret = mk_iip_cp_sm_tcp_impl_rw_did_something(sm_tcp_intr->m_sessioncmd_tcp_impl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_on_msg(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_on_msg(sm_tcp_intr->m_sessioncmd_tcp_impl, message); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_make_msg(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr, mk_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_make_msg(sm_tcp_intr->m_sessioncmd_tcp_impl, message); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intr_rw_tick_single(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_tick_single(sm_tcp_intr->m_sessioncmd_tcp_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intrs_pr_element_construct_void(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_allocate_and_construct(&sm_tcp_intr->m_sessioncmd_tcp_impl, sm_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sm_tcp_intrs_pr_element_destruct(mk_iip_cp_sm_tcp_intr_pt const sm_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sm_tcp_intr);

	err = mk_iip_cp_sm_tcp_impl_rw_destruct_and_deallocate(sm_tcp_intr->m_sessioncmd_tcp_impl); mk_lang_check_rereturn(err);
	return 0;
}


#define mk_sl_vector_t_name mk_iip_cp_sm_tcp_intrs
#define mk_sl_vector_t_element mk_iip_cp_sm_tcp_intr_t
#define mk_sl_vector_t_element_construct_void mk_iip_cp_sm_tcp_intrs_pr_element_construct_void
#define mk_sl_vector_t_element_destruct mk_iip_cp_sm_tcp_intrs_pr_element_destruct
#define mk_sl_vector_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
