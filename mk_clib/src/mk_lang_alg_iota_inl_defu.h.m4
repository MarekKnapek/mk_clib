include(`mk_lang_typedef.m')dnl












#undef mk_lang_alg_iota_inl_defd_name
#undef mk_lang_alg_iota_inl_defd_element_type
#undef mk_lang_alg_iota_inl_defd_counter_type


#undef mk_lang_alg_iota_inl_defd_element
#undef mk_lang_alg_iota_inl_defd_element_t
mm_per_typedef(`#undef mk_lang_alg_iota_inl_defd_element_$1'`')

#undef mk_lang_alg_iota_inl_defd_counter
#undef mk_lang_alg_iota_inl_defd_counter_t
mm_per_typedef(`#undef mk_lang_alg_iota_inl_defd_counter_$1'`')


#undef mk_lang_alg_iota_inl_defd_fn
