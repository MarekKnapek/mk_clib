#ifndef mk_include_guard_mk_lib_crypto_hash_stream_sha0
#define mk_include_guard_mk_lib_crypto_hash_stream_sha0


#include "mk_lib_crypto_hash_block_sha0.h"


#define mk_lib_crypto_hash_stream_t_name sha0
#include "mk_lib_crypto_hash_stream_inl_fileh.h"
#undef mk_lib_crypto_hash_stream_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_stream_sha0.c"
#endif
#endif
