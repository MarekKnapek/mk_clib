#ifndef mk_include_guard_mk_lang_external_cryptopp_c
#define mk_include_guard_mk_lang_external_cryptopp_c
#include "mk_lang_external_cryptopp.h"

#include "mk_lang_arch.h"
#include "mk_lang_configuration.h"
#include "mk_lang_msvc.h"


#if mk_lang_external_cryptopp_have


#if mk_lang_msvc_ver != 0
#if mk_lang_configuration_is_debug && mk_lang_arch_is_x8632
#pragma comment(lib, "..\\..\\..\\external\\cryptopp\\Win32\\DLL_Output\\Debug\\cryptopp.lib")
#elif mk_lang_configuration_is_release && mk_lang_arch_is_x8632
#pragma comment(lib, "cryptlib.lib")
#elif mk_lang_configuration_is_debug && mk_lang_arch_is_x8664
#pragma comment(lib, "..\\..\\..\\external\\cryptopp\\x64\\DLL_Output\\Debug\\cryptopp.lib")
#elif mk_lang_configuration_is_release && mk_lang_arch_is_x8664
#pragma comment(lib, "cryptlib.lib")
#else
#error xxxxxxxxxx
#endif
#endif


#include "mk_lang_warning_msvc_push_c4505.h"
static void mk_lang_external_cryptopp_dummy(void){}
#include "mk_lang_warning_msvc_pop.h"


#else


#include "mk_lang_warning_msvc_push_c4505.h"
static void mk_lang_external_cryptopp_dummy(void){}
#include "mk_lang_warning_msvc_pop.h"


#endif


#endif
