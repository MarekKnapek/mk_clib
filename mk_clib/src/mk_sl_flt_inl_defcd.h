#include "mk_lang_bi.h"
#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_endian.h"
#include "mk_lang_sizeof.h"


#define mk_sl_flt_defd_bui_tn uint
#define mk_sl_flt_defd_bui_t mk_lang_concat(mk_lang_concat(mk_lang_bi_, mk_sl_flt_defd_bui_tn), _t)
#define mk_sl_flt_defd_bui_sizeof mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_sl_flt_defd_bui_tn), _t)
#define mk_sl_flt_defd_bui_bits (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)
#define mk_sl_flt_defd_has_bits_a (mk_lang_div_roundup(mk_sl_flt_defd_need_bits_a, (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)) * (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit))
#define mk_sl_flt_defd_has_bits_b (mk_lang_div_roundup(mk_sl_flt_defd_need_bits_b, (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)) * (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit))


#define mk_lang_bui_name mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name)
#define mk_lang_bui_type mk_sl_flt_defd_bui_t
#define mk_lang_bui_sizeof mk_sl_flt_defd_bui_sizeof
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_cui_name mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name)
#define mk_sl_cui_base_type mk_sl_flt_defd_bui_t
#define mk_sl_cui_base_name mk_lang_concat(mk_lang_bui_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))
#define mk_sl_cui_base_bits (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(mk_sl_flt_defd_bits, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn mk_sl_flt_defd_bui_tn
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#define mk_sl_flt_defd_cui mk_lang_concat(mk_sl_cui_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))
#define mk_sl_flt_defd_cui_t mk_lang_concat(mk_sl_flt_defd_cui, _t)
#define mk_sl_flt_defd_cui_set_zero mk_lang_concat(mk_sl_flt_defd_cui, _set_zero)
#define mk_sl_flt_defd_cui_to_bi_sint mk_lang_concat(mk_sl_flt_defd_cui, _to_bi_sint)
#define mk_sl_flt_defd_cui_from_bi_sint mk_lang_concat(mk_sl_flt_defd_cui, _from_bi_sint)
#define mk_sl_flt_defd_cui_to_buis_uchar_le mk_lang_concat(mk_sl_flt_defd_cui, _to_buis_uchar_le)
#define mk_sl_flt_defd_cui_from_buis_uchar_le mk_lang_concat(mk_sl_flt_defd_cui, _from_buis_uchar_le)
#define mk_sl_flt_defd_cui_set_bit mk_lang_concat(mk_sl_flt_defd_cui, _set_bit)
#define mk_sl_flt_defd_cui_set_mask mk_lang_concat(mk_sl_flt_defd_cui, _set_mask)
#define mk_sl_flt_defd_cui_is_zero mk_lang_concat(mk_sl_flt_defd_cui, _is_zero)
#define mk_sl_flt_defd_cui_or2 mk_lang_concat(mk_sl_flt_defd_cui, _or2)
#define mk_sl_flt_defd_cui_and3 mk_lang_concat(mk_sl_flt_defd_cui, _and3)
#define mk_sl_flt_defd_cui_and2 mk_lang_concat(mk_sl_flt_defd_cui, _and2)
#define mk_sl_flt_defd_cui_shr3 mk_lang_concat(mk_sl_flt_defd_cui, _shr3)
#define mk_sl_flt_defd_cui_shl2 mk_lang_concat(mk_sl_flt_defd_cui, _shl2)

#define mk_sl_cui_name mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), biga)
#define mk_sl_cui_base_type mk_sl_flt_defd_bui_t
#define mk_sl_cui_base_name mk_lang_concat(mk_lang_bui_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))
#define mk_sl_cui_base_bits (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(mk_sl_flt_defd_need_bits_a, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn mk_sl_flt_defd_bui_tn
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#define mk_sl_flt_defd_cuiba mk_lang_concat(mk_sl_cui_, mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), biga))
#define mk_sl_flt_defd_cuiba_t mk_lang_concat(mk_sl_flt_defd_cuiba, _t)
#define mk_sl_flt_defd_cuiba_from_bi_sint mk_lang_concat(mk_sl_flt_defd_cuiba, _from_bi_sint)
#define mk_sl_flt_defd_cuiba_count_leading_zeros mk_lang_concat(mk_sl_flt_defd_cuiba, _count_leading_zeros)
#define mk_sl_flt_defd_cuiba_is_zero mk_lang_concat(mk_sl_flt_defd_cuiba, _is_zero)
#define mk_sl_flt_defd_cuiba_shl2 mk_lang_concat(mk_sl_flt_defd_cuiba, _shl2)
#define mk_sl_flt_defd_cuiba_shr2 mk_lang_concat(mk_sl_flt_defd_cuiba, _shr2)
#define mk_sl_flt_defd_cuiba_add3_wrap_cid_coe mk_lang_concat(mk_sl_flt_defd_cuiba, _add3_wrap_cid_coe)
#define mk_sl_flt_defd_cuiba_add3_wrap_cid_coe_smol mk_lang_concat(mk_sl_flt_defd_cuiba, _add3_wrap_cid_coe_smol)
#define mk_sl_flt_defd_cuiba_mul4_wrap_wi_smol mk_lang_concat(mk_sl_flt_defd_cuiba, _mul4_wrap_wi_smol)
#define mk_sl_flt_defd_cuiba_to_str_dec_n mk_lang_concat(mk_sl_flt_defd_cuiba, _to_str_dec_n)

#define mk_sl_cui_name mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), bigb)
#define mk_sl_cui_base_type mk_sl_flt_defd_bui_t
#define mk_sl_cui_base_name mk_lang_concat(mk_lang_bui_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))
#define mk_sl_cui_base_bits (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)
#define mk_sl_cui_count mk_lang_div_roundup(mk_sl_flt_defd_need_bits_b, mk_sl_cui_base_bits)
#define mk_sl_cui_endian mk_lang_endian_little
#define mk_sl_cui_base_is_bui 1
#define mk_sl_cui_base_bui_tn mk_sl_flt_defd_bui_tn
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#define mk_sl_flt_defd_cuibb mk_lang_concat(mk_sl_cui_, mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), bigb))
#define mk_sl_flt_defd_cuibb_t mk_lang_concat(mk_sl_flt_defd_cuibb, _t)
#define mk_sl_flt_defd_cuibb_is_zero mk_lang_concat(mk_sl_flt_defd_cuibb, _is_zero)
#define mk_sl_flt_defd_cuibb_shl2 mk_lang_concat(mk_sl_flt_defd_cuibb, _shl2)
#define mk_sl_flt_defd_cuibb_mul4_wrap_wi_smol mk_lang_concat(mk_sl_flt_defd_cuibb, _mul4_wrap_wi_smol)

#define mk_sl_cui_convert_a_name mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name)
#define mk_sl_cui_convert_a_base_type mk_sl_flt_defd_bui_t
#define mk_sl_cui_convert_a_base_name mk_lang_concat(mk_lang_bui_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))
#define mk_sl_cui_convert_a_base_bits (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)
#define mk_sl_cui_convert_a_count mk_lang_div_roundup(mk_sl_flt_defd_bits, (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit))
#define mk_sl_cui_convert_a_endian mk_lang_endian_little
#define mk_sl_cui_convert_a_base_is_bui 1
#define mk_sl_cui_convert_a_base_bui_tn mk_sl_flt_defd_bui_tn
#define mk_sl_cui_convert_b_name mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), biga)
#define mk_sl_cui_convert_b_base_type mk_sl_flt_defd_bui_t
#define mk_sl_cui_convert_b_base_name mk_lang_concat(mk_lang_bui_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))
#define mk_sl_cui_convert_b_base_bits (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)
#define mk_sl_cui_convert_b_count mk_lang_div_roundup(mk_sl_flt_defd_need_bits_a, (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit))
#define mk_sl_cui_convert_b_endian mk_lang_endian_little
#define mk_sl_cui_convert_b_base_is_bui 1
#define mk_sl_cui_convert_b_base_bui_tn mk_sl_flt_defd_bui_tn
#include "mk_sl_cui_convert_inl_fileh.h"
#include "mk_sl_cui_convert_inl_filec.h"
#define mk_sl_flt_defd_convert_to_biga mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_convert_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name)), _to_), mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), biga))

#define mk_sl_cui_convert_a_name mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), biga)
#define mk_sl_cui_convert_a_base_type mk_sl_flt_defd_bui_t
#define mk_sl_cui_convert_a_base_name mk_lang_concat(mk_lang_bui_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))
#define mk_sl_cui_convert_a_base_bits (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)
#define mk_sl_cui_convert_a_count mk_lang_div_roundup(mk_sl_flt_defd_need_bits_a, (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit))
#define mk_sl_cui_convert_a_endian mk_lang_endian_little
#define mk_sl_cui_convert_a_base_is_bui 1
#define mk_sl_cui_convert_a_base_bui_tn mk_sl_flt_defd_bui_tn
#define mk_sl_cui_convert_b_name mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name)
#define mk_sl_cui_convert_b_base_type mk_sl_flt_defd_bui_t
#define mk_sl_cui_convert_b_base_name mk_lang_concat(mk_lang_bui_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))
#define mk_sl_cui_convert_b_base_bits (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)
#define mk_sl_cui_convert_b_count mk_lang_div_roundup(mk_sl_flt_defd_bits, (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit))
#define mk_sl_cui_convert_b_endian mk_lang_endian_little
#define mk_sl_cui_convert_b_base_is_bui 1
#define mk_sl_cui_convert_b_base_bui_tn mk_sl_flt_defd_bui_tn
#include "mk_sl_cui_convert_inl_fileh.h"
#include "mk_sl_cui_convert_inl_filec.h"
#define mk_sl_flt_defd_convert_to_num mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_convert_, mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), biga)), _to_), mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))

#define mk_sl_cui_convert_a_name mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name)
#define mk_sl_cui_convert_a_base_type mk_sl_flt_defd_bui_t
#define mk_sl_cui_convert_a_base_name mk_lang_concat(mk_lang_bui_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))
#define mk_sl_cui_convert_a_base_bits (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)
#define mk_sl_cui_convert_a_count mk_lang_div_roundup(mk_sl_flt_defd_bits, (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit))
#define mk_sl_cui_convert_a_endian mk_lang_endian_little
#define mk_sl_cui_convert_a_base_is_bui 1
#define mk_sl_cui_convert_a_base_bui_tn mk_sl_flt_defd_bui_tn
#define mk_sl_cui_convert_b_name mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), bigb)
#define mk_sl_cui_convert_b_base_type mk_sl_flt_defd_bui_t
#define mk_sl_cui_convert_b_base_name mk_lang_concat(mk_lang_bui_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name))
#define mk_sl_cui_convert_b_base_bits (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)
#define mk_sl_cui_convert_b_count mk_lang_div_roundup(mk_sl_flt_defd_need_bits_b, (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit))
#define mk_sl_cui_convert_b_endian mk_lang_endian_little
#define mk_sl_cui_convert_b_base_is_bui 1
#define mk_sl_cui_convert_b_base_bui_tn mk_sl_flt_defd_bui_tn
#include "mk_sl_cui_convert_inl_fileh.h"
#include "mk_sl_cui_convert_inl_filec.h"
#define mk_sl_flt_defd_convert_to_bigb mk_lang_concat(mk_lang_concat(mk_lang_concat(mk_sl_cui_convert_, mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name)), _to_), mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), bigb))
