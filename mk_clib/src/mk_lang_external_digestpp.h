#ifndef mk_include_guard_mk_lang_external_digestpp_h
#define mk_include_guard_mk_lang_external_digestpp_h


#include "mk_lang_jumbo.h"


#if defined mk_lang_external_digestpp_want
#if (mk_lang_external_digestpp_want) == 1
#define mk_lang_external_digestpp_wand 1
#elif (mk_lang_external_digestpp_want) == 0
#define mk_lang_external_digestpp_wand 0
#else
#error xxxxxxxxxx
#endif
#else
#define mk_lang_external_digestpp_wand 0
#endif


#if mk_lang_external_digestpp_wand
#if defined __cplusplus
#define mk_lang_external_digestpp_have 1
#else
#define mk_lang_external_digestpp_have 0
#endif
#else
#define mk_lang_external_digestpp_have 0
#endif


#if mk_lang_external_digestpp_have


#include "mk_lang_warning_msvc_push_everything.h"
#include "../external/digestpp/digestpp.hpp"
#include "mk_lang_warning_msvc_pop.h"


#endif


#if mk_lang_jumbo_have
#include "mk_lang_external_digestpp.c"
#endif
#endif
