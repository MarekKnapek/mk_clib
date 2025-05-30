#ifndef mk_include_guard_mk_lib_crypto_xof_stream_turbo_shake_256_h
#define mk_include_guard_mk_lib_crypto_xof_stream_turbo_shake_256_h


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_xof_block_turbo_shake_256.h"


#define mk_lib_crypto_xof_stream_t_name turbo_shake_256
#include "mk_lib_crypto_xof_stream_inl_fileh.h"
#include "mk_lib_crypto_xof_stream_inl_fileu.h"


#if mk_lang_jumbo_have == 1
#include "mk_lib_crypto_xof_stream_turbo_shake_256.c"
#endif
#endif
