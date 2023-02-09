#include "mk_lang_bui_div_test.h"

#include "mk_lang_bi.h"
#include "mk_lang_crash.h"
#include "mk_lang_endian.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof.h"
#include "mk_lang_sizet.h"
#include "mk_lang_charbit.h"
#include "mk_lang_lllong.h"

#define mk_sl_cui_name test
#define mk_sl_cui_base_type mk_lang_bi_uchar_t
#define mk_sl_cui_base_name mk_lang_bui_uchar
#define mk_sl_cui_base_bits (mk_lang_sizeof_bi_uchar_t * mk_lang_charbit)
#define mk_sl_cui_count 8
#define mk_sl_cui_endian mk_lang_endian_little
/*#include "mk_sl_cui_inl.h"*/
#include "mk_sl_cui_inl.c"

#define mk_lang_bui_div_bt mk_lang_bi_uchar_t
#define mk_lang_bui_div_bt2 mk_lang_bi_ushort_t
#define mk_lang_bui_div_bt3 mk_lang_bi_uint_t
#define mk_lang_bui_div_lena 8
#define mk_lang_bui_div_lenb 8
#define mk_lang_bui_div_endian mk_lang_endian_little
#define mk_lang_bui_div_alg 2
#define mk_lang_bui_div_name test
#include "mk_lang_bui_div_inl.h"
#include "mk_lang_bui_div_inl.c"

#include <string.h> /* memcpy */


mk_lang_jumbo void mk_lang_bui_div_test_fuzz(unsigned char const* const data, mk_lang_size_t const size)
{
	#if mk_lang_llong_has == 0
	((void)(data));
	((void)(size));
	#else

	#define test(x) if(!(x)) mk_lang_crash(); ((void)(0))

	#define check(x) if(!(x)) return; ((void)(0))
	#define check_data(x) check(d && s >= (x)); ((void)(0))

	unsigned char const* d;
	mk_lang_size_t s;
	mk_lang_ullong_t ul1a;
	mk_lang_ullong_t ul2a;
	mk_lang_ullong_t ul3a;
	mk_lang_ullong_t ul4a;
	mk_lang_ullong_t ul1b;
	mk_lang_ullong_t ul2b;
	mk_lang_ullong_t ul3b;
	mk_lang_ullong_t ul4b;
	mk_sl_cui_test_t cui1;
	mk_sl_cui_test_t cui2;
	mk_sl_cui_test_t cui3;
	mk_sl_cui_test_t cui4;

	d = data;
	s = size;
	check_data(2 * 8);
	ul1a = 0;
	memcpy(&ul1a, data + 0 * 8, 8);
	ul2a = 0;
	memcpy(&ul2a, data + 1 * 8, 8);
	if(ul2a == 0) return;
	ul3a = ul1a / ul2a;
	ul4a = ul1a % ul2a;
	ul1b = ul1a;
	ul2b = ul2a;
	mk_sl_cui_test_from_bi_ullong(&cui1, &ul1b);
	mk_sl_cui_test_from_bi_ullong(&cui2, &ul2b);
	mk_lang_bui_div_test(cui1.m_data, cui2.m_data, cui3.m_data, cui4.m_data);
	mk_sl_cui_test_to_bi_ullong(&cui3, &ul3b);
	mk_sl_cui_test_to_bi_ullong(&cui4, &ul4b);
	test(ul3b == ul3a);
	test(ul4b == ul4a);

	#undef check
	#undef check_data

	#undef test

	#endif
}
