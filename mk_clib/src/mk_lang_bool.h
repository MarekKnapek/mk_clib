#ifndef mk_include_guard_mk_lang_bool_h
#define mk_include_guard_mk_lang_bool_h


#include "mk_lang_version.h"
#include "mk_lang_msvc.h"


#if defined __cplusplus

#define mk_lang_bool_t bool
#define mk_lang_true ((mk_lang_bool_t)(true))
#define mk_lang_false ((mk_lang_bool_t)(false))

#elif mk_lang_version_at_least_c_23 && (mk_lang_msvc_ver == 0 || mk_lang_msvc_ver >= 9999l) /* todo when msvc starts supporting this */

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
