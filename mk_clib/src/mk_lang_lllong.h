#ifndef mk_include_guard_mk_lang_lllong_h
#define mk_include_guard_mk_lang_lllong_h


#include "mk_lang_arch.h"


#if defined mk_lang_disable_lllong_want
#if (mk_lang_disable_lllong_want) == 0
#define mk_lang_disable_lllong_have 0
#elif (mk_lang_disable_lllong_want) == 1
#define mk_lang_disable_lllong_have 1
#else
#error xxxxxxxxxx
#endif
#else
#define mk_lang_disable_lllong_have 0
#endif


#if !mk_lang_disable_lllong_have
#if defined __SIZEOF_INT128__
#if (__SIZEOF_INT128__) != 0  && !mk_lang_arch_is_emscripten
#define mk_lang_lllong_has 1
#define mk_lang_ulllong_t unsigned __int128
#define mk_lang_slllong_t signed __int128
#endif
#endif
#endif

#if !defined mk_lang_lllong_has
#include "mk_lang_llong.h"
#define mk_lang_lllong_has 0
#define mk_lang_ulllong_t mk_lang_ullong_t
#define mk_lang_slllong_t mk_lang_sllong_t
#endif


#endif
