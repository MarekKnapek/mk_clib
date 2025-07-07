#ifndef mk_include_guard_mk_lib_iip_any_data_connections_c
#define mk_include_guard_mk_lib_iip_any_data_connections_c
#include "mk_lib_iip_any_data_connections.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_any_data_connection.h"
#include "mk_lib_iip_any_func_connection.h"
#include "mk_lib_iip_cp_mallocator_global.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_data_connections_elem_rw_construct_void(mk_lib_iip_any_data_connection_ppt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	((mk_lang_types_void_t)(x));
	mk_lang_check_todo();
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_data_connections_elem_rw_destroy(mk_lib_iip_any_data_connection_ppt const x) mk_lang_noexcept
{
	mk_lib_iip_any_data_connection_pt obj;
	mk_lang_types_sint_t err;

	mk_lang_assert(x);

	obj = *x;
	if(obj)
	{
		err = mk_lib_iip_any_func_connection_rw_destroy(obj); mk_lang_check_rereturn(err);
		err = mk_lib_iip_any_func_connection_rw_deallocate(obj); mk_lang_check_rereturn(err);
	}
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_data_connections_elem_rw_construct_copy(mk_lib_iip_any_data_connection_ppt const dst, mk_lib_iip_any_data_connection_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_data_connections_elem_rw_construct_move(mk_lib_iip_any_data_connection_ppt const dst, mk_lib_iip_any_data_connection_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_data_connections_elem_rw_assign_copy(mk_lib_iip_any_data_connection_ppt const dst, mk_lib_iip_any_data_connection_pcpt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	mk_lang_check_todo();
	*dst = *src;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_any_data_connections_elem_rw_assign_move(mk_lib_iip_any_data_connection_ppt const dst, mk_lib_iip_any_data_connection_ppt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	*src = mk_lang_null;
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_lib_iip_any_data_connections_elem_ro_eq(mk_lib_iip_any_data_connection_pcpt const a, mk_lib_iip_any_data_connection_pcpt const b) mk_lang_noexcept
{
	mk_lang_types_bool_t eq;

	mk_lang_assert(a);
	mk_lang_assert(b);

	eq = *a == *b;
	return eq;
}


#define mk_sl_vector_t_name mk_lib_iip_any_data_connections
#define mk_sl_vector_t_element_type mk_lib_iip_any_data_connection_pt
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#define mk_sl_vector_t_element_construct_void mk_lib_iip_any_data_connections_elem_rw_construct_void
#define mk_sl_vector_t_element_destruct mk_lib_iip_any_data_connections_elem_rw_destroy
#define mk_sl_vector_t_element_copy_construct mk_lib_iip_any_data_connections_elem_rw_construct_copy
#define mk_sl_vector_t_element_move_construct mk_lib_iip_any_data_connections_elem_rw_construct_move
#define mk_sl_vector_t_element_copy_assign mk_lib_iip_any_data_connections_elem_rw_assign_copy
#define mk_sl_vector_t_element_move_assign mk_lib_iip_any_data_connections_elem_rw_assign_move
#define mk_sl_vector_t_element_eq mk_lib_iip_any_data_connections_elem_ro_eq
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"


#endif
