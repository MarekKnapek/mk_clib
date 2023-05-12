#ifndef include_guard_mk_lang_static_assert
#define include_guard_mk_lang_static_assert


#if defined __cplusplus && __cplusplus >= 201703l
#define mk_lang_static_assert(x) static_assert(x)
#elif defined __cplusplus && __cplusplus >= 201103l
#define mk_lang_static_assert(x) static_assert(x, "")
#elif defined __cpp_static_assert && __cpp_static_assert >= 201411l
#define mk_lang_static_assert(x) static_assert(x)
#elif defined __cpp_static_assert && __cpp_static_assert >= 200410l
#define mk_lang_static_assert(x) static_assert(x, "")
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 202299l /* todo c23 */
#define mk_lang_static_assert(x) static_assert(x)
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112l
#define mk_lang_static_assert(x) _Static_assert(x, "")
#else
#include "mk_lang_assert.h"
#define mk_lang_static_assert mk_lang_assert
#endif


#endif
