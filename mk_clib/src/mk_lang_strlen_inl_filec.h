#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lang_strlen_inl_defd.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_lang_strlen_inl_defd_fn(mk_lang_strlen_inl_defd_pct const str) mk_lang_noexcept
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


#include "mk_lang_strlen_inl_defu.h"


#undef mk_lang_strlen_t_name
#undef mk_lang_strlen_t_base
