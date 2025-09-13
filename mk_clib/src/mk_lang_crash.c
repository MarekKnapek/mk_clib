#ifndef mk_include_guard_mk_lang_crash_c
#define mk_include_guard_mk_lang_crash_c
#include "mk_lang_crash.h"

#include "mk_lang_arch.h"
#include "mk_lang_debug_break.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"

#include <stdlib.h> /* abort */


#include "mk_lang_warning_msvc_push_c4746.h"
mk_lang_noreturn static mk_lang_inline mk_lang_types_void_t mk_lang_crash_impl(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_pvt volatile ptr;

	#if !mk_lang_arch_is_emscripten
	ptr = mk_lang_null;
	#else
	ptr = ((mk_lang_types_sint_pvt)(((mk_lang_types_uintptr_t)(((mk_lang_types_ulong_t)(3ul * 1024ul * 1024ul * 1024ul)))))); /* Sure we have nothing at 3GB mark. Right? Hope this triggers crash or something. */
	#endif
	*ptr = 0;

	abort();
}
#include "mk_lang_warning_msvc_pop.h"


#if mk_lang_crash_detail_have


#include <stdio.h> /* puts fflush stdout */

mk_lang_jumbo mk_lang_types_void_t mk_lang_crash_for_real(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_crash_impl();
}

mk_lang_jumbo mk_lang_types_void_t mk_lang_crash_print_msg(mk_lang_types_pchar_pct const msg) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi;

	/* assert(msg); */

	tsi = puts(msg); /* assert(tsi != EOF && tsi >= 0); */
	tsi = fflush(stdout); /* assert(tsi != EOF && tsi == 0); */
	((mk_lang_types_void_t)(tsi));
}


#else


mk_lang_jumbo mk_lang_types_void_t mk_lang_crash(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_crash_impl();
}


#endif


#endif
