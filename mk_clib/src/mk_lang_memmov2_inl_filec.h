#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lang_memmov2_inl_defd.h"


#define mk_lang_memmov2_inl_filec_overlap_name mk_lang_concat(mk_lang_memmov2_inl_defd_name, _zzz_overlap)
#define mk_lang_overlap_t_name mk_lang_memmov2_inl_filec_overlap_name
#define mk_lang_overlap_t_type mk_lang_memmov2_inl_defd_type_t
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#include "mk_lang_overlap_inl_fileu.h"
#define mk_lang_memmov2_inl_filec_overlap_fn mk_lang_concat(mk_lang_memmov2_inl_filec_overlap_name, _fn)
#define mk_lang_memmov2_inl_filec_overlap_fn2 mk_lang_concat(mk_lang_memmov2_inl_filec_overlap_name, _fn2)

#define mk_lang_memmov2_inl_filec_memcpy2_name mk_lang_concat(mk_lang_memmov2_inl_defd_name, _zzz_memcpy)
#define mk_lang_memcpy2_t_name mk_lang_memmov2_inl_filec_memcpy2_name
#define mk_lang_memcpy2_t_tn mk_lang_memmov2_inl_defd_tn
#include "mk_lang_memcpy2_inl_fileh.h"
#include "mk_lang_memcpy2_inl_filec.h"
#include "mk_lang_memcpy2_inl_fileu.h"
#define mk_lang_memmov2_inl_filec_memcpy2_fn mk_lang_concat(mk_lang_memmov2_inl_filec_memcpy2_name, _fn)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_memmov2_inl_defd_fn(mk_lang_memmov2_inl_defd_type_pt const dst, mk_lang_memmov2_inl_defd_type_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t overlap mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	overlap = mk_lang_memmov2_inl_filec_overlap_fn2(dst, count, src, count);
	switch(overlap)
	{
		case 0: /* no overlap */
		{
			mk_lang_memmov2_inl_filec_memcpy2_fn(dst, src, count);
		}
		break;
		case 1: /* arr1 is on lower address */
		{
			n = count;
			for(i = 0; i != n; ++i)
			{
				dst[i] = src[i];
			}
		}
		break;
		case 2: /* arr2 is on lower address */
		{
			n = count;
			for(i = 0; i != n; ++i)
			{
				dst[(n - 1) - i] = src[(n - 1) - i];
			}
		}
		break;
		case 3: /* exact match */
		{
		}
		break;
	}
}


#undef mk_lang_memmov2_inl_filec_overlap_name
#undef mk_lang_memmov2_inl_filec_overlap_fn
#undef mk_lang_memmov2_inl_filec_overlap_fn2

#undef mk_lang_memmov2_inl_filec_memcpy2_name
#undef mk_lang_memmov2_inl_filec_memcpy2_fn


#include "mk_lang_memmov2_inl_defu.h"
