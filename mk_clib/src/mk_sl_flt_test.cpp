#include "mk_sl_flt_test.hpp"
#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_version.h"

#define mk_sl_flt_name dbl
#define mk_sl_flt_bits 64
#define mk_sl_flt_fraction_bits 52
#include "mk_sl_flt_inl_fileh.h"
#include "mk_sl_flt_inl_filec.h"

#if mk_lang_version_at_least_cpp_20 || mk_lang_version_at_least_msvc_cpp_20

#include <array> /* std::array */
#include <bit> /* std::bit_cast */
#include <string_view> /* std::string_view */


struct mk_sl_flt_test_result_s
{
	int m_len;
	char m_chars[mk_sl_flt_dbl_to_string_dec_basic_len_v + 1];
};
typedef struct mk_sl_flt_test_result_s mk_sl_flt_test_result_t;


mk_lang_nodiscard static mk_lang_constexpr mk_sl_flt_test_result_t mk_sl_flt_test_compute_constexpr(double const d) mk_lang_noexcept
{
	std::array<unsigned char, sizeof(d)> arr mk_lang_constexpr_init;
	int mx mk_lang_constexpr_init;
	mk_sl_flt_test_result_t ret mk_lang_constexpr_init;

	arr = std::bit_cast<decltype(arr)>(d);
	mx = mk_sl_flt_dbl_to_string_dec_basic_len_v;
	ret.m_len = mk_sl_flt_dbl_bytes_to_string_dec_basic_n(arr.data(), ret.m_chars, mx);
	mk_lang_assert(ret.m_len > 0 && ret.m_len <= mx);
	ret.m_chars[ret.m_len] = '\0';
	return ret;
}

#endif


mk_lang_extern_c void mk_sl_flt_test(void) mk_lang_noexcept
{
	#if mk_lang_version_at_least_cpp_20 || mk_lang_version_at_least_msvc_cpp_20

	mk_lang_constexpr_static_inline auto const d = -123.456;
	mk_lang_constexpr_static_inline auto const flt_str = mk_sl_flt_test_compute_constexpr(d);

	using namespace std::literals;

	static_assert(flt_str.m_len == 51);
	static_assert(flt_str.m_chars == "-123.4560000000000030695446184836328029632568359375"sv);

	#endif
}
