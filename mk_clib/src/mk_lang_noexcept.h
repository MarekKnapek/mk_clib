#ifndef include_guard_mk_lang_noexcept
#define include_guard_mk_lang_noexcept


#if defined __cplusplus && __cplusplus >= 201103l
#define mk_lang_noexcept noexcept(true)
#elif defined __cplusplus
#define mk_lang_noexcept throw()
#else
#define mk_lang_noexcept
#endif


#endif
