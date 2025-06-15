#ifndef mk_include_guard_mk_iip_cp_socket_tcp_intr_c
#define mk_include_guard_mk_iip_cp_socket_tcp_intr_c
#include "mk_iip_cp_socket_tcp_intr.h"

#include "mk_iip_cp_mallocator_global.h"
#include "mk_iip_cp_socket_tcp_impl.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intr_rw_allocate(mk_iip_cp_socket_tcp_intr_ppt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**socket_tcp_intr), ((mk_lang_types_void_ppt)(socket_tcp_intr))); mk_lang_check_rereturn(err); mk_lang_assert(*socket_tcp_intr);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intr_rw_deallocate(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_mallocator_global_deallocate(socket_tcp_intr, sizeof(*socket_tcp_intr)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intr_rw_construct(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_impl_rw_allocate_and_construct(&socket_tcp_intr->m_socket_tcp_impl, socket_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intr_rw_destruct(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_impl_rw_destruct_and_deallocate(socket_tcp_intr->m_socket_tcp_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intr_rw_allocate_and_construct(mk_iip_cp_socket_tcp_intr_ppt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_intr_rw_allocate(socket_tcp_intr); mk_lang_check_rereturn(err); mk_lang_assert(*socket_tcp_intr);
	err = mk_iip_cp_socket_tcp_intr_rw_construct(*socket_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intr_rw_destruct_and_deallocate(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_intr_rw_destruct(socket_tcp_intr); mk_lang_check_rereturn(err);
	err = mk_iip_cp_socket_tcp_intr_rw_deallocate(socket_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_destination_pct mk_iip_cp_socket_tcp_intr_rw_get_destination(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_iip_cp_destination_pct ret;

	mk_lang_assert(socket_tcp_intr);

	ret = mk_iip_cp_socket_tcp_impl_rw_get_destination(socket_tcp_intr->m_socket_tcp_impl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_sm_tcp_intr_pcpt mk_iip_cp_socket_tcp_intr_rw_get_tcpsm(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_iip_cp_sm_tcp_intr_pcpt ret;

	mk_lang_assert(socket_tcp_intr);

	ret = mk_iip_cp_socket_tcp_impl_rw_get_tcpsm(socket_tcp_intr->m_socket_tcp_impl);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intr_rw_set_tcpsm(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr, mk_iip_cp_sm_tcp_intr_pcpt const tcpsm) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_impl_rw_set_tcpsm(socket_tcp_intr->m_socket_tcp_impl, tcpsm); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_socket_tcp_intr_rw_did_something(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(socket_tcp_intr);

	ret = mk_iip_cp_socket_tcp_impl_rw_did_something(socket_tcp_intr->m_socket_tcp_impl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intr_rw_tick_single(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_impl_rw_tick_single(socket_tcp_intr->m_socket_tcp_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intr_rw_bind(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr, mk_iip_cp_destination_pct const destination) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_impl_rw_bind(socket_tcp_intr->m_socket_tcp_impl, destination); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intr_rw_listen(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_impl_rw_listen(socket_tcp_intr->m_socket_tcp_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intrs_pr_element_construct_void(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_impl_rw_allocate_and_construct(&socket_tcp_intr->m_socket_tcp_impl, socket_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_intrs_pr_element_destruct(mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_impl_rw_destruct_and_deallocate(socket_tcp_intr->m_socket_tcp_impl); mk_lang_check_rereturn(err);
	return 0;
}


#define mk_sl_vector_t_name mk_iip_cp_socket_tcp_intrs
#define mk_sl_vector_t_element mk_iip_cp_socket_tcp_intr_t
#define mk_sl_vector_t_element_construct_void mk_iip_cp_socket_tcp_intrs_pr_element_construct_void
#define mk_sl_vector_t_element_destruct mk_iip_cp_socket_tcp_intrs_pr_element_destruct
#define mk_sl_vector_t_mallocatorg mk_iip_cp_mallocator_global
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
