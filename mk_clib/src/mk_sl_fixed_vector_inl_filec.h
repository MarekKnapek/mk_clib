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


#include "mk_sl_fixed_vector_inl_defd.h"


#define mk_sl_fixed_vector_inl_filec_memcpy_name mk_lang_concat(mk_sl_fixed_vector_inl_defd_name, _zzz_element_memcpy)
#define mk_sl_fixed_vector_inl_filec_memcpy_fn mk_lang_concat(mk_sl_fixed_vector_inl_filec_memcpy_name, _fn)
#define mk_lang_memcpy1_t_name mk_sl_fixed_vector_inl_filec_memcpy_name
#define mk_lang_memcpy1_t_type mk_sl_fixed_vector_inl_defd_element_t
#include "mk_lang_memcpy1_inl_fileh.h"
#include "mk_lang_memcpy1_inl_filec.h"
#include "mk_lang_memcpy1_inl_fileu.h"

#define mk_sl_fixed_vector_inl_filec_overlap_name mk_lang_concat(mk_sl_fixed_vector_inl_defd_name, _zzz_element_overlap)
#define mk_sl_fixed_vector_inl_filec_overlap_fn mk_lang_concat(mk_sl_fixed_vector_inl_filec_overlap_name, _fn)
#define mk_lang_overlap_t_name mk_sl_fixed_vector_inl_filec_overlap_name
#define mk_lang_overlap_t_type mk_sl_fixed_vector_inl_defd_element_t
#include "mk_lang_overlap_inl_fileh.h"
#include "mk_lang_overlap_inl_filec.h"
#include "mk_lang_overlap_inl_fileu.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_element_bitblt(mk_sl_fixed_vector_inl_defd_element_pt const dst, mk_sl_fixed_vector_inl_defd_element_pct const src) mk_lang_noexcept
{
	mk_lang_assert(dst);
	mk_lang_assert(src);

	*dst = *src;

	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_element_construct_void(mk_sl_fixed_vector_inl_defd_element_pt const element) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_element_construct_destroy_has
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(element);

	err = mk_sl_fixed_vector_inl_defd_element_construct_void(element); mk_lang_check_rereturn(err);

	return 0;
#else
	mk_lang_assert(element);

	((mk_lang_types_void_t)(element));

	return 0;
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_element_destroy(mk_sl_fixed_vector_inl_defd_element_pt const element) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_element_construct_destroy_has
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(element);

	err = mk_sl_fixed_vector_inl_defd_element_destroy(element); mk_lang_check_rereturn(err);

	return 0;
#else
	mk_lang_assert(element);

	((mk_lang_types_void_t)(element));

	return 0;
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_element_construct_copy(mk_sl_fixed_vector_inl_defd_element_pt const dst, mk_sl_fixed_vector_inl_defd_element_pct const src) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_bitblt
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(dst != src);
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_fixed_vector_inl_defd_prrw_element_bitblt(dst, src); mk_lang_check_rereturn(err);

	return 0;
#elif mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_custom
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(dst != src);
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_fixed_vector_inl_defd_element_construct_copy(dst, src); mk_lang_check_rereturn(err);

	return 0;
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_element_construct_move(mk_sl_fixed_vector_inl_defd_element_pt const dst, mk_sl_fixed_vector_inl_defd_element_pt const src) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_bitblt
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(dst != src);
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_fixed_vector_inl_defd_prrw_element_bitblt(dst, src); mk_lang_check_rereturn(err);

	return 0;
#elif mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_custom
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(dst != src);
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_fixed_vector_inl_defd_element_construct_move(dst, src); mk_lang_check_rereturn(err);

	return 0;
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_element_assign_copy(mk_sl_fixed_vector_inl_defd_element_pt const dst, mk_sl_fixed_vector_inl_defd_element_pct const src) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_bitblt
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(dst != src);
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_fixed_vector_inl_defd_prrw_element_bitblt(dst, src); mk_lang_check_rereturn(err);

	return 0;
#elif mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_custom
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(dst != src);
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_fixed_vector_inl_defd_element_assign_copy(dst, src); mk_lang_check_rereturn(err);

	return 0;
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_element_assign_move(mk_sl_fixed_vector_inl_defd_element_pt const dst, mk_sl_fixed_vector_inl_defd_element_pt const src) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_bitblt
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(dst != src);
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_fixed_vector_inl_defd_prrw_element_bitblt(dst, src); mk_lang_check_rereturn(err);

	return 0;
#elif mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_custom
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(dst);
	mk_lang_assert(src);
	mk_lang_assert(dst != src);
	#include "mk_lang_warning_msvc_pop.h"

	err = mk_sl_fixed_vector_inl_defd_element_assign_move(dst, src); mk_lang_check_rereturn(err);

	return 0;
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_prrw_element_eq(mk_sl_fixed_vector_inl_defd_element_pct const a, mk_sl_fixed_vector_inl_defd_element_pct const b) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_element_eq_has
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ret = mk_sl_fixed_vector_inl_defd_element_eq_fn(a, b);
	return ret;
#else
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(a);
	mk_lang_assert(b);

	ret = mk_lang_false;
	return ret;
#endif
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_prro_verify_invariants(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t gud mk_lang_constexpr_init;

	mk_lang_static_assert(((mk_lang_types_usize_t)(mk_sl_fixed_vector_inl_defd_capacity_d)) <= ((mk_lang_types_usize_t)(mk_lang_limits_usize_max)) / ((mk_lang_types_usize_t)(sizeof(mk_sl_fixed_vector_inl_defd_element_t))));

	mk_lang_assert(fixed_vector);

	gud = mk_lang_true;
	gud &= fixed_vector->m_size <= mk_sl_fixed_vector_inl_defd_capacity_d;
	return gud;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_prst_max_capacity(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_capacity_d;
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_prro_max_capacity(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	((mk_lang_types_void_t)(fixed_vector));
	ret = mk_sl_fixed_vector_inl_defd_prst_max_capacity();

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_prro_capacity(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_max_capacity(fixed_vector);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_prro_size(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = fixed_vector->m_size;

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prro_sise(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t size mk_lang_constexpr_init;
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	size = mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector);
	mk_lang_assert(size <= ((mk_lang_types_usize_t)(mk_lang_limits_sint_max)));
	ret = ((mk_lang_types_sint_t)(size));

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_prro_free(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_capacity(fixed_vector) - mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_prro_is_empty(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector) == 0;

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_prro_is_full(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_free(fixed_vector) == 0;

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_prro_data(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = &fixed_vector->m_arr[0];

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_prro_at(mk_sl_fixed_vector_inl_defd_pct const fixed_vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_prro_is_empty(fixed_vector));
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx < mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	ret = &mk_sl_fixed_vector_inl_defd_prro_data(fixed_vector)[idx];

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_prro_front(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_prro_is_empty(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_at(fixed_vector, 0);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_prro_back(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_prro_is_empty(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_at(fixed_vector, mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector) - 1);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_prro_eq(mk_sl_fixed_vector_inl_defd_pct const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t m mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_sl_fixed_vector_inl_defd_element_pct ea mk_lang_constexpr_init;
	mk_sl_fixed_vector_inl_defd_element_pct eb mk_lang_constexpr_init;
	mk_lang_types_bool_t eq mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(other);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(other));

	ret = mk_lang_false;
	n = mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector);
	m = mk_sl_fixed_vector_inl_defd_prro_size(other);
	if(n == m)
	{
		ret = mk_lang_true;
		for(i = 0; i != n; ++i)
		{
			ea = mk_sl_fixed_vector_inl_defd_prro_at(fixed_vector, i); mk_lang_assert(ea);
			eb = mk_sl_fixed_vector_inl_defd_prro_at(other, i); mk_lang_assert(eb);
			eq = mk_sl_fixed_vector_inl_defd_prrw_element_eq(ea, eb);
			if(!eq)
			{
				ret = mk_lang_false;
				break;
			}
		}
	}

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(other));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_prro_ne(mk_sl_fixed_vector_inl_defd_pct const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(other);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(other));

	ret = !mk_sl_fixed_vector_inl_defd_prro_eq(fixed_vector, other);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(other));
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_prrw_max_capacity(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_max_capacity(fixed_vector);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_prrw_capacity(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_capacity(fixed_vector);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_prrw_size(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_sise(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_sise(fixed_vector);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_prrw_free(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_free(fixed_vector);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_prrw_is_empty(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_is_empty(fixed_vector);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_prrw_is_full(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_is_full(fixed_vector);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_prrw_data(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = &fixed_vector->m_arr[0];

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_prrw_at(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt ret mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_prro_is_empty(fixed_vector));
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx < mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	ret = &mk_sl_fixed_vector_inl_defd_prrw_data(fixed_vector)[idx];

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_prrw_front(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_prro_is_empty(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prrw_at(fixed_vector, 0);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_prrw_back(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_prro_is_empty(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prrw_at(fixed_vector, mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector) - 1);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_prrw_eq(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	ret = mk_sl_fixed_vector_inl_defd_prro_eq(fixed_vector, other);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_prrw_ne(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(other);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(other));

	ret = !mk_sl_fixed_vector_inl_defd_prrw_eq(fixed_vector, other);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(other));
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_elements_construct_void_from_to(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const idx_from, mk_lang_types_usize_t const idx_to) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_element_construct_destroy_has
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_usize_t idx;
	mk_sl_fixed_vector_inl_defd_element_pt e;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(idx_from >= 0);
	mk_lang_assert(idx_from < mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	mk_lang_assert(idx_to >= 0);
	mk_lang_assert(idx_to < mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	mk_lang_assert(idx_from <= idx_to);
	#include "mk_lang_warning_msvc_pop.h"

	n = idx_to - idx_from + 1;
	for(i = 0; i != n; ++i)
	{
		idx = idx_from + i;
		e = mk_sl_fixed_vector_inl_defd_prrw_at(fixed_vector, idx); mk_lang_assert(e);
		err = mk_sl_fixed_vector_inl_defd_prrw_element_construct_void(e); mk_lang_check_rereturn(err);
	}

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(idx_from >= 0);
	mk_lang_assert(idx_from < mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	mk_lang_assert(idx_to >= 0);
	mk_lang_assert(idx_to < mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	mk_lang_assert(idx_from <= idx_to);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));
	((mk_lang_types_void_t)(idx_from));
	((mk_lang_types_void_t)(idx_to));

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_elements_destroy_from_to(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const idx_from, mk_lang_types_usize_t const idx_to) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_element_construct_destroy_has
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_usize_t idx;
	mk_sl_fixed_vector_inl_defd_element_pt e;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(idx_from >= 0);
	mk_lang_assert(idx_from < mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	mk_lang_assert(idx_to >= 0);
	mk_lang_assert(idx_to < mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	mk_lang_assert(idx_from <= idx_to);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = idx_to - idx_from + 1;
	for(i = 0; i != n; ++i)
	{
		idx = idx_from + i;
		e = mk_sl_fixed_vector_inl_defd_prrw_at(fixed_vector, idx); mk_lang_assert(e);
		err = mk_sl_fixed_vector_inl_defd_prrw_element_destroy(e); mk_lang_check_rereturn(err);
	}

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
#else
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(idx_from >= 0);
	mk_lang_assert(idx_from < mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	mk_lang_assert(idx_to >= 0);
	mk_lang_assert(idx_to < mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	mk_lang_assert(idx_from <= idx_to);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));
	((mk_lang_types_void_t)(idx_from));
	((mk_lang_types_void_t)(idx_to));

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_elements_construct_void_last(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t idx_from mk_lang_constexpr_init;
	mk_lang_types_usize_t idx_to mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		idx_from = mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector) - count;
		idx_to = mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector) - 1;
		err = mk_sl_fixed_vector_inl_defd_prrw_elements_construct_void_from_to(fixed_vector, idx_from, idx_to); mk_lang_check_rereturn(err);
	}

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_elements_destroy_last(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t idx_from mk_lang_constexpr_init;
	mk_lang_types_usize_t idx_to mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count != 0)
	{
		idx_from = mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector) - count;
		idx_to = mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector) - 1;
		err = mk_sl_fixed_vector_inl_defd_prrw_elements_destroy_from_to(fixed_vector, idx_from, idx_to); mk_lang_check_rereturn(err);
	}

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_elements_destroy_all(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t count mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	count = mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector);
	err = mk_sl_fixed_vector_inl_defd_prrw_elements_destroy_last(fixed_vector, count); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_elements_construct_copy_many(mk_sl_fixed_vector_inl_defd_element_pt const dst, mk_sl_fixed_vector_inl_defd_element_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_bitblt
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_capacity_d);
	mk_lang_assert(dst != src);
	mk_lang_assert(!mk_sl_fixed_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_fixed_vector_inl_filec_memcpy_fn(dst, src, count);

	return 0;
#elif mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_custom
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_capacity_d);
	mk_lang_assert(dst != src);
	mk_lang_assert(!mk_sl_fixed_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_sl_fixed_vector_inl_defd_prrw_element_construct_copy(&dst[i], &src[i]); mk_lang_check_rereturn(err);
	}

	return 0;
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_elements_construct_move_many(mk_sl_fixed_vector_inl_defd_element_pt const dst, mk_sl_fixed_vector_inl_defd_element_pt const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_bitblt
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_capacity_d);
	mk_lang_assert(dst != src);
	mk_lang_assert(!mk_sl_fixed_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_fixed_vector_inl_filec_memcpy_fn(dst, src, count);

	return 0;
#elif mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_custom
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_capacity_d);
	mk_lang_assert(dst != src);
	mk_lang_assert(!mk_sl_fixed_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_sl_fixed_vector_inl_defd_prrw_element_construct_move(&dst[i], &src[i]); mk_lang_check_rereturn(err);
	}

	return 0;
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_elements_assign_copy_many(mk_sl_fixed_vector_inl_defd_element_pt const dst, mk_sl_fixed_vector_inl_defd_element_pct const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_bitblt
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_capacity_d);
	mk_lang_assert(dst != src);
	mk_lang_assert(!mk_sl_fixed_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_fixed_vector_inl_filec_memcpy_fn(dst, src, count);

	return 0;
#elif mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_custom
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_capacity_d);
	mk_lang_assert(dst != src);
	mk_lang_assert(!mk_sl_fixed_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_sl_fixed_vector_inl_defd_prrw_element_assign_copy(&dst[i], &src[i]); mk_lang_check_rereturn(err);
	}

	return 0;
#else
#error xxxxxxxxxx
#endif
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_elements_assign_move_many(mk_sl_fixed_vector_inl_defd_element_pt const dst, mk_sl_fixed_vector_inl_defd_element_pt const src, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_bitblt
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_capacity_d);
	mk_lang_assert(dst != src);
	mk_lang_assert(!mk_sl_fixed_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	mk_sl_fixed_vector_inl_filec_memcpy_fn(dst, src, count);

	return 0;
#elif mk_sl_fixed_vector_inl_defd_copy_style == mk_sl_fixed_vector_copy_use_custom
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(dst || count == 0);
	mk_lang_assert(src || count == 0);
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_capacity_d);
	mk_lang_assert(dst != src);
	mk_lang_assert(!mk_sl_fixed_vector_inl_filec_overlap_fn(dst, count, src, count));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		err = mk_sl_fixed_vector_inl_defd_prrw_element_assign_move(&dst[i], &src[i]); mk_lang_check_rereturn(err);
	}

	return 0;
#else
#error xxxxxxxxxx
#endif
}


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_construct_void(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_assert(fixed_vector);

	fixed_vector->m_size = 0;

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_destroy(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	err = mk_sl_fixed_vector_inl_defd_prrw_elements_destroy_all(fixed_vector); mk_lang_check_rereturn(err);

	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_construct_copy(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const src) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt d mk_lang_constexpr_init;
	mk_sl_fixed_vector_inl_defd_element_pct s mk_lang_constexpr_init;
	mk_lang_types_usize_t c mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(src));

	d = mk_sl_fixed_vector_inl_defd_prrw_data(fixed_vector); mk_lang_assert(d);
	s = mk_sl_fixed_vector_inl_defd_prro_data(src); mk_lang_assert(s);
	c = mk_sl_fixed_vector_inl_defd_prro_size(src);
	err = mk_sl_fixed_vector_inl_defd_prrw_elements_construct_copy_many(d, s, c); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_construct_move(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pt const src) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt d mk_lang_constexpr_init;
	mk_sl_fixed_vector_inl_defd_element_pt s mk_lang_constexpr_init;
	mk_lang_types_usize_t c mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(src));

	d = mk_sl_fixed_vector_inl_defd_prrw_data(fixed_vector); mk_lang_assert(d);
	s = mk_sl_fixed_vector_inl_defd_prrw_data(src); mk_lang_assert(s);
	c = mk_sl_fixed_vector_inl_defd_prrw_size(src);
	err = mk_sl_fixed_vector_inl_defd_prrw_elements_construct_move_many(d, s, c); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_assign_copy(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const src) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt d mk_lang_constexpr_init;
	mk_sl_fixed_vector_inl_defd_element_pct s mk_lang_constexpr_init;
	mk_lang_types_usize_t c mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(src));

	d = mk_sl_fixed_vector_inl_defd_prrw_data(fixed_vector); mk_lang_assert(d);
	s = mk_sl_fixed_vector_inl_defd_prro_data(src); mk_lang_assert(s);
	c = mk_sl_fixed_vector_inl_defd_prro_size(src);
	err = mk_sl_fixed_vector_inl_defd_prrw_elements_assign_copy_many(d, s, c); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_assign_move(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pt const src) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pt d mk_lang_constexpr_init;
	mk_sl_fixed_vector_inl_defd_element_pt s mk_lang_constexpr_init;
	mk_lang_types_usize_t c mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(src);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(src));

	d = mk_sl_fixed_vector_inl_defd_prrw_data(fixed_vector); mk_lang_assert(d);
	s = mk_sl_fixed_vector_inl_defd_prrw_data(src); mk_lang_assert(s);
	c = mk_sl_fixed_vector_inl_defd_prrw_size(src);
	err = mk_sl_fixed_vector_inl_defd_prrw_elements_assign_move_many(d, s, c); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(src));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_reserve_at_least(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(count == mk_sl_fixed_vector_inl_defd_capacity_d);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_reserve_additional(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(count == 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_shrink_by(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(count == 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_resize_to(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t diff mk_lang_constexpr_init;
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_capacity_d);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	if(count > fixed_vector->m_size)
	{
		diff = count - fixed_vector->m_size;
		fixed_vector->m_size = count;
		err = mk_sl_fixed_vector_inl_defd_prrw_elements_construct_void_last(fixed_vector, diff); mk_lang_check_rereturn(err);
	}
	else if(count < fixed_vector->m_size)
	{
		diff = fixed_vector->m_size - count;
		err = mk_sl_fixed_vector_inl_defd_prrw_elements_destroy_last(fixed_vector, diff); mk_lang_check_rereturn(err);
		fixed_vector->m_size = count;
	}

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_grow_by(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t err mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_prrw_free(fixed_vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	fixed_vector->m_size += count;
	err = mk_sl_fixed_vector_inl_defd_prrw_elements_construct_void_last(fixed_vector, count); mk_lang_check_rereturn(err);

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_clear(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));

	((mk_lang_types_void_t)(fixed_vector));
	mk_lang_assert_false();

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_push_back_copy_many(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count == 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));
	mk_lang_assert_false();

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_push_back_move_many(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pt const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(elements || count == 0);
	mk_lang_assert(count == 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));
	mk_lang_assert_false();

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_push_back_copy_single(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(element);

	((mk_lang_types_void_t)(fixed_vector));
	mk_lang_assert_false();

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_push_back_move_single(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pt const element) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(element);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));
	mk_lang_assert_false();

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_pop_back_many(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(count >= 0);
	mk_lang_assert(count <= mk_sl_fixed_vector_inl_defd_prrw_size(fixed_vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));
	mk_lang_assert_false();

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_pop_back_single(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_prrw_is_empty(fixed_vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));
	mk_lang_assert_false();

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_erase_at(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_prrw_is_empty(fixed_vector));
	mk_lang_assert(idx >= 0);
	mk_lang_assert(idx < mk_sl_fixed_vector_inl_defd_prrw_size(fixed_vector));
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(fixed_vector));
	mk_lang_assert_false();

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_prrw_erase_element(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_assert(fixed_vector);
	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	mk_lang_assert(element);
	mk_lang_assert(!mk_sl_fixed_vector_inl_defd_prrw_is_empty(fixed_vector));
	mk_lang_assert(element >= &fixed_vector->m_arr[0] && element <= &fixed_vector->m_arr[mk_sl_fixed_vector_inl_defd_prrw_size(fixed_vector) - 1]);
	mk_lang_assert(mk_sl_fixed_vector_inl_filec_overlap_fn(element, 1, &fixed_vector->m_arr[0], 1));

	((mk_lang_types_void_t)(fixed_vector));
	mk_lang_assert_false();

	mk_lang_assert(mk_sl_fixed_vector_inl_defd_prro_verify_invariants(fixed_vector));
	return 0;
}





mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_st_max_capacity(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prst_max_capacity();
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_ro_max_capacity(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_max_capacity(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_ro_capacity(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_capacity(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_ro_size(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_size(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_ro_sise(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_sise(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_ro_free(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_usize_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_free(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_ro_is_empty(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_is_empty(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_ro_is_full(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_is_full(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_data(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_data(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_at(mk_sl_fixed_vector_inl_defd_pct const fixed_vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_at(fixed_vector, idx);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_front(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_front(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pct mk_sl_fixed_vector_inl_defd_ro_back(mk_sl_fixed_vector_inl_defd_pct const fixed_vector) mk_lang_noexcept
{
	mk_sl_fixed_vector_inl_defd_element_pct ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_back(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_ro_eq(mk_sl_fixed_vector_inl_defd_pct const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_eq(fixed_vector, other);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_ro_ne(mk_sl_fixed_vector_inl_defd_pct const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const other) mk_lang_noexcept
{
	mk_lang_types_bool_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prro_ne(fixed_vector, other);
	return ret;
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_rw_max_capacity(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	return mk_sl_fixed_vector_inl_defd_ro_max_capacity(fixed_vector);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_rw_capacity(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	return mk_sl_fixed_vector_inl_defd_ro_capacity(fixed_vector);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_rw_size(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	return mk_sl_fixed_vector_inl_defd_ro_size(fixed_vector);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_sise(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	return mk_sl_fixed_vector_inl_defd_ro_sise(fixed_vector);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_usize_t mk_sl_fixed_vector_inl_defd_rw_free(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	return mk_sl_fixed_vector_inl_defd_ro_free(fixed_vector);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_rw_is_empty(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	return mk_sl_fixed_vector_inl_defd_ro_is_empty(fixed_vector);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_rw_is_full(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	return mk_sl_fixed_vector_inl_defd_ro_is_full(fixed_vector);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_data(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	#include "mk_lang_warning_clang_push_cast_qual.h"
	return ((mk_sl_fixed_vector_inl_defd_element_pt)(mk_sl_fixed_vector_inl_defd_ro_data(fixed_vector)));
	#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_at(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	#include "mk_lang_warning_clang_push_cast_qual.h"
	return ((mk_sl_fixed_vector_inl_defd_element_pt)(mk_sl_fixed_vector_inl_defd_ro_at(fixed_vector, idx)));
	#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_front(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	#include "mk_lang_warning_clang_push_cast_qual.h"
	return ((mk_sl_fixed_vector_inl_defd_element_pt)(mk_sl_fixed_vector_inl_defd_ro_front(fixed_vector)));
	#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_sl_fixed_vector_inl_defd_element_pt mk_sl_fixed_vector_inl_defd_rw_back(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	#include "mk_lang_warning_clang_push_cast_qual.h"
	return ((mk_sl_fixed_vector_inl_defd_element_pt)(mk_sl_fixed_vector_inl_defd_ro_back(fixed_vector)));
	#include "mk_lang_warning_clang_pop.h"
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_rw_eq(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const other) mk_lang_noexcept
{
	return mk_sl_fixed_vector_inl_defd_ro_eq(((mk_sl_fixed_vector_inl_defd_pct)(fixed_vector)), other);
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_fixed_vector_inl_defd_rw_ne(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const other) mk_lang_noexcept
{
	return mk_sl_fixed_vector_inl_defd_ro_ne(((mk_sl_fixed_vector_inl_defd_pct)(fixed_vector)), other);
}


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_construct_void(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_construct_void(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_destroy(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_destroy(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_construct_copy(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_construct_copy(fixed_vector, src);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_construct_move(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_construct_move(fixed_vector, src);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_assign_copy(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pct const src) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_assign_copy(fixed_vector, src);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_assign_move(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_pt const src) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_assign_move(fixed_vector, src);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_reserve_at_least(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_reserve_at_least(fixed_vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_reserve_additional(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_reserve_additional(fixed_vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_shrink_by(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_shrink_by(fixed_vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_resize_to(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_resize_to(fixed_vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_grow_by(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_grow_by(fixed_vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_clear(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_clear(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_push_back_copy_many(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pct const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_push_back_copy_many(fixed_vector, elements, count);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_push_back_move_many(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pt const elements, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_push_back_move_many(fixed_vector, elements, count);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_push_back_copy_single(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_push_back_copy_single(fixed_vector, element);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_push_back_move_single(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pt const element) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_push_back_move_single(fixed_vector, element);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_pop_back_many(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_pop_back_many(fixed_vector, count);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_pop_back_single(mk_sl_fixed_vector_inl_defd_pt const fixed_vector) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_pop_back_single(fixed_vector);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_erase_at(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_lang_types_usize_t const idx) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_erase_at(fixed_vector, idx);
	return ret;
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_sint_t mk_sl_fixed_vector_inl_defd_rw_erase_element(mk_sl_fixed_vector_inl_defd_pt const fixed_vector, mk_sl_fixed_vector_inl_defd_element_pct const element) mk_lang_noexcept
{
	mk_lang_types_sint_t ret mk_lang_constexpr_init;

	ret = mk_sl_fixed_vector_inl_defd_prrw_erase_element(fixed_vector, element);
	return ret;
}


#undef mk_sl_fixed_vector_inl_filec_memcpy_name
#undef mk_sl_fixed_vector_inl_filec_memcpy_fn

#undef mk_sl_fixed_vector_inl_filec_overlap_name
#undef mk_sl_fixed_vector_inl_filec_overlap_fn


#include "mk_sl_fixed_vector_inl_defu.h"
