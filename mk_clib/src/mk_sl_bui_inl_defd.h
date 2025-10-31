#include "mk_lang_charbit.h"
#include "mk_lang_concat.h"


#if(!( \
	(defined mk_sl_bui_t_name) && \
1))
#error xxxxxxxxxx
#endif


#define mk_sl_bui_inl_defd_name mk_sl_bui_t_name


#define mk_sl_bui_inl_defd_base_name mk_lang_concat(mk_lang_bui_, mk_sl_bui_inl_defd_name)

#define mk_sl_bui_inl_defd_base_t mk_lang_concat(mk_sl_bui_inl_defd_base_name, _t)
#define mk_sl_bui_inl_defd_base_ct mk_lang_concat(mk_sl_bui_inl_defd_base_name, _ct)
#define mk_sl_bui_inl_defd_base_pt mk_lang_concat(mk_sl_bui_inl_defd_base_name, _pt)
#define mk_sl_bui_inl_defd_base_pct mk_lang_concat(mk_sl_bui_inl_defd_base_name, _pct)

#define mk_sl_bui_inl_defd_base_from_buis_uchar_le mk_lang_concat(mk_sl_bui_inl_defd_base_name, _from_buis_uchar_le)
#define mk_sl_bui_inl_defd_base_from_buis_uchar_be mk_lang_concat(mk_sl_bui_inl_defd_base_name, _from_buis_uchar_be)
#define mk_sl_bui_inl_defd_base_from_buis_uchar_ne mk_lang_concat(mk_sl_bui_inl_defd_base_name, _from_buis_uchar_ne)


#define mk_sl_bui_inl_defd_count ((mk_lang_concat(mk_lang_concat(mk_lang_bui_, mk_sl_bui_inl_defd_name), _size_bits_d)) / mk_lang_charbit)

#define mk_sl_bui_inl_defd_prefix mk_lang_concat(mk_sl_bui_, mk_sl_bui_inl_defd_name)

#define mk_sl_bui_inl_defd_convertor_data_u mk_lang_concat(mk_sl_bui_inl_defd_prefix, _convertor_data_u)
#define mk_sl_bui_inl_defd_convertor_data_t mk_lang_concat(mk_sl_bui_inl_defd_prefix, _convertor_data_t)
#define mk_sl_bui_inl_defd_convertor_s mk_lang_concat(mk_sl_bui_inl_defd_prefix, _convertor_s)
#define mk_sl_bui_inl_defd_convertor_t mk_lang_concat(mk_sl_bui_inl_defd_prefix, _convertor_t)

#define mk_sl_bui_inl_defd_pr_from_uint8s_le mk_lang_concat(mk_sl_bui_inl_defd_prefix, _pr_from_uint8s_le)
#define mk_sl_bui_inl_defd_pr_from_uint8s_be mk_lang_concat(mk_sl_bui_inl_defd_prefix, _pr_from_uint8s_be)
#define mk_sl_bui_inl_defd_pr_from_uint8s_ne mk_lang_concat(mk_sl_bui_inl_defd_prefix, _pr_from_uint8s_ne)

#define mk_sl_bui_inl_defd_from_uint8s_le mk_lang_concat(mk_sl_bui_inl_defd_prefix, _from_uint8s_le)
#define mk_sl_bui_inl_defd_from_uint8s_be mk_lang_concat(mk_sl_bui_inl_defd_prefix, _from_uint8s_be)
#define mk_sl_bui_inl_defd_from_uint8s_ne mk_lang_concat(mk_sl_bui_inl_defd_prefix, _from_uint8s_ne)
