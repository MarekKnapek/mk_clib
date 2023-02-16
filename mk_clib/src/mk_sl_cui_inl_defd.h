#include "mk_lang_concat.h"
#include "mk_lang_endian.h"
#include "mk_lang_assert.h"


#if \
	defined mk_sl_cui_name && \
	defined mk_sl_cui_base_type && \
	defined mk_sl_cui_base_name && \
	defined mk_sl_cui_base_bits && \
	defined mk_sl_cui_count && \
	defined mk_sl_cui_endian && \
	1
#define mk_sl_cui_inl_defd_name mk_sl_cui_name
#define mk_sl_cui_inl_defd_base_type mk_sl_cui_base_type
#define mk_sl_cui_inl_defd_base_name mk_sl_cui_base_name
#define mk_sl_cui_inl_defd_base_bits mk_sl_cui_base_bits
#define mk_sl_cui_inl_defd_count mk_sl_cui_count
#define mk_sl_cui_inl_defd_endian mk_sl_cui_endian
#else
#define mk_sl_cui_inl_defd_name mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_for_bui, _tn), mk_lang_concat(mk_sl_cui_for_count, _n)), mk_lang_concat(mk_sl_cui_for_endian, _name))
#define mk_sl_cui_inl_defd_base_type mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_lang_concat(mk_sl_cui_for_bui, _tn)), _t)
#define mk_sl_cui_inl_defd_base_name mk_lang_concat(mk_lang_bui_, mk_lang_concat(mk_sl_cui_for_bui, _tn))
#define mk_sl_cui_inl_defd_base_bits (mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_concat(mk_sl_cui_for_bui, _tn)), _t) * mk_lang_charbit)
#define mk_sl_cui_inl_defd_count mk_lang_concat(mk_sl_cui_for_count, _n)
#define mk_sl_cui_inl_defd_endian mk_lang_concat(mk_sl_cui_for_endian, _value)
#endif

#define mk_sl_cui_inl_defd_base_set_zero mk_lang_concat(mk_sl_cui_inl_defd_base_name, _set_zero)
#define mk_sl_cui_inl_defd_base_set_max mk_lang_concat(mk_sl_cui_inl_defd_base_name, _set_max)
#define mk_sl_cui_inl_defd_base_set_one mk_lang_concat(mk_sl_cui_inl_defd_base_name, _set_one)
#define mk_sl_cui_inl_defd_base_set_bit mk_lang_concat(mk_sl_cui_inl_defd_base_name, _set_bit)
#define mk_sl_cui_inl_defd_base_set_mask mk_lang_concat(mk_sl_cui_inl_defd_base_name, _set_mask)
#define mk_sl_cui_inl_defd_base_is_zero mk_lang_concat(mk_sl_cui_inl_defd_base_name, _is_zero)
#define mk_sl_cui_inl_defd_base_is_max mk_lang_concat(mk_sl_cui_inl_defd_base_name, _is_max)
#define mk_sl_cui_inl_defd_base_eq mk_lang_concat(mk_sl_cui_inl_defd_base_name, _eq)
#define mk_sl_cui_inl_defd_base_ne mk_lang_concat(mk_sl_cui_inl_defd_base_name, _ne)
#define mk_sl_cui_inl_defd_base_lt mk_lang_concat(mk_sl_cui_inl_defd_base_name, _lt)
#define mk_sl_cui_inl_defd_base_le mk_lang_concat(mk_sl_cui_inl_defd_base_name, _le)
#define mk_sl_cui_inl_defd_base_gt mk_lang_concat(mk_sl_cui_inl_defd_base_name, _gt)
#define mk_sl_cui_inl_defd_base_ge mk_lang_concat(mk_sl_cui_inl_defd_base_name, _ge)
#define mk_sl_cui_inl_defd_base_inc2 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _inc2)
#define mk_sl_cui_inl_defd_base_dec2 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _dec2)
#define mk_sl_cui_inl_defd_base_inc1 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _inc1)
#define mk_sl_cui_inl_defd_base_dec1 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _dec1)
#define mk_sl_cui_inl_defd_base_not2 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _not2)
#define mk_sl_cui_inl_defd_base_or3 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _or3)
#define mk_sl_cui_inl_defd_base_and3 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _and3)
#define mk_sl_cui_inl_defd_base_xor3 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _xor3)
#define mk_sl_cui_inl_defd_base_not1 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _not1)
#define mk_sl_cui_inl_defd_base_or2 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _or2)
#define mk_sl_cui_inl_defd_base_and2 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _and2)
#define mk_sl_cui_inl_defd_base_xor2 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _xor2)
#define mk_sl_cui_inl_defd_base_shl3 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _shl3)
#define mk_sl_cui_inl_defd_base_shr3 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _shr3)
#define mk_sl_cui_inl_defd_base_rotl3 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _rotl3)
#define mk_sl_cui_inl_defd_base_rotr3 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _rotr3)
#define mk_sl_cui_inl_defd_base_shl2 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _shl2)
#define mk_sl_cui_inl_defd_base_shr2 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _shr2)
#define mk_sl_cui_inl_defd_base_rotl2 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _rotl2)
#define mk_sl_cui_inl_defd_base_rotr2 mk_lang_concat(mk_sl_cui_inl_defd_base_name, _rotr2)
#define mk_sl_cui_inl_defd_base_add3_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_base_name, _add3_wrap_cid_cod)
#define mk_sl_cui_inl_defd_base_add3_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_base_name, _add3_wrap_cid_coe)
#define mk_sl_cui_inl_defd_base_add3_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_base_name, _add3_wrap_cie_cod)
#define mk_sl_cui_inl_defd_base_add3_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_base_name, _add3_wrap_cie_coe)
#define mk_sl_cui_inl_defd_base_add2_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_base_name, _add2_wrap_cid_cod)
#define mk_sl_cui_inl_defd_base_add2_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_base_name, _add2_wrap_cid_coe)
#define mk_sl_cui_inl_defd_base_add2_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_base_name, _add2_wrap_cie_cod)
#define mk_sl_cui_inl_defd_base_add2_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_base_name, _add2_wrap_cie_coe)
#define mk_sl_cui_inl_defd_base_sub3_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_base_name, _sub3_wrap_cid_cod)
#define mk_sl_cui_inl_defd_base_sub3_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_base_name, _sub3_wrap_cid_coe)
#define mk_sl_cui_inl_defd_base_sub3_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_base_name, _sub3_wrap_cie_cod)
#define mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_base_name, _sub3_wrap_cie_coe)
#define mk_sl_cui_inl_defd_base_sub2_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_base_name, _sub2_wrap_cid_cod)
#define mk_sl_cui_inl_defd_base_sub2_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_base_name, _sub2_wrap_cid_coe)
#define mk_sl_cui_inl_defd_base_sub2_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_base_name, _sub2_wrap_cie_cod)
#define mk_sl_cui_inl_defd_base_sub2_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_base_name, _sub2_wrap_cie_coe)
#define mk_sl_cui_inl_defd_base_mul3_wrap_lo mk_lang_concat(mk_sl_cui_inl_defd_base_name, _mul3_wrap_lo)
#define mk_sl_cui_inl_defd_base_mul3_wrap_hi mk_lang_concat(mk_sl_cui_inl_defd_base_name, _mul3_wrap_hi)
#define mk_sl_cui_inl_defd_base_mul4_wrap_wi mk_lang_concat(mk_sl_cui_inl_defd_base_name, _mul4_wrap_wi)
#define mk_sl_cui_inl_defd_base_mul2_wrap_lo mk_lang_concat(mk_sl_cui_inl_defd_base_name, _mul2_wrap_lo)
#define mk_sl_cui_inl_defd_base_mul2_wrap_hi mk_lang_concat(mk_sl_cui_inl_defd_base_name, _mul2_wrap_hi)
#define mk_sl_cui_inl_defd_base_mul2_wrap_wi mk_lang_concat(mk_sl_cui_inl_defd_base_name, _mul2_wrap_wi)

#define mk_sl_cui_inl_defd_s mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _s)
#define mk_sl_cui_inl_defd_t mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _t)

#define mk_sl_cui_inl_defd_idx(x) ((mk_sl_cui_inl_defd_endian == mk_lang_endian_little) ? (x) : ((mk_sl_cui_inl_defd_endian == mk_lang_endian_big) ? ((mk_sl_cui_inl_defd_count - 1) - (x)) : (mk_lang_assert(0), 0)))

#define mk_sl_cui_inl_defd_set_zero mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _set_zero)
#define mk_sl_cui_inl_defd_set_max mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _set_max)
#define mk_sl_cui_inl_defd_set_one mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _set_one)
#define mk_sl_cui_inl_defd_set_bit mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _set_bit)
#define mk_sl_cui_inl_defd_set_mask mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _set_mask)

#define mk_sl_cui_inl_defd_is_zero mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _is_zero)
#define mk_sl_cui_inl_defd_is_max mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _is_max)
#define mk_sl_cui_inl_defd_eq mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _eq)
#define mk_sl_cui_inl_defd_ne mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _ne)
#define mk_sl_cui_inl_defd_lt mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _lt)
#define mk_sl_cui_inl_defd_le mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _le)
#define mk_sl_cui_inl_defd_gt mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _gt)
#define mk_sl_cui_inl_defd_ge mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _ge)

#define mk_sl_cui_inl_defd_inc2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _inc2)
#define mk_sl_cui_inl_defd_dec2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _dec2)
#define mk_sl_cui_inl_defd_inc1 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _inc1)
#define mk_sl_cui_inl_defd_dec1 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _dec1)

#define mk_sl_cui_inl_defd_not2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _not2)
#define mk_sl_cui_inl_defd_or3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _or3)
#define mk_sl_cui_inl_defd_and3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _and3)
#define mk_sl_cui_inl_defd_xor3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _xor3)
#define mk_sl_cui_inl_defd_not1 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _not1)
#define mk_sl_cui_inl_defd_or2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _or2)
#define mk_sl_cui_inl_defd_and2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _and2)
#define mk_sl_cui_inl_defd_xor2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _xor2)

#define mk_sl_cui_inl_defd_shl3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _shl3)
#define mk_sl_cui_inl_defd_shr3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _shr3)
#define mk_sl_cui_inl_defd_rotl3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _rotl3)
#define mk_sl_cui_inl_defd_rotr3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _rotr3)
#define mk_sl_cui_inl_defd_shl2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _shl2)
#define mk_sl_cui_inl_defd_shr2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _shr2)
#define mk_sl_cui_inl_defd_rotl2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _rotl2)
#define mk_sl_cui_inl_defd_rotr2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _rotr2)

#define mk_sl_cui_inl_defd_add3_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _add3_wrap_cid_cod)
#define mk_sl_cui_inl_defd_add3_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _add3_wrap_cid_coe)
#define mk_sl_cui_inl_defd_add3_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _add3_wrap_cie_cod)
#define mk_sl_cui_inl_defd_add3_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _add3_wrap_cie_coe)
#define mk_sl_cui_inl_defd_add2_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _add2_wrap_cid_cod)
#define mk_sl_cui_inl_defd_add2_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _add2_wrap_cid_coe)
#define mk_sl_cui_inl_defd_add2_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _add2_wrap_cie_cod)
#define mk_sl_cui_inl_defd_add2_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _add2_wrap_cie_coe)

#define mk_sl_cui_inl_defd_sub3_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _sub3_wrap_cid_cod)
#define mk_sl_cui_inl_defd_sub3_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _sub3_wrap_cid_coe)
#define mk_sl_cui_inl_defd_sub3_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _sub3_wrap_cie_cod)
#define mk_sl_cui_inl_defd_sub3_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _sub3_wrap_cie_coe)
#define mk_sl_cui_inl_defd_sub2_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _sub2_wrap_cid_cod)
#define mk_sl_cui_inl_defd_sub2_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _sub2_wrap_cid_coe)
#define mk_sl_cui_inl_defd_sub2_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _sub2_wrap_cie_cod)
#define mk_sl_cui_inl_defd_sub2_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _sub2_wrap_cie_coe)

#define mk_sl_cui_inl_defd_mul3_wrap_lo_restrict mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul3_wrap_lo_restrict)
#define mk_sl_cui_inl_defd_mul3_wrap_lo_alias mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul3_wrap_lo_alias)
#define mk_sl_cui_inl_defd_mul3_wrap_hi_restrict mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul3_wrap_hi_restrict)
#define mk_sl_cui_inl_defd_mul3_wrap_hi_alias mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul3_wrap_hi_alias)
#define mk_sl_cui_inl_defd_mul4_wrap_wi_restrict mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul4_wrap_wi_restrict)
#define mk_sl_cui_inl_defd_mul4_wrap_wi_alias mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul4_wrap_wi_alias)

#define mk_sl_cui_inl_defd_mul3_wrap_lo mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul3_wrap_lo)
#define mk_sl_cui_inl_defd_mul3_wrap_hi mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul3_wrap_hi)
#define mk_sl_cui_inl_defd_mul4_wrap_wi mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul4_wrap_wi)
#define mk_sl_cui_inl_defd_mul2_wrap_lo mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul2_wrap_lo)
#define mk_sl_cui_inl_defd_mul2_wrap_hi mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul2_wrap_hi)
#define mk_sl_cui_inl_defd_mul2_wrap_wi mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_defd_name), _mul2_wrap_wi)
