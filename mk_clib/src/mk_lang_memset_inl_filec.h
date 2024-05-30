#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
#include <memory.h>
#pragma intrinsic(memset)
#endif


#include "mk_lang_memset_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_memset_inl_defd_fn(mk_lang_memset_inl_defd_type_pt const dst, mk_lang_memset_inl_defd_type_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(dst);
		mk_lang_assert(src);
		mk_lang_assert(count >= 0);

		memset(((mk_lang_types_void_pt)(dst)), ((mk_lang_types_sint_t)(*((mk_lang_types_uchar_pct)(src)))), count * sizeof(mk_lang_memset_inl_defd_type_t));
	}
	else
#endif
	{
		mk_lang_memset_inl_defd_type_t v mk_lang_constexpr_init;
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;

		mk_lang_assert(dst);
		mk_lang_assert(src);
		mk_lang_assert(count >= 0);

		v = *src;
		n = count;
		for(i = 0; i != n; ++i)
		{
			dst[i] = v;
		}
	}
}


#include "mk_lang_memset_inl_defu.h"


#undef mk_lang_memset_t_name
#undef mk_lang_memset_t_type
