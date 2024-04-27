#include "mk_lib_fmt_fuzz.h"

#include "mk_lang_assert.h"
#include "mk_lang_countof.h"
#include "mk_lang_inline.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_static_assert.h"
#include "mk_lang_test.h"
#include "mk_lang_types.h"
#include "mk_sl_uint32.h"

#define mk_lib_fmt_t_name mk_lib_fmt_fuzz_n
#define mk_lib_fmt_t_wide 0
#include "mk_lib_fmt_inl_fileh.h"
#include "mk_lib_fmt_inl_filec.h"

#define mk_lib_fmt_t_name mk_lib_fmt_fuzz_w
#define mk_lib_fmt_t_wide 1
#include "mk_lib_fmt_inl_fileh.h"
#include "mk_lib_fmt_inl_filec.h"

#include <stdio.h>
#include <string.h>
#include <wchar.h>


static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_n_d(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t tui;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_sint_t tsia;
	mk_lang_types_pchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_pchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_uint_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 4);
	memcpy(&tui, d, 4);
	memcpy(&tu32, d, 4);
	advance(4);
	tsia = snprintf(&bufa[0], mk_lang_countof(bufa), "%d", *((mk_lang_types_sint_pct)(&tui)));
	tsib = mk_lib_fmt_fuzz_n_snprintf(&bufb[0], mk_lang_countof(bufb), "%d", &tu32);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_w_d(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t tui;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_sint_t tsia;
	mk_lang_types_wchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_wchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_uint_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 4);
	memcpy(&tui, d, 4);
	memcpy(&tu32, d, 4);
	advance(4);
	tsia = swprintf(&bufa[0], mk_lang_countof(bufa), L"%d", *((mk_lang_types_sint_pct)(&tui)));
	tsib = mk_lib_fmt_fuzz_w_snprintf(&bufb[0], mk_lang_countof(bufb), L"%d", &tu32);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_n_u(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t tui;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_sint_t tsia;
	mk_lang_types_pchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_pchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_uint_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 4);
	memcpy(&tui, d, 4);
	memcpy(&tu32, d, 4);
	advance(4);
	tsia = snprintf(&bufa[0], mk_lang_countof(bufa), "%u", tui);
	tsib = mk_lib_fmt_fuzz_n_snprintf(&bufb[0], mk_lang_countof(bufb), "%u", &tu32);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_w_u(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t tui;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_sint_t tsia;
	mk_lang_types_wchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_wchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_uint_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 4);
	memcpy(&tui, d, 4);
	memcpy(&tu32, d, 4);
	advance(4);
	tsia = swprintf(&bufa[0], mk_lang_countof(bufa), L"%u", tui);
	tsib = mk_lib_fmt_fuzz_w_snprintf(&bufb[0], mk_lang_countof(bufb), L"%u", &tu32);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_n_x(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t tui;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_sint_t tsia;
	mk_lang_types_pchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_pchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_uint_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 4);
	memcpy(&tui, d, 4);
	memcpy(&tu32, d, 4);
	advance(4);
	tsia = snprintf(&bufa[0], mk_lang_countof(bufa), "%x", tui);
	tsib = mk_lib_fmt_fuzz_n_snprintf(&bufb[0], mk_lang_countof(bufb), "%x", &tu32);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_w_x(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_uint_t tui;
	mk_sl_cui_uint32_t tu32;
	mk_lang_types_sint_t tsia;
	mk_lang_types_wchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_wchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_uint_t) == 4);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint32_t) == 4);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 4);
	memcpy(&tui, d, 4);
	memcpy(&tu32, d, 4);
	advance(4);
	tsia = swprintf(&bufa[0], mk_lang_countof(bufa), L"%x", tui);
	tsib = mk_lib_fmt_fuzz_w_snprintf(&bufb[0], mk_lang_countof(bufb), L"%x", &tu32);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_n_lld(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_ullong_t tull;
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_sint_t tsia;
	mk_lang_types_pchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_pchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_ullong_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 8);
	memcpy(&tull, d, 8);
	memcpy(&tu64, d, 8);
	advance(8);
	tsia = snprintf(&bufa[0], mk_lang_countof(bufa), "%lld", *((mk_lang_types_sllong_pct)(&tull)));
	tsib = mk_lib_fmt_fuzz_n_snprintf(&bufb[0], mk_lang_countof(bufb), "%lld", &tu64);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_w_lld(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_ullong_t tull;
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_sint_t tsia;
	mk_lang_types_wchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_wchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_ullong_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 8);
	memcpy(&tull, d, 8);
	memcpy(&tu64, d, 8);
	advance(8);
	tsia = swprintf(&bufa[0], mk_lang_countof(bufa), L"%lld", *((mk_lang_types_sllong_pct)(&tull)));
	tsib = mk_lib_fmt_fuzz_w_snprintf(&bufb[0], mk_lang_countof(bufb), L"%lld", &tu64);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_n_llu(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_ullong_t tull;
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_sint_t tsia;
	mk_lang_types_pchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_pchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_ullong_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 8);
	memcpy(&tull, d, 8);
	memcpy(&tu64, d, 8);
	advance(8);
	tsia = snprintf(&bufa[0], mk_lang_countof(bufa), "%llu", tull);
	tsib = mk_lib_fmt_fuzz_n_snprintf(&bufb[0], mk_lang_countof(bufb), "%llu", &tu64);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_w_llu(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_ullong_t tull;
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_sint_t tsia;
	mk_lang_types_wchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_wchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_ullong_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 8);
	memcpy(&tull, d, 8);
	memcpy(&tu64, d, 8);
	advance(8);
	tsia = swprintf(&bufa[0], mk_lang_countof(bufa), L"%llu", tull);
	tsib = mk_lib_fmt_fuzz_w_snprintf(&bufb[0], mk_lang_countof(bufb), L"%llu", &tu64);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_n_llx(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_ullong_t tull;
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_sint_t tsia;
	mk_lang_types_pchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_pchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_ullong_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 8);
	memcpy(&tull, d, 8);
	memcpy(&tu64, d, 8);
	advance(8);
	tsia = snprintf(&bufa[0], mk_lang_countof(bufa), "%llx", tull);
	tsib = mk_lib_fmt_fuzz_n_snprintf(&bufb[0], mk_lang_countof(bufb), "%llx", &tu64);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}

static mk_lang_inline mk_lang_types_void_t mk_lib_fmt_fuzz_w_llx(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	#define check(x) if(!(x)) return;
	#define advance(x) d += (x); s -= (x); ((mk_lang_types_void_t)(0))

	mk_lang_types_uchar_pct d;
	mk_lang_types_usize_t s;
	mk_lang_types_ullong_t tull;
	mk_sl_cui_uint64_t tu64;
	mk_lang_types_sint_t tsia;
	mk_lang_types_wchar_t bufa[64];
	mk_lang_types_sint_t tsib;
	mk_lang_types_wchar_t bufb[mk_lang_countof(bufa)];

	mk_lang_static_assert(sizeof(mk_lang_types_ullong_t) == 8);
	mk_lang_static_assert(sizeof(mk_sl_cui_uint64_t) == 8);

	mk_lang_assert(data || size == 0);
	mk_lang_assert(size >= 0);

	d = data;
	s = size;
	check(s >= 8);
	memcpy(&tull, d, 8);
	memcpy(&tu64, d, 8);
	advance(8);
	tsia = swprintf(&bufa[0], mk_lang_countof(bufa), L"%llx", tull);
	tsib = mk_lib_fmt_fuzz_w_snprintf(&bufb[0], mk_lang_countof(bufb), L"%llx", &tu64);
	mk_lang_test(tsia == tsib);
	mk_lang_test(memcmp(&bufa[0], &bufb[0], (tsia + 1) * sizeof(bufa[0])) == 0);

	#undef check
	#undef advance
}


mk_lang_jumbo mk_lang_types_void_t mk_lib_fmt_fuzz(mk_lang_types_uchar_pct const data, mk_lang_types_usize_t const size) mk_lang_noexcept
{
	mk_lib_fmt_fuzz_n_d(data, size);
	mk_lib_fmt_fuzz_w_d(data, size);
	mk_lib_fmt_fuzz_n_u(data, size);
	mk_lib_fmt_fuzz_w_u(data, size);
	mk_lib_fmt_fuzz_n_x(data, size);
	mk_lib_fmt_fuzz_w_x(data, size);
	mk_lib_fmt_fuzz_n_lld(data, size);
	mk_lib_fmt_fuzz_w_lld(data, size);
	mk_lib_fmt_fuzz_n_llu(data, size);
	mk_lib_fmt_fuzz_w_llu(data, size);
	mk_lib_fmt_fuzz_n_llx(data, size);
	mk_lib_fmt_fuzz_w_llx(data, size);
}
