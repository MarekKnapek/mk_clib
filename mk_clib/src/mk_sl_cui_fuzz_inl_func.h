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
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)


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

#define mk_lang_forb1_id mk_lang_for_constants_bi
#define mk_lang_forb_file "mk_sl_cui_fuzz_inl_tofrom_bi_inl_func.h"
#define mk_sl_cui_fuzz_inl_tofrom_bi_for_bi mk_lang_forb_bi
#include "mk_lang_forb1.h"
#undef mk_lang_forb1_id
#undef mk_lang_forb_file
#undef mk_sl_cui_fuzz_inl_tofrom_bi_for_bi

#define mk_lang_forb2_id mk_lang_for_constants_bui
#define mk_lang_forb1_id mk_lang_for_constants_endian
#define mk_lang_forb_file "mk_sl_cui_fuzz_inl_tofrom_buis_inl_func.h"
#define mk_sl_cui_fuzz_inl_tofrom_buis_for_bui mk_lang_forb_bui
#define mk_sl_cui_fuzz_inl_tofrom_buis_for_endian mk_lang_forb_endian
#include "mk_lang_forb2.h"
#undef mk_lang_forb2_id
#undef mk_lang_forb1_id
#undef mk_lang_forb_file
#undef mk_sl_cui_fuzz_inl_tofrom_buis_for_bui
#undef mk_sl_cui_fuzz_inl_tofrom_buis_for_endian

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

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_eq_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_eq_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	test(mk_sl_cui_inl_defd_eq(&cui, &cui) == mk_lang_bui_ulllong_eq(&bui, &bui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_eq(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_eq_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_eq_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_ne_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_ne_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	test(mk_sl_cui_inl_defd_ne(&cui, &cui) == mk_lang_bui_ulllong_ne(&bui, &bui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_ne(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_ne_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_ne_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_lt_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_lt_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	test(mk_sl_cui_inl_defd_lt(&cui, &cui) == mk_lang_bui_ulllong_lt(&bui, &bui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_lt(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_lt_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_lt_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_le_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_le_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	test(mk_sl_cui_inl_defd_le(&cui, &cui) == mk_lang_bui_ulllong_le(&bui, &bui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_le(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_le_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_le_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_gt_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_gt_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	test(mk_sl_cui_inl_defd_gt(&cui, &cui) == mk_lang_bui_ulllong_gt(&bui, &bui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_gt(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_gt_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_gt_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_ge_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_ge_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	test(mk_sl_cui_inl_defd_ge(&cui, &cui) == mk_lang_bui_ulllong_ge(&bui, &bui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_ge(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_ge_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_ge_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_inc2_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_bi_ulllong_t bui;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t buir1;
	mk_sl_cui_inl_defd_t cuir1;
	mk_lang_bi_ulllong_t buir2;

	d = data;
	s = size;
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	check_data(sizeof(buir1));
	memcpy(&buir1, d, sizeof(buir1));
	advance(sizeof(buir1));
	mk_lang_bui_ulllong_inc2(&bui, &buir1);
	check_data(sizeof(cuir1));
	memcpy(&cuir1, d, sizeof(cuir1));
	advance(sizeof(cuir1));
	mk_sl_cui_inl_defd_inc2(&cui, &cuir1);
	check_data(sizeof(buir2));
	memcpy(&buir2, d, sizeof(buir2));
	advance(sizeof(buir2));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cuir1, &buir2);
	test(buir2 == buir1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_inc2_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_bi_ulllong_t bui;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_lang_bui_ulllong_inc2(&bui, &bui);
	mk_sl_cui_inl_defd_inc2(&cui, &cui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_inc2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_inc2_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_inc2_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_dec2_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_bi_ulllong_t bui;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t buir1;
	mk_sl_cui_inl_defd_t cuir1;
	mk_lang_bi_ulllong_t buir2;

	d = data;
	s = size;
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	check_data(sizeof(buir1));
	memcpy(&buir1, d, sizeof(buir1));
	advance(sizeof(buir1));
	mk_lang_bui_ulllong_dec2(&bui, &buir1);
	check_data(sizeof(cuir1));
	memcpy(&cuir1, d, sizeof(cuir1));
	advance(sizeof(cuir1));
	mk_sl_cui_inl_defd_dec2(&cui, &cuir1);
	check_data(sizeof(buir2));
	memcpy(&buir2, d, sizeof(buir2));
	advance(sizeof(buir2));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cuir1, &buir2);
	test(buir2 == buir1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_dec2_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_bi_ulllong_t bui;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_lang_bui_ulllong_dec2(&bui, &bui);
	mk_sl_cui_inl_defd_dec2(&cui, &cui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_dec2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_dec2_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_dec2_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_inc1(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_bi_ulllong_t bui;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_lang_bui_ulllong_inc1(&bui);
	mk_sl_cui_inl_defd_inc1(&cui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_dec1(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_bi_ulllong_t bui;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_lang_bui_ulllong_dec1(&bui);
	mk_sl_cui_inl_defd_dec1(&cui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_not2_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_lang_bi_ulllong_t bui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui2;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	mk_sl_cui_inl_defd_not2(&cui1, &cui2);
	mk_lang_bui_ulllong_not2(&bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_not2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_not2_restrict(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bi_ulllong_t bui3;
	mk_lang_bi_ulllong_t buir;

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
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	mk_sl_cui_inl_defd_or3(&cui1, &cui2, &cui3);
	mk_lang_bui_ulllong_or3(&bui1, &bui2, &bui3);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	test(buir == bui3);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_or3_restrict(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bi_ulllong_t bui3;
	mk_lang_bi_ulllong_t buir;

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
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	mk_sl_cui_inl_defd_and3(&cui1, &cui2, &cui3);
	mk_lang_bui_ulllong_and3(&bui1, &bui2, &bui3);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	test(buir == bui3);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_and3_restrict(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bi_ulllong_t bui3;
	mk_lang_bi_ulllong_t buir;

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
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	mk_sl_cui_inl_defd_xor3(&cui1, &cui2, &cui3);
	mk_lang_bui_ulllong_xor3(&bui1, &bui2, &bui3);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	test(buir == bui3);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_xor3_restrict(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_not1(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_not1(&cui);
	mk_lang_bui_ulllong_not1(&bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or2_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_lang_bi_ulllong_t buir;

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
	mk_sl_cui_inl_defd_or2(&cui1, &cui2);
	mk_lang_bui_ulllong_or2(&bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_or2_restrict(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and2_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_lang_bi_ulllong_t buir;

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
	mk_sl_cui_inl_defd_and2(&cui1, &cui2);
	mk_lang_bui_ulllong_and2(&bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_and2_restrict(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor2_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_lang_bi_ulllong_t buir;

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
	mk_sl_cui_inl_defd_xor2(&cui1, &cui2);
	mk_lang_bui_ulllong_xor2(&bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_xor2_restrict(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shl3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

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
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % mk_sl_cui_inl_defd_bits));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_shl3(&cui1, val, &cui2);
	mk_lang_bui_ulllong_shl3(&bui1, val, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shl3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_shl3_restrict(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shr3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

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
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % mk_sl_cui_inl_defd_bits));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_shr3(&cui1, val, &cui2);
	mk_lang_bui_ulllong_shr3(&bui1, val, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shr3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_shr3_restrict(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotl3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

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
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % (mk_sl_cui_inl_defd_bits - 1))) + 1;
	if(val % mk_sl_cui_inl_defd_base_bits != 0) return;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_rotl3(&cui1, val, &cui2);
	mk_lang_bui_ulllong_rotl3(&bui1, val, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotl3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_rotl3_restrict(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotr3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

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
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % (mk_sl_cui_inl_defd_bits - 1))) + 1;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_rotr3(&cui1, val, &cui2);
	mk_lang_bui_ulllong_rotr3(&bui1, val, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotr3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

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
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % (mk_sl_cui_inl_defd_bits - 1))) + 1;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_rotl3(&cui1, val, &cui2);
	mk_lang_bui_ulllong_rotl3(&bui1, val, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotl3_v2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

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
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % (mk_sl_cui_inl_defd_bits - 1))) + 1;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_rotl3_v2(&cui1, val, &cui2);
	mk_lang_bui_ulllong_rotl3(&bui1, val, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotr3_v2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

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
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % (mk_sl_cui_inl_defd_bits - 1))) + 1;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_rotr3_v2(&cui1, val, &cui2);
	mk_lang_bui_ulllong_rotr3(&bui1, val, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
}


mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_fn(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_set_zero(data, size);
	mk_sl_cui_fuzz_inl_defd_set_max(data, size);
	mk_sl_cui_fuzz_inl_defd_set_one(data, size);
	mk_sl_cui_fuzz_inl_defd_set_bit(data, size);
	mk_sl_cui_fuzz_inl_defd_set_mask(data, size);
	#define mk_lang_forb1_id mk_lang_for_constants_bi
	#define mk_lang_forb_file "mk_sl_cui_fuzz_inl_tofrom_bi_inl_call.h"
	#define mk_sl_cui_fuzz_inl_tofrom_bi_for_bi mk_lang_forb_bi
	#include "mk_lang_forb1.h"
	#undef mk_lang_forb1_id
	#undef mk_lang_forb_file
	#undef mk_sl_cui_fuzz_inl_tofrom_bi_for_bi
	#define mk_lang_forb2_id mk_lang_for_constants_bui
	#define mk_lang_forb1_id mk_lang_for_constants_endian
	#define mk_lang_forb_file "mk_sl_cui_fuzz_inl_tofrom_buis_inl_call.h"
	#define mk_sl_cui_fuzz_inl_tofrom_buis_for_bui mk_lang_forb_bui
	#define mk_sl_cui_fuzz_inl_tofrom_buis_for_endian mk_lang_forb_endian
	#include "mk_lang_forb2.h"
	#undef mk_lang_forb2_id
	#undef mk_lang_forb1_id
	#undef mk_lang_forb_file
	#undef mk_sl_cui_fuzz_inl_tofrom_buis_for_bui
	#undef mk_sl_cui_fuzz_inl_tofrom_buis_for_endian
	mk_sl_cui_fuzz_inl_defd_is_zero(data, size);
	mk_sl_cui_fuzz_inl_defd_is_max(data, size);
	mk_sl_cui_fuzz_inl_defd_eq(data, size);
	mk_sl_cui_fuzz_inl_defd_ne(data, size);
	mk_sl_cui_fuzz_inl_defd_lt(data, size);
	mk_sl_cui_fuzz_inl_defd_le(data, size);
	mk_sl_cui_fuzz_inl_defd_gt(data, size);
	mk_sl_cui_fuzz_inl_defd_ge(data, size);
	mk_sl_cui_fuzz_inl_defd_inc2(data, size);
	mk_sl_cui_fuzz_inl_defd_dec2(data, size);
	mk_sl_cui_fuzz_inl_defd_inc1(data, size);
	mk_sl_cui_fuzz_inl_defd_dec1(data, size);
	mk_sl_cui_fuzz_inl_defd_not2(data, size);
	mk_sl_cui_fuzz_inl_defd_or3(data, size);
	mk_sl_cui_fuzz_inl_defd_and3(data, size);
	mk_sl_cui_fuzz_inl_defd_xor3(data, size);
	mk_sl_cui_fuzz_inl_defd_not1(data, size);
	mk_sl_cui_fuzz_inl_defd_or2(data, size);
	mk_sl_cui_fuzz_inl_defd_and2(data, size);
	mk_sl_cui_fuzz_inl_defd_xor2(data, size);
	mk_sl_cui_fuzz_inl_defd_shl3(data, size);
	mk_sl_cui_fuzz_inl_defd_shr3(data, size);
	mk_sl_cui_fuzz_inl_defd_rotl3(data, size);
	mk_sl_cui_fuzz_inl_defd_rotr3(data, size);
	mk_sl_cui_fuzz_inl_defd_rotl3_v2(data, size);
	mk_sl_cui_fuzz_inl_defd_rotr3_v2(data, size);
}


#undef test
#undef check
#undef check_data
#undef advance


#endif
#include "mk_sl_cui_fuzz_inl_defu.h"
#include "mk_sl_cui_inl_defu.h"
