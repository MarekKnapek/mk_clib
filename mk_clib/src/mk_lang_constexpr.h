#ifndef mk_include_guard_mk_lang_constexpr
#define mk_include_guard_mk_lang_constexpr


#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_23
#define mk_lang_constexpr_has 1
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#define mk_lang_constexpr_static static constexpr
#elif mk_lang_version_at_least_cpp_14
#define mk_lang_constexpr_has 1
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#define mk_lang_constexpr_static constexpr
#elif mk_lang_version_at_least_msvc_cpp_14
#define mk_lang_constexpr_has 1
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#define mk_lang_constexpr_static constexpr
#else
#define mk_lang_constexpr_has 0
#define mk_lang_constexpr
#define mk_lang_constexpr_init
#define mk_lang_constexpr_static static
#endif


#endif
