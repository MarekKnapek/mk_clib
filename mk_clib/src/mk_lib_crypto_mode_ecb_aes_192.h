#ifndef mk_include_guard_mk_lib_crypto_mode_ecb_aes_192
#define mk_include_guard_mk_lib_crypto_mode_ecb_aes_192


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_alg_aes_192.h"


#define mk_lib_crypto_mode_ecb_t_alg aes_192
#include "mk_lib_crypto_mode_ecb_inl_fileh.h"
#undef mk_lib_crypto_mode_ecb_t_alg


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_mode_ecb_aes_192.c"
#endif
#endif
