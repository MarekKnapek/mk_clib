include(`mk_lang_bui_inl.m')dnl
#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_intrinsic.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


#if defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2005
#include <intrin.h>
#if defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2012 && defined _M_AMD64
#pragma intrinsic(_umul128)
#endif
#if defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && (defined _M_IA64 || defined _M_AMD64 || defined _M_ARM64)
#pragma intrinsic(__umulh)
#endif
#if defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && defined _M_AMD64
#pragma intrinsic(__popcnt64)
#endif
#if defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && (defined _M_IX86 || defined _M_AMD64)
#pragma intrinsic(__popcnt16)
#pragma intrinsic(__popcnt)
#endif
#if defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2008 && defined _M_AMD64
#pragma intrinsic(__ull_rshift)
#endif
#if defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2008 && (defined _M_IX86 || defined _M_AMD64)
#pragma intrinsic(__emulu)
#endif
#if defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2005 && (defined _M_IA64 || defined _M_AMD64 || defined _M_ARM64)
#pragma intrinsic(_BitScanForward64)
#pragma intrinsic(_BitScanReverse64)
#endif
#if defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2005
#pragma intrinsic(_BitScanForward)
#pragma intrinsic(_BitScanReverse)
#endif
#endif


#include "mk_lang_bui_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_from_base(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_base_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui_inl_defd_t)(*b));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_from_bi_bool(mk_lang_bui_inl_defd_pt const a, mk_lang_types_bool_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui_inl_defd_t)(!!*b));
}

mm_per_bi_nobool(`mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_from_bi_$1(mk_lang_bui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui_inl_defd_t)(*b));
}
')
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_to_base(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_base_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_base_t)(*a));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_to_bi_bool(mk_lang_bui_inl_defd_pct const a, mk_lang_types_bool_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_types_bool_t)(!!*a));
}

mm_per_bi_nobool(`mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_to_bi_$1(mk_lang_bui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_types_$1_t)(*a));
}
')
mm_per_bui(`mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_from_buis_$1_le(mk_lang_bui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept
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
}
')
mm_per_bui(`mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_to_buis_$1_le(mk_lang_bui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept
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
}
')
mm_per_bui(`mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_from_buis_$1_be(mk_lang_bui_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept
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
}
')
mm_per_bui(`mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_to_buis_$1_be(mk_lang_bui_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept
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
}
')
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_set_zero(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_inl_defd_t)(0));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_set_max(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_set_one(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_inl_defd_t)(1));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_set_bit(mk_lang_bui_inl_defd_pt const x, mk_lang_types_sint_t const bit_idx) mk_lang_noexcept
{
	mk_lang_assert(x);
	mk_lang_assert(bit_idx >= 0 && bit_idx < ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit)))));

	*x = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(1)) << bit_idx));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_set_mask(mk_lang_bui_inl_defd_pt const x, mk_lang_types_sint_t const bits_count) mk_lang_noexcept
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
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_leading_zeros(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
#if mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2005 && mk_lang_bui_inl_defd_sizebits_d <= 32
	unsigned char nz;
	unsigned long index;

	mk_lang_assert(x);

	nz = ((unsigned char)(_BitScanReverse(&index, ((unsigned long)(*x)))));
	return nz ? ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d - 1)) - ((mk_lang_types_sint_t)(index)))) : ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d));
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2005 && (defined _M_IA64 || defined _M_AMD64 || defined _M_ARM64) && mk_lang_bui_inl_defd_sizebits_d <= 64
	unsigned char nz;
	unsigned long index;

	mk_lang_assert(x);

	nz = ((unsigned char)(_BitScanReverse64(&index, ((unsigned __int64)(*x)))));
	return nz ? ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d - 1)) - ((mk_lang_types_sint_t)(index)))) : ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d));
#else
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
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_leading_ones(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;

	mk_lang_assert(x);

	xx = ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(*x))));
	return mk_lang_bui_inl_defd_count_leading_zeros(&xx);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_trailing_zeros(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
#if mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2005 && mk_lang_bui_inl_defd_sizebits_d <= 32
	unsigned char nz;
	unsigned long index;

	mk_lang_assert(x);

	nz = ((unsigned char)(_BitScanForward(&index, ((unsigned long)(*x)))));
	return nz ? ((mk_lang_types_sint_t)(index)) : ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d));
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2005 && (defined _M_IA64 || defined _M_AMD64 || defined _M_ARM64) && mk_lang_bui_inl_defd_sizebits_d <= 64
	unsigned char nz;
	unsigned long index;

	mk_lang_assert(x);

	nz = ((unsigned char)(_BitScanForward64(&index, ((unsigned __int64)(*x)))));
	return nz ? ((mk_lang_types_sint_t)(index)) : ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d));
#else
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
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_trailing_ones(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;

	mk_lang_assert(x);

	xx = ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(*x))));
	return mk_lang_bui_inl_defd_count_trailing_zeros(&xx);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lang_bui_inl_defd_count_zeros_portable(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
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
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_zeros(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
#if mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && (defined _M_IX86 || defined _M_AMD64) && mk_lang_bui_inl_defd_sizebits_d <= 16
	if(mk_lang_cpuid_has_popcnt())
	{
		return mk_lang_bui_inl_defd_sizebits_d - mk_lang_bui_inl_defd_count_ones(x);
	}
	else
	{
		return mk_lang_bui_inl_defd_count_zeros_portable(x);
	}
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && (defined _M_IX86 || defined _M_AMD64) && mk_lang_bui_inl_defd_sizebits_d <= 32
	if(mk_lang_cpuid_has_popcnt())
	{
		return mk_lang_bui_inl_defd_sizebits_d - mk_lang_bui_inl_defd_count_ones(x);
	}
	else
	{
		return mk_lang_bui_inl_defd_count_zeros_portable(x);
	}
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && defined _M_AMD64 && mk_lang_bui_inl_defd_sizebits_d <= 64
	if(mk_lang_cpuid_has_popcnt())
	{
		return mk_lang_bui_inl_defd_sizebits_d - mk_lang_bui_inl_defd_count_ones(x);
	}
	else
	{
		return mk_lang_bui_inl_defd_count_zeros_portable(x);
	}
#else
	return mk_lang_bui_inl_defd_count_zeros_portable(x);
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lang_bui_inl_defd_count_ones_portable(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_t xx mk_lang_constexpr_init;

	mk_lang_assert(x);

	xx = ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(*x))));
	return mk_lang_bui_inl_defd_count_zeros(&xx);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lang_bui_inl_defd_count_ones(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
#if mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && (defined _M_IX86 || defined _M_AMD64) && mk_lang_bui_inl_defd_sizebits_d <= 16
	unsigned short u;

	mk_lang_assert(x);

	if(mk_lang_cpuid_has_popcnt())
	{
		u = ((unsigned short)(__popcnt16(((unsigned short)(*x)))));
		return ((mk_lang_types_sint_t)(u));
	}
	else
	{
		return mk_lang_bui_inl_defd_count_ones_portable(x);
	}
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && (defined _M_IX86 || defined _M_AMD64) && mk_lang_bui_inl_defd_sizebits_d <= 32
	unsigned int u;

	mk_lang_assert(x);

	if(mk_lang_cpuid_has_popcnt())
	{
		u = ((unsigned int)(__popcnt(((unsigned int)(*x)))));
		return ((mk_lang_types_sint_t)(u));
	}
	else
	{
		return mk_lang_bui_inl_defd_count_ones_portable(x);
	}
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && defined _M_AMD64 && mk_lang_bui_inl_defd_sizebits_d <= 64
	unsigned __int64 u;

	mk_lang_assert(x);

	if(mk_lang_cpuid_has_popcnt())
	{
		u = ((unsigned __int64)(__popcnt64(((unsigned __int64)(*x)))));
		return ((mk_lang_types_sint_t)(u));
	}
	else
	{
		return mk_lang_bui_inl_defd_count_ones_portable(x);
	}
#else
	return mk_lang_bui_inl_defd_count_ones_portable(x);
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_has_lsb(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	return *x & ((mk_lang_bui_inl_defd_t)(1));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_is_zero(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	return *x == ((mk_lang_bui_inl_defd_t)(0));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_is_one(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	return *x == ((mk_lang_bui_inl_defd_t)(1));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_is_max(mk_lang_bui_inl_defd_pct const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	return *x == ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0))));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_eq(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a == *b;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_ne(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a != *b;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_lt(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a < *b;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_le(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a <= *b;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_gt(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a > *b;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_ge(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a >= *b;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_inc2(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) + ((mk_lang_bui_inl_defd_t)(1))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_dec2(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) - ((mk_lang_bui_inl_defd_t)(1))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_inc1(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	++*x;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_dec1(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept
{
	mk_lang_assert(x);

	--*x;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_not2(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(*a))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_or3(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) | ((mk_lang_bui_inl_defd_t)(*b))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_and3(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) & ((mk_lang_bui_inl_defd_t)(*b))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_xor3(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) ^ ((mk_lang_bui_inl_defd_t)(*b))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_not1(mk_lang_bui_inl_defd_pt const x) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_not2(x, x);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_or2(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_or3(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_and2(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_and3(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_xor2(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_xor3(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_shl3(mk_lang_bui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) << b));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_shr3(mk_lang_bui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) >> b));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_rotl3(mk_lang_bui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) << b)) | ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) >> ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit)))) - b))))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_rotr3(mk_lang_bui_inl_defd_pct const a, mk_lang_types_sint_t const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < ((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizebits_d)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) >> b)) | ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) << ((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(((mk_lang_types_sint_t)(mk_lang_bui_inl_defd_sizeof_d)) * ((mk_lang_types_sint_t)(mk_lang_charbit)))) - b))))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_shl2(mk_lang_bui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_shl3(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_shr2(mk_lang_bui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_shr3(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_rotl2(mk_lang_bui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_rotl3(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_rotr2(mk_lang_bui_inl_defd_pt const a, mk_lang_types_sint_t const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_rotr3(a, b, a);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_would_overflow_add_cc(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0)))) - ((mk_lang_bui_inl_defd_t)(*a)))) < ((mk_lang_bui_inl_defd_t)(*b));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_would_overflow_add_cs(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0)))) - ((mk_lang_bui_inl_defd_t)(*a)))) <= ((mk_lang_bui_inl_defd_t)(*b));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_would_overflow_add(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t const cf) mk_lang_noexcept
{
	return cf ? mk_lang_bui_inl_defd_would_overflow_add_cs(a, b) : mk_lang_bui_inl_defd_would_overflow_add_cc(a, b);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_would_overflow_sub_cc(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return ((mk_lang_bui_inl_defd_t)(*a)) < ((mk_lang_bui_inl_defd_t)(*b));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_would_overflow_sub_cs(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return ((mk_lang_bui_inl_defd_t)(*a)) <= ((mk_lang_bui_inl_defd_t)(*b));
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_would_overflow_sub(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t const cf) mk_lang_noexcept
{
	return cf ? mk_lang_bui_inl_defd_would_overflow_sub_cs(a, b) : mk_lang_bui_inl_defd_would_overflow_sub_cc(a, b);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_would_overflow_mul(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return (((mk_lang_bui_inl_defd_t)(*a)) != ((mk_lang_bui_inl_defd_t)(0))) && (((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0)))) / ((mk_lang_bui_inl_defd_t)(*a)))) < ((mk_lang_bui_inl_defd_t)(*b)));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add3_wrap_cid_cod(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) + ((mk_lang_bui_inl_defd_t)(*b))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add3_wrap_cid_coe(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(~((mk_lang_bui_inl_defd_t)(0)))) - ((mk_lang_bui_inl_defd_t)(*a)))) < ((mk_lang_bui_inl_defd_t)(*b));
	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) + ((mk_lang_bui_inl_defd_t)(*b))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add3_wrap_cie_cod(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t const ci, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) + ((mk_lang_bui_inl_defd_t)(*b)))) + ((mk_lang_bui_inl_defd_t)(ci ? ((mk_lang_bui_inl_defd_t)(1)) : ((mk_lang_bui_inl_defd_t)(0))))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add3_wrap_cie_coe(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t const ci, mk_lang_bui_inl_defd_pt const c, mk_lang_bool_t* const co) mk_lang_noexcept
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
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add2_wrap_cid_cod(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_add3_wrap_cid_cod(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add2_wrap_cid_coe(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_add3_wrap_cid_coe(a, b, a, co);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add2_wrap_cie_cod(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t const ci) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_add3_wrap_cie_cod(a, b, ci, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_add2_wrap_cie_coe(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t const ci, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_add3_wrap_cie_coe(a, b, ci, a, co);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub3_wrap_cid_cod(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) - ((mk_lang_bui_inl_defd_t)(*b))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub3_wrap_cid_coe(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ((mk_lang_bui_inl_defd_t)(*a)) < ((mk_lang_bui_inl_defd_t)(*b));
	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) - ((mk_lang_bui_inl_defd_t)(*b))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub3_wrap_cie_cod(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t const ci, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) - ((mk_lang_bui_inl_defd_t)(*b)))) - ((mk_lang_bui_inl_defd_t)(ci ? ((mk_lang_bui_inl_defd_t)(1)) : ((mk_lang_bui_inl_defd_t)(0))))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub3_wrap_cie_coe(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t const ci, mk_lang_bui_inl_defd_pt const c, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ci ? (((mk_lang_bui_inl_defd_t)(*a)) <= ((mk_lang_bui_inl_defd_t)(*b))) : (((mk_lang_bui_inl_defd_t)(*a)) < ((mk_lang_bui_inl_defd_t)(*b)));
	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) - ((mk_lang_bui_inl_defd_t)(*b)))) - ((mk_lang_bui_inl_defd_t)(ci ? ((mk_lang_bui_inl_defd_t)(1)) : ((mk_lang_bui_inl_defd_t)(0))))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub2_wrap_cid_cod(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_sub3_wrap_cid_cod(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub2_wrap_cid_coe(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_sub3_wrap_cid_coe(a, b, a, co);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub2_wrap_cie_cod(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t const ci) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_sub3_wrap_cie_cod(a, b, ci, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_sub2_wrap_cie_coe(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bool_t const ci, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_sub3_wrap_cie_coe(a, b, ci, a, co);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul3_wrap_lo(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) * ((mk_lang_bui_inl_defd_t)(*b))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul3_wrap_hi(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
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
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && (defined _M_IA64 || defined _M_AMD64 || defined _M_ARM64) && mk_lang_bui_inl_defd_sizebits_d == 64
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(__umulh(((unsigned __int64)(*a)), ((unsigned __int64)(*b)))))));
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2008 && defined _M_AMD64 && mk_lang_bui_inl_defd_sizebits_d == 32
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(__ull_rshift(((unsigned __int64)(__emulu(((unsigned int)(*a)), ((unsigned int)(*b))))), 32)))));
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2008 && defined _M_IX86 && mk_lang_bui_inl_defd_sizebits_d == 32
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(((unsigned __int64)(__emulu(((unsigned int)(*a)), ((unsigned int)(*b))))) >> 32))));
#else
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
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul4_wrap_wi(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c, mk_lang_bui_inl_defd_pt const d) mk_lang_noexcept
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
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2012 && defined _M_AMD64 && mk_lang_bui_inl_defd_sizebits_d == 64
	unsigned __int64 cc;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	*c = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(_umul128(((unsigned __int64)(*a)), ((unsigned __int64)(*b)), &cc)))));
	*d = ((mk_lang_bui_inl_defd_t)(cc));
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2010 && (defined _M_IA64 || defined _M_AMD64 || defined _M_ARM64) && mk_lang_bui_inl_defd_sizebits_d == 64
	unsigned __int64 aa;
	unsigned __int64 bb;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	aa = ((unsigned __int64)(*a));
	bb = ((unsigned __int64)(*b));
	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) * ((mk_lang_bui_inl_defd_t)(*b))));
	*d = ((mk_lang_bui_inl_defd_t)(((unsigned __int64)(__umulh(aa, bb)))));
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2008 && defined _M_AMD64 && mk_lang_bui_inl_defd_sizebits_d == 32
	unsigned int aa;
	unsigned int bb;
	unsigned __int64 cc;

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
#elif mk_lang_intrinsic_has && defined _MSC_VER && _MSC_VER >= mk_lang_msvc_ver_2008 && defined _M_IX86 && mk_lang_bui_inl_defd_sizebits_d == 32
	unsigned int aa;
	unsigned int bb;
	unsigned __int64 cc;

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
#else
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
#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul2_wrap_lo(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_mul3_wrap_lo(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul2_wrap_hi(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_mul3_wrap_hi(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mul2_wrap_wi(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pt const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_mul4_wrap_wi(a, b, a, b);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_div3_wrap(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) / ((mk_lang_bui_inl_defd_t)(*b))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mod3_wrap(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_t)(((mk_lang_bui_inl_defd_t)(*a)) % ((mk_lang_bui_inl_defd_t)(*b))));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_divmod4_wrap(mk_lang_bui_inl_defd_pct const a, mk_lang_bui_inl_defd_pct const b, mk_lang_bui_inl_defd_pt const c, mk_lang_bui_inl_defd_pt const d) mk_lang_noexcept
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
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_div2_wrap(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_div3_wrap(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_mod2_wrap(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pct const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_mod3_wrap(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_inl_defd_divmod2_wrap(mk_lang_bui_inl_defd_pt const a, mk_lang_bui_inl_defd_pt const b) mk_lang_noexcept
{
	mk_lang_bui_inl_defd_divmod4_wrap(a, b, a, b);
}


#include "mk_lang_bui_inl_defu.h"


#undef mk_lang_bui_t_name
#undef mk_lang_bui_t_base
