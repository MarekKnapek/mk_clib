include(`mk_lang_bui2_inl.m')dnl
#include "mk_lang_concat.h"


#if \
	!defined mk_lang_bui2_t_name || \
	!defined mk_lang_bui2_t_base || \
	0
xxxxxxxxxx
#endif


#define mk_lang_bui2_inl_defd_name mk_lang_bui2_t_name
#define mk_lang_bui2_inl_defd_base mk_lang_bui2_t_base

#define mk_lang_bui2_inl_defd_base_name mk_lang_concat(mk_lang_types_, mk_lang_bui2_inl_defd_base)

#define mk_lang_bui2_inl_defd_base_t mk_lang_concat(mk_lang_bui2_inl_defd_base_name, _t)
#define mk_lang_bui2_inl_defd_base_ct mk_lang_concat(mk_lang_bui2_inl_defd_base_name, _ct)
#define mk_lang_bui2_inl_defd_base_pt mk_lang_concat(mk_lang_bui2_inl_defd_base_name, _pt)
#define mk_lang_bui2_inl_defd_base_prt mk_lang_concat(mk_lang_bui2_inl_defd_base_name, _prt)
#define mk_lang_bui2_inl_defd_base_pct mk_lang_concat(mk_lang_bui2_inl_defd_base_name, _pct)
#define mk_lang_bui2_inl_defd_base_prct mk_lang_concat(mk_lang_bui2_inl_defd_base_name, _prct)


#define mk_lang_bui2_inl_defd_sizeof_d mk_lang_concat(mk_lang_concat(mk_lang_sizeof_bi_, mk_lang_bui2_inl_defd_base), _t)

#define mk_lang_bui2_inl_defd_t mk_lang_concat(mk_lang_bui2_inl_defd_name, _t)
#define mk_lang_bui2_inl_defd_ct mk_lang_concat(mk_lang_bui2_inl_defd_name, _ct)
#define mk_lang_bui2_inl_defd_pt mk_lang_concat(mk_lang_bui2_inl_defd_name, _pt)
#define mk_lang_bui2_inl_defd_prt mk_lang_concat(mk_lang_bui2_inl_defd_name, _prt)
#define mk_lang_bui2_inl_defd_pct mk_lang_concat(mk_lang_bui2_inl_defd_name, _pct)
#define mk_lang_bui2_inl_defd_prct mk_lang_concat(mk_lang_bui2_inl_defd_name, _prct)

#define mk_lang_bui2_inl_defd_sizeof_e mk_lang_concat(mk_lang_bui2_inl_defd_name, _sizeof_e)
#define mk_lang_bui2_inl_defd_sizeof_t mk_lang_concat(mk_lang_bui2_inl_defd_name, _sizeof_t)
#define mk_lang_bui2_inl_defd_sizeof_v mk_lang_concat(mk_lang_bui2_inl_defd_name, _sizeof_v)

#define mk_lang_bui2_inl_defd_from_base mk_lang_concat(mk_lang_bui2_inl_defd_name, _from_base)
mm_per_bi(`#define mk_lang_bui2_inl_defd_from_bi_$1 mk_lang_concat(mk_lang_bui2_inl_defd_name, _from_bi_$1)')dnl
#define mk_lang_bui2_inl_defd_to_base mk_lang_concat(mk_lang_bui2_inl_defd_name, _to_base)
mm_per_bi(`#define mk_lang_bui2_inl_defd_to_bi_$1 mk_lang_concat(mk_lang_bui2_inl_defd_name, _to_bi_$1)')dnl
mm_per_bui(`#define mk_lang_bui2_inl_defd_from_buis_$1_le mk_lang_concat(mk_lang_bui2_inl_defd_name, _from_buis_$1_le)')dnl
mm_per_bui(`#define mk_lang_bui2_inl_defd_to_buis_$1_le mk_lang_concat(mk_lang_bui2_inl_defd_name, _to_buis_$1_le)')dnl
mm_per_bui(`#define mk_lang_bui2_inl_defd_from_buis_$1_be mk_lang_concat(mk_lang_bui2_inl_defd_name, _from_buis_$1_be)')dnl
mm_per_bui(`#define mk_lang_bui2_inl_defd_to_buis_$1_be mk_lang_concat(mk_lang_bui2_inl_defd_name, _to_buis_$1_be)')dnl
