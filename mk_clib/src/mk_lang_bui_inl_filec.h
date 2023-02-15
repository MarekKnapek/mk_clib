#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_static_assert.h"


#include "mk_lang_bui_inl_defd.h"


mk_lang_jumbo void mk_lang_bui_inl_defd_set_zero(mk_lang_bui_inl_defd_type* const x)
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_inl_defd_type)(0));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_set_max(mk_lang_bui_inl_defd_type* const x)
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_inl_defd_type)(~((mk_lang_bui_inl_defd_type)(0))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_set_one(mk_lang_bui_inl_defd_type* x)
{
	mk_lang_assert(x);

	*x = ((mk_lang_bui_inl_defd_type)(1));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_set_bit(mk_lang_bui_inl_defd_type* const x, int const bit_idx)
{
	mk_lang_assert(x);
	mk_lang_assert(bit_idx >= 0 && bit_idx < ((int)(sizeof(mk_lang_bui_inl_defd_type) * mk_lang_charbit)));

	*x = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(1)) << bit_idx));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_set_mask(mk_lang_bui_inl_defd_type* const x, int const bits_count)
{
	#if defined NDEBUG
	#else
	mk_lang_bui_inl_defd_type tmp;
	#endif

	mk_lang_assert(x);
	mk_lang_assert(bits_count >= 1 && bits_count <= ((int)(((int)(sizeof(mk_lang_bui_inl_defd_type))) * ((int)(mk_lang_charbit)))));

	#if defined NDEBUG
	*x = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(1)) << ((int)(bits_count - 1)))) - ((mk_lang_bui_inl_defd_type)(1)))) << ((int)(1)))) + ((mk_lang_bui_inl_defd_type)(1))));
	#else
	tmp = ((mk_lang_bui_inl_defd_type)(1));
	tmp = ((mk_lang_bui_inl_defd_type)(tmp << ((int)(bits_count - 1))));
	tmp = ((mk_lang_bui_inl_defd_type)(tmp - ((mk_lang_bui_inl_defd_type)(1))));
	tmp = ((mk_lang_bui_inl_defd_type)(tmp << ((int)(1))));
	tmp = ((mk_lang_bui_inl_defd_type)(tmp + ((mk_lang_bui_inl_defd_type)(1))));
	*x = tmp;
	#endif
}

#define mk_lang_forb1_id mk_lang_for_constants_bi
#define mk_lang_forb_file "mk_lang_bui_inl_tofrom_bi_filec.h"
#include "mk_lang_forb1.h"
#undef mk_lang_forb1_id
#undef mk_lang_forb_file

#define mk_lang_forb2_id mk_lang_for_constants_bui
#define mk_lang_forb1_id mk_lang_for_constants_endian
#define mk_lang_forb_file "mk_lang_bui_inl_tofrom_buis_filec.h"
#include "mk_lang_forb2.h"
#undef mk_lang_forb2_id
#undef mk_lang_forb1_id
#undef mk_lang_forb_file

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_is_zero(mk_lang_bui_inl_defd_type const* const x)
{
	mk_lang_assert(x);

	return *x == ((mk_lang_bui_inl_defd_type)(0));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_is_max(mk_lang_bui_inl_defd_type const* const x)
{
	mk_lang_assert(x);

	return *x == ((mk_lang_bui_inl_defd_type)(~((mk_lang_bui_inl_defd_type)(0))));
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_eq(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a == *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_ne(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a != *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_lt(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a < *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_le(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a <= *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_gt(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a > *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_bool_t mk_lang_bui_inl_defd_ge(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a >= *b;
}


mk_lang_jumbo void mk_lang_bui_inl_defd_inc2(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type* const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) + ((mk_lang_bui_inl_defd_type)(1))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_dec2(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type* const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) - ((mk_lang_bui_inl_defd_type)(1))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_inc1(mk_lang_bui_inl_defd_type* const x)
{
	mk_lang_assert(x);

	++*x;
}

mk_lang_jumbo void mk_lang_bui_inl_defd_dec1(mk_lang_bui_inl_defd_type* const x)
{
	mk_lang_assert(x);

	--*x;
}


mk_lang_jumbo void mk_lang_bui_inl_defd_not2(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type* const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	*b = ((mk_lang_bui_inl_defd_type)(~((mk_lang_bui_inl_defd_type)(*a))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_or3(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) | ((mk_lang_bui_inl_defd_type)(*b))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_and3(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) & ((mk_lang_bui_inl_defd_type)(*b))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_xor3(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) ^ ((mk_lang_bui_inl_defd_type)(*b))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_not1(mk_lang_bui_inl_defd_type* const x)
{
	mk_lang_bui_inl_defd_not2(x, x);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_or2(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_bui_inl_defd_or3(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_and2(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_bui_inl_defd_and3(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_xor2(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_bui_inl_defd_xor3(a, b, a);
}


mk_lang_jumbo void mk_lang_bui_inl_defd_shl3(mk_lang_bui_inl_defd_type const* const a, int const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((int)(sizeof(mk_lang_bui_inl_defd_type) * mk_lang_charbit)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) << b));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_shr3(mk_lang_bui_inl_defd_type const* const a, int const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 0 && b < ((int)(sizeof(mk_lang_bui_inl_defd_type) * mk_lang_charbit)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) >> b));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_rotl3(mk_lang_bui_inl_defd_type const* const a, int const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < ((int)(sizeof(mk_lang_bui_inl_defd_type) * mk_lang_charbit)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) << b)) | ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) >> ((int)(((int)(sizeof(mk_lang_bui_inl_defd_type) * mk_lang_charbit)) - b))))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_rotr3(mk_lang_bui_inl_defd_type const* const a, int const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b >= 1 && b < ((int)(sizeof(mk_lang_bui_inl_defd_type) * mk_lang_charbit)));
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) >> b)) | ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) << ((int)(((int)(sizeof(mk_lang_bui_inl_defd_type) * mk_lang_charbit)) - b))))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_shl2(mk_lang_bui_inl_defd_type* const a, int const b)
{
	mk_lang_bui_inl_defd_shl3(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_shr2(mk_lang_bui_inl_defd_type* const a, int const b)
{
	mk_lang_bui_inl_defd_shr3(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_rotl2(mk_lang_bui_inl_defd_type* const a, int const b)
{
	mk_lang_bui_inl_defd_rotl3(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_rotr2(mk_lang_bui_inl_defd_type* const a, int const b)
{
	mk_lang_bui_inl_defd_rotr3(a, b, a);
}


mk_lang_jumbo void mk_lang_bui_inl_defd_add3_wrap_cid_cod(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) + ((mk_lang_bui_inl_defd_type)(*b))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_add3_wrap_cid_coe(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c, mk_lang_bool_t* const co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(~((mk_lang_bui_inl_defd_type)(0)))) - ((mk_lang_bui_inl_defd_type)(*a)))) < ((mk_lang_bui_inl_defd_type)(*b));
	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) + ((mk_lang_bui_inl_defd_type)(*b))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_add3_wrap_cie_cod(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bool_t const ci, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) + ((mk_lang_bui_inl_defd_type)(*b)))) + ((mk_lang_bui_inl_defd_type)(ci ? ((mk_lang_bui_inl_defd_type)(1)) : ((mk_lang_bui_inl_defd_type)(0))))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_add3_wrap_cie_coe(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bool_t const ci, mk_lang_bui_inl_defd_type* const c, mk_lang_bool_t* const co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co =
		ci ?
		(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(~((mk_lang_bui_inl_defd_type)(0)))) - ((mk_lang_bui_inl_defd_type)(*a)))) <= ((mk_lang_bui_inl_defd_type)(*b))) :
		(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(~((mk_lang_bui_inl_defd_type)(0)))) - ((mk_lang_bui_inl_defd_type)(*a)))) < ((mk_lang_bui_inl_defd_type)(*b)));
	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) + ((mk_lang_bui_inl_defd_type)(*b)))) + ((mk_lang_bui_inl_defd_type)(ci ? ((mk_lang_bui_inl_defd_type)(1)) : ((mk_lang_bui_inl_defd_type)(0))))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_add2_wrap_cid_cod(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_bui_inl_defd_add3_wrap_cid_cod(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_add2_wrap_cid_coe(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bool_t* const co)
{
	mk_lang_bui_inl_defd_add3_wrap_cid_coe(a, b, a, co);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_add2_wrap_cie_cod(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bool_t const ci)
{
	mk_lang_bui_inl_defd_add3_wrap_cie_cod(a, b, ci, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_add2_wrap_cie_coe(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bool_t const ci, mk_lang_bool_t* const co)
{
	mk_lang_bui_inl_defd_add3_wrap_cie_coe(a, b, ci, a, co);
}


mk_lang_jumbo void mk_lang_bui_inl_defd_sub3_wrap_cid_cod(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) - ((mk_lang_bui_inl_defd_type)(*b))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_sub3_wrap_cid_coe(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c, mk_lang_bool_t* const co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ((mk_lang_bui_inl_defd_type)(*a)) < ((mk_lang_bui_inl_defd_type)(*b));
	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) - ((mk_lang_bui_inl_defd_type)(*b))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_sub3_wrap_cie_cod(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bool_t const ci, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) - ((mk_lang_bui_inl_defd_type)(*b)))) - ((mk_lang_bui_inl_defd_type)(ci ? ((mk_lang_bui_inl_defd_type)(1)) : ((mk_lang_bui_inl_defd_type)(0))))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_sub3_wrap_cie_coe(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bool_t const ci, mk_lang_bui_inl_defd_type* const c, mk_lang_bool_t* const co)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(co);

	*co = ci ? (((mk_lang_bui_inl_defd_type)(*a)) <= ((mk_lang_bui_inl_defd_type)(*b))) : (((mk_lang_bui_inl_defd_type)(*a)) < ((mk_lang_bui_inl_defd_type)(*b)));
	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) - ((mk_lang_bui_inl_defd_type)(*b)))) - ((mk_lang_bui_inl_defd_type)(ci ? ((mk_lang_bui_inl_defd_type)(1)) : ((mk_lang_bui_inl_defd_type)(0))))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_sub2_wrap_cid_cod(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_bui_inl_defd_sub3_wrap_cid_cod(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_sub2_wrap_cid_coe(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bool_t* const co)
{
	mk_lang_bui_inl_defd_sub3_wrap_cid_coe(a, b, a, co);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_sub2_wrap_cie_cod(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bool_t const ci)
{
	mk_lang_bui_inl_defd_sub3_wrap_cie_cod(a, b, ci, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_sub2_wrap_cie_coe(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bool_t const ci, mk_lang_bool_t* const co)
{
	mk_lang_bui_inl_defd_sub3_wrap_cie_coe(a, b, ci, a, co);
}


mk_lang_jumbo void mk_lang_bui_inl_defd_mul3_wrap_lo(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) * ((mk_lang_bui_inl_defd_type)(*b))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_mul3_wrap_hi(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c)
{
	#define shift ((int)(((int)(((int)(sizeof(mk_lang_bui_inl_defd_type))) * ((int)(mk_lang_charbit)))) / ((int)(2))))
	#define mask ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(1)) << shift)) - ((mk_lang_bui_inl_defd_type)(1))))

	mk_lang_bui_inl_defd_type alo;
	mk_lang_bui_inl_defd_type ahi;
	mk_lang_bui_inl_defd_type blo;
	mk_lang_bui_inl_defd_type bhi;
	mk_lang_bui_inl_defd_type ablo;
	mk_lang_bui_inl_defd_type abmi;
	mk_lang_bui_inl_defd_type bami;
	mk_lang_bui_inl_defd_type abhi;

	mk_lang_static_assert(((int)(((((int)(((int)(sizeof(mk_lang_bui_inl_defd_type))) * ((int)(mk_lang_charbit))))) % ((int)(2))))) == ((int)(0)));
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	alo = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) & mask));
	ahi = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) >> shift));
	blo = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*b)) & mask));
	bhi = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*b)) >> shift));
	ablo = ((mk_lang_bui_inl_defd_type)(alo * blo));
	abmi = ((mk_lang_bui_inl_defd_type)(alo * bhi));
	bami = ((mk_lang_bui_inl_defd_type)(ahi * blo));
	abhi = ((mk_lang_bui_inl_defd_type)(ahi * bhi));
	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(abhi + ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(abmi >> shift)) + ((mk_lang_bui_inl_defd_type)(bami >> shift)))))) + ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(abmi & mask)) + ((mk_lang_bui_inl_defd_type)(bami & mask)))) + ((mk_lang_bui_inl_defd_type)(ablo >> shift)))) >> shift))));

	#undef shift
	#undef mask
}

mk_lang_jumbo void mk_lang_bui_inl_defd_mul4_wrap_wi(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c, mk_lang_bui_inl_defd_type* const d)
{
	#define shift ((int)(((int)(((int)(sizeof(mk_lang_bui_inl_defd_type))) * ((int)(mk_lang_charbit)))) / ((int)(2))))
	#define mask ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(1)) << shift)) - ((mk_lang_bui_inl_defd_type)(1))))

	mk_lang_bui_inl_defd_type alo;
	mk_lang_bui_inl_defd_type ahi;
	mk_lang_bui_inl_defd_type blo;
	mk_lang_bui_inl_defd_type bhi;
	mk_lang_bui_inl_defd_type ablo;
	mk_lang_bui_inl_defd_type abmi;
	mk_lang_bui_inl_defd_type bami;
	mk_lang_bui_inl_defd_type abhi;

	mk_lang_static_assert(((int)(((((int)(((int)(sizeof(mk_lang_bui_inl_defd_type))) * ((int)(mk_lang_charbit))))) % ((int)(2))))) == ((int)(0)));
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	alo = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) & mask));
	ahi = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) >> shift));
	blo = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*b)) & mask));
	bhi = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*b)) >> shift));
	ablo = ((mk_lang_bui_inl_defd_type)(alo * blo));
	abmi = ((mk_lang_bui_inl_defd_type)(alo * bhi));
	bami = ((mk_lang_bui_inl_defd_type)(ahi * blo));
	abhi = ((mk_lang_bui_inl_defd_type)(ahi * bhi));
	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) * ((mk_lang_bui_inl_defd_type)(*b))));
	*d = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(abhi + ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(abmi >> shift)) + ((mk_lang_bui_inl_defd_type)(bami >> shift)))))) + ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(abmi & mask)) + ((mk_lang_bui_inl_defd_type)(bami & mask)))) + ((mk_lang_bui_inl_defd_type)(ablo >> shift)))) >> shift))));

	#undef shift
	#undef mask
}

mk_lang_jumbo void mk_lang_bui_inl_defd_mul2_wrap_lo(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_bui_inl_defd_mul3_wrap_lo(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_mul2_wrap_hi(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_bui_inl_defd_mul3_wrap_hi(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_mul2_wrap_wi(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type* const b)
{
	mk_lang_bui_inl_defd_mul4_wrap_wi(a, b, a, b);
}


mk_lang_jumbo void mk_lang_bui_inl_defd_div3_wrap(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) / ((mk_lang_bui_inl_defd_type)(*b))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_mod3_wrap(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c)
{
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);

	*c = ((mk_lang_bui_inl_defd_type)(((mk_lang_bui_inl_defd_type)(*a)) % ((mk_lang_bui_inl_defd_type)(*b))));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_divmod4_wrap(mk_lang_bui_inl_defd_type const* const a, mk_lang_bui_inl_defd_type const* const b, mk_lang_bui_inl_defd_type* const c, mk_lang_bui_inl_defd_type* const d)
{
	mk_lang_bui_inl_defd_type aa;
	mk_lang_bui_inl_defd_type bb;

	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(c);
	mk_lang_assert(d);

	aa = ((mk_lang_bui_inl_defd_type)(*a));
	bb = ((mk_lang_bui_inl_defd_type)(*b));
	*c = ((mk_lang_bui_inl_defd_type)(aa / bb));
	*d = ((mk_lang_bui_inl_defd_type)(aa % bb));
}

mk_lang_jumbo void mk_lang_bui_inl_defd_div2_wrap(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_bui_inl_defd_div3_wrap(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_mod2_wrap(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type const* const b)
{
	mk_lang_bui_inl_defd_mod3_wrap(a, b, a);
}

mk_lang_jumbo void mk_lang_bui_inl_defd_divmod2_wrap(mk_lang_bui_inl_defd_type* const a, mk_lang_bui_inl_defd_type* const b)
{
	mk_lang_bui_inl_defd_divmod4_wrap(a, b, a, b);
}


#include "mk_lang_bui_inl_defu.h"


#undef mk_lang_bui_name
#undef mk_lang_bui_type
