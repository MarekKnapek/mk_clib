#ifndef mk_include_guard_mk_iip_cp_sessioncmd_base_intr_c
#define mk_include_guard_mk_iip_cp_sessioncmd_base_intr_c
#include "mk_iip_cp_sessioncmd_base_intr.h"

#include "mk_iip_cp_sessioncmd_base_impl.h"
#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_mallocatorg.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intr_rw_allocate(mk_iip_cp_sessioncmd_base_intr_ppt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_sl_mallocatorg_allocate(sizeof(**sessioncmd_base_intr), ((mk_lang_types_void_ppt)(sessioncmd_base_intr))); mk_lang_check_rereturn(err); mk_lang_assert(*sessioncmd_base_intr);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intr_rw_deallocate(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_sl_mallocatorg_deallocate(sessioncmd_base_intr, sizeof(*sessioncmd_base_intr)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intr_rw_construct(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_impl_rw_allocate_and_construct(&sessioncmd_base_intr->m_sessioncmd_base_impl, sessioncmd_base_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intr_rw_destruct(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_impl_rw_destruct_and_deallocate(sessioncmd_base_intr->m_sessioncmd_base_impl); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intr_rw_allocate_and_construct(mk_iip_cp_sessioncmd_base_intr_ppt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_intr_rw_allocate(sessioncmd_base_intr); mk_lang_check_rereturn(err); mk_lang_assert(*sessioncmd_base_intr);
	err = mk_iip_cp_sessioncmd_base_intr_rw_construct(*sessioncmd_base_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intr_rw_destruct_and_deallocate(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_intr_rw_destruct(sessioncmd_base_intr); mk_lang_check_rereturn(err);
	err = mk_iip_cp_sessioncmd_base_intr_rw_deallocate(sessioncmd_base_intr); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intr_rw_set_session_id(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr, mk_iip_cp_type_sessionid_pct const session_id) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_impl_rw_set_session_id(sessioncmd_base_intr->m_sessioncmd_base_impl, session_id); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_iip_cp_type_sessionid_pct mk_iip_cp_sessioncmd_base_intr_rw_get_session_id(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_iip_cp_type_sessionid_pct ret;

	mk_lang_assert(sessioncmd_base_intr);

	ret = mk_iip_cp_sessioncmd_base_impl_rw_get_session_id(sessioncmd_base_intr->m_sessioncmd_base_impl);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_iip_cp_sessioncmd_base_intr_rw_did_something(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(sessioncmd_base_intr);

	ret = mk_iip_cp_sessioncmd_base_impl_rw_did_something(sessioncmd_base_intr->m_sessioncmd_base_impl);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intr_rw_on_msg(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr, mk_iip_cp_message_pct const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_impl_rw_on_msg(sessioncmd_base_intr->m_sessioncmd_base_impl, message); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intr_rw_make_msg(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr, mk_iip_cp_message_pt const message) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_impl_rw_make_msg(sessioncmd_base_intr->m_sessioncmd_base_impl, message); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intr_rw_tick_single(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_impl_rw_tick_single(sessioncmd_base_intr->m_sessioncmd_base_impl); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intrs_pr_element_construct_void(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_impl_rw_allocate_and_construct(&sessioncmd_base_intr->m_sessioncmd_base_impl, sessioncmd_base_intr); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_iip_cp_sessioncmd_base_intrs_pr_element_destruct(mk_iip_cp_sessioncmd_base_intr_pt const sessioncmd_base_intr) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(sessioncmd_base_intr);

	err = mk_iip_cp_sessioncmd_base_impl_rw_destruct_and_deallocate(sessioncmd_base_intr->m_sessioncmd_base_impl); mk_lang_check_rereturn(err);
	return 0;
}


#define mk_sl_vector_t_name mk_iip_cp_sessioncmd_base_intrs
#define mk_sl_vector_t_element mk_iip_cp_sessioncmd_base_intr_t
#define mk_sl_vector_t_element_construct_void mk_iip_cp_sessioncmd_base_intrs_pr_element_construct_void
#define mk_sl_vector_t_element_destruct mk_iip_cp_sessioncmd_base_intrs_pr_element_destruct
#define mk_sl_vector_t_mallocatorg mk_sl_mallocatorg
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
