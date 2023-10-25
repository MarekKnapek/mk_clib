#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_bui_to2.h"
#include "mk_lang_bui_to3.h"
#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_overlap.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


#include "mk_lang_bui_divmod_inl_defd.h"
#if mk_lang_bui_divmod_inl_defd_valid == 1


#if mk_lang_bui_divmod_inl_defd_lena == 1 && mk_lang_bui_divmod_inl_defd_lenb == 1

mk_lang_constexpr mk_lang_jumbo void mk_lang_bui_divmod_inl_defd_fn_simple_1_1(mk_lang_bui_divmod_inl_defd_bt const* const a, mk_lang_bui_divmod_inl_defd_bt const* const b, mk_lang_bui_divmod_inl_defd_bt* const c, mk_lang_bui_divmod_inl_defd_bt* const d) mk_lang_noexcept
{
	mk_lang_bui_divmod_inl_defd_bt aa mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt bb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(!(c >= d && c < d + mk_lang_bui_divmod_inl_defd_lend)); /* todo overlap */
	mk_lang_assert(!(d >= c && d < c + mk_lang_bui_divmod_inl_defd_lenc));
	mk_lang_assert(*b != ((mk_lang_bui_divmod_inl_defd_bt)(0)));

	aa = ((mk_lang_bui_divmod_inl_defd_bt)(*a));
	bb = ((mk_lang_bui_divmod_inl_defd_bt)(*b));
	*c = ((mk_lang_bui_divmod_inl_defd_bt)(aa / bb));
	*d = ((mk_lang_bui_divmod_inl_defd_bt)(aa % bb));
}

#else

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo int mk_lang_bui_divmod_inl_defd_fn_simple_lena(mk_lang_bui_divmod_inl_defd_bt const* const a) mk_lang_noexcept
{
	int lena mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);

	lena = 0;
	for(i = 0; i != mk_lang_bui_divmod_inl_defd_lena; ++i)
	{
		if(a[mk_lang_bui_divmod_inl_defd_endian_idxa((mk_lang_bui_divmod_inl_defd_lena - 1) - i)] != ((mk_lang_bui_divmod_inl_defd_bt)(0)))
		{
			lena = mk_lang_bui_divmod_inl_defd_lena - i;
			break;
		}
	}
	mk_lang_assert(lena >= 0 && lena <= mk_lang_bui_divmod_inl_defd_lena);
	return lena;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo int mk_lang_bui_divmod_inl_defd_fn_simple_lenb(mk_lang_bui_divmod_inl_defd_bt const* const b) mk_lang_noexcept
{
	int lenb mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(b);

	lenb = 0;
	for(i = 0; i != mk_lang_bui_divmod_inl_defd_lenb; ++i)
	{
		if(b[mk_lang_bui_divmod_inl_defd_endian_idxb((mk_lang_bui_divmod_inl_defd_lenb - 1) - i)] != ((mk_lang_bui_divmod_inl_defd_bt)(0)))
		{
			lenb = mk_lang_bui_divmod_inl_defd_lenb - i;
			break;
		}
	}
	mk_lang_assert(lenb >= 0 && lenb <= mk_lang_bui_divmod_inl_defd_lenb);
	return lenb;
}

mk_lang_constexpr mk_lang_jumbo void mk_lang_bui_divmod_inl_defd_fn_simple_0(mk_lang_bui_divmod_inl_defd_bt const* const a__, mk_lang_bui_divmod_inl_defd_bt const* const b__, mk_lang_bui_divmod_inl_defd_bt* const c, mk_lang_bui_divmod_inl_defd_bt* const d) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	((void)(a__));
	((void)(b__));
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(!mk_lang_bui_divmod_inl_defd_fn_overlap(c, mk_lang_bui_divmod_inl_defd_lenc, d, mk_lang_bui_divmod_inl_defd_lend));

	for(i = 0; i != mk_lang_bui_divmod_inl_defd_lenc; ++i)
	{
		c[mk_lang_bui_divmod_inl_defd_endian_idxc(i)] = ((mk_lang_bui_divmod_inl_defd_bt)(0));
	}
	for(i = 0; i != mk_lang_bui_divmod_inl_defd_lend; ++i)
	{
		d[mk_lang_bui_divmod_inl_defd_endian_idxd(i)] = ((mk_lang_bui_divmod_inl_defd_bt)(0));
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lang_bui_divmod_inl_defd_fn_simple_bigger(mk_lang_bui_divmod_inl_defd_bt const* const a, mk_lang_bui_divmod_inl_defd_bt const* const b__, mk_lang_bui_divmod_inl_defd_bt* const c, mk_lang_bui_divmod_inl_defd_bt* const d) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_bui_divmod_inl_defd_lend <= mk_lang_bui_divmod_inl_defd_lena);
	mk_lang_assert(a);
	((void)(b__));
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(c != d);
	mk_lang_assert(!(a >= c && a < c + mk_lang_bui_divmod_inl_defd_lenc));
	mk_lang_assert(!(a >= d && a < d + mk_lang_bui_divmod_inl_defd_lend));
	mk_lang_assert(!(c >= a && c < a + mk_lang_bui_divmod_inl_defd_lena)); /* todo overlap */
	mk_lang_assert(!(c >= d && c < d + mk_lang_bui_divmod_inl_defd_lend));
	mk_lang_assert(!(d >= a && d < a + mk_lang_bui_divmod_inl_defd_lena));
	mk_lang_assert(!(d >= c && d < c + mk_lang_bui_divmod_inl_defd_lenc));

	for(i = 0; i != mk_lang_bui_divmod_inl_defd_lenc; ++i)
	{
		c[mk_lang_bui_divmod_inl_defd_endian_idxc(i)] = ((mk_lang_bui_divmod_inl_defd_bt)(0));
	}
	for(i = 0; i != mk_lang_bui_divmod_inl_defd_lend; ++i)
	{
		d[mk_lang_bui_divmod_inl_defd_endian_idxd(i)] = a[mk_lang_bui_divmod_inl_defd_endian_idxa(i)];
	}
}

mk_lang_constexpr mk_lang_jumbo void mk_lang_bui_divmod_inl_defd_fn_simple_x_1(mk_lang_bui_divmod_inl_defd_bt const* const a, mk_lang_bui_divmod_inl_defd_bt const* const b, mk_lang_bui_divmod_inl_defd_bt* const c, mk_lang_bui_divmod_inl_defd_bt* const d, int const lena) mk_lang_noexcept
{
	mk_lang_bui_divmod_inl_defd_bt bb mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt ta mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt tb mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt2 tc mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_lang_bui_divmod_inl_defd_bt2) >= 2 * sizeof(mk_lang_bui_divmod_inl_defd_bt));
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(a != c);
	mk_lang_assert(a != d);
	mk_lang_assert(c != d);
	mk_lang_assert(!mk_lang_bui_divmod_inl_defd_fn_overlap(a, mk_lang_bui_divmod_inl_defd_lena, c, mk_lang_bui_divmod_inl_defd_lenc));
	mk_lang_assert(!mk_lang_bui_divmod_inl_defd_fn_overlap(a, mk_lang_bui_divmod_inl_defd_lena, d, mk_lang_bui_divmod_inl_defd_lend));
	mk_lang_assert(!mk_lang_bui_divmod_inl_defd_fn_overlap(c, mk_lang_bui_divmod_inl_defd_lenc, d, mk_lang_bui_divmod_inl_defd_lend));
	mk_lang_assert(b[mk_lang_bui_divmod_inl_defd_endian_idxb(0)] != ((mk_lang_bui_divmod_inl_defd_bt)(0)));
	mk_lang_assert(lena >= 1 && lena <= mk_lang_bui_divmod_inl_defd_lena);

	bb = b[mk_lang_bui_divmod_inl_defd_endian_idxb(0)];
	for(i = 0; i != mk_lang_bui_divmod_inl_defd_lena - lena; ++i)
	{
		c[mk_lang_bui_divmod_inl_defd_endian_idxc((mk_lang_bui_divmod_inl_defd_lenc - 1) - i)] = ((mk_lang_bui_divmod_inl_defd_bt)(0));
	}
	for(i = 0; i != mk_lang_bui_divmod_inl_defd_lend - 1; ++i)
	{
		d[mk_lang_bui_divmod_inl_defd_endian_idxd((mk_lang_bui_divmod_inl_defd_lend - 1) - i)] = ((mk_lang_bui_divmod_inl_defd_bt)(0));
	}
	ta = ((mk_lang_bui_divmod_inl_defd_bt)(a[mk_lang_bui_divmod_inl_defd_endian_idxa(lena - 1)] / bb));
	tb = ((mk_lang_bui_divmod_inl_defd_bt)(a[mk_lang_bui_divmod_inl_defd_endian_idxa(lena - 1)] % bb));
	c[mk_lang_bui_divmod_inl_defd_endian_idxc(lena - 1)] = ta;
	for(i = 1; i != lena; ++i)
	{
		tc = ((mk_lang_bui_divmod_inl_defd_bt2)(tb));
		tc = ((mk_lang_bui_divmod_inl_defd_bt2)(tc << ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
		tc = ((mk_lang_bui_divmod_inl_defd_bt2)(tc | ((mk_lang_bui_divmod_inl_defd_bt2)(a[mk_lang_bui_divmod_inl_defd_endian_idxa(lena - 1 - i)]))));
		ta = ((mk_lang_bui_divmod_inl_defd_bt)(tc / bb));
		tb = ((mk_lang_bui_divmod_inl_defd_bt)(tc % bb));
		c[mk_lang_bui_divmod_inl_defd_endian_idxc(lena - 1 - i)] = ta;
	}
	d[mk_lang_bui_divmod_inl_defd_endian_idxd(0)] = tb;
}

mk_lang_constexpr mk_lang_jumbo void mk_lang_bui_divmod_inl_defd_fn_simple_n_1(mk_lang_bui_divmod_inl_defd_bt const* const a, mk_lang_bui_divmod_inl_defd_bt const* const b, mk_lang_bui_divmod_inl_defd_bt* const c, mk_lang_bui_divmod_inl_defd_bt* const d) mk_lang_noexcept
{
	int lena mk_lang_constexpr_init;

	lena = mk_lang_bui_divmod_inl_defd_fn_simple_lena(a);
	if(lena == 0)
	{
		mk_lang_assert(mk_lang_bui_divmod_inl_defd_fn_simple_lenb(b) != 0);
		mk_lang_bui_divmod_inl_defd_fn_simple_0(a, b, c, d);
	}
	else
	{
		mk_lang_bui_divmod_inl_defd_fn_simple_x_1(a, b, c, d, lena);
	}
}

#if mk_lang_bui_divmod_inl_defd_lena >= 2 && mk_lang_bui_divmod_inl_defd_lenb >= 2

mk_lang_constexpr mk_lang_jumbo void mk_lang_bui_divmod_inl_defd_fn_complex_n_n(mk_lang_bui_divmod_inl_defd_bt const* const a, mk_lang_bui_divmod_inl_defd_bt const* const b, mk_lang_bui_divmod_inl_defd_bt* const c, mk_lang_bui_divmod_inl_defd_bt* const d, int const lena, int const lenb) mk_lang_noexcept
{
	int i mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt f mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt2 ta mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt aa[mk_lang_bui_divmod_inl_defd_lena + 1] mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt tb mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt bb[mk_lang_bui_divmod_inl_defd_lenb] mk_lang_constexpr_init;
	int id mk_lang_constexpr_init;
	#if mk_lang_bui_divmod_inl_defd_alg == 2
	mk_lang_bui_divmod_inl_defd_bt2 rn mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt dn mk_lang_constexpr_init;
	#elif mk_lang_bui_divmod_inl_defd_alg == 3
	mk_lang_bui_divmod_inl_defd_bt3 rn mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt2 dn mk_lang_constexpr_init;
	#endif
	mk_lang_bui_divmod_inl_defd_bt dq[mk_lang_bui_divmod_inl_defd_lenb + 1] mk_lang_constexpr_init;
	mk_lang_bui_divmod_inl_defd_bt tc mk_lang_constexpr_init;
	mk_lang_types_bool_t overshoot mk_lang_constexpr_init;
	mk_lang_types_bool_t borrow1 mk_lang_constexpr_init;
	mk_lang_types_bool_t borrow2 mk_lang_constexpr_init;

	mk_lang_static_assert(sizeof(mk_lang_bui_divmod_inl_defd_bt2) >= 2 * sizeof(mk_lang_bui_divmod_inl_defd_bt));
	#if mk_lang_bui_divmod_inl_defd_alg == 2
	#elif mk_lang_bui_divmod_inl_defd_alg == 3
	mk_lang_static_assert(sizeof(mk_lang_bui_divmod_inl_defd_bt3) >= 3 * sizeof(mk_lang_bui_divmod_inl_defd_bt));
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
	mk_lang_assert(!(a >= c && a < c + mk_lang_bui_divmod_inl_defd_lenc));
	mk_lang_assert(!(a >= d && a < d + mk_lang_bui_divmod_inl_defd_lend));
	mk_lang_assert(!(b >= c && b < c + mk_lang_bui_divmod_inl_defd_lenc));
	mk_lang_assert(!(b >= d && b < d + mk_lang_bui_divmod_inl_defd_lend));
	mk_lang_assert(!(c >= a && c < a + mk_lang_bui_divmod_inl_defd_lena)); /* todo overlap */
	mk_lang_assert(!(c >= b && c < b + mk_lang_bui_divmod_inl_defd_lenb));
	mk_lang_assert(!(c >= d && c < d + mk_lang_bui_divmod_inl_defd_lend));
	mk_lang_assert(!(d >= a && d < a + mk_lang_bui_divmod_inl_defd_lena));
	mk_lang_assert(!(d >= b && d < b + mk_lang_bui_divmod_inl_defd_lenb));
	mk_lang_assert(!(d >= c && d < c + mk_lang_bui_divmod_inl_defd_lenc));
	mk_lang_assert(lena >= 2 && lena <= mk_lang_bui_divmod_inl_defd_lena);
	mk_lang_assert(lenb >= 2 && lenb <= mk_lang_bui_divmod_inl_defd_lenb);
	mk_lang_assert(lena >= lenb);

	for(i = 0; i != mk_lang_bui_divmod_inl_defd_lenc - (lena - lenb + 1); ++i)
	{
		c[mk_lang_bui_divmod_inl_defd_endian_idxc((mk_lang_bui_divmod_inl_defd_lenc - 1) - i)] = ((mk_lang_bui_divmod_inl_defd_bt)(0));
	}
	for(i = 0; i != mk_lang_bui_divmod_inl_defd_lend - lenb; ++i)
	{
		d[mk_lang_bui_divmod_inl_defd_endian_idxd((mk_lang_bui_divmod_inl_defd_lend - 1) - i)] = ((mk_lang_bui_divmod_inl_defd_bt)(0));
	}
	f =
		((mk_lang_bui_divmod_inl_defd_bt)(
			((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(1u)) << ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit)))))) /
			((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(b[mk_lang_bui_divmod_inl_defd_endian_idxb(lenb - 1)])) + ((mk_lang_bui_divmod_inl_defd_bt2)(1u))))
		));
	ta = ((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(a[mk_lang_bui_divmod_inl_defd_endian_idxa(0)])) * ((mk_lang_bui_divmod_inl_defd_bt2)(f))));
	aa[0] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
	tb = ((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
	for(i = 1; i != lena; ++i)
	{
		ta =
			((mk_lang_bui_divmod_inl_defd_bt2)(
				((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(a[mk_lang_bui_divmod_inl_defd_endian_idxa(i)])) * ((mk_lang_bui_divmod_inl_defd_bt2)(f)))) +
				((mk_lang_bui_divmod_inl_defd_bt2)(tb))
			));
		aa[i] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
		tb = ((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
	}
	aa[lena] = tb;
	ta = ((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(b[mk_lang_bui_divmod_inl_defd_endian_idxb(0)])) * ((mk_lang_bui_divmod_inl_defd_bt2)(f))));
	bb[0] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
	tb = ((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
	for(i = 1; i != lenb - 1; ++i)
	{
		ta =
			((mk_lang_bui_divmod_inl_defd_bt2)(
				((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(b[mk_lang_bui_divmod_inl_defd_endian_idxb(i)])) * ((mk_lang_bui_divmod_inl_defd_bt2)(f)))) +
				((mk_lang_bui_divmod_inl_defd_bt2)(tb))
			));
		bb[i] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
		tb = ((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
	}
	ta = ((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(b[mk_lang_bui_divmod_inl_defd_endian_idxb(lenb - 1)])) * ((mk_lang_bui_divmod_inl_defd_bt2)(f)))) + ((mk_lang_bui_divmod_inl_defd_bt2)(tb))));
	bb[lenb - 1] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
	mk_lang_assert(((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit)))))) == ((mk_lang_bui_divmod_inl_defd_bt)(0)));
	for(id = 0; id != lena - lenb + 1; ++id)
	{
		#if mk_lang_bui_divmod_inl_defd_alg == 2
		rn =
			((mk_lang_bui_divmod_inl_defd_bt2)(
				((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(aa[lena - id - 0])) << ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit)))))) |
				((mk_lang_bui_divmod_inl_defd_bt2)(aa[lena - id - 1]))
			));
		dn = bb[lenb - 1];
		#elif mk_lang_bui_divmod_inl_defd_alg == 3
		rn =
			((mk_lang_bui_divmod_inl_defd_bt3)(
				((mk_lang_bui_divmod_inl_defd_bt3)(
					((mk_lang_bui_divmod_inl_defd_bt3)(((mk_lang_bui_divmod_inl_defd_bt3)(aa[lena - id - 0])) << ((int)(((int)((((int)(2)) * ((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt)))) * ((int)(mk_lang_charbit)))))))) |
					((mk_lang_bui_divmod_inl_defd_bt3)(((mk_lang_bui_divmod_inl_defd_bt3)(aa[lena - id - 1])) << ((int)(((int)((((int)(1)) * ((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt)))) * ((int)(mk_lang_charbit))))))))
				)) |
				((mk_lang_bui_divmod_inl_defd_bt3)(aa[lena - id - 2]))
			));
		dn =
			((mk_lang_bui_divmod_inl_defd_bt2)(
				((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(bb[lenb - 1])) << ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit)))))) |
				((mk_lang_bui_divmod_inl_defd_bt2)(bb[lenb - 2]))
			));
		#endif
		ta = ((mk_lang_bui_divmod_inl_defd_bt2)(rn / dn));
		tb = ((mk_lang_bui_divmod_inl_defd_bt)(mk_lang_min(ta, ((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt)(((mk_lang_bui_divmod_inl_defd_bt)(0)) - ((mk_lang_bui_divmod_inl_defd_bt)(1)))))))));
		ta = ((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(bb[0])) * ((mk_lang_bui_divmod_inl_defd_bt2)(tb))));
		dq[0] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
		tc = ((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
		for(i = 1; i != lenb; ++i)
		{
			ta = ((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(bb[i])) * ((mk_lang_bui_divmod_inl_defd_bt2)(tb)))) + ((mk_lang_bui_divmod_inl_defd_bt2)(tc))));
			dq[i] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
			tc = ((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
		}
		dq[lenb] = tc;
		overshoot = mk_lang_false;
		for(i = 0; i != lenb + 1; ++i)
		{
			if(dq[lenb - i] > aa[lena - id - i]) { overshoot = mk_lang_true; break; }
			if(dq[lenb - i] < aa[lena - id - i]) { overshoot = mk_lang_false; break; }
		}
		if(overshoot)
		{
			--tb;
			ta = ((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(bb[0])) * ((mk_lang_bui_divmod_inl_defd_bt2)(tb))));
			dq[0] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
			tc = ((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
			for(i = 1; i != lenb; ++i)
			{
				ta = ((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(bb[i])) * ((mk_lang_bui_divmod_inl_defd_bt2)(tb)))) + ((mk_lang_bui_divmod_inl_defd_bt2)(tc))));
				dq[i] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
				tc = ((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
			}
			dq[lenb] = tc;
			#if mk_lang_bui_divmod_inl_defd_alg == 2
			overshoot = mk_lang_false;
			for(i = 0; i != lenb + 1; ++i)
			{
				if(dq[lenb - i] > aa[lena - id - i]) { overshoot = mk_lang_true; break; }
				if(dq[lenb - i] < aa[lena - id - i]) { overshoot = mk_lang_false; break; }
			}
			if(overshoot)
			{
				--tb;
				ta = ((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(bb[0])) * ((mk_lang_bui_divmod_inl_defd_bt2)(tb))));
				dq[0] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
				tc = ((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
				for(i = 1; i != lenb; ++i)
				{
					ta = ((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(bb[i])) * ((mk_lang_bui_divmod_inl_defd_bt2)(tb)))) + ((mk_lang_bui_divmod_inl_defd_bt2)(tc))));
					dq[i] = ((mk_lang_bui_divmod_inl_defd_bt)(ta));
					tc = ((mk_lang_bui_divmod_inl_defd_bt)(ta >> ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit))))));
				}
				dq[lenb] = tc;
			}
			#elif mk_lang_bui_divmod_inl_defd_alg == 3
			#endif
		}
		c[mk_lang_bui_divmod_inl_defd_endian_idxc(lena - lenb - id)] = tb;
		borrow1 = aa[lena - lenb - id] < dq[0];
		aa[lena - lenb - id] = ((mk_lang_bui_divmod_inl_defd_bt)(aa[lena - lenb - id] - dq[0]));
		borrow2 = borrow1;
		for(i = 1; i != lenb; ++i)
		{
			borrow1 = borrow2 ? (aa[lena - lenb - id + i] <= dq[i]) : (aa[lena - lenb - id + i] < dq[i]);
			aa[lena - lenb - id + i] = ((mk_lang_bui_divmod_inl_defd_bt)(((mk_lang_bui_divmod_inl_defd_bt)(aa[lena - lenb - id + i] - dq[i])) - ((mk_lang_bui_divmod_inl_defd_bt)(borrow2))));
			borrow2 = borrow1;
		}
		mk_lang_assert(((mk_lang_bui_divmod_inl_defd_bt)(((mk_lang_bui_divmod_inl_defd_bt)(aa[lena - lenb - id + lenb] - dq[lenb])) - ((mk_lang_bui_divmod_inl_defd_bt)(borrow2)))) == ((mk_lang_bui_divmod_inl_defd_bt)(0)));
	}
	if(f == 1)
	{
		for(i = 0; i != lenb; ++i)
		{
			d[mk_lang_bui_divmod_inl_defd_endian_idxd((mk_lang_bui_divmod_inl_defd_lend - 1) - (mk_lang_bui_divmod_inl_defd_lend - lenb) - i)] = aa[lenb - 1 - i];
		}
	}
	else
	{
		tc = ((mk_lang_bui_divmod_inl_defd_bt)(aa[lenb - 1] / f));
		tb = ((mk_lang_bui_divmod_inl_defd_bt)(aa[lenb - 1] - ((mk_lang_bui_divmod_inl_defd_bt)(tc * f))));
		d[mk_lang_bui_divmod_inl_defd_endian_idxd((mk_lang_bui_divmod_inl_defd_lend - 1) - (mk_lang_bui_divmod_inl_defd_lend - lenb))] = tc;
		for(i = 1; i != lenb - 1; ++i)
		{
			ta =
				((mk_lang_bui_divmod_inl_defd_bt2)(
					((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(tb)) << ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit)))))) |
					((mk_lang_bui_divmod_inl_defd_bt2)(aa[lenb - 1 - i]))
				));
			tc = ((mk_lang_bui_divmod_inl_defd_bt)(ta / f));
			tb = ((mk_lang_bui_divmod_inl_defd_bt)(aa[lenb - 1 - i] - ((mk_lang_bui_divmod_inl_defd_bt)(tc * f))));
			d[mk_lang_bui_divmod_inl_defd_endian_idxd((mk_lang_bui_divmod_inl_defd_lend - 1) - (mk_lang_bui_divmod_inl_defd_lend - lenb) - i)] = tc;
		}
		ta =
			((mk_lang_bui_divmod_inl_defd_bt2)(
				((mk_lang_bui_divmod_inl_defd_bt2)(((mk_lang_bui_divmod_inl_defd_bt2)(tb)) << ((int)(((int)(sizeof(mk_lang_bui_divmod_inl_defd_bt))) * ((int)(mk_lang_charbit)))))) |
				((mk_lang_bui_divmod_inl_defd_bt2)(aa[lenb - 1 - i]))
			));
		tc = ((mk_lang_bui_divmod_inl_defd_bt)(ta / f));
		mk_lang_assert(((mk_lang_bui_divmod_inl_defd_bt)(aa[0] - ((mk_lang_bui_divmod_inl_defd_bt)(tc * f)))) == 0);
		d[mk_lang_bui_divmod_inl_defd_endian_idxd(0)] = tc;
	}
}

#endif

#if mk_lang_bui_divmod_inl_defd_lena == 1 && mk_lang_bui_divmod_inl_defd_lenb == 1
#elif mk_lang_bui_divmod_inl_defd_lenb == 1
#else

mk_lang_constexpr mk_lang_jumbo void mk_lang_bui_divmod_inl_defd_fn_simple_n_n(mk_lang_bui_divmod_inl_defd_bt const* const a, mk_lang_bui_divmod_inl_defd_bt const* const b, mk_lang_bui_divmod_inl_defd_bt* const c, mk_lang_bui_divmod_inl_defd_bt* const d) mk_lang_noexcept
{
	int lena mk_lang_constexpr_init;
	int lenb mk_lang_constexpr_init;

	lena = mk_lang_bui_divmod_inl_defd_fn_simple_lena(a);
	if(lena == 0)
	{
		mk_lang_assert(mk_lang_bui_divmod_inl_defd_fn_simple_lenb(b) != 0);
		mk_lang_bui_divmod_inl_defd_fn_simple_0(a, b, c, d);
	}
	else
	{
		lenb = mk_lang_bui_divmod_inl_defd_fn_simple_lenb(b);
		mk_lang_assert(lenb != 0);
		if(lenb == 1)
		{
			mk_lang_bui_divmod_inl_defd_fn_simple_x_1(a, b, c, d, lena);
		}
		#if mk_lang_bui_divmod_inl_defd_lena != 1
		else if(lena < lenb)
		#else
		else
		#endif
		{
			mk_lang_bui_divmod_inl_defd_fn_simple_bigger(a, b, c, d);
		}
		#if mk_lang_bui_divmod_inl_defd_lena != 1
		else
		{
			mk_lang_bui_divmod_inl_defd_fn_complex_n_n(a, b, c, d, lena, lenb);
		}
		#else
		#endif
	}
}

#endif
#endif


mk_lang_constexpr mk_lang_jumbo void mk_lang_bui_divmod_inl_defd_fn(mk_lang_bui_divmod_inl_defd_bt const* const a, mk_lang_bui_divmod_inl_defd_bt const* const b, mk_lang_bui_divmod_inl_defd_bt* const c, mk_lang_bui_divmod_inl_defd_bt* const d) mk_lang_noexcept
{
#if mk_lang_bui_divmod_inl_defd_lena == 1 && mk_lang_bui_divmod_inl_defd_lenb == 1
	mk_lang_bui_divmod_inl_defd_fn_simple_1_1(a, b, c, d);
#elif mk_lang_bui_divmod_inl_defd_lenb == 1
	mk_lang_bui_divmod_inl_defd_fn_simple_n_1(a, b, c, d);
#else
	mk_lang_bui_divmod_inl_defd_fn_simple_n_n(a, b, c, d);
#endif
}


#endif
#include "mk_lang_bui_divmod_inl_defu.h"


#undef mk_lang_bui_divmod_btn
#undef mk_lang_bui_divmod_bt
#undef mk_lang_bui_divmod_bt2
#undef mk_lang_bui_divmod_bt3
#undef mk_lang_bui_divmod_lena
#undef mk_lang_bui_divmod_lenb
#undef mk_lang_bui_divmod_endian
#undef mk_lang_bui_divmod_alg
#undef mk_lang_bui_divmod_name
