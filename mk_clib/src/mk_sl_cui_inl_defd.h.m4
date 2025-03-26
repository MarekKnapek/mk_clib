include(`mk_sl_cui_inl.m')dnl
#include "mk_lang_concat.h"
#include "mk_lang_endian.h"
#include "mk_lang_flatten.h"
#include "mk_lang_forceinline.h"
#include "mk_lang_roundup.h"
#include "mk_lang_str_style.h"


#if(!( \
	(defined mk_sl_cui_t_name) && \
	(defined mk_sl_cui_t_base) && \
	(defined mk_sl_cui_t_count && (mk_sl_cui_t_count) >= 1 && (mk_sl_cui_t_count) <= 16 * 1024) && \
	((defined mk_sl_cui_t_endian && ((mk_sl_cui_t_endian) == mk_lang_endian_little || (mk_sl_cui_t_endian) == mk_lang_endian_big)) || !defined mk_sl_cui_t_endian) && \
	((defined mk_sl_cui_t_str_style && ((mk_sl_cui_t_str_style) == mk_lang_str_style_table || (mk_sl_cui_t_str_style) == mk_lang_str_style_arithmetic || (mk_sl_cui_t_str_style) == mk_lang_str_style_arithmetic_if_possible)) || !defined mk_sl_cui_t_str_style) && \
	((defined mk_sl_cui_t_disable_big_div && ((mk_sl_cui_t_disable_big_div) == 0 || (mk_sl_cui_t_disable_big_div) == 1)) || !defined mk_sl_cui_t_disable_big_div) && \
	((defined mk_sl_cui_t_base_size_bits_d && (mk_sl_cui_t_base_size_bits_d) >= 1) || !defined mk_sl_cui_t_base_size_bits_d) && \
	((defined mk_sl_cui_t_inline && ((mk_sl_cui_t_inline) == 0 || (mk_sl_cui_t_inline) == 1)) || !defined mk_sl_cui_t_inline) && \
1))
#error xxxxxxxxxx
#endif


#define mk_sl_cui_inl_defd_name mk_sl_cui_t_name
#define mk_sl_cui_inl_defd_base mk_sl_cui_t_base
#define mk_sl_cui_inl_defd_count (mk_sl_cui_t_count)


#if defined mk_sl_cui_t_endian
#define mk_sl_cui_inl_defd_endian (mk_sl_cui_t_endian)
#else
#define mk_sl_cui_inl_defd_endian mk_lang_endian_native
#endif

#if defined mk_sl_cui_t_str_style
#define mk_sl_cui_inl_defd_str_style (mk_sl_cui_t_str_style)
#else
#define mk_sl_cui_inl_defd_str_style mk_lang_str_style_arithmetic_if_possible
#endif

#if defined mk_sl_cui_t_disable_big_div
#define mk_sl_cui_inl_defd_disable_big_div (mk_sl_cui_t_disable_big_div)
#else
#define mk_sl_cui_inl_defd_disable_big_div 0
#endif

#if defined mk_sl_cui_t_base_size_bits_d
#define mk_sl_cui_inl_defd_base_size_bits_d (mk_sl_cui_t_base_size_bits_d)
#else
#define mk_sl_cui_inl_defd_base_size_bits_d mk_lang_concat(mk_sl_cui_inl_defd_base, _size_bits_d)
#endif

#if defined mk_sl_cui_t_inline
#define mk_sl_cui_inl_defd_inline (mk_sl_cui_t_inline)
#else
#define mk_sl_cui_inl_defd_inline 0
#endif


#if mk_sl_cui_inl_defd_inline
#define mk_sl_cui_inl_defd_flatten mk_lang_flatten
#define mk_sl_cui_inl_defd_forceinline mk_lang_forceinline
#else
#define mk_sl_cui_inl_defd_flatten
#define mk_sl_cui_inl_defd_forceinline
#endif


#define mk_sl_cui_inl_defd_base_t mk_lang_concat(mk_sl_cui_inl_defd_base, _t)
#define mk_sl_cui_inl_defd_base_ct mk_lang_concat(mk_sl_cui_inl_defd_base, _ct)
#define mk_sl_cui_inl_defd_base_pt mk_lang_concat(mk_sl_cui_inl_defd_base, _pt)
#define mk_sl_cui_inl_defd_base_pct mk_lang_concat(mk_sl_cui_inl_defd_base, _pct)
#define mk_sl_cui_inl_defd_base_prt mk_lang_concat(mk_sl_cui_inl_defd_base, _prt)
#define mk_sl_cui_inl_defd_base_prct mk_lang_concat(mk_sl_cui_inl_defd_base, _prct)

#define mk_sl_cui_inl_defd_base_from_base mk_lang_concat(mk_sl_cui_inl_defd_base, _from_base)
mm_per_bi(`#define mk_sl_cui_inl_defd_base_from_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_base, _from_bi_$1)')
#define mk_sl_cui_inl_defd_base_to_base mk_lang_concat(mk_sl_cui_inl_defd_base, _to_base)
mm_per_bi(`#define mk_sl_cui_inl_defd_base_to_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_base, _to_bi_$1)')
mm_per_bui(`#define mk_sl_cui_inl_defd_base_from_buis_$1_le mk_lang_concat(mk_sl_cui_inl_defd_base, _from_buis_$1_le)')
mm_per_bui(`#define mk_sl_cui_inl_defd_base_to_buis_$1_le mk_lang_concat(mk_sl_cui_inl_defd_base, _to_buis_$1_le)')
mm_per_bui(`#define mk_sl_cui_inl_defd_base_from_buis_$1_be mk_lang_concat(mk_sl_cui_inl_defd_base, _from_buis_$1_be)')
mm_per_bui(`#define mk_sl_cui_inl_defd_base_to_buis_$1_be mk_lang_concat(mk_sl_cui_inl_defd_base, _to_buis_$1_be)')
#define mk_sl_cui_inl_defd_base_assign mk_lang_concat(mk_sl_cui_inl_defd_base, _assign)
#define mk_sl_cui_inl_defd_base_set_zero mk_lang_concat(mk_sl_cui_inl_defd_base, _set_zero)
#define mk_sl_cui_inl_defd_base_set_max mk_lang_concat(mk_sl_cui_inl_defd_base, _set_max)
#define mk_sl_cui_inl_defd_base_set_one mk_lang_concat(mk_sl_cui_inl_defd_base, _set_one)
#define mk_sl_cui_inl_defd_base_set_two mk_lang_concat(mk_sl_cui_inl_defd_base, _set_two)
#define mk_sl_cui_inl_defd_base_set_bit mk_lang_concat(mk_sl_cui_inl_defd_base, _set_bit)
#define mk_sl_cui_inl_defd_base_set_mask mk_lang_concat(mk_sl_cui_inl_defd_base, _set_mask)
#define mk_sl_cui_inl_defd_base_count_leading_zeros mk_lang_concat(mk_sl_cui_inl_defd_base, _count_leading_zeros)
#define mk_sl_cui_inl_defd_base_count_leading_ones mk_lang_concat(mk_sl_cui_inl_defd_base, _count_leading_ones)
#define mk_sl_cui_inl_defd_base_count_trailing_zeros mk_lang_concat(mk_sl_cui_inl_defd_base, _count_trailing_zeros)
#define mk_sl_cui_inl_defd_base_count_trailing_ones mk_lang_concat(mk_sl_cui_inl_defd_base, _count_trailing_ones)
#define mk_sl_cui_inl_defd_base_count_ones mk_lang_concat(mk_sl_cui_inl_defd_base, _count_ones)
#define mk_sl_cui_inl_defd_base_count_zeros mk_lang_concat(mk_sl_cui_inl_defd_base, _count_zeros)
#define mk_sl_cui_inl_defd_base_has_lsb mk_lang_concat(mk_sl_cui_inl_defd_base, _has_lsb)
#define mk_sl_cui_inl_defd_base_is_zero mk_lang_concat(mk_sl_cui_inl_defd_base, _is_zero)
#define mk_sl_cui_inl_defd_base_is_one mk_lang_concat(mk_sl_cui_inl_defd_base, _is_one)
#define mk_sl_cui_inl_defd_base_is_two mk_lang_concat(mk_sl_cui_inl_defd_base, _is_two)
#define mk_sl_cui_inl_defd_base_is_max mk_lang_concat(mk_sl_cui_inl_defd_base, _is_max)
#define mk_sl_cui_inl_defd_base_eq mk_lang_concat(mk_sl_cui_inl_defd_base, _eq)
#define mk_sl_cui_inl_defd_base_ne mk_lang_concat(mk_sl_cui_inl_defd_base, _ne)
#define mk_sl_cui_inl_defd_base_lt mk_lang_concat(mk_sl_cui_inl_defd_base, _lt)
#define mk_sl_cui_inl_defd_base_le mk_lang_concat(mk_sl_cui_inl_defd_base, _le)
#define mk_sl_cui_inl_defd_base_gt mk_lang_concat(mk_sl_cui_inl_defd_base, _gt)
#define mk_sl_cui_inl_defd_base_ge mk_lang_concat(mk_sl_cui_inl_defd_base, _ge)
#define mk_sl_cui_inl_defd_base_cmp mk_lang_concat(mk_sl_cui_inl_defd_base, _cmp)
#define mk_sl_cui_inl_defd_base_inc2 mk_lang_concat(mk_sl_cui_inl_defd_base, _inc2)
#define mk_sl_cui_inl_defd_base_dec2 mk_lang_concat(mk_sl_cui_inl_defd_base, _dec2)
#define mk_sl_cui_inl_defd_base_inc1 mk_lang_concat(mk_sl_cui_inl_defd_base, _inc1)
#define mk_sl_cui_inl_defd_base_dec1 mk_lang_concat(mk_sl_cui_inl_defd_base, _dec1)
#define mk_sl_cui_inl_defd_base_not2 mk_lang_concat(mk_sl_cui_inl_defd_base, _not2)
#define mk_sl_cui_inl_defd_base_or3 mk_lang_concat(mk_sl_cui_inl_defd_base, _or3)
#define mk_sl_cui_inl_defd_base_and3 mk_lang_concat(mk_sl_cui_inl_defd_base, _and3)
#define mk_sl_cui_inl_defd_base_xor3 mk_lang_concat(mk_sl_cui_inl_defd_base, _xor3)
#define mk_sl_cui_inl_defd_base_not1 mk_lang_concat(mk_sl_cui_inl_defd_base, _not1)
#define mk_sl_cui_inl_defd_base_or2 mk_lang_concat(mk_sl_cui_inl_defd_base, _or2)
#define mk_sl_cui_inl_defd_base_and2 mk_lang_concat(mk_sl_cui_inl_defd_base, _and2)
#define mk_sl_cui_inl_defd_base_xor2 mk_lang_concat(mk_sl_cui_inl_defd_base, _xor2)
#define mk_sl_cui_inl_defd_base_shl3 mk_lang_concat(mk_sl_cui_inl_defd_base, _shl3)
#define mk_sl_cui_inl_defd_base_shr3 mk_lang_concat(mk_sl_cui_inl_defd_base, _shr3)
#define mk_sl_cui_inl_defd_base_rotl3 mk_lang_concat(mk_sl_cui_inl_defd_base, _rotl3)
#define mk_sl_cui_inl_defd_base_rotr3 mk_lang_concat(mk_sl_cui_inl_defd_base, _rotr3)
#define mk_sl_cui_inl_defd_base_shl2 mk_lang_concat(mk_sl_cui_inl_defd_base, _shl2)
#define mk_sl_cui_inl_defd_base_shr2 mk_lang_concat(mk_sl_cui_inl_defd_base, _shr2)
#define mk_sl_cui_inl_defd_base_rotl2 mk_lang_concat(mk_sl_cui_inl_defd_base, _rotl2)
#define mk_sl_cui_inl_defd_base_rotr2 mk_lang_concat(mk_sl_cui_inl_defd_base, _rotr2)
#define mk_sl_cui_inl_defd_base_would_overflow_add_cc mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_add_cc)
#define mk_sl_cui_inl_defd_base_would_overflow_add_cs mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_add_cs)
#define mk_sl_cui_inl_defd_base_would_overflow_add_cp mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_add_cp)
#define mk_sl_cui_inl_defd_base_would_overflow_sub_cc mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_sub_cc)
#define mk_sl_cui_inl_defd_base_would_overflow_sub_cs mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_sub_cs)
#define mk_sl_cui_inl_defd_base_would_overflow_sub_cp mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_sub_cp)
#define mk_sl_cui_inl_defd_base_would_overflow_mul mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_mul)
#define mk_sl_cui_inl_defd_base_add3_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_base, _add3_wrap_cid_cod)
#define mk_sl_cui_inl_defd_base_add3_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_base, _add3_wrap_cid_coe)
#define mk_sl_cui_inl_defd_base_add3_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_base, _add3_wrap_cie_cod)
#define mk_sl_cui_inl_defd_base_add3_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_base, _add3_wrap_cie_coe)
#define mk_sl_cui_inl_defd_base_add2_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_base, _add2_wrap_cid_cod)
#define mk_sl_cui_inl_defd_base_add2_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_base, _add2_wrap_cid_coe)
#define mk_sl_cui_inl_defd_base_add2_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_base, _add2_wrap_cie_cod)
#define mk_sl_cui_inl_defd_base_add2_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_base, _add2_wrap_cie_coe)
#define mk_sl_cui_inl_defd_base_sub3_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_base, _sub3_wrap_cid_cod)
#define mk_sl_cui_inl_defd_base_sub3_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_base, _sub3_wrap_cid_coe)
#define mk_sl_cui_inl_defd_base_sub3_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_base, _sub3_wrap_cie_cod)
#define mk_sl_cui_inl_defd_base_sub3_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_base, _sub3_wrap_cie_coe)
#define mk_sl_cui_inl_defd_base_sub2_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_base, _sub2_wrap_cid_cod)
#define mk_sl_cui_inl_defd_base_sub2_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_base, _sub2_wrap_cid_coe)
#define mk_sl_cui_inl_defd_base_sub2_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_base, _sub2_wrap_cie_cod)
#define mk_sl_cui_inl_defd_base_sub2_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_base, _sub2_wrap_cie_coe)
#define mk_sl_cui_inl_defd_base_mul3_wrap_lo mk_lang_concat(mk_sl_cui_inl_defd_base, _mul3_wrap_lo)
#define mk_sl_cui_inl_defd_base_mul3_wrap_hi mk_lang_concat(mk_sl_cui_inl_defd_base, _mul3_wrap_hi)
#define mk_sl_cui_inl_defd_base_mul4_wrap_wi mk_lang_concat(mk_sl_cui_inl_defd_base, _mul4_wrap_wi)
#define mk_sl_cui_inl_defd_base_mul2_wrap_lo mk_lang_concat(mk_sl_cui_inl_defd_base, _mul2_wrap_lo)
#define mk_sl_cui_inl_defd_base_mul2_wrap_hi mk_lang_concat(mk_sl_cui_inl_defd_base, _mul2_wrap_hi)
#define mk_sl_cui_inl_defd_base_mul2_wrap_wi mk_lang_concat(mk_sl_cui_inl_defd_base, _mul2_wrap_wi)
#define mk_sl_cui_inl_defd_base_div3_wrap mk_lang_concat(mk_sl_cui_inl_defd_base, _div3_wrap)
#define mk_sl_cui_inl_defd_base_mod3_wrap mk_lang_concat(mk_sl_cui_inl_defd_base, _mod3_wrap)
#define mk_sl_cui_inl_defd_base_divmod4_wrap mk_lang_concat(mk_sl_cui_inl_defd_base, _divmod4_wrap)
#define mk_sl_cui_inl_defd_base_div2_wrap mk_lang_concat(mk_sl_cui_inl_defd_base, _div2_wrap)
#define mk_sl_cui_inl_defd_base_mod2_wrap mk_lang_concat(mk_sl_cui_inl_defd_base, _mod2_wrap)
#define mk_sl_cui_inl_defd_base_divmod2_wrap mk_lang_concat(mk_sl_cui_inl_defd_base, _divmod2_wrap)
#define mk_sl_cui_inl_defd_base_to_str_bin_n mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_bin_n)
#define mk_sl_cui_inl_defd_base_to_str_bin_w mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_bin_w)
#define mk_sl_cui_inl_defd_base_from_str_bin_n mk_lang_concat(mk_sl_cui_inl_defd_base, _from_str_bin_n)
#define mk_sl_cui_inl_defd_base_from_str_bin_w mk_lang_concat(mk_sl_cui_inl_defd_base, _from_str_bin_w)
#define mk_sl_cui_inl_defd_base_to_str_oct_n mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_oct_n)
#define mk_sl_cui_inl_defd_base_to_str_oct_w mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_oct_w)
#define mk_sl_cui_inl_defd_base_from_str_oct_n mk_lang_concat(mk_sl_cui_inl_defd_base, _from_str_oct_n)
#define mk_sl_cui_inl_defd_base_from_str_oct_w mk_lang_concat(mk_sl_cui_inl_defd_base, _from_str_oct_w)
#define mk_sl_cui_inl_defd_base_to_str_dec_n mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_dec_n)
#define mk_sl_cui_inl_defd_base_to_str_dec_w mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_dec_w)
#define mk_sl_cui_inl_defd_base_from_str_dec_n mk_lang_concat(mk_sl_cui_inl_defd_base, _from_str_dec_n)
#define mk_sl_cui_inl_defd_base_from_str_dec_w mk_lang_concat(mk_sl_cui_inl_defd_base, _from_str_dec_w)
#define mk_sl_cui_inl_defd_base_to_str_hex_n mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_hex_n)
#define mk_sl_cui_inl_defd_base_to_str_hex_w mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_hex_w)
#define mk_sl_cui_inl_defd_base_from_str_hex_n mk_lang_concat(mk_sl_cui_inl_defd_base, _from_str_hex_n)
#define mk_sl_cui_inl_defd_base_from_str_hex_w mk_lang_concat(mk_sl_cui_inl_defd_base, _from_str_hex_w)
#define mk_sl_cui_inl_defd_base_to_str_binf_n mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_binf_n)
#define mk_sl_cui_inl_defd_base_to_str_binf_w mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_binf_w)
#define mk_sl_cui_inl_defd_base_to_str_hexf_n mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_hexf_n)
#define mk_sl_cui_inl_defd_base_to_str_hexf_w mk_lang_concat(mk_sl_cui_inl_defd_base, _to_str_hexf_w)


#if mk_sl_cui_inl_defd_endian == mk_lang_endian_little
#define mk_sl_cui_inl_defd_idx(idx) ((idx))
#elif mk_sl_cui_inl_defd_endian == mk_lang_endian_big
#define mk_sl_cui_inl_defd_idx(idx) (((mk_sl_cui_inl_defd_count) - 1) - (idx))
#else
#error xxxxxxxxxx
#endif

#define mk_sl_cui_inl_defd_s mk_lang_concat(mk_sl_cui_inl_defd_name, _s)
#define mk_sl_cui_inl_defd_t mk_lang_concat(mk_sl_cui_inl_defd_name, _t)
#define mk_sl_cui_inl_defd_ct mk_lang_concat(mk_sl_cui_inl_defd_name, _ct)
#define mk_sl_cui_inl_defd_pt mk_lang_concat(mk_sl_cui_inl_defd_name, _pt)
#define mk_sl_cui_inl_defd_pct mk_lang_concat(mk_sl_cui_inl_defd_name, _pct)
#define mk_sl_cui_inl_defd_prt mk_lang_concat(mk_sl_cui_inl_defd_name, _prt)
#define mk_sl_cui_inl_defd_prct mk_lang_concat(mk_sl_cui_inl_defd_name, _prct)
#define mk_sl_cui_inl_defd_ppt mk_lang_concat(mk_sl_cui_inl_defd_name, _ppt)
#define mk_sl_cui_inl_defd_ppct mk_lang_concat(mk_sl_cui_inl_defd_name, _ppct)
#define mk_sl_cui_inl_defd_pprt mk_lang_concat(mk_sl_cui_inl_defd_name, _pprt)
#define mk_sl_cui_inl_defd_pprct mk_lang_concat(mk_sl_cui_inl_defd_name, _pprct)

#define mk_sl_cui_inl_defd_size_bits_d (mk_sl_cui_inl_defd_count * mk_sl_cui_inl_defd_base_size_bits_d)
#define mk_sl_cui_inl_defd_size_bits_e mk_lang_concat(mk_sl_cui_inl_defd_name, _size_bits_e)
#define mk_sl_cui_inl_defd_size_bits_t mk_lang_concat(mk_sl_cui_inl_defd_name, _size_bits_t)
#define mk_sl_cui_inl_defd_size_bits_v mk_lang_concat(mk_sl_cui_inl_defd_name, _size_bits_v)

#define mk_sl_cui_inl_defd_size_bytes_d (mk_lang_roundup_div((mk_sl_cui_inl_defd_size_bits_d), (mk_lang_charbit)))
#define mk_sl_cui_inl_defd_size_bytes_e mk_lang_concat(mk_sl_cui_inl_defd_name, _size_bytes_e)
#define mk_sl_cui_inl_defd_size_bytes_t mk_lang_concat(mk_sl_cui_inl_defd_name, _size_bytes_t)
#define mk_sl_cui_inl_defd_size_bytes_v mk_lang_concat(mk_sl_cui_inl_defd_name, _size_bytes_v)

#define mk_sl_cui_inl_defd_strlen_dec_log 19728ul /* floor(log10(2) * (2^16)) */

#define mk_sl_cui_inl_defd_strlen_bin_d mk_sl_cui_inl_defd_size_bits_d
#define mk_sl_cui_inl_defd_strlen_bin_e mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_bin_e)
#define mk_sl_cui_inl_defd_strlen_bin_t mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_bin_t)
#define mk_sl_cui_inl_defd_strlen_bin_v mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_bin_v)

#define mk_sl_cui_inl_defd_strlen_oct_d mk_lang_roundup_div(mk_sl_cui_inl_defd_size_bits_d, 3)
#define mk_sl_cui_inl_defd_strlen_oct_e mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_oct_e)
#define mk_sl_cui_inl_defd_strlen_oct_t mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_oct_t)
#define mk_sl_cui_inl_defd_strlen_oct_v mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_oct_v)

#define mk_sl_cui_inl_defd_strlen_dec_d (((mk_sl_cui_inl_defd_size_bits_d * mk_sl_cui_inl_defd_strlen_dec_log) >> 16) + 1)
#define mk_sl_cui_inl_defd_strlen_dec_e mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_dec_e)
#define mk_sl_cui_inl_defd_strlen_dec_t mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_dec_t)
#define mk_sl_cui_inl_defd_strlen_dec_v mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_dec_v)

#define mk_sl_cui_inl_defd_strlen_hex_d mk_lang_roundup_div(mk_sl_cui_inl_defd_size_bits_d, 4)
#define mk_sl_cui_inl_defd_strlen_hex_e mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_hex_e)
#define mk_sl_cui_inl_defd_strlen_hex_t mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_hex_t)
#define mk_sl_cui_inl_defd_strlen_hex_v mk_lang_concat(mk_sl_cui_inl_defd_name, _strlen_hex_v)

#define mk_sl_cui_inl_defd_symbols_bin_a mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_bin_a)
#define mk_sl_cui_inl_defd_symbols_bin_b mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_bin_b)
#define mk_sl_cui_inl_defd_symbols_bin_c mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_bin_c)
#define mk_sl_cui_inl_defd_symbols_bin_d mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_bin_d)
#define mk_sl_cui_inl_defd_symbols_oct_a mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_oct_a)
#define mk_sl_cui_inl_defd_symbols_oct_b mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_oct_b)
#define mk_sl_cui_inl_defd_symbols_oct_c mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_oct_c)
#define mk_sl_cui_inl_defd_symbols_oct_d mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_oct_d)
#define mk_sl_cui_inl_defd_symbols_dec_a mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_dec_a)
#define mk_sl_cui_inl_defd_symbols_dec_b mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_dec_b)
#define mk_sl_cui_inl_defd_symbols_dec_c mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_dec_c)
#define mk_sl_cui_inl_defd_symbols_dec_d mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_dec_d)
#define mk_sl_cui_inl_defd_symbols_hex_a mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_a)
#define mk_sl_cui_inl_defd_symbols_hex_b mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_b)
#define mk_sl_cui_inl_defd_symbols_hex_c mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_c)
#define mk_sl_cui_inl_defd_symbols_hex_C mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_C)
#define mk_sl_cui_inl_defd_symbols_hex_d mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_d)
#define mk_sl_cui_inl_defd_symbols_hex_D mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_D)
#define mk_sl_cui_inl_defd_symbols_bin_e mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_bin_e)
#define mk_sl_cui_inl_defd_symbols_bin_f mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_bin_f)
#define mk_sl_cui_inl_defd_symbols_hex_e mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_e)
#define mk_sl_cui_inl_defd_symbols_hex_f mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_f)

#define mk_sl_cui_inl_defd_from_base mk_lang_concat(mk_sl_cui_inl_defd_name, _from_base)
mm_per_bi(`#define mk_sl_cui_inl_defd_from_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_name, _from_bi_$1)')
#define mk_sl_cui_inl_defd_to_base mk_lang_concat(mk_sl_cui_inl_defd_name, _to_base)
mm_per_bi(`#define mk_sl_cui_inl_defd_to_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_name, _to_bi_$1)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_le mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_le)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_le mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_le)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_be mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_be)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_be mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_be)')
#define mk_sl_cui_inl_defd_assign mk_lang_concat(mk_sl_cui_inl_defd_name, _assign)
#define mk_sl_cui_inl_defd_set_zero mk_lang_concat(mk_sl_cui_inl_defd_name, _set_zero)
#define mk_sl_cui_inl_defd_set_max mk_lang_concat(mk_sl_cui_inl_defd_name, _set_max)
#define mk_sl_cui_inl_defd_set_one mk_lang_concat(mk_sl_cui_inl_defd_name, _set_one)
#define mk_sl_cui_inl_defd_set_two mk_lang_concat(mk_sl_cui_inl_defd_name, _set_two)
#define mk_sl_cui_inl_defd_set_bit mk_lang_concat(mk_sl_cui_inl_defd_name, _set_bit)
#define mk_sl_cui_inl_defd_set_mask mk_lang_concat(mk_sl_cui_inl_defd_name, _set_mask)
#define mk_sl_cui_inl_defd_count_leading_zeros mk_lang_concat(mk_sl_cui_inl_defd_name, _count_leading_zeros)
#define mk_sl_cui_inl_defd_count_leading_ones mk_lang_concat(mk_sl_cui_inl_defd_name, _count_leading_ones)
#define mk_sl_cui_inl_defd_count_trailing_zeros mk_lang_concat(mk_sl_cui_inl_defd_name, _count_trailing_zeros)
#define mk_sl_cui_inl_defd_count_trailing_ones mk_lang_concat(mk_sl_cui_inl_defd_name, _count_trailing_ones)
#define mk_sl_cui_inl_defd_count_ones mk_lang_concat(mk_sl_cui_inl_defd_name, _count_ones)
#define mk_sl_cui_inl_defd_count_zeros mk_lang_concat(mk_sl_cui_inl_defd_name, _count_zeros)
#define mk_sl_cui_inl_defd_has_lsb mk_lang_concat(mk_sl_cui_inl_defd_name, _has_lsb)
#define mk_sl_cui_inl_defd_is_zero mk_lang_concat(mk_sl_cui_inl_defd_name, _is_zero)
#define mk_sl_cui_inl_defd_is_one mk_lang_concat(mk_sl_cui_inl_defd_name, _is_one)
#define mk_sl_cui_inl_defd_is_two mk_lang_concat(mk_sl_cui_inl_defd_name, _is_two)
#define mk_sl_cui_inl_defd_is_max mk_lang_concat(mk_sl_cui_inl_defd_name, _is_max)
#define mk_sl_cui_inl_defd_eq mk_lang_concat(mk_sl_cui_inl_defd_name, _eq)
#define mk_sl_cui_inl_defd_ne mk_lang_concat(mk_sl_cui_inl_defd_name, _ne)
#define mk_sl_cui_inl_defd_lt mk_lang_concat(mk_sl_cui_inl_defd_name, _lt)
#define mk_sl_cui_inl_defd_le mk_lang_concat(mk_sl_cui_inl_defd_name, _le)
#define mk_sl_cui_inl_defd_gt mk_lang_concat(mk_sl_cui_inl_defd_name, _gt)
#define mk_sl_cui_inl_defd_ge mk_lang_concat(mk_sl_cui_inl_defd_name, _ge)
#define mk_sl_cui_inl_defd_cmp mk_lang_concat(mk_sl_cui_inl_defd_name, _cmp)
#define mk_sl_cui_inl_defd_inc2 mk_lang_concat(mk_sl_cui_inl_defd_name, _inc2)
#define mk_sl_cui_inl_defd_dec2 mk_lang_concat(mk_sl_cui_inl_defd_name, _dec2)
#define mk_sl_cui_inl_defd_inc1 mk_lang_concat(mk_sl_cui_inl_defd_name, _inc1)
#define mk_sl_cui_inl_defd_dec1 mk_lang_concat(mk_sl_cui_inl_defd_name, _dec1)
#define mk_sl_cui_inl_defd_not2 mk_lang_concat(mk_sl_cui_inl_defd_name, _not2)
#define mk_sl_cui_inl_defd_or3 mk_lang_concat(mk_sl_cui_inl_defd_name, _or3)
#define mk_sl_cui_inl_defd_and3 mk_lang_concat(mk_sl_cui_inl_defd_name, _and3)
#define mk_sl_cui_inl_defd_xor3 mk_lang_concat(mk_sl_cui_inl_defd_name, _xor3)
#define mk_sl_cui_inl_defd_not1 mk_lang_concat(mk_sl_cui_inl_defd_name, _not1)
#define mk_sl_cui_inl_defd_or2 mk_lang_concat(mk_sl_cui_inl_defd_name, _or2)
#define mk_sl_cui_inl_defd_and2 mk_lang_concat(mk_sl_cui_inl_defd_name, _and2)
#define mk_sl_cui_inl_defd_xor2 mk_lang_concat(mk_sl_cui_inl_defd_name, _xor2)
#define mk_sl_cui_inl_defd_shl3 mk_lang_concat(mk_sl_cui_inl_defd_name, _shl3)
#define mk_sl_cui_inl_defd_shr3 mk_lang_concat(mk_sl_cui_inl_defd_name, _shr3)
#define mk_sl_cui_inl_defd_rotl3 mk_lang_concat(mk_sl_cui_inl_defd_name, _rotl3)
#define mk_sl_cui_inl_defd_rotr3 mk_lang_concat(mk_sl_cui_inl_defd_name, _rotr3)
#define mk_sl_cui_inl_defd_shl2 mk_lang_concat(mk_sl_cui_inl_defd_name, _shl2)
#define mk_sl_cui_inl_defd_shr2 mk_lang_concat(mk_sl_cui_inl_defd_name, _shr2)
#define mk_sl_cui_inl_defd_rotl2 mk_lang_concat(mk_sl_cui_inl_defd_name, _rotl2)
#define mk_sl_cui_inl_defd_rotr2 mk_lang_concat(mk_sl_cui_inl_defd_name, _rotr2)
#define mk_sl_cui_inl_defd_would_overflow_add_cc mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_add_cc)
#define mk_sl_cui_inl_defd_would_overflow_add_cs mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_add_cs)
#define mk_sl_cui_inl_defd_would_overflow_add_cp mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_add_cp)
#define mk_sl_cui_inl_defd_would_overflow_sub_cc mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_sub_cc)
#define mk_sl_cui_inl_defd_would_overflow_sub_cs mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_sub_cs)
#define mk_sl_cui_inl_defd_would_overflow_sub_cp mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_sub_cp)
#define mk_sl_cui_inl_defd_would_overflow_mul mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_mul)
#define mk_sl_cui_inl_defd_would_overflow_div mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_div)
#define mk_sl_cui_inl_defd_would_overflow_mod mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_mod)
#define mk_sl_cui_inl_defd_add3_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_name, _add3_wrap_cid_cod)
#define mk_sl_cui_inl_defd_add3_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_name, _add3_wrap_cid_coe)
#define mk_sl_cui_inl_defd_add3_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_name, _add3_wrap_cie_cod)
#define mk_sl_cui_inl_defd_add3_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_name, _add3_wrap_cie_coe)
#define mk_sl_cui_inl_defd_add2_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_name, _add2_wrap_cid_cod)
#define mk_sl_cui_inl_defd_add2_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_name, _add2_wrap_cid_coe)
#define mk_sl_cui_inl_defd_add2_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_name, _add2_wrap_cie_cod)
#define mk_sl_cui_inl_defd_add2_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_name, _add2_wrap_cie_coe)
#define mk_sl_cui_inl_defd_sub3_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_name, _sub3_wrap_cid_cod)
#define mk_sl_cui_inl_defd_sub3_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_name, _sub3_wrap_cid_coe)
#define mk_sl_cui_inl_defd_sub3_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_name, _sub3_wrap_cie_cod)
#define mk_sl_cui_inl_defd_sub3_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_name, _sub3_wrap_cie_coe)
#define mk_sl_cui_inl_defd_sub2_wrap_cid_cod mk_lang_concat(mk_sl_cui_inl_defd_name, _sub2_wrap_cid_cod)
#define mk_sl_cui_inl_defd_sub2_wrap_cid_coe mk_lang_concat(mk_sl_cui_inl_defd_name, _sub2_wrap_cid_coe)
#define mk_sl_cui_inl_defd_sub2_wrap_cie_cod mk_lang_concat(mk_sl_cui_inl_defd_name, _sub2_wrap_cie_cod)
#define mk_sl_cui_inl_defd_sub2_wrap_cie_coe mk_lang_concat(mk_sl_cui_inl_defd_name, _sub2_wrap_cie_coe)
#define mk_sl_cui_inl_defd_mul3_wrap_lo mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_lo)
#define mk_sl_cui_inl_defd_mul3_wrap_hi mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_hi)
#define mk_sl_cui_inl_defd_mul4_wrap_wi mk_lang_concat(mk_sl_cui_inl_defd_name, _mul4_wrap_wi)
#define mk_sl_cui_inl_defd_mul2_wrap_lo mk_lang_concat(mk_sl_cui_inl_defd_name, _mul2_wrap_lo)
#define mk_sl_cui_inl_defd_mul2_wrap_hi mk_lang_concat(mk_sl_cui_inl_defd_name, _mul2_wrap_hi)
#define mk_sl_cui_inl_defd_mul2_wrap_wi mk_lang_concat(mk_sl_cui_inl_defd_name, _mul2_wrap_wi)
#define mk_sl_cui_inl_defd_div3_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _div3_wrap)
#define mk_sl_cui_inl_defd_mod3_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _mod3_wrap)
#define mk_sl_cui_inl_defd_divmod4_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _divmod4_wrap)
#define mk_sl_cui_inl_defd_div2_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _div2_wrap)
#define mk_sl_cui_inl_defd_mod2_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _mod2_wrap)
#define mk_sl_cui_inl_defd_divmod2_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _divmod2_wrap)
#define mk_sl_cui_inl_defd_to_str_bin_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_bin_n)
#define mk_sl_cui_inl_defd_to_str_bin_w mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_bin_w)
#define mk_sl_cui_inl_defd_from_str_bin_n mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_bin_n)
#define mk_sl_cui_inl_defd_from_str_bin_w mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_bin_w)
#define mk_sl_cui_inl_defd_to_str_oct_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_oct_n)
#define mk_sl_cui_inl_defd_to_str_oct_w mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_oct_w)
#define mk_sl_cui_inl_defd_from_str_oct_n mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_oct_n)
#define mk_sl_cui_inl_defd_from_str_oct_w mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_oct_w)
#define mk_sl_cui_inl_defd_to_str_dec_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_dec_n)
#define mk_sl_cui_inl_defd_to_str_dec_w mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_dec_w)
#define mk_sl_cui_inl_defd_from_str_dec_n mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_n)
#define mk_sl_cui_inl_defd_from_str_dec_w mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_w)
#define mk_sl_cui_inl_defd_to_str_hex_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_hex_n)
#define mk_sl_cui_inl_defd_to_str_hex_w mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_hex_w)
#define mk_sl_cui_inl_defd_from_str_hex_n mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_hex_n)
#define mk_sl_cui_inl_defd_from_str_hex_w mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_hex_w)
#define mk_sl_cui_inl_defd_to_str_binf_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_binf_n)
#define mk_sl_cui_inl_defd_to_str_binf_w mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_binf_w)
#define mk_sl_cui_inl_defd_to_str_hexf_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_hexf_n)
#define mk_sl_cui_inl_defd_to_str_hexf_w mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_hexf_w)

#define mk_sl_cui_inl_defd_mul3_wrap_lo_restrict mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_lo_restrict)
#define mk_sl_cui_inl_defd_mul3_wrap_lo_alias mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_lo_alias)
#define mk_sl_cui_inl_defd_mul3_wrap_hi_restrict mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_hi_restrict)
#define mk_sl_cui_inl_defd_mul3_wrap_hi_alias mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_hi_alias)
#define mk_sl_cui_inl_defd_mul3_wrap_wi_restrict mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_wi_restrict)
#define mk_sl_cui_inl_defd_mul3_wrap_wi_alias mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_wi_alias)
#define mk_sl_cui_inl_defd_mul4_wrap_wi_restrict mk_lang_concat(mk_sl_cui_inl_defd_name, _mul4_wrap_wi_restrict)
#define mk_sl_cui_inl_defd_mul4_wrap_wi_alias mk_lang_concat(mk_sl_cui_inl_defd_name, _mul4_wrap_wi_alias)
#define mk_sl_cui_inl_defd_add2_wrap_cid_cod_smol mk_lang_concat(mk_sl_cui_inl_defd_name, _add2_wrap_cid_cod_smol)
#define mk_sl_cui_inl_defd_mul3_wrap_lo_smol mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_lo_smol)
#define mk_sl_cui_inl_defd_divmod4_wrap_smol mk_lang_concat(mk_sl_cui_inl_defd_name, _divmod4_wrap_smol)
#define mk_sl_cui_inl_defd_from_str_dec_border_base_impl mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_base_impl)
#define mk_sl_cui_inl_defd_from_str_dec_border_value_impl mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_value_impl)
#define mk_sl_cui_inl_defd_from_str_dec_border_digit_impl mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_digit_impl)
#define mk_sl_cui_inl_defd_from_str_dec_border_base mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_base)
#define mk_sl_cui_inl_defd_from_str_dec_border_value mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_value)
#define mk_sl_cui_inl_defd_from_str_dec_border_digit mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_digit)
#define mk_sl_cui_inl_defd_from_str_dec_border_base_val mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_base_val)
#define mk_sl_cui_inl_defd_from_str_dec_border_value_val mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_value_val)
#define mk_sl_cui_inl_defd_from_str_dec_border_digit_val mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_digit_val)
