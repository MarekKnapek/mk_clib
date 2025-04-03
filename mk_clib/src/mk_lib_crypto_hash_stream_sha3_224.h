#ifndef mk_include_guard_mk_lib_crypto_hash_stream_sha3_224_h
#define mk_include_guard_mk_lib_crypto_hash_stream_sha3_224_h


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_hash_block_sha3_224.h"


#define mk_lib_crypto_hash_stream_t_name sha3_224
#include "mk_lib_crypto_hash_stream_inl_fileh.h"
#include "mk_lib_crypto_hash_stream_inl_fileu.h"


#if mk_lang_jumbo_have == 1
#include "mk_lib_crypto_hash_stream_sha3_224.c"
#endif
#endif
