#include "mk_lang_bui_div_test.h"

#include "mk_lang_bui_div.h"
#include "mk_lang_crash.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizet.h"
#include "mk_sl_cui.h"

#include <string.h> /* memcpy */


mk_lang_jumbo void mk_lang_bui_div_test_fuzz_uchar4le(unsigned char const* const data, mk_lang_size_t const size)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	unsigned long ul1;
	unsigned long ul2;
	unsigned long ul3;
	unsigned long ul4;
	unsigned long ul5;
	unsigned long ul6;
	unsigned long ul7;
	unsigned long ul8;
	mk_sl_cui_uchar4le_t cui1;
	mk_sl_cui_uchar4le_t cui2;
	mk_sl_cui_uchar4le_t cui3;
	mk_sl_cui_uchar4le_t cui4;

	d = data;
	s = size;
	check_data(2 * 4);
	ul1 = 0;
	memcpy(&ul1, data + 0 * 4, 4);
	ul2 = 0;
	memcpy(&ul2, data + 1 * 4, 4);
	if(ul2 == 0) return;
	ul3 = ul1 / ul2;
	ul4 = ul1 % ul2;
	ul5 = ul1;
	ul6 = ul2;
	mk_sl_cui_uchar4le_from_bi_ulong(&cui1, &ul5);
	mk_sl_cui_uchar4le_from_bi_ulong(&cui2, &ul6);
	mk_lang_bui_div_uchar_4_4_le_3(cui1.m_data, cui2.m_data, cui3.m_data, cui4.m_data);
	mk_sl_cui_uchar4le_to_bi_ulong(&cui3, &ul7);
	mk_sl_cui_uchar4le_to_bi_ulong(&cui4, &ul8);
	test(ul7 == ul3);
	test(ul8 == ul4);

	#undef check
	#undef check_data

	#undef test
}

mk_lang_jumbo void mk_lang_bui_div_test_fuzz_uchar4be(unsigned char const* const data, mk_lang_size_t const size)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	unsigned long ul1;
	unsigned long ul2;
	unsigned long ul3;
	unsigned long ul4;
	unsigned long ul5;
	unsigned long ul6;
	unsigned long ul7;
	unsigned long ul8;
	mk_sl_cui_uchar4be_t cui1;
	mk_sl_cui_uchar4be_t cui2;
	mk_sl_cui_uchar4be_t cui3;
	mk_sl_cui_uchar4be_t cui4;

	d = data;
	s = size;
	check_data(2 * 4);
	ul1 = 0;
	memcpy(&ul1, data + 0 * 4, 4);
	ul2 = 0;
	memcpy(&ul2, data + 1 * 4, 4);
	if(ul2 == 0) return;
	ul3 = ul1 / ul2;
	ul4 = ul1 % ul2;
	ul5 = ul1;
	ul6 = ul2;
	mk_sl_cui_uchar4be_from_bi_ulong(&cui1, &ul5);
	mk_sl_cui_uchar4be_from_bi_ulong(&cui2, &ul6);
	mk_lang_bui_div_uchar_4_4_be_3(cui1.m_data, cui2.m_data, cui3.m_data, cui4.m_data);
	mk_sl_cui_uchar4be_to_bi_ulong(&cui3, &ul7);
	mk_sl_cui_uchar4be_to_bi_ulong(&cui4, &ul8);
	test(ul7 == ul3);
	test(ul8 == ul4);

	#undef check
	#undef check_data

	#undef test
}

mk_lang_jumbo void mk_lang_bui_div_test_fuzz_ushort2le(unsigned char const* const data, mk_lang_size_t const size)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	unsigned long ul1;
	unsigned long ul2;
	unsigned long ul3;
	unsigned long ul4;
	unsigned long ul5;
	unsigned long ul6;
	unsigned long ul7;
	unsigned long ul8;
	mk_sl_cui_ushort2le_t cui1;
	mk_sl_cui_ushort2le_t cui2;
	mk_sl_cui_ushort2le_t cui3;
	mk_sl_cui_ushort2le_t cui4;

	d = data;
	s = size;
	check_data(2 * 4);
	ul1 = 0;
	memcpy(&ul1, data + 0 * 4, 4);
	ul2 = 0;
	memcpy(&ul2, data + 1 * 4, 4);
	if(ul2 == 0) return;
	ul3 = ul1 / ul2;
	ul4 = ul1 % ul2;
	ul5 = ul1;
	ul6 = ul2;
	mk_sl_cui_ushort2le_from_bi_ulong(&cui1, &ul5);
	mk_sl_cui_ushort2le_from_bi_ulong(&cui2, &ul6);
	mk_lang_bui_div_ushort_2_2_le_3(cui1.m_data, cui2.m_data, cui3.m_data, cui4.m_data);
	mk_sl_cui_ushort2le_to_bi_ulong(&cui3, &ul7);
	mk_sl_cui_ushort2le_to_bi_ulong(&cui4, &ul8);
	test(ul7 == ul3);
	test(ul8 == ul4);

	#undef check
	#undef check_data

	#undef test
}

mk_lang_jumbo void mk_lang_bui_div_test_fuzz_ushort2be(unsigned char const* const data, mk_lang_size_t const size)
{
	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	unsigned long ul1;
	unsigned long ul2;
	unsigned long ul3;
	unsigned long ul4;
	unsigned long ul5;
	unsigned long ul6;
	unsigned long ul7;
	unsigned long ul8;
	mk_sl_cui_ushort2be_t cui1;
	mk_sl_cui_ushort2be_t cui2;
	mk_sl_cui_ushort2be_t cui3;
	mk_sl_cui_ushort2be_t cui4;

	d = data;
	s = size;
	check_data(2 * 4);
	ul1 = 0;
	memcpy(&ul1, data + 0 * 4, 4);
	ul2 = 0;
	memcpy(&ul2, data + 1 * 4, 4);
	if(ul2 == 0) return;
	ul3 = ul1 / ul2;
	ul4 = ul1 % ul2;
	ul5 = ul1;
	ul6 = ul2;
	mk_sl_cui_ushort2be_from_bi_ulong(&cui1, &ul5);
	mk_sl_cui_ushort2be_from_bi_ulong(&cui2, &ul6);
	mk_lang_bui_div_ushort_2_2_be_3(cui1.m_data, cui2.m_data, cui3.m_data, cui4.m_data);
	mk_sl_cui_ushort2be_to_bi_ulong(&cui3, &ul7);
	mk_sl_cui_ushort2be_to_bi_ulong(&cui4, &ul8);
	test(ul7 == ul3);
	test(ul8 == ul4);

	#undef check
	#undef check_data

	#undef test
}

mk_lang_jumbo void mk_lang_bui_div_test_fuzz(unsigned char const* const data, mk_lang_size_t const size)
{
	mk_lang_bui_div_test_fuzz_uchar4le(data, size);
	mk_lang_bui_div_test_fuzz_uchar4be(data, size);
	mk_lang_bui_div_test_fuzz_ushort2le(data, size);
	mk_lang_bui_div_test_fuzz_ushort2be(data, size);
}
