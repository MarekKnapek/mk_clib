#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_log2.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


#include "mk_sl_averager_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_st_round_time(mk_sl_averager_inl_defd_timer_pt const time) mk_lang_noexcept
{
	mk_sl_averager_inl_defd_timer_t granule mk_lang_constexpr_init;

	mk_lang_assert(time);

	granule = mk_sl_averager_inl_defd_period_chunk;
	mk_sl_averager_inl_defd_timer_div2_wrap(time, &granule);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_ro_compute(mk_sl_averager_inl_defd_pt const averager, mk_sl_averager_inl_defd_counter_pt const count) mk_lang_noexcept
{
	mk_sl_averager_inl_defd_counter_t suma mk_lang_constexpr_init;
	mk_sl_averager_inl_defd_counter_t sumb mk_lang_constexpr_init;
	mk_lang_types_sint_t bits mk_lang_constexpr_init;
	mk_sl_averager_inl_defd_counter_t mask mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_averager_inl_defd_counter_t ta mk_lang_constexpr_init;
	mk_sl_averager_inl_defd_counter_t tb mk_lang_constexpr_init;

	mk_lang_assert(averager);
	mk_lang_assert(count);

	mk_sl_averager_inl_defd_counter_set_zero(&suma);
	mk_sl_averager_inl_defd_counter_set_zero(&sumb);
	bits = mk_lang_log2(mk_sl_averager_inl_defd_history / mk_sl_averager_inl_defd_count);
	mk_sl_averager_inl_defd_counter_set_mask(&mask, bits);
	n = mk_sl_averager_inl_defd_history;
	for(i = 0; i != n; ++i)
	{
		mk_sl_averager_inl_defd_counter_shr3(&averager->m_buff[i], bits, &ta);
		mk_sl_averager_inl_defd_counter_and3(&averager->m_buff[i], &mask, &tb);
		mk_lang_assert(!mk_sl_averager_inl_defd_counter_would_overflow_add_cc(&suma, &ta));
		mk_lang_assert(!mk_sl_averager_inl_defd_counter_would_overflow_add_cc(&sumb, &tb));
		mk_sl_averager_inl_defd_counter_add2_wrap_cid_cod(&suma, &ta);
		mk_sl_averager_inl_defd_counter_add2_wrap_cid_cod(&sumb, &tb);
	}
	mk_sl_averager_inl_defd_counter_shr2(&sumb, bits);
	mk_lang_assert(!mk_sl_averager_inl_defd_counter_would_overflow_add_cc(&suma, &sumb));
	mk_sl_averager_inl_defd_counter_add3_wrap_cid_cod(&suma, &sumb, count);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_rw_construct(mk_sl_averager_inl_defd_pt const averager) mk_lang_noexcept
{
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_averager_inl_defd_history >= 2);
	mk_lang_static_assert(mk_sl_averager_inl_defd_history <= 256);
	mk_lang_static_assert(mk_sl_averager_inl_defd_count <= mk_sl_averager_inl_defd_history);
	mk_lang_static_assert(mk_lang_pow2_is(mk_sl_averager_inl_defd_history));
	mk_lang_static_assert(mk_lang_pow2_is(mk_sl_averager_inl_defd_history / mk_sl_averager_inl_defd_count));

	mk_lang_assert(averager);

	n = mk_sl_averager_inl_defd_history;
	for(i = 0; i != n; ++i)
	{
		mk_sl_averager_inl_defd_counter_set_zero(&averager->m_buff[i]);
	}
	mk_sl_averager_inl_defd_counter_set_zero(&averager->m_curr_cnt);
	mk_sl_averager_inl_defd_timer_set_zero(&averager->m_curr_time);
	averager->m_idx = 0;
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_rw_add_prepare(mk_sl_averager_inl_defd_pt const averager, mk_sl_averager_inl_defd_timer_pct const time) mk_lang_noexcept
{
	mk_sl_averager_inl_defd_timer_t timer_diff mk_lang_constexpr_init;
	mk_lang_types_sint_t tsi mk_lang_constexpr_init;
	mk_sl_averager_inl_defd_timer_t timer_tmp mk_lang_constexpr_init;
	mk_lang_types_sint_t n mk_lang_constexpr_init;
	mk_lang_types_sint_t i mk_lang_constexpr_init;
	mk_sl_averager_inl_defd_counter_t counter mk_lang_constexpr_init;

	mk_lang_assert(averager);
	mk_lang_assert(time);

	if(mk_sl_averager_inl_defd_timer_ne(time, &averager->m_curr_time))
	{
		mk_sl_averager_inl_defd_timer_sub3_wrap_cid_cod(time, &averager->m_curr_time, &timer_diff);
		tsi = mk_sl_averager_inl_defd_history;
		mk_sl_averager_inl_defd_timer_from_bi_sint(&timer_tmp, &tsi);
		if(mk_sl_averager_inl_defd_timer_gt(&timer_diff, &timer_tmp)){ timer_diff = timer_tmp; }
		mk_sl_averager_inl_defd_timer_to_bi_sint(&timer_diff, &n);
		mk_lang_assert(n >= 1 && n <= mk_sl_averager_inl_defd_history);
		for(i = 0; i != n - 1; ++i)
		{
			averager->m_idx = (averager->m_idx + 1) & (mk_sl_averager_inl_defd_history - 1);
			mk_sl_averager_inl_defd_counter_set_zero(&averager->m_buff[averager->m_idx]);
		}
		averager->m_idx = (averager->m_idx + 1) & (mk_sl_averager_inl_defd_history - 1);
		averager->m_buff[averager->m_idx] = averager->m_curr_cnt;
		mk_sl_averager_inl_defd_counter_set_zero(&averager->m_curr_cnt);
		averager->m_curr_time = *time;
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_rw_add_one(mk_sl_averager_inl_defd_pt const averager, mk_sl_averager_inl_defd_timer_pct const time) mk_lang_noexcept
{
	mk_lang_assert(averager);
	mk_lang_assert(time);

	mk_sl_averager_inl_defd_rw_add_prepare(averager, time);
	mk_sl_averager_inl_defd_counter_inc1(&averager->m_curr_cnt); /* todo inc1_sat */ if(mk_sl_averager_inl_defd_counter_is_zero(&averager->m_curr_cnt)){ mk_sl_averager_inl_defd_counter_dec1(&averager->m_curr_cnt); }
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_averager_inl_defd_rw_add_n(mk_sl_averager_inl_defd_pt const averager, mk_sl_averager_inl_defd_timer_pct const time, mk_sl_averager_inl_defd_counter_pct const count) mk_lang_noexcept
{
	mk_lang_assert(averager);
	mk_lang_assert(time);

	mk_sl_averager_inl_defd_rw_add_prepare(averager, time);
	mk_sl_averager_inl_defd_counter_add2_wrap_cid_cod(&averager->m_curr_cnt, count); /* todo add_sat */
}


#include "mk_sl_vector_inl_defu.h"


#undef mk_sl_averager_t_name
#undef mk_sl_averager_t_count
#undef mk_sl_averager_t_history
#undef mk_sl_averager_t_timer_tnb
#undef mk_sl_averager_t_counter_tnb
#undef mk_sl_averager_t_period_chunk
