#include "mk_lang_assert.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_pow2.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"


#include "mk_sl_speed_counter_inl_defd.h"


#define mk_lang_memmove_obj_tn mk_lang_concat(mk_sl_speed_counter_inl_defd_prefix, _item)
#define mk_lang_memmove_obj_t mk_sl_speed_counter_inl_defd_item_t
#include "mk_lang_memmove_obj_inl_fileh.h"
#include "mk_lang_memmove_obj_inl_filec.h"
#undef mk_lang_memmove_obj_tn /* todo move this into memmove */
#undef mk_lang_memmove_obj_t


mk_lang_jumbo void mk_sl_speed_counter_inl_defd_construct(mk_sl_speed_counter_inl_defd_pt const counter) mk_lang_noexcept
{
	int granule_count;
	int i;

	mk_lang_static_assert(((mk_lang_types_slllong_t)(mk_sl_speed_counter_t_time_denominator)) > ((mk_lang_types_slllong_t)(0)));
	mk_lang_static_assert(((mk_lang_types_slllong_t)(mk_sl_speed_counter_t_time_granule_size)) > ((mk_lang_types_slllong_t)(0)));
	mk_lang_static_assert(((mk_lang_types_slllong_t)(mk_sl_speed_counter_t_time_granule_size)) < ((mk_lang_types_slllong_t)(mk_sl_speed_counter_t_time_denominator)));
	mk_lang_static_assert(((mk_lang_types_slllong_t)(mk_sl_speed_counter_inl_defd_time_granule_count)) >= ((mk_lang_types_slllong_t)(2)));
	mk_lang_static_assert(((mk_lang_types_slllong_t)(mk_sl_speed_counter_inl_defd_time_granule_count)) <= ((mk_lang_types_slllong_t)(mk_lang_limits_sshort_max)));
	mk_lang_static_assert(mk_lang_pow2_is(((mk_lang_types_sshort_t)(mk_sl_speed_counter_inl_defd_time_granule_count))));

	mk_lang_assert(counter);

	granule_count = ((int)(mk_sl_speed_counter_inl_defd_time_granule_count));
	for(i = 0; i != granule_count; ++i)
	{
		mk_sl_speed_counter_inl_defd_item_set_zero(&counter->m_items_counts[i]);
	}
	mk_sl_speed_counter_inl_defd_item_set_zero(&counter->m_curr_items_count);
	mk_sl_speed_counter_inl_defd_time_set_zero(&counter->m_curr_time_quantized);
}

mk_lang_jumbo void mk_sl_speed_counter_inl_defd_count(mk_sl_speed_counter_inl_defd_pt const counter, mk_sl_speed_counter_inl_defd_item_pct const how_many, mk_sl_speed_counter_inl_defd_time_pct const when) mk_lang_noexcept
{
	int granule_count;
	mk_lang_types_ulllong_t time_granule_size_ulll;
	mk_sl_speed_counter_inl_defd_time_t time_granule_size;
	mk_sl_speed_counter_inl_defd_time_t when_quantized;
	mk_sl_speed_counter_inl_defd_time_t time_quantized_diff;
	mk_lang_types_ulllong_t time_quantized_diff_ulll;
	int time_quantized_diff_i;
	int items_to_move;
	int i;

	mk_lang_assert(counter);
	mk_lang_assert(how_many);
	mk_lang_assert(when);

	granule_count = ((int)(mk_sl_speed_counter_inl_defd_time_granule_count));
	time_granule_size_ulll = mk_sl_speed_counter_inl_defd_time_granule_size;
	mk_sl_speed_counter_inl_defd_time_from_bi_ulllong(&time_granule_size, &time_granule_size_ulll);
	mk_sl_speed_counter_inl_defd_time_div3_wrap(when, &time_granule_size, &when_quantized);
	mk_sl_speed_counter_inl_defd_time_sub3_wrap_cid_cod(&when_quantized, &counter->m_curr_time_quantized, &time_quantized_diff);
	mk_sl_speed_counter_inl_defd_time_to_bi_ulllong(&time_quantized_diff, &time_quantized_diff_ulll);
	if(time_quantized_diff_ulll == ((mk_lang_types_ulllong_t)(0)))
	{
		mk_lang_assert(!mk_sl_speed_counter_inl_defd_item_would_overflow_add_cc(&counter->m_curr_items_count, how_many)); /* too many counts per quantum, todo throw exception? */
		mk_sl_speed_counter_inl_defd_item_add2_wrap_cid_cod(&counter->m_curr_items_count, how_many);
	}
	else if(time_quantized_diff_ulll < ((mk_lang_types_ulllong_t)(granule_count)))
	{
		time_quantized_diff_i = ((int)(time_quantized_diff_ulll));
		mk_lang_assert((time_quantized_diff_i >= 1) && (time_quantized_diff_i <= (granule_count - 1)));
		items_to_move = granule_count - time_quantized_diff_i;
		mk_lang_assert((items_to_move >= 1) && (items_to_move <= (granule_count - 1)));
		mk_sl_speed_counter_inl_defd_item_memmove(&counter->m_items_counts[0], &counter->m_items_counts[time_quantized_diff_i], ((mk_lang_types_usize_t)(items_to_move)));
		for(i = 0; i != time_quantized_diff_i - 1; ++i)
		{
			mk_sl_speed_counter_inl_defd_item_set_zero(&counter->m_items_counts[(granule_count - 1) - 1 - i]);
		}
		counter->m_items_counts[(granule_count - 1)] = counter->m_curr_items_count;
		counter->m_curr_items_count = *how_many;
		counter->m_curr_time_quantized = when_quantized;
	}
	else
	{
		for(i = 0; i != granule_count; ++i)
		{
			mk_sl_speed_counter_inl_defd_item_set_zero(&counter->m_items_counts[i]);
		}
		counter->m_curr_items_count = *how_many;
		counter->m_curr_time_quantized = when_quantized;
	}
}

mk_lang_jumbo void mk_sl_speed_counter_inl_defd_get_time_quantized(mk_sl_speed_counter_inl_defd_pct const counter, mk_sl_speed_counter_inl_defd_time_pt const time_quantized) mk_lang_noexcept
{
	mk_lang_assert(counter);
	mk_lang_assert(time_quantized);

	*time_quantized = counter->m_curr_time_quantized;
}

mk_lang_jumbo void mk_sl_speed_counter_inl_defd_get_speed(mk_sl_speed_counter_inl_defd_pct const counter, mk_sl_speed_counter_inl_defd_item_pt const speed) mk_lang_noexcept
{
	int granule_count;
	int i;
	unsigned int tui;
	mk_lang_types_bool_t bita;
	mk_lang_types_bool_t bitb;
	mk_sl_speed_counter_inl_defd_item_t ta;
	mk_sl_speed_counter_inl_defd_item_t tb;
	mk_sl_speed_counter_inl_defd_item_pct src;
	int n;
	mk_sl_speed_counter_inl_defd_item_t items_counts[mk_sl_speed_counter_inl_defd_time_granule_count / 2];

	mk_lang_assert(counter);
	mk_lang_assert(speed);

	granule_count = ((int)(mk_sl_speed_counter_inl_defd_time_granule_count));
	src = counter->m_items_counts;
	n = granule_count / 2;
	while(n != 0)
	{
		for(i = 0; i != n; ++i)
		{
			mk_sl_speed_counter_inl_defd_item_to_bi_uint(&src[i * 2 + 0], &tui); bita = ((tui & 0x1u) != 0u);
			mk_sl_speed_counter_inl_defd_item_to_bi_uint(&src[i * 2 + 1], &tui); bitb = ((tui & 0x1u) != 0u);
			mk_sl_speed_counter_inl_defd_item_shr3(&src[i * 2 + 0], 1, &ta);
			mk_sl_speed_counter_inl_defd_item_shr3(&src[i * 2 + 1], 1, &tb);
			mk_lang_assert(!mk_sl_speed_counter_inl_defd_item_would_overflow_add_cc(&ta, &tb));
			mk_sl_speed_counter_inl_defd_item_add3_wrap_cid_cod(&ta, &tb, &items_counts[i]);
			mk_lang_assert(!mk_sl_speed_counter_inl_defd_item_is_max(&items_counts[i]));
			if(bita && bitb) mk_sl_speed_counter_inl_defd_item_inc1(&items_counts[i]);
		}
		src = items_counts;
		n /= 2;
	}
	tui = ((unsigned int)(((mk_lang_types_ulllong_t)(mk_sl_speed_counter_inl_defd_time_denominator)) / ((mk_lang_types_ulllong_t)(mk_sl_speed_counter_inl_defd_time_granule_size))));
	mk_sl_speed_counter_inl_defd_item_from_bi_uint(&ta, &tui);
	mk_sl_speed_counter_inl_defd_item_mul3_wrap_lo(&items_counts[0], &ta, speed);
}


#include "mk_sl_speed_counter_inl_defu.h"


#undef mk_sl_speed_counter_t_name
#undef mk_sl_speed_counter_t_item_prefix
#undef mk_sl_speed_counter_t_time_prefix
#undef mk_sl_speed_counter_t_time_denominator
#undef mk_sl_speed_counter_t_time_granule_size
#undef mk_sl_speed_counter_t_time_granule_count
