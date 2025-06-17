#ifndef mk_include_guard_mk_lib_iip_time_c
#define mk_include_guard_mk_lib_iip_time_c
#include "mk_lib_iip_time.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint64.h"
#include "mk_win_dll_kernel_time.h"


mk_lang_constexpr_static_inline mk_sl_cui_uint64_t const mk_lib_iip_time_k_components_max = mk_sl_cui_uint64_c(0x000017d2ul, 0x5b8ae400ul);
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_time_k_text_fmt[] = "0000-00-00T00:00:00.000Z";


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_to_components(mk_sl_cui_uint64_pct const time, mk_lib_iip_time_components_pt const components) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t s_since_unix mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tc mk_lang_constexpr_init;
	mk_lang_types_sint_t ms_in_s mk_lang_constexpr_init;
	mk_sl_cui_uint64_t d_since_unix_big mk_lang_constexpr_init;
	mk_lang_types_slong_t d_since_unix mk_lang_constexpr_init;
	mk_lang_types_slong_t s_in_d mk_lang_constexpr_init;
	mk_lang_types_slong_t m_in_d mk_lang_constexpr_init;
	mk_lang_types_slong_t s_in_m mk_lang_constexpr_init;
	mk_lang_types_slong_t h_in_d mk_lang_constexpr_init;
	mk_lang_types_slong_t m_in_h mk_lang_constexpr_init;
	mk_lang_types_slong_t d_since_c400_march mk_lang_constexpr_init;
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

	mk_lang_types_slong_t const k_d_in_c400 = 400l * 365l + 400l / 4l - 400l / 100l + 400l / 400l;
	mk_lang_types_slong_t const k_d_unix_to_c400_march = 10957l + 31l + 29l;
	mk_lang_types_slong_t const k_d_in_c100 = 100l * 365l + 100l / 4l - 100l / 100l;
	mk_lang_types_slong_t const k_d_in_c4 = 4l * 365l + 1l;
	mk_lang_types_slong_t const k_d_in_c1 = 1l * 365l + 0l;
	mk_lang_types_sint_t const k_lens[] = {31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29};

	mk_lang_assert(time);
	mk_lang_assert(components);

	if(mk_sl_cui_uint64_le(time, &mk_lib_iip_time_k_components_max))
	{
		tsi = 1 * 1000; mk_sl_cui_uint64_from_bi_sint(&ta, &tsi);
		mk_sl_cui_uint64_divmod4_wrap(time, &ta, &s_since_unix, &tc);
		mk_sl_cui_uint64_to_bi_sint(&tc, &ms_in_s);

		tsi = 1 * 24 * 60 * 60; mk_sl_cui_uint64_from_bi_sint(&ta, &tsi);
		mk_sl_cui_uint64_divmod4_wrap(&s_since_unix, &ta, &d_since_unix_big, &tc);
		mk_sl_cui_uint64_to_bi_slong(&d_since_unix_big, &d_since_unix);
		mk_sl_cui_uint64_to_bi_slong(&tc, &s_in_d);

		m_in_d = s_in_d / (1 * 60);
		s_in_m = s_in_d % (1 * 60);

		h_in_d = m_in_d / (1 * 60);
		m_in_h = m_in_d % (1 * 60);

		d_since_c400_march = d_since_unix + (k_d_in_c400 - k_d_unix_to_c400_march);

		c400 = d_since_c400_march / k_d_in_c400;
		d_in_c400 = d_since_c400_march % k_d_in_c400;

		c100 = d_in_c400 / k_d_in_c100;
		d_in_c100 = d_in_c400 % k_d_in_c100;

		c4 = d_in_c100 / k_d_in_c4;
		d_in_c4 = d_in_c100 % k_d_in_c4;

		c1 = 0;
		d_in_c4r = d_in_c4;
		if(d_in_c4r > k_d_in_c1)
		{
			++c1;
			d_in_c4r -= k_d_in_c1;
			if(d_in_c4r > k_d_in_c1)
			{
				++c1;
				d_in_c4r -= k_d_in_c1;
				if(d_in_c4r > k_d_in_c1)
				{
					++c1;
					d_in_c4r -= k_d_in_c1;
				}
			}
		}
		d_in_c1 = d_in_c4r;
		d_in_y = d_in_c1;
		m_in_y = 0;
		while(d_in_y >= k_lens[m_in_y])
		{
			d_in_y -= k_lens[m_in_y];
			++m_in_y;
		}
		d_in_m = d_in_y + 1;
		m_in_y += 2;
		if(m_in_y >= 12)
		{
			m_in_y -= 12;
			++c1;
		}
		++m_in_y;
		y = 1600 + c400 * 400 + c100 * 100 + c4 * 4 + c1 * 1;
		if(m_in_y == 2 && d_in_m == 29 && !((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
		{
			d_in_m = 1;
			m_in_y = 3;
		}
		mk_lang_assert(y >= 1600 && y <= 2800);
		mk_lang_assert(m_in_y >= 1 && m_in_y <= 12);
		mk_lang_assert(d_in_m >= 1 && d_in_m <= 31); mk_lang_assert(d_in_m >= 1 && d_in_m <= k_lens[((m_in_y + 12) - 3) % 12]);
		mk_lang_assert(h_in_d >= 0 && h_in_d < 24);
		mk_lang_assert(m_in_h >= 0 && m_in_h < 60);
		mk_lang_assert(s_in_m >= 0 && s_in_m < 60);
		mk_lang_assert(ms_in_s >= 0 && ms_in_s < 1000);
		components->m_year = y;
		components->m_month = m_in_y;
		components->m_day = d_in_m;
		components->m_hour = h_in_d;
		components->m_minute = m_in_h;
		components->m_second = s_in_m;
		components->m_milli_second = ms_in_s;
	}
	else
	{
		components->m_year = 0;
		components->m_month = 0;
		components->m_day = 0;
		components->m_hour = 0;
		components->m_minute = 0;
		components->m_second = 0;
		components->m_milli_second = 0;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_to_text(mk_sl_cui_uint64_pct const time, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lib_iip_time_components_t components mk_lang_constexpr_init;
	mk_sl_cui_uint16_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_pchar_t buf[mk_sl_cui_uint16_strlen_dec_v] mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lang_countstr(mk_lib_iip_time_k_text_fmt) == 24);

	mk_lang_assert(time);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(out_len);

	if(str_len >= mk_lang_countstr(mk_lib_iip_time_k_text_fmt))
	{
		mk_lib_iip_time_to_components(time, &components);
		mk_lang_string_memcpy_pc_fn(&str_buf[0], &mk_lib_iip_time_k_text_fmt[0], mk_lang_countstr(mk_lib_iip_time_k_text_fmt));
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_year)        ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&str_buf[ 0 + 4 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_month)       ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&str_buf[ 5 + 2 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_day)         ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&str_buf[ 8 + 2 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_hour)        ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&str_buf[11 + 2 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_minute)      ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&str_buf[14 + 2 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_second)      ; len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&str_buf[17 + 2 - len], &buf[0], len);
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_milli_second); len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_string_memcpy_pc_fn(&str_buf[20 + 3 - len], &buf[0], len);
		*out_len = mk_lang_countstr(mk_lib_iip_time_k_text_fmt);
	}
	else
	{
		*out_len = 0;
	}
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_get_now(mk_sl_cui_uint64_pt const time) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul;
	mk_sl_cui_uint64_t tu64a;
	mk_sl_cui_uint64_t tu64b;
	mk_win_dll_kernel_time_file_time_t file_time;
	mk_lang_types_uint_t tuis[2];

	mk_lang_assert(time);

	tul = 116444736ul; mk_sl_cui_uint64_from_bi_ulong(&tu64a, &tul);
	tul = 1000000000ul; mk_sl_cui_uint64_from_bi_ulong(&tu64b, &tul);
	mk_sl_cui_uint64_mul2_wrap_lo(&tu64a, &tu64b);
	mk_win_dll_kernel_time_get_system_time_precise_as_file_time(&file_time);
	tuis[0] = ((mk_lang_types_uint_t)(file_time.m_lo));
	tuis[1] = ((mk_lang_types_uint_t)(file_time.m_hi));
	mk_sl_cui_uint64_from_buis_uint_le(&tu64b, &tuis[0]);
	mk_sl_cui_uint64_sub2_wrap_cid_cod(&tu64b, &tu64a);
	tul = 10000ul; mk_sl_cui_uint64_from_bi_ulong(&tu64a, &tul);
	mk_sl_cui_uint64_div3_wrap(&tu64b, &tu64a, time);
}


#endif
