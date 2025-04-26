#ifndef mk_include_guard_mk_lib_crypto_hash_stream_tiger2_128_h
#define mk_include_guard_mk_lib_crypto_hash_stream_tiger2_128_h


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_hash_block_tiger2_128.h"


#define mk_lib_crypto_hash_stream_t_name tiger2_128
#include "mk_lib_crypto_hash_stream_inl_fileh.h"
#include "mk_lib_crypto_hash_stream_inl_fileu.h"


#if mk_lang_jumbo_have == 1
#include "mk_lib_crypto_hash_stream_tiger2_128.c"
#endif
#endif
