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
#include "mk_lang_offsetof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_client_connection_any1.h"
#include "mk_sl_cui_uint8.h"

mk_lib_iip_cp_client_connection_any_mm_per_type(`#include "$1.h"', `
')


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_rw_allocate(mk_lib_iip_cp_client_connection_any2_ppt const any2, mk_lib_iip_cp_client_connection_any1_id_t const id) mk_lang_noexcept
{
	mk_lang_types_usize_t size;
	mk_lang_types_void_pt mem;
	mk_lib_iip_cp_client_connection_any2_pt connection;
	mk_lang_types_sint_t err;

mk_lib_iip_cp_client_connection_any_mm_per_type(`	mk_lang_static_assert(mk_lang_offsetof(mk_lib_iip_cp_client_connection_any2_$1_t, m_$1) == sizeof(mk_lib_iip_cp_client_connection_any2_id_store_t));
')dnl

	mk_lang_assert(any2);
	mk_lang_assert(id >= 0);
	mk_lang_assert(id < mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: size = sizeof(mk_lib_iip_cp_client_connection_any2_$1_t); break;')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&size);
	err = mk_lib_iip_cp_mallocator_global_allocate(size, &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); connection = ((mk_lib_iip_cp_client_connection_any2_pt)(mem)); mk_lang_assert(connection);
	connection->m_data.m_id.m_data.m_id = id;
		switch(id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: connection->m_data.m_$1.m_id.m_data.m_id = id; break;')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	*any2 = connection;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_rw_deallocate(mk_lib_iip_cp_client_connection_any2_pt const any2) mk_lang_noexcept
{
	mk_lang_types_usize_t size;
	mk_lang_types_sint_t err;

mk_lib_iip_cp_client_connection_any_mm_per_type(`	mk_lang_static_assert(mk_lang_offsetof(mk_lib_iip_cp_client_connection_any2_$1_t, m_$1) == sizeof(mk_lib_iip_cp_client_connection_any2_id_store_t));
')dnl

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id.m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: size = sizeof(mk_lib_iip_cp_client_connection_any2_$1_t); break;')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert_false(); break;
		default: mk_lang_assert_false(); break;
	}
	mk_lang_clobber(&size);
	err = mk_lib_iip_cp_mallocator_global_deallocate(any2, size); mk_lang_check_rereturn(err);
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_rw_construct(mk_lib_iip_cp_client_connection_any2_pt const any2, mk_lang_types_void_pct const settings) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id.m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: err = $1_rw_construct(&any2->m_data.m_$1.m_$1, (($1_settings_pt)(settings))); mk_lang_check_rereturn(err); break;', `
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
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id.m_data.m_id)
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
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id.m_data.m_id)
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
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id.m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: ret = $1_rw_want_associate_socket(&any2->m_data.m_$1.m_$1); break;', `
')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	mk_lang_clobber(&ret);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_rw_gimme_socket(mk_lib_iip_cp_client_connection_any2_pt const any2, mk_lib_net_socket_ppt const socket, mk_lib_iip_cp_client_connection_any2_ppt const associatee) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);
	mk_lang_assert(socket);
	mk_lang_assert(associatee);

	switch(any2->m_data.m_id.m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: err = $1_rw_gimme_socket(&any2->m_data.m_$1.m_$1, socket, associatee); mk_lang_check_rereturn(err); break;', `
')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_rw_on_iorp_done(mk_lib_iip_cp_client_connection_any2_pt const any2, mk_lang_types_sint_t const bytes_transferred, mk_lang_types_void_pt const overlapped) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(any2);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);

	switch(any2->m_data.m_id.m_data.m_id)
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
	mk_lang_assert(any2->m_data.m_id.m_data.m_id >= 0);
	mk_lang_assert(any2->m_data.m_id.m_data.m_id < mk_lib_iip_cp_client_connection_any1_id_e_dummy_end);
	mk_lang_assert(*step_result == mk_lib_iip_cp_client_connection_any2_result_e_dummy_end);

	switch(any2->m_data.m_id.m_data.m_id)
	{
mk_lib_iip_cp_client_connection_any_mm_per_type(`		case mk_lib_iip_cp_client_connection_any1_id_e_$1: { $1_result_t stp_res; stp_res = $1_result_e_dummy_end; err = $1_rw_step(&any2->m_data.m_$1.m_$1, allow_to_block, tm, &stp_res); mk_lang_check_rereturn(err); *step_result = ((mk_lib_iip_cp_client_connection_any2_result_t)(stp_res)); } break;', `
')
		case mk_lib_iip_cp_client_connection_any1_id_e_dummy_end: mk_lang_assert(mk_lang_false); break;
		default: mk_lang_assert(mk_lang_false); break;
	}
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_ptr_rw_construct_void(mk_lib_iip_cp_client_connection_any2_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_ptr_rw_destroy(mk_lib_iip_cp_client_connection_any2_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_cp_client_connection_any2_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_cp_client_connection_any2_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_cp_mallocator_global_deallocate(obj, sizeof(*obj)); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_ptr_rw_construct_copy(mk_lib_iip_cp_client_connection_any2_ppt const dst, mk_lib_iip_cp_client_connection_any2_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_ptr_rw_construct_move(mk_lib_iip_cp_client_connection_any2_ppt const dst, mk_lib_iip_cp_client_connection_any2_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_ptr_rw_assign_copy(mk_lib_iip_cp_client_connection_any2_ppt const dst, mk_lib_iip_cp_client_connection_any2_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_cp_client_connection_any2_ptr_rw_assign_move(mk_lib_iip_cp_client_connection_any2_ppt const dst, mk_lib_iip_cp_client_connection_any2_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}


#define mk_sl_vector_t_name mk_lib_iip_cp_client_connection_any2s
#define mk_sl_vector_t_element_type mk_lib_iip_cp_client_connection_any2_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_cp_client_connection_any2_ptr_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_cp_client_connection_any2_ptr_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_cp_client_connection_any2_ptr_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_cp_client_connection_any2_ptr_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_cp_client_connection_any2_ptr_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_cp_client_connection_any2_ptr_rw_assign_move
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
