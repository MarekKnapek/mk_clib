#include "mk_lang_concat.h"


#if(!( \
	(defined mk_lib_crypto_bitops_bulk_t_name) && \
	(defined mk_lib_crypto_bitops_bulk_t_tn) && \
	(defined mk_lib_crypto_bitops_bulk_t_count && (mk_lib_crypto_bitops_bulk_t_count) >= 1 && (mk_lib_crypto_bitops_bulk_t_count) <= 2 * 1024 * 1024) && \
1))
#error xxxxxxxxxx
#endif


#define mk_lib_crypto_bitops_bulk_inl_defd_name mk_lib_crypto_bitops_bulk_t_name
#define mk_lib_crypto_bitops_bulk_inl_defd_tn mk_lib_crypto_bitops_bulk_t_tn
#define mk_lib_crypto_bitops_bulk_inl_defd_count (mk_lib_crypto_bitops_bulk_t_count)


#define mk_lib_crypto_bitops_bulk_inl_defd_base_t mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_tn, _t)
#define mk_lib_crypto_bitops_bulk_inl_defd_base_ct mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_tn, _ct)
#define mk_lib_crypto_bitops_bulk_inl_defd_base_pt mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_tn, _pt)
#define mk_lib_crypto_bitops_bulk_inl_defd_base_pct mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_tn, _pct)

#define mk_lib_crypto_bitops_bulk_inl_defd_base_xor2 mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_tn, _xor2)
#define mk_lib_crypto_bitops_bulk_inl_defd_base_xor3 mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_tn, _xor3)
#define mk_lib_crypto_bitops_bulk_inl_defd_base_add2_wrap_cid_cod mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_tn, _add2_wrap_cid_cod)


#define mk_lib_crypto_bitops_bulk_inl_defd_t mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _t)
#define mk_lib_crypto_bitops_bulk_inl_defd_ct mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _ct)
#define mk_lib_crypto_bitops_bulk_inl_defd_pt mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _pt)
#define mk_lib_crypto_bitops_bulk_inl_defd_pct mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _pct)

#define mk_lib_crypto_bitops_bulk_inl_defd_memcpy mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _memcpy)
#define mk_lib_crypto_bitops_bulk_inl_defd_memclr mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _memclr)
#define mk_lib_crypto_bitops_bulk_inl_defd_xor2 mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _xor2)
#define mk_lib_crypto_bitops_bulk_inl_defd_xor3 mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _xor3)
#define mk_lib_crypto_bitops_bulk_inl_defd_add2_wrap_cid_cod mk_lang_concat(mk_lib_crypto_bitops_bulk_inl_defd_name, _add2_wrap_cid_cod)
