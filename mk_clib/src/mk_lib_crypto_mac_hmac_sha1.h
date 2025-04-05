#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_sha1_h
#define mk_include_guard_mk_lib_crypto_mac_hmac_sha1_h


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_hash_stream_sha1.h"


#define mk_lib_crypto_mac_hmac_t_name sha1
#include "mk_lib_crypto_mac_hmac_inl_fileh.h"
#include "mk_lib_crypto_mac_hmac_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_crypto_mac_hmac_sha1.c"
#endif
#endif
