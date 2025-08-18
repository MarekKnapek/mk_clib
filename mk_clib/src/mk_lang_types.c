#ifndef mk_include_guard_mk_lang_types_c
#define mk_include_guard_mk_lang_types_c
#include "mk_lang_types.h"

#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lang_types_pchar_eq(mk_lang_types_pchar_pct const a, mk_lang_types_pchar_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	/*mk_lang_assert(a);*/
	/*mk_lang_assert(b);*/

	ret = *a == *b;
	return ret;
}


#endif
