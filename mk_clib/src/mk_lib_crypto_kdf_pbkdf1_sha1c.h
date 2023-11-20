#ifndef mk_include_guard_mk_lib_crypto_kdf_pbkdf1_sha1c
#define mk_include_guard_mk_lib_crypto_kdf_pbkdf1_sha1c


/* rfc 2898 */
/* pkcs #5 */


#include "mk_lib_crypto_hash_stream_sha1c.h"


#define mk_lib_crypto_kdf_pbkdf1_t_name sha1c
#include "mk_lib_crypto_kdf_pbkdf1_inl_fileh.h"
#undef mk_lib_crypto_kdf_pbkdf1_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_kdf_pbkdf1_sha1c.c"
#endif
#endif
