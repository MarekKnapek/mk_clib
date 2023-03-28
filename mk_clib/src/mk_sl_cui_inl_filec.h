#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_for_constants.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_memmove_obj.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"


#include "mk_sl_cui_inl_defd.h"


mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_set_zero(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_set_zero(&x->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_set_max(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_set_max(&x->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_set_max(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_set_one(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_set_one(&x->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_set_one(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
	for(i = 1; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_set_bit(mk_sl_cui_inl_defd_t* const x, int const bit_idx) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_set_bit(&x->m_data[0], bit_idx);
#else
	mk_lang_assert(x);
	mk_lang_assert(bit_idx >= 0 && bit_idx < mk_sl_cui_inl_defd_bits);

	mk_sl_cui_inl_defd_set_zero(x);
	mk_sl_cui_inl_defd_base_set_bit(&x->m_data[mk_sl_cui_inl_defd_idx(bit_idx / mk_sl_cui_inl_defd_base_bits)], bit_idx % mk_sl_cui_inl_defd_base_bits);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_set_mask(mk_sl_cui_inl_defd_t* const x, int const bits_count) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_set_mask(&x->m_data[0], bits_count);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(bits_count >= 1 && bits_count <= mk_sl_cui_inl_defd_bits);

	for(i = 0; i != bits_count / mk_sl_cui_inl_defd_base_bits; ++i)
	{
		mk_sl_cui_inl_defd_base_set_max(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	if(bits_count % mk_sl_cui_inl_defd_base_bits != 0)
	{
		mk_sl_cui_inl_defd_base_set_mask(&x->m_data[mk_sl_cui_inl_defd_idx(i)], bits_count % mk_sl_cui_inl_defd_base_bits);
		++i;
	}
	for(; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

#include "mk_lang_bui.h"
#define mk_lang_forb1_id mk_lang_for_constants_bi
#define mk_lang_forb_file "mk_sl_cui_inl_tofrom_bi_inl_filec.h"
#define mk_sl_cui_inl_tofrom_bi_for_bi mk_lang_forb_bi
#include "mk_lang_forb1.h"
#undef mk_lang_forb1_id
#undef mk_lang_forb_file
#undef mk_sl_cui_inl_tofrom_bi_for_bi

#define mk_lang_forb2_id mk_lang_for_constants_bui
#define mk_lang_forb1_id mk_lang_for_constants_endian
#define mk_lang_forb_file "mk_sl_cui_inl_tofrom_buis_inl_filec.h"
#define mk_sl_cui_inl_tofrom_buis_for_bui mk_lang_forb_bui
#define mk_sl_cui_inl_tofrom_buis_for_endian mk_lang_forb_endian
#include "mk_lang_forb2.h"
#undef mk_lang_forb2_id
#undef mk_lang_forb1_id
#undef mk_lang_forb_file
#undef mk_sl_cui_inl_tofrom_buis_for_bui
#undef mk_sl_cui_inl_tofrom_buis_for_endian

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_is_zero(mk_sl_cui_inl_defd_t const* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	return mk_sl_cui_inl_defd_base_is_zero(&x->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		if(!mk_sl_cui_inl_defd_base_is_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_is_max(mk_sl_cui_inl_defd_t const* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	return mk_sl_cui_inl_defd_base_is_max(&x->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		if(!mk_sl_cui_inl_defd_base_is_max(&x->m_data[mk_sl_cui_inl_defd_idx(i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_eq(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_defd_base_eq(&a->m_data[0], &b->m_data[0]);
#else
	if(a == b)
	{
		return mk_lang_true;
	}
	else
	{
		int i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
		{
			if(!mk_sl_cui_inl_defd_base_eq(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_true;
	}
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_ne(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_defd_base_ne(&a->m_data[0], &b->m_data[0]);
#else
	if(a == b)
	{
		return mk_lang_false;
	}
	else
	{
		int i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
		{
			if(mk_sl_cui_inl_defd_base_ne(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]))
			{
				return mk_lang_true;
			}
		}
		return mk_lang_false;
	}
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_lt(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_defd_base_lt(&a->m_data[0], &b->m_data[0]);
#else
	if(a == b)
	{
		return mk_lang_false;
	}
	else
	{
		int i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
		{
			if(mk_sl_cui_inl_defd_base_lt(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)]))
			{
				return mk_lang_true;
			}
			else if(mk_sl_cui_inl_defd_base_lt(&b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_false;
	}
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_le(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_defd_base_le(&a->m_data[0], &b->m_data[0]);
#else
	if(a == b)
	{
		return mk_lang_true;
	}
	else
	{
		int i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
		{
			if(mk_sl_cui_inl_defd_base_lt(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)]))
			{
				return mk_lang_true;
			}
			else if(mk_sl_cui_inl_defd_base_lt(&b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_true;
	}
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_gt(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_defd_base_gt(&a->m_data[0], &b->m_data[0]);
#else
	if(a == b)
	{
		return mk_lang_false;
	}
	else
	{
		int i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
		{
			if(mk_sl_cui_inl_defd_base_gt(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)]))
			{
				return mk_lang_true;
			}
			else if(mk_sl_cui_inl_defd_base_gt(&b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_false;
	}
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_ge(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_defd_base_ge(&a->m_data[0], &b->m_data[0]);
#else
	if(a == b)
	{
		return mk_lang_true;
	}
	else
	{
		int i mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
		{
			if(mk_sl_cui_inl_defd_base_gt(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)]))
			{
				return mk_lang_true;
			}
			else if(mk_sl_cui_inl_defd_base_gt(&b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)]))
			{
				return mk_lang_false;
			}
		}
		return mk_lang_true;
	}
#endif
}


mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_inc2(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_sl_cui_inl_defd_base_inc2(&a->m_data[0], &b->m_data[0]);
#else
	if(a == b)
	{
		mk_sl_cui_inl_defd_inc1(b);
	}
	else
	{
		int i mk_lang_constexpr_init;
		mk_lang_bool_t c mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		c = mk_lang_true;
		for(i = 0; i != mk_sl_cui_inl_defd_count - 1 && c; ++i)
		{
			mk_sl_cui_inl_defd_base_inc2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
			c = mk_sl_cui_inl_defd_base_is_zero(&b->m_data[mk_sl_cui_inl_defd_idx(i)]);
		}
		if(c)
		{
			mk_sl_cui_inl_defd_base_inc2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
			++i;
		}
		for(; i != mk_sl_cui_inl_defd_count; ++i)
		{
			b->m_data[mk_sl_cui_inl_defd_idx(i)] = a->m_data[mk_sl_cui_inl_defd_idx(i)];
		}
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_dec2(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_sl_cui_inl_defd_base_dec2(&a->m_data[0], &b->m_data[0]);
#else
	if(a == b)
	{
		mk_sl_cui_inl_defd_dec1(b);
	}
	else
	{
		int i mk_lang_constexpr_init;
		mk_lang_bool_t c mk_lang_constexpr_init;

		mk_lang_assert(a);
		mk_lang_assert(b);

		c = mk_lang_true;
		for(i = 0; i != mk_sl_cui_inl_defd_count - 1 && c; ++i)
		{
			mk_sl_cui_inl_defd_base_dec2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
			c = mk_sl_cui_inl_defd_base_is_max(&b->m_data[mk_sl_cui_inl_defd_idx(i)]);
		}
		if(c)
		{
			mk_sl_cui_inl_defd_base_dec2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
			++i;
		}
		for(; i != mk_sl_cui_inl_defd_count; ++i)
		{
			b->m_data[mk_sl_cui_inl_defd_idx(i)] = a->m_data[mk_sl_cui_inl_defd_idx(i)];
		}
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_inc1(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_inc1(&x->m_data[0]);
#else
	int i mk_lang_constexpr_init;
	mk_lang_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(x);

	c = mk_lang_true;
	for(i = 0; i != mk_sl_cui_inl_defd_count - 1 && c; ++i)
	{
		mk_sl_cui_inl_defd_base_inc1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
		c = mk_sl_cui_inl_defd_base_is_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	if(c)
	{
		mk_sl_cui_inl_defd_base_inc1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_dec1(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_dec1(&x->m_data[0]);
#else
	int i mk_lang_constexpr_init;
	mk_lang_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(x);

	c = mk_lang_true;
	for(i = 0; i != mk_sl_cui_inl_defd_count - 1 && c; ++i)
	{
		mk_sl_cui_inl_defd_base_dec1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
		c = mk_sl_cui_inl_defd_base_is_max(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	if(c)
	{
		mk_sl_cui_inl_defd_base_dec1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}


mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_not2(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_sl_cui_inl_defd_base_not2(&a->m_data[0], &b->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_not2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_or3(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_or3(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_or3(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_and3(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_and3(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_and3(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_xor3(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_xor3(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_xor3(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_not1(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_not1(&x->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_not1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_or2(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_sl_cui_inl_defd_base_or2(&a->m_data[0], &b->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_or2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_and2(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_sl_cui_inl_defd_base_and2(&a->m_data[0], &b->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_and2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_xor2(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_sl_cui_inl_defd_base_xor2(&a->m_data[0], &b->m_data[0]);
#else
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_xor2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}


mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_shl3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_shl3(&a->m_data[0], b, &c->m_data[0]);
#else
	int i mk_lang_constexpr_init;
	int big mk_lang_constexpr_init;
	int smol mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type t mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);

	big = ((int)(((int)(b)) / ((int)(mk_sl_cui_inl_defd_base_bits))));
	smol = ((int)(((int)(b)) % ((int)(mk_sl_cui_inl_defd_base_bits))));
	if(smol == 0)
	{
		for(i = 0; i != mk_sl_cui_inl_defd_count - big; ++i)
		{
			c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)] = a->m_data[mk_sl_cui_inl_defd_idx(((mk_sl_cui_inl_defd_count - 1) - big) - i)];
		}
		for(; i != mk_sl_cui_inl_defd_count; ++i)
		{
			mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]);
		}
	}
	else
	{
		for(i = 0; i != mk_sl_cui_inl_defd_count - big - 1; ++i)
		{
			mk_sl_cui_inl_defd_base_shl3(&a->m_data[mk_sl_cui_inl_defd_idx((((mk_sl_cui_inl_defd_count - 1) - 0) - big) - i)], smol, &c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]);
			mk_sl_cui_inl_defd_base_shr3(&a->m_data[mk_sl_cui_inl_defd_idx((((mk_sl_cui_inl_defd_count - 1) - 1) - big) - i)], mk_sl_cui_inl_defd_base_bits - smol, &t);
			mk_sl_cui_inl_defd_base_or2(&c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &t);
		}
		mk_sl_cui_inl_defd_base_shl3(&a->m_data[mk_sl_cui_inl_defd_idx((((mk_sl_cui_inl_defd_count - 1) - 0) - big) - i)], smol, &c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]);
		for(++i; i != mk_sl_cui_inl_defd_count; ++i)
		{
			mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]);
		}
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_shr3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_shr3(&a->m_data[0], b, &c->m_data[0]);
#else
	int i mk_lang_constexpr_init;
	int big mk_lang_constexpr_init;
	int smol mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type t mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);

	big = ((int)(((int)(b)) / ((int)(mk_sl_cui_inl_defd_base_bits))));
	smol = ((int)(((int)(b)) % ((int)(mk_sl_cui_inl_defd_base_bits))));
	if(smol == 0)
	{
		for(i = 0; i != mk_sl_cui_inl_defd_count - big; ++i)
		{
			c->m_data[mk_sl_cui_inl_defd_idx(i)] = a->m_data[mk_sl_cui_inl_defd_idx(big + i)];
		}
		for(; i != mk_sl_cui_inl_defd_count; ++i)
		{
			mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(i)]);
		}
	}
	else
	{
		for(i = 0; i != mk_sl_cui_inl_defd_count - big - 1; ++i)
		{
			mk_sl_cui_inl_defd_base_shr3(&a->m_data[mk_sl_cui_inl_defd_idx(big + 0 + i)], smol, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
			mk_sl_cui_inl_defd_base_shl3(&a->m_data[mk_sl_cui_inl_defd_idx(big + 1 + i)], mk_sl_cui_inl_defd_base_bits - smol, &t);
			mk_sl_cui_inl_defd_base_or2(&c->m_data[mk_sl_cui_inl_defd_idx(i)], &t);
		}
		mk_sl_cui_inl_defd_base_shr3(&a->m_data[mk_sl_cui_inl_defd_idx(big + i)], smol, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
		for(++i; i != mk_sl_cui_inl_defd_count; ++i)
		{
			mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(i)]);
		}
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_rotl3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_rotl3(&a->m_data[0], b, &c->m_data[0]);
#else
	mk_sl_cui_inl_defd_t ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_shl3(a, b, &ta);
	mk_sl_cui_inl_defd_shr3(a, mk_sl_cui_inl_defd_bits - b, &tb);
	mk_sl_cui_inl_defd_or3(&ta, &tb, c);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_rotr3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_rotr3(&a->m_data[0], b, &c->m_data[0]);
#else
	mk_sl_cui_inl_defd_t ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_shr3(a, b, &ta);
	mk_sl_cui_inl_defd_shl3(a, mk_sl_cui_inl_defd_bits - b, &tb);
	mk_sl_cui_inl_defd_or3(&ta, &tb, c);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_shl2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_shl3(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_shr2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_shr3(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_rotl2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_rotl3(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_rotr2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_rotr3(a, b, a);
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_add_cc(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_would_overflow_add_cc(&a->m_data[0], &b->m_data[0]);
#else
	int i mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_set_max(&ta);
	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cid_cod(&ta, &a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &tb);
		if(mk_sl_cui_inl_defd_base_lt(&tb, &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
		{
			return mk_lang_true;
		}
		else if(mk_sl_cui_inl_defd_base_gt(&tb, &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_false;
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_add_cs(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_would_overflow_add_cs(&a->m_data[0], &b->m_data[0]);
#else
	int i mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	mk_sl_cui_inl_defd_base_set_max(&ta);
	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cid_cod(&ta, &a->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)], &tb);
		if(mk_sl_cui_inl_defd_base_lt(&tb, &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
		{
			return mk_lang_true;
		}
		else if(mk_sl_cui_inl_defd_base_gt(&tb, &b->m_data[mk_sl_cui_inl_defd_idx((mk_sl_cui_inl_defd_count - 1) - i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_add(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const cf) mk_lang_noexcept
{
	return cf ? mk_sl_cui_inl_defd_would_overflow_add_cs(a, b) : mk_sl_cui_inl_defd_would_overflow_add_cc(a, b);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_sub_cc(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	return mk_sl_cui_inl_defd_lt(a, b);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_sub_cs(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	return mk_sl_cui_inl_defd_le(a, b);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_sub(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const cf) mk_lang_noexcept
{
	return cf ? mk_sl_cui_inl_defd_would_overflow_sub_cs(a, b) : mk_sl_cui_inl_defd_would_overflow_sub_cc(a, b);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_mul(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return 0; /*todo*/
}


mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cid_cod(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_add3_wrap_cid_cod(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_add3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_add3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cid_coe(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_lang_bool_t* const co) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_add3_wrap_cid_coe(&a->m_data[0], &b->m_data[0], &c->m_data[0], co);
#else
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_add3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], co);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cie_cod(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_add3_wrap_cie_cod(&a->m_data[0], &b->m_data[0], ci, &c->m_data[0]);
#else
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_add3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cie_coe(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_sl_cui_inl_defd_t* const c, mk_lang_bool_t* const co) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[0], &b->m_data[0], ci, &c->m_data[0], co);
#else
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], co);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_add2_wrap_cid_cod(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_add3_wrap_cid_cod(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_add2_wrap_cid_coe(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_add3_wrap_cid_coe(a, b, a, co);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_add2_wrap_cie_cod(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_add3_wrap_cie_cod(a, b, ci, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_add2_wrap_cie_coe(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_add3_wrap_cie_coe(a, b, ci, a, co);
}


mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_sub3_wrap_cid_cod(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_sub3_wrap_cid_cod(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_sub3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_sub3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_sub3_wrap_cid_coe(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_lang_bool_t* const co) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_sub3_wrap_cid_coe(&a->m_data[0], &b->m_data[0], &c->m_data[0], co);
#else
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_sub3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], co);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_sub3_wrap_cie_cod(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_sub3_wrap_cie_cod(&a->m_data[0], &b->m_data[0], ci, &c->m_data[0]);
#else
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_sub3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_sub3_wrap_cie_coe(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_sl_cui_inl_defd_t* const c, mk_lang_bool_t* const co) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[0], &b->m_data[0], ci, &c->m_data[0], co);
#else
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], ci, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &cf);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], &cf);
	}
	mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], cf, &c->m_data[mk_sl_cui_inl_defd_idx(i)], co);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_sub2_wrap_cid_cod(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_sub3_wrap_cid_cod(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_sub2_wrap_cid_coe(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_sub3_wrap_cid_coe(a, b, a, co);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_sub2_wrap_cie_cod(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_sub3_wrap_cie_cod(a, b, ci, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_sub2_wrap_cie_coe(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_lang_bool_t* const co) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_sub3_wrap_cie_coe(a, b, ci, a, co);
}


#if mk_sl_cui_inl_defd_count != 1
mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul3_wrap_lo_restrict(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 2
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta);
#elif mk_sl_cui_inl_defd_count == 3
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, cf);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta);
#elif mk_sl_cui_inl_defd_count == 4
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(3)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &tb, cf);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &tb, cf);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &tb, cf);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &ta);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &ta);
#else
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count > 4);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(3)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	for(j = 2; j != mk_sl_cui_inl_defd_count - 2; ++j)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &ta, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &tb, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]);
		for(i = 1; i != j + 1; ++i)
		{
			mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &ta, &tb);
			mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &ta, &cf);
			mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &tb, cf, &cf);
			if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]);
		}
	}
	for(i = 0; i != j + 1; ++i)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &ta, &tb);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &ta, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &tb, cf);
	}
	++j;
	for(i = 0; i != j + 1; ++i)
	{
		mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(j - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &ta);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &ta);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul3_wrap_lo_alias(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_t cc mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 2);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c == a || c == b);

	mk_sl_cui_inl_defd_mul3_wrap_lo_restrict(a, b, &cc);
	*c = cc;
}
#endif

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul3_wrap_lo(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	if(c != a && c != b)
	{
		mk_sl_cui_inl_defd_mul3_wrap_lo_restrict(a, b, c);
	}
	else
	{
		mk_sl_cui_inl_defd_mul3_wrap_lo_alias(a, b, c);
	}
#endif
}

#if mk_sl_cui_inl_defd_count != 1
mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul3_wrap_hi_restrict(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 2
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tc mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul3_wrap_hi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, &tc);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(&ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &tc, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(1)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, cf);
#elif mk_sl_cui_inl_defd_count == 3
	/* todo */
	((void)(a));
	((void)(b));
	((void)(c));
#elif mk_sl_cui_inl_defd_count == 4
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tc mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type td mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul3_wrap_hi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &tc);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&tc);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, &td);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(&ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&tc, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&ta); else mk_sl_cui_inl_defd_base_set_zero(&ta);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&tc, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&ta, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(0)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&tc, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&ta, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, &td);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(&tc, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&ta, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &tc);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &tc, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(1)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, &tc);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &tc, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, &tc);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &tc, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &tb, &tc);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(&ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &tc, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(2)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(3)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &tb, cf);
#else
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tc mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type td mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type* t0 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type* t1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type* t2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type te mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type* t3 mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 4);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	mk_sl_cui_inl_defd_base_mul3_wrap_hi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &tc);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&ta, &tb, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&tc);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &tb, &td);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(&ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&tc, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&ta); else mk_sl_cui_inl_defd_base_set_zero(&ta);
	t0 = &tc;
	t1 = &ta;
	t2 = &te;
	for(j = 2; j != mk_sl_cui_inl_defd_count - 2; ++j)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &td);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_set_one(t2); else mk_sl_cui_inl_defd_base_set_zero(t2);
		for(i = 1; i != j; ++i)
		{
			mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &tb, &td);
			mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
			mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
			if(cf) mk_sl_cui_inl_defd_base_inc1(t2);
		}
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(j)], &tb, &td);
		cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(t0, &tb);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_inc1(t2);
		t3 = t0;
		t0 = t1;
		t1 = t2;
		t2 = t3;
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(0)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 2; ++i)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 2 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &tb, &td);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 2)], &tb, &td);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(t0, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(t1, &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(0)]);
	t0 = t1;
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(1)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &tb, &td);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(t0, &tb, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &tb, &td);
	cf = mk_sl_cui_inl_defd_base_would_overflow_add_cc(t0, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(0)], &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	for(j = 0; j != mk_sl_cui_inl_defd_count - 3; ++j)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &tb, &td);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &tb, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]);
		for(i = 1; i != mk_sl_cui_inl_defd_count - 2 - j; ++i)
		{
			mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(j + 1 + i)], &tb, &td);
			mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &tb, &cf);
			mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &td, cf, &cf);
			if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]);
		}
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &tb, &td);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j)], &tb, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &td, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(j + 2)]);
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 2)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 3)], &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 2)], &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)]); else mk_sl_cui_inl_defd_base_set_zero(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 2)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 3)], &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 2)], &td, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &tb, &td);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 2)], &tb, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &td, cf);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul3_wrap_hi_alias(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_t cc mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 2);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c == a || c == b);

	mk_sl_cui_inl_defd_mul3_wrap_hi_restrict(a, b, &cc);
	*c = cc;
}
#endif

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul3_wrap_hi(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_mul3_wrap_hi(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	if(c != a && c != b)
	{
		mk_sl_cui_inl_defd_mul3_wrap_hi_restrict(a, b, c);
	}
	else
	{
		mk_sl_cui_inl_defd_mul3_wrap_hi_alias(a, b, c);
	}
#endif
}

#if mk_sl_cui_inl_defd_count != 1
mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul4_wrap_wi_restrict(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_sl_cui_inl_defd_t* const d) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 2
	#define out_idx(x) (out[(x) / mk_sl_cui_inl_defd_count]->m_data[mk_sl_cui_inl_defd_idx((x) % mk_sl_cui_inl_defd_count)])

	mk_sl_cui_inl_defd_t* out[2] mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c != a && c != b && d != a && d != b);

	out[0] = c;
	out[1] = d;
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &out_idx(0), &out_idx(1));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &out_idx(2));
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(2));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(2), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(3)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(3));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&out_idx(3), &tb, cf);

	#undef out_idx
#elif mk_sl_cui_inl_defd_count == 3
	/* todo */
	((void)(a));
	((void)(b));
	((void)(c));
	((void)(d));
#elif mk_sl_cui_inl_defd_count == 4
	#define out_idx(x) (out[(x) / mk_sl_cui_inl_defd_count]->m_data[mk_sl_cui_inl_defd_idx((x) % mk_sl_cui_inl_defd_count)])

	mk_sl_cui_inl_defd_t* out[2] mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c != a && c != b && d != a && d != b);

	out[0] = c;
	out[1] = d;
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &out_idx(0), &out_idx(1));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &out_idx(2));
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(2));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(2), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(3)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(3));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&out_idx(3), &tb, cf);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(3), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(4)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(4));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(3), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(4));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(3), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(4), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(5)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(5));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(3), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(4), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(5));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(3), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(4), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(5));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(3), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(4), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(5));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(4), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(5), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(6)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(6));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(4), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(5), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(6));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(4), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(5), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(6));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(2)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(5), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(6), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(7)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(7));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(5), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(6), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(7));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], &b->m_data[mk_sl_cui_inl_defd_idx(3)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(6), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&out_idx(7), &tb, cf);

	#undef out_idx
#else
	#define out_idx(x) (out[(x) / mk_sl_cui_inl_defd_count]->m_data[mk_sl_cui_inl_defd_idx((x) % mk_sl_cui_inl_defd_count)])

	mk_sl_cui_inl_defd_t* out[2] mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type ta mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type tb mk_lang_constexpr_init;
	int j mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 4);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c != a && c != b && d != a && d != b);

	out[0] = c;
	out[1] = d;
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &out_idx(0), &out_idx(1));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &out_idx(2));
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(2));
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], &b->m_data[mk_sl_cui_inl_defd_idx(1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(1), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(2), &tb, cf, &cf);
	if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(3)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(3));
	for(j = 2; j != mk_sl_cui_inl_defd_count; ++j)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j)], &b->m_data[mk_sl_cui_inl_defd_idx(0)], &ta, &tb);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(j), &ta, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(j + 1), &tb, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(j + 2)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(j + 2));
		for(i = 1; i != j + 1; ++i)
		{
			mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(j - i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &ta, &tb);
			mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(j), &ta, &cf);
			mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(j + 1), &tb, cf, &cf);
			if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(j + 2));
		}
	}
	for(j = 0; j != mk_sl_cui_inl_defd_count - 2; ++j)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(j + 1)], &ta, &tb);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(mk_sl_cui_inl_defd_count + j), &ta, &cf);
		mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(mk_sl_cui_inl_defd_count + 1 + j), &tb, cf, &cf);
		if(cf) mk_sl_cui_inl_defd_base_set_one(&out_idx(mk_sl_cui_inl_defd_count + 2 + j)); else mk_sl_cui_inl_defd_base_set_zero(&out_idx(mk_sl_cui_inl_defd_count + 2 + j));
		for(i = 1; i != mk_sl_cui_inl_defd_count - 1 - j; ++i)
		{
			mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1 - i)], &b->m_data[mk_sl_cui_inl_defd_idx(j + 1 + i)], &ta, &tb);
			mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(mk_sl_cui_inl_defd_count + j), &ta, &cf);
			mk_sl_cui_inl_defd_base_add2_wrap_cie_coe(&out_idx(mk_sl_cui_inl_defd_count + 1 + j), &tb, cf, &cf);
			if(cf) mk_sl_cui_inl_defd_base_inc1(&out_idx(mk_sl_cui_inl_defd_count + 2 + j));
		}
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &b->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &ta, &tb);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&out_idx(mk_sl_cui_inl_defd_count + mk_sl_cui_inl_defd_count - 2), &ta, &cf);
	mk_sl_cui_inl_defd_base_add2_wrap_cie_cod(&out_idx(mk_sl_cui_inl_defd_count + mk_sl_cui_inl_defd_count - 1), &tb, cf);

	#undef out_idx
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul4_wrap_wi_alias(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_sl_cui_inl_defd_t* const d) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_t cc mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t dd mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 2);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c == a || c == b || d == a || d == b);

	mk_sl_cui_inl_defd_mul4_wrap_wi_restrict(a, b, &cc, &dd);
	*c = cc;
	*d = dd;
}
#endif

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul4_wrap_wi(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_sl_cui_inl_defd_t* const d) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[0], &b->m_data[0], &c->m_data[0], &d->m_data[0]);
#else
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	if(c != a && c != b && d != a && d != b)
	{
		mk_sl_cui_inl_defd_mul4_wrap_wi_restrict(a, b, c, d);
	}
	else
	{
		mk_sl_cui_inl_defd_mul4_wrap_wi_alias(a, b, c, d);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul2_wrap_lo(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_mul3_wrap_lo(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul2_wrap_hi(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_mul3_wrap_hi(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul2_wrap_wi(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_mul4_wrap_wi(a, b, a, b);
}


mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_div3_wrap(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_div3_wrap(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	mk_sl_cui_inl_defd_t d mk_lang_constexpr_init;

	mk_sl_cui_inl_defd_divmod4_wrap(a, b, c, &d);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mod3_wrap(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_mod3_wrap(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	mk_sl_cui_inl_defd_t d mk_lang_constexpr_init;

	mk_sl_cui_inl_defd_divmod4_wrap(a, b, &d, c);
#endif
}

#if mk_sl_cui_inl_defd_count != 1
#include "mk_sl_cui_inl_filec_div_defd.h"
mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_divmod4_wrap_restrict(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_sl_cui_inl_defd_t* const d) mk_lang_noexcept
{
#if mk_sl_cui_inl_filec_div_need_convert == 1
	mk_sl_cui_inl_filec_div_t aa[mk_sl_cui_inl_filec_div_count] mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t bb[mk_sl_cui_inl_filec_div_count] mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t cc[mk_sl_cui_inl_filec_div_count] mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t dd[mk_sl_cui_inl_filec_div_count] mk_lang_constexpr_init;
#endif
	mk_sl_cui_inl_filec_div_t const* pa mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t const* pb mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t* pc mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t* pd mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 2);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c != a && c != b && d != a && d != b);

#if mk_sl_cui_inl_filec_div_need_convert == 1
	mk_sl_cui_inl_filec_div_convert_to_buis(a, &aa[0]);
	mk_sl_cui_inl_filec_div_convert_to_buis(b, &bb[0]);
	pa = &aa[0];
	pb = &bb[0];
	pc = &cc[0];
	pd = &dd[0];
#else
	pa = &a->m_data[0];
	pb = &b->m_data[0];
	pc = &c->m_data[0];
	pd = &d->m_data[0];
#endif
	mk_sl_cui_inl_filec_div_fn(pa, pb, pc, pd);
#if mk_sl_cui_inl_filec_div_need_convert == 1
	mk_sl_cui_inl_filec_div_convert_from_buis(c, &cc[0]);
	mk_sl_cui_inl_filec_div_convert_from_buis(d, &dd[0]);
#endif
}
#include "mk_sl_cui_inl_filec_div_defu.h"

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_divmod4_wrap_alias(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_sl_cui_inl_defd_t* const d) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_t cc mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t dd mk_lang_constexpr_init;

	mk_lang_static_assert(mk_sl_cui_inl_defd_count >= 2);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);
	mk_lang_assert(c == a || c == b || d == a || d == b);

	mk_sl_cui_inl_defd_divmod4_wrap_restrict(a, b, &cc, &dd);
	*c = cc;
	*d = dd;
}
#endif

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_divmod4_wrap(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_sl_cui_inl_defd_t* const d) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	mk_sl_cui_inl_defd_base_divmod4_wrap(&a->m_data[0], &b->m_data[0], &c->m_data[0], &d->m_data[0]);
#else
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != d);

	if(c != a && c != b && d != a && d != b) /* todo alias/restrict possibly not needed */
	{
		mk_sl_cui_inl_defd_divmod4_wrap_restrict(a, b, c, d);
	}
	else
	{
		mk_sl_cui_inl_defd_divmod4_wrap_alias(a, b, c, d);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_div2_wrap(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_div3_wrap(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mod2_wrap(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_mod3_wrap(a, b, a);
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_divmod2_wrap(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_divmod4_wrap(a, b, a, b);
}


#define mk_sl_cui_inl_defd_want_smol
#include "mk_sl_cui_inl_filec_div_defd.h"
mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_divmod_smol(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_base_type const* const b, mk_sl_cui_inl_defd_t* const c, mk_sl_cui_inl_defd_base_type* const d) mk_lang_noexcept
{
#if mk_sl_cui_inl_filec_div_need_convert == 1
	mk_sl_cui_inl_filec_div_t aa[mk_sl_cui_inl_filec_div_count] mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t bb mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t cc[mk_sl_cui_inl_filec_div_count] mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t dd mk_lang_constexpr_init;
#endif
	mk_sl_cui_inl_filec_div_t const* pa mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t const* pb mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t* pc mk_lang_constexpr_init;
	mk_sl_cui_inl_filec_div_t* pd mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

#if mk_sl_cui_inl_filec_div_need_convert == 1
	mk_sl_cui_inl_filec_div_convert_to_buis(a, &aa[0]);
	mk_sl_cui_inl_filec_div_convert_to_bui(b, &bb);
	pa = &aa[0];
	pb = &bb;
	pc = &cc[0];
	pd = &dd;
#else
	pa = &a->m_data[0];
	pb = b;
	pc = &c->m_data[0];
	pd = d;
#endif
	mk_sl_cui_inl_filec_div_fn(pa, pb, pc, pd);
#if mk_sl_cui_inl_filec_div_need_convert == 1
	mk_sl_cui_inl_filec_div_convert_from_buis(c, &cc[0]);
	mk_sl_cui_inl_filec_div_convert_from_bui(d, &dd);
#endif
}
#include "mk_sl_cui_inl_filec_div_defu.h"

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul3_wrap_lo_smol(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_base_type const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[0], b, &c->m_data[0]);
#elif mk_sl_cui_inl_defd_count == 2
	mk_sl_cui_inl_defd_base_type t mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(!(b >= &a->m_data[0] && b < &a->m_data[mk_sl_cui_inl_defd_count]));
	mk_lang_assert(!(b >= &c->m_data[0] && b < &c->m_data[mk_sl_cui_inl_defd_count]));
	mk_lang_assert(c != a);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(1)], b, &t);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &t);
#elif mk_sl_cui_inl_defd_count == 3
	mk_sl_cui_inl_defd_base_type t mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(!(b >= &a->m_data[0] && b < &a->m_data[mk_sl_cui_inl_defd_count]));
	mk_lang_assert(!(b >= &c->m_data[0] && b < &c->m_data[mk_sl_cui_inl_defd_count]));
	mk_lang_assert(c != a);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], b, &t, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(2)], b, &t);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &t);
#elif mk_sl_cui_inl_defd_count == 4
	mk_sl_cui_inl_defd_base_type t mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(!(b >= &a->m_data[0] && b < &a->m_data[mk_sl_cui_inl_defd_count]));
	mk_lang_assert(!(b >= &c->m_data[0] && b < &c->m_data[mk_sl_cui_inl_defd_count]));
	mk_lang_assert(c != a);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], b, &t, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], b, &t, &c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(3)], b, &t);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &t);
#else
	mk_sl_cui_inl_defd_base_type t mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(!(b >= &a->m_data[0] && b < &a->m_data[mk_sl_cui_inl_defd_count]));
	mk_lang_assert(!(b >= &c->m_data[0] && b < &c->m_data[mk_sl_cui_inl_defd_count]));
	mk_lang_assert(c != a);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], b, &t, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	for(i = 2; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(i)], b, &t, &c->m_data[mk_sl_cui_inl_defd_idx(i + 1)]);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(i)], &t, &cf);
		if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(i + 1)]);
	}
	mk_sl_cui_inl_defd_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], b, &t);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &t);
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_add2_wrap_cid_cod_smol(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_base_type const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	
	mk_sl_cui_inl_defd_base_add2_wrap_cid_cod(&a->m_data[0], b);
#else
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(!(b >= &a->m_data[0] && b < &a->m_data[mk_sl_cui_inl_defd_count]));
	
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &cf);
	for(i = 1; i != mk_sl_cui_inl_defd_count - 1 && cf; ++i)
	{
		mk_sl_cui_inl_defd_base_inc1(&a->m_data[mk_sl_cui_inl_defd_idx(i)]);
		cf = mk_sl_cui_inl_defd_base_is_zero(&a->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
	if(cf)
	{
		mk_sl_cui_inl_defd_base_inc1(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)]);
	}
#endif
}

mk_lang_constexpr mk_lang_jumbo void mk_sl_cui_inl_defd_mul4_wrap_wi_smol(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_base_type const* const b, mk_sl_cui_inl_defd_t* const c, mk_sl_cui_inl_defd_base_type* const d) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != a);
	mk_lang_assert(d != b);
	mk_lang_assert(!(d >= &a->m_data[0] && d < &a->m_data[mk_sl_cui_inl_defd_count]));

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[0], b, &c->m_data[0], d);
#elif mk_sl_cui_inl_defd_count == 2
	mk_sl_cui_inl_defd_base_type t mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != a);
	mk_lang_assert(d != b);
	mk_lang_assert(!(d >= &a->m_data[0] && d < &a->m_data[mk_sl_cui_inl_defd_count]));

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], b, &t, d);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_dec1(d);
#elif mk_sl_cui_inl_defd_count == 3
	mk_sl_cui_inl_defd_base_type t mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != a);
	mk_lang_assert(d != b);
	mk_lang_assert(!(d >= &a->m_data[0] && d < &a->m_data[mk_sl_cui_inl_defd_count]));

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], b, &t, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], b, &t, d);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(d);
#elif mk_sl_cui_inl_defd_count == 4
	mk_sl_cui_inl_defd_base_type t mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != a);
	mk_lang_assert(d != b);
	mk_lang_assert(!(d >= &a->m_data[0] && d < &a->m_data[mk_sl_cui_inl_defd_count]));

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], b, &t, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(2)], b, &t, &c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(2)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(3)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(3)], b, &t, d);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(3)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(d);
#else
	mk_sl_cui_inl_defd_base_type t mk_lang_constexpr_init;
	mk_lang_bool_t cf mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(!(b >= &a->m_data[0] && b < &a->m_data[mk_sl_cui_inl_defd_count]));
	mk_lang_assert(!(b >= &c->m_data[0] && b < &c->m_data[mk_sl_cui_inl_defd_count]));
	mk_lang_assert(c != a);

	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(0)], b, &c->m_data[mk_sl_cui_inl_defd_idx(0)], &c->m_data[mk_sl_cui_inl_defd_idx(1)]);
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(1)], b, &t, &c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(1)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(2)]);
	for(i = 2; i != mk_sl_cui_inl_defd_count - 1; ++i)
	{
		mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(i)], b, &t, &c->m_data[mk_sl_cui_inl_defd_idx(i + 1)]);
		mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(i)], &t, &cf);
		if(cf) mk_sl_cui_inl_defd_base_inc1(&c->m_data[mk_sl_cui_inl_defd_idx(i + 1)]);
	}
	mk_sl_cui_inl_defd_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], b, &t, d);
	mk_sl_cui_inl_defd_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_defd_idx(mk_sl_cui_inl_defd_count - 1)], &t, &cf);
	if(cf) mk_sl_cui_inl_defd_base_inc1(d);
#endif
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo int mk_sl_cui_inl_defd_to_str_dec_n(mk_sl_cui_inl_defd_t const* const x, char* const str, int const str_len) mk_lang_noexcept
{
	#define mk_sl_cui_inl_defd_base_to_bi_sint mk_lang_concat(mk_sl_cui_inl_defd_base_name, _to_bi_sint)
	#define mk_sl_cui_inl_defd_base_from_bi_sint mk_lang_concat(mk_sl_cui_inl_defd_base_name, _from_bi_sint)

	char const s_symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	int i mk_lang_constexpr_init;
	int n mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type base mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t* pa1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t a1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t* pa2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t a2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t* pa3 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type b mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str || str_len == 0);
	mk_lang_assert(str_len >= 0);

	i = str_len;
	n = 10;
	mk_sl_cui_inl_defd_base_from_bi_sint(&base, &n);
	pa1 = &a1;
	pa2 = &a2;
	*pa2 = *x;
	for(;;)
	{
		pa3 = pa1;
		pa1 = pa2;
		pa2 = pa3;
		mk_sl_cui_inl_defd_divmod_smol(pa1, &base, pa2, &b);
		mk_sl_cui_inl_defd_base_to_bi_sint(&b, &n);
		mk_lang_assert(n >= 0 && n < 10);
		str[--i] = s_symbols[n];
		if(mk_sl_cui_inl_defd_is_zero(pa2))
		{
			break;
		}
		if(i == 0)
		{
			return 0;
		}
	}
	if(i != 0)
	{
		mk_lang_memmove_obj_pchar(str, str + i, ((unsigned)(str_len - i)));
	}
	return str_len - i;

	#undef mk_sl_cui_inl_defd_to_bi_sint
	#undef mk_sl_cui_inl_defd_from_bi_sint
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo int mk_sl_cui_inl_defd_from_str_dec_n(mk_sl_cui_inl_defd_t* const x, char const* const str, int const str_len) mk_lang_noexcept
{
	#define mk_sl_cui_inl_defd_base_to_bi_sint mk_lang_concat(mk_sl_cui_inl_defd_base_name, _to_bi_sint)
	#define mk_sl_cui_inl_defd_base_from_bi_sint mk_lang_concat(mk_sl_cui_inl_defd_base_name, _from_bi_sint)
	#define mk_sl_cui_inl_defd_from_bi_sint mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _from_bi_sint)

	mk_lang_constexpr char const s_symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	mk_sl_cui_inl_defd_base_type s_base mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t s_border_value mk_lang_constexpr_init;
	int s_border_digit mk_lang_constexpr_init;

	char const* it mk_lang_constexpr_init;
	char const* ite mk_lang_constexpr_init;
	char e mk_lang_constexpr_init;
	int i mk_lang_constexpr_init;
	int overflow mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t* px1 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t xx mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t* px2 mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_base_type digit mk_lang_constexpr_init;
	mk_sl_cui_inl_defd_t* px3 mk_lang_constexpr_init;

	mk_lang_assert(x);
	mk_lang_assert(str);
	mk_lang_assert(str_len > 0);

	{
		int n mk_lang_constexpr_init;
		mk_sl_cui_inl_defd_base_type base mk_lang_constexpr_init;
		mk_sl_cui_inl_defd_t mx mk_lang_constexpr_init;
		mk_sl_cui_inl_defd_t border_value mk_lang_constexpr_init;
		mk_sl_cui_inl_defd_base_type border_digit mk_lang_constexpr_init;

		n = 10;
		mk_sl_cui_inl_defd_base_from_bi_sint(&base, &n);
		mk_sl_cui_inl_defd_set_max(&mx);
		mk_sl_cui_inl_defd_divmod_smol(&mx, &base, &border_value, &border_digit);
		mk_sl_cui_inl_defd_base_to_bi_sint(&border_digit, &n);
		s_base = base;
		s_border_value = border_value;
		s_border_digit = n;
	}

	it = str;
	ite = str + str_len;
	e = *it;
	for(i = 0; i != ((int)(sizeof(s_symbols) / sizeof(s_symbols[0]))); ++i)
	{
		if(e == s_symbols[i])
		{
			break;
		}
	}
	if(i == ((int)(sizeof(s_symbols) / sizeof(s_symbols[0]))))
	{
		return 0;
	}
	overflow = 1;
	px1 = &xx;
	px2 = x;
	mk_sl_cui_inl_defd_from_bi_sint(px1, &i);
	for(++it; it != ite; ++it)
	{
		e = *it;
		for(i = 0; i != ((int)(sizeof(s_symbols) / sizeof(s_symbols[0]))); ++i)
		{
			if(e == s_symbols[i])
			{
				break;
			}
		}
		if(i == ((int)(sizeof(s_symbols) / sizeof(s_symbols[0]))))
		{
			break;
		}
		if(!(mk_sl_cui_inl_defd_lt(px1, &s_border_value) || (mk_sl_cui_inl_defd_eq(px1, &s_border_value) && i <= s_border_digit)))
		{
			overflow = -1;
			break;
		}
		mk_sl_cui_inl_defd_mul3_wrap_lo_smol(px1, &s_base, px2);
		mk_sl_cui_inl_defd_base_from_bi_sint(&digit, &i);
		mk_sl_cui_inl_defd_add2_wrap_cid_cod_smol(px2, &digit);
		px3 = px1;
		px1 = px2;
		px2 = px3;
	}
	if(px1 == &xx)
	{
		*x = xx;
	}
	return ((int)(((int)(it - str)) * overflow));

	#undef mk_sl_cui_inl_defd_to_bi_sint
	#undef mk_sl_cui_inl_defd_from_bi_sint
	#undef mk_sl_cui_inl_defd_from_bi_sint
}


#include "mk_sl_cui_inl_defu.h"


#undef mk_sl_cui_name
#undef mk_sl_cui_base_type
#undef mk_sl_cui_base_name
#undef mk_sl_cui_base_bits
#undef mk_sl_cui_count
#undef mk_sl_cui_endian
#undef mk_sl_cui_base_is_bui
#undef mk_sl_cui_base_bui_tn
