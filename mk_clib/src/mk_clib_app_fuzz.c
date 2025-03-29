#ifndef mk_include_guard_mk_clib_app_fuzz_c
#define mk_include_guard_mk_clib_app_fuzz_c
#include "mk_clib_app_fuzz.h"

#include "mk_clib_fuzz.h"
#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_check.h"
#include "mk_lang_countof.h"
#include "mk_lang_cpuid.h"
#include "mk_lang_inline.h"
#include "mk_lang_limits.h"
#include "mk_lang_min.h"
#include "mk_lang_nodiscard.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_null.h"
#include "mk_lang_types.h"

#include <stdio.h> /* putchar puts */
#include <stdlib.h> /* srand rand */
#include <time.h> /* time_t time clock_t clock CLK_TCK */


mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fuzz_init_rand(mk_lang_types_void_t) mk_lang_noexcept
{
	time_t t;
	mk_lang_types_uint_t u;

	t = time(mk_lang_null); mk_lang_check_return(t != ((time_t)(-1))); u = ((mk_lang_types_uint_t)(t));
	srand(u);
	return 0;
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_fuzz_fill_rand(mk_lang_types_uchar_pt const data, mk_lang_types_sint_t const size) mk_lang_noexcept
{
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	n = size;
	for(i = 0; i != n; ++i)
	{
		data[i] = ((mk_lang_types_uchar_t)(rand() & 0xff));
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_fuzz_adjust_rand(mk_lang_types_uchar_pt const data, mk_lang_types_sint_t const size, mk_lang_types_sint_t const count) mk_lang_noexcept
{
	mk_lang_types_uchar_t buf[16];
	mk_lang_types_sint_t n;
	mk_lang_types_sint_t i;
	mk_lang_types_uint_t tui;

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);
	mk_lang_assert(count >= 0 && count <= mk_lang_countof(buf));
	mk_lang_assert(size >= count * mk_lang_sizeof_bi_uint_t);

	mk_clib_app_fuzz_fill_rand(&buf[0], count);
	n = count;
	for(i = 0; i != n; ++i)
	{
		if(buf[i] % 2 == 0)
		{
			mk_lang_bui_uint_set_max(&tui);
			mk_lang_bui_uint_to_buis_uchar_le(&tui, &data[i * mk_lang_sizeof_bi_uint_t]);
		}
	}
}

static mk_lang_inline mk_lang_types_void_t mk_clib_app_fuzz_one(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_uchar_t data[1024];

	mk_clib_app_fuzz_fill_rand(&data[0], mk_lang_countof(data));
	mk_clib_app_fuzz_adjust_rand(&data[0], mk_lang_countof(data), 8);
	mk_clib_fuzz(&data[0], mk_lang_countof(data), mk_lang_true);
}

mk_lang_nodiscard static mk_lang_inline mk_lang_types_sint_t mk_clib_app_fuzz_lot(mk_lang_types_void_t) mk_lang_noexcept
{
	enum mk_clib_fuzz_fn_ticks_e{ mk_clib_fuzz_fn_ticks_v = 10 * CLK_TCK };
	enum mk_clib_fuzz_fn_attempts_e{ mk_clib_fuzz_fn_attempts_v = 1000 };
	enum mk_clib_fuzz_fn_percent_e{ mk_clib_fuzz_fn_percent_v = 40 };

	mk_lang_types_sint_t percent_new;
	mk_lang_types_sint_t percent_dif;
	mk_lang_types_sint_t percent_old;
	mk_lang_types_ulong_t attempt;
	clock_t clk_start;
	clock_t clk_now;
	clock_t clk_dif_ticks;

	percent_new = 0;
	percent_dif = 0;
	percent_old = 0;
	attempt = 0;
	clk_start = clock(); mk_lang_check_return(clk_start != ((clock_t)(-1)));
	do
	{
		mk_clib_app_fuzz_one();
		clk_now = clock(); mk_lang_check_return(clk_now != ((clock_t)(-1)));
		clk_dif_ticks = clk_now - clk_start;
		++attempt;
		percent_new = mk_lang_min(((mk_lang_types_sint_t)((clk_dif_ticks * mk_clib_fuzz_fn_percent_v) / mk_clib_fuzz_fn_ticks_v)), ((mk_lang_types_sint_t)((attempt * mk_clib_fuzz_fn_percent_v) / mk_clib_fuzz_fn_attempts_v)));
		percent_dif = percent_new - percent_old;
		percent_old = percent_new;
		while(percent_dif > 0)
		{
			putchar('.');
			--percent_dif;
		}
	}while((clk_dif_ticks < mk_clib_fuzz_fn_ticks_v || attempt < mk_clib_fuzz_fn_attempts_v) && (attempt < mk_lang_limits_ulong_max / mk_clib_fuzz_fn_percent_v));
	puts("");
	return 0;
}


mk_lang_nodiscard mk_lang_jumbo mk_lang_types_sint_t mk_clib_app_fuzz_void(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_types_sint_t err;

	mk_lang_cpuid_init();
	err = mk_clib_app_fuzz_init_rand(); mk_lang_check_rereturn(err);
	err = mk_clib_app_fuzz_lot(); mk_lang_check_rereturn(err);
	return 0;
}


#endif
