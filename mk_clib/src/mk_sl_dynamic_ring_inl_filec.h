#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_check.h"
#include "mk_lang_concat.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits.h"
#include "mk_lang_max.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_pow2.h"
#include "mk_lang_types.h"


#include "mk_sl_dynamic_ring_inl_defd.h"


#define mk_sl_dynamic_ring_inl_filec_memcpy_name mk_lang_concat(mk_sl_dynamic_ring_inl_defd_name, _zzz_element_memcpy)
#define mk_sl_dynamic_ring_inl_filec_memcpy_fn mk_lang_concat(mk_sl_dynamic_ring_inl_filec_memcpy_name, _fn)
#define mk_lang_memcpy1_t_name mk_sl_dynamic_ring_inl_filec_memcpy_name
#define mk_lang_memcpy1_t_type mk_sl_dynamic_ring_inl_defd_element_t
#include "mk_lang_memcpy1_inl_fileh.h"
#include "mk_lang_memcpy1_inl_filec.h"
#include "mk_lang_memcpy1_inl_fileu.h"

#define mk_sl_dynamic_ring_inl_filec_memmov_name mk_lang_concat(mk_sl_dynamic_ring_inl_defd_name, _zzz_element_memmov)
#define mk_sl_dynamic_ring_inl_filec_memmov_fn mk_lang_concat(mk_sl_dynamic_ring_inl_filec_memmov_name, _fn)
#define mk_lang_memmov1_t_name mk_sl_dynamic_ring_inl_filec_memmov_name
#define mk_lang_memmov1_t_type mk_sl_dynamic_ring_inl_defd_element_t
#include "mk_lang_memmov1_inl_fileh.h"
#include "mk_lang_memmov1_inl_filec.h"
#include "mk_lang_memmov1_inl_fileu.h"

#define mk_sl_dynamic_ring_inl_filec_overlap_name mk_lang_concat(mk_sl_dynamic_ring_inl_defd_name, _zzz_element_overlap)
#define mk_sl_dynamic_ring_inl_filec_overlap_fn mk_lang_concat(mk_sl_dynamic_ring_inl_filec_overlap_name, _fn)
#define mk_lang_overlap_t_name mk_sl_dynamic_ring_inl_filec_overlap_name
#define mk_lang_overlap_t_type mk_sl_dynamic_ring_inl_defd_element_t
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#include "mk_lang_overlap_inl_fileu.h"


mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_bool_t gud;

	mk_lang_assert(ring);

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_clang_push_tautological_unsigned_zero_compare.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	gud = mk_lang_true;
	gud &= ring->m_buffer || ring->m_capacity == 0;
	gud &= ring->m_capacity == 0 || ring->m_buffer;
	gud &= ring->m_capacity >= 0;
	gud &= ring->m_capacity <= mk_sl_dynamic_ring_inl_defd_max_capacity_d;
	gud &= ring->m_capacity == 0 || mk_lang_pow2_is(ring->m_capacity);
	gud &= ring->m_read >= 0;
	gud &= ring->m_write >= 0;
	gud &= (ring->m_write - ring->m_read) >= 0;
	gud &= (ring->m_write - ring->m_read) <= ring->m_capacity;
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_clang_pop.h"
	#include "mk_lang_warning_msvc_pop.h"
	return gud;
}





mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_element_construct_copy_single(mk_sl_dynamic_ring_inl_defd_element_pt const dst, mk_sl_dynamic_ring_inl_defd_element_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(dst != src);

	err = mk_sl_dynamic_ring_inl_defd_element_copy_construct(dst, src); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_element_construct_move_single(mk_sl_dynamic_ring_inl_defd_element_pt const dst, mk_sl_dynamic_ring_inl_defd_element_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(dst != src);

	err = mk_sl_dynamic_ring_inl_defd_element_move_construct(dst, src); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_element_destroy_single(mk_sl_dynamic_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
#if mk_sl_dynamic_ring_inl_defd_element_construct_destruct_has
	mk_lang_types_sint_t err;

	mk_lang_assert(element);

	err = mk_sl_dynamic_ring_t_element_destruct(element); mk_lang_check_rereturn(err);
	return 0;
#else
	mk_lang_assert(element);
	((mk_lang_types_void_t)(elements));
#endif
}





mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_copy_many(mk_sl_dynamic_ring_inl_defd_element_pt const dst, mk_sl_dynamic_ring_inl_defd_element_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_sl_dynamic_ring_inl_defd_copy_style == mk_sl_dynamic_ring_copy_use_bitblt
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_dynamic_ring_inl_filec_memcpy_fn(dst, src, count);
	return 0;
#elif mk_sl_dynamic_ring_inl_defd_copy_style == mk_sl_dynamic_ring_copy_use_custom
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_sl_dynamic_ring_inl_defd_prrw_element_construct_copy_single(&dst[i], &src[i]); mk_lang_check_rereturn(err);
	}
	return 0;
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_move_many(mk_sl_dynamic_ring_inl_defd_element_pt const dst, mk_sl_dynamic_ring_inl_defd_element_pt const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_sl_dynamic_ring_inl_defd_copy_style == mk_sl_dynamic_ring_copy_use_bitblt
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_dynamic_ring_inl_filec_memcpy_fn(dst, src, count);
	return 0;
#elif mk_sl_dynamic_ring_inl_defd_copy_style == mk_sl_dynamic_ring_copy_use_custom
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_sl_dynamic_ring_inl_defd_prrw_element_construct_move_single(&dst[i], &src[i]); mk_lang_check_rereturn(err);
	}
	return 0;
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_elements_assign_move_many(mk_sl_dynamic_ring_inl_defd_element_pt const dst, mk_sl_dynamic_ring_inl_defd_element_pt const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_sl_dynamic_ring_inl_defd_copy_style == mk_sl_dynamic_ring_copy_use_bitblt
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_dynamic_ring_inl_filec_memcpy_fn(dst, src, count);
	return 0;
#elif mk_sl_dynamic_ring_inl_defd_copy_style == mk_sl_dynamic_ring_copy_use_custom
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d);
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_dynamic_ring_inl_defd_element_move_assign(dst, src, count); mk_lang_check_rereturn(err);
	return 0;
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(mk_sl_dynamic_ring_inl_defd_element_pt const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n;
	mk_lang_types_usize_t i;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_sl_dynamic_ring_inl_defd_prrw_element_destroy_single(&elements[i]); mk_lang_check_rereturn(err);
	}
	return 0;
}





mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prro_get_capacity(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_capacity;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prro_get_size(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t r mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_write - ring->m_read;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prro_get_sise(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t size mk_lang_constexpr_init;
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	size = mk_sl_dynamic_ring_inl_defd_prro_get_size(ring);
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	r = ((mk_lang_types_sint_t)(size));

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prro_get_free_size(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = mk_sl_dynamic_ring_inl_defd_prro_get_capacity(ring) - mk_sl_dynamic_ring_inl_defd_prro_get_size(ring);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_dynamic_ring_inl_defd_prro_is_empty(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_bool_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = mk_sl_dynamic_ring_inl_defd_prro_get_size(ring) == 0;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_dynamic_ring_inl_defd_prro_is_full(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_bool_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = mk_sl_dynamic_ring_inl_defd_prro_get_free_size(ring) == 0;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_prro_get_front(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pct r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_defd_prro_is_empty(ring));

	r = &ring->m_buffer[ring->m_read & (ring->m_capacity - 1)];

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_prro_get_back(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pct r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_defd_prro_is_empty(ring));

	r = &ring->m_buffer[(ring->m_read + ((ring->m_write - ring->m_read) - 1)) & (ring->m_capacity - 1)];

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prro_get_size_a(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t cap;
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	cap = ring->m_capacity - (ring->m_read & (ring->m_capacity - 1));
	r = ring->m_write - ring->m_read;
	r = mk_lang_min(r, cap);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prro_get_sise_a(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t size mk_lang_constexpr_init;
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	size = mk_sl_dynamic_ring_inl_defd_prro_get_size_a(ring);
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	r = ((mk_lang_types_sint_t)(size));

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_prro_get_data_a(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pct r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_buffer + (ring->m_read & (ring->m_capacity - 1));

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prro_get_size_b(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = mk_sl_dynamic_ring_inl_defd_prro_get_size(ring) - mk_sl_dynamic_ring_inl_defd_prro_get_size_a(ring);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prro_get_sise_b(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t size mk_lang_constexpr_init;
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	size = mk_sl_dynamic_ring_inl_defd_prro_get_size_b(ring);
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	r = ((mk_lang_types_sint_t)(size));

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_prro_get_data_b(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pct r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_buffer;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prro_get_free_size_a(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t cap;
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	cap = (ring->m_read & (ring->m_capacity - 1)) - (ring->m_write & (ring->m_capacity - 1));
	r = ring->m_capacity - (ring->m_write & (ring->m_capacity - 1));
	r = mk_lang_min(r, cap);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_prro_get_free_data_a(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pct r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_buffer + (ring->m_write & (ring->m_capacity - 1));

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prro_get_free_size_b(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = mk_sl_dynamic_ring_inl_defd_prro_get_free_size(ring) - mk_sl_dynamic_ring_inl_defd_prro_get_free_size_a(ring);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_prro_get_free_data_b(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pct r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_buffer;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}





mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prrw_get_capacity(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_capacity;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prrw_get_size(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t r mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_write - ring->m_read;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_get_sise(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t size mk_lang_constexpr_init;
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	size = mk_sl_dynamic_ring_inl_defd_prrw_get_size(ring);
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	r = ((mk_lang_types_sint_t)(size));

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prrw_get_free_size(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = mk_sl_dynamic_ring_inl_defd_prrw_get_capacity(ring) - mk_sl_dynamic_ring_inl_defd_prrw_get_size(ring);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_dynamic_ring_inl_defd_prrw_is_empty(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_bool_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = mk_sl_dynamic_ring_inl_defd_prrw_get_size(ring) == 0;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_bool_t mk_sl_dynamic_ring_inl_defd_prrw_is_full(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_bool_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = mk_sl_dynamic_ring_inl_defd_prrw_get_free_size(ring) == 0;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_prrw_get_front(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_defd_prrw_is_empty(ring));

	r = &ring->m_buffer[ring->m_read & (ring->m_capacity - 1)];

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_prrw_get_back(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_defd_prrw_is_empty(ring));

	r = &ring->m_buffer[(ring->m_read + ((ring->m_write - ring->m_read) - 1)) & (ring->m_capacity - 1)];

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t cap;
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	cap = ring->m_capacity - (ring->m_read & (ring->m_capacity - 1));
	r = ring->m_write - ring->m_read;
	r = mk_lang_min(r, cap);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_get_sise_a(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t size mk_lang_constexpr_init;
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	size = mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring);
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	r = ((mk_lang_types_sint_t)(size));

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_buffer + (ring->m_read & (ring->m_capacity - 1));

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = mk_sl_dynamic_ring_inl_defd_prrw_get_size(ring) - mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_get_sise_b(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t size mk_lang_constexpr_init;
	mk_lang_types_sint_t r mk_lang_constexpr_init;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	size = mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring);
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	r = ((mk_lang_types_sint_t)(size));

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_buffer;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_a(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t cap;
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	cap = ring->m_capacity - (ring->m_write & (ring->m_capacity - 1));
	r = (((ring->m_read & (ring->m_capacity - 1)) + ring->m_capacity) - (ring->m_write & (ring->m_capacity - 1)));
	r = mk_lang_min(r, cap);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_a(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_buffer + (ring->m_write & (ring->m_capacity - 1));

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_b(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_usize_t r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = mk_sl_dynamic_ring_inl_defd_prrw_get_free_size(ring) - mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_a(ring);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}

mk_lang_nodiscard static mk_lang_inline mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_b(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt r;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	r = ring->m_buffer;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return r;
}





mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_construct(mk_sl_dynamic_ring_inl_defd_pt const ring mk_sl_dynamic_ring_inl_defd_mallocator_param) mk_lang_noexcept
{
	mk_lang_assert(ring);
	mk_sl_dynamic_ring_inl_defd_mallocator_assert();

	ring->m_buffer = mk_lang_null;
	ring->m_capacity = 0;
	ring->m_read = 0;
	ring->m_write = 0;
	mk_sl_dynamic_ring_inl_defd_mallocator_assign(ring);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_construct_copy(mk_sl_dynamic_ring_inl_defd_pt const dst, mk_sl_dynamic_ring_inl_defd_pct const src) mk_lang_noexcept
{
	mk_lang_types_usize_t old_elements_count;
	mk_lang_types_usize_t new_elements_capacity;
	mk_lang_types_usize_t bytes_count;
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;
	mk_sl_dynamic_ring_inl_defd_element_pt new_buffer;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(src));

	old_elements_count = mk_sl_dynamic_ring_inl_defd_prro_get_size(src);
	new_elements_capacity = mk_lang_pow2_roundup(old_elements_count);
	bytes_count = new_elements_capacity * sizeof(mk_sl_dynamic_ring_inl_defd_element_t);
	err = mk_sl_dynamic_ring_inl_defd_mallocator_allocate(src, bytes_count, &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); new_buffer = ((mk_sl_dynamic_ring_inl_defd_element_pt)(mem));
	err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_copy_many(new_buffer, src->m_buffer, old_elements_count); mk_lang_check_rereturn(err);
	dst->m_buffer = new_buffer;
	dst->m_capacity = new_elements_capacity;
	dst->m_read = 0;
	dst->m_write = old_elements_count;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(dst));
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_construct_move(mk_sl_dynamic_ring_inl_defd_pt const dst, mk_sl_dynamic_ring_inl_defd_pt const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(src));

	dst->m_buffer   = src->m_buffer  ; src->m_buffer   = mk_lang_null;
	dst->m_capacity = src->m_capacity; src->m_capacity = 0           ;
	dst->m_read     = src->m_read    ; src->m_read     = 0           ;
	dst->m_write    = src->m_write   ; src->m_write    = 0           ;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(dst));
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_clear(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring)); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring)); mk_lang_check_rereturn(err);
	ring->m_read = 0;
	ring->m_write = 0;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_consolidate(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt data_a;
	mk_lang_types_usize_t size_a;
	mk_sl_dynamic_ring_inl_defd_element_pt data_b;
	mk_lang_types_usize_t size_b;
	mk_sl_dynamic_ring_inl_defd_element_pt old_buffer;
	mk_lang_types_usize_t old_capacity;
	mk_lang_types_usize_t old_bytes_count;
	mk_lang_types_usize_t elements_count;
	mk_lang_types_usize_t elements_capacity;
	mk_lang_types_usize_t bytes_capacity;
	mk_lang_types_void_pt mem;
	mk_sl_dynamic_ring_inl_defd_element_pt new_buffer;
	mk_lang_types_sint_t err;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	data_a = mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring);
	size_a = mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring);
	data_b = mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring);
	size_b = mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring);
	if(size_a != 0 && size_b != 0)
	{
		old_buffer = ring->m_buffer;
		old_capacity = ring->m_capacity;
		old_bytes_count = old_capacity * sizeof(mk_sl_dynamic_ring_inl_defd_element_t);
		elements_count = size_a + size_b;
		elements_capacity = mk_lang_pow2_roundup(elements_count);
		bytes_capacity = elements_capacity * sizeof(mk_sl_dynamic_ring_inl_defd_element_t);
		err = mk_sl_dynamic_ring_inl_defd_mallocator_allocate(ring, bytes_capacity, &mem); mk_lang_check_rereturn(err); mk_lang_assert(mem); new_buffer = ((mk_sl_dynamic_ring_inl_defd_element_pt)(mem)); mk_lang_assert(new_buffer);
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_move_many(new_buffer + 0 * size_a, data_a, size_a); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_move_many(new_buffer + 1 * size_a, data_b, size_b); mk_lang_check_rereturn(err);
		ring->m_buffer = new_buffer;
		ring->m_capacity = elements_capacity;
		ring->m_read = 0;
		ring->m_write = elements_count;
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(data_a, size_a); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(data_b, size_b); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_inl_defd_mallocator_deallocate(ring, old_buffer, old_bytes_count); mk_lang_check_rereturn(err);
	}

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_push_back_void(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_a(ring));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	ring->m_write += count;

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_destroy(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt mem;
	mk_lang_types_usize_t elements_count;
	mk_lang_types_usize_t bytes_count;

	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));

	err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring)); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring)); mk_lang_check_rereturn(err);
	mem = ring->m_buffer;
	elements_count = ring->m_capacity;
	bytes_count = elements_count * sizeof(mk_sl_dynamic_ring_inl_defd_element_t);
	err = mk_sl_dynamic_ring_inl_defd_mallocator_deallocate(ring, mem, bytes_count); mk_lang_check_rereturn(err);
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_reserve_at_least(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt old_buffer;
	mk_lang_types_usize_t old_capacity;
	mk_lang_types_usize_t elements_count;
	mk_lang_types_usize_t new_capacity;
	mk_lang_types_usize_t new_bytes_count;
	mk_lang_types_usize_t old_bytes_count;
	mk_lang_types_sint_t err;
	mk_lang_types_void_pt new_mem;
	mk_sl_dynamic_ring_inl_defd_element_pt new_buffer;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	old_buffer = ring->m_buffer;
	old_capacity = ring->m_capacity;
	if(count > old_capacity)
	{
		if(old_buffer)
		{
			elements_count = mk_sl_dynamic_ring_inl_defd_prrw_get_size(ring);
			new_capacity = old_capacity * 2;
			new_capacity = mk_lang_max(new_capacity, count);
			new_capacity = mk_lang_pow2_roundup(new_capacity);
			new_bytes_count = new_capacity * sizeof(mk_sl_dynamic_ring_inl_defd_element_t);
			old_bytes_count = old_capacity * sizeof(mk_sl_dynamic_ring_inl_defd_element_t);
			#if mk_sl_dynamic_ring_inl_defd_copy_style == mk_sl_dynamic_ring_copy_use_bitblt
			err = mk_sl_dynamic_ring_inl_defd_mallocator_reallocate(ring, old_buffer, old_bytes_count, new_bytes_count, &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_dynamic_ring_inl_defd_element_pt)(new_mem)); mk_lang_assert(new_buffer);
			ring->m_buffer = new_buffer;
			ring->m_capacity = new_capacity;
			#elif mk_sl_dynamic_ring_inl_defd_copy_style == mk_sl_dynamic_ring_copy_use_custom
			err = mk_sl_dynamic_ring_inl_defd_mallocator_allocate(ring, new_bytes_count, &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_dynamic_ring_inl_defd_element_pt)(new_mem)); mk_lang_assert(new_buffer);
			err = mk_sl_dynamic_ring_inl_defd_prrw_elements_assign_move_many(new_buffer + 0 * mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring)); mk_lang_check_rereturn(err);
			err = mk_sl_dynamic_ring_inl_defd_prrw_elements_assign_move_many(new_buffer + 1 * mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring)); mk_lang_check_rereturn(err);
			err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring)); mk_lang_check_rereturn(err);
			err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring)); mk_lang_check_rereturn(err);
			err = mk_sl_dynamic_ring_inl_defd_mallocator_deallocate(ring, old_buffer, old_bytes_count); mk_lang_check_rereturn(err);
			ring->m_buffer = new_buffer;
			ring->m_capacity = new_capacity;
			ring->m_read = 0;
			ring->m_write = elements_count;
			#else
			#error xxxxxxxxxx
			#endif
		}
		else
		{
			new_capacity = 8;
			new_capacity = mk_lang_max(new_capacity, count);
			new_capacity = mk_lang_pow2_roundup(new_capacity);
			new_bytes_count = new_capacity * sizeof(mk_sl_dynamic_ring_inl_defd_element_t);
			err = mk_sl_dynamic_ring_inl_defd_mallocator_allocate(ring, new_bytes_count, &new_mem); mk_lang_check_rereturn(err); mk_lang_assert(new_mem); new_buffer = ((mk_sl_dynamic_ring_inl_defd_element_pt)(new_mem)); mk_lang_assert(new_buffer);
			ring->m_buffer = new_buffer;
			ring->m_capacity = new_capacity;
		}
	}

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_reserve_additional(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d - mk_sl_dynamic_ring_inl_defd_prro_get_capacity(ring));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_dynamic_ring_inl_defd_prrw_reserve_at_least(ring, mk_sl_dynamic_ring_inl_defd_prrw_get_size(ring) + count); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_push_back_copy_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_dynamic_ring_inl_defd_element_pt dst_a;
	mk_sl_dynamic_ring_inl_defd_element_pct src_a;
	mk_lang_types_usize_t cnt_a;
	mk_sl_dynamic_ring_inl_defd_element_pt dst_b;
	mk_sl_dynamic_ring_inl_defd_element_pct src_b;
	mk_lang_types_usize_t cnt_b;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d - mk_sl_dynamic_ring_inl_defd_rw_get_size(ring));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(elements, count, mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring)));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(elements, count, mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring)));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		err = mk_sl_dynamic_ring_inl_defd_prrw_reserve_additional(ring, count); mk_lang_check_rereturn(err);
		dst_a = mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_a(ring); mk_lang_assert(dst_a);
		src_a = elements;
		cnt_a = mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_a(ring);
		cnt_a = mk_lang_min(cnt_a, count);
		dst_b = mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_b(ring); mk_lang_assert(dst_a);
		src_b = elements + cnt_a;
		cnt_b = count - cnt_a;
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_copy_many(dst_a, src_a, cnt_a); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_copy_many(dst_b, src_b, cnt_b); mk_lang_check_rereturn(err);
		ring->m_write += count;
	}

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_push_back_copy_single(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pct const element) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_back_copy_many(ring, element, 1);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_push_back_move_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pt const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_dynamic_ring_inl_defd_element_pt dst_a;
	mk_sl_dynamic_ring_inl_defd_element_pt src_a;
	mk_lang_types_usize_t cnt_a;
	mk_sl_dynamic_ring_inl_defd_element_pt dst_b;
	mk_sl_dynamic_ring_inl_defd_element_pt src_b;
	mk_lang_types_usize_t cnt_b;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d - mk_sl_dynamic_ring_inl_defd_rw_get_size(ring));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(elements, count, mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring)));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(elements, count, mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring)));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		err = mk_sl_dynamic_ring_inl_defd_prrw_reserve_additional(ring, count); mk_lang_check_rereturn(err);
		dst_a = mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_a(ring); mk_lang_assert(dst_a);
		src_a = elements;
		cnt_a = mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_a(ring);
		cnt_a = mk_lang_min(cnt_a, count);
		dst_b = mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_b(ring); mk_lang_assert(dst_a);
		src_b = elements + cnt_a;
		cnt_b = count - cnt_a;
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_move_many(dst_a, src_a, cnt_a); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_move_many(dst_b, src_b, cnt_b); mk_lang_check_rereturn(err);
		ring->m_write += count;
	}

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_push_back_move_single(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_back_move_many(ring, element, 1);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_push_front_copy_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_dynamic_ring_inl_defd_element_pt dst_a;
	mk_sl_dynamic_ring_inl_defd_element_pct src_a;
	mk_lang_types_usize_t cap_a;
	mk_lang_types_usize_t cnt_a;
	mk_sl_dynamic_ring_inl_defd_element_pt dst_b;
	mk_sl_dynamic_ring_inl_defd_element_pct src_b;
	mk_lang_types_usize_t cap_b;
	mk_lang_types_usize_t cnt_b;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d - mk_sl_dynamic_ring_inl_defd_rw_get_size(ring));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(elements, count, mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring)));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(elements, count, mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring)));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		err = mk_sl_dynamic_ring_inl_defd_prrw_reserve_additional(ring, count); mk_lang_check_rereturn(err);
		dst_a = mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_b(ring); mk_lang_assert(dst_a);
		src_a = elements;
		cap_a = mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_b(ring);
		cnt_a = mk_lang_min(cap_a, count);
		dst_a = dst_a + cap_a - cnt_a;
		dst_b = mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_a(ring); mk_lang_assert(dst_a);
		cap_b = mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_a(ring);
		src_b = elements + cnt_a;
		cnt_b = count - cnt_a;
		dst_b = dst_b + cap_b - cnt_b;
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_copy_many(dst_a, src_a, cnt_a); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_copy_many(dst_b, src_b, cnt_b); mk_lang_check_rereturn(err);
		ring->m_write += count;
	}

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_push_front_copy_single(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pct const element) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_front_copy_many(ring, element, 1);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_push_front_move_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pt const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err;
	mk_sl_dynamic_ring_inl_defd_element_pt dst_a;
	mk_sl_dynamic_ring_inl_defd_element_pt src_a;
	mk_lang_types_usize_t cap_a;
	mk_lang_types_usize_t cnt_a;
	mk_sl_dynamic_ring_inl_defd_element_pt dst_b;
	mk_sl_dynamic_ring_inl_defd_element_pt src_b;
	mk_lang_types_usize_t cap_b;
	mk_lang_types_usize_t cnt_b;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_max_capacity_d - mk_sl_dynamic_ring_inl_defd_rw_get_size(ring));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(elements, count, mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring)));
	mk_lang_assert(!mk_sl_dynamic_ring_inl_filec_overlap_fn(elements, count, mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring), mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring)));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		err = mk_sl_dynamic_ring_inl_defd_prrw_reserve_additional(ring, count); mk_lang_check_rereturn(err);
		dst_a = mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_b(ring); mk_lang_assert(dst_a);
		src_a = elements;
		cap_a = mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_b(ring);
		cnt_a = mk_lang_min(cap_a, count);
		dst_a = dst_a + cap_a - cnt_a;
		dst_b = mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_a(ring); mk_lang_assert(dst_a);
		cap_b = mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_a(ring);
		src_b = elements + cnt_a;
		cnt_b = count - cnt_a;
		dst_b = dst_b + cap_b - cnt_b;
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_move_many(dst_a, src_a, cnt_a); mk_lang_check_rereturn(err);
		err = mk_sl_dynamic_ring_inl_defd_prrw_elements_construct_move_many(dst_b, src_b, cnt_b); mk_lang_check_rereturn(err);
		ring->m_write += count;
	}

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_push_front_move_single(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_front_move_many(ring, element, 1);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_assign_copy(mk_sl_dynamic_ring_inl_defd_pt const dst, mk_sl_dynamic_ring_inl_defd_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(dst));
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(src));

	err = mk_sl_dynamic_ring_inl_defd_prrw_clear(dst); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_inl_defd_prrw_push_back_copy_many(dst, mk_sl_dynamic_ring_inl_defd_prro_get_data_a(src), mk_sl_dynamic_ring_inl_defd_prro_get_size_a(src)); mk_lang_check_rereturn(err);
	err = mk_sl_dynamic_ring_inl_defd_prrw_push_back_copy_many(dst, mk_sl_dynamic_ring_inl_defd_prro_get_data_b(src), mk_sl_dynamic_ring_inl_defd_prro_get_size_b(src)); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(dst));
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_assign_move(mk_sl_dynamic_ring_inl_defd_pt const dst, mk_sl_dynamic_ring_inl_defd_pt const src) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt e;
	mk_lang_types_usize_t u;
	#if mk_sl_dynamic_ring_inl_defd_mallocator_is_lokal
	mk_sl_dynamic_ring_inl_defd_mallocator_pt m;
	#endif

	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(dst));
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(src));

	e = dst->m_buffer    ; dst->m_buffer     = src->m_buffer    ; src->m_buffer     = e;
	u = dst->m_capacity  ; dst->m_capacity   = src->m_capacity  ; src->m_capacity   = u;
	u = dst->m_read      ; dst->m_read       = src->m_read      ; src->m_read       = u;
	u = dst->m_write     ; dst->m_write      = src->m_write     ; src->m_write      = u;
	#if mk_sl_dynamic_ring_inl_defd_mallocator_is_lokal
	m = dst->m_mallocator; dst->m_mallocator = src->m_mallocator; src->m_mallocator = m;
	#endif

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(dst));
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_pop_back_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt data_a;
	mk_sl_dynamic_ring_inl_defd_element_pt data_b;
	mk_lang_types_usize_t size_a;
	mk_lang_types_usize_t size_b;
	mk_lang_types_usize_t rem;
	mk_lang_types_usize_t cnt;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_prrw_get_size(ring));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	data_a = mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring);
	data_b = mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring);
	size_a = mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring);
	size_b = mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring);
	rem = count;
	cnt = mk_lang_min(rem, size_b);
	err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(data_b + size_b - cnt, cnt); mk_lang_check_rereturn(err);
	rem -= cnt;
	cnt = rem;
	err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(data_a + size_a - cnt, cnt); mk_lang_check_rereturn(err);
	ring->m_write -= count;
	if(ring->m_read == ring->m_write)
	{
		ring->m_read = 0;
		ring->m_write = 0;
	}

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_pop_back_single(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_pop_back_many(ring, 1);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_pop_front_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_sl_dynamic_ring_inl_defd_element_pt data_a;
	mk_sl_dynamic_ring_inl_defd_element_pt data_b;
	mk_lang_types_usize_t size_a;
	mk_lang_types_usize_t rem;
	mk_lang_types_usize_t cnt;
	mk_lang_types_sint_t err;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(ring);
	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_dynamic_ring_inl_defd_prrw_get_size(ring));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	data_a = mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring);
	data_b = mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring);
	size_a = mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring);
	rem = count;
	cnt = mk_lang_min(rem, size_a);
	err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(data_a, cnt); mk_lang_check_rereturn(err);
	rem -= cnt;
	cnt = rem;
	err = mk_sl_dynamic_ring_inl_defd_prrw_elements_destroy_many(data_b, cnt); mk_lang_check_rereturn(err);
	ring->m_read += count;
	if(ring->m_read == ring->m_write)
	{
		ring->m_read = 0;
		ring->m_write = 0;
	}

	mk_lang_assert(mk_sl_dynamic_ring_inl_defd_prro_verify_invariants(ring));
	return 0;
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_prrw_pop_front_single(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_pop_front_many(ring, 1);
}





mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_ro_get_capacity(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_capacity(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_ro_get_size(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_size(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_ro_get_sise(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_sise(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_ro_get_free_size(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_free_size(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_dynamic_ring_inl_defd_ro_is_empty(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_is_empty(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_dynamic_ring_inl_defd_ro_is_full(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_is_full(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_ro_get_front(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_front(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_ro_get_back(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_back(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_ro_get_size_a(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_size_a(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_ro_get_sise_a(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_sise_a(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_ro_get_data_a(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_data_a(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_ro_get_size_b(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_size_b(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_ro_get_sise_b(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_sise_b(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_ro_get_data_b(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_data_b(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_ro_get_free_size_a(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_free_size_a(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_ro_get_free_data_a(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_free_data_a(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_ro_get_free_size_b(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_free_size_b(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pct mk_sl_dynamic_ring_inl_defd_ro_get_free_data_b(mk_sl_dynamic_ring_inl_defd_pct const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prro_get_free_data_b(ring);
}





mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_rw_get_capacity(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_capacity(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_rw_get_size(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_size(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_get_sise(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_sise(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_rw_get_free_size(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_free_size(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_dynamic_ring_inl_defd_rw_is_empty(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_is_empty(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_rw_get_front(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_front(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_rw_get_back(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_back(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_dynamic_ring_inl_defd_rw_is_full(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_is_full(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_rw_get_size_a(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_size_a(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_get_sise_a(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_sise_a(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_rw_get_data_a(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_data_a(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_rw_get_size_b(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_size_b(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_get_sise_b(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_sise_b(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_rw_get_data_b(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_data_b(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_rw_get_free_size_a(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_a(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_rw_get_free_data_a(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_a(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_usize_t mk_sl_dynamic_ring_inl_defd_rw_get_free_size_b(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_free_size_b(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_sl_dynamic_ring_inl_defd_element_pt mk_sl_dynamic_ring_inl_defd_rw_get_free_data_b(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_get_free_data_b(ring);
}





mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_construct(mk_sl_dynamic_ring_inl_defd_pt const ring mk_sl_dynamic_ring_inl_defd_mallocator_param) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_construct(ring mk_sl_dynamic_ring_inl_defd_mallocator_get_param);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_construct_copy(mk_sl_dynamic_ring_inl_defd_pt const dst, mk_sl_dynamic_ring_inl_defd_pct const src) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_construct_copy(dst, src);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_construct_move(mk_sl_dynamic_ring_inl_defd_pt const dst, mk_sl_dynamic_ring_inl_defd_pt const src) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_construct_move(dst, src);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_destroy(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_destroy(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_assign_copy(mk_sl_dynamic_ring_inl_defd_pt const dst, mk_sl_dynamic_ring_inl_defd_pct const src) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_assign_copy(dst, src);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_assign_move(mk_sl_dynamic_ring_inl_defd_pt const dst, mk_sl_dynamic_ring_inl_defd_pt const src) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_assign_move(dst, src);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_reserve_at_least(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_reserve_at_least(ring, count);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_reserve_additional(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_reserve_additional(ring, count);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_clear(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_clear(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_consolidate(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_consolidate(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_push_back_void(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_back_void(ring, count);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_push_back_move_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pt const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_back_move_many(ring, elements, count);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_push_back_copy_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_back_copy_many(ring, elements, count);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_push_back_move_single(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_back_move_single(ring, element);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_push_back_copy_single(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pct const element) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_back_copy_single(ring, element);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_push_front_move_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pt const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_front_move_many(ring, elements, count);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_push_front_copy_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_front_copy_many(ring, elements, count);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_push_front_move_single(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pt const element) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_front_move_single(ring, element);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_push_front_copy_single(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pct const element) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_push_front_copy_single(ring, element);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_pop_back_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_pop_back_many(ring, count);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_pop_back_single(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_pop_back_single(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_pop_front_many(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_pop_front_many(ring, count);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_pop_front_single(mk_sl_dynamic_ring_inl_defd_pt const ring) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_pop_front_single(ring);
}

/*mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_erase_at(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_erase_at(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_erase_element(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pct const element) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_erase_element(ring);
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_dynamic_ring_inl_defd_rw_erase_value(mk_sl_dynamic_ring_inl_defd_pt const ring, mk_sl_dynamic_ring_inl_defd_element_pct const element) mk_lang_noexcept
{
	return mk_sl_dynamic_ring_inl_defd_prrw_erase_value(ring);
}*/





#undef mk_sl_dynamic_ring_inl_filec_memcpy_name
#undef mk_sl_dynamic_ring_inl_filec_memcpy_fn

#undef mk_sl_dynamic_ring_inl_filec_memmov_name
#undef mk_sl_dynamic_ring_inl_filec_memmov_fn

#undef mk_sl_dynamic_ring_inl_filec_overlap_name
#undef mk_sl_dynamic_ring_inl_filec_overlap_fn


#include "mk_sl_dynamic_ring_inl_defu.h"
