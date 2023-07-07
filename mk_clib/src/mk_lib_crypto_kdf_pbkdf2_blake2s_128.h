#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf2_blake2s_128
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf2_blake2s_128


#include "mk_lib_crypto_mac_hmac_blake2s_128.h"


#define mk_lib_crypto_kdf_pbkdf2_t_name blake2s_128
#include "mk_lib_crypto_kdf_pbkdf2_inl_fileh.h"
#undef mk_lib_crypto_kdf_pbkdf2_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_kdf_pbkdf2_blake2s_128.c"
#endif
#endif
