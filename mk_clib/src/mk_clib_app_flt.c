#include "mk_clib_app_flt.h"

#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"

#define mk_sl_flt_name dbl
#define mk_sl_flt_bits 64
#define mk_sl_flt_fraction_bits 52
#include "mk_sl_flt_inl_fileh.h"
#include "mk_sl_flt_inl_filec.h"

#include <stdio.h> /* printf */
#include <stdlib.h> /* atof */


mk_lang_jumbo int mk_clib_app_flt(int const argc, char const* const* const argv) mk_lang_noexcept
{
	double d;
	int mx;
	char* bf;
	char buff[mk_sl_flt_dbl_to_string_dec_basic_len_v + 1];
	int n;

	mk_lang_assert(argv);

	d = 0.0;
	if(argc == 2)
	{
		d = atof(argv[1]);
	}
	mx = mk_sl_flt_dbl_to_string_dec_basic_len_v;
	bf = buff;
	n = mk_sl_flt_dbl_to_string_dec_basic_n(&d, bf, mx);
	mk_lang_assert(n > 0 && n <= mx);
	bf[n] = '\0';
	n = printf("%s\n", bf);
	mk_lang_assert(n > 0);
	return 0;
}
