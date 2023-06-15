#include "mk_sl_sort_merge_fuzz.h"


#include "mk_lang_assert.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"
#include "mk_lang_types.h"

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_sort_merge_fuzz_cmp2_plain(mk_lang_types_ushort_prct const a, mk_lang_types_ushort_prct const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a <= *b;
}

mk_lang_nodiscard mk_lang_jumbo mk_lang_types_bool_t mk_sl_sort_merge_fuzz_cmp2_proxy(mk_lang_types_ushort_prct const a, mk_lang_types_ushort_prct const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return *a <= *b;
}

#define mk_lang_bui_name sort_merge_fuzz
#define mk_lang_bui_type mk_lang_types_ushort_t
#define mk_lang_bui_sizeof 1
#include "mk_lang_bui_inl_fileh.h"
#include "mk_lang_bui_inl_filec.h"

#define mk_sl_sort_merge_name fuzz1
#define mk_sl_sort_merge_data_t mk_lang_types_ushort_t
#define mk_sl_sort_merge_count_t mk_lang_types_ushort_t
#define mk_sl_sort_merge_count_math_prefix mk_lang_bui_sort_merge_fuzz
#define mk_sl_sort_merge_is_sorted mk_sl_sort_merge_fuzz_cmp2_plain
#define mk_sl_sort_merge_first_round 0
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"

#define mk_sl_sort_merge_name fuzz2
#define mk_sl_sort_merge_data_t mk_lang_types_ushort_t
#define mk_sl_sort_merge_count_t mk_lang_types_ushort_t
#define mk_sl_sort_merge_count_math_prefix mk_lang_bui_sort_merge_fuzz
#define mk_sl_sort_merge_is_sorted mk_sl_sort_merge_fuzz_cmp2_plain
#define mk_sl_sort_merge_first_round 1
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"

#define mk_sl_sort_merge_name fuzz3
#define mk_sl_sort_merge_data_t mk_lang_types_ushort_t
#define mk_sl_sort_merge_count_t mk_lang_types_ushort_t
#define mk_sl_sort_merge_count_math_prefix mk_lang_bui_sort_merge_fuzz
#define mk_sl_sort_merge_is_sorted mk_sl_sort_merge_fuzz_cmp2_proxy
#define mk_sl_sort_merge_proxy_t mk_lang_types_uchar_t
#define mk_sl_sort_merge_first_round 0
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"

#define mk_sl_sort_merge_name fuzz4
#define mk_sl_sort_merge_data_t mk_lang_types_ushort_t
#define mk_sl_sort_merge_count_t mk_lang_types_ushort_t
#define mk_sl_sort_merge_count_math_prefix mk_lang_bui_sort_merge_fuzz
#define mk_sl_sort_merge_is_sorted mk_sl_sort_merge_fuzz_cmp2_proxy
#define mk_sl_sort_merge_proxy_t mk_lang_types_uchar_t
#define mk_sl_sort_merge_first_round 1
#include "mk_sl_sort_merge_inl_fileh.h"
#include "mk_sl_sort_merge_inl_filec.h"

#include <stdlib.h> /* qsort */
static mk_lang_types_ushort_pct g;


mk_lang_nodiscard mk_lang_jumbo int mk_sl_sort_merge_fuzz_cmp1_plain(mk_lang_types_void_pct const a, mk_lang_types_void_pct const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return ((int)(*((mk_lang_types_ushort_pct)(a)))) - ((int)(*((mk_lang_types_ushort_pct)(b))));
}

mk_lang_nodiscard mk_lang_jumbo int mk_sl_sort_merge_fuzz_cmp1_proxy(mk_lang_types_void_pct const a, mk_lang_types_void_pct const b)
{
	mk_lang_assert(a);
	mk_lang_assert(b);

	return ((int)(g[*((mk_lang_types_uchar_pct)(a))])) - ((int)(g[*((mk_lang_types_uchar_pct)(b))]));
}

mk_lang_jumbo void mk_sl_sort_merge_testn_plain(int const variant, mk_lang_types_ushort_pt const buffer, mk_lang_types_uchar_t const count, mk_lang_types_ushort_pt const tmp) mk_lang_noexcept
{
	mk_lang_assert(variant >= 0 && variant <= 1);

	switch(variant)
	{
		case 0: mk_sl_sort_merge_fuzz1_plain(buffer, count, tmp); break;
		case 1: mk_sl_sort_merge_fuzz2_plain(buffer, count, tmp); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_jumbo void mk_sl_sort_merge_testn_proxy(int const variant, mk_lang_types_ushort_pct const buffer, mk_lang_types_uchar_pt const proxy, mk_lang_types_uchar_t const count, mk_lang_types_uchar_pt const tmp) mk_lang_noexcept
{
	mk_lang_assert(variant >= 0 && variant <= 1);

	switch(variant)
	{
		case 0: mk_sl_sort_merge_fuzz3_proxy(buffer, proxy, count, tmp); break;
		case 1: mk_sl_sort_merge_fuzz4_proxy(buffer, proxy, count, tmp); break;
		default: mk_lang_assert(0); break;
	}
}

mk_lang_jumbo void mk_sl_sort_merge_fuzz_plain(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((void)(0))
	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_assert(0); mk_lang_crash(); } ((void)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_size_t s;
	int variant;
	mk_lang_types_uchar_t count;
	mk_lang_types_uchar_t i;
	mk_lang_types_ushort_t buffer1[256];
	mk_lang_types_ushort_t buffer2[256];
	mk_lang_types_ushort_t tmp[256];

	d = data;
	s = size;
	check(s >= 1);
	variant = ((int)(*d & 0x1));
	advance(1);
	check(s >= 1);
	count = *d;
	advance(1);
	check(s >= count * sizeof(mk_lang_types_ushort_t));
	for(i = 0; i != count; ++i)
	{
		buffer1[i] = ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(d[0])) << 8)) | ((mk_lang_types_ushort_t)(d[1]))));
		buffer2[i] = buffer1[i];
		advance(sizeof(mk_lang_types_ushort_t));
	}
	qsort(buffer1, count, sizeof(mk_lang_types_ushort_t), mk_sl_sort_merge_fuzz_cmp1_plain);
	mk_sl_sort_merge_testn_plain(variant, buffer2, count, tmp);
	for(i = 0; i != count; ++i)
	{
		test(buffer2[i] == buffer1[i]);
	}

	#undef check
	#undef advance
	#undef test
}

mk_lang_jumbo void mk_sl_sort_merge_fuzz_proxy(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((void)(0))
	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_assert(0); mk_lang_crash(); } ((void)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_size_t s;
	int variant;
	mk_lang_types_uchar_t count;
	mk_lang_types_uchar_t i;
	mk_lang_types_ushort_t buffer1[256];
	mk_lang_types_ushort_t buffer2[256];
	mk_lang_types_uchar_t proxy1[256];
	mk_lang_types_uchar_t proxy2[256];
	mk_lang_types_uchar_t tmp[256];

	d = data;
	s = size;
	check(s >= 1);
	variant = ((int)(*d & 0x1));
	advance(1);
	check(s >= 1);
	count = *d;
	advance(1);
	check(s >= count * sizeof(mk_lang_types_ushort_t));
	for(i = 0; i != count; ++i)
	{
		buffer1[i] = ((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(((mk_lang_types_ushort_t)(d[0])) << 8)) | ((mk_lang_types_ushort_t)(d[1]))));
		buffer2[i] = buffer1[i];
		proxy1[i] = i;
		proxy2[i] = proxy1[i];
		advance(sizeof(mk_lang_types_ushort_t));
	}
	g = buffer1;
	qsort(proxy1, count, 1, mk_sl_sort_merge_fuzz_cmp1_proxy);
	mk_sl_sort_merge_testn_proxy(variant, buffer2, proxy2, count, tmp);
	for(i = 0; i != count; ++i)
	{
		test(buffer2[i] == buffer1[i]);
		test(buffer2[proxy2[i]] == buffer1[proxy1[i]]);
	}

	#undef check
	#undef advance
	#undef test
}


mk_lang_jumbo void mk_sl_sort_merge_fuzz(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((void)(0))
	#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_assert(0); mk_lang_crash(); } ((void)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_size_t s;
	int variant;

	d = data;
	s = size;
	check(s >= 1);
	variant = ((int)(*d & 0x1));
	advance(1);
	switch(variant)
	{
		case 0: mk_sl_sort_merge_fuzz_plain(d, s); break;
		case 1: mk_sl_sort_merge_fuzz_proxy(d, s); break;
		default: mk_lang_assert(0); break;
	}

	#undef check
	#undef advance
	#undef test
}
