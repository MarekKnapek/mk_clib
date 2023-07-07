#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf2_sha2_512_224
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf2_sha2_512_224


#include "mk_lib_crypto_mac_hmac_sha2_512_224.h"


#define mk_lib_crypto_kdf_pbkdf2_t_name sha2_512_224
#include "mk_lib_crypto_kdf_pbkdf2_inl_fileh.h"
#undef mk_lib_crypto_kdf_pbkdf2_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_kdf_pbkdf2_sha2_512_224.c"
#endif
#endif
