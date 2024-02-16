#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#if defined __SANITIZE_ADDRESS__ && __SANITIZE_ADDRESS__ == 1
#include <string.h> /* memmove */
#endif


#include "mk_lang_memmove_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_memmove_inl_defd_fn(mk_lang_memmove_inl_defd_prt const dst, mk_lang_memmove_inl_defd_prct const src, mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(len >= 0);
	mk_lang_assert(dst != src);

	#if defined __SANITIZE_ADDRESS__ && __SANITIZE_ADDRESS__ == 1
	#if !mk_lang_constexpr_is_constant_evaluated
	if(1)
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#endif
	{
		memmove(dst, src, len);
	}
	else
	#endif
	{
		if(!(dst >= src && dst < src + len))
		{
			for(i = 0; i != len; ++i)
			{
				dst[i] = src[i];
			}
		}
		else
		{
			for(i = 0; i != len; ++i)
			{
				dst[(len - 1) - i] = src[(len - 1) - i];
			}
		}
	}
}


#include "mk_lang_memmove_inl_defu.h"


#undef mk_lang_memmove_t_name
#undef mk_lang_memmove_t_base
