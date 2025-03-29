#ifndef mk_include_guard_mk_clib_test_c
#define mk_include_guard_mk_clib_test_c
#include "mk_clib_test.h"

#include "mk_lang_jumbo.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_types.h"

#include "mk_lang_sizeof_test.h"
#include "mk_lib_crypto_hash_stream_md2_test.hpp"
#include "mk_lib_crypto_hash_stream_md4_test.hpp"
#include "mk_lib_crypto_hash_stream_md5_test.hpp"
#include "mk_lib_crypto_hash_stream_sha0_test.hpp"
#include "mk_lib_crypto_hash_stream_sha1_test.hpp"
#include "mk_lib_crypto_hash_stream_sha2_224_test.hpp"
#include "mk_lib_crypto_hash_stream_sha2_256_test.hpp"
#include "mk_lib_crypto_hash_stream_sha2_384_test.hpp"
#include "mk_lib_crypto_hash_stream_sha2_512_224_test.hpp"
#include "mk_lib_crypto_hash_stream_sha2_512_256_test.hpp"
#include "mk_lib_crypto_hash_stream_sha2_512_test.hpp"
#include "mk_lib_crypto_hash_stream_sha3_224_test.hpp"


mk_lang_jumbo mk_lang_types_void_t mk_clib_test(mk_lang_types_void_t) mk_lang_noexcept
{
	mk_lang_sizeof_test();
	mk_lib_crypto_hash_stream_md2_test();
	mk_lib_crypto_hash_stream_md4_test();
	mk_lib_crypto_hash_stream_md5_test();
	mk_lib_crypto_hash_stream_sha0_test();
	mk_lib_crypto_hash_stream_sha1_test();
	mk_lib_crypto_hash_stream_sha2_224_test();
	mk_lib_crypto_hash_stream_sha2_256_test();
	mk_lib_crypto_hash_stream_sha2_384_test();
	mk_lib_crypto_hash_stream_sha2_512_224_test();
	mk_lib_crypto_hash_stream_sha2_512_256_test();
	mk_lib_crypto_hash_stream_sha2_512_test();
	mk_lib_crypto_hash_stream_sha3_224_test();
}


#endif
