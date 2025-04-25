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


#if defined _MSC_VER && defined _MSC_FULL_VER
#pragma warning(push, 0)
#endif


#include "mk_lang_arch.h"

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
#include "../external/libtomcrypt/tomcrypt.h"


#if defined _MSC_VER && defined _MSC_FULL_VER
#if mk_lang_arch == mk_lang_arch_x8664
#if defined DEBUG || defined _DEBUG
#pragma comment(lib, "../../../external/build/out/amd64/debug/ltc.lib")
#elif defined NDEBUG || defined _NDEBUG
#pragma comment(lib, "../../../external/build/out/amd64/release/ltc.lib")
#else
#error xxxxxxxxxx
#endif
#elif mk_lang_arch == mk_lang_arch_x8632
#if defined DEBUG || defined _DEBUG
#pragma comment(lib, "../../../external/build/out/i386/debug/ltc.lib")
#elif defined NDEBUG || defined _NDEBUG
#pragma comment(lib, "../../../external/build/out/i386/release/ltc.lib")
#else
#error xxxxxxxxxx
#endif
#else
#error xxxxxxxxxx
#endif
#endif


#if defined _MSC_VER && defined _MSC_FULL_VER
#pragma warning(pop)
#endif


#endif


#if mk_lang_jumbo_have
#include "mk_lang_external_ltc.c"
#endif
#endif
