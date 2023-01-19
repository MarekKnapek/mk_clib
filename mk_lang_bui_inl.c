#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"


#include "mk_lang_bui_inl_def.h"


mk_lang_jumbo void mk_lang_bui_set_zero(mk_lang_bui_t* x)
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_t)(0));
}

mk_lang_jumbo void mk_lang_bui_set_one(mk_lang_bui_t* x)
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_t)(1));
}

mk_lang_jumbo void mk_lang_bui_set_bit(mk_lang_bui_t* x, int bit_idx)
{
	mk_lang_assert(x);
	mk_lang_assert(bit_idx >= 0 && bit_idx < ((int)(sizeof(mk_lang_bui_t) * mk_lang_charbit)));

	*x = ((mk_lang_bui_t)(((mk_lang_bui_t)(1)) << bit_idx));
}

mk_lang_jumbo void mk_lang_bui_set_mask(mk_lang_bui_t* x, int bits_count)
{
	#if defined NDEBUG
	#else
	mk_lang_bui_t tmp;
	#endif

	mk_lang_assert(x);
	mk_lang_assert(bits_count >= 1 && bits_count <= ((int)(((int)(sizeof(mk_lang_bui_t))) * ((int)(mk_lang_charbit)))));

	#if defined NDEBUG
	*x = ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(1)) << ((int)(bits_count - 1)))) - ((mk_lang_bui_t)(1)))) << ((int)(1)))) + ((mk_lang_bui_t)(1))));
	#else
	tmp = ((mk_lang_bui_t)(1));
	tmp = ((mk_lang_bui_t)(tmp << ((int)(bits_count - 1))));
	tmp = ((mk_lang_bui_t)(tmp - ((mk_lang_bui_t)(1))));
	tmp = ((mk_lang_bui_t)(tmp << ((int)(1))));
	tmp = ((mk_lang_bui_t)(tmp + ((mk_lang_bui_t)(1))));
	*x = tmp;
	#endif
}

#include "mk_lang_bui_inl_to_bi.c"
#include "mk_lang_bui_inl_from_bi.c"
#include "mk_lang_bui_inl_to_buis_le.c"
#include "mk_lang_bui_inl_to_buis_be.c"
#include "mk_lang_bui_inl_from_buis_le.c"
#include "mk_lang_bui_inl_from_buis_be.c"

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_is_zero(mk_lang_bui_t const* x)
{
	mk_lang_assert(x);

	return *x == ((mk_lang_bui_t)(0));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_is_max(mk_lang_bui_t const* x)
{
	mk_lang_assert(x);

	return *x == ((mk_lang_bui_t)(((mk_lang_bui_t)(0)) - ((mk_lang_bui_t)(1))));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_eq(mk_lang_bui_t const* a, mk_lang_bui_t const* b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a == *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_ne(mk_lang_bui_t const* a, mk_lang_bui_t const* b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a == *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_lt(mk_lang_bui_t const* a, mk_lang_bui_t const* b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a < *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_le(mk_lang_bui_t const* a, mk_lang_bui_t const* b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a <= *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_gt(mk_lang_bui_t const* a, mk_lang_bui_t const* b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a > *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_ge(mk_lang_bui_t const* a, mk_lang_bui_t const* b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a >= *b;
}


mk_lang_jumbo void mk_lang_bui_inc2(mk_lang_bui_t const* a, mk_lang_bui_t* b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) + ((mk_lang_bui_t)(1))));
}

mk_lang_jumbo void mk_lang_bui_dec2(mk_lang_bui_t const* a, mk_lang_bui_t* b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) - ((mk_lang_bui_t)(1))));
}

mk_lang_jumbo void mk_lang_bui_inc1(mk_lang_bui_t* x)
{
	mk_lang_assert(x);

	++*x;
}

mk_lang_jumbo void mk_lang_bui_dec1(mk_lang_bui_t* x)
{
	mk_lang_assert(x);

	--*x;
}


mk_lang_jumbo void mk_lang_bui_not2(mk_lang_bui_t const* a, mk_lang_bui_t* b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_t)(~((mk_lang_bui_t)(*a))));
}

mk_lang_jumbo void mk_lang_bui_or3(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) | ((mk_lang_bui_t)(*b))));
}

mk_lang_jumbo void mk_lang_bui_and3(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) & ((mk_lang_bui_t)(*b))));
}

mk_lang_jumbo void mk_lang_bui_xor3(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) ^ ((mk_lang_bui_t)(*b))));
}

mk_lang_jumbo void mk_lang_bui_not1(mk_lang_bui_t* x)
{
	mk_lang_bui_not2(x, x);
}

mk_lang_jumbo void mk_lang_bui_or2(mk_lang_bui_t* a, mk_lang_bui_t const* b)
{
	mk_lang_bui_or3(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_and2(mk_lang_bui_t* a, mk_lang_bui_t const* b)
{
	mk_lang_bui_and3(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_xor2(mk_lang_bui_t* a, mk_lang_bui_t const* b)
{
	mk_lang_bui_xor3(a, b, a);
}


#include "mk_lang_bui_inl_undef.h"


#undef mk_lang_bui_btn
#undef mk_lang_bui_n
