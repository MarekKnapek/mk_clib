#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lang_memcmp_inl_defd.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lang_memcmp_inl_defd_fn(mk_lang_memcmp_inl_defd_pct const a, mk_lang_memcmp_inl_defd_pct const b, mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(len >= 0);

	if(a == b)
	{
		return mk_lang_true;
	}
	else
	{
		for(i = 0; i != len; ++i)
		{
			if(!(a[i] == b[i]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_true;
	}
}


#include "mk_lang_memcmp_inl_defu.h"


#undef mk_lang_memcmp_t_name
#undef mk_lang_memcmp_t_base
