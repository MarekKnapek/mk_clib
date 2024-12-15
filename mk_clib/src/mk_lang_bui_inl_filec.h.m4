include(`mk_lang_bui_inl.m')dnl
#include "mk_lang_arch.h"
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_compiler.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_encoding.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_llong.h"
#include "mk_lang_msvc.h"
#include "mk_lang_noalias.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2005
#include <intrin.h>
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2012 && mk_lang_arch == mk_lang_arch_x8664
#pragma intrinsic(_umul128)
#endif
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && (mk_lang_arch == mk_lang_arch_ia64 || mk_lang_arch == mk_lang_arch_x8664 || mk_lang_arch == mk_lang_arch_arm64)
#pragma intrinsic(__umulh)
#endif
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && mk_lang_arch == mk_lang_arch_x8664
#pragma intrinsic(__popcnt64)
#endif
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)
#pragma intrinsic(__popcnt16)
#pragma intrinsic(__popcnt)
#endif
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
#include <intrin.h>
#include <stdlib.h>
#pragma intrinsic(_rotr8)
#pragma intrinsic(_rotl8)
#pragma intrinsic(_rotr16)
#pragma intrinsic(_rotl16)
#pragma intrinsic(_rotr)
#pragma intrinsic(_rotl)
#pragma intrinsic(_lrotr)
#pragma intrinsic(_lrotl)
#pragma intrinsic(_rotr64)
#pragma intrinsic(_rotl64)
#endif
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_arch == mk_lang_arch_x8664
#pragma intrinsic(__ull_rshift)
#endif
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664)
#pragma intrinsic(__emulu)
#endif
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2005 && (mk_lang_arch == mk_lang_arch_ia64 || mk_lang_arch == mk_lang_arch_x8664 || mk_lang_arch == mk_lang_arch_arm64)
#pragma intrinsic(_BitScanForward64)
#pragma intrinsic(_BitScanReverse64)
#endif
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2005
#pragma intrinsic(_BitScanForward)
#pragma intrinsic(_BitScanReverse)
#endif
#endif


#include "mk_lang_bui_inl_defd.h"


mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_from_base(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_base_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui_inl_defd_t)(*b));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_from_bi_bool(mk_lang_bui_inl_defd_pt const a, mk_lang_types_bool_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui_inl_defd_t)(!!*b));
}}

mm_per_bi_nobool(`mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_from_bi_$1(mk_lang_bui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui_inl_defd_t)(*b));
}}
')
mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_to_base(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_base_pt const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_base_t)(*a));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_to_bi_bool(mk_lang_bui_inl_defd_pct const a, mk_lang_types_bool_pt const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_types_bool_t)(!!*a));
}}

mm_per_bi_nobool(`mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_to_bi_$1(mk_lang_bui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_types_$1_t)(*a));
}}
')
mm_per_bui(`mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_from_buis_$1_le(mk_lang_bui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
#if mk_lang_bui_inl_defd_sizeof_d <= mk_lang_sizeof_bi_$1_t
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui_inl_defd_t)(*b));
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_bui_inl_defd_sizeof_d > mk_lang_sizeof_bi_$1_t);
	mk_lang_static_assert(mk_lang_bui_inl_defd_sizeof_d % mk_lang_sizeof_bi_$1_t == 0);

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lang_bui_inl_defd_sizeof_d / mk_lang_sizeof_bi_$1_t;
	ta = ((mk_lang_bui_inl_defd_t)(b[n - 1 - 0]));
	for(i = 1; i != n; ++i)
	{
		ta = ((mk_lang_bui_inl_defd_t)(ta << (mk_lang_sizeof_bi_$1_t * mk_lang_charbit)));
		ta = ((mk_lang_bui_inl_defd_t)(ta | ((mk_lang_bui_inl_defd_t)(b[n - 1 - i]))));
	}
	*a = ta;
#endif
}}
')
mm_per_bui(`mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_to_buis_$1_le(mk_lang_bui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
#if mk_lang_bui_inl_defd_sizeof_d <= mk_lang_sizeof_bi_$1_t
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_types_$1_t)(*a));
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_bui_inl_defd_sizeof_d > mk_lang_sizeof_bi_$1_t);
	mk_lang_static_assert(mk_lang_bui_inl_defd_sizeof_d % mk_lang_sizeof_bi_$1_t == 0);

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lang_bui_inl_defd_sizeof_d / mk_lang_sizeof_bi_$1_t;
	ta = *a;
	b[0 + 0] = ((mk_lang_types_$1_t)(ta));
	for(i = 1; i != n; ++i)
	{
		ta = ((mk_lang_bui_inl_defd_t)(ta >> (mk_lang_sizeof_bi_$1_t * mk_lang_charbit)));
		b[0 + i] = ((mk_lang_types_$1_t)(ta));
	}
#endif
}}
')
mm_per_bui(`mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_from_buis_$1_be(mk_lang_bui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
#if mk_lang_bui_inl_defd_sizeof_d <= mk_lang_sizeof_bi_$1_t
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui_inl_defd_t)(*b));
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_bui_inl_defd_sizeof_d > mk_lang_sizeof_bi_$1_t);
	mk_lang_static_assert(mk_lang_bui_inl_defd_sizeof_d % mk_lang_sizeof_bi_$1_t == 0);

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lang_bui_inl_defd_sizeof_d / mk_lang_sizeof_bi_$1_t;
	ta = ((mk_lang_bui_inl_defd_t)(b[0 + 0]));
	for(i = 1; i != n; ++i)
	{
		ta = ((mk_lang_bui_inl_defd_t)(ta << (mk_lang_sizeof_bi_$1_t * mk_lang_charbit)));
		ta = ((mk_lang_bui_inl_defd_t)(ta | ((mk_lang_bui_inl_defd_t)(b[0 + i]))));
	}
	*a = ta;
#endif
}}
')
mm_per_bui(`mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_to_buis_$1_be(mk_lang_bui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
#if mk_lang_bui_inl_defd_sizeof_d <= mk_lang_sizeof_bi_$1_t
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_types_$1_t)(*a));
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_bui_inl_defd_sizeof_d > mk_lang_sizeof_bi_$1_t);
	mk_lang_static_assert(mk_lang_bui_inl_defd_sizeof_d % mk_lang_sizeof_bi_$1_t == 0);

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lang_bui_inl_defd_sizeof_d / mk_lang_sizeof_bi_$1_t;
	ta = *a;
	b[n - 1 - 0] = ((mk_lang_types_$1_t)(ta));
	for(i = 1; i != n; ++i)
	{
		ta = ((mk_lang_bui_inl_defd_t)(ta >> (mk_lang_sizeof_bi_$1_t * mk_lang_charbit)));
		b[n - 1 - i] = ((mk_lang_types_$1_t)(ta));
	}
#endif
}}
')
mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_assign(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = *b;
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_set_zero(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_inl_defd_t)(0));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_set_max(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_set_one(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_inl_defd_t)(1));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_set_bit(mk_lang_bui_inl_defd_pt const x, mk_lang_types_sint_t const bit_idx) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(x);
	mk_lang_assert(bit_idx >= 0 && bit_idx < ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit)))));

	*x = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(1)) << bit_idx));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_set_mask(mk_lang_bui_inl_defd_pt const x, mk_lang_types_sint_t const bits_count) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
#if defined NDEBUG
#else
	mk_lang_bui_inl_defd_t tmp mk_lang_constexpr_init;
#endif

	mk_lang_assert(x);
	mk_lang_assert(bits_count >= 1 && bits_count <= ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit)))));

#if defined NDEBUG
	*x = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(1)) << ((mk_lang_types_sint_t)(bits_count - 1)))) - ((mk_lang_bui_inl_defd_t)(1)))) << ((mk_lang_types_sint_t)(1)))) + ((mk_lang_bui_inl_defd_t)(1))));
#else
	tmp = ((mk_lang_bui_inl_defd_t)(1));
	tmp = ((mk_lang_bui_inl_defd_t)(tmp << ((mk_lang_types_sint_t)(bits_count - 1))));
	tmp = ((mk_lang_bui_inl_defd_t)(tmp - ((mk_lang_bui_inl_defd_t)(1))));
	tmp = ((mk_lang_bui_inl_defd_t)(tmp << ((mk_lang_types_sint_t)(1))));
	tmp = ((mk_lang_bui_inl_defd_t)(tmp + ((mk_lang_bui_inl_defd_t)(1))));
	*x = tmp;
#endif
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_leading_zeros(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2005 && mk_lang_bui_inl_defd_sizebits_d <= 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		unsigned char nz mk_lang_constexpr_init;
		unsigned long index mk_lang_constexpr_init;

		mk_lang_assert(x);

		nz = ((unsigned char)(_BitScanReverse(&index, ((unsigned long)(*x)))));
		return nz ? ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d - 1)) - ((mk_lang_types_sint_t)(index)))) : ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d));
	}
	else
	#elif mk_lang_compiler_is_at_least_gcc(4, 1) && mk_lang_bui_inl_defd_sizebits_d <= 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(x);

		return *x == 0 ? mk_lang_bui_inl_defd_sizebits_d : __builtin_clzl(((unsigned long)(*x)));
	}
	else
	#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2005 && (mk_lang_arch == mk_lang_arch_ia64 || mk_lang_arch == mk_lang_arch_x8664 || mk_lang_arch == mk_lang_arch_arm64) && mk_lang_bui_inl_defd_sizebits_d <= 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		unsigned char nz mk_lang_constexpr_init;
		unsigned long index mk_lang_constexpr_init;

		mk_lang_assert(x);

		nz = ((unsigned char)(_BitScanReverse64(&index, ((unsigned __int64)(*x)))));
		return nz ? ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d - 1)) - ((mk_lang_types_sint_t)(index)))) : ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d));
	}
	else
	#elif mk_lang_compiler_is_at_least_gcc(4, 1) && mk_lang_llong_has && mk_lang_bui_inl_defd_sizebits_d <= 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(x);

		return *x == 0 ? mk_lang_bui_inl_defd_sizebits_d : __builtin_clzll(((unsigned long long)(*x)));
	}
	else
	#endif
	{
		mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
		mk_lang_types_sint_t cnt mk_lang_constexpr_init;
		mk_lang_types_sint_t n mk_lang_constexpr_init;
		mk_lang_bui_inl_defd_t yy mk_lang_constexpr_init;

		mk_lang_assert(x);

		if(((mk_lang_bui_inl_defd_t)(*x)) == ((mk_lang_bui_inl_defd_t)(0)))
		{
			return mk_lang_bui_inl_defd_sizebits_d;
		}
		xx = ((mk_lang_bui_inl_defd_t)(*x));
		cnt = mk_lang_bui_inl_defd_sizebits_d;
		n = cnt / 2;
		do
		{
			yy = ((mk_lang_bui_inl_defd_t)(xx >> n));
			if(yy != ((mk_lang_bui_inl_defd_t)(0)))
			{
				cnt -= n;
				xx = yy;
			}
			n /= 2;
		}while(n != 1);
		yy = ((mk_lang_bui_inl_defd_t)(xx >> 1));
		if(yy != ((mk_lang_bui_inl_defd_t)(0)))
		{
			return cnt - 2;
		}
		else
		{
			return cnt - ((mk_lang_types_sint_t)(xx));
		}
	}
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_leading_ones(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;

	mk_lang_assert(x);

	xx = ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(*x))));
	return mk_lang_bui_inl_defd_count_leading_zeros(&xx);
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_trailing_zeros(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2005 && mk_lang_bui_inl_defd_sizebits_d <= 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		unsigned char nz mk_lang_constexpr_init;
		unsigned long index mk_lang_constexpr_init;

		mk_lang_assert(x);

		nz = ((unsigned char)(_BitScanForward(&index, ((unsigned long)(*x)))));
		return nz ? ((mk_lang_types_sint_t)(index)) : ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d));
	}
	else
	#elif mk_lang_compiler_is_at_least_gcc(4, 1) && mk_lang_bui_inl_defd_sizebits_d <= 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(x);

		return *x == 0 ? mk_lang_bui_inl_defd_sizebits_d : __builtin_ctzl(((unsigned long)(*x)));
	}
	else
	#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2005 && (mk_lang_arch == mk_lang_arch_ia64 || mk_lang_arch == mk_lang_arch_x8664 || mk_lang_arch == mk_lang_arch_arm64) && mk_lang_bui_inl_defd_sizebits_d <= 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		unsigned char nz mk_lang_constexpr_init;
		unsigned long index mk_lang_constexpr_init;

		mk_lang_assert(x);

		nz = ((unsigned char)(_BitScanForward64(&index, ((unsigned __int64)(*x)))));
		return nz ? ((mk_lang_types_sint_t)(index)) : ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d));
	}
	else
	#elif mk_lang_compiler_is_at_least_gcc(4, 1) && mk_lang_llong_has && mk_lang_bui_inl_defd_sizebits_d <= 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(x);

		return *x == 0 ? mk_lang_bui_inl_defd_sizebits_d : __builtin_ctzll(((unsigned long long)(*x)));
	}
	else
	#endif
	{
		mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
		mk_lang_types_sint_t cnt mk_lang_constexpr_init;
		mk_lang_types_sint_t n mk_lang_constexpr_init;

		mk_lang_assert(x);

		if(((mk_lang_bui_inl_defd_t)(*x)) == ((mk_lang_bui_inl_defd_t)(0)))
		{
			return mk_lang_bui_inl_defd_sizebits_d;
		}
		xx = ((mk_lang_bui_inl_defd_t)(*x));
		cnt = 1;
		n = mk_lang_bui_inl_defd_sizebits_d / 2;
		do
		{
			if(((mk_lang_bui_inl_defd_t)(xx & ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(1)) << n)) - ((mk_lang_bui_inl_defd_t)(1)))))) == ((mk_lang_bui_inl_defd_t)(0)))
			{
				cnt += n;
				xx = ((mk_lang_bui_inl_defd_t)(xx >> n));
			}
			n /= 2;
		}while(n != 1);
		return cnt - ((mk_lang_types_sint_t)(((mk_lang_bui_inl_defd_t)((xx & ((mk_lang_bui_inl_defd_t)(1)))))));
	}
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_trailing_ones(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;

	mk_lang_assert(x);

	xx = ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(*x))));
	return mk_lang_bui_inl_defd_count_trailing_zeros(&xx);
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_sint_t mk_lang_bui_inl_defd_count_zeros_portable(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_sint_t cnt mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;

	mk_lang_assert(x);

	cnt = ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit))));
	xx = ((mk_lang_bui_inl_defd_t)(*x));
	while(xx != ((mk_lang_bui_inl_defd_t)(0)))
	{
		--cnt;
		xx = ((mk_lang_bui_inl_defd_t)(xx & ((mk_lang_bui_inl_defd_t)(xx - ((mk_lang_bui_inl_defd_t)(1))))));
	}
	return cnt;
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_zeros(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_bui_inl_defd_sizebits_d <= 16
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_popcnt())
	{
		return mk_lang_bui_inl_defd_sizebits_d - mk_lang_bui_inl_defd_count_ones(x);
	}
	else
	#elif mk_lang_compiler_is_at_least_gcc(4, 1) && mk_lang_bui_inl_defd_sizebits_d <= 16
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_bui_inl_defd_sizebits_d - mk_lang_bui_inl_defd_count_ones(x);
	}
	else
	#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_bui_inl_defd_sizebits_d <= 32
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_popcnt())
	{
		return mk_lang_bui_inl_defd_sizebits_d - mk_lang_bui_inl_defd_count_ones(x);
	}
	else
	#elif mk_lang_compiler_is_at_least_gcc(4, 1) && mk_lang_bui_inl_defd_sizebits_d <= 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_bui_inl_defd_sizebits_d - mk_lang_bui_inl_defd_count_ones(x);
	}
	else
	#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && mk_lang_arch == mk_lang_arch_x8664 && mk_lang_bui_inl_defd_sizebits_d <= 64
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_popcnt())
	{
		return mk_lang_bui_inl_defd_sizebits_d - mk_lang_bui_inl_defd_count_ones(x);
	}
	else
	#elif mk_lang_compiler_is_at_least_gcc(4, 1) && mk_lang_llong_has && mk_lang_bui_inl_defd_sizebits_d <= 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		return mk_lang_bui_inl_defd_sizebits_d - mk_lang_bui_inl_defd_count_ones(x);
	}
	else
	#endif
	{
		return mk_lang_bui_inl_defd_count_zeros_portable(x);
	}
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_sint_t mk_lang_bui_inl_defd_count_ones_portable(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;

	mk_lang_assert(x);

	xx = ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(*x))));
	return mk_lang_bui_inl_defd_count_zeros(&xx);
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_ones(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_bui_inl_defd_sizebits_d <= 16
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_popcnt())
	{
		unsigned short u mk_lang_constexpr_init;

		mk_lang_assert(x);

		u = ((unsigned short)(__popcnt16(((unsigned short)(*x)))));
		return ((mk_lang_types_sint_t)(u));
	}
	else
	#elif mk_lang_compiler_is_at_least_gcc(4, 1) && mk_lang_bui_inl_defd_sizebits_d <= 16
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(x);

		return __builtin_popcount(((unsigned int)(*x)));
	}
	else
	#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && (mk_lang_arch == mk_lang_arch_x8632 || mk_lang_arch == mk_lang_arch_x8664) && mk_lang_bui_inl_defd_sizebits_d <= 32
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_popcnt())
	{
		unsigned int u mk_lang_constexpr_init;

		mk_lang_assert(x);

		u = ((unsigned int)(__popcnt(((unsigned int)(*x)))));
		return ((mk_lang_types_sint_t)(u));
	}
	else
	#elif mk_lang_compiler_is_at_least_gcc(4, 1) && mk_lang_bui_inl_defd_sizebits_d <= 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(x);

		return __builtin_popcountl(((unsigned long)(*x)));
	}
	else
	#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && mk_lang_arch == mk_lang_arch_x8664 && mk_lang_bui_inl_defd_sizebits_d <= 64
	if(!mk_lang_constexpr_is_constant_evaluated_test && mk_lang_cpuid_has_popcnt())
	{
		unsigned __int64 u mk_lang_constexpr_init;

		mk_lang_assert(x);

		u = ((unsigned __int64)(__popcnt64(((unsigned __int64)(*x)))));
		return ((mk_lang_types_sint_t)(u));
	}
	else
	#elif mk_lang_compiler_is_at_least_gcc(4, 1) && mk_lang_llong_has && mk_lang_bui_inl_defd_sizebits_d <= 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(x);

		return __builtin_popcountll(((unsigned long long)(*x)));
	}
	else
	#endif
	{
		return mk_lang_bui_inl_defd_count_ones_portable(x);
	}
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_has_lsb(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(x);

	return *x & ((mk_lang_bui_inl_defd_t)(1));
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_is_zero(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(x);

	return *x == ((mk_lang_bui_inl_defd_t)(0));
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_is_one(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(x);

	return *x == ((mk_lang_bui_inl_defd_t)(1));
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_is_max(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(x);

	return *x == ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0))));
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_eq(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a == *b;
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_ne(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a != *b;
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_lt(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a < *b;
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_le(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a <= *b;
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_gt(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a > *b;
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_ge(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a >= *b;
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_inc2(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pt const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) + ((mk_lang_bui_inl_defd_t)(1))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_dec2(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pt const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) - ((mk_lang_bui_inl_defd_t)(1))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_inc1(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(x);

	++*x;
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_dec1(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(x);

	--*x;
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_not2(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pt const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(*a))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_or3(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) | ((mk_lang_bui_inl_defd_t)(*b))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_and3(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) & ((mk_lang_bui_inl_defd_t)(*b))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_xor3(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) ^ ((mk_lang_bui_inl_defd_t)(*b))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_not1(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_not2(x, x);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_or2(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_or3(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_and2(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_and3(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_xor2(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_xor3(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_shl3(mk_lang_bui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) << b));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_shr3(mk_lang_bui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) >> b));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_rotl3(mk_lang_bui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_bui_inl_defd_sizebits_d == 8
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(_rotl8(((mk_lang_types_uchar_t)(*a)), ((mk_lang_types_uchar_t)(b)))));
	}
	else
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_bui_inl_defd_sizebits_d == 16
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(_rotl16(((mk_lang_types_ushort_t)(*a)), ((mk_lang_types_uchar_t)(b)))));
	}
	else
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_bui_inl_defd_sizebits_d == 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(_rotl(((mk_lang_types_uint_t)(*a)), b)));
	}
	else
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_bui_inl_defd_sizebits_d == 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(_rotl64(((mk_lang_types_ullong_t)(*a)), b)));
	}
	else
#endif
	{
		mk_lang_assert(a);
		mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) << b)) | ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) >> ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit)))) - b))))));
	}
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_rotr3(mk_lang_bui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_bui_inl_defd_sizebits_d == 8
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(_rotr8(((mk_lang_types_uchar_t)(*a)), ((mk_lang_types_uchar_t)(b)))));
	}
	else
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_bui_inl_defd_sizebits_d == 16
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(_rotr16(((mk_lang_types_ushort_t)(*a)), ((mk_lang_types_uchar_t)(b)))));
	}
	else
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_bui_inl_defd_sizebits_d == 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
		mk_lang_assert(c);
		mk_lang_assert(a);

		*c = ((mk_lang_bui_inl_defd_t)(_rotr(((mk_lang_types_uint_t)(*a)), b)));
	}
	else
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_bui_inl_defd_sizebits_d == 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
		mk_lang_assert(c);
		mk_lang_assert(a);

		*c = ((mk_lang_bui_inl_defd_t)(_rotr64(((mk_lang_types_ullong_t)(*a)), b)));
	}
	else
#endif
	{
		mk_lang_assert(a);
		mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) >> b)) | ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) << ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit)))) - b))))));
	}
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_shl2(mk_lang_bui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_shl3(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_shr2(mk_lang_bui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_shr3(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_rotl2(mk_lang_bui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_rotl3(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_rotr2(mk_lang_bui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_rotr3(a, b, a);
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_would_overflow_add_cc(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0)))) - ((mk_lang_bui_inl_defd_t)(*a)))) < ((mk_lang_bui_inl_defd_t)(*b));
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_would_overflow_add_cs(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0)))) - ((mk_lang_bui_inl_defd_t)(*a)))) <= ((mk_lang_bui_inl_defd_t)(*b));
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_would_overflow_add(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_t const cf) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	return cf ? mk_lang_bui_inl_defd_would_overflow_add_cs(a, b) : mk_lang_bui_inl_defd_would_overflow_add_cc(a, b);
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_would_overflow_sub_cc(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return ((mk_lang_bui_inl_defd_t)(*a)) < ((mk_lang_bui_inl_defd_t)(*b));
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_would_overflow_sub_cs(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return ((mk_lang_bui_inl_defd_t)(*a)) <= ((mk_lang_bui_inl_defd_t)(*b));
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_would_overflow_sub(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_t const cf) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	return cf ? mk_lang_bui_inl_defd_would_overflow_sub_cs(a, b) : mk_lang_bui_inl_defd_would_overflow_sub_cc(a, b);
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_bool_t mk_lang_bui_inl_defd_would_overflow_mul(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return (((mk_lang_bui_inl_defd_t)(*a)) != ((mk_lang_bui_inl_defd_t)(0))) && (((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0)))) / ((mk_lang_bui_inl_defd_t)(*a)))) < ((mk_lang_bui_inl_defd_t)(*b)));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add3_wrap_cid_cod(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) + ((mk_lang_bui_inl_defd_t)(*b))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add3_wrap_cid_coe(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0)))) - ((mk_lang_bui_inl_defd_t)(*a)))) < ((mk_lang_bui_inl_defd_t)(*b));
	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) + ((mk_lang_bui_inl_defd_t)(*b))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add3_wrap_cie_cod(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) + ((mk_lang_bui_inl_defd_t)(*b)))) + ((mk_lang_bui_inl_defd_t)(ci ? ((mk_lang_bui_inl_defd_t)(1)) : ((mk_lang_bui_inl_defd_t)(0))))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add3_wrap_cie_coe(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_bui_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co =
		ci ?
		(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0)))) - ((mk_lang_bui_inl_defd_t)(*a)))) <= ((mk_lang_bui_inl_defd_t)(*b))) :
		(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0)))) - ((mk_lang_bui_inl_defd_t)(*a)))) < ((mk_lang_bui_inl_defd_t)(*b)));
	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) + ((mk_lang_bui_inl_defd_t)(*b)))) + ((mk_lang_bui_inl_defd_t)(ci ? ((mk_lang_bui_inl_defd_t)(1)) : ((mk_lang_bui_inl_defd_t)(0))))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add2_wrap_cid_cod(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_add3_wrap_cid_cod(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add2_wrap_cid_coe(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_add3_wrap_cid_coe(a, b, a, co);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add2_wrap_cie_cod(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_t const ci) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_add3_wrap_cie_cod(a, b, ci, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add2_wrap_cie_coe(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_add3_wrap_cie_coe(a, b, ci, a, co);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub3_wrap_cid_cod(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) - ((mk_lang_bui_inl_defd_t)(*b))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub3_wrap_cid_coe(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ((mk_lang_bui_inl_defd_t)(*a)) < ((mk_lang_bui_inl_defd_t)(*b));
	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) - ((mk_lang_bui_inl_defd_t)(*b))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub3_wrap_cie_cod(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) - ((mk_lang_bui_inl_defd_t)(*b)))) - ((mk_lang_bui_inl_defd_t)(ci ? ((mk_lang_bui_inl_defd_t)(1)) : ((mk_lang_bui_inl_defd_t)(0))))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub3_wrap_cie_coe(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_bui_inl_defd_pt const c, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ci ? (((mk_lang_bui_inl_defd_t)(*a)) <= ((mk_lang_bui_inl_defd_t)(*b))) : (((mk_lang_bui_inl_defd_t)(*a)) < ((mk_lang_bui_inl_defd_t)(*b)));
	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) - ((mk_lang_bui_inl_defd_t)(*b)))) - ((mk_lang_bui_inl_defd_t)(ci ? ((mk_lang_bui_inl_defd_t)(1)) : ((mk_lang_bui_inl_defd_t)(0))))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub2_wrap_cid_cod(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_sub3_wrap_cid_cod(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub2_wrap_cid_coe(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_sub3_wrap_cid_coe(a, b, a, co);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub2_wrap_cie_cod(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_t const ci) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_sub3_wrap_cie_cod(a, b, ci, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub2_wrap_cie_coe(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_types_bool_t const ci, mk_lang_types_bool_pt const co) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_sub3_wrap_cie_coe(a, b, ci, a, co);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul3_wrap_lo(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) * ((mk_lang_bui_inl_defd_t)(*b))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_lang_bui_inl_defd_mul3_wrap_hi_portable(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	#define mk_lang_bui_inl_filec_shift ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit)))) / ((mk_lang_types_sint_t)(2))))
	#define mk_lang_bui_inl_filec_mask ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(1)) << mk_lang_bui_inl_filec_shift)) - ((mk_lang_bui_inl_defd_t)(1))))

	mk_lang_bui_inl_defd_t alo mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t ahi mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t blo mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t bhi mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t ablo mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t abmi mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t bami mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t abhi mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(((((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit))))) % ((mk_lang_types_sint_t)(2))))) == ((mk_lang_types_sint_t)(0)));
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	alo = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) & mk_lang_bui_inl_filec_mask));
	ahi = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) >> mk_lang_bui_inl_filec_shift));
	blo = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*b)) & mk_lang_bui_inl_filec_mask));
	bhi = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*b)) >> mk_lang_bui_inl_filec_shift));
	ablo = ((mk_lang_bui_inl_defd_t)(alo * blo));
	abmi = ((mk_lang_bui_inl_defd_t)(alo * bhi));
	bami = ((mk_lang_bui_inl_defd_t)(ahi * blo));
	abhi = ((mk_lang_bui_inl_defd_t)(ahi * bhi));
	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(abhi + ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(abmi >> mk_lang_bui_inl_filec_shift)) + ((mk_lang_bui_inl_defd_t)(bami >> mk_lang_bui_inl_filec_shift)))))) + ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(abmi & mk_lang_bui_inl_filec_mask)) + ((mk_lang_bui_inl_defd_t)(bami & mk_lang_bui_inl_filec_mask)))) + ((mk_lang_bui_inl_defd_t)(ablo >> mk_lang_bui_inl_filec_shift)))) >> mk_lang_bui_inl_filec_shift))));

	#undef mk_lang_bui_inl_filec_shift
	#undef mk_lang_bui_inl_filec_mask
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul3_wrap_hi(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
#if mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_bui_inl_defd_sizeof_d
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(*a)) * ((mk_lang_types_ushort_t)(*b)))) >> ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d))));
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_bui_inl_defd_sizeof_d
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_types_uint_t)(((mk_lang_types_uint_t)(*a)) * ((mk_lang_types_uint_t)(*b)))) >> ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d))));
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_bui_inl_defd_sizeof_d
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_types_ulong_t)(((mk_lang_types_ulong_t)(*a)) * ((mk_lang_types_ulong_t)(*b)))) >> ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d))));
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_bui_inl_defd_sizeof_d
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_types_ullong_t)(((mk_lang_types_ullong_t)(*a)) * ((mk_lang_types_ullong_t)(*b)))) >> ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d))));
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_bui_inl_defd_sizeof_d
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_types_ulllong_t)(((mk_lang_types_ulllong_t)(*a)) * ((mk_lang_types_ulllong_t)(*b)))) >> ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d))));
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && (mk_lang_arch == mk_lang_arch_ia64 || mk_lang_arch == mk_lang_arch_x8664 || mk_lang_arch == mk_lang_arch_arm64) && mk_lang_bui_inl_defd_sizebits_d == 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b);
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(__umulh(((unsigned __int64)(*a)), ((unsigned __int64)(*b)))))));
	}
	else
	{
		mk_lang_bui_inl_defd_mul3_wrap_hi_portable(a, b, c);
	}
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_arch == mk_lang_arch_x8664 && mk_lang_bui_inl_defd_sizebits_d == 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b);
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(__ull_rshift(((unsigned __int64)(__emulu(((unsigned int)(*a)), ((unsigned int)(*b))))), 32)))));
	}
	else
	{
		mk_lang_bui_inl_defd_mul3_wrap_hi_portable(a, b, c);
	}
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_arch == mk_lang_arch_x8632 && mk_lang_bui_inl_defd_sizebits_d == 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		mk_lang_assert(a);
		mk_lang_assert(b);
		mk_lang_assert(c);

		*c = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(((unsigned __int64)(__emulu(((unsigned int)(*a)), ((unsigned int)(*b))))) >> 32))));
	}
	else
	{
		mk_lang_bui_inl_defd_mul3_wrap_hi_portable(a, b, c);
	}
#else
	mk_lang_bui_inl_defd_mul3_wrap_hi_portable(a, b, c);
#endif
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_void_t mk_lang_bui_inl_defd_mul4_wrap_wi_portable(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c, mk_lang_bui_inl_defd_pt const d) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	#define mk_lang_bui_inl_filec_shift ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit)))) / ((mk_lang_types_sint_t)(2))))
	#define mk_lang_bui_inl_filec_mask ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(1)) << mk_lang_bui_inl_filec_shift)) - ((mk_lang_bui_inl_defd_t)(1))))

	mk_lang_bui_inl_defd_t alo mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t ahi mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t blo mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t bhi mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t ablo mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t abmi mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t bami mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t abhi mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_sint_t)(((((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit))))) % ((mk_lang_types_sint_t)(2))))) == ((mk_lang_types_sint_t)(0)));
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	alo = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) & mk_lang_bui_inl_filec_mask));
	ahi = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) >> mk_lang_bui_inl_filec_shift));
	blo = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*b)) & mk_lang_bui_inl_filec_mask));
	bhi = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*b)) >> mk_lang_bui_inl_filec_shift));
	ablo = ((mk_lang_bui_inl_defd_t)(alo * blo));
	abmi = ((mk_lang_bui_inl_defd_t)(alo * bhi));
	bami = ((mk_lang_bui_inl_defd_t)(ahi * blo));
	abhi = ((mk_lang_bui_inl_defd_t)(ahi * bhi));
	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) * ((mk_lang_bui_inl_defd_t)(*b))));
	*d = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(abhi + ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(abmi >> mk_lang_bui_inl_filec_shift)) + ((mk_lang_bui_inl_defd_t)(bami >> mk_lang_bui_inl_filec_shift)))))) + ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(abmi & mk_lang_bui_inl_filec_mask)) + ((mk_lang_bui_inl_defd_t)(bami & mk_lang_bui_inl_filec_mask)))) + ((mk_lang_bui_inl_defd_t)(ablo >> mk_lang_bui_inl_filec_shift)))) >> mk_lang_bui_inl_filec_shift))));

	#undef mk_lang_bui_inl_filec_shift
	#undef mk_lang_bui_inl_filec_mask
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul4_wrap_wi(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c, mk_lang_bui_inl_defd_pt const d) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
#if mk_lang_sizeof_bi_ushort_t >= 2 * mk_lang_bui_inl_defd_sizeof_d
	mk_lang_types_ushort_t aa mk_lang_constexpr_init;
	mk_lang_types_ushort_t bb mk_lang_constexpr_init;
	mk_lang_types_ushort_t cc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	aa = ((mk_lang_types_ushort_t)(*a));
	bb = ((mk_lang_types_ushort_t)(*b));
	cc = ((mk_lang_types_ushort_t)(aa * bb));
	*c = ((mk_lang_bui_inl_defd_t)(cc));
	*d = ((mk_lang_bui_inl_defd_t)(cc >> ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d))));
#elif mk_lang_sizeof_bi_uint_t >= 2 * mk_lang_bui_inl_defd_sizeof_d
	mk_lang_types_uint_t aa mk_lang_constexpr_init;
	mk_lang_types_uint_t bb mk_lang_constexpr_init;
	mk_lang_types_uint_t cc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	aa = ((mk_lang_types_uint_t)(*a));
	bb = ((mk_lang_types_uint_t)(*b));
	cc = ((mk_lang_types_uint_t)(aa * bb));
	*c = ((mk_lang_bui_inl_defd_t)(cc));
	*d = ((mk_lang_bui_inl_defd_t)(cc >> ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d))));
#elif mk_lang_sizeof_bi_ulong_t >= 2 * mk_lang_bui_inl_defd_sizeof_d
	mk_lang_types_ulong_t aa mk_lang_constexpr_init;
	mk_lang_types_ulong_t bb mk_lang_constexpr_init;
	mk_lang_types_ulong_t cc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	aa = ((mk_lang_types_ulong_t)(*a));
	bb = ((mk_lang_types_ulong_t)(*b));
	cc = ((mk_lang_types_ulong_t)(aa * bb));
	*c = ((mk_lang_bui_inl_defd_t)(cc));
	*d = ((mk_lang_bui_inl_defd_t)(cc >> ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d))));
#elif mk_lang_sizeof_bi_ullong_t >= 2 * mk_lang_bui_inl_defd_sizeof_d
	mk_lang_types_ullong_t aa mk_lang_constexpr_init;
	mk_lang_types_ullong_t bb mk_lang_constexpr_init;
	mk_lang_types_ullong_t cc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	aa = ((mk_lang_types_ullong_t)(*a));
	bb = ((mk_lang_types_ullong_t)(*b));
	cc = ((mk_lang_types_ullong_t)(aa * bb));
	*c = ((mk_lang_bui_inl_defd_t)(cc));
	*d = ((mk_lang_bui_inl_defd_t)(cc >> ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d))));
#elif mk_lang_sizeof_bi_ulllong_t >= 2 * mk_lang_bui_inl_defd_sizeof_d
	mk_lang_types_ulllong_t aa mk_lang_constexpr_init;
	mk_lang_types_ulllong_t bb mk_lang_constexpr_init;
	mk_lang_types_ulllong_t cc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	aa = ((mk_lang_types_ulllong_t)(*a));
	bb = ((mk_lang_types_ulllong_t)(*b));
	cc = ((mk_lang_types_ulllong_t)(aa * bb));
	*c = ((mk_lang_bui_inl_defd_t)(cc));
	*d = ((mk_lang_bui_inl_defd_t)(cc >> ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d))));
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2012 && mk_lang_arch == mk_lang_arch_x8664 && mk_lang_bui_inl_defd_sizebits_d == 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		unsigned __int64 cc mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);
		mk_lang_assert(c);
		mk_lang_assert(d);
		mk_lang_assert(c != d);

		*c = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(_umul128(((unsigned __int64)(*a)), ((unsigned __int64)(*b)), &cc)))));
		*d = ((mk_lang_bui_inl_defd_t)(cc));
	}
	else
	{
		mk_lang_bui_inl_defd_mul4_wrap_wi_portable(a, b, c, d);
	}
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2010 && (mk_lang_arch == mk_lang_arch_ia64 || mk_lang_arch == mk_lang_arch_x8664 || mk_lang_arch == mk_lang_arch_arm64) && mk_lang_bui_inl_defd_sizebits_d == 64
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		unsigned __int64 aa mk_lang_constexpr_init;
		unsigned __int64 bb mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);
		mk_lang_assert(c);
		mk_lang_assert(d);
		mk_lang_assert(c != d);

		aa = ((unsigned __int64)(*a));
		bb = ((unsigned __int64)(*b));
		*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) * ((mk_lang_bui_inl_defd_t)(*b))));
		*d = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(__umulh(aa, bb)))));
	}
	else
	{
		mk_lang_bui_inl_defd_mul4_wrap_wi_portable(a, b, c, d);
	}
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_arch == mk_lang_arch_x8664 && mk_lang_bui_inl_defd_sizebits_d == 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		unsigned int aa mk_lang_constexpr_init;
		unsigned int bb mk_lang_constexpr_init;
		unsigned __int64 cc mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);
		mk_lang_assert(c);
		mk_lang_assert(d);
		mk_lang_assert(c != d);

		aa = ((unsigned int)(*a));
		bb = ((unsigned int)(*b));
		cc = ((unsigned __int64)(__emulu(aa, bb)));
		*c = ((mk_lang_bui_inl_defd_t)(cc));
		*d = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(__ull_rshift(cc, 32)))));
	}
	else
	{
		mk_lang_bui_inl_defd_mul4_wrap_wi_portable(a, b, c, d);
	}
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_2008 && mk_lang_arch == mk_lang_arch_x8632 && mk_lang_bui_inl_defd_sizebits_d == 32
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	{
		unsigned int aa mk_lang_constexpr_init;
		unsigned int bb mk_lang_constexpr_init;
		unsigned __int64 cc mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);
		mk_lang_assert(c);
		mk_lang_assert(d);
		mk_lang_assert(c != d);

		aa = ((unsigned int)(*a));
		bb = ((unsigned int)(*b));
		cc = ((unsigned __int64)(__emulu(aa, bb)));
		*c = ((mk_lang_bui_inl_defd_t)(cc));
		*d = ((mk_lang_bui_inl_defd_t)(cc >> 32));
	}
	else
	{
		mk_lang_bui_inl_defd_mul4_wrap_wi_portable(a, b, c, d);
	}
#else
	mk_lang_bui_inl_defd_mul4_wrap_wi_portable(a, b, c, d);
#endif
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul2_wrap_lo(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_mul3_wrap_lo(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul2_wrap_hi(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_mul3_wrap_hi(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul2_wrap_wi(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pt const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_mul4_wrap_wi(a, b, a, b);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_div3_wrap(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) / ((mk_lang_bui_inl_defd_t)(*b))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mod3_wrap(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) % ((mk_lang_bui_inl_defd_t)(*b))));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_divmod4_wrap(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c, mk_lang_bui_inl_defd_pt const d) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t aa mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t bb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	aa = ((mk_lang_bui_inl_defd_t)(*a));
	bb = ((mk_lang_bui_inl_defd_t)(*b));
	*c = ((mk_lang_bui_inl_defd_t)(aa / bb));
	*d = ((mk_lang_bui_inl_defd_t)(aa % bb));
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_div2_wrap(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_div3_wrap(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mod2_wrap(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_mod3_wrap(a, b, a);
}}

mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_divmod2_wrap(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pt const b) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_divmod4_wrap(a, b, a, b);
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_bui_inl_defd_symbols_bin_a[] = {'0', '1'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_bin_n(mk_lang_bui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_bool_t lsb mk_lang_constexpr_init;
	mk_lang_types_bool_t zero mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	xx = *x;
	ptr = &str[str_len - 1]; ++ptr;
	rem = str_len;
	for(;;)
	{
		if(rem == 0)
		{
			return 0; /* todo return negative? */
		}
		--rem;
		lsb = mk_lang_bui_inl_defd_has_lsb(&xx);
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_bin_a[lsb ? 1 : 0];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = ((mk_lang_types_pchar_t)('0' + (lsb ? 1 : 0)));
		#endif
		mk_lang_bui_inl_defd_shr2(&xx, 1);
		zero = mk_lang_bui_inl_defd_is_zero(&xx);
		if(zero)
		{
			break;
		}
	}
	ret = str_len - rem;
	if(ret != str_len)
	{
		mk_lang_string_memmove_pc_fn(&str[0], &str[str_len - ret], ((mk_lang_types_usize_t)(ret)));
	}
	return ret;
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_lang_bui_inl_defd_symbols_bin_b[] = {L'0', L'1'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_bin_w(mk_lang_bui_inl_defd_pct const x, mk_lang_types_wchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_wchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_bool_t lsb mk_lang_constexpr_init;
	mk_lang_types_bool_t zero mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	xx = *x;
	ptr = &str[str_len - 1]; ++ptr;
	rem = str_len;
	for(;;)
	{
		if(rem == 0)
		{
			return 0; /* todo return negative? */
		}
		--rem;
		lsb = mk_lang_bui_inl_defd_has_lsb(&xx);
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_bin_a[lsb ? 1 : 0];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = ((mk_lang_types_pchar_t)(L'0' + (lsb ? 1 : 0)));
		#endif
		mk_lang_bui_inl_defd_shr2(&xx, 1);
		zero = mk_lang_bui_inl_defd_is_zero(&xx);
		if(zero)
		{
			break;
		}
	}
	ret = str_len - rem;
	if(ret != str_len)
	{
		mk_lang_string_memmove_wc_fn(&str[0], &str[str_len - ret], ((mk_lang_types_usize_t)(ret)));
	}
	return ret;
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_bui_inl_defd_symbols_bin_c[] = {'0', '1'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_from_str_bin_n(mk_lang_bui_inl_defd_pt const x, mk_lang_types_pchar_pct const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_pchar_pct it mk_lang_constexpr_init;
	mk_lang_types_pchar_pct ite mk_lang_constexpr_init;
	mk_lang_types_pchar_t e mk_lang_constexpr_init;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	#endif
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t overflow mk_lang_constexpr_init;
	mk_lang_types_sint_t shifts mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t digit mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0)
	{
		return 0;
	}
	it = str;
	ite = str + str_len;
	e = *it;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_bin_c);
	for(i = 0; i != n; ++i)
	{
		if(e == mk_lang_bui_inl_defd_symbols_bin_c[i])
		{
			break;
		}
	}
	if(i == n)
	{
		return 0;
	}
	#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
	if(e >= '0' && e <= '1')
	{
		i = e - '0';
	}
	else
	{
		return 0;
	}
	#endif
	overflow = 1;
	shifts = 0;
	mk_lang_bui_inl_defd_from_bi_sint(&xx, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_bin_c);
		for(i = 0; i != n; ++i)
		{
			if(e == mk_lang_bui_inl_defd_symbols_bin_c[i])
			{
				break;
			}
		}
		if(i == n)
		{
			break;
		}
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		if(e >= '0' && e <= '1')
		{
			i = e - '0';
		}
		else
		{
			break;
		}
		#endif
		if(!mk_lang_bui_inl_defd_is_zero(&xx))
		{
			++shifts;
			if(shifts == mk_lang_bui_inl_defd_sizebits_d)
			{
				overflow = -1;
				break;
			}
		}
		mk_lang_bui_inl_defd_from_bi_sint(&digit, &i);
		mk_lang_bui_inl_defd_shl2(&xx, 1);
		mk_lang_bui_inl_defd_or2(&xx, &digit);
	}
	if(overflow == 1)
	{
		*x = xx;
	}
	return ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(it - str)) * overflow));
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_lang_bui_inl_defd_symbols_bin_d[] = {L'0', L'1'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_from_str_bin_w(mk_lang_bui_inl_defd_pt const x, mk_lang_types_wchar_pct const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_wchar_pct it mk_lang_constexpr_init;
	mk_lang_types_wchar_pct ite mk_lang_constexpr_init;
	mk_lang_types_wchar_t e mk_lang_constexpr_init;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	#endif
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t overflow mk_lang_constexpr_init;
	mk_lang_types_sint_t shifts mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t digit mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0)
	{
		return 0;
	}
	it = str;
	ite = str + str_len;
	e = *it;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_bin_d);
	for(i = 0; i != n; ++i)
	{
		if(e == mk_lang_bui_inl_defd_symbols_bin_d[i])
		{
			break;
		}
	}
	if(i == n)
	{
		return 0;
	}
	#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
	if(e >= L'0' && e <= L'1')
	{
		i = e - L'0';
	}
	else
	{
		return 0;
	}
	#endif
	overflow = 1;
	shifts = 0;
	mk_lang_bui_inl_defd_from_bi_sint(&xx, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_bin_d);
		for(i = 0; i != n; ++i)
		{
			if(e == mk_lang_bui_inl_defd_symbols_bin_d[i])
			{
				break;
			}
		}
		if(i == n)
		{
			break;
		}
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		if(e >= L'0' && e <= L'1')
		{
			i = e - L'0';
		}
		else
		{
			break;
		}
		#endif
		++shifts;
		if(shifts == mk_lang_bui_inl_defd_sizebits_d)
		{
			overflow = -1;
			break;
		}
		mk_lang_bui_inl_defd_from_bi_sint(&digit, &i);
		mk_lang_bui_inl_defd_shl2(&xx, 1);
		mk_lang_bui_inl_defd_or2(&xx, &digit);
	}
	if(overflow == 1)
	{
		*x = xx;
	}
	return ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(it - str)) * overflow));
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_bui_inl_defd_symbols_oct_a[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_oct_n(mk_lang_bui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	xx = *x;
	ptr = &str[str_len - 1]; ++ptr;
	rem = str_len;
	for(;;)
	{
		mk_lang_bui_inl_defd_to_bi_uchar(&xx, &tuc);
		tuc = tuc & 0x7;
		if(rem == 0)
		{
			return 0; /* todo return negative? */
		}
		--rem;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_oct_a[tuc];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = ((mk_lang_types_pchar_t)('0' + tuc));
		#endif
		mk_lang_bui_inl_defd_shr2(&xx, 3);
		if(mk_lang_bui_inl_defd_is_zero(&xx))
		{
			break;
		}
	}
	ret = str_len - rem;
	if(ret != str_len)
	{
		mk_lang_string_memmove_pc_fn(&str[0], &str[str_len - ret], ((mk_lang_types_usize_t)(ret)));
	}
	return ret;
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_lang_bui_inl_defd_symbols_oct_b[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_oct_w(mk_lang_bui_inl_defd_pct const x, mk_lang_types_wchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_wchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	xx = *x;
	ptr = &str[str_len - 1]; ++ptr;
	rem = str_len;
	for(;;)
	{
		mk_lang_bui_inl_defd_to_bi_uchar(&xx, &tuc);
		tuc = tuc & 0x7;
		if(rem == 0)
		{
			return 0; /* todo return negative? */
		}
		--rem;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_oct_a[tuc];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = ((mk_lang_types_wchar_t)(L'0' + tuc));
		#endif
		mk_lang_bui_inl_defd_shr2(&xx, 3);
		if(mk_lang_bui_inl_defd_is_zero(&xx))
		{
			break;
		}
	}
	ret = str_len - rem;
	if(ret != str_len)
	{
		mk_lang_string_memmove_wc_fn(&str[0], &str[str_len - ret], ((mk_lang_types_usize_t)(ret)));
	}
	return ret;
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_bui_inl_defd_symbols_oct_c[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_from_str_oct_n(mk_lang_bui_inl_defd_pt const x, mk_lang_types_pchar_pct const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_pchar_pct it mk_lang_constexpr_init;
	mk_lang_types_pchar_pct ite mk_lang_constexpr_init;
	mk_lang_types_pchar_t e mk_lang_constexpr_init;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	#endif
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t overflow mk_lang_constexpr_init;
	mk_lang_types_sint_t shifts mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t digit mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(mk_lang_charbit % mk_lang_charbit == 0);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0)
	{
		return 0;
	}
	it = str;
	ite = str + str_len;
	e = *it;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_oct_c);
	for(i = 0; i != n; ++i)
	{
		if(e == mk_lang_bui_inl_defd_symbols_oct_c[i])
		{
			break;
		}
	}
	if(i == n)
	{
		return 0;
	}
	#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
	if(e >= '0' && e <= '7')
	{
		i = e - '0';
	}
	else
	{
		return 0;
	}
	#endif
	overflow = 1;
	shifts = 0;
	mk_lang_bui_inl_defd_from_bi_sint(&xx, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_oct_c);
		for(i = 0; i != n; ++i)
		{
			if(e == mk_lang_bui_inl_defd_symbols_oct_c[i])
			{
				break;
			}
		}
		if(i == n)
		{
			break;
		}
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		if(e >= '0' && e <= '7')
		{
			i = e - '0';
		}
		else
		{
			break;
		}
		#endif
		if(!mk_lang_bui_inl_defd_is_zero(&xx))
		{
			++shifts;
			if(shifts > mk_lang_bui_inl_defd_sizebits_d / 3 || (shifts == mk_lang_bui_inl_defd_sizebits_d / 3 && mk_lang_bui_inl_defd_count_leading_zeros(&xx) < 3))
			{
				overflow = -1;
				break;
			}
		}
		mk_lang_bui_inl_defd_from_bi_sint(&digit, &i);
		mk_lang_bui_inl_defd_shl2(&xx, 3);
		mk_lang_bui_inl_defd_or2(&xx, &digit);
	}
	if(overflow == 1)
	{
		*x = xx;
	}
	return ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(it - str)) * overflow));
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_lang_bui_inl_defd_symbols_oct_d[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_from_str_oct_w(mk_lang_bui_inl_defd_pt const x, mk_lang_types_wchar_pct const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_wchar_pct it mk_lang_constexpr_init;
	mk_lang_types_wchar_pct ite mk_lang_constexpr_init;
	mk_lang_types_wchar_t e mk_lang_constexpr_init;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	#endif
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t overflow mk_lang_constexpr_init;
	mk_lang_types_sint_t shifts mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t digit mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(mk_lang_charbit % mk_lang_charbit == 0);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0)
	{
		return 0;
	}
	it = str;
	ite = str + str_len;
	e = *it;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_oct_d);
	for(i = 0; i != n; ++i)
	{
		if(e == mk_lang_bui_inl_defd_symbols_oct_d[i])
		{
			break;
		}
	}
	if(i == n)
	{
		return 0;
	}
	#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
	if(e >= L'0' && e <= L'7')
	{
		i = e - L'0';
	}
	else
	{
		return 0;
	}
	#endif
	overflow = 1;
	shifts = 0;
	mk_lang_bui_inl_defd_from_bi_sint(&xx, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_oct_d);
		for(i = 0; i != n; ++i)
		{
			if(e == mk_lang_bui_inl_defd_symbols_oct_d[i])
			{
				break;
			}
		}
		if(i == n)
		{
			break;
		}
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		if(e >= L'0' && e <= L'7')
		{
			i = e - L'0';
		}
		else
		{
			break;
		}
		#endif
		++shifts;
		if(shifts > mk_lang_bui_inl_defd_sizebits_d / 3 || (shifts == mk_lang_bui_inl_defd_sizebits_d / 3 && mk_lang_bui_inl_defd_count_leading_zeros(&xx) < 3))
		{
			overflow = -1;
			break;
		}
		mk_lang_bui_inl_defd_from_bi_sint(&digit, &i);
		mk_lang_bui_inl_defd_shl2(&xx, 3);
		mk_lang_bui_inl_defd_or2(&xx, &digit);
	}
	if(overflow == 1)
	{
		*x = xx;
	}
	return ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(it - str)) * overflow));
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_bui_inl_defd_symbols_dec_a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_dec_n(mk_lang_bui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t base mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt pa1 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t a1 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt pa2 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t a2 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt pa3 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t b mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	i = str_len;
	n = 10;
	mk_lang_bui_inl_defd_from_bi_sint(&base, &n);
	pa1 = &a1;
	pa2 = &a2;
	*pa2 = *x;
	for(;;)
	{
		pa3 = pa1;
		pa1 = pa2;
		pa2 = pa3;
		mk_lang_bui_inl_defd_divmod4_wrap(pa1, &base, pa2, &b);
		mk_lang_bui_inl_defd_to_bi_sint(&b, &n);
		mk_lang_assert(n >= 0 && n < 10);
		--i;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		str[i] = mk_lang_bui_inl_defd_symbols_dec_a[n];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		str[i] = ((mk_lang_types_pchar_t)('0' + n));
		#endif
		if(mk_lang_bui_inl_defd_is_zero(pa2))
		{
			break;
		}
		if(i == 0)
		{
			return 0;
		}
	}
	if(i != 0)
	{
		mk_lang_assert(str_len - i >= 1);
		mk_lang_string_memmove_pc_fn(str, str + i, ((mk_lang_types_uint_t)(str_len - i)));
	}
	mk_lang_assert(str_len - i >= 0);
	mk_lang_assert(str_len - i <= mk_lang_bui_inl_defd_strlendec_v);
	return str_len - i;
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_lang_bui_inl_defd_symbols_dec_b[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_dec_w(mk_lang_bui_inl_defd_pct const x, mk_lang_types_wchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t base mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt pa1 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t a1 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt pa2 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t a2 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt pa3 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t b mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	i = str_len;
	n = 10;
	mk_lang_bui_inl_defd_from_bi_sint(&base, &n);
	pa1 = &a1;
	pa2 = &a2;
	*pa2 = *x;
	for(;;)
	{
		pa3 = pa1;
		pa1 = pa2;
		pa2 = pa3;
		mk_lang_bui_inl_defd_divmod4_wrap(pa1, &base, pa2, &b);
		mk_lang_bui_inl_defd_to_bi_sint(&b, &n);
		mk_lang_assert(n >= 0 && n < 10);
		--i;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		str[i] = mk_lang_bui_inl_defd_symbols_dec_b[n];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		str[i] = ((mk_lang_types_wchar_t)(L'0' + n));
		#endif
		if(mk_lang_bui_inl_defd_is_zero(pa2))
		{
			break;
		}
		if(i == 0)
		{
			return 0;
		}
	}
	if(i != 0)
	{
		mk_lang_assert(str_len - i >= 1);
		mk_lang_string_memmove_wc_fn(str, str + i, ((mk_lang_types_uint_t)(str_len - i)));
	}
	mk_lang_assert(str_len - i >= 0);
	mk_lang_assert(str_len - i <= mk_lang_bui_inl_defd_strlendec_v);
	return str_len - i;
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_bui_inl_defd_symbols_dec_c[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_bui_inl_defd_t mk_lang_bui_inl_defd_from_str_dec_border_base_impl(mk_lang_types_void_t) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t base mk_lang_constexpr_init;

	tsi = 10;
	mk_lang_bui_inl_defd_from_bi_sint(&base, &tsi);
	return base;
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_bui_inl_defd_t mk_lang_bui_inl_defd_from_str_dec_border_value_impl(mk_lang_types_void_t) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t base mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t mx mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t border_value mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t border_digit mk_lang_constexpr_init;

	tsi = 10;
	mk_lang_bui_inl_defd_from_bi_sint(&base, &tsi);
	mk_lang_bui_inl_defd_set_max(&mx);
	mk_lang_bui_inl_defd_divmod4_wrap(&mx, &base, &border_value, &border_digit);
	return border_value;
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_sint_t mk_lang_bui_inl_defd_from_str_dec_border_digit_impl(mk_lang_types_void_t) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t base mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t mx mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t border_value mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t border_digit mk_lang_constexpr_init;

	tsi = 10;
	mk_lang_bui_inl_defd_from_bi_sint(&base, &tsi);
	mk_lang_bui_inl_defd_set_max(&mx);
	mk_lang_bui_inl_defd_divmod4_wrap(&mx, &base, &border_value, &border_digit);
	mk_lang_bui_inl_defd_to_bi_sint(&border_digit, &tsi);
	return tsi;
}}

#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
mk_lang_constexpr_static_inline mk_lang_bui_inl_defd_t const mk_lang_bui_inl_defd_from_str_dec_border_base_val = mk_lang_bui_inl_defd_from_str_dec_border_base_impl();
mk_lang_constexpr_static_inline mk_lang_bui_inl_defd_t const mk_lang_bui_inl_defd_from_str_dec_border_value_val = mk_lang_bui_inl_defd_from_str_dec_border_value_impl();
mk_lang_constexpr_static_inline mk_lang_types_sint_t const mk_lang_bui_inl_defd_from_str_dec_border_digit_val = mk_lang_bui_inl_defd_from_str_dec_border_digit_impl();
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_bui_inl_defd_t mk_lang_bui_inl_defd_from_str_dec_border_base(mk_lang_types_void_t) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	return mk_lang_bui_inl_defd_from_str_dec_border_base_val;
	#else
	return mk_lang_bui_inl_defd_from_str_dec_border_base_impl();
	#endif
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_bui_inl_defd_t mk_lang_bui_inl_defd_from_str_dec_border_value(mk_lang_types_void_t) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	return mk_lang_bui_inl_defd_from_str_dec_border_value_val;
	#else
	return mk_lang_bui_inl_defd_from_str_dec_border_value_impl();
	#endif
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias static mk_lang_inline mk_lang_types_sint_t mk_lang_bui_inl_defd_from_str_dec_border_digit(mk_lang_types_void_t) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	return mk_lang_bui_inl_defd_from_str_dec_border_digit_val;
	#else
	return mk_lang_bui_inl_defd_from_str_dec_border_digit_impl();
	#endif
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_from_str_dec_n(mk_lang_bui_inl_defd_pt const x, mk_lang_types_pchar_pct const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t s_base mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t s_border_value mk_lang_constexpr_init;
	mk_lang_types_sint_t s_border_digit mk_lang_constexpr_init;

	mk_lang_types_pchar_pct it mk_lang_constexpr_init;
	mk_lang_types_pchar_pct ite mk_lang_constexpr_init;
	mk_lang_types_pchar_t e mk_lang_constexpr_init;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	#endif
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t overflow mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt px1 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt px2 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t digit mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt px3 mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0)
	{
		return 0;
	}
	s_base = mk_lang_bui_inl_defd_from_str_dec_border_base();
	s_border_value = mk_lang_bui_inl_defd_from_str_dec_border_value();
	s_border_digit = mk_lang_bui_inl_defd_from_str_dec_border_digit();
	it = str;
	ite = str + str_len;
	e = *it;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_dec_c);
	for(i = 0; i != n; ++i)
	{
		if(e == mk_lang_bui_inl_defd_symbols_dec_c[i])
		{
			break;
		}
	}
	if(i == n)
	{
		return 0;
	}
	#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
	if(e >= '0' && e <= '9')
	{
		i = e - '0';
	}
	else
	{
		return 0;
	}
	#endif
	overflow = 1;
	px1 = &xx;
	px2 = x;
	mk_lang_bui_inl_defd_from_bi_sint(px1, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_dec_c);
		for(i = 0; i != n; ++i)
		{
			if(e == mk_lang_bui_inl_defd_symbols_dec_c[i])
			{
				break;
			}
		}
		if(i == n)
		{
			break;
		}
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		if(e >= '0' && e <= '9')
		{
			i = e - '0';
		}
		else
		{
			break;
		}
		#endif
		if(!(mk_lang_bui_inl_defd_lt(px1, &s_border_value) || (mk_lang_bui_inl_defd_eq(px1, &s_border_value) && i <= s_border_digit)))
		{
			overflow = -1;
			break;
		}
		mk_lang_bui_inl_defd_mul3_wrap_lo(px1, &s_base, px2);
		mk_lang_bui_inl_defd_from_bi_sint(&digit, &i);
		mk_lang_bui_inl_defd_add2_wrap_cid_cod(px2, &digit);
		px3 = px1;
		px1 = px2;
		px2 = px3;
	}
	if(px1 == &xx)
	{
		*x = xx;
	}
	return ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(it - str)) * overflow));
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_lang_bui_inl_defd_symbols_dec_d[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_from_str_dec_w(mk_lang_bui_inl_defd_pt const x, mk_lang_types_wchar_pct const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t s_base mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t s_border_value mk_lang_constexpr_init;
	mk_lang_types_sint_t s_border_digit mk_lang_constexpr_init;

	mk_lang_types_wchar_pct it mk_lang_constexpr_init;
	mk_lang_types_wchar_pct ite mk_lang_constexpr_init;
	mk_lang_types_wchar_t e mk_lang_constexpr_init;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	#endif
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t overflow mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt px1 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt px2 mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t digit mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_pt px3 mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0)
	{
		return 0;
	}
	s_base = mk_lang_bui_inl_defd_from_str_dec_border_base();
	s_border_value = mk_lang_bui_inl_defd_from_str_dec_border_value();
	s_border_digit = mk_lang_bui_inl_defd_from_str_dec_border_digit();
	it = str;
	ite = str + str_len;
	e = *it;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_dec_d);
	for(i = 0; i != n; ++i)
	{
		if(e == mk_lang_bui_inl_defd_symbols_dec_d[i])
		{
			break;
		}
	}
	if(i == n)
	{
		return 0;
	}
	#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
	if(e >= L'0' && e <= L'9')
	{
		i = e - L'0';
	}
	else
	{
		return 0;
	}
	#endif
	overflow = 1;
	px1 = &xx;
	px2 = x;
	mk_lang_bui_inl_defd_from_bi_sint(px1, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_dec_d);
		for(i = 0; i != n; ++i)
		{
			if(e == mk_lang_bui_inl_defd_symbols_dec_d[i])
			{
				break;
			}
		}
		if(i == n)
		{
			break;
		}
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		if(e >= L'0' && e <= L'9')
		{
			i = e - L'0';
		}
		else
		{
			break;
		}
		#endif
		if(!(mk_lang_bui_inl_defd_lt(px1, &s_border_value) || (mk_lang_bui_inl_defd_eq(px1, &s_border_value) && i <= s_border_digit)))
		{
			overflow = -1;
			break;
		}
		mk_lang_bui_inl_defd_mul3_wrap_lo(px1, &s_base, px2);
		mk_lang_bui_inl_defd_from_bi_sint(&digit, &i);
		mk_lang_bui_inl_defd_add2_wrap_cid_cod(px2, &digit);
		px3 = px1;
		px1 = px2;
		px2 = px3;
	}
	if(px1 == &xx)
	{
		*x = xx;
	}
	return ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(it - str)) * overflow));
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_bui_inl_defd_symbols_hex_a[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_hex_n(mk_lang_bui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_bool_t zero mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_lo mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_hi mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit % 2 == 0);
	mk_lang_static_assert(mk_lang_bui_inl_defd_sizebits_d > mk_lang_charbit / 2);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	xx = *x;
	ptr = &str[str_len - 1]; ++ptr;
	rem = str_len;
	for(;;)
	{
		mk_lang_bui_inl_defd_to_bi_uchar(&xx, &tuc);
		#if mk_lang_bui_inl_defd_sizebits_d > mk_lang_charbit
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit);
		#else
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		#endif
		zero = mk_lang_bui_inl_defd_is_zero(&xx);
		tuc_lo = ((mk_lang_types_uchar_t)((tuc >> 0) & 0xf));
		if(rem == 0)
		{
			return 0; /* todo return negative? */
		}
		--rem;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_hex_a[tuc_lo];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = (tuc_lo >= 0 && tuc_lo <= 9) ? ((mk_lang_types_pchar_t)('0' + tuc_lo)) : ((mk_lang_types_pchar_t)('a' + (tuc_lo - 10)));
		#endif
		tuc_hi = ((mk_lang_types_uchar_t)((tuc >> 4) & 0xf));
		if(tuc_hi == 0 && zero)
		{
			break;
		}
		if(rem == 0)
		{
			return 0; /* todo return negative? */
		}
		--rem;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_hex_a[tuc_hi];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = (tuc_hi >= 0 && tuc_hi <= 9) ? ((mk_lang_types_pchar_t)('0' + tuc_hi)) : ((mk_lang_types_pchar_t)('a' + (tuc_hi - 10)));
		#endif
		if(zero)
		{
			break;
		}
	}
	ret = str_len - rem;
	if(ret != str_len)
	{
		mk_lang_string_memmove_pc_fn(&str[0], &str[str_len - ret], ((mk_lang_types_usize_t)(ret)));
	}
	return ret;
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_lang_bui_inl_defd_symbols_hex_b[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'a', L'b', L'c', L'd', L'e', L'f'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_hex_w(mk_lang_bui_inl_defd_pct const x, mk_lang_types_wchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_wchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_bool_t zero mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_lo mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_hi mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit % 2 == 0);
	mk_lang_static_assert(mk_lang_bui_inl_defd_sizebits_d > mk_lang_charbit / 2);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	xx = *x;
	ptr = &str[str_len - 1]; ++ptr;
	rem = str_len;
	for(;;)
	{
		mk_lang_bui_inl_defd_to_bi_uchar(&xx, &tuc);
		#if mk_lang_bui_inl_defd_sizebits_d > mk_lang_charbit
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit);
		#else
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		#endif
		zero = mk_lang_bui_inl_defd_is_zero(&xx);
		tuc_lo = ((mk_lang_types_uchar_t)((tuc >> 0) & 0xf));
		if(rem == 0)
		{
			return 0; /* todo return negative? */
		}
		--rem;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_hex_b[tuc_lo];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = (tuc_lo >= 0 && tuc_lo <= 9) ? ((mk_lang_types_wchar_t)(L'0' + tuc_lo)) : ((mk_lang_types_wchar_t)(L'a' + (tuc_lo - 10)));
		#endif
		tuc_hi = ((mk_lang_types_uchar_t)((tuc >> 4) & 0xf));
		if(tuc_hi == 0 && zero)
		{
			break;
		}
		if(rem == 0)
		{
			return 0; /* todo return negative? */
		}
		--rem;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_hex_b[tuc_hi];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = (tuc_hi >= 0 && tuc_hi <= 9) ? ((mk_lang_types_wchar_t)(L'0' + tuc_hi)) : ((mk_lang_types_wchar_t)(L'a' + (tuc_hi - 10)));
		#endif
		if(zero)
		{
			break;
		}
	}
	ret = str_len - rem;
	if(ret != str_len)
	{
		mk_lang_string_memmove_wc_fn(&str[0], &str[str_len - ret], ((mk_lang_types_usize_t)(ret)));
	}
	return ret;
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_bui_inl_defd_symbols_hex_ca[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lang_bui_inl_defd_symbols_hex_cb[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_from_str_hex_n(mk_lang_bui_inl_defd_pt const x, mk_lang_types_pchar_pct const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_pchar_pct it mk_lang_constexpr_init;
	mk_lang_types_pchar_pct ite mk_lang_constexpr_init;
	mk_lang_types_pchar_t e mk_lang_constexpr_init;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	#endif
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t overflow mk_lang_constexpr_init;
	mk_lang_types_sint_t shifts mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t digit mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(mk_lang_charbit % mk_lang_charbit == 0);
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	mk_lang_static_assert(mk_lang_countof(mk_lang_bui_inl_defd_symbols_hex_ca) == mk_lang_countof(mk_lang_bui_inl_defd_symbols_hex_cb));
	#endif

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0)
	{
		return 0;
	}
	it = str;
	ite = str + str_len;
	e = *it;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_hex_ca);
	for(i = 0; i != n; ++i)
	{
		if
		(
			e == mk_lang_bui_inl_defd_symbols_hex_ca[i] ||
			e == mk_lang_bui_inl_defd_symbols_hex_cb[i]
		)
		{
			break;
		}
	}
	if(i == n)
	{
		return 0;
	}
	#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
	if(e >= '0' && e <= '9')
	{
		i = e - '0';
	}
	else if(e >= 'a' && e <= 'f')
	{
		i = 10 + (e - 'a');
	}
	else if(e >= 'A' && e <= 'F')
	{
		i = 10 + (e - 'A');
	}
	else
	{
		return 0;
	}
	#endif
	overflow = 1;
	shifts = 0;
	mk_lang_bui_inl_defd_from_bi_sint(&xx, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_hex_ca);
		for(i = 0; i != n; ++i)
		{
			if
			(
				e == mk_lang_bui_inl_defd_symbols_hex_ca[i] ||
				e == mk_lang_bui_inl_defd_symbols_hex_cb[i]
			)
			{
				break;
			}
		}
		if(i == n)
		{
			break;
		}
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		if(e >= '0' && e <= '9')
		{
			i = e - '0';
		}
		else if(e >= 'a' && e <= 'f')
		{
			i = 10 + (e - 'a');
		}
		else if(e >= 'A' && e <= 'F')
		{
			i = 10 + (e - 'A');
		}
		else
		{
			break;
		}
		#endif
		if(!mk_lang_bui_inl_defd_is_zero(&xx))
		{
			++shifts;
			if(shifts == mk_lang_bui_inl_defd_sizebits_d / mk_lang_charbit * 2)
			{
				overflow = -1;
				break;
			}
		}
		mk_lang_bui_inl_defd_from_bi_sint(&digit, &i);
		mk_lang_bui_inl_defd_shl2(&xx, mk_lang_charbit / 2);
		mk_lang_bui_inl_defd_or2(&xx, &digit);
	}
	if(overflow == 1)
	{
		*x = xx;
	}
	return ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(it - str)) * overflow));
}}

#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_lang_bui_inl_defd_symbols_hex_da[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'a', L'b', L'c', L'd', L'e', L'f'};
mk_lang_constexpr_static_inline mk_lang_types_wchar_t const mk_lang_bui_inl_defd_symbols_hex_db[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'A', L'B', L'C', L'D', L'E', L'F'};
#endif

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_from_str_hex_w(mk_lang_bui_inl_defd_pt const x, mk_lang_types_wchar_pct const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept { mk_lang_bui_inl_defd_flatten
{
	mk_lang_types_wchar_pct it mk_lang_constexpr_init;
	mk_lang_types_wchar_pct ite mk_lang_constexpr_init;
	mk_lang_types_wchar_t e mk_lang_constexpr_init;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	#endif
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t overflow mk_lang_constexpr_init;
	mk_lang_types_sint_t shifts mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_bui_inl_defd_t digit mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(mk_lang_charbit % mk_lang_charbit == 0);
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	mk_lang_static_assert(mk_lang_countof(mk_lang_bui_inl_defd_symbols_hex_da) == mk_lang_countof(mk_lang_bui_inl_defd_symbols_hex_db));
	#endif

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(str_len == 0)
	{
		return 0;
	}
	it = str;
	ite = str + str_len;
	e = *it;
	#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
	n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_hex_da);
	for(i = 0; i != n; ++i)
	{
		if
		(
			e == mk_lang_bui_inl_defd_symbols_hex_da[i] ||
			e == mk_lang_bui_inl_defd_symbols_hex_db[i]
		)
		{
			break;
		}
	}
	if(i == n)
	{
		return 0;
	}
	#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
	if(e >= L'0' && e <= L'9')
	{
		i = e - L'0';
	}
	else if(e >= L'a' && e <= L'f')
	{
		i = 10 + (e - L'a');
	}
	else if(e >= L'A' && e <= L'F')
	{
		i = 10 + (e - L'A');
	}
	else
	{
		return 0;
	}
	#endif
	overflow = 1;
	shifts = 0;
	mk_lang_bui_inl_defd_from_bi_sint(&xx, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		n = mk_lang_countof(mk_lang_bui_inl_defd_symbols_hex_da);
		for(i = 0; i != n; ++i)
		{
			if
			(
				e == mk_lang_bui_inl_defd_symbols_hex_da[i] ||
				e == mk_lang_bui_inl_defd_symbols_hex_db[i]
			)
			{
				break;
			}
		}
		if(i == n)
		{
			break;
		}
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		if(e >= L'0' && e <= L'9')
		{
			i = e - L'0';
		}
		else if(e >= L'a' && e <= L'f')
		{
			i = 10 + (e - L'a');
		}
		else if(e >= L'A' && e <= L'F')
		{
			i = 10 + (e - L'A');
		}
		else
		{
			break;
		}
		#endif
		++shifts;
		if(shifts == mk_lang_bui_inl_defd_sizebits_d / mk_lang_charbit * 2)
		{
			overflow = -1;
			break;
		}
		mk_lang_bui_inl_defd_from_bi_sint(&digit, &i);
		mk_lang_bui_inl_defd_shl2(&xx, mk_lang_charbit / 2);
		mk_lang_bui_inl_defd_or2(&xx, &digit);
	}
	if(overflow == 1)
	{
		*x = xx;
	}
	return ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(it - str)) * overflow));
}}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_binf_n(mk_lang_bui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_bool_t lsb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	mk_lang_static_assert(mk_lang_charbit == 8);

	if(!(str_len >= mk_lang_bui_inl_defd_strlenbin_v))
	{
		return 0; /* todo return negative? */
	}
	xx = *x;
	ptr = &str[mk_lang_bui_inl_defd_strlenbin_v - 1]; ++ptr;
	for(i = 0; i != mk_lang_bui_inl_defd_strlenbin_v; ++i)
	{
		lsb = mk_lang_bui_inl_defd_has_lsb(&xx);
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_bin_a[lsb ? 1 : 0];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = ((mk_lang_types_pchar_t)('0' + (lsb ? 1 : 0)));
		#endif
		mk_lang_bui_inl_defd_shr2(&xx, 1);
	}
	mk_lang_assert(mk_lang_bui_inl_defd_is_zero(&xx));
	return mk_lang_bui_inl_defd_strlenbin_v;
}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_binf_w(mk_lang_bui_inl_defd_pct const x, mk_lang_types_wchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_wchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_bool_t lsb mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	mk_lang_static_assert(mk_lang_charbit == 8);

	if(!(str_len >= mk_lang_bui_inl_defd_strlenbin_v))
	{
		return 0; /* todo return negative? */
	}
	xx = *x;
	ptr = &str[mk_lang_bui_inl_defd_strlenbin_v - 1]; ++ptr;
	for(i = 0; i != mk_lang_bui_inl_defd_strlenbin_v; ++i)
	{
		lsb = mk_lang_bui_inl_defd_has_lsb(&xx);
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_bin_b[lsb ? 1 : 0];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = ((mk_lang_types_pchar_t)(L'0' + (lsb ? 1 : 0)));
		#endif
		mk_lang_bui_inl_defd_shr2(&xx, 1);
	}
	mk_lang_assert(mk_lang_bui_inl_defd_is_zero(&xx));
	return mk_lang_bui_inl_defd_strlenbin_v;
}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_hexf_n(mk_lang_bui_inl_defd_pct const x, mk_lang_types_pchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_lo mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_hi mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(mk_lang_bui_inl_defd_sizebits_d > mk_lang_charbit / 2);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(!(str_len >= mk_lang_bui_inl_defd_strlenhex_v))
	{
		return 0; /* todo return negative? */
	}
	xx = *x;
	ptr = &str[mk_lang_bui_inl_defd_strlenhex_v - 1]; ++ptr;
	for(i = 0; i != mk_lang_bui_inl_defd_strlenhex_v / 2; ++i)
	{
		mk_lang_bui_inl_defd_to_bi_uchar(&xx, &tuc);
		tuc_lo = ((mk_lang_types_uchar_t)((tuc >> (0 * 4)) & 0xf));
		tuc_hi = ((mk_lang_types_uchar_t)((tuc >> (1 * 4)) & 0xf));
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_hex_a[tuc_lo];
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_hex_a[tuc_hi];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = (tuc_lo >= 0 && tuc_lo <= 9) ? ((mk_lang_types_pchar_t)('0' + tuc_lo)) : ((mk_lang_types_pchar_t)('a' + (tuc_lo - 10)));
		--ptr; ptr[0] = (tuc_hi >= 0 && tuc_hi <= 9) ? ((mk_lang_types_pchar_t)('0' + tuc_hi)) : ((mk_lang_types_pchar_t)('a' + (tuc_hi - 10)));
		#endif
		#if mk_lang_bui_inl_defd_sizebits_d > mk_lang_charbit
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit);
		#else
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		#endif
	}
	mk_lang_assert(mk_lang_bui_inl_defd_is_zero(&xx));
	return mk_lang_bui_inl_defd_strlenhex_v;
}

mk_lang_nodiscard mk_lang_bui_inl_defd_forceinline mk_lang_constexpr mk_lang_noalias mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_to_str_hexf_w(mk_lang_bui_inl_defd_pct const x, mk_lang_types_wchar_pt const str, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;
	mk_lang_types_wchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_lo mk_lang_constexpr_init;
	mk_lang_types_uchar_t tuc_hi mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_charbit == 8);
	mk_lang_static_assert(mk_lang_bui_inl_defd_sizebits_d > mk_lang_charbit / 2);

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(!(str_len >= mk_lang_bui_inl_defd_strlenhex_v))
	{
		return 0; /* todo return negative? */
	}
	xx = *x;
	ptr = &str[mk_lang_bui_inl_defd_strlenhex_v - 1]; ++ptr;
	for(i = 0; i != mk_lang_bui_inl_defd_strlenhex_v / 2; ++i)
	{
		mk_lang_bui_inl_defd_to_bi_uchar(&xx, &tuc);
		tuc_lo = ((mk_lang_types_uchar_t)((tuc >> (0 * 4)) & 0xf));
		tuc_hi = ((mk_lang_types_uchar_t)((tuc >> (1 * 4)) & 0xf));
		#if (mk_lang_bui_inl_defd_str_style == 1001) || (mk_lang_bui_inl_defd_str_style == 1003 && !mk_lang_encoding_is_ascii && !mk_lang_encoding_is_ebcdic)
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_hex_b[tuc_lo];
		--ptr; ptr[0] = mk_lang_bui_inl_defd_symbols_hex_b[tuc_hi];
		#elif (mk_lang_bui_inl_defd_str_style == 1002) || (mk_lang_bui_inl_defd_str_style == 1003 && (mk_lang_encoding_is_ascii || mk_lang_encoding_is_ebcdic))
		--ptr; ptr[0] = (tuc_lo >= 0 && tuc_lo <= 9) ? ((mk_lang_types_pchar_t)(L'0' + tuc_lo)) : ((mk_lang_types_pchar_t)(L'a' + (tuc_lo - 10)));
		--ptr; ptr[0] = (tuc_hi >= 0 && tuc_hi <= 9) ? ((mk_lang_types_pchar_t)(L'0' + tuc_hi)) : ((mk_lang_types_pchar_t)(L'a' + (tuc_hi - 10)));
		#endif
		#if mk_lang_bui_inl_defd_sizebits_d > mk_lang_charbit
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit);
		#else
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		mk_lang_bui_inl_defd_shr2(&xx, mk_lang_charbit / 2);
		#endif
	}
	mk_lang_assert(mk_lang_bui_inl_defd_is_zero(&xx));
	return mk_lang_bui_inl_defd_strlenhex_v;
}


#include "mk_lang_bui_inl_defu.h"


#undef mk_lang_bui_t_name
#undef mk_lang_bui_t_base
#undef mk_lang_bui_t_str_style
#undef mk_lang_bui_t_inline
