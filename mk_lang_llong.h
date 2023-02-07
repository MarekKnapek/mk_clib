#ifndef mk_include_guard_lang_llong
#define mk_include_guard_lang_llong


#if defined __cplusplus && __cplusplus >= 201103l
#define mk_lang_llong_has 1
#define mk_lang_ullong_t unsigned long long int
#define mk_lang_sllong_t signed long long int
#define mk_lang_ullong_c(x) x ## ull
#define mk_lang_sllong_c(x) x ## ll
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901l
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
#elif defined __GNUC__ && defined __GNUC_MINOR__ && __GNUC__ * 100 + __GNUC_MINOR__ >= 302
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
