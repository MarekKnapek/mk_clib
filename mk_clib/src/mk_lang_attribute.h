#ifndef mk_include_guard_mk_lang_attribute_h
#define mk_include_guard_mk_lang_attribute_h


#include "mk_lang_compiler.h"


#if mk_lang_compiler_is_at_least_gcc(11, 1)
#define mk_lang_attribute_target(x) __attribute__((__target__(x)))
#elif mk_lang_compiler_is_at_least_clang(11, 1)
#define mk_lang_attribute_target(x) __attribute__((__target__(x)))
#else
#define mk_lang_attribute_target(x)
#endif


#endif
