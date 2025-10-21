#ifndef mk_include_guard_mk_lang_rt_c
#define mk_include_guard_mk_lang_rt_c
#include "mk_lang_rt.h"

#include "mk_lang_arch.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any && mk_lang_arch_is_x8664

#include "mk_lang_assert.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_types.h"
#include "mk_win_base.h"
#include "mk_win_dll_ntdll.h"


mk_lang_extern_force_c mk_lang_types_sint_t mk_lang_rt_memcmp(mk_lang_types_void_pct const a, mk_lang_types_void_pct const b, mk_lang_types_usize_t const c) mk_lang_noexcept
{
	mk_lang_types_usize_t compared;
	mk_lang_types_sint_t cmp;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(a || c == 0);
	mk_lang_assert(b || c == 0);
	mk_lang_assert(c >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	compared = mk_win_dll_ntdll_rtl_compare_memory(a, b, c);
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(compared >= 0);
	mk_lang_assert(compared <= c);
	#include "mk_lang_warning_msvc_pop.h"
	cmp =
	(
		(compared == c) ?
		(0) :
		(
			((mk_lang_types_sint_t)(((mk_lang_types_uchar_pct)(a))[compared])) -
			((mk_lang_types_sint_t)(((mk_lang_types_uchar_pct)(b))[compared]))
		)
	);
	return cmp;
}

mk_lang_extern_force_c mk_lang_noreturn mk_lang_types_void_t mk_win_base_cdecl mk_lang_rt_terminate(mk_lang_types_void_pct const x) mk_lang_noexcept
{
	((mk_lang_types_void_t)(x));
}


#else
void mk_lang_rt_dummy(void);
void mk_lang_rt_dummy(void){}
#endif
#endif
