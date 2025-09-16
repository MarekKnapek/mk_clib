#ifndef mk_include_guard_mk_lib_wasm_info_c
#define mk_include_guard_mk_lib_wasm_info_c
#include "mk_lib_wasm_info.h"

#include "mk_clib_app_info.h"
#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo mk_lang_types_void_t mk_lib_wasm_info_main(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_clib_app_info_void();
	mk_lang_assert(err == 0);
}


#endif
