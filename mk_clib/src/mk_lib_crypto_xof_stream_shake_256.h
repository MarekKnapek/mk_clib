#ifndef mk_include_guard_mk_lib_crypto_xof_stream_shake_256
#define mk_include_guard_mk_lib_crypto_xof_stream_shake_256


#include "mk_lib_crypto_xof_block_shake_256.h"


#define mk_lib_crypto_xof_stream_t_name shake_256
#include "mk_lib_crypto_xof_stream_inl_fileh.h"
#undef mk_lib_crypto_xof_stream_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_xof_stream_shake_256.c"
#endif
#endif
