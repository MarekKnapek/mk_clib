#ifndef mk_include_guard_mk_lang_external_zlib_h
#define mk_include_guard_mk_lang_external_zlib_h


#include "mk_lang_jumbo.h"


#if defined mk_lang_external_zlib_want
#if (mk_lang_external_zlib_want) == 1
#define mk_lang_external_zlib_have 1
#elif (mk_lang_external_zlib_want) == 0
#define mk_lang_external_zlib_have 0
#else
#error xxxxxxxxxx
#endif
#else
#define mk_lang_external_zlib_have 0
#endif


#if mk_lang_external_zlib_have


#include "mk_lang_arch.h"


#if defined _MSC_VER && defined _MSC_FULL_VER
#pragma warning(push, 0)
#endif
/*#include "../external/zlib/zlib.h"*/
#if defined _MSC_VER && defined _MSC_FULL_VER
#pragma warning(pop)
#endif


#if defined _MSC_VER && defined _MSC_FULL_VER
#if mk_lang_arch == mk_lang_arch_x8664
#if defined DEBUG || defined _DEBUG
#pragma comment(lib, "../../../external/build/out/amd64/debug/zlib.lib")
#elif defined NDEBUG || defined _NDEBUG
/*#pragma comment(lib, "../../../external/build/out/amd64/release/zlib.lib")*/
#else
#error xxxxxxxxxx
#endif
#elif mk_lang_arch == mk_lang_arch_x8632
#if defined DEBUG || defined _DEBUG
#pragma comment(lib, "../../../external/build/out/i386/debug/zlib.lib")
#elif defined NDEBUG || defined _NDEBUG
/*#pragma comment(lib, "../../../external/build/out/i386/release/zlib.lib")*/
#else
#error xxxxxxxxxx
#endif
#else
#error xxxxxxxxxx
#endif
#endif


#endif


#if mk_lang_jumbo_have
#include "mk_lang_external_zlib.c"
#endif
#endif
