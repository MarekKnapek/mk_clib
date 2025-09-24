#ifndef mk_include_guard_mk_sl_stopwatch_posix_c
#define mk_include_guard_mk_sl_stopwatch_posix_c
#include "mk_sl_stopwatch_posix.h"

#include "mk_lang_platform.h"
#if mk_lang_platform_is_posix_at_least_2008_09 /* todo exact version */

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint64.h"

#include <time.h> /* clock_gettime CLOCK_THREAD_CPUTIME_ID CLOCK_PROCESS_CPUTIME_ID CLOCK_MONOTONIC timespec time_t */


#define mk_sl_cui_t_name mk_sl_stopwatch_posix_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_stopwatch_posix_duration
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_posix_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_posix_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_posix_timestamp_get_now(mk_sl_stopwatch_posix_timestamp_pt const timestamp) mk_lang_noexcept
{
	mk_lang_types_sint_t st;
	struct timespec ts;
	mk_lang_types_ulllong_t tulll_a;
	mk_lang_types_ulong_t tul_b;
	mk_lang_types_ulong_t tul_c;
	mk_sl_cui_uint64_t tu64_a;
	mk_sl_cui_uint64_t tu64_b;
	mk_sl_cui_uint64_t tu64_c;

	mk_lang_assert(timestamp);

	#if defined _POSIX_THREAD_CPUTIME
	st = clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts); mk_lang_check_return(st == 0);
	#elif defined _POSIX_CPUTIME
	st = clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts); mk_lang_check_return(st == 0);
	#else
	st = clock_gettime(CLOCK_MONOTONIC, &ts); mk_lang_check_return(st == 0);
	#endif
	tulll_a = ((mk_lang_types_ulllong_t)(ts.tv_sec)); /* integer */
	tul_b = ((mk_lang_types_ulong_t)(ts.tv_nsec)); /* long */
	tul_c = ((mk_lang_types_ullong_t)(1ul * 1000ul * 1000ul * 1000ul));
	mk_lang_assert(ts.tv_nsec >= 0);
	mk_lang_assert(ts.tv_nsec < ((mk_lang_types_slong_t)(tul_c)));
	mk_sl_cui_uint64_from_bi_ulllong(&tu64_a, &tulll_a);
	mk_sl_cui_uint64_from_bi_ulong(&tu64_b, &tul_b);
	mk_sl_cui_uint64_from_bi_ulong(&tu64_c, &tul_c);
	mk_sl_cui_uint64_mul2_wrap_lo(&tu64_a, &tu64_c);
	mk_sl_cui_uint64_or2(&tu64_a, &tu64_b);
	mk_sl_stopwatch_posix_timestamp_from_base(timestamp, &tu64_a);
	return 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_stopwatch_posix_duration_adjust(mk_sl_stopwatch_posix_duration_pct const before, mk_sl_stopwatch_posix_duration_pt const after) mk_lang_noexcept
{
	mk_lang_assert(before);
	mk_lang_assert(after);

	mk_sl_stopwatch_posix_duration_assign(after, before);
}


#else
static void mk_sl_stopwatch_posix_dmmy(void);
#endif
#endif
