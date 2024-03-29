#include "mk_lang_concat.h"


#define mk_sl_vector_inl_defd_prefix mk_lang_concat(mk_sl_vector_, mk_sl_vector_t_name)

#define mk_sl_vector_inl_defd_vector_s mk_lang_concat(mk_sl_vector_inl_defd_prefix, _s)
#define mk_sl_vector_inl_defd_vector_t mk_lang_concat(mk_sl_vector_inl_defd_prefix, _t)
#define mk_sl_vector_inl_defd_vector_ct mk_lang_concat(mk_sl_vector_inl_defd_prefix, _ct)
#define mk_sl_vector_inl_defd_vector_pt mk_lang_concat(mk_sl_vector_inl_defd_prefix, _pt)
#define mk_sl_vector_inl_defd_vector_pct mk_lang_concat(mk_sl_vector_inl_defd_prefix, _pct)

#define mk_sl_vector_inl_defd_vector_ro_destroy mk_lang_concat(mk_sl_vector_inl_defd_prefix, _ro_destroy)
#define mk_sl_vector_inl_defd_vector_ro_is_empty mk_lang_concat(mk_sl_vector_inl_defd_prefix, _ro_is_empty)
#define mk_sl_vector_inl_defd_vector_ro_get_count mk_lang_concat(mk_sl_vector_inl_defd_prefix, _ro_get_count)
#define mk_sl_vector_inl_defd_vector_ro_get_capacity mk_lang_concat(mk_sl_vector_inl_defd_prefix, _ro_get_capacity)
#define mk_sl_vector_inl_defd_vector_ro_get_data mk_lang_concat(mk_sl_vector_inl_defd_prefix, _ro_get_data)
#define mk_sl_vector_inl_defd_vector_ro_get_data_at mk_lang_concat(mk_sl_vector_inl_defd_prefix, _ro_get_data_at)
#define mk_sl_vector_inl_defd_vector_ro_get_data_back mk_lang_concat(mk_sl_vector_inl_defd_prefix, _ro_get_data_back)

#define mk_sl_vector_inl_defd_vector_rw_destroy mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_destroy)
#define mk_sl_vector_inl_defd_vector_rw_is_empty mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_is_empty)
#define mk_sl_vector_inl_defd_vector_rw_get_count mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_get_count)
#define mk_sl_vector_inl_defd_vector_rw_get_capacity mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_get_capacity)
#define mk_sl_vector_inl_defd_vector_rw_get_data mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_get_data)
#define mk_sl_vector_inl_defd_vector_rw_get_data_at mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_get_data_at)
#define mk_sl_vector_inl_defd_vector_rw_get_data_back mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_get_data_back)

#define mk_sl_vector_inl_defd_vector_rw_construct mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_construct)
#define mk_sl_vector_inl_defd_vector_rw_reserve_n mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_reserve_n)
#define mk_sl_vector_inl_defd_vector_rw_reserve_one mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_reserve_one)
#define mk_sl_vector_inl_defd_vector_rw_resize mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_resize)
#define mk_sl_vector_inl_defd_vector_rw_push_back mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_push_back)
#define mk_sl_vector_inl_defd_vector_rw_clear mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_clear)
#define mk_sl_vector_inl_defd_vector_rw_push_back_from_capacity_one mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_push_back_from_capacity_one)
#define mk_sl_vector_inl_defd_vector_rw_push_back_from_capacity_n mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_push_back_from_capacity_n)
#define mk_sl_vector_inl_defd_vector_rw_pop_back_one mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_pop_back_one)
#define mk_sl_vector_inl_defd_vector_rw_pop_back_n mk_lang_concat(mk_sl_vector_inl_defd_prefix, _rw_pop_back_n)

#define mk_sl_vector_inl_defd_vector_pr_check_invariants mk_lang_concat(mk_sl_vector_inl_defd_prefix, _pr_check_invariants)


#define mk_sl_vector_inl_defd_elem_t mk_sl_vector_t_elem_t
#define mk_sl_vector_inl_defd_elem_ct mk_sl_vector_inl_defd_elem_t const
#define mk_sl_vector_inl_defd_elem_pt mk_sl_vector_inl_defd_elem_t*
#define mk_sl_vector_inl_defd_elem_pct mk_sl_vector_inl_defd_elem_t const*


#define mk_sl_vector_inl_defd_buffer_prefix mk_sl_vector_t_buffer_tn

#define mk_sl_vector_inl_defd_buffer_s mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _s)
#define mk_sl_vector_inl_defd_buffer_t mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _t)
#define mk_sl_vector_inl_defd_buffer_ct mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _ct)
#define mk_sl_vector_inl_defd_buffer_pt mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _pt)
#define mk_sl_vector_inl_defd_buffer_pct mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _pct)

#define mk_sl_vector_inl_defd_buffer_ro_destroy mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _ro_destroy)
#define mk_sl_vector_inl_defd_buffer_ro_get_data mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _ro_get_data)
#define mk_sl_vector_inl_defd_buffer_ro_get_size mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _ro_get_size)
#define mk_sl_vector_inl_defd_buffer_ro_is_empty mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _ro_is_empty)
#define mk_sl_vector_inl_defd_buffer_ro_get_data_at mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _ro_get_data_at)

#define mk_sl_vector_inl_defd_buffer_rw_destroy mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _rw_destroy)
#define mk_sl_vector_inl_defd_buffer_rw_get_data mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _rw_get_data)
#define mk_sl_vector_inl_defd_buffer_rw_get_size mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _rw_get_size)
#define mk_sl_vector_inl_defd_buffer_rw_is_empty mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _rw_is_empty)
#define mk_sl_vector_inl_defd_buffer_rw_get_data_at mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _rw_get_data_at)

#define mk_sl_vector_inl_defd_buffer_rw_construct mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _rw_construct)
#define mk_sl_vector_inl_defd_buffer_rw_resize mk_lang_concat(mk_sl_vector_inl_defd_buffer_prefix, _rw_resize)
