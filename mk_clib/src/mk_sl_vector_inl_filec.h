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


#define mk_sl_vector_inl_filec_memcpy_name mk_lang_concat(mk_sl_vector_inl_defd_name, _zzz_element_memcpy)
#define mk_sl_vector_inl_filec_memcpy_fn mk_lang_concat(mk_sl_vector_inl_filec_memcpy_name, _fn)
#define mk_lang_memcpy1_t_name mk_sl_vector_inl_filec_memcpy_name
#define mk_lang_memcpy1_t_type mk_sl_vector_inl_defd_element_t
#include "mk_lang_memcpy1_inl_fileh.h"
#include "mk_lang_memcpy1_inl_filec.h"
#include "mk_lang_memcpy1_inl_fileu.h"

#define mk_sl_vector_inl_filec_memmov_name mk_lang_concat(mk_sl_vector_inl_defd_name, _zzz_element_memmov)
#define mk_sl_vector_inl_filec_memmov_fn mk_lang_concat(mk_sl_vector_inl_filec_memmov_name, _fn)
#define mk_lang_memmov1_t_name mk_sl_vector_inl_filec_memmov_name
#define mk_lang_memmov1_t_type mk_sl_vector_inl_defd_element_t
#include "mk_lang_memmov1_inl_fileh.h"
#include "mk_lang_memmov1_inl_filec.h"
#include "mk_lang_memmov1_inl_fileu.h"

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
	#include "mk_lang_warning_clang_push_tautological_unsigned_zero_compare.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	gud = mk_lang_true;
	gud &= vector->m_buffer || vector->m_capacity == 0;
	gud &= vector->m_capacity == 0 || vector->m_buffer;
	gud &= vector->m_capacity >= 0;
	gud &= vector->m_size >= 0;
	gud &= vector->m_capacity <= mk_sl_vector_inl_defd_max_capacity_d;
	gud &= vector->m_size <= mk_sl_vector_inl_defd_max_capacity_d;
	gud &= vector->m_size <= vector->m_capacity;
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_clang_pop.h"
	#include "mk_lang_warning_msvc_pop.h"
	return gud;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_vector_inl_defd_prst_max_capacity(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	ret = mk_sl_vector_inl_defd_max_capacity_d;
	return ret;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_vector_inl_defd_prro_max_capacity(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	((mk_lang_types_void_t)(vector));
	ret = mk_sl_vector_inl_defd_prst_max_capacity();

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_vector_inl_defd_prro_capacity(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = vector->m_capacity;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_vector_inl_defd_prro_size(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = vector->m_size;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prro_sise(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t size mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	size = vector->m_size;
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	ret = ((mk_lang_types_sint_t)(size));

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_vector_inl_defd_prro_free(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = mk_sl_vector_inl_defd_prro_capacity(vector) - mk_sl_vector_inl_defd_prro_size(vector);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_vector_inl_defd_prro_is_empty(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = mk_sl_vector_inl_defd_prro_size(vector) == 0;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_vector_inl_defd_prro_is_full(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = mk_sl_vector_inl_defd_prro_free(vector) == 0;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_prro_data(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = vector->m_buffer;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_prro_at(mk_sl_vector_inl_defd_pct const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx < mk_sl_vector_inl_defd_ro_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	ret = &vector->m_buffer[idx];

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_prro_front(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));

	ret = mk_sl_vector_inl_defd_prro_at(vector, 0);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_prro_back(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));

	ret = mk_sl_vector_inl_defd_prro_at(vector, mk_sl_vector_inl_defd_prro_size(vector) - 1);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

#if mk_sl_vector_inl_defd_element_eq_has
mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_vector_inl_defd_prro_eq(mk_sl_vector_inl_defd_pct const vector, mk_sl_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t m;
	mk_lang_types_usize_t i;
	mk_sl_vector_inl_defd_element_pct ea;
	mk_sl_vector_inl_defd_element_pct eb;
	mk_lang_types_bool_t eq;

	mk_lang_assert(vector);
	mk_lang_assert(other);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(other));

	ret = mk_lang_false;
	n = mk_sl_vector_inl_defd_prro_size(vector);
	m = mk_sl_vector_inl_defd_prro_size(other);
	if(n == m)
	{
		ret = mk_lang_true;
		for(i = 0; i != n; ++i)
		{
			ea = mk_sl_vector_inl_defd_prro_at(vector, i); mk_lang_assert(ea);
			eb = mk_sl_vector_inl_defd_prro_at(other, i); mk_lang_assert(eb);
			eq = mk_sl_vector_inl_defd_element_eq(ea, eb);
			if(!eq)
			{
				ret = mk_lang_false;
				break;
			}
		}
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(other));
	return ret;
}
#else
mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_vector_inl_defd_prro_eq(mk_sl_vector_inl_defd_pct const vector, mk_sl_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(other);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(other));

	ret = mk_lang_false;
	mk_lang_assert_false();

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(other));
	return ret;
}
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_vector_inl_defd_prro_ne(mk_sl_vector_inl_defd_pct const vector, mk_sl_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(other);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(other));

	ret = !mk_sl_vector_inl_defd_prro_eq(vector, other);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(other));
	return ret;
}


mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_vector_inl_defd_prrw_max_capacity(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	((mk_lang_types_void_t)(vector));
	ret = mk_sl_vector_inl_defd_prst_max_capacity();

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_vector_inl_defd_prrw_capacity(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = vector->m_capacity;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_vector_inl_defd_prrw_size(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = vector->m_size;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_sise(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t size mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	size = vector->m_size;
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	ret = ((mk_lang_types_sint_t)(size));

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_vector_inl_defd_prrw_free(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = mk_sl_vector_inl_defd_prrw_capacity(vector) - mk_sl_vector_inl_defd_prrw_size(vector);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_vector_inl_defd_prrw_is_empty(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = mk_sl_vector_inl_defd_prrw_size(vector) == 0;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_vector_inl_defd_prrw_is_full(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = mk_sl_vector_inl_defd_prrw_free(vector) == 0;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_prrw_data(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	ret = vector->m_buffer;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_prrw_at(mk_sl_vector_inl_defd_pct const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt ret;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx < mk_sl_vector_inl_defd_ro_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	ret = &vector->m_buffer[idx];

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_prrw_front(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));

	ret = mk_sl_vector_inl_defd_prrw_at(vector, 0);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_prrw_back(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt ret;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_ro_is_empty(vector));

	ret = mk_sl_vector_inl_defd_prrw_at(vector, mk_sl_vector_inl_defd_prrw_size(vector) - 1);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return ret;
}


#if mk_sl_vector_inl_defd_mallocator_is_lokal
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_construct(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_mallocator_pt const mallocator) mk_lang_noexcept
#else
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_construct(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
#endif
{
	mk_lang_assert(vector);
	#if mk_sl_vector_inl_defd_mallocator_is_lokal
	mk_lang_assert(mallocator);
	#endif

	vector->m_buffer = mk_lang_null;
	vector->m_capacity = 0;
	vector->m_size = 0;
	#if mk_sl_vector_inl_defd_mallocator_is_lokal
	vector->m_mallocator = mallocator;
	#endif

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_element_bitblt_assign(mk_sl_vector_inl_defd_element_pt const dst, mk_sl_vector_inl_defd_element_pct const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_elements_construct_void_last(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_sl_vector_inl_defd_element_construct_destruct_has
	mk_lang_types_usize_t size;
	mk_sl_vector_inl_defd_element_pt data;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_prro_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	size = mk_sl_vector_inl_defd_prrw_size(vector);
	data = mk_sl_vector_inl_defd_prrw_data(vector);
	n = count;
	for(i = 0; i != n; ++i)
	{
		idx = (size - count) + i;
		#if mk_sl_vector_inl_defd_mallocator_is_lokal
		err = mk_sl_vector_inl_defd_element_construct_void(&data[idx], vector->m_mallocator); mk_lang_check_rereturn(err);
		#else
		err = mk_sl_vector_inl_defd_element_construct_void(&data[idx]); mk_lang_check_rereturn(err);
		#endif
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_prro_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(vector));
	((mk_lang_types_void_t)(count));

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
#endif
}

#if mk_sl_vector_inl_defd_copy_style == mk_sl_vector_copy_use_bitblt
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_elements_move_construct_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const dst, mk_sl_vector_inl_defd_element_pt const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(vector));
	mk_sl_vector_inl_filec_memcpy_fn(dst, src, count);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}
#elif mk_sl_vector_inl_defd_copy_style == mk_sl_vector_copy_use_custom
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_elements_move_construct_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const dst, mk_sl_vector_inl_defd_element_pt const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(vector));
	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_sl_vector_inl_defd_element_move_construct(&dst[i], &src[i]); mk_lang_check_rereturn(err);
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}
#else
#error xxxxxxxxxx
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_elements_move_assign_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const dst, mk_sl_vector_inl_defd_element_pt const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_sl_vector_inl_defd_copy_style == mk_sl_vector_copy_use_bitblt
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(vector));
	mk_sl_vector_inl_filec_memmov_fn(dst, src, count);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
#elif mk_sl_vector_inl_defd_copy_style == mk_sl_vector_copy_use_custom
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(vector));
	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_sl_vector_inl_defd_element_move_assign(&dst[i], &src[i]); mk_lang_check_rereturn(err);
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
#else
#error xxxxxxxxxx
#endif
}

#if mk_sl_vector_inl_defd_copy_style == mk_sl_vector_copy_use_bitblt
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_elements_copy_construct_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const dst, mk_sl_vector_inl_defd_element_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(vector));
	mk_sl_vector_inl_filec_memcpy_fn(dst, src, count);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}
#elif mk_sl_vector_inl_defd_copy_style == mk_sl_vector_copy_use_custom
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_elements_copy_construct_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const dst, mk_sl_vector_inl_defd_element_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(vector));
	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_sl_vector_inl_defd_element_copy_construct(&dst[i], &src[i]); mk_lang_check_rereturn(err);
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}
#else
#error xxxxxxxxxx
#endif

#if mk_sl_vector_inl_defd_element_construct_destruct_has
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_elements_destroy_last(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t size;
	mk_sl_vector_inl_defd_element_pt data;
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_usize_t idx;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_prro_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	size = mk_sl_vector_inl_defd_prrw_size(vector);
	data = mk_sl_vector_inl_defd_prrw_data(vector);
	n = count;
	for(i = 0; i != n; ++i)
	{
		idx = (size - 1) - i;
		err = mk_sl_vector_inl_defd_element_destruct(&data[idx]); mk_lang_check_rereturn(err);
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}
#else
mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_elements_destroy_last(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_prro_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(vector));
	((mk_lang_types_void_t)(count));

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}
#endif

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_elements_destroy_all(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	err = mk_sl_vector_inl_defd_prrw_elements_destroy_last(vector, mk_sl_vector_inl_defd_prro_size(vector)); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_destroy(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	err = mk_sl_vector_inl_defd_prrw_elements_destroy_all(vector); mk_lang_check_rereturn(err);
	err = mk_sl_vector_inl_defd_mallocator_deallocate(vector, vector->m_buffer, vector->m_capacity * sizeof(mk_sl_vector_inl_defd_element_t)); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_reconstruct(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	#if mk_sl_vector_inl_defd_mallocator_is_lokal
	mk_sl_vector_inl_defd_mallocator_pt mallocator;
	#endif

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	#if mk_sl_vector_inl_defd_mallocator_is_lokal
	mallocator = vector->m_mallocator;
	#endif
	err = mk_sl_vector_inl_defd_prrw_destroy(vector); mk_lang_check_rereturn(err);
	#if mk_sl_vector_inl_defd_mallocator_is_lokal
	err = mk_sl_vector_inl_defd_prrw_construct(vector, mallocator); mk_lang_check_rereturn(err);
	#else
	err = mk_sl_vector_inl_defd_prrw_construct(vector); mk_lang_check_rereturn(err);
	#endif

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_reserve_at_least(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt old_buffer;
	mk_lang_types_usize_t old_capacity;
	mk_sl_vector_inl_defd_element_pt new_buffer;
	mk_lang_types_usize_t new_capacity;
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt new_mem;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	old_buffer = vector->m_buffer;
	old_capacity = vector->m_capacity;
	if(count > old_capacity)
	{
		if(old_buffer)
		{
			new_capacity = old_capacity * 2;
			new_capacity = mk_lang_max(new_capacity, count);
			new_capacity = mk_lang_pow2_roundup(new_capacity);
			#if mk_sl_vector_inl_defd_copy_style == mk_sl_vector_copy_use_bitblt
			err = mk_sl_vector_inl_defd_mallocator_reallocate(vector, old_buffer, old_capacity * sizeof(mk_sl_vector_inl_defd_element_t), new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
			vector->m_buffer = new_buffer;
			vector->m_capacity = new_capacity;
			#elif mk_sl_vector_inl_defd_copy_style == mk_sl_vector_copy_use_custom
			err = mk_sl_vector_inl_defd_mallocator_allocate(vector, new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
			err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, new_buffer, old_buffer, vector->m_size);
			err = mk_sl_vector_inl_defd_mallocator_deallocate(vector, old_buffer, old_capacity * sizeof(mk_sl_vector_inl_defd_element_t)); mk_lang_check_rereturn(err);
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
			err = mk_sl_vector_inl_defd_mallocator_allocate(vector, new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
			vector->m_buffer = new_buffer;
			vector->m_capacity = new_capacity;
		}
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_reserve_additional(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d - mk_sl_vector_inl_defd_prro_capacity(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_prrw_reserve_at_least(vector, mk_sl_vector_inl_defd_prrw_size(vector) + count); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_shrink_by(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_prrw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_prrw_elements_destroy_last(vector, count); mk_lang_check_rereturn(err);
	vector->m_size -= count;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_resize_to(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t size;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	size = mk_sl_vector_inl_defd_prrw_size(vector);
	if(count > size)
	{
		err = mk_sl_vector_inl_defd_prrw_reserve_at_least(vector, count); mk_lang_check_rereturn(err);
		vector->m_size = count;
		err = mk_sl_vector_inl_defd_prrw_elements_construct_void_last(vector, count - size); mk_lang_check_rereturn(err);
	}
	else if(count < size)
	{
		err = mk_sl_vector_inl_defd_prrw_shrink_by(vector, size - count); mk_lang_check_rereturn(err);
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_grow_by(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t size;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d - mk_sl_vector_inl_defd_prrw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	size = mk_sl_vector_inl_defd_prrw_size(vector);
	size = size + count;
	err = mk_sl_vector_inl_defd_prrw_resize_to(vector, size); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_clear(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));

	err = mk_sl_vector_inl_defd_prrw_resize_to(vector, 0); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_push_back_move_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d - mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		if(count <= mk_sl_vector_inl_defd_rw_free(vector))
		{
			mk_sl_vector_inl_defd_element_pt end;
			mk_lang_types_sint_t err;

			end = mk_sl_vector_inl_defd_rw_data(vector) + mk_sl_vector_inl_defd_rw_size(vector); mk_lang_assert(end);
			err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, end, elements, count); mk_lang_check_rereturn(err);
			vector->m_size += count;
		}
		else
		{
			if(!mk_sl_vector_inl_filec_overlap_fn(elements, count, vector->m_buffer, vector->m_size))
			{
				mk_lang_types_sint_t err;
				mk_sl_vector_inl_defd_element_pt end;

				err = mk_sl_vector_inl_defd_rw_reserve_additional(vector, count); mk_lang_check_rereturn(err);
				end = mk_sl_vector_inl_defd_rw_data(vector) + mk_sl_vector_inl_defd_rw_size(vector); mk_lang_assert(end);
				err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, end, elements, count);
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
				err = mk_sl_vector_inl_defd_mallocator_allocate(vector, new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
				err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, new_buffer, old_buffer, old_size); mk_lang_check_rereturn(err);
				end = new_buffer + old_size;
				err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, end, elements, count);
				err = mk_sl_vector_inl_defd_mallocator_deallocate(vector, old_buffer, old_capacity * sizeof(mk_sl_vector_inl_defd_element_t)); mk_lang_check_rereturn(err);
				vector->m_buffer = new_buffer;
				vector->m_capacity = new_capacity;
				vector->m_size = new_size;
			}
		}
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_push_back_copy_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d - mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		if(count <= mk_sl_vector_inl_defd_rw_free(vector))
		{
			mk_sl_vector_inl_defd_element_pt end;
			mk_lang_types_sint_t err;

			end = &mk_sl_vector_inl_defd_rw_data(vector)[mk_sl_vector_inl_defd_rw_size(vector)]; mk_lang_assert(end);
			err = mk_sl_vector_inl_defd_prrw_elements_copy_construct_many(vector, end, elements, count); mk_lang_check_rereturn(err);
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
				err = mk_sl_vector_inl_defd_prrw_elements_copy_construct_many(vector, end, elements, count);
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
				err = mk_sl_vector_inl_defd_mallocator_allocate(vector, new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
				err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, new_buffer, old_buffer, old_size); mk_lang_check_rereturn(err);
				end = new_buffer + old_size;
				err = mk_sl_vector_inl_defd_prrw_elements_copy_construct_many(vector, end, elements, count);
				err = mk_sl_vector_inl_defd_mallocator_deallocate(vector, old_buffer, old_capacity * sizeof(mk_sl_vector_inl_defd_element_t)); mk_lang_check_rereturn(err);
				vector->m_buffer = new_buffer;
				vector->m_capacity = new_capacity;
				vector->m_size = new_size;
			}
		}
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_push_back_move_single(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(element);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_rw_push_back_move_many(vector, element, 1); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_push_back_copy_single(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(element);

	err = mk_sl_vector_inl_defd_rw_push_back_copy_many(vector, element, 1); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_pop_front_many(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pt dst;
	mk_sl_vector_inl_defd_element_pt src;
	mk_lang_types_usize_t cnt;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	dst = &vector->m_buffer[0];
	src = &vector->m_buffer[count];
	cnt = vector->m_size - count;
	err = mk_sl_vector_inl_defd_prrw_elements_move_assign_many(vector, dst, src, cnt); mk_lang_check_rereturn(err);
	err = mk_sl_vector_inl_defd_prrw_shrink_by(vector, count); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_pop_front_single(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_prrw_pop_front_many(vector, 1); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_pop_back_many(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_rw_shrink_by(vector, count); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_pop_back_single(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_rw_shrink_by(vector, 1); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_erase_at(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx < mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(idx != mk_sl_vector_inl_defd_rw_size(vector) - 1)
	{
		err = mk_sl_vector_inl_defd_element_move_assign(mk_sl_vector_inl_defd_rw_at(vector, idx), mk_sl_vector_inl_defd_rw_back(vector)); mk_lang_check_rereturn(err);
	}
	err = mk_sl_vector_inl_defd_rw_pop_back_single(vector); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_erase_element(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(element);
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	mk_lang_assert(element >= &vector->m_buffer[0] && element <= &vector->m_buffer[vector->m_size - 1]);
	mk_lang_assert(mk_sl_vector_inl_filec_overlap_fn(element, 1, vector->m_buffer, vector->m_size));

	if(element != &vector->m_buffer[vector->m_size - 1])
	{
		err = mk_sl_vector_inl_defd_element_move_assign(mk_sl_vector_inl_defd_rw_back(vector), element); mk_lang_check_rereturn(err);
	}
	err = mk_sl_vector_inl_defd_rw_pop_back_single(vector); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_erase_value(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
#if mk_sl_vector_inl_defd_element_eq_has
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_sl_vector_inl_defd_element_pt e;
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(element);
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	mk_lang_assert(!(element >= &vector->m_buffer[0] && element <= &vector->m_buffer[vector->m_size - 1]));
	mk_lang_assert(!(mk_sl_vector_inl_filec_overlap_fn(element, 1, vector->m_buffer, vector->m_size)));

	n = vector->m_size;
	for(i = 0; i != n; ++i)
	{
		e = &vector->m_buffer[i]; mk_lang_assert(e);
		if(mk_sl_vector_inl_defd_element_eq(e, element))
		{
			err = mk_sl_vector_inl_defd_prrw_erase_element(vector, e); mk_lang_check_rereturn(err);
			break;
		}
	}

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
#else
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(element);
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	mk_lang_assert(!(element >= &vector->m_buffer[0] && element <= &vector->m_buffer[vector->m_size - 1]));
	mk_lang_assert(!(mk_sl_vector_inl_filec_overlap_fn(element, 1, vector->m_buffer, vector->m_size)));

	mk_lang_assert_false();
	return 0;
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_copy_construct(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(vector);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(src));

	#if mk_sl_vector_inl_defd_mallocator_is_lokal
	err = mk_sl_vector_inl_defd_prrw_construct(vector, src->m_mallocator); mk_lang_check_rereturn(err);
	#else
	err = mk_sl_vector_inl_defd_prrw_construct(vector); mk_lang_check_rereturn(err);
	#endif
	mk_lang_check_todo(); /* insert all */

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_move_construct(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_pt const src) mk_lang_noexcept
{
	mk_lang_assert(vector);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(src));

	vector->m_buffer = src->m_buffer;
	vector->m_capacity = src->m_capacity;
	vector->m_size = src->m_size;
	#if mk_sl_vector_inl_defd_mallocator_is_lokal
	vector->m_mallocator = src->m_mallocator;
	#endif
	src->m_buffer = mk_lang_null;
	src->m_capacity = 0;
	src->m_size = 0;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_copy_assign(mk_sl_vector_inl_defd_pt const dst, mk_sl_vector_inl_defd_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(dst));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(src));

	err = mk_sl_vector_inl_defd_prrw_clear(dst); mk_lang_check_rereturn(err);
	err = mk_sl_vector_inl_defd_prrw_push_back_copy_many(dst, mk_sl_vector_inl_defd_prro_data(src), mk_sl_vector_inl_defd_prro_size(src)); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(dst));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_vector_inl_defd_prrw_move_assign(mk_sl_vector_inl_defd_pt const dst, mk_sl_vector_inl_defd_pt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(dst));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(src));

	dst->m_buffer = src->m_buffer;
	dst->m_capacity = src->m_capacity;
	dst->m_size = src->m_size;
	#if mk_sl_vector_inl_defd_mallocator_is_lokal
	dst->m_mallocator = src->m_mallocator;
	#endif
	src->m_buffer = mk_lang_null;
	src->m_capacity = 0;
	src->m_size = 0;

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(dst));
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(src));
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_st_max_capacity(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	ret = mk_sl_vector_inl_defd_prst_max_capacity();
	return ret;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_max_capacity(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	ret = mk_sl_vector_inl_defd_prro_max_capacity(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_capacity(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	ret = mk_sl_vector_inl_defd_prro_capacity(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_size(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	ret = mk_sl_vector_inl_defd_prro_size(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_ro_sise(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prro_sise(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_vector_inl_defd_ro_free(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret;

	ret = mk_sl_vector_inl_defd_prro_free(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_ro_is_empty(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	ret = mk_sl_vector_inl_defd_prro_is_empty(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_ro_is_full(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	ret = mk_sl_vector_inl_defd_prro_is_full(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_data(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	ret = mk_sl_vector_inl_defd_prro_data(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_at(mk_sl_vector_inl_defd_pct const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	ret = mk_sl_vector_inl_defd_prro_at(vector, idx);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_front(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	ret = mk_sl_vector_inl_defd_prro_front(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pct mk_sl_vector_inl_defd_ro_back(mk_sl_vector_inl_defd_pct const vector) mk_lang_noexcept
{
	mk_sl_vector_inl_defd_element_pct ret;

	ret = mk_sl_vector_inl_defd_prro_back(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_ro_eq(mk_sl_vector_inl_defd_pct const vector, mk_sl_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	ret = mk_sl_vector_inl_defd_prro_eq(vector, other);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_ro_ne(mk_sl_vector_inl_defd_pct const vector, mk_sl_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret;

	ret = mk_sl_vector_inl_defd_prro_ne(vector, other);
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_sise(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_ro_sise(vector);
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

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_data(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	#include "mk_lang_warning_clang_push_cast_qual.h"
	return ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_data(vector)));
	#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_at(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	#include "mk_lang_warning_clang_push_cast_qual.h"
	return ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_at(vector, idx)));
	#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_front(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	#include "mk_lang_warning_clang_push_cast_qual.h"
	return ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_front(vector)));
	#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_vector_inl_defd_element_pt mk_sl_vector_inl_defd_rw_back(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	#include "mk_lang_warning_clang_push_cast_qual.h"
	return ((mk_sl_vector_inl_defd_element_pt)(mk_sl_vector_inl_defd_ro_back(vector)));
	#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_rw_eq(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_pct const other) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_ro_eq(((mk_sl_vector_inl_defd_pct)(vector)), other);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_vector_inl_defd_rw_ne(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_pct const other) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_ro_ne(((mk_sl_vector_inl_defd_pct)(vector)), other);
}


#if mk_sl_vector_inl_defd_mallocator_is_lokal
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_construct(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_mallocator_pt const mallocator) mk_lang_noexcept
#else
mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_construct(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
#endif
{
	mk_lang_types_sint_t ret;

	#if mk_sl_vector_inl_defd_mallocator_is_lokal
	ret = mk_sl_vector_inl_defd_prrw_construct(vector, mallocator);
	#else
	ret = mk_sl_vector_inl_defd_prrw_construct(vector);
	#endif
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_copy_construct(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_copy_construct(vector, src);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_move_construct(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_move_construct(vector, src);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_destroy(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_destroy(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_copy_assign(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_copy_assign(vector, src);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_move_assign(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_move_assign(vector, src);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_reconstruct(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_reconstruct(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_reserve_at_least(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_reserve_at_least(vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_reserve_additional(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_reserve_additional(vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_shrink_by(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_shrink_by(vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_resize_to(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_resize_to(vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_grow_by(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_grow_by(vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_clear(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t ret;

	ret = mk_sl_vector_inl_defd_prrw_clear(vector);
	return ret;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_push_back_move_many(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pt const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d - mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		if(count <= mk_sl_vector_inl_defd_rw_free(vector))
		{
			mk_sl_vector_inl_defd_element_pt end;
			mk_lang_types_sint_t err;

			end = mk_sl_vector_inl_defd_rw_data(vector) + mk_sl_vector_inl_defd_rw_size(vector); mk_lang_assert(end);
			err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, end, elements, count); mk_lang_check_rereturn(err);
			vector->m_size += count;
		}
		else
		{
			if(!mk_sl_vector_inl_filec_overlap_fn(elements, count, vector->m_buffer, vector->m_size))
			{
				mk_lang_types_sint_t err;
				mk_sl_vector_inl_defd_element_pt end;

				err = mk_sl_vector_inl_defd_rw_reserve_additional(vector, count); mk_lang_check_rereturn(err);
				end = mk_sl_vector_inl_defd_rw_data(vector) + mk_sl_vector_inl_defd_rw_size(vector); mk_lang_assert(end);
				err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, end, elements, count);
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
				err = mk_sl_vector_inl_defd_mallocator_allocate(vector, new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
				err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, new_buffer, old_buffer, old_size); mk_lang_check_rereturn(err);
				end = new_buffer + old_size;
				err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, end, elements, count);
				err = mk_sl_vector_inl_defd_mallocator_deallocate(vector, old_buffer, old_capacity * sizeof(mk_sl_vector_inl_defd_element_t)); mk_lang_check_rereturn(err);
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
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_max_capacity_d - mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		if(count <= mk_sl_vector_inl_defd_rw_free(vector))
		{
			mk_sl_vector_inl_defd_element_pt end;
			mk_lang_types_sint_t err;

			end = &mk_sl_vector_inl_defd_rw_data(vector)[mk_sl_vector_inl_defd_rw_size(vector)]; mk_lang_assert(end);
			err = mk_sl_vector_inl_defd_prrw_elements_copy_construct_many(vector, end, elements, count); mk_lang_check_rereturn(err);
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
				err = mk_sl_vector_inl_defd_prrw_elements_copy_construct_many(vector, end, elements, count);
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
				err = mk_sl_vector_inl_defd_mallocator_allocate(vector, new_capacity * sizeof(mk_sl_vector_inl_defd_element_t), &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_vector_inl_defd_element_pt)(new_mem));
				err = mk_sl_vector_inl_defd_prrw_elements_move_construct_many(vector, new_buffer, old_buffer, old_size); mk_lang_check_rereturn(err);
				end = new_buffer + old_size;
				err = mk_sl_vector_inl_defd_prrw_elements_copy_construct_many(vector, end, elements, count);
				err = mk_sl_vector_inl_defd_mallocator_deallocate(vector, old_buffer, old_capacity * sizeof(mk_sl_vector_inl_defd_element_t)); mk_lang_check_rereturn(err);
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
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(element);
	#include "mk_lang_warning_gcc_pop.h"
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

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_pop_front_many(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_prrw_pop_front_many(vector, count);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_pop_front_single(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_prrw_pop_front_single(vector);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_pop_back_many(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_rw_shrink_by(vector, count); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_pop_back_single(mk_sl_vector_inl_defd_pt const vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_vector_inl_defd_rw_shrink_by(vector, 1); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_erase_at(mk_sl_vector_inl_defd_pt const vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(vector);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	mk_lang_assert(!mk_sl_vector_inl_defd_rw_is_empty(vector));
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx < mk_sl_vector_inl_defd_rw_size(vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(idx != mk_sl_vector_inl_defd_rw_size(vector) - 1)
	{
		err = mk_sl_vector_inl_defd_element_move_assign(mk_sl_vector_inl_defd_rw_at(vector, idx), mk_sl_vector_inl_defd_rw_back(vector)); mk_lang_check_rereturn(err);
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
	mk_lang_assert(mk_sl_vector_inl_filec_overlap_fn(element, 1, vector->m_buffer, vector->m_size));

	if(element != &vector->m_buffer[vector->m_size - 1])
	{
		#include "mk_lang_warning_clang_push_cast_qual.h"
		err = mk_sl_vector_inl_defd_element_move_assign(((mk_sl_vector_inl_defd_element_pt)(element)), mk_sl_vector_inl_defd_rw_back(vector)); mk_lang_check_rereturn(err);
		#include "mk_lang_warning_clang_pop.h"
	}
	err = mk_sl_vector_inl_defd_rw_pop_back_single(vector); mk_lang_check_rereturn(err);
	mk_lang_assert(mk_sl_vector_inl_defd_prro_verify_invariants(vector));
	return 0;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_vector_inl_defd_rw_erase_value(mk_sl_vector_inl_defd_pt const vector, mk_sl_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
	return mk_sl_vector_inl_defd_prrw_erase_value(vector, element);
}


#undef mk_sl_vector_inl_filec_memcpy_name
#undef mk_sl_vector_inl_filec_memcpy_fn

#undef mk_sl_vector_inl_filec_memmov_name
#undef mk_sl_vector_inl_filec_memmov_fn

#undef mk_sl_vector_inl_filec_overlap_name
#undef mk_sl_vector_inl_filec_overlap_fn


#include "mk_sl_vector_inl_defu.h"
