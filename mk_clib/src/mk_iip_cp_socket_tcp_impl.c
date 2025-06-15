#ifndef mk_include_guard_mk_iip_cp_socket_tcp_impl_c
#define mk_include_guard_mk_iip_cp_socket_tcp_impl_c
#include "mk_iip_cp_socket_tcp_impl.h"

#include "mk_iip_cp_destination.h"
#include "mk_iip_cp_mallocator_global.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_struct.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_impl_rw_allocate(mk_iip_cp_socket_tcp_impl_ppt const socket_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_impl);

	err = mk_iip_cp_mallocator_global_allocate(sizeof(**socket_tcp_impl), ((mk_lang_types_void_ppt)(socket_tcp_impl))); mk_lang_check_rereturn(err); mk_lang_assert(*socket_tcp_impl);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_impl_rw_deallocate(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_impl);

	err = mk_iip_cp_mallocator_global_deallocate(socket_tcp_impl, sizeof(*socket_tcp_impl)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_impl_rw_construct(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl, mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_assert(socket_tcp_impl);
	mk_lang_assert(socket_tcp_intr);

	socket_tcp_impl->m_socket_tcp_intr = socket_tcp_intr;
	((mk_lang_types_void_t)(socket_tcp_impl->m_did_something));
	socket_tcp_impl->m_state = mk_iip_cp_socket_tcp_impl_state_e_constructed;
	((mk_lang_types_void_t)(socket_tcp_impl->m_destination));
	((mk_lang_types_void_t)(socket_tcp_impl->m_tcpsm));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_impl_rw_destruct(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl) mk_lang_noexcept
{
	mk_lang_assert(socket_tcp_impl);

	((mk_lang_types_void_t)(socket_tcp_impl->m_socket_tcp_intr));
	((mk_lang_types_void_t)(socket_tcp_impl->m_did_something));
	((mk_lang_types_void_t)(socket_tcp_impl->m_state));
	((mk_lang_types_void_t)(socket_tcp_impl->m_destination));
	((mk_lang_types_void_t)(socket_tcp_impl->m_tcpsm));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_impl_rw_allocate_and_construct(mk_iip_cp_socket_tcp_impl_ppt const socket_tcp_impl, mk_iip_cp_socket_tcp_intr_pt const socket_tcp_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_impl);
	mk_lang_assert(socket_tcp_intr);

	err = mk_iip_cp_socket_tcp_impl_rw_allocate(socket_tcp_impl); mk_lang_check_rereturn(err); mk_lang_assert(*socket_tcp_impl);
	err = mk_iip_cp_socket_tcp_impl_rw_construct(*socket_tcp_impl, socket_tcp_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_impl_rw_destruct_and_deallocate(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(socket_tcp_impl);

	err = mk_iip_cp_socket_tcp_impl_rw_destruct(socket_tcp_impl); mk_lang_check_rereturn(err);
	err = mk_iip_cp_socket_tcp_impl_rw_deallocate(socket_tcp_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_destination_pct mk_iip_cp_socket_tcp_impl_rw_get_destination(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl) mk_lang_noexcept
{
	mk_iip_cp_destination_pct ret;

	mk_lang_assert(socket_tcp_impl);

	ret = &socket_tcp_impl->m_destination;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_sm_tcp_intr_pcpt mk_iip_cp_socket_tcp_impl_rw_get_tcpsm(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl) mk_lang_noexcept
{
	mk_iip_cp_sm_tcp_intr_pcpt ret;

	mk_lang_assert(socket_tcp_impl);

	ret = &socket_tcp_impl->m_tcpsm;
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_impl_rw_set_tcpsm(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl, mk_iip_cp_sm_tcp_intr_pcpt const tcpsm) mk_lang_noexcept
{
	mk_lang_assert(socket_tcp_impl);
	mk_lang_assert(tcpsm);

	socket_tcp_impl->m_tcpsm = *tcpsm;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_socket_tcp_impl_rw_did_something(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(socket_tcp_impl);

	ret = socket_tcp_impl->m_did_something;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_impl_rw_tick_single(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl) mk_lang_noexcept
{
	mk_lang_assert(socket_tcp_impl);

	socket_tcp_impl->m_did_something = mk_lang_false;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_impl_rw_bind(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl, mk_iip_cp_destination_pct const destination) mk_lang_noexcept
{
	mk_lang_assert(socket_tcp_impl);
	mk_lang_assert(destination);
	mk_lang_assert(socket_tcp_impl->m_state == mk_iip_cp_socket_tcp_impl_state_e_constructed);

	socket_tcp_impl->m_destination = *destination;
	socket_tcp_impl->m_state = mk_iip_cp_socket_tcp_impl_state_e_bound;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_socket_tcp_impl_rw_listen(mk_iip_cp_socket_tcp_impl_pt const socket_tcp_impl) mk_lang_noexcept
{
	mk_lang_assert(socket_tcp_impl);
	mk_lang_assert(socket_tcp_impl->m_state == mk_iip_cp_socket_tcp_impl_state_e_bound);

	socket_tcp_impl->m_state = mk_iip_cp_socket_tcp_impl_state_e_listening;
	return 0;
}


#endif
