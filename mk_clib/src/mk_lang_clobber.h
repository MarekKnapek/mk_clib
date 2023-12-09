#ifndef mk_include_guard_mk_lang_clobber
#define mk_include_guard_mk_lang_clobber


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_clobber(mk_lang_types_void_pct const arg) mk_lang_noexcept;


#if mk_lang_jumbo_want == 1
#include "mk_lang_clobber.c"
#endif
#endif
