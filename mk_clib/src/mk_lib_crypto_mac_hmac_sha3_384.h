#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_sha3_384
#define mk_include_guard_mk_lib_crypto_mac_hmac_sha3_384


#include "mk_lib_crypto_hash_stream_sha3_384.h"


#define mk_lib_crypto_mac_hmac_t_name sha3_384
#include "mk_lib_crypto_mac_hmac_inl_fileh.h"
#undef mk_lib_crypto_mac_hmac_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_mac_hmac_sha3_384.c"
#endif
#endif
