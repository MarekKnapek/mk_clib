#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lang_memset_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_memset_inl_defd_fn(mk_lang_memset_inl_defd_pt const dst, mk_lang_memset_inl_defd_pct const src, mk_lang_types_usize_t const len) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(len >= 0);

	for(i = 0; i != len; ++i)
	{
		dst[i] = *src;
	}
}


#include "mk_lang_memset_inl_defu.h"


#undef mk_lang_memset_t_name
#undef mk_lang_memset_t_base
