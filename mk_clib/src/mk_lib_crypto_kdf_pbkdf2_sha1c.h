#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf2_sha1c
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf2_sha1c


#include "mk_lib_crypto_mac_hmac_sha1c.h"


#define mk_lib_crypto_kdf_pbkdf2_t_name sha1c
#include "mk_lib_crypto_kdf_pbkdf2_inl_fileh.h"
#undef mk_lib_crypto_kdf_pbkdf2_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_kdf_pbkdf2_sha1c.c"
#endif
#endif
