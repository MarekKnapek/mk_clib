#include "mk_lang_crash.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_null.h"
#include "mk_lang_noexcept.h"

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
	int ta;
	int volatile* volatile ptr;

	#if mk_lang_crash_detail_have
	ta = puts(msg); /* assert(ta != EOF && ta >= 0) */
	ta = fflush(stdout); /* assert(ta != EOF && ta == 0) */
	#else
	#endif

	ptr = mk_lang_null;
	*ptr = 0;

	#if defined _MSC_VER /* todo version */
	__debugbreak();
	#endif

	#if defined __has_builtin
	#if __has_builtin(__builtin_debugtrap)
	__builtin_debugtrap();
	#endif
	#endif

	#if defined __has_builtin
	#if __has_builtin(__builtin_trap)
	__builtin_trap();
	#endif
	#endif

	abort();
}
