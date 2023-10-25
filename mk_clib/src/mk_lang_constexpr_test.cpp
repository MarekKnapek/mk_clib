#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_noexcept.h"

#if mk_lang_constexpr_has

#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"

#define mk_lang_bui_t_name mk_lang_constexpr_test_cnstxpr_bui
#define mk_lang_bui_t_base uint
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_lang_constexpr_test_cnstxpr_bui_sizebits_d (mk_lang_sizeof_bi_ushort_t * mk_lang_charbit)

#define mk_sl_cui_t_name mk_lang_constexpr_test_cnstxpr_cui
#define mk_sl_cui_t_base mk_lang_constexpr_test_cnstxpr_bui
#define mk_sl_cui_t_count 2
#define mk_sl_cui_t_endian mk_lang_endian_little
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#define mk_lang_constexpr_test_cnstxpr_cui_sizebits_d (2 * mk_lang_constexpr_test_cnstxpr_bui_sizebits_d)

#endif


#if mk_lang_constexpr_has
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo int mk_lang_constexpr_test_(void) mk_lang_noexcept
{
	{
		mk_lang_constexpr_test_cnstxpr_bui_t a mk_lang_constexpr_init;
		mk_lang_constexpr_test_cnstxpr_bui_t b mk_lang_constexpr_init;
		mk_lang_bi_uchar_t c[mk_lang_sizeof_bi_uint_t] mk_lang_constexpr_init;
		mk_lang_bi_ulllong_t d mk_lang_constexpr_init;
		mk_lang_constexpr_test_cnstxpr_bui_t e mk_lang_constexpr_init;
		mk_lang_bool_t cf mk_lang_constexpr_init;
		mk_lang_constexpr_test_cnstxpr_bui_t f mk_lang_constexpr_init;
		mk_lang_constexpr_test_cnstxpr_bui_t g mk_lang_constexpr_init;

		mk_lang_constexpr_test_cnstxpr_bui_set_zero(&a);
		mk_lang_constexpr_test_cnstxpr_bui_set_max(&a);
		mk_lang_constexpr_test_cnstxpr_bui_set_one(&a);
		mk_lang_constexpr_test_cnstxpr_bui_set_bit(&a, 2);
		mk_lang_constexpr_test_cnstxpr_bui_set_mask(&a, 2);
		mk_lang_constexpr_test_cnstxpr_bui_to_bi_uint(&a, &b);
		mk_lang_constexpr_test_cnstxpr_bui_from_bi_uint(&a, &b);
		mk_lang_constexpr_test_cnstxpr_bui_to_buis_uchar_le(&a, c);
		mk_lang_constexpr_test_cnstxpr_bui_from_buis_uchar_le(&a, c);
		mk_lang_constexpr_test_cnstxpr_bui_to_buis_uchar_be(&a, c);
		mk_lang_constexpr_test_cnstxpr_bui_from_buis_uchar_be(&a, c);
		mk_lang_constexpr_test_cnstxpr_bui_to_buis_ulllong_le(&a, &d);
		mk_lang_constexpr_test_cnstxpr_bui_from_buis_ulllong_le(&a, &d);
		mk_lang_constexpr_test_cnstxpr_bui_to_buis_ulllong_be(&a, &d);
		mk_lang_constexpr_test_cnstxpr_bui_from_buis_ulllong_be(&a, &d);
		(void)mk_lang_constexpr_test_cnstxpr_bui_is_zero(&a);
		(void)mk_lang_constexpr_test_cnstxpr_bui_is_max(&a);
		(void)mk_lang_constexpr_test_cnstxpr_bui_eq(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_bui_ne(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_bui_lt(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_bui_le(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_bui_gt(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_bui_ge(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_inc2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_dec2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_inc1(&a);
		mk_lang_constexpr_test_cnstxpr_bui_dec1(&a);
		mk_lang_constexpr_test_cnstxpr_bui_not2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_or3(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_bui_and3(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_bui_xor3(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_bui_not1(&a);
		mk_lang_constexpr_test_cnstxpr_bui_or2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_and2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_xor2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_shl3(&a, 2, &e);
		mk_lang_constexpr_test_cnstxpr_bui_shr3(&a, 2, &e);
		mk_lang_constexpr_test_cnstxpr_bui_rotl3(&a, 2, &e);
		mk_lang_constexpr_test_cnstxpr_bui_rotr3(&a, 2, &e);
		mk_lang_constexpr_test_cnstxpr_bui_shl2(&a, 2);
		mk_lang_constexpr_test_cnstxpr_bui_shr2(&a, 2);
		mk_lang_constexpr_test_cnstxpr_bui_rotl2(&a, 2);
		mk_lang_constexpr_test_cnstxpr_bui_rotr2(&a, 2);
		(void)mk_lang_constexpr_test_cnstxpr_bui_would_overflow_add_cc(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_bui_would_overflow_add_cs(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_bui_would_overflow_add(&a, &e, cf);
		(void)mk_lang_constexpr_test_cnstxpr_bui_would_overflow_sub_cc(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_bui_would_overflow_sub_cs(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_bui_would_overflow_sub(&a, &e, cf);
		(void)mk_lang_constexpr_test_cnstxpr_bui_would_overflow_mul(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_add3_wrap_cid_cod(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_bui_add3_wrap_cid_coe(&a, &e, &f, &cf);
		mk_lang_constexpr_test_cnstxpr_bui_add3_wrap_cie_cod(&a, &e, cf, &f);
		mk_lang_constexpr_test_cnstxpr_bui_add3_wrap_cie_coe(&a, &e, cf, &f, &cf);
		mk_lang_constexpr_test_cnstxpr_bui_add2_wrap_cid_cod(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_add2_wrap_cid_coe(&a, &e, &cf);
		mk_lang_constexpr_test_cnstxpr_bui_add2_wrap_cie_cod(&a, &e, cf);
		mk_lang_constexpr_test_cnstxpr_bui_add2_wrap_cie_coe(&a, &e, cf, &cf);
		mk_lang_constexpr_test_cnstxpr_bui_sub3_wrap_cid_cod(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_bui_sub3_wrap_cid_coe(&a, &e, &f, &cf);
		mk_lang_constexpr_test_cnstxpr_bui_sub3_wrap_cie_cod(&a, &e, cf, &f);
		mk_lang_constexpr_test_cnstxpr_bui_sub3_wrap_cie_coe(&a, &e, cf, &f, &cf);
		mk_lang_constexpr_test_cnstxpr_bui_sub2_wrap_cid_cod(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_sub2_wrap_cid_coe(&a, &e, &cf);
		mk_lang_constexpr_test_cnstxpr_bui_sub2_wrap_cie_cod(&a, &e, cf);
		mk_lang_constexpr_test_cnstxpr_bui_sub2_wrap_cie_coe(&a, &e, cf, &cf);
		mk_lang_constexpr_test_cnstxpr_bui_mul3_wrap_lo(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_bui_mul3_wrap_hi(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_bui_mul4_wrap_wi(&a, &e, &f, &g);
		mk_lang_constexpr_test_cnstxpr_bui_mul2_wrap_lo(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_mul2_wrap_hi(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_mul2_wrap_wi(&a, &e);
		++e; ++e;
		mk_lang_constexpr_test_cnstxpr_bui_div3_wrap(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_bui_mod3_wrap(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_bui_divmod4_wrap(&a, &e, &f, &g);
		mk_lang_constexpr_test_cnstxpr_bui_div2_wrap(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_mod2_wrap(&a, &e);
		mk_lang_constexpr_test_cnstxpr_bui_divmod2_wrap(&a, &e);
	}
	{
		mk_lang_constexpr_test_cnstxpr_cui_t a mk_lang_constexpr_init;
		mk_lang_constexpr_test_cnstxpr_bui_t b mk_lang_constexpr_init;
		mk_lang_bi_uchar_t c[mk_lang_sizeof_bi_uint_t*99] mk_lang_constexpr_init;
		mk_lang_bi_ulllong_t d[99] mk_lang_constexpr_init;
		mk_lang_constexpr_test_cnstxpr_cui_t e mk_lang_constexpr_init;
		mk_lang_bool_t cf mk_lang_constexpr_init;
		mk_lang_constexpr_test_cnstxpr_cui_t f mk_lang_constexpr_init;
		mk_lang_constexpr_test_cnstxpr_cui_t g mk_lang_constexpr_init;

		mk_lang_constexpr_test_cnstxpr_cui_set_zero(&a);
		mk_lang_constexpr_test_cnstxpr_cui_set_max(&a);
		mk_lang_constexpr_test_cnstxpr_cui_set_one(&a);
		mk_lang_constexpr_test_cnstxpr_cui_set_bit(&a, 2);
		mk_lang_constexpr_test_cnstxpr_cui_set_mask(&a, 2);
		mk_lang_constexpr_test_cnstxpr_cui_to_bi_uint(&a, &b);
		mk_lang_constexpr_test_cnstxpr_cui_from_bi_uint(&a, &b);
		mk_lang_constexpr_test_cnstxpr_cui_to_buis_uchar_le(&a, c);
		mk_lang_constexpr_test_cnstxpr_cui_from_buis_uchar_le(&a, c);
		mk_lang_constexpr_test_cnstxpr_cui_to_buis_uchar_be(&a, c);
		mk_lang_constexpr_test_cnstxpr_cui_from_buis_uchar_be(&a, c);
		mk_lang_constexpr_test_cnstxpr_cui_to_buis_ulllong_le(&a, d);
		mk_lang_constexpr_test_cnstxpr_cui_from_buis_ulllong_le(&a, d);
		mk_lang_constexpr_test_cnstxpr_cui_to_buis_ulllong_be(&a, d);
		mk_lang_constexpr_test_cnstxpr_cui_from_buis_ulllong_be(&a, d);
		(void)mk_lang_constexpr_test_cnstxpr_cui_is_zero(&a);
		(void)mk_lang_constexpr_test_cnstxpr_cui_is_max(&a);
		(void)mk_lang_constexpr_test_cnstxpr_cui_eq(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_cui_ne(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_cui_lt(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_cui_le(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_cui_gt(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_cui_ge(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_inc2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_dec2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_inc1(&a);
		mk_lang_constexpr_test_cnstxpr_cui_dec1(&a);
		mk_lang_constexpr_test_cnstxpr_cui_not2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_or3(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_cui_and3(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_cui_xor3(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_cui_not1(&a);
		mk_lang_constexpr_test_cnstxpr_cui_or2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_and2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_xor2(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_shl3(&a, 2, &e);
		mk_lang_constexpr_test_cnstxpr_cui_shr3(&a, 2, &e);
		mk_lang_constexpr_test_cnstxpr_cui_rotl3(&a, 2, &e);
		mk_lang_constexpr_test_cnstxpr_cui_rotr3(&a, 2, &e);
		mk_lang_constexpr_test_cnstxpr_cui_shl2(&a, 2);
		mk_lang_constexpr_test_cnstxpr_cui_shr2(&a, 2);
		mk_lang_constexpr_test_cnstxpr_cui_rotl2(&a, 2);
		mk_lang_constexpr_test_cnstxpr_cui_rotr2(&a, 2);
		(void)mk_lang_constexpr_test_cnstxpr_cui_would_overflow_add_cc(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_cui_would_overflow_add_cs(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_cui_would_overflow_add(&a, &e, cf);
		(void)mk_lang_constexpr_test_cnstxpr_cui_would_overflow_sub_cc(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_cui_would_overflow_sub_cs(&a, &e);
		(void)mk_lang_constexpr_test_cnstxpr_cui_would_overflow_sub(&a, &e, cf);
		(void)mk_lang_constexpr_test_cnstxpr_cui_would_overflow_mul(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_add3_wrap_cid_cod(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_cui_add3_wrap_cid_coe(&a, &e, &f, &cf);
		mk_lang_constexpr_test_cnstxpr_cui_add3_wrap_cie_cod(&a, &e, cf, &f);
		mk_lang_constexpr_test_cnstxpr_cui_add3_wrap_cie_coe(&a, &e, cf, &f, &cf);
		mk_lang_constexpr_test_cnstxpr_cui_add2_wrap_cid_cod(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_add2_wrap_cid_coe(&a, &e, &cf);
		mk_lang_constexpr_test_cnstxpr_cui_add2_wrap_cie_cod(&a, &e, cf);
		mk_lang_constexpr_test_cnstxpr_cui_add2_wrap_cie_coe(&a, &e, cf, &cf);
		mk_lang_constexpr_test_cnstxpr_cui_sub3_wrap_cid_cod(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_cui_sub3_wrap_cid_coe(&a, &e, &f, &cf);
		mk_lang_constexpr_test_cnstxpr_cui_sub3_wrap_cie_cod(&a, &e, cf, &f);
		mk_lang_constexpr_test_cnstxpr_cui_sub3_wrap_cie_coe(&a, &e, cf, &f, &cf);
		mk_lang_constexpr_test_cnstxpr_cui_sub2_wrap_cid_cod(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_sub2_wrap_cid_coe(&a, &e, &cf);
		mk_lang_constexpr_test_cnstxpr_cui_sub2_wrap_cie_cod(&a, &e, cf);
		mk_lang_constexpr_test_cnstxpr_cui_sub2_wrap_cie_coe(&a, &e, cf, &cf);
		mk_lang_constexpr_test_cnstxpr_cui_mul3_wrap_lo(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_cui_mul3_wrap_hi(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_cui_mul4_wrap_wi(&a, &e, &f, &g);
		mk_lang_constexpr_test_cnstxpr_cui_mul2_wrap_lo(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_mul2_wrap_hi(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_mul2_wrap_wi(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_inc1(&e); mk_lang_constexpr_test_cnstxpr_cui_inc1(&e);
		mk_lang_constexpr_test_cnstxpr_cui_div3_wrap(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_cui_mod3_wrap(&a, &e, &f);
		mk_lang_constexpr_test_cnstxpr_cui_divmod4_wrap(&a, &e, &f, &g);
		mk_lang_constexpr_test_cnstxpr_cui_div2_wrap(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_mod2_wrap(&a, &e);
		mk_lang_constexpr_test_cnstxpr_cui_divmod2_wrap(&a, &e);
	}
	{
		int ret mk_lang_constexpr_init;

		return ret;
	}
}
#endif


mk_lang_extern_c void mk_lang_constexpr_test(void) mk_lang_noexcept
{
#if mk_lang_constexpr_has
	static mk_lang_constexpr auto const s_x = mk_lang_constexpr_test_();

	mk_lang_static_assert(s_x == 0);
#endif
}
