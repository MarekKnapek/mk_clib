#ifndef mk_include_guard_mk_lang_alignas
#define mk_include_guard_mk_lang_alignas


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11
#define mk_lang_alignas_has 1
#define mk_lang_alignas(x) alignas(x)
#elif mk_lang_version_at_least_c_23
#define mk_lang_alignas_has 1
#define mk_lang_alignas(x) alignas(x)
#elif mk_lang_version_at_least_c_11
#define mk_lang_alignas_has 1
#define mk_lang_alignas(x) _Alignas(x)
#else
#define mk_lang_alignas_has 0
#define mk_lang_alignas(x)
#endif


#endif
