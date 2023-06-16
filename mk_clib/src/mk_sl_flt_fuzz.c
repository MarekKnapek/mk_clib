#include "mk_sl_flt_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_memcpy.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_sl_flt.h"

#include <stdlib.h> /* malloc atof free */


mk_lang_jumbo void mk_sl_flt_fuzz(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_assert(0); mk_lang_crash(); } ((void)(0))

	{
		unsigned char const* d;
		mk_lang_size_t s;
		unsigned short shrt;
		float flta;
		int tn;
		char* buff;
		int ti;
		float fltb;

		d = data;
		s = size;
		if(s < sizeof(shrt)) return; mk_lang_memcpy(&shrt, d, sizeof(shrt)); d += sizeof(shrt); s -= sizeof(shrt);
		if(s < sizeof(flta)) return; mk_lang_memcpy(&flta, d, sizeof(flta)); d += sizeof(flta); s -= sizeof(flta);
		shrt &= 0xffffu; tn = ((int)(shrt)); if(tn <= 0) return;
		buff = ((char*)(malloc(tn))); if(!buff) return;
		ti = mk_sl_flt_float_to_string_dec_basic_n(&flta, &buff[0], tn);
		test(ti >= 0 && ti <= tn && ti <= mk_sl_flt_float_to_string_dec_basic_len_v);
		if(ti == 0 || ti == tn){ free(buff); return; }
		buff[ti] = '\0';
		fltb = ((float)(atof(buff)));
		test((fltb == flta) || (flta != flta && fltb != fltb));
		free(buff);
	}
	{
		unsigned char const* d;
		mk_lang_size_t s;
		unsigned short shrt;
		double flta;
		int tn;
		char* buff;
		int ti;
		double fltb;

		d = data;
		s = size;
		if(s < sizeof(shrt)) return; mk_lang_memcpy(&shrt, d, sizeof(shrt)); d += sizeof(shrt); s -= sizeof(shrt);
		if(s < sizeof(flta)) return; mk_lang_memcpy(&flta, d, sizeof(flta)); d += sizeof(flta); s -= sizeof(flta);
		shrt &= 0xffffu; tn = ((int)(shrt)); if(tn <= 0) return;
		buff = ((char*)(malloc(tn))); if(!buff) return;
		ti = mk_sl_flt_double_to_string_dec_basic_n(&flta, &buff[0], tn);
		test(ti >= 0 && ti <= tn && ti <= mk_sl_flt_double_to_string_dec_basic_len_v);
		if(ti == 0 || ti == tn){ free(buff); return; }
		buff[ti] = '\0';
		fltb = ((double)(atof(buff)));
		test((fltb == flta) || (flta != flta && fltb != fltb));
		free(buff);
	}

	#undef test
}
