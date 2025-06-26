#ifndef mk_include_guard_mk_sl_time_c
#define mk_include_guard_mk_sl_time_c
#include "mk_sl_time.h"

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint64.h"
#include "mk_win_dll_kernel_time.h"


#define mk_sl_cui_t_name mk_sl_time_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const mk_sl_time_k_max = mk_sl_cui_uint64_c(0x0a82b522ul, 0xb3b28000ul);
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_sl_time_k_fmt[] = "0000-00-00T00:00:00.0000000Z";


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_time_to_components(mk_sl_time_timestamp_pct const timestamp, mk_sl_time_components_pt const components) mk_lang_noexcept
{
	mk_sl_cui_uint64_pct time_u64 mk_lang_constexpr_init;
	mk_lang_types_slong_t tsl mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t s_since_nt mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tc mk_lang_constexpr_init;
	mk_lang_types_slong_t hns_in_s mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint64_t d_since_nt_big mk_lang_constexpr_init;
	mk_lang_types_slong_t d_since_nt mk_lang_constexpr_init;
	mk_lang_types_slong_t s_in_d mk_lang_constexpr_init;
	mk_lang_types_slong_t m_in_d mk_lang_constexpr_init;
	mk_lang_types_slong_t s_in_m mk_lang_constexpr_init;
	mk_lang_types_slong_t h_in_d mk_lang_constexpr_init;
	mk_lang_types_slong_t m_in_h mk_lang_constexpr_init;
	mk_lang_types_slong_t c400 mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_c400 mk_lang_constexpr_init;
	mk_lang_types_slong_t c100 mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_c100 mk_lang_constexpr_init;
	mk_lang_types_slong_t c4 mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_c4 mk_lang_constexpr_init;
	mk_lang_types_slong_t c1 mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_c4r mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_c1 mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_y mk_lang_constexpr_init;
	mk_lang_types_slong_t m_in_y mk_lang_constexpr_init;
	mk_lang_types_slong_t d_in_m mk_lang_constexpr_init;
	mk_lang_types_slong_t y mk_lang_constexpr_init;
	mk_lang_types_bool_t leap mk_lang_constexpr_init;

	mk_lang_types_slong_t const k_d_in_c1 = 1l * 365l;
	mk_lang_types_slong_t const k_d_in_c4 = (4l * k_d_in_c1) + 1l;
	mk_lang_types_slong_t const k_d_in_c100 = (100l * k_d_in_c1) + ((100l / 4l) * 1l) - ((100l / 100l) * 1l);
	mk_lang_types_slong_t const k_d_in_c400 = (400l * k_d_in_c1) + ((400l / 4l) * 1l) - ((400l / 100l) * 1l) + ((400l / 400l) * 1l);
	mk_lang_types_sint_t const k_lens_a[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	mk_lang_types_sint_t const k_lens_b[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	mk_lang_assert(timestamp);
	mk_lang_assert(components);

	time_u64 = &timestamp->m_elements[0];
	if(mk_sl_cui_uint64_le(time_u64, &mk_sl_time_k_max))
	{
		tsl = 10l * 1000l * 1000l; mk_sl_cui_uint64_from_bi_slong(&ta, &tsl);
		mk_sl_cui_uint64_divmod4_wrap(time_u64, &ta, &s_since_nt, &tc);
		mk_sl_cui_uint64_to_bi_slong(&tc, &hns_in_s);

		tsi = 1 * 24 * 60 * 60; mk_sl_cui_uint64_from_bi_sint(&ta, &tsi);
		mk_sl_cui_uint64_divmod4_wrap(&s_since_nt, &ta, &d_since_nt_big, &tc);
		mk_sl_cui_uint64_to_bi_slong(&d_since_nt_big, &d_since_nt);
		mk_sl_cui_uint64_to_bi_slong(&tc, &s_in_d);

		m_in_d = s_in_d / 60;
		s_in_m = s_in_d - m_in_d * 60;

		h_in_d = m_in_d / 60;
		m_in_h = m_in_d - h_in_d * 60;

		c400 = d_since_nt / k_d_in_c400;
		d_in_c400 = d_since_nt - c400 * k_d_in_c400;

		c100 = d_in_c400 / k_d_in_c100;
		c100 = mk_lang_min(c100, 3);
		d_in_c100 = d_in_c400 - c100 * k_d_in_c100;

		c4 = d_in_c100 / k_d_in_c4;
		d_in_c4 = d_in_c100 % k_d_in_c4;

		c1 = 0;
		d_in_c4r = d_in_c4;
		if(d_in_c4r >= k_d_in_c1)
		{
			++c1;
			d_in_c4r -= k_d_in_c1;
			if(d_in_c4r >= k_d_in_c1)
			{
				++c1;
				d_in_c4r -= k_d_in_c1;
				if(d_in_c4r >= k_d_in_c1)
				{
					++c1;
					d_in_c4r -= k_d_in_c1;
				}
			}
		}
		mk_lang_assert(d_in_c4r >= 0 && d_in_c4r <= k_d_in_c1);
		y = 1601 + c400 * 400 + c100 * 100 + c4 * 4 + c1 * 1;
		leap = ((((y % 4) == 0) && ((y % 100) != 0)) || ((y % 400) == 0));
		d_in_c1 = d_in_c4r;
		d_in_y = d_in_c1;
		m_in_y = 0;
		while(d_in_y >= ((!leap) ? (k_lens_a[m_in_y]) : (k_lens_b[m_in_y])))
		{
			d_in_y -= ((!leap) ? (k_lens_a[m_in_y]) : (k_lens_b[m_in_y]));
			++m_in_y;
		}
		d_in_m = d_in_y + 1;
		++m_in_y;
		mk_lang_assert(y >= 1600 && y <= 4001);
		mk_lang_assert(m_in_y >= 1 && m_in_y <= 12);
		mk_lang_assert(d_in_m >= 1 && d_in_m <= 31); mk_lang_assert(d_in_m >= 1 && d_in_m <= ((!leap) ? (k_lens_a[m_in_y - 1]) : (k_lens_b[m_in_y - 1])));
		mk_lang_assert(h_in_d >= 0 && h_in_d < 24);
		mk_lang_assert(m_in_h >= 0 && m_in_h < 60);
		mk_lang_assert(s_in_m >= 0 && s_in_m < 60);
		mk_lang_assert(hns_in_s >= 0l && hns_in_s < 10l * 1000l * 1000l);
		components->m_year = y;
		components->m_month = m_in_y;
		components->m_day = d_in_m;
		components->m_hour = h_in_d;
		components->m_minute = m_in_h;
		components->m_second = s_in_m;
		components->m_hundred_nano_second = hns_in_s;
	}
	else
	{
		components->m_year = 0;
		components->m_month = 0;
		components->m_day = 0;
		components->m_hour = 0;
		components->m_minute = 0;
		components->m_second = 0;
		components->m_hundred_nano_second = 0l;
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_time_timestamp_to_text(mk_sl_time_timestamp_pct const timestamp, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_sl_time_components_t components mk_lang_constexpr_init;
	mk_lang_types_pchar_t buf[7] mk_lang_constexpr_init;
	mk_sl_cui_uint16_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;
	mk_sl_cui_uint32_t tb mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_time_k_str_len == mk_lang_countstr(mk_sl_time_k_fmt));

	mk_lang_assert(timestamp);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(str_len >= mk_lang_countstr(mk_sl_time_k_fmt))
	{
		ptr = 0;
		mk_sl_time_to_components(timestamp, &components);
		mk_lang_string_memcpy_pc_fn(&str_buf[0], &mk_sl_time_k_fmt[0], mk_lang_countstr(mk_sl_time_k_fmt));
		mk_sl_cui_uint16_from_bi_sint (&ta, &components.m_year)               ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 4 - len], &buf[0], len); ptr += 4; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint (&ta, &components.m_month)              ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 2 - len], &buf[0], len); ptr += 2; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint (&ta, &components.m_day)                ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 2 - len], &buf[0], len); ptr += 2; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint (&ta, &components.m_hour)               ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 2 - len], &buf[0], len); ptr += 2; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint (&ta, &components.m_minute)             ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 2 - len], &buf[0], len); ptr += 2; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint (&ta, &components.m_second)             ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 2 - len], &buf[0], len); ptr += 2; ptr += 1;
		mk_sl_cui_uint32_from_bi_slong(&tb, &components.m_hundred_nano_second); len = mk_sl_cui_uint32_to_str_dec_n(&tb, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 7 - len], &buf[0], len); ptr += 7; ptr += 1;
		mk_lang_assert(ptr == mk_lang_countstr(mk_sl_time_k_fmt));
		len = mk_lang_countstr(mk_sl_time_k_fmt);
	}
	else
	{
		len = 0;
	}
	return len;
}

mk_lang_jumbo mk_lang_types_void_t mk_sl_time_timestamp_get_now(mk_sl_time_timestamp_pt const timestamp) mk_lang_noexcept
{
	mk_win_dll_kernel_time_file_time_t file_time;
	mk_lang_types_uint_t tuis[2];

	mk_lang_static_assert(sizeof(file_time.m_lo) == sizeof(tuis[0]));
	mk_lang_static_assert(sizeof(file_time.m_hi) == sizeof(tuis[1]));
	mk_lang_static_assert(mk_lang_alignof(mk_win_base_dword_t) == mk_lang_alignof(mk_lang_types_uint_t));

	mk_lang_assert(timestamp);

	mk_win_dll_kernel_time_get_system_time_precise_as_file_time(&file_time);
	tuis[0] = ((mk_lang_types_uint_t)(file_time.m_lo));
	tuis[1] = ((mk_lang_types_uint_t)(file_time.m_hi));
	mk_sl_time_timestamp_from_buis_uint_le(timestamp, &tuis[0]);
}


#endif
