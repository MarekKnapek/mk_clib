#ifndef mk_include_guard_mk_lang_nodiscard
#define mk_include_guard_mk_lang_nodiscard


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_17
#define mk_lang_nodiscard [[nodiscard]]
#elif mk_lang_version_at_least_c_23
#define mk_lang_nodiscard [[nodiscard]]
#else
#define mk_lang_nodiscard
#endif


#endif
