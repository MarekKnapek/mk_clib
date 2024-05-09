#include "mk_lang_concat.h"


#if(!( \
	(defined mk_sl_sort_merge_t_name) && \
	(defined mk_sl_sort_merge_t_data) && \
	(defined mk_sl_sort_merge_t_counter) && \
	(defined mk_sl_sort_merge_t_is_sorted) && \
	((defined mk_sl_sort_merge_t_first_round && (mk_sl_sort_merge_t_first_round == 0 || mk_sl_sort_merge_t_first_round == 1)) || !defined mk_sl_sort_merge_t_first_round) && \
	(defined mk_sl_sort_merge_t_proxy || !defined mk_sl_sort_merge_t_proxy) && \
	1))
#error xxxxxxxxxx
#endif


#define mk_sl_sort_merge_inl_defd_name mk_sl_sort_merge_t_name
#define mk_sl_sort_merge_inl_defd_data mk_sl_sort_merge_t_data
#define mk_sl_sort_merge_inl_defd_counter mk_sl_sort_merge_t_counter
#define mk_sl_sort_merge_inl_defd_is_sorted mk_sl_sort_merge_t_is_sorted
#if defined mk_sl_sort_merge_t_first_round
#define mk_sl_sort_merge_inl_defd_first_round mk_sl_sort_merge_t_first_round
#else
#define mk_sl_sort_merge_inl_defd_first_round 0
#endif
#if defined mk_sl_sort_merge_t_proxy
#define mk_sl_sort_merge_inl_defd_proxy mk_sl_sort_merge_t_proxy
#else
#define mk_sl_sort_merge_inl_defd_proxy mk_sl_sort_merge_inl_defd_myint
#endif


#define mk_sl_sort_merge_inl_defd_myint_t int
#define mk_sl_sort_merge_inl_defd_myint_ct int const
#define mk_sl_sort_merge_inl_defd_myint_pt int*
#define mk_sl_sort_merge_inl_defd_myint_pct int const*
#define mk_sl_sort_merge_inl_defd_myint_prt int* mk_lang_restrict
#define mk_sl_sort_merge_inl_defd_myint_prct int const* mk_lang_restrict

#define mk_sl_sort_merge_inl_defd_data_t mk_lang_concat(mk_sl_sort_merge_inl_defd_data, _t)
#define mk_sl_sort_merge_inl_defd_data_ct mk_lang_concat(mk_sl_sort_merge_inl_defd_data, _ct)
#define mk_sl_sort_merge_inl_defd_data_pt mk_lang_concat(mk_sl_sort_merge_inl_defd_data, _pt)
#define mk_sl_sort_merge_inl_defd_data_pct mk_lang_concat(mk_sl_sort_merge_inl_defd_data, _pct)
#define mk_sl_sort_merge_inl_defd_data_prt mk_lang_concat(mk_sl_sort_merge_inl_defd_data, _prt)
#define mk_sl_sort_merge_inl_defd_data_prct mk_lang_concat(mk_sl_sort_merge_inl_defd_data, _prct)

#define mk_sl_sort_merge_inl_defd_proxy_t mk_lang_concat(mk_sl_sort_merge_inl_defd_proxy, _t)
#define mk_sl_sort_merge_inl_defd_proxy_ct mk_lang_concat(mk_sl_sort_merge_inl_defd_proxy, _ct)
#define mk_sl_sort_merge_inl_defd_proxy_pt mk_lang_concat(mk_sl_sort_merge_inl_defd_proxy, _pt)
#define mk_sl_sort_merge_inl_defd_proxy_pct mk_lang_concat(mk_sl_sort_merge_inl_defd_proxy, _pct)
#define mk_sl_sort_merge_inl_defd_proxy_prt mk_lang_concat(mk_sl_sort_merge_inl_defd_proxy, _prt)
#define mk_sl_sort_merge_inl_defd_proxy_prct mk_lang_concat(mk_sl_sort_merge_inl_defd_proxy, _prct)

#define mk_sl_sort_merge_inl_defd_counter_t mk_lang_concat(mk_sl_sort_merge_inl_defd_counter, _t)
#define mk_sl_sort_merge_inl_defd_counter_ct mk_lang_concat(mk_sl_sort_merge_inl_defd_counter, _ct)
#define mk_sl_sort_merge_inl_defd_counter_pt mk_lang_concat(mk_sl_sort_merge_inl_defd_counter, _pt)
#define mk_sl_sort_merge_inl_defd_counter_pct mk_lang_concat(mk_sl_sort_merge_inl_defd_counter, _pct)
#define mk_sl_sort_merge_inl_defd_counter_prt mk_lang_concat(mk_sl_sort_merge_inl_defd_counter, _prt)
#define mk_sl_sort_merge_inl_defd_counter_prct mk_lang_concat(mk_sl_sort_merge_inl_defd_counter, _prct)

#define mk_sl_sort_merge_inl_defd_counter_dec2 mk_lang_concat(mk_sl_sort_merge_inl_defd_counter, _dec2)
#define mk_sl_sort_merge_inl_defd_counter_count_leading_zeros mk_lang_concat(mk_sl_sort_merge_inl_defd_counter, _count_leading_zeros)

#define mk_sl_sort_merge_inl_defd_fn_is_sorted_plain mk_sl_sort_merge_inl_defd_is_sorted
#define mk_sl_sort_merge_inl_defd_fn_is_sorted_proxy mk_sl_sort_merge_inl_defd_is_sorted
#define mk_sl_sort_merge_inl_defd_fn_first_round_plain_inplace mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _first_round_plain_inplace)
#define mk_sl_sort_merge_inl_defd_fn_first_round_plain_copy mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _first_round_plain_copy)
#define mk_sl_sort_merge_inl_defd_fn_first_round_plain mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _first_round_plain)
#define mk_sl_sort_merge_inl_defd_fn_first_round_proxy_inplace mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _first_round_proxy_inplace)
#define mk_sl_sort_merge_inl_defd_fn_first_round_proxy_copy mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _first_round_proxy_copy)
#define mk_sl_sort_merge_inl_defd_fn_first_round_proxy mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _first_round_proxy)
#define mk_sl_sort_merge_inl_defd_fn_merge_plain mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _merge_plain)
#define mk_sl_sort_merge_inl_defd_fn_merge_proxy mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _merge_proxy)
#define mk_sl_sort_merge_inl_defd_fn_plain_many mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _plain_many)
#define mk_sl_sort_merge_inl_defd_fn_proxy_many mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _proxy_many)

#define mk_sl_sort_merge_inl_defd_fn_plain mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _plain)
#define mk_sl_sort_merge_inl_defd_fn_proxy mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _proxy)
