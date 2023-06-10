#ifndef mk_include_guard_mk_lang_noreturn
#define mk_include_guard_mk_lang_noreturn


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11
#define mk_lang_noreturn [[noreturn]]
#elif mk_lang_version_at_least_c_23
#define mk_lang_noreturn [[noreturn]]
#elif mk_lang_version_at_least_c_11
#define mk_lang_noreturn _Noreturn
#elif defined _MSC_VER && _MSC_VER >= 1200 /* vs 6 */ /* todo maybe ealier */
#define mk_lang_noreturn __declspec(noreturn)
#else
#define mk_lang_noreturn
#endif


#endif
