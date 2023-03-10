#include "mk_sl_flt_fuzz.h"

#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_memcpy.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_sl_flt.h"


mk_lang_jumbo void mk_sl_flt_fuzz(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	#define test(x) if(!(x)) mk_lang_unlikely mk_lang_crash(); ((void)(0))

	float f;
	int tn;
	char buff[mk_sl_flt_float_to_string_dec_basic_len_v];
	int ti;

	if(size < sizeof(float))
	{
		return;
	}
	mk_lang_memcpy(&f, data, sizeof(f));
	tn = ((int)(sizeof(buff) / sizeof(buff[0])));
	ti = mk_sl_flt_float_to_string_dec_basic_n(&f, &buff[0], tn);
	test(ti > 0 && ti <= tn);

	#undef test
}
