#ifndef mk_include_guard_mk_lang_noreturn_h
#define mk_include_guard_mk_lang_noreturn_h


#include "mk_lang_msvc.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11
#define mk_lang_noreturn [[noreturn]]
#elif mk_lang_version_at_least_c_23
#define mk_lang_noreturn [[noreturn]]
#elif mk_lang_version_at_least_c_11
#define mk_lang_noreturn _Noreturn
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_6 /* todo maybe ealier */
#define mk_lang_noreturn __declspec(noreturn)
#else
#define mk_lang_noreturn
#endif


#endif
