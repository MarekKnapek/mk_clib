#ifndef mk_include_guard_mk_sl_time_h
#define mk_include_guard_mk_sl_time_h


#include "mk_lang_charbit.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint64.h"


#define mk_sl_cui_t_name mk_sl_time_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_disable_big_div 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_time_timestamp_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_time_timestamp_size_bytes_d (mk_sl_cui_uint64_size_bits_d / mk_lang_charbit)


struct mk_sl_time_components_s
{
	mk_lang_types_sint_t m_year;
	mk_lang_types_sint_t m_month;
	mk_lang_types_sint_t m_day;
	mk_lang_types_sint_t m_hour;
	mk_lang_types_sint_t m_minute;
	mk_lang_types_sint_t m_second;
	mk_lang_types_slong_t m_ticks;
};
typedef struct mk_sl_time_components_s mk_sl_time_components_t;
mk_lang_typedef(mk_sl_time_components);


#define mk_sl_time_k_str_len (28)


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_time_to_components(mk_sl_time_timestamp_pct const timestamp, mk_sl_time_components_pt const components) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_time_timestamp_to_text(mk_sl_time_timestamp_pct const timestamp, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;
mk_lang_jumbo mk_lang_types_void_t mk_sl_time_timestamp_get_now(mk_sl_time_timestamp_pt const timestamp) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_time.c"
#endif
#endif
