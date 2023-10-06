include(`mk_lang_bui2_inl.m')dnl
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_restrict.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_types.h"


#include "mk_lang_bui2_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui2_inl_defd_from_base(mk_lang_bui2_inl_defd_pt const a, mk_lang_bui2_inl_defd_base_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui2_inl_defd_t)(*b));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui2_inl_defd_from_bi_bool(mk_lang_bui2_inl_defd_pt const a, mk_lang_types_bool_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui2_inl_defd_t)(!!*b));
}
mm_per_bi_nobool(`
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui2_inl_defd_from_bi_$1(mk_lang_bui2_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui2_inl_defd_t)(*b));
}')dnl

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui2_inl_defd_to_base(mk_lang_bui2_inl_defd_pct const a, mk_lang_bui2_inl_defd_base_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui2_inl_defd_base_t)(*a));
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui2_inl_defd_to_bi_bool(mk_lang_bui2_inl_defd_pct const a, mk_lang_types_bool_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_types_bool_t)(!!*a));
}
mm_per_bi_nobool(`
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui2_inl_defd_to_bi_$1(mk_lang_bui2_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_types_$1_t)(*a));
}')dnl
mm_per_bui(`
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui2_inl_defd_from_buis_$1_le(mk_lang_bui2_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept
{
#if mk_lang_bui2_inl_defd_sizeof_d <= mk_lang_sizeof_bi_$1_t
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui2_inl_defd_t)(*b));
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_bui2_inl_defd_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_bui2_inl_defd_sizeof_d > mk_lang_sizeof_bi_$1_t);
	mk_lang_static_assert(mk_lang_bui2_inl_defd_sizeof_d % mk_lang_sizeof_bi_$1_t == 0);

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lang_bui2_inl_defd_sizeof_d / mk_lang_sizeof_bi_$1_t;
	ta = ((mk_lang_bui2_inl_defd_t)(b[n - 1 - 0]));
	for(i = 1; i != n; ++i)
	{
		ta = ((mk_lang_bui2_inl_defd_t)(ta << (mk_lang_sizeof_bi_$1_t * mk_lang_charbit)));
		ta = ((mk_lang_bui2_inl_defd_t)(ta | ((mk_lang_bui2_inl_defd_t)(b[n - 1 - i]))));
	}
	*a = ta;
#endif
}')dnl
mm_per_bui(`
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui2_inl_defd_to_buis_$1_le(mk_lang_bui2_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept
{
#if mk_lang_bui2_inl_defd_sizeof_d <= mk_lang_sizeof_bi_$1_t
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_types_$1_t)(*a));
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_bui2_inl_defd_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_bui2_inl_defd_sizeof_d > mk_lang_sizeof_bi_$1_t);
	mk_lang_static_assert(mk_lang_bui2_inl_defd_sizeof_d % mk_lang_sizeof_bi_$1_t == 0);

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lang_bui2_inl_defd_sizeof_d / mk_lang_sizeof_bi_$1_t;
	ta = *a;
	b[0 + 0] = ((mk_lang_types_$1_t)(ta));
	for(i = 1; i != n; ++i)
	{
		ta = ((mk_lang_bui2_inl_defd_t)(ta >> (mk_lang_sizeof_bi_$1_t * mk_lang_charbit)));
		b[0 + i] = ((mk_lang_types_$1_t)(ta));
	}
#endif
}')dnl
mm_per_bui(`
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui2_inl_defd_from_buis_$1_be(mk_lang_bui2_inl_defd_pt const a, mk_lang_types_$1_pct const b) mk_lang_noexcept
{
#if mk_lang_bui2_inl_defd_sizeof_d <= mk_lang_sizeof_bi_$1_t
	mk_lang_assert(a);
	mk_lang_assert(b);

	*a = ((mk_lang_bui2_inl_defd_t)(*b));
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_bui2_inl_defd_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_bui2_inl_defd_sizeof_d > mk_lang_sizeof_bi_$1_t);
	mk_lang_static_assert(mk_lang_bui2_inl_defd_sizeof_d % mk_lang_sizeof_bi_$1_t == 0);

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lang_bui2_inl_defd_sizeof_d / mk_lang_sizeof_bi_$1_t;
	ta = ((mk_lang_bui2_inl_defd_t)(b[0 + 0]));
	for(i = 1; i != n; ++i)
	{
		ta = ((mk_lang_bui2_inl_defd_t)(ta << (mk_lang_sizeof_bi_$1_t * mk_lang_charbit)));
		ta = ((mk_lang_bui2_inl_defd_t)(ta | ((mk_lang_bui2_inl_defd_t)(b[0 + i]))));
	}
	*a = ta;
#endif
}')dnl
mm_per_bui(`
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui2_inl_defd_to_buis_$1_be(mk_lang_bui2_inl_defd_pct const a, mk_lang_types_$1_pt const b) mk_lang_noexcept
{
#if mk_lang_bui2_inl_defd_sizeof_d <= mk_lang_sizeof_bi_$1_t
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_types_$1_t)(*a));
#else
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_bui2_inl_defd_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_bui2_inl_defd_sizeof_d > mk_lang_sizeof_bi_$1_t);
	mk_lang_static_assert(mk_lang_bui2_inl_defd_sizeof_d % mk_lang_sizeof_bi_$1_t == 0);

	mk_lang_assert(a);
	mk_lang_assert(b);

	n = mk_lang_bui2_inl_defd_sizeof_d / mk_lang_sizeof_bi_$1_t;
	ta = *a;
	b[n - 1 - 0] = ((mk_lang_types_$1_t)(ta));
	for(i = 1; i != n; ++i)
	{
		ta = ((mk_lang_bui2_inl_defd_t)(ta >> (mk_lang_sizeof_bi_$1_t * mk_lang_charbit)));
		b[n - 1 - i] = ((mk_lang_types_$1_t)(ta));
	}
#endif
}')dnl


#include "mk_lang_bui2_inl_defu.h"


#undef mk_lang_bui2_t_name
#undef mk_lang_bui2_t_base
