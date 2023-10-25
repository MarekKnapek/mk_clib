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

#define mk_sl_sort_merge_overlap_proxy_name mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _overlap_proxy)
#define mk_sl_sort_merge_overlap_proxy_fn mk_lang_concat(mk_sl_sort_merge_overlap_proxy_name, _fn)
#define mk_lang_overlap_t_name mk_sl_sort_merge_overlap_proxy_name
#define mk_lang_overlap_t_base mk_sl_sort_merge_inl_defd_proxy
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"


mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_merge_plain(mk_sl_sort_merge_inl_defd_data_prct const input_a, mk_sl_sort_merge_inl_defd_counter_t const count_a, mk_sl_sort_merge_inl_defd_data_prct const input_b, mk_sl_sort_merge_inl_defd_counter_t const count_b, mk_sl_sort_merge_inl_defd_data_prt const output) mk_lang_noexcept
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
	while(idx_a != count_a)
	{
		output[idx_o++] = input_a[idx_a++];
	}
	while(idx_b != count_b)
	{
		output[idx_o++] = input_b[idx_b++];
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_merge_proxy(mk_sl_sort_merge_inl_defd_data_prct const data, mk_sl_sort_merge_inl_defd_proxy_prct const input_a, mk_sl_sort_merge_inl_defd_counter_t const count_a, mk_sl_sort_merge_inl_defd_proxy_prct const input_b, mk_sl_sort_merge_inl_defd_counter_t const count_b, mk_sl_sort_merge_inl_defd_proxy_prt const output) mk_lang_noexcept
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
	while(idx_a != count_a)
	{
		output[idx_o++] = input_a[idx_a++];
	}
	while(idx_b != count_b)
	{
		output[idx_o++] = input_b[idx_b++];
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_first_round_plain_inplace(mk_sl_sort_merge_inl_defd_data_prt const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_data_prt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_t t mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 2);
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(data, count, tmp, count));

	for(i = 0; i != count / 2; ++i)
	{
		if(!mk_sl_sort_merge_inl_defd_fn_is_sorted_plain(&data[i * 2 + 0], &data[i * 2 + 1]))
		{
			t = data[i * 2 + 0];
			data[i * 2 + 0] = data[i * 2 + 1];
			data[i * 2 + 1] = t;
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_first_round_plain_copy(mk_sl_sort_merge_inl_defd_data_prt const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_data_prt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 2);
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(data, count, tmp, count));

	for(i = 0; i != count / 2; ++i)
	{
		if(mk_sl_sort_merge_inl_defd_fn_is_sorted_plain(&data[i * 2 + 0], &data[i * 2 + 1]))
		{
			tmp[i * 2 + 0] = data[i * 2 + 0];
			tmp[i * 2 + 1] = data[i * 2 + 1];
		}
		else
		{
			tmp[i * 2 + 0] = data[i * 2 + 1];
			tmp[i * 2 + 1] = data[i * 2 + 0];
		}
	}
	if(count % 2 != 0)
	{
		tmp[count - 1] = data[count - 1];
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_bool_t mk_sl_sort_merge_inl_defd_fn_first_round_plain(mk_sl_sort_merge_inl_defd_data_prt const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_data_prt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t cnt mk_lang_constexpr_init;
	int clz mk_lang_constexpr_init;
	mk_lang_bool_t r mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 2);
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(data, count, tmp, count));

	cnt = count - 1;
	clz = mk_sl_sort_merge_inl_defd_counter_count_leading_zeros(&cnt);
	r = clz % 2 == 0;
	if(r)
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_plain_copy(data, count, tmp);
	}
	else
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_plain_inplace(data, count, tmp);
	}
	return r;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_first_round_proxy_inplace(mk_sl_sort_merge_inl_defd_data_prct const data, mk_sl_sort_merge_inl_defd_proxy_prt const proxy, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_proxy_prt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_t t mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 2);
	mk_lang_assert(tmp);
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-proxy and data-tmp */
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(proxy, count, tmp, count));

	for(i = 0; i != count / 2; ++i)
	{
		if(!mk_sl_sort_merge_inl_defd_fn_is_sorted_proxy(&data[proxy[i * 2 + 0]], &data[proxy[i * 2 + 1]]))
		{
			t = proxy[i * 2 + 0];
			proxy[i * 2 + 0] = proxy[i * 2 + 1];
			proxy[i * 2 + 1] = t;
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_first_round_proxy_copy(mk_sl_sort_merge_inl_defd_data_prct const data, mk_sl_sort_merge_inl_defd_proxy_prt const proxy, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_proxy_prt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 2);
	mk_lang_assert(tmp);
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-proxy and data-tmp */
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(proxy, count, tmp, count));

	for(i = 0; i != count / 2; ++i)
	{
		if(mk_sl_sort_merge_inl_defd_fn_is_sorted_proxy(&data[proxy[i * 2 + 0]], &data[proxy[i * 2 + 1]]))
		{
			tmp[i * 2 + 0] = proxy[i * 2 + 0];
			tmp[i * 2 + 1] = proxy[i * 2 + 1];
		}
		else
		{
			tmp[i * 2 + 0] = proxy[i * 2 + 1];
			tmp[i * 2 + 1] = proxy[i * 2 + 0];
		}
	}
	if(count % 2 != 0)
	{
		tmp[count - 1] = proxy[count - 1];
	}
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_bool_t mk_sl_sort_merge_inl_defd_fn_first_round_proxy(mk_sl_sort_merge_inl_defd_data_prct const data, mk_sl_sort_merge_inl_defd_proxy_prt const proxy, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_proxy_prt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t cnt mk_lang_constexpr_init;
	int clz mk_lang_constexpr_init;
	mk_lang_bool_t r mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 2);
	mk_lang_assert(tmp);
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-proxy and data-tmp */
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(proxy, count, tmp, count));

	cnt = count - 1;
	clz = mk_sl_sort_merge_inl_defd_counter_count_leading_zeros(&cnt);
	r = clz % 2 == 0;
	if(r)
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_proxy_copy(data, proxy, count, tmp);
	}
	else
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_proxy_inplace(data, proxy, count, tmp);
	}
	return r;
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_plain(mk_sl_sort_merge_inl_defd_data_prt const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_data_prt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_data_pt in mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pt out mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t chunk_size mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t block_size mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_data_pt t mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t block_count mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t rest mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t j mk_lang_constexpr_init;

	mk_lang_assert(data);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= ((mk_sl_sort_merge_inl_defd_counter_t)(((mk_sl_sort_merge_inl_defd_counter_t)(~((mk_sl_sort_merge_inl_defd_counter_t)(0)))) / ((mk_sl_sort_merge_inl_defd_counter_t)(2)))));
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_data_fn(data, count, tmp, count));

	if(count <= 1)
	{
		return;
	}
	else if(count == 2)
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_plain_inplace(data, 2, tmp);
		return;
	}
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
			mk_sl_sort_merge_inl_defd_fn_merge_plain(&in[i * block_size], chunk_size, &in[i * block_size + chunk_size], chunk_size, &out[i * block_size]);
		}
		if(rest > chunk_size)
		{
			rest = rest - chunk_size;
			mk_sl_sort_merge_inl_defd_fn_merge_plain(&in[i * block_size], chunk_size, &in[i * block_size + chunk_size], rest, &out[i * block_size]);
		}
		else
		{
			for(j = 0; j != rest; ++j){ out[i * block_size + j] = in[i * block_size + j]; }
		}
	}
	mk_lang_assert(count > chunk_size);
	rest = count - chunk_size;
	mk_sl_sort_merge_inl_defd_fn_merge_plain(&in[0], chunk_size, &in[chunk_size], rest, &out[0]);
	#if mk_sl_sort_merge_inl_defd_first_round
	mk_lang_assert(out == data);
	#else
	if(out != data){ for(i = 0; i != count; ++i){ data[i] = out[i]; } }
	#endif
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn_proxy(mk_sl_sort_merge_inl_defd_data_prct const data, mk_sl_sort_merge_inl_defd_proxy_prt const proxy, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_proxy_prt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_proxy_pt in mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_pt out mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t chunk_size mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t block_size mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_proxy_pt t mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t block_count mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t rest mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t j mk_lang_constexpr_init;

	#if defined _MSC_VER && _MSC_VER == 1936
	#pragma warning(push)
	#pragma warning(disable:4296) /* warning C4296: '>=': expression is always true */
	#endif

	mk_lang_assert(data);
	mk_lang_assert(proxy);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= ((mk_sl_sort_merge_inl_defd_counter_t)(((mk_sl_sort_merge_inl_defd_counter_t)(~((mk_sl_sort_merge_inl_defd_counter_t)(0)))) / ((mk_sl_sort_merge_inl_defd_counter_t)(2)))));
	mk_lang_assert(tmp);
	/* todo if data type is the same as proxy type (but it usually is not), then also check for overlap with data-proxy and data-tmp */
	mk_lang_assert(!mk_sl_sort_merge_overlap_proxy_fn(proxy, count, tmp, count));

	#if defined _MSC_VER && _MSC_VER == 1936
	#pragma warning(pop)
	#endif

	if(count <= 1)
	{
		return;
	}
	else if(count == 2)
	{
		mk_sl_sort_merge_inl_defd_fn_first_round_proxy_inplace(data, proxy, 2, tmp);
		return;
	}
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
			mk_sl_sort_merge_inl_defd_fn_merge_proxy(data, &in[i * block_size], chunk_size, &in[i * block_size + chunk_size], chunk_size, &out[i * block_size]);
		}
		if(rest > chunk_size)
		{
			rest = rest - chunk_size;
			mk_sl_sort_merge_inl_defd_fn_merge_proxy(data, &in[i * block_size], chunk_size, &in[i * block_size + chunk_size], rest, &out[i * block_size]);
		}
		else
		{
			for(j = 0; j != rest; ++j){ out[i * block_size + j] = in[i * block_size + j]; }
		}
	}
	mk_lang_assert(count > chunk_size);
	rest = count - chunk_size;
	mk_sl_sort_merge_inl_defd_fn_merge_proxy(data, &in[0], chunk_size, &in[chunk_size], rest, &out[0]);
	#if mk_sl_sort_merge_inl_defd_first_round
	mk_lang_assert(out == proxy);
	#else
	if(out != proxy){ for(i = 0; i != count; ++i){ proxy[i] = out[i]; } }
	#endif
}


#undef mk_sl_sort_merge_overlap_data_name
#undef mk_sl_sort_merge_overlap_data_fn
#undef mk_sl_sort_merge_overlap_proxy_name
#undef mk_sl_sort_merge_overlap_proxy_fn


#include "mk_sl_sort_merge_inl_defu.h"


#undef mk_sl_sort_merge_t_name
#undef mk_sl_sort_merge_t_data
#undef mk_sl_sort_merge_t_counter
#undef mk_sl_sort_merge_t_is_sorted
#undef mk_sl_sort_merge_t_first_round
#undef mk_sl_sort_merge_t_proxy
