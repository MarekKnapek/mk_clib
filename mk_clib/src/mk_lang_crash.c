#include "mk_lang_crash.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_null.h"
#include "mk_lang_noexcept.h"

#include <stdlib.h> /* abort */


#if defined NDEBUG
mk_lang_noreturn mk_lang_jumbo void mk_lang_crash(void) mk_lang_noexcept
#else
mk_lang_noreturn mk_lang_jumbo void mk_lang_crash_impl(char const* const file, int const line) mk_lang_noexcept
#endif
{
	int volatile* volatile ptr;

	ptr = mk_lang_null;
	#if defined NDEBUG
	*ptr = 0;
	#else
	*ptr = file[line];
	#endif

	#if defined _MSC_VER >= 1200 /* todo version */
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
