#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lang_memall2_t_name) && \
	(defined mk_lang_memall2_t_tn) && \
1))
#error xxxxxxxxxx
#endif


#define mk_lang_memall2_inl_defd_name mk_lang_memall2_t_name
#define mk_lang_memall2_inl_defd_tn mk_lang_memall2_t_tn


#define mk_lang_memall2_inl_defd_memclr mk_lang_concat(mk_lang_memall2_inl_defd_name, _memclr)
#define mk_lang_memall2_inl_defd_memcmp mk_lang_concat(mk_lang_memall2_inl_defd_name, _memcmp)
#define mk_lang_memall2_inl_defd_memcpy mk_lang_concat(mk_lang_memall2_inl_defd_name, _memcpy)
#define mk_lang_memall2_inl_defd_memmov mk_lang_concat(mk_lang_memall2_inl_defd_name, _memmov)
#define mk_lang_memall2_inl_defd_memset mk_lang_concat(mk_lang_memall2_inl_defd_name, _memset)
