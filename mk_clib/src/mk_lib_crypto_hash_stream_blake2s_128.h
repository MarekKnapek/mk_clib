#ifndef mk_include_guard_mk_lib_crypto_hash_stream_blake2s_128_h
#define mk_include_guard_mk_lib_crypto_hash_stream_blake2s_128_h


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_hash_block_blake2s_128.h"


#define mk_lib_crypto_hash_stream_t_name blake2s_128
#define mk_lib_crypto_hash_stream_t_padding 0
#include "mk_lib_crypto_hash_stream_inl_fileh.h"
#include "mk_lib_crypto_hash_stream_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_crypto_hash_stream_blake2s_128.c"
#endif
#endif
