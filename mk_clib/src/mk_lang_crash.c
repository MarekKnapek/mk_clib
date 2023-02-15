#include "mk_lang_crash.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noreturn.h"
#include "mk_lang_null.h"
#include "mk_lang_noexcept.h"


mk_lang_noreturn mk_lang_jumbo void mk_lang_crash(void) mk_lang_noexcept
{
	int volatile* volatile ptr;

	ptr = mk_lang_null;
	*ptr = 0;
}
