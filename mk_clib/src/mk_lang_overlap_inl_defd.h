#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lang_overlap_t_name) && \
	(defined mk_lang_overlap_t_base) && \
	1))
#error xxxxxxxxxx
#endif


#define mk_lang_overlap_inl_defd_name mk_lang_overlap_t_name
#define mk_lang_overlap_inl_defd_base mk_lang_overlap_t_base


#define mk_lang_overlap_inl_defd_prct mk_lang_concat(mk_lang_overlap_inl_defd_base, _prct)

#define mk_lang_overlap_inl_defd_fn mk_lang_concat(mk_lang_overlap_inl_defd_name, _fn)
