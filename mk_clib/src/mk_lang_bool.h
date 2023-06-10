#ifndef mk_include_guard_mk_lang_bool
#define mk_include_guard_mk_lang_bool


#include "mk_lang_version.h"


#if defined __cplusplus
#define mk_lang_bool_t bool
#define mk_lang_true ((mk_lang_bool_t)(true))
#define mk_lang_false ((mk_lang_bool_t)(false))
#elif mk_lang_version_at_least_c_23
#define mk_lang_bool_t bool
#define mk_lang_true ((mk_lang_bool_t)(true))
#define mk_lang_false ((mk_lang_bool_t)(false))
#elif mk_lang_version_at_least_c_99
#define mk_lang_bool_t _Bool
#define mk_lang_true ((mk_lang_bool_t)(1))
#define mk_lang_false ((mk_lang_bool_t)(0))
#else
#define mk_lang_bool_t int
#define mk_lang_true ((mk_lang_bool_t)(1))
#define mk_lang_false ((mk_lang_bool_t)(0))
#endif


#endif
