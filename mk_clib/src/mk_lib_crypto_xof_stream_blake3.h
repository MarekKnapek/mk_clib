#ifndef mk_include_guard_mk_lib_crypto_xof_stream_blake3_h
#define mk_include_guard_mk_lib_crypto_xof_stream_blake3_h


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_xof_block_blake3.h"


#define mk_lib_crypto_xof_stream_t_name blake3
#define mk_lib_crypto_xof_stream_t_padding 0
#include "mk_lib_crypto_xof_stream_inl_fileh.h"
#include "mk_lib_crypto_xof_stream_inl_fileu.h"


#if mk_lang_jumbo_have == 1
#include "mk_lib_crypto_xof_stream_blake3.c"
#endif
#endif
