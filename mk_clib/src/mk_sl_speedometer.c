#ifndef mk_include_guard_mk_sl_speedometer_c
#define mk_include_guard_mk_sl_speedometer_c
#include "mk_sl_speedometer.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_tchar.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_fxp_128.h"
#include "mk_sl_stopwatch.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_speedometer_pr_construct(mk_sl_speedometer_pt const speedometer) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_stopwatch_timestamp_t now;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) == mk_lang_countof(speedometer->m_timestamps));
	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) >= 2);
	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) <= 16);

	mk_lang_assert(speedometer);

	err = mk_sl_stopwatch_timestamp_get_now(&now); mk_lang_check_rereturn(err);
	n = mk_lang_countof(speedometer->m_amounts);
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint64_set_zero(&speedometer->m_amounts[(speedometer->m_idx + i) % mk_lang_countof(speedometer->m_amounts)]);
		speedometer->m_timestamps[(speedometer->m_idx + i) % mk_lang_countof(speedometer->m_timestamps)] = now;
	}
	speedometer->m_lat_append = now;
	speedometer->m_lat_reported = now;
	speedometer->m_idx = 0;
	speedometer->m_tick = 0;
	speedometer->m_scale = ((mk_lang_types_uchar_t)(mk_sl_speedometer_scale_e_b));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_speedometer_pr_destroy(mk_sl_speedometer_pt const speedometer) mk_lang_noexcept
{
	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) == mk_lang_countof(speedometer->m_timestamps));
	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) >= 2);
	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) <= 16);

	mk_lang_assert(speedometer);

	((mk_lang_types_void_t)(speedometer));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_speedometer_pr_append(mk_sl_speedometer_pt const speedometer, mk_lang_types_sint_t const amount) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_stopwatch_timestamp_t timestamp_now;
	mk_sl_cui_uint64_t cui_amount;
	mk_sl_stopwatch_timestamp_pt db_timestamp;
	mk_sl_cui_uint64_pt db_amount;
	mk_sl_stopwatch_duration_t time_diff_dur;
	mk_lang_types_ulong_t time_treshold_ul;
	mk_sl_stopwatch_duration_t time_treshold_dur;

	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) == mk_lang_countof(speedometer->m_timestamps));
	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) >= 2);
	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) <= 16);

	mk_lang_assert(speedometer);
	mk_lang_assert(amount >= 0);

	err = mk_sl_stopwatch_timestamp_get_now(&timestamp_now); mk_lang_check_rereturn(err);
	mk_sl_cui_uint64_from_bi_sint(&cui_amount, &amount);
	db_timestamp = &speedometer->m_timestamps[(speedometer->m_idx + 0) % mk_lang_countof(speedometer->m_timestamps)];
	db_amount = &speedometer->m_amounts[(speedometer->m_idx + 0) % mk_lang_countof(speedometer->m_amounts)];
	mk_sl_stopwatch_timestamp_get_duration(db_timestamp, &timestamp_now, &time_diff_dur);
	time_treshold_ul = 333ul * 1000ul * 1000ul; mk_sl_stopwatch_duration_from_bi_ulong(&time_treshold_dur, &time_treshold_ul);
	if(mk_sl_stopwatch_duration_le(&time_diff_dur, &time_treshold_dur))
	{
		mk_sl_cui_uint64_add2_wrap_cid_cod(db_amount, &cui_amount);
	}
	else
	{
		speedometer->m_idx += 1;
		db_timestamp = &speedometer->m_timestamps[(speedometer->m_idx + 0) % mk_lang_countof(speedometer->m_timestamps)];
		db_amount = &speedometer->m_amounts[(speedometer->m_idx + 0) % mk_lang_countof(speedometer->m_amounts)];
		*db_timestamp = timestamp_now;
		*db_amount = cui_amount;
	}
	speedometer->m_lat_append = timestamp_now;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_speedometer_pr_report(mk_sl_speedometer_pt const speedometer, mk_lang_tchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const reported, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	mk_lang_tchar_pt ptr;
	mk_lang_types_sint_t rem;
	mk_sl_stopwatch_duration_t time_diff_dur;
	mk_lang_types_ulong_t time_treshold_ul;
	mk_sl_stopwatch_duration_t time_treshold_dur;
	mk_lang_types_bool_t want;
	mk_lang_types_uint_t kilobyte_ui;
	mk_sl_fxp_128_64_64_t kilobyte_fxp;
	mk_lang_types_uint_t speed_treshold_ui;
	mk_sl_fxp_128_64_64_t speed_treshold_fxp;
	mk_sl_cui_uint64_t amount_cui;
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_sl_fxp_128_64_64_t amount_fxp;
	mk_sl_fxp_128_64_64_t time_diff_fxp_nanos;
	mk_lang_types_ulong_t second_ul;
	mk_sl_fxp_128_64_64_t second_fxp;
	mk_sl_fxp_128_64_64_t time_diff_fxp_seconds;
	mk_sl_fxp_128_64_64_t speed_fxp;
	mk_lang_types_sint_t len;
	mk_lang_tchar_pct unit_ptr;
	mk_lang_types_sint_t unit_len;

	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) == mk_lang_countof(speedometer->m_timestamps));
	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) >= 2);
	mk_lang_static_assert(mk_lang_countof(speedometer->m_amounts) <= 16);

	mk_lang_assert(speedometer);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);
	mk_lang_assert(reported);
	mk_lang_assert(out_len);

	*reported = mk_lang_false;
	ptr = str_buf;
	rem = str_len;
	mk_sl_stopwatch_timestamp_get_duration(&speedometer->m_lat_reported, &speedometer->m_lat_append, &time_diff_dur);
	time_treshold_ul = 333ul * 1000ul * 1000ul; mk_sl_stopwatch_duration_from_bi_ulong(&time_treshold_dur, &time_treshold_ul);
	want = mk_sl_stopwatch_duration_gt(&time_diff_dur, &time_treshold_dur);
	if(want)
	{
		speedometer->m_lat_reported = speedometer->m_lat_append;
		++speedometer->m_tick;
		kilobyte_ui = 1ul * 1024ul; mk_sl_fxp_128_64_64_from_bi_uint(&kilobyte_fxp, &kilobyte_ui);
		speed_treshold_ui = 999u; mk_sl_fxp_128_64_64_from_bi_uint(&speed_treshold_fxp, &speed_treshold_ui);
		amount_cui = speedometer->m_amounts[(speedometer->m_idx + 0) % mk_lang_countof(speedometer->m_amounts)];
		n = mk_lang_countof(speedometer->m_amounts);
		for(i = 1; i != n; ++i)
		{
			mk_sl_cui_uint64_add2_wrap_cid_cod(&amount_cui, &speedometer->m_amounts[(speedometer->m_idx + i) % mk_lang_countof(speedometer->m_amounts)]);
		}
		mk_sl_fxp_128_64_64_from_uint64(&amount_fxp, &amount_cui);
		mk_sl_stopwatch_timestamp_get_duration(&speedometer->m_timestamps[(speedometer->m_idx + 1) % mk_lang_countof(speedometer->m_timestamps)], &speedometer->m_lat_append, &time_diff_dur);
		mk_sl_fxp_128_64_64_from_uint64(&time_diff_fxp_nanos, &time_diff_dur.m_elements[0].m_elements[0]);
		second_ul = 1ul * 1000ul * 1000ul * 1000ul; mk_sl_fxp_128_64_64_from_bi_ulong(&second_fxp, &second_ul);
		mk_sl_fxp_128_64_64_div3_wrap(&time_diff_fxp_nanos, &second_fxp, &time_diff_fxp_seconds);
		mk_sl_fxp_128_64_64_div3_wrap(&amount_fxp, &time_diff_fxp_seconds, &speed_fxp);
		speedometer->m_scale = ((mk_lang_types_uchar_t)(mk_sl_speedometer_scale_e_b));
		while(mk_sl_fxp_128_64_64_gt(&speed_fxp, &speed_treshold_fxp) && ((mk_sl_speedometer_scale_t)(speedometer->m_scale)) != mk_sl_speedometer_scale_e_tb)
		{
			mk_sl_fxp_128_64_64_div2_wrap(&speed_fxp, &kilobyte_fxp);
			speedometer->m_scale = ((mk_lang_types_uchar_t)(((mk_sl_speedometer_scale_t)(((mk_lang_types_sint_t)(speedometer->m_scale)) + 1))));
		}
		len = mk_sl_fxp_128_64_64_to_string_t(&speed_fxp, ptr, mk_lang_min(5, rem)); if(!(len >= 1)){ return 0; } mk_lang_assert(len >= 1); mk_lang_assert(len <= mk_lang_min(5, rem)); ptr += len; rem -= len;
		unit_ptr = mk_lang_null; unit_len = 0;
		switch(((mk_sl_speedometer_scale_t)(speedometer->m_scale)))
		{
			case mk_sl_speedometer_scale_e_b : unit_ptr = mk_lang_tchar_c("B/s" ); unit_len = 3; break;
			case mk_sl_speedometer_scale_e_kb: unit_ptr = mk_lang_tchar_c("kB/s"); unit_len = 4; break;
			case mk_sl_speedometer_scale_e_mb: unit_ptr = mk_lang_tchar_c("MB/s"); unit_len = 4; break;
			case mk_sl_speedometer_scale_e_gb: unit_ptr = mk_lang_tchar_c("GB/s"); unit_len = 4; break;
			case mk_sl_speedometer_scale_e_tb: unit_ptr = mk_lang_tchar_c("TB/s"); unit_len = 4; break;
			case mk_sl_speedometer_scale_e_dummy_end: mk_lang_assert_false(); break;
			default: mk_lang_assert_false(); break;
		}
		if(!(rem >= 1 + unit_len)){ return 0; }
		ptr[0] = mk_lang_tchar_c(' '); ptr += 1; rem -= 1;
		mk_lang_tchar_memcpy_fn(ptr, unit_ptr, ((mk_lang_types_usize_t)(unit_len))); ptr += unit_len; rem -= unit_len;
		if(!(rem >= 2)){ return 0; }
		ptr[0] = mk_lang_tchar_c(' '); ptr += 1; rem -= 1;
		ptr[0] = mk_lang_tchar_c("|/-\\")[speedometer->m_tick % 4]; ptr += 1; rem -= 1;
		len = str_len - rem;
		*out_len = len;
	}
	*reported = want;
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_speedometer_rw_construct(mk_sl_speedometer_pt const speedometer) mk_lang_noexcept
{
	return mk_sl_speedometer_pr_construct(speedometer);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_speedometer_rw_destroy(mk_sl_speedometer_pt const speedometer) mk_lang_noexcept
{
	return mk_sl_speedometer_pr_destroy(speedometer);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_speedometer_rw_append(mk_sl_speedometer_pt const speedometer, mk_lang_types_sint_t const amount) mk_lang_noexcept
{
	return mk_sl_speedometer_pr_append(speedometer, amount);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_speedometer_rw_report(mk_sl_speedometer_pt const speedometer, mk_lang_tchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const reported, mk_lang_types_sint_pt const out_len) mk_lang_noexcept
{
	return mk_sl_speedometer_pr_report(speedometer, str_buf, str_len, reported, out_len);
}


#endif
