#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"


#define mk_lang_overlap_fn mk_lang_concat(mk_lang_overlap_, mk_lang_overlap_tn)


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_overlap_fn(mk_lang_overlap_t const* const arr1, int const len1, mk_lang_overlap_t const* const arr2, int const len2) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;

	mk_lang_assert(arr1);
	mk_lang_assert(len1 >= 1);
	mk_lang_assert(arr2);
	mk_lang_assert(len2 >= 1);

	for(i = 0; i != len1; ++i)
	{
		for(j = 0; j != len2; ++j)
		{
			if(arr1 + i == arr2 + j)
			{
				return mk_lang_true;
			}
		}
	}
	return mk_lang_false;
}


#undef mk_lang_overlap_fn
