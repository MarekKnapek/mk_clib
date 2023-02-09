#ifndef mk_include_guard_sl_cui
#include "mk_sl_cui_inl.h"
#endif

#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"


#include "mk_sl_cui_inl_def.h"


mk_lang_jumbo void mk_sl_cui_inl_def_set_zero(mk_sl_cui_inl_def_t* x)
{
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_set_zero(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_set_max(mk_sl_cui_inl_def_t* x)
{
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_set_max(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_set_one(mk_sl_cui_inl_def_t* x)
{
	int i;

	mk_lang_assert(x);

	mk_sl_cui_inl_def_base_set_one(&x->m_data[mk_sl_cui_inl_def_idx(0)]);
	for(i = 1; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_set_zero(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_set_bit(mk_sl_cui_inl_def_t* x, int bit_idx)
{
	mk_lang_assert(x);
	mk_lang_assert(bit_idx >= 0 && bit_idx < ((int)(mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits)));

	mk_sl_cui_inl_def_set_zero(x);
	mk_sl_cui_inl_def_base_set_bit(&x->m_data[mk_sl_cui_inl_def_idx(bit_idx / mk_sl_cui_inl_def_base_bits)], bit_idx % mk_sl_cui_inl_def_base_bits);
}

mk_lang_jumbo void mk_sl_cui_inl_def_set_mask(mk_sl_cui_inl_def_t* x, int bits_count)
{
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
}

#include "mk_sl_cui_inl_to_bi.c"
#include "mk_sl_cui_inl_from_bi.c"

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_is_zero(mk_sl_cui_inl_def_t const* x)
{
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
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_is_max(mk_sl_cui_inl_def_t const* x)
{
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
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_eq(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b)
{
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
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_ne(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b)
{
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
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_lt(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b)
{
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
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_le(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b)
{
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
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_gt(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b)
{
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
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_sl_cui_inl_def_ge(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b)
{
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
}


mk_lang_jumbo void mk_sl_cui_inl_def_inc2(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t* b)
{
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_inc2(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)]);
		if(!mk_sl_cui_inl_def_base_is_zero(&b->m_data[mk_sl_cui_inl_def_idx(i)]))
		{
			break;
		}
	}
	for(++i; i < mk_sl_cui_inl_def_count; ++i)
	{
		b->m_data[mk_sl_cui_inl_def_idx(i)] = a->m_data[mk_sl_cui_inl_def_idx(i)];
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_dec2(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t* b)
{
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_dec2(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)]);
		if(!mk_sl_cui_inl_def_base_is_max(&b->m_data[mk_sl_cui_inl_def_idx(i)]))
		{
			break;
		}
	}
	for(++i; i < mk_sl_cui_inl_def_count; ++i)
	{
		b->m_data[mk_sl_cui_inl_def_idx(i)] = a->m_data[mk_sl_cui_inl_def_idx(i)];
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_inc1(mk_sl_cui_inl_def_t* x)
{
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_inc1(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
		if(!mk_sl_cui_inl_def_base_is_zero(&x->m_data[mk_sl_cui_inl_def_idx(i)]))
		{
			break;
		}
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_dec1(mk_sl_cui_inl_def_t* x)
{
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_dec1(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
		if(!mk_sl_cui_inl_def_base_is_max(&x->m_data[mk_sl_cui_inl_def_idx(i)]))
		{
			break;
		}
	}
}


mk_lang_jumbo void mk_sl_cui_inl_def_not2(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t* b)
{
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_not2(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_or3(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_or3(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], &c->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_and3(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_and3(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], &c->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_xor3(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_xor3(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], &c->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_not1(mk_sl_cui_inl_def_t* x)
{
	int i;

	mk_lang_assert(x);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_not1(&x->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_or2(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b)
{
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_or2(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_and2(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b)
{
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_and2(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_xor2(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b)
{
	int i;

	mk_lang_assert(a);
	mk_lang_assert(b);

	for(i = 0; i != mk_sl_cui_inl_def_count; ++i)
	{
		mk_sl_cui_inl_def_base_xor2(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)]);
	}
}


mk_lang_jumbo void mk_sl_cui_inl_def_shl3(mk_sl_cui_inl_def_t const* a, int b, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((int)(mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits)));
	mk_lang_assert(c);

	if(b == 0)
	{
		*c = *a;
	}
	else
	{
		int n;
		int m;
		int i;

		n = b / mk_sl_cui_inl_def_base_bits;
		m = b % mk_sl_cui_inl_def_base_bits;
		if(m == 0)
		{
			for(i = 0; i != mk_sl_cui_inl_def_count - n; ++i)
			{
				c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)] = a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - n - i)];
			}
			for(; i != mk_sl_cui_inl_def_count; ++i)
			{
				mk_sl_cui_inl_def_base_set_zero(&c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]);
			}
		}
		else
		{
			for(i = 0; i != mk_sl_cui_inl_def_count - 1 - n; ++i)
			{
				mk_sl_cui_inl_def_base_type ta;
				mk_sl_cui_inl_def_base_type tb;

				mk_sl_cui_inl_def_base_shl3(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - n - i)], m, &ta);
				mk_sl_cui_inl_def_base_shr3(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 2 - n - i)], mk_sl_cui_inl_def_base_bits - m, &tb);
				mk_sl_cui_inl_def_base_or3(&ta, &tb, &c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]);
			}
			mk_sl_cui_inl_def_base_shl3(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - n - i)], m, &c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]);
			for(++i; i != mk_sl_cui_inl_def_count; ++i)
			{
				mk_sl_cui_inl_def_base_set_zero(&c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1 - i)]);
			}
		}
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_shr3(mk_sl_cui_inl_def_t const* a, int b, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((int)(mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits)));
	mk_lang_assert(c);

	if(b == 0)
	{
		*c = *a;
	}
	else
	{
		int n;
		int m;
		int i;

		n = b / mk_sl_cui_inl_def_base_bits;
		m = b % mk_sl_cui_inl_def_base_bits;
		if(m == 0)
		{
			for(i = 0; i != mk_sl_cui_inl_def_count - n; ++i)
			{
				c->m_data[mk_sl_cui_inl_def_idx(i)] = a->m_data[mk_sl_cui_inl_def_idx(n + i)];
			}
			for(; i != mk_sl_cui_inl_def_count; ++i)
			{
				mk_sl_cui_inl_def_base_set_zero(&c->m_data[mk_sl_cui_inl_def_idx(i)]);
			}
		}
		else
		{
			for(i = 0; i != mk_sl_cui_inl_def_count - 1 - n; ++i)
			{
				mk_sl_cui_inl_def_base_type ta;
				mk_sl_cui_inl_def_base_type tb;

				mk_sl_cui_inl_def_base_shr3(&a->m_data[mk_sl_cui_inl_def_idx(n + i)], m, &ta);
				mk_sl_cui_inl_def_base_shl3(&a->m_data[mk_sl_cui_inl_def_idx(n + 1 + i)], mk_sl_cui_inl_def_base_bits - m, &tb);
				mk_sl_cui_inl_def_base_or3(&ta, &tb, &c->m_data[mk_sl_cui_inl_def_idx(i)]);
			}
			mk_sl_cui_inl_def_base_shr3(&a->m_data[mk_sl_cui_inl_def_idx(n + i)], m, &c->m_data[mk_sl_cui_inl_def_idx(i)]);
			for(++i; i != mk_sl_cui_inl_def_count; ++i)
			{
				mk_sl_cui_inl_def_base_set_zero(&c->m_data[mk_sl_cui_inl_def_idx(i)]);
			}
		}
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_rotl3(mk_sl_cui_inl_def_t const* a, int b, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((int)(mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits)));
	mk_lang_assert(c);

	if(b == 0)
	{
		*c = *a;
	}
	else
	{
		mk_sl_cui_inl_def_t ta;
		mk_sl_cui_inl_def_t tb;

		mk_sl_cui_inl_def_shl3(a, b, &ta);
		mk_sl_cui_inl_def_shr3(a, mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits - b, &tb);
		mk_sl_cui_inl_def_or3(&ta, &tb, c);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_rotr3(mk_sl_cui_inl_def_t const* a, int b, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((int)(mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits)));
	mk_lang_assert(c);

	if(b == 0)
	{
		*c = *a;
	}
	else
	{
		mk_sl_cui_inl_def_t ta;
		mk_sl_cui_inl_def_t tb;

		mk_sl_cui_inl_def_shr3(a, b, &ta);
		mk_sl_cui_inl_def_shl3(a, mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits - b, &tb);
		mk_sl_cui_inl_def_or3(&ta, &tb, c);
	}
}

mk_lang_jumbo void mk_sl_cui_inl_def_shl2(mk_sl_cui_inl_def_t* a, int b)
{
	mk_sl_cui_inl_def_shl3(a, b, a);
}

mk_lang_jumbo void mk_sl_cui_inl_def_shr2(mk_sl_cui_inl_def_t* a, int b)
{
	mk_sl_cui_inl_def_shr3(a, b, a);
}

mk_lang_jumbo void mk_sl_cui_inl_def_rotl2(mk_sl_cui_inl_def_t* a, int b)
{
	mk_sl_cui_inl_def_rotl3(a, b, a);
}

mk_lang_jumbo void mk_sl_cui_inl_def_rotr2(mk_sl_cui_inl_def_t* a, int b)
{
	mk_sl_cui_inl_def_rotr3(a, b, a);
}


mk_lang_jumbo void mk_sl_cui_inl_def_add3_wrap_cid_cod(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_add3_wrap_cid_cod(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
	#elif mk_sl_cui_inl_def_count == 2
	{
		mk_lang_bool_t o;

		mk_sl_cui_inl_def_base_add3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		mk_sl_cui_inl_def_base_add3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(1)], o, &c->m_data[mk_sl_cui_inl_def_idx(1)]);
	}
	#else
	{
		mk_lang_bool_t o;
		int i;

		mk_sl_cui_inl_def_base_add3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		for(i = 1; i != mk_sl_cui_inl_def_count - 1; ++i)
		{
			mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], o, &c->m_data[mk_sl_cui_inl_def_idx(i)], &o);
		}
		mk_sl_cui_inl_def_base_add3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], o, &c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)]);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_add3_wrap_cid_coe(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c, mk_lang_bool_t* co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_add3_wrap_cid_coe(&a->m_data[0], &b->m_data[0], &c->m_data[0], co);
	#elif mk_sl_cui_inl_def_count == 2
	{
		mk_lang_bool_t o;

		mk_sl_cui_inl_def_base_add3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(1)], o, &c->m_data[mk_sl_cui_inl_def_idx(1)], co);
	}
	#else
	{
		mk_lang_bool_t o;
		int i;

		mk_sl_cui_inl_def_base_add3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		for(i = 1; i != mk_sl_cui_inl_def_count - 1; ++i)
		{
			mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], o, &c->m_data[mk_sl_cui_inl_def_idx(i)], &o);
		}
		mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], o, &c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], co);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_add3_wrap_cie_cod(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_add3_wrap_cie_cod(&a->m_data[0], &b->m_data[0], ci, &c->m_data[0]);
	#elif mk_sl_cui_inl_def_count == 2
	{
		mk_lang_bool_t o;

		mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], ci, &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		mk_sl_cui_inl_def_base_add3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(1)], o, &c->m_data[mk_sl_cui_inl_def_idx(1)]);
	}
	#else
	{
		mk_lang_bool_t o;
		int i;

		mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], ci, &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		for(i = 1; i != mk_sl_cui_inl_def_count - 1; ++i)
		{
			mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], o, &c->m_data[mk_sl_cui_inl_def_idx(i)], &o);
		}
		mk_sl_cui_inl_def_base_add3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], o, &c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)]);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_add3_wrap_cie_coe(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_sl_cui_inl_def_t* c, mk_lang_bool_t* co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[0], &b->m_data[0], ci, &c->m_data[0], co);
	#elif mk_sl_cui_inl_def_count == 2
	{
		mk_lang_bool_t o;

		mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], ci, &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(1)], o, &c->m_data[mk_sl_cui_inl_def_idx(1)], co);
	}
	#else
	{
		mk_lang_bool_t o;
		int i;

		mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], ci, &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		for(i = 1; i != mk_sl_cui_inl_def_count - 1; ++i)
		{
			mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], o, &c->m_data[mk_sl_cui_inl_def_idx(i)], &o);
		}
		mk_sl_cui_inl_def_base_add3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], o, &c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], co);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_add2_wrap_cid_cod(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b)
{
	mk_sl_cui_inl_def_add3_wrap_cid_cod(a, b, a);
}

mk_lang_jumbo void mk_sl_cui_inl_def_add2_wrap_cid_coe(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t* co)
{
	mk_sl_cui_inl_def_add3_wrap_cid_coe(a, b, a, co);
}

mk_lang_jumbo void mk_sl_cui_inl_def_add2_wrap_cie_cod(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci)
{
	mk_sl_cui_inl_def_add3_wrap_cie_cod(a, b, ci, a);
}

mk_lang_jumbo void mk_sl_cui_inl_def_add2_wrap_cie_coe(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_sl_cui_inl_def_add3_wrap_cie_coe(a, b, ci, a, co);
}


mk_lang_jumbo void mk_sl_cui_inl_def_sub3_wrap_cid_cod(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_sub3_wrap_cid_cod(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
	#elif mk_sl_cui_inl_def_count == 2
	{
		mk_lang_bool_t o;

		mk_sl_cui_inl_def_base_sub3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		mk_sl_cui_inl_def_base_sub3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(1)], o, &c->m_data[mk_sl_cui_inl_def_idx(1)]);
	}
	#else
	{
		mk_lang_bool_t o;
		int i;

		mk_sl_cui_inl_def_base_sub3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		for(i = 1; i != mk_sl_cui_inl_def_count - 1; ++i)
		{
			mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], o, &c->m_data[mk_sl_cui_inl_def_idx(i)], &o);
		}
		mk_sl_cui_inl_def_base_sub3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], o, &c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)]);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_sub3_wrap_cid_coe(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c, mk_lang_bool_t* co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_sub3_wrap_cid_coe(&a->m_data[0], &b->m_data[0], &c->m_data[0], co);
	#elif mk_sl_cui_inl_def_count == 2
	{
		mk_lang_bool_t o;

		mk_sl_cui_inl_def_base_sub3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(1)], o, &c->m_data[mk_sl_cui_inl_def_idx(1)], co);
	}
	#else
	{
		mk_lang_bool_t o;
		int i;

		mk_sl_cui_inl_def_base_sub3_wrap_cid_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		for(i = 1; i != mk_sl_cui_inl_def_count - 1; ++i)
		{
			mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], o, &c->m_data[mk_sl_cui_inl_def_idx(i)], &o);
		}
		mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], o, &c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], co);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_sub3_wrap_cie_cod(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_sub3_wrap_cie_cod(&a->m_data[0], &b->m_data[0], ci, &c->m_data[0]);
	#elif mk_sl_cui_inl_def_count == 2
	{
		mk_lang_bool_t o;

		mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], ci, &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		mk_sl_cui_inl_def_base_sub3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(1)], o, &c->m_data[mk_sl_cui_inl_def_idx(1)]);
	}
	#else
	{
		mk_lang_bool_t o;
		int i;

		mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], ci, &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		for(i = 1; i != mk_sl_cui_inl_def_count - 1; ++i)
		{
			mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], o, &c->m_data[mk_sl_cui_inl_def_idx(i)], &o);
		}
		mk_sl_cui_inl_def_base_sub3_wrap_cie_cod(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], o, &c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)]);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_sub3_wrap_cie_coe(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_sl_cui_inl_def_t* c, mk_lang_bool_t* co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[0], &b->m_data[0], ci, &c->m_data[0], co);
	#elif mk_sl_cui_inl_def_count == 2
	{
		mk_lang_bool_t o;

		mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], ci, &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(1)], o, &c->m_data[mk_sl_cui_inl_def_idx(1)], co);
	}
	#else
	{
		mk_lang_bool_t o;
		int i;

		mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], ci, &c->m_data[mk_sl_cui_inl_def_idx(0)], &o);
		for(i = 1; i != mk_sl_cui_inl_def_count - 1; ++i)
		{
			mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], o, &c->m_data[mk_sl_cui_inl_def_idx(i)], &o);
		}
		mk_sl_cui_inl_def_base_sub3_wrap_cie_coe(&a->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], &b->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], o, &c->m_data[mk_sl_cui_inl_def_idx(mk_sl_cui_inl_def_count - 1)], co);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_sub2_wrap_cid_cod(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b)
{
	mk_sl_cui_inl_def_sub3_wrap_cid_cod(a, b, a);
}

mk_lang_jumbo void mk_sl_cui_inl_def_sub2_wrap_cid_coe(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t* co)
{
	mk_sl_cui_inl_def_sub3_wrap_cid_coe(a, b, a, co);
}

mk_lang_jumbo void mk_sl_cui_inl_def_sub2_wrap_cie_cod(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci)
{
	mk_sl_cui_inl_def_sub3_wrap_cie_cod(a, b, ci, a);
}

mk_lang_jumbo void mk_sl_cui_inl_def_sub2_wrap_cie_coe(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_sl_cui_inl_def_sub3_wrap_cie_coe(a, b, ci, a, co);
}


mk_lang_jumbo void mk_sl_cui_inl_def_mul3_wrap_lo_restrict(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(mk_sl_cui_inl_def_count >= 2);
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c != a && c != b);

	#if mk_sl_cui_inl_def_count == 2
	{
		mk_sl_cui_inl_def_base_type t;

		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(1)]);
		mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &t);
		mk_sl_cui_inl_def_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_def_idx(1)], &t);
		mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(1)], &t);
		mk_sl_cui_inl_def_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_def_idx(1)], &t);
	}
	#elif mk_sl_cui_inl_def_count == 3
	{
		mk_sl_cui_inl_def_base_type ta;
		mk_lang_bool_t cf;
		mk_sl_cui_inl_def_base_type tb;

		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(1)]);
		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &ta, &c->m_data[mk_sl_cui_inl_def_idx(2)]);
		mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(1)], &ta, &cf);
		if(cf) mk_sl_cui_inl_def_base_inc1(&c->m_data[mk_sl_cui_inl_def_idx(2)]);
		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(1)], &ta, &tb);
		mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(1)], &ta, &cf);
		mk_sl_cui_inl_def_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_def_idx(2)], &tb, cf);
		mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_def_idx(2)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &ta);
		mk_sl_cui_inl_def_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_def_idx(2)], &ta);
		mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(1)], &ta);
		mk_sl_cui_inl_def_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_def_idx(2)], &ta);
		mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(2)], &ta);
		mk_sl_cui_inl_def_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_def_idx(2)], &ta);
	}
	#elif mk_sl_cui_inl_def_count == 4
	{
		mk_sl_cui_inl_def_base_type ta;
		mk_lang_bool_t cf;
		mk_sl_cui_inl_def_base_type tb;

		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(1)]);
		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &ta, &c->m_data[mk_sl_cui_inl_def_idx(2)]);
		mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(1)], &ta, &cf);
		if(cf) mk_sl_cui_inl_def_base_inc1(&c->m_data[mk_sl_cui_inl_def_idx(2)]);
		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(1)], &ta, &tb);
		mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(1)], &ta, &cf);
		mk_sl_cui_inl_def_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_def_idx(2)], &tb, cf, &cf);
		if(cf) mk_sl_cui_inl_def_base_set_one(&c->m_data[mk_sl_cui_inl_def_idx(3)]); else mk_sl_cui_inl_def_base_set_zero(&c->m_data[mk_sl_cui_inl_def_idx(3)]);
		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(2)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &ta, &tb);
		mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(2)], &ta, &cf);
		mk_sl_cui_inl_def_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_def_idx(3)], &tb, cf);
		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(1)], &ta, &tb);
		mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(2)], &ta, &cf);
		mk_sl_cui_inl_def_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_def_idx(3)], &tb, cf);
		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(2)], &ta, &tb);
		mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(2)], &ta, &cf);
		mk_sl_cui_inl_def_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_def_idx(3)], &tb, cf);
		mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_def_idx(3)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &ta);
		mk_sl_cui_inl_def_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_def_idx(3)], &ta);
		mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_def_idx(2)], &b->m_data[mk_sl_cui_inl_def_idx(1)], &ta);
		mk_sl_cui_inl_def_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_def_idx(3)], &ta);
		mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(2)], &ta);
		mk_sl_cui_inl_def_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_def_idx(3)], &ta);
		mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(3)], &ta);
		mk_sl_cui_inl_def_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_def_idx(3)], &ta);
	}
	#else
	{
		mk_sl_cui_inl_def_base_type ta;
		mk_lang_bool_t cf;
		mk_sl_cui_inl_def_base_type tb;
		int j;
		int i;

		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(0)], &c->m_data[mk_sl_cui_inl_def_idx(1)]);
		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(1)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &ta, &c->m_data[mk_sl_cui_inl_def_idx(2)]);
		mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(1)], &ta, &cf);
		if(cf) mk_sl_cui_inl_def_base_inc1(&c->m_data[mk_sl_cui_inl_def_idx(2)]);
		mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(0)], &b->m_data[mk_sl_cui_inl_def_idx(1)], &ta, &tb);
		mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(1)], &ta, &cf);
		mk_sl_cui_inl_def_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_def_idx(2)], &tb, cf, &cf);
		if(cf) mk_sl_cui_inl_def_base_set_one(&c->m_data[mk_sl_cui_inl_def_idx(3)]); else mk_sl_cui_inl_def_base_set_zero(&c->m_data[mk_sl_cui_inl_def_idx(3)]);
		for(j = 2; j != mk_sl_cui_inl_def_count - 2; ++j)
		{
			mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(j)], &b->m_data[mk_sl_cui_inl_def_idx(0)], &ta, &tb);
			mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(j)], &ta, &cf);
			mk_sl_cui_inl_def_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_def_idx(j + 1)], &tb, cf, &cf);
			if(cf) mk_sl_cui_inl_def_base_set_one(&c->m_data[mk_sl_cui_inl_def_idx(j + 2)]); else mk_sl_cui_inl_def_base_set_zero(&c->m_data[mk_sl_cui_inl_def_idx(j + 2)]);
			for(i = 1; i != j + 1; ++i)
			{
				mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(j - i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], &ta, &tb);
				mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(j)], &ta, &cf);
				mk_sl_cui_inl_def_base_add2_wrap_cie_coe(&c->m_data[mk_sl_cui_inl_def_idx(j + 1)], &tb, cf, &cf);
				if(cf) mk_sl_cui_inl_def_base_inc1(&c->m_data[mk_sl_cui_inl_def_idx(j + 2)]);
			}
		}
		for(i = 0; i != j + 1; ++i)
		{
			mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[mk_sl_cui_inl_def_idx(j - i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], &ta, &tb);
			mk_sl_cui_inl_def_base_add2_wrap_cid_coe(&c->m_data[mk_sl_cui_inl_def_idx(j)], &ta, &cf);
			mk_sl_cui_inl_def_base_add2_wrap_cie_cod(&c->m_data[mk_sl_cui_inl_def_idx(j + 1)], &tb, cf);
		}
		++j;
		for(i = 0; i != j + 1; ++i)
		{
			mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[mk_sl_cui_inl_def_idx(j - i)], &b->m_data[mk_sl_cui_inl_def_idx(i)], &ta);
			mk_sl_cui_inl_def_base_add2_wrap_cid_cod(&c->m_data[mk_sl_cui_inl_def_idx(j)], &ta);
		}
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul3_wrap_lo_alias(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	mk_sl_cui_inl_def_t r;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c == a || c == b);

	mk_sl_cui_inl_def_mul3_wrap_lo_restrict(a, b, &r);
	*c = r;
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul3_wrap_lo(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_mul3_wrap_lo(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
	#else
	if(c != a && c != b)
	{
		mk_sl_cui_inl_def_mul3_wrap_lo_restrict(a, b, c);
	}
	else
	{
		mk_sl_cui_inl_def_mul3_wrap_lo_alias(a, b, c);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul3_wrap_hi_restrict(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	#define shift ((int)(((int)(((int)(mk_sl_cui_inl_def_count)) * ((int)(mk_sl_cui_inl_def_base_bits)))) / ((int)(2))))

	mk_sl_cui_inl_def_t mask;
	mk_sl_cui_inl_def_t alo;
	mk_sl_cui_inl_def_t ahi;
	mk_sl_cui_inl_def_t blo;
	mk_sl_cui_inl_def_t abmi;
	mk_sl_cui_inl_def_t bami;
	mk_sl_cui_inl_def_t abhi;
	mk_sl_cui_inl_def_t ta;

	mk_lang_assert(((int)(((int)(((int)(mk_sl_cui_inl_def_count)) * ((int)(mk_sl_cui_inl_def_base_bits)))) % ((int)(2)))) == ((int)(0)));
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	mk_sl_cui_inl_def_set_mask(&mask, shift);
	mk_sl_cui_inl_def_and3(a, &mask, &alo);
	mk_sl_cui_inl_def_shr3(a, shift, &ahi);
	mk_sl_cui_inl_def_and3(b, &mask, &blo);
	mk_sl_cui_inl_def_shr3(b, shift, &ta);
	mk_sl_cui_inl_def_mul3_wrap_lo(&alo, &ta, &abmi);
	mk_sl_cui_inl_def_mul3_wrap_lo(&ahi, &ta, &abhi);
	mk_sl_cui_inl_def_mul3_wrap_lo(&ahi, &blo, &bami);
	mk_sl_cui_inl_def_mul3_wrap_lo(&alo, &blo, &ta);
	mk_sl_cui_inl_def_shr3(&ta, shift, c);
	mk_sl_cui_inl_def_and3(&abmi, &mask, &ta);
	mk_sl_cui_inl_def_add2_wrap_cid_cod(c, &ta);
	mk_sl_cui_inl_def_and3(&bami, &mask, &ta);
	mk_sl_cui_inl_def_add2_wrap_cid_cod(c, &ta);
	mk_sl_cui_inl_def_shr2(c, shift);
	mk_sl_cui_inl_def_add2_wrap_cid_cod(c, &abhi);
	mk_sl_cui_inl_def_shr3(&abmi, shift, &ta);
	mk_sl_cui_inl_def_add2_wrap_cid_cod(c, &ta);
	mk_sl_cui_inl_def_shr3(&bami, shift, &ta);
	mk_sl_cui_inl_def_add2_wrap_cid_cod(c, &ta);

	#undef shift
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul3_wrap_hi_alias(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	mk_sl_cui_inl_def_t r;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(c == a || c == b);

	mk_sl_cui_inl_def_mul3_wrap_hi_restrict(a, b, &r);
	*c = r;
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul3_wrap_hi(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_mul3_wrap_hi(&a->m_data[0], &b->m_data[0], &c->m_data[0]);
	#else
	if(c != a && c != b)
	{
		mk_sl_cui_inl_def_mul3_wrap_hi_restrict(a, b, c);
	}
	else
	{
		mk_sl_cui_inl_def_mul3_wrap_hi_alias(a, b, c);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul4_wrap_wi_restrict(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c, mk_sl_cui_inl_def_t* d)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c != a && c != b && c != d && d != a && d != b);

	mk_sl_cui_inl_def_mul3_wrap_lo_restrict(a, b, c);
	mk_sl_cui_inl_def_mul3_wrap_hi_restrict(a, b, d);
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul4_wrap_wi_alias(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c, mk_sl_cui_inl_def_t* d)
{
	mk_sl_cui_inl_def_t r;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);
	mk_lang_assert(c == a || c == b || c == d || d == a || d == b);

	mk_sl_cui_inl_def_mul3_wrap_lo_restrict(a, b, &r);
	mk_sl_cui_inl_def_mul3_wrap_hi(a, b, d);
	*c = r;
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul4_wrap_wi(mk_sl_cui_inl_def_t const* a, mk_sl_cui_inl_def_t const* b, mk_sl_cui_inl_def_t* c, mk_sl_cui_inl_def_t* d)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	#if mk_sl_cui_inl_def_count == 1
	mk_sl_cui_inl_def_base_mul4_wrap_wi(&a->m_data[0], &b->m_data[0], &c->m_data[0], &d->m_data[0]);
	#else
	if(c != a && c != b && c != d && d != a && d != b)
	{
		mk_sl_cui_inl_def_mul4_wrap_wi_restrict(a, b, c, d);
	}
	else
	{
		mk_sl_cui_inl_def_mul4_wrap_wi_alias(a, b, c, d);
	}
	#endif
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul2_wrap_lo(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b)
{
	mk_sl_cui_inl_def_mul3_wrap_lo(a, b, a);
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul2_wrap_hi(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t const* b)
{
	mk_sl_cui_inl_def_mul3_wrap_hi(a, b, a);
}

mk_lang_jumbo void mk_sl_cui_inl_def_mul2_wrap_wi(mk_sl_cui_inl_def_t* a, mk_sl_cui_inl_def_t* b)
{
	mk_sl_cui_inl_def_mul4_wrap_wi(a, b, a, b);
}


#include "mk_sl_cui_inl_undef.h"


#undef mk_sl_cui_inl_def_name
#undef mk_sl_cui_inl_def_base_type
#undef mk_sl_cui_inl_def_base_name
#undef mk_sl_cui_inl_def_base_bits
#undef mk_sl_cui_inl_def_count
#undef mk_sl_cui_inl_def_endian
