#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
#include <memory.h> /* memcmp */
#include <wchar.h> /* wmemcmp */
#pragma intrinsic(memcmp)
#endif


#include "mk_lang_memcmp_inl_defd.h"


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_memcmp_inl_defd_fn(mk_lang_memcmp_inl_defd_type_pct const bufa, mk_lang_memcmp_inl_defd_type_pct const bufb, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	if(!mk_lang_constexpr_is_constant_evaluated_test && sizeof(mk_lang_memcmp_inl_defd_type_t) == 1)
	{
		mk_lang_assert(bufa);
		mk_lang_assert(bufb);
		mk_lang_assert(count >= 0);

		return memcmp(((mk_lang_types_void_pct)(bufa)), ((mk_lang_types_void_pct)(bufb)), count);
	}
	else
	#endif
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	if(!mk_lang_constexpr_is_constant_evaluated_test && sizeof(mk_lang_memcmp_inl_defd_type_t) == 2)
	{
		mk_lang_assert(bufa);
		mk_lang_assert(bufb);
		mk_lang_assert(count >= 0);

		return wmemcmp(((mk_lang_types_wchar_pct)(bufa)), ((mk_lang_types_wchar_pct)(bufb)), count);
	}
	else
	#endif
	{
		mk_lang_assert(bufa);
		mk_lang_assert(bufb);
		mk_lang_assert(count >= 0);

		mk_lang_assert(0); /* todo */
		return 0;
	}
}


#include "mk_lang_memcmp_inl_defu.h"


#undef mk_lang_memcmp_t_name
#undef mk_lang_memcmp_t_type
