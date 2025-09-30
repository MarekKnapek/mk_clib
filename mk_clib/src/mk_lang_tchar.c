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


#define mk_lang_memclr1_t_name mk_lang_tchar_memclr
#define mk_lang_memclr1_t_type mk_lang_tchar_t
#include "mk_lang_memclr1_inl_filec.h"
#include "mk_lang_memclr1_inl_fileu.h"
#define mk_lang_memcmp1_t_name mk_lang_tchar_memcmp
#define mk_lang_memcmp1_t_type mk_lang_tchar_t
#include "mk_lang_memcmp1_inl_filec.h"
#include "mk_lang_memcmp1_inl_fileu.h"
#define mk_lang_memcpy1_t_name mk_lang_tchar_memcpy
#define mk_lang_memcpy1_t_type mk_lang_tchar_t
#include "mk_lang_memcpy1_inl_filec.h"
#include "mk_lang_memcpy1_inl_fileu.h"
#define mk_lang_memmov1_t_name mk_lang_tchar_memmov
#define mk_lang_memmov1_t_type mk_lang_tchar_t
#include "mk_lang_memmov1_inl_filec.h"
#include "mk_lang_memmov1_inl_fileu.h"
#define mk_lang_memset1_t_name mk_lang_tchar_memset
#define mk_lang_memset1_t_type mk_lang_tchar_t
#include "mk_lang_memset1_inl_filec.h"
#include "mk_lang_memset1_inl_fileu.h"


#endif
