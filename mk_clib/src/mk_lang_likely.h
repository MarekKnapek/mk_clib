#ifndef mk_include_guard_lang_likely
#define mk_include_guard_lang_likely


#if defined __cplusplus && __cplusplus >= 202002l
#define mk_lang_likely [[likely]]
#define mk_lang_unlikely [[unlikely]]
#else
#define mk_lang_likely
#define mk_lang_unlikely
#endif


#endif
