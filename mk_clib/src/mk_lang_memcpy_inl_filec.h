#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
#include <memory.h>
#pragma intrinsic(memcpy)
#endif


#include "mk_lang_memcpy_inl_defd.h"


#define mk_lang_memcpy_inl_filec_overlap_name mk_lang_concat(mk_lang_memcpy_inl_defd_name, _zzz_overlap)
#define mk_lang_overlap_t_name mk_lang_memcpy_inl_filec_overlap_name
#define mk_lang_overlap_t_type mk_lang_memcpy_inl_defd_type_t
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#define mk_lang_memcpy_inl_filec_overlap_fn mk_lang_concat(mk_lang_memcpy_inl_filec_overlap_name, _fn)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_memcpy_inl_defd_fn(mk_lang_memcpy_inl_defd_type_prt const dst, mk_lang_memcpy_inl_defd_type_prct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(dst);
		mk_lang_assert(src);
		mk_lang_assert(count >= 0);
		mk_lang_assert(dst != src);
		mk_lang_assert(!mk_lang_memcpy_inl_filec_overlap_fn(dst, count, src, count));

		memcpy(((mk_lang_types_void_pt)(dst)), ((mk_lang_types_void_pct)(src)), count * sizeof(mk_lang_memcpy_inl_defd_type_t));
	}
	else
#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;

		mk_lang_assert(dst);
		mk_lang_assert(src);
		mk_lang_assert(count >= 0);
		mk_lang_assert(dst != src);
		mk_lang_assert(!mk_lang_memcpy_inl_filec_overlap_fn(dst, count, src, count));

		n = count;
		for(i = 0; i != n; ++i)
		{
			dst[i] = src[i];
		}
	}
}


#undef mk_lang_memcpy_inl_filec_overlap_name
#undef mk_lang_memcpy_inl_filec_overlap_fn


#include "mk_lang_memcpy_inl_defu.h"


#undef mk_lang_memcpy_t_name
#undef mk_lang_memcpy_t_type
