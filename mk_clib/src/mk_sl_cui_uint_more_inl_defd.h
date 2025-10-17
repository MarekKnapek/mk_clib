#include "mk_lang_concat.h"


#if \
(!( \
	(defined mk_sl_cui_uint_more_t_name) && \
	(defined mk_sl_cui_uint_more_t_type && mk_sl_cui_uint_more_t_type >= 1 && mk_sl_cui_uint_more_t_type <= 1024) && \
	(defined mk_sl_cui_uint_more_t_count && (mk_sl_cui_uint_more_t_count) >= 1 && (mk_sl_cui_uint_more_t_count) <= 1024) && \
1))
#error xxxxxxxxxx
#endif


#define mk_sl_cui_uint_more_inl_defd_name mk_sl_cui_uint_more_t_name
#define mk_sl_cui_uint_more_inl_defd_type mk_sl_cui_uint_more_t_type
#define mk_sl_cui_uint_more_inl_defd_count (mk_sl_cui_uint_more_t_count)


#define mk_sl_cui_uint_more_inl_defd_type_t mk_lang_concat(mk_lang_concat(mk_sl_cui_uint, mk_sl_cui_uint_more_inl_defd_type), _t)
#define mk_sl_cui_uint_more_inl_defd_type_ct mk_lang_concat(mk_lang_concat(mk_sl_cui_uint, mk_sl_cui_uint_more_inl_defd_type), _ct)

#define mk_sl_cui_uint_more_inl_defd_xor2 mk_lang_concat(mk_sl_cui_uint_more_inl_defd_name, _xor2)
#define mk_sl_cui_uint_more_inl_defd_xor3 mk_lang_concat(mk_sl_cui_uint_more_inl_defd_name, _xor3)
