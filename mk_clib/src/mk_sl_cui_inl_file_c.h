#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"


#include "mk_sl_cui_inl_def.h"


mk_lang_jumbo void mk_sl_cui_inl_def_set_zero(mk_sl_cui_inl_def_t* const x)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_def_base_set_zero(&x->m_data[0]);
#else
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_set_zero(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_set_max(mk_sl_cui_inl_def_t* const x)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_def_base_set_max(&x->m_data[0]);
#else
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_set_max(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_set_one(mk_sl_cui_inl_def_t* const x)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_def_base_set_one(&x->m_data[0]);
#else
	int i;

	mk_lang_assert(x);

	mk_sl_cui_inl_def_base_set_one(&x->m_data[mk_sl_cui_inl_def_idx(0)]);
	for(i = 1; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_set_zero(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_set_bit(mk_sl_cui_inl_def_t* const x, int const bit_idx)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_def_base_set_bit(&x->m_data[0], bit_idx);
#else
	mk_lang_assert(x);
	mk_lang_assert(bit_idx >= 0 && bit_idx < ((int)(mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits)));

	mk_sl_cui_inl_def_set_zero(x);
	mk_sl_cui_inl_def_base_set_bit(&x->m_data[mk_sl_cui_inl_def_idx(bit_idx / mk_sl_cui_inl_def_base_bits)], bit_idx % mk_sl_cui_inl_def_base_bits);
#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_set_mask(mk_sl_cui_inl_def_t* const x, int const bits_count)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(x);
	mk_sl_cui_inl_def_base_set_mask(&x->m_data[0], bits_count);
#else
	int i;

	mk_lang_assert(x);
	mk_lang_assert(bits_count >= 1 && bits_count <= ((int)(mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits)));

	for(i = 0; i != bits_count / mk_sl_cui_inl_def_base_bits; ++i)
	{
		mk_sl_cui_inl_def_base_set_max(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
	if(bits_count % mk_sl_cui_inl_def_base_bits != 0)
	{
		mk_sl_cui_inl_def_base_set_mask(&x->m_data[mk_sl_cui_inl_def_idx(i)], bits_count % mk_sl_cui_inl_def_base_bits);
		++i;
	}
	for(; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_set_zero(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
#endif
}

#include "mk_sl_cui_inl_to_bi_c.h"
#include "mk_sl_cui_inl_from_bi_c.h"
#include "mk_sl_cui_inl_to_buis_c.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_is_zero(mk_sl_cui_inl_def_t const* const x)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(x);
	return mk_sl_cui_inl_def_base_is_zero(&x->m_data[0]);
#else
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		if(!mk_sl_cui_inl_def_base_is_zero(&x->m_data[mk_sl_cui_inl_def_idx(i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_is_max(mk_sl_cui_inl_def_t const* const x)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(x);
	return mk_sl_cui_inl_def_base_is_max(&x->m_data[0]);
#else
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		if(!mk_sl_cui_inl_def_base_is_max(&x->m_data[mk_sl_cui_inl_def_idx(i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_eq(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_def_base_eq(&a->m_data[0], &b->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		if(!mk_sl_cui_inl_def_base_eq(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_ne(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_def_base_ne(&a->m_data[0], &b->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		if(mk_sl_cui_inl_def_base_ne(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)]))
		{
			return mk_lang_true;
		}
	}
	return mk_lang_false;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_lt(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_def_base_lt(&a->m_data[0], &b->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		if(mk_sl_cui_inl_def_base_lt(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]))
		{
			return mk_lang_true;
		}
		else if(mk_sl_cui_inl_def_base_lt(&b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)], &a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_false;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_le(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_def_base_le(&a->m_data[0], &b->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		if(mk_sl_cui_inl_def_base_lt(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]))
		{
			return mk_lang_true;
		}
		else if(mk_sl_cui_inl_def_base_lt(&b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)], &a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_gt(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_def_base_gt(&a->m_data[0], &b->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		if(mk_sl_cui_inl_def_base_gt(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]))
		{
			return mk_lang_true;
		}
		else if(mk_sl_cui_inl_def_base_gt(&b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)], &a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_false;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_ge(mk_sl_cui_inl_def_t const* const a, mk_sl_cui_inl_def_t const* const b)
{
#if mk_sl_cui_inl_def_count == 1
	mk_lang_assert(a);
	mk_lang_assert(b);
	return mk_sl_cui_inl_def_base_ge(&a->m_data[0], &b->m_data[0]);
#else
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		if(mk_sl_cui_inl_def_base_gt(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]))
		{
			return mk_lang_true;
		}
		else if(mk_sl_cui_inl_def_base_gt(&b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)], &a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]))
		{
			return mk_lang_false;
		}
	}
	return mk_lang_true;
#endif
}


#include "mk_sl_cui_inl_undef.h"
