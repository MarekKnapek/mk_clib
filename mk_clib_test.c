#include "mk_clib_test.h"

#include "mk_lang_bi_test.h"
#include "mk_lang_bui_div_test.h"
#include "mk_lang_bui_test.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_sizeof_test.h"
#include "mk_lang_sizet.h"
#include "mk_sl_cui_test.h"


mk_lang_jumbo void mk_clib_test(void)
{
	mk_lang_bi_test();
	mk_lang_bui_test();
	mk_lang_sizeof_test();
	mk_sl_cui_test();
}

mk_lang_jumbo void mk_clib_test_fuzz(unsigned char const* const data, mk_lang_size_t const size)
{
	mk_lang_bui_div_test_fuzz(data, size);
	mk_lang_bui_test_fuzz(data, size);
	mk_sl_cui_test_fuzz(data, size);
}
