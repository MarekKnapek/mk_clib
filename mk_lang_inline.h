#ifndef mk_include_guard_lang_inline
#define mk_include_guard_lang_inline


#if defined __cplusplus && __cplusplus >= 199711l
#define mk_lang_inline inline
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901l
#define mk_lang_inline inline
#else
#define mk_lang_inline
#endif


#endif
