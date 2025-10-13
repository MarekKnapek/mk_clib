#ifndef mk_include_guard_mk_lang_rt_h
#define mk_include_guard_mk_lang_rt_h


#include "mk_lang_arch.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any && mk_lang_arch_is_x8664

#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"


mk_lang_extern_force_c mk_lang_types_sint_t mk_lang_rt_memcmp(mk_lang_types_void_pct const a, mk_lang_types_void_pct const b, mk_lang_types_usize_t const c) mk_lang_noexcept;
mk_lang_extern_force_c mk_lang_noreturn mk_lang_types_void_t mk_win_base_cdecl mk_lang_rt_terminate(mk_lang_types_void_pct const x) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_lang_rt.c"
#endif
#endif
