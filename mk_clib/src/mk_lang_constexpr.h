#ifndef mk_include_guard_lang_constexpr
#define mk_include_guard_lang_constexpr


#if defined __cplusplus && __cplusplus >= 201402l
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#elif defined _MSVC_LANG && _MSVC_LANG >= 201402l
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#else
#define mk_lang_constexpr
#define mk_lang_constexpr_init
#endif


#endif
