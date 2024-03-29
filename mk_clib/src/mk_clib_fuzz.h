#ifndef mk_include_guard_mk_clib_fuzz
#define mk_include_guard_mk_clib_fuzz


#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_jumbo void mk_clib_fuzz(unsigned char const* const data, mk_lang_types_usize_t const size) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_clib_fuzz.c"
#endif
#endif
