#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
#include <memory.h> /* memcmp */
#pragma intrinsic(memcmp)
#endif


#include "mk_lang_memcmp1_inl_defd.h"


#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_memcmp1_inl_defd_fn(mk_lang_memcmp1_inl_defd_type_pct const bufa, mk_lang_memcmp1_inl_defd_type_pct const bufb, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test && bufa && bufb && count >= 1)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_assert(bufa);
		mk_lang_assert(bufb);
		mk_lang_assert(count >= 1);

		return memcmp(((mk_lang_types_void_pct)(bufa)), ((mk_lang_types_void_pct)(bufb)), count * sizeof(mk_lang_memcmp1_inl_defd_type_t));
	}
	else
	#endif
	{
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;

		#include "mk_lang_warning_msvc_push_c4296.h"
		#include "mk_lang_warning_gcc_push_type_limits.h"
		mk_lang_assert(bufa || count == 0);
		mk_lang_assert(bufb || count == 0);
		mk_lang_assert(count >= 0);
		#include "mk_lang_warning_gcc_pop.h"
		#include "mk_lang_warning_msvc_pop.h"

		n = count;
		for(i = 0; i != n; ++i)
		{
			if(bufa[i] < bufb[i])
			{
				return -1;
			}
			else if(bufb[i] < bufa[i])
			{
				return +1;
			}
			else
			{
				#include "mk_lang_warning_clang_push_float_equal.h"
				mk_lang_assert(bufa[i] == bufb[i]);
				#include "mk_lang_warning_clang_pop.h"
			}
		}
		return 0;
	}
}
#include "mk_lang_warning_msvc_pop.h"


#include "mk_lang_memcmp1_inl_defu.h"
