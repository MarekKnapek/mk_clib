#include "mk_clib_app_factorial.h"

#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_div_roundup.h"
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
#define mk_sl_cui_count mk_lang_div_roundup(19072, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#define mk_sl_cui_name hlp
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_fct
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count 1
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"

#include <stdio.h> /* printf */
#include <string.h> /* strlen */


#define nmin 1
#define nmax 2000
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
	mk_sl_cui_fct_t* pa1;
	mk_sl_cui_fct_t a1;
	mk_sl_cui_fct_t* pa2;
	mk_sl_cui_fct_t a2;
	mk_sl_cui_fct_t b;
	int i;
	mk_sl_cui_fct_t* pa3;
	int tn;
	char buff[mk_sl_cui_fct_to_str_dec_len + 1];

	mk_lang_assert(n >= nmin && n <= nmax);

	pa1 = &a1;
	pa2 = &a2;
	mk_sl_cui_fct_set_one(pa1);
	b = *pa1;
	for(i = 1; i != n; ++i)
	{
		mk_sl_cui_fct_inc1(&b);
		mk_sl_cui_fct_mul3_wrap_lo(pa1, &b, pa2);
		pa3 = pa1;
		pa1 = pa2;
		pa2 = pa3;
	}
	tn = mk_sl_cui_fct_to_str_dec_n(pa1, &buff[0], ((int)(sizeof(buff) / sizeof(*buff))) - 1);
	mk_lang_assert(tn != 0);
	buff[tn] = '\0';
	tn = printf("%s\n", &buff[0]);
	mk_lang_assert(tn >= 0);
}


mk_lang_jumbo int mk_clib_app_factorial(int const argc, char const* const* const argv) mk_lang_noexcept
{
	int tn;
	int n;
	mk_sl_cui_hlp_t hlp;

	if(argc < 1)
	{
		return 1;
	}
	else if(argc != 2)
	{
		tn = printf("Example usage: %s 5\n", mk_clib_app_factorial_get_exe_name(argv[0]));
		mk_lang_assert(tn >= 0);
		return 0;
	}
	else
	{
		n = 0;
		tn = mk_sl_cui_hlp_from_str_dec_n(&hlp, argv[1], ((int)(strlen(argv[1]))));
		if(tn > 0)
		{
			mk_sl_cui_hlp_to_bi_sint(&hlp, &n);
		}
		if(!(n >= nmin && n <= nmax))
		{
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
