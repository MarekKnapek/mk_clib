#ifndef mk_include_guard_mk_clib_app_info_c
#define mk_include_guard_mk_clib_app_info_c
#include "mk_clib_app_info.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_stdout.h"
#include "mk_lang_types.h"

#include "mk_lang_info_platform.h"
#include "mk_lang_info_types.h"


#if mk_lang_entry_point_have


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_types_sint_t mk_clib_app_info_peb(mk_lang_types_void_pt const peb) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(peb);

	((mk_lang_types_void_t)(peb));
	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_lang_info_platform_print(); mk_lang_check_rereturn(err);
	err = mk_lang_info_types_print_sizes(); mk_lang_check_rereturn(err);
	return 0;
}


#else


mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_info_void(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_lang_stdout_init(); mk_lang_check_rereturn(err);
	err = mk_lang_info_platform_print(); mk_lang_check_rereturn(err);
	err = mk_lang_info_types_print_sizes(); mk_lang_check_rereturn(err);
	return 0;
}


#endif


#endif
