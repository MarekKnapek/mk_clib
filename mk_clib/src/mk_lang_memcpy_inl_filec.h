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


#define mk_lang_overlap_t_name mk_lang_concat(mk_lang_memcpy_inl_defd_name, _filec_overlap)
#define mk_lang_overlap_t_base mk_lang_memcpy_inl_defd_base
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#define mk_lang_memcpy_inl_filec_overlap mk_lang_concat(mk_lang_concat(mk_lang_memcpy_inl_defd_name, _filec_overlap), _fn)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_memcpy_inl_defd_fn(mk_lang_memcpy_inl_defd_prt const dst, mk_lang_memcpy_inl_defd_prct const src, mk_lang_types_usize_t const len) mk_lang_noexcept
{
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	if(!mk_lang_constexpr_is_constant_evaluated_test && sizeof(*dst) == 1)
	{
		mk_lang_assert(dst);
		mk_lang_assert(src);
		mk_lang_assert(len >= 0);
		mk_lang_assert(dst != src);
		mk_lang_assert(!mk_lang_memcpy_inl_filec_overlap(dst, len, src, len));

		memcpy(((mk_lang_types_void_pt)(dst)), ((mk_lang_types_void_pct)(src)), len);
	}
	else
#endif
	{
		mk_lang_types_usize_t i mk_lang_constexpr_init;

		mk_lang_assert(dst);
		mk_lang_assert(src);
		mk_lang_assert(len >= 0);
		mk_lang_assert(dst != src);
		mk_lang_assert(!mk_lang_memcpy_inl_filec_overlap(dst, len, src, len));

		for(i = 0; i != len; ++i)
		{
			dst[i] = src[i];
		}
	}
}


#undef mk_lang_memcpy_inl_filec_overlap


#include "mk_lang_memcpy_inl_defu.h"


#undef mk_lang_memcpy_t_name
#undef mk_lang_memcpy_t_base
