#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


#if !defined(mk_lang_overlap_name) && defined(mk_lang_overlap_tn)
#define mk_lang_overlap_name mk_lang_overlap_tn
#endif
#if !defined(mk_lang_overlap_t) && defined(mk_lang_overlap_tt)
#define mk_lang_overlap_t mk_lang_overlap_tt
#endif
#define mk_lang_overlap_fn mk_lang_concat(mk_lang_overlap_, mk_lang_overlap_name)


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_overlap_fn(mk_lang_overlap_t const* const arr1, mk_lang_size_t const len1, mk_lang_overlap_t const* const arr2, mk_lang_size_t const len2) mk_lang_noexcept
{
	mk_lang_size_t i mk_lang_constexpr_init;
	mk_lang_size_t j mk_lang_constexpr_init;

	mk_lang_assert(arr1);
	mk_lang_assert(arr2);

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


#undef mk_lang_overlap_name
#undef mk_lang_overlap_t
