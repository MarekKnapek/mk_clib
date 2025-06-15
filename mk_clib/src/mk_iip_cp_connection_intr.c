#ifndef mk_include_guard_mk_iip_cp_connection_intr_c
#define mk_include_guard_mk_iip_cp_connection_intr_c
#include "mk_iip_cp_connection_intr.h"

#include "mk_iip_cp_client_data.h"
#include "mk_iip_cp_client_data_impl.h"
#include "mk_iip_cp_connection_impl.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_allocate(mk_iip_cp_connection_intr_ppt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**connection_intr), ((mk_lang_types_void_ppt)(connection_intr))); mk_lang_check_rereturn(err); mk_lang_assert(*connection_intr);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_deallocate(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_mallocator_global_deallocate(connection_intr, sizeof(*connection_intr)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_construct(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_construct(connection_intr->m_connection_impl, connection_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_destruct(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_destruct(connection_intr->m_connection_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_allocate_and_construct(mk_iip_cp_connection_intr_ppt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_intr_rw_allocate(connection_intr); mk_lang_check_rereturn(err); mk_lang_assert(*connection_intr);
	err = mk_iip_cp_connection_intr_rw_construct(*connection_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_destruct_and_deallocate(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_intr_rw_destruct(connection_intr); mk_lang_check_rereturn(err);
	err = mk_iip_cp_connection_intr_rw_deallocate(connection_intr); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_set_iocp(mk_iip_cp_connection_intr_pt const connection_intr, mk_sl_io_async_iocp_windows_pt const iocp) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_set_iocp(connection_intr->m_connection_impl, iocp); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_connection_intr_rw_did_something(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(connection_intr);

	ret = mk_iip_cp_connection_impl_rw_did_something(connection_intr->m_connection_impl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_connection_intr_rw_has_outstanding_iorp(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(connection_intr);

	ret = mk_iip_cp_connection_impl_rw_has_outstanding_iorp(connection_intr->m_connection_impl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_on_iorp(mk_iip_cp_connection_intr_pt const connection_intr, mk_sl_net_windows_iorp_xxx_pt const iorp) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_on_iorp(connection_intr->m_connection_impl, iorp); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_tick_single(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_tick_single(connection_intr->m_connection_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_tick_force(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_tick_force(connection_intr->m_connection_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_connect_to_i2cp(mk_iip_cp_connection_intr_pt const connection_intr, mk_iip_cp_client_data_request_connect_pct const request, mk_iip_cp_client_data_response_connect_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_connect_to_i2cp(connection_intr->m_connection_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_create_session(mk_iip_cp_connection_intr_pt const connection_intr, mk_iip_cp_client_data_request_create_session_pct const request, mk_iip_cp_client_data_response_create_session_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_create_session(connection_intr->m_connection_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_get_bandwidth_limits(mk_iip_cp_connection_intr_pt const connection_intr, mk_iip_cp_client_data_request_get_bandwidth_limits_pct const request, mk_iip_cp_client_data_response_get_bandwidth_limits_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_get_bandwidth_limits(connection_intr->m_connection_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_host_lookup(mk_iip_cp_connection_intr_pt const connection_intr, mk_iip_cp_client_data_request_host_lookup_pct const request, mk_iip_cp_client_data_response_host_lookup_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_host_lookup(connection_intr->m_connection_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_accept(mk_iip_cp_connection_intr_pt const connection_intr, mk_iip_cp_client_data_request_accept_pct const request, mk_iip_cp_client_data_response_accept_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_accept(connection_intr->m_connection_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_read_data(mk_iip_cp_connection_intr_pt const connection_intr, mk_iip_cp_client_data_request_read_data_pct const request, mk_iip_cp_client_data_response_read_data_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_read_data(connection_intr->m_connection_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intr_rw_get_bandwidth_limits_internal(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_get_bandwidth_limits_internal(connection_intr->m_connection_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intrs_pr_element_construct_void(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_allocate_and_construct(&connection_intr->m_connection_impl, connection_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_connection_intrs_pr_element_destruct(mk_iip_cp_connection_intr_pt const connection_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(connection_intr);

	err = mk_iip_cp_connection_impl_rw_destruct_and_deallocate(connection_intr->m_connection_impl); mk_lang_check_rereturn(err);
	return 0;
}


#define mk_sl_vector_t_name mk_iip_cp_connection_intrs
#define mk_sl_vector_t_element mk_iip_cp_connection_intr_t
#define mk_sl_vector_t_element_construct_void mk_iip_cp_connection_intrs_pr_element_construct_void
#define mk_sl_vector_t_element_destruct mk_iip_cp_connection_intrs_pr_element_destruct
#define mk_sl_vector_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
