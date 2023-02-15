#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"

#include <string.h> /* memcpy */


#include "mk_lang_bui_divmod_fuzz_inl_func_defd.h"
#if mk_lang_bui_divmod_fuzz_inl_func_defd_valid == 1


mk_lang_jumbo void mk_lang_bui_divmod_fuzz_inl_func_defd_fn(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	#define test(x) if(!(x)) mk_lang_unlikely mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))
	#define advance(x) { mk_lang_size_t a; a = (x); mk_lang_assert(a <= s); d += a; s -= a; } ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_bui_divmod_fuzz_inl_func_defd_lt maska;
	mk_lang_bui_divmod_fuzz_inl_func_defd_lt maskb;
	mk_lang_bui_divmod_fuzz_inl_func_defd_lt la;
	mk_lang_bui_divmod_fuzz_inl_func_defd_lt lb;
	mk_lang_bui_divmod_fuzz_inl_func_defd_lt lc;
	mk_lang_bui_divmod_fuzz_inl_func_defd_lt ld;
	mk_lang_bui_divmod_fuzz_inl_func_defd_st sa[mk_lang_bui_divmod_fuzz_inl_func_defd_lena];
	mk_lang_bui_divmod_fuzz_inl_func_defd_st sb[mk_lang_bui_divmod_fuzz_inl_func_defd_lenb];
	mk_lang_bui_divmod_fuzz_inl_func_defd_st sc[mk_lang_bui_divmod_fuzz_inl_func_defd_lena];
	mk_lang_bui_divmod_fuzz_inl_func_defd_st sd[mk_lang_bui_divmod_fuzz_inl_func_defd_lend];
	mk_lang_bui_divmod_fuzz_inl_func_defd_lt lrc;
	mk_lang_bui_divmod_fuzz_inl_func_defd_lt lrd;
	int i;

	d = data;
	s = size;
	maska = mk_lang_bui_divmod_fuzz_inl_func_defd_maska;
	maskb = mk_lang_bui_divmod_fuzz_inl_func_defd_maskb;
	check_data(sizeof(la));
	memcpy(&la, d, sizeof(la));
	advance(sizeof(la));
	check_data(sizeof(lb));
	memcpy(&lb, d, sizeof(lb));
	advance(sizeof(lb));
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
	for(i = 0; i != mk_lang_bui_divmod_fuzz_inl_func_defd_lena; ++i)
	{
		sa[mk_lang_bui_divmod_fuzz_inl_func_defd_idxa(i)] = ((mk_lang_bui_divmod_fuzz_inl_func_defd_st)(la >> (i * (mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st * mk_lang_charbit))));
	}
	for(i = 0; i != mk_lang_bui_divmod_fuzz_inl_func_defd_lenb; ++i)
	{
		sb[mk_lang_bui_divmod_fuzz_inl_func_defd_idxb(i)] = ((mk_lang_bui_divmod_fuzz_inl_func_defd_st)(lb >> (i * (mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st * mk_lang_charbit))));
	}
	mk_lang_bui_divmod_fuzz_inl_func_defd_divmod(sa, sb, sc, sd);
	#if mk_lang_bui_divmod_fuzz_inl_func_defd_lena == 1
	lrc = sc[0];
	#else
	lrc = 0;
	for(i = 0; i != mk_lang_bui_divmod_fuzz_inl_func_defd_lena; ++i)
	{
		lrc = ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(lrc << (mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st * mk_lang_charbit)));
		lrc = ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(lrc | ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(sc[mk_lang_bui_divmod_fuzz_inl_func_defd_idxa((mk_lang_bui_divmod_fuzz_inl_func_defd_lena - 1) - i)]))));
	}
	#endif
	#if mk_lang_bui_divmod_fuzz_inl_func_defd_lend == 1
	lrd = sd[0];
	#else
	lrd = 0;
	for(i = 0; i != mk_lang_bui_divmod_fuzz_inl_func_defd_lend; ++i)
	{
		lrd = ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(lrd << (mk_lang_bui_divmod_fuzz_inl_func_defd_sizeof_st * mk_lang_charbit)));
		lrd = ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(lrd | ((mk_lang_bui_divmod_fuzz_inl_func_defd_lt)(sd[mk_lang_bui_divmod_fuzz_inl_func_defd_idxd((mk_lang_bui_divmod_fuzz_inl_func_defd_lend - 1) - i)]))));
	}
	#endif
	test(lrc == lc);
	test(lrd == ld);

	#undef check
	#undef check_data
	#undef advance

	#undef test
}


#endif
#include "mk_lang_bui_divmod_fuzz_inl_func_defu.h"
