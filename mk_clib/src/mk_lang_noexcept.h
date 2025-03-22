#ifndef mk_include_guard_mk_lang_noexcept_h
#define mk_include_guard_mk_lang_noexcept_h


#include "mk_lang_msvc.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11 || mk_lang_version_at_least_msvc_cpp_14 /* todo maybe msvc earlier */
#define mk_lang_noexcept noexcept(true)
#elif mk_lang_version_at_least_cpp_98
#define mk_lang_noexcept throw()
#else
#define mk_lang_noexcept
#endif


#endif
