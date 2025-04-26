#ifndef mk_include_guard_mk_lib_crypto_alg_aes_x86_vaes256_128_h
#define mk_include_guard_mk_lib_crypto_alg_aes_x86_vaes256_128_h


#include "mk_lang_charbit.h"
#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_alg_aes_x86_tech.h"


#define mk_lib_crypto_alg_aes_x86_t_name mk_lib_crypto_alg_aes_x86_vaes256_128
#define mk_lib_crypto_alg_aes_x86_t_bits 128
#define mk_lib_crypto_alg_aes_x86_t_tech mk_lib_crypto_alg_aes_x86_tech_vaes256
#include "mk_lib_crypto_alg_aes_x86_inl_fileh.h"
#include "mk_lib_crypto_alg_aes_x86_inl_fileu.h"
#define mk_lib_crypto_alg_aes_x86_vaes256_128_key_len_d (128 / mk_lang_charbit)
#define mk_lib_crypto_alg_aes_x86_vaes256_128_msg_len_d (128 / mk_lang_charbit)
#define mk_lib_crypto_alg_aes_x86_vaes256_128_schedule_len_d ((10 + 1) * mk_lib_crypto_alg_aes_x86_vaes256_128_msg_len_d)


#if mk_lang_jumbo_have
#include "mk_lib_crypto_alg_aes_x86_vaes256_128.c"
#endif
#endif
