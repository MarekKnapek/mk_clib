#ifndef mk_include_guard_mk_lang_static_assert
#define mk_include_guard_mk_lang_static_assert


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_17
#define mk_lang_static_assert(x) static_assert(x)
#elif mk_lang_version_at_least_cpp_11
#define mk_lang_static_assert(x) static_assert(x, "")
#elif defined __cpp_static_assert && __cpp_static_assert >= 201411l
#define mk_lang_static_assert(x) static_assert(x)
#elif defined __cpp_static_assert && __cpp_static_assert >= 200410l
#define mk_lang_static_assert(x) static_assert(x, "")
#elif mk_lang_version_at_least_c_23
#define mk_lang_static_assert(x) static_assert(x)
#elif mk_lang_version_at_least_c_11
#define mk_lang_static_assert(x) _Static_assert(x, "")
#else
#include "mk_lang_assert.h"
#define mk_lang_static_assert mk_lang_assert
#endif


#endif
