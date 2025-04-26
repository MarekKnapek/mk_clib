#ifndef mk_include_guard_mk_sl_uint_more_c
#define mk_include_guard_mk_sl_uint_more_c
#include "mk_sl_uint_more.h"

#include "mk_lang_assert.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint8.h"


mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_xor2_many(mk_sl_cui_uint8_pt const a, mk_sl_cui_uint8_pct const b, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_xor2(&a[i], &b[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_xor3_many_1(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pct const b, mk_lang_types_usize_t const count, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(count >= 0);
	mk_lang_assert(c);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_xor3(&a[i], b, &c[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_xor3_many_n(mk_sl_cui_uint8_pct const a,mk_sl_cui_uint8_pct const b, mk_lang_types_usize_t const count, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(a);
	mk_lang_assert(b);
	mk_lang_assert(count >= 0);
	mk_lang_assert(c);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_xor3(&a[i], &b[i], &c[i]);
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_from_bi_uchar_many(mk_sl_cui_uint8_pt const a, mk_lang_types_uchar_pct const b, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	mk_lang_types_usize_t n mk_lang_constexpr_init;
	mk_lang_types_usize_t i mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	#include "mk_lang_warning_gcc_push_type_limits.h"
	mk_lang_assert(a || count == 0);
	mk_lang_assert(b || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_gcc_pop.h"
	#include "mk_lang_warning_msvc_pop.h"

	n = count;
	for(i = 0; i != n; ++i)
	{
		mk_sl_cui_uint8_from_bi_uchar(&a[i], &b[i]);
	}
}


#endif
