#include "mk_lang_exe_name.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_pchar_pct mk_lang_exe_name_get(mk_lang_types_pchar_pct const arg) mk_lang_noexcept
{
	mk_lang_types_pchar_pct ptr mk_lang_constexpr_init;
	mk_lang_types_pchar_pct last mk_lang_constexpr_init;

	mk_lang_assert(arg);
	mk_lang_assert(arg[0] != '\0');

	ptr = arg;
	last = arg;
	for(; ptr[0] != '\0'; ++ptr)
	{
		if(ptr[0] == '/' || ptr[0] == '\\')
		{
			last = ptr + 1;
		}
	}
	return last;
}
