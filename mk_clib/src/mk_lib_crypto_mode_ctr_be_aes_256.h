#ifndef mk_include_guard_mk_lib_crypto_mode_ctr_be_aes_256
#define mk_include_guard_mk_lib_crypto_mode_ctr_be_aes_256


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_alg_aes_256.h"


#define mk_lib_crypto_mode_ctr_be_t_alg aes_256
#include "mk_lib_crypto_mode_ctr_be_inl_fileh.h"
#undef mk_lib_crypto_mode_ctr_be_t_alg


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_mode_ctr_be_aes_256.c"
#endif
#endif
