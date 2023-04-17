#include "mk_sl_flt_parse_fuzz.hpp"

extern "C"
{
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
}

#include <charconv> /* std::from_chars */


mk_lang_extern_c void mk_sl_flt_parse_fuzz(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
		int c;
		mk_sl_flt_parse_fzflt_result_t ra;
		std::from_chars_result rb;
		float fb;

		d = ((char const*)(data));
		s = ((int)(size));
		mk_sl_flt_parse_fzflt_void_from_string_dec_n(&fa, d, s, &c, &ra);
		mk_lang_assert(c >= 0 && c <= s);
		if(ra == mk_sl_flt_parse_fzflt_result_e_invalid) break; /* todo test also invalid */
		rb = std::from_chars(d + ((d[0] == '+') ? 1 : 0), d + c, fb); /* todo test s length */
		mk_lang_assert((rb.ec == std::errc{} && ra == mk_sl_flt_parse_fzflt_result_e_ok) || (rb.ec == std::errc::result_out_of_range && ra == mk_sl_flt_parse_fzflt_result_e_out_of_range));
		test((fa == fb) || (fa != fa && fb != fb));
		test(rb.ptr == d + c);
	}while(0);
	do
	{
		char const* d;
		int s;
		double fa;
		int c;
		mk_sl_flt_parse_fzdbl_result_t ra;
		std::from_chars_result rb;
		double fb;

		d = ((char const*)(data));
		s = ((int)(size));
		mk_sl_flt_parse_fzdbl_void_from_string_dec_n(&fa, d, s, &c, &ra);
		mk_lang_assert(c >= 0 && c <= s);
		if(ra == mk_sl_flt_parse_fzdbl_result_e_invalid) break; /* todo test also invalid */
		rb = std::from_chars(d + ((d[0] == '+') ? 1 : 0), d + c, fb); /* todo test s length */
		mk_lang_assert((rb.ec == std::errc{} && ra == mk_sl_flt_parse_fzdbl_result_e_ok) || (rb.ec == std::errc::result_out_of_range && ra == mk_sl_flt_parse_fzdbl_result_e_out_of_range));
		test((fa == fb) || (fa != fa && fb != fb));
		test(rb.ptr == d + c);
	}while(0);

	#undef test
}
