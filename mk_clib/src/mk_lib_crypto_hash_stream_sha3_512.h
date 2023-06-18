#ifndef mk_include_guard_mk_lib_crypto_hash_stream_sha3_512
#define mk_include_guard_mk_lib_crypto_hash_stream_sha3_512


#include "mk_lib_crypto_hash_block_sha3_512.h"


#define mk_lib_crypto_hash_stream_t_name sha3_512
#include "mk_lib_crypto_hash_stream_inl_fileh.h"
#undef mk_lib_crypto_hash_stream_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_stream_sha3_512.c"
#endif
#endif
