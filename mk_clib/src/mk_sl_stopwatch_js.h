#ifndef mk_include_guard_mk_sl_stopwatch_js_h
#define mk_include_guard_mk_sl_stopwatch_js_h


#include "mk_lang_jumbo.h"
#include "mk_lang_arch.h"
#if mk_lang_arch_is_emscripten


#include "mk_lang_constexpr.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint64.h"


#define mk_sl_cui_t_name mk_sl_stopwatch_js_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_stopwatch_js_timestamp_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_stopwatch_js_timestamp_size_bytes_d mk_sl_cui_uint64_size_bytes_d

#define mk_sl_cui_t_name mk_sl_stopwatch_js_duration
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_fileu.h"
#define mk_sl_stopwatch_js_duration_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_stopwatch_js_duration_size_bytes_d mk_sl_cui_uint64_size_bytes_d


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_js_init(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_js_deinit(mk_lang_types_void_t) mk_lang_noexcept;
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_js_timestamp_get_now(mk_sl_stopwatch_js_timestamp_pt const timestamp) mk_lang_noexcept;
mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_stopwatch_js_duration_adjust(mk_sl_stopwatch_js_duration_pct const before, mk_sl_stopwatch_js_duration_pt const after) mk_lang_noexcept;


#endif


#if mk_lang_jumbo_have
#include "mk_sl_stopwatch_js.c"
#endif
#endif
