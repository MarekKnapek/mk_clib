#ifndef mk_include_guard_mk_lang_llong
#define mk_include_guard_mk_lang_llong


#include "mk_lang_gnuc.h"
#include "mk_lang_version.h"


#if mk_lang_version_at_least_cpp_11
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#define mk_lang_ullong_c(x) x ## ull
#define mk_lang_sllong_c(x) x ## ll
#elif mk_lang_version_at_least_c_99
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#define mk_lang_ullong_c(x) x ## ull
#define mk_lang_sllong_c(x) x ## ll
#elif defined _MSC_VER && _MSC_VER >= 1200 /* vs 6 */
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned __int64
#define mk_lang_sllong_t signed __int64
#define mk_lang_ullong_c(x) x ## ui64
#define mk_lang_sllong_c(x) x ## i64
#elif defined __WATCOM_CPLUSPLUS__ && __WATCOM_CPLUSPLUS__ >= 1300
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#define mk_lang_ullong_c(x) x ## ull
#define mk_lang_sllong_c(x) x ## ll
#elif defined __WATCOMC__ && __WATCOMC__ >= 1300
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#define mk_lang_ullong_c(x) x ## ull
#define mk_lang_sllong_c(x) x ## ll
#elif defined __WATCOM_CPLUSPLUS__ && __WATCOM_CPLUSPLUS__ >= 1100
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned __int64
#define mk_lang_sllong_t signed __int64
#define mk_lang_ullong_c(x) x ## ui64
#define mk_lang_sllong_c(x) x ## i64
#elif defined __WATCOMC__ && __WATCOMC__ >= 1100
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned __int64
#define mk_lang_sllong_t signed __int64
#define mk_lang_ullong_c(x) x ## ui64
#define mk_lang_sllong_c(x) x ## i64
#elif mk_lang_gnuc_is_at_least(3, 2)
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
