#ifndef mk_include_guard_mk_lang_test
#define mk_include_guard_mk_lang_test


#include "mk_lang_crash.h"


#define mk_lang_test(x) ((void)((x) ? ((void)(0)) : ((void)(mk_lang_crash()))))


#endif
