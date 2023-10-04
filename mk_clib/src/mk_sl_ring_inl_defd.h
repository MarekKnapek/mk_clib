#include "mk_lang_concat.h"


#define mk_sl_ring_inl_defd_name mk_sl_ring_t_name
#define mk_sl_ring_inl_defd_elem_t mk_sl_ring_t_elem_t
#define mk_sl_ring_inl_defd_capacity mk_sl_ring_t_capacity

#define mk_sl_ring_inl_defd_prefix mk_lang_concat(mk_sl_ring_, mk_sl_ring_inl_defd_name)

#define mk_sl_ring_inl_defd_s mk_lang_concat(mk_sl_ring_inl_defd_prefix, _s)
#define mk_sl_ring_inl_defd_t mk_lang_concat(mk_sl_ring_inl_defd_prefix, _t)
#define mk_sl_ring_inl_defd_ct mk_lang_concat(mk_sl_ring_inl_defd_prefix, _ct)
#define mk_sl_ring_inl_defd_pt mk_lang_concat(mk_sl_ring_inl_defd_prefix, _pt)
#define mk_sl_ring_inl_defd_pct mk_lang_concat(mk_sl_ring_inl_defd_prefix, _pct)

#define mk_sl_ring_inl_defd_elem_ct mk_lang_concat(mk_sl_ring_inl_defd_prefix, _elem_ct)
#define mk_sl_ring_inl_defd_elem_pt mk_lang_concat(mk_sl_ring_inl_defd_prefix, _elem_pt)
#define mk_sl_ring_inl_defd_elem_pct mk_lang_concat(mk_sl_ring_inl_defd_prefix, _elem_pct)

#define mk_sl_ring_inl_defd_ro_destroy mk_lang_concat(mk_sl_ring_inl_defd_prefix, _ro_destroy)
#define mk_sl_ring_inl_defd_ro_is_empty mk_lang_concat(mk_sl_ring_inl_defd_prefix, _ro_is_empty)
#define mk_sl_ring_inl_defd_ro_is_full mk_lang_concat(mk_sl_ring_inl_defd_prefix, _ro_is_full)
#define mk_sl_ring_inl_defd_ro_get_size mk_lang_concat(mk_sl_ring_inl_defd_prefix, _ro_get_size)
#define mk_sl_ring_inl_defd_ro_get_capacity mk_lang_concat(mk_sl_ring_inl_defd_prefix, _ro_get_capacity)
#define mk_sl_ring_inl_defd_ro_get_free mk_lang_concat(mk_sl_ring_inl_defd_prefix, _ro_get_free)
#define mk_sl_ring_inl_defd_ro_get_elem mk_lang_concat(mk_sl_ring_inl_defd_prefix, _ro_get_elem)
#define mk_sl_ring_inl_defd_ro_get_head mk_lang_concat(mk_sl_ring_inl_defd_prefix, _ro_get_head)
#define mk_sl_ring_inl_defd_ro_get_tail mk_lang_concat(mk_sl_ring_inl_defd_prefix, _ro_get_tail)

#define mk_sl_ring_inl_defd_rw_destroy mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_destroy)
#define mk_sl_ring_inl_defd_rw_is_empty mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_is_empty)
#define mk_sl_ring_inl_defd_rw_is_full mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_is_full)
#define mk_sl_ring_inl_defd_rw_get_size mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_get_size)
#define mk_sl_ring_inl_defd_rw_get_capacity mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_get_capacity)
#define mk_sl_ring_inl_defd_rw_get_free mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_get_free)
#define mk_sl_ring_inl_defd_rw_get_elem mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_get_elem)
#define mk_sl_ring_inl_defd_rw_get_head mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_get_head)
#define mk_sl_ring_inl_defd_rw_get_tail mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_get_tail)

#define mk_sl_ring_inl_defd_rw_construct mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_construct)
#define mk_sl_ring_inl_defd_rw_push_void mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_push_void)
#define mk_sl_ring_inl_defd_rw_push_elem mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_push_elem)
#define mk_sl_ring_inl_defd_rw_pop mk_lang_concat(mk_sl_ring_inl_defd_prefix, _rw_pop)
