#ifndef mk_include_guard_mk_lang_likely
#define mk_include_guard_mk_lang_likely


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_20
#define mk_lang_likely [[likely]]
#define mk_lang_unlikely [[unlikely]]
#else
#define mk_lang_likely
#define mk_lang_unlikely
#endif


#endif
