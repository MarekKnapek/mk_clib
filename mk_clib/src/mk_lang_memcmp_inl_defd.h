#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lang_memcmp_t_name) && \
	(defined mk_lang_memcmp_t_base) && \
	1))
#error xxxxxxxxxx
#endif


#define mk_lang_memcmp_inl_defd_name mk_lang_memcmp_t_name
#define mk_lang_memcmp_inl_defd_base mk_lang_memcmp_t_base


#define mk_lang_memcmp_inl_defd_pct mk_lang_concat(mk_lang_memcmp_inl_defd_base, _pct)
#define mk_lang_memcmp_inl_defd_eq mk_lang_concat(mk_lang_memcmp_inl_defd_base, _eq)

#define mk_lang_memcmp_inl_defd_fn mk_lang_concat(mk_lang_memcmp_inl_defd_name, _fn)
