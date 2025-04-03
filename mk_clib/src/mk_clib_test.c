#ifndef mk_include_guard_mk_clib_test_c
#define mk_include_guard_mk_clib_test_c
#include "mk_clib_test.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include "mk_lang_sizeof_test.h"
#include "mk_lib_crypto_hash_stream_md2_test.hpp"


mk_lang_jumbo mk_lang_types_void_t mk_clib_test(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_sizeof_test();
	mk_lib_crypto_hash_stream_md2_test();
}


#endif
