include(`mk_lang_typedef.m')dnl
#include "mk_lang_bui.h"
#include "mk_lang_concat.h"
#include "mk_lang_types.h"


#if(!( \
	(defined mk_sl_sort_merge_t_name) && \
	(defined mk_sl_sort_merge_t_element_type) && \
	(defined mk_sl_sort_merge_t_element_is_sorted) && \
	(defined mk_sl_sort_merge_t_counter_name || !defined mk_sl_sort_merge_t_counter_name) && \
	(defined mk_sl_sort_merge_t_context_type || !defined mk_sl_sort_merge_t_context_type) && \
	((defined mk_sl_sort_merge_t_first_round && ((mk_sl_sort_merge_t_first_round) == 0 || (mk_sl_sort_merge_t_first_round) == 1)) || !defined mk_sl_sort_merge_t_first_round) && \
1))
#error xxxxxxxxxx
#endif


#define mk_sl_sort_merge_inl_defd_name mk_sl_sort_merge_t_name
#define mk_sl_sort_merge_inl_defd_element_type mk_sl_sort_merge_t_element_type
#define mk_sl_sort_merge_inl_defd_element_is_sorted mk_sl_sort_merge_t_element_is_sorted

#if defined mk_sl_sort_merge_t_counter_name
#define mk_sl_sort_merge_inl_defd_counter_name mk_sl_sort_merge_t_counter_name
#else
#define mk_sl_sort_merge_inl_defd_counter_name mk_lang_bui_usize
#endif

#if defined mk_sl_sort_merge_t_context_type
#define mk_sl_sort_merge_inl_defd_context_type mk_sl_sort_merge_t_context_type
#else
#define mk_sl_sort_merge_inl_defd_context_type mk_lang_types_uintptr_t
#endif

#if defined mk_sl_sort_merge_t_first_round
#define mk_sl_sort_merge_inl_defd_first_round mk_sl_sort_merge_t_first_round
#else
#define mk_sl_sort_merge_inl_defd_first_round 0
#endif


#define mk_sl_sort_merge_inl_defd_element mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _element)
#define mk_sl_sort_merge_inl_defd_element_t mk_lang_concat(mk_sl_sort_merge_inl_defd_element, _t)
mm_per_typedef(`#define mk_sl_sort_merge_inl_defd_element_$1 mk_lang_concat(mk_sl_sort_merge_inl_defd_element, _$1)'`')

#define mk_sl_sort_merge_inl_defd_counter_type mk_lang_concat(mk_sl_sort_merge_inl_defd_counter_name, _t)
#define mk_sl_sort_merge_inl_defd_counter mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _counter)
#define mk_sl_sort_merge_inl_defd_counter_t mk_lang_concat(mk_sl_sort_merge_inl_defd_counter, _t)
mm_per_typedef(`#define mk_sl_sort_merge_inl_defd_counter_$1 mk_lang_concat(mk_sl_sort_merge_inl_defd_counter, _$1)'`')

#define mk_sl_sort_merge_inl_defd_context mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _context)
#define mk_sl_sort_merge_inl_defd_context_t mk_lang_concat(mk_sl_sort_merge_inl_defd_context, _t)
mm_per_typedef(`#define mk_sl_sort_merge_inl_defd_context_$1 mk_lang_concat(mk_sl_sort_merge_inl_defd_context, _$1)'`')


#define mk_sl_sort_merge_inl_defd_counter_dec2 mk_lang_concat(mk_sl_sort_merge_inl_defd_counter_name, _dec2)
#define mk_sl_sort_merge_inl_defd_counter_count_leading_zeros mk_lang_concat(mk_sl_sort_merge_inl_defd_counter_name, _count_leading_zeros)

#define mk_sl_sort_merge_inl_defd_prfn_is_sorted mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _prfn_is_sorted)
#define mk_sl_sort_merge_inl_defd_prfn_first_round_inplace mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _prfn_first_round_inplace)
#define mk_sl_sort_merge_inl_defd_prfn_first_round_copy mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _prfn_first_round_copy)
#define mk_sl_sort_merge_inl_defd_prfn_first_round_d mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _prfn_first_round_d)
#define mk_sl_sort_merge_inl_defd_prfn_merge mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _prfn_merge)
#define mk_sl_sort_merge_inl_defd_prfn_many mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _prfn_many)

#define mk_sl_sort_merge_inl_defd_fn mk_lang_concat(mk_sl_sort_merge_inl_defd_name, _fn)
