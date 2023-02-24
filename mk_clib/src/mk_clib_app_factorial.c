#include "mk_clib_app_factorial.h"

#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_sizeof.h"
#define mk_lang_bui_name fct
#define mk_lang_bui_type mk_lang_bi_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_name fct
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_fct
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count ((9 * 1024) / mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#include <stdio.h> /* printf */
#include <stdlib.h> /* atoi */


#define nmin 1
#define nmax 1000
#define tostr_(x) #x
#define tostr(x) tostr_(x)


mk_lang_jumbo char const* mk_clib_app_factorial_get_exe_name(char const* const arg) mk_lang_noexcept
{
	char const* r;
	char const* p;

	r = arg;
	for(p = r; *p; ++p)
	{
		if(*p == '/' || *p == '\\')
		{
			r = p + 1;
		}
	}
	return r;
}

mk_lang_jumbo void mk_clib_app_factorial_compute_and_print(int const n) mk_lang_noexcept
{
	mk_sl_cui_fct_t a;
	mk_sl_cui_fct_t b;
	int i;

	mk_lang_assert(n >= nmin && n <= nmax);

	mk_sl_cui_fct_set_one(&a);
	b = a;
	for(i = 1; i != n; ++i)
	{
		mk_sl_cui_fct_inc1(&b);
		mk_sl_cui_fct_mul2_wrap_lo(&a, &b);
	}
	{
		/* tmp */
		unsigned un;
		int tn;
		mk_sl_cui_fct_to_bi_uint(&a, &un);
		tn = printf("%u\n", un);
		mk_lang_assert(tn >= 0);
		/* tmp */
	}
}


mk_lang_jumbo int mk_clib_app_factorial(int const argc, char const* const* const argv) mk_lang_noexcept
{
	if(argc < 1)
	{
		return 1;
	}
	else if(argc != 2)
	{
		int tn;
		tn = printf("Example usage: %s 5\n", mk_clib_app_factorial_get_exe_name(argv[0]));
		mk_lang_assert(tn >= 0);
		return 0;
	}
	else
	{
		int n;
		n = atoi(argv[1]);
		if(!(n >= nmin && n <= nmax))
		{
			int tn;
			tn = printf("Please enter value between " tostr(nmin) " and " tostr(nmax) ", you entered %d.\n", n);
			mk_lang_assert(tn >= 0);
			return 0;
		}
		else
		{
			mk_clib_app_factorial_compute_and_print(n);
			return 0;
		}
	}
}


#undef nmin
#undef nmax
#undef tostr_
#undef tostr
