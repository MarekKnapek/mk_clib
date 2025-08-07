#ifndef mk_include_guard_mk_lib_iip_http_buffer_c
#define mk_include_guard_mk_lib_iip_http_buffer_c
#include "mk_lib_iip_http_buffer.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_cp_mallocator_global.h"
#include "mk_sl_cui_uint8.h"


#define mk_sl_vector_t_name mk_lib_iip_http_buffer
#define mk_sl_vector_t_element_type mk_sl_cui_uint8_t
#define mk_sl_vector_t_mallocatorg mk_lib_iip_cp_mallocator_global
#include "mk_sl_vector_inl_filec.h"
#include "mk_sl_vector_inl_fileu.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_http_buffer_rw_fancy_string(mk_lib_iip_http_buffer_pt const buffer) mk_lang_noexcept
{
#if defined DEBUG || defined _DEBUG
	mk_sl_cui_uint8_t zero;
	mk_lang_types_sint_t err;

	mk_lang_assert(buffer);

	mk_sl_cui_uint8_set_zero(&zero);
	err = mk_lib_iip_http_buffer_rw_push_back_copy_single(buffer, &zero); mk_lang_check_rereturn(err);
	err = mk_lib_iip_http_buffer_rw_pop_back_single(buffer); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(buffer);

	((mk_lang_types_void_t)(buffer));
	return 0;
#endif
}


#endif
