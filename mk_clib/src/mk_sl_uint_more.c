#ifndef mk_include_guard_mk_sl_uint_more_c
#define mk_include_guard_mk_sl_uint_more_c
#include "mk_sl_uint_more.h"

#include "mk_lang_assert.h"
#include "mk_lang_configuration.h"
#include "mk_lang_constexpr.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_msvc.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"
#include "mk_sl_cui_uint32.h"
#include "mk_sl_cui_uint8.h"


#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
#include <memory.h> /* memcmp memcpy */
#pragma intrinsic(memcmp)
#pragma intrinsic(memcpy)
#endif


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

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_xor3_many_n(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint8_pct const b, mk_lang_types_usize_t const count, mk_sl_cui_uint8_pt const c) mk_lang_noexcept
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
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		#include "mk_lang_warning_msvc_push_c4296.h"
		#include "mk_lang_warning_gcc_push_type_limits.h"
		mk_lang_assert(a || count == 0);
		mk_lang_assert(b || count == 0);
		mk_lang_assert(count >= 0);
		#include "mk_lang_warning_gcc_pop.h"
		#include "mk_lang_warning_msvc_pop.h"

		memcpy(((mk_lang_types_void_pt)(a)), ((mk_lang_types_void_pct)(b)), count);
	}
	else
	#endif
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
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
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_from_bi_pchar_many(mk_sl_cui_uint8_pt const a, mk_lang_types_pchar_pct const b, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		#include "mk_lang_warning_msvc_push_c4296.h"
		#include "mk_lang_warning_gcc_push_type_limits.h"
		mk_lang_assert(a || count == 0);
		mk_lang_assert(b || count == 0);
		mk_lang_assert(count >= 0);
		#include "mk_lang_warning_gcc_pop.h"
		#include "mk_lang_warning_msvc_pop.h"

		memcpy(((mk_lang_types_void_pt)(a)), ((mk_lang_types_void_pct)(b)), count);
	}
	else
	#endif
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
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
			mk_sl_cui_uint8_from_bi_pchar(&a[i], &b[i]);
		}
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_to_bi_pchar_many(mk_sl_cui_uint8_pct const a, mk_lang_types_pchar_pt const b, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		#include "mk_lang_warning_msvc_push_c4296.h"
		#include "mk_lang_warning_gcc_push_type_limits.h"
		mk_lang_assert(a || count == 0);
		mk_lang_assert(b || count == 0);
		mk_lang_assert(count >= 0);
		#include "mk_lang_warning_gcc_pop.h"
		#include "mk_lang_warning_msvc_pop.h"

		memcpy(((mk_lang_types_void_pt)(b)), ((mk_lang_types_void_pct)(a)), count);
	}
	else
	#endif
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
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
			mk_sl_cui_uint8_to_bi_pchar(&a[i], &b[i]);
		}
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_to_bi_uchar_many(mk_sl_cui_uint8_pct const a, mk_lang_types_uchar_pt const b, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		#include "mk_lang_warning_msvc_push_c4296.h"
		#include "mk_lang_warning_gcc_push_type_limits.h"
		mk_lang_assert(a || count == 0);
		mk_lang_assert(b || count == 0);
		mk_lang_assert(count >= 0);
		#include "mk_lang_warning_gcc_pop.h"
		#include "mk_lang_warning_msvc_pop.h"

		memcpy(((mk_lang_types_void_pt)(b)), ((mk_lang_types_void_pct)(a)), count);
	}
	else
	#endif
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
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
			mk_sl_cui_uint8_to_bi_uchar(&a[i], &b[i]);
		}
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_nodiscard mk_lang_constexpr mk_lang_jumbo mk_lang_types_bool_t mk_sl_cui_uint8_eq_pchar_many(mk_sl_cui_uint8_pct const a, mk_lang_types_pchar_pct const b, mk_lang_types_usize_t const count) mk_lang_noexcept
{
	#if mk_lang_msvc_ver >= mk_lang_msvc_ver_2008
	#include "mk_lang_warning_msvc_push_c4127.h"
	if(!mk_lang_constexpr_is_constant_evaluated_test)
	#include "mk_lang_warning_msvc_pop.h"
	{
		mk_lang_types_sint_t res mk_lang_constexpr_init;
		mk_lang_types_bool_t eq mk_lang_constexpr_init;

		#include "mk_lang_warning_msvc_push_c4296.h"
		#include "mk_lang_warning_gcc_push_type_limits.h"
		mk_lang_assert(a || count == 0);
		mk_lang_assert(b || count == 0);
		mk_lang_assert(count >= 0);
		#include "mk_lang_warning_gcc_pop.h"
		#include "mk_lang_warning_msvc_pop.h"

		res = memcmp(((mk_lang_types_void_pct)(a)), ((mk_lang_types_void_pct)(b)), count);
		eq = res == 0;
		return eq;
	}
	else
	#endif
	{
		#include "mk_lang_warning_clang_push_unreachable_code.h"
		mk_lang_types_usize_t n mk_lang_constexpr_init;
		mk_lang_types_usize_t i mk_lang_constexpr_init;
		mk_sl_cui_uint8_t cui mk_lang_constexpr_init;
		mk_lang_types_bool_t eq mk_lang_constexpr_init;

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
			mk_sl_cui_uint8_from_bi_pchar(&cui, &b[i]);
			if(!mk_sl_cui_uint8_eq(&a[i], &cui))
			{
				break;
			}
		}
		eq = i == n;
		return eq;
		#include "mk_lang_warning_clang_pop.h"
	}
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_to_u32(mk_sl_cui_uint8_pct const a, mk_sl_cui_uint32_pt const b) mk_lang_noexcept
{
	mk_lang_types_uint_t tui mk_lang_constexpr_init;

	mk_sl_cui_uint8_to_bi_uint(a, &tui);
	mk_sl_cui_uint32_from_bi_uint(b, &tui);
}

mk_lang_constexpr mk_lang_jumbo mk_lang_types_void_t mk_sl_cui_uint8_mem_mark_new(mk_sl_cui_uint8_pt const mem, mk_lang_types_usize_t const count) mk_lang_noexcept
{
#if mk_lang_configuration_is_debug
	mk_lang_types_uchar_t tuc mk_lang_constexpr_init;
	mk_sl_cui_uint8_t pattern mk_lang_constexpr_init;

	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	tuc = 0xaa; mk_sl_cui_uint8_from_bi_uchar(&pattern, &tuc);
	mk_sl_cui_uint8_memset_fn(mem, &pattern, count);
#elif mk_lang_configuration_is_release
	#include "mk_lang_warning_msvc_push_c4296.h"
	mk_lang_assert(mem || count == 0);
	mk_lang_assert(count >= 0);
	#include "mk_lang_warning_msvc_pop.h"

	((mk_lang_types_void_t)(mem));
	((mk_lang_types_void_t)(count));
#else
#error xxxxxxxxxx
#endif
}


#endif
