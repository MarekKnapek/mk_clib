#ifndef mk_include_guard_mk_sl_sort_merge_fuzz_c
#define mk_include_guard_mk_sl_sort_merge_fuzz_c
#include "mk_sl_sort_merge_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_bui.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_string.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"

#include <stdlib.h> /* qsort */


mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_fuzz_1_cmp(mk_lang_types_uintptr_t const context, mk_lang_types_ulllong_pct const a, mk_lang_types_ulllong_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	((mk_lang_types_void_t)(context));
	c = *a <= *b;
	return c;
}
#define mk_sl_sort_merge_t_name mk_sl_sort_merge_fuzz_1
#define mk_sl_sort_merge_t_element_type mk_lang_types_ulllong_t
#define mk_sl_sort_merge_t_element_is_sorted mk_sl_sort_merge_fuzz_1_cmp
#define mk_sl_sort_merge_t_first_round 0
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_fuzz_1_sort(mk_lang_types_ulllong_pt const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_ulllong_t tmp[64];

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(len <= mk_lang_countof(tmp));

	mk_sl_sort_merge_fuzz_1_fn(0, buf, len, &tmp[0]);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_fuzz_2_cmp(mk_lang_types_uintptr_t const context, mk_lang_types_ulllong_pct const a, mk_lang_types_ulllong_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(&context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	((mk_lang_types_void_t)(context));
	c = *a <= *b;
	return c;
}
#define mk_sl_sort_merge_t_name mk_sl_sort_merge_fuzz_2
#define mk_sl_sort_merge_t_element_type mk_lang_types_ulllong_t
#define mk_sl_sort_merge_t_element_is_sorted mk_sl_sort_merge_fuzz_2_cmp
#define mk_sl_sort_merge_t_first_round 1
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_fuzz_2_sort(mk_lang_types_ulllong_pt const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_ulllong_t tmp[64];

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(len <= mk_lang_countof(tmp));

	mk_sl_sort_merge_fuzz_2_fn(0, buf, len, &tmp[0]);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_fuzz_3_cmp(mk_lang_types_ulllong_pct const context, mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	c = context[*a] <= context[*b];
	return c;
}
#define mk_sl_sort_merge_t_name mk_sl_sort_merge_fuzz_3
#define mk_sl_sort_merge_t_element_type mk_lang_types_sint_t
#define mk_sl_sort_merge_t_element_is_sorted mk_sl_sort_merge_fuzz_3_cmp
#define mk_sl_sort_merge_t_context_type mk_lang_types_ulllong_pct
#define mk_sl_sort_merge_t_first_round 0
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_fuzz_3_sort(mk_lang_types_ulllong_pt const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t sints[64];
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t tmp[mk_lang_countof(sints)];
	mk_lang_types_ulllong_t res[mk_lang_countof(sints)];

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(len <= mk_lang_countof(sints));

	n = len;
	for(i = 0; i != n; ++i)
	{
		sints[i] = i;
	}
	mk_sl_sort_merge_fuzz_3_fn(buf, &sints[0], len, &tmp[0]);
	for(i = 0; i != n; ++i)
	{
		res[i] = buf[sints[i]];
	}
	mk_lang_string_memcpy_ulll_fn(buf, &res[0], len);
}

mk_lang_nodiscard mk_lang_constexpr static mk_lang_inline mk_lang_types_bool_t mk_sl_sort_merge_fuzz_4_cmp(mk_lang_types_ulllong_pct const context, mk_lang_types_sint_pct const a, mk_lang_types_sint_pct const b) mk_lang_noexcept
{
	mk_lang_types_bool_t c mk_lang_constexpr_init;

	mk_lang_assert(context);
	mk_lang_assert(a);
	mk_lang_assert(b);

	c = context[*a] <= context[*b];
	return c;
}
#define mk_sl_sort_merge_t_name mk_sl_sort_merge_fuzz_4
#define mk_sl_sort_merge_t_element_type mk_lang_types_sint_t
#define mk_sl_sort_merge_t_element_is_sorted mk_sl_sort_merge_fuzz_4_cmp
#define mk_sl_sort_merge_t_context_type mk_lang_types_ulllong_pct
#define mk_sl_sort_merge_t_first_round 1
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"
#include "mk_sl_sort_merge_inl_fileu.h"
mk_lang_constexpr static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_fuzz_4_sort(mk_lang_types_ulllong_pt const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{
	mk_lang_types_sint_t sints[64];
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_sint_t tmp[mk_lang_countof(sints)];
	mk_lang_types_ulllong_t res[mk_lang_countof(sints)];

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);
	mk_lang_assert(len <= mk_lang_countof(sints));

	n = len;
	for(i = 0; i != n; ++i)
	{
		sints[i] = i;
	}
	mk_sl_sort_merge_fuzz_4_fn(buf, &sints[0], len, &tmp[0]);
	for(i = 0; i != n; ++i)
	{
		res[i] = buf[sints[i]];
	}
	mk_lang_string_memcpy_ulll_fn(buf, &res[0], len);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_sl_sort_merge_fuzz_0_cmp(mk_lang_types_void_pct const a, mk_lang_types_void_pct const b) mk_lang_noexcept
{
	mk_lang_types_ulllong_t aa;
	mk_lang_types_ulllong_t bb;
	mk_lang_types_sint_t c;

	mk_lang_assert(a);
	mk_lang_assert(b);

	aa = *((mk_lang_types_ulllong_pct)(a));
	bb = *((mk_lang_types_ulllong_pct)(b));
	c = aa < bb ? -1 : (aa > bb ? +1 : 0);
	return c;
}

static mk_lang_inline mk_lang_types_void_t mk_sl_sort_merge_fuzz_0_sort(mk_lang_types_ulllong_pt const buf, mk_lang_types_sint_t const len) mk_lang_noexcept
{

	mk_lang_assert(buf || len == 0);
	mk_lang_assert(len >= 0);

	qsort(buf, len, sizeof(*buf), &mk_sl_sort_merge_fuzz_0_cmp);
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_sl_sort_merge_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t count;
	mk_lang_types_ulllong_t elements_0[64];
	mk_lang_types_uint_t n;
	mk_lang_types_uint_t i;
	mk_lang_types_ulllong_t elements_1[mk_lang_countof(elements_0)];
	mk_lang_types_ulllong_t elements_2[mk_lang_countof(elements_0)];
	mk_lang_types_ulllong_t elements_3[mk_lang_countof(elements_0)];
	mk_lang_types_ulllong_t elements_4[mk_lang_countof(elements_0)];

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	d = data;
	s = size;

	if(!(s >= mk_lang_bui_uint_size_bytes_v))
	{
		return 0;
	}
	mk_lang_bui_uint_from_buis_uchar_le(&count, &d[0]); /* todo ne */
	d += mk_lang_bui_uint_size_bytes_v;
	s -= mk_lang_bui_uint_size_bytes_v;
	count = mk_lang_min(count, mk_lang_countof(elements_0));
	count = mk_lang_min(count, ((mk_lang_types_uint_t)(s / sizeof(elements_0[0]))));

	n = count;
	for(i = 0; i != n; ++i)
	{
		mk_lang_bui_ulllong_from_buis_uchar_le(&elements_0[i], &d[0]); /* todo ne */
		d += sizeof(elements_0[0]);
		s -= sizeof(elements_0[0]);
	}
	mk_lang_string_memcpy_ulll_fn(&elements_1[0], &elements_0[0], count);
	mk_lang_string_memcpy_ulll_fn(&elements_2[0], &elements_0[0], count);
	mk_lang_string_memcpy_ulll_fn(&elements_3[0], &elements_0[0], count);
	mk_lang_string_memcpy_ulll_fn(&elements_4[0], &elements_0[0], count);

	mk_sl_sort_merge_fuzz_0_sort(&elements_0[0], count);
	mk_sl_sort_merge_fuzz_1_sort(&elements_1[0], count);
	mk_sl_sort_merge_fuzz_2_sort(&elements_2[0], count);
	mk_sl_sort_merge_fuzz_3_sort(&elements_3[0], count);
	mk_sl_sort_merge_fuzz_4_sort(&elements_4[0], count);
	mk_lang_test(mk_lang_string_memcmp_ulll_fn(&elements_1[0], &elements_0[0], count) == 0);
	mk_lang_test(mk_lang_string_memcmp_ulll_fn(&elements_2[0], &elements_0[0], count) == 0);
	mk_lang_test(mk_lang_string_memcmp_ulll_fn(&elements_3[0], &elements_0[0], count) == 0);
	mk_lang_test(mk_lang_string_memcmp_ulll_fn(&elements_4[0], &elements_0[0], count) == 0);
	return 0;
}


#endif
