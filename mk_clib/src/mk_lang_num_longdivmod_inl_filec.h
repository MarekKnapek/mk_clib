#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


#include "mk_lang_num_longdivmod_inl_defd.h"


#define mk_lang_overlap_t_name mk_lang_concat(mk_lang_num_longdivmod_inl_defd_name, _overlap)
#define mk_lang_overlap_t_base mk_lang_num_longdivmod_inl_defd_tn1
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#define mk_lang_num_longdivmod_inl_defd_overlap mk_lang_concat(mk_lang_concat(mk_lang_num_longdivmod_inl_defd_name, _overlap), _fn)


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lang_num_longdivmod_inl_defd_get_lena(mk_lang_num_longdivmod_inl_defd_tn1_pct const a) mk_lang_noexcept
{
	mk_lang_types_sint_t lena mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);

	lena = 0;
	n = mk_lang_num_longdivmod_inl_defd_lena;
	for(i = 0; i != n; ++i)
	{
		if(!mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&a[mk_lang_num_longdivmod_inl_defd_idxa((n - 1) - i)]))
		{
			lena = n - i;
			break;
		}
	}
	mk_lang_assert(lena >= 0 && lena <= n);
	return lena;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_lang_num_longdivmod_inl_defd_get_lenb(mk_lang_num_longdivmod_inl_defd_tn1_pct const a) mk_lang_noexcept
{
	mk_lang_types_sint_t lenb mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(a);

	lenb = 0;
	n = mk_lang_num_longdivmod_inl_defd_lenb;
	for(i = 0; i != n; ++i)
	{
		if(!mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&a[mk_lang_num_longdivmod_inl_defd_idxa((n - 1) - i)]))
		{
			lenb = n - i;
			break;
		}
	}
	mk_lang_assert(lenb >= 0 && lenb <= n);
	return lenb;
}

#if mk_lang_num_longdivmod_inl_defd_lena == 1 && mk_lang_num_longdivmod_inl_defd_lenb == 1
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_inl_defd_divmod4_1_1(mk_lang_num_longdivmod_inl_defd_tn1_pct const a, mk_lang_num_longdivmod_inl_defd_tn1_pct const b, mk_lang_num_longdivmod_inl_defd_tn1_pt const c, mk_lang_num_longdivmod_inl_defd_tn1_pt const d) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lena == 1);
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lenb == 1);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(c, mk_lang_num_longdivmod_inl_defd_lenc, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&b[mk_lang_num_longdivmod_inl_defd_idxb(0)]));

	mk_lang_num_longdivmod_inl_defd_tn1_divmod4_wrap(a, b, c, d);
}
#endif

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_inl_defd_divmod4_0_n(mk_lang_num_longdivmod_inl_defd_tn1_pct const a, mk_lang_num_longdivmod_inl_defd_tn1_pct const b, mk_lang_num_longdivmod_inl_defd_tn1_pt const c, mk_lang_num_longdivmod_inl_defd_tn1_pt const d) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lena >= 1);
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lenb >= 1);

	mk_lang_assert(a); ((mk_lang_types_void_t)(a));
	mk_lang_assert(b); ((mk_lang_types_void_t)(b));
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(c, mk_lang_num_longdivmod_inl_defd_lenc, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(mk_lang_num_longdivmod_inl_defd_get_lena(a) == 0);
	mk_lang_assert(mk_lang_num_longdivmod_inl_defd_get_lenb(b) != 0);

	n = mk_lang_num_longdivmod_inl_defd_lenc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_num_longdivmod_inl_defd_tn1_set_zero(&c[mk_lang_num_longdivmod_inl_defd_idxc(i)]);
	}
	n = mk_lang_num_longdivmod_inl_defd_lend;
	for(i = 0; i != n; ++i)
	{
		mk_lang_num_longdivmod_inl_defd_tn1_set_zero(&d[mk_lang_num_longdivmod_inl_defd_idxd(i)]);
	}
}

#if mk_lang_num_longdivmod_inl_defd_lena >= 2 && mk_lang_num_longdivmod_inl_defd_lenb >= 2
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_inl_defd_divmod4_b_g(mk_lang_num_longdivmod_inl_defd_tn1_pct const a, mk_lang_num_longdivmod_inl_defd_tn1_pct const b, mk_lang_num_longdivmod_inl_defd_tn1_pt const c, mk_lang_num_longdivmod_inl_defd_tn1_pt const d) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lena >= 2);
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lenb >= 2);
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lend <= mk_lang_num_longdivmod_inl_defd_lena);

	mk_lang_assert(a);
	mk_lang_assert(b); ((mk_lang_types_void_t)(b));
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(c, mk_lang_num_longdivmod_inl_defd_lenc, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(mk_lang_num_longdivmod_inl_defd_get_lenb(b) != 0);
	mk_lang_assert(mk_lang_num_longdivmod_inl_defd_get_lena(a) < mk_lang_num_longdivmod_inl_defd_get_lenb(b));

	n = mk_lang_num_longdivmod_inl_defd_lend;
	for(i = 0; i != n; ++i)
	{
		d[mk_lang_num_longdivmod_inl_defd_idxd(i)] = a[mk_lang_num_longdivmod_inl_defd_idxa(i)];
	}
	n = mk_lang_num_longdivmod_inl_defd_lenc;
	for(i = 0; i != n; ++i)
	{
		mk_lang_num_longdivmod_inl_defd_tn1_set_zero(&c[mk_lang_num_longdivmod_inl_defd_idxc(i)]);
	}
}
#endif

#if mk_lang_num_longdivmod_inl_defd_lena >= 2
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_inl_defd_divmod4_x_1(mk_lang_num_longdivmod_inl_defd_tn1_pct const a, mk_lang_num_longdivmod_inl_defd_tn1_pct const b, mk_lang_num_longdivmod_inl_defd_tn1_pt const c, mk_lang_num_longdivmod_inl_defd_tn1_pt const d, mk_lang_types_sint_t const lena) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn1_t tsa mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn2_t tba mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn2_t tbb mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn2_t tbc mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn2_t tbd mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_tn2_sizebits_d >= 2 * mk_lang_num_longdivmod_inl_defd_tn1_sizebits_d);
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lena >= 2);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(a, mk_lang_num_longdivmod_inl_defd_lena, c, mk_lang_num_longdivmod_inl_defd_lenc));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(a, mk_lang_num_longdivmod_inl_defd_lena, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(b, mk_lang_num_longdivmod_inl_defd_lenb, c, mk_lang_num_longdivmod_inl_defd_lenc));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(b, mk_lang_num_longdivmod_inl_defd_lenb, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(c, mk_lang_num_longdivmod_inl_defd_lenc, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&b[mk_lang_num_longdivmod_inl_defd_idxb(0)]));
	mk_lang_assert(lena >= 1 && lena <= mk_lang_num_longdivmod_inl_defd_lena);

	n = mk_lang_num_longdivmod_inl_defd_lena - lena;
	for(i = 0; i != n; ++i)
	{
		mk_lang_num_longdivmod_inl_defd_tn1_set_zero(&c[mk_lang_num_longdivmod_inl_defd_idxc(mk_lang_num_longdivmod_inl_defd_lenc - 1) - i]);
	}
	n = mk_lang_num_longdivmod_inl_defd_lend - 1;
	for(i = 0; i != n; ++i)
	{
		mk_lang_num_longdivmod_inl_defd_tn1_set_zero(&d[mk_lang_num_longdivmod_inl_defd_idxd(mk_lang_num_longdivmod_inl_defd_lend - 1) - i]);
	}
	if(lena == 1)
	{
		mk_lang_num_longdivmod_inl_defd_tn1_divmod4_wrap(&a[mk_lang_num_longdivmod_inl_defd_idxa(lena - 1) - 0], &b[mk_lang_num_longdivmod_inl_defd_idxb(0)], &c[mk_lang_num_longdivmod_inl_defd_idxc(lena - 1) - 0], &d[mk_lang_num_longdivmod_inl_defd_idxd(0)]);
	}
	else
	{
		mk_lang_assert(lena >= 2);
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&b[mk_lang_num_longdivmod_inl_defd_idxa(0)], &tba);
		mk_lang_num_longdivmod_inl_defd_tn1_divmod4_wrap(&a[mk_lang_num_longdivmod_inl_defd_idxa(lena - 1) - 0], &b[mk_lang_num_longdivmod_inl_defd_idxb(0)], &c[mk_lang_num_longdivmod_inl_defd_idxc((lena - 1) - 0)], &tsa);
		for(i = 1; i != lena - 1; ++i)
		{
			mk_lang_num_longdivmod_inl_defd_tn1d_to_tn2(&tsa, &a[mk_lang_num_longdivmod_inl_defd_idxa((lena - 1) - i)], &tbb);
			mk_lang_num_longdivmod_inl_defd_tn2_divmod4_wrap(&tbb, &tba, &tbc, &tbd);
			mk_lang_num_longdivmod_t_tn2_get_hi(&tbc, &tsa); mk_lang_assert(mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&tsa));
			mk_lang_num_longdivmod_t_tn2_get_hi(&tbd, &tsa); mk_lang_assert(mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&tsa));
			mk_lang_num_longdivmod_t_tn2_get_lo(&tbc, &c[mk_lang_num_longdivmod_inl_defd_idxc((lena - 1) - i)]);
			mk_lang_num_longdivmod_t_tn2_get_lo(&tbd, &tsa);
		}
		mk_lang_num_longdivmod_inl_defd_tn1d_to_tn2(&tsa, &a[mk_lang_num_longdivmod_inl_defd_idxa((lena - 1) - i)], &tbb);
		mk_lang_num_longdivmod_inl_defd_tn2_divmod4_wrap(&tbb, &tba, &tbc, &tbd);
		mk_lang_num_longdivmod_t_tn2_get_hi(&tbc, &tsa); mk_lang_assert(mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&tsa));
		mk_lang_num_longdivmod_t_tn2_get_hi(&tbd, &tsa); mk_lang_assert(mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&tsa));
		mk_lang_num_longdivmod_t_tn2_get_lo(&tbc, &c[mk_lang_num_longdivmod_inl_defd_idxc((lena - 1) - i)]);
		mk_lang_num_longdivmod_t_tn2_get_lo(&tbd, &d[mk_lang_num_longdivmod_inl_defd_idxd(0)]);
	}
}
#endif

#if mk_lang_num_longdivmod_inl_defd_lena >= 1 && mk_lang_num_longdivmod_inl_defd_lenb == 1
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_inl_defd_divmod4_n_1(mk_lang_num_longdivmod_inl_defd_tn1_pct const a, mk_lang_num_longdivmod_inl_defd_tn1_pct const b, mk_lang_num_longdivmod_inl_defd_tn1_pt const c, mk_lang_num_longdivmod_inl_defd_tn1_pt const d) mk_lang_noexcept
{
	mk_lang_types_sint_t lena mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lena >= 1);
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lenb == 1);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(c, mk_lang_num_longdivmod_inl_defd_lenc, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&b[mk_lang_num_longdivmod_inl_defd_idxb(0)]));

	lena = mk_lang_num_longdivmod_inl_defd_get_lena(a);
	if(lena == 0)
	{
		mk_lang_num_longdivmod_inl_defd_divmod4_0_n(a, b, c, d);
	}
	else
	{
		mk_lang_num_longdivmod_inl_defd_divmod4_x_1(a, b, c, d, lena);
	}
}
#endif

#if mk_lang_num_longdivmod_inl_defd_lena >= 2 && mk_lang_num_longdivmod_inl_defd_lenb >= 2
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_inl_defd_divmod4_x_x(mk_lang_num_longdivmod_inl_defd_tn1_pct const a, mk_lang_num_longdivmod_inl_defd_tn1_pct const b, mk_lang_num_longdivmod_inl_defd_tn1_pt const c, mk_lang_num_longdivmod_inl_defd_tn1_pt const d, mk_lang_types_sint_t const lena, mk_lang_types_sint_t const lenb) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn1_t tsa mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn2_t tba mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn2_t tbb mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn2_t fb mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn1_t fs mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn1_t aa[mk_lang_num_longdivmod_inl_defd_lena + 1] mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn1_t bb[mk_lang_num_longdivmod_inl_defd_lenb] mk_lang_constexpr_init;
	mk_lang_types_sint_t id mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn2_t tbc mk_lang_constexpr_init;
	#if mk_lang_num_longdivmod_inl_defd_alg == 2
	#elif mk_lang_num_longdivmod_inl_defd_alg == 3
	mk_lang_num_longdivmod_inl_defd_tn3_t tha mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn3_t thb mk_lang_constexpr_init;
	mk_lang_num_longdivmod_inl_defd_tn3_t thc mk_lang_constexpr_init;
	#endif
	mk_lang_num_longdivmod_inl_defd_tn1_t dq[mk_lang_num_longdivmod_inl_defd_lenb + 1] mk_lang_constexpr_init;
	mk_lang_types_bool_t tboa mk_lang_constexpr_init;
	mk_lang_types_bool_t tbob mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lena >= 2);
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lenb >= 2);
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_tn2_sizebits_d >= 2 * mk_lang_num_longdivmod_inl_defd_tn1_sizebits_d);
	#if mk_lang_num_longdivmod_inl_defd_alg == 2
	#elif mk_lang_num_longdivmod_inl_defd_alg == 3
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_tn3_sizebits_d >= 3 * mk_lang_num_longdivmod_inl_defd_tn1_sizebits_d);
	#endif

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(b != c);
	mk_lang_assert(b != d);
	mk_lang_assert(c != d);
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(a, mk_lang_num_longdivmod_inl_defd_lena, c, mk_lang_num_longdivmod_inl_defd_lenc));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(a, mk_lang_num_longdivmod_inl_defd_lena, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(b, mk_lang_num_longdivmod_inl_defd_lenb, c, mk_lang_num_longdivmod_inl_defd_lenc));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(b, mk_lang_num_longdivmod_inl_defd_lenb, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(c, mk_lang_num_longdivmod_inl_defd_lenc, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(lena >= 2);
	mk_lang_assert(lenb >= 2);
	mk_lang_assert(lena <= mk_lang_num_longdivmod_inl_defd_lena);
	mk_lang_assert(lenb <= mk_lang_num_longdivmod_inl_defd_lenb);
	mk_lang_assert(lena >= lenb);

	n = mk_lang_num_longdivmod_inl_defd_lenc;
	for(i = 0; i != n - ((lena - lenb) + 1); ++i)
	{
		mk_lang_num_longdivmod_inl_defd_tn1_set_zero(&c[mk_lang_num_longdivmod_inl_defd_idxc((mk_lang_num_longdivmod_inl_defd_lenc - 1) - i)]);
	}
	n = mk_lang_num_longdivmod_inl_defd_lend;
	for(i = 0; i != n - lenb; ++i)
	{
		mk_lang_num_longdivmod_inl_defd_tn1_set_zero(&d[mk_lang_num_longdivmod_inl_defd_idxd((mk_lang_num_longdivmod_inl_defd_lend - 1) - i)]);
	}
	mk_lang_num_longdivmod_inl_defd_tn1_set_max(&tsa);
	mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tba);
	mk_lang_num_longdivmod_inl_defd_tn2_inc1(&tba);
	mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&b[mk_lang_num_longdivmod_inl_defd_idxb((lenb - 1) - 0)], &tbb);
	mk_lang_num_longdivmod_inl_defd_tn2_inc1(&tbb);
	mk_lang_num_longdivmod_inl_defd_tn2_div3_wrap(&tba, &tbb, &fb);
	mk_lang_num_longdivmod_t_tn2_get_hi(&fb, &fs); mk_lang_assert(mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&fs));
	mk_lang_num_longdivmod_t_tn2_get_lo(&fb, &fs);
	if(mk_lang_num_longdivmod_inl_defd_tn1_is_one(&fs))
	{
		for(i = 0; i != lena; ++i)
		{
			aa[i] = a[mk_lang_num_longdivmod_inl_defd_idxa(i)];
		}
		mk_lang_num_longdivmod_inl_defd_tn1_set_zero(&aa[lena]);
		for(i = 0; i != lenb; ++i)
		{
			bb[i] = b[mk_lang_num_longdivmod_inl_defd_idxb(i)];
		}
	}
	else
	{
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&a[mk_lang_num_longdivmod_inl_defd_idxa(0)], &tba);
		mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &fb);
		mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &aa[0]);
		mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa);
		for(i = 1; i != lena - 1; ++i)
		{
			mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&a[mk_lang_num_longdivmod_inl_defd_idxa(i)], &tba);
			mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &fb);
			mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbb);
			mk_lang_num_longdivmod_inl_defd_tn2_add2_wrap_cid_cod(&tba, &tbb);
			mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &aa[i]);
			mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa);
		}
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&a[mk_lang_num_longdivmod_inl_defd_idxa(i)], &tba);
		mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &fb);
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbb);
		mk_lang_num_longdivmod_inl_defd_tn2_add2_wrap_cid_cod(&tba, &tbb);
		mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &aa[i]);
		mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &aa[lena]);
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&b[mk_lang_num_longdivmod_inl_defd_idxb(0)], &tba);
		mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &fb);
		mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &bb[0]);
		mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa);
		for(i = 1; i != lenb - 1; ++i)
		{
			mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&b[mk_lang_num_longdivmod_inl_defd_idxb(i)], &tba);
			mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &fb);
			mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbb);
			mk_lang_num_longdivmod_inl_defd_tn2_add2_wrap_cid_cod(&tba, &tbb);
			mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &bb[i]);
			mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa);
		}
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&b[mk_lang_num_longdivmod_inl_defd_idxb(i)], &tba);
		mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &fb);
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbb);
		mk_lang_num_longdivmod_inl_defd_tn2_add2_wrap_cid_cod(&tba, &tbb);
		mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &bb[i]);
		mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa); mk_lang_assert(mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&tsa));
	}
	for(id = 0; id != (lena - lenb) + 1; ++id)
	{
		#if mk_lang_num_longdivmod_inl_defd_alg == 2
		mk_lang_num_longdivmod_inl_defd_tn1d_to_tn2(&aa[lena - id - 0], &aa[lena - id - 1], &tbc);
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&bb[lenb - 1], &tbb);
		mk_lang_num_longdivmod_inl_defd_tn2_div3_wrap(&tbc, &tbb, &tba);
		#elif mk_lang_num_longdivmod_inl_defd_alg == 3
		mk_lang_num_longdivmod_inl_defd_tn1t_to_tn3(&aa[lena - id - 0], &aa[lena - id - 1], &aa[lena - id - 2], &tha);
		mk_lang_num_longdivmod_inl_defd_tn1d_to_tn3(&bb[lenb - 1], &bb[lenb - 2], &thb);
		mk_lang_num_longdivmod_inl_defd_tn3_div3_wrap(&tha, &thb, &thc);
		mk_lang_num_longdivmod_inl_defd_tn3_get_tn2(&thc, &tba);
		#endif
		mk_lang_num_longdivmod_inl_defd_tn1_set_max(&tsa);
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbb);
		mk_lang_num_longdivmod_t_tn2_get_lo(mk_lang_num_longdivmod_inl_defd_tn2_lt(&tba, &tbb) ? &tba : &tbb, &tsa);
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbb);
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&bb[0], &tba);
		mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &tbb);
		mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &dq[0]);
		mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa);
		for(i = 1; i != lenb - 1; ++i)
		{
			mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&bb[i], &tba);
			mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &tbb);
			mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbc);
			mk_lang_num_longdivmod_inl_defd_tn2_add2_wrap_cid_cod(&tba, &tbc);
			mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &dq[i]);
			mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa);
		}
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&bb[i], &tba);
		mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &tbb);
		mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbc);
		mk_lang_num_longdivmod_inl_defd_tn2_add2_wrap_cid_cod(&tba, &tbc);
		mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &dq[i]);
		mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &dq[i + 1]);
		tboa = mk_lang_false;
		for(i = 0; i != lenb + 1; ++i)
		{
			if(mk_lang_num_longdivmod_inl_defd_tn1_gt(&dq[lenb - i], &aa[(lena - id) - i])){ tboa = mk_lang_true; break; }
			if(mk_lang_num_longdivmod_inl_defd_tn1_lt(&dq[lenb - i], &aa[(lena - id) - i])){ tboa = mk_lang_false; break; }
		}
		if(tboa)
		{
			mk_lang_num_longdivmod_inl_defd_tn2_dec1(&tbb);
			mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&bb[0], &tba);
			mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &tbb);
			mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &dq[0]);
			mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa);
			for(i = 1; i != lenb - 1; ++i)
			{
				mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&bb[i], &tba);
				mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &tbb);
				mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbc);
				mk_lang_num_longdivmod_inl_defd_tn2_add2_wrap_cid_cod(&tba, &tbc);
				mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &dq[i]);
				mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa);
			}
			mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&bb[i], &tba);
			mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &tbb);
			mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbc);
			mk_lang_num_longdivmod_inl_defd_tn2_add2_wrap_cid_cod(&tba, &tbc);
			mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &dq[i]);
			mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &dq[i + 1]);
			#if mk_lang_num_longdivmod_inl_defd_alg == 2
			tboa = mk_lang_false;
			for(i = 0; i != lenb + 1; ++i)
			{
				if(mk_lang_num_longdivmod_inl_defd_tn1_gt(&dq[lenb - i], &aa[(lena - id) - i])){ tboa = mk_lang_true; break; }
				if(mk_lang_num_longdivmod_inl_defd_tn1_lt(&dq[lenb - i], &aa[(lena - id) - i])){ tboa = mk_lang_false; break; }
			}
			if(tboa)
			{
				mk_lang_num_longdivmod_inl_defd_tn2_dec1(&tbb);
				mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&bb[0], &tba);
				mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &tbb);
				mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &dq[0]);
				mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa);
				for(i = 1; i != lenb - 1; ++i)
				{
					mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&bb[i], &tba);
					mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &tbb);
					mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbc);
					mk_lang_num_longdivmod_inl_defd_tn2_add2_wrap_cid_cod(&tba, &tbc);
					mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &dq[i]);
					mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &tsa);
				}
				mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&bb[i], &tba);
				mk_lang_num_longdivmod_inl_defd_tn2_mul2_wrap_lo(&tba, &tbb);
				mk_lang_num_longdivmod_inl_defd_tn1s_to_tn2(&tsa, &tbc);
				mk_lang_num_longdivmod_inl_defd_tn2_add2_wrap_cid_cod(&tba, &tbc);
				mk_lang_num_longdivmod_t_tn2_get_lo(&tba, &dq[i]);
				mk_lang_num_longdivmod_t_tn2_get_hi(&tba, &dq[i + 1]);
			}
			#elif mk_lang_num_longdivmod_inl_defd_alg == 3
			#endif
		}
		mk_lang_num_longdivmod_t_tn2_get_lo(&tbb, &c[mk_lang_num_longdivmod_inl_defd_idxc((lena - lenb) - id)]);
		tboa = mk_lang_num_longdivmod_inl_defd_tn1_lt(&aa[(lena - lenb) - id], &dq[0]);
		mk_lang_num_longdivmod_inl_defd_tn1_sub2_wrap_cid_cod(&aa[(lena - lenb) - id], &dq[0]);
		tbob = tboa;
		for(i = 1; i != lenb; ++i)
		{
			tboa = tbob ? mk_lang_num_longdivmod_inl_defd_tn1_le(&aa[((lena - lenb) - id) + i], &dq[i]) : mk_lang_num_longdivmod_inl_defd_tn1_lt(&aa[((lena - lenb) - id) + i], &dq[i]);
			mk_lang_num_longdivmod_inl_defd_tn1_sub2_wrap_cid_cod(&aa[((lena - lenb) - id) + i], &dq[i]);
			if(tbob){ mk_lang_num_longdivmod_inl_defd_tn1_dec1(&aa[((lena - lenb) - id) + i]); }
			tbob = tboa;
		}
		mk_lang_num_longdivmod_inl_defd_tn1_sub3_wrap_cid_cod(&aa[((lena - lenb) - id) + i], &dq[i], &tsa);
		if(tbob){ mk_lang_num_longdivmod_inl_defd_tn1_dec1(&tsa); }
		mk_lang_assert(mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&tsa));
	}
	if(mk_lang_num_longdivmod_inl_defd_tn1_is_one(&fs))
	{
		for(i = 0; i != lenb; ++i)
		{
			d[mk_lang_num_longdivmod_inl_defd_idxd(((mk_lang_num_longdivmod_inl_defd_lend - 1) - (mk_lang_num_longdivmod_inl_defd_lend - lenb)) - i)] = aa[(lenb - 1) - i];
		}
	}
	else
	{
		mk_lang_num_longdivmod_inl_defd_tn1_div3_wrap(&aa[(lenb - 1) - 0], &fs, &tsa);
		d[mk_lang_num_longdivmod_inl_defd_idxd(((mk_lang_num_longdivmod_inl_defd_lend - 1) - (mk_lang_num_longdivmod_inl_defd_lend - lenb)) - 0)] = tsa;
		mk_lang_num_longdivmod_inl_defd_tn1_mul2_wrap_lo(&tsa, &fs);
		mk_lang_num_longdivmod_inl_defd_tn1_sub3_wrap_cid_cod(&aa[(lenb - 1) - 0], &tsa, &tsa);
		for(i = 1; i != lenb - 1; ++i)
		{
			mk_lang_num_longdivmod_inl_defd_tn1d_to_tn2(&tsa, &aa[(lenb - 1) - i], &tba);
			mk_lang_num_longdivmod_inl_defd_tn2_div3_wrap(&tba, &fb, &tbc);
			mk_lang_num_longdivmod_t_tn2_get_hi(&tbc, &tsa); mk_lang_assert(mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&tsa));
			mk_lang_num_longdivmod_t_tn2_get_lo(&tbc, &tsa);
			d[mk_lang_num_longdivmod_inl_defd_idxd(((mk_lang_num_longdivmod_inl_defd_lend - 1) - (mk_lang_num_longdivmod_inl_defd_lend - lenb)) - i)] = tsa;
			mk_lang_num_longdivmod_inl_defd_tn1_mul2_wrap_lo(&tsa, &fs);
			mk_lang_num_longdivmod_inl_defd_tn1_sub3_wrap_cid_cod(&aa[(lenb - 1) - i], &tsa, &tsa);
		}
		mk_lang_num_longdivmod_inl_defd_tn1d_to_tn2(&tsa, &aa[(lenb - 1) - i], &tba);
		mk_lang_num_longdivmod_inl_defd_tn2_div3_wrap(&tba, &fb, &tbc);
		mk_lang_num_longdivmod_t_tn2_get_hi(&tbc, &tsa); mk_lang_assert(mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&tsa));
		mk_lang_num_longdivmod_t_tn2_get_lo(&tbc, &tsa);
		d[mk_lang_num_longdivmod_inl_defd_idxd(((mk_lang_num_longdivmod_inl_defd_lend - 1) - (mk_lang_num_longdivmod_inl_defd_lend - lenb)) - i)] = tsa;
		mk_lang_num_longdivmod_inl_defd_tn1_mul2_wrap_lo(&tsa, &fs); mk_lang_num_longdivmod_inl_defd_tn1_sub3_wrap_cid_cod(&aa[(lenb - 1) - i], &tsa, &tsa); mk_lang_assert(mk_lang_num_longdivmod_inl_defd_tn1_is_zero(&tsa));
	}
}
#endif

#if mk_lang_num_longdivmod_inl_defd_lena >= 2 && mk_lang_num_longdivmod_inl_defd_lenb >= 2
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_num_longdivmod_inl_defd_divmod4_n_n(mk_lang_num_longdivmod_inl_defd_tn1_pct const a, mk_lang_num_longdivmod_inl_defd_tn1_pct const b, mk_lang_num_longdivmod_inl_defd_tn1_pt const c, mk_lang_num_longdivmod_inl_defd_tn1_pt const d) mk_lang_noexcept
{
	mk_lang_types_sint_t lena mk_lang_constexpr_init;
	mk_lang_types_sint_t lenb mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lena >= 2);
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lenb >= 2);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(c, mk_lang_num_longdivmod_inl_defd_lenc, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(mk_lang_num_longdivmod_inl_defd_get_lenb(b) != 0);

	lena = mk_lang_num_longdivmod_inl_defd_get_lena(a);
	if(lena == 0)
	{
		mk_lang_num_longdivmod_inl_defd_divmod4_0_n(a, b, c, d);
	}
	else
	{
		lenb = mk_lang_num_longdivmod_inl_defd_get_lena(b); mk_lang_assert(lenb != 0);
		if(lenb == 1)
		{
			mk_lang_num_longdivmod_inl_defd_divmod4_x_1(a, &b[mk_lang_num_longdivmod_inl_defd_idxb(0)], c, d, lena);
		}
		else if(lena < lenb)
		{
			mk_lang_num_longdivmod_inl_defd_divmod4_b_g(a, b, c, d);
		}
		else
		{
			mk_lang_num_longdivmod_inl_defd_divmod4_x_x(a, b, c, d, lena, lenb);
		}
	}
}
#endif


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_num_longdivmod_inl_defd_divmod4(mk_lang_num_longdivmod_inl_defd_tn1_pct const a, mk_lang_num_longdivmod_inl_defd_tn1_pct const b, mk_lang_num_longdivmod_inl_defd_tn1_pt const c, mk_lang_num_longdivmod_inl_defd_tn1_pt const d) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lena >= 1);
	mk_lang_static_assert(mk_lang_num_longdivmod_inl_defd_lenb >= 1);

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(!mk_lang_num_longdivmod_inl_defd_overlap(c, mk_lang_num_longdivmod_inl_defd_lenc, d, mk_lang_num_longdivmod_inl_defd_lend));
	mk_lang_assert(mk_lang_num_longdivmod_inl_defd_get_lenb(b) != 0);

#if mk_lang_num_longdivmod_inl_defd_lena == 1 && mk_lang_num_longdivmod_inl_defd_lenb == 1
	mk_lang_num_longdivmod_inl_defd_divmod4_1_1(a, b, c, d);
#elif mk_lang_num_longdivmod_inl_defd_lenb == 1
	mk_lang_num_longdivmod_inl_defd_divmod4_n_1(a, b, c, d);
#else
	mk_lang_num_longdivmod_inl_defd_divmod4_n_n(a, b, c, d);
#endif
}


#undef mk_lang_num_longdivmod_inl_defd_overlap


#include "mk_lang_num_longdivmod_inl_defu.h"


#undef mk_lang_num_longdivmod_t_name
#undef mk_lang_num_longdivmod_t_tn1
#undef mk_lang_num_longdivmod_t_tn2
#undef mk_lang_num_longdivmod_t_tn3
#undef mk_lang_num_longdivmod_t_lena
#undef mk_lang_num_longdivmod_t_lenb
#undef mk_lang_num_longdivmod_t_endian
#undef mk_lang_num_longdivmod_t_alg
#undef mk_lang_num_longdivmod_t_tn1s_to_tn2
#undef mk_lang_num_longdivmod_t_tn1d_to_tn2
#undef mk_lang_num_longdivmod_t_tn1d_to_tn3
#undef mk_lang_num_longdivmod_t_tn1t_to_tn3
#undef mk_lang_num_longdivmod_t_tn2_get_lo
#undef mk_lang_num_longdivmod_t_tn2_get_hi
#undef mk_lang_num_longdivmod_t_tn3_get_tn2
#undef mk_lang_num_longdivmod_t_tn1_sizebits_d
#undef mk_lang_num_longdivmod_t_tn2_sizebits_d
