#ifndef mk_include_guard_mk_lang_str_len_c
#define mk_include_guard_mk_lang_str_len_c
#include "mk_lang_str_len.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_str_len_n(mk_lang_types_pchar_pct const str) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str);

	len = 0;
	while(str[len] != '\0')
	{
		mk_lang_assert(len < mk_lang_limits_sint_max);
		++len;
	}
	return len;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_str_len_w(mk_lang_types_wchar_pct const str) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str);

	len = 0;
	while(str[len] != L'\0')
	{
		mk_lang_assert(len < mk_lang_limits_sint_max);
		++len;
	}
	return len;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_str_len_t(mk_lang_tchar_pct const str) mk_lang_noexcept
{
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(str);

	len = mk_lang_tchar_dispatch(mk_lang_str_len_)(str);
	return len;
}


#endif
