#ifndef mk_include_guard_mk_sl_stopwatch_c
#define mk_include_guard_mk_sl_stopwatch_c
#include "mk_sl_stopwatch.h"

#include "mk_lang_assert.h"
#include "mk_lang_check.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lang_types.h"


#define mk_sl_stopwatch_impl_init mk_lang_concat(mk_sl_stopwatch_impl_prefix, _init)
#define mk_sl_stopwatch_impl_deinit mk_lang_concat(mk_sl_stopwatch_impl_prefix, _deinit)
#define mk_sl_stopwatch_impl_timestamp_t mk_lang_concat(mk_sl_stopwatch_impl_prefix, _timestamp_t)
#define mk_sl_stopwatch_impl_timestamp_sub3_wrap_cid_cod mk_lang_concat(mk_sl_stopwatch_impl_prefix, _timestamp_sub3_wrap_cid_cod)
#define mk_sl_stopwatch_impl_timestamp_get_now mk_lang_concat(mk_sl_stopwatch_impl_prefix, _timestamp_get_now)
#define mk_sl_stopwatch_impl_duration_adjust mk_lang_concat(mk_sl_stopwatch_impl_prefix, _duration_adjust)


#define mk_sl_cui_t_name mk_sl_stopwatch_timestamp
#define mk_sl_cui_t_base_type_name mk_sl_stopwatch_impl_timestamp
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_stopwatch_impl_timestamp_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"

#define mk_sl_cui_t_name mk_sl_stopwatch_duration
#define mk_sl_cui_t_base_type_name mk_sl_stopwatch_impl_duration
#define mk_sl_cui_t_count 1
#define mk_sl_cui_t_base_type_size_bits_d mk_sl_stopwatch_impl_duration_size_bits_d
#define mk_sl_cui_t_inline 1
#include "mk_sl_cui_inl_filec.h"
#include "mk_sl_cui_inl_fileu.h"


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_init(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_stopwatch_impl_init(); mk_lang_check_rereturn(err);
	return err;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_deinit(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	err = mk_sl_stopwatch_impl_deinit(); mk_lang_check_rereturn(err);
	return err;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_timestamp_get_now(mk_sl_stopwatch_timestamp_pt const timestamp) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(timestamp);

	err = mk_sl_stopwatch_impl_timestamp_get_now(&timestamp->m_elements[0]); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_stopwatch_timestamp_to_duration(mk_sl_stopwatch_timestamp_pct const timestamp, mk_sl_stopwatch_duration_pt const duration) mk_lang_noexcept
{
	#define mk_sl_stopwatch_timestamp_to_duration_d_max mk_lang_max(mk_sl_stopwatch_timestamp_size_bytes_d, mk_sl_stopwatch_duration_size_bytes_d)
	#define mk_sl_stopwatch_timestamp_to_duration_d_min mk_lang_min(mk_sl_stopwatch_timestamp_size_bytes_d, mk_sl_stopwatch_duration_size_bytes_d)
	#define mk_sl_stopwatch_timestamp_to_duration_d_dif (mk_sl_stopwatch_timestamp_to_duration_d_max - mk_sl_stopwatch_timestamp_to_duration_d_min)

	union mk_sl_stopwatch_timestamp_to_duration_convertor_data_u
	{
		mk_lang_types_uchar_t m_uchars[mk_sl_stopwatch_timestamp_to_duration_d_max];
		mk_sl_stopwatch_timestamp_t m_timestamp;
		mk_sl_stopwatch_duration_t m_duration;
	};
	typedef union mk_sl_stopwatch_timestamp_to_duration_convertor_data_u mk_sl_stopwatch_timestamp_to_duration_convertor_data_t;
	struct mk_sl_stopwatch_timestamp_to_duration_convertor_s
	{
		mk_sl_stopwatch_timestamp_to_duration_convertor_data_t m_data;
	};
	typedef struct mk_sl_stopwatch_timestamp_to_duration_convertor_s mk_sl_stopwatch_timestamp_to_duration_convertor_t;

	mk_sl_stopwatch_timestamp_to_duration_convertor_t convertor mk_lang_constexpr_init;

	mk_lang_assert(timestamp);
	mk_lang_assert(duration);

	#if mk_sl_stopwatch_timestamp_to_duration_d_dif != 0
	mk_lang_string_memclr_uc_fn(&convertor.m_data.m_uchars[mk_sl_stopwatch_timestamp_to_duration_d_min], ((mk_lang_types_usize_t)(mk_sl_stopwatch_timestamp_to_duration_d_dif)));
	#endif
	mk_sl_stopwatch_timestamp_to_buis_uchar_le(timestamp, &convertor.m_data.m_uchars[0]);
	mk_sl_stopwatch_duration_from_buis_uchar_le(duration, &convertor.m_data.m_uchars[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_stopwatch_duration_adjust(mk_sl_stopwatch_duration_pct const before, mk_sl_stopwatch_duration_pt const after) mk_lang_noexcept
{
	mk_lang_assert(before);
	mk_lang_assert(after);

	mk_sl_stopwatch_impl_duration_adjust(&before->m_elements[0], &after->m_elements[0]);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_stopwatch_timestamp_get_duration(mk_sl_stopwatch_timestamp_pct const before, mk_sl_stopwatch_timestamp_pct const after, mk_sl_stopwatch_duration_pt const duration) mk_lang_noexcept
{
	mk_sl_stopwatch_timestamp_t d mk_lang_constexpr_init;

	mk_lang_assert(before);
	mk_lang_assert(after);
	mk_lang_assert(duration);

	mk_sl_stopwatch_timestamp_sub3_wrap_cid_cod(after, before, &d);
	mk_sl_stopwatch_timestamp_to_duration(&d, duration);
	mk_sl_stopwatch_duration_adjust(duration, duration);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_stopwatch_duration_pr_to_text_ns(mk_sl_stopwatch_duration_pct const duration, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(duration);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	ptr = str_buf;
	rem = str_len;

	len = mk_sl_stopwatch_duration_to_str_dec_n(duration, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 3);
	if(!(rem >= 1)){ return 0; } ptr[0] = ' '; ptr += 1; rem -= 1;
	if(!(rem >= 1)){ return 0; } ptr[0] = 'n'; ptr += 1; rem -= 1;
	if(!(rem >= 1)){ return 0; } ptr[0] = 's'; ptr += 1; rem -= 1;
	len = str_len - rem;
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_stopwatch_duration_pr_to_text_us(mk_sl_stopwatch_duration_pct const duration, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_sl_stopwatch_duration_t k_micro_second mk_lang_constexpr_init;

	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t micros mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t nanos mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t trailing mk_lang_constexpr_init;
	mk_lang_types_pchar_t zero mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(duration);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	{
		mk_sl_stopwatch_duration_t k_nano_second mk_lang_constexpr_init;
		mk_lang_types_sint_t tsi mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_t tt mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_set_one(&k_nano_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_nano_second, &k_micro_second);
	}

	ptr = str_buf;
	rem = str_len;

	mk_sl_stopwatch_duration_divmod4_wrap(duration, &k_micro_second, &micros, &nanos);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&micros, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 3);
	if(!(rem >= 1)){ return 0; } ptr[0] = '.'; ptr += 1; rem -= 1;

	len = mk_sl_stopwatch_duration_to_str_dec_n(&nanos, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	trailing = 3;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= trailing);
	zero = '0';
	if(len != trailing)
	{
		mk_lang_string_memmov_pc_fn(ptr - len + trailing - len, ptr - len, ((mk_lang_types_usize_t)(len)));
		mk_lang_string_memset_pc_fn(ptr - len, &zero, ((mk_lang_types_usize_t)(trailing - len)));
	}
	len = trailing - len;
	ptr += len; rem -= len;
	n = trailing - 1;
	for(i = 0; i != n; ++i)
	{
		if(ptr[-1] == zero)
		{
			ptr -= 1; rem += 1;
		}
		else
		{
			break;
		}
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = ' '; ptr += 1; rem -= 1;
	if(!(rem >= 1)){ return 0; } ptr[0] = 'u'; ptr += 1; rem -= 1;
	if(!(rem >= 1)){ return 0; } ptr[0] = 's'; ptr += 1; rem -= 1;
	len = str_len - rem;
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_stopwatch_duration_pr_to_text_ms(mk_sl_stopwatch_duration_pct const duration, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_sl_stopwatch_duration_t k_micro_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_milli_second mk_lang_constexpr_init;

	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t millis mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t nanos mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t trailing mk_lang_constexpr_init;
	mk_lang_types_pchar_t zero mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(duration);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	{
		mk_sl_stopwatch_duration_t k_nano_second mk_lang_constexpr_init;
		mk_lang_types_sint_t tsi mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_t tt mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_set_one(&k_nano_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_nano_second, &k_micro_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_micro_second, &k_milli_second);
	}

	ptr = str_buf;
	rem = str_len;

	mk_sl_stopwatch_duration_divmod4_wrap(duration, &k_milli_second, &millis, &nanos);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&millis, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 3);
	if(!(rem >= 1)){ return 0; } ptr[0] = '.'; ptr += 1; rem -= 1;

	len = mk_sl_stopwatch_duration_to_str_dec_n(&nanos, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	trailing = 6;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= trailing);
	zero = '0';
	if(len != trailing)
	{
		mk_lang_string_memmov_pc_fn(ptr - len + trailing - len, ptr - len, ((mk_lang_types_usize_t)(len)));
		mk_lang_string_memset_pc_fn(ptr - len, &zero, ((mk_lang_types_usize_t)(trailing - len)));
	}
	len = trailing - len;
	ptr += len; rem -= len;
	n = trailing - 1;
	for(i = 0; i != n; ++i)
	{
		if(ptr[-1] == zero)
		{
			ptr -= 1; rem += 1;
		}
		else
		{
			break;
		}
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = ' '; ptr += 1; rem -= 1;
	if(!(rem >= 1)){ return 0; } ptr[0] = 'm'; ptr += 1; rem -= 1;
	if(!(rem >= 1)){ return 0; } ptr[0] = 's'; ptr += 1; rem -= 1;
	len = str_len - rem;
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_stopwatch_duration_pr_to_text_s(mk_sl_stopwatch_duration_pct const duration, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_sl_stopwatch_duration_t k_micro_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_milli_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_second mk_lang_constexpr_init;

	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t seconds mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t nanos mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_lang_types_sint_t trailing mk_lang_constexpr_init;
	mk_lang_types_pchar_t zero mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(duration);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	{
		mk_sl_stopwatch_duration_t k_nano_second mk_lang_constexpr_init;
		mk_lang_types_sint_t tsi mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_t tt mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_set_one(&k_nano_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_nano_second, &k_micro_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_micro_second, &k_milli_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_milli_second, &k_second);
	}

	ptr = str_buf;
	rem = str_len;

	mk_sl_stopwatch_duration_divmod4_wrap(duration, &k_second, &seconds, &nanos);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&seconds, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 2);
	if(!(rem >= 1)){ return 0; } ptr[0] = '.'; ptr += 1; rem -= 1;

	len = mk_sl_stopwatch_duration_to_str_dec_n(&nanos, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	trailing = 9;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= trailing);
	zero = '0';
	if(len != trailing)
	{
		mk_lang_string_memmov_pc_fn(ptr - len + trailing - len, ptr - len, ((mk_lang_types_usize_t)(len)));
		mk_lang_string_memset_pc_fn(ptr - len, &zero, ((mk_lang_types_usize_t)(trailing - len)));
	}
	len = trailing - len;
	ptr += len; rem -= len;
	n = trailing - 1;
	for(i = 0; i != n; ++i)
	{
		if(ptr[-1] == zero)
		{
			ptr -= 1; rem += 1;
		}
		else
		{
			break;
		}
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = ' '; ptr += 1; rem -= 1;
	if(!(rem >= 1)){ return 0; } ptr[0] = 's'; ptr += 1; rem -= 1;
	len = str_len - rem;
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_stopwatch_duration_pr_to_text_m(mk_sl_stopwatch_duration_pct const duration, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_sl_stopwatch_duration_t k_micro_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_milli_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_minute mk_lang_constexpr_init;

	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t minutes mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t dur mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t seconds mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t nanos mk_lang_constexpr_init;
	mk_lang_types_pchar_t zero mk_lang_constexpr_init;
	mk_lang_types_sint_t trailing mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(duration);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	{
		mk_sl_stopwatch_duration_t k_nano_second mk_lang_constexpr_init;
		mk_lang_types_sint_t tsi mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_t tt mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_set_one(&k_nano_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_nano_second, &k_micro_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_micro_second, &k_milli_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_milli_second, &k_second);
		tsi = 60; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_second, &k_minute);
	}

	ptr = str_buf;
	rem = str_len;

	mk_sl_stopwatch_duration_div3_wrap(duration, &k_minute, &minutes);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&minutes, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 2);
	if(!(rem >= 1)){ return 0; } ptr[0] = ':'; ptr += 1; rem -= 1;
	mk_sl_stopwatch_duration_mul2_wrap_lo(&minutes, &k_minute);
	mk_sl_stopwatch_duration_sub3_wrap_cid_cod(duration, &minutes, &dur);

	mk_sl_stopwatch_duration_divmod4_wrap(&dur, &k_second, &seconds, &nanos);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&seconds, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 2);
	zero = '0';
	if(len == 1)
	{
		if(!(rem >= 1)){ return 0; }
		ptr[0] = ptr[-1]; ptr += 1; rem -= 1;
		ptr[-2] = zero;
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = '.'; ptr += 1; rem -= 1;

	len = mk_sl_stopwatch_duration_to_str_dec_n(&nanos, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	trailing = 9;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= trailing);
	if(len != trailing)
	{
		mk_lang_string_memmov_pc_fn(ptr - len + trailing - len, ptr - len, ((mk_lang_types_usize_t)(len)));
		mk_lang_string_memset_pc_fn(ptr - len, &zero, ((mk_lang_types_usize_t)(trailing - len)));
	}
	len = trailing - len;
	ptr += len; rem -= len;
	n = trailing - 1;
	for(i = 0; i != n; ++i)
	{
		if(ptr[-1] == zero)
		{
			ptr -= 1; rem += 1;
		}
		else
		{
			break;
		}
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = ' '; ptr += 1; rem -= 1;
	if(!(rem >= 1)){ return 0; } ptr[0] = 'm'; ptr += 1; rem -= 1;
	len = str_len - rem;
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_stopwatch_duration_pr_to_text_h(mk_sl_stopwatch_duration_pct const duration, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_sl_stopwatch_duration_t k_micro_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_milli_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_minute mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_hour mk_lang_constexpr_init;

	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t hours mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t dur mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t minutes mk_lang_constexpr_init;
	mk_lang_types_pchar_t zero mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t seconds mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t nanos mk_lang_constexpr_init;
	mk_lang_types_sint_t trailing mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(duration);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	{
		mk_sl_stopwatch_duration_t k_nano_second mk_lang_constexpr_init;
		mk_lang_types_sint_t tsi mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_t tt mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_set_one(&k_nano_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_nano_second, &k_micro_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_micro_second, &k_milli_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_milli_second, &k_second);
		tsi = 60; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_second, &k_minute);
		tsi = 60; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_minute, &k_hour);
	}

	ptr = str_buf;
	rem = str_len;

	mk_sl_stopwatch_duration_div3_wrap(duration, &k_hour, &hours);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&hours, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 2);
	if(!(rem >= 1)){ return 0; } ptr[0] = ':'; ptr += 1; rem -= 1;
	mk_sl_stopwatch_duration_mul2_wrap_lo(&hours, &k_hour);
	mk_sl_stopwatch_duration_sub3_wrap_cid_cod(duration, &hours, &dur);

	mk_sl_stopwatch_duration_div3_wrap(&dur, &k_minute, &minutes);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&minutes, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 2);
	zero = '0';
	if(len == 1)
	{
		if(!(rem >= 1)){ return 0; }
		ptr[0] = ptr[-1]; ptr += 1; rem -= 1;
		ptr[-2] = zero;
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = ':'; ptr += 1; rem -= 1;
	mk_sl_stopwatch_duration_mul2_wrap_lo(&minutes, &k_minute);
	mk_sl_stopwatch_duration_sub2_wrap_cid_cod(&dur, &minutes);

	mk_sl_stopwatch_duration_divmod4_wrap(&dur, &k_second, &seconds, &nanos);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&seconds, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 2);
	if(len == 1)
	{
		if(!(rem >= 1)){ return 0; }
		ptr[0] = ptr[-1]; ptr += 1; rem -= 1;
		ptr[-2] = zero;
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = '.'; ptr += 1; rem -= 1;

	len = mk_sl_stopwatch_duration_to_str_dec_n(&nanos, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	trailing = 9;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= trailing);
	if(len != trailing)
	{
		mk_lang_string_memmov_pc_fn(ptr - len + trailing - len, ptr - len, ((mk_lang_types_usize_t)(len)));
		mk_lang_string_memset_pc_fn(ptr - len, &zero, ((mk_lang_types_usize_t)(trailing - len)));
	}
	len = trailing - len;
	ptr += len; rem -= len;
	n = trailing - 1;
	for(i = 0; i != n; ++i)
	{
		if(ptr[-1] == zero)
		{
			ptr -= 1; rem += 1;
		}
		else
		{
			break;
		}
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = ' '; ptr += 1; rem -= 1;
	if(!(rem >= 1)){ return 0; } ptr[0] = 'h'; ptr += 1; rem -= 1;
	len = str_len - rem;
	return len;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_stopwatch_duration_pr_to_text_d(mk_sl_stopwatch_duration_pct const duration, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_sl_stopwatch_duration_t k_micro_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_milli_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_minute mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_hour mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_day mk_lang_constexpr_init;

	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t days mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t dur mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t hours mk_lang_constexpr_init;
	mk_lang_types_pchar_t zero mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t minutes mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t seconds mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t nanos mk_lang_constexpr_init;
	mk_lang_types_sint_t trailing mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_assert(duration);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	{
		mk_sl_stopwatch_duration_t k_nano_second mk_lang_constexpr_init;
		mk_lang_types_sint_t tsi mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_t tt mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_set_one(&k_nano_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_nano_second, &k_micro_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_micro_second, &k_milli_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_milli_second, &k_second);
		tsi = 60; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_second, &k_minute);
		tsi = 60; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_minute, &k_hour);
		tsi = 24; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_hour, &k_day);
	}

	ptr = str_buf;
	rem = str_len;

	mk_sl_stopwatch_duration_div3_wrap(duration, &k_day, &days);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&days, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	if(!(rem >= 1)){ return 0; } ptr[0] = '+'; ptr += 1; rem -= 1;
	mk_sl_stopwatch_duration_mul2_wrap_lo(&days, &k_day);
	mk_sl_stopwatch_duration_sub3_wrap_cid_cod(duration, &days, &dur);

	mk_sl_stopwatch_duration_div3_wrap(&dur, &k_hour, &hours);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&hours, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 2);
	zero = '0';
	if(len == 1)
	{
		if(!(rem >= 1)){ return 0; }
		ptr[0] = ptr[-1]; ptr += 1; rem -= 1;
		ptr[-2] = zero;
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = ':'; ptr += 1; rem -= 1;
	mk_sl_stopwatch_duration_mul2_wrap_lo(&hours, &k_hour);
	mk_sl_stopwatch_duration_sub2_wrap_cid_cod(&dur, &hours);

	mk_sl_stopwatch_duration_div3_wrap(&dur, &k_minute, &minutes);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&minutes, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 2);
	if(len == 1)
	{
		if(!(rem >= 1)){ return 0; }
		ptr[0] = ptr[-1]; ptr += 1; rem -= 1;
		ptr[-2] = zero;
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = ':'; ptr += 1; rem -= 1;
	mk_sl_stopwatch_duration_mul2_wrap_lo(&minutes, &k_minute);
	mk_sl_stopwatch_duration_sub2_wrap_cid_cod(&dur, &minutes);

	mk_sl_stopwatch_duration_divmod4_wrap(&dur, &k_second, &seconds, &nanos);
	len = mk_sl_stopwatch_duration_to_str_dec_n(&seconds, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= 2);
	if(len == 1)
	{
		if(!(rem >= 1)){ return 0; }
		ptr[0] = ptr[-1]; ptr += 1; rem -= 1;
		ptr[-2] = zero;
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = '.'; ptr += 1; rem -= 1;

	len = mk_sl_stopwatch_duration_to_str_dec_n(&nanos, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len;
	trailing = 9;
	mk_lang_assert(len >= 1); mk_lang_assert(len <= trailing);
	if(len != trailing)
	{
		mk_lang_string_memmov_pc_fn(ptr - len + trailing - len, ptr - len, ((mk_lang_types_usize_t)(len)));
		mk_lang_string_memset_pc_fn(ptr - len, &zero, ((mk_lang_types_usize_t)(trailing - len)));
	}
	len = trailing - len;
	ptr += len; rem -= len;
	n = trailing - 1;
	for(i = 0; i != n; ++i)
	{
		if(ptr[-1] == zero)
		{
			ptr -= 1; rem += 1;
		}
		else
		{
			break;
		}
	}
	if(!(rem >= 1)){ return 0; } ptr[0] = ' '; ptr += 1; rem -= 1;
	if(!(rem >= 1)){ return 0; } ptr[0] = 'd'; ptr += 1; rem -= 1;
	len = str_len - rem;
	return len;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_stopwatch_duration_to_text(mk_sl_stopwatch_duration_pct const duration, mk_lang_types_pchar_pt const str_buf, mk_lang_types_sint_t const str_len) mk_lang_noexcept
{
	mk_sl_stopwatch_duration_t k_micro_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_milli_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_second mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_minute mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_hour mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t k_day mk_lang_constexpr_init;

	mk_lang_types_pchar_pt ptr mk_lang_constexpr_init;
	mk_lang_types_sint_t rem mk_lang_constexpr_init;
	mk_lang_types_bool_t negative mk_lang_constexpr_init;
	mk_sl_stopwatch_duration_t dur mk_lang_constexpr_init;
	mk_lang_types_sint_t len mk_lang_constexpr_init;

	mk_lang_assert(duration);
	mk_lang_assert(str_buf || str_len == 0);
	mk_lang_assert(str_len >= 0);

	{
		mk_sl_stopwatch_duration_t k_nano_second mk_lang_constexpr_init;
		mk_lang_types_sint_t tsi mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_t tt mk_lang_constexpr_init;
		mk_sl_stopwatch_duration_set_one(&k_nano_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_nano_second, &k_micro_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_micro_second, &k_milli_second);
		tsi = 1000; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_milli_second, &k_second);
		tsi = 60; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_second, &k_minute);
		tsi = 60; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_minute, &k_hour);
		tsi = 24; mk_sl_stopwatch_duration_from_bi_sint(&tt, &tsi); mk_sl_stopwatch_duration_mul3_wrap_lo(&tt, &k_hour, &k_day);
	}

	ptr = str_buf; rem = str_len;
	dur = *duration;
	negative = mk_sl_stopwatch_duration_has_msb(&dur);
	if(negative)
	{
		mk_sl_stopwatch_duration_not1(&dur);
		mk_sl_stopwatch_duration_inc1(&dur);
		if(!(rem >= 1)){ return 0; }
		ptr[0] = '-';
		ptr += 1; rem -= 1;
	}
	if     (mk_sl_stopwatch_duration_lt(&dur, &k_micro_second)){ len = mk_sl_stopwatch_duration_pr_to_text_ns(&dur, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len; }
	else if(mk_sl_stopwatch_duration_lt(&dur, &k_milli_second)){ len = mk_sl_stopwatch_duration_pr_to_text_us(&dur, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len; }
	else if(mk_sl_stopwatch_duration_lt(&dur, &k_second      )){ len = mk_sl_stopwatch_duration_pr_to_text_ms(&dur, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len; }
	else if(mk_sl_stopwatch_duration_lt(&dur, &k_minute      )){ len = mk_sl_stopwatch_duration_pr_to_text_s (&dur, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len; }
	else if(mk_sl_stopwatch_duration_lt(&dur, &k_hour        )){ len = mk_sl_stopwatch_duration_pr_to_text_m (&dur, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len; }
	else if(mk_sl_stopwatch_duration_lt(&dur, &k_day         )){ len = mk_sl_stopwatch_duration_pr_to_text_h (&dur, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len; }
	else                                                       { len = mk_sl_stopwatch_duration_pr_to_text_d (&dur, ptr, rem); if(!(len >= 1)){ return len; } mk_lang_assert(len >= 1); mk_lang_assert(len <= rem); ptr += len; rem -= len; }
	len = str_len - rem;
	return len;
}


#endif
