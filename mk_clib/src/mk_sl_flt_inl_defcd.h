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
#define mk_sl_flt_defd_has_bits_b (mk_lang_div_roundup(mk_sl_flt_defd_need_bits_b, (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit)) * (mk_sl_flt_defd_bui_sizeof * mk_lang_charbit))


#define mk_sl_flt_defd_buiname mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), _bui)
#define mk_lang_bui_t_name mk_sl_flt_defd_buiname
#define mk_lang_bui_t_base mk_sl_flt_defd_bui_tn
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_flt_defd_cui mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), _cui)
#define mk_sl_cui_t_name mk_sl_flt_defd_cui
#define mk_sl_cui_t_base mk_sl_flt_defd_buiname
#define mk_sl_cui_t_count mk_lang_div_roundup(mk_sl_flt_defd_bits, mk_sl_flt_defd_bui_bits)
#define mk_sl_cui_t_endian mk_lang_endian_little
#define mk_sl_cui_t_base_sizebits_d mk_sl_flt_defd_bui_bits
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#define mk_sl_flt_defd_cui_t mk_lang_concat(mk_sl_flt_defd_cui, _t)
#define mk_sl_flt_defd_cui_to_bi_sint mk_lang_concat(mk_sl_flt_defd_cui, _to_bi_sint)
#define mk_sl_flt_defd_cui_to_buis_uint_le mk_lang_concat(mk_sl_flt_defd_cui, _to_buis_uint_le)
#define mk_sl_flt_defd_cui_from_buis_uchar_le mk_lang_concat(mk_sl_flt_defd_cui, _from_buis_uchar_le)
#define mk_sl_flt_defd_cui_set_bit mk_lang_concat(mk_sl_flt_defd_cui, _set_bit)
#define mk_sl_flt_defd_cui_set_mask mk_lang_concat(mk_sl_flt_defd_cui, _set_mask)
#define mk_sl_flt_defd_cui_is_zero mk_lang_concat(mk_sl_flt_defd_cui, _is_zero)
#define mk_sl_flt_defd_cui_or2 mk_lang_concat(mk_sl_flt_defd_cui, _or2)
#define mk_sl_flt_defd_cui_and3 mk_lang_concat(mk_sl_flt_defd_cui, _and3)
#define mk_sl_flt_defd_cui_and2 mk_lang_concat(mk_sl_flt_defd_cui, _and2)
#define mk_sl_flt_defd_cui_shr3 mk_lang_concat(mk_sl_flt_defd_cui, _shr3)

#define mk_sl_flt_defd_cuiba mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), _biga_cui)
#define mk_sl_cui_t_name mk_sl_flt_defd_cuiba
#define mk_sl_cui_t_base mk_sl_flt_defd_buiname
#define mk_sl_cui_t_count mk_lang_div_roundup(mk_sl_flt_defd_need_bits_a, mk_sl_flt_defd_bui_bits)
#define mk_sl_cui_t_endian mk_lang_endian_little
#define mk_sl_cui_t_base_sizebits_d mk_sl_flt_defd_bui_bits
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#define mk_sl_flt_defd_cuiba_t mk_lang_concat(mk_sl_flt_defd_cuiba, _t)
#define mk_sl_flt_defd_cuiba_from_buis_uint_le mk_lang_concat(mk_sl_flt_defd_cuiba, _from_buis_uint_le)
#define mk_sl_flt_defd_cuiba_shl2 mk_lang_concat(mk_sl_flt_defd_cuiba, _shl2)
#define mk_sl_flt_defd_cuiba_shr2 mk_lang_concat(mk_sl_flt_defd_cuiba, _shr2)
#define mk_sl_flt_defd_cuiba_to_str_dec_n mk_lang_concat(mk_sl_flt_defd_cuiba, _to_str_dec_n)

#define mk_sl_flt_defd_cuibb mk_lang_concat(mk_lang_concat(mk_sl_flt_, mk_sl_flt_defd_name), _bigb_cui)
#define mk_sl_cui_t_name mk_sl_flt_defd_cuibb
#define mk_sl_cui_t_base mk_sl_flt_defd_buiname
#define mk_sl_cui_t_count mk_lang_div_roundup(mk_sl_flt_defd_need_bits_b, mk_sl_flt_defd_bui_bits)
#define mk_sl_cui_t_endian mk_lang_endian_little
#define mk_sl_cui_t_base_sizebits_d mk_sl_flt_defd_bui_bits
#include "mk_sl_cui_inl_fileh.h"
#include "mk_sl_cui_inl_filec.h"
#define mk_sl_flt_defd_cuibb_t mk_lang_concat(mk_sl_flt_defd_cuibb, _t)
#define mk_sl_flt_defd_cuibb_from_bi_uint mk_lang_concat(mk_sl_flt_defd_cuibb, _from_bi_uint)
#define mk_sl_flt_defd_cuibb_to_bi_uint mk_lang_concat(mk_sl_flt_defd_cuibb, _to_bi_uint)
#define mk_sl_flt_defd_cuibb_from_buis_uint_le mk_lang_concat(mk_sl_flt_defd_cuibb, _from_buis_uint_le)
#define mk_sl_flt_defd_cuibb_is_zero mk_lang_concat(mk_sl_flt_defd_cuibb, _is_zero)
#define mk_sl_flt_defd_cuibb_shl2 mk_lang_concat(mk_sl_flt_defd_cuibb, _shl2)
#define mk_sl_flt_defd_cuibb_mul4_wrap_wi mk_lang_concat(mk_sl_flt_defd_cuibb, _mul4_wrap_wi)

#define mk_sl_flt_defd_convert_to_biga mk_lang_concat(mk_sl_flt_defd_name, _convert_to_biga)
#define mk_sl_flt_defd_convert_to_bigb mk_lang_concat(mk_sl_flt_defd_name, _convert_to_bigb)
