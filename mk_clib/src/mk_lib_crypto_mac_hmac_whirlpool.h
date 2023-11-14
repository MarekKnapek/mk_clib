#ifndef mk_include_guard_mk_lib_crypto_mac_hmac_whirlpool
#define mk_include_guard_mk_lib_crypto_mac_hmac_whirlpool


#include "mk_lib_crypto_hash_stream_whirlpool.h"


#define mk_lib_crypto_mac_hmac_t_name whirlpool
#include "mk_lib_crypto_mac_hmac_inl_fileh.h"
#undef mk_lib_crypto_mac_hmac_t_name


#if mk_lang_jumbo_want == 1
#include "mk_lib_crypto_mac_hmac_whirlpool.c"
#endif
#endif
