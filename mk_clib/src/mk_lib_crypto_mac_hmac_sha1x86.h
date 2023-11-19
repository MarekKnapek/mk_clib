#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_sha1x86
#define mk_include_guard_mk_lib_crypto_mac_hmac_sha1x86


#include "mk_lib_crypto_hash_stream_sha1x86.h"


#define mk_lib_crypto_mac_hmac_t_name sha1x86
#include "mk_lib_crypto_mac_hmac_inl_fileh.h"
#undef mk_lib_crypto_mac_hmac_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_mac_hmac_sha1x86.c"
#endif
#endif
