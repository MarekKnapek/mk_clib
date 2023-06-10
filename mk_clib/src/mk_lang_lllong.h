#ifndef mk_include_guard_mk_lang_lllong
#define mk_include_guard_mk_lang_lllong


#if defined __SIZEOF_INT128__ && __SIZEOF_INT128__ != 0
#define mk_lang_lllong_has 1
#define mk_lang_ulllong_t unsigned __int128
#define mk_lang_slllong_t signed __int128
#else
#include "mk_lang_llong.h"
#define mk_lang_lllong_has 0
#define mk_lang_ulllong_t mk_lang_ullong_t
#define mk_lang_slllong_t mk_lang_sllong_t
#endif


#endif
