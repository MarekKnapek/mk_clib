#ifndef mk_include_guard_mk_lang_external_ltc_h
#define mk_include_guard_mk_lang_external_ltc_h


#include "mk_lang_jumbo.h"


#if defined mk_lang_external_ltc_want
#if (mk_lang_external_ltc_want) == 1
#define mk_lang_external_ltc_have 1
#elif (mk_lang_external_ltc_want) == 0
#define mk_lang_external_ltc_have 0
#else
#error xxxxxxxxxx
#endif
#else
#define mk_lang_external_ltc_have 0
#endif


#if mk_lang_external_ltc_have


#include "mk_lang_arch.h"
#include "mk_lang_compiler.h"
#include "mk_lang_configuration.h"


#define LTC_BLAKE2B
#define LTC_BLAKE2S
#define LTC_MD2
#define LTC_MD4
#define LTC_MD5
#define LTC_SHA1
#define LTC_SHA224
#define LTC_SHA256
#define LTC_SHA3
#define LTC_SHA512
#define LTC_TIGER
#define LTC_WHIRLPOOL
#define LTC_CHACHA20_PRNG
#define LTC_CURVE25519
#define ARGTYPE 3
#include "mk_lang_warning_msvc_push_everything.h"
#include "../external/libtomcrypt/src/headers/tomcrypt.h"
#include "mk_lang_warning_msvc_pop.h"


#if mk_lang_compiler_is_msvc
#if mk_lang_arch_is_x8664
#if mk_lang_configuration_is_debug
#pragma comment(lib, "../../../external/build/out/amd64/debug/ltc.lib")
#elif mk_lang_configuration_is_release
#pragma comment(lib, "../../../external/build/out/amd64/release/ltc.lib")
#else
#error xxxxxxxxxx
#endif
#elif mk_lang_arch_is_x8632
#if mk_lang_configuration_is_debug
#pragma comment(lib, "../../../external/build/out/i386/debug/ltc.lib")
#elif mk_lang_configuration_is_release
#pragma comment(lib, "../../../external/build/out/i386/release/ltc.lib")
#else
#error xxxxxxxxxx
#endif
#else
#error xxxxxxxxxx
#endif
#endif


#endif


#if mk_lang_jumbo_have
#include "mk_lang_external_ltc.c"
#endif
#endif
