#ifndef mk_include_guard_mk_lang_str_match_c
#define mk_include_guard_mk_lang_str_match_c
#include "mk_lang_str_match.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_encoding.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"


#if !mk_lang_encoding_is_ascii
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_str_match_k_letters[] =
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
};
#endif

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_pchar_t mk_lang_str_match_to_lower(mk_lang_types_pchar_t const pchar) mk_lang_noexcept
{
#if !mk_lang_encoding_is_ascii
	mk_lang_types_pchar_t res mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countof(mk_lang_str_match_k_letters) % 2 == 0);

	res = pchar;
	n = mk_lang_countof(mk_lang_str_match_k_letters) / 2;
	for(i = 0; i != n; ++i)
	{
		if(pchar == mk_lang_str_match_k_letters[i])
		{
			res = mk_lang_str_match_k_letters[i + mk_lang_countof(mk_lang_str_match_k_letters) / 2];
			break;
		}
	}
	return res;
#else
	mk_lang_types_pchar_t res mk_lang_constexpr_init;

	res = pchar;
	if(pchar >= 'A' && pchar <= 'Z')
	{
		res = 'a' + (pchar - 'A');
	}
	return res;
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_pchar_t mk_lang_str_match_to_narrow(mk_lang_types_wchar_t const wchar) mk_lang_noexcept
{
	mk_lang_types_pchar_t pchar mk_lang_constexpr_init;

	pchar = ((mk_lang_types_pchar_t)(wchar));
	return pchar;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lang_str_match_n(mk_lang_types_pchar_pct const str_a_buf, mk_lang_types_sint_t const str_a_len, mk_lang_types_pchar_pct const str_b_buf, mk_lang_types_sint_t const str_b_len) mk_lang_noexcept
{
	mk_lang_types_bool_t res mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(str_a_buf || str_a_len == 0);
	mk_lang_assert(str_a_len >= 0);
	mk_lang_assert(str_b_buf || str_b_len == 0);
	mk_lang_assert(str_b_len >= 0);

	res = mk_lang_false;
	if(str_a_len == str_b_len)
	{
		n = str_a_len;
		for(i = 0; i != n; ++i)
		{
			if(mk_lang_str_match_to_lower(str_a_buf[i]) != mk_lang_str_match_to_lower(str_b_buf[i]))
			{
				break;
			}
		}
		res = i == n;
	}
	return res;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lang_str_match_w(mk_lang_types_wchar_pct const str_a_buf, mk_lang_types_sint_t const str_a_len, mk_lang_types_pchar_pct const str_b_buf, mk_lang_types_sint_t const str_b_len) mk_lang_noexcept
{
	mk_lang_types_bool_t res mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(str_a_buf || str_a_len == 0);
	mk_lang_assert(str_a_len >= 0);
	mk_lang_assert(str_b_buf || str_b_len == 0);
	mk_lang_assert(str_b_len >= 0);

	res = mk_lang_false;
	if(str_a_len == str_b_len)
	{
		n = str_a_len;
		for(i = 0; i != n; ++i)
		{
			if(mk_lang_str_match_to_lower(mk_lang_str_match_to_narrow(str_a_buf[i])) != mk_lang_str_match_to_lower(str_b_buf[i]))
			{
				break;
			}
		}
		res = i == n;
	}
	return res;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lang_str_match_t(mk_lang_tchar_pct const str_a_buf, mk_lang_types_sint_t const str_a_len, mk_lang_types_pchar_pct const str_b_buf, mk_lang_types_sint_t const str_b_len) mk_lang_noexcept
{
	mk_lang_types_bool_t res mk_lang_constexpr_init;

	mk_lang_assert(str_a_buf || str_a_len == 0);
	mk_lang_assert(str_a_len >= 0);
	mk_lang_assert(str_b_buf || str_b_len == 0);
	mk_lang_assert(str_b_len >= 0);

	res = mk_lang_tchar_dispatch(mk_lang_str_match_)(str_a_buf, str_a_len, str_b_buf, str_b_len);
	return res;
}


#endif
