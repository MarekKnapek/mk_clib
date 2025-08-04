#ifndef mk_include_guard_mk_lib_iip_time_c
#define mk_include_guard_mk_lib_iip_time_c
#include "mk_lib_iip_time.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint16.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_time.h"
#include "mk_win_dll_kernel_time.h"


#define mk_sl_cui_t_name mk_lib_iip_time_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_lib_iip_time_duration
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_constexpr_static_inline mk_lib_iip_time_timestamp_t const mk_lib_iip_time_k_max = { mk_sl_cui_uint64_c(0x00003a4aul, 0xa17b4000ul) }; /* 4001-01-01 */
mk_lang_constexpr_static_inline mk_lang_types_pchar_t const mk_lib_iip_time_k_fmt[] = "0000-00-00T00:00:00.000Z";


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_from_nt_timestamp(mk_lib_iip_time_timestamp_pt const iip_timestamp, mk_win_dll_kernel_time_file_time_pct const nt_timestamp) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul;
	mk_lib_iip_time_timestamp_t ta;
	mk_lib_iip_time_timestamp_t tb;
	mk_lang_types_uint_t tuis[2];

	mk_lang_assert(iip_timestamp);
	mk_lang_assert(nt_timestamp);

	tul = 116444736ul; mk_lib_iip_time_timestamp_from_bi_ulong(&ta, &tul);
	tul = 1000000000ul; mk_lib_iip_time_timestamp_from_bi_ulong(&tb, &tul);
	mk_lib_iip_time_timestamp_mul2_wrap_lo(&ta, &tb);
	tuis[0] = ((mk_lang_types_uint_t)(nt_timestamp->m_lo));
	tuis[1] = ((mk_lang_types_uint_t)(nt_timestamp->m_hi));
	mk_lib_iip_time_timestamp_from_buis_uint_le(&tb, &tuis[0]);
	mk_lib_iip_time_timestamp_sub2_wrap_cid_cod(&tb, &ta);
	tul = 10000ul; mk_lib_iip_time_timestamp_from_bi_ulong(&ta, &tul);
	mk_lib_iip_time_timestamp_div3_wrap(&tb, &ta, iip_timestamp);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_from_sl_timestamp(mk_lib_iip_time_timestamp_pt const iip_timestamp, mk_sl_time_timestamp_pct const sl_timestamp) mk_lang_noexcept
{
	mk_lang_types_ulong_t tul;
	mk_lib_iip_time_timestamp_t ta;
	mk_lib_iip_time_timestamp_t tb;

	mk_lang_assert(iip_timestamp);
	mk_lang_assert(sl_timestamp);

	tul = 116444736ul; mk_lib_iip_time_timestamp_from_bi_ulong(&ta, &tul);
	tul = 1000000000ul; mk_lib_iip_time_timestamp_from_bi_ulong(&tb, &tul);
	mk_lib_iip_time_timestamp_mul2_wrap_lo(&ta, &tb);
	tb.m_elements[0] = sl_timestamp->m_elements[0];
	mk_lib_iip_time_timestamp_sub2_wrap_cid_cod(&tb, &ta);
	tul = 10000ul; mk_lib_iip_time_timestamp_from_bi_ulong(&ta, &tul);
	mk_lib_iip_time_timestamp_div3_wrap(&tb, &ta, iip_timestamp);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_to_components(mk_lib_iip_time_timestamp_pct const timestamp, mk_lib_iip_time_components_pt const components) mk_lang_noexcept
{
	mk_sl_cui_uint64_pct milli_seconds_since_unix mk_lang_constexpr_init;
	mk_lang_types_slong_t tsl mk_lang_constexpr_init;
	mk_sl_cui_uint64_t ta mk_lang_constexpr_init;
	mk_sl_cui_uint64_t seconds_since_unix mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tb mk_lang_constexpr_init;
	mk_lang_types_slong_t milli_seconds_in_second mk_lang_constexpr_init;
	mk_sl_cui_uint64_t tc mk_lang_constexpr_init;
	mk_lang_types_slong_t days_since_unix mk_lang_constexpr_init;
	mk_lang_types_slong_t seconds_in_day mk_lang_constexpr_init;
	mk_lang_types_slong_t minutes_in_day mk_lang_constexpr_init;
	mk_lang_types_slong_t seconds_in_minute mk_lang_constexpr_init;
	mk_lang_types_slong_t hours_in_day mk_lang_constexpr_init;
	mk_lang_types_slong_t minutes_in_hour mk_lang_constexpr_init;
	mk_lang_types_slong_t days_since_jd mk_lang_constexpr_init;
	mk_lang_types_slong_t a mk_lang_constexpr_init;
	mk_lang_types_slong_t b mk_lang_constexpr_init;
	mk_lang_types_slong_t c mk_lang_constexpr_init;
	mk_lang_types_slong_t d mk_lang_constexpr_init;
	mk_lang_types_slong_t e mk_lang_constexpr_init;
	mk_lang_types_slong_t m mk_lang_constexpr_init;
	mk_lang_types_slong_t day mk_lang_constexpr_init;
	mk_lang_types_slong_t month mk_lang_constexpr_init;
	mk_lang_types_slong_t year mk_lang_constexpr_init;

	mk_lang_types_slong_t const k_milli_seconds_per_second = 1000l;
	mk_lang_types_slong_t const k_seconds_per_minute = 60l;
	mk_lang_types_slong_t const k_minutes_per_hour = 60l;
	mk_lang_types_slong_t const k_hours_per_day = 24l;
	mk_lang_types_slong_t const k_seconds_per_day = k_seconds_per_minute * k_minutes_per_hour * k_hours_per_day;
	mk_lang_types_slong_t const k_minutes_per_day = k_minutes_per_hour * k_hours_per_day;

	mk_lang_assert(timestamp);
	mk_lang_assert(components);

	if(mk_lib_iip_time_timestamp_le(timestamp, &mk_lib_iip_time_k_max))
	{
		milli_seconds_since_unix = &timestamp->m_elements[0];
		tsl = k_milli_seconds_per_second; mk_sl_cui_uint64_from_bi_slong(&ta, &tsl);
		mk_sl_cui_uint64_divmod4_wrap(milli_seconds_since_unix, &ta, &seconds_since_unix, &tb);
		mk_sl_cui_uint64_to_bi_slong(&tb, &milli_seconds_in_second);
		mk_lang_assert(milli_seconds_in_second >= 0l);
		mk_lang_assert(milli_seconds_in_second < k_milli_seconds_per_second);

		tsl = k_seconds_per_day; mk_sl_cui_uint64_from_bi_slong(&ta, &tsl);
		mk_sl_cui_uint64_divmod4_wrap(&seconds_since_unix, &ta, &tc, &tb);
		mk_sl_cui_uint64_to_bi_slong(&tc, &days_since_unix);
		mk_sl_cui_uint64_to_bi_slong(&tb, &seconds_in_day);
		mk_lang_assert(seconds_in_day >= 0l);
		mk_lang_assert(seconds_in_day < k_seconds_per_day);

		minutes_in_day = seconds_in_day / k_seconds_per_minute;
		seconds_in_minute = seconds_in_day - minutes_in_day * k_seconds_per_minute;
		mk_lang_assert(minutes_in_day >= 0l);
		mk_lang_assert(minutes_in_day < k_minutes_per_day);
		mk_lang_assert(seconds_in_minute >= 0l);
		mk_lang_assert(seconds_in_minute < k_seconds_per_minute);

		hours_in_day = minutes_in_day / k_minutes_per_hour;
		minutes_in_hour = minutes_in_day - hours_in_day * k_minutes_per_hour;
		mk_lang_assert(hours_in_day >= 0l);
		mk_lang_assert(hours_in_day < k_hours_per_day);
		mk_lang_assert(minutes_in_hour >= 0l);
		mk_lang_assert(minutes_in_hour < k_minutes_per_hour);

		days_since_jd = 2440588l + days_since_unix;
		a = days_since_jd + 32044l;
		b = (4l * a + 3l) / 146097l;
		c = a - (146097l * b) / 4l;
		d = (4l * c + 3l) / 1461l;
		e = c - (1461l * d) / 4l;
		m = (5l * e + 2l) / 153l;
		day = e - (153l * m + 2l) / 5l + 1l;
		month = m + 3l - 12l * (m / 10l);
		year = 100l * b + d - 4800l + (m / 10l);

		components->m_year = year;
		components->m_month = month;
		components->m_day = day;
		components->m_hour = hours_in_day;
		components->m_minute = minutes_in_hour;
		components->m_second = seconds_in_minute;
		components->m_milli_second = milli_seconds_in_second;
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

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_time_to_text(mk_lib_iip_time_timestamp_pct const timestamp, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lib_iip_time_components_t components mk_lang_constexpr_init;
	mk_lang_types_pchar_t buf[4] mk_lang_constexpr_init;
	mk_sl_cui_uint16_t ta mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t ptr mk_lang_constexpr_init;

	mk_lang_static_assert(mk_lib_iip_time_k_str_len == mk_lang_countstr(mk_lib_iip_time_k_fmt));

	mk_lang_assert(timestamp);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	if(str_len >= mk_lang_countstr(mk_lib_iip_time_k_fmt))
	{
		ptr = 0;
		mk_lib_iip_time_to_components(timestamp, &components);
		mk_lang_string_memcpy_pc_fn(&str_buf[0], &mk_lib_iip_time_k_fmt[0], mk_lang_countstr(mk_lib_iip_time_k_fmt));
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_year        ); len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 4 - len], &buf[0], ((mk_lang_types_usize_t)(len))); ptr += 4; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_month       ); len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 2 - len], &buf[0], ((mk_lang_types_usize_t)(len))); ptr += 2; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_day         ); len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 2 - len], &buf[0], ((mk_lang_types_usize_t)(len))); ptr += 2; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_hour        ); len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 2 - len], &buf[0], ((mk_lang_types_usize_t)(len))); ptr += 2; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_minute      ); len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 2 - len], &buf[0], ((mk_lang_types_usize_t)(len))); ptr += 2; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_second      ); len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 2 - len], &buf[0], ((mk_lang_types_usize_t)(len))); ptr += 2; ptr += 1;
		mk_sl_cui_uint16_from_bi_sint(&ta, &components.m_milli_second); len = mk_sl_cui_uint16_to_str_dec_n(&ta, &buf[0], mk_lang_countof(buf)); mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_countof(buf)); mk_lang_string_memcpy_pc_fn(&str_buf[ptr + 3 - len], &buf[0], ((mk_lang_types_usize_t)(len))); ptr += 3; ptr += 1;
		mk_lang_assert(ptr == mk_lang_countstr(mk_lib_iip_time_k_fmt));
		len = mk_lang_countstr(mk_lib_iip_time_k_fmt);
	}
	else
	{
		len = 0;
	}
	return len;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_timestamp_get_duration(mk_lib_iip_time_timestamp_pct const before, mk_lib_iip_time_timestamp_pct const after, mk_lib_iip_time_duration_pt const duration) mk_lang_noexcept
{
	mk_sl_cui_uint64_t b;
	mk_sl_cui_uint64_t a;
	mk_sl_cui_uint64_t d;

	mk_lang_assert(before);
	mk_lang_assert(after);
	mk_lang_assert(duration);

	mk_lib_iip_time_timestamp_to_base(before, &b);
	mk_lib_iip_time_timestamp_to_base(after, &a);
	mk_sl_cui_uint64_sub3_wrap_cid_cod(&a, &b, &d);
	mk_lib_iip_time_duration_from_base(duration, &d);
}

mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_get_now(mk_lib_iip_time_timestamp_pt const timestamp) mk_lang_noexcept
{
	mk_win_dll_kernel_time_file_time_t file_time;

	mk_lang_assert(timestamp);

	mk_win_dll_kernel_time_get_system_time_precise_as_file_time(&file_time);
	mk_lib_iip_time_from_nt_timestamp(timestamp, &file_time);
}


#endif
