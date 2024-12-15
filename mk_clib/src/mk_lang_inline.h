#ifndef mk_include_guard_mk_lang_inline
#define mk_include_guard_mk_lang_inline


#include "mk_lang_compiler.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_98
#define mk_lang_inline_has 1
#define mk_lang_inline inline
#elif mk_lang_version_at_least_c_99
#define mk_lang_inline_has 1
#define mk_lang_inline inline
#elif mk_lang_compiler_is_at_least_watcom(11, 0) /* todo maybe earlier */
#define mk_lang_inline_has 1
#define mk_lang_inline __inline
#else
#define mk_lang_inline_has 0
#define mk_lang_inline
#endif


#endif
