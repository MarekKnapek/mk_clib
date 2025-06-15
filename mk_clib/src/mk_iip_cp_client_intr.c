#ifndef mk_include_guard_mk_iip_cp_client_intr_c
#define mk_include_guard_mk_iip_cp_client_intr_c
#include "mk_iip_cp_client_intr.h"

#include "mk_iip_cp_client_impl.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_allocate(mk_iip_cp_client_intr_ppt const client_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**client_intr), ((mk_lang_types_void_ppt)(client_intr))); mk_lang_check_rereturn(err); mk_lang_assert(*client_intr);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_deallocate(mk_iip_cp_client_intr_pt const client_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_mallocator_global_deallocate(client_intr, sizeof(*client_intr)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_construct(mk_iip_cp_client_intr_pt const client_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_allocate_and_construct(&client_intr->m_client_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_destruct(mk_iip_cp_client_intr_pt const client_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_destruct_and_deallocate(client_intr->m_client_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_allocate_and_construct(mk_iip_cp_client_intr_ppt const client_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_intr_rw_allocate(client_intr); mk_lang_check_rereturn(err); mk_lang_assert(*client_intr);
	err = mk_iip_cp_client_intr_rw_construct(*client_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_destruct_and_deallocate(mk_iip_cp_client_intr_pt const client_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_intr_rw_destruct(client_intr); mk_lang_check_rereturn(err);
	err = mk_iip_cp_client_intr_rw_deallocate(client_intr); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_client_intr_rw_did_something(mk_iip_cp_client_intr_pt const client_intr) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(client_intr);

	ret = mk_iip_cp_client_impl_rw_did_something(client_intr->m_client_impl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_tick_single(mk_iip_cp_client_intr_pt const client_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_tick_single(client_intr->m_client_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_tick_single2(mk_iip_cp_client_intr_pt const client_intr, mk_lang_types_sint_t const ms) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_tick_single2(client_intr->m_client_impl, ms); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_tick_until_idle(mk_iip_cp_client_intr_pt const client_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_tick_until_idle(client_intr->m_client_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_generate_destination(mk_iip_cp_client_intr_pt const client_intr, mk_iip_cp_client_data_request_generate_destination_pct const request, mk_iip_cp_client_data_response_generate_destination_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_generate_destination(client_intr->m_client_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_connect_to_i2cp(mk_iip_cp_client_intr_pt const client_intr, mk_iip_cp_client_data_request_connect_pct const request, mk_iip_cp_client_data_response_connect_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_connect_to_i2cp(client_intr->m_client_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_create_session(mk_iip_cp_client_intr_pt const client_intr, mk_iip_cp_client_data_request_create_session_pct const request, mk_iip_cp_client_data_response_create_session_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_create_session(client_intr->m_client_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_host_lookup(mk_iip_cp_client_intr_pt const client_intr, mk_iip_cp_client_data_request_host_lookup_pct const request, mk_iip_cp_client_data_response_host_lookup_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_host_lookup(client_intr->m_client_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_accept(mk_iip_cp_client_intr_pt const client_intr, mk_iip_cp_client_data_request_accept_pct const request, mk_iip_cp_client_data_response_accept_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_accept(client_intr->m_client_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_read_data(mk_iip_cp_client_intr_pt const client_intr, mk_iip_cp_client_data_request_read_data_pct const request, mk_iip_cp_client_data_response_read_data_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_read_data(client_intr->m_client_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_client_intr_rw_send_data(mk_iip_cp_client_intr_pt const client_intr, mk_iip_cp_client_data_request_send_data_pct const request, mk_iip_cp_client_data_response_send_data_pt const response) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(client_intr);

	err = mk_iip_cp_client_impl_rw_send_data(client_intr->m_client_impl, request, response); mk_lang_check_rereturn(err);
	return 0;
}


#endif
