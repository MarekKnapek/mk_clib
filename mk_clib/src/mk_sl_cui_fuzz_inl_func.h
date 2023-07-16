#include "mk_lang_assert.h"
#include "mk_lang_bool.h"
#include "mk_lang_charbit.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_likely.h"
#include "mk_lang_min.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_sizet.h"

#include <string.h> /* memcpy memcmp */


#include "mk_sl_cui_inl_defd.h"
#include "mk_sl_cui_fuzz_inl_defd.h"


#define test(x) if(!(x)) { mk_lang_unlikely mk_lang_crash(); } ((void)(0))
#define check(x) if(!(x)) return; ((void)(0))
#define check_data(x) check(d && s >= (x)); ((void)(0))
#define advance(x) { mk_lang_size_t a; a = (x); mk_lang_assert(a <= s); d += a; s -= a; } ((void)(0))


#if mk_sl_cui_inl_defd_bits <= (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mask(mk_lang_bi_ulllong_t* const bui) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits != (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	mk_lang_bi_ulllong_t mask;

	mk_lang_assert(bui);

	mk_lang_bui_ulllong_set_mask(&mask, mk_sl_cui_inl_defd_bits);
	mk_lang_bui_ulllong_and2(bui, &mask);
#else
	((void)(bui));
#endif
}

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
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
#else
	((void)(data));
	((void)(size));
#endif
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
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_set_mask(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
#else
	((void)(data));
	((void)(size));
#endif
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
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_is_max(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
#else
	((void)(data));
	((void)(size));
#endif
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
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
	mk_sl_cui_fuzz_inl_defd_mask(&buir1);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_lang_bui_ulllong_inc2(&bui, &bui);
	mk_sl_cui_inl_defd_inc2(&cui, &cui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
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
	mk_sl_cui_fuzz_inl_defd_mask(&buir1);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_lang_bui_ulllong_dec2(&bui, &bui);
	mk_sl_cui_inl_defd_dec2(&cui, &cui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_lang_bui_ulllong_inc1(&bui);
	mk_sl_cui_inl_defd_inc1(&cui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_lang_bui_ulllong_dec1(&bui);
	mk_sl_cui_inl_defd_dec1(&cui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_not2_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_not2(&cui, &cui);
	mk_lang_bui_ulllong_not2(&bui, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_not2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_not2_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_not2_alias(data, size);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui3);
	test(buir == bui3);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or3_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_or3(&cui1, &cui1, &cui2);
	mk_lang_bui_ulllong_or3(&bui1, &bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or3_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_or3(&cui1, &cui2, &cui1);
	mk_lang_bui_ulllong_or3(&bui1, &bui2, &bui1);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	test(buir == bui1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or3_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_or3(&cui1, &cui2, &cui2);
	mk_lang_bui_ulllong_or3(&bui1, &bui2, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or3_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_or3(&cui, &cui, &cui);
	mk_lang_bui_ulllong_or3(&bui, &bui, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_or3_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_or3_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_or3_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_or3_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_or3_alias_abc(data, size);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui3);
	test(buir == bui3);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and3_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_and3(&cui1, &cui1, &cui2);
	mk_lang_bui_ulllong_and3(&bui1, &bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and3_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_and3(&cui1, &cui2, &cui1);
	mk_lang_bui_ulllong_and3(&bui1, &bui2, &bui1);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	test(buir == bui1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and3_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_and3(&cui1, &cui2, &cui2);
	mk_lang_bui_ulllong_and3(&bui1, &bui2, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and3_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_and3(&cui, &cui, &cui);
	mk_lang_bui_ulllong_and3(&bui, &bui, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_and3_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_and3_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_and3_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_and3_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_and3_alias_abc(data, size);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui3);
	test(buir == bui3);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor3_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_xor3(&cui1, &cui1, &cui2);
	mk_lang_bui_ulllong_xor3(&bui1, &bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor3_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_xor3(&cui1, &cui2, &cui1);
	mk_lang_bui_ulllong_xor3(&bui1, &bui2, &bui1);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	test(buir == bui1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor3_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_xor3(&cui1, &cui2, &cui2);
	mk_lang_bui_ulllong_xor3(&bui1, &bui2, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor3_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_xor3(&cui, &cui, &cui);
	mk_lang_bui_ulllong_xor3(&bui, &bui, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_xor3_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_xor3_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_xor3_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_xor3_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_xor3_alias_abc(data, size);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_not1(&cui);
	mk_lang_bui_ulllong_not1(&bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_or2(&cui1, &cui2);
	mk_lang_bui_ulllong_or2(&bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	test(buir == bui1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or2_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_or2(&cui, &cui);
	mk_lang_bui_ulllong_or2(&bui, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_or2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_or2_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_or2_alias(data, size);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_and2(&cui1, &cui2);
	mk_lang_bui_ulllong_and2(&bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	test(buir == bui1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and2_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_and2(&cui, &cui);
	mk_lang_bui_ulllong_and2(&bui, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_and2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_and2_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_and2_alias(data, size);
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_xor2(&cui1, &cui2);
	mk_lang_bui_ulllong_xor2(&bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	test(buir == bui1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor2_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_xor2(&cui, &cui);
	mk_lang_bui_ulllong_xor2(&bui, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_xor2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_xor2_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_xor2_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shl3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	val = ((int)(((unsigned)(val_)) % ((int)(mk_sl_cui_inl_defd_bits))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_shl3(&cui1, val, &cui2);
	mk_lang_bui_ulllong_shl3(&bui1, val, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shl3_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % ((int)(mk_sl_cui_inl_defd_bits))));
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_shl3(&cui, val, &cui);
	mk_lang_bui_ulllong_shl3(&bui, val, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shl3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_shl3_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_shl3_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shr3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	val = ((int)(((unsigned)(val_)) % ((int)(mk_sl_cui_inl_defd_bits))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_shr3(&cui1, val, &cui2);
	mk_lang_bui_ulllong_shr3(&bui1, val, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shr3_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % ((int)(mk_sl_cui_inl_defd_bits))));
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_shr3(&cui, val, &cui);
	mk_lang_bui_ulllong_shr3(&bui, val, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shr3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_shr3_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_shr3_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotl3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotl3_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % (mk_sl_cui_inl_defd_bits - 1))) + 1;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_rotl3(&cui, val, &cui);
	mk_lang_bui_ulllong_rotl3(&bui, val, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotl3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_rotl3_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_rotl3_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotr3_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotr3_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % (mk_sl_cui_inl_defd_bits - 1))) + 1;
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_rotr3(&cui, val, &cui);
	mk_lang_bui_ulllong_rotr3(&bui, val, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotr3(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_rotr3_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_rotr3_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shl2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % ((int)(mk_sl_cui_inl_defd_bits))));
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_shl2(&cui, val);
	mk_lang_bui_ulllong_shl2(&bui, val);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_shr2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % ((int)(mk_sl_cui_inl_defd_bits))));
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_shr2(&cui, val);
	mk_lang_bui_ulllong_shr2(&bui, val);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotl2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % (mk_sl_cui_inl_defd_bits - 1))) + 1;
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_rotl2(&cui, val);
	mk_lang_bui_ulllong_rotl2(&bui, val);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_rotr2(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char val_;
	int val;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(val_));
	memcpy(&val_, d, sizeof(val_));
	advance(sizeof(val_));
	val = ((int)(((unsigned)(val_)) % (mk_sl_cui_inl_defd_bits - 1))) + 1;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_rotr2(&cui, val);
	mk_lang_bui_ulllong_rotr2(&bui, val);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_add_cc_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	test(mk_sl_cui_inl_defd_would_overflow_add_cc(&cui1, &cui2) == mk_lang_bui_ulllong_would_overflow_add_cc(&bui1, &bui2));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_add_cc_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	test(mk_sl_cui_inl_defd_would_overflow_add_cc(&cui, &cui) == mk_lang_bui_ulllong_would_overflow_add_cc(&bui, &bui));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_add_cc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_would_overflow_add_cc_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_add_cc_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_add_cs_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	test(mk_sl_cui_inl_defd_would_overflow_add_cs(&cui1, &cui2) == mk_lang_bui_ulllong_would_overflow_add_cs(&bui1, &bui2));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_add_cs_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	test(mk_sl_cui_inl_defd_would_overflow_add_cs(&cui, &cui) == mk_lang_bui_ulllong_would_overflow_add_cs(&bui, &bui));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_add_cs(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_would_overflow_add_cs_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_add_cs_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_add_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char b_;
	mk_lang_bool_t b;

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
	check_data(sizeof(b_));
	memcpy(&b_, d, sizeof(b_));
	advance(sizeof(b_));
	b = b_ & 1u;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	test(mk_sl_cui_inl_defd_would_overflow_add(&cui1, &cui2, b) == mk_lang_bui_ulllong_would_overflow_add(&bui1, &bui2, b));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_add_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char b_;
	mk_lang_bool_t b;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(b_));
	memcpy(&b_, d, sizeof(b_));
	advance(sizeof(b_));
	b = b_ & 1u;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	test(mk_sl_cui_inl_defd_would_overflow_add(&cui, &cui, b) == mk_lang_bui_ulllong_would_overflow_add(&bui, &bui, b));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_add(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_would_overflow_add_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_add_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cc_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	test(mk_sl_cui_inl_defd_would_overflow_sub_cc(&cui1, &cui2) == mk_lang_bui_ulllong_would_overflow_sub_cc(&bui1, &bui2));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cc_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	test(mk_sl_cui_inl_defd_would_overflow_sub_cc(&cui, &cui) == mk_lang_bui_ulllong_would_overflow_sub_cc(&bui, &bui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cc_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cc_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cs_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	test(mk_sl_cui_inl_defd_would_overflow_sub_cs(&cui1, &cui2) == mk_lang_bui_ulllong_would_overflow_sub_cs(&bui1, &bui2));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cs_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	test(mk_sl_cui_inl_defd_would_overflow_sub_cs(&cui, &cui) == mk_lang_bui_ulllong_would_overflow_sub_cs(&bui, &bui));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cs(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cs_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cs_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_sub_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char b_;
	mk_lang_bool_t b;

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
	check_data(sizeof(b_));
	memcpy(&b_, d, sizeof(b_));
	advance(sizeof(b_));
	b = b_ & 1u;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	test(mk_sl_cui_inl_defd_would_overflow_sub(&cui1, &cui2, b) == mk_lang_bui_ulllong_would_overflow_sub(&bui1, &bui2, b));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_sub_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char b_;
	mk_lang_bool_t b;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(b_));
	memcpy(&b_, d, sizeof(b_));
	advance(sizeof(b_));
	b = b_ & 1u;
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	test(mk_sl_cui_inl_defd_would_overflow_sub(&cui, &cui, b) == mk_lang_bui_ulllong_would_overflow_sub(&bui, &bui, b));
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_sub(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_would_overflow_sub_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_sub_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_mul_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	test(mk_sl_cui_inl_defd_would_overflow_mul(&cui1, &cui2) == mk_lang_bui_ulllong_would_overflow_mul(&bui1, &bui2));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_mul_alias(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	test(mk_sl_cui_inl_defd_would_overflow_mul(&cui, &cui) == mk_lang_bui_ulllong_would_overflow_mul(&bui, &bui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_would_overflow_mul(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_would_overflow_mul_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_mul_alias(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	mk_sl_cui_inl_defd_add3_wrap_cid_cod(&cui1, &cui2, &cui3);
	mk_lang_bui_ulllong_add3_wrap_cid_cod(&bui1, &bui2, &bui3);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui3);
	test(buir == bui3);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_add3_wrap_cid_cod(&cui1, &cui1, &cui2);
	mk_lang_bui_ulllong_add3_wrap_cid_cod(&bui1, &bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_add3_wrap_cid_cod(&cui1, &cui2, &cui1);
	mk_lang_bui_ulllong_add3_wrap_cid_cod(&bui1, &bui2, &bui1);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	test(buir == bui1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_add3_wrap_cid_cod(&cui1, &cui2, &cui2);
	mk_lang_bui_ulllong_add3_wrap_cid_cod(&bui1, &bui2, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_add3_wrap_cid_cod(&cui, &cui, &cui);
	mk_lang_bui_ulllong_add3_wrap_cid_cod(&bui, &bui, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod_alias_abc(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bool_t cuicf;
	mk_lang_bi_ulllong_t bui3;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_add3_wrap_cid_coe(&cui1, &cui2, &cui3, &cuicf);
	mk_lang_bui_ulllong_add3_wrap_cid_coe(&bui1, &bui2, &bui3, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	test(buir == bui3 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_add3_wrap_cid_coe(&cui1, &cui1, &cui2, &cuicf);
	mk_lang_bui_ulllong_add3_wrap_cid_coe(&bui1, &bui1, &bui2, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_add3_wrap_cid_coe(&cui1, &cui2, &cui1, &cuicf);
	mk_lang_bui_ulllong_add3_wrap_cid_coe(&bui1, &bui2, &bui1, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	test(buir == bui1 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_add3_wrap_cid_coe(&cui1, &cui2, &cui2, &cuicf);
	mk_lang_bui_ulllong_add3_wrap_cid_coe(&bui1, &bui2, &bui2, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_add3_wrap_cid_coe(&cui, &cui, &cui, &cuicf);
	mk_lang_bui_ulllong_add3_wrap_cid_coe(&bui, &bui, &bui, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe_alias_abc(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	mk_sl_cui_inl_defd_add3_wrap_cie_cod(&cui1, &cui2, cf, &cui3);
	mk_lang_bui_ulllong_add3_wrap_cie_cod(&bui1, &bui2, cf, &bui3);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	test(buir == bui3);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_add3_wrap_cie_cod(&cui1, &cui1, cf, &cui2);
	mk_lang_bui_ulllong_add3_wrap_cie_cod(&bui1, &bui1, cf, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_add3_wrap_cie_cod(&cui1, &cui2, cf, &cui1);
	mk_lang_bui_ulllong_add3_wrap_cie_cod(&bui1, &bui2, cf, &bui1);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	test(buir == bui1);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_add3_wrap_cie_cod(&cui1, &cui2, cf, &cui2);
	mk_lang_bui_ulllong_add3_wrap_cie_cod(&bui1, &bui2, cf, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_add3_wrap_cie_cod(&cui, &cui, cf, &cui);
	mk_lang_bui_ulllong_add3_wrap_cie_cod(&bui, &bui, cf, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod_alias_abc(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bool_t cuicf;
	mk_lang_bi_ulllong_t bui3;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_add3_wrap_cie_coe(&cui1, &cui2, cf, &cui3, &cuicf);
	mk_lang_bui_ulllong_add3_wrap_cie_coe(&bui1, &bui2, cf, &bui3, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	test(buir == bui3 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_add3_wrap_cie_coe(&cui1, &cui1, cf, &cui2, &cuicf);
	mk_lang_bui_ulllong_add3_wrap_cie_coe(&bui1, &bui1, cf, &bui2, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_add3_wrap_cie_coe(&cui1, &cui2, cf, &cui1, &cuicf);
	mk_lang_bui_ulllong_add3_wrap_cie_coe(&bui1, &bui2, cf, &bui1, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	test(buir == bui1 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_add3_wrap_cie_coe(&cui1, &cui2, cf, &cui2, &cuicf);
	mk_lang_bui_ulllong_add3_wrap_cie_coe(&bui1, &bui2, cf, &bui2, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_add3_wrap_cie_coe(&cui, &cui, cf, &cui, &cuicf);
	mk_lang_bui_ulllong_add3_wrap_cie_coe(&bui, &bui, cf, &bui, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe_alias_abc(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	mk_sl_cui_inl_defd_sub3_wrap_cid_cod(&cui1, &cui2, &cui3);
	mk_lang_bui_ulllong_sub3_wrap_cid_cod(&bui1, &bui2, &bui3);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui3);
	test(buir == bui3);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_sub3_wrap_cid_cod(&cui1, &cui1, &cui2);
	mk_lang_bui_ulllong_sub3_wrap_cid_cod(&bui1, &bui1, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_sub3_wrap_cid_cod(&cui1, &cui2, &cui1);
	mk_lang_bui_ulllong_sub3_wrap_cid_cod(&bui1, &bui2, &bui1);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	test(buir == bui1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_sub3_wrap_cid_cod(&cui1, &cui2, &cui2);
	mk_lang_bui_ulllong_sub3_wrap_cid_cod(&bui1, &bui2, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_sub3_wrap_cid_cod(&cui, &cui, &cui);
	mk_lang_bui_ulllong_sub3_wrap_cid_cod(&bui, &bui, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod_alias_abc(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bool_t cuicf;
	mk_lang_bi_ulllong_t bui3;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_sub3_wrap_cid_coe(&cui1, &cui2, &cui3, &cuicf);
	mk_lang_bui_ulllong_sub3_wrap_cid_coe(&bui1, &bui2, &bui3, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	test(buir == bui3 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_sub3_wrap_cid_coe(&cui1, &cui1, &cui2, &cuicf);
	mk_lang_bui_ulllong_sub3_wrap_cid_coe(&bui1, &bui1, &bui2, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_sub3_wrap_cid_coe(&cui1, &cui2, &cui1, &cuicf);
	mk_lang_bui_ulllong_sub3_wrap_cid_coe(&bui1, &bui2, &bui1, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	test(buir == bui1 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_sub3_wrap_cid_coe(&cui1, &cui2, &cui2, &cuicf);
	mk_lang_bui_ulllong_sub3_wrap_cid_coe(&bui1, &bui2, &bui2, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_sub3_wrap_cid_coe(&cui, &cui, &cui, &cuicf);
	mk_lang_bui_ulllong_sub3_wrap_cid_coe(&bui, &bui, &bui, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe_alias_abc(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	mk_sl_cui_inl_defd_sub3_wrap_cie_cod(&cui1, &cui2, cf, &cui3);
	mk_lang_bui_ulllong_sub3_wrap_cie_cod(&bui1, &bui2, cf, &bui3);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	test(buir == bui3);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_sub3_wrap_cie_cod(&cui1, &cui1, cf, &cui2);
	mk_lang_bui_ulllong_sub3_wrap_cie_cod(&bui1, &bui1, cf, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_sub3_wrap_cie_cod(&cui1, &cui2, cf, &cui1);
	mk_lang_bui_ulllong_sub3_wrap_cie_cod(&bui1, &bui2, cf, &bui1);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	test(buir == bui1);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_sub3_wrap_cie_cod(&cui1, &cui2, cf, &cui2);
	mk_lang_bui_ulllong_sub3_wrap_cie_cod(&bui1, &bui2, cf, &bui2);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_sub3_wrap_cie_cod(&cui, &cui, cf, &cui);
	mk_lang_bui_ulllong_sub3_wrap_cie_cod(&bui, &bui, cf, &bui);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod_alias_abc(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bool_t cuicf;
	mk_lang_bi_ulllong_t bui3;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_sub3_wrap_cie_coe(&cui1, &cui2, cf, &cui3, &cuicf);
	mk_lang_bui_ulllong_sub3_wrap_cie_coe(&bui1, &bui2, cf, &bui3, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	test(buir == bui3 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_sub3_wrap_cie_coe(&cui1, &cui1, cf, &cui2, &cuicf);
	mk_lang_bui_ulllong_sub3_wrap_cie_coe(&bui1, &bui1, cf, &bui2, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_sub3_wrap_cie_coe(&cui1, &cui2, cf, &cui1, &cuicf);
	mk_lang_bui_ulllong_sub3_wrap_cie_coe(&bui1, &bui2, cf, &bui1, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	test(buir == bui1 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
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
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_sub3_wrap_cie_coe(&cui1, &cui2, cf, &cui2, &cuicf);
	mk_lang_bui_ulllong_sub3_wrap_cie_coe(&bui1, &bui2, cf, &bui2, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2 && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	mk_lang_bi_ulllong_t bui;
	unsigned char cf_;
	mk_lang_bool_t cf;
	mk_lang_bool_t cuicf;
	mk_lang_bool_t buicf;
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(sizeof(bui));
	memcpy(&bui, d, sizeof(bui));
	advance(sizeof(bui));
	check_data(sizeof(cf_));
	memcpy(&cf_, d, sizeof(cf_));
	advance(sizeof(cf_));
	cf = ((mk_lang_bool_t)(((unsigned)(cf_)) & ((unsigned)(1u))));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	check_data(sizeof(cuicf));
	memcpy(&cuicf, d, sizeof(cuicf));
	advance(sizeof(cuicf));
	check_data(sizeof(buicf));
	memcpy(&buicf, d, sizeof(buicf));
	advance(sizeof(buicf));
	mk_sl_cui_inl_defd_sub3_wrap_cie_coe(&cui, &cui, cf, &cui, &cuicf);
	mk_lang_bui_ulllong_sub3_wrap_cie_coe(&bui, &bui, cf, &bui, &buicf);
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui && cuicf == buicf);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe_alias_abc(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
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
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_mul3_wrap_lo(&cui1, &cui2, &cui3);
	mk_lang_bui_ulllong_mul3_wrap_lo(&bui1, &bui2, &bui3);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui3);
	test(buir == bui3);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_mul3_wrap_lo(&cui1, &cui1, &cui2);
	mk_lang_bui_ulllong_mul3_wrap_lo(&bui1, &bui1, &bui2);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_mul3_wrap_lo(&cui1, &cui2, &cui1);
	mk_lang_bui_ulllong_mul3_wrap_lo(&bui1, &bui2, &bui1);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	test(buir == bui1);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_mask(&bui1);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_mul3_wrap_lo(&cui1, &cui2, &cui2);
	mk_lang_bui_ulllong_mul3_wrap_lo(&bui1, &bui2, &bui2);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui2);
	test(buir == bui2);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
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
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_mul3_wrap_lo(&cui, &cui, &cui);
	mk_lang_bui_ulllong_mul3_wrap_lo(&bui, &bui, &bui);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	mk_sl_cui_fuzz_inl_defd_mask(&bui);
	test(buir == bui);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo_alias_abc(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi_restrict(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bi_ulllong_t bui1;
	mk_lang_bi_ulllong_t bui2;
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
	check_data(sizeof(cui3));
	memcpy(&cui3, d, sizeof(cui3));
	advance(sizeof(cui3));
	check_data(sizeof(bui1));
	memcpy(&bui1, d, sizeof(bui1));
	advance(sizeof(bui1));
	check_data(sizeof(bui2));
	memcpy(&bui2, d, sizeof(bui2));
	advance(sizeof(bui2));
	check_data(sizeof(bui3));
	memcpy(&bui3, d, sizeof(bui3));
	advance(sizeof(bui3));
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_mul3_wrap_hi(&cui1, &cui2, &cui3);
	mk_lang_bui_ulllong_mul3_wrap_hi(&bui1, &bui2, &bui3);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir);
	test(buir == bui3);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi_alias_ab(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_mul3_wrap_hi(&cui1, &cui1, &cui2);
	mk_lang_bui_ulllong_mul3_wrap_hi(&bui1, &bui1, &bui2);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi_alias_ac(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_mul3_wrap_hi(&cui1, &cui2, &cui1);
	mk_lang_bui_ulllong_mul3_wrap_hi(&bui1, &bui2, &bui1);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui1, &buir);
	test(buir == bui1);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi_alias_bc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui1, &bui1);
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui2, &bui2);
	mk_sl_cui_inl_defd_mul3_wrap_hi(&cui1, &cui2, &cui2);
	mk_lang_bui_ulllong_mul3_wrap_hi(&bui1, &bui2, &bui2);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui2, &buir);
	test(buir == bui2);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi_alias_abc(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	check_data(sizeof(buir));
	memcpy(&buir, d, sizeof(buir));
	advance(sizeof(buir));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui, &bui);
	mk_sl_cui_inl_defd_mul3_wrap_hi(&cui, &cui, &cui);
	mk_lang_bui_ulllong_mul3_wrap_hi(&bui, &bui, &bui);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui, &buir);
	test(buir == bui);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi_restrict(data, size);
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi_alias_ab(data, size);
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi_alias_ac(data, size);
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi_alias_bc(data, size);
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi_alias_abc(data, size);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul4_wrap_wi(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	int i;
	unsigned char val;
	mk_lang_bi_ulllong_t* b[3];
	mk_sl_cui_inl_defd_t* c[3];
	mk_lang_bi_ulllong_t bui[3];
	mk_sl_cui_inl_defd_t cui[3];
	mk_lang_bi_ulllong_t bui3;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bi_ulllong_t buir1;
	mk_lang_bi_ulllong_t buir2;

	d = data;
	s = size;
	for(i = 0; i != 3; ++i)
	{
		check_data(sizeof(val)); memcpy(&val, d, sizeof(val)); advance(sizeof(val));
		b[i] = &bui[val % 3];
		c[i] = &cui[val % 3];
		check_data(sizeof(*b[i])); memcpy(b[i], d, sizeof(*b[i])); advance(sizeof(*b[i]));
		check_data(sizeof(*c[i])); memcpy(c[i], d, sizeof(*c[i])); advance(sizeof(*c[i]));
		mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(c[i], b[i]);
	}
	check_data(sizeof(bui3)); memcpy(&bui3, d, sizeof(bui3)); advance(sizeof(bui3));
	check_data(sizeof(cui3)); memcpy(&cui3, d, sizeof(cui3)); advance(sizeof(cui3));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui3, &bui3);
	check_data(sizeof(buir1)); memcpy(&buir1, d, sizeof(buir1)); advance(sizeof(buir1));
	check_data(sizeof(buir2)); memcpy(&buir2, d, sizeof(buir2)); advance(sizeof(buir2));
	mk_lang_bui_ulllong_mul4_wrap_wi(b[0], b[1], b[2], &bui3);
	mk_sl_cui_inl_defd_mul4_wrap_wi(c[0], c[1], c[2], &cui3);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(c[2], &buir1);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir2);
	test(buir1 == *b[2]);
	test(buir2 == bui3);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul2_wrap_lo(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	int i;
	unsigned char val;
	mk_lang_bi_ulllong_t* b[2];
	mk_sl_cui_inl_defd_t* c[2];
	mk_lang_bi_ulllong_t bui[2];
	mk_sl_cui_inl_defd_t cui[2];
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	for(i = 0; i != 2; ++i)
	{
		check_data(sizeof(val)); memcpy(&val, d, sizeof(val)); advance(sizeof(val));
		b[i] = &bui[val % 2];
		c[i] = &cui[val % 2];
		check_data(sizeof(*b[i])); memcpy(b[i], d, sizeof(*b[i])); advance(sizeof(*b[i]));
		check_data(sizeof(*c[i])); memcpy(c[i], d, sizeof(*c[i])); advance(sizeof(*c[i]));
		mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(c[i], b[i]);
	}
	check_data(sizeof(buir)); memcpy(&buir, d, sizeof(buir)); advance(sizeof(buir));
	mk_lang_bui_ulllong_mul2_wrap_lo(b[0], b[1]);
	mk_sl_cui_inl_defd_mul2_wrap_lo(c[0], c[1]);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(c[0], &buir);
	test(buir == *b[0]);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul2_wrap_hi(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	int i;
	unsigned char val;
	mk_lang_bi_ulllong_t* b[2];
	mk_sl_cui_inl_defd_t* c[2];
	mk_lang_bi_ulllong_t bui[2];
	mk_sl_cui_inl_defd_t cui[2];
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	for(i = 0; i != 2; ++i)
	{
		check_data(sizeof(val)); memcpy(&val, d, sizeof(val)); advance(sizeof(val));
		b[i] = &bui[val % 2];
		c[i] = &cui[val % 2];
		check_data(sizeof(*b[i])); memcpy(b[i], d, sizeof(*b[i])); advance(sizeof(*b[i]));
		check_data(sizeof(*c[i])); memcpy(c[i], d, sizeof(*c[i])); advance(sizeof(*c[i]));
		mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(c[i], b[i]);
	}
	check_data(sizeof(buir)); memcpy(&buir, d, sizeof(buir)); advance(sizeof(buir));
	mk_lang_bui_ulllong_mul2_wrap_hi(b[0], b[1]);
	mk_sl_cui_inl_defd_mul2_wrap_hi(c[0], c[1]);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(c[0], &buir);
	test(buir == *b[0]);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mul2_wrap_wi(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	int i;
	mk_lang_bi_ulllong_t bui[2];
	mk_sl_cui_inl_defd_t cui[2];
	mk_lang_bi_ulllong_t buir1;
	mk_lang_bi_ulllong_t buir2;

	d = data;
	s = size;
	for(i = 0; i != 2; ++i)
	{
		check_data(sizeof(bui[i])); memcpy(&bui[i], d, sizeof(bui[i])); advance(sizeof(bui[i]));
		check_data(sizeof(cui[i])); memcpy(&cui[i], d, sizeof(cui[i])); advance(sizeof(cui[i]));
		mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui[i], &bui[i]);
	}
	check_data(sizeof(buir1)); memcpy(&buir1, d, sizeof(buir1)); advance(sizeof(buir1));
	check_data(sizeof(buir2)); memcpy(&buir2, d, sizeof(buir2)); advance(sizeof(buir2));
	mk_lang_bui_ulllong_mul2_wrap_wi(&bui[0], &bui[1]);
	mk_sl_cui_inl_defd_mul2_wrap_wi(&cui[0], &cui[1]);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui[0], &buir1);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui[1], &buir2);
	test(buir1 == bui[0]);
	test(buir2 == bui[1]);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_div3_wrap(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	int i;
	unsigned char val;
	mk_lang_bi_ulllong_t* b[3];
	mk_sl_cui_inl_defd_t* c[3];
	mk_lang_bi_ulllong_t bui[3];
	mk_sl_cui_inl_defd_t cui[3];
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	for(i = 0; i != 3; ++i)
	{
		check_data(sizeof(val)); memcpy(&val, d, sizeof(val)); advance(sizeof(val));
		b[i] = &bui[val % 3];
		c[i] = &cui[val % 3];
		check_data(sizeof(*b[i])); memcpy(b[i], d, sizeof(*b[i])); advance(sizeof(*b[i]));
		check_data(sizeof(*c[i])); memcpy(c[i], d, sizeof(*c[i])); advance(sizeof(*c[i]));
		mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(c[i], b[i]);
	}
	check_data(sizeof(buir)); memcpy(&buir, d, sizeof(buir)); advance(sizeof(buir));
	if(mk_lang_bui_ulllong_is_zero(b[1])) return;
	mk_lang_bui_ulllong_div3_wrap(b[0], b[1], b[2]);
	mk_sl_cui_inl_defd_div3_wrap(c[0], c[1], c[2]);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(c[2], &buir);
	test(buir == *b[2]);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mod3_wrap(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	int i;
	unsigned char val;
	mk_lang_bi_ulllong_t* b[3];
	mk_sl_cui_inl_defd_t* c[3];
	mk_lang_bi_ulllong_t bui[3];
	mk_sl_cui_inl_defd_t cui[3];
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	for(i = 0; i != 3; ++i)
	{
		check_data(sizeof(val)); memcpy(&val, d, sizeof(val)); advance(sizeof(val));
		b[i] = &bui[val % 3];
		c[i] = &cui[val % 3];
		check_data(sizeof(*b[i])); memcpy(b[i], d, sizeof(*b[i])); advance(sizeof(*b[i]));
		check_data(sizeof(*c[i])); memcpy(c[i], d, sizeof(*c[i])); advance(sizeof(*c[i]));
		mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(c[i], b[i]);
	}
	check_data(sizeof(buir)); memcpy(&buir, d, sizeof(buir)); advance(sizeof(buir));
	if(mk_lang_bui_ulllong_is_zero(b[1])) return;
	mk_lang_bui_ulllong_mod3_wrap(b[0], b[1], b[2]);
	mk_sl_cui_inl_defd_mod3_wrap(c[0], c[1], c[2]);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(c[2], &buir);
	test(buir == *b[2]);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_divmod4_wrap(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	int i;
	unsigned char val;
	mk_lang_bi_ulllong_t* b[3];
	mk_sl_cui_inl_defd_t* c[3];
	mk_lang_bi_ulllong_t bui[3];
	mk_sl_cui_inl_defd_t cui[3];
	mk_lang_bi_ulllong_t bui3;
	mk_sl_cui_inl_defd_t cui3;
	mk_lang_bi_ulllong_t buir1;
	mk_lang_bi_ulllong_t buir2;

	d = data;
	s = size;
	for(i = 0; i != 3; ++i)
	{
		check_data(sizeof(val)); memcpy(&val, d, sizeof(val)); advance(sizeof(val));
		b[i] = &bui[val % 3];
		c[i] = &cui[val % 3];
		check_data(sizeof(*b[i])); memcpy(b[i], d, sizeof(*b[i])); advance(sizeof(*b[i]));
		check_data(sizeof(*c[i])); memcpy(c[i], d, sizeof(*c[i])); advance(sizeof(*c[i]));
		mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(c[i], b[i]);
	}
	check_data(sizeof(bui3)); memcpy(&bui3, d, sizeof(bui3)); advance(sizeof(bui3));
	check_data(sizeof(cui3)); memcpy(&cui3, d, sizeof(cui3)); advance(sizeof(cui3));
	mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui3, &bui3);
	check_data(sizeof(buir1)); memcpy(&buir1, d, sizeof(buir1)); advance(sizeof(buir1));
	check_data(sizeof(buir2)); memcpy(&buir2, d, sizeof(buir2)); advance(sizeof(buir2));
	if(mk_lang_bui_ulllong_is_zero(b[1])) return;
	mk_lang_bui_ulllong_divmod4_wrap(b[0], b[1], b[2], &bui3);
	mk_sl_cui_inl_defd_divmod4_wrap(c[0], c[1], c[2], &cui3);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(c[2], &buir1);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui3, &buir2);
	test(buir1 == *b[2]);
	test(buir2 == bui3);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_div2_wrap(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	int i;
	unsigned char val;
	mk_lang_bi_ulllong_t* b[2];
	mk_sl_cui_inl_defd_t* c[2];
	mk_lang_bi_ulllong_t bui[2];
	mk_sl_cui_inl_defd_t cui[2];
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	for(i = 0; i != 2; ++i)
	{
		check_data(sizeof(val)); memcpy(&val, d, sizeof(val)); advance(sizeof(val));
		b[i] = &bui[val % 2];
		c[i] = &cui[val % 2];
		check_data(sizeof(*b[i])); memcpy(b[i], d, sizeof(*b[i])); advance(sizeof(*b[i]));
		check_data(sizeof(*c[i])); memcpy(c[i], d, sizeof(*c[i])); advance(sizeof(*c[i]));
		mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(c[i], b[i]);
	}
	check_data(sizeof(buir)); memcpy(&buir, d, sizeof(buir)); advance(sizeof(buir));
	if(mk_lang_bui_ulllong_is_zero(b[1])) return;
	mk_lang_bui_ulllong_div2_wrap(b[0], b[1]);
	mk_sl_cui_inl_defd_div2_wrap(c[0], c[1]);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(c[0], &buir);
	test(buir == *b[0]);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_mod2_wrap(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	int i;
	unsigned char val;
	mk_lang_bi_ulllong_t* b[2];
	mk_sl_cui_inl_defd_t* c[2];
	mk_lang_bi_ulllong_t bui[2];
	mk_sl_cui_inl_defd_t cui[2];
	mk_lang_bi_ulllong_t buir;

	d = data;
	s = size;
	for(i = 0; i != 2; ++i)
	{
		check_data(sizeof(val)); memcpy(&val, d, sizeof(val)); advance(sizeof(val));
		b[i] = &bui[val % 2];
		c[i] = &cui[val % 2];
		check_data(sizeof(*b[i])); memcpy(b[i], d, sizeof(*b[i])); advance(sizeof(*b[i]));
		check_data(sizeof(*c[i])); memcpy(c[i], d, sizeof(*c[i])); advance(sizeof(*c[i]));
		mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(c[i], b[i]);
	}
	check_data(sizeof(buir)); memcpy(&buir, d, sizeof(buir)); advance(sizeof(buir));
	if(mk_lang_bui_ulllong_is_zero(b[1])) return;
	mk_lang_bui_ulllong_mod2_wrap(b[0], b[1]);
	mk_sl_cui_inl_defd_mod2_wrap(c[0], c[1]);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(c[0], &buir);
	test(buir == *b[0]);
#else
	((void)(data));
	((void)(size));
#endif
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_divmod2_wrap(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
#if mk_sl_cui_inl_defd_bits == (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
	unsigned char const* d;
	mk_lang_size_t s;
	int i;
	mk_lang_bi_ulllong_t bui[2];
	mk_sl_cui_inl_defd_t cui[2];
	mk_lang_bi_ulllong_t buir1;
	mk_lang_bi_ulllong_t buir2;

	d = data;
	s = size;
	for(i = 0; i != 2; ++i)
	{
		check_data(sizeof(bui[i])); memcpy(&bui[i], d, sizeof(bui[i])); advance(sizeof(bui[i]));
		check_data(sizeof(cui[i])); memcpy(&cui[i], d, sizeof(cui[i])); advance(sizeof(cui[i]));
		mk_sl_cui_fuzz_inl_defd_from_bi_ulllong(&cui[i], &bui[i]);
	}
	check_data(sizeof(buir1)); memcpy(&buir1, d, sizeof(buir1)); advance(sizeof(buir1));
	check_data(sizeof(buir2)); memcpy(&buir2, d, sizeof(buir2)); advance(sizeof(buir2));
	if(mk_lang_bui_ulllong_is_zero(&bui[1])) return;
	mk_lang_bui_ulllong_divmod2_wrap(&bui[0], &bui[1]);
	mk_sl_cui_inl_defd_divmod2_wrap(&cui[0], &cui[1]);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui[0], &buir1);
	mk_sl_cui_fuzz_inl_defd_to_bi_ulllong(&cui[1], &buir2);
	test(buir1 == bui[0]);
	test(buir2 == bui[1]);
#else
	((void)(data));
	((void)(size));
#endif
}
#endif

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_tofrom_str(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui1;
	mk_sl_cui_inl_defd_t cui2;
	char buff[mk_sl_cui_inl_defd_to_str_dec_lenv];
	int n;
	int m;

	d = data;
	s = size;
	check_data(sizeof(cui1)); memcpy(&cui1, d, sizeof(cui1)); advance(sizeof(cui1));
	check_data(sizeof(cui2)); memcpy(&cui2, d, sizeof(cui2)); advance(sizeof(cui2));
	check_data(sizeof(buff)); memcpy(&buff, d, sizeof(buff)); advance(sizeof(buff));
	n = mk_sl_cui_inl_defd_to_str_dec_n(&cui1, &buff[0], ((int)(mk_sl_cui_inl_defd_to_str_dec_lenv)));
	test(n >= 1 && n <= ((int)(mk_sl_cui_inl_defd_to_str_dec_lenv)));
	m = mk_sl_cui_inl_defd_from_str_dec_n(&cui2, buff, n);
	test(m == n);
	test(mk_sl_cui_inl_defd_eq(&cui2, &cui1));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_fromto_str(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_defd_t cui;
	char buff[mk_sl_cui_inl_defd_to_str_dec_lenv];
	int n;
	int m;

	d = data;
	s = size;
	check_data(sizeof(cui)); memcpy(&cui, d, sizeof(cui)); advance(sizeof(cui));
	check_data(sizeof(buff)); memcpy(&buff, d, sizeof(buff)); advance(sizeof(buff));
	check_data(1);
	n = mk_sl_cui_inl_defd_from_str_dec_n(&cui, ((char const*)(d)), ((int)(s)));
	if(n == 0) return;
	if(n < 0)
	{
		n = -n;
	}
	m = mk_sl_cui_inl_defd_to_str_dec_n(&cui, &buff[0], mk_lang_min(((int)(mk_sl_cui_inl_defd_to_str_dec_lenv)), n));
	test(m <= n);
	test(memcmp(buff, d + (n - m), m) == 0);
}


mk_lang_jumbo void mk_sl_cui_fuzz_inl_defd_fn(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	#if mk_sl_cui_inl_defd_bits <= (mk_lang_sizeof_bi_ulllong_t * mk_lang_charbit)
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
	mk_sl_cui_fuzz_inl_defd_shl2(data, size);
	mk_sl_cui_fuzz_inl_defd_shr2(data, size);
	mk_sl_cui_fuzz_inl_defd_rotl2(data, size);
	mk_sl_cui_fuzz_inl_defd_rotr2(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_add_cc(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_add_cs(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_add(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cc(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_sub_cs(data, size);
	mk_sl_cui_fuzz_inl_defd_would_overflow_sub(data, size);
	/*mk_sl_cui_fuzz_inl_defd_would_overflow_mul(data, size);*/
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_cod(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cid_coe(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_cod(data, size);
	mk_sl_cui_fuzz_inl_defd_add3_wrap_cie_coe(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_cod(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cid_coe(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_cod(data, size);
	mk_sl_cui_fuzz_inl_defd_sub3_wrap_cie_coe(data, size);
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_lo(data, size);
	mk_sl_cui_fuzz_inl_defd_mul3_wrap_hi(data, size);
	mk_sl_cui_fuzz_inl_defd_mul4_wrap_wi(data, size);
	mk_sl_cui_fuzz_inl_defd_mul2_wrap_lo(data, size);
	mk_sl_cui_fuzz_inl_defd_mul2_wrap_hi(data, size);
	mk_sl_cui_fuzz_inl_defd_mul2_wrap_wi(data, size);
	mk_sl_cui_fuzz_inl_defd_div3_wrap(data, size);
	mk_sl_cui_fuzz_inl_defd_mod3_wrap(data, size);
	mk_sl_cui_fuzz_inl_defd_divmod4_wrap(data, size);
	mk_sl_cui_fuzz_inl_defd_div2_wrap(data, size);
	mk_sl_cui_fuzz_inl_defd_mod2_wrap(data, size);
	mk_sl_cui_fuzz_inl_defd_divmod2_wrap(data, size);
	#endif
	mk_sl_cui_fuzz_inl_defd_tofrom_str(data, size);
	mk_sl_cui_fuzz_inl_defd_fromto_str(data, size);
}


#undef test
#undef check
#undef check_data
#undef advance


#include "mk_sl_cui_fuzz_inl_defu.h"
#include "mk_sl_cui_inl_defu.h"
