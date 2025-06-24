#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_endian.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_llong.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_str_style.h"
#include "mk_lang_string.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#if (mk_lang_version_at_least_c_99 || mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11) && mk_lang_llong_has


#include <stdio.h> /* snprintf */


#include "mk_sl_cui_fuzz_printf_inl_defd.h"


#define mk_lang_bui_t_name mk_sl_cui_fuzz_printf_inl_defd_a_prefix
#define mk_lang_bui_t_base mk_sl_cui_fuzz_printf_inl_defd_a_tn
#define mk_lang_bui_t_str_style mk_lang_str_style_arithmetic_if_possible
#define mk_lang_bui_t_inline 0
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#include "mk_lang_bui_inl_fileu.h"

#define mk_lang_bui_t_name mk_sl_cui_fuzz_printf_inl_defd_b_prefix
#define mk_lang_bui_t_base mk_sl_cui_fuzz_printf_inl_defd_b_tn
#define mk_lang_bui_t_str_style mk_lang_str_style_arithmetic_if_possible
#define mk_lang_bui_t_inline 0
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#include "mk_lang_bui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_cui_fuzz_printf_inl_defd_c_prefix
#define mk_sl_cui_t_base_type_name mk_sl_cui_fuzz_printf_inl_defd_b_prefix
#define mk_sl_cui_t_count (mk_sl_cui_fuzz_printf_inl_defd_a_size_bits_d / mk_sl_cui_fuzz_printf_inl_defd_b_size_bits_d)
#define mk_sl_cui_t_endian mk_sl_cui_fuzz_printf_inl_defd_endian
#define mk_sl_cui_t_str_style mk_sl_cui_fuzz_printf_inl_defd_str_style
#define mk_sl_cui_t_disable_big_div 0
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_fuzz_printf_inl_defd_b_size_bits_d
#define mk_sl_cui_t_inline 0
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_printf_inl_defd_pr_statics(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_static_assert(sizeof(mk_sl_cui_fuzz_printf_inl_defd_c_t) == sizeof(mk_sl_cui_fuzz_printf_inl_defd_a_t));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_c_size_bytes_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_a_size_bytes_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_c_size_bits_v )) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_a_size_bits_v )));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_c_strlen_bin_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_a_strlen_bin_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_c_strlen_oct_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_a_strlen_oct_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_c_strlen_dec_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_a_strlen_dec_v)));
	mk_lang_static_assert(((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_c_strlen_hex_v)) == ((mk_lang_types_sint_t)(mk_sl_cui_fuzz_printf_inl_defd_a_strlen_hex_v)));

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
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_printf_inl_defd_pr_printf_u(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_printf_inl_defd_a_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_printf_inl_defd_c_t cui mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len_a mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[2 * mk_sl_cui_fuzz_printf_inl_defd_a_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len_c mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[2 * mk_sl_cui_fuzz_printf_inl_defd_c_strlen_dec_v] mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= sizeof(bui)))
	{
		return;
	}
	mk_sl_cui_fuzz_printf_inl_defd_a_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_printf_inl_defd_c_from_buis_uchar_le(&cui, &d[0]);
	d += sizeof(bui);
	s -= sizeof(bui);
	str_len_a = snprintf(&str_buf_a[0], mk_lang_countof(str_buf_a), "%" mk_sl_cui_fuzz_printf_inl_defd_a_printf_length_modifier "u", bui);
	str_len_c = mk_sl_cui_fuzz_printf_inl_defd_c_to_str_dec_n(&cui, &str_buf_c[0], mk_lang_countof(str_buf_c));
	mk_lang_test(str_len_c >= 1);
	mk_lang_test(str_len_c == str_len_a);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_a[0], ((mk_lang_types_usize_t)(str_len_c))) == 0);
}
#include "mk_lang_warning_msvc_pop.h"

#include "mk_lang_warning_msvc_push_c5045.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_cui_fuzz_printf_inl_defd_pr_printf_x(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d mk_lang_constexpr_init;
	mk_lang_types_usize_t s mk_lang_constexpr_init;
	mk_sl_cui_fuzz_printf_inl_defd_a_t bui mk_lang_constexpr_init;
	mk_sl_cui_fuzz_printf_inl_defd_c_t cui mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len_a mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_a[2 * mk_sl_cui_fuzz_printf_inl_defd_a_strlen_dec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t str_len_c mk_lang_constexpr_init;
	mk_lang_types_pchar_t str_buf_c[2 * mk_sl_cui_fuzz_printf_inl_defd_c_strlen_dec_v] mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;
	if(!(s >= sizeof(bui)))
	{
		return;
	}
	mk_sl_cui_fuzz_printf_inl_defd_a_from_buis_uchar_le(&bui, &d[0]);
	mk_sl_cui_fuzz_printf_inl_defd_c_from_buis_uchar_le(&cui, &d[0]);
	d += sizeof(bui);
	s -= sizeof(bui);
	str_len_a = snprintf(&str_buf_a[0], mk_lang_countof(str_buf_a), "%" mk_sl_cui_fuzz_printf_inl_defd_a_printf_length_modifier "x", bui);
	str_len_c = mk_sl_cui_fuzz_printf_inl_defd_c_to_str_hex_n(&cui, &str_buf_c[0], mk_lang_countof(str_buf_c));
	mk_lang_test(str_len_c >= 1);
	mk_lang_test(str_len_c == str_len_a);
	mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_buf_c[0], &str_buf_a[0], ((mk_lang_types_usize_t)(str_len_c))) == 0);
}
#include "mk_lang_warning_msvc_pop.h"


mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_fuzz_printf_inl_defd_fn(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size, mk_lang_types_bool_t const allow_all) mk_lang_noexcept
{
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
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_printf_inl_defd_pr_statics(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_printf_inl_defd_pr_printf_u(d, s); }
	if(all || curr == ((mk_lang_types_uint_t)(__LINE__))){ mk_sl_cui_fuzz_printf_inl_defd_pr_printf_x(d, s); }
}


#include "mk_sl_cui_fuzz_printf_inl_defu.h"


#endif
