#include "mk_sl_flt_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_memcpy.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"

#define mk_sl_flt_name float
#define mk_sl_flt_bits 32
#define mk_sl_flt_fraction_bits 23
#include "mk_sl_flt_inl_fileh.h"
#include "mk_sl_flt_inl_filec.h"

#include <string.h> /* memcpy */
#include <stdlib.h> /* malloc atof free */


mk_lang_jumbo void mk_sl_flt_fuzz(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	#define test(x) if(!(x)) mk_lang_unlikely mk_lang_crash(); ((void)(0))

	/*do
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
		if(s < sizeof(shrt)) break; mk_lang_memcpy(&shrt, d, sizeof(shrt)); d += sizeof(shrt); s -= sizeof(shrt);
		if(s < sizeof(flta)) break; mk_lang_memcpy(&flta, d, sizeof(flta)); d += sizeof(flta); s -= sizeof(flta);
		shrt &= 0xffffu; tn = ((int)(shrt)); if(tn <= 0) break;
		buff = ((char*)(malloc(tn))); if(!buff) break;
		ti = mk_sl_flt_float_to_string_dec_basic_n(&flta, &buff[0], tn);
		test(ti >= 0 && ti <= tn && ti <= mk_sl_flt_float_to_string_dec_basic_len_v);
		if(ti == 0 || ti == tn){ free(buff); break; }
		buff[ti] = '\0';
		fltb = ((float)(atof(buff)));
		test((fltb == flta) || (flta != flta && fltb != fltb));
		free(buff);
	}while(0);
	do
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
		if(s < sizeof(shrt)) break; mk_lang_memcpy(&shrt, d, sizeof(shrt)); d += sizeof(shrt); s -= sizeof(shrt);
		if(s < sizeof(flta)) break; mk_lang_memcpy(&flta, d, sizeof(flta)); d += sizeof(flta); s -= sizeof(flta);
		shrt &= 0xffffu; tn = ((int)(shrt)); if(tn <= 0) break;
		buff = ((char*)(malloc(tn))); if(!buff) break;
		ti = mk_sl_flt_double_to_string_dec_basic_n(&flta, &buff[0], tn);
		test(ti >= 0 && ti <= tn && ti <= mk_sl_flt_double_to_string_dec_basic_len_v);
		if(ti == 0 || ti == tn){ free(buff); break; }
		buff[ti] = '\0';
		fltb = ((double)(atof(buff)));
		test((fltb == flta) || (flta != flta && fltb != fltb));
		free(buff);
	}while(0);*/
	do
	{
		float fa;
		int n;
		char* buff;
		float fb;

		if(size == 0) break;
		n = mk_sl_flt_float_from_string_dec_n(&fa, ((char const*)(data)), ((int)(size)));
		mk_lang_assert(n >= 0 && n <= ((int)(size)));
		if(n == 0) break;
		buff = ((char*)(malloc(n + 1))); if(!buff) break;
		memcpy(buff, data, n);
		buff[n] = '\0';
		fb = ((float)(atof(buff)));
		free(buff);
		test((fa == fb) || (fa != fa && fb != fb));
	}while(0);

	#undef test
}
