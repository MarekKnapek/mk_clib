#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_sha1_c
#define mk_include_guard_mk_lib_crypto_mac_hmac_sha1_c


#include "mk_lib_crypto_hash_stream_sha1_c.h"


#define mk_lib_crypto_mac_hmac_t_name sha1_c
#include "mk_lib_crypto_mac_hmac_inl_fileh.h"
#undef mk_lib_crypto_mac_hmac_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_mac_hmac_sha1_c.c"
#endif
#endif
