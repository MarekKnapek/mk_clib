#ifndef mk_include_guard_mk_lang_extern_h
#define mk_include_guard_mk_lang_extern_h


#include "mk_lang_jumbo.h"


#if mk_lang_jumbo_variant != 1
#if defined __cplusplus
#define mk_lang_extern_c extern "C"
#else
#define mk_lang_extern_c extern
#endif
#else
#define mk_lang_extern_c
#endif

#if defined __cplusplus
#define mk_lang_extern_force_c extern "C"
#else
#define mk_lang_extern_force_c extern
#endif

#if defined __cplusplus
#define mk_lang_extern_force_cpp extern
#else
#define mk_lang_extern_force_cpp xxxxxxxxxx
#endif


#endif
