#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"


#include "mk_lang_bui_div_inl_def.h"
#if (mk_lang_bui_div_inl_def_alg == 2 && mk_lang_bui_div_inl_def_bt2_has == 1) || (mk_lang_bui_div_inl_def_alg == 3 && mk_lang_bui_div_inl_def_bt3_has == 1)


mk_lang_jumbo void mk_lang_bui_div_inl_def_name(mk_lang_bui_div_inl_def_bt const* const a, mk_lang_bui_div_inl_def_bt const* const b, mk_lang_bui_div_inl_def_bt* const c, mk_lang_bui_div_inl_def_bt* const d)
{
	#define mk_lang_bui_div_inl_def_lenc mk_lang_bui_div_inl_def_lena
	#define mk_lang_bui_div_inl_def_lend mk_lang_bui_div_inl_def_lenb
	#define mk_lang_bui_div_inl_def_endian_idxc mk_lang_bui_div_inl_def_endian_idxa
	#define mk_lang_bui_div_inl_def_endian_idxd mk_lang_bui_div_inl_def_endian_idxb

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != a && c != b && c != d);
	mk_lang_assert(d != a && d != b && d != c);
	mk_lang_assert(a + mk_lang_bui_div_inl_def_lena <= b || a >= b + mk_lang_bui_div_inl_def_lenb);
	mk_lang_assert(a + mk_lang_bui_div_inl_def_lena <= c || a >= c + mk_lang_bui_div_inl_def_lenc);
	mk_lang_assert(a + mk_lang_bui_div_inl_def_lena <= d || a >= d + mk_lang_bui_div_inl_def_lend);
	mk_lang_assert(b + mk_lang_bui_div_inl_def_lenb <= a || b >= a + mk_lang_bui_div_inl_def_lena);
	mk_lang_assert(b + mk_lang_bui_div_inl_def_lenb <= c || b >= c + mk_lang_bui_div_inl_def_lenc);
	mk_lang_assert(b + mk_lang_bui_div_inl_def_lenb <= d || b >= d + mk_lang_bui_div_inl_def_lend);
	mk_lang_assert(c + mk_lang_bui_div_inl_def_lenc <= a || c >= a + mk_lang_bui_div_inl_def_lena);
	mk_lang_assert(c + mk_lang_bui_div_inl_def_lenc <= b || c >= b + mk_lang_bui_div_inl_def_lenb);
	mk_lang_assert(c + mk_lang_bui_div_inl_def_lenc <= d || c >= d + mk_lang_bui_div_inl_def_lend);
	mk_lang_assert(d + mk_lang_bui_div_inl_def_lend <= a || d >= a + mk_lang_bui_div_inl_def_lena);
	mk_lang_assert(d + mk_lang_bui_div_inl_def_lend <= b || d >= b + mk_lang_bui_div_inl_def_lenb);
	mk_lang_assert(d + mk_lang_bui_div_inl_def_lend <= c || d >= c + mk_lang_bui_div_inl_def_lenc);
	mk_lang_assert(mk_lang_bui_div_inl_def_lena >= 1 && mk_lang_bui_div_inl_def_lena <= 128);
	mk_lang_assert(mk_lang_bui_div_inl_def_lenb >= 1 && mk_lang_bui_div_inl_def_lenb <= 128);

	#if mk_lang_bui_div_inl_def_lena == 1 && mk_lang_bui_div_inl_def_lenb == 1
	{
		*c = ((mk_lang_bui_div_inl_def_bt)(((mk_lang_bui_div_inl_def_bt)(*a)) / ((mk_lang_bui_div_inl_def_bt)(*b))));
		*d = ((mk_lang_bui_div_inl_def_bt)(((mk_lang_bui_div_inl_def_bt)(*a)) % ((mk_lang_bui_div_inl_def_bt)(*b))));
	}
	#elif mk_lang_bui_div_inl_def_lenb == 1
	{
		int lena;
		int i;
		mk_lang_bui_div_inl_def_bt bb;
		mk_lang_bui_div_inl_def_bt ta;
		mk_lang_bui_div_inl_def_bt tb;
		mk_lang_bui_div_inl_def_bt2 tc;

		lena = 0;
		for(i = 0; i != mk_lang_bui_div_inl_def_lena; ++i)
		{
			if(a[mk_lang_bui_div_inl_def_endian_idxa((mk_lang_bui_div_inl_def_lena - 1) - i)] != ((mk_lang_bui_div_inl_def_bt)(0)))
			{
				lena = mk_lang_bui_div_inl_def_lena - i;
				break;
			}
		}
		for(i = 0; i != mk_lang_bui_div_inl_def_lena - lena; ++i)
		{
			c[mk_lang_bui_div_inl_def_endian_idxc((mk_lang_bui_div_inl_def_lenc - 1) - i)] = 0;
		}
		for(i = 0; i != mk_lang_bui_div_inl_def_lend - 1; ++i)
		{
			d[mk_lang_bui_div_inl_def_endian_idxd((mk_lang_bui_div_inl_def_lend - 1) - i)] = 0;
		}
		bb = b[mk_lang_bui_div_inl_def_endian_idxb(0)];
		ta = ((mk_lang_bui_div_inl_def_bt)(a[mk_lang_bui_div_inl_def_endian_idxa(lena - 1)] / bb));
		tb = ((mk_lang_bui_div_inl_def_bt)(a[mk_lang_bui_div_inl_def_endian_idxa(lena - 1)] % bb));
		c[mk_lang_bui_div_inl_def_endian_idxc(lena - 1)] = ta;
		for(i = 1; i != lena; ++i)
		{
			tc = ((mk_lang_bui_div_inl_def_bt2)(tb));
			tc = ((mk_lang_bui_div_inl_def_bt2)(tc << ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
			tc = ((mk_lang_bui_div_inl_def_bt2)(tc | ((mk_lang_bui_div_inl_def_bt2)(a[mk_lang_bui_div_inl_def_endian_idxa(lena - 1 - i)]))));
			ta = ((mk_lang_bui_div_inl_def_bt)(tc / bb));
			tb = ((mk_lang_bui_div_inl_def_bt)(tc % bb));
			c[mk_lang_bui_div_inl_def_endian_idxc(lena - 1 - i)] = ta;
		}
		d[mk_lang_bui_div_inl_def_endian_idxd(0)] = tb;
	}
	#else
	{
		int lena;
		int i;

		lena = 0;
		for(i = 0; i != mk_lang_bui_div_inl_def_lena; ++i)
		{
			if(a[mk_lang_bui_div_inl_def_endian_idxa((mk_lang_bui_div_inl_def_lena - 1) - i)] != ((mk_lang_bui_div_inl_def_bt)(0)))
			{
				lena = mk_lang_bui_div_inl_def_lena - i;
				break;
			}
		}
		if(lena == 0)
		{
			for(i = 0; i != mk_lang_bui_div_inl_def_lenc; ++i)
			{
				c[mk_lang_bui_div_inl_def_endian_idxc(i)] = ((mk_lang_bui_div_inl_def_bt)(0));
			}
			for(i = 0; i != mk_lang_bui_div_inl_def_lend; ++i)
			{
				d[mk_lang_bui_div_inl_def_endian_idxd(i)] = ((mk_lang_bui_div_inl_def_bt)(0));
			}
		}
		else
		{
			int lenb;

			lenb = 0;
			for(i = 0; i != mk_lang_bui_div_inl_def_lenb; ++i)
			{
				if(b[mk_lang_bui_div_inl_def_endian_idxb((mk_lang_bui_div_inl_def_lenb - 1) - i)] != ((mk_lang_bui_div_inl_def_bt)(0)))
				{
					lenb = mk_lang_bui_div_inl_def_lenb - i;
					break;
				}
			}
			mk_lang_assert(lenb != 0);
			if(lenb == 1)
			{
				mk_lang_bui_div_inl_def_bt bb;
				mk_lang_bui_div_inl_def_bt ta;
				mk_lang_bui_div_inl_def_bt tb;
				mk_lang_bui_div_inl_def_bt2 tc;

				mk_lang_assert(sizeof(mk_lang_bui_div_inl_def_bt2) >= 2 * sizeof(mk_lang_bui_div_inl_def_bt));

				for(i = 0; i != mk_lang_bui_div_inl_def_lena - lena; ++i)
				{
					c[mk_lang_bui_div_inl_def_endian_idxc((mk_lang_bui_div_inl_def_lenc - 1) - i)] = ((mk_lang_bui_div_inl_def_bt)(0));
				}
				for(i = 0; i != mk_lang_bui_div_inl_def_lend - 1; ++i)
				{
					d[mk_lang_bui_div_inl_def_endian_idxd((mk_lang_bui_div_inl_def_lend - 1) - i)] = ((mk_lang_bui_div_inl_def_bt)(0));
				}
				bb = b[mk_lang_bui_div_inl_def_endian_idxb(0)];
				ta = ((mk_lang_bui_div_inl_def_bt)(a[mk_lang_bui_div_inl_def_endian_idxa(lena - 1)] / bb));
				tb = ((mk_lang_bui_div_inl_def_bt)(a[mk_lang_bui_div_inl_def_endian_idxa(lena - 1)] % bb));
				c[mk_lang_bui_div_inl_def_endian_idxc(lena - 1)] = ta;
				for(i = 1; i != lena; ++i)
				{
					tc = ((mk_lang_bui_div_inl_def_bt2)(tb));
					tc = ((mk_lang_bui_div_inl_def_bt2)(tc << ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
					tc = ((mk_lang_bui_div_inl_def_bt2)(tc | ((mk_lang_bui_div_inl_def_bt2)(a[mk_lang_bui_div_inl_def_endian_idxa(lena - 1 - i)]))));
					ta = ((mk_lang_bui_div_inl_def_bt)(tc / bb));
					tb = ((mk_lang_bui_div_inl_def_bt)(tc % bb));
					c[mk_lang_bui_div_inl_def_endian_idxc(lena - 1 - i)] = ta;
				}
				d[mk_lang_bui_div_inl_def_endian_idxd(0)] = tb;
			}
			else if(lena < lenb)
			{
				for(i = 0; i != mk_lang_bui_div_inl_def_lenc; ++i)
				{
					c[mk_lang_bui_div_inl_def_endian_idxc(i)] = ((mk_lang_bui_div_inl_def_bt)(0));
				}
				for(i = 0; i != mk_lang_bui_div_inl_def_lend; ++i)
				{
					d[mk_lang_bui_div_inl_def_endian_idxd(i)] = a[mk_lang_bui_div_inl_def_endian_idxa(i)];
				}
			}
			else
			{
				mk_lang_bui_div_inl_def_bt f;
				mk_lang_bui_div_inl_def_bt2 tmp;
				mk_lang_bui_div_inl_def_bt carry;
				mk_lang_bui_div_inl_def_bt aa[mk_lang_bui_div_inl_def_lena + 1];
				mk_lang_bui_div_inl_def_bt bb[mk_lang_bui_div_inl_def_lenb];
				int id;

				mk_lang_assert(sizeof(mk_lang_bui_div_inl_def_bt2) >= 2 * sizeof(mk_lang_bui_div_inl_def_bt));

				for(i = 0; i != mk_lang_bui_div_inl_def_lenc - (lena - lenb + 1); ++i)
				{
					c[mk_lang_bui_div_inl_def_endian_idxc((mk_lang_bui_div_inl_def_lenc - 1) - i)] = ((mk_lang_bui_div_inl_def_bt)(0));
				}
				for(i = 0; i != mk_lang_bui_div_inl_def_lend - lenb; ++i)
				{
					d[mk_lang_bui_div_inl_def_endian_idxd((mk_lang_bui_div_inl_def_lend - 1) - i)] = ((mk_lang_bui_div_inl_def_bt)(0));
				}
				f =
					((mk_lang_bui_div_inl_def_bt)(
						((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(1u)) << ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit)))))) /
						((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(b[mk_lang_bui_div_inl_def_endian_idxb(lenb - 1)])) + ((mk_lang_bui_div_inl_def_bt2)(1u))))
					));
				tmp = ((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(a[mk_lang_bui_div_inl_def_endian_idxa(0)])) * ((mk_lang_bui_div_inl_def_bt2)(f))));
				aa[0] = ((mk_lang_bui_div_inl_def_bt)(tmp));
				carry = ((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
				for(i = 1; i != lena; ++i)
				{
					tmp =
						((mk_lang_bui_div_inl_def_bt2)(
							((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(a[mk_lang_bui_div_inl_def_endian_idxa(i)])) * ((mk_lang_bui_div_inl_def_bt2)(f)))) +
							((mk_lang_bui_div_inl_def_bt2)(carry))
						));
					aa[i] = ((mk_lang_bui_div_inl_def_bt)(tmp));
					carry = ((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
				}
				aa[lena] = carry;
				tmp = ((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(b[mk_lang_bui_div_inl_def_endian_idxb(0)])) * ((mk_lang_bui_div_inl_def_bt2)(f))));
				bb[0] = ((mk_lang_bui_div_inl_def_bt)(tmp));
				carry = ((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
				for(i = 1; i != lenb - 1; ++i)
				{
					tmp =
						((mk_lang_bui_div_inl_def_bt2)(
							((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(b[mk_lang_bui_div_inl_def_endian_idxb(i)])) * ((mk_lang_bui_div_inl_def_bt2)(f)))) +
							((mk_lang_bui_div_inl_def_bt2)(carry))
						));
					bb[i] = ((mk_lang_bui_div_inl_def_bt)(tmp));
					carry = ((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
				}
				tmp = ((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(b[mk_lang_bui_div_inl_def_endian_idxb(i)])) * ((mk_lang_bui_div_inl_def_bt2)(f)))) + ((mk_lang_bui_div_inl_def_bt2)(carry))));
				bb[i] = ((mk_lang_bui_div_inl_def_bt)(tmp));
				mk_lang_assert(((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit)))))) == ((mk_lang_bui_div_inl_def_bt)(0)));
				for(id = 0; id != lena - lenb + 1; ++id)
				{
					#if mk_lang_bui_div_inl_def_alg == 2
					mk_lang_bui_div_inl_def_bt2 rn;
					mk_lang_bui_div_inl_def_bt dn;
					#elif mk_lang_bui_div_inl_def_alg == 3
					mk_lang_bui_div_inl_def_bt3 rn;
					mk_lang_bui_div_inl_def_bt2 dn;
					#endif
					mk_lang_bui_div_inl_def_bt2 qtmid;
					mk_lang_bui_div_inl_def_bt qt;
					mk_lang_bui_div_inl_def_bt dq[mk_lang_bui_div_inl_def_lenb + 1];
					mk_lang_bool_t overshoot;
					mk_lang_bool_t borrow2;
					mk_lang_bool_t borrow1;

					#if mk_lang_bui_div_inl_def_alg == 2
					rn =
						((mk_lang_bui_div_inl_def_bt2)(
							((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(aa[lena - id - 0])) << ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit)))))) |
							((mk_lang_bui_div_inl_def_bt2)(aa[lena - id - 1]))
						));
					dn = bb[lenb - 1];
					#elif mk_lang_bui_div_inl_def_alg == 3
					mk_lang_assert(sizeof(mk_lang_bui_div_inl_def_bt3) >= 3 * sizeof(mk_lang_bui_div_inl_def_bt));
					rn =
						((mk_lang_bui_div_inl_def_bt3)(
							((mk_lang_bui_div_inl_def_bt3)(
								((mk_lang_bui_div_inl_def_bt3)(((mk_lang_bui_div_inl_def_bt3)(aa[lena - id - 0])) << ((int)(((int)((((int)(2)) * ((int)(sizeof(mk_lang_bui_div_inl_def_bt)))) * ((int)(mk_lang_charbit)))))))) |
								((mk_lang_bui_div_inl_def_bt3)(((mk_lang_bui_div_inl_def_bt3)(aa[lena - id - 1])) << ((int)(((int)((((int)(1)) * ((int)(sizeof(mk_lang_bui_div_inl_def_bt)))) * ((int)(mk_lang_charbit))))))))
							)) |
							((mk_lang_bui_div_inl_def_bt3)(aa[lena - id - 2]))
						));
					dn =
						((mk_lang_bui_div_inl_def_bt2)(
							((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(bb[lenb - 1])) << ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit)))))) |
							((mk_lang_bui_div_inl_def_bt2)(bb[lenb - 2]))
						));
					#endif
					qtmid = ((mk_lang_bui_div_inl_def_bt2)(rn / dn));
					qt = ((mk_lang_bui_div_inl_def_bt)(mk_lang_min(qtmid, ((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt)(((mk_lang_bui_div_inl_def_bt)(0)) - ((mk_lang_bui_div_inl_def_bt)(1)))))))));
					tmp = ((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(bb[0])) * ((mk_lang_bui_div_inl_def_bt2)(qt))));
					dq[0] = ((mk_lang_bui_div_inl_def_bt)(tmp));
					carry = ((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
					for(i = 1; i != lenb; ++i)
					{
						tmp = ((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(bb[i])) * ((mk_lang_bui_div_inl_def_bt2)(qt)))) + ((mk_lang_bui_div_inl_def_bt2)(carry))));
						dq[i] = ((mk_lang_bui_div_inl_def_bt)(tmp));
						carry = ((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
					}
					dq[lenb] = carry;
					overshoot = mk_lang_false;
					for(i = 0; i != lenb + 1; ++i)
					{
						if(dq[lenb - i] > aa[lena - id - i]) { overshoot = mk_lang_true; break; }
						if(dq[lenb - i] < aa[lena - id - i]) { overshoot = mk_lang_false; break; }
					}
					if(overshoot)
					{
						--qt;
						tmp = ((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(bb[0])) * ((mk_lang_bui_div_inl_def_bt2)(qt))));
						dq[0] = ((mk_lang_bui_div_inl_def_bt)(tmp));
						carry = ((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
						for(i = 1; i != lenb; ++i)
						{
							tmp = ((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(bb[i])) * ((mk_lang_bui_div_inl_def_bt2)(qt)))) + ((mk_lang_bui_div_inl_def_bt2)(carry))));
							dq[i] = ((mk_lang_bui_div_inl_def_bt)(tmp));
							carry = ((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
						}
						dq[lenb] = carry;
						#if mk_lang_bui_div_inl_def_alg == 2
						overshoot = mk_lang_false;
						for(i = 0; i != lenb + 1; ++i)
						{
							if(dq[lenb - i] > aa[lena - id - i]) { overshoot = mk_lang_true; break; }
							if(dq[lenb - i] < aa[lena - id - i]) { overshoot = mk_lang_false; break; }
						}
						if(overshoot)
						{
							--qt;
							tmp = ((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(bb[0])) * ((mk_lang_bui_div_inl_def_bt2)(qt))));
							dq[0] = ((mk_lang_bui_div_inl_def_bt)(tmp));
							carry = ((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
							for(i = 1; i != lenb; ++i)
							{
								tmp = ((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(bb[i])) * ((mk_lang_bui_div_inl_def_bt2)(qt)))) + ((mk_lang_bui_div_inl_def_bt2)(carry))));
							dq[i] = ((mk_lang_bui_div_inl_def_bt)(tmp));
							carry = ((mk_lang_bui_div_inl_def_bt)(tmp >> ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit))))));
							}
							dq[lenb] = carry;
						}
						#elif mk_lang_bui_div_inl_def_alg == 3
						#endif
					}
					c[mk_lang_bui_div_inl_def_endian_idxc(lena - lenb - id)] = qt;
					borrow2 = aa[lena - lenb - id] < dq[0];
					aa[lena - lenb - id] = ((mk_lang_bui_div_inl_def_bt)(aa[lena - lenb - id] - dq[0]));
					borrow1 = borrow2;
					for(i = 1; i != lenb; ++i)
					{
						borrow2 = borrow1 ? (aa[lena - lenb - id + i] <= dq[i]) : (aa[lena - lenb - id + i] < dq[i]);
						aa[lena - lenb - id + i] = ((mk_lang_bui_div_inl_def_bt)(((mk_lang_bui_div_inl_def_bt)(aa[lena - lenb - id + i] - dq[i])) - borrow1));
						borrow1 = borrow2;
					}
					mk_lang_assert(((mk_lang_bui_div_inl_def_bt)(((mk_lang_bui_div_inl_def_bt)(aa[lena - lenb - id + i] - dq[i])) - borrow1)) == ((mk_lang_bui_div_inl_def_bt)(0)));
				}
				if(f == 1)
				{
					for(i = 0; i != lenb; ++i)
					{
						d[mk_lang_bui_div_inl_def_endian_idxd((mk_lang_bui_div_inl_def_lend - 1) - (mk_lang_bui_div_inl_def_lend - lenb) - i)] = aa[lenb - 1 - i];
					}
				}
				else
				{
					mk_lang_bui_div_inl_def_bt m;

					m = ((mk_lang_bui_div_inl_def_bt)(aa[lenb - 1] / f));
					carry = ((mk_lang_bui_div_inl_def_bt)(aa[lenb - 1] - ((mk_lang_bui_div_inl_def_bt)(m * f))));
					d[mk_lang_bui_div_inl_def_endian_idxd((mk_lang_bui_div_inl_def_lend - 1) - (mk_lang_bui_div_inl_def_lend - lenb))] = m;
					for(i = 1; i != lenb - 1; ++i)
					{
						tmp =
							((mk_lang_bui_div_inl_def_bt2)(
								((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(carry)) << ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit)))))) |
								((mk_lang_bui_div_inl_def_bt2)(aa[lenb - 1 - i]))
							));
						m = ((mk_lang_bui_div_inl_def_bt)(tmp / f));
						carry = ((mk_lang_bui_div_inl_def_bt)(aa[lenb - 1 - i] - ((mk_lang_bui_div_inl_def_bt)(m * f))));
						d[mk_lang_bui_div_inl_def_endian_idxd((mk_lang_bui_div_inl_def_lend - 1) - (mk_lang_bui_div_inl_def_lend - lenb) - i)] = m;
					}
					tmp =
						((mk_lang_bui_div_inl_def_bt2)(
							((mk_lang_bui_div_inl_def_bt2)(((mk_lang_bui_div_inl_def_bt2)(carry)) << ((int)(((int)(sizeof(mk_lang_bui_div_inl_def_bt))) * ((int)(mk_lang_charbit)))))) |
							((mk_lang_bui_div_inl_def_bt2)(aa[lenb - 1 - i]))
						));
					m = ((mk_lang_bui_div_inl_def_bt)(tmp / f));
					mk_lang_assert(((mk_lang_bui_div_inl_def_bt)(aa[lenb - 1 - i] - ((mk_lang_bui_div_inl_def_bt)(m * f)))) == 0);
					d[mk_lang_bui_div_inl_def_endian_idxd((mk_lang_bui_div_inl_def_lend - 1) - (mk_lang_bui_div_inl_def_lend - lenb) - i)] = m;
				}
			}
		}
	}
	#endif

	#undef mk_lang_bui_div_inl_def_lenc
	#undef mk_lang_bui_div_inl_def_lend
	#undef mk_lang_bui_div_inl_def_endian_idxc
	#undef mk_lang_bui_div_inl_def_endian_idxd
}


#endif
#include "mk_lang_bui_div_inl_undef.h"


#undef mk_lang_bui_div_bt
#undef mk_lang_bui_div_bt2
#undef mk_lang_bui_div_inl_def_lena
#undef mk_lang_bui_div_inl_def_lenb
#undef mk_lang_bui_div_endian
#undef mk_lang_bui_div_alg
#undef mk_lang_bui_div_name
