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

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(arr1 || len1 == 0);
	mk_lang_assert(len1 >= 0);
	mk_lang_assert(arr2 || len2 == 0);
	mk_lang_assert(len2 >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		#include "mk_lang_warning_msvc_push_c4826.h"
		return
			(((mk_lang_types_uintptr_t)(arr1)) >= ((mk_lang_types_uintptr_t)(arr2)) && ((mk_lang_types_uintptr_t)(((mk_lang_types_sintptr_t)(arr1)))) < ((mk_lang_types_uintptr_t)(arr2 + len2))) ||
			(((mk_lang_types_uintptr_t)(arr2)) >= ((mk_lang_types_uintptr_t)(arr1)) && ((mk_lang_types_uintptr_t)(((mk_lang_types_sintptr_t)(arr2)))) < ((mk_lang_types_uintptr_t)(arr1 + len1)));
		#include "mk_lang_warning_msvc_pop.h"
	}
	else
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
}


#include "mk_lang_overlap_inl_defu.h"
