#include "mk_lang_bui_test.h"

#include "mk_lang_bui.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizet.h"

#include <string.h> /* memcpy */


mk_lang_jumbo void mk_lang_bui_test(void)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	unsigned long ul;

	mk_lang_bui_ulong_set_zero(&ul); test(ul == 0ul);
	mk_lang_bui_ulong_set_max(&ul); test(ul == 0xfffffffful);
	mk_lang_bui_ulong_set_one(&ul); test(ul == 1ul);

	#undef test
}

mk_lang_jumbo void mk_lang_bui_test_fuzz(unsigned char const* const data, mk_lang_size_t const size)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	unsigned long ul;
	unsigned char val;
	unsigned char uchars[4];
	unsigned short int ushorts[2];
	unsigned long int ulongs[1];

	d = data;
	s = size;
	ul = 1ul;
	val = 0;

	check_data(1);
	val = *data;
	val = val % 32;
	mk_lang_bui_ulong_set_bit(&ul, val); test(ul == (1ul << val));

	check_data(1);
	val = *data;
	val = (val % 32) + 1;
	mk_lang_bui_ulong_set_mask(&ul, val); test(ul == ((((1ul << (val - 1)) - 1ul) << 1) + 1ul));

	ul = 0;
	check_data(4);
	memcpy(&ul, data, 4);

	mk_lang_bui_ulong_to_buis_uchar_le(&ul, uchars);
	test(uchars[0] == ((ul >> (0 * 8)) & 0xfful));
	test(uchars[1] == ((ul >> (1 * 8)) & 0xfful));
	test(uchars[2] == ((ul >> (2 * 8)) & 0xfful));
	test(uchars[3] == ((ul >> (3 * 8)) & 0xfful));

	mk_lang_bui_ulong_to_buis_uchar_be(&ul, uchars);
	test(uchars[0] == ((ul >> (3 * 8)) & 0xfful));
	test(uchars[1] == ((ul >> (2 * 8)) & 0xfful));
	test(uchars[2] == ((ul >> (1 * 8)) & 0xfful));
	test(uchars[3] == ((ul >> (0 * 8)) & 0xfful));

	mk_lang_bui_ulong_to_buis_ushort_le(&ul, ushorts);
	test(ushorts[0] == ((ul >> (0 * 2 * 8)) & 0xfffful));
	test(ushorts[1] == ((ul >> (1 * 2 * 8)) & 0xfffful));

	mk_lang_bui_ulong_to_buis_ushort_be(&ul, ushorts);
	test(ushorts[0] == ((ul >> (1 * 2 * 8)) & 0xfffful));
	test(ushorts[1] == ((ul >> (0 * 2 * 8)) & 0xfffful));

	mk_lang_bui_ulong_to_buis_ulong_le(&ul, ulongs);
	test(ulongs[0] == ul);

	mk_lang_bui_ulong_to_buis_ulong_be(&ul, ulongs);
	test(ulongs[0] == ul);

	#undef check
	#undef check_data

	#undef test
}
