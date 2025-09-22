#ifndef mk_include_guard_mk_sl_stopwatch_h
#define mk_include_guard_mk_sl_stopwatch_h


#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_platform.h"
#include "mk_lang_types.h"


#if mk_lang_platform_is_windows_at_least_any
#include "mk_sl_stopwatch_qpc.h"
#define mk_sl_stopwatch_impl qpc
#elif mk_lang_platform_is_posix_at_least_2008_09 /* todo exact version */
#include "mk_sl_stopwatch_posix.h"
#define mk_sl_stopwatch_impl posix
#endif


#define mk_sl_stopwatch_impl_prefix mk_lang_concat(mk_sl_stopwatch_, mk_sl_stopwatch_impl)
#define mk_sl_stopwatch_impl_timestamp mk_lang_concat(mk_sl_stopwatch_impl_prefix, _timestamp)
#define mk_sl_stopwatch_impl_timestamp_size_bits_d mk_lang_concat(mk_sl_stopwatch_impl_prefix, _timestamp_size_bits_d)
#define mk_sl_stopwatch_impl_timestamp_size_bytes_d mk_lang_concat(mk_sl_stopwatch_impl_prefix, _timestamp_size_bytes_d)
#define mk_sl_stopwatch_impl_duration mk_lang_concat(mk_sl_stopwatch_impl_prefix, _duration)
#define mk_sl_stopwatch_impl_duration_size_bits_d mk_lang_concat(mk_sl_stopwatch_impl_prefix, _duration_size_bits_d)
#define mk_sl_stopwatch_impl_duration_size_bytes_d mk_lang_concat(mk_sl_stopwatch_impl_prefix, _duration_size_bytes_d)


#define mk_sl_cui_t_name mk_sl_stopwatch_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_stopwatch_impl_timestamp
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_stopwatch_impl_timestamp_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_stopwatch_timestamp_size_bits_d mk_sl_stopwatch_impl_timestamp_size_bits_d
#define mk_sl_stopwatch_timestamp_size_bytes_d mk_sl_stopwatch_impl_timestamp_size_bytes_d

#define mk_sl_cui_t_name mk_sl_stopwatch_duration
#define mk_sl_cui_t_base_type_name mk_sl_stopwatch_impl_duration
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_stopwatch_impl_duration_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_stopwatch_duration_size_bits_d mk_sl_stopwatch_impl_duration_size_bits_d
#define mk_sl_stopwatch_duration_size_bytes_d mk_sl_stopwatch_impl_duration_size_bytes_d


#define mk_sl_stopwatch_duration_text_max_len (28)


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_timestamp_get_now(mk_sl_stopwatch_timestamp_pt const timestamp) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_stopwatch_timestamp_get_duration(mk_sl_stopwatch_timestamp_pct const before, mk_sl_stopwatch_timestamp_pct const after, mk_sl_stopwatch_duration_pt const duration) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_duration_to_text(mk_sl_stopwatch_duration_pct const duration, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept;


#if mk_lang_jumbo_have
#include "mk_sl_stopwatch.c"
#endif
#endif
