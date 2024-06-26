include(`mk_sl_cui_inl.m')dnl
#include "mk_lang_attribute.h"
#include "mk_lang_concat.h"
#include "mk_lang_div_roundup.h"
#include "mk_lang_endian.h"


#if(!( \
	(defined mk_sl_cui_t_name) && \
	(defined mk_sl_cui_t_base) && \
	(defined mk_sl_cui_t_count && mk_sl_cui_t_count >= 1) && \
	((defined mk_sl_cui_t_endian && (mk_sl_cui_t_endian == mk_lang_endian_little || mk_sl_cui_t_endian == mk_lang_endian_big)) || !defined mk_sl_cui_t_endian) && \
	((defined mk_sl_cui_t_disable_big_div && (mk_sl_cui_t_disable_big_div == 0 || mk_sl_cui_t_disable_big_div == 1)) || !defined mk_sl_cui_t_disable_big_div) && \
	((defined mk_sl_cui_t_base_sizebits_d && mk_sl_cui_t_base_sizebits_d >= 1) || !defined mk_sl_cui_t_base_sizebits_d) && \
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
#define mk_sl_cui_inl_defd_endian mk_lang_endian_little
#endif
#if defined mk_sl_cui_t_inline
#define mk_sl_cui_inl_defd_inline (mk_sl_cui_t_inline)
#else
#define mk_sl_cui_inl_defd_inline 0
#endif


#if mk_sl_cui_inl_defd_inline
#define mk_sl_cui_inl_defd_flatten mk_lang_attribute_msvc_flatten
#define mk_sl_cui_inl_defd_forceinline mk_lang_attribute_msvc_forceinline
#else
#define mk_sl_cui_inl_defd_flatten
#define mk_sl_cui_inl_defd_forceinline
#endif


#define mk_sl_cui_inl_defd_base_t mk_lang_concat(mk_sl_cui_inl_defd_base, _t)
#define mk_sl_cui_inl_defd_base_ct mk_lang_concat(mk_sl_cui_inl_defd_base, _ct)
#define mk_sl_cui_inl_defd_base_pt mk_lang_concat(mk_sl_cui_inl_defd_base, _pt)
#define mk_sl_cui_inl_defd_base_prt mk_lang_concat(mk_sl_cui_inl_defd_base, _prt)
#define mk_sl_cui_inl_defd_base_pct mk_lang_concat(mk_sl_cui_inl_defd_base, _pct)
#define mk_sl_cui_inl_defd_base_prct mk_lang_concat(mk_sl_cui_inl_defd_base, _prct)

#if defined mk_sl_cui_t_disable_big_div
#define mk_sl_cui_inl_defd_disable_big_div mk_sl_cui_t_disable_big_div
#else
#define mk_sl_cui_inl_defd_disable_big_div 0
#endif

#if defined mk_sl_cui_t_base_sizebits_d
#define mk_sl_cui_inl_defd_base_sizebits_d mk_sl_cui_t_base_sizebits_d
#else
#define mk_sl_cui_inl_defd_base_sizebits_d mk_lang_concat(mk_sl_cui_inl_defd_base, _sizebits_d)
#endif

#define mk_sl_cui_inl_defd_base_from_base mk_lang_concat(mk_sl_cui_inl_defd_base, _from_base)
#define mk_sl_cui_inl_defd_base_from_bi_bool mk_lang_concat(mk_sl_cui_inl_defd_base, _from_bi_bool)
#define mk_sl_cui_inl_defd_base_from_bi_pchar mk_lang_concat(mk_sl_cui_inl_defd_base, _from_bi_pchar)
mm_per_bui(`#define mk_sl_cui_inl_defd_base_from_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_base, _from_bi_$1)')
mm_per_bsi(`#define mk_sl_cui_inl_defd_base_from_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_base, _from_bi_$1)')
#define mk_sl_cui_inl_defd_base_to_base mk_lang_concat(mk_sl_cui_inl_defd_base, _to_base)
#define mk_sl_cui_inl_defd_base_to_bi_bool mk_lang_concat(mk_sl_cui_inl_defd_base, _to_bi_bool)
#define mk_sl_cui_inl_defd_base_to_bi_pchar mk_lang_concat(mk_sl_cui_inl_defd_base, _to_bi_pchar)
mm_per_bui(`#define mk_sl_cui_inl_defd_base_to_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_base, _to_bi_$1)')
mm_per_bsi(`#define mk_sl_cui_inl_defd_base_to_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_base, _to_bi_$1)')
mm_per_bui(`#define mk_sl_cui_inl_defd_base_from_buis_$1_le mk_lang_concat(mk_sl_cui_inl_defd_base, _from_buis_$1_le)')
mm_per_bui(`#define mk_sl_cui_inl_defd_base_to_buis_$1_le mk_lang_concat(mk_sl_cui_inl_defd_base, _to_buis_$1_le)')
mm_per_bui(`#define mk_sl_cui_inl_defd_base_from_buis_$1_be mk_lang_concat(mk_sl_cui_inl_defd_base, _from_buis_$1_be)')
mm_per_bui(`#define mk_sl_cui_inl_defd_base_to_buis_$1_be mk_lang_concat(mk_sl_cui_inl_defd_base, _to_buis_$1_be)')
#define mk_sl_cui_inl_defd_base_assign mk_lang_concat(mk_sl_cui_inl_defd_base, _assign)
#define mk_sl_cui_inl_defd_base_set_zero mk_lang_concat(mk_sl_cui_inl_defd_base, _set_zero)
#define mk_sl_cui_inl_defd_base_set_max mk_lang_concat(mk_sl_cui_inl_defd_base, _set_max)
#define mk_sl_cui_inl_defd_base_set_one mk_lang_concat(mk_sl_cui_inl_defd_base, _set_one)
#define mk_sl_cui_inl_defd_base_set_bit mk_lang_concat(mk_sl_cui_inl_defd_base, _set_bit)
#define mk_sl_cui_inl_defd_base_set_mask mk_lang_concat(mk_sl_cui_inl_defd_base, _set_mask)
#define mk_sl_cui_inl_defd_base_count_leading_zeros mk_lang_concat(mk_sl_cui_inl_defd_base, _count_leading_zeros)
#define mk_sl_cui_inl_defd_base_count_leading_ones mk_lang_concat(mk_sl_cui_inl_defd_base, _count_leading_ones)
#define mk_sl_cui_inl_defd_base_count_trailing_zeros mk_lang_concat(mk_sl_cui_inl_defd_base, _count_trailing_zeros)
#define mk_sl_cui_inl_defd_base_count_trailing_ones mk_lang_concat(mk_sl_cui_inl_defd_base, _count_trailing_ones)
#define mk_sl_cui_inl_defd_base_count_zeros mk_lang_concat(mk_sl_cui_inl_defd_base, _count_zeros)
#define mk_sl_cui_inl_defd_base_count_ones mk_lang_concat(mk_sl_cui_inl_defd_base, _count_ones)
#define mk_sl_cui_inl_defd_base_has_lsb mk_lang_concat(mk_sl_cui_inl_defd_base, _has_lsb)
#define mk_sl_cui_inl_defd_base_is_zero mk_lang_concat(mk_sl_cui_inl_defd_base, _is_zero)
#define mk_sl_cui_inl_defd_base_is_one mk_lang_concat(mk_sl_cui_inl_defd_base, _is_one)
#define mk_sl_cui_inl_defd_base_is_max mk_lang_concat(mk_sl_cui_inl_defd_base, _is_max)
#define mk_sl_cui_inl_defd_base_eq mk_lang_concat(mk_sl_cui_inl_defd_base, _eq)
#define mk_sl_cui_inl_defd_base_ne mk_lang_concat(mk_sl_cui_inl_defd_base, _ne)
#define mk_sl_cui_inl_defd_base_lt mk_lang_concat(mk_sl_cui_inl_defd_base, _lt)
#define mk_sl_cui_inl_defd_base_le mk_lang_concat(mk_sl_cui_inl_defd_base, _le)
#define mk_sl_cui_inl_defd_base_gt mk_lang_concat(mk_sl_cui_inl_defd_base, _gt)
#define mk_sl_cui_inl_defd_base_ge mk_lang_concat(mk_sl_cui_inl_defd_base, _ge)
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
#define mk_sl_cui_inl_defd_base_would_overflow_add mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_add)
#define mk_sl_cui_inl_defd_base_would_overflow_sub_cc mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_sub_cc)
#define mk_sl_cui_inl_defd_base_would_overflow_sub_cs mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_sub_cs)
#define mk_sl_cui_inl_defd_base_would_overflow_sub mk_lang_concat(mk_sl_cui_inl_defd_base, _would_overflow_sub)
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


#define mk_sl_cui_inl_defd_strlendec_log 19728ul /* floor(log10(2) * (2^16)) */
#define mk_sl_cui_inl_defd_sizebits_d (mk_sl_cui_inl_defd_count * mk_sl_cui_inl_defd_base_sizebits_d)
#define mk_sl_cui_inl_defd_strlenbin_d mk_sl_cui_inl_defd_sizebits_d
#define mk_sl_cui_inl_defd_strlendec_d (((mk_sl_cui_inl_defd_sizebits_d * mk_sl_cui_inl_defd_strlendec_log) >> 16) + 1)
#define mk_sl_cui_inl_defd_strlenhex_d mk_lang_div_roundup(mk_sl_cui_inl_defd_sizebits_d, 4)

#if mk_sl_cui_inl_defd_endian == mk_lang_endian_little
#define mk_sl_cui_inl_defd_idx(idx) ((idx))
#elif mk_sl_cui_inl_defd_endian == mk_lang_endian_big
#define mk_sl_cui_inl_defd_idx(idx) ((mk_sl_cui_inl_defd_count - 1) - (idx))
#else
#error xxxxxxxxxx
#endif

#define mk_sl_cui_inl_defd_s mk_lang_concat(mk_sl_cui_inl_defd_name, _s)
#define mk_sl_cui_inl_defd_t mk_lang_concat(mk_sl_cui_inl_defd_name, _t)
#define mk_sl_cui_inl_defd_ct mk_lang_concat(mk_sl_cui_inl_defd_name, _ct)
#define mk_sl_cui_inl_defd_pt mk_lang_concat(mk_sl_cui_inl_defd_name, _pt)
#define mk_sl_cui_inl_defd_prt mk_lang_concat(mk_sl_cui_inl_defd_name, _prt)
#define mk_sl_cui_inl_defd_pct mk_lang_concat(mk_sl_cui_inl_defd_name, _pct)
#define mk_sl_cui_inl_defd_prct mk_lang_concat(mk_sl_cui_inl_defd_name, _prct)

#define mk_sl_cui_inl_defd_sizebits_e mk_lang_concat(mk_sl_cui_inl_defd_name, _sizebits_e)
#define mk_sl_cui_inl_defd_sizebits_t mk_lang_concat(mk_sl_cui_inl_defd_name, _sizebits_t)
#define mk_sl_cui_inl_defd_sizebits_v mk_lang_concat(mk_sl_cui_inl_defd_name, _sizebits_v)

#define mk_sl_cui_inl_defd_symbols_dec_a mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_dec_a)
#define mk_sl_cui_inl_defd_symbols_dec_b mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_dec_b)
#define mk_sl_cui_inl_defd_symbols_dec_c mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_dec_c)
#define mk_sl_cui_inl_defd_symbols_dec_d mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_dec_d)
#define mk_sl_cui_inl_defd_symbols_hex_a mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_a)
#define mk_sl_cui_inl_defd_symbols_hex_b mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_b)
#define mk_sl_cui_inl_defd_symbols_hex_c mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_c)
#define mk_sl_cui_inl_defd_symbols_hex_d mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_hex_d)
#define mk_sl_cui_inl_defd_symbols_bin_a mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_bin_a)
#define mk_sl_cui_inl_defd_symbols_bin_b mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_bin_b)
#define mk_sl_cui_inl_defd_symbols_bin_c mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_bin_c)
#define mk_sl_cui_inl_defd_symbols_bin_d mk_lang_concat(mk_sl_cui_inl_defd_name, _symbols_bin_d)

#define mk_sl_cui_inl_defd_strlenbin_e mk_lang_concat(mk_sl_cui_inl_defd_name, _strlenbin_e)
#define mk_sl_cui_inl_defd_strlenbin_t mk_lang_concat(mk_sl_cui_inl_defd_name, _strlenbin_t)
#define mk_sl_cui_inl_defd_strlenbin_v mk_lang_concat(mk_sl_cui_inl_defd_name, _strlenbin_v)
#define mk_sl_cui_inl_defd_strlendec_e mk_lang_concat(mk_sl_cui_inl_defd_name, _strlendec_e)
#define mk_sl_cui_inl_defd_strlendec_t mk_lang_concat(mk_sl_cui_inl_defd_name, _strlendec_t)
#define mk_sl_cui_inl_defd_strlendec_v mk_lang_concat(mk_sl_cui_inl_defd_name, _strlendec_v)
#define mk_sl_cui_inl_defd_strlenhex_e mk_lang_concat(mk_sl_cui_inl_defd_name, _strlenhex_e)
#define mk_sl_cui_inl_defd_strlenhex_t mk_lang_concat(mk_sl_cui_inl_defd_name, _strlenhex_t)
#define mk_sl_cui_inl_defd_strlenhex_v mk_lang_concat(mk_sl_cui_inl_defd_name, _strlenhex_v)

#define mk_sl_cui_inl_defd_from_base mk_lang_concat(mk_sl_cui_inl_defd_name, _from_base)
#define mk_sl_cui_inl_defd_from_bi_bool mk_lang_concat(mk_sl_cui_inl_defd_name, _from_bi_bool)
#define mk_sl_cui_inl_defd_from_bi_pchar mk_lang_concat(mk_sl_cui_inl_defd_name, _from_bi_pchar)
mm_per_bui(`#define mk_sl_cui_inl_defd_from_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_name, _from_bi_$1)')
mm_per_bsi(`#define mk_sl_cui_inl_defd_from_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_name, _from_bi_$1)')
#define mk_sl_cui_inl_defd_to_base mk_lang_concat(mk_sl_cui_inl_defd_name, _to_base)
#define mk_sl_cui_inl_defd_to_bi_bool mk_lang_concat(mk_sl_cui_inl_defd_name, _to_bi_bool)
#define mk_sl_cui_inl_defd_to_bi_pchar mk_lang_concat(mk_sl_cui_inl_defd_name, _to_bi_pchar)
mm_per_bui(`#define mk_sl_cui_inl_defd_to_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_name, _to_bi_$1)')
mm_per_bsi(`#define mk_sl_cui_inl_defd_to_bi_$1 mk_lang_concat(mk_sl_cui_inl_defd_name, _to_bi_$1)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_le_impl_one mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_le_impl_one)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_le_impl_same mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_le_impl_same)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_le_impl_bigger_int mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_le_impl_bigger_int)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_le_impl_smoler_int mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_le_impl_smoler_int)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_le mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_le)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_le_impl_one mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_le_impl_one)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_le_impl_same mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_le_impl_same)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_le_impl_bigger_int mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_le_impl_bigger_int)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_le_impl_smoler_int mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_le_impl_smoler_int)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_le mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_le)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_be_impl_one mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_be_impl_one)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_be_impl_same mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_be_impl_same)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_be_impl_bigger_int mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_be_impl_bigger_int)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_be_impl_smoler_int mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_be_impl_smoler_int)')
mm_per_bui(`#define mk_sl_cui_inl_defd_from_buis_$1_be mk_lang_concat(mk_sl_cui_inl_defd_name, _from_buis_$1_be)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_be_impl_one mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_be_impl_one)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_be_impl_same mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_be_impl_same)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_be_impl_bigger_int mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_be_impl_bigger_int)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_be_impl_smoler_int mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_be_impl_smoler_int)')
mm_per_bui(`#define mk_sl_cui_inl_defd_to_buis_$1_be mk_lang_concat(mk_sl_cui_inl_defd_name, _to_buis_$1_be)')
#define mk_sl_cui_inl_defd_assign mk_lang_concat(mk_sl_cui_inl_defd_name, _assign)
#define mk_sl_cui_inl_defd_set_zero mk_lang_concat(mk_sl_cui_inl_defd_name, _set_zero)
#define mk_sl_cui_inl_defd_set_max mk_lang_concat(mk_sl_cui_inl_defd_name, _set_max)
#define mk_sl_cui_inl_defd_set_one mk_lang_concat(mk_sl_cui_inl_defd_name, _set_one)
#define mk_sl_cui_inl_defd_set_bit mk_lang_concat(mk_sl_cui_inl_defd_name, _set_bit)
#define mk_sl_cui_inl_defd_set_mask mk_lang_concat(mk_sl_cui_inl_defd_name, _set_mask)
#define mk_sl_cui_inl_defd_count_leading_zeros mk_lang_concat(mk_sl_cui_inl_defd_name, _count_leading_zeros)
#define mk_sl_cui_inl_defd_count_leading_ones mk_lang_concat(mk_sl_cui_inl_defd_name, _count_leading_ones)
#define mk_sl_cui_inl_defd_count_trailing_zeros mk_lang_concat(mk_sl_cui_inl_defd_name, _count_trailing_zeros)
#define mk_sl_cui_inl_defd_count_trailing_ones mk_lang_concat(mk_sl_cui_inl_defd_name, _count_trailing_ones)
#define mk_sl_cui_inl_defd_count_zeros mk_lang_concat(mk_sl_cui_inl_defd_name, _count_zeros)
#define mk_sl_cui_inl_defd_count_ones mk_lang_concat(mk_sl_cui_inl_defd_name, _count_ones)
#define mk_sl_cui_inl_defd_has_lsb mk_lang_concat(mk_sl_cui_inl_defd_name, _has_lsb)
#define mk_sl_cui_inl_defd_is_zero mk_lang_concat(mk_sl_cui_inl_defd_name, _is_zero)
#define mk_sl_cui_inl_defd_is_one mk_lang_concat(mk_sl_cui_inl_defd_name, _is_one)
#define mk_sl_cui_inl_defd_is_max mk_lang_concat(mk_sl_cui_inl_defd_name, _is_max)
#define mk_sl_cui_inl_defd_eq mk_lang_concat(mk_sl_cui_inl_defd_name, _eq)
#define mk_sl_cui_inl_defd_ne mk_lang_concat(mk_sl_cui_inl_defd_name, _ne)
#define mk_sl_cui_inl_defd_lt mk_lang_concat(mk_sl_cui_inl_defd_name, _lt)
#define mk_sl_cui_inl_defd_le mk_lang_concat(mk_sl_cui_inl_defd_name, _le)
#define mk_sl_cui_inl_defd_gt mk_lang_concat(mk_sl_cui_inl_defd_name, _gt)
#define mk_sl_cui_inl_defd_ge mk_lang_concat(mk_sl_cui_inl_defd_name, _ge)
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
#define mk_sl_cui_inl_defd_would_overflow_add mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_add)
#define mk_sl_cui_inl_defd_would_overflow_sub_cc mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_sub_cc)
#define mk_sl_cui_inl_defd_would_overflow_sub_cs mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_sub_cs)
#define mk_sl_cui_inl_defd_would_overflow_sub mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_sub)
#define mk_sl_cui_inl_defd_would_overflow_mul mk_lang_concat(mk_sl_cui_inl_defd_name, _would_overflow_mul)
#define mk_sl_cui_inl_defd_add2_wrap_cid_cod_smol mk_lang_concat(mk_sl_cui_inl_defd_name, _add2_wrap_cid_cod_smol)
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
#define mk_sl_cui_inl_defd_mul3_wrap_lo_smol mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_lo_smol)
#define mk_sl_cui_inl_defd_mul3_wrap_lo mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_lo)
#define mk_sl_cui_inl_defd_mul3_wrap_hi mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_hi)
#define mk_sl_cui_inl_defd_mul4_wrap_wi mk_lang_concat(mk_sl_cui_inl_defd_name, _mul4_wrap_wi)
#define mk_sl_cui_inl_defd_mul4_wrap_wi_smol mk_lang_concat(mk_sl_cui_inl_defd_name, _mul4_wrap_wi_smol)
#define mk_sl_cui_inl_defd_mul2_wrap_lo mk_lang_concat(mk_sl_cui_inl_defd_name, _mul2_wrap_lo)
#define mk_sl_cui_inl_defd_mul2_wrap_hi mk_lang_concat(mk_sl_cui_inl_defd_name, _mul2_wrap_hi)
#define mk_sl_cui_inl_defd_mul2_wrap_wi mk_lang_concat(mk_sl_cui_inl_defd_name, _mul2_wrap_wi)
#define mk_sl_cui_inl_defd_div3_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _div3_wrap)
#define mk_sl_cui_inl_defd_mod3_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _mod3_wrap)
#define mk_sl_cui_inl_defd_divmod4_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _divmod4_wrap)
#define mk_sl_cui_inl_defd_divmod4_wrap_smol mk_lang_concat(mk_sl_cui_inl_defd_name, _divmod4_wrap_smol)
#define mk_sl_cui_inl_defd_div2_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _div2_wrap)
#define mk_sl_cui_inl_defd_mod2_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _mod2_wrap)
#define mk_sl_cui_inl_defd_divmod2_wrap mk_lang_concat(mk_sl_cui_inl_defd_name, _divmod2_wrap)
#define mk_sl_cui_inl_defd_to_str_dec_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_dec_n)
#define mk_sl_cui_inl_defd_to_str_dec_w mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_dec_w)
#define mk_sl_cui_inl_defd_from_str_dec_n mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_n)
#define mk_sl_cui_inl_defd_from_str_dec_w mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_w)
#define mk_sl_cui_inl_defd_to_str_hex_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_hex_n)
#define mk_sl_cui_inl_defd_to_str_hex_w mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_hex_w)
#define mk_sl_cui_inl_defd_to_str_hexf_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_hexf_n)
#define mk_sl_cui_inl_defd_to_str_bin_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_bin_n)
#define mk_sl_cui_inl_defd_to_str_binf_n mk_lang_concat(mk_sl_cui_inl_defd_name, _to_str_binf_n)

#define mk_sl_cui_inl_defd_mul3_wrap_lo_restrict mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_lo_restrict)
#define mk_sl_cui_inl_defd_mul3_wrap_lo_alias mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_lo_alias)
#define mk_sl_cui_inl_defd_mul3_wrap_hi_restrict mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_hi_restrict)
#define mk_sl_cui_inl_defd_mul3_wrap_hi_alias mk_lang_concat(mk_sl_cui_inl_defd_name, _mul3_wrap_hi_alias)
#define mk_sl_cui_inl_defd_mul4_wrap_wi_restrict mk_lang_concat(mk_sl_cui_inl_defd_name, _mul4_wrap_wi_restrict)
#define mk_sl_cui_inl_defd_mul4_wrap_wi_alias mk_lang_concat(mk_sl_cui_inl_defd_name, _mul4_wrap_wi_alias)
#define mk_sl_cui_inl_defd_from_str_dec_border_base_impl mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_base_impl)
#define mk_sl_cui_inl_defd_from_str_dec_border_value_impl mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_value_impl)
#define mk_sl_cui_inl_defd_from_str_dec_border_digit_impl mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_digit_impl)
#define mk_sl_cui_inl_defd_from_str_dec_border_base_val mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_base_val)
#define mk_sl_cui_inl_defd_from_str_dec_border_value_val mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_value_val)
#define mk_sl_cui_inl_defd_from_str_dec_border_digit_val mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_digit_val)
#define mk_sl_cui_inl_defd_from_str_dec_border_base mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_base)
#define mk_sl_cui_inl_defd_from_str_dec_border_value mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_value)
#define mk_sl_cui_inl_defd_from_str_dec_border_digit mk_lang_concat(mk_sl_cui_inl_defd_name, _from_str_dec_border_digit)
