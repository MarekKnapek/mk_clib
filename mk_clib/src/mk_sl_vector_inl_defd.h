#include "mk_lang_concat.h"


#if(!( \
	(defined mk_sl_vector_t_name) && \
	(defined mk_sl_vector_t_element) && \
	(defined mk_sl_vector_t_mallocatorg) && \
1))
#error xxxxxxxxxx
#endif


#define mk_sl_vector_inl_defd_name mk_sl_vector_t_name
#define mk_sl_vector_inl_defd_element mk_sl_vector_t_element
#define mk_sl_vector_inl_defd_mallocatorg mk_sl_vector_t_mallocatorg


#define mk_sl_vector_inl_defd_element_t mk_lang_concat(mk_sl_vector_inl_defd_name, _element_t)
#define mk_sl_vector_inl_defd_element_ct mk_lang_concat(mk_sl_vector_inl_defd_name, _element_ct)
#define mk_sl_vector_inl_defd_element_pt mk_lang_concat(mk_sl_vector_inl_defd_name, _element_pt)
#define mk_sl_vector_inl_defd_element_pct mk_lang_concat(mk_sl_vector_inl_defd_name, _element_pct)

#define mk_sl_vecotr_inl_defd_mallocatorg_allocate mk_lang_concat(mk_sl_vector_inl_defd_mallocatorg, _allocate)
#define mk_sl_vecotr_inl_defd_mallocatorg_deallocate mk_lang_concat(mk_sl_vector_inl_defd_mallocatorg, _deallocate)
#define mk_sl_vecotr_inl_defd_mallocatorg_reallocate mk_lang_concat(mk_sl_vector_inl_defd_mallocatorg, _reallocate)

#define mk_sl_vector_inl_defd_s mk_lang_concat(mk_sl_vector_inl_defd_name, _s)
#define mk_sl_vector_inl_defd_t mk_lang_concat(mk_sl_vector_inl_defd_name, _t)
#define mk_sl_vector_inl_defd_ct mk_lang_concat(mk_sl_vector_inl_defd_name, _ct)
#define mk_sl_vector_inl_defd_pt mk_lang_concat(mk_sl_vector_inl_defd_name, _pt)
#define mk_sl_vector_inl_defd_pct mk_lang_concat(mk_sl_vector_inl_defd_name, _pct)
#define mk_sl_vector_inl_defd_ppt mk_lang_concat(mk_sl_vector_inl_defd_name, _ppt)
#define mk_sl_vector_inl_defd_pcpt mk_lang_concat(mk_sl_vector_inl_defd_name, _pcpt)
#define mk_sl_vector_inl_defd_ppct mk_lang_concat(mk_sl_vector_inl_defd_name, _ppct)
#define mk_sl_vector_inl_defd_pcpct mk_lang_concat(mk_sl_vector_inl_defd_name, _pcpct)

#define mk_sl_vector_inl_defd_ro_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_capacity)
#define mk_sl_vector_inl_defd_ro_size mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_size)
#define mk_sl_vector_inl_defd_ro_free mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_free)
#define mk_sl_vector_inl_defd_ro_is_empty mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_is_empty)
#define mk_sl_vector_inl_defd_ro_is_full mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_is_full)
#define mk_sl_vector_inl_defd_ro_at mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_at)
#define mk_sl_vector_inl_defd_ro_data mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_data)
#define mk_sl_vector_inl_defd_ro_front mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_front)
#define mk_sl_vector_inl_defd_ro_back mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_back)

#define mk_sl_vector_inl_defd_rw_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_capacity)
#define mk_sl_vector_inl_defd_rw_size mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_size)
#define mk_sl_vector_inl_defd_rw_free mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_free)
#define mk_sl_vector_inl_defd_rw_is_empty mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_is_empty)
#define mk_sl_vector_inl_defd_rw_is_full mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_is_full)
#define mk_sl_vector_inl_defd_rw_at mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_at)
#define mk_sl_vector_inl_defd_rw_data mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_data)
#define mk_sl_vector_inl_defd_rw_front mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_front)
#define mk_sl_vector_inl_defd_rw_back mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_back)

#define mk_sl_vector_inl_defd_rw_construct mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_construct)
#define mk_sl_vector_inl_defd_rw_destroy mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_destroy)
#define mk_sl_vector_inl_defd_rw_reserve_at_least mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_reserve_at_least)
#define mk_sl_vector_inl_defd_rw_shrink mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_shrink)
#define mk_sl_vector_inl_defd_rw_resize mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_resize)
#define mk_sl_vector_inl_defd_rw_clear mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_clear)
#define mk_sl_vector_inl_defd_rw_push_back_many mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_push_back_many)
#define mk_sl_vector_inl_defd_rw_push_back_one mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_push_back_one)
#define mk_sl_vector_inl_defd_rw_push_back_void mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_push_back_void)
#define mk_sl_vector_inl_defd_rw_pop_back_one mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_pop_back_one)
#define mk_sl_vector_inl_defd_rw_pop_back_many mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_pop_back_many)
