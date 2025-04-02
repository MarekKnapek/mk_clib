#ifndef mk_include_guard_mk_lang_null_h
#define mk_include_guard_mk_lang_null_h


#include "mk_lang_msvc.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11
#define mk_lang_null nullptr
#elif mk_lang_version_at_least_c_23 && (mk_lang_msvc_ver == 0 || mk_lang_msvc_ver >= 9999l) /* todo when msvc starts supporting this */
#define mk_lang_null nullptr
#else
#define mk_lang_null 0
#endif


#endif
