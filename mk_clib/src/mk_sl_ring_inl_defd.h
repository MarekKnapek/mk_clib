#include "mk_lang_concat.h"
#include "mk_lang_pow2.h"


#if(!( \
	(defined mk_sl_ring_t_name) && \
	(defined mk_sl_ring_t_element) && \
	(defined mk_sl_ring_t_count && (mk_sl_ring_t_count) >= 2 && (mk_sl_ring_t_count) <= (1ul * 1024ul * 1024ul * 1024ul) && mk_lang_pow2_is(mk_sl_ring_t_count)) && \
1))
#error xxxxxxxxxx
#endif


#define mk_sl_ring_inl_defd_name mk_sl_ring_t_name
#define mk_sl_ring_inl_defd_element mk_sl_ring_t_element
#define mk_sl_ring_inl_defd_count (mk_sl_ring_t_count)

#define mk_sl_ring_inl_defd_array_name mk_lang_concat(mk_sl_ring_inl_defd_name, _array)

#define mk_sl_ring_inl_defd_array_element_t mk_lang_concat(mk_sl_ring_inl_defd_array_name, _element_t)
#define mk_sl_ring_inl_defd_array_element_ct mk_lang_concat(mk_sl_ring_inl_defd_array_name, _element_ct)
#define mk_sl_ring_inl_defd_array_element_pt mk_lang_concat(mk_sl_ring_inl_defd_array_name, _element_pt)
#define mk_sl_ring_inl_defd_array_element_pct mk_lang_concat(mk_sl_ring_inl_defd_array_name, _element_pct)

#define mk_sl_ring_inl_defd_array_len_e mk_lang_concat(mk_sl_ring_inl_defd_array_name, _len_e)
#define mk_sl_ring_inl_defd_array_len_t mk_lang_concat(mk_sl_ring_inl_defd_array_name, _len_t)
#define mk_sl_ring_inl_defd_array_len_v mk_lang_concat(mk_sl_ring_inl_defd_array_name, _len_v)

#define mk_sl_ring_inl_defd_array_t mk_lang_concat(mk_sl_ring_inl_defd_array_name, _t)
#define mk_sl_ring_inl_defd_array_ct mk_lang_concat(mk_sl_ring_inl_defd_array_name, _ct)
#define mk_sl_ring_inl_defd_array_pt mk_lang_concat(mk_sl_ring_inl_defd_array_name, _pt)
#define mk_sl_ring_inl_defd_array_pct mk_lang_concat(mk_sl_ring_inl_defd_array_name, _pct)

#define mk_sl_ring_inl_defd_array_st_capacity mk_lang_concat(mk_sl_ring_inl_defd_array_name, _st_capacity)
#define mk_sl_ring_inl_defd_array_st_size mk_lang_concat(mk_sl_ring_inl_defd_array_name, _st_size)

#define mk_sl_ring_inl_defd_array_ro_capacity mk_lang_concat(mk_sl_ring_inl_defd_array_name, _ro_capacity)
#define mk_sl_ring_inl_defd_array_ro_size mk_lang_concat(mk_sl_ring_inl_defd_array_name, _ro_size)
#define mk_sl_ring_inl_defd_array_ro_at mk_lang_concat(mk_sl_ring_inl_defd_array_name, _ro_at)
#define mk_sl_ring_inl_defd_array_ro_data mk_lang_concat(mk_sl_ring_inl_defd_array_name, _ro_data)
#define mk_sl_ring_inl_defd_array_ro_front mk_lang_concat(mk_sl_ring_inl_defd_array_name, _ro_front)
#define mk_sl_ring_inl_defd_array_ro_back mk_lang_concat(mk_sl_ring_inl_defd_array_name, _ro_back)

#define mk_sl_ring_inl_defd_array_rw_capacity mk_lang_concat(mk_sl_ring_inl_defd_array_name, _rw_capacity)
#define mk_sl_ring_inl_defd_array_rw_size mk_lang_concat(mk_sl_ring_inl_defd_array_name, _rw_size)
#define mk_sl_ring_inl_defd_array_rw_at mk_lang_concat(mk_sl_ring_inl_defd_array_name, _rw_at)
#define mk_sl_ring_inl_defd_array_rw_data mk_lang_concat(mk_sl_ring_inl_defd_array_name, _rw_data)
#define mk_sl_ring_inl_defd_array_rw_front mk_lang_concat(mk_sl_ring_inl_defd_array_name, _rw_front)
#define mk_sl_ring_inl_defd_array_rw_back mk_lang_concat(mk_sl_ring_inl_defd_array_name, _rw_back)

#define mk_sl_ring_inl_defd_element_t mk_lang_concat(mk_sl_ring_inl_defd_name, _element_t)
#define mk_sl_ring_inl_defd_element_ct mk_lang_concat(mk_sl_ring_inl_defd_name, _element_ct)
#define mk_sl_ring_inl_defd_element_pt mk_lang_concat(mk_sl_ring_inl_defd_name, _element_pt)
#define mk_sl_ring_inl_defd_element_pct mk_lang_concat(mk_sl_ring_inl_defd_name, _element_pct)

#define mk_sl_ring_inl_defd_len_e mk_lang_concat(mk_sl_ring_inl_defd_name, _len_e)
#define mk_sl_ring_inl_defd_len_t mk_lang_concat(mk_sl_ring_inl_defd_name, _len_t)
#define mk_sl_ring_inl_defd_len_v mk_lang_concat(mk_sl_ring_inl_defd_name, _len_v)

#define mk_sl_ring_inl_defd_s mk_lang_concat(mk_sl_ring_inl_defd_name, _s)
#define mk_sl_ring_inl_defd_t mk_lang_concat(mk_sl_ring_inl_defd_name, _t)
#define mk_sl_ring_inl_defd_ct mk_lang_concat(mk_sl_ring_inl_defd_name, _ct)
#define mk_sl_ring_inl_defd_pt mk_lang_concat(mk_sl_ring_inl_defd_name, _pt)
#define mk_sl_ring_inl_defd_pct mk_lang_concat(mk_sl_ring_inl_defd_name, _pct)

#define mk_sl_ring_inl_defd_st_capacity mk_lang_concat(mk_sl_ring_inl_defd_name, _st_capacity)

#define mk_sl_ring_inl_defd_ro_capacity mk_lang_concat(mk_sl_ring_inl_defd_name, _ro_capacity)
#define mk_sl_ring_inl_defd_ro_size mk_lang_concat(mk_sl_ring_inl_defd_name, _ro_size)
#define mk_sl_ring_inl_defd_ro_free mk_lang_concat(mk_sl_ring_inl_defd_name, _ro_free)
#define mk_sl_ring_inl_defd_ro_is_empty mk_lang_concat(mk_sl_ring_inl_defd_name, _ro_is_empty)
#define mk_sl_ring_inl_defd_ro_is_full mk_lang_concat(mk_sl_ring_inl_defd_name, _ro_is_full)
#define mk_sl_ring_inl_defd_ro_at mk_lang_concat(mk_sl_ring_inl_defd_name, _ro_at)
#define mk_sl_ring_inl_defd_ro_data mk_lang_concat(mk_sl_ring_inl_defd_name, _ro_data)
#define mk_sl_ring_inl_defd_ro_front mk_lang_concat(mk_sl_ring_inl_defd_name, _ro_front)
#define mk_sl_ring_inl_defd_ro_back mk_lang_concat(mk_sl_ring_inl_defd_name, _ro_back)

#define mk_sl_ring_inl_defd_rw_capacity mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_capacity)
#define mk_sl_ring_inl_defd_rw_size mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_size)
#define mk_sl_ring_inl_defd_rw_free mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_free)
#define mk_sl_ring_inl_defd_rw_is_empty mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_is_empty)
#define mk_sl_ring_inl_defd_rw_is_full mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_is_full)
#define mk_sl_ring_inl_defd_rw_at mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_at)
#define mk_sl_ring_inl_defd_rw_data mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_data)
#define mk_sl_ring_inl_defd_rw_front mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_front)
#define mk_sl_ring_inl_defd_rw_back mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_back)

#define mk_sl_ring_inl_defd_rw_construct mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_construct)
#define mk_sl_ring_inl_defd_rw_push_back_one mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_push_back_one)
#define mk_sl_ring_inl_defd_rw_push_back_many mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_push_back_many)
#define mk_sl_ring_inl_defd_rw_pop_back mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_pop_back)
#define mk_sl_ring_inl_defd_rw_push_front mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_push_front)
#define mk_sl_ring_inl_defd_rw_pop_front_one mk_lang_concat(mk_sl_ring_inl_defd_name, _rw_pop_front_one)
