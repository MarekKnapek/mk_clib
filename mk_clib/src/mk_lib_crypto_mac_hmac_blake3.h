#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_blake3_h
#define mk_include_guard_mk_lib_crypto_mac_hmac_blake3_h


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_hash_stream_blake3.h"


#define mk_lib_crypto_mac_hmac_t_name blake3
#include "mk_lib_crypto_mac_hmac_inl_fileh.h"
#include "mk_lib_crypto_mac_hmac_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_crypto_mac_hmac_blake3.c"
#endif
#endif
