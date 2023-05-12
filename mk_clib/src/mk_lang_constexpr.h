#ifndef include_guard_mk_lang_constexpr
#define include_guard_mk_lang_constexpr


#if defined __cplusplus && __cplusplus >= 202299l /* todo c++23 */
#define mk_lang_constexpr_has 1
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#define mk_lang_constexpr_static static constexpr
#elif defined __cplusplus && __cplusplus >= 201402l
#define mk_lang_constexpr_has 1
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#define mk_lang_constexpr_static constexpr
#elif defined _MSVC_LANG && _MSVC_LANG >= 201402l
#define mk_lang_constexpr_has 1
#define mk_lang_constexpr constexpr
#define mk_lang_constexpr_init {}
#define mk_lang_constexpr_static constexpr
#else
#define mk_lang_constexpr_has 0
#define mk_lang_constexpr
#define mk_lang_constexpr_init
#define mk_lang_constexpr_static static
#endif


#endif
