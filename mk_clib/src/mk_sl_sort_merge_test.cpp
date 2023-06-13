#include "mk_sl_sort_merge_test.hpp"


#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_sizet.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_types.h"
#include "mk_lang_version.h"
#include "mk_lib_cpp_constexpr.hpp"


#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14


mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_sort_merge_test_cmp(mk_lang_types_sint_prct const a, mk_lang_types_sint_prct const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a <= *b;
}


#define mk_lang_bui_name sort_merge_test
#define mk_lang_bui_type mk_lang_types_usize_t
#define mk_lang_bui_sizeof mk_lang_sizeof_bi_size_t
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_sort_merge_name test1
#define mk_sl_sort_merge_data_t mk_lang_types_sint_t
#define mk_sl_sort_merge_count_t mk_lang_types_usize_t
#define mk_sl_sort_merge_count_math_prefix mk_lang_bui_sort_merge_test
#define mk_sl_sort_merge_is_sorted mk_sl_sort_merge_test_cmp
#define mk_sl_sort_merge_first_round 0
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"

#define mk_sl_sort_merge_name test2
#define mk_sl_sort_merge_data_t mk_lang_types_sint_t
#define mk_sl_sort_merge_count_t mk_lang_types_usize_t
#define mk_sl_sort_merge_count_math_prefix mk_lang_bui_sort_merge_test
#define mk_sl_sort_merge_is_sorted mk_sl_sort_merge_test_cmp
#define mk_sl_sort_merge_first_round 1
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"

#define mk_sl_sort_merge_name test3
#define mk_sl_sort_merge_data_t mk_lang_types_sint_t
#define mk_sl_sort_merge_count_t mk_lang_types_usize_t
#define mk_sl_sort_merge_count_math_prefix mk_lang_bui_sort_merge_test
#define mk_sl_sort_merge_is_sorted mk_sl_sort_merge_test_cmp
#define mk_sl_sort_merge_proxy_t mk_lang_types_usize_t
#define mk_sl_sort_merge_first_round 0
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"

#define mk_sl_sort_merge_name test4
#define mk_sl_sort_merge_data_t mk_lang_types_sint_t
#define mk_sl_sort_merge_count_t mk_lang_types_usize_t
#define mk_sl_sort_merge_count_math_prefix mk_lang_bui_sort_merge_test
#define mk_sl_sort_merge_is_sorted mk_sl_sort_merge_test_cmp
#define mk_sl_sort_merge_proxy_t mk_lang_types_usize_t
#define mk_sl_sort_merge_first_round 1
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"


template<mk_lang_types_usize_t n>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto sort_numbers1(int const(&arr)[n]) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<int, n> ret mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<int, n> tmp mk_lang_constexpr_init;

	for(i = 0; i != n; ++i)
	{
		ret[i] = arr[i];
	}
	mk_sl_sort_merge_test1_plain(ret.data(), ret.size(), tmp.data());
	return ret;
}

template<mk_lang_types_usize_t n>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto sort_numbers2(int const(&arr)[n]) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<int, n> ret mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<int, n> tmp mk_lang_constexpr_init;

	for(i = 0; i != n; ++i)
	{
		ret[i] = arr[i];
	}
	mk_sl_sort_merge_test2_plain(ret.data(), ret.size(), tmp.data());
	return ret;
}

template<mk_lang_types_usize_t n>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto sort_numbers3(int const(&arr)[n]) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<int, n> ret mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_usize_t, n> proxy mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_usize_t, n> tmp mk_lang_constexpr_init;

	for(i = 0; i != n; ++i)
	{
		proxy[i] = i;
	}
	mk_sl_sort_merge_test3_proxy(arr, proxy.data(), ret.size(), tmp.data());
	for(i = 0; i != n; ++i)
	{
		ret[i] = arr[proxy[i]];
	}
	return ret;
}

template<mk_lang_types_usize_t n>
mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo auto sort_numbers4(int const(&arr)[n]) mk_lang_noexcept
{
	mk_lang_types_usize_t i mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<int, n> ret mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_usize_t, n> proxy mk_lang_constexpr_init;
	mk_lib_cpp_constexpr_array_t<mk_lang_types_usize_t, n> tmp mk_lang_constexpr_init;

	for(i = 0; i != n; ++i)
	{
		proxy[i] = i;
	}
	mk_sl_sort_merge_test4_proxy(arr, proxy.data(), ret.size(), tmp.data());
	for(i = 0; i != n; ++i)
	{
		ret[i] = arr[proxy[i]];
	}
	return ret;
}


#endif


mk_lang_extern_c void mk_sl_sort_merge_test(void) mk_lang_noexcept
{
	#if mk_lang_version_at_least_cpp_14 || mk_lang_version_at_least_msvc_cpp_14

	mk_lang_constexpr_static int const s_numbers_unsorted[] = {42, 1986, 4, 26, 1979, 3, 28, 2011, 3, 11};
	mk_lang_constexpr_static auto const s_numbers_sorted1 = sort_numbers1(s_numbers_unsorted);
	mk_lang_constexpr_static auto const s_numbers_sorted2 = sort_numbers2(s_numbers_unsorted);
	mk_lang_constexpr_static auto const s_numbers_sorted3 = sort_numbers3(s_numbers_unsorted);
	mk_lang_constexpr_static auto const s_numbers_sorted4 = sort_numbers4(s_numbers_unsorted);
	mk_lang_constexpr_static int const s_numbers_test[] = {3, 3, 4, 11, 26, 28, 42, 1979, 1986, 2011};

	mk_lang_static_assert(s_numbers_sorted1[0] == s_numbers_test[0]);
	mk_lang_static_assert(s_numbers_sorted1[1] == s_numbers_test[1]);
	mk_lang_static_assert(s_numbers_sorted1[2] == s_numbers_test[2]);
	mk_lang_static_assert(s_numbers_sorted1[3] == s_numbers_test[3]);
	mk_lang_static_assert(s_numbers_sorted1[4] == s_numbers_test[4]);
	mk_lang_static_assert(s_numbers_sorted1[5] == s_numbers_test[5]);
	mk_lang_static_assert(s_numbers_sorted1[6] == s_numbers_test[6]);
	mk_lang_static_assert(s_numbers_sorted1[7] == s_numbers_test[7]);
	mk_lang_static_assert(s_numbers_sorted1[8] == s_numbers_test[8]);
	mk_lang_static_assert(s_numbers_sorted1[9] == s_numbers_test[9]);

	mk_lang_static_assert(s_numbers_sorted2[0] == s_numbers_test[0]);
	mk_lang_static_assert(s_numbers_sorted2[1] == s_numbers_test[1]);
	mk_lang_static_assert(s_numbers_sorted2[2] == s_numbers_test[2]);
	mk_lang_static_assert(s_numbers_sorted2[3] == s_numbers_test[3]);
	mk_lang_static_assert(s_numbers_sorted2[4] == s_numbers_test[4]);
	mk_lang_static_assert(s_numbers_sorted2[5] == s_numbers_test[5]);
	mk_lang_static_assert(s_numbers_sorted2[6] == s_numbers_test[6]);
	mk_lang_static_assert(s_numbers_sorted2[7] == s_numbers_test[7]);
	mk_lang_static_assert(s_numbers_sorted2[8] == s_numbers_test[8]);
	mk_lang_static_assert(s_numbers_sorted2[9] == s_numbers_test[9]);

	mk_lang_static_assert(s_numbers_sorted3[0] == s_numbers_test[0]);
	mk_lang_static_assert(s_numbers_sorted3[1] == s_numbers_test[1]);
	mk_lang_static_assert(s_numbers_sorted3[2] == s_numbers_test[2]);
	mk_lang_static_assert(s_numbers_sorted3[3] == s_numbers_test[3]);
	mk_lang_static_assert(s_numbers_sorted3[4] == s_numbers_test[4]);
	mk_lang_static_assert(s_numbers_sorted3[5] == s_numbers_test[5]);
	mk_lang_static_assert(s_numbers_sorted3[6] == s_numbers_test[6]);
	mk_lang_static_assert(s_numbers_sorted3[7] == s_numbers_test[7]);
	mk_lang_static_assert(s_numbers_sorted3[8] == s_numbers_test[8]);
	mk_lang_static_assert(s_numbers_sorted3[9] == s_numbers_test[9]);

	mk_lang_static_assert(s_numbers_sorted4[0] == s_numbers_test[0]);
	mk_lang_static_assert(s_numbers_sorted4[1] == s_numbers_test[1]);
	mk_lang_static_assert(s_numbers_sorted4[2] == s_numbers_test[2]);
	mk_lang_static_assert(s_numbers_sorted4[3] == s_numbers_test[3]);
	mk_lang_static_assert(s_numbers_sorted4[4] == s_numbers_test[4]);
	mk_lang_static_assert(s_numbers_sorted4[5] == s_numbers_test[5]);
	mk_lang_static_assert(s_numbers_sorted4[6] == s_numbers_test[6]);
	mk_lang_static_assert(s_numbers_sorted4[7] == s_numbers_test[7]);
	mk_lang_static_assert(s_numbers_sorted4[8] == s_numbers_test[8]);
	mk_lang_static_assert(s_numbers_sorted4[9] == s_numbers_test[9]);

	#endif
}
