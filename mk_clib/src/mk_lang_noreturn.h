#ifndef mk_include_guard_lang_noreturn
#define mk_include_guard_lang_noreturn


#if defined __cplusplus && __cplusplus >= 201103l
#define mk_lang_noreturn [[noreturn]]
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 202299l /* todo c23 */
#define mk_lang_noreturn [[noreturn]]
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112l
#define mk_lang_noreturn _Noreturn
#elif defined _MSC_VER && _MSC_VER >= 1200 /* vs 6 */ /* todo maybe ealier */
#define mk_lang_noreturn __declspec(noreturn)
#else
#define mk_lang_noreturn
#endif


#endif
