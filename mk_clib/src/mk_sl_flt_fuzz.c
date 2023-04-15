#include "mk_sl_flt_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_memcpy.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"

#if (defined __cplusplus && __cplusplus >= 201703l) || (defined _MSVC_LANG && _MSVC_LANG >= 201703l)
#define mk_sl_flt_name fzflt
#define mk_sl_flt_bits 32
#define mk_sl_flt_fraction_bits 23
#include "mk_sl_flt_parse_inl_fileh.h"
#include "mk_sl_flt_parse_inl_filec.h"

#define mk_sl_flt_name fzdbl
#define mk_sl_flt_bits 64
#define mk_sl_flt_fraction_bits 52
#include "mk_sl_flt_parse_inl_fileh.h"
#include "mk_sl_flt_parse_inl_filec.h"
#endif

#include <string.h> /* memcpy */
#include <stdlib.h> /* malloc atof free */
#if (defined __cplusplus && __cplusplus >= 201703l) || (defined _MSVC_LANG && _MSVC_LANG >= 201703l)
#include <charconv> /* std::from_chars */
#endif


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
#if (defined __cplusplus && __cplusplus >= 201703l) || (defined _MSVC_LANG && _MSVC_LANG >= 201703l)
	do
	{
		float fa;
		int n;
		std::from_chars_result res;
		float fb;

		n = mk_sl_flt_parse_fzflt_void_from_string_dec_n(((void*)(&fa)), ((char const*)(data)), ((int)(size)));
		mk_lang_assert(n >= 0 && n <= ((int)(size)));
		if(n == 0) break;
		res = std::from_chars(data + (((char const*)(data))[0] == '+' ? 1 : 0), data + size, fb);
		mk_lang_assert(res.ec == std::errc::result_out_of_range || res.ec == std::errc{});
		test((fa == fb) || (fa != fa && fb != fb));
	}while(0);
	do
	{
		double fa;
		int n;
		std::from_chars_result res;
		double fb;

		n = mk_sl_flt_parse_fzdbl_void_from_string_dec_n(((void*)(&fa)), ((char const*)(data)), ((int)(size)));
		mk_lang_assert(n >= 0 && n <= ((int)(size)));
		if(n == 0) break;
		res = std::from_chars(data + (((char const*)(data))[0] == '+' ? 1 : 0), data + size, fb);
		mk_lang_assert(res.ec == std::errc::result_out_of_range || res.ec == std::errc{});
		test((fa == fb) || (fa != fa && fb != fb));
	}while(0);
#endif

	#undef test
}
