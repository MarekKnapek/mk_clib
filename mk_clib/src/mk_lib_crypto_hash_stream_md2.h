#ifndef mk_include_guard_mk_lib_crypto_hash_stream_md2
#define mk_include_guard_mk_lib_crypto_hash_stream_md2


#include "mk_lib_crypto_hash_block_md2.h"


#define mk_lib_crypto_hash_stream_t_name md2
#include "mk_lib_crypto_hash_stream_inl_fileh.h"
#undef mk_lib_crypto_hash_stream_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_stream_md2.c"
#endif
#endif
