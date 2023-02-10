#include "mk_lang_assert.h"
#include "mk_lang_bui_divmod.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_crash.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_sizet.h"

#include <string.h> /* memcpy */


#include "mk_lang_bui_divmod_fuzz_inl_func_def.h"


#if \
( \
	(mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st <= mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt) && \
	((mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt % mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st) == 0) && \
	(mk_lang_bui_divmod_fuzz_inl_func_lena <= (mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt / mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st)) && \
	(mk_lang_bui_divmod_fuzz_inl_func_lenb <= (mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt / mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st)) && \
	( \
		(mk_lang_bui_divmod_fuzz_inl_func_lena == 1 && mk_lang_bui_divmod_fuzz_inl_func_lenb == 1) || \
		(mk_lang_bui_divmod_fuzz_inl_func_alg == 2 && mk_lang_bui_divmod_fuzz_inl_func_def_has2 == 1) || \
		(mk_lang_bui_divmod_fuzz_inl_func_alg == 3 && mk_lang_bui_divmod_fuzz_inl_func_def_has3 == 1) \
	) \
)
#define lena mk_lang_min(mk_lang_bui_divmod_fuzz_inl_func_lena, mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt / mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st)
#define lenb mk_lang_min(mk_lang_bui_divmod_fuzz_inl_func_lenb, mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt / mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st)
#define lend mk_lang_min(lena, lenb)
#define maska_ ((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(1)) << ((lena) * mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st * mk_lang_charbit - 1))) - ((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(1)))) << 1)) + ((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(1))))
#define maskb_ ((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(1)) << ((lenb) * mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st * mk_lang_charbit - 1))) - ((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(1)))) << 1)) + ((mk_lang_bui_divmod_fuzz_inl_func_def_lt)(1))))
#define mk_lang_to_num_a lena
#define mk_lang_to_num_b lenb
#include "mk_lang_to_num_a.h"
#include "mk_lang_to_num_b.h"
#if mk_lang_bui_divmod_fuzz_inl_func_endian == mk_lang_endian_little
#define endian_name le
#elif mk_lang_bui_divmod_fuzz_inl_func_endian == mk_lang_endian_big
#define endian_name be
#endif

mk_lang_jumbo void mk_lang_bui_divmod_fuzz_inl_func_def_fn(unsigned char const* const data, mk_lang_size_t const size)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))
	#define advance(x) { mk_lang_size_t a; a = (x); mk_lang_assert(a <= s); d += a; s -= a; } ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_bui_divmod_fuzz_inl_func_def_lt maska;
	mk_lang_bui_divmod_fuzz_inl_func_def_lt maskb;
	mk_lang_bui_divmod_fuzz_inl_func_def_lt la;
	mk_lang_bui_divmod_fuzz_inl_func_def_lt lb;
	mk_lang_bui_divmod_fuzz_inl_func_def_lt lc;
	mk_lang_bui_divmod_fuzz_inl_func_def_lt ld;
	mk_lang_bui_divmod_fuzz_inl_func_def_st sa[lena];
	mk_lang_bui_divmod_fuzz_inl_func_def_st sb[lenb];
	mk_lang_bui_divmod_fuzz_inl_func_def_st sc[lena];
	mk_lang_bui_divmod_fuzz_inl_func_def_st sd[lend];
	mk_lang_bui_divmod_fuzz_inl_func_def_lt lrc;
	mk_lang_bui_divmod_fuzz_inl_func_def_lt lrd;
	int i;

	d = data;
	s = size;
	maska = maska_;
	maskb = maskb_;
	check_data(mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt);
	memcpy(&la, d, mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt);
	advance(mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt);
	check_data(mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt);
	memcpy(&lb, d, mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt);
	advance(mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_lt);
	check_data(sizeof(sc));
	memcpy(&sc, d, sizeof(sc));
	advance(sizeof(sc));
	check_data(sizeof(sd));
	memcpy(&sd, d, sizeof(sd));
	advance(sizeof(sd));
	if((lb & maskb) == 0)
	{
		return;
	}
	lc = (la & maska) / (lb & maskb);
	ld = (la & maska) % (lb & maskb);
	for(i = 0; i != lena; ++i)
	{
		#if mk_lang_bui_divmod_fuzz_inl_func_endian == mk_lang_endian_little
		sa[i] =
		#elif mk_lang_bui_divmod_fuzz_inl_func_endian == mk_lang_endian_big
		sa[lena - 1 - i] =
		#endif
			((mk_lang_bui_divmod_fuzz_inl_func_def_st)(la >> (i * mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st * mk_lang_charbit)));
	}
	for(i = 0; i != lenb; ++i)
	{
		#if mk_lang_bui_divmod_fuzz_inl_func_endian == mk_lang_endian_little
		sb[i] =
		#elif mk_lang_bui_divmod_fuzz_inl_func_endian == mk_lang_endian_big
		sb[lenb - 1 - i] =
		#endif
			((mk_lang_bui_divmod_fuzz_inl_func_def_st)(lb >> (i * mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st * mk_lang_charbit)));
	}
	mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_lang_bui_divmod_, mk_lang_bui_divmod_fuzz_inl_func_st), _), mk_lang_to_num_as), _), mk_lang_to_num_bs), _), endian_name), _), mk_lang_bui_divmod_fuzz_inl_func_alg)(sa, sb, sc, sd);
	#if lena == 1
	lrc = sc[0];
	#else
	lrc = 0;
	for(i = 0; i != lena; ++i)
	{
		lrc <<= mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st * mk_lang_charbit;
		lrc |=
		#if mk_lang_bui_divmod_fuzz_inl_func_endian == mk_lang_endian_little
			sc[lena - 1 - i];
		#elif mk_lang_bui_divmod_fuzz_inl_func_endian == mk_lang_endian_big
			sc[i];
		#endif
	}
	#endif
	#if lend == 1
	lrd = sd[0];
	#else
	lrd = 0;
	for(i = 0; i != lend; ++i)
	{
		lrd <<= mk_lang_bui_divmod_fuzz_inl_func_def_sizeof_st * mk_lang_charbit;
		lrd |=
		#if mk_lang_bui_divmod_fuzz_inl_func_endian == mk_lang_endian_little
			sd[lend - 1 - i];
		#elif mk_lang_bui_divmod_fuzz_inl_func_endian == mk_lang_endian_big
			sd[i];
		#endif
	}
	#endif
	test(lrc == lc);
	test(lrd == ld);

	#undef check
	#undef check_data
	#undef advance

	#undef test
}

#undef lena
#undef lenb
#undef lend
#undef maska_
#undef maskb_
#undef mk_lang_to_num_a
#undef mk_lang_to_num_b
#undef mk_lang_to_num_as
#undef mk_lang_to_num_bs
#undef endian_name
#endif


#include "mk_lang_bui_divmod_fuzz_inl_func_undef.h"


#undef mk_lang_bui_divmod_fuzz_inl_func_alg
