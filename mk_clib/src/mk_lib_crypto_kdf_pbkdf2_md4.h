#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf2_md4
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf2_md4


#include "mk_lib_crypto_mac_hmac_md4.h"


#define mk_lib_crypto_kdf_pbkdf2_t_name md4
#include "mk_lib_crypto_kdf_pbkdf2_inl_fileh.h"
#undef mk_lib_crypto_kdf_pbkdf2_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_kdf_pbkdf2_md4.c"
#endif
#endif
