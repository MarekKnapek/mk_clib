#ifndef mk_include_guard_mk_lang_alignas_h
#define mk_include_guard_mk_lang_alignas_h


#include "mk_lang_min.h"
#include "mk_lang_version.h"


#define mk_lang_alignas_max (4 * 1024)


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14
#define mk_lang_alignas_has 1
#define mk_lang_alignas(x) alignas(mk_lang_min(mk_lang_alignas_max, (x)))
#elif mk_lang_version_at_least_c_23
#define mk_lang_alignas_has 1
#define mk_lang_alignas(x) alignas(mk_lang_min(mk_lang_alignas_max, (x)))
#elif mk_lang_version_at_least_c_11
#define mk_lang_alignas_has 1
#define mk_lang_alignas(x) _Alignas(mk_lang_min(mk_lang_alignas_max, (x)))
#else
#define mk_lang_alignas_has 0
#define mk_lang_alignas(x)
#endif


#endif
