#ifndef mk_include_guard_lang_null
#define mk_include_guard_lang_null


#if defined __cplusplus && __cplusplus >= 201103l
#define mk_lang_null nullptr
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 202299l /* todo c23 */
#define mk_lang_null nullptr
#else
#define mk_lang_null 0
#endif


#endif
