#include "mk_lang_bui_fuzz_str_offset_oct_n.h"

#include "mk_lang_assert.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"


#define mk_lang_bui_t_name mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint
#define mk_lang_bui_t_base uint
#define mk_lang_bui_t_str_style 1003
#define mk_lang_bui_t_inline 0
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"


#if mk_lang_version_at_least_cpp_17 || mk_lang_version_at_least_msvc_cpp_17 || (defined __cpp_lib_to_chars && __cpp_lib_to_chars >= 201611l)
#include <charconv>
#include <system_error>
#endif


static mk_lang_inline mk_lang_types_void_t mk_lang_bui_fuzz_str_offset_oct_n_uint_to_str_different(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t bui_a;
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t bui_b;
	mk_lang_types_sint_t len_a;
	mk_lang_types_pchar_t str_a[mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_strlenoct_v];
	mk_lang_types_sint_t len_b;
	mk_lang_types_pchar_t str_b[mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_strlenoct_v];

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	if(!(size == 2 * sizeof(mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t)))
	{
		return;
	}
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_from_buis_uchar_le(&bui_a, &data[0 * sizeof(mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t)]);
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_from_buis_uchar_le(&bui_b, &data[1 * sizeof(mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t)]);
	if(!mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_eq(&bui_a, &bui_b))
	{
		len_a = mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_to_str_oct_n(&bui_a, &str_a[0], mk_lang_countof(str_a)); mk_lang_test(len_a >= 1); mk_lang_test(len_a <= mk_lang_countof(str_a));
		len_b = mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_to_str_oct_n(&bui_b, &str_b[0], mk_lang_countof(str_b)); mk_lang_test(len_b >= 1); mk_lang_test(len_b <= mk_lang_countof(str_b));
		mk_lang_test(len_a != len_b || mk_lang_string_memcmp_pc_fn(&str_a[0], &str_b[0], len_a) != 0);
	}
}

static mk_lang_inline mk_lang_types_void_t mk_lang_bui_fuzz_str_offset_oct_n_uint_to_str_and_back(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t bui_a;
	mk_lang_types_sint_t len_a;
	mk_lang_types_pchar_t str[mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_strlenoct_v];
	mk_lang_types_sint_t len_b;
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t bui_b;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	if(!(size == sizeof(mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t)))
	{
		return;
	}
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_from_buis_uchar_le(&bui_a, data);
	len_a = mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_to_str_oct_n(&bui_a, &str[0], mk_lang_countof(str));
	mk_lang_test(len_a >= 1);
	mk_lang_test(len_a <= mk_lang_countof(str));
	len_b = mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_from_str_oct_n(&bui_b, &str[0], len_a);
	mk_lang_test(len_b == len_a);
	mk_lang_test(mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_eq(&bui_b, &bui_a));
}

static mk_lang_inline mk_lang_types_void_t mk_lang_bui_fuzz_str_offset_oct_n_uint_from_str_and_back(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_pchar_t str_a[4 * mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_strlenoct_v];
	mk_lang_types_sint_t sz;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t len_a;
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t bui;
	mk_lang_types_sint_t len_b;
	mk_lang_types_pchar_t str_b[mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_strlenoct_v];

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	if(!(size >= 0 && size <= mk_lang_countof(str_a)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str_a[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	len_a = mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_from_str_oct_n(&bui, &str_a[0], sz);
	if(len_a >= 1)
	{
		len_b = mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_to_str_oct_n(&bui, &str_b[0], mk_lang_countof(str_b));
		mk_lang_assert(len_b >= 1);
		mk_lang_assert(len_b <= mk_lang_countof(str_b));
		mk_lang_test(len_b <= len_a);
		mk_lang_test(mk_lang_string_memcmp_pc_fn(&str_b[0], &str_a[len_a - len_b], len_b) == 0);
	}
}

static mk_lang_inline mk_lang_types_void_t mk_lang_bui_fuzz_str_offset_oct_n_uint_from_str_vs_cpp_a(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
#if mk_lang_version_at_least_cpp_17 || mk_lang_version_at_least_msvc_cpp_17 || (defined __cpp_lib_to_chars && __cpp_lib_to_chars >= 201611l)
	mk_lang_types_pchar_t str_a[4 * mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_strlenoct_v];
	mk_lang_types_sint_t sz;
	mk_lang_types_sint_t i;
	std::from_chars_result res;
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t bui_a;
	mk_lang_types_sint_t len_a;
	mk_lang_types_sint_t len_b;
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t bui_b;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	if(!(size >= 0 && size <= mk_lang_countof(str_a)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str_a[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	res = std::from_chars(&str_a[0], &str_a[sz], bui_a, 8);
	if(res.ec == std::errc{})
	{
		len_a = ((mk_lang_types_sint_t)(res.ptr - &str_a[0]));
		len_b = mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_from_str_oct_n(&bui_b, &str_a[0], len_a);
		mk_lang_test(len_b >= 1);
		mk_lang_assert(len_b <= len_a);
		mk_lang_test(len_b == len_a);
		mk_lang_test(mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_eq(&bui_b, &bui_a));
	}
#else
	((mk_lang_types_void_t)(data));
	((mk_lang_types_void_t)(size));
#endif
}

static mk_lang_inline mk_lang_types_void_t mk_lang_bui_fuzz_str_offset_oct_n_uint_from_str_vs_cpp_b(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
#if mk_lang_version_at_least_cpp_17 || mk_lang_version_at_least_msvc_cpp_17 || (defined __cpp_lib_to_chars && __cpp_lib_to_chars >= 201611l)
	mk_lang_types_pchar_t str_a[4 * mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_strlenoct_v];
	mk_lang_types_sint_t sz;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t len_a;
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t bui_a;
	std::from_chars_result res;
	mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_t bui_b;
	mk_lang_types_sint_t len_b;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	if(!(size >= 0 && size <= mk_lang_countof(str_a)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str_a[i] = ((mk_lang_types_pchar_t)(data[i]));
	}
	len_a = mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_from_str_oct_n(&bui_a, &str_a[0], sz);
	if(len_a >= 1)
	{
		mk_lang_assert(len_a <= sz);
		res = std::from_chars(&str_a[0], &str_a[len_a], bui_b, 8);
		mk_lang_test(res.ec == std::errc{});
		len_b = ((mk_lang_types_sint_t)(res.ptr - &str_a[0]));
		mk_lang_test(len_b == len_a);
		mk_lang_test(mk_lang_bui_fuzz_str_offset_oct_n_zzz_uint_eq(&bui_b, &bui_a));
	}
#else
	((mk_lang_types_void_t)(data));
	((mk_lang_types_void_t)(size));
#endif
}


mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_fuzz_str_offset_oct_n(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_bui_fuzz_str_offset_oct_n_uint_to_str_different(data, size);
	mk_lang_bui_fuzz_str_offset_oct_n_uint_to_str_and_back(data, size);
	mk_lang_bui_fuzz_str_offset_oct_n_uint_from_str_and_back(data, size);
	mk_lang_bui_fuzz_str_offset_oct_n_uint_from_str_vs_cpp_a(data, size);
	mk_lang_bui_fuzz_str_offset_oct_n_uint_from_str_vs_cpp_b(data, size);
}
