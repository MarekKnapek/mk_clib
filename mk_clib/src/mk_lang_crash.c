#ifndef mk_include_guard_mk_lang_crash_c
#define mk_include_guard_mk_lang_crash_c
#include "mk_lang_crash.h"

#include "mk_lang_debug_break.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"


#include <stdlib.h> /* abort */

#if mk_lang_crash_detail_have
#include <stdio.h> /* puts fflush stdout */
#endif


#include "mk_lang_warning_msvc_push_c4746.h"
#if mk_lang_crash_detail_have
mk_lang_noreturn mk_lang_jumbo mk_lang_types_void_t mk_lang_crash_impl(mk_lang_types_pchar_pct const msg) mk_lang_noexcept
#else
mk_lang_noreturn mk_lang_jumbo mk_lang_types_void_t mk_lang_crash(mk_lang_types_void_t) mk_lang_noexcept
#endif
{
	#if mk_lang_crash_detail_have
	mk_lang_types_sint_t tsi;
	#endif
	mk_lang_types_sint_pvt volatile ptr;

	#if mk_lang_crash_detail_have
	tsi = puts(msg); /* assert(tsi != EOF && tsi >= 0) */
	tsi = fflush(stdout); /* assert(tsi != EOF && tsi == 0) */
	((mk_lang_types_void_t)(tsi));
	#endif

	mk_lang_debug_break();

	ptr = mk_lang_null;
	*ptr = 0;

	abort();
}
#include "mk_lang_warning_msvc_pop.h"


#endif
