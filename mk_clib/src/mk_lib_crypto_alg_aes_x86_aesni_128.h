#ifndef mk_include_guard_mk_lib_crypto_alg_aes_x86_aesni_128
#define mk_include_guard_mk_lib_crypto_alg_aes_x86_aesni_128


#include "mk_lang_jumbo.h"

#define mk_lib_crypto_alg_aes_x86_t_name mk_lib_crypto_alg_aes_x86_aesni_128
#define mk_lib_crypto_alg_aes_x86_t_bits 128
#define mk_lib_crypto_alg_aes_x86_t_tech 3
#include "mk_lib_crypto_alg_aes_x86_inl_fileh.h"
#undef mk_lib_crypto_alg_aes_x86_t_name
#undef mk_lib_crypto_alg_aes_x86_t_bits
#undef mk_lib_crypto_alg_aes_x86_t_tech


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_alg_aes_x86_aesni_128.c"
#endif
#endif
