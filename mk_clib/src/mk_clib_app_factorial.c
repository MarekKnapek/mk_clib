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

#include <stdio.h> /* printf */
#include <stdlib.h> /* atoi */
#include <string.h> /* memcpy */


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




#include "mk_sl_flt.h"


static void dothis(float f)
{
	int tn;
	int ti;
	char buff[mk_sl_flt_float_to_string_dec_basic_len_v + 1];

	tn = ((int)(sizeof(buff) / sizeof(buff[0]) - 1));
	ti = mk_sl_flt_float_to_string_dec_basic_n(&f, buff, tn);
	mk_lang_assert(ti > 0 && ti <= tn);
	buff[ti] = '\0';
	printf("%s\n", buff);
}


mk_lang_jumbo int mk_clib_app_factorial(int const argc, char const* const* const argv) mk_lang_noexcept
{
	int tn;
	float f;

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
		f = ((float)(atof(argv[1])));
		dothis(f);
		return 0;
	}
}


#undef nmin
#undef nmax
#undef tostr_
#undef tostr
