#ifndef mk_include_guard_mk_lang_jumbo_h
#define mk_include_guard_mk_lang_jumbo_h


#if defined mk_lang_jumbo_want && (mk_lang_jumbo_want) == 0
#define mk_lang_jumbo_variant 0
#elif defined mk_lang_jumbo_want && (mk_lang_jumbo_want) == 1
#define mk_lang_jumbo_variant 1
#elif defined mk_lang_jumbo_want && (mk_lang_jumbo_want) == 2
#define mk_lang_jumbo_variant 2
#elif !defined mk_lang_jumbo_variant
#if defined DEBUG || defined _DEBUG
#define mk_lang_jumbo_variant 0
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_jumbo_variant 1
#else
#define mk_lang_jumbo_variant 0
#endif
#endif
#else
#error xxxxxxxxxx
#endif





#if mk_lang_jumbo_variant == 0


#define mk_lang_jumbo_have 0
#define mk_lang_jumbo


#elif mk_lang_jumbo_variant == 1


#include "mk_lang_inline.h"

#define mk_lang_jumbo_have 1
#define mk_lang_jumbo static mk_lang_inline


#elif mk_lang_jumbo_variant == 2


#include "mk_lang_inline.h"

#define mk_lang_jumbo_have 1
#define mk_lang_jumbo mk_lang_inline


#else


#error xxxxxxxxxx


#endif





#endif
