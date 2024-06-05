include(`mk_lang_bui_inl.m')dnl
#include "mk_lang_attribute.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lang_bui_t_name) && \
	(defined mk_lang_bui_t_base) && \
	((defined mk_lang_bui_t_inline && ((mk_lang_bui_t_inline) == 0 || (mk_lang_bui_t_inline) == 1)) || !defined mk_lang_bui_t_inline) && \
1))
#error xxxxxxxxxx
#endif


#define mk_lang_bui_inl_defd_name mk_lang_bui_t_name
#define mk_lang_bui_inl_defd_base mk_lang_bui_t_base


#if defined mk_lang_bui_t_inline
#define mk_lang_bui_inl_defd_inline (mk_lang_bui_t_inline)
#else
#define mk_lang_bui_inl_defd_inline 0
#endif


#if mk_lang_bui_inl_defd_inline
#define mk_lang_bui_inl_defd_flatten mk_lang_attribute_msvc_flatten
#define mk_lang_bui_inl_defd_forceinline mk_lang_attribute_msvc_forceinline
#else
#define mk_lang_bui_inl_defd_flatten
#define mk_lang_bui_inl_defd_forceinline
#endif


#define mk_lang_bui_inl_defd_base_name mk_lang_concat(mk_lang_types_, mk_lang_bui_inl_defd_base)

#define mk_lang_bui_inl_defd_base_t mk_lang_concat(mk_lang_bui_inl_defd_base_name, _t)
#define mk_lang_bui_inl_defd_base_ct mk_lang_concat(mk_lang_bui_inl_defd_base_name, _ct)
#define mk_lang_bui_inl_defd_base_pt mk_lang_concat(mk_lang_bui_inl_defd_base_name, _pt)
#define mk_lang_bui_inl_defd_base_prt mk_lang_concat(mk_lang_bui_inl_defd_base_name, _prt)
#define mk_lang_bui_inl_defd_base_pct mk_lang_concat(mk_lang_bui_inl_defd_base_name, _pct)
#define mk_lang_bui_inl_defd_base_prct mk_lang_concat(mk_lang_bui_inl_defd_base_name, _prct)


#define mk_lang_bui_inl_defd_sizeof_d mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_bui_inl_defd_base), _t)
#define mk_lang_bui_inl_defd_sizebits_d (mk_lang_bui_inl_defd_sizeof_d * mk_lang_charbit)

#define mk_lang_bui_inl_defd_t mk_lang_concat(mk_lang_bui_inl_defd_name, _t)
#define mk_lang_bui_inl_defd_ct mk_lang_concat(mk_lang_bui_inl_defd_name, _ct)
#define mk_lang_bui_inl_defd_pt mk_lang_concat(mk_lang_bui_inl_defd_name, _pt)
#define mk_lang_bui_inl_defd_prt mk_lang_concat(mk_lang_bui_inl_defd_name, _prt)
#define mk_lang_bui_inl_defd_pct mk_lang_concat(mk_lang_bui_inl_defd_name, _pct)
#define mk_lang_bui_inl_defd_prct mk_lang_concat(mk_lang_bui_inl_defd_name, _prct)

#define mk_lang_bui_inl_defd_sizebits_e mk_lang_concat(mk_lang_bui_inl_defd_name, _sizebits_e)
#define mk_lang_bui_inl_defd_sizebits_t mk_lang_concat(mk_lang_bui_inl_defd_name, _sizebits_t)
#define mk_lang_bui_inl_defd_sizebits_v mk_lang_concat(mk_lang_bui_inl_defd_name, _sizebits_v)

#define mk_lang_bui_inl_defd_from_base mk_lang_concat(mk_lang_bui_inl_defd_name, _from_base)
mm_per_bi(`#define mk_lang_bui_inl_defd_from_bi_$1 mk_lang_concat(mk_lang_bui_inl_defd_name, _from_bi_$1)')
#define mk_lang_bui_inl_defd_to_base mk_lang_concat(mk_lang_bui_inl_defd_name, _to_base)
mm_per_bi(`#define mk_lang_bui_inl_defd_to_bi_$1 mk_lang_concat(mk_lang_bui_inl_defd_name, _to_bi_$1)')
mm_per_bui(`#define mk_lang_bui_inl_defd_from_buis_$1_le mk_lang_concat(mk_lang_bui_inl_defd_name, _from_buis_$1_le)')
mm_per_bui(`#define mk_lang_bui_inl_defd_to_buis_$1_le mk_lang_concat(mk_lang_bui_inl_defd_name, _to_buis_$1_le)')
mm_per_bui(`#define mk_lang_bui_inl_defd_from_buis_$1_be mk_lang_concat(mk_lang_bui_inl_defd_name, _from_buis_$1_be)')
mm_per_bui(`#define mk_lang_bui_inl_defd_to_buis_$1_be mk_lang_concat(mk_lang_bui_inl_defd_name, _to_buis_$1_be)')
#define mk_lang_bui_inl_defd_assign mk_lang_concat(mk_lang_bui_inl_defd_name, _assign)
#define mk_lang_bui_inl_defd_set_zero mk_lang_concat(mk_lang_bui_inl_defd_name, _set_zero)
#define mk_lang_bui_inl_defd_set_max mk_lang_concat(mk_lang_bui_inl_defd_name, _set_max)
#define mk_lang_bui_inl_defd_set_one mk_lang_concat(mk_lang_bui_inl_defd_name, _set_one)
#define mk_lang_bui_inl_defd_set_bit mk_lang_concat(mk_lang_bui_inl_defd_name, _set_bit)
#define mk_lang_bui_inl_defd_set_mask mk_lang_concat(mk_lang_bui_inl_defd_name, _set_mask)
#define mk_lang_bui_inl_defd_count_leading_zeros mk_lang_concat(mk_lang_bui_inl_defd_name, _count_leading_zeros)
#define mk_lang_bui_inl_defd_count_leading_ones mk_lang_concat(mk_lang_bui_inl_defd_name, _count_leading_ones)
#define mk_lang_bui_inl_defd_count_trailing_zeros mk_lang_concat(mk_lang_bui_inl_defd_name, _count_trailing_zeros)
#define mk_lang_bui_inl_defd_count_trailing_ones mk_lang_concat(mk_lang_bui_inl_defd_name, _count_trailing_ones)
#define mk_lang_bui_inl_defd_count_zeros_portable mk_lang_concat(mk_lang_bui_inl_defd_name, _count_zeros_portable)
#define mk_lang_bui_inl_defd_count_zeros mk_lang_concat(mk_lang_bui_inl_defd_name, _count_zeros)
#define mk_lang_bui_inl_defd_count_ones_portable mk_lang_concat(mk_lang_bui_inl_defd_name, _count_ones_portable)
#define mk_lang_bui_inl_defd_count_ones mk_lang_concat(mk_lang_bui_inl_defd_name, _count_ones)
#define mk_lang_bui_inl_defd_has_lsb mk_lang_concat(mk_lang_bui_inl_defd_name, _has_lsb)
#define mk_lang_bui_inl_defd_is_zero mk_lang_concat(mk_lang_bui_inl_defd_name, _is_zero)
#define mk_lang_bui_inl_defd_is_one mk_lang_concat(mk_lang_bui_inl_defd_name, _is_one)
#define mk_lang_bui_inl_defd_is_max mk_lang_concat(mk_lang_bui_inl_defd_name, _is_max)
#define mk_lang_bui_inl_defd_eq mk_lang_concat(mk_lang_bui_inl_defd_name, _eq)
#define mk_lang_bui_inl_defd_ne mk_lang_concat(mk_lang_bui_inl_defd_name, _ne)
#define mk_lang_bui_inl_defd_lt mk_lang_concat(mk_lang_bui_inl_defd_name, _lt)
#define mk_lang_bui_inl_defd_le mk_lang_concat(mk_lang_bui_inl_defd_name, _le)
#define mk_lang_bui_inl_defd_gt mk_lang_concat(mk_lang_bui_inl_defd_name, _gt)
#define mk_lang_bui_inl_defd_ge mk_lang_concat(mk_lang_bui_inl_defd_name, _ge)
#define mk_lang_bui_inl_defd_inc2 mk_lang_concat(mk_lang_bui_inl_defd_name, _inc2)
#define mk_lang_bui_inl_defd_dec2 mk_lang_concat(mk_lang_bui_inl_defd_name, _dec2)
#define mk_lang_bui_inl_defd_inc1 mk_lang_concat(mk_lang_bui_inl_defd_name, _inc1)
#define mk_lang_bui_inl_defd_dec1 mk_lang_concat(mk_lang_bui_inl_defd_name, _dec1)
#define mk_lang_bui_inl_defd_not2 mk_lang_concat(mk_lang_bui_inl_defd_name, _not2)
#define mk_lang_bui_inl_defd_or3 mk_lang_concat(mk_lang_bui_inl_defd_name, _or3)
#define mk_lang_bui_inl_defd_and3 mk_lang_concat(mk_lang_bui_inl_defd_name, _and3)
#define mk_lang_bui_inl_defd_xor3 mk_lang_concat(mk_lang_bui_inl_defd_name, _xor3)
#define mk_lang_bui_inl_defd_not1 mk_lang_concat(mk_lang_bui_inl_defd_name, _not1)
#define mk_lang_bui_inl_defd_or2 mk_lang_concat(mk_lang_bui_inl_defd_name, _or2)
#define mk_lang_bui_inl_defd_and2 mk_lang_concat(mk_lang_bui_inl_defd_name, _and2)
#define mk_lang_bui_inl_defd_xor2 mk_lang_concat(mk_lang_bui_inl_defd_name, _xor2)
#define mk_lang_bui_inl_defd_shl3 mk_lang_concat(mk_lang_bui_inl_defd_name, _shl3)
#define mk_lang_bui_inl_defd_shr3 mk_lang_concat(mk_lang_bui_inl_defd_name, _shr3)
#define mk_lang_bui_inl_defd_rotl3 mk_lang_concat(mk_lang_bui_inl_defd_name, _rotl3)
#define mk_lang_bui_inl_defd_rotr3 mk_lang_concat(mk_lang_bui_inl_defd_name, _rotr3)
#define mk_lang_bui_inl_defd_shl2 mk_lang_concat(mk_lang_bui_inl_defd_name, _shl2)
#define mk_lang_bui_inl_defd_shr2 mk_lang_concat(mk_lang_bui_inl_defd_name, _shr2)
#define mk_lang_bui_inl_defd_rotl2 mk_lang_concat(mk_lang_bui_inl_defd_name, _rotl2)
#define mk_lang_bui_inl_defd_rotr2 mk_lang_concat(mk_lang_bui_inl_defd_name, _rotr2)
#define mk_lang_bui_inl_defd_would_overflow_add_cc mk_lang_concat(mk_lang_bui_inl_defd_name, _would_overflow_add_cc)
#define mk_lang_bui_inl_defd_would_overflow_add_cs mk_lang_concat(mk_lang_bui_inl_defd_name, _would_overflow_add_cs)
#define mk_lang_bui_inl_defd_would_overflow_add mk_lang_concat(mk_lang_bui_inl_defd_name, _would_overflow_add)
#define mk_lang_bui_inl_defd_would_overflow_sub_cc mk_lang_concat(mk_lang_bui_inl_defd_name, _would_overflow_sub_cc)
#define mk_lang_bui_inl_defd_would_overflow_sub_cs mk_lang_concat(mk_lang_bui_inl_defd_name, _would_overflow_sub_cs)
#define mk_lang_bui_inl_defd_would_overflow_sub mk_lang_concat(mk_lang_bui_inl_defd_name, _would_overflow_sub)
#define mk_lang_bui_inl_defd_would_overflow_mul mk_lang_concat(mk_lang_bui_inl_defd_name, _would_overflow_mul)
#define mk_lang_bui_inl_defd_add3_wrap_cid_cod mk_lang_concat(mk_lang_bui_inl_defd_name, _add3_wrap_cid_cod)
#define mk_lang_bui_inl_defd_add3_wrap_cid_coe mk_lang_concat(mk_lang_bui_inl_defd_name, _add3_wrap_cid_coe)
#define mk_lang_bui_inl_defd_add3_wrap_cie_cod mk_lang_concat(mk_lang_bui_inl_defd_name, _add3_wrap_cie_cod)
#define mk_lang_bui_inl_defd_add3_wrap_cie_coe mk_lang_concat(mk_lang_bui_inl_defd_name, _add3_wrap_cie_coe)
#define mk_lang_bui_inl_defd_add2_wrap_cid_cod mk_lang_concat(mk_lang_bui_inl_defd_name, _add2_wrap_cid_cod)
#define mk_lang_bui_inl_defd_add2_wrap_cid_coe mk_lang_concat(mk_lang_bui_inl_defd_name, _add2_wrap_cid_coe)
#define mk_lang_bui_inl_defd_add2_wrap_cie_cod mk_lang_concat(mk_lang_bui_inl_defd_name, _add2_wrap_cie_cod)
#define mk_lang_bui_inl_defd_add2_wrap_cie_coe mk_lang_concat(mk_lang_bui_inl_defd_name, _add2_wrap_cie_coe)
#define mk_lang_bui_inl_defd_sub3_wrap_cid_cod mk_lang_concat(mk_lang_bui_inl_defd_name, _sub3_wrap_cid_cod)
#define mk_lang_bui_inl_defd_sub3_wrap_cid_coe mk_lang_concat(mk_lang_bui_inl_defd_name, _sub3_wrap_cid_coe)
#define mk_lang_bui_inl_defd_sub3_wrap_cie_cod mk_lang_concat(mk_lang_bui_inl_defd_name, _sub3_wrap_cie_cod)
#define mk_lang_bui_inl_defd_sub3_wrap_cie_coe mk_lang_concat(mk_lang_bui_inl_defd_name, _sub3_wrap_cie_coe)
#define mk_lang_bui_inl_defd_sub2_wrap_cid_cod mk_lang_concat(mk_lang_bui_inl_defd_name, _sub2_wrap_cid_cod)
#define mk_lang_bui_inl_defd_sub2_wrap_cid_coe mk_lang_concat(mk_lang_bui_inl_defd_name, _sub2_wrap_cid_coe)
#define mk_lang_bui_inl_defd_sub2_wrap_cie_cod mk_lang_concat(mk_lang_bui_inl_defd_name, _sub2_wrap_cie_cod)
#define mk_lang_bui_inl_defd_sub2_wrap_cie_coe mk_lang_concat(mk_lang_bui_inl_defd_name, _sub2_wrap_cie_coe)
#define mk_lang_bui_inl_defd_mul3_wrap_lo mk_lang_concat(mk_lang_bui_inl_defd_name, _mul3_wrap_lo)
#define mk_lang_bui_inl_defd_mul3_wrap_hi mk_lang_concat(mk_lang_bui_inl_defd_name, _mul3_wrap_hi)
#define mk_lang_bui_inl_defd_mul4_wrap_wi mk_lang_concat(mk_lang_bui_inl_defd_name, _mul4_wrap_wi)
#define mk_lang_bui_inl_defd_mul2_wrap_lo mk_lang_concat(mk_lang_bui_inl_defd_name, _mul2_wrap_lo)
#define mk_lang_bui_inl_defd_mul2_wrap_hi mk_lang_concat(mk_lang_bui_inl_defd_name, _mul2_wrap_hi)
#define mk_lang_bui_inl_defd_mul2_wrap_wi mk_lang_concat(mk_lang_bui_inl_defd_name, _mul2_wrap_wi)
#define mk_lang_bui_inl_defd_div3_wrap mk_lang_concat(mk_lang_bui_inl_defd_name, _div3_wrap)
#define mk_lang_bui_inl_defd_mod3_wrap mk_lang_concat(mk_lang_bui_inl_defd_name, _mod3_wrap)
#define mk_lang_bui_inl_defd_divmod4_wrap mk_lang_concat(mk_lang_bui_inl_defd_name, _divmod4_wrap)
#define mk_lang_bui_inl_defd_div2_wrap mk_lang_concat(mk_lang_bui_inl_defd_name, _div2_wrap)
#define mk_lang_bui_inl_defd_mod2_wrap mk_lang_concat(mk_lang_bui_inl_defd_name, _mod2_wrap)
#define mk_lang_bui_inl_defd_divmod2_wrap mk_lang_concat(mk_lang_bui_inl_defd_name, _divmod2_wrap)

#define mk_lang_bui_inl_defd_mul3_wrap_hi_portable mk_lang_concat(mk_lang_bui_inl_defd_name, _mul3_wrap_hi_portable)
#define mk_lang_bui_inl_defd_mul4_wrap_wi_portable mk_lang_concat(mk_lang_bui_inl_defd_name, _mul4_wrap_wi_portable)
