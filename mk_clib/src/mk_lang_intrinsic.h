#ifndef mk_include_guard_lang_intrinsic
#define mk_include_guard_lang_intrinsic


#if defined __cplusplus && __cplusplus >= 201402l
#define mk_lang_intrinsic_want 0
#elif defined _MSVC_LANG && _MSVC_LANG >= 201402l
#define mk_lang_intrinsic_want 0
#else
#define mk_lang_intrinsic_want 1
#endif


#endif
