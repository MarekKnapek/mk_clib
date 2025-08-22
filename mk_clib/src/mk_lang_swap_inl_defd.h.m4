include(`mk_lang_typedef.m')dnl
#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lang_swap_t_name) && \
	(defined mk_lang_swap_t_type) && \
1))
#error xxxxxxxxxx
#endif


#define mk_lang_swap_inl_defd_name mk_lang_swap_t_name
#define mk_lang_swap_inl_defd_type mk_lang_swap_t_type


#define mk_lang_swap_inl_defd_element mk_lang_concat(mk_lang_swap_inl_defd_name, _element)
#define mk_lang_swap_inl_defd_element_t mk_lang_concat(mk_lang_swap_inl_defd_element, _t)
mm_per_typedef(`#define mk_lang_swap_inl_defd_element_$1 mk_lang_concat(mk_lang_swap_inl_defd_element, _$1)')


#define mk_lang_swap_inl_defd_fn mk_lang_concat(mk_lang_swap_inl_defd_name, _fn)
