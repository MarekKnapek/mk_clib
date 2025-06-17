#ifndef mk_include_guard_mk_lib_iip_time_h
#define mk_include_guard_mk_lib_iip_time_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_typedef.h"
#include "mk_lang_types.h"


mk_lang_forward(mk_sl_cui_uint64);


struct mk_lib_iip_time_components_s
{
	mk_lang_types_sint_t m_year;
	mk_lang_types_sint_t m_month;
	mk_lang_types_sint_t m_day;
	mk_lang_types_sint_t m_hour;
	mk_lang_types_sint_t m_minute;
	mk_lang_types_sint_t m_second;
	mk_lang_types_sint_t m_milli_second;
};
typedef struct mk_lib_iip_time_components_s mk_lib_iip_time_components_t;
mk_lang_typedef(mk_lib_iip_time_components);


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_to_components(mk_sl_cui_uint64_pct const time, mk_lib_iip_time_components_pt const components) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_to_text(mk_sl_cui_uint64_pct const time, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len, mk_lang_types_sint_pt const out_len) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_lib_iip_time_get_now(mk_sl_cui_uint64_pt const time) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_lib_iip_time.c"
#endif
#endif
