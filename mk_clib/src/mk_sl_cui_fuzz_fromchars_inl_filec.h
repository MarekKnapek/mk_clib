#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_str_style.h"
#include "mk_lang_string.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#include "mk_sl_cui_fuzz_fromchars_inl_defd.h"


#if mk_lang_version_at_least_cpp_17 || mk_lang_version_at_least_msvc_cpp_17


#include <charconv> /* std::from_chars std::from_chars_result */


#define mk_lang_bui_t_name mk_sl_cui_fuzz_fromchars_inl_defd_a_prefix
#define mk_lang_bui_t_base mk_sl_cui_fuzz_fromchars_inl_defd_a_tn
#define mk_lang_bui_t_str_style mk_lang_str_style_arithmetic_if_possible
#define mk_lang_bui_t_inline 0
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#include "mk_lang_bui_inl_fileu.h"

#define mk_lang_bui_t_name mk_sl_cui_fuzz_fromchars_inl_defd_b_prefix
#define mk_lang_bui_t_base mk_sl_cui_fuzz_fromchars_inl_defd_b_tn
#define mk_lang_bui_t_str_style mk_lang_str_style_arithmetic_if_possible
#define mk_lang_bui_t_inline 0
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#include "mk_lang_bui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_cui_fuzz_fromchars_inl_defd_c_prefix
#define mk_sl_cui_t_base_type_name mk_sl_cui_fuzz_fromchars_inl_defd_b_prefix
#define mk_sl_cui_t_count (mk_sl_cui_fuzz_fromchars_inl_defd_a_size_bits_d / mk_sl_cui_fuzz_fromchars_inl_defd_b_size_bits_d)
#define mk_sl_cui_t_endian mk_sl_cui_fuzz_fromchars_inl_defd_endian
#define mk_sl_cui_t_str_style mk_sl_cui_fuzz_fromchars_inl_defd_str_style
#define mk_sl_cui_t_disable_big_div 0
#define mk_sl_cui_t_base_size_bits_d mk_sl_cui_fuzz_fromchars_inl_defd_b_size_bits_d
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_fromchars_inl_defd_pr_statics(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_fuzz_fromchars_inl_defd_c_t) == sizeof(mk_sl_cui_fuzz_fromchars_inl_defd_a_t));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_c_size_bytes_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_a_size_bytes_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_c_size_bits_v )) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_a_size_bits_v )));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_c_strlen_bin_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_a_strlen_bin_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_c_strlen_oct_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_a_strlen_oct_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_c_strlen_dec_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_a_strlen_dec_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_c_strlen_hex_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_fromchars_inl_defd_a_strlen_hex_v)));

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(data));
	((mk_lang_types_void_t)(size));
}

#include "mk_lang_warning_msvc_push_c5045.h"
static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_fromchars_inl_defd_pr_fromchars_bin(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_fromchars_inl_defd_a_strlen_bin_v] mk_lang_constexpr_init;
	std::from_chars_result str_len_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_fromchars_inl_defd_a_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_fromchars_inl_defd_c_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rc mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = mk_lang_min(mk_lang_countof(str_buf), size);
	for(i = 0; i != n; ++i)
	{
		str_buf[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	str_len_a = std::from_chars(&str_buf[0], &str_buf[0] + n, bui, 2);
	str_len_c = mk_sl_cui_fuzz_fromchars_inl_defd_c_from_str_bin_n(&cui, &str_buf[0], ((mk_lang_types_sint_t)(n)));
	mk_lang_test
	(
		(str_len_a.ec == std::errc{} && str_len_a.ptr == &str_buf[0] + str_len_c && str_len_c >= 1) ||
		(str_len_a.ec == std::errc::invalid_argument && str_len_a.ptr == &str_buf[0] && str_len_c == 0) ||
		(str_len_a.ec == std::errc::result_out_of_range && str_len_a.ptr == &str_buf[0] + (-str_len_c) && str_len_c < 0)
	);
	if(str_len_c >= 1)
	{
		ra = ((mk_lang_types_ulllong_t)(bui));
		mk_sl_cui_fuzz_fromchars_inl_defd_c_to_bi_ulllong(&cui, &rc);
		mk_lang_test(rc == ra);
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_fromchars_inl_defd_pr_fromchars_oct(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_fromchars_inl_defd_a_strlen_oct_v] mk_lang_constexpr_init;
	std::from_chars_result str_len_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_fromchars_inl_defd_a_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_fromchars_inl_defd_c_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rc mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = mk_lang_min(mk_lang_countof(str_buf), size);
	for(i = 0; i != n; ++i)
	{
		str_buf[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	str_len_a = std::from_chars(&str_buf[0], &str_buf[0] + n, bui, 8);
	str_len_c = mk_sl_cui_fuzz_fromchars_inl_defd_c_from_str_oct_n(&cui, &str_buf[0], ((mk_lang_types_sint_t)(n)));
	mk_lang_test
	(
		(str_len_a.ec == std::errc{} && str_len_a.ptr == &str_buf[0] + str_len_c && str_len_c >= 1) ||
		(str_len_a.ec == std::errc::invalid_argument && str_len_a.ptr == &str_buf[0] && str_len_c == 0) ||
		(str_len_a.ec == std::errc::result_out_of_range && str_len_a.ptr == &str_buf[0] + (-str_len_c) && str_len_c < 0)
	);
	if(str_len_c >= 1)
	{
		ra = ((mk_lang_types_ulllong_t)(bui));
		mk_sl_cui_fuzz_fromchars_inl_defd_c_to_bi_ulllong(&cui, &rc);
		mk_lang_test(rc == ra);
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_fromchars_inl_defd_pr_fromchars_dec(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_fromchars_inl_defd_a_strlen_dec_v] mk_lang_constexpr_init;
	std::from_chars_result str_len_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_fromchars_inl_defd_a_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_fromchars_inl_defd_c_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rc mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = mk_lang_min(mk_lang_countof(str_buf), size);
	for(i = 0; i != n; ++i)
	{
		str_buf[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	str_len_a = std::from_chars(&str_buf[0], &str_buf[0] + n, bui, 10);
	str_len_c = mk_sl_cui_fuzz_fromchars_inl_defd_c_from_str_dec_n(&cui, &str_buf[0], ((mk_lang_types_sint_t)(n)));
	mk_lang_test
	(
		(str_len_a.ec == std::errc{} && str_len_a.ptr == &str_buf[0] + str_len_c && str_len_c >= 1) ||
		(str_len_a.ec == std::errc::invalid_argument && str_len_a.ptr == &str_buf[0] && str_len_c == 0) ||
		(str_len_a.ec == std::errc::result_out_of_range && str_len_a.ptr == &str_buf[0] + (-str_len_c) && str_len_c < 0)
	);
	if(str_len_c >= 1)
	{
		ra = ((mk_lang_types_ulllong_t)(bui));
		mk_sl_cui_fuzz_fromchars_inl_defd_c_to_bi_ulllong(&cui, &rc);
		mk_lang_test(rc == ra);
	}
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_fromchars_inl_defd_pr_fromchars_hex(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf[2 * mk_sl_cui_fuzz_fromchars_inl_defd_a_strlen_hex_v] mk_lang_constexpr_init;
	std::from_chars_result str_len_a mk_lang_constexpr_init;
	mk_sl_cui_fuzz_fromchars_inl_defd_a_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len_c mk_lang_constexpr_init;
	mk_sl_cui_fuzz_fromchars_inl_defd_c_t cui mk_lang_constexpr_init;
	mk_lang_types_ulllong_t ra mk_lang_constexpr_init;
	mk_lang_types_ulllong_t rc mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = mk_lang_min(mk_lang_countof(str_buf), size);
	for(i = 0; i != n; ++i)
	{
		str_buf[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	str_len_a = std::from_chars(&str_buf[0], &str_buf[0] + n, bui, 16);
	str_len_c = mk_sl_cui_fuzz_fromchars_inl_defd_c_from_str_hex_n(&cui, &str_buf[0], ((mk_lang_types_sint_t)(n)));
	mk_lang_test
	(
		(str_len_a.ec == std::errc{} && str_len_a.ptr == &str_buf[0] + str_len_c && str_len_c >= 1) ||
		(str_len_a.ec == std::errc::invalid_argument && str_len_a.ptr == &str_buf[0] && str_len_c == 0) ||
		(str_len_a.ec == std::errc::result_out_of_range && str_len_a.ptr == &str_buf[0] + (-str_len_c) && str_len_c < 0)
	);
	if(str_len_c >= 1)
	{
		ra = ((mk_lang_types_ulllong_t)(bui));
		mk_sl_cui_fuzz_fromchars_inl_defd_c_to_bi_ulllong(&cui, &rc);
		mk_lang_test(rc == ra);
	}
}
#include "mk_lang_warning_msvc_pop.h"


#endif


mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_fuzz_fromchars_inl_defd_fn(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size, mk_lang_types_bool_t const allow_all) mk_lang_noexcept
{
#if mk_lang_version_at_least_cpp_17 || mk_lang_version_at_least_msvc_cpp_17
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_lang_types_uint_t line mk_lang_constexpr_init;
	mk_lang_types_bool_t all mk_lang_constexpr_init;
	mk_lang_types_uint_t base mk_lang_constexpr_init;
	mk_lang_types_uint_t curr mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(allow_all == mk_lang_true || allow_all == mk_lang_false);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	line = 0;
	if(s >= mk_lang_bui_uint_size_bytes_v)
	{
		mk_lang_bui_uint_from_buis_uchar_le(&line, &d[0]);
		d += mk_lang_bui_uint_size_bytes_v;
		s -= mk_lang_bui_uint_size_bytes_v;
	}
	all = mk_lang_bui_uint_is_max(&line) && allow_all;
	base = __LINE__;
	curr = base + 2 + line;
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_fromchars_inl_defd_pr_statics(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_fromchars_inl_defd_pr_fromchars_bin(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_fromchars_inl_defd_pr_fromchars_oct(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_fromchars_inl_defd_pr_fromchars_dec(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_fromchars_inl_defd_pr_fromchars_hex(d, s); }
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(allow_all == mk_lang_true || allow_all == mk_lang_false);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(data));
	((mk_lang_types_void_t)(size));
#endif
}


#include "mk_sl_cui_fuzz_fromchars_inl_defu.h"
