#ifndef mk_include_guard_mk_lib_iip_time_fuzz_c
#define mk_include_guard_mk_lib_iip_time_fuzz_c
#include "mk_lib_iip_time_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lib_iip_time.h"
#include "mk_sl_time.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_lib_iip_time_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_sl_time_timestamp_t sl_timestamp;
	mk_lib_iip_time_timestamp_t iip_timestamp;
	mk_lib_iip_time_components_t iip_components;
	mk_sl_time_components_t sl_components;

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
	mk_sl_time_timestamp_from_buis_uchar_le(&sl_timestamp, &d[0]);
	d += mk_sl_time_timestamp_size_bytes_v;
	s -= mk_sl_time_timestamp_size_bytes_v;

	mk_sl_time_to_components(&sl_timestamp, &sl_components);
	if
	(!(
		(sl_components.m_year == 0) &&
		(sl_components.m_month == 0) &&
		(sl_components.m_day == 0) &&
		(sl_components.m_hour == 0) &&
		(sl_components.m_minute == 0) &&
		(sl_components.m_second == 0) &&
		(sl_components.m_ticks == 0l) &&
		(mk_lang_true)
	))
	{
		mk_lib_iip_time_from_sl_timestamp(&iip_timestamp, &sl_timestamp);
		mk_lib_iip_time_to_components(&iip_timestamp, &iip_components);
		mk_lang_test(iip_components.m_year == sl_components.m_year);
		mk_lang_test(iip_components.m_month == sl_components.m_month);
		mk_lang_test(iip_components.m_day == sl_components.m_day);
		mk_lang_test(iip_components.m_hour == sl_components.m_hour);
		mk_lang_test(iip_components.m_minute == sl_components.m_minute);
		mk_lang_test(iip_components.m_second == sl_components.m_second);
		mk_lang_test(iip_components.m_milli_second == ((mk_lang_types_sint_t)(sl_components.m_ticks / (10l * 1000l))));
	}
	return 0;
}


#endif
