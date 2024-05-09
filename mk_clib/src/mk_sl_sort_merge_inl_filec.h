#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"


#include "mk_sl_sort_merge_inl_defd.h"


#define mk_sl_sort_merge_overlap_data_name mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _overlap_data)
#define mk_sl_sort_merge_overlap_data_fn mk_lang_concat(mk_sl_sort_merge_overlap_data_name, _fn)
#define mk_lang_overlap_t_name mk_sl_sort_merge_overlap_data_name
#define mk_lang_overlap_t_base mk_sl_sort_merge_inl_defd_data
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"

#define mk_sl_sort_merge_memcpy_data_name mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _memcpy_data)
#define mk_sl_sort_merge_memcpy_data_fn mk_lang_concat(mk_sl_sort_merge_memcpy_data_name, _fn)
#define mk_lang_memcpy_t_name mk_sl_sort_merge_memcpy_data_name
#define mk_lang_memcpy_t_base mk_sl_sort_merge_inl_defd_data
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_sl_sort_merge_swap_data_name mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _swap_data)
#define mk_sl_sort_merge_swap_data_fn mk_lang_concat(mk_sl_sort_merge_swap_data_name, _fn)
#define mk_lang_swap_t_name mk_sl_sort_merge_swap_data_name
#define mk_lang_swap_t_base mk_sl_sort_merge_inl_defd_data
#include "mk_lang_swap_inl_fileh.h"
#include "mk_lang_swap_inl_filec.h"

#define mk_sl_sort_merge_overlap_proxy_name mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _overlap_proxy)
#define mk_sl_sort_merge_overlap_proxy_fn mk_lang_concat(mk_sl_sort_merge_overlap_proxy_name, _fn)
#define mk_lang_overlap_t_name mk_sl_sort_merge_overlap_proxy_name
#define mk_lang_overlap_t_base mk_sl_sort_merge_inl_defd_proxy
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"

#define mk_sl_sort_merge_memcpy_proxy_name mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _memcpy_proxy)
#define mk_sl_sort_merge_memcpy_proxy_fn mk_lang_concat(mk_sl_sort_merge_memcpy_proxy_name, _fn)
#define mk_lang_memcpy_t_name mk_sl_sort_merge_memcpy_proxy_name
#define mk_lang_memcpy_t_base mk_sl_sort_merge_inl_defd_proxy
#include "mk_lang_memcpy_inl_fileh.h"
#include "mk_lang_memcpy_inl_filec.h"

#define mk_sl_sort_merge_swap_proxy_name mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _swap_proxy)
#define mk_sl_sort_merge_swap_proxy_fn mk_lang_concat(mk_sl_sort_merge_swap_proxy_name, _fn)
#define mk_lang_swap_t_name mk_sl_sort_merge_swap_proxy_name
#define mk_lang_swap_t_base mk_sl_sort_merge_inl_defd_proxy
#include "mk_lang_swap_inl_fileh.h"
#include "mk_lang_swap_inl_filec.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_merge_plain(mk_sl_sort_merge_inl_defd_data_pct const input_a, mk_sl_sort_merge_inl_defd_counter_t const count_a, mk_sl_sort_merge_inl_defd_data_pct const input_b, mk_sl_sort_merge_inl_defd_counter_t const count_b, mk_sl_sort_merge_inl_defd_data_pt const output) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t idx_a mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t idx_b mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t idx_o mk_lang_constexpr_init;

	mk_lang_assert(input_a);
	mk_lang_assert(count_a >= 1);
	mk_lang_assert(input_b);
	mk_lang_assert(count_b >= 1);
	mk_lang_assert(output);
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(input_a, count_a, input_b, count_b));
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(input_a, count_a, output, count_a + count_b));
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(input_b, count_b, output, count_a + count_b));

	idx_a = 0;
	idx_b = 0;
	idx_o = 0;
	while(idx_a != count_a && idx_b != count_b)
	{
		if(mk_sl_sort_merge_inl_defd_fn_is_sorted_plain(&input_a[idx_a], &input_b[idx_b]))
		{
			output[idx_o++] = input_a[idx_a++];
		}
		else
		{
			output[idx_o++] = input_b[idx_b++];
		}
	}
	mk_sl_sort_merge_memcpy_data_fn(&output[idx_o], &input_a[idx_a], count_a - idx_a); idx_o += count_a - idx_a; idx_a += count_a - idx_a;
	mk_sl_sort_merge_memcpy_data_fn(&output[idx_o], &input_b[idx_b], count_b - idx_b); idx_o += count_b - idx_b; idx_b += count_b - idx_b;
	mk_lang_assert(idx_a == count_a);
	mk_lang_assert(idx_b == count_b);
	mk_lang_assert(idx_o == count_a + count_b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_merge_proxy(mk_sl_sort_merge_inl_defd_data_pct const data, mk_sl_sort_merge_inl_defd_proxy_pct const input_a, mk_sl_sort_merge_inl_defd_counter_t const count_a, mk_sl_sort_merge_inl_defd_proxy_pct const input_b, mk_sl_sort_merge_inl_defd_counter_t const count_b, mk_sl_sort_merge_inl_defd_proxy_pt const output) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t idx_a mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t idx_b mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t idx_o mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(input_a);
	mk_lang_assert(count_a >= 1);
	mk_lang_assert(input_b);
	mk_lang_assert(count_b >= 1);
	mk_lang_assert(output);
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-input_a */
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-input_b */
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-output */
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(input_a, count_a, input_b, count_b));
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(input_a, count_a, output, count_a + count_b));
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(input_b, count_b, output, count_a + count_b));

	idx_a = 0;
	idx_b = 0;
	idx_o = 0;
	while(idx_a != count_a && idx_b != count_b)
	{
		if(mk_sl_sort_merge_inl_defd_fn_is_sorted_proxy(&data[input_a[idx_a]], &data[input_b[idx_b]]))
		{
			output[idx_o++] = input_a[idx_a++];
		}
		else
		{
			output[idx_o++] = input_b[idx_b++];
		}
	}
	mk_sl_sort_merge_memcpy_proxy_fn(&output[idx_o], &input_a[idx_a], count_a - idx_a); idx_o += count_a - idx_a; idx_a += count_a - idx_a;
	mk_sl_sort_merge_memcpy_proxy_fn(&output[idx_o], &input_b[idx_b], count_b - idx_b); idx_o += count_b - idx_b; idx_b += count_b - idx_b;
	mk_lang_assert(idx_a == count_a);
	mk_lang_assert(idx_b == count_b);
	mk_lang_assert(idx_o == count_a + count_b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_first_round_plain_inplace(mk_sl_sort_merge_inl_defd_data_pt const data, mk_sl_sort_merge_inl_defd_counter_t const count) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pt a mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pt b mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 2);

	for(i = 0; i != count / 2; ++i)
	{
		a = &data[i * 2 + 0];
		b = &data[i * 2 + 1];
		if(!mk_sl_sort_merge_inl_defd_fn_is_sorted_plain(a, b))
		{
			mk_sl_sort_merge_swap_data_fn(a, b);
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_first_round_plain_copy(mk_sl_sort_merge_inl_defd_data_pct const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_data_pt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pct ai mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pct bi mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pt ao mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pt bo mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 3);
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(data, count, tmp, count));

	for(i = 0; i != count / 2; ++i)
	{
		ai = &data[i * 2 + 0];
		bi = &data[i * 2 + 1];
		ao = &tmp[i * 2 + 0];
		bo = &tmp[i * 2 + 1];
		if(mk_sl_sort_merge_inl_defd_fn_is_sorted_plain(ai, bi))
		{
			*ao = *ai;
			*bo = *bi;
		}
		else
		{
			*ao = *bi;
			*bo = *ai;
		}
	}
	if(count % 2 != 0)
	{
		tmp[count - 1] = data[count - 1];
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_inl_defd_fn_first_round_plain(mk_sl_sort_merge_inl_defd_data_pt const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_data_pt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t cnt mk_lang_constexpr_init;
	mk_lang_types_sint_t clz mk_lang_constexpr_init;
	mk_lang_types_bool_t r mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 3);
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(data, count, tmp, count));

	mk_sl_sort_merge_inl_defd_counter_dec2(&count, &cnt);
	clz = mk_sl_sort_merge_inl_defd_counter_count_leading_zeros(&cnt);
	r = clz % 2 == 0;
	if(r)
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_plain_copy(data, count, tmp);
	}
	else
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_plain_inplace(data, count);
	}
	return r;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_first_round_proxy_inplace(mk_sl_sort_merge_inl_defd_data_pct const data, mk_sl_sort_merge_inl_defd_proxy_pt const proxy, mk_sl_sort_merge_inl_defd_counter_t const count) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_pt a mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_pt b mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pct c mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pct d mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 2);

	for(i = 0; i != count / 2; ++i)
	{
		a = &proxy[i * 2 + 0];
		b = &proxy[i * 2 + 1];
		c = &data[*a];
		d = &data[*b];
		if(!mk_sl_sort_merge_inl_defd_fn_is_sorted_proxy(c, d))
		{
			mk_sl_sort_merge_swap_proxy_fn(a, b);
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_first_round_proxy_copy(mk_sl_sort_merge_inl_defd_data_pct const data, mk_sl_sort_merge_inl_defd_proxy_pt const proxy, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_proxy_pt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_pct ai mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_pct bi mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pct c mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pct d mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_pt ao mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_pt bo mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(proxy);
	mk_lang_assert(count >= 3);
	mk_lang_assert(tmp);
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-proxy and data-tmp */
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(proxy, count, tmp, count));

	for(i = 0; i != count / 2; ++i)
	{
		ai = &proxy[i * 2 + 0];
		bi = &proxy[i * 2 + 1];
		c = &data[*ai];
		d = &data[*bi];
		ao = &tmp[i * 2 + 0];
		bo = &tmp[i * 2 + 1];
		if(mk_sl_sort_merge_inl_defd_fn_is_sorted_plain(c, d))
		{
			*ao = *ai;
			*bo = *bi;
		}
		else
		{
			*ao = *bi;
			*bo = *ai;
		}
	}
	if(count % 2 != 0)
	{
		tmp[count - 1] = proxy[count - 1];
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_inl_defd_fn_first_round_proxy(mk_sl_sort_merge_inl_defd_data_pct const data, mk_sl_sort_merge_inl_defd_proxy_pt const proxy, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_proxy_pt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t cnt mk_lang_constexpr_init;
	mk_lang_types_sint_t clz mk_lang_constexpr_init;
	mk_lang_types_bool_t r mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 2);
	mk_lang_assert(tmp);
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-proxy and data-tmp */
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(proxy, count, tmp, count));

	mk_sl_sort_merge_inl_defd_counter_dec2(&count, &cnt);
	clz = mk_sl_sort_merge_inl_defd_counter_count_leading_zeros(&cnt);
	r = clz % 2 == 0;
	if(r)
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_proxy_copy(data, proxy, count, tmp);
	}
	else
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_proxy_inplace(data, proxy, count);
	}
	return r;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_plain_many(mk_sl_sort_merge_inl_defd_data_pt const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_data_pt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_data_pt in mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pt out mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t chunk_size mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t block_size mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pt t mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t block_count mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t rest mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 3);
	mk_lang_assert(count <= ((mk_sl_sort_merge_inl_defd_counter_t)(((mk_sl_sort_merge_inl_defd_counter_t)(~((mk_sl_sort_merge_inl_defd_counter_t)(0)))) / ((mk_sl_sort_merge_inl_defd_counter_t)(2)))));
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(data, count, tmp, count));

	in = data;
	out = tmp;
	#if mk_sl_sort_merge_inl_defd_first_round
	if(mk_sl_sort_merge_inl_defd_fn_first_round_plain(data, count, tmp)){ t = in, in = out, out = t; }
	chunk_size = 2;
	#else
	chunk_size = 1;
	#endif
	for(block_size = chunk_size * 2; block_size < count; chunk_size *= 2, block_size *= 2, t = in, in = out, out = t)
	{
		block_count = count / block_size;
		rest = count - (block_count * block_size);
		for(i = 0; i != block_count; ++i)
		{
			mk_sl_sort_merge_inl_defd_fn_merge_plain(&in[i * block_size + 0 * chunk_size], chunk_size, &in[i * block_size + 1 * chunk_size], chunk_size, &out[i * block_size]);
		}
		if(rest > chunk_size)
		{
			rest = rest - chunk_size;
			mk_sl_sort_merge_inl_defd_fn_merge_plain(&in[i * block_size + 0 * chunk_size], chunk_size, &in[i * block_size + 1 * chunk_size], rest, &out[i * block_size]);
		}
		else
		{
			mk_sl_sort_merge_memcpy_data_fn(&out[i * block_size], &in[i * block_size], rest);
		}
	}
	mk_lang_assert(count > chunk_size);
	rest = count - chunk_size;
	mk_sl_sort_merge_inl_defd_fn_merge_plain(&in[0 * chunk_size], chunk_size, &in[1 * chunk_size], rest, &out[0]);
	#if mk_sl_sort_merge_inl_defd_first_round
	mk_lang_assert(out == data);
	#else
	if(out != data){ mk_sl_sort_merge_memcpy_data_fn(&data[0], &out[0], count); }
	#endif
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_proxy_many(mk_sl_sort_merge_inl_defd_data_pct const data, mk_sl_sort_merge_inl_defd_proxy_pt const proxy, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_proxy_pt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_proxy_pt in mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_pt out mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t chunk_size mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t block_size mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_pt t mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t block_count mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t rest mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(proxy);
	mk_lang_assert(count >= 3);
	mk_lang_assert(count <= ((mk_sl_sort_merge_inl_defd_counter_t)(((mk_sl_sort_merge_inl_defd_counter_t)(~((mk_sl_sort_merge_inl_defd_counter_t)(0)))) / ((mk_sl_sort_merge_inl_defd_counter_t)(2)))));
	mk_lang_assert(tmp);
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-proxy and data-tmp */
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(proxy, count, tmp, count));

	in = proxy;
	out = tmp;
	#if mk_sl_sort_merge_inl_defd_first_round
	if(mk_sl_sort_merge_inl_defd_fn_first_round_proxy(data, proxy, count, tmp)){ t = in, in = out, out = t; }
	chunk_size = 2;
	#else
	chunk_size = 1;
	#endif
	for(block_size = chunk_size * 2; block_size < count; chunk_size *= 2, block_size *= 2, t = in, in = out, out = t)
	{
		block_count = count / block_size;
		rest = count - (block_count * block_size);
		for(i = 0; i != block_count; ++i)
		{
			mk_sl_sort_merge_inl_defd_fn_merge_proxy(data, &in[i * block_size + 0 * chunk_size], chunk_size, &in[i * block_size + 1 * chunk_size], chunk_size, &out[i * block_size]);
		}
		if(rest > chunk_size)
		{
			rest = rest - chunk_size;
			mk_sl_sort_merge_inl_defd_fn_merge_proxy(data, &in[i * block_size + 0 * chunk_size], chunk_size, &in[i * block_size + 1 * chunk_size], rest, &out[i * block_size]);
		}
		else
		{
			mk_sl_sort_merge_memcpy_proxy_fn(&out[i * block_size], &in[i * block_size], rest);
		}
	}
	mk_lang_assert(count > chunk_size);
	rest = count - chunk_size;
	mk_sl_sort_merge_inl_defd_fn_merge_proxy(data, &in[0 * chunk_size], chunk_size, &in[1 * chunk_size], rest, &out[0]);
	#if mk_sl_sort_merge_inl_defd_first_round
	mk_lang_assert(out == proxy);
	#else
	if(out != proxy){ mk_sl_sort_merge_memcpy_proxy_fn(&proxy[0], &out[0], count); }
	#endif
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_plain(mk_sl_sort_merge_inl_defd_data_pt const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_data_pt const tmp) mk_lang_noexcept
{
	mk_lang_assert(data);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= ((mk_sl_sort_merge_inl_defd_counter_t)(((mk_sl_sort_merge_inl_defd_counter_t)(~((mk_sl_sort_merge_inl_defd_counter_t)(0)))) / ((mk_sl_sort_merge_inl_defd_counter_t)(2)))));
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(data, count, tmp, count));

	if(count <= 1)
	{
	}
	else if(count == 2)
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_plain_inplace(data, 2);
	}
	else
	{
		mk_sl_sort_merge_inl_defd_fn_plain_many(data, count, tmp);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_proxy(mk_sl_sort_merge_inl_defd_data_pct const data, mk_sl_sort_merge_inl_defd_proxy_pt const proxy, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_proxy_pt const tmp) mk_lang_noexcept
{
	mk_lang_assert(data);
	mk_lang_assert(proxy);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= ((mk_sl_sort_merge_inl_defd_counter_t)(((mk_sl_sort_merge_inl_defd_counter_t)(~((mk_sl_sort_merge_inl_defd_counter_t)(0)))) / ((mk_sl_sort_merge_inl_defd_counter_t)(2)))));
	mk_lang_assert(tmp);
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-proxy and data-tmp */
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(proxy, count, tmp, count));

	if(count <= 1)
	{
	}
	else if(count == 2)
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_proxy_inplace(data, proxy, 2);
	}
	else
	{
		mk_sl_sort_merge_inl_defd_fn_proxy_many(data, proxy, count, tmp);
	}
}


#undef mk_sl_sort_merge_overlap_data_name
#undef mk_sl_sort_merge_overlap_data_fn
#undef mk_sl_sort_merge_memcpy_data_name
#undef mk_sl_sort_merge_memcpy_data_fn
#undef mk_sl_sort_merge_swap_data_name
#undef mk_sl_sort_merge_swap_data_fn
#undef mk_sl_sort_merge_overlap_proxy_name
#undef mk_sl_sort_merge_overlap_proxy_fn
#undef mk_sl_sort_merge_memcpy_proxy_name
#undef mk_sl_sort_merge_memcpy_proxy_fn
#undef mk_sl_sort_merge_swap_proxy_name
#undef mk_sl_sort_merge_swap_proxy_fn


#include "mk_sl_sort_merge_inl_defu.h"


#undef mk_sl_sort_merge_t_name
#undef mk_sl_sort_merge_t_data
#undef mk_sl_sort_merge_t_counter
#undef mk_sl_sort_merge_t_is_sorted
#undef mk_sl_sort_merge_t_first_round
#undef mk_sl_sort_merge_t_proxy
