#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lang_memset2_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_memset2_inl_defd_fn(mk_lang_memset2_inl_defd_type_pt const dst, mk_lang_memset2_inl_defd_type_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_memset2_inl_defd_type_t val mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_lang_memset2_inl_defd_type_assign(&val, src);
	n = count;
	for(i = 0; i != n; ++i)
	{
		mk_lang_memset2_inl_defd_type_assign(&dst[i], &val);
	}
}


#include "mk_lang_memset2_inl_defu.h"
