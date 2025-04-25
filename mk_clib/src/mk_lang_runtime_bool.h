#ifndef mk_include_guard_mk_lang_runtime_bool_h
#define mk_include_guard_mk_lang_runtime_bool_h


#if defined mk_lang_runtime_bool_want && (mk_lang_runtime_bool_want) == 1
#define mk_lang_runtime_bool_have 1
#elif defined mk_lang_runtime_bool_want && (mk_lang_runtime_bool_want) == 0
#define mk_lang_runtime_bool_have 0
#elif !defined mk_lang_runtime_bool_want
#if defined DEBUG || defined _DEBUG
#define mk_lang_runtime_bool_have 1
#else
#if defined NDEBUG || defined _NDEBUG
#define mk_lang_runtime_bool_have 0
#else
#define mk_lang_runtime_bool_have 1
#endif
#endif
#else
#error xxxxxxxxxx
#endif





#include "mk_lang_bool.h"
#include "mk_lang_jumbo.h"


#if mk_lang_runtime_bool_have


static mk_lang_bool_t const mk_lang_runtime_bool_c_false = mk_lang_false;


#define mk_lang_runtime_bool_fn_false mk_lang_runtime_bool_c_false


#else


#define mk_lang_runtime_bool_fn_false mk_lang_false


#endif


#define mk_lang_runtime_bool_fn_true (!mk_lang_runtime_bool_fn_false)





#if mk_lang_jumbo_have
#include "mk_lang_runtime_bool.c"
#endif
#endif
