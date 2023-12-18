#ifndef mk_include_guard_mk_lang_static_param
#define mk_include_guard_mk_lang_static_param


#include "mk_lang_version.h"


#if !defined __cplusplus && !defined _MSC_FULL_VER && mk_lang_version_at_least_c_99
#define mk_lang_static_param(type, name, count) type name[static const count]
#else
#define mk_lang_static_param(type, name, count) type* const name
#endif


#endif
