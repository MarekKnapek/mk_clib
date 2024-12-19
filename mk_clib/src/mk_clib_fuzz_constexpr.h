#ifndef mk_include_guard_mk_clib_fuzz_constexpr
#define mk_include_guard_mk_clib_fuzz_constexpr


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo mk_lang_types_void_t mk_clib_fuzz_constexpr(mk_lang_types_void_t) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_fuzz_constexpr.c"
#endif
#endif
