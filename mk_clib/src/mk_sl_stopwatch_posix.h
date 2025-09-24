#ifndef mk_include_guard_mk_sl_stopwatch_posix_h
#define mk_include_guard_mk_sl_stopwatch_posix_h


#include "mk_lang_jumbo.h"
#include "mk_lang_platform.h"
#if mk_lang_platform_is_posix_at_least_2008_09 /* todo exact version */


#include "mk_lang_constexpr.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint64.h"


#define mk_sl_cui_t_name mk_sl_stopwatch_posix_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_stopwatch_posix_timestamp_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_stopwatch_posix_timestamp_size_bytes_d mk_sl_cui_uint64_size_bytes_d

#define mk_sl_cui_t_name mk_sl_stopwatch_posix_duration
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_stopwatch_posix_duration_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_stopwatch_posix_duration_size_bytes_d mk_sl_cui_uint64_size_bytes_d


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_posix_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_posix_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_posix_timestamp_get_now(mk_sl_stopwatch_posix_timestamp_pt const timestamp) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_stopwatch_posix_duration_adjust(mk_sl_stopwatch_posix_duration_pct const before, mk_sl_stopwatch_posix_duration_pt const after) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_sl_stopwatch_posix.c"
#endif
#endif
