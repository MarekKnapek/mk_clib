#ifndef mk_include_guard_mk_clib_app_info_c
#define mk_include_guard_mk_clib_app_info_c
#include "mk_clib_app_info.h"

#include "mk_lang_extern.h"
#include "mk_lang_info_platform.h"
#include "mk_lang_info_types.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_extern_c mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_info_void(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_info_platform_print();
	mk_lang_info_types_print_sizes();
	return 0;
}


#endif
