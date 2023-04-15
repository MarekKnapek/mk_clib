#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1
#include "mk_sl_flt_parse_fuzz.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_cpp.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_lang_static_assert.h"

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

#include <charconv> /* std::from_chars */


mk_lang_extern_c mk_lang_jumbo void mk_sl_flt_parse_fuzz(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	#define test(x) if(!(x)) mk_lang_unlikely mk_lang_crash(); ((void)(0))

	#if(!((defined __cplusplus && __cplusplus >= 201703l) || (defined _MSVC_LANG && _MSVC_LANG >= 201703l)))
	mk_lang_static_assert(false);
	#endif

	do
	{
		char const* d;
		int s;
		float fa;
		int n;
		std::from_chars_result res;
		float fb;

		d = ((char const*)(data));
		s = ((int)(size));
		n = mk_sl_flt_parse_fzflt_void_from_string_dec_n(&fa, d, s);
		mk_lang_assert(n >= 0 && n <= s);
		if(n == 0) break;
		res = std::from_chars(d + (d[0] == '+' ? 1 : 0), d + n, fb);
		mk_lang_assert(res.ec == std::errc::result_out_of_range || res.ec == std::errc{});
		test((fa == fb) || (fa != fa && fb != fb));
		//test(res.ptr == d + n);
	}while(0);
	do
	{
		char const* d;
		int s;
		double fa;
		int n;
		std::from_chars_result res;
		double fb;

		d = ((char const*)(data));
		s = ((int)(size));
		n = mk_sl_flt_parse_fzdbl_void_from_string_dec_n(&fa, d, s);
		mk_lang_assert(n >= 0 && n <= s);
		if(n == 0) break;
		res = std::from_chars(d + (d[0] == '+' ? 1 : 0), d + n, fb);
		mk_lang_assert(res.ec == std::errc::result_out_of_range || res.ec == std::errc{});
		test((fa == fb) || (fa != fa && fb != fb));
		//test(res.ptr == d + n);
	}while(0);

	#undef test
}
