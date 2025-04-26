#ifndef mk_include_guard_mk_clib_fuzz_h
#define mk_include_guard_mk_clib_fuzz_h


#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_extern_force_c mk_lang_nodiscard mk_lang_inline mk_lang_types_sint_t mk_clib_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size, mk_lang_types_bool_t const allow_all) mk_lang_noexcept;


#if mk_lang_jumbo_have == 1
#include "mk_clib_fuzz.c"
#endif
#endif
