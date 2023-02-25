#include "mk_lang_crash.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_null.h"
#include "mk_lang_noexcept.h"

#include <stdlib.h> /* abort */


mk_lang_noreturn mk_lang_jumbo void mk_lang_crash(void) mk_lang_noexcept
{
	int volatile* volatile ptr;

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
