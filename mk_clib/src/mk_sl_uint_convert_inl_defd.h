#include "mk_lang_concat.h"
#include "mk_lang_endian.h"


#if(!( \
	(defined mk_sl_uint_convert_t_name) && \
	(defined mk_sl_uint_convert_t_big_tn) && \
	(defined mk_sl_uint_convert_t_sml_tn) && \
	(defined mk_sl_uint_convert_t_endian && ((mk_sl_uint_convert_t_endian) == mk_lang_endian_little || (mk_sl_uint_convert_t_endian) == mk_lang_endian_big)) && \
1))
#error xxxxxxxxxx
#endif


#define mk_sl_uint_convert_inl_defd_name mk_sl_uint_convert_t_name
#define mk_sl_uint_convert_inl_defd_big_tn mk_sl_uint_convert_t_big_tn
#define mk_sl_uint_convert_inl_defd_sml_tn mk_sl_uint_convert_t_sml_tn
#define mk_sl_uint_convert_inl_defd_endian (mk_sl_uint_convert_t_endian)


#define mk_sl_uint_convert_inl_defd_big_prefix mk_sl_uint_convert_inl_defd_big_tn

#define mk_sl_uint_convert_inl_defd_big_t mk_lang_concat(mk_sl_uint_convert_inl_defd_big_prefix, _t)
#define mk_sl_uint_convert_inl_defd_big_ct mk_lang_concat(mk_sl_uint_convert_inl_defd_big_prefix, _ct)
#define mk_sl_uint_convert_inl_defd_big_pt mk_lang_concat(mk_sl_uint_convert_inl_defd_big_prefix, _pt)
#define mk_sl_uint_convert_inl_defd_big_pct mk_lang_concat(mk_sl_uint_convert_inl_defd_big_prefix, _pct)

#define mk_sl_uint_convert_inl_defd_big_size_bits_v mk_lang_concat(mk_sl_uint_convert_inl_defd_big_prefix, _size_bits_v)
#define mk_sl_uint_convert_inl_defd_big_size_bytes_v mk_lang_concat(mk_sl_uint_convert_inl_defd_big_prefix, _size_bytes_v)

#define mk_sl_uint_convert_inl_defd_big_to_buis_uchar_le mk_lang_concat(mk_sl_uint_convert_inl_defd_big_prefix, _to_buis_uchar_le)
#define mk_sl_uint_convert_inl_defd_big_from_buis_uchar_le mk_lang_concat(mk_sl_uint_convert_inl_defd_big_prefix, _from_buis_uchar_le)


#define mk_sl_uint_convert_inl_defd_sml_prefix mk_sl_uint_convert_inl_defd_sml_tn

#define mk_sl_uint_convert_inl_defd_sml_t mk_lang_concat(mk_sl_uint_convert_inl_defd_sml_prefix, _t)
#define mk_sl_uint_convert_inl_defd_sml_ct mk_lang_concat(mk_sl_uint_convert_inl_defd_sml_prefix, _ct)
#define mk_sl_uint_convert_inl_defd_sml_pt mk_lang_concat(mk_sl_uint_convert_inl_defd_sml_prefix, _pt)
#define mk_sl_uint_convert_inl_defd_sml_pct mk_lang_concat(mk_sl_uint_convert_inl_defd_sml_prefix, _pct)

#define mk_sl_uint_convert_inl_defd_sml_size_bits_v mk_lang_concat(mk_sl_uint_convert_inl_defd_sml_prefix, _size_bits_v)
#define mk_sl_uint_convert_inl_defd_sml_size_bytes_v mk_lang_concat(mk_sl_uint_convert_inl_defd_sml_prefix, _size_bytes_v)

#define mk_sl_uint_convert_inl_defd_sml_to_buis_uchar_le mk_lang_concat(mk_sl_uint_convert_inl_defd_sml_prefix, _to_buis_uchar_le)
#define mk_sl_uint_convert_inl_defd_sml_from_buis_uchar_le mk_lang_concat(mk_sl_uint_convert_inl_defd_sml_prefix, _from_buis_uchar_le)


#define mk_sl_uint_convert_inl_defd_ratio_e mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _ratio_e)
#define mk_sl_uint_convert_inl_defd_ratio_v mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _ratio_v)
#define mk_sl_uint_convert_inl_defd_ratio_t mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _ratio_t)

#define mk_sl_uint_convert_inl_defd_converter_data_u mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _converter_data_u)
#define mk_sl_uint_convert_inl_defd_converter_data_t mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _converter_data_t)
#define mk_sl_uint_convert_inl_defd_converter_s mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _converter_s)
#define mk_sl_uint_convert_inl_defd_converter_t mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _converter_t)
#define mk_sl_uint_convert_inl_defd_converter_ct mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _converter_ct)
#define mk_sl_uint_convert_inl_defd_converter_pt mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _converter_pt)
#define mk_sl_uint_convert_inl_defd_converter_pct mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _converter_pct)

#define mk_sl_uint_convert_inl_defd_to_sml mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _to_sml)
#define mk_sl_uint_convert_inl_defd_to_big mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _to_big)
#define mk_sl_uint_convert_inl_defd_to_sml_multi mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _to_sml_multi)
#define mk_sl_uint_convert_inl_defd_to_big_multi mk_lang_concat(mk_sl_uint_convert_inl_defd_name, _to_big_multi)
