#ifndef mk_include_guard_mk_lang_noexcept
#define mk_include_guard_mk_lang_noexcept


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11
#define mk_lang_noexcept noexcept(true)
#elif defined __cplusplus
#define mk_lang_noexcept throw()
#else
#define mk_lang_noexcept
#endif


#endif
