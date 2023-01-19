#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_static_assert.h"


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

	return *x == ((mk_lang_bui_t)(~((mk_lang_bui_t)(0))));
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


mk_lang_jumbo void mk_lang_bui_shl3(mk_lang_bui_t const* a, int b, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((int)(sizeof(mk_lang_bui_t) * mk_lang_charbit)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) << b));
}

mk_lang_jumbo void mk_lang_bui_shr3(mk_lang_bui_t const* a, int b, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((int)(sizeof(mk_lang_bui_t) * mk_lang_charbit)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) >> b));
}

mk_lang_jumbo void mk_lang_bui_rotl3(mk_lang_bui_t const* a, int b, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < ((int)(sizeof(mk_lang_bui_t) * mk_lang_charbit)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) << b)) | ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) >> ((int)(((int)(sizeof(mk_lang_bui_t) * mk_lang_charbit)) - b))))));
}

mk_lang_jumbo void mk_lang_bui_rotr3(mk_lang_bui_t const* a, int b, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < ((int)(sizeof(mk_lang_bui_t) * mk_lang_charbit)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) >> b)) | ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) << ((int)(((int)(sizeof(mk_lang_bui_t) * mk_lang_charbit)) - b))))));
}

mk_lang_jumbo void mk_lang_bui_shl2(mk_lang_bui_t* a, int b)
{
	mk_lang_bui_shl3(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_shr2(mk_lang_bui_t* a, int b)
{
	mk_lang_bui_shr3(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_rotl2(mk_lang_bui_t* a, int b)
{
	mk_lang_bui_rotl3(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_rotr2(mk_lang_bui_t* a, int b)
{
	mk_lang_bui_rotr3(a, b, a);
}


mk_lang_jumbo void mk_lang_bui_add3_wrap_cid_cod(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) + ((mk_lang_bui_t)(*b))));
}

mk_lang_jumbo void mk_lang_bui_add3_wrap_cid_coe(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c, mk_lang_bool_t* co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ((mk_lang_bui_t)(((mk_lang_bui_t)(~((mk_lang_bui_t)(0)))) - ((mk_lang_bui_t)(*a)))) < ((mk_lang_bui_t)(*b));
	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) + ((mk_lang_bui_t)(*b))));
}

mk_lang_jumbo void mk_lang_bui_add3_wrap_cie_cod(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) + ((mk_lang_bui_t)(*b)))) + ((mk_lang_bui_t)(ci ? ((mk_lang_bui_t)(1)) : ((mk_lang_bui_t)(0))))));
}

mk_lang_jumbo void mk_lang_bui_add3_wrap_cie_coe(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bui_t* c, mk_lang_bool_t* co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(~((mk_lang_bui_t)(0)))) - ((mk_lang_bui_t)(ci ? ((mk_lang_bui_t)(1)) : ((mk_lang_bui_t)(0)))))) - ((mk_lang_bui_t)(*a)))) < ((mk_lang_bui_t)(*b));
	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) + ((mk_lang_bui_t)(*b)))) + ((mk_lang_bui_t)(ci ? ((mk_lang_bui_t)(1)) : ((mk_lang_bui_t)(0))))));
}

mk_lang_jumbo void mk_lang_bui_add2_wrap_cid_cod(mk_lang_bui_t* a, mk_lang_bui_t const* b)
{
	mk_lang_bui_add3_wrap_cid_cod(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_add2_wrap_cid_coe(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t* co)
{
	mk_lang_bui_add3_wrap_cid_coe(a, b, a, co);
}

mk_lang_jumbo void mk_lang_bui_add2_wrap_cie_cod(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t ci)
{
	mk_lang_bui_add3_wrap_cie_cod(a, b, ci, a);
}

mk_lang_jumbo void mk_lang_bui_add2_wrap_cie_coe(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_lang_bui_add3_wrap_cie_coe(a, b, ci, a, co);
}


mk_lang_jumbo void mk_lang_bui_sub3_wrap_cid_cod(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) - ((mk_lang_bui_t)(*b))));
}

mk_lang_jumbo void mk_lang_bui_sub3_wrap_cid_coe(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c, mk_lang_bool_t* co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ((mk_lang_bui_t)(*a)) < ((mk_lang_bui_t)(*b));
	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) - ((mk_lang_bui_t)(*b))));
}

mk_lang_jumbo void mk_lang_bui_sub3_wrap_cie_cod(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) - ((mk_lang_bui_t)(*b)))) - ((mk_lang_bui_t)(ci ? ((mk_lang_bui_t)(1)) : ((mk_lang_bui_t)(0))))));
}

mk_lang_jumbo void mk_lang_bui_sub3_wrap_cie_coe(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bui_t* c, mk_lang_bool_t* co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ci ? (((mk_lang_bui_t)(*a)) <= ((mk_lang_bui_t)(*b))) : (((mk_lang_bui_t)(*a)) < ((mk_lang_bui_t)(*b)));
	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) - ((mk_lang_bui_t)(*b)))) - ((mk_lang_bui_t)(ci ? ((mk_lang_bui_t)(1)) : ((mk_lang_bui_t)(0))))));
}

mk_lang_jumbo void mk_lang_bui_sub2_wrap_cid_cod(mk_lang_bui_t* a, mk_lang_bui_t const* b)
{
	mk_lang_bui_sub3_wrap_cid_cod(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_sub2_wrap_cid_coe(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t* co)
{
	mk_lang_bui_sub3_wrap_cid_coe(a, b, a, co);
}

mk_lang_jumbo void mk_lang_bui_sub2_wrap_cie_cod(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t ci)
{
	mk_lang_bui_sub3_wrap_cie_cod(a, b, ci, a);
}

mk_lang_jumbo void mk_lang_bui_sub2_wrap_cie_coe(mk_lang_bui_t* a, mk_lang_bui_t const* b, mk_lang_bool_t ci, mk_lang_bool_t* co)
{
	mk_lang_bui_sub3_wrap_cie_coe(a, b, ci, a, co);
}


mk_lang_jumbo void mk_lang_bui_mul3_wrap_lo(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) * ((mk_lang_bui_t)(*b))));
}

mk_lang_jumbo void mk_lang_bui_mul3_wrap_hi(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c)
{
	#define shift ((int)(((int)(((int)(sizeof(mk_lang_bui_t))) * ((int)(mk_lang_charbit)))) / ((int)(2))))
	#define mask ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(1)) << shift)) - ((mk_lang_bui_t)(1))))

	mk_lang_bui_t alo;
	mk_lang_bui_t ahi;
	mk_lang_bui_t blo;
	mk_lang_bui_t bhi;
	mk_lang_bui_t ablo;
	mk_lang_bui_t abmi;
	mk_lang_bui_t bami;
	mk_lang_bui_t abhi;

	mk_lang_static_assert(((int)(((((int)(((int)(sizeof(mk_lang_bui_t))) * ((int)(mk_lang_charbit))))) % ((int)(2))))) == ((int)(0)));
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	alo = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) & mask));
	ahi = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) >> shift));
	blo = ((mk_lang_bui_t)(((mk_lang_bui_t)(*b)) & mask));
	bhi = ((mk_lang_bui_t)(((mk_lang_bui_t)(*b)) >> shift));
	ablo = ((mk_lang_bui_t)(alo * blo));
	abmi = ((mk_lang_bui_t)(alo * bhi));
	bami = ((mk_lang_bui_t)(ahi * blo));
	abhi = ((mk_lang_bui_t)(ahi * bhi));
	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(abhi + ((mk_lang_bui_t)(((mk_lang_bui_t)(abmi >> shift)) + ((mk_lang_bui_t)(bami >> shift)))))) + ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(abmi & mask)) + ((mk_lang_bui_t)(bami & mask)))) + ((mk_lang_bui_t)(ablo >> shift)))) >> shift))));

	#undef shift
	#undef mask
}

mk_lang_jumbo void mk_lang_bui_mul4_wrap_wi(mk_lang_bui_t const* a, mk_lang_bui_t const* b, mk_lang_bui_t* c, mk_lang_bui_t* d)
{
	#define shift ((int)(((int)(((int)(sizeof(mk_lang_bui_t))) * ((int)(mk_lang_charbit)))) / ((int)(2))))
	#define mask ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(1)) << shift)) - ((mk_lang_bui_t)(1))))

	mk_lang_bui_t alo;
	mk_lang_bui_t ahi;
	mk_lang_bui_t blo;
	mk_lang_bui_t bhi;
	mk_lang_bui_t ablo;
	mk_lang_bui_t abmi;
	mk_lang_bui_t bami;
	mk_lang_bui_t abhi;

	mk_lang_static_assert(((int)(((((int)(((int)(sizeof(mk_lang_bui_t))) * ((int)(mk_lang_charbit))))) % ((int)(2))))) == ((int)(0)));
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	alo = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) & mask));
	ahi = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) >> shift));
	blo = ((mk_lang_bui_t)(((mk_lang_bui_t)(*b)) & mask));
	bhi = ((mk_lang_bui_t)(((mk_lang_bui_t)(*b)) >> shift));
	ablo = ((mk_lang_bui_t)(alo * blo));
	abmi = ((mk_lang_bui_t)(alo * bhi));
	bami = ((mk_lang_bui_t)(ahi * blo));
	abhi = ((mk_lang_bui_t)(ahi * bhi));
	*c = ((mk_lang_bui_t)(((mk_lang_bui_t)(*a)) * ((mk_lang_bui_t)(*b))));
	*d = ((mk_lang_bui_t)(((mk_lang_bui_t)(abhi + ((mk_lang_bui_t)(((mk_lang_bui_t)(abmi >> shift)) + ((mk_lang_bui_t)(bami >> shift)))))) + ((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(((mk_lang_bui_t)(abmi & mask)) + ((mk_lang_bui_t)(bami & mask)))) + ((mk_lang_bui_t)(ablo >> shift)))) >> shift))));

	#undef shift
	#undef mask
}

mk_lang_jumbo void mk_lang_bui_mul2_wrap_lo(mk_lang_bui_t* a, mk_lang_bui_t const* b)
{
	mk_lang_bui_mul3_wrap_lo(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_mul2_wrap_hi(mk_lang_bui_t* a, mk_lang_bui_t const* b)
{
	mk_lang_bui_mul3_wrap_hi(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_mul2_wrap_wi(mk_lang_bui_t* a, mk_lang_bui_t* b)
{
	mk_lang_bui_mul4_wrap_wi(a, b, a, b);
}


#include "mk_lang_bui_inl_undef.h"


#undef mk_lang_bui_btn
#undef mk_lang_bui_n
