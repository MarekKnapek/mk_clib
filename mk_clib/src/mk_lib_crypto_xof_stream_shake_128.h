#ifndef mk_include_guard_mk_lib_crypto_xof_stream_shake_128
#define mk_include_guard_mk_lib_crypto_xof_stream_shake_128


#include "mk_lib_crypto_xof_block_shake_128.h"


#define mk_lib_crypto_xof_stream_t_name shake_128
#include "mk_lib_crypto_xof_stream_inl_fileh.h"
#undef mk_lib_crypto_xof_stream_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_xof_stream_shake_128.c"
#endif
#endif
