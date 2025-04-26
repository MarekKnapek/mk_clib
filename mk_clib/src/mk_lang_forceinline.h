#ifndef mk_include_guard_mk_lang_forceinline_h
#define mk_include_guard_mk_lang_forceinline_h


#include "mk_lang_compiler.h"
#include "mk_lang_msvc.h"
#include "mk_lang_version.h"


#if (mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_11 || mk_lang_version_at_least_c_23) && mk_lang_msvc_ver && !mk_lang_compiler_is_at_least_clang(1, 0) && defined NDEBUG
#define mk_lang_forceinline [[msvc::forceinline]]
#elif mk_lang_compiler_is_at_least_clang(19, 1) && defined NDEBUG
#define mk_lang_forceinline __attribute__((always_inline)) __attribute__((flatten))
#else
#define mk_lang_forceinline
#endif


#endif
