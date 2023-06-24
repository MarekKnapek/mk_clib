#ifndef mk_include_guard_mk_lib_crypto_hash_stream_blake2b_base
#define mk_include_guard_mk_lib_crypto_hash_stream_blake2b_base


#include "mk_lib_crypto_hash_block_blake2b_base.h"


#define mk_lib_crypto_hash_stream_blake2_t_name blake2b_base
#include "mk_lib_crypto_hash_stream_blake2_inl_fileh.h"
#undef mk_lib_crypto_hash_stream_blake2_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_stream_blake2b_base.c"
#endif
#endif
