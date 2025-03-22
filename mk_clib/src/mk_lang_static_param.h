#ifndef mk_include_guard_mk_lang_static_param_h
#define mk_include_guard_mk_lang_static_param_h


#include "mk_lang_msvc.h"
#include "mk_lang_version.h"


#if mk_lang_version_macro_cplusplus == 0 && mk_lang_msvc_ver == 0 && mk_lang_version_at_least_c_99
#define mk_lang_static_param(type, name, count) type name[static const count]
#else
#define mk_lang_static_param(type, name, count) type* const name
#endif


#endif
