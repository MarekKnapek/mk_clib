#ifndef mk_include_guard_mk_lang_null
#define mk_include_guard_mk_lang_null


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11
#define mk_lang_null nullptr
#elif mk_lang_version_at_least_c_23
#define mk_lang_null nullptr
#else
#define mk_lang_null 0
#endif


#endif
