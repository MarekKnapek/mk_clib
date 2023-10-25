#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if !defined(mk_lang_overlap_name) && defined(mk_lang_overlap_tn)
#define mk_lang_overlap_name mk_lang_overlap_tn
#endif
#if !defined(mk_lang_overlap_t) && defined(mk_lang_overlap_tt)
#define mk_lang_overlap_t mk_lang_overlap_tt
#endif
#define mk_lang_overlap_fn mk_lang_concat(mk_lang_overlap_, mk_lang_overlap_name)


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_lang_overlap_fn(mk_lang_overlap_t const* const arr1, mk_lang_types_usize_t const len1, mk_lang_overlap_t const* const arr2, mk_lang_types_usize_t const len2) mk_lang_noexcept
{
#if mk_lang_constexpr_has
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_usize_t j mk_lang_constexpr_init;

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
#else
	unsigned char const* p1;
	unsigned char const* p2;
	mk_lang_types_usize_t l1;
	mk_lang_types_usize_t l2;
	mk_lang_types_bool_t ret;

	mk_lang_assert(arr1);
	mk_lang_assert(arr2);

	p1 = ((unsigned char const*)(arr1));
	p2 = ((unsigned char const*)(arr2));
	l1 = len1 * sizeof(mk_lang_overlap_t);
	l2 = len2 * sizeof(mk_lang_overlap_t);

	ret =
		(p1 >= p2 && p1 < p2 + l2) ||
		(p2 >= p1 && p2 < p1 + l1);
	return ret;
#endif
}


#undef mk_lang_overlap_fn


#undef mk_lang_overlap_name
#undef mk_lang_overlap_t
