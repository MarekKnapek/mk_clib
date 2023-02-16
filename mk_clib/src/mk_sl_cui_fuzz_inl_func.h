#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_sizet.h"

#include <string.h> /* memcpy */


#include "mk_sl_cui_inl_defd.h"
#include "mk_sl_cui_fuzz_inl_defd.h"
#if (mk_sl_cui_inl_defd_count * mk_sl_cui_inl_defd_base_bits) == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)


#define test(x) if(!(x)) mk_lang_unlikely mk_lang_crash(); ((void)(0))
#define check(x) if(!(x)) return; ((void)(0))
#define check_data(x) check(d && s >= (x)); ((void)(0))
#define advance(x) { mk_lang_size_t a; a = (x); mk_lang_assert(a <= s); d += a; s -= a; } ((void)(0))


mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_set_zero(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	mk_sl_cui_inl_defd_set_zero(&cui);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &bui1);
	mk_lang_bui_ulllong_set_zero(&bui2);
	test(bui1 == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_set_max(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	mk_sl_cui_inl_defd_set_max(&cui);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &bui1);
	mk_lang_bui_ulllong_set_max(&bui2);
	test(bui1 == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_set_one(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	mk_sl_cui_inl_defd_set_one(&cui);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &bui1);
	mk_lang_bui_ulllong_set_one(&bui2);
	test(bui1 == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_set_bit(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	int val;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	check_data(sizeof(val));
	memcpy(&val, d, sizeof(val));
	advance(sizeof(val));
	val = (((val < 0) ? (-val) : (val)) % (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit));
	mk_sl_cui_inl_defd_set_bit(&cui, val);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &bui1);
	mk_lang_bui_ulllong_set_bit(&bui2, val);
	test(bui1 == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_set_mask(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	int val;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	check_data(sizeof(val));
	memcpy(&val, d, sizeof(val));
	advance(sizeof(val));
	val = ((((val < 0) ? (-val) : (val)) % (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)) + 1);
	mk_sl_cui_inl_defd_set_mask(&cui, val);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &bui1);
	mk_lang_bui_ulllong_set_mask(&bui2, val);
	test(bui1 == bui2);
}

/* todo to/form bi */
/* todo to/from buis */

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_is_zero(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	test(mk_sl_cui_inl_defd_is_zero(&cui) == mk_lang_bui_ulllong_is_zero(&bui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_is_max(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	test(mk_sl_cui_inl_defd_is_max(&cui) == mk_lang_bui_ulllong_is_max(&bui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_eq(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	test(mk_sl_cui_inl_defd_eq(&cui1, &cui2) == mk_lang_bui_ulllong_eq(&bui1, &bui2));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_ne(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	test(mk_sl_cui_inl_defd_ne(&cui1, &cui2) == mk_lang_bui_ulllong_ne(&bui1, &bui2));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_lt(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	test(mk_sl_cui_inl_defd_lt(&cui1, &cui2) == mk_lang_bui_ulllong_lt(&bui1, &bui2));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_le(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	test(mk_sl_cui_inl_defd_le(&cui1, &cui2) == mk_lang_bui_ulllong_le(&bui1, &bui2));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_gt(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	test(mk_sl_cui_inl_defd_gt(&cui1, &cui2) == mk_lang_bui_ulllong_gt(&bui1, &bui2));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_ge(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	test(mk_sl_cui_inl_defd_ge(&cui1, &cui2) == mk_lang_bui_ulllong_ge(&bui1, &bui2));
}


mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_fn(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_set_zero(data, size);
	mk_sl_cui_fuzz_inl_defd_set_max(data, size);
	mk_sl_cui_fuzz_inl_defd_set_one(data, size);
	mk_sl_cui_fuzz_inl_defd_set_bit(data, size);
	mk_sl_cui_fuzz_inl_defd_set_mask(data, size);
	/*#include "mk_sl_cui_fuzz_inl_func_bi_call.h"*/
	mk_sl_cui_fuzz_inl_defd_is_zero(data, size);
	mk_sl_cui_fuzz_inl_defd_is_max(data, size);
	mk_sl_cui_fuzz_inl_defd_eq(data, size);
	mk_sl_cui_fuzz_inl_defd_ne(data, size);
	mk_sl_cui_fuzz_inl_defd_lt(data, size);
	mk_sl_cui_fuzz_inl_defd_le(data, size);
	mk_sl_cui_fuzz_inl_defd_gt(data, size);
	mk_sl_cui_fuzz_inl_defd_ge(data, size);
}


#undef test
#undef check
#undef check_data
#undef advance


#endif
#include "mk_sl_cui_fuzz_inl_defu.h"
#include "mk_sl_cui_inl_defu.h"
