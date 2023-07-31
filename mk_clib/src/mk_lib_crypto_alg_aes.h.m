include(`mk_lang_concat.m')dnl
ifdef(`mk_lib_crypto_alg_aes_t_name', `', `define(`mk_lib_crypto_alg_aes_t_name', `mk_lib_crypto_alg_aes_t_key_bits')')dnl
define(`mk_lib_crypto_alg_aes_full_name', `mk_lang_concat(`mk_lib_crypto_alg_aes_', mk_lib_crypto_alg_aes_t_name)')dnl
define(`mk_lib_crypto_alg_aes_include_guard', `mk_lang_concat(`mk_include_guard_', mk_lib_crypto_alg_aes_full_name)')dnl
`#ifndef' mk_lib_crypto_alg_aes_include_guard
`#define' mk_lib_crypto_alg_aes_include_guard


/* NIST FIPS PUB 197 */


`#define mk_lib_crypto_alg_aes_t_key_bits' mk_lib_crypto_alg_aes_t_key_bits
`#define mk_lib_crypto_alg_aes_t_nr' mk_lib_crypto_alg_aes_t_nr


#include "mk_lang_jumbo.h"


include(mk_lib_crypto_alg_aes_inl_fileh.m)dnl


#undef mk_lib_crypto_alg_aes_t_key_bits
#undef mk_lib_crypto_alg_aes_t_nr


#if mk_lang_jumbo_want == 1
`#include' "mk_lib_crypto_alg_aes_full_name.c"
#endif
#endif
