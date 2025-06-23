#ifndef mk_include_guard_mk_lang_tchar_c
#define mk_include_guard_mk_lang_tchar_c
#include "mk_lang_tchar.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"


mk_lang_jumbo mk_lang_types_void_t mk_lang_tchar_to_bi_pchar_many(mk_lang_tchar_prct const tchars, mk_lang_types_pchar_prt const pchars, mk_lang_types_sint_t const count) mk_lang_noexcept
{
#if mk_lang_tchar_wchar_have
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(tchars || count == 0);
	mk_lang_assert(pchars || count == 0);
	mk_lang_assert(count >= 0);

	n = count;
	for(i = 0; i != n; ++i)
	{
		pchars[i] = ((mk_lang_types_pchar_t)(tchars[i]));
	}
#else
	mk_lang_assert(tchars || count == 0);
	mk_lang_assert(pchars || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(tchars != pchars);

	mk_lang_string_memcpy_pc_fn(pchars, tchars, ((mk_lang_types_usize_t)(count)));
#endif
}


#endif
