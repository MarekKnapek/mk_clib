#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
#include <string.h>
#pragma intrinsic(strlen)
#pragma intrinsic(wcslen)
#endif


#include "mk_lang_strlen_inl_defd.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_lang_strlen_inl_defd_fn(mk_lang_strlen_inl_defd_pct const str) mk_lang_noexcept
{
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	if(!mk_lang_constexpr_is_constant_evaluated_test && sizeof(*str) == 1)
	{
		mk_lang_types_usize_t len;

		mk_lang_assert(str);

		len = strlen(((mk_lang_types_pchar_pct)(str)));
		return len;
	}
	else
#endif
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	if(!mk_lang_constexpr_is_constant_evaluated_test && sizeof(*str) == 2)
	{
		mk_lang_types_usize_t len;

		mk_lang_assert(str);

		len = wcslen(((mk_lang_types_wchar_pct)(str)));
		return len;
	}
	else
#endif
	{
		mk_lang_strlen_inl_defd_pct ptr mk_lang_constexpr_init;
		mk_lang_types_usize_t len mk_lang_constexpr_init;

		mk_lang_assert(str);

		ptr = str;
		while(ptr[0] != ((mk_lang_strlen_inl_defd_t)(0)))
		{
			++ptr;
		}
		len = ((mk_lang_types_usize_t)(ptr - str));
		return len;
	}
}


#include "mk_lang_strlen_inl_defu.h"


#undef mk_lang_strlen_t_name
#undef mk_lang_strlen_t_base
