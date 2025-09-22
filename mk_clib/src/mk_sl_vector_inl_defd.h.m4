include(`mk_lang_typedef.m')dnl
#include "mk_lang_concat.h"
#include "mk_lang_limits.h"
#include "mk_lang_types.h"
#include "mk_sl_vector_copy.h"


#if(!( \
	(defined mk_sl_vector_t_name) && \
	(defined mk_sl_vector_t_element_type) && \
	(defined mk_sl_vector_t_mallocatorg || defined mk_sl_vector_t_mallocatorl) && \
	((defined mk_sl_vector_t_copy_style && ((mk_sl_vector_t_copy_style) == mk_sl_vector_copy_use_bitblt || (mk_sl_vector_t_copy_style) == mk_sl_vector_copy_use_custom)) || !defined mk_sl_vector_t_copy_style) && \
	(defined mk_sl_vector_t_element_construct_void || !defined mk_sl_vector_t_element_construct_void) && \
	(defined mk_sl_vector_t_element_destruct || !defined mk_sl_vector_t_element_destruct) && \
	(defined mk_sl_vector_t_element_copy_construct || !defined mk_sl_vector_t_element_copy_construct) && \
	(defined mk_sl_vector_t_element_move_construct || !defined mk_sl_vector_t_element_move_construct) && \
	(defined mk_sl_vector_t_element_copy_assign || !defined mk_sl_vector_t_element_copy_assign) && \
	(defined mk_sl_vector_t_element_move_assign || !defined mk_sl_vector_t_element_move_assign) && \
	(defined mk_sl_vector_t_element_eq || !defined mk_sl_vector_t_element_eq) && \
1))
#error xxxxxxxxxx
#endif


#if( \
	defined mk_sl_vector_t_mallocatorg && \
	defined mk_sl_vector_t_mallocatorl && \
1)
#error xxxxxxxxxx
#endif

#if( \
	defined mk_sl_vector_t_element_construct_void || \
	defined mk_sl_vector_t_element_destruct || \
0)
#if(!( \
	defined mk_sl_vector_t_element_construct_void && \
	defined mk_sl_vector_t_element_destruct && \
1))
#error xxxxxxxxxx
#endif
#endif

#if( \
	defined mk_sl_vector_t_element_copy_construct || \
	defined mk_sl_vector_t_element_copy_assign || \
0)
#if(!( \
	defined mk_sl_vector_t_element_copy_construct && \
	defined mk_sl_vector_t_element_copy_assign && \
1))
#error xxxxxxxxxx
#endif
#endif

#if( \
	defined mk_sl_vector_t_element_move_construct || \
	defined mk_sl_vector_t_element_move_assign || \
0)
#if(!( \
	defined mk_sl_vector_t_element_move_construct && \
	defined mk_sl_vector_t_element_move_assign && \
1))
#error xxxxxxxxxx
#endif
#endif


#define mk_sl_vector_inl_defd_name mk_sl_vector_t_name
#define mk_sl_vector_inl_defd_element_type mk_sl_vector_t_element_type

#if defined mk_sl_vector_t_mallocatorg
#define mk_sl_vector_inl_defd_mallocator mk_sl_vector_t_mallocatorg
#define mk_sl_vector_inl_defd_mallocator_is_global 1
#define mk_sl_vector_inl_defd_mallocator_is_lokal 0
#elif defined mk_sl_vector_t_mallocatorl
#define mk_sl_vector_inl_defd_mallocator mk_sl_vector_t_mallocatorl
#define mk_sl_vector_inl_defd_mallocator_is_global 0
#define mk_sl_vector_inl_defd_mallocator_is_lokal 1
#else
#error xxxxxxxxxx
#endif

#if defined mk_sl_vector_t_copy_style
#define mk_sl_vector_inl_defd_copy_style mk_sl_vector_t_copy_style
#else
#if defined mk_sl_vector_t_element_copy_construct && defined mk_sl_vector_t_element_copy_assign
#define mk_sl_vector_inl_defd_copy_style mk_sl_vector_copy_use_custom
#else
#if defined mk_sl_vector_t_element_move_construct && defined mk_sl_vector_t_element_move_assign
#define mk_sl_vector_inl_defd_copy_style mk_sl_vector_copy_use_custom
#else
#define mk_sl_vector_inl_defd_copy_style mk_sl_vector_copy_use_bitblt
#endif
#endif
#endif

#if defined mk_sl_vector_t_element_construct_void && defined mk_sl_vector_t_element_destruct
#define mk_sl_vector_inl_defd_element_construct_destruct_has 1
#define mk_sl_vector_inl_defd_element_construct_void mk_sl_vector_t_element_construct_void
#define mk_sl_vector_inl_defd_element_destruct mk_sl_vector_t_element_destruct
#else
#define mk_sl_vector_inl_defd_element_construct_destruct_has 0
#endif

#if defined mk_sl_vector_t_element_copy_construct && defined mk_sl_vector_t_element_copy_assign
#define mk_sl_vector_inl_defd_element_copy_construct(a, b) mk_sl_vector_t_element_copy_construct((a), (b))
#define mk_sl_vector_inl_defd_element_copy_assign(a, b) mk_sl_vector_t_element_copy_assign((a), (b))
#else
#define mk_sl_vector_inl_defd_element_copy_construct(a, b) mk_sl_vector_inl_defd_element_bitblt_construct((a), (b))
#define mk_sl_vector_inl_defd_element_copy_assign(a, b) mk_sl_vector_inl_defd_prrw_element_bitblt_assign((a), (b))
#endif

#if defined mk_sl_vector_t_element_move_construct && defined mk_sl_vector_t_element_move_assign
#define mk_sl_vector_inl_defd_element_move_construct(a, b) mk_sl_vector_t_element_move_construct((a), (b))
#define mk_sl_vector_inl_defd_element_move_assign(a, b) mk_sl_vector_t_element_move_assign((a), (b))
#else
#define mk_sl_vector_inl_defd_element_move_construct(a, b) mk_sl_vector_inl_defd_element_copy_construct((a), (b))
#define mk_sl_vector_inl_defd_element_move_assign(a, b) mk_sl_vector_inl_defd_element_copy_assign((a), (b))
#endif

#if defined mk_sl_vector_t_element_eq
#define mk_sl_vector_inl_defd_element_eq_has 1
#define mk_sl_vector_inl_defd_element_eq mk_sl_vector_t_element_eq
#else
#define mk_sl_vector_inl_defd_element_eq_has 0
#endif


#define mk_sl_vector_inl_defd_element_prefix mk_lang_concat(mk_sl_vector_inl_defd_name, _element)
#define mk_sl_vector_inl_defd_element_s mk_lang_concat(mk_sl_vector_inl_defd_element_prefix, _s)
#define mk_sl_vector_inl_defd_element_t mk_lang_concat(mk_sl_vector_inl_defd_element_prefix, _t)
mm_per_typedef(`#define mk_sl_vector_inl_defd_element_$1 mk_lang_concat(mk_sl_vector_inl_defd_element_prefix, _$1)')

#define mk_sl_vector_inl_defd_mallocator_pt mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _pt)
#if mk_sl_vector_inl_defd_mallocator_is_global
#define mk_sl_vector_inl_defd_mallocator_init mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _init)
#define mk_sl_vector_inl_defd_mallocator_deinit mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _deinit)
#define mk_sl_vector_inl_defd_mallocator_allocate(a, b, c) mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _allocate)((b), (c)); ((mk_lang_types_void_t)((a)))
#define mk_sl_vector_inl_defd_mallocator_deallocate(a, b, c) mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _deallocate)((b), (c)); ((mk_lang_types_void_t)((a)))
#define mk_sl_vector_inl_defd_mallocator_reallocate(a, b, c, d, e) mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _reallocate)((b), (c), (d), (e)); ((mk_lang_types_void_t)((a)))
#define mk_sl_vector_inl_defd_mallocator_statistics_get_blocks_allocated mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_blocks_allocated)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_blocks_dealocated mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_blocks_dealocated)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_blocks_peak mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_blocks_peak)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_blocks_live mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_blocks_live)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_bytes_allocated mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_bytes_allocated)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_bytes_dealocated mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_bytes_dealocated)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_bytes_peak mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_bytes_peak)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_bytes_live mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_bytes_live)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_all mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_all)
#else
#define mk_sl_vector_inl_defd_mallocator_init mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _init)
#define mk_sl_vector_inl_defd_mallocator_deinit mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _deinit)
#define mk_sl_vector_inl_defd_mallocator_allocate(a, b, c) mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _allocate)((a)->m_mallocator, (b), (c))
#define mk_sl_vector_inl_defd_mallocator_deallocate(a, b, c) mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _deallocate)((a)->m_mallocator, (b), (c))
#define mk_sl_vector_inl_defd_mallocator_reallocate(a, b, c, d, e) mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _reallocate)((a)->m_mallocator, (b), (c), (d), (e))
#define mk_sl_vector_inl_defd_mallocator_statistics_get_blocks_allocated mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_blocks_allocated)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_blocks_dealocated mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_blocks_dealocated)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_blocks_peak mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_blocks_peak)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_blocks_live mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_blocks_live)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_bytes_allocated mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_bytes_allocated)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_bytes_dealocated mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_bytes_dealocated)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_bytes_peak mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_bytes_peak)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_bytes_live mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_bytes_live)
#define mk_sl_vector_inl_defd_mallocator_statistics_get_all mk_lang_concat(mk_sl_vector_inl_defd_mallocator, _statistics_get_all)
#endif

#define mk_sl_vector_inl_defd_s mk_lang_concat(mk_sl_vector_inl_defd_name, _s)
#define mk_sl_vector_inl_defd_t mk_lang_concat(mk_sl_vector_inl_defd_name, _t)
mm_per_typedef(`#define mk_sl_vector_inl_defd_$1 mk_lang_concat(mk_sl_vector_inl_defd_name, _$1)')

/*#if mk_sl_vector_inl_defd_mallocator_is_global
#define mk_sl_vector_inl_defd_mallocator_member
#define mk_sl_vector_inl_defd_mallocator_param
#define mk_sl_vector_inl_defd_mallocator_assert() mk_lang_assert(mk_lang_true)
#define mk_sl_vector_inl_defd_mallocator_assign(x) mk_lang_assert(mk_lang_true)
#define mk_sl_vector_inl_defd_mallocator_access(x)
#else
#define mk_sl_vector_inl_defd_mallocator_member mk_sl_vector_inl_defd_mallocator_pt m_mallocator;
#define mk_sl_vector_inl_defd_mallocator_param , mk_sl_vector_inl_defd_mallocator_pt const mallocator
#define mk_sl_vector_inl_defd_mallocator_assert() mk_lang_assert(mallocator)
#define mk_sl_vector_inl_defd_mallocator_assign(x) (x)->m_mallocator = mallocator
#define mk_sl_vector_inl_defd_mallocator_access(x) (x)->m_mallocator
#endif*/





#define mk_sl_vector_inl_defd_prro_verify_invariants mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_verify_invariants)
#define mk_sl_vector_inl_defd_prst_max_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _prst_max_capacity)
#define mk_sl_vector_inl_defd_prro_max_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_max_capacity)
#define mk_sl_vector_inl_defd_prro_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_capacity)
#define mk_sl_vector_inl_defd_prro_size mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_size)
#define mk_sl_vector_inl_defd_prro_sise mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_sise)
#define mk_sl_vector_inl_defd_prro_free mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_free)
#define mk_sl_vector_inl_defd_prro_is_empty mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_is_empty)
#define mk_sl_vector_inl_defd_prro_is_full mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_is_full)
#define mk_sl_vector_inl_defd_prro_data mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_data)
#define mk_sl_vector_inl_defd_prro_at mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_at)
#define mk_sl_vector_inl_defd_prro_front mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_front)
#define mk_sl_vector_inl_defd_prro_back mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_back)
#define mk_sl_vector_inl_defd_prro_eq mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_eq)
#define mk_sl_vector_inl_defd_prro_ne mk_lang_concat(mk_sl_vector_inl_defd_name, _prro_ne)
#define mk_sl_vector_inl_defd_prrw_max_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_max_capacity)
#define mk_sl_vector_inl_defd_prrw_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_capacity)
#define mk_sl_vector_inl_defd_prrw_size mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_size)
#define mk_sl_vector_inl_defd_prrw_sise mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_sise)
#define mk_sl_vector_inl_defd_prrw_free mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_free)
#define mk_sl_vector_inl_defd_prrw_is_empty mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_is_empty)
#define mk_sl_vector_inl_defd_prrw_is_full mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_is_full)
#define mk_sl_vector_inl_defd_prrw_data mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_data)
#define mk_sl_vector_inl_defd_prrw_at mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_at)
#define mk_sl_vector_inl_defd_prrw_front mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_front)
#define mk_sl_vector_inl_defd_prrw_back mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_back)
#define mk_sl_vector_inl_defd_prrw_eq mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_eq)
#define mk_sl_vector_inl_defd_prrw_ne mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_ne)
#define mk_sl_vector_inl_defd_prrw_construct mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_construct)
#define mk_sl_vector_inl_defd_prrw_element_bitblt_assign mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_element_bitblt_assign)
#define mk_sl_vector_inl_defd_prrw_elements_construct_void_last mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_elements_construct_void_last)
#define mk_sl_vector_inl_defd_prrw_elements_move_construct_many mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_elements_move_construct_many)
#define mk_sl_vector_inl_defd_prrw_elements_move_assign_many mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_elements_move_assign_many)
#define mk_sl_vector_inl_defd_prrw_elements_copy_construct_many mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_elements_copy_construct_many)
#define mk_sl_vector_inl_defd_prrw_elements_copy_assign_many mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_elements_copy_assign_many)
#define mk_sl_vector_inl_defd_prrw_elements_destroy_last mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_elements_destroy_last)
#define mk_sl_vector_inl_defd_prrw_elements_destroy_all mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_elements_destroy_all)
#define mk_sl_vector_inl_defd_prrw_destroy mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_destroy)
#define mk_sl_vector_inl_defd_prrw_reconstruct mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_reconstruct)
#define mk_sl_vector_inl_defd_prrw_reserve_at_least mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_reserve_at_least)
#define mk_sl_vector_inl_defd_prrw_reserve_additional mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_reserve_additional)
#define mk_sl_vector_inl_defd_prrw_shrink_by mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_shrink_by)
#define mk_sl_vector_inl_defd_prrw_resize_to mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_resize_to)
#define mk_sl_vector_inl_defd_prrw_grow_by mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_grow_by)
#define mk_sl_vector_inl_defd_prrw_clear mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_clear)
#define mk_sl_vector_inl_defd_prrw_push_back_move_many mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_push_back_move_many)
#define mk_sl_vector_inl_defd_prrw_push_back_copy_many mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_push_back_copy_many)
#define mk_sl_vector_inl_defd_prrw_push_back_move_single mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_push_back_move_single)
#define mk_sl_vector_inl_defd_prrw_push_back_copy_single mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_push_back_copy_single)
#define mk_sl_vector_inl_defd_prrw_pop_front_many mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_pop_front_many)
#define mk_sl_vector_inl_defd_prrw_pop_front_single mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_pop_front_single)
#define mk_sl_vector_inl_defd_prrw_pop_back_many mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_pop_back_many)
#define mk_sl_vector_inl_defd_prrw_pop_back_single mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_pop_back_single)
#define mk_sl_vector_inl_defd_prrw_erase_at mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_erase_at)
#define mk_sl_vector_inl_defd_prrw_erase_element mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_erase_element)
#define mk_sl_vector_inl_defd_prrw_erase_value mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_erase_value)
#define mk_sl_vector_inl_defd_prrw_copy_construct mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_copy_construct)
#define mk_sl_vector_inl_defd_prrw_move_construct mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_move_construct)
#define mk_sl_vector_inl_defd_prrw_copy_assign mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_copy_assign)
#define mk_sl_vector_inl_defd_prrw_move_assign mk_lang_concat(mk_sl_vector_inl_defd_name, _prrw_move_assign)





#define mk_sl_vector_inl_defd_max_capacity_e mk_lang_concat(mk_sl_vector_inl_defd_name, _max_capacity_e)
#define mk_sl_vector_inl_defd_max_capacity_t mk_lang_concat(mk_sl_vector_inl_defd_name, _max_capacity_t)
#define mk_sl_vector_inl_defd_max_capacity_v mk_lang_concat(mk_sl_vector_inl_defd_name, _max_capacity_v)
#define mk_sl_vector_inl_defd_max_capacity_d ((mk_lang_types_usize_t)((((mk_lang_types_usize_t)(mk_lang_limits_usize_max)) / ((mk_lang_types_usize_t)(sizeof(mk_sl_vector_inl_defd_element_t))))))

#define mk_sl_vector_inl_defd_st_max_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _st_max_capacity)

#define mk_sl_vector_inl_defd_ro_max_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_max_capacity)
#define mk_sl_vector_inl_defd_ro_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_capacity)
#define mk_sl_vector_inl_defd_ro_size mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_size)
#define mk_sl_vector_inl_defd_ro_sise mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_sise)
#define mk_sl_vector_inl_defd_ro_free mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_free)
#define mk_sl_vector_inl_defd_ro_is_empty mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_is_empty)
#define mk_sl_vector_inl_defd_ro_is_full mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_is_full)
#define mk_sl_vector_inl_defd_ro_at mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_at)
#define mk_sl_vector_inl_defd_ro_data mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_data)
#define mk_sl_vector_inl_defd_ro_front mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_front)
#define mk_sl_vector_inl_defd_ro_back mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_back)
#define mk_sl_vector_inl_defd_ro_eq mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_eq)
#define mk_sl_vector_inl_defd_ro_ne mk_lang_concat(mk_sl_vector_inl_defd_name, _ro_ne)

#define mk_sl_vector_inl_defd_rw_max_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_max_capacity)
#define mk_sl_vector_inl_defd_rw_capacity mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_capacity)
#define mk_sl_vector_inl_defd_rw_size mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_size)
#define mk_sl_vector_inl_defd_rw_sise mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_sise)
#define mk_sl_vector_inl_defd_rw_free mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_free)
#define mk_sl_vector_inl_defd_rw_is_empty mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_is_empty)
#define mk_sl_vector_inl_defd_rw_is_full mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_is_full)
#define mk_sl_vector_inl_defd_rw_at mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_at)
#define mk_sl_vector_inl_defd_rw_data mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_data)
#define mk_sl_vector_inl_defd_rw_front mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_front)
#define mk_sl_vector_inl_defd_rw_back mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_back)
#define mk_sl_vector_inl_defd_rw_eq mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_eq)
#define mk_sl_vector_inl_defd_rw_ne mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_ne)

#define mk_sl_vector_inl_defd_rw_construct mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_construct)
#define mk_sl_vector_inl_defd_rw_copy_construct mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_copy_construct)
#define mk_sl_vector_inl_defd_rw_move_construct mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_move_construct)
#define mk_sl_vector_inl_defd_rw_destroy mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_destroy)
#define mk_sl_vector_inl_defd_rw_copy_assign mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_copy_assign)
#define mk_sl_vector_inl_defd_rw_move_assign mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_move_assign)
#define mk_sl_vector_inl_defd_rw_reconstruct mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_reconstruct)
#define mk_sl_vector_inl_defd_rw_reserve_at_least mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_reserve_at_least)
#define mk_sl_vector_inl_defd_rw_reserve_additional mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_reserve_additional)
#define mk_sl_vector_inl_defd_rw_shrink_by mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_shrink_by)
#define mk_sl_vector_inl_defd_rw_resize_to mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_resize_to)
#define mk_sl_vector_inl_defd_rw_grow_by mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_grow_by)
#define mk_sl_vector_inl_defd_rw_clear mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_clear)
#define mk_sl_vector_inl_defd_rw_push_back_move_many mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_push_back_move_many)
#define mk_sl_vector_inl_defd_rw_push_back_copy_many mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_push_back_copy_many)
#define mk_sl_vector_inl_defd_rw_push_back_move_single mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_push_back_move_single)
#define mk_sl_vector_inl_defd_rw_push_back_copy_single mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_push_back_copy_single)
#define mk_sl_vector_inl_defd_rw_pop_front_many mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_pop_front_many)
#define mk_sl_vector_inl_defd_rw_pop_front_single mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_pop_front_single)
#define mk_sl_vector_inl_defd_rw_pop_back_many mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_pop_back_many)
#define mk_sl_vector_inl_defd_rw_pop_back_single mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_pop_back_single)
#define mk_sl_vector_inl_defd_rw_erase_at mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_erase_at)
#define mk_sl_vector_inl_defd_rw_erase_element mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_erase_element)
#define mk_sl_vector_inl_defd_rw_erase_value mk_lang_concat(mk_sl_vector_inl_defd_name, _rw_erase_value)
