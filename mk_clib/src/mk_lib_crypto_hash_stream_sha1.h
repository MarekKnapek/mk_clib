#ifndef mk_include_guard_mk_lib_crypto_hash_stream_sha1
#define mk_include_guard_mk_lib_crypto_hash_stream_sha1


#include "mk_lib_crypto_hash_block_sha1.h"


#define mk_lib_crypto_hash_stream_t_name sha1
#include "mk_lib_crypto_hash_stream_inl_fileh.h"
#undef mk_lib_crypto_hash_stream_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_stream_sha1.c"
#endif
#endif
