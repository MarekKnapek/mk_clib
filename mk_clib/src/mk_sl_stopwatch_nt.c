#ifndef mk_include_guard_mk_sl_stopwatch_nt_c
#define mk_include_guard_mk_sl_stopwatch_nt_c
#include "mk_sl_stopwatch_nt.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_windows_at_least_any

#include "mk_lang_alignof.h"
#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint64.h"
#include "mk_win_base.h"
#include "mk_win_dll_kernel_time.h"


#define mk_sl_cui_t_name mk_sl_stopwatch_nt_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_stopwatch_nt_duration
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_nt_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_nt_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_nt_timestamp_get_now(mk_sl_stopwatch_nt_timestamp_pt const timestamp) mk_lang_noexcept
{
	mk_win_dll_kernel_time_file_time_t file_time;
	mk_lang_types_uint_t tuis[2];

	mk_lang_static_assert(sizeof(file_time.m_lo) == sizeof(tuis[0]));
	mk_lang_static_assert(sizeof(file_time.m_hi) == sizeof(tuis[1]));
	mk_lang_static_assert(mk_lang_alignof(mk_win_base_dword_t) == mk_lang_alignof(mk_lang_types_uint_t));

	mk_lang_assert(timestamp);

	mk_win_dll_kernel_time_get_system_time_precise_as_file_time(&file_time);
	tuis[0] = ((mk_lang_types_uint_t)(file_time.m_lo));
	tuis[1] = ((mk_lang_types_uint_t)(file_time.m_hi));
	mk_sl_stopwatch_nt_timestamp_from_buis_uint_le(timestamp, &tuis[0]);
	return 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_stopwatch_nt_duration_adjust(mk_sl_stopwatch_nt_duration_pct const before, mk_sl_stopwatch_nt_duration_pt const after) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_stopwatch_nt_duration_t ta mk_lang_constexpr_init;
	mk_sl_stopwatch_nt_duration_t tb mk_lang_constexpr_init;

	mk_lang_assert(before);
	mk_lang_assert(after);

	tsi = 100; mk_sl_stopwatch_nt_duration_from_bi_sint(&ta, &tsi);
	if(!mk_sl_stopwatch_nt_duration_has_msb(before))
	{
		mk_lang_assert(!mk_sl_stopwatch_nt_duration_would_overflow_mul(before, &ta));
		mk_sl_stopwatch_nt_duration_mul3_wrap_lo(before, &ta, after);
	}
	else
	{
		mk_sl_stopwatch_nt_duration_not2(before, &tb);
		mk_sl_stopwatch_nt_duration_dec1(&tb);
		mk_lang_assert(!mk_sl_stopwatch_nt_duration_would_overflow_mul(&tb, &ta));
		mk_sl_stopwatch_nt_duration_mul2_wrap_lo(&tb, &ta);
		mk_sl_stopwatch_nt_duration_inc1(&tb);
		mk_sl_stopwatch_nt_duration_not2(&tb, after);
	}
}


#else
static void mk_sl_stopwatch_nt_dmmy(void);
#endif
#endif
