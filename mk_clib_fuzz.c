#include "mk_clib_fuzz.h"

#include "mk_clib_test.h"
#include "mk_lang_bool.h"


static mk_lang_bool_t g_clib_fuzz_once = mk_lang_false;


mk_lang_jumbo void mk_clib_fuzz(unsigned char const* const data, mk_lang_size_t const size)
{
	if(!g_clib_fuzz_once)
	{
		g_clib_fuzz_once = mk_lang_true;
		mk_clib_test();
	}
	mk_clib_test_fuzz(data, size);
}
