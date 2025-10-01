#ifndef mk_include_guard_mk_sl_stopwatch_js_c
#define mk_include_guard_mk_sl_stopwatch_js_c
#include "mk_sl_stopwatch_js.h"

#include "mk_lang_arch.h"
#if mk_lang_arch_is_emscripten

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_extern.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint64.h"


#define mk_sl_cui_t_name mk_sl_stopwatch_js_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_stopwatch_js_duration
#define mk_sl_cui_t_base_type_name mk_sl_cui_uint64
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_cui_uint64_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_extern_force_c mk_lang_types_void_t js_get_now_ms64le(mk_lang_types_uchar_pt const uchars_le) mk_lang_noexcept;


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_js_init(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_js_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_js_timestamp_get_now(mk_sl_stopwatch_js_timestamp_pt const timestamp) mk_lang_noexcept
{
	union mk_sl_stopwatch_js_timestamp_get_now_convertor_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_sl_cui_uint64_size_bytes_v];
		mk_sl_stopwatch_js_timestamp_t m_timestamp;
	};
	typedef union mk_sl_stopwatch_js_timestamp_get_now_convertor_data_u mk_sl_stopwatch_js_timestamp_get_now_convertor_data_t;
	struct mk_sl_stopwatch_js_timestamp_get_now_convertor_s
	{
		mk_sl_stopwatch_js_timestamp_get_now_convertor_data_t m_data;
	};
	typedef struct mk_sl_stopwatch_js_timestamp_get_now_convertor_s mk_sl_stopwatch_js_timestamp_get_now_convertor_t;

	mk_sl_stopwatch_js_timestamp_get_now_convertor_t convertor;

	mk_lang_assert(timestamp);

	js_get_now_ms64le(&convertor.m_data.m_uchars[0]);
	mk_sl_stopwatch_js_timestamp_from_buis_uchar_le(timestamp, &convertor.m_data.m_uchars[0]);
	return 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_stopwatch_js_duration_adjust(mk_sl_stopwatch_js_duration_pct const before, mk_sl_stopwatch_js_duration_pt const after) mk_lang_noexcept
{
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_stopwatch_js_duration_t ta mk_lang_constexpr_init;
	mk_sl_stopwatch_js_duration_t tb mk_lang_constexpr_init;

	mk_lang_assert(before);
	mk_lang_assert(after);

	tsi = 1 * 1000 * 1000; mk_sl_stopwatch_js_duration_from_bi_sint(&ta, &tsi);
	if(!mk_sl_stopwatch_js_duration_has_msb(before))
	{
		mk_lang_assert(!mk_sl_stopwatch_js_duration_would_overflow_mul(before, &ta));
		mk_sl_stopwatch_js_duration_mul3_wrap_lo(before, &ta, after);
	}
	else
	{
		mk_sl_stopwatch_js_duration_not2(before, &tb);
		mk_sl_stopwatch_js_duration_dec1(&tb);
		mk_lang_assert(!mk_sl_stopwatch_js_duration_would_overflow_mul(&tb, &ta));
		mk_sl_stopwatch_js_duration_mul2_wrap_lo(&tb, &ta);
		mk_sl_stopwatch_js_duration_inc1(&tb);
		mk_sl_stopwatch_js_duration_not2(&tb, after);
	}
}


#else
static void mk_sl_stopwatch_js_dmmy(void);
#endif
#endif
