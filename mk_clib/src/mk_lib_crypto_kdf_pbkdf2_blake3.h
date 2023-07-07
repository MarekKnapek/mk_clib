#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf2_blake3
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf2_blake3


#include "mk_lib_crypto_mac_hmac_blake3.h"


#define mk_lib_crypto_kdf_pbkdf2_t_name blake3
#include "mk_lib_crypto_kdf_pbkdf2_inl_fileh.h"
#undef mk_lib_crypto_kdf_pbkdf2_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_kdf_pbkdf2_blake3.c"
#endif
#endif
