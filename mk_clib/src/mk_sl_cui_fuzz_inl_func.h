#include "mk_lang_assert.h"
#include "mk_lang_charbit.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_sizet.h"

#include <string.h> /* memcpy */


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
	int i;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	mk_sl_cui_inl_def_set_zero(&cui);
	for(i = 0; i != sizeof(cui); ++i)
	{
		test(((unsigned char*)(&cui))[i] == 0);
	}
}

mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_set_max(unsigned char const* const data, mk_lang_size_t const size)
{
	unsigned char const* d;
	mk_lang_size_t s;
	mk_sl_cui_inl_def_t cui;
	int i;

	d = data;
	s = size;
	check_data(sizeof(cui));
	memcpy(&cui, d, sizeof(cui));
	mk_sl_cui_inl_def_set_max(&cui);
	for(i = 0; i != sizeof(cui); ++i)
	{
		test(((unsigned char*)(&cui))[i] == 0xff);
	}
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


mk_lang_jumbo void mk_sl_cui_fuzz_inl_def_fn(unsigned char const* const data, mk_lang_size_t const size)
{
	if(!(size >= sizeof(mk_sl_cui_inl_def_t))) return;
	mk_sl_cui_fuzz_inl_def_set_zero(data, size);
	mk_sl_cui_fuzz_inl_def_set_max(data, size);
	mk_sl_cui_fuzz_inl_def_set_one(data, size);
	mk_sl_cui_fuzz_inl_def_set_bit(data, size);
	mk_sl_cui_fuzz_inl_def_set_mask(data, size);
}


#undef test
#undef check
#undef check_data
#undef advance


#include "mk_sl_cui_fuzz_inl_undef.h"
#include "mk_sl_cui_inl_undef.h"
