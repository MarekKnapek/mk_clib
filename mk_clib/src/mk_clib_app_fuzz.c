#include "mk_clib_app_fuzz.h"

#include "mk_clib_fuzz.h"
#include "mk_clib_test.h"
#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


static mk_lang_bool_t g_clib_app_fuzz_once = mk_lang_false;


mk_lang_jumbo int mk_clib_app_fuzz(unsigned char const* const data, mk_lang_size_t const size) mk_lang_noexcept
{
	if(!g_clib_app_fuzz_once)
	{
		g_clib_app_fuzz_once = mk_lang_true;
		mk_clib_test();
	}
	mk_clib_fuzz(data, size);
	return 0;
}
