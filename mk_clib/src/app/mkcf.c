#include "../mk_clib_app_fuzz.h"
#include "../mk_lang_cpp.h"
#include "../mk_lang_sizet.h"


mk_lang_extern_c int LLVMFuzzerTestOneInput(unsigned char const* data, mk_lang_size_t size)
{
	return mk_clib_app_fuzz(data, size);
}
