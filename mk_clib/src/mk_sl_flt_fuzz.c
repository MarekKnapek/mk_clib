#include "mk_sl_flt_fuzz.h"

#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_memcpy.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_sl_flt.h"

#include <stdlib.h> /* atof */


mk_lang_jumbo void mk_sl_flt_fuzz(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	#define test(x) if(!(x)) mk_lang_unlikely mk_lang_crash(); ((void)(0))

	{
		float flta;
		int tn;
		char buff[mk_sl_flt_float_to_string_dec_basic_len_v + 1];
		int ti;
		float fltb;

		if(size < sizeof(flta)) return;
		mk_lang_memcpy(&flta, data, sizeof(flta));
		tn = ((int)(sizeof(buff) / sizeof(buff[0]) - 1));
		ti = mk_sl_flt_float_to_string_dec_basic_n(&flta, &buff[0], tn);
		test(ti > 0 && ti <= tn);
		buff[ti] = '\0';
		fltb = ((float)(atof(buff)));
		test((fltb == flta) || (flta != flta && fltb != fltb));
	}
	{
		double flta;
		int tn;
		char buff[mk_sl_flt_double_to_string_dec_basic_len_v + 1];
		int ti;
		double fltb;

		if(size < sizeof(flta)) return;
		mk_lang_memcpy(&flta, data, sizeof(flta));
		tn = ((int)(sizeof(buff) / sizeof(buff[0]) - 1));
		ti = mk_sl_flt_double_to_string_dec_basic_n(&flta, &buff[0], tn);
		test(ti > 0 && ti <= tn);
		buff[ti] = '\0';
		fltb = ((double)(atof(buff)));
		test((fltb == flta) || (flta != flta && fltb != fltb));
	}

	#undef test
}
