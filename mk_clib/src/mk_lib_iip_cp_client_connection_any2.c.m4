include(`mk_lib_iip_cp_client_connection_any.m')dnl
dnl
dnl
#ifndef mk_include_guard_mk_lib_iip_cp_client_connection_any2_c
#define mk_include_guard_mk_lib_iip_cp_client_connection_any2_c
#include "mk_lib_iip_cp_client_connection_any2.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_clobber.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_client_connection_any1.h"
#include "mk_sl_cui_uint8.h"

mk_lib_iip_cp_client_connection_any_mm_per_type(`#include "$1.h"', `
')


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_rw_construct(mk_lib_iip_cp_client_connection_any2_pt const any2, mk_lib_iip_cp_client_connection_any1_id_t const id, mk_lang_types_void_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(any2);
	mk_lang_assert(id >= 0 && id <= mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: any2->m_data.m_$1.m_id = id; err = $1_rw_construct(&any2->m_data.m_$1.m_$1, (($1_settings_pt)(settings))); mk_lang_check_rereturn(err); break;', `
')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_rw_destroy(mk_lib_iip_cp_client_connection_any2_pt const any2) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id >= 0 && any2->m_data.m_id <= mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: err = $1_rw_destroy(&any2->m_data.m_$1.m_$1); mk_lang_check_rereturn(err); break;', `
')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_rw_request_close(mk_lib_iip_cp_client_connection_any2_pt const any2) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id >= 0 && any2->m_data.m_id <= mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: err = $1_rw_request_close(&any2->m_data.m_$1.m_$1); mk_lang_check_rereturn(err); break;', `
')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_cp_client_connection_any2_rw_want_associate_socket(mk_lib_iip_cp_client_connection_any2_pt const any2) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id >= 0 && any2->m_data.m_id <= mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: ret = $1_rw_want_associate_socket(&any2->m_data.m_$1.m_$1); break;', `
')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	mk_lang_clobber(&ret);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lib_net_socket_pt mk_lib_iip_cp_client_connection_any2_rw_gimme_socket(mk_lib_iip_cp_client_connection_any2_pt const any2) mk_lang_noexcept
{
	mk_lib_net_socket_pt ret;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id >= 0 && any2->m_data.m_id <= mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: ret = $1_rw_gimme_socket(&any2->m_data.m_$1.m_$1); break;', `
')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	mk_lang_clobber(&ret);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_rw_on_iorp_done(mk_lib_iip_cp_client_connection_any2_pt const any2, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id >= 0 && any2->m_data.m_id <= mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: err = $1_rw_on_iorp_done(&any2->m_data.m_$1.m_$1, bytes_transferred, overlapped); mk_lang_check_rereturn(err); break;', `
')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_rw_step(mk_lib_iip_cp_client_connection_any2_pt const any2, mk_lang_types_bool_t const allow_to_block, mk_lang_types_sint_t const tm, mk_lib_iip_cp_client_connection_any2_result_pt const step_result) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(any2);
	mk_lang_assert(step_result);
	mk_lang_assert(any2->m_data.m_id >= 0 && any2->m_data.m_id <= mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_any2_result_e_dummy_end);

	switch(any2->m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: { $1_result_t stp_res; stp_res = $1_result_e_dummy_end; err = $1_rw_step(&any2->m_data.m_$1.m_$1, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); *step_result = ((mk_lib_iip_cp_client_connection_any2_result_t)(stp_res)); } break;', `
')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}


#endif
