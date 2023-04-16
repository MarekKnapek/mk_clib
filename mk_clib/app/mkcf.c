#include "../src/mk_clib_app_fuzz.h"
#include "../src/mk_lang_cpp.h"
#include "../src/mk_lang_sizet.h"


mk_lang_extern_c int LLVMFuzzerTestOneInput(unsigned char const* const data, mk_lang_size_t const size)
{
	return mk_clib_app_fuzz(data, size);
}

mk_lang_extern_c mk_lang_size_t LLVMFuzzerCustomMutator(unsigned char* const data, mk_lang_size_t const size, mk_lang_size_t const size_max, unsigned const seed)
{
	return mk_clib_app_fuzz_mutate(data, size, size_max, seed);
}
