#ifndef mk_include_guard_mk_sl_stopwatch_qpc_c
#define mk_include_guard_mk_sl_stopwatch_qpc_c
#include "mk_sl_stopwatch_qpc.h"

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


#define mk_sl_cui_t_name mk_sl_stopwatch_qpc_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_stopwatch_qpc_duration
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


static mk_sl_cui_uint64_t mk_sl_stopwatch_qpc_g_freq;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_qpc_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_large_integer_t integer;

	b = mk_win_dll_kernel_time_query_performance_frequency(&integer); mk_lang_check_return(b != mk_win_base_false);
	mk_sl_cui_uint64_from_bi_ullong(&mk_sl_stopwatch_qpc_g_freq, ((mk_win_base_ullong_pt)(&integer)));
	mk_lang_check_return(!mk_sl_cui_uint64_is_zero(&mk_sl_stopwatch_qpc_g_freq));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_qpc_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_qpc_timestamp_get_now(mk_sl_stopwatch_qpc_timestamp_pt const timestamp) mk_lang_noexcept
{
	mk_win_base_bool_t b;
	mk_win_base_large_integer_t integer;

	b = mk_win_dll_kernel_time_query_performance_counter(&integer); mk_lang_check_return(b != mk_win_base_false);
	mk_sl_cui_uint64_from_bi_ullong(&timestamp->m_elements[0], ((mk_win_base_ullong_pt)(&integer)));
	return 0;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_stopwatch_qpc_u64_to_u128(mk_sl_cui_uint64_pct const u64, mk_sl_cui_uint128_pt const u128) mk_lang_noexcept
{
	union mk_sl_stopwatch_qpc_u64_to_u128_convertor_data_u
	{
		mk_sl_cui_uint64_t m_u64s[2];
		mk_sl_cui_uint128_t m_u128;
	};
	typedef union mk_sl_stopwatch_qpc_u64_to_u128_convertor_data_u mk_sl_stopwatch_qpc_u64_to_u128_convertor_data_t;
	struct mk_sl_stopwatch_qpc_u64_to_u128_convertor_s
	{
		mk_sl_stopwatch_qpc_u64_to_u128_convertor_data_t m_data;
	};
	typedef struct mk_sl_stopwatch_qpc_u64_to_u128_convertor_s mk_sl_stopwatch_qpc_u64_to_u128_convertor_t;

	mk_sl_stopwatch_qpc_u64_to_u128_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(u64);
	mk_lang_assert(u128);

	mk_sl_cui_uint64_assign(&convertor.m_data.m_u64s[0], u64);
	mk_sl_cui_uint64_set_zero(&convertor.m_data.m_u64s[1]);
	mk_sl_uint_convert_128_64_le_to_big(u128, &convertor.m_data.m_u64s[0]);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_stopwatch_qpc_u128_to_u64(mk_sl_cui_uint128_pct const u128, mk_sl_cui_uint64_pt const u64) mk_lang_noexcept
{
	union mk_sl_stopwatch_qpc_u128_to_u64_convertor_data_u
	{
		mk_sl_cui_uint64_t m_u64s[2];
		mk_sl_cui_uint128_t m_u128;
	};
	typedef union mk_sl_stopwatch_qpc_u128_to_u64_convertor_data_u mk_sl_stopwatch_qpc_u128_to_u64_convertor_data_t;
	struct mk_sl_stopwatch_qpc_u128_to_u64_convertor_s
	{
		mk_sl_stopwatch_qpc_u128_to_u64_convertor_data_t m_data;
	};
	typedef struct mk_sl_stopwatch_qpc_u128_to_u64_convertor_s mk_sl_stopwatch_qpc_u128_to_u64_convertor_t;

	mk_sl_stopwatch_qpc_u128_to_u64_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(u128);
	mk_lang_assert(u64);

	mk_sl_uint_convert_128_64_le_to_sml(u128, &convertor.m_data.m_u64s[0]);
	mk_sl_cui_uint64_assign(u64, &convertor.m_data.m_u64s[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_stopwatch_qpc_duration_adjust(mk_sl_stopwatch_qpc_duration_pct const before, mk_sl_stopwatch_qpc_duration_pt const after) mk_lang_noexcept
{
	mk_sl_cui_uint128_t u128a mk_lang_constexpr_init;
	mk_lang_types_ulong_t tul mk_lang_constexpr_init;
	mk_sl_cui_uint128_t u128b mk_lang_constexpr_init;

	mk_lang_assert(before);
	mk_lang_assert(after);

	mk_sl_stopwatch_qpc_u64_to_u128(&before->m_elements[0], &u128a);
	tul = 1ul * 1000ul * 1000ul * 1000ul;
	mk_sl_cui_uint128_from_bi_ulong(&u128b, &tul);
	mk_sl_cui_uint128_mul2_wrap_lo(&u128a, &u128b);
	mk_sl_stopwatch_qpc_u64_to_u128(&mk_sl_stopwatch_qpc_g_freq, &u128b);
	mk_sl_cui_uint128_div2_wrap(&u128a, &u128b);
	mk_sl_stopwatch_qpc_u128_to_u64(&u128a, &after->m_elements[0]);
}


#else
static void mk_sl_stopwatch_qpc_dmmy(void);
#endif
#endif
