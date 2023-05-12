#ifndef include_guard_mk_lang_likely
#define include_guard_mk_lang_likely


#if defined __cplusplus && __cplusplus >= 202002l
#define mk_lang_likely [[likely]]
#define mk_lang_unlikely [[unlikely]]
#else
#define mk_lang_likely
#define mk_lang_unlikely
#endif


#endif
