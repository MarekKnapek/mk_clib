#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf2_sha0
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf2_sha0


#include "mk_lib_crypto_mac_hmac_sha0.h"


#define mk_lib_crypto_kdf_pbkdf2_t_name sha0
#include "mk_lib_crypto_kdf_pbkdf2_inl_fileh.h"
#undef mk_lib_crypto_kdf_pbkdf2_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_kdf_pbkdf2_sha0.c"
#endif
#endif
