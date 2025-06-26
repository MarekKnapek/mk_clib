#ifndef mk_include_guard_mk_sl_time_fuzz_c
#define mk_include_guard_mk_sl_time_fuzz_c
#include "mk_sl_time_fuzz.h"

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_sl_time.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_time.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_time_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_sl_time_timestamp_t timestamp;
	mk_sl_time_components_t components;
	mk_lang_types_uint_t tuis[2];
	mk_win_dll_kernel_time_file_time_t file_time;
	mk_win_base_bool_t b;
	mk_win_dll_kernel_time_system_time_t system_time;

	mk_lang_static_assert(sizeof(file_time.m_lo) == sizeof(tuis[0]));
	mk_lang_static_assert(sizeof(file_time.m_hi) == sizeof(tuis[1]));
	mk_lang_static_assert(mk_lang_alignof(mk_win_base_dword_t) == mk_lang_alignof(mk_lang_types_uint_t));

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;

	if(!(s >= mk_sl_time_timestamp_size_bytes_v))
	{
		return 0;
	}
	mk_sl_time_timestamp_from_buis_uchar_le(&timestamp, &d[0]);
	d += mk_sl_time_timestamp_size_bytes_v;
	s -= mk_sl_time_timestamp_size_bytes_v;

	mk_sl_time_to_components(&timestamp, &components);
	if
	(!(
		(components.m_year == 0) &&
		(components.m_month == 0) &&
		(components.m_day == 0) &&
		(components.m_hour == 0) &&
		(components.m_minute == 0) &&
		(components.m_second == 0) &&
		(components.m_ticks == 0l) &&
		mk_lang_true
	))
	{
		mk_sl_time_timestamp_to_buis_uint_le(&timestamp, &tuis[0]);
		file_time.m_lo = ((mk_win_base_dword_t)(tuis[0]));
		file_time.m_hi = ((mk_win_base_dword_t)(tuis[1]));
		b = mk_win_dll_kernel_time_file_to_system_time(&file_time, &system_time); mk_lang_test(b != mk_win_base_false);
		mk_lang_test(components.m_year == ((mk_lang_types_sint_t)(system_time.m_year)));
		mk_lang_test(components.m_month == ((mk_lang_types_sint_t)(system_time.m_month)));
		mk_lang_test(components.m_day == ((mk_lang_types_sint_t)(system_time.m_day)));
		mk_lang_test(components.m_hour == ((mk_lang_types_sint_t)(system_time.m_hour)));
		mk_lang_test(components.m_minute == ((mk_lang_types_sint_t)(system_time.m_minute)));
		mk_lang_test(components.m_second == ((mk_lang_types_sint_t)(system_time.m_second)));
		mk_lang_test(components.m_ticks / (10l * 1000l) == ((mk_lang_types_sint_t)(system_time.m_millisecond)));
	}
	return 0;
}


#endif
