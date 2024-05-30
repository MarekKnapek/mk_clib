#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lang_overlap_inl_defd.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lang_overlap_inl_defd_fn(mk_lang_overlap_inl_defd_type_pct const arr1, mk_lang_types_usize_t const len1, mk_lang_overlap_inl_defd_type_pct const arr2, mk_lang_types_usize_t const len2) mk_lang_noexcept
{
	mk_lang_types_usize_t it1 mk_lang_constexpr_init;
	mk_lang_types_usize_t it2 mk_lang_constexpr_init;

	mk_lang_assert(arr1);
	mk_lang_assert(len1 >= 0);
	mk_lang_assert(arr2);
	mk_lang_assert(len2 >= 0);

	if(mk_lang_constexpr_is_constant_evaluated_test)
	{
		for(it1 = 0; it1 != len1; ++it1)
		{
			for(it2 = 0; it2 != len2; ++it2)
			{
				if(arr1 + it1 == arr2 + it2)
				{
					return mk_lang_true;
				}
			}
		}
		return mk_lang_false;
	}
	else
	{
		return
			(arr1 >= arr2 && arr1 < arr2 + len2) ||
			(arr2 >= arr1 && arr2 < arr1 + len1);
	}
}


#include "mk_lang_overlap_inl_defu.h"


#undef mk_lang_overlap_t_name
#undef mk_lang_overlap_t_type
