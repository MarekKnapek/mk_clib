#ifndef mk_include_guard_mk_iip_cp_session_intr_c
#define mk_include_guard_mk_iip_cp_session_intr_c
#include "mk_iip_cp_session_intr.h"

#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_session_impl.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_allocate(mk_iip_cp_session_intr_ppt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**session_intr), ((mk_lang_types_void_ppt)(session_intr))); mk_lang_check_rereturn(err); mk_lang_assert(*session_intr);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_deallocate(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_mallocator_global_deallocate(session_intr, sizeof(*session_intr)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_construct(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_construct(session_intr->m_session_impl, session_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_destruct(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_destruct(session_intr->m_session_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_allocate_and_construct(mk_iip_cp_session_intr_ppt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_intr_rw_allocate(session_intr); mk_lang_check_rereturn(err); mk_lang_assert(*session_intr);
	err = mk_iip_cp_session_intr_rw_construct(*session_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_destruct_and_deallocate(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_intr_rw_destruct(session_intr); mk_lang_check_rereturn(err);
	err = mk_iip_cp_session_intr_rw_deallocate(session_intr); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_set_connection(mk_iip_cp_session_intr_pt const session_intr, mk_iip_cp_connection_intr_pcpt const connection) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_set_connection(session_intr->m_session_impl, connection); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_set_session_id(mk_iip_cp_session_intr_pt const session_intr, mk_iip_cp_type_sessionid_pct const session_id) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_set_session_id(session_intr->m_session_impl, session_id); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_set_destination(mk_iip_cp_session_intr_pt const session_intr, mk_iip_cp_type_destination_elgamal_dsa_pct const destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_set_destination(session_intr->m_session_impl, destination); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_connection_intr_pcpt mk_iip_cp_session_intr_rw_get_connection(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_iip_cp_connection_intr_pcpt ret;

	mk_lang_assert(session_intr);

	ret = mk_iip_cp_session_impl_rw_get_connection(session_intr->m_session_impl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_sessionid_pct mk_iip_cp_session_intr_rw_get_session_id(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_iip_cp_type_sessionid_pct ret;

	mk_lang_assert(session_intr);

	ret = mk_iip_cp_session_impl_rw_get_session_id(session_intr->m_session_impl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_destination_elgamal_dsa_pct mk_iip_cp_session_intr_rw_get_destination(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_iip_cp_type_destination_elgamal_dsa_pct ret;

	mk_lang_assert(session_intr);

	ret = mk_iip_cp_session_impl_rw_get_destination(session_intr->m_session_impl);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_session_intr_rw_did_something(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(session_intr);

	ret = mk_iip_cp_session_impl_rw_did_something(session_intr->m_session_impl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_tick_single(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_tick_single(session_intr->m_session_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_on_msg(mk_iip_cp_session_intr_pt const session_intr, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_on_msg(session_intr->m_session_impl, message); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_make_msg(mk_iip_cp_session_intr_pt const session_intr, mk_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_make_msg(session_intr->m_session_impl, message); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_accept(mk_iip_cp_session_intr_pt const session_intr, mk_iip_cp_client_data_request_accept_pct const request, mk_iip_cp_client_data_response_accept_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_accept(session_intr->m_session_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intr_rw_read_data(mk_iip_cp_session_intr_pt const session_intr, mk_iip_cp_client_data_request_read_data_pct const request, mk_iip_cp_client_data_response_read_data_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_read_data(session_intr->m_session_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intrs_pr_element_construct_void(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_allocate_and_construct(&session_intr->m_session_impl, session_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_session_intrs_pr_element_destruct(mk_iip_cp_session_intr_pt const session_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(session_intr);

	err = mk_iip_cp_session_impl_rw_destruct_and_deallocate(session_intr->m_session_impl); mk_lang_check_rereturn(err);
	return 0;
}


#define mk_sl_vector_t_name mk_iip_cp_session_intrs
#define mk_sl_vector_t_element mk_iip_cp_session_intr_t
#define mk_sl_vector_t_element_construct_void mk_iip_cp_session_intrs_pr_element_construct_void
#define mk_sl_vector_t_element_destruct mk_iip_cp_session_intrs_pr_element_destruct
#define mk_sl_vector_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
