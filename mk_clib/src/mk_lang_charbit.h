#ifndef mk_include_guard_mk_lang_charbit_h
#define mk_include_guard_mk_lang_charbit_h


#if defined __cplusplus
#include <climits> /* CHAR_BIT */
#define mk_lang_charbit CHAR_BIT
#else
#include <limits.h> /* CHAR_BIT */
#define mk_lang_charbit CHAR_BIT
#endif


#endif
