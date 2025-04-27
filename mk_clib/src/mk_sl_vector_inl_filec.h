#include "mk_lang_concat.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_max.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_pow2.h"
#include "mk_lang_types.h"


#include "mk_sl_vector_inl_defd.h"


#if mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_bitblasting
#define mk_sl_vector_inl_filec_memcpy_name mk_lang_concat(mk_sl_vector_inl_defd_name, _zzz_element_memcpy)
#define mk_sl_vector_inl_filec_memcpy_fn mk_lang_concat(mk_sl_vector_inl_filec_memcpy_name, _fn)
#define mk_lang_memcpy1_t_name mk_sl_vector_inl_filec_memcpy_name
#define mk_lang_memcpy1_t_type mk_sl_vector_inl_defd_element_t
#include "mk_lang_memcpy1_inl_fileh.h"
#include "mk_lang_memcpy1_inl_filec.h"
#include "mk_lang_memcpy1_inl_fileu.h"
#endif

#define mk_sl_vector_inl_filec_overlap_name mk_lang_concat(mk_sl_vector_inl_defd_name, _zzz_element_overlap)
#define mk_sl_vector_inl_filec_overlap_fn mk_lang_concat(mk_sl_vector_inl_filec_overlap_name, _fn)
#define mk_lang_overlap_t_name mk_sl_vector_inl_filec_overlap_name
#define mk_lang_overlap_t_type mk_sl_vector_inl_defd_element_t
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#include "mk_lang_overlap_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_vector_inl_defd_prro_verify_invariants(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;

	mk_lang_assert(vector);

	#include "mk_lang_warning_msvc_push_c4296.h"
	gud = mk_lang_true;
	gud &= vector->m_buffer || vector->m_capacity == 0;
	gud &= vector->m_capacity >= 0;
	gud &= vector->m_size >= 0;
	gud &= vector->m_capacity <= mk_sl_vector_inl_defd_max_capacity_d;
	gud &= vector->m_size <= mk_sl_vector_inl_defd_max_capacity_d;
	gud &= vector->m_size <= vector->m_capacity;
	#include "mk_lang_warning_msvc_pop.h"
	return gud;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_st_max_capacity(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	ret = mk_sl_vector_inl_defd_max_capacity_d;
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_max_capacity(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	((mk_lang_types_void_t)(vector));
	ret = mk_sl_vector_inl_defd_st_max_capacity();
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_capacity(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = vector->m_capacity;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_size(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = vector->m_size;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_free(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = mk_sl_vector_inl_defd_ro_capacity(vector) - mk_sl_vector_inl_defd_ro_size(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_ro_is_empty(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = mk_sl_vector_inl_defd_ro_size(vector) == 0;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_ro_is_full(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = mk_sl_vector_inl_defd_ro_free(vector) == 0;
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_at(mk_sl_vector_inl_defd_pct const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx < mk_sl_vector_inl_defd_ro_size(vector));
	#include "mk_lang_warning_msvc_pop.h"

	ret = &vector->m_buffer[idx];
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_data(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(mk_sl_vector_inl_defd_ro_capacity(vector) != 0);

	ret = &vector->m_buffer[0];
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_front(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));

	ret = mk_sl_vector_inl_defd_ro_at(vector, 0);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_back(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));

	ret = mk_sl_vector_inl_defd_ro_at(vector, mk_sl_vector_inl_defd_ro_size(vector) - 1);
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_rw_max_capacity(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_ro_max_capacity(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_rw_capacity(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_ro_capacity(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_rw_size(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_ro_size(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_rw_free(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_ro_free(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_rw_is_empty(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_ro_is_empty(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_rw_is_full(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_ro_is_full(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_at(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	return ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_at(vector, idx)));
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_data(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_data(vector)));
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_front(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_front(vector)));
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_back(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_back(vector)));
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_destruct_last_count(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if defined mk_sl_vector_t_element_destruct
	mk_lang_types_usize_t size;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_sl_vector_inl_defd_element_pt element;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_msvc_pop.h"

	size = mk_sl_vector_inl_defd_rw_size(vector);
	n = count;
	for(i = 0; i != n; ++i)
	{
		idx = (size - n) + i;
		element = mk_sl_vector_inl_defd_rw_at(vector, idx); mk_lang_assert(element);
		err = mk_sl_vector_inl_defd_element_destruct(element); mk_lang_check_rereturn(err);
	}
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(vector));
	((mk_lang_types_void_t)(count));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_destruct_all(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	err = mk_sl_vector_inl_defd_prrw_destruct_last_count(vector, mk_sl_vector_inl_defd_rw_size(vector)); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_move_assign_single(mk_sl_vector_inl_defd_element_pt const dst, mk_sl_vector_inl_defd_element_pt const src) mk_lang_noexcept
{
#if mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_bitblasting
	mk_lang_assert(dst);
	mk_lang_assert(src);

	((mk_lang_types_void_t)(dst));
	((mk_lang_types_void_t)(src));
	mk_lang_assert(mk_lang_false);
	return 0;
#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_type_suffix
	mk_lang_check_todo();
#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_custom
	mk_lang_check_todo();
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_move_assign_many(mk_sl_vector_inl_defd_element_pt const src, mk_sl_vector_inl_defd_element_pt const dst, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(src || count == 0);
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	#include "mk_lang_warning_msvc_pop.h"

	#if mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_bitblasting
	mk_sl_vector_inl_filec_memcpy_fn(dst, src, count);
	#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_type_suffix
	mk_lang_check_todo();
	#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_custom
	mk_lang_check_todo();
	#else
	#endif
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_move_construct_single(mk_sl_vector_inl_defd_element_pt const src, mk_sl_vector_inl_defd_element_pt const dst) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(src);
	mk_lang_assert(dst);

	#if mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_bitblasting
	((mk_lang_types_void_t)(err));
	mk_lang_assert(mk_lang_false);
	#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_type_suffix
	err = mk_sl_vector_inl_defd_element_move_construct(src, dst); mk_lang_check_rereturn(err);
	#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_custom
	err = mk_sl_vector_inl_defd_element_move_construct(src, dst); mk_lang_check_rereturn(err);
	#else
	#error xxxxxxxxxx
	#endif
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_move_construct_many(mk_sl_vector_inl_defd_element_pt const src, mk_sl_vector_inl_defd_element_pt const dst, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(src || count == 0);
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	#include "mk_lang_warning_msvc_pop.h"

	#if mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_bitblasting
	((mk_lang_types_void_t)(n));
	((mk_lang_types_void_t)(i));
	((mk_lang_types_void_t)(err));
	mk_lang_assert(mk_lang_false);
	#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_type_suffix
	mk_lang_check_todo();
	((mk_lang_types_void_t)(n));
	((mk_lang_types_void_t)(i));
	((mk_lang_types_void_t)(err));
	mk_lang_assert(mk_lang_false);
	#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_custom
	mk_lang_check_todo();
	((mk_lang_types_void_t)(n));
	((mk_lang_types_void_t)(i));
	((mk_lang_types_void_t)(err));
	mk_lang_assert(mk_lang_false);
	#else
	#error xxxxxxxxxx
	#endif
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_copy_construct_many(mk_sl_vector_inl_defd_element_pt const dst, mk_sl_vector_inl_defd_element_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	#include "mk_lang_warning_msvc_pop.h"

	#if mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_bitblasting
	mk_sl_vector_inl_filec_memcpy_fn(dst, src, count);
	#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_type_suffix
	mk_lang_check_todo();
	#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_custom
	mk_lang_check_todo();
	#else
	#error xxxxxxxxxx
	#endif
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_construct_last_count(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if defined mk_sl_vector_t_element_construct_void
	mk_lang_types_usize_t size;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_sl_vector_inl_defd_element_pt element;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(mk_sl_vector_inl_defd_rw_size(vector) >= count);
	#include "mk_lang_warning_msvc_pop.h"

	size = mk_sl_vector_inl_defd_rw_size(vector);
	n = count;
	for(i = 0; i != n; ++i)
	{
		idx = (size - n) + i;
		element = mk_sl_vector_inl_defd_rw_at(vector, idx); mk_lang_assert(element);
		err = mk_sl_vector_inl_defd_element_construct_void(element); mk_lang_check_rereturn(err);
	}
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(mk_sl_vector_inl_defd_rw_size(vector) >= count);
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(vector));
	((mk_lang_types_void_t)(count));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
#endif
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_construct(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_assert(vector);

	vector->m_buffer = mk_lang_null;
	vector->m_capacity = 0;
	vector->m_size = 0;
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_destroy(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	err = mk_sl_vector_inl_defd_prrw_destruct_all(vector); mk_lang_check_rereturn(err);
	err = mk_sl_vector_inl_defd_mallocatorg_deallocate(vector->m_buffer, vector->m_capacity * sizeof(mk_sl_vector_inl_defd_element_t)); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_reserve_at_least(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt old_buffer;
	mk_lang_types_usize_t old_capacity;
	mk_lang_types_usize_t old_size;
	mk_sl_vector_inl_defd_element_pt new_buffer;
	mk_lang_types_usize_t new_capacity;
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt new_mem;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	#include "mk_lang_warning_msvc_pop.h"

	old_buffer = vector->m_buffer;
	old_capacity = vector->m_capacity;
	old_size = vector->m_size;
	if(count > old_capacity)
	{
		if(old_buffer)
		{
			new_capacity = old_capacity * 2;
			new_capacity = mk_lang_max(new_capacity, count);
			new_capacity = mk_lang_pow2_roundup(new_capacity);
			#if mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_bitblasting
			err = mk_sl_vector_inl_defd_mallocatorg_reallocate(old_buffer, old_capacity * sizeof(mk_sl_vector_inl_defd_element_t), new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
			vector->m_buffer = new_buffer;
			vector->m_capacity = new_capacity;
			#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_type_suffix
			err = mk_sl_vector_inl_defd_mallocatorg_allocate(new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
			err = mk_sl_vector_inl_defd_prrw_move_construct_many(old_buffer, new_buffer, old_size);
			vector->m_buffer = new_buffer;
			vector->m_capacity = new_capacity;
			#elif mk_sl_vector_inl_defd_copy == mk_sl_vector_cpy_use_custom
			err = mk_sl_vector_inl_defd_mallocatorg_allocate(new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
			err = mk_sl_vector_inl_defd_prrw_move_construct_many(old_buffer, new_buffer, old_size);
			vector->m_buffer = new_buffer;
			vector->m_capacity = new_capacity;
			#else
			#error xxxxxxxxxx
			#endif
		}
		else
		{
			new_capacity = 4;
			new_capacity = mk_lang_max(new_capacity, count);
			new_capacity = mk_lang_pow2_roundup(new_capacity);
			err = mk_sl_vector_inl_defd_mallocatorg_allocate(new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
			vector->m_buffer = new_buffer;
			vector->m_capacity = new_capacity;
		}
	}
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_reserve_additional(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d - mk_sl_vector_inl_defd_ro_capacity(vector));
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_rw_reserve_at_least(vector, mk_sl_vector_inl_defd_rw_size(vector) + count); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_shrink_by(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_prrw_destruct_last_count(vector, count); mk_lang_check_rereturn(err);
	vector->m_size -= count;
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_resize_to(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t size;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	#include "mk_lang_warning_msvc_pop.h"

	size = mk_sl_vector_inl_defd_rw_size(vector);
	if(count > size)
	{
		err = mk_sl_vector_inl_defd_rw_reserve_at_least(vector, count); mk_lang_check_rereturn(err);
		vector->m_size = count;
		err = mk_sl_vector_inl_defd_prrw_construct_last_count(vector, count - size); mk_lang_check_rereturn(err);
	}
	else if(count < size)
	{
		err = mk_sl_vector_inl_defd_rw_shrink_by(vector, size - count); mk_lang_check_rereturn(err);
	}
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_clear(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	err = mk_sl_vector_inl_defd_rw_resize_to(vector, 0); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_push_back_move_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d - mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		if(count <= mk_sl_vector_inl_defd_rw_free(vector))
		{
			mk_sl_vector_inl_defd_element_pt end;
			mk_lang_types_sint_t err;

			end = mk_sl_vector_inl_defd_rw_at(vector, mk_sl_vector_inl_defd_rw_size(vector)); mk_lang_assert(end);
			err = mk_sl_vector_inl_defd_prrw_move_construct_many(elements, end, count);
			vector->m_size += count;
		}
		else
		{
			if(!mk_sl_vector_inl_filec_overlap_fn(elements, count, vector->m_buffer, vector->m_size))
			{
				mk_lang_types_sint_t err;
				mk_sl_vector_inl_defd_element_pt end;

				err = mk_sl_vector_inl_defd_rw_reserve_additional(vector, count); mk_lang_check_rereturn(err);
				end = mk_sl_vector_inl_defd_rw_at(vector, mk_sl_vector_inl_defd_rw_size(vector)); mk_lang_assert(end);
				err = mk_sl_vector_inl_defd_prrw_move_construct_many(elements, end, count);
				vector->m_size += count;
			}
			else
			{
				mk_sl_vector_inl_defd_element_pt old_buffer;
				mk_lang_types_usize_t old_capacity;
				mk_lang_types_usize_t old_size;
				mk_lang_types_usize_t new_size;
				mk_lang_types_usize_t new_capacity;
				mk_lang_types_sint_t err;
				mk_lang_types_void_pt new_mem;
				mk_sl_vector_inl_defd_element_pt new_buffer;
				mk_sl_vector_inl_defd_element_pt end;

				old_buffer = vector->m_buffer;
				old_capacity = vector->m_capacity;
				old_size = vector->m_size;
				new_size = old_size + count;
				new_capacity = old_capacity * 2;
				new_capacity = mk_lang_max(new_capacity, 4);
				new_capacity = mk_lang_max(new_capacity, new_size);
				new_capacity = mk_lang_pow2_roundup(new_capacity);
				err = mk_sl_vector_inl_defd_mallocatorg_allocate(new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
				err = mk_sl_vector_inl_defd_prrw_move_construct_many(old_buffer, new_buffer, old_size); mk_lang_check_rereturn(err);
				end = new_buffer + old_size;
				err = mk_sl_vector_inl_defd_prrw_move_construct_many(elements, end, count);
				err = mk_sl_vector_inl_defd_mallocatorg_deallocate(old_buffer, old_capacity * sizeof(mk_sl_vector_inl_defd_element_t)); mk_lang_check_rereturn(err);
				vector->m_buffer = new_buffer;
				vector->m_capacity = new_capacity;
				vector->m_size = new_size;
			}
		}
	}
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_push_back_copy_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d - mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		if(count <= mk_sl_vector_inl_defd_rw_free(vector))
		{
			mk_sl_vector_inl_defd_element_pt end;
			mk_lang_types_sint_t err;

			end = &mk_sl_vector_inl_defd_rw_data(vector)[mk_sl_vector_inl_defd_rw_size(vector)]; mk_lang_assert(end);
			err = mk_sl_vector_inl_defd_prrw_copy_construct_many(end, elements, count);
			vector->m_size += count;
		}
		else
		{
			if(!mk_sl_vector_inl_filec_overlap_fn(elements, count, vector->m_buffer, vector->m_size))
			{
				mk_lang_types_sint_t err;
				mk_sl_vector_inl_defd_element_pt end;

				err = mk_sl_vector_inl_defd_rw_reserve_additional(vector, count); mk_lang_check_rereturn(err);
				end = &mk_sl_vector_inl_defd_rw_data(vector)[mk_sl_vector_inl_defd_rw_size(vector)]; mk_lang_assert(end);
				err = mk_sl_vector_inl_defd_prrw_copy_construct_many(end, elements, count);
				vector->m_size += count;
			}
			else
			{
				mk_sl_vector_inl_defd_element_pt old_buffer;
				mk_lang_types_usize_t old_capacity;
				mk_lang_types_usize_t old_size;
				mk_lang_types_usize_t new_size;
				mk_lang_types_usize_t new_capacity;
				mk_lang_types_sint_t err;
				mk_lang_types_void_pt new_mem;
				mk_sl_vector_inl_defd_element_pt new_buffer;
				mk_sl_vector_inl_defd_element_pt end;

				old_buffer = vector->m_buffer;
				old_capacity = vector->m_capacity;
				old_size = vector->m_size;
				new_size = old_size + count;
				new_capacity = old_capacity * 2;
				new_capacity = mk_lang_max(new_capacity, 4);
				new_capacity = mk_lang_max(new_capacity, new_size);
				new_capacity = mk_lang_pow2_roundup(new_capacity);
				err = mk_sl_vector_inl_defd_mallocatorg_allocate(new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
				err = mk_sl_vector_inl_defd_prrw_move_construct_many(old_buffer, new_buffer, old_size); mk_lang_check_rereturn(err);
				end = new_buffer + old_size;
				err = mk_sl_vector_inl_defd_prrw_copy_construct_many(end, elements, count);
				err = mk_sl_vector_inl_defd_mallocatorg_deallocate(old_buffer, old_capacity * sizeof(mk_sl_vector_inl_defd_element_t)); mk_lang_check_rereturn(err);
				vector->m_buffer = new_buffer;
				vector->m_capacity = new_capacity;
				vector->m_size = new_size;
			}
		}
	}
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_push_back_move_single(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(element);
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_rw_push_back_move_many(vector, element, 1); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_push_back_copy_single(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(element);

	err = mk_sl_vector_inl_defd_rw_push_back_copy_many(vector, element, 1); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_pop_back_many(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_rw_shrink_by(vector, count); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_pop_back_single(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_rw_shrink_by(vector, 1); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_erase_at(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx < mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_msvc_pop.h"

	if(idx != mk_sl_vector_inl_defd_rw_size(vector) - 1)
	{
		err = mk_sl_vector_inl_defd_prrw_move_assign_single(mk_sl_vector_inl_defd_rw_back(vector), mk_sl_vector_inl_defd_rw_at(vector, idx)); mk_lang_check_rereturn(err);
	}
	err = mk_sl_vector_inl_defd_rw_pop_back_single(vector); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_erase_element(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(element);
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	mk_lang_assert(element >= &vector->m_buffer[0] && element <= &vector->m_buffer[vector->m_size - 1]);
	mk_lang_assert(mk_sl_vector_inl_filec_overlap_fn(element, 1, vector->m_buffer, 1));

	if(element != &vector->m_buffer[vector->m_size - 1])
	{
		err = mk_sl_vector_inl_defd_prrw_move_assign_single(((mk_sl_vector_inl_defd_element_pt)(element)), mk_sl_vector_inl_defd_rw_back(vector)); mk_lang_check_rereturn(err);
	}
	err = mk_sl_vector_inl_defd_rw_pop_back_single(vector); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}


#undef mk_sl_vector_inl_filec_memcpy_name
#undef mk_sl_vector_inl_filec_memcpy_fn

#undef mk_sl_vector_inl_filec_overlap_name
#undef mk_sl_vector_inl_filec_overlap_fn


#include "mk_sl_vector_inl_defu.h"
