#ifndef mk_include_guard_mk_sl_speedometer_h
#define mk_include_guard_mk_sl_speedometer_h


#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_tchar.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_stopwatch.h"


enum mk_sl_speedometer_scale_e
{
	mk_sl_speedometer_scale_e_b,
	mk_sl_speedometer_scale_e_kb,
	mk_sl_speedometer_scale_e_mb,
	mk_sl_speedometer_scale_e_gb,
	mk_sl_speedometer_scale_e_tb,
	mk_sl_speedometer_scale_e_dummy_end
};
typedef enum mk_sl_speedometer_scale_e mk_sl_speedometer_scale_t;


#include "mk_lang_warning_msvc_push_c4820.h"
struct mk_sl_speedometer_s
{
	mk_sl_cui_uint64_t m_amounts[14];
	mk_sl_stopwatch_timestamp_t m_timestamps[14];
	mk_sl_stopwatch_timestamp_t m_lat_append;
	mk_sl_stopwatch_timestamp_t m_lat_reported;
	mk_lang_types_uchar_t m_idx;
	mk_lang_types_uchar_t m_tick;
	mk_lang_types_uchar_t m_scale;
};
typedef struct mk_sl_speedometer_s mk_sl_speedometer_t;
mk_lang_typedef(mk_sl_speedometer);
#include "mk_lang_warning_msvc_pop.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_speedometer_rw_construct(mk_sl_speedometer_pt const speedometer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_speedometer_rw_destroy(mk_sl_speedometer_pt const speedometer) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_speedometer_rw_append(mk_sl_speedometer_pt const speedometer, mk_lang_types_sint_t const amount) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_speedometer_rw_report(mk_sl_speedometer_pt const speedometer, mk_lang_tchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_bool_pt const reported, mk_lang_types_sint_pt const out_len) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_speedometer.c"
#endif
#endif
