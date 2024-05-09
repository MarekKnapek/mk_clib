#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lang_swap_t_name) && \
	(defined mk_lang_swap_t_base) && \
	1))
#error xxxxxxxxxx
#endif


#define mk_lang_swap_inl_defd_name mk_lang_swap_t_name
#define mk_lang_swap_inl_defd_base mk_lang_swap_t_base


#define mk_lang_swap_inl_defd_t mk_lang_concat(mk_lang_swap_inl_defd_base, _t)
#define mk_lang_swap_inl_defd_prt mk_lang_concat(mk_lang_swap_inl_defd_base, _prt)

#define mk_lang_swap_inl_defd_fn mk_lang_concat(mk_lang_swap_inl_defd_name, _fn)
