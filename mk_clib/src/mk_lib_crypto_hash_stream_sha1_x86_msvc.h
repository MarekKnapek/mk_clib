#ifndef mk_include_guard_mk_lib_crypto_hash_stream_sha1_x86_msvc
#define mk_include_guard_mk_lib_crypto_hash_stream_sha1_x86_msvc


#include "mk_lib_crypto_hash_block_sha1_x86_msvc.h"


#define mk_lib_crypto_hash_stream_t_name sha1_x86_msvc
#include "mk_lib_crypto_hash_stream_inl_fileh.h"
#undef mk_lib_crypto_hash_stream_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_hash_stream_sha1_x86_msvc.c"
#endif
#endif
