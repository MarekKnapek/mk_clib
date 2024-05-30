#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#if defined __SANITIZE_ADDRESS__ && __SANITIZE_ADDRESS__ == 1
#include <string.h> /* memmove */
#endif


#include "mk_lang_memmove_inl_defd.h"


#define mk_lang_memmove_inl_filec_memcpy_name mk_lang_concat(mk_lang_memmove_inl_defd_name, _zzz_memcpy)
#define mk_lang_memcpy_t_name mk_lang_memmove_inl_filec_memcpy_name
#define mk_lang_memcpy_t_type mk_lang_memmove_inl_defd_type_t
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"
#define mk_lang_memmove_inl_filec_memcpy_fn mk_lang_concat(mk_lang_memmove_inl_filec_memcpy_name, _fn)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_memmove_inl_defd_fn(mk_lang_memmove_inl_defd_type_pt const dst, mk_lang_memmove_inl_defd_type_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(count >= 0);
	mk_lang_assert(dst != src);

	#if defined __SANITIZE_ADDRESS__ && __SANITIZE_ADDRESS__ == 1
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		memmove(dst, src, count * sizeof(mk_lang_memmove_inl_defd_type_t));
	}
	else
	#endif
	{
		if(!(
			(dst >= src && dst < src + count) ||
			(src >= dst && src < dst + count)
		))
		{
			mk_lang_memmove_inl_filec_memcpy_fn(dst, src, count);
		}
		else if(!(dst >= src && dst < src + count))
		{
			n = count;
			for(i = 0; i != n; ++i)
			{
				dst[i] = src[i];
			}
		}
		else
		{
			n = count;
			for(i = 0; i != n; ++i)
			{
				dst[(n - 1) - i] = src[(n - 1) - i];
			}
		}
	}
}


#undef mk_lang_memmove_inl_filec_memcpy_name
#undef mk_lang_memmove_inl_filec_memcpy_fn


#include "mk_lang_memmove_inl_defu.h"


#undef mk_lang_memmove_t_name
#undef mk_lang_memmove_t_type
