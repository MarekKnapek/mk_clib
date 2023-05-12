#include "mk_lang_concat.h"


#define mk_sl_buffer_inl_defd_buffer_s mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _s)
#define mk_sl_buffer_inl_defd_buffer_t mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _t)
#define mk_sl_buffer_inl_defd_buffer_ct mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _ct)
#define mk_sl_buffer_inl_defd_buffer_pt mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _pt)
#define mk_sl_buffer_inl_defd_buffer_pct mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _pct)

#define mk_sl_buffer_inl_defd_buffer_ro_destroy mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _ro_destroy)
#define mk_sl_buffer_inl_defd_buffer_ro_get_data mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _ro_get_data)
#define mk_sl_buffer_inl_defd_buffer_ro_get_size mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _ro_get_size)
#define mk_sl_buffer_inl_defd_buffer_ro_is_empty mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _ro_is_empty)
#define mk_sl_buffer_inl_defd_buffer_ro_get_data_at mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _ro_get_data_at)

#define mk_sl_buffer_inl_defd_buffer_rw_construct mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _rw_construct)
#define mk_sl_buffer_inl_defd_buffer_rw_destroy mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _rw_destroy)
#define mk_sl_buffer_inl_defd_buffer_rw_get_data mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _rw_get_data)
#define mk_sl_buffer_inl_defd_buffer_rw_get_size mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _rw_get_size)
#define mk_sl_buffer_inl_defd_buffer_rw_is_empty mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _rw_is_empty)
#define mk_sl_buffer_inl_defd_buffer_rw_get_data_at mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _rw_get_data_at)
#define mk_sl_buffer_inl_defd_buffer_rw_resize mk_lang_concat(mk_lang_concat(mk_sl_buffer_, mk_sl_buffer_t_name), _rw_resize)

#define mk_sl_buffer_inl_defd_mallocator_allocate mk_lang_concat(mk_sl_buffer_t_mallocator, _allocate)
#define mk_sl_buffer_inl_defd_mallocator_deallocate mk_lang_concat(mk_sl_buffer_t_mallocator, _deallocate)
#define mk_sl_buffer_inl_defd_mallocator_reallocate mk_lang_concat(mk_sl_buffer_t_mallocator, _reallocate)
