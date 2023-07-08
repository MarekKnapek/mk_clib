#ifndef mk_include_guard_mk_lib_crypto_mode_ofb_aes_256
#define mk_include_guard_mk_lib_crypto_mode_ofb_aes_256


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_alg_aes_256.h"


#define mk_lib_crypto_mode_ofb_t_alg aes_256
#include "mk_lib_crypto_mode_ofb_inl_fileh.h"
#undef mk_lib_crypto_mode_ofb_t_alg


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_mode_ofb_aes_256.c"
#endif
#endif
