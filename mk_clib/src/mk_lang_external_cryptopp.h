#ifndef mk_include_guard_mk_lang_external_cryptopp_h
#define mk_include_guard_mk_lang_external_cryptopp_h


#include "mk_lang_jumbo.h"


#if defined mk_lang_external_cryptopp_want
#if (mk_lang_external_cryptopp_want) == 1
#define mk_lang_external_cryptopp_have 1
#elif (mk_lang_external_cryptopp_want) == 0
#define mk_lang_external_cryptopp_have 0
#else
#error xxxxxxxxxx
#endif
#else
#define mk_lang_external_cryptopp_have 0
#endif


#if mk_lang_jumbo_have
#include "mk_lang_external_cryptopp.c"
#endif
#endif
