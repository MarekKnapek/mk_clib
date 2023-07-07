#include "mk_clib_test.h"

#include "mk_lang_alignof_test.h"
#include "mk_lang_bi_test.h"
#include "mk_lang_constexpr_test.hpp"
#include "mk_lang_exception_test.h"
#include "mk_lang_jumbo.h"
#include "mk_lang_limits_test.h"
#include "mk_lang_noexcept.h"
#include "mk_lang_sizeof_test.h"
#include "mk_lib_crypto_alg_aes_128_test.hpp"
#include "mk_lib_crypto_hash_stream_blake2b_256_test.hpp"
#include "mk_lib_crypto_hash_stream_blake2b_384_test.hpp"
#include "mk_lib_crypto_hash_stream_blake2b_512_test.hpp"
#include "mk_lib_crypto_hash_stream_blake2s_128_test.hpp"
#include "mk_lib_crypto_hash_stream_blake2s_160_test.hpp"
#include "mk_lib_crypto_hash_stream_blake2s_224_test.hpp"
#include "mk_lib_crypto_hash_stream_blake2s_256_test.hpp"
#include "mk_lib_crypto_hash_stream_blake3_test.hpp"
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
#include "mk_lib_crypto_hash_stream_sha3_256_test.hpp"
#include "mk_lib_crypto_hash_stream_sha3_384_test.hpp"
#include "mk_lib_crypto_hash_stream_sha3_512_test.hpp"
#include "mk_lib_crypto_hash_stream_tiger2_128_test.hpp"
#include "mk_lib_crypto_hash_stream_tiger2_160_test.hpp"
#include "mk_lib_crypto_hash_stream_tiger2_192_test.hpp"
#include "mk_lib_crypto_hash_stream_tiger_128_test.hpp"
#include "mk_lib_crypto_hash_stream_tiger_160_test.hpp"
#include "mk_lib_crypto_hash_stream_tiger_192_test.hpp"
#include "mk_lib_crypto_kdf_pbkdf1_sha1_test.hpp"
#include "mk_lib_crypto_xof_stream_shake_128_test.hpp"
#include "mk_lib_crypto_xof_stream_shake_256_test.hpp"
#include "mk_sl_flt_test.hpp"
#include "mk_sl_sort_merge_test.hpp"


mk_lang_jumbo void mk_clib_test(void) mk_lang_noexcept
{
	mk_lang_alignof_test();
	mk_lang_bi_test();
	mk_lang_constexpr_test();
	mk_lang_exception_test();
	mk_lang_limits_test();
	mk_lang_sizeof_test();
	mk_lib_crypto_alg_aes_128_test();
	mk_lib_crypto_hash_stream_blake2b_256_test();
	mk_lib_crypto_hash_stream_blake2b_384_test();
	mk_lib_crypto_hash_stream_blake2b_512_test();
	mk_lib_crypto_hash_stream_blake2s_128_test();
	mk_lib_crypto_hash_stream_blake2s_160_test();
	mk_lib_crypto_hash_stream_blake2s_224_test();
	mk_lib_crypto_hash_stream_blake2s_256_test();
	mk_lib_crypto_hash_stream_blake3_test();
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
	mk_lib_crypto_hash_stream_sha3_256_test();
	mk_lib_crypto_hash_stream_sha3_384_test();
	mk_lib_crypto_hash_stream_sha3_512_test();
	mk_lib_crypto_hash_stream_tiger2_128_test();
	mk_lib_crypto_hash_stream_tiger2_160_test();
	mk_lib_crypto_hash_stream_tiger2_192_test();
	mk_lib_crypto_hash_stream_tiger_128_test();
	mk_lib_crypto_hash_stream_tiger_160_test();
	mk_lib_crypto_hash_stream_tiger_192_test();
	mk_lib_crypto_kdf_pbkdf1_sha1_test();
	mk_lib_crypto_xof_stream_shake_128_test();
	mk_lib_crypto_xof_stream_shake_256_test();
	mk_sl_flt_test();
	mk_sl_sort_merge_test();
}
