#include "mk_lang_crash.h"

#include "mk_lang_jumbo.h"


mk_lang_jumbo void mk_lang_crash(void)
{
	int volatile* volatile ptr;

	ptr = 0;
	*ptr = 0;
}
