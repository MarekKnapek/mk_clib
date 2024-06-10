#include "mk_lang_crash.h"

#include "mk_lang_builtin.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_null.h"

#include <stdlib.h> /* abort */

#if mk_lang_crash_detail_have
#include <stdio.h> /* puts fflush stdout */
#endif


#if mk_lang_crash_detail_have
mk_lang_noreturn mk_lang_jumbo void mk_lang_crash_impl(char const* const msg) mk_lang_noexcept
#else
mk_lang_noreturn mk_lang_jumbo void mk_lang_crash(void) mk_lang_noexcept
#endif
{
	#if mk_lang_crash_detail_have
	int ta;
	#endif
	int volatile* volatile ptr;

	#if mk_lang_crash_detail_have
	ta = puts(msg); /* assert(ta != EOF && ta >= 0) */
	ta = fflush(stdout); /* assert(ta != EOF && ta == 0) */
	((void)(ta));
	#endif

	#if mk_lang_msvc_ver >= 1200l /* vs6 */
	__debugbreak();
	#endif

	#if mk_lang_builtin_has_debugtrap
	__builtin_debugtrap();
	#endif

	#if mk_lang_builtin_has_trap
	__builtin_trap();
	#endif

	ptr = mk_lang_null;
	*ptr = 0;

	abort();
}
