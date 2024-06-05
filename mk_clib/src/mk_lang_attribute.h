#ifndef mk_include_guard_mk_lang_attribute
#define mk_include_guard_mk_lang_attribute


#include "mk_lang_msvc.h"
#include "mk_lang_version.h"


#if (mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11 || mk_lang_version_at_least_c_23) && mk_lang_msvc_ver && defined NDEBUG
#define mk_lang_attribute_msvc_flatten [[msvc::flatten]]
#else
#define mk_lang_attribute_msvc_flatten
#endif


#endif
