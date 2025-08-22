#include "mk_lang_assert.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"


#include "mk_sl_sort_merge_inl_defd.h"


#define mk_sl_sort_merge_overlap_type_name mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _zzz_overlap_type)
#define mk_sl_sort_merge_overlap_type_fn mk_lang_concat(mk_sl_sort_merge_overlap_type_name, _fn)
#define mk_lang_overlap_t_name mk_sl_sort_merge_overlap_type_name
#define mk_lang_overlap_t_type mk_sl_sort_merge_inl_defd_element_t
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#include "mk_lang_overlap_inl_fileu.h"

#define mk_sl_sort_merge_memcpy_element_name mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _zzz_memcpy_type)
#define mk_sl_sort_merge_memcpy_element_fn mk_lang_concat(mk_sl_sort_merge_memcpy_element_name, _fn)
#define mk_lang_memcpy1_t_name mk_sl_sort_merge_memcpy_element_name
#define mk_lang_memcpy1_t_type mk_sl_sort_merge_inl_defd_element_t
#include "mk_lang_memcpy1_inl_fileh.h"
#include "mk_lang_memcpy1_inl_filec.h"
#include "mk_lang_memcpy1_inl_fileu.h"

#define mk_sl_sort_merge_swap_type_name mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _zzz_swap_type)
#define mk_sl_sort_merge_swap_data_fn mk_lang_concat(mk_sl_sort_merge_swap_type_name, _fn)
#define mk_lang_swap_t_name mk_sl_sort_merge_swap_type_name
#define mk_lang_swap_t_type mk_sl_sort_merge_inl_defd_element_t
#include "mk_lang_swap_inl_fileh.h"
#include "mk_lang_swap_inl_filec.h"
#include "mk_lang_swap_inl_fileu.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_inl_defd_prfn_is_sorted(mk_sl_sort_merge_inl_defd_context_t const context, mk_sl_sort_merge_inl_defd_element_pct const a, mk_sl_sort_merge_inl_defd_element_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	c = mk_sl_sort_merge_inl_defd_element_is_sorted(context, a, b);
	return c;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_prfn_first_round_inplace(mk_sl_sort_merge_inl_defd_context_t const context, mk_sl_sort_merge_inl_defd_element_pt const data, mk_sl_sort_merge_inl_defd_counter_t const count) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t n mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_element_pt a mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_element_pt b mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(data);
	mk_lang_assert(count >= 2);

	n = count / 2;
	for(i = 0; i != n; ++i)
	{
		a = &data[i * 2 + 0];
		b = &data[i * 2 + 1];
		if(!mk_sl_sort_merge_inl_defd_prfn_is_sorted(context, a, b))
		{
			mk_sl_sort_merge_swap_data_fn(a, b);
		}
	}
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_prfn_first_round_copy(mk_sl_sort_merge_inl_defd_context_t const context, mk_sl_sort_merge_inl_defd_element_pct const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_element_pt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_element_pct ai mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_element_pct bi mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_element_pt ao mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_element_pt bo mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(data);
	mk_lang_assert(count >= 3);
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_type_fn(data, count, tmp, count));

	for(i = 0; i != count / 2; ++i)
	{
		ai = &data[i * 2 + 0];
		bi = &data[i * 2 + 1];
		ao = &tmp[i * 2 + 0];
		bo = &tmp[i * 2 + 1];
		if(mk_sl_sort_merge_inl_defd_prfn_is_sorted(context, ai, bi))
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

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_inl_defd_prfn_first_round_d(mk_sl_sort_merge_inl_defd_context_t const context, mk_sl_sort_merge_inl_defd_element_pt const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_element_pt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t cnt mk_lang_constexpr_init;
	mk_lang_types_sint_t clz mk_lang_constexpr_init;
	mk_lang_types_bool_t r mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(data);
	mk_lang_assert(count >= 3);
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_type_fn(data, count, tmp, count));

	mk_sl_sort_merge_inl_defd_counter_dec2(&count, &cnt);
	clz = mk_sl_sort_merge_inl_defd_counter_count_leading_zeros(&cnt);
	r = clz % 2 == 0;
	if(r)
	{
		mk_sl_sort_merge_inl_defd_prfn_first_round_copy(context, data, count, tmp);
	}
	else
	{
		mk_sl_sort_merge_inl_defd_prfn_first_round_inplace(context, data, count);
	}
	return r;
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_prfn_merge(mk_sl_sort_merge_inl_defd_context_t const context, mk_sl_sort_merge_inl_defd_element_pct const input_a, mk_sl_sort_merge_inl_defd_counter_t const count_a, mk_sl_sort_merge_inl_defd_element_pct const input_b, mk_sl_sort_merge_inl_defd_counter_t const count_b, mk_sl_sort_merge_inl_defd_element_pt const output) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_counter_t idx_a mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t idx_b mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t idx_o mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(input_a);
	mk_lang_assert(count_a >= 1);
	mk_lang_assert(input_b);
	mk_lang_assert(count_b >= 1);
	mk_lang_assert(output);
	mk_lang_assert(!mk_sl_sort_merge_overlap_type_fn(input_a, count_a, input_b, count_b));
	mk_lang_assert(!mk_sl_sort_merge_overlap_type_fn(input_a, count_a, output, count_a + count_b));
	mk_lang_assert(!mk_sl_sort_merge_overlap_type_fn(input_b, count_b, output, count_a + count_b));

	idx_a = 0;
	idx_b = 0;
	idx_o = 0;
	while(idx_a != count_a && idx_b != count_b)
	{
		if(mk_sl_sort_merge_inl_defd_prfn_is_sorted(context, &input_a[idx_a], &input_b[idx_b]))
		{
			output[idx_o++] = input_a[idx_a++];
		}
		else
		{
			output[idx_o++] = input_b[idx_b++];
		}
	}
	mk_sl_sort_merge_memcpy_element_fn(&output[idx_o], &input_a[idx_a], count_a - idx_a); idx_o += count_a - idx_a; idx_a += count_a - idx_a;
	mk_sl_sort_merge_memcpy_element_fn(&output[idx_o], &input_b[idx_b], count_b - idx_b); idx_o += count_b - idx_b; idx_b += count_b - idx_b;
	mk_lang_assert(idx_a == count_a);
	mk_lang_assert(idx_b == count_b);
	mk_lang_assert(idx_o == count_a + count_b);
}

mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_inl_defd_prfn_many(mk_sl_sort_merge_inl_defd_context_t const context, mk_sl_sort_merge_inl_defd_element_pt const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_element_pt const tmp) mk_lang_noexcept
{
	mk_sl_sort_merge_inl_defd_element_pt in mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_element_pt out mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t chunk_size mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t block_size mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_element_pt t mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t block_count mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t rest mk_lang_constexpr_init;
	mk_sl_sort_merge_inl_defd_counter_t i mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(data);
	mk_lang_assert(count >= 3);
	mk_lang_assert(count <= ((mk_sl_sort_merge_inl_defd_counter_t)(((mk_sl_sort_merge_inl_defd_counter_t)(~((mk_sl_sort_merge_inl_defd_counter_t)(0)))) / ((mk_sl_sort_merge_inl_defd_counter_t)(2)))));
	mk_lang_assert(tmp);
	mk_lang_assert(!mk_sl_sort_merge_overlap_type_fn(data, count, tmp, count));

	in = data;
	out = tmp;
	#if mk_sl_sort_merge_inl_defd_first_round
	if(mk_sl_sort_merge_inl_defd_prfn_first_round_d(context, data, count, tmp)){ t = in, in = out, out = t; }
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
			mk_sl_sort_merge_inl_defd_prfn_merge(context, &in[i * block_size + 0 * chunk_size], chunk_size, &in[i * block_size + 1 * chunk_size], chunk_size, &out[i * block_size]);
		}
		if(rest > chunk_size)
		{
			rest = rest - chunk_size;
			mk_sl_sort_merge_inl_defd_prfn_merge(context, &in[i * block_size + 0 * chunk_size], chunk_size, &in[i * block_size + 1 * chunk_size], rest, &out[i * block_size]);
		}
		else
		{
			mk_sl_sort_merge_memcpy_element_fn(&out[i * block_size], &in[i * block_size], rest);
		}
	}
	mk_lang_assert(count > chunk_size);
	rest = count - chunk_size;
	mk_sl_sort_merge_inl_defd_prfn_merge(context, &in[0 * chunk_size], chunk_size, &in[1 * chunk_size], rest, &out[0]);
	#if mk_sl_sort_merge_inl_defd_first_round
	mk_lang_assert(out == data);
	#else
	if(out != data){ mk_sl_sort_merge_memcpy_element_fn(&data[0], &out[0], count); }
	#endif
}


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_sort_merge_inl_defd_fn(mk_sl_sort_merge_inl_defd_context_t const context, mk_sl_sort_merge_inl_defd_element_pt const data, mk_sl_sort_merge_inl_defd_counter_t const count, mk_sl_sort_merge_inl_defd_element_pt const tmp) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(&context);
	mk_lang_assert(data || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= ((mk_sl_sort_merge_inl_defd_counter_t)(((mk_sl_sort_merge_inl_defd_counter_t)(~((mk_sl_sort_merge_inl_defd_counter_t)(0)))) / ((mk_sl_sort_merge_inl_defd_counter_t)(2)))));
	mk_lang_assert(tmp || count == 0);
	mk_lang_assert(!mk_sl_sort_merge_overlap_type_fn(data, count, tmp, count));
	#include "mk_lang_warning_msvc_pop.h"

	if(count <= 1)
	{
	}
	else if(count == 2)
	{
		mk_sl_sort_merge_inl_defd_prfn_first_round_inplace(context, data, 2);
	}
	else
	{
		mk_sl_sort_merge_inl_defd_prfn_many(context, data, count, tmp);
	}
}


#undef mk_sl_sort_merge_overlap_type_name
#undef mk_sl_sort_merge_overlap_type_fn

#undef mk_sl_sort_merge_memcpy_element_name
#undef mk_sl_sort_merge_memcpy_element_fn

#undef mk_sl_sort_merge_swap_type_name
#undef mk_sl_sort_merge_swap_data_fn

#undef mk_sl_sort_merge_overlap_proxy_name
#undef mk_sl_sort_merge_overlap_proxy_fn

#undef mk_sl_sort_merge_memcpy_proxy_name
#undef mk_sl_sort_merge_memcpy_proxy_fn

#undef mk_sl_sort_merge_swap_proxy_name
#undef mk_sl_sort_merge_swap_proxy_fn


#include "mk_sl_sort_merge_inl_defu.h"
