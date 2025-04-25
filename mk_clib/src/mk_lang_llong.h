#ifndef mk_include_guard_mk_lang_llong_h
#define mk_include_guard_mk_lang_llong_h


#include "mk_lang_arch.h"
#include "mk_lang_compiler.h"
#include "mk_lang_entry_point.h"
#include "mk_lang_msvc.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11 && !(mk_lang_entry_point_have && mk_lang_arch_is_x8632)
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#define mk_lang_ullong_c(x) x ## ull
#define mk_lang_sllong_c(x) x ## ll
#elif mk_lang_version_at_least_c_99 && !(mk_lang_entry_point_have && mk_lang_arch_is_x8632)
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#define mk_lang_ullong_c(x) x ## ull
#define mk_lang_sllong_c(x) x ## ll
#elif mk_lang_msvc_ver >= mk_lang_msvc_ver_6 && !(mk_lang_entry_point_have && mk_lang_arch_is_x8632)
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned __int64
#define mk_lang_sllong_t signed __int64
#define mk_lang_ullong_c(x) x ## ui64
#define mk_lang_sllong_c(x) x ## i64
#elif mk_lang_compiler_is_at_least_watcom(13, 0)
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#define mk_lang_ullong_c(x) x ## ull
#define mk_lang_sllong_c(x) x ## ll
#elif mk_lang_compiler_is_at_least_watcom(11, 0)
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned __int64
#define mk_lang_sllong_t signed __int64
#define mk_lang_ullong_c(x) x ## ui64
#define mk_lang_sllong_c(x) x ## i64
#elif mk_lang_compiler_is_at_least_gcc(3, 2)
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#define mk_lang_ullong_c(x) x ## ull
#define mk_lang_sllong_c(x) x ## ll
#else
#define mk_lang_llong_has 0
#define mk_lang_ullong_t unsigned long int
#define mk_lang_sllong_t signed long int
#define mk_lang_ullong_c(x) x ## ul
#define mk_lang_sllong_c(x) x ## l
#endif


#endif
