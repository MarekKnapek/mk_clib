#include "mk_clib_app_fuzz.h"

#include "mk_clib_fuzz.h"
#include "mk_clib_test.h"
#include "mk_lang_bool.h"
#include "mk_lang_cpp.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizet.h"


mk_lang_extern_c mk_lang_size_t LLVMFuzzerMutate(unsigned char* const data, mk_lang_size_t const size, mk_lang_size_t const size_max) mk_lang_noexcept;


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

mk_lang_jumbo mk_lang_size_t mk_clib_app_fuzz_mutate(unsigned char* const data, mk_lang_size_t const size, mk_lang_size_t const size_max, unsigned const seed) mk_lang_noexcept
{
	if((seed % 2u) == 0u)
	{
		return LLVMFuzzerMutate(data, size, size_max);
	}
	else
	{
		if(size == 0)
		{
			return 0;
		}
		else
		{
			return size - 1;
		}
	}
}
