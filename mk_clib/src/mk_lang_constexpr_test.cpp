#undef mk_lang_jumbo_want
#define mk_lang_jumbo_want 1

#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_noexcept.h"

#if mk_lang_constexpr_has
#include "mk_lang_assert.h"
#include "mk_lang_bi.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#define mk_lang_bui_name cnstxpr
#define mk_lang_bui_type mk_lang_bi_uint_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_uint_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"
#define mk_sl_cui_name cnstxpr
#define mk_sl_cui_base_type mk_lang_bi_uint_t
#define mk_sl_cui_base_name mk_lang_bui_cnstxpr
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#define mk_sl_cui_count 2
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn uint
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#endif


#if mk_lang_constexpr_has
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo int mk_lang_constexpr_test_(void) mk_lang_noexcept
{
	{
		mk_lang_bi_uint_t a mk_lang_constexpr_init;
		mk_lang_bi_uint_t b mk_lang_constexpr_init;
		mk_lang_bi_uchar_t c[mk_lang_sizeof_bi_uint_t] mk_lang_constexpr_init;
		mk_lang_bi_ulllong_t d mk_lang_constexpr_init;
		mk_lang_bi_uint_t e mk_lang_constexpr_init;
		mk_lang_types_bool_t cf mk_lang_constexpr_init;
		mk_lang_bi_uint_t f mk_lang_constexpr_init;
		mk_lang_bi_uint_t g mk_lang_constexpr_init;

		mk_lang_bui_cnstxpr_set_zero(&a);
		mk_lang_bui_cnstxpr_set_max(&a);
		mk_lang_bui_cnstxpr_set_one(&a);
		mk_lang_bui_cnstxpr_set_bit(&a, 2);
		mk_lang_bui_cnstxpr_set_mask(&a, 2);
		mk_lang_bui_cnstxpr_to_bi_uint(&a, &b);
		mk_lang_bui_cnstxpr_from_bi_uint(&a, &b);
		mk_lang_bui_cnstxpr_to_buis_uchar_le(&a, c);
		mk_lang_bui_cnstxpr_from_buis_uchar_le(&a, c);
		mk_lang_bui_cnstxpr_to_buis_uchar_be(&a, c);
		mk_lang_bui_cnstxpr_from_buis_uchar_be(&a, c);
		mk_lang_bui_cnstxpr_to_buis_ulllong_le(&a, &d);
		mk_lang_bui_cnstxpr_from_buis_ulllong_le(&a, &d);
		mk_lang_bui_cnstxpr_to_buis_ulllong_be(&a, &d);
		mk_lang_bui_cnstxpr_from_buis_ulllong_be(&a, &d);
		(void)mk_lang_bui_cnstxpr_is_zero(&a);
		(void)mk_lang_bui_cnstxpr_is_max(&a);
		(void)mk_lang_bui_cnstxpr_eq(&a, &e);
		(void)mk_lang_bui_cnstxpr_ne(&a, &e);
		(void)mk_lang_bui_cnstxpr_lt(&a, &e);
		(void)mk_lang_bui_cnstxpr_le(&a, &e);
		(void)mk_lang_bui_cnstxpr_gt(&a, &e);
		(void)mk_lang_bui_cnstxpr_ge(&a, &e);
		mk_lang_bui_cnstxpr_inc2(&a, &e);
		mk_lang_bui_cnstxpr_dec2(&a, &e);
		mk_lang_bui_cnstxpr_inc1(&a);
		mk_lang_bui_cnstxpr_dec1(&a);
		mk_lang_bui_cnstxpr_not2(&a, &e);
		mk_lang_bui_cnstxpr_or3(&a, &e, &f);
		mk_lang_bui_cnstxpr_and3(&a, &e, &f);
		mk_lang_bui_cnstxpr_xor3(&a, &e, &f);
		mk_lang_bui_cnstxpr_not1(&a);
		mk_lang_bui_cnstxpr_or2(&a, &e);
		mk_lang_bui_cnstxpr_and2(&a, &e);
		mk_lang_bui_cnstxpr_xor2(&a, &e);
		mk_lang_bui_cnstxpr_shl3(&a, 2, &e);
		mk_lang_bui_cnstxpr_shr3(&a, 2, &e);
		mk_lang_bui_cnstxpr_rotl3(&a, 2, &e);
		mk_lang_bui_cnstxpr_rotr3(&a, 2, &e);
		mk_lang_bui_cnstxpr_shl2(&a, 2);
		mk_lang_bui_cnstxpr_shr2(&a, 2);
		mk_lang_bui_cnstxpr_rotl2(&a, 2);
		mk_lang_bui_cnstxpr_rotr2(&a, 2);
		(void)mk_lang_bui_cnstxpr_would_overflow_add_cc(&a, &e);
		(void)mk_lang_bui_cnstxpr_would_overflow_add_cs(&a, &e);
		(void)mk_lang_bui_cnstxpr_would_overflow_add(&a, &e, cf);
		(void)mk_lang_bui_cnstxpr_would_overflow_sub_cc(&a, &e);
		(void)mk_lang_bui_cnstxpr_would_overflow_sub_cs(&a, &e);
		(void)mk_lang_bui_cnstxpr_would_overflow_sub(&a, &e, cf);
		(void)mk_lang_bui_cnstxpr_would_overflow_mul(&a, &e);
		mk_lang_bui_cnstxpr_add3_wrap_cid_cod(&a, &e, &f);
		mk_lang_bui_cnstxpr_add3_wrap_cid_coe(&a, &e, &f, &cf);
		mk_lang_bui_cnstxpr_add3_wrap_cie_cod(&a, &e, cf, &f);
		mk_lang_bui_cnstxpr_add3_wrap_cie_coe(&a, &e, cf, &f, &cf);
		mk_lang_bui_cnstxpr_add2_wrap_cid_cod(&a, &e);
		mk_lang_bui_cnstxpr_add2_wrap_cid_coe(&a, &e, &cf);
		mk_lang_bui_cnstxpr_add2_wrap_cie_cod(&a, &e, cf);
		mk_lang_bui_cnstxpr_add2_wrap_cie_coe(&a, &e, cf, &cf);
		mk_lang_bui_cnstxpr_sub3_wrap_cid_cod(&a, &e, &f);
		mk_lang_bui_cnstxpr_sub3_wrap_cid_coe(&a, &e, &f, &cf);
		mk_lang_bui_cnstxpr_sub3_wrap_cie_cod(&a, &e, cf, &f);
		mk_lang_bui_cnstxpr_sub3_wrap_cie_coe(&a, &e, cf, &f, &cf);
		mk_lang_bui_cnstxpr_sub2_wrap_cid_cod(&a, &e);
		mk_lang_bui_cnstxpr_sub2_wrap_cid_coe(&a, &e, &cf);
		mk_lang_bui_cnstxpr_sub2_wrap_cie_cod(&a, &e, cf);
		mk_lang_bui_cnstxpr_sub2_wrap_cie_coe(&a, &e, cf, &cf);
		mk_lang_bui_cnstxpr_mul3_wrap_lo(&a, &e, &f);
		mk_lang_bui_cnstxpr_mul3_wrap_hi(&a, &e, &f);
		mk_lang_bui_cnstxpr_mul4_wrap_wi(&a, &e, &f, &g);
		mk_lang_bui_cnstxpr_mul2_wrap_lo(&a, &e);
		mk_lang_bui_cnstxpr_mul2_wrap_hi(&a, &e);
		mk_lang_bui_cnstxpr_mul2_wrap_wi(&a, &e);
		++e; ++e;
		mk_lang_bui_cnstxpr_div3_wrap(&a, &e, &f);
		mk_lang_bui_cnstxpr_mod3_wrap(&a, &e, &f);
		mk_lang_bui_cnstxpr_divmod4_wrap(&a, &e, &f, &g);
		mk_lang_bui_cnstxpr_div2_wrap(&a, &e);
		mk_lang_bui_cnstxpr_mod2_wrap(&a, &e);
		mk_lang_bui_cnstxpr_divmod2_wrap(&a, &e);
	}
	{
		mk_sl_cui_cnstxpr_t a mk_lang_constexpr_init;
		mk_lang_bi_uint_t b mk_lang_constexpr_init;
		mk_lang_bi_uchar_t c[mk_lang_sizeof_bi_uint_t*99] mk_lang_constexpr_init;
		mk_lang_bi_ulllong_t d[99] mk_lang_constexpr_init;
		mk_sl_cui_cnstxpr_t e mk_lang_constexpr_init;
		mk_lang_types_bool_t cf mk_lang_constexpr_init;
		mk_sl_cui_cnstxpr_t f mk_lang_constexpr_init;
		mk_sl_cui_cnstxpr_t g mk_lang_constexpr_init;

		mk_sl_cui_cnstxpr_set_zero(&a);
		mk_sl_cui_cnstxpr_set_max(&a);
		mk_sl_cui_cnstxpr_set_one(&a);
		mk_sl_cui_cnstxpr_set_bit(&a, 2);
		mk_sl_cui_cnstxpr_set_mask(&a, 2);
		mk_sl_cui_cnstxpr_to_bi_uint(&a, &b);
		mk_sl_cui_cnstxpr_from_bi_uint(&a, &b);
		mk_sl_cui_cnstxpr_to_buis_uchar_le(&a, c);
		mk_sl_cui_cnstxpr_from_buis_uchar_le(&a, c);
		mk_sl_cui_cnstxpr_to_buis_uchar_be(&a, c);
		mk_sl_cui_cnstxpr_from_buis_uchar_be(&a, c);
		mk_sl_cui_cnstxpr_to_buis_ulllong_le(&a, d);
		mk_sl_cui_cnstxpr_from_buis_ulllong_le(&a, d);
		mk_sl_cui_cnstxpr_to_buis_ulllong_be(&a, d);
		mk_sl_cui_cnstxpr_from_buis_ulllong_be(&a, d);
		(void)mk_sl_cui_cnstxpr_is_zero(&a);
		(void)mk_sl_cui_cnstxpr_is_max(&a);
		(void)mk_sl_cui_cnstxpr_eq(&a, &e);
		(void)mk_sl_cui_cnstxpr_ne(&a, &e);
		(void)mk_sl_cui_cnstxpr_lt(&a, &e);
		(void)mk_sl_cui_cnstxpr_le(&a, &e);
		(void)mk_sl_cui_cnstxpr_gt(&a, &e);
		(void)mk_sl_cui_cnstxpr_ge(&a, &e);
		mk_sl_cui_cnstxpr_inc2(&a, &e);
		mk_sl_cui_cnstxpr_dec2(&a, &e);
		mk_sl_cui_cnstxpr_inc1(&a);
		mk_sl_cui_cnstxpr_dec1(&a);
		mk_sl_cui_cnstxpr_not2(&a, &e);
		mk_sl_cui_cnstxpr_or3(&a, &e, &f);
		mk_sl_cui_cnstxpr_and3(&a, &e, &f);
		mk_sl_cui_cnstxpr_xor3(&a, &e, &f);
		mk_sl_cui_cnstxpr_not1(&a);
		mk_sl_cui_cnstxpr_or2(&a, &e);
		mk_sl_cui_cnstxpr_and2(&a, &e);
		mk_sl_cui_cnstxpr_xor2(&a, &e);
		mk_sl_cui_cnstxpr_shl3(&a, 2, &e);
		mk_sl_cui_cnstxpr_shr3(&a, 2, &e);
		mk_sl_cui_cnstxpr_rotl3(&a, 2, &e);
		mk_sl_cui_cnstxpr_rotr3(&a, 2, &e);
		mk_sl_cui_cnstxpr_shl2(&a, 2);
		mk_sl_cui_cnstxpr_shr2(&a, 2);
		mk_sl_cui_cnstxpr_rotl2(&a, 2);
		mk_sl_cui_cnstxpr_rotr2(&a, 2);
		(void)mk_sl_cui_cnstxpr_would_overflow_add_cc(&a, &e);
		(void)mk_sl_cui_cnstxpr_would_overflow_add_cs(&a, &e);
		(void)mk_sl_cui_cnstxpr_would_overflow_add(&a, &e, cf);
		(void)mk_sl_cui_cnstxpr_would_overflow_sub_cc(&a, &e);
		(void)mk_sl_cui_cnstxpr_would_overflow_sub_cs(&a, &e);
		(void)mk_sl_cui_cnstxpr_would_overflow_sub(&a, &e, cf);
		(void)mk_sl_cui_cnstxpr_would_overflow_mul(&a, &e);
		mk_sl_cui_cnstxpr_add3_wrap_cid_cod(&a, &e, &f);
		mk_sl_cui_cnstxpr_add3_wrap_cid_coe(&a, &e, &f, &cf);
		mk_sl_cui_cnstxpr_add3_wrap_cie_cod(&a, &e, cf, &f);
		mk_sl_cui_cnstxpr_add3_wrap_cie_coe(&a, &e, cf, &f, &cf);
		mk_sl_cui_cnstxpr_add2_wrap_cid_cod(&a, &e);
		mk_sl_cui_cnstxpr_add2_wrap_cid_coe(&a, &e, &cf);
		mk_sl_cui_cnstxpr_add2_wrap_cie_cod(&a, &e, cf);
		mk_sl_cui_cnstxpr_add2_wrap_cie_coe(&a, &e, cf, &cf);
		mk_sl_cui_cnstxpr_sub3_wrap_cid_cod(&a, &e, &f);
		mk_sl_cui_cnstxpr_sub3_wrap_cid_coe(&a, &e, &f, &cf);
		mk_sl_cui_cnstxpr_sub3_wrap_cie_cod(&a, &e, cf, &f);
		mk_sl_cui_cnstxpr_sub3_wrap_cie_coe(&a, &e, cf, &f, &cf);
		mk_sl_cui_cnstxpr_sub2_wrap_cid_cod(&a, &e);
		mk_sl_cui_cnstxpr_sub2_wrap_cid_coe(&a, &e, &cf);
		mk_sl_cui_cnstxpr_sub2_wrap_cie_cod(&a, &e, cf);
		mk_sl_cui_cnstxpr_sub2_wrap_cie_coe(&a, &e, cf, &cf);
		mk_sl_cui_cnstxpr_mul3_wrap_lo(&a, &e, &f);
		mk_sl_cui_cnstxpr_mul3_wrap_hi(&a, &e, &f);
		mk_sl_cui_cnstxpr_mul4_wrap_wi(&a, &e, &f, &g);
		mk_sl_cui_cnstxpr_mul2_wrap_lo(&a, &e);
		mk_sl_cui_cnstxpr_mul2_wrap_hi(&a, &e);
		mk_sl_cui_cnstxpr_mul2_wrap_wi(&a, &e);
		mk_sl_cui_cnstxpr_inc1(&e); mk_sl_cui_cnstxpr_inc1(&e);
		mk_sl_cui_cnstxpr_div3_wrap(&a, &e, &f);
		mk_sl_cui_cnstxpr_mod3_wrap(&a, &e, &f);
		mk_sl_cui_cnstxpr_divmod4_wrap(&a, &e, &f, &g);
		mk_sl_cui_cnstxpr_div2_wrap(&a, &e);
		mk_sl_cui_cnstxpr_mod2_wrap(&a, &e);
		mk_sl_cui_cnstxpr_divmod2_wrap(&a, &e);
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
