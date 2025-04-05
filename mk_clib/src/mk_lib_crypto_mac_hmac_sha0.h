#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_sha0_h
#define mk_include_guard_mk_lib_crypto_mac_hmac_sha0_h


#include "mk_lang_jumbo.h"
#include "mk_lib_crypto_hash_stream_sha0.h"


#define mk_lib_crypto_mac_hmac_t_name sha0
#include "mk_lib_crypto_mac_hmac_inl_fileh.h"
#include "mk_lib_crypto_mac_hmac_inl_fileu.h"


#if mk_lang_jumbo_have
#include "mk_lib_crypto_mac_hmac_sha0.c"
#endif
#endif
