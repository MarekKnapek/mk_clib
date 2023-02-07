#include "mk_sl_cui_test.h"

#include "mk_lang_bool.h"
#include "mk_lang_bui.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_lllong.h"
#include "mk_lang_llong.h"
#include "mk_lang_sizet.h"
#include "mk_sl_cui.h"

#include <string.h> /* memcpy */


mk_lang_jumbo void mk_sl_cui_test(void)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	unsigned long ul;
	mk_sl_cui_uchar4le_t uchar4le;
	mk_sl_cui_uchar4be_t uchar4be;
	mk_sl_cui_ushort2le_t ushort2le;
	mk_sl_cui_ushort2be_t ushort2be;
	mk_sl_cui_ulong1le_t ulong1le;
	mk_sl_cui_ulong1be_t ulong1be;

	ul = 1ul;

	mk_sl_cui_uchar4le_set_zero(&uchar4le); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le, &ul); test(ul == 0ul);
	mk_sl_cui_uchar4be_set_zero(&uchar4be); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be, &ul); test(ul == 0ul);
	mk_sl_cui_ushort2le_set_zero(&ushort2le); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le, &ul); test(ul == 0ul);
	mk_sl_cui_ushort2be_set_zero(&ushort2be); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be, &ul); test(ul == 0ul);
	mk_sl_cui_ulong1le_set_zero(&ulong1le); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le, &ul); test(ul == 0ul);
	mk_sl_cui_ulong1be_set_zero(&ulong1be); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be, &ul); test(ul == 0ul);

	mk_sl_cui_uchar4le_set_max(&uchar4le); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le, &ul); test(ul == 0xfffffffful);
	mk_sl_cui_uchar4be_set_max(&uchar4be); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be, &ul); test(ul == 0xfffffffful);
	mk_sl_cui_ushort2le_set_max(&ushort2le); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le, &ul); test(ul == 0xfffffffful);
	mk_sl_cui_ushort2be_set_max(&ushort2be); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be, &ul); test(ul == 0xfffffffful);
	mk_sl_cui_ulong1le_set_max(&ulong1le); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le, &ul); test(ul == 0xfffffffful);
	mk_sl_cui_ulong1be_set_max(&ulong1be); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be, &ul); test(ul == 0xfffffffful);

	mk_sl_cui_uchar4le_set_one(&uchar4le); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le, &ul); test(ul == 1ul);
	mk_sl_cui_uchar4be_set_one(&uchar4be); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be, &ul); test(ul == 1ul);
	mk_sl_cui_ushort2le_set_one(&ushort2le); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le, &ul); test(ul == 1ul);
	mk_sl_cui_ushort2be_set_one(&ushort2be); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be, &ul); test(ul == 1ul);
	mk_sl_cui_ulong1le_set_one(&ulong1le); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le, &ul); test(ul == 1ul);
	mk_sl_cui_ulong1be_set_one(&ulong1be); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be, &ul); test(ul == 1ul);

	#undef test
}

mk_lang_jumbo void mk_sl_cui_test_fuzz_mul3_long(unsigned char const* const data, mk_lang_size_t const size)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	unsigned long ul1;
	unsigned long ul2;
	unsigned long ul3;
	mk_sl_cui_uchar3le_t uchar3le1;
	mk_sl_cui_uchar3le_t uchar3le2;
	mk_sl_cui_uchar3le_t uchar3le3;
	mk_sl_cui_uchar3be_t uchar3be1;
	mk_sl_cui_uchar3be_t uchar3be2;
	mk_sl_cui_uchar3be_t uchar3be3;

	d = data;
	s = size;
	ul1 = 0;
	ul2 = 0;
	ul3 = 0;
	mk_sl_cui_uchar3le_set_zero(&uchar3le1);
	mk_sl_cui_uchar3le_set_zero(&uchar3le2);
	mk_sl_cui_uchar3le_set_zero(&uchar3le3);
	mk_sl_cui_uchar3be_set_zero(&uchar3be1);
	mk_sl_cui_uchar3be_set_zero(&uchar3be2);
	mk_sl_cui_uchar3be_set_zero(&uchar3be3);

	check_data(2 * 4);
	memcpy(&ul1, data + 0 * 4, 4);
	memcpy(&ul2, data + 1 * 4, 4);
	mk_sl_cui_uchar3le_from_bi_ulong(&uchar3le1, &ul1); mk_sl_cui_uchar3le_from_bi_ulong(&uchar3le2, &ul2); mk_sl_cui_uchar3le_mul3_wrap_lo(&uchar3le1, &uchar3le2, &uchar3le3); mk_sl_cui_uchar3le_to_bi_ulong(&uchar3le3, &ul3); test(ul3 == (((ul1 & 0x00fffffful) * (ul2 & 0x00fffffful)) & 0x00fffffful));
	mk_sl_cui_uchar3be_from_bi_ulong(&uchar3be1, &ul1); mk_sl_cui_uchar3be_from_bi_ulong(&uchar3be2, &ul2); mk_sl_cui_uchar3be_mul3_wrap_lo(&uchar3be1, &uchar3be2, &uchar3be3); mk_sl_cui_uchar3be_to_bi_ulong(&uchar3be3, &ul3); test(ul3 == (((ul1 & 0x00fffffful) * (ul2 & 0x00fffffful)) & 0x00fffffful));

	#undef check
	#undef check_data

	#undef test
}

mk_lang_jumbo void mk_sl_cui_test_fuzz_mul3_llong(unsigned char const* const data, mk_lang_size_t const size)
{
	#if mk_lang_llong_has == 1

	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_ullong_t ull1;
	mk_lang_ullong_t ull2;
	mk_lang_ullong_t ull3;
	mk_sl_cui_ushort3le_t ushort3le1;
	mk_sl_cui_ushort3le_t ushort3le2;
	mk_sl_cui_ushort3le_t ushort3le3;
	mk_sl_cui_ushort3be_t ushort3be1;
	mk_sl_cui_ushort3be_t ushort3be2;
	mk_sl_cui_ushort3be_t ushort3be3;

	d = data;
	s = size;
	ull1 = 0;
	ull2 = 0;
	ull3 = 0;
	mk_sl_cui_ushort3le_set_zero(&ushort3le1);
	mk_sl_cui_ushort3le_set_zero(&ushort3le2);
	mk_sl_cui_ushort3le_set_zero(&ushort3le3);
	mk_sl_cui_ushort3be_set_zero(&ushort3be1);
	mk_sl_cui_ushort3be_set_zero(&ushort3be2);
	mk_sl_cui_ushort3be_set_zero(&ushort3be3);

	check_data(2 * 8);
	memcpy(&ull1, data + 0 * 8, 8);
	memcpy(&ull2, data + 1 * 8, 8);
	mk_sl_cui_ushort3le_from_bi_ullong(&ushort3le1, &ull1); mk_sl_cui_ushort3le_from_bi_ullong(&ushort3le2, &ull2); mk_sl_cui_ushort3le_mul3_wrap_lo(&ushort3le1, &ushort3le2, &ushort3le3); mk_sl_cui_ushort3le_to_bi_ullong(&ushort3le3, &ull3); test(ull3 == (((ull1 & mk_lang_ullong_c(0x0000ffffffffffff)) * (ull2 & mk_lang_ullong_c(0x0000ffffffffffff))) & mk_lang_ullong_c(0x0000ffffffffffff)));
	mk_sl_cui_ushort3be_from_bi_ullong(&ushort3be1, &ull1); mk_sl_cui_ushort3be_from_bi_ullong(&ushort3be2, &ull2); mk_sl_cui_ushort3be_mul3_wrap_lo(&ushort3be1, &ushort3be2, &ushort3be3); mk_sl_cui_ushort3be_to_bi_ullong(&ushort3be3, &ull3); test(ull3 == (((ull1 & mk_lang_ullong_c(0x0000ffffffffffff)) * (ull2 & mk_lang_ullong_c(0x0000ffffffffffff))) & mk_lang_ullong_c(0x0000ffffffffffff)));

	#undef check
	#undef check_data

	#undef test

	#else

	((void)(data));
	((void)(size));

	#endif
}

mk_lang_jumbo void mk_sl_cui_test_fuzz_mul3_lllong(unsigned char const* const data, mk_lang_size_t const size)
{
	#if mk_lang_lllong_has == 1

	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_ulllong_t ulll1;
	mk_lang_ulllong_t ulll2;
	mk_lang_ulllong_t ulll3;
	mk_lang_ulllong_t mask;
	mk_sl_cui_ulong3le_t ulong3le1;
	mk_sl_cui_ulong3le_t ulong3le2;
	mk_sl_cui_ulong3le_t ulong3le3;
	mk_sl_cui_ulong3be_t ulong3be1;
	mk_sl_cui_ulong3be_t ulong3be2;
	mk_sl_cui_ulong3be_t ulong3be3;

	d = data;
	s = size;
	ulll1 = 0;
	ulll2 = 0;
	ulll3 = 0;
	mask = ((mk_lang_ulllong_t)(((mk_lang_ulllong_t)(((mk_lang_ulllong_t)(mk_lang_ullong_c(0x00000000ffffffff))) << 64)) | ((mk_lang_ulllong_t)(mk_lang_ullong_c(0xffffffffffffffff)))));
	mk_sl_cui_ulong3le_set_zero(&ulong3le1);
	mk_sl_cui_ulong3le_set_zero(&ulong3le2);
	mk_sl_cui_ulong3le_set_zero(&ulong3le3);
	mk_sl_cui_ulong3be_set_zero(&ulong3be1);
	mk_sl_cui_ulong3be_set_zero(&ulong3be2);
	mk_sl_cui_ulong3be_set_zero(&ulong3be3);

	check_data(2 * 16);
	memcpy(&ulll1, data + 0 * 16, 16);
	memcpy(&ulll2, data + 1 * 16, 16);
	mk_sl_cui_ulong3le_from_bi_ulllong(&ulong3le1, &ulll1); mk_sl_cui_ulong3le_from_bi_ulllong(&ulong3le2, &ulll2); mk_sl_cui_ulong3le_mul3_wrap_lo(&ulong3le1, &ulong3le2, &ulong3le3); mk_sl_cui_ulong3le_to_bi_ulllong(&ulong3le3, &ulll3); test(ulll3 == (((ulll1 & mask) * (ulll2 & mask)) & mask));
	mk_sl_cui_ulong3be_from_bi_ulllong(&ulong3be1, &ulll1); mk_sl_cui_ulong3be_from_bi_ulllong(&ulong3be2, &ulll2); mk_sl_cui_ulong3be_mul3_wrap_lo(&ulong3be1, &ulong3be2, &ulong3be3); mk_sl_cui_ulong3be_to_bi_ulllong(&ulong3be3, &ulll3); test(ulll3 == (((ulll1 & mask) * (ulll2 & mask)) & mask));

	#undef check
	#undef check_data

	#undef test

	#else

	((void)(data));
	((void)(size));

	#endif
}

mk_lang_jumbo void mk_sl_cui_test_fuzz_mul3(unsigned char const* const data, mk_lang_size_t const size)
{
	mk_sl_cui_test_fuzz_mul3_long(data, size);
	mk_sl_cui_test_fuzz_mul3_llong(data, size);
	mk_sl_cui_test_fuzz_mul3_lllong(data, size);
}

mk_lang_jumbo void mk_sl_cui_test_fuzz_long(unsigned char const* const data, mk_lang_size_t const size)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	unsigned long ul;
	unsigned long ul1;
	unsigned long ul2;
	unsigned long ul3;
	unsigned char val;
	mk_sl_cui_uchar4le_t uchar4le1;
	mk_sl_cui_uchar4be_t uchar4be1;
	mk_sl_cui_ushort2le_t ushort2le1;
	mk_sl_cui_ushort2be_t ushort2be1;
	mk_sl_cui_ulong1le_t ulong1le1;
	mk_sl_cui_ulong1be_t ulong1be1;
	mk_sl_cui_uchar4le_t uchar4le2;
	mk_sl_cui_uchar4be_t uchar4be2;
	mk_sl_cui_ushort2le_t ushort2le2;
	mk_sl_cui_ushort2be_t ushort2be2;
	mk_sl_cui_ulong1le_t ulong1le2;
	mk_sl_cui_ulong1be_t ulong1be2;
	mk_sl_cui_uchar4le_t uchar4le3;
	mk_sl_cui_uchar4be_t uchar4be3;
	mk_sl_cui_ushort2le_t ushort2le3;
	mk_sl_cui_ushort2be_t ushort2be3;
	mk_sl_cui_ulong1le_t ulong1le3;
	mk_sl_cui_ulong1be_t ulong1be3;
	mk_lang_bool_t b1;
	mk_lang_bool_t b2;

	d = data;
	s = size;
	ul = 1ul;
	ul1 = 1ul;
	ul2 = 1ul;
	val = 0;

	check_data(1);
	val = *data;
	val = val % 32;
	mk_sl_cui_uchar4le_set_bit(&uchar4le1, val); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul); test(ul == (1ul << val));
	mk_sl_cui_uchar4be_set_bit(&uchar4be1, val); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul); test(ul == (1ul << val));
	mk_sl_cui_ushort2le_set_bit(&ushort2le1, val); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul); test(ul == (1ul << val));
	mk_sl_cui_ushort2be_set_bit(&ushort2be1, val); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul); test(ul == (1ul << val));
	mk_sl_cui_ulong1le_set_bit(&ulong1le1, val); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul); test(ul == (1ul << val));
	mk_sl_cui_ulong1be_set_bit(&ulong1be1, val); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul); test(ul == (1ul << val));

	check_data(1);
	val = *data;
	val = (val % 32) + 1;
	mk_sl_cui_uchar4le_set_mask(&uchar4le1, val); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul); test(ul == ((((1ul << (val - 1)) - 1ul) << 1) + 1ul));
	mk_sl_cui_uchar4be_set_mask(&uchar4be1, val); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul); test(ul == ((((1ul << (val - 1)) - 1ul) << 1) + 1ul));
	mk_sl_cui_ushort2le_set_mask(&ushort2le1, val); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul); test(ul == ((((1ul << (val - 1)) - 1ul) << 1) + 1ul));
	mk_sl_cui_ushort2be_set_mask(&ushort2be1, val); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul); test(ul == ((((1ul << (val - 1)) - 1ul) << 1) + 1ul));
	mk_sl_cui_ulong1le_set_mask(&ulong1le1, val); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul); test(ul == ((((1ul << (val - 1)) - 1ul) << 1) + 1ul));
	mk_sl_cui_ulong1be_set_mask(&ulong1be1, val); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul); test(ul == ((((1ul << (val - 1)) - 1ul) << 1) + 1ul));

	check_data(4);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul2); test(ul2 == ul1);
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul2); test(ul2 == ul1);
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul2); test(ul2 == ul1);
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul2); test(ul2 == ul1);
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul2); test(ul2 == ul1);
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul2); test(ul2 == ul1);

	check_data(4);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); test(mk_sl_cui_uchar4le_is_zero(&uchar4le1) == (ul1 == 0ul));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); test(mk_sl_cui_uchar4be_is_zero(&uchar4be1) == (ul1 == 0ul));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); test(mk_sl_cui_ushort2le_is_zero(&ushort2le1) == (ul1 == 0ul));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); test(mk_sl_cui_ushort2be_is_zero(&ushort2be1) == (ul1 == 0ul));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); test(mk_sl_cui_ulong1le_is_zero(&ulong1le1) == (ul1 == 0ul));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); test(mk_sl_cui_ulong1be_is_zero(&ulong1be1) == (ul1 == 0ul));

	check_data(4);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); test(mk_sl_cui_uchar4le_is_max(&uchar4le1) == (ul1 == 0xfffffffful));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); test(mk_sl_cui_uchar4be_is_max(&uchar4be1) == (ul1 == 0xfffffffful));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); test(mk_sl_cui_ushort2le_is_max(&ushort2le1) == (ul1 == 0xfffffffful));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); test(mk_sl_cui_ushort2be_is_max(&ushort2be1) == (ul1 == 0xfffffffful));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); test(mk_sl_cui_ulong1le_is_max(&ulong1le1) == (ul1 == 0xfffffffful));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); test(mk_sl_cui_ulong1be_is_max(&ulong1be1) == (ul1 == 0xfffffffful));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); test(mk_sl_cui_uchar4le_eq(&uchar4le1, &uchar4le2) == (ul1 == ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); test(mk_sl_cui_uchar4be_eq(&uchar4be1, &uchar4be2) == (ul1 == ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); test(mk_sl_cui_ushort2le_eq(&ushort2le1, &ushort2le2) == (ul1 == ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); test(mk_sl_cui_ushort2be_eq(&ushort2be1, &ushort2be2) == (ul1 == ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); test(mk_sl_cui_ulong1le_eq(&ulong1le1, &ulong1le2) == (ul1 == ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); test(mk_sl_cui_ulong1be_eq(&ulong1be1, &ulong1be2) == (ul1 == ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); test(mk_sl_cui_uchar4le_ne(&uchar4le1, &uchar4le2) == (ul1 != ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); test(mk_sl_cui_uchar4be_ne(&uchar4be1, &uchar4be2) == (ul1 != ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); test(mk_sl_cui_ushort2le_ne(&ushort2le1, &ushort2le2) == (ul1 != ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); test(mk_sl_cui_ushort2be_ne(&ushort2be1, &ushort2be2) == (ul1 != ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); test(mk_sl_cui_ulong1le_ne(&ulong1le1, &ulong1le2) == (ul1 != ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); test(mk_sl_cui_ulong1be_ne(&ulong1be1, &ulong1be2) == (ul1 != ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); test(mk_sl_cui_uchar4le_lt(&uchar4le1, &uchar4le2) == (ul1 < ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); test(mk_sl_cui_uchar4be_lt(&uchar4be1, &uchar4be2) == (ul1 < ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); test(mk_sl_cui_ushort2le_lt(&ushort2le1, &ushort2le2) == (ul1 < ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); test(mk_sl_cui_ushort2be_lt(&ushort2be1, &ushort2be2) == (ul1 < ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); test(mk_sl_cui_ulong1le_lt(&ulong1le1, &ulong1le2) == (ul1 < ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); test(mk_sl_cui_ulong1be_lt(&ulong1be1, &ulong1be2) == (ul1 < ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); test(mk_sl_cui_uchar4le_le(&uchar4le1, &uchar4le2) == (ul1 <= ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); test(mk_sl_cui_uchar4be_le(&uchar4be1, &uchar4be2) == (ul1 <= ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); test(mk_sl_cui_ushort2le_le(&ushort2le1, &ushort2le2) == (ul1 <= ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); test(mk_sl_cui_ushort2be_le(&ushort2be1, &ushort2be2) == (ul1 <= ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); test(mk_sl_cui_ulong1le_le(&ulong1le1, &ulong1le2) == (ul1 <= ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); test(mk_sl_cui_ulong1be_le(&ulong1be1, &ulong1be2) == (ul1 <= ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); test(mk_sl_cui_uchar4le_gt(&uchar4le1, &uchar4le2) == (ul1 > ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); test(mk_sl_cui_uchar4be_gt(&uchar4be1, &uchar4be2) == (ul1 > ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); test(mk_sl_cui_ushort2le_gt(&ushort2le1, &ushort2le2) == (ul1 > ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); test(mk_sl_cui_ushort2be_gt(&ushort2be1, &ushort2be2) == (ul1 > ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); test(mk_sl_cui_ulong1le_gt(&ulong1le1, &ulong1le2) == (ul1 > ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); test(mk_sl_cui_ulong1be_gt(&ulong1be1, &ulong1be2) == (ul1 > ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); test(mk_sl_cui_uchar4le_ge(&uchar4le1, &uchar4le2) == (ul1 >= ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); test(mk_sl_cui_uchar4be_ge(&uchar4be1, &uchar4be2) == (ul1 >= ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); test(mk_sl_cui_ushort2le_ge(&ushort2le1, &ushort2le2) == (ul1 >= ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); test(mk_sl_cui_ushort2be_ge(&ushort2be1, &ushort2be2) == (ul1 >= ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); test(mk_sl_cui_ulong1le_ge(&ulong1le1, &ulong1le2) == (ul1 >= ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); test(mk_sl_cui_ulong1be_ge(&ulong1be1, &ulong1be2) == (ul1 >= ul2));

	check_data(4);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_inc2(&uchar4le1, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le2, &ul2); test(ul2 == (ul1 + 1ul));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_inc2(&uchar4be1, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be2, &ul2); test(ul2 == (ul1 + 1ul));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_inc2(&ushort2le1, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le2, &ul2); test(ul2 == (ul1 + 1ul));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_inc2(&ushort2be1, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be2, &ul2); test(ul2 == (ul1 + 1ul));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_inc2(&ulong1le1, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le2, &ul2); test(ul2 == (ul1 + 1ul));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_inc2(&ulong1be1, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be2, &ul2); test(ul2 == (ul1 + 1ul));

	check_data(4);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_dec2(&uchar4le1, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le2, &ul2); test(ul2 == (ul1 - 1ul));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_dec2(&uchar4be1, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be2, &ul2); test(ul2 == (ul1 - 1ul));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_dec2(&ushort2le1, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le2, &ul2); test(ul2 == (ul1 - 1ul));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_dec2(&ushort2be1, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be2, &ul2); test(ul2 == (ul1 - 1ul));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_dec2(&ulong1le1, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le2, &ul2); test(ul2 == (ul1 - 1ul));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_dec2(&ulong1be1, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be2, &ul2); test(ul2 == (ul1 - 1ul));

	check_data(4);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_inc1(&uchar4le1); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul2); test(ul2 == (ul1 + 1ul));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_inc1(&uchar4be1); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul2); test(ul2 == (ul1 + 1ul));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_inc1(&ushort2le1); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul2); test(ul2 == (ul1 + 1ul));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_inc1(&ushort2be1); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul2); test(ul2 == (ul1 + 1ul));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_inc1(&ulong1le1); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul2); test(ul2 == (ul1 + 1ul));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_inc1(&ulong1be1); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul2); test(ul2 == (ul1 + 1ul));

	check_data(4);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_dec1(&uchar4le1); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul2); test(ul2 == (ul1 - 1ul));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_dec1(&uchar4be1); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul2); test(ul2 == (ul1 - 1ul));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_dec1(&ushort2le1); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul2); test(ul2 == (ul1 - 1ul));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_dec1(&ushort2be1); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul2); test(ul2 == (ul1 - 1ul));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_dec1(&ulong1le1); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul2); test(ul2 == (ul1 - 1ul));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_dec1(&ulong1be1); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul2); test(ul2 == (ul1 - 1ul));

	check_data(4);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_not2(&uchar4le1, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le2, &ul2); test(ul2 == (~ul1));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_not2(&uchar4be1, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be2, &ul2); test(ul2 == (~ul1));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_not2(&ushort2le1, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le2, &ul2); test(ul2 == (~ul1));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_not2(&ushort2be1, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be2, &ul2); test(ul2 == (~ul1));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_not2(&ulong1le1, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le2, &ul2); test(ul2 == (~ul1));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_not2(&ulong1be1, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be2, &ul2); test(ul2 == (~ul1));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_or3(&uchar4le1, &uchar4le2, &uchar4le3); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 | ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_or3(&uchar4be1, &uchar4be2, &uchar4be3); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 | ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2);mk_sl_cui_ushort2le_or3(&ushort2le1, &ushort2le2, &ushort2le3); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 | ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2);mk_sl_cui_ushort2be_or3(&ushort2be1, &ushort2be2, &ushort2be3); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 | ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_or3(&ulong1le1, &ulong1le2, &ulong1le3); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 | ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_or3(&ulong1be1, &ulong1be2, &ulong1be3); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 | ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_and3(&uchar4le1, &uchar4le2, &uchar4le3); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 & ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_and3(&uchar4be1, &uchar4be2, &uchar4be3); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 & ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2);mk_sl_cui_ushort2le_and3(&ushort2le1, &ushort2le2, &ushort2le3); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 & ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2);mk_sl_cui_ushort2be_and3(&ushort2be1, &ushort2be2, &ushort2be3); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 & ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_and3(&ulong1le1, &ulong1le2, &ulong1le3); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 & ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_and3(&ulong1be1, &ulong1be2, &ulong1be3); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 & ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_xor3(&uchar4le1, &uchar4le2, &uchar4le3); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 ^ ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_xor3(&uchar4be1, &uchar4be2, &uchar4be3); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 ^ ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2);mk_sl_cui_ushort2le_xor3(&ushort2le1, &ushort2le2, &ushort2le3); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 ^ ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2);mk_sl_cui_ushort2be_xor3(&ushort2be1, &ushort2be2, &ushort2be3); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 ^ ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_xor3(&ulong1le1, &ulong1le2, &ulong1le3); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 ^ ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_xor3(&ulong1be1, &ulong1be2, &ulong1be3); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 ^ ul2));

	check_data(4);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_not1(&uchar4le1); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul2); test(ul2 == (~ul1));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_not1(&uchar4be1); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul2); test(ul2 == (~ul1));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_not1(&ushort2le1); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul2); test(ul2 == (~ul1));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_not1(&ushort2be1); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul2); test(ul2 == (~ul1));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_not1(&ulong1le1); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul2); test(ul2 == (~ul1));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_not1(&ulong1be1); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul2); test(ul2 == (~ul1));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_or2(&uchar4le1, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul3); test(ul3 == (ul1 | ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_or2(&uchar4be1, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 | ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2);mk_sl_cui_ushort2le_or2(&ushort2le1, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 | ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2);mk_sl_cui_ushort2be_or2(&ushort2be1, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 | ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_or2(&ulong1le1, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 | ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_or2(&ulong1be1, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 | ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_and2(&uchar4le1, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul3); test(ul3 == (ul1 & ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_and2(&uchar4be1, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 & ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2);mk_sl_cui_ushort2le_and2(&ushort2le1, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 & ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2);mk_sl_cui_ushort2be_and2(&ushort2be1, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 & ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_and2(&ulong1le1, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 & ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_and2(&ulong1be1, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 & ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_xor2(&uchar4le1, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul3); test(ul3 == (ul1 ^ ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_xor2(&uchar4be1, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 ^ ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2);mk_sl_cui_ushort2le_xor2(&ushort2le1, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 ^ ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2);mk_sl_cui_ushort2be_xor2(&ushort2be1, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 ^ ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_xor2(&ulong1le1, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 ^ ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_xor2(&ulong1be1, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 ^ ul2));

	check_data(5);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	val = data[4] % 32;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_shl3(&uchar4le1, val, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le2, &ul2); test(ul2 == (ul1 << val));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_shl3(&uchar4be1, val, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be2, &ul2); test(ul2 == (ul1 << val));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_shl3(&ushort2le1, val, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le2, &ul2); test(ul2 == (ul1 << val));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_shl3(&ushort2be1, val, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be2, &ul2); test(ul2 == (ul1 << val));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_shl3(&ulong1le1, val, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le2, &ul2); test(ul2 == (ul1 << val));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_shl3(&ulong1be1, val, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be2, &ul2); test(ul2 == (ul1 << val));

	check_data(5);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	val = data[4] % 32;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_shr3(&uchar4le1, val, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le2, &ul2); test(ul2 == (ul1 >> val));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_shr3(&uchar4be1, val, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be2, &ul2); test(ul2 == (ul1 >> val));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_shr3(&ushort2le1, val, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le2, &ul2); test(ul2 == (ul1 >> val));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_shr3(&ushort2be1, val, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be2, &ul2); test(ul2 == (ul1 >> val));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_shr3(&ulong1le1, val, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le2, &ul2); test(ul2 == (ul1 >> val));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_shr3(&ulong1be1, val, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be2, &ul2); test(ul2 == (ul1 >> val));

	check_data(5);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	val = data[4] % 32;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_rotl3(&uchar4le1, val, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le2, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_rotl3(&uchar4be1, val, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be2, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_rotl3(&ushort2le1, val, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le2, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_rotl3(&ushort2be1, val, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be2, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_rotl3(&ulong1le1, val, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le2, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_rotl3(&ulong1be1, val, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be2, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));

	check_data(5);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	val = data[4] % 32;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_rotr3(&uchar4le1, val, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le2, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_rotr3(&uchar4be1, val, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be2, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_rotr3(&ushort2le1, val, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le2, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_rotr3(&ushort2be1, val, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be2, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_rotr3(&ulong1le1, val, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le2, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_rotr3(&ulong1be1, val, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be2, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));

	check_data(5);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	val = data[4] % 32;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_shl2(&uchar4le1, val); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul2); test(ul2 == (ul1 << val));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_shl2(&uchar4be1, val); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul2); test(ul2 == (ul1 << val));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_shl2(&ushort2le1, val); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul2); test(ul2 == (ul1 << val));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_shl2(&ushort2be1, val); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul2); test(ul2 == (ul1 << val));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_shl2(&ulong1le1, val); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul2); test(ul2 == (ul1 << val));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_shl2(&ulong1be1, val); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul2); test(ul2 == (ul1 << val));

	check_data(5);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	val = data[4] % 32;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_shr2(&uchar4le1, val); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul2); test(ul2 == (ul1 >> val));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_shr2(&uchar4be1, val); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul2); test(ul2 == (ul1 >> val));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_shr2(&ushort2le1, val); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul2); test(ul2 == (ul1 >> val));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_shr2(&ushort2be1, val); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul2); test(ul2 == (ul1 >> val));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_shr2(&ulong1le1, val); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul2); test(ul2 == (ul1 >> val));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_shr2(&ulong1be1, val); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul2); test(ul2 == (ul1 >> val));

	check_data(5);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	val = data[4] % 32;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_rotl2(&uchar4le1, val); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_rotl2(&uchar4be1, val); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_rotl2(&ushort2le1, val); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_rotl2(&ushort2be1, val); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_rotl2(&ulong1le1, val); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_rotl2(&ulong1be1, val); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul2); test(ul2 == ((ul1 << val) | (ul1 >> (32 - val))));

	check_data(5);
	ul1 = 0;
	memcpy(&ul1, data, 4);
	val = data[4] % 32;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_rotr2(&uchar4le1, val); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_rotr2(&uchar4be1, val); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_rotr2(&ushort2le1, val); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_rotr2(&ushort2be1, val); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_rotr2(&ulong1le1, val); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_rotr2(&ulong1be1, val); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul2); test(ul2 == ((ul1 >> val) | (ul1 << (32 - val))));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_add3_wrap_cid_cod(&uchar4le1, &uchar4le2, &uchar4le3); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 + ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_add3_wrap_cid_cod(&uchar4be1, &uchar4be2, &uchar4be3); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 + ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_add3_wrap_cid_cod(&ushort2le1, &ushort2le2, &ushort2le3); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 + ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_add3_wrap_cid_cod(&ushort2be1, &ushort2be2, &ushort2be3); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 + ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_add3_wrap_cid_cod(&ulong1le1, &ulong1le2, &ulong1le3); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 + ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_add3_wrap_cid_cod(&ulong1be1, &ulong1be2, &ulong1be3); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 + ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_add3_wrap_cid_coe(&uchar4le1, &uchar4le2, &uchar4le3, &b1); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_add3_wrap_cid_coe(&uchar4be1, &uchar4be2, &uchar4be3, &b1); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_add3_wrap_cid_coe(&ushort2le1, &ushort2le2, &ushort2le3, &b1); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_add3_wrap_cid_coe(&ushort2be1, &ushort2be2, &ushort2be3, &b1); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_add3_wrap_cid_coe(&ulong1le1, &ulong1le2, &ulong1le3, &b1); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_add3_wrap_cid_coe(&ulong1be1, &ulong1be2, &ulong1be3, &b1); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));

	check_data(9);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	b1 = ((data[8] % 1) == 0) ? mk_lang_false : mk_lang_true;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_add3_wrap_cie_cod(&uchar4le1, &uchar4le2, b1, &uchar4le3); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_add3_wrap_cie_cod(&uchar4be1, &uchar4be2, b1, &uchar4be3); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_add3_wrap_cie_cod(&ushort2le1, &ushort2le2, b1, &ushort2le3); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_add3_wrap_cie_cod(&ushort2be1, &ushort2be2, b1, &ushort2be3); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_add3_wrap_cie_cod(&ulong1le1, &ulong1le2, b1, &ulong1le3); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_add3_wrap_cie_cod(&ulong1be1, &ulong1be2, b1, &ulong1be3); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));

	check_data(9);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	b1 = ((data[8] % 1) == 0) ? mk_lang_false : mk_lang_true;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_add3_wrap_cie_coe(&uchar4le1, &uchar4le2, b1, &uchar4le3, &b2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_add3_wrap_cie_coe(&uchar4be1, &uchar4be2, b1, &uchar4be3, &b2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_add3_wrap_cie_coe(&ushort2le1, &ushort2le2, b1, &ushort2le3, &b2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_add3_wrap_cie_coe(&ushort2be1, &ushort2be2, b1, &ushort2be3, &b2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_add3_wrap_cie_coe(&ulong1le1, &ulong1le2, b1, &ulong1le3, &b2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_add3_wrap_cie_coe(&ulong1be1, &ulong1be2, b1, &ulong1be3, &b2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_add2_wrap_cid_cod(&uchar4le1, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul3); test(ul3 == (ul1 + ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_add2_wrap_cid_cod(&uchar4be1, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 + ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_add2_wrap_cid_cod(&ushort2le1, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 + ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_add2_wrap_cid_cod(&ushort2be1, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 + ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_add2_wrap_cid_cod(&ulong1le1, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 + ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_add2_wrap_cid_cod(&ulong1be1, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 + ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_add2_wrap_cid_coe(&uchar4le1, &uchar4le2, &b1); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_add2_wrap_cid_coe(&uchar4be1, &uchar4be2, &b1); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_add2_wrap_cid_coe(&ushort2le1, &ushort2le2, &b1); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_add2_wrap_cid_coe(&ushort2be1, &ushort2be2, &b1); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_add2_wrap_cid_coe(&ulong1le1, &ulong1le2, &b1); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_add2_wrap_cid_coe(&ulong1be1, &ulong1be2, &b1); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 + ul2)); test(b1 == ((0xfffffffful - ul1) < ul2));

	check_data(9);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	b1 = ((data[8] % 1) == 0) ? mk_lang_false : mk_lang_true;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_add2_wrap_cie_cod(&uchar4le1, &uchar4le2, b1); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_add2_wrap_cie_cod(&uchar4be1, &uchar4be2, b1); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_add2_wrap_cie_cod(&ushort2le1, &ushort2le2, b1); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_add2_wrap_cie_cod(&ushort2be1, &ushort2be2, b1); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_add2_wrap_cie_cod(&ulong1le1, &ulong1le2, b1); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_add2_wrap_cie_cod(&ulong1be1, &ulong1be2, b1); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul))));

	check_data(9);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	b1 = ((data[8] % 1) == 0) ? mk_lang_false : mk_lang_true;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_add2_wrap_cie_coe(&uchar4le1, &uchar4le2, b1, &b2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_add2_wrap_cie_coe(&uchar4be1, &uchar4be2, b1, &b2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_add2_wrap_cie_coe(&ushort2le1, &ushort2le2, b1, &b2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_add2_wrap_cie_coe(&ushort2be1, &ushort2be2, b1, &b2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_add2_wrap_cie_coe(&ulong1le1, &ulong1le2, b1, &b2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_add2_wrap_cie_coe(&ulong1be1, &ulong1be2, b1, &b2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 + ul2 + ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? ((0xfffffffful - ul1) <= ul2) : ((0xfffffffful - ul1) < ul2)));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_sub3_wrap_cid_cod(&uchar4le1, &uchar4le2, &uchar4le3); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 - ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_sub3_wrap_cid_cod(&uchar4be1, &uchar4be2, &uchar4be3); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 - ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_sub3_wrap_cid_cod(&ushort2le1, &ushort2le2, &ushort2le3); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 - ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_sub3_wrap_cid_cod(&ushort2be1, &ushort2be2, &ushort2be3); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 - ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_sub3_wrap_cid_cod(&ulong1le1, &ulong1le2, &ulong1le3); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 - ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_sub3_wrap_cid_cod(&ulong1be1, &ulong1be2, &ulong1be3); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 - ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_sub3_wrap_cid_coe(&uchar4le1, &uchar4le2, &uchar4le3, &b1); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_sub3_wrap_cid_coe(&uchar4be1, &uchar4be2, &uchar4be3, &b1); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_sub3_wrap_cid_coe(&ushort2le1, &ushort2le2, &ushort2le3, &b1); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_sub3_wrap_cid_coe(&ushort2be1, &ushort2be2, &ushort2be3, &b1); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_sub3_wrap_cid_coe(&ulong1le1, &ulong1le2, &ulong1le3, &b1); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_sub3_wrap_cid_coe(&ulong1be1, &ulong1be2, &ulong1be3, &b1); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));

	check_data(9);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	b1 = ((data[8] % 1) == 0) ? mk_lang_false : mk_lang_true;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_sub3_wrap_cie_cod(&uchar4le1, &uchar4le2, b1, &uchar4le3); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_sub3_wrap_cie_cod(&uchar4be1, &uchar4be2, b1, &uchar4be3); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_sub3_wrap_cie_cod(&ushort2le1, &ushort2le2, b1, &ushort2le3); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_sub3_wrap_cie_cod(&ushort2be1, &ushort2be2, b1, &ushort2be3); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_sub3_wrap_cie_cod(&ulong1le1, &ulong1le2, b1, &ulong1le3); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_sub3_wrap_cie_cod(&ulong1be1, &ulong1be2, b1, &ulong1be3); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));

	check_data(9);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	b1 = ((data[8] % 1) == 0) ? mk_lang_false : mk_lang_true;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_sub3_wrap_cie_coe(&uchar4le1, &uchar4le2, b1, &uchar4le3, &b2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_sub3_wrap_cie_coe(&uchar4be1, &uchar4be2, b1, &uchar4be3, &b2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_sub3_wrap_cie_coe(&ushort2le1, &ushort2le2, b1, &ushort2le3, &b2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_sub3_wrap_cie_coe(&ushort2be1, &ushort2be2, b1, &ushort2be3, &b2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_sub3_wrap_cie_coe(&ulong1le1, &ulong1le2, b1, &ulong1le3, &b2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_sub3_wrap_cie_coe(&ulong1be1, &ulong1be2, b1, &ulong1be3, &b2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_sub2_wrap_cid_cod(&uchar4le1, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul3); test(ul3 == (ul1 - ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_sub2_wrap_cid_cod(&uchar4be1, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 - ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_sub2_wrap_cid_cod(&ushort2le1, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 - ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_sub2_wrap_cid_cod(&ushort2be1, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 - ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_sub2_wrap_cid_cod(&ulong1le1, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 - ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_sub2_wrap_cid_cod(&ulong1be1, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 - ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_sub2_wrap_cid_coe(&uchar4le1, &uchar4le2, &b1); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_sub2_wrap_cid_coe(&uchar4be1, &uchar4be2, &b1); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_sub2_wrap_cid_coe(&ushort2le1, &ushort2le2, &b1); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_sub2_wrap_cid_coe(&ushort2be1, &ushort2be2, &b1); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_sub2_wrap_cid_coe(&ulong1le1, &ulong1le2, &b1); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_sub2_wrap_cid_coe(&ulong1be1, &ulong1be2, &b1); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 - ul2)); test(b1 == (ul1 < ul2));

	check_data(9);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	b1 = ((data[8] % 1) == 0) ? mk_lang_false : mk_lang_true;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_sub2_wrap_cie_cod(&uchar4le1, &uchar4le2, b1); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_sub2_wrap_cie_cod(&uchar4be1, &uchar4be2, b1); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_sub2_wrap_cie_cod(&ushort2le1, &ushort2le2, b1); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_sub2_wrap_cie_cod(&ushort2be1, &ushort2be2, b1); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_sub2_wrap_cie_cod(&ulong1le1, &ulong1le2, b1); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_sub2_wrap_cie_cod(&ulong1be1, &ulong1be2, b1); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul))));

	check_data(9);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	b1 = ((data[8] % 1) == 0) ? mk_lang_false : mk_lang_true;
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_sub2_wrap_cie_coe(&uchar4le1, &uchar4le2, b1, &b2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_sub2_wrap_cie_coe(&uchar4be1, &uchar4be2, b1, &b2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_sub2_wrap_cie_coe(&ushort2le1, &ushort2le2, b1, &b2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_sub2_wrap_cie_coe(&ushort2be1, &ushort2be2, b1, &b2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_sub2_wrap_cie_coe(&ulong1le1, &ulong1le2, b1, &b2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_sub2_wrap_cie_coe(&ulong1be1, &ulong1be2, b1, &b2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); test(ul3 == (ul1 - ul2 - ((unsigned long)(b1 ? 1ul : 0ul)))); test(b2 == (b1 ? (ul1 <= ul2) : (ul1 < ul2)));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_mul3_wrap_lo(&uchar4le1, &uchar4le2, &uchar4le3); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); test(ul3 == (ul1 * ul2));
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_mul3_wrap_lo(&uchar4be1, &uchar4be2, &uchar4be3); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); test(ul3 == (ul1 * ul2));
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_mul3_wrap_lo(&ushort2le1, &ushort2le2, &ushort2le3); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); test(ul3 == (ul1 * ul2));
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_mul3_wrap_lo(&ushort2be1, &ushort2be2, &ushort2be3); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); test(ul3 == (ul1 * ul2));
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_mul3_wrap_lo(&ulong1le1, &ulong1le2, &ulong1le3); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); test(ul3 == (ul1 * ul2));
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_mul3_wrap_lo(&ulong1be1, &ulong1be2, &ulong1be3); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); test(ul3 == (ul1 * ul2));

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_mul3_wrap_hi(&uchar4le1, &uchar4le2, &uchar4le3); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le3, &ul3); mk_lang_bui_ulong_mul3_wrap_hi(&ul1, &ul2, &ul); test(ul3 == ul);
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_mul3_wrap_hi(&uchar4be1, &uchar4be2, &uchar4be3); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be3, &ul3); mk_lang_bui_ulong_mul3_wrap_hi(&ul1, &ul2, &ul); test(ul3 == ul);
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_mul3_wrap_hi(&ushort2le1, &ushort2le2, &ushort2le3); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le3, &ul3); mk_lang_bui_ulong_mul3_wrap_hi(&ul1, &ul2, &ul); test(ul3 == ul);
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_mul3_wrap_hi(&ushort2be1, &ushort2be2, &ushort2be3); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be3, &ul3); mk_lang_bui_ulong_mul3_wrap_hi(&ul1, &ul2, &ul); test(ul3 == ul);
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_mul3_wrap_hi(&ulong1le1, &ulong1le2, &ulong1le3); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le3, &ul3); mk_lang_bui_ulong_mul3_wrap_hi(&ul1, &ul2, &ul); test(ul3 == ul);
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_mul3_wrap_hi(&ulong1be1, &ulong1be2, &ulong1be3); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be3, &ul3); mk_lang_bui_ulong_mul3_wrap_hi(&ul1, &ul2, &ul); test(ul3 == ul);

	check_data(8);
	ul1 = 0;
	memcpy(&ul1, data + 0, 4);
	ul2 = 0;
	memcpy(&ul2, data + 4, 4);
	mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le1, &ul1); mk_sl_cui_uchar4le_from_bi_ulong(&uchar4le2, &ul2); mk_sl_cui_uchar4le_mul4_wrap_wi(&uchar4le1, &uchar4le2, &uchar4le1, &uchar4le2); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le1, &ul3); mk_sl_cui_uchar4le_to_bi_ulong(&uchar4le2, &ul); mk_lang_bui_ulong_mul4_wrap_wi(&ul1, &ul2, &ul1, &ul2); test(ul3 == ul1); test(ul == ul2);
	mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be1, &ul1); mk_sl_cui_uchar4be_from_bi_ulong(&uchar4be2, &ul2); mk_sl_cui_uchar4be_mul4_wrap_wi(&uchar4be1, &uchar4be2, &uchar4be1, &uchar4be2); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be1, &ul3); mk_sl_cui_uchar4be_to_bi_ulong(&uchar4be2, &ul); mk_lang_bui_ulong_mul4_wrap_wi(&ul1, &ul2, &ul1, &ul2); test(ul3 == ul1); test(ul == ul2);
	mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le1, &ul1); mk_sl_cui_ushort2le_from_bi_ulong(&ushort2le2, &ul2); mk_sl_cui_ushort2le_mul4_wrap_wi(&ushort2le1, &ushort2le2, &ushort2le1, &ushort2le2); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le1, &ul3); mk_sl_cui_ushort2le_to_bi_ulong(&ushort2le2, &ul); mk_lang_bui_ulong_mul4_wrap_wi(&ul1, &ul2, &ul1, &ul2); test(ul3 == ul1); test(ul == ul2);
	mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be1, &ul1); mk_sl_cui_ushort2be_from_bi_ulong(&ushort2be2, &ul2); mk_sl_cui_ushort2be_mul4_wrap_wi(&ushort2be1, &ushort2be2, &ushort2be1, &ushort2be2); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be1, &ul3); mk_sl_cui_ushort2be_to_bi_ulong(&ushort2be2, &ul); mk_lang_bui_ulong_mul4_wrap_wi(&ul1, &ul2, &ul1, &ul2); test(ul3 == ul1); test(ul == ul2);
	mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le1, &ul1); mk_sl_cui_ulong1le_from_bi_ulong(&ulong1le2, &ul2); mk_sl_cui_ulong1le_mul4_wrap_wi(&ulong1le1, &ulong1le2, &ulong1le1, &ulong1le2); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le1, &ul3); mk_sl_cui_ulong1le_to_bi_ulong(&ulong1le2, &ul); mk_lang_bui_ulong_mul4_wrap_wi(&ul1, &ul2, &ul1, &ul2); test(ul3 == ul1); test(ul == ul2);
	mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be1, &ul1); mk_sl_cui_ulong1be_from_bi_ulong(&ulong1be2, &ul2); mk_sl_cui_ulong1be_mul4_wrap_wi(&ulong1be1, &ulong1be2, &ulong1be1, &ulong1be2); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be1, &ul3); mk_sl_cui_ulong1be_to_bi_ulong(&ulong1be2, &ul); mk_lang_bui_ulong_mul4_wrap_wi(&ul1, &ul2, &ul1, &ul2); test(ul3 == ul1); test(ul == ul2);

	/*{
		unsigned long long ul1;
		unsigned long long ul2;
		unsigned long long ul3;
		mk_sl_cui_uchar8le_t uchar8le1;
		mk_sl_cui_uchar8le_t uchar8le2;
		mk_sl_cui_uchar8le_t uchar8le3;
		mk_sl_cui_uchar8be_t uchar8be1;
		mk_sl_cui_uchar8be_t uchar8be2;
		mk_sl_cui_uchar8be_t uchar8be3;
		check_data(16);
		ul1 = 0;
		memcpy(&ul1, data + 0, 8);
		ul2 = 0;
		memcpy(&ul2, data + 8, 8);
		mk_sl_cui_uchar8le_from_bi_ulong(&uchar8le1, &ul1); mk_sl_cui_uchar8le_from_bi_ulong(&uchar8le2, &ul2); mk_sl_cui_uchar8le_mul3_wrap_lo(&uchar8le1, &uchar8le2, &uchar8le3); mk_sl_cui_uchar8le_to_bi_ulong(&uchar8le3, &ul3); test(ul3 == (ul1 * ul2));
		mk_sl_cui_uchar8be_from_bi_ulong(&uchar8be1, &ul1); mk_sl_cui_uchar8be_from_bi_ulong(&uchar8be2, &ul2); mk_sl_cui_uchar8be_mul3_wrap_lo(&uchar8be1, &uchar8be2, &uchar8be3); mk_sl_cui_uchar8be_to_bi_ulong(&uchar8be3, &ul3); test(ul3 == (ul1 * ul2));
	}*/

	#undef check
	#undef check_data

	#undef test
}

mk_lang_jumbo void mk_sl_cui_test_fuzz_llong(unsigned char const* const data, mk_lang_size_t const size)
{
	#if mk_lang_llong_has == 1
	#else
	((void)(data));
	((void)(size));
	#endif
}

mk_lang_jumbo void mk_sl_cui_test_fuzz_lllong(unsigned char const* const data, mk_lang_size_t const size)
{
	#if mk_lang_lllong_has == 1
	#else
	((void)(data));
	((void)(size));
	#endif
}

mk_lang_jumbo void mk_sl_cui_test_fuzz(unsigned char const* const data, mk_lang_size_t const size)
{
	mk_sl_cui_test_fuzz_mul3(data, size);
	mk_sl_cui_test_fuzz_long(data, size);
	mk_sl_cui_test_fuzz_llong(data, size);
	mk_sl_cui_test_fuzz_lllong(data, size);
}
