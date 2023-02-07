#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_endian.h"
#include "mk_lang_sizeof.h"


#if defined mk_sl_cui_name
#define mk_sl_cui_inl_def_name mk_sl_cui_name
#else
#if !defined mk_sl_cui_inl_type && !defined mk_sl_cui_inl_count && !defined mk_sl_cui_inl_endian
#define mk_sl_cui_inl_def_name zzzzzzzzzz
#elif !defined mk_sl_cui_inl_type && !defined mk_sl_cui_inl_count && defined mk_sl_cui_inl_endian && defined mk_sl_cui_inl_endian_default
#define mk_sl_cui_inl_def_name zzzzzzzzzz1
#elif !defined mk_sl_cui_inl_type && defined mk_sl_cui_inl_count && defined mk_sl_cui_inl_count_default && defined mk_sl_cui_inl_endian
#if mk_sl_cui_inl_endian == mk_lang_endian_little
#define mk_sl_cui_inl_def_name zzzzzzzzzzle
#elif mk_sl_cui_inl_endian == mk_lang_endian_big
#define mk_sl_cui_inl_def_name zzzzzzzzzzbe
#endif
#elif defined mk_sl_cui_inl_type && defined mk_sl_cui_inl_type_default && defined mk_sl_cui_inl_count && defined mk_sl_cui_inl_endian
#if mk_sl_cui_inl_endian == mk_lang_endian_little
#define mk_sl_cui_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(zzzzzzzzzz, mk_sl_cui_inl_type), mk_sl_cui_inl_count), le)
#elif mk_sl_cui_inl_endian == mk_lang_endian_big
#define mk_sl_cui_inl_def_name mk_lang_concat(mk_lang_concat(mk_lang_concat(zzzzzzzzzz, mk_sl_cui_inl_type), mk_sl_cui_inl_count), be)
#endif
#elif defined mk_sl_cui_inl_type && defined mk_sl_cui_inl_count && defined mk_sl_cui_inl_endian
#if mk_sl_cui_inl_endian == mk_lang_endian_little
#define mk_sl_cui_inl_def_name mk_lang_concat(mk_lang_concat(mk_sl_cui_inl_type, mk_sl_cui_inl_count), le)
#elif mk_sl_cui_inl_endian == mk_lang_endian_big
#define mk_sl_cui_inl_def_name mk_lang_concat(mk_lang_concat(mk_sl_cui_inl_type, mk_sl_cui_inl_count), be)
#endif
#endif
#endif

#if defined mk_sl_cui_base_type
#define mk_sl_cui_inl_def_base_type mk_sl_cui_base_type
#elif defined mk_sl_cui_inl_type
#define mk_sl_cui_inl_def_base_type mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_cui_inl_type), _t)
#else
#define mk_sl_cui_inl_def_base_type mk_lang_bi_uint_t
#endif

#if defined mk_sl_cui_base_name
#define mk_sl_cui_inl_def_base_name mk_sl_cui_base_name
#elif defined mk_sl_cui_inl_type
#define mk_sl_cui_inl_def_base_name mk_lang_concat(mk_lang_bui_, mk_sl_cui_inl_type)
#else
#define mk_sl_cui_inl_def_base_name mk_lang_bui_uint
#endif

#if defined mk_sl_cui_base_bits
#define mk_sl_cui_inl_def_base_bits mk_sl_cui_base_bits
#elif defined mk_sl_cui_inl_type
#define mk_sl_cui_inl_def_base_bits (mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_sl_cui_inl_type), _t) * mk_lang_charbit)
#else
#define mk_sl_cui_inl_def_base_bits (mk_lang_sizeof_bi_uint_t * mk_lang_charbit)
#endif

#if defined mk_sl_cui_count
#define mk_sl_cui_inl_def_count mk_sl_cui_count
#elif defined mk_sl_cui_inl_count
#define mk_sl_cui_inl_def_count mk_sl_cui_inl_count
#else
#define mk_sl_cui_inl_def_count 1
#endif

#if defined mk_sl_cui_endian
#define mk_sl_cui_inl_def_endian mk_sl_cui_endian
#elif defined mk_sl_cui_inl_endian
#define mk_sl_cui_inl_def_endian mk_sl_cui_inl_endian
#else
#define mk_sl_cui_inl_def_endian mk_lang_endian_little
#endif


#if mk_sl_cui_inl_def_endian == mk_lang_endian_little
#define mk_sl_cui_inl_def_idx(x) ((int)(x))
#elif mk_sl_cui_inl_def_endian == mk_lang_endian_big
#define mk_sl_cui_inl_def_idx(x) ((int)(((int)(mk_sl_cui_inl_def_count - 1)) - ((int)(x))))
#endif

#define mk_sl_cui_inl_def_base_set_zero mk_lang_concat(mk_sl_cui_inl_def_base_name, _set_zero)
#define mk_sl_cui_inl_def_base_set_max mk_lang_concat(mk_sl_cui_inl_def_base_name, _set_max)
#define mk_sl_cui_inl_def_base_set_one mk_lang_concat(mk_sl_cui_inl_def_base_name, _set_one)
#define mk_sl_cui_inl_def_base_set_bit mk_lang_concat(mk_sl_cui_inl_def_base_name, _set_bit)
#define mk_sl_cui_inl_def_base_set_mask mk_lang_concat(mk_sl_cui_inl_def_base_name, _set_mask)
#define mk_sl_cui_inl_def_base_is_zero mk_lang_concat(mk_sl_cui_inl_def_base_name, _is_zero)
#define mk_sl_cui_inl_def_base_is_max mk_lang_concat(mk_sl_cui_inl_def_base_name, _is_max)
#define mk_sl_cui_inl_def_base_eq mk_lang_concat(mk_sl_cui_inl_def_base_name, _eq)
#define mk_sl_cui_inl_def_base_ne mk_lang_concat(mk_sl_cui_inl_def_base_name, _ne)
#define mk_sl_cui_inl_def_base_lt mk_lang_concat(mk_sl_cui_inl_def_base_name, _lt)
#define mk_sl_cui_inl_def_base_le mk_lang_concat(mk_sl_cui_inl_def_base_name, _le)
#define mk_sl_cui_inl_def_base_gt mk_lang_concat(mk_sl_cui_inl_def_base_name, _gt)
#define mk_sl_cui_inl_def_base_ge mk_lang_concat(mk_sl_cui_inl_def_base_name, _ge)
#define mk_sl_cui_inl_def_base_inc2 mk_lang_concat(mk_sl_cui_inl_def_base_name, _inc2)
#define mk_sl_cui_inl_def_base_dec2 mk_lang_concat(mk_sl_cui_inl_def_base_name, _dec2)
#define mk_sl_cui_inl_def_base_inc1 mk_lang_concat(mk_sl_cui_inl_def_base_name, _inc1)
#define mk_sl_cui_inl_def_base_dec1 mk_lang_concat(mk_sl_cui_inl_def_base_name, _dec1)
#define mk_sl_cui_inl_def_base_not2 mk_lang_concat(mk_sl_cui_inl_def_base_name, _not2)
#define mk_sl_cui_inl_def_base_or3 mk_lang_concat(mk_sl_cui_inl_def_base_name, _or3)
#define mk_sl_cui_inl_def_base_and3 mk_lang_concat(mk_sl_cui_inl_def_base_name, _and3)
#define mk_sl_cui_inl_def_base_xor3 mk_lang_concat(mk_sl_cui_inl_def_base_name, _xor3)
#define mk_sl_cui_inl_def_base_not1 mk_lang_concat(mk_sl_cui_inl_def_base_name, _not1)
#define mk_sl_cui_inl_def_base_or2 mk_lang_concat(mk_sl_cui_inl_def_base_name, _or2)
#define mk_sl_cui_inl_def_base_and2 mk_lang_concat(mk_sl_cui_inl_def_base_name, _and2)
#define mk_sl_cui_inl_def_base_xor2 mk_lang_concat(mk_sl_cui_inl_def_base_name, _xor2)
#define mk_sl_cui_inl_def_base_shl3 mk_lang_concat(mk_sl_cui_inl_def_base_name, _shl3)
#define mk_sl_cui_inl_def_base_shr3 mk_lang_concat(mk_sl_cui_inl_def_base_name, _shr3)
#define mk_sl_cui_inl_def_base_rotl3 mk_lang_concat(mk_sl_cui_inl_def_base_name, _rotl3)
#define mk_sl_cui_inl_def_base_rotr3 mk_lang_concat(mk_sl_cui_inl_def_base_name, _rotr3)
#define mk_sl_cui_inl_def_base_shl2 mk_lang_concat(mk_sl_cui_inl_def_base_name, _shl2)
#define mk_sl_cui_inl_def_base_shr2 mk_lang_concat(mk_sl_cui_inl_def_base_name, _shr2)
#define mk_sl_cui_inl_def_base_rotl2 mk_lang_concat(mk_sl_cui_inl_def_base_name, _rotl2)
#define mk_sl_cui_inl_def_base_rotr2 mk_lang_concat(mk_sl_cui_inl_def_base_name, _rotr2)
#define mk_sl_cui_inl_def_base_add3_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_def_base_name, _add3_wrap_cid_cod)
#define mk_sl_cui_inl_def_base_add3_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_def_base_name, _add3_wrap_cid_coe)
#define mk_sl_cui_inl_def_base_add3_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_def_base_name, _add3_wrap_cie_cod)
#define mk_sl_cui_inl_def_base_add3_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_def_base_name, _add3_wrap_cie_coe)
#define mk_sl_cui_inl_def_base_add2_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_def_base_name, _add2_wrap_cid_cod)
#define mk_sl_cui_inl_def_base_add2_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_def_base_name, _add2_wrap_cid_coe)
#define mk_sl_cui_inl_def_base_add2_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_def_base_name, _add2_wrap_cie_cod)
#define mk_sl_cui_inl_def_base_add2_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_def_base_name, _add2_wrap_cie_coe)
#define mk_sl_cui_inl_def_base_sub3_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_def_base_name, _sub3_wrap_cid_cod)
#define mk_sl_cui_inl_def_base_sub3_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_def_base_name, _sub3_wrap_cid_coe)
#define mk_sl_cui_inl_def_base_sub3_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_def_base_name, _sub3_wrap_cie_cod)
#define mk_sl_cui_inl_def_base_sub3_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_def_base_name, _sub3_wrap_cie_coe)
#define mk_sl_cui_inl_def_base_sub2_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_def_base_name, _sub2_wrap_cid_cod)
#define mk_sl_cui_inl_def_base_sub2_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_def_base_name, _sub2_wrap_cid_coe)
#define mk_sl_cui_inl_def_base_sub2_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_def_base_name, _sub2_wrap_cie_cod)
#define mk_sl_cui_inl_def_base_sub2_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_def_base_name, _sub2_wrap_cie_coe)
#define mk_sl_cui_inl_def_base_mul3_wrap_lo mk_lang_concat(mk_sl_cui_inl_def_base_name, _mul3_wrap_lo)
#define mk_sl_cui_inl_def_base_mul3_wrap_hi mk_lang_concat(mk_sl_cui_inl_def_base_name, _mul3_wrap_hi)
#define mk_sl_cui_inl_def_base_mul4_wrap_wi mk_lang_concat(mk_sl_cui_inl_def_base_name, _mul4_wrap_wi)
#define mk_sl_cui_inl_def_base_mul2_wrap_lo mk_lang_concat(mk_sl_cui_inl_def_base_name, _mul2_wrap_lo)
#define mk_sl_cui_inl_def_base_mul2_wrap_hi mk_lang_concat(mk_sl_cui_inl_def_base_name, _mul2_wrap_hi)
#define mk_sl_cui_inl_def_base_mul2_wrap_wi mk_lang_concat(mk_sl_cui_inl_def_base_name, _mul2_wrap_wi)

#define mk_sl_cui_inl_def_s mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _s)
#define mk_sl_cui_inl_def_t mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _t)

#define mk_sl_cui_inl_def_set_zero mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _set_zero)
#define mk_sl_cui_inl_def_set_max mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _set_max)
#define mk_sl_cui_inl_def_set_one mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _set_one)
#define mk_sl_cui_inl_def_set_bit mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _set_bit)
#define mk_sl_cui_inl_def_set_mask mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _set_mask)

#define mk_sl_cui_inl_def_is_zero mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _is_zero)
#define mk_sl_cui_inl_def_is_max mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _is_max)
#define mk_sl_cui_inl_def_eq mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _eq)
#define mk_sl_cui_inl_def_ne mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _ne)
#define mk_sl_cui_inl_def_lt mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _lt)
#define mk_sl_cui_inl_def_le mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _le)
#define mk_sl_cui_inl_def_gt mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _gt)
#define mk_sl_cui_inl_def_ge mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _ge)

#define mk_sl_cui_inl_def_inc2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _inc2)
#define mk_sl_cui_inl_def_dec2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _dec2)
#define mk_sl_cui_inl_def_inc1 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _inc1)
#define mk_sl_cui_inl_def_dec1 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _dec1)

#define mk_sl_cui_inl_def_not2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _not2)
#define mk_sl_cui_inl_def_or3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _or3)
#define mk_sl_cui_inl_def_and3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _and3)
#define mk_sl_cui_inl_def_xor3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _xor3)
#define mk_sl_cui_inl_def_not1 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _not1)
#define mk_sl_cui_inl_def_or2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _or2)
#define mk_sl_cui_inl_def_and2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _and2)
#define mk_sl_cui_inl_def_xor2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _xor2)

#define mk_sl_cui_inl_def_shl3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _shl3)
#define mk_sl_cui_inl_def_shr3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _shr3)
#define mk_sl_cui_inl_def_rotl3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _rotl3)
#define mk_sl_cui_inl_def_rotr3 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _rotr3)
#define mk_sl_cui_inl_def_shl2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _shl2)
#define mk_sl_cui_inl_def_shr2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _shr2)
#define mk_sl_cui_inl_def_rotl2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _rotl2)
#define mk_sl_cui_inl_def_rotr2 mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _rotr2)

#define mk_sl_cui_inl_def_add3_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _add3_wrap_cid_cod)
#define mk_sl_cui_inl_def_add3_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _add3_wrap_cid_coe)
#define mk_sl_cui_inl_def_add3_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _add3_wrap_cie_cod)
#define mk_sl_cui_inl_def_add3_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _add3_wrap_cie_coe)
#define mk_sl_cui_inl_def_add2_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _add2_wrap_cid_cod)
#define mk_sl_cui_inl_def_add2_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _add2_wrap_cid_coe)
#define mk_sl_cui_inl_def_add2_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _add2_wrap_cie_cod)
#define mk_sl_cui_inl_def_add2_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _add2_wrap_cie_coe)

#define mk_sl_cui_inl_def_sub3_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _sub3_wrap_cid_cod)
#define mk_sl_cui_inl_def_sub3_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _sub3_wrap_cid_coe)
#define mk_sl_cui_inl_def_sub3_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _sub3_wrap_cie_cod)
#define mk_sl_cui_inl_def_sub3_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _sub3_wrap_cie_coe)
#define mk_sl_cui_inl_def_sub2_wrap_cid_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _sub2_wrap_cid_cod)
#define mk_sl_cui_inl_def_sub2_wrap_cid_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _sub2_wrap_cid_coe)
#define mk_sl_cui_inl_def_sub2_wrap_cie_cod mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _sub2_wrap_cie_cod)
#define mk_sl_cui_inl_def_sub2_wrap_cie_coe mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _sub2_wrap_cie_coe)

#define mk_sl_cui_inl_def_mul3_wrap_lo_restrict mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul3_wrap_lo_restrict)
#define mk_sl_cui_inl_def_mul3_wrap_lo_alias mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul3_wrap_lo_alias)
#define mk_sl_cui_inl_def_mul3_wrap_hi_restrict mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul3_wrap_hi_restrict)
#define mk_sl_cui_inl_def_mul3_wrap_hi_alias mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul3_wrap_hi_alias)
#define mk_sl_cui_inl_def_mul4_wrap_wi_restrict mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul4_wrap_wi_restrict)
#define mk_sl_cui_inl_def_mul4_wrap_wi_alias mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul4_wrap_wi_alias)

#define mk_sl_cui_inl_def_mul3_wrap_lo mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul3_wrap_lo)
#define mk_sl_cui_inl_def_mul3_wrap_hi mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul3_wrap_hi)
#define mk_sl_cui_inl_def_mul4_wrap_wi mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul4_wrap_wi)
#define mk_sl_cui_inl_def_mul2_wrap_lo mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul2_wrap_lo)
#define mk_sl_cui_inl_def_mul2_wrap_hi mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul2_wrap_hi)
#define mk_sl_cui_inl_def_mul2_wrap_wi mk_lang_concat(mk_lang_concat(mk_sl_cui_, mk_sl_cui_inl_def_name), _mul2_wrap_wi)
