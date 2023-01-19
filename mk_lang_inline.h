#ifndef mk_include_guard_lang_inline
#define mk_include_guard_lang_inline


#if defined __cplusplus && __cplusplus >= 199711l
#define mk_lang_inline inline
#elif defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901l
#define mk_lang_inline inline
#elif (defined __WATCOMC__ && __WATCOMC__ >= 1100) || (defined __WATCOM_CPLUSPLUS__ && __WATCOM_CPLUSPLUS__ >= 1100) /* todo maybe earlier */
#define mk_lang_inline __inline
#else
#define mk_lang_inline
#endif


#endif
