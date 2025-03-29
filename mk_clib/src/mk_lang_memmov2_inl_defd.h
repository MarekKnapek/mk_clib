#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lang_memmov2_t_name) && \
	(defined mk_lang_memmov2_t_tn) && \
1))
#error xxxxxxxxxx
#endif


#define mk_lang_memmov2_inl_defd_name mk_lang_memmov2_t_name
#define mk_lang_memmov2_inl_defd_tn mk_lang_memmov2_t_tn


#define mk_lang_memmov2_inl_defd_type_t mk_lang_concat(mk_lang_memmov2_inl_defd_tn, _t)
#define mk_lang_memmov2_inl_defd_type_ct mk_lang_concat(mk_lang_memmov2_inl_defd_tn, _ct)
#define mk_lang_memmov2_inl_defd_type_pt mk_lang_concat(mk_lang_memmov2_inl_defd_tn, _pt)
#define mk_lang_memmov2_inl_defd_type_pct mk_lang_concat(mk_lang_memmov2_inl_defd_tn, _pct)

#define mk_lang_memmov2_inl_defd_fn mk_lang_concat(mk_lang_memmov2_inl_defd_name, _fn)
