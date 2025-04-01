#ifndef mk_include_guard_mk_clib_app_test_h
#define mk_include_guard_mk_clib_app_test_h


#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_extern_c mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_test_void(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_clib_app_test.c"
#endif
#endif
