#ifndef mk_include_guard_mk_sl_sort_merge_test_cpp
#define mk_include_guard_mk_sl_sort_merge_test_cpp


#if defined mk_lang_jumbo_want
#undef mk_lang_jumbo_want
#endif
#define mk_lang_jumbo_want 2


#include "mk_lang_warning_msvc_push_c4514.h"


#include "mk_sl_sort_merge_test.hpp"

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_extern.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr_array_u8.hpp"
#include "mk_sl_cui_uint8.h"


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_test_1_cmp(mk_lang_types_uintptr_t const context, mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	((mk_lang_types_void_t)(context));
	c = *a <= *b;
	return c;
}
#define mk_sl_sort_merge_t_name mk_sl_sort_merge_test_1
#define mk_sl_sort_merge_t_element_type mk_lang_types_sint_t
#define mk_sl_sort_merge_t_element_is_sorted mk_sl_sort_merge_test_1_cmp
#define mk_sl_sort_merge_t_first_round 0
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_test_2_cmp(mk_lang_types_uintptr_t const context, mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	((mk_lang_types_void_t)(context));
	c = *a <= *b;
	return c;
}
#define mk_sl_sort_merge_t_name mk_sl_sort_merge_test_2
#define mk_sl_sort_merge_t_element_type mk_lang_types_sint_t
#define mk_sl_sort_merge_t_element_is_sorted mk_sl_sort_merge_test_2_cmp
#define mk_sl_sort_merge_t_first_round 1
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_test_3_cmp(mk_lang_types_sint_pct const context, mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	c = context[*a] <= context[*b];
	return c;
}
#define mk_sl_sort_merge_t_name mk_sl_sort_merge_test_3
#define mk_sl_sort_merge_t_element_type mk_lang_types_sint_t
#define mk_sl_sort_merge_t_element_is_sorted mk_sl_sort_merge_test_3_cmp
#define mk_sl_sort_merge_t_context_type mk_lang_types_sint_pct
#define mk_sl_sort_merge_t_first_round 0
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_test_4_cmp(mk_lang_types_sint_pct const context, mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	c = context[*a] <= context[*b];
	return c;
}
#define mk_sl_sort_merge_t_name mk_sl_sort_merge_test_4
#define mk_sl_sort_merge_t_element_type mk_lang_types_sint_t
#define mk_sl_sort_merge_t_element_is_sorted mk_sl_sort_merge_test_4_cmp
#define mk_sl_sort_merge_t_context_type mk_lang_types_sint_pct
#define mk_sl_sort_merge_t_first_round 1
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14


template<mk_lang_types_usize_t n>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_sl_sort_merge_test_sort_numbers_1(mk_lang_types_sint_t const(&arr)[n]) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_sint_t, n> ret mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_sint_t, n> tmp mk_lang_constexpr_init;

	for(i = 0; i != n; ++i)
	{
		ret[i] = arr[i];
	}
	mk_sl_sort_merge_test_1_fn(0, ret.data(), ret.size(), tmp.data());
	return ret;
}

template<mk_lang_types_usize_t n>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_sl_sort_merge_test_sort_numbers_2(mk_lang_types_sint_t const(&arr)[n]) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_sint_t, n> ret mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_sint_t, n> tmp mk_lang_constexpr_init;

	for(i = 0; i != n; ++i)
	{
		ret[i] = arr[i];
	}
	mk_sl_sort_merge_test_2_fn(0, ret.data(), ret.size(), tmp.data());
	return ret;
}

template<mk_lang_types_usize_t n>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_sl_sort_merge_test_sort_numbers_3(mk_lang_types_sint_t const(&arr)[n]) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_sint_t, n> proxy mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_sint_t, n> tmp mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_sint_t, n> ret mk_lang_constexpr_init;

	for(i = 0; i != n; ++i)
	{
		proxy[i] = ((mk_lang_types_sint_t)(i));
	}
	mk_sl_sort_merge_test_3_fn(&arr[0], proxy.data(), proxy.size(), tmp.data());
	for(i = 0; i != n; ++i)
	{
		ret[i] = arr[proxy[i]];
	}
	return ret;
}

template<mk_lang_types_usize_t n>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto mk_sl_sort_merge_test_sort_numbers_4(mk_lang_types_sint_t const(&arr)[n]) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_sint_t, n> proxy mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_sint_t, n> tmp mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_sint_t, n> ret mk_lang_constexpr_init;

	for(i = 0; i != n; ++i)
	{
		proxy[i] = ((mk_lang_types_sint_t)(i));
	}
	mk_sl_sort_merge_test_4_fn(&arr[0], proxy.data(), proxy.size(), tmp.data());
	for(i = 0; i != n; ++i)
	{
		ret[i] = arr[proxy[i]];
	}
	return ret;
}


#endif


mk_lang_extern_force_c mk_lang_types_void_t mk_sl_sort_merge_test(mk_lang_types_void_t) mk_lang_noexcept
{
#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14
	mk_lang_constexpr_static mk_lang_types_sint_t const numbers_unsorted[] = {42, 1986, 4, 26, 1979, 3, 28, 2011, 3, 11};
	mk_lang_constexpr_static auto const numbers_sorted_1 = mk_sl_sort_merge_test_sort_numbers_1(numbers_unsorted);
	mk_lang_constexpr_static auto const numbers_sorted_2 = mk_sl_sort_merge_test_sort_numbers_2(numbers_unsorted);
	mk_lang_constexpr_static auto const numbers_sorted_3 = mk_sl_sort_merge_test_sort_numbers_3(numbers_unsorted);
	mk_lang_constexpr_static auto const numbers_sorted_4 = mk_sl_sort_merge_test_sort_numbers_4(numbers_unsorted);
	mk_lang_constexpr_static mk_lang_types_sint_t const numbers_sorted_0[] = {3, 3, 4, 11, 26, 28, 42, 1979, 1986, 2011};

	mk_lang_static_assert(numbers_sorted_1[0] == numbers_sorted_0[0]);
	mk_lang_static_assert(numbers_sorted_1[1] == numbers_sorted_0[1]);
	mk_lang_static_assert(numbers_sorted_1[2] == numbers_sorted_0[2]);
	mk_lang_static_assert(numbers_sorted_1[3] == numbers_sorted_0[3]);
	mk_lang_static_assert(numbers_sorted_1[4] == numbers_sorted_0[4]);
	mk_lang_static_assert(numbers_sorted_1[5] == numbers_sorted_0[5]);
	mk_lang_static_assert(numbers_sorted_1[6] == numbers_sorted_0[6]);
	mk_lang_static_assert(numbers_sorted_1[7] == numbers_sorted_0[7]);
	mk_lang_static_assert(numbers_sorted_1[8] == numbers_sorted_0[8]);
	mk_lang_static_assert(numbers_sorted_1[9] == numbers_sorted_0[9]);

	mk_lang_static_assert(numbers_sorted_2[0] == numbers_sorted_0[0]);
	mk_lang_static_assert(numbers_sorted_2[1] == numbers_sorted_0[1]);
	mk_lang_static_assert(numbers_sorted_2[2] == numbers_sorted_0[2]);
	mk_lang_static_assert(numbers_sorted_2[3] == numbers_sorted_0[3]);
	mk_lang_static_assert(numbers_sorted_2[4] == numbers_sorted_0[4]);
	mk_lang_static_assert(numbers_sorted_2[5] == numbers_sorted_0[5]);
	mk_lang_static_assert(numbers_sorted_2[6] == numbers_sorted_0[6]);
	mk_lang_static_assert(numbers_sorted_2[7] == numbers_sorted_0[7]);
	mk_lang_static_assert(numbers_sorted_2[8] == numbers_sorted_0[8]);
	mk_lang_static_assert(numbers_sorted_2[9] == numbers_sorted_0[9]);

	mk_lang_static_assert(numbers_sorted_3[0] == numbers_sorted_0[0]);
	mk_lang_static_assert(numbers_sorted_3[1] == numbers_sorted_0[1]);
	mk_lang_static_assert(numbers_sorted_3[2] == numbers_sorted_0[2]);
	mk_lang_static_assert(numbers_sorted_3[3] == numbers_sorted_0[3]);
	mk_lang_static_assert(numbers_sorted_3[4] == numbers_sorted_0[4]);
	mk_lang_static_assert(numbers_sorted_3[5] == numbers_sorted_0[5]);
	mk_lang_static_assert(numbers_sorted_3[6] == numbers_sorted_0[6]);
	mk_lang_static_assert(numbers_sorted_3[7] == numbers_sorted_0[7]);
	mk_lang_static_assert(numbers_sorted_3[8] == numbers_sorted_0[8]);
	mk_lang_static_assert(numbers_sorted_3[9] == numbers_sorted_0[9]);

	mk_lang_static_assert(numbers_sorted_4[0] == numbers_sorted_0[0]);
	mk_lang_static_assert(numbers_sorted_4[1] == numbers_sorted_0[1]);
	mk_lang_static_assert(numbers_sorted_4[2] == numbers_sorted_0[2]);
	mk_lang_static_assert(numbers_sorted_4[3] == numbers_sorted_0[3]);
	mk_lang_static_assert(numbers_sorted_4[4] == numbers_sorted_0[4]);
	mk_lang_static_assert(numbers_sorted_4[5] == numbers_sorted_0[5]);
	mk_lang_static_assert(numbers_sorted_4[6] == numbers_sorted_0[6]);
	mk_lang_static_assert(numbers_sorted_4[7] == numbers_sorted_0[7]);
	mk_lang_static_assert(numbers_sorted_4[8] == numbers_sorted_0[8]);
	mk_lang_static_assert(numbers_sorted_4[9] == numbers_sorted_0[9]);
#endif
}


#include "mk_lang_warning_msvc_pop.h"


#endif
