#ifndef mk_include_guard_mk_lang_wchar
#define mk_include_guard_mk_lang_wchar


#if defined __cplusplus
#define mk_lang_wchar_t wchar_t
#else
#include <stddef.h> /* wchar_t */
#define mk_lang_wchar_t wchar_t
#endif


#endif
