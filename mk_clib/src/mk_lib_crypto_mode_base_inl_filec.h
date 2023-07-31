#include "mk_lang_alignas.h"
#include "mk_lang_alignof.h"
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_uint8.h"


#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has))
#include <immintrin.h> /* _mm_load_ps _mm_store_ps _mm_xor_ps */
#endif


#include "mk_lib_crypto_mode_base_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_base_inl_defd_xor3(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pct const b, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has) && (mk_lib_crypto_mode_base_inl_defd_len == 16))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse())
	#endif
	{
		__m128 ta;
		__m128 tb;

		mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0);
		mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0);
		mk_lang_assert((((mk_lang_types_uintptr_t)(c)) & 0xf) == 0);

		ta = _mm_load_ps(((float const*)(a)));
		tb = _mm_load_ps(((float const*)(b)));
		ta = _mm_xor_ps(ta, tb);
		_mm_store_ps(((float*)(c)), ta);
	}
	else
	#endif
	{
		for(i = 0; i != mk_lib_crypto_mode_base_inl_defd_len; ++i)
		{
			mk_sl_cui_uint8_xor3(&a[i], &b[i], &c[i]);
		}
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lib_crypto_mode_base_inl_defd_xor2(mk_sl_cui_uint8_pt const a, mk_sl_cui_uint8_pct const b) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	#if((mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && (defined _MSC_FULL_VER && _MSC_FULL_VER >= mk_lang_msvc_full_ver_2008_sp_1) && (mk_lang_alignas_has && mk_lang_alignof_has) && (mk_lib_crypto_mode_base_inl_defd_len == 16))
	#if(!mk_lang_constexpr_is_constant_evaluated)
	if(mk_lang_cpuid_has_sse())
	#else
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_sse())
	#endif
	{
		__m128 ta;
		__m128 tb;

		mk_lang_assert((((mk_lang_types_uintptr_t)(a)) & 0xf) == 0);
		mk_lang_assert((((mk_lang_types_uintptr_t)(b)) & 0xf) == 0);

		ta = _mm_load_ps(((float const*)(a)));
		tb = _mm_load_ps(((float const*)(b)));
		ta = _mm_xor_ps(ta, tb);
		_mm_store_ps(((float*)(a)), ta);
	}
	else
	#endif
	{
		for(i = 0; i != mk_lib_crypto_mode_base_inl_defd_len; ++i)
		{
			mk_sl_cui_uint8_xor2(&a[i], &b[i]);
		}
	}
}


#include "mk_lib_crypto_mode_base_inl_defu.h"


#undef mk_lib_crypto_mode_base_t_name
#undef mk_lib_crypto_mode_base_t_len
