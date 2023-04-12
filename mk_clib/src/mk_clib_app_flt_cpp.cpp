#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"

#define mk_sl_flt_name dbl
#define mk_sl_flt_bits 64
#define mk_sl_flt_fraction_bits 52
#include "mk_sl_flt_inl_fileh.h"
#include "mk_sl_flt_inl_filec.h"

#include <array> /* std::array */
#include <bit> /* std::bit_cast */
#include <string_view> /* std::string_view */

#include <stdio.h> /* printf */


struct mk_clib_app_flt_cpp_result_s
{
	char m_chars[mk_sl_flt_dbl_to_string_dec_basic_len_v + 1];
	int m_len;
};
typedef struct mk_clib_app_flt_cpp_result_s mk_clib_app_flt_cpp_result_t;


mk_lang_nodiscard static mk_lang_constexpr mk_clib_app_flt_cpp_result_t mk_clib_app_flt_cpp_compute_constexpr(double const d) mk_lang_noexcept
{
	std::array<unsigned char, sizeof(d)> arr mk_lang_constexpr_init;
	int mx mk_lang_constexpr_init;
	mk_clib_app_flt_cpp_result_t ret mk_lang_constexpr_init;

	arr = std::bit_cast<decltype(arr)>(d);
	mx = mk_sl_flt_dbl_to_string_dec_basic_len_v;
	ret.m_len = mk_sl_flt_dbl_bytes_to_string_dec_basic_n(arr.data(), ret.m_chars, mx);
	mk_lang_assert(ret.m_len > 0 && ret.m_len <= mx);
	ret.m_chars[ret.m_len] = '\0';
	return ret;
}


mk_lang_jumbo int mk_clib_app_flt_cpp(void) mk_lang_noexcept
{
	static mk_lang_constexpr auto const d = -123.456;
	static mk_lang_constexpr auto const flt_str = mk_clib_app_flt_cpp_compute_constexpr(d);

	int tn;
	
	using namespace std::literals;

	static_assert(flt_str.m_len == 51);
	static_assert(flt_str.m_chars == "-123.4560000000000030695446184836328029632568359375"sv);

	tn = printf("%s\n", flt_str.m_chars);
	mk_lang_assert(tn >= 0);

	return 0;
}
