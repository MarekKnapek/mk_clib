#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_sizet.h"

#include <string.h> /* memcpy memcmp */


#include "mk_sl_cui_inl_def.h"
#include "mk_sl_cui_fuzz_inl_def.h"


#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))
#define check(x) if(!(x)) return; ((void)(0))
#define check_data(x) check(d && s >= (x)); ((void)(0))
#define advance(x) { mk_lang_size_t a; a = (x); mk_lang_assert(a <= s); d += a; s -= a; } ((void)(0))


mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_set_zero(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	mk_sl_cui_inl_def_set_zero(&cui);
	test(mk_sl_cui_inl_def_is_zero(&cui));
	test(!mk_sl_cui_inl_def_is_max(&cui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_set_max(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	mk_sl_cui_inl_def_set_max(&cui);
	test(!mk_sl_cui_inl_def_is_zero(&cui));
	test(mk_sl_cui_inl_def_is_max(&cui));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_set_one(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui;
	int i;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	mk_sl_cui_inl_def_set_one(&cui);
	test(cui.m_data[mk_sl_cui_inl_def_idx(0)] == 1);
	for(i = 1; i != mk_sl_cui_inl_def_count; ++i)
	{
		test(cui.m_data[mk_sl_cui_inl_def_idx(i)] == 0);
	}
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_set_bit(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui;
	int bit_idx;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(1);
	bit_idx = *d % (mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits);
	mk_sl_cui_inl_def_set_bit(&cui, bit_idx);
	/* todo test result */
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_set_mask(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui;
	int bits_count;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	check_data(1);
	bits_count = (*d % (mk_sl_cui_inl_def_count * mk_sl_cui_inl_def_base_bits)) + 1;
	mk_sl_cui_inl_def_set_mask(&cui, bits_count);
	/* todo test result */
}

#include "mk_sl_cui_fuzz_inl_func_bi_func.h"

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_is_zero(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui;
	mk_lang_bool_t b;
	int i;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	b = mk_lang_true; for(i = 0; i != sizeof(cui); ++i) if(((unsigned char*)(&cui))[i] != 0) b = mk_lang_false;
	test(mk_sl_cui_inl_def_is_zero(&cui) == b);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_is_max(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui;
	mk_lang_bool_t b;
	int i;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	advance(sizeof(cui));
	b = mk_lang_true; for(i = 0; i != sizeof(cui); ++i) if(((unsigned char*)(&cui))[i] != 0xff) b = mk_lang_false;
	test(mk_sl_cui_inl_def_is_max(&cui) == b);
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_eq(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui1;
	mk_sl_cui_inl_def_t cui2;

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	test(mk_sl_cui_inl_def_eq(&cui1, &cui2) == (memcmp(&cui1, &cui2, sizeof(cui1)) == 0));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_ne(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui1;
	mk_sl_cui_inl_def_t cui2;

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	test(mk_sl_cui_inl_def_ne(&cui1, &cui2) == (memcmp(&cui1, &cui2, sizeof(cui1)) != 0));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_lt(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui1;
	mk_sl_cui_inl_def_t cui2;
	unsigned char buff1[sizeof(cui1)];
	unsigned char buff2[sizeof(cui2)];

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	mk_sl_cui_fuzz_inl_def_tobuffbe(&cui1, buff1);
	mk_sl_cui_fuzz_inl_def_tobuffbe(&cui2, buff2);
	test(mk_sl_cui_inl_def_lt(&cui1, &cui2) == (memcmp(&buff1, &buff2, sizeof(cui1)) < 0));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_le(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui1;
	mk_sl_cui_inl_def_t cui2;
	unsigned char buff1[sizeof(cui1)];
	unsigned char buff2[sizeof(cui2)];

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	mk_sl_cui_fuzz_inl_def_tobuffbe(&cui1, buff1);
	mk_sl_cui_fuzz_inl_def_tobuffbe(&cui2, buff2);
	test(mk_sl_cui_inl_def_le(&cui1, &cui2) == (memcmp(&buff1, &buff2, sizeof(cui1)) <= 0));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_gt(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui1;
	mk_sl_cui_inl_def_t cui2;
	unsigned char buff1[sizeof(cui1)];
	unsigned char buff2[sizeof(cui2)];

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	mk_sl_cui_fuzz_inl_def_tobuffbe(&cui1, buff1);
	mk_sl_cui_fuzz_inl_def_tobuffbe(&cui2, buff2);
	test(mk_sl_cui_inl_def_gt(&cui1, &cui2) == (memcmp(&buff1, &buff2, sizeof(cui1)) > 0));
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_ge(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui1;
	mk_sl_cui_inl_def_t cui2;
	unsigned char buff1[sizeof(cui1)];
	unsigned char buff2[sizeof(cui2)];

	d = data;
	s = size;
	check_data(sizeof(cui1));
	memcpy(&cui1, d, sizeof(cui1));
	advance(sizeof(cui1));
	check_data(sizeof(cui2));
	memcpy(&cui2, d, sizeof(cui2));
	advance(sizeof(cui2));
	mk_sl_cui_fuzz_inl_def_tobuffbe(&cui1, buff1);
	mk_sl_cui_fuzz_inl_def_tobuffbe(&cui2, buff2);
	test(mk_sl_cui_inl_def_ge(&cui1, &cui2) == (memcmp(&buff1, &buff2, sizeof(cui1)) >= 0));
}


mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_fn(unsigned char const* const data, mk_lang_size_t const size)
{
	if(!(size >= sizeof(mk_sl_cui_inl_def_t))) return;
	mk_sl_cui_fuzz_inl_def_set_zero(data, size);
	mk_sl_cui_fuzz_inl_def_set_max(data, size);
	mk_sl_cui_fuzz_inl_def_set_one(data, size);
	mk_sl_cui_fuzz_inl_def_set_bit(data, size);
	mk_sl_cui_fuzz_inl_def_set_mask(data, size);
	#include "mk_sl_cui_fuzz_inl_func_bi_call.h"
	mk_sl_cui_fuzz_inl_def_is_zero(data, size);
	mk_sl_cui_fuzz_inl_def_is_max(data, size);
	mk_sl_cui_fuzz_inl_def_eq(data, size);
	mk_sl_cui_fuzz_inl_def_ne(data, size);
	mk_sl_cui_fuzz_inl_def_lt(data, size);
	mk_sl_cui_fuzz_inl_def_le(data, size);
	mk_sl_cui_fuzz_inl_def_gt(data, size);
	mk_sl_cui_fuzz_inl_def_ge(data, size);
}


#undef test
#undef check
#undef check_data
#undef advance


#include "mk_sl_cui_fuzz_inl_undef.h"
#include "mk_sl_cui_inl_undef.h"
