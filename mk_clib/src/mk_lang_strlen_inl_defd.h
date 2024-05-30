#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lang_strlen_t_name) && \
	(defined mk_lang_strlen_t_type) && \
1))
#error xxxxxxxxxx
#endif


#define mk_lang_strlen_inl_defd_name mk_lang_strlen_t_name
#define mk_lang_strlen_inl_defd_type mk_lang_strlen_t_type


#define mk_lang_strlen_inl_defd_type_t mk_lang_concat(mk_lang_strlen_inl_defd_name, _type_t)
#define mk_lang_strlen_inl_defd_type_ct mk_lang_concat(mk_lang_strlen_inl_defd_name, _type_ct)
#define mk_lang_strlen_inl_defd_type_pt mk_lang_concat(mk_lang_strlen_inl_defd_name, _type_pt)
#define mk_lang_strlen_inl_defd_type_pct mk_lang_concat(mk_lang_strlen_inl_defd_name, _type_pct)

#define mk_lang_strlen_inl_defd_fn mk_lang_concat(mk_lang_strlen_inl_defd_name, _fn)
