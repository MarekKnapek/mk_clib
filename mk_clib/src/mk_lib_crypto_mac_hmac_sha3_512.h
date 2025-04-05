#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_sha3_512_h
#define mk_include_guard_mk_lib_crypto_mac_hmac_sha3_512_h


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_hash_stream_sha3_512.h"


#define mk_lib_crypto_mac_hmac_t_name sha3_512
#include "mk_lib_crypto_mac_hmac_inl_fileh.h"
#include "mk_lib_crypto_mac_hmac_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_crypto_mac_hmac_sha3_512.c"
#endif
#endif
