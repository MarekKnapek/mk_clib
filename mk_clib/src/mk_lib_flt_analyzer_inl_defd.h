#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lib_flt_analyzer_t_name) && \
	(defined mk_lib_flt_analyzer_t_flt_bits && (mk_lib_flt_analyzer_t_flt_bits) >= 1 && (mk_lib_flt_analyzer_t_flt_bits) <= 1 * 1024 * 1024) && \
	(defined mk_lib_flt_analyzer_t_flt_frac && (mk_lib_flt_analyzer_t_flt_frac) >= 1 && (1 + 1 + (mk_lib_flt_analyzer_t_flt_frac)) <= (mk_lib_flt_analyzer_t_flt_bits)) && \
	(defined mk_lib_flt_analyzer_t_uint) && \
	(defined mk_lib_flt_analyzer_t_lent) && \
	(defined mk_lib_flt_analyzer_t_expuint) && \
	(defined mk_lib_flt_analyzer_t_mtsuint) && \
	(defined mk_lib_flt_analyzer_t_mtslent) && \
	(1) \
))
#error xxxxxxxxxx
#endif


#define mk_lib_flt_analyzer_inl_defd_name mk_lib_flt_analyzer_t_name
#define mk_lib_flt_analyzer_inl_defd_flt_bits (mk_lib_flt_analyzer_t_flt_bits)
#define mk_lib_flt_analyzer_inl_defd_flt_frac (mk_lib_flt_analyzer_t_flt_frac)
#define mk_lib_flt_analyzer_inl_defd_flt_expb (mk_lib_flt_analyzer_inl_defd_flt_bits - 1 - mk_lib_flt_analyzer_inl_defd_flt_frac)
#define mk_lib_flt_analyzer_inl_defd_uint mk_lib_flt_analyzer_t_uint
#define mk_lib_flt_analyzer_inl_defd_lent mk_lib_flt_analyzer_t_lent
#define mk_lib_flt_analyzer_inl_defd_expuint mk_lib_flt_analyzer_t_expuint
#define mk_lib_flt_analyzer_inl_defd_mtsuint mk_lib_flt_analyzer_t_mtsuint
#define mk_lib_flt_analyzer_inl_defd_mtslent mk_lib_flt_analyzer_t_mtslent

#define mk_lib_flt_analyzer_inl_defd_prefix mk_lib_flt_analyzer_inl_defd_name

#define mk_lib_flt_analyzer_inl_defd_s mk_lang_concat(mk_lib_flt_analyzer_inl_defd_prefix, _s)
#define mk_lib_flt_analyzer_inl_defd_t mk_lang_concat(mk_lib_flt_analyzer_inl_defd_prefix, _t)
#define mk_lib_flt_analyzer_inl_defd_ct mk_lang_concat(mk_lib_flt_analyzer_inl_defd_prefix, _ct)
#define mk_lib_flt_analyzer_inl_defd_pt mk_lang_concat(mk_lib_flt_analyzer_inl_defd_prefix, _pt)
#define mk_lib_flt_analyzer_inl_defd_pct mk_lang_concat(mk_lib_flt_analyzer_inl_defd_prefix, _pct)

#define mk_lib_flt_analyzer_inl_defd_symbols mk_lang_concat(mk_lib_flt_analyzer_inl_defd_prefix, _symbols)

#define mk_lib_flt_analyzer_inl_defd_analyze_mts mk_lang_concat(mk_lib_flt_analyzer_inl_defd_prefix, _analyze_mts)
#define mk_lib_flt_analyzer_inl_defd_analyze mk_lang_concat(mk_lib_flt_analyzer_inl_defd_prefix, _analyze)

#define mk_lib_flt_analyzer_inl_defd_uint_t mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _t)
#define mk_lib_flt_analyzer_inl_defd_uint_pct mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _pct)
#define mk_lib_flt_analyzer_inl_defd_uint_strlenbin_v mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _strlenbin_v)
#define mk_lib_flt_analyzer_inl_defd_uint_strlenhex_v mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _strlenhex_v)
#define mk_lib_flt_analyzer_inl_defd_uint_strlendec_v mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _strlendec_v)
#define mk_lib_flt_analyzer_inl_defd_uint_to_str_binf_n mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _to_str_binf_n)
#define mk_lib_flt_analyzer_inl_defd_uint_to_str_hexf_n mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _to_str_hexf_n)
#define mk_lib_flt_analyzer_inl_defd_uint_to_str_dec_n mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _to_str_dec_n)
#define mk_lib_flt_analyzer_inl_defd_uint_shr3 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _shr3)
#define mk_lib_flt_analyzer_inl_defd_uint_has_lsb mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _has_lsb)
#define mk_lib_flt_analyzer_inl_defd_uint_not2 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _not2)
#define mk_lib_flt_analyzer_inl_defd_uint_inc1 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _inc1)
#define mk_lib_flt_analyzer_inl_defd_uint_shl3 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _shl3)
#define mk_lib_flt_analyzer_inl_defd_uint_shr2 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _shr2)
#define mk_lib_flt_analyzer_inl_defd_uint_to_buis_uint_le mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _to_buis_uint_le)
#define mk_lib_flt_analyzer_inl_defd_uint_is_zero mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _is_zero)
#define mk_lib_flt_analyzer_inl_defd_uint_from_bi_sint mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _from_bi_sint)
#define mk_lib_flt_analyzer_inl_defd_uint_mul4_wrap_wi mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _mul4_wrap_wi)
#define mk_lib_flt_analyzer_inl_defd_uint_to_bi_sint mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _to_bi_sint)
#define mk_lib_flt_analyzer_inl_defd_uint_from_buis_uchar_le mk_lang_concat(mk_lib_flt_analyzer_inl_defd_uint, _from_buis_uchar_le)


#define mk_lib_flt_analyzer_inl_defd_lent_t mk_lang_concat(mk_lib_flt_analyzer_inl_defd_lent, _t)
#define mk_lib_flt_analyzer_inl_defd_lent_pt mk_lang_concat(mk_lib_flt_analyzer_inl_defd_lent, _pt)
#define mk_lib_flt_analyzer_inl_defd_lent_set_zero mk_lang_concat(mk_lib_flt_analyzer_inl_defd_lent, _set_zero)
#define mk_lib_flt_analyzer_inl_defd_lent_inc1 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_lent, _inc1)
#define mk_lib_flt_analyzer_inl_defd_lent_from_bi_sint mk_lang_concat(mk_lib_flt_analyzer_inl_defd_lent, _from_bi_sint)
#define mk_lib_flt_analyzer_inl_defd_lent_to_buis_uchar_le mk_lang_concat(mk_lib_flt_analyzer_inl_defd_lent, _to_buis_uchar_le)

#define mk_lib_flt_analyzer_inl_defd_expuint_t mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _t)
#define mk_lib_flt_analyzer_inl_defd_expuint_strlenbin_v mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _strlenbin_v)
#define mk_lib_flt_analyzer_inl_defd_expuint_strlenhex_v mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _strlenhex_v)
#define mk_lib_flt_analyzer_inl_defd_expuint_strlendec_v mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _strlendec_v)
#define mk_lib_flt_analyzer_inl_defd_expuint_from_buis_uint_le mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _from_buis_uint_le)
#define mk_lib_flt_analyzer_inl_defd_expuint_to_str_binf_n mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _to_str_binf_n)
#define mk_lib_flt_analyzer_inl_defd_expuint_to_str_hexf_n mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _to_str_hexf_n)
#define mk_lib_flt_analyzer_inl_defd_expuint_to_str_dec_n mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _to_str_dec_n)
#define mk_lib_flt_analyzer_inl_defd_expuint_set_mask mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _set_mask)
#define mk_lib_flt_analyzer_inl_defd_expuint_shr1 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _shr1)
#define mk_lib_flt_analyzer_inl_defd_expuint_dec1 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _dec1)
#define mk_lib_flt_analyzer_inl_defd_expuint_shr2 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _shr2)
#define mk_lib_flt_analyzer_inl_defd_expuint_sub3_wrap_cid_cod mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _sub3_wrap_cid_cod)
#define mk_lib_flt_analyzer_inl_defd_expuint_shr3 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _shr3)
#define mk_lib_flt_analyzer_inl_defd_expuint_is_zero mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _is_zero)
#define mk_lib_flt_analyzer_inl_defd_expuint_eq mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _eq)
#define mk_lib_flt_analyzer_inl_defd_expuint_has_lsb mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _has_lsb)
#define mk_lib_flt_analyzer_inl_defd_expuint_not2 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _not2)
#define mk_lib_flt_analyzer_inl_defd_expuint_inc1 mk_lang_concat(mk_lib_flt_analyzer_inl_defd_expuint, _inc1)

#define mk_lib_flt_analyzer_inl_defd_mtsuint_t mk_lang_concat(mk_lib_flt_analyzer_inl_defd_mtsuint, _t)
#define mk_lib_flt_analyzer_inl_defd_mtsuint_strlenbin_v mk_lang_concat(mk_lib_flt_analyzer_inl_defd_mtsuint, _strlenbin_v)
#define mk_lib_flt_analyzer_inl_defd_mtsuint_strlenhex_v mk_lang_concat(mk_lib_flt_analyzer_inl_defd_mtsuint, _strlenhex_v)
#define mk_lib_flt_analyzer_inl_defd_mtsuint_strlendec_v mk_lang_concat(mk_lib_flt_analyzer_inl_defd_mtsuint, _strlendec_v)

#define mk_lib_flt_analyzer_inl_defd_mtslent_t mk_lang_concat(mk_lib_flt_analyzer_inl_defd_mtslent, _t)
#define mk_lib_flt_analyzer_inl_defd_mtslent_from_bi_sint mk_lang_concat(mk_lib_flt_analyzer_inl_defd_mtslent, _from_bi_sint)
#define mk_lib_flt_analyzer_inl_defd_mtslent_to_buis_uchar_le mk_lang_concat(mk_lib_flt_analyzer_inl_defd_mtslent, _to_buis_uchar_le)
