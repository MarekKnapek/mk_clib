#ifndef mk_include_guard_mk_lang_charbit
#define mk_include_guard_mk_lang_charbit


#if defined __cplusplus
#if defined _MSC_FULL_VER
#pragma warning(push)
#pragma warning(disable:4668)
#endif
#include <climits> /* CHAR_BIT */
#if defined _MSC_FULL_VER
#pragma warning(pop)
#endif
#define mk_lang_charbit CHAR_BIT
#else
#if defined _MSC_FULL_VER
#pragma warning(push)
#pragma warning(disable:4668)
#endif
#include <limits.h> /* CHAR_BIT */
#if defined _MSC_FULL_VER
#pragma warning(pop)
#endif
#define mk_lang_charbit CHAR_BIT
#endif


#endif
