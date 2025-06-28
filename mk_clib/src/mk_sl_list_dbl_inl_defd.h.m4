include(`mk_lang_typedef.m')dnl
#include "mk_lang_concat.h"


#if(!( \
	(defined mk_sl_list_dbl_t_name) && \
	(defined mk_sl_list_dbl_t_element_type) && \
	(defined mk_sl_list_dbl_t_mallocator_global) && \
	(defined mk_sl_list_dbl_t_element_construct_copy || !defined mk_sl_list_dbl_t_element_construct_copy) && \
	(defined mk_sl_list_dbl_t_element_construct_move || !defined mk_sl_list_dbl_t_element_construct_move) && \
	(defined mk_sl_list_dbl_t_element_destroy || !defined mk_sl_list_dbl_t_element_destroy) && \
1))
#error xxxxxxxxxx
#endif


#define mk_sl_list_dbl_inl_defd_name mk_sl_list_dbl_t_name
#define mk_sl_list_dbl_inl_defd_element_type mk_sl_list_dbl_t_element_type
#define mk_sl_list_dbl_inl_mallocator_global mk_sl_list_dbl_t_mallocator_global

#if defined mk_sl_list_dbl_t_element_construct_copy
#define mk_sl_list_dbl_inl_defd_element_has_construct_copy 1
#define mk_sl_list_dbl_inl_defd_element_construct_copy mk_sl_list_dbl_t_element_construct_copy
#else
#define mk_sl_list_dbl_inl_defd_element_has_construct_copy 0
#endif

#if defined mk_sl_list_dbl_t_element_construct_move
#define mk_sl_list_dbl_inl_defd_element_has_construct_move 1
#define mk_sl_list_dbl_inl_defd_element_construct_move mk_sl_list_dbl_t_element_construct_move
#else
#define mk_sl_list_dbl_inl_defd_element_has_construct_move 0
#endif

#if defined mk_sl_list_dbl_t_element_destroy
#define mk_sl_list_dbl_inl_defd_element_has_destroy 1
#define mk_sl_list_dbl_inl_defd_element_destroy mk_sl_list_dbl_t_element_destroy
#else
#define mk_sl_list_dbl_inl_defd_element_has_destroy 0
#endif





#define mk_sl_list_dbl_inl_defd_element_prefix mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _element)

#define mk_sl_list_dbl_inl_defd_element mk_sl_list_dbl_inl_defd_element_prefix
#define mk_sl_list_dbl_inl_defd_element_t mk_lang_concat(mk_sl_list_dbl_inl_defd_element_prefix, _t)
mm_per_typedef(`#define mk_sl_list_dbl_inl_defd_element_$1 mk_lang_concat(mk_sl_list_dbl_inl_defd_element_prefix, _$1)')





#define mk_sl_list_dbl_inl_defd_prefix_mallocator mk_sl_list_dbl_inl_mallocator_global

#define mk_sl_list_dbl_inl_defd_mallocator_init mk_lang_concat(mk_sl_list_dbl_inl_defd_prefix_mallocator, _init)
#define mk_sl_list_dbl_inl_defd_mallocator_deinit mk_lang_concat(mk_sl_list_dbl_inl_defd_prefix_mallocator, _deinit)
#define mk_sl_list_dbl_inl_defd_mallocator_allocate mk_lang_concat(mk_sl_list_dbl_inl_defd_prefix_mallocator, _allocate)
#define mk_sl_list_dbl_inl_defd_mallocator_deallocate mk_lang_concat(mk_sl_list_dbl_inl_defd_prefix_mallocator, _deallocate)
#define mk_sl_list_dbl_inl_defd_mallocator_reallocate mk_lang_concat(mk_sl_list_dbl_inl_defd_prefix_mallocator, _reallocate)





#define mk_sl_list_dbl_inl_defd_node_s mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _node_s)
#define mk_sl_list_dbl_inl_defd_node_t mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _node_t)
mm_per_typedef(`#define mk_sl_list_dbl_inl_defd_node_$1 mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _node_$1)')

#define mk_sl_list_dbl_inl_defd_s mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _s)
#define mk_sl_list_dbl_inl_defd_t mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _t)
mm_per_typedef(`#define mk_sl_list_dbl_inl_defd_$1 mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _$1)')

#define mk_sl_list_dbl_inl_defd_prrw_check_invariants mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_check_invariants)
#define mk_sl_list_dbl_inl_defd_prrw_element_destroy mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_element_destroy)
#define mk_sl_list_dbl_inl_defd_prrw_element_construct_copy mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_element_construct_copy)
#define mk_sl_list_dbl_inl_defd_prrw_element_construct_move mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_element_construct_move)
#define mk_sl_list_dbl_inl_defd_prrw_construct mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_construct)
#define mk_sl_list_dbl_inl_defd_prrw_destroy mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_destroy)
#define mk_sl_list_dbl_inl_defd_prrw_is_empty mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_is_empty)
#define mk_sl_list_dbl_inl_defd_prrw_push_back_copy mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_push_back_copy)
#define mk_sl_list_dbl_inl_defd_prrw_push_back_move mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_push_back_move)
#define mk_sl_list_dbl_inl_defd_prrw_pop_front_copy mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_pop_front_copy)
#define mk_sl_list_dbl_inl_defd_prrw_pop_front_move mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _prrw_pop_front_move)

#define mk_sl_list_dbl_inl_defd_rw_construct mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _rw_construct)
#define mk_sl_list_dbl_inl_defd_rw_destroy mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _rw_destroy)
#define mk_sl_list_dbl_inl_defd_rw_is_empty mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _rw_is_empty)
#define mk_sl_list_dbl_inl_defd_rw_push_back_copy mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _rw_push_back_copy)
#define mk_sl_list_dbl_inl_defd_rw_push_back_move mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _rw_push_back_move)
#define mk_sl_list_dbl_inl_defd_rw_pop_front_copy mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _rw_pop_front_copy)
#define mk_sl_list_dbl_inl_defd_rw_pop_front_move mk_lang_concat(mk_sl_list_dbl_inl_defd_name, _rw_pop_front_move)
