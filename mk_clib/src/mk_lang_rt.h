#ifndef mk_include_guard_mk_lang_rt_h
#define mk_include_guard_mk_lang_rt_h


#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_extern_force_c mk_lang_types_sint_t mk_lang_rt_memcmp(mk_lang_types_void_pct const a, mk_lang_types_void_pct const b, mk_lang_types_usize_t const c) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lang_rt.c"
#endif
#endif
