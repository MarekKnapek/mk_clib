#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_for_constants.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"


#include "mk_sl_cui_inl_defd.h"


mk_lang_jumbo void mk_sl_cui_inl_defd_set_zero(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_set_zero(&x->m_data[0]);
#else
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_set_max(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_set_max(&x->m_data[0]);
#else
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_set_max(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_set_one(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_set_one(&x->m_data[0]);
#else
	int i;

	mk_lang_assert(x);

	mk_sl_cui_inl_defd_base_set_one(&x->m_data[mk_sl_cui_inl_defd_idx(0)]);
	for(i = 1; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_set_zero(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_set_bit(mk_sl_cui_inl_defd_t* const x, int const bit_idx) mk_lang_noexcept
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

mk_lang_jumbo void mk_sl_cui_inl_defd_set_mask(mk_sl_cui_inl_defd_t* const x, int const bits_count) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_set_mask(&x->m_data[0], bits_count);
#else
	int i;

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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_is_zero(mk_sl_cui_inl_defd_t const* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	return mk_sl_cui_inl_defd_base_is_zero(&x->m_data[0]);
#else
	int i;

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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_is_max(mk_sl_cui_inl_defd_t const* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	return mk_sl_cui_inl_defd_base_is_max(&x->m_data[0]);
#else
	int i;

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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_eq(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
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
		int i;

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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_ne(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
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
		int i;

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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_lt(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
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
		int i;

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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_le(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
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
		int i;

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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_gt(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
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
		int i;

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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_ge(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
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
		int i;

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


mk_lang_jumbo void mk_sl_cui_inl_defd_inc2(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept
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
		int i;
		mk_lang_bool_t c;

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

mk_lang_jumbo void mk_sl_cui_inl_defd_dec2(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept
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
		int i;
		mk_lang_bool_t c;

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

mk_lang_jumbo void mk_sl_cui_inl_defd_inc1(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_inc1(&x->m_data[0]);
#else
	int i;
	mk_lang_bool_t c;

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

mk_lang_jumbo void mk_sl_cui_inl_defd_dec1(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_dec1(&x->m_data[0]);
#else
	int i;
	mk_lang_bool_t c;

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


mk_lang_jumbo void mk_sl_cui_inl_defd_not2(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_sl_cui_inl_defd_base_not2(&a->m_data[0], &b->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_not2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_or3(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_or3(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_or3(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_and3(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_and3(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_and3(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_xor3(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_xor3(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_xor3(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)], &c->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_not1(mk_sl_cui_inl_defd_t* const x) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_defd_base_not1(&x->m_data[0]);
#else
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_not1(&x->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_or2(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_sl_cui_inl_defd_base_or2(&a->m_data[0], &b->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_or2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_and2(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_sl_cui_inl_defd_base_and2(&a->m_data[0], &b->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_and2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_xor2(mk_sl_cui_inl_defd_t* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_sl_cui_inl_defd_base_xor2(&a->m_data[0], &b->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_defd_count; ++i)
	{
		mk_sl_cui_inl_defd_base_xor2(&a->m_data[mk_sl_cui_inl_defd_idx(i)], &b->m_data[mk_sl_cui_inl_defd_idx(i)]);
	}
#endif
}


mk_lang_jumbo void mk_sl_cui_inl_defd_shl3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_shl3(&a->m_data[0], b, &c->m_data[0]);
#else
	int i;
	int big;
	int smol;
	mk_sl_cui_inl_defd_base_type t;

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

mk_lang_jumbo void mk_sl_cui_inl_defd_shr3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_shr3(&a->m_data[0], b, &c->m_data[0]);
#else
	int i;
	int big;
	int smol;
	mk_sl_cui_inl_defd_base_type t;

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

mk_lang_jumbo void mk_sl_cui_inl_defd_rotl3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_rotl3(&a->m_data[0], b, &c->m_data[0]);
#else
	mk_sl_cui_inl_defd_t ta;
	mk_sl_cui_inl_defd_t tb;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_shl3(a, b, &ta);
	mk_sl_cui_inl_defd_shr3(a, mk_sl_cui_inl_defd_bits - b, &tb);
	mk_sl_cui_inl_defd_or3(&ta, &tb, c);
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_rotr3(mk_sl_cui_inl_defd_t const* const a, int const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);
	mk_sl_cui_inl_defd_base_rotr3(&a->m_data[0], b, &c->m_data[0]);
#else
	mk_sl_cui_inl_defd_t ta;
	mk_sl_cui_inl_defd_t tb;

	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < mk_sl_cui_inl_defd_bits);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_shr3(a, b, &ta);
	mk_sl_cui_inl_defd_shl3(a, mk_sl_cui_inl_defd_bits - b, &tb);
	mk_sl_cui_inl_defd_or3(&ta, &tb, c);
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_defd_shl2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_shl3(a, b, a);
}

mk_lang_jumbo void mk_sl_cui_inl_defd_shr2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_shr3(a, b, a);
}

mk_lang_jumbo void mk_sl_cui_inl_defd_rotl2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_rotl3(a, b, a);
}

mk_lang_jumbo void mk_sl_cui_inl_defd_rotr2(mk_sl_cui_inl_defd_t* const a, int const b) mk_lang_noexcept
{
	mk_sl_cui_inl_defd_rotr3(a, b, a);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_add_cc(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_would_overflow_add_cc(&a->m_data[0], &b->m_data[0]);
#else
	int i;
	mk_sl_cui_inl_defd_base_type ta;
	mk_sl_cui_inl_defd_base_type tb;

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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_add_cs(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);

	return mk_sl_cui_inl_defd_base_would_overflow_add_cs(&a->m_data[0], &b->m_data[0]);
#else
	int i;
	mk_sl_cui_inl_defd_base_type ta;
	mk_sl_cui_inl_defd_base_type tb;

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

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_add(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const cf) mk_lang_noexcept
{
	return cf ? mk_sl_cui_inl_defd_would_overflow_add_cs(a, b) : mk_sl_cui_inl_defd_would_overflow_add_cc(a, b);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_sub_cc(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	return mk_sl_cui_inl_defd_lt(a, b);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_sub_cs(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	return mk_sl_cui_inl_defd_le(a, b);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_sub(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const cf) mk_lang_noexcept
{
	return cf ? mk_sl_cui_inl_defd_would_overflow_sub_cs(a, b) : mk_sl_cui_inl_defd_would_overflow_sub_cc(a, b);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_defd_would_overflow_mul(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b) mk_lang_noexcept
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return 0; /*todo*/
}


mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cid_cod(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_add3_wrap_cid_cod(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
#else
	mk_lang_bool_t cf;
	int i;

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

mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cid_coe(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_sl_cui_inl_defd_t* const c, mk_lang_bool_t* const co) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_add3_wrap_cid_coe(&a->m_data[0], &b->m_data[0], &c->m_data[0], co);
#else
	mk_lang_bool_t cf;
	int i;

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

mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cie_cod(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_sl_cui_inl_defd_t* const c) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_defd_base_add3_wrap_cie_cod(&a->m_data[0], &b->m_data[0], ci, &c->m_data[0]);
#else
	mk_lang_bool_t cf;
	int i;

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

mk_lang_jumbo void mk_sl_cui_inl_defd_add3_wrap_cie_coe(mk_sl_cui_inl_defd_t const* const a, mk_sl_cui_inl_defd_t const* const b, mk_lang_bool_t const ci, mk_sl_cui_inl_defd_t* const c, mk_lang_bool_t* const co) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	mk_sl_cui_inl_defd_base_add3_wrap_cie_coe(&a->m_data[0], &b->m_data[0], ci, &c->m_data[0], co);
#else
	mk_lang_bool_t cf;
	int i;

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

#include "mk_sl_cui_inl_defu.h"
