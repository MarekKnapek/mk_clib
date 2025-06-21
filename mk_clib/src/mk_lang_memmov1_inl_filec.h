#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_lang_memmov1_inl_defd.h"


#define mk_lang_memmov1_inl_filec_overlap_name mk_lang_concat(mk_lang_memmov1_inl_defd_name, _zzz_overlap)
#define mk_lang_overlap_t_name mk_lang_memmov1_inl_filec_overlap_name
#define mk_lang_overlap_t_type mk_lang_memmov1_inl_defd_type_t
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#include "mk_lang_overlap_inl_fileu.h"
#define mk_lang_memmov1_inl_filec_overlap_fn mk_lang_concat(mk_lang_memmov1_inl_filec_overlap_name, _fn)

#define mk_lang_memmov1_inl_filec_memcpy1_name mk_lang_concat(mk_lang_memmov1_inl_defd_name, _zzz_memcpy)
#define mk_lang_memcpy1_t_name mk_lang_memmov1_inl_filec_memcpy1_name
#define mk_lang_memcpy1_t_type mk_lang_memmov1_inl_defd_type_t
#include "mk_lang_memcpy1_inl_fileh.h"
#include "mk_lang_memcpy1_inl_filec.h"
#include "mk_lang_memcpy1_inl_fileu.h"
#define mk_lang_memmov1_inl_filec_memcpy1_fn mk_lang_concat(mk_lang_memmov1_inl_filec_memcpy1_name, _fn)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_memmov1_inl_defd_fn(mk_lang_memmov1_inl_defd_type_pt const dst, mk_lang_memmov1_inl_defd_type_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(!mk_lang_memmov1_inl_filec_overlap_fn(dst, count, src, count))
	{
		mk_lang_memmov1_inl_filec_memcpy1_fn(dst, src, count);
	}
	else
	{
		#include "mk_lang_warning_msvc_push_c4826.h"
		/*if(((mk_lang_types_uintptr_t)(dst)) >= ((mk_lang_types_uintptr_t)(src)) && ((mk_lang_types_uintptr_t)(dst)) < ((mk_lang_types_uintptr_t)(src + count)))*/
		if(dst >= src && dst < src + count)
		#include "mk_lang_warning_msvc_pop.h"
		{
			n = count;
			for(i = 0; i != n; ++i)
			{
				dst[(n - 1) - i] = src[(n - 1) - i];
			}
		}
		else
		{
			n = count;
			for(i = 0; i != n; ++i)
			{
				dst[i] = src[i];
			}
		}
	}
}


#undef mk_lang_memmov1_inl_filec_overlap_name
#undef mk_lang_memmov1_inl_filec_overlap_fn

#undef mk_lang_memmov1_inl_filec_memcpy1_name
#undef mk_lang_memmov1_inl_filec_memcpy1_fn


#include "mk_lang_memmov1_inl_defu.h"
