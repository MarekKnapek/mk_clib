#ifndef mk_include_guard_mk_lang_inline
#define mk_include_guard_mk_lang_inline


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_98
#define mk_lang_inline inline
#elif mk_lang_version_at_least_c_99
#define mk_lang_inline inline
#elif (defined __WATCOMC__ && __WATCOMC__ >= 1100) || (defined __WATCOM_CPLUSPLUS__ && __WATCOM_CPLUSPLUS__ >= 1100) /* todo maybe earlier */
#define mk_lang_inline __inline
#else
#define mk_lang_inline
#endif


#endif
