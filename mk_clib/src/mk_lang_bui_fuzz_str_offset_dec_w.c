#include "mk_lang_bui_fuzz_str_offset_dec_w.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"


#define mk_lang_bui_t_name mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint
#define mk_lang_bui_t_base uint
#define mk_lang_bui_t_str_style 1003
#define mk_lang_bui_t_inline 0
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_bui_fuzz_str_offset_dec_w_uint_to_str_different(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_t bui_a mk_lang_constexpr_init;
	mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_t bui_b mk_lang_constexpr_init;
	mk_lang_types_sint_t len_a mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_a[mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_b[mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_strlendec_v] mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	if(!(size == 2 * sizeof(mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_t)))
	{
		return;
	}
	mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_from_buis_uchar_le(&bui_a, &data[0 * sizeof(mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_t)]);
	mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_from_buis_uchar_le(&bui_b, &data[1 * sizeof(mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_t)]);
	if(!mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_eq(&bui_a, &bui_b))
	{
		len_a = mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_to_str_dec_w(&bui_a, &str_a[0], mk_lang_countof(str_a)); mk_lang_test(len_a >= 1); mk_lang_test(len_a <= mk_lang_countof(str_a));
		len_b = mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_to_str_dec_w(&bui_b, &str_b[0], mk_lang_countof(str_b)); mk_lang_test(len_b >= 1); mk_lang_test(len_b <= mk_lang_countof(str_b));
		mk_lang_test(len_a != len_b || mk_lang_string_memcmp_wc_fn(&str_a[0], &str_b[0], len_a) != 0);
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_bui_fuzz_str_offset_dec_w_uint_to_str_and_back(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_t bui_a mk_lang_constexpr_init;
	mk_lang_types_sint_t len_a mk_lang_constexpr_init;
	mk_lang_types_wchar_t str[mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_t bui_b mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	if(!(size == sizeof(mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_t)))
	{
		return;
	}
	mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_from_buis_uchar_le(&bui_a, data);
	len_a = mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_to_str_dec_w(&bui_a, &str[0], mk_lang_countof(str));
	mk_lang_test(len_a >= 1);
	mk_lang_test(len_a <= mk_lang_countof(str));
	len_b = mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_from_str_dec_w(&bui_b, &str[0], len_a);
	mk_lang_test(len_b == len_a);
	mk_lang_test(mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_eq(&bui_b, &bui_a));
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_lang_bui_fuzz_str_offset_dec_w_uint_from_str_and_back(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_wchar_t str_a[4 * mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_strlendec_v] mk_lang_constexpr_init;
	mk_lang_types_sint_t sz mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t len_a mk_lang_constexpr_init;
	mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_t bui mk_lang_constexpr_init;
	mk_lang_types_sint_t len_b mk_lang_constexpr_init;
	mk_lang_types_wchar_t str_b[mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_strlendec_v] mk_lang_constexpr_init;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	if(!(size >= 0 && size <= mk_lang_countof(str_a)))
	{
		return;
	}
	sz = ((mk_lang_types_sint_t)(size));
	for(i = 0; i != sz; ++i)
	{
		str_a[i] = ((mk_lang_types_wchar_t)(data[i]));
	}
	len_a = mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_from_str_dec_w(&bui, &str_a[0], sz);
	if(len_a >= 1)
	{
		len_b = mk_lang_bui_fuzz_str_offset_dec_w_zzz_uint_to_str_dec_w(&bui, &str_b[0], mk_lang_countof(str_b));
		mk_lang_assert(len_b >= 1);
		mk_lang_assert(len_b <= mk_lang_countof(str_b));
		mk_lang_test(len_b <= len_a);
		mk_lang_test(mk_lang_string_memcmp_wc_fn(&str_b[0], &str_a[len_a - len_b], len_b) == 0);
	}
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lang_bui_fuzz_str_offset_dec_w(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	mk_lang_bui_fuzz_str_offset_dec_w_uint_to_str_different(data, size);
	mk_lang_bui_fuzz_str_offset_dec_w_uint_to_str_and_back(data, size);
	mk_lang_bui_fuzz_str_offset_dec_w_uint_from_str_and_back(data, size);
}
