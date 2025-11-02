#ifndef mk_include_guard_mk_sl_stopwatch_gtc64_c
#define mk_include_guard_mk_sl_stopwatch_gtc64_c
#include "mk_sl_stopwatch_gtc64.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint128.h"
#include "mk_sl_cui_uint64.h"
#include "mk_sl_uint_convert.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_time.h"


#define mk_sl_cui_t_name mk_sl_stopwatch_gtc64_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_stopwatch_gtc64_duration
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_stopwatch_gtc64_pr_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_stopwatch_gtc64_pr_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_stopwatch_gtc64_pr_timestamp_get_now(mk_sl_stopwatch_gtc64_timestamp_pt const timestamp) mk_lang_noexcept
{
	mk_win_base_ullong_t ticks;

	ticks = mk_win_dll_kernel_time_get_tick_count64();
	mk_sl_cui_uint64_from_bi_ullong(&timestamp->m_elements[0], ((mk_lang_types_ullong_pct)(&ticks)));
	return 0;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_stopwatch_gtc64_pr_duration_adjust(mk_sl_stopwatch_gtc64_duration_pct const before, mk_sl_stopwatch_gtc64_duration_pt const after) mk_lang_noexcept
{
	mk_lang_types_uint_t million_ui mk_lang_constexpr_init;
	mk_sl_cui_uint64_t million_u64 mk_lang_constexpr_init;

	mk_lang_assert(before);
	mk_lang_assert(after);

	million_ui = 1u * 1000u * 1000u; mk_sl_cui_uint64_from_bi_uint(&million_u64, &million_ui);
	mk_sl_cui_uint64_mul3_wrap_lo(&before->m_elements[0], &million_u64, &after->m_elements[0]);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_gtc64_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_sl_stopwatch_gtc64_pr_init();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_gtc64_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return mk_sl_stopwatch_gtc64_pr_deinit();
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_gtc64_timestamp_get_now(mk_sl_stopwatch_gtc64_timestamp_pt const timestamp) mk_lang_noexcept
{
	return mk_sl_stopwatch_gtc64_pr_timestamp_get_now(timestamp);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_stopwatch_gtc64_duration_adjust(mk_sl_stopwatch_gtc64_duration_pct const before, mk_sl_stopwatch_gtc64_duration_pt const after) mk_lang_noexcept
{
	mk_sl_stopwatch_gtc64_pr_duration_adjust(before, after);
}


#else
static void mk_sl_stopwatch_gtc64_dmmy(void);
#endif
#endif
